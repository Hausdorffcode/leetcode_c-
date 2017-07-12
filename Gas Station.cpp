//https://leetcode.com/problems/gas-station/#/description

//±©Á¦³¬Ê±£¬time O(n^2), space O(1)
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        
        for (int i = 0; i < n; i++) {
            int left = 0;
            int j = i;
            bool ok = true;
            for (; j < i+n; j++) {
                left += gas[j%n];
                if (left < cost[j%n]) {ok = false; break;}
                left -= cost[j%n];
            }
            if (ok) return j%n;
        }
        return -1;
    }


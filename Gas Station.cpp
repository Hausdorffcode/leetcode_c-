//https://leetcode.com/problems/gas-station/#/description

//暴力超时，time O(n^2), space O(1)
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
	
//time O(n), space O(1)
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int startIndex = -1;
        int total = 0;
        for (int i = 0, sum = 0; i < n; i++) {
            sum += gas[i] - cost[i];
            total += gas[i]-cost[i];
            if (sum < 0) {
                sum = 0;
                startIndex = i;
            }
        }
        if (total >= 0) {   //只要total>=0必有解
            return startIndex+1;
        }
        return -1;
    }


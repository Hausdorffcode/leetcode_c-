//Restore IP Addresses

//dfs
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ret;
        vector<string> path;
        dfs(s, ret, path, 0);
        return ret;
    }
    
private:
    void dfs(string s, vector<string>& ret, vector<string>& path, int cur) {
        if (path.size() == 4 && cur == s.size()) {
            string temp;
            temp = path[0] + '.' + path[1] + '.' + path[2] + '.' + path[3];
            ret.push_back(temp);
            return;
        }
        if (s.size()-cur < (4-path.size())) return;   //ºÙ÷¶
        if (s.size()-cur > (4-path.size())*3) return;  //ºÙ÷¶
        int num = 0;
        for (int i = cur; i < cur+3; i++) {
            num =  num * 10 + (s[i]-'0');
            if (num < 0 || num > 255) break;   //ºÙ÷¶
            path.push_back(s.substr(cur, i-cur+1));
            dfs(s, ret, path, i+1);
            path.pop_back();
            
            if (num == 0) break;   //ºÙ÷¶
        }
    }
};
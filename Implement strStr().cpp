//https://leetcode.com/problems/implement-strstr/#/description

//time O(n), space O(1)
class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.size() == 0) return 0;
        int len = haystack.size() - needle.size();
        for (int i = 0; i <= len; i++) {
            bool ok = true;
            for (int k = 0; k < needle.size(); k++) {
                if (needle[k] != haystack[i+k]) {
                    ok = false;
                    break;
                }
            }
            if (ok) return i;
        }
        return -1;
    }
};
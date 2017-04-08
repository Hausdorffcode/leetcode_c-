/**Reverse Integer
Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321

click to show spoilers.

Have you thought about this?
Here are some good questions to ask before coding. Bonus points for you if you have already thought through this!

If the integer's last digit is 0, what should the output be? ie, cases such as 10, 100.

Did you notice that the reversed integer might overflow? Assume the input is a 32-bit integer, then the reverse of 1000000003 overflows. How should you handle such cases?

For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
*/

class Solution {
public:
    int reverse(int x) {
        bool sign = true;
        if (x == 0x80000000) {
            return 0;
        }
        if (x < 0) {
            sign = false;
            x = -x;
        }
        long lx = 0;
        while (x != 0) {
            lx = lx * 10 + x % 10;
            x /= 10;
        }
        if (lx > 0x7fffffff) {
            return 0;
        } else {
            if (sign) {
                return (int)lx;
            } else {
                return -1 * (int)lx;
            }
        }
    }
};

/**qinghua dashen*/
#include <climits>
#include <cstdint>

class Solution {
public:
    int reverse(int x) {
        const int R = 10;
        
        if (x == INT_MIN) {
            // I forgot this case.
            // x == -x, x == ?
            return 0;
        }
        
        if (x < 0) {
            return -reverse(-x);
        }
        int64_t res = 0;
        while (x > 0) {
            res = res * R + x % R;
            if (res > INT_MAX) {
                return 0;
            }
            x /= R;
        }
        return res;
    }
};
/*
 * @lc app=leetcode.cn id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
class Solution {
public:
    // double myPow(double x, int n) {
    //     if (n == 0) return 1;
    //     if (x == 1) return 1;
    //     if (x == -1) {
    //         if(n %2 == 0) return 1;
    //         else return -1;
    //     }
    //     double res = 1;
    //     if (n < 0){
    //         if(n <= INT_MIN) return 0;
    //         for (int i = 0; i < -n; i++){
    //             res *= x;
    //         }
    //         return 1 / res;
    //     }
    //     else{
    //         for (int i = 0; i < n; i++){
    //             res *= x;
    //         }
    //         return res;
    //     }
    // }

    // double myPow(double x, int n) {
    //     long long N = n;
    //     if (N < 0) {
    //         x = 1 / x;
    //         N = -N;
    //     }
    //     double res = 1.0;
    //     double tmp = x;
    //     for (long long i = N; i > 0; i /= 2) {
    //         if (i % 2 == 1) {
    //             res *= tmp;
    //         }
    //         tmp *= tmp;
    //     }
    //     return res;
    // }
    double myPow(double x, int n) {
        long long N = n;
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }
        double res = 1.0;
        double tmp =x;
        double oldtmp = 1;
        long long i = 1;
        while(N >0)
        {
            while((N -i)>=0){
                oldtmp = tmp;
                tmp *= tmp;
                i = i << 1;
            }
            tmp = oldtmp;
            i = i >> 1;
            res *= tmp;
            N -= i;
            i = 1;
            tmp = x;
        }
        return res;
    }
};
// @lc code=end


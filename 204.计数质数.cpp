/*
 * @lc app=leetcode.cn id=204 lang=cpp
 *
 * [204] 计数质数
 */

// @lc code=start
class Solution {
public:
    // unordered_map<int, int> s;
    // int maxCount;
    // bool isPrime(int num) {
    //     if (num <= 1) {
    //         return false;
    //     }
    //     for (int i = 2; i * i <= num; i++) {
    //         if (num % i == 0) {
    //             return false;
    //         }
    //     }
    //     return true;
    // }
    // int countPrimes(int n) {
    //     s[0]=0;
    //     s[1]=0;
    //     s[2]=0;
    //     s[3]=1;
    //     int count = 0;
    //     if(s.find(n)!= s.end()){
    //         return s[n];
    //     }
    //     if(n>maxCount) {
    //         for(int i = maxCount+1; i < n; i++)
    //         {
    //             if(isPrime(i))
    //             {
    //                 count++;
    //                 s[i] = count;
    //             }
    //             s[i]=count;
    //         }
    //     }
    //     maxCount = n;
    //     return count;
    // }
    int countPrimes(int n) {
        vector<int> isPrime(n, 1);
        int ans = 0;
        for (int i = 2; i < n; ++i) {
            if (isPrime[i]) {
                ans += 1;
                if ((long long)i * i < n) {
                    for (int j = i * i; j < n; j += i) {
                        isPrime[j] = 0;
                    }
                }
            }
        }
        return ans;
    }
};
// @lc code=end


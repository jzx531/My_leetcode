/*
 * @lc app=leetcode.cn id=201 lang=cpp
 *
 * [201] 数字范围按位与
 */

// @lc code=start
class Solution {
public:
    // int rangeBitwiseAnd(int left, int right) {
    //     int res = left;
    //     if(right == INT_MAX) right--;
    //     for(int i=left;i<=right;i++){
    //         res = res & i;
    //         if(res == 0) return 0;
    //     }
    //     return res;
    // }
    int rangeBitwiseAnd(int left, int right) {
        int shift = 0;
        while(left!= right){
            left >>= 1;
            right >>= 1;
            shift++;
        }
        return left << shift;
    }

};
// @lc code=end


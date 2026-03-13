/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
 */

// @lc code=start
class Solution {
public:
    // int removeDuplicates(vector<int>& nums) {
    //     unordered_set<int> s;
    //     auto it = nums.begin();
    //     while(it!= nums.end()){
    //         auto ret = s.insert(*it);
    //         if(ret.second){
    //             it++;
    //         }else{
    //             auto ittmp = it;
    //             nums.erase(ittmp);
    //         }
    //     }
    //     return nums.size();
    // }
    int removeDuplicates(vector<int>& nums) {
        int last = nums[0];
        auto it = nums.begin();
        it++;
        while(it!= nums.end()){
            if(*it == last){
                auto ittmp = it;
                nums.erase(ittmp);
            }
            else{
                last = *it;
                it++;
            }
        }
        return nums.size();
    }
};
// @lc code=end


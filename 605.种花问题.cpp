/*
 * @lc app=leetcode.cn id=605 lang=cpp
 *
 * [605] 种花问题
 */

// @lc code=start
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if(n==0) return true;
        if(flowerbed.size()==1)
        {
            if(flowerbed[0]==0) return n==1?true:false;
            else return false;
        }
        if(flowerbed[0] ==0 && flowerbed[1] ==0)
        {
            flowerbed[0]=1;
            n--;
            if(n<=0) return true;
        }
        if(flowerbed[flowerbed.size()-1] ==0 && flowerbed[flowerbed.size()-2] ==0)
        {
            flowerbed[flowerbed.size()-1]=1;
            n--;
            if(n<=0) return true;
        }
        for(int i=0;i<flowerbed.size()-1;i++)
        {
            if(flowerbed[i]==0 && flowerbed[i+1]==0 && flowerbed[i+2]==0)
            {
                flowerbed[i+1]=1;
                ++i;
                n--;
                if(n<=0) return true;
            }
        }
        return false;
    }
};
// @lc code=end


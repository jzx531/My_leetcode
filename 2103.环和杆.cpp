/*
 * @lc app=leetcode.cn id=2103 lang=cpp
 *
 * [2103] 环和杆
 */

// @lc code=start
class Solution {
public:
    int countPoints(string rings) {
        vector<vector<int>> place(10,vector<int>(3,0));
        int n=rings.size();
        for(int i=0;i<n;i+=2)
        {
            switch(rings[i])
            {
                case 'R':
                    place[rings[i+1]-'0'][0]=1;
                    break;
                case 'G':
                    place[rings[i+1]-'0'][1]=1;
                    break;
                case 'B':
                    place[rings[i+1]-'0'][2]=1;
                    break;
            }
        }
        int count=0;
        for(int i=0;i<10;i++)
        {
            if(place[i][0]&&place[i][1]&&place[i][2])
                count++;
        }
        return count;
    }
};
// @lc code=end

// The new version of the code is missing the '0' character in the place array index.

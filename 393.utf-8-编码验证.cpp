/*
 * @lc app=leetcode.cn id=393 lang=cpp
 *
 * [393] UTF-8 编码验证
 */

// @lc code=start
class Solution {
public:
    bool judge(vector<int>& data,int start,int len)
    {
        if(len == 0) return true;
        if((data[start]&0x80) == 0) {
            if(len == 1) return true;
            return judge(data,start+1,len-1);
        }
        int cnt = 0;
        for(int i = 0;i<5;i++){
            if(data[start]&(1<<(7-i))) {
                cnt++;
            }
            else{
                break;
            }
        }
        if(cnt <2 || cnt > 4|| len < cnt) return false;
        for(int i = 1;i<(cnt);i++) {
            if((data[start+i]&(0xC0))!= 0x80) return false;
        }
        return judge(data,start+cnt,len-cnt);
    }
    bool validUtf8(vector<int>& data) {
        return judge(data,0,data.size());
    }
};
// @lc code=end


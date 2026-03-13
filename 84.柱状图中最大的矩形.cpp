/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 */

// @lc code=start
class Solution {
public:
    // int largestRectangleArea(vector<int>& heights) 
    // {
    //     int n=heights.size();
    //     if(n==0) return 0;
    //     if(n==1) return heights[0];
    //     int res=0;
    //     int height;
    //     for(int i=0;i<n;i++)
    //     {
    //         height=heights[i];
    //         if(i>0 && heights[i-1]>=height) continue;
    //         for(int j=i;j<n;j++)
    //         {
    //             if(heights[j]<height) height=heights[j];
    //             if((height*(n-i+1)<res)) break;
    //             res=max(res,height*(j-i+1));
    //         }
    //     }
    //     return res;
    // }
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        if(n==0) return 0;
        if(n==1) return heights[0];
        stack<int> st;
        int res=0;
        int height;
        int left=0;
        int right=0;
        st.push(-1);
        for(int i=0;i<n;i++)
        {

            if(st.top()==-1 || heights[i]>=heights[st.top()]){
                st.push(i);
                right=i;
            }
            else{
                while(st.top()!=-1 && heights[i]<heights[st.top()]){
                    height=heights[st.top()];
                    st.pop();
                    left=st.top();
                    res=max(res,height*(right-left));
                    // cout<<res<<endl;
                }
                st.push(i);
                right=i;
            }
        }
        while(st.top()!=-1){
            height=heights[st.top()];
            st.pop();
            left=st.top();
            res=max(res,height*(right-left));
        }
        return res;
    }
};
// @lc code=end


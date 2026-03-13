/*
 * @lc app=leetcode.cn id=134 lang=cpp
 *
 * [134] 加油站
 */

// @lc code=start
class Solution {
public:
    // bool canCompleteCircuit(int start,vector<int>& gas, vector<int>& cost) {
    //     int n = gas.size();
    //     int sum = gas[start];
    //     int i;
    //     for (i = 1;i<=n;i++)
    //     {
    //         int index = (start+i)%n;
    //         int cost_index = (start+i-1)%n;
    //         sum -=cost[cost_index];
    //         if (sum < 0)
    //         {
    //             break;
    //         }
    //         sum += gas[index];
    //     }
    //     return i == n+1;
    // }
    // int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    //     int sum1 = accumulate(gas.begin(),gas.end(),0);
    //     int sum2 = accumulate(cost.begin(),cost.end(),0);
    //     if(sum1<sum2) return -1;
    //     for(int i=0;i<gas.size();i++){
    //         if(canCompleteCircuit(i,gas,cost)){
    //             return i;
    //         }
    //     }
    //     return -1;
    // }
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int sum = 0;
        int start = 0;
        int min_spare = INT_MAX;
        int min_index = 0;
        for(int i = 0;i<n;i++){
            sum += gas[i] - cost[i];
            if(sum < min_spare){
                min_spare = sum;
                min_index = i;
            }
        }
        if(sum < 0) return -1;
        return (min_index+1)%n;
    }
};
// @lc code=end


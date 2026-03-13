/*
 * @lc app=leetcode.cn id=207 lang=cpp
 *
 * [207] 课程表
 */

// @lc code=start
class Solution {
public:
    // struct ListNode{
    //     int val;
    //     vector<ListNode*>courses;
    //     ListNode(int val):val(val){
    //         courses.clear();
    //     }
    // };
    // void dfs(ListNode *node,int & count,int current_val,bool& flag,int numCourses){
    //     if(flag) return;
    //     if(!node) return;
    //     current_val ++;
    //     count = max(count, current_val);
    //     if(current_val > numCourses){
    //         flag = true;
    //         return;
    //     }
    //     for(auto course : node->courses){
    //         dfs(course, count, current_val, flag, numCourses);
    //     }
    // }
    
    // bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    //     unordered_map<int, ListNode*> graph;

    //     int max_val = 0;
    //     for (auto& p : prerequisites) {
    //         if(!graph.count(p[1])){
    //             graph[p[1]] = new ListNode(p[1]);
    //         }
    //         if(!graph.count(p[0])){
    //             graph[p[0]] = new ListNode(p[0]);
    //         }
    //         graph[p[0]]->courses.push_back(graph[p[1]]);
    //     }
    //     ListNode* p ;
    //     int count = 0;
    //     bool flag = false;
    //     for(int i = 0; i <= numCourses; i++)
    //     {
    //         count = 0;
    //         if(flag) return false;
    //         dfs(graph[i], count,0, flag, numCourses);
    //     }
    //     return true;
    // }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
    {
        vector<vector<int>> graph(numCourses, vector<int>());
        vector<int> indegree(numCourses, 0);
        for (auto& p : prerequisites) {
            graph[p[1]].push_back(p[0]);
            indegree[p[0]]++;
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        int count = 0;
        while (!q.empty()) {
            int course = q.front();
            q.pop();
            count++;
            for (int j = 0; j < graph[course].size(); j++) {
                indegree[graph[course][j]]--;
                if (indegree[graph[course][j]] == 0) {
                    q.push(graph[course][j]);
                }
            }
        }
        return count == numCourses;
    }
};
// @lc code=end


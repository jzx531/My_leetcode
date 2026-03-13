/*
 * @lc app=leetcode.cn id=310 lang=cpp
 *
 * [310] 最小高度树
 */

// @lc code=start
class Solution {
public:
    // struct ListNode{
    //     int val;
    //     vector<ListNode*> neighbors;
    //     ListNode(int x) : val(x) {}
    // };

    // void dfs(ListNode*node,vector<bool>&visited,int height,int &max_height)
    // {
    //     if(visited[node->val]) {
    //         max_height=max(max_height,height);
    //         return;
    //     }
    //     visited[node->val]=true;
    //     if(node->neighbors.empty())
    //     {
    //         max_height=max(max_height,height);
    //         return;
    //     }
    //     for(auto neighbor:node->neighbors)
    //     {
    //         dfs(neighbor,visited,height+1,max_height);
    //     }
    // }
    
    // vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
    //     vector<ListNode*> nodes(n);
    //     int m=edges.size();
    //     for(int i=0;i<n;i++)
    //     {
    //         nodes[i] = new ListNode(i);
    //     }
    //     for(int i=0;i<m;i++)
    //     {
    //         int x = edges[i][0];
    //         int y = edges[i][1];
    //         nodes[x]->neighbors.push_back(nodes[y]);
    //         nodes[y]->neighbors.push_back(nodes[x]);
    //     }
        
    //     vector<int> heights;
    //     for(int i=0;i<n;i++)
    //     {
    //         vector<bool> visited(n,false);
    //         int max_height=0;

    //         dfs(nodes[i],visited,1,max_height);
    //         heights.push_back(max_height);
    //     }
    //     int min_height=*min_element(heights.begin(),heights.end());
    //     vector<int> res;
    //     for(int i=0;i<n;i++)
    //     {
    //         cout<<heights[i]<<" ";
    //         if(heights[i]==min_height)
    //         {
    //             res.push_back(i);
    //         }
    //     }
    //     return res;
    // }
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) return {0};  // 只有一个节点时直接返回
        
        // 构建邻接表
        vector<unordered_set<int>> adj(n);
        
        for (const auto& edge : edges) {
            adj[edge[0]].insert(edge[1]);
            adj[edge[1]].insert(edge[0]);
        }
        
        // 初始化叶子节点队列（度为1的节点）
        queue<int> leaves;
        for (int i = 0; i < n; ++i) {
            if (adj[i].size() == 1) {
                leaves.push(i);
            }
        }
        
        int remainingNodes = n;
        while (remainingNodes > 2) {
            int currentLayerSize = leaves.size();
            remainingNodes -= currentLayerSize;
            
            // 剥离当前层的所有叶子节点
            for (int i = 0; i < currentLayerSize; ++i) {
                int leaf = leaves.front();
                leaves.pop();
                
                // 获取该叶子节点的唯一邻居
                int neighbor = *adj[leaf].begin();
                adj[neighbor].erase(leaf);  // 删除该叶子节点
                
                // 如果邻居成为新的叶子节点，加入队列
                if (adj[neighbor].size() == 1) {
                    leaves.push(neighbor);
                }
            }
        }
        
        // 剩下的1或2个节点即为MHT的根
        vector<int> result;
        while (!leaves.empty()) {
            result.push_back(leaves.front());
            leaves.pop();
        }
        
        return result;
    }
};
// @lc code=end


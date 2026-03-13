/*
 * @lc app=leetcode.cn id=307 lang=cpp
 *
 * [307] 区域和检索 - 数组可修改
 */

// @lc code=start
// class NumArray {
// public:
//     NumArray(vector<int>& nums) {
//         for (int i = 0; i < nums.size(); i++) {
//             hash_map[i] = nums[i];
//         }
//     }
    
//     void update(int index, int val) {
//         hash_map[index] = val;
//     }
    
//     int sumRange(int left, int right) {
//         int sum = 0;
//         for (int i = left; i <= right; i++) {
//             sum += hash_map[i];
//         }
//         return sum;
//     }
// private:
//     unordered_map<int, int> hash_map;
// };

// class NumArray {
//     public:
//         NumArray(vector<int>& nums) {
//             n = nums.size();
//             tree = vector<int>(4 * n, 0);  // 使用4*n空间
//             buildTree(nums, 0, 0, n-1);
//         }
        
//         void update(int index, int val) {
//             updateTree(0, 0, n-1, index, val);
//         }
        
//         int sumRange(int left, int right) {
//             return queryTree(0, 0, n-1, left, right);
//         }
    
//     private:
//         vector<int> tree;
//         int n;
        
//         void buildTree(vector<int>& nums, int node, int start, int end) {
//             if (start == end) {
//                 tree[node] = nums[start];
//                 return;
//             }
//             int mid = (start + end) / 2;
//             buildTree(nums, 2*node+1, start, mid);
//             buildTree(nums, 2*node+2, mid+1, end);
//             tree[node] = tree[2*node+1] + tree[2*node+2];
//         }
        
//         void updateTree(int node, int start, int end, int idx, int val) {
//             if (start == end) {
//                 tree[node] = val;
//                 return;
//             }
//             int mid = (start + end) / 2;
//             if (idx <= mid) {
//                 updateTree(2*node+1, start, mid, idx, val);
//             } else {
//                 updateTree(2*node+2, mid+1, end, idx, val);
//             }
//             tree[node] = tree[2*node+1] + tree[2*node+2];
//         }
        
//         int queryTree(int node, int start, int end, int l, int r) {
//             if (r < start || l > end) return 0;
//             if (l <= start && end <= r) return tree[node];
//             int mid = (start + end) / 2;
//             return queryTree(2*node+1, start, mid, l, r) + 
//                    queryTree(2*node+2, mid+1, end, l, r);
//         }
//     };

class NumArray {
    public:
        NumArray(vector<int>& nums) {
            this->tree = vector<int>(2 * nums.size(), 0);
            // copy(nums.begin(), nums.end(), this->tree.begin() + nums.size());
            for (int i = 0; i < nums.size(); i++) {
                this->tree[i + nums.size()] = nums[i];
            }
            for (int i = nums.size() - 1; i > 0; i--) {
                this->tree[i] = this->tree[i << 1] + this->tree[(i << 1)+1];
            }
        }
        void update(int index, int val) {
            index += this->tree.size() / 2;
            this->tree[index] = val;
            // while(index > 0){
            //     int left = index % 2 == 0? index : index - 1;
            //     int right = index % 2 == 0? index + 1 : index;
            //     this->tree[index/2] = this->tree[left] + this->tree[right];
            //     index /= 2;
            // }
            while(index > 0){
                index /= 2;
                this->tree[index] = this->tree[index*2] + this->tree[index*2+1];
            }
        }
        int sumRange(int left, int right) {
            int sum = 0;
            left += this->tree.size() / 2;
            right += this->tree.size() /2;
            while(left <= right){
                if(left % 2==1){
                    sum += this->tree[left];
                    left++;
                }
                if(right % 2 == 0){
                    sum += this->tree[right];
                    right--;
                }
                left = left>> 1;
                right = right >> 1;
            }
            return sum;
        }
    private: 
        vector<int> tree;
    };
/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
// @lc code=end


/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 */

// @lc code=start
class MinStack {
public:
    struct ListNode {
        int val;
        ListNode* next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode* next) : val(x), next(next) {}
    };
    ListNode* head;
    stack<int> s;
    MinStack() {
        head = new ListNode(0);
        head->next = nullptr;
        stack<int> s;
    }
    
    void push(int val) {
        ListNode* node = new ListNode(val);
        ListNode* p = head->next;
        ListNode* prev = head;
        while(p && p->val < val)
        {
            prev = p;
            p = p->next;
        }
        node->next = p;
        prev->next = node;
        s.push(val);
    }
    
    void pop() {
        if(s.empty()) return;
        int val = s.top();
        s.pop();
        ListNode* p = head->next;
        ListNode* prev = head;
        while(p && p->val < val)
        {
            prev = p;
            p = p->next;
        }
        prev->next = p->next;
        delete p;
    }
    
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return head->next->val;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end


#include <iostream>
#include <unordered_set>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

ListNode* reverseKGroup(ListNode* head, int k) {
    if(!head) return head;
    if(k == 1) return head;
    if(!head->next) return head;

    ListNode * preHead = nullptr;
    ListNode * prev = head;
    ListNode * curr = head->next;
    ListNode * next = head;
    int i;
    ListNode * res = head;

    while(next){
        for(i = 1; next!= nullptr&&i <= k; i++)
        {
            if(next->next == nullptr)
            {
                next = nullptr;
                break;
            }
            else{ next=next->next;}
        }
        cout<<i<<endl;
        if(i < k){
            return res;
        }
        else{
            ListNode *tmpHead = prev;
            for(i = 0;i<(k-1);i++)
            {
                ListNode *tmp = curr ->next;
                prev -> next = tmp;
                curr ->next = tmpHead;
                
                tmpHead = curr;
                curr = tmp;
                if(preHead != nullptr){
                    preHead->next = tmpHead;
                }
                else{
                    res = tmpHead;
                }
            }
        } 
        preHead = prev;
        if(next!= nullptr){
            prev = next;
        }
        else {
            break;
        }
        if(prev->next == nullptr) {
            break;
        }
        curr = prev->next;
    }
    return res;
}



int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    ListNode* p = head->next;
    for(int i=3;i<=3;i++)
    {
        p->next = new ListNode(i);
        p = p->next;
    }
    printList(head);
    head = reverseKGroup(head, 3);
    printList(head);
    return 0;
}

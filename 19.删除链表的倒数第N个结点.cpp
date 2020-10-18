/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/**
 * 快慢指针，慢指针从头结点前一位出发，快指针领先n个结点，当快指针指向链表尾时，慢指针刚好在第倒数N+1个结点上
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *node=new ListNode(0,head),*q=head;
        ListNode *p=node;
        for(int i=0;i<n;i++){
            q=q->next;
        }
        while(q){
            p=p->next;
            q=q->next;
        }
        p->next=p->next->next;
        return node->next;
    }
};
/**
 * 栈
 * 用栈保存每一位结点的指针，当指针指向链表尾下一位时，出栈n个结点，此时栈顶存放的就是倒数第N+1位结点
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *node=new ListNode(0);
        node->next=head;
        ListNode *p=node;
        stack<ListNode *> t;
        while(p){
            t.push(p);
            p=p->next;
        }
        for(int i=0;i<n;i++){
            t.pop();
        }
        ListNode *top=t.top();
        top->next=top->next->next;
        return node->next;
    }
};
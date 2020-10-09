/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 /**
 *	污染链表法
 *	遍历链表，并将其值替换为标记值
 *	若链表有环，则会再次遇到值为标记值的结点
 */
 

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==NULL || head->next==NULL){
            return false;
        }
        ListNode *pos=head;
        while(pos->next!=NULL){
            if(pos->val=='p'){
                return true;
            }
            else
                pos->val='p';
            pos=pos->next;
        }
        return false;
    }
};
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
* 通过一个指针依次访问两条链表中的最小值，并将其穿起来
*/
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *dum = new ListNode(),*cur=dum;
        while(l1 && l2){
            if(l1->val<l2->val){
                cur->next=l1;
                l1=l1->next;
                cur=cur->next;
            }
            else{
                cur->next=l2;
                l2=l2->next;
                cur=cur->next;
            }
        }
        cur->next=l1?l1:l2;
        return dum->next;
    }
};
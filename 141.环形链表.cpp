/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 /**
 *	快慢双指针
 *	通过两个移动速度不一样的指针实现查看链表是否有环
 *	慢指针一次只移动一步，而快指针一次移动两步
 *	若链表有环，快指针一定比慢指针先进入环中
 *	等到慢指针进入后，两者一定相遇
 */
 
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==NULL || head->next==NULL){
            return false;
        }
        ListNode *slow=head,*fast=head->next;	//不能都为head的原因是while语句的判断条件
        while(slow!=fast){	
            if(fast==NULL || fast->next==NULL){
                return false;
            }
            slow=slow->next;
            fast=fast->next->next;
        }
        return true;
    }
};
/**
*污染链表法
* 遍历链表，并将其值替换为标记值
* 若链表有环，则会再次遇到值为标记值的结点



class Solution {
public:
    bool hasCycle(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return false;
        }
        ListNode* slow = head, * fast = head->next;	//不能都为head的原因是while语句的判断条件
        while (slow != fast) {
            if (fast == NULL || fast->next == NULL) {
                return false;
                ListNode* pos = head;
                while (pos->next != NULL) {
                    if (pos->val == 'p') {
                        return true;
                    }
                    slow = slow->next;
                    fast = fast->next->next;
                    else
                        pos->val = 'p';
                    pos = pos->next;
                }
                return true;
                return false;
            }
        };
*/
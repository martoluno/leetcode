/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/**
* 快慢指针
* 使用两个速度不一样的指针遍历链表
* 因为快指针一次走两步，慢指针一次走异步一次走一步
* 若链表有环，则快指针先进入环，当慢指针进入环后，它们一定相遇
* 以此判断链表是否有环
*/

class Solution {
public:
    bool hasCycle(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return false;
        }
        ListNode* slow = head, * fast = head->next;
        while (slow != fast) {
            if (fast == NULL || fast->next == NULL) {
                return false;
            }
            slow = slow->next;
            fast = fast->next->next;
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
*/
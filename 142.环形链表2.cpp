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
* 设链表中环外部分的长度为a。slow 指针进入环后，又走了b的距离与fast相遇。此时fast指针已经走完了环的n圈，
* 因此它走过的总距离为 a+n(b+c)+b=a+(n+1)b+nca+n(b+c)+b=a+(n+1)b+nc。
* 根据题意，任意时刻fast指针走过的距离都为slow指针的2倍。因此，我们有
* a+(n+1)b+nc=2(a+b)⟹a=c+(n−1)(b+c)
* 因此，当发现slow 与fast相遇时，我们再额外使用一个指针ptr。起始，它指向链表头部；随后，它和slow每次向后移动一个位置。最终，它们会在入环点相遇。
* 
*/
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {

        ListNode *slow=head,*fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(fast==slow){
                ListNode *ptr=head;
                while(ptr!=slow){
                    ptr=ptr->next;
                    slow=slow->next;
                }
                return ptr;
            }
        }
        return NULL;
        
    }
};
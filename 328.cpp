/*
328. Odd Even Linked List

Given a singly linked list, group all odd nodes together followed by the even nodes. Please note here we are talking about the node number and not the value in the nodes.

You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.

Example:
Given 1->2->3->4->5->NULL,
return 1->3->5->2->4->NULL.

Note:
The relative order inside both the even and odd groups should remain as it was in the input. 
The first node is considered odd, the second node even and so on ...

Credits:
Special thanks to @aadarshjajodia for adding this problem and creating all test cases.
*/

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode* o = head;
        ListNode* e0;// start of even
        ListNode* e1;// end of even
        if(head && head->next) {
            e0 = e1 = o->next;
        } else {
            return head;
        }

        while(e0 && e1 && e1->next && o->next) {
            ListNode* tmp = e1->next;

            o->next = tmp;
            e1->next = tmp->next;

            // attach the start of even to the end of odd
            tmp->next = e0;

            o = o->next;
            e1 = e1->next;

        }
        return head;
    }
};

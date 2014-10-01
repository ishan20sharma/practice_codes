/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        
            if(head == NULL)
                return false;
                
            if(head->next == NULL)
                return false;
                
            ListNode *slow = head, *fast = head->next->next;
            
            while(fast != NULL && fast->next != NULL  && fast != slow) {
                slow = slow->next;
                fast = fast->next->next;
            }
            
            if(fast == NULL || fast->next == NULL)
                return false;
                
            if(fast == slow)
                return true;
        
        
    }
};

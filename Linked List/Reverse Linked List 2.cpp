/* Time :- O(N) Space :- O(1) */

class Solution
{
public:
    ListNode* reverseKGroup(ListNode* head, int k)
    {
        ListNode* curr = head;
        ListNode* prev = NULL;
        
        while(k--)
        {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        head->next = curr;
        return prev;
    }
    
    ListNode* reverseBetween(ListNode* head, int left, int right)
    {   
	   if(left == 1)
       {
           return reverseKGroup(head, right-left+1);
       }
	   
       int count = 2; 
       ListNode* curr = head;
       while(left>count)
       {
            count++;
            curr = curr->next;
       }
       curr->next = reverseKGroup(curr->next, right-left+1);
       return head;
    }
};

class Solution
{
public:
    ListNode* reverseBetween(ListNode* head, int left, int right)
    {
        ListNode* dummy = new ListNode(0);
        dummy->next=head;
        
        ListNode* leftPrev=dummy;
        ListNode* curr=head;
        
        int temp = left-1;
        while(temp--)   /* Moving current at the starting point of reverse */
        {
           leftPrev=curr;
           curr=curr->next;
        }
        
        ListNode* prev=NULL;
        int size=right-left+1;
        
        while(size--)  /* Performing operation req times by reversing the links */
        {
            ListNode* flag = curr->next;
            curr->next=prev;
            prev=curr;
            curr=flag;
        }
        
        leftPrev->next->next=curr; 
        leftPrev->next=prev;
        
        return dummy->next;
    }
};

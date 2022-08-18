/* Time :- O(N) Space :- O(1) */

class Solution
{
public:
    
    ListNode* reverseKGroup(ListNode* head, int k)
    {
        int count=0;
        ListNode* temp = head;
        
        if(k==1)
        {
            return head;
        }
        while(temp!=NULL)
        {
            count++;
            temp=temp->next;
        }
        if(k>count)
        {
            return head;
        }
        
        count=0;
        ListNode* prevPtr=NULL;
        ListNode* currPtr=head;
        ListNode* nextPtr=NULL;
        
        while(count<k&&currPtr!=NULL)
        {
            count++;
            nextPtr=currPtr->next;   
            currPtr->next=prevPtr;        
            prevPtr=currPtr;              
            currPtr=nextPtr;              
        }
        if(nextPtr!=NULL)
        {
            head->next = reverseKGroup(nextPtr,k);
        }
        return prevPtr;
    }
};

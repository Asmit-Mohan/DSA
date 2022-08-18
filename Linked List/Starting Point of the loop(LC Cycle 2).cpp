/* Time :- O(N) Space :- O(1) */

class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return NULL;
        }
        
        ListNode* slow=head;
        ListNode* fast=head;
        int flag=0;
        
        while(fast!=NULL&&fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)
            {
                flag=1;
                break;
            }
        }
        
        if (slow != fast||flag==0)  /*No Cycle*/
        {
            return NULL;
        }
        else
        {
            slow=head;
            while(slow!=fast)
            {
                slow=slow->next;
                fast=fast->next;
            }
        }
        return fast;
    }
};

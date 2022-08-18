/* Time :- O(N) Space :- O(1) */

class Solution
{
    public:
    void removeLoop(Node* head)
    {
        Node* slow=head;
        Node* fast=head;
        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)
            {
                break;
            }
        }
        
        if(slow!=fast)
        {
            return;         /*No cycle case*/
        }
        
        slow=head;
        while(slow!=fast)
        {
            slow=slow->next;
            fast=fast->next;
        }
        
        /*Now Slow will be pointing at starting point of the loop*/
        
        slow=slow->next;
        while(slow->next!=fast)
        {
            slow=slow->next;
        }
        slow->next=NULL;
    }
};

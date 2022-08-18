/* Time :- O(N) Space :- O(1) */

class Solution
{
public:
    ListNode* prev;
    
    ListNode* reverse(ListNode* head)
    {
        if(head==NULL)
        {
           return NULL;
        }
        if(head->next==NULL)
        {
           return head;
        }
       
        ListNode* temp = reverse(head->next);
        head->next->next=head;
        head->next=NULL;
        
        return temp;
    }
    
    ListNode* findMid(ListNode* head)
    {
            ListNode* slow=head;
            ListNode* fast=head;
            while(fast!=NULL&&fast->next!=NULL)
            {
                prev=slow;
                slow=slow->next;
                fast=fast->next->next;
            }
            prev->next=NULL; 
            return slow;
    }
    
    void reorderList(ListNode* head)
    {
        if(head->next==NULL)
        {
            return;
        }
        
        ListNode* second = findMid(head);
        second=reverse(second);
        ListNode* first = head;
        ListNode* ans = new ListNode(-1);
        
        ListNode* temp1;
        ListNode* temp2;
        
        while(first!=NULL&&second!=NULL)
        {
            temp1=first->next;
            temp2=second->next;
            
            ans->next=first;
            ans=ans->next;
            
            ans->next=second;
            ans=ans->next;
            
            first=temp1;
            second=temp2;
        }
    }
};

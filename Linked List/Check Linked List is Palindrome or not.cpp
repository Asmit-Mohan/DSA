class Solution
{
public:
    ListNode* reverse(ListNode* head)
    {
        if(head==NULL||head->next==NULL)
        {
            return head;
        }
         ListNode* ans=reverse(head->next);
         ListNode* nextNode=head->next;
         nextNode->next=head;
         head->next=NULL;
         return ans;
    }
    bool isPalindrome(ListNode* head)
    {
        ListNode* slow=head;
        ListNode* fast=head;
        
        while(fast!=NULL&&fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        slow=reverse(slow);
        while(slow!=NULL)
        {
            if(head->val!=slow->val)
            {
                return 0;
            }
            slow=slow->next;
            head=head->next;
        }
        return 1;
    }
};

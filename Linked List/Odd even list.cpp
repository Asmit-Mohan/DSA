class Solution 
{
public:
    ListNode* oddEvenList(ListNode* head)
    {
        if(head==NULL)
        {
            return head;
        }
        
        ListNode* a=head;
        ListNode* b=head->next;
        ListNode* head1=head->next;
        
        if(a==NULL||b==NULL)
        {
            return head;
        }
        while(a->next!=NULL&&b->next!=NULL)
        {
            a->next=b->next;
            a=b->next;
            b->next=a->next;
            b=b->next;
        }
        
        a->next=head1;
        return head;
    }
};

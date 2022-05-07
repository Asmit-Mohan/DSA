class Solution
{
    public:
    ListNode* reverseKGroup(ListNode* head, int k)
    {
        ListNode * temp = head;
        for (int i=0; i<k; ++i)
        {
           if (temp==NULL)
           {
               return head;
           }
           temp = temp->next;
        }
        
        ListNode* prePtr=NULL;
        ListNode* currPtr=head;
        ListNode* nextPtr;
        int count=0;
        
        while(count<k&&currPtr!=NULL)
        {
            nextPtr=currPtr->next;
            currPtr->next=prePtr;
            prePtr=currPtr;
            currPtr=nextPtr;
            count++;
        }
        
        if(nextPtr!=NULL)
        {
            head->next= reverseKGroup(nextPtr,k);
        }
        return prePtr;
    }
};

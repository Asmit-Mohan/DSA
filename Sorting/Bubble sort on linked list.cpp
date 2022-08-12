/* Time :- O(n*n) space :- O(1) */

class Solution
{
public:
    ListNode* sortList(ListNode* head)
    {
        if(head == NULL || head->next == NULL)
        {
            return head;
        }
        ListNode* curr = head;
        
        while(curr->next!=NULL)
        {
            ListNode* temp = curr->next;
            while(temp!=NULL)
            {
                if(temp->val<curr->val)
                {
                    swap(temp->val,curr->val);
                }
                temp=temp->next;
            }
            curr=curr->next;
        }
        return head;
    }
};

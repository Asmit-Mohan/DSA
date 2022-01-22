class Solution
{
public:
    void solve(ListNode* first,ListNode* second)
    {
        swap(first->val,second->val);
        if(second->next&&second->next->next)
        {
            solve(second->next,second->next->next);
        }
    }
    ListNode* swapPairs(ListNode* head)
    {
        if(head&&head->next)
        {
            solve(head,head->next);
        }
        return head;
    }
};

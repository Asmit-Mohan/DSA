/* Time :- O(N) Space :- O(1) Iterative Method */

class Solution
{
public:
    ListNode* swapPairs(ListNode* head)
    {
        ListNode* root = head;
        ListNode* nextN = NULL;
        ListNode* prev = NULL;
        
        while (root != NULL && root->next != NULL)
        {
            nextN = root->next;    
            root->next = nextN->next;
            nextN->next = root;            
            
            if (prev != NULL)
            {
                prev->next = nextN;
            }
            else
            {
                head = nextN;
            }
            prev = root;
            if (root->next != NULL)
            {
                root = root->next;
            }
        }
        return head;
    }
};

/* Recursion :- O(N) Space :- O(1) */

class Solution
{
public:
    ListNode* swapPairs(ListNode* head)
    {
        if(head == NULL || head->next == NULL)
        {
            return head;
        }
        ListNode *res = head->next;
        head->next = swapPairs(head->next->next);
        res->next = head;
        return res;
    }
};

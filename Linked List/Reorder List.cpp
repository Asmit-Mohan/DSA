class Solution
{
public:
    int length(ListNode* head)
    {
        int n = 0;
        while (head)
        {
            head = head->next;
            n++;
        }
        return n;
    }
    
    void reorderList(ListNode* head)
    {
        int n = length(head);
        queue<ListNode*> q;
        stack<ListNode*> s;
        
        ListNode* curr = head;
        for (int i = 0; i < n / 2; i++)
        {
            q.push(curr);
            curr = curr->next;
        }
        
        if (n % 2 == 1)
        {
            q.push(curr);
            curr = curr->next;
        }
    
        while (curr!=NULL)
        {
            s.push(curr);
            curr = curr->next;
        }

        ListNode* prev =new ListNode(0);
        for (int i = 0; i < n; i++)
        {
            ListNode* temp = NULL;
            if (i % 2 == 0)
            {
                temp = q.front();
                q.pop();
            }
            else
            {
                temp = s.top();
                s.pop();
            }
            prev->next = temp;
            prev = temp;
        }
        
        prev->next = NULL;
    }
};

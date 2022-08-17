/* Time :- O(N) Space :- O(1) */

/* GFG Question Solution */

class Solution
{
    public:
    Node* rotate(Node* head, int k)
    {
        Node* ptr=head;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=head;
        ptr=head;
        k--;
        
        while(k--)
        {
            ptr=ptr->next;
        }
        head=ptr->next;
        ptr->next=NULL;
        return head;
    }
};

/* Time :- O(N) Space :- O(1) */

/* Leetcode Question Solution*/

class Solution
{
public:
    ListNode* rotateRight(ListNode* head, int k)
    {
        if(head==NULL||head->next==NULL||k==0)
        {
            return head;
        }
        int count=0;
        ListNode* curr=head;
        while(curr!=NULL)
        {
            count++;
            if(curr->next==NULL)
            {
                curr->next=head;
                break;
            }
            curr=curr->next;
        }
        
        k=k%count;
        count=count-k-1;
        while(count--)
        {
            head=head->next;
        }
        ListNode* ans=head->next;
        head->next=NULL;
        return ans;
    }
};

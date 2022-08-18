/* Approach 1 Time :- O(N) and Space O(N) */

class Solution
{
public:
    Node* divide(int N, Node *head)
    {
         Node* ans = new Node(0);
         Node* res=ans;
         Node* ptr=head;
         
         while(ptr!=NULL)
         {
             if(ptr->data%2==0)
             {
                 Node* temp = new Node(ptr->data);
                 res->next=temp;
                 res=res->next;
             }
             ptr=ptr->next;
         }
         ptr=head;
         while(ptr!=NULL)
         {
             if(ptr->data%2==1)
             {
                 Node* temp = new Node(ptr->data);
                 res->next=temp;
                 res=res->next;
             }
             ptr=ptr->next;
         }
         return ans->next;
    }
};

/* Approach 2 Time :- O(N) Space :- O(1) */

class Solution 
{
public:
    ListNode* oddEvenList(ListNode* head)
    {
        if(head==NULL || head->next==NULL)
        {
          return head;
        }
        ListNode *odd = head;
        ListNode *even = head->next;
        ListNode *even_head = head->next;
        
        while(even && even->next)
        {
            odd->next = odd->next->next;
            even->next = even->next->next;
            odd = odd->next;
            even = even->next;
        }
        odd->next = even_head;
        return head;
    }
};

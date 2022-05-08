/* Time :- O(N) and Space O(N) */
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

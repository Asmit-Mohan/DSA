/* Time :- O(n) Space :- O(1) */

class Solution
{
  public:
    Node *sortedInsert(struct Node* head, int data)
    {
        Node* temp = new Node(data);
        Node* curr=head;
        
        if(data<=head->data)
        {
            temp->next=head;
            return temp;
        }
        else
        {
            Node* prev=NULL;
            while(curr!=NULL&&data>curr->data)
            {
                prev=curr;
                curr=curr->next;
            }
            if(curr==NULL)
            {
                prev->next=temp;
                temp->next=NULL;
            }
            else
            {
                prev->next=temp;
                temp->next=curr;
            }
            return head;
        }
    }
};

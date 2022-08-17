/* Time :- O(N) Space :- O(1) */

class Solution
{
    public:
    Node *sortedInsert(Node* head, int data)
    {
        Node* temp = new Node(data);
        Node* curr=head;
        
        if(data<head->data)
        {
            while(curr->next!=head)
            {
                curr=curr->next;
            }
            curr->next=temp;
            temp->next=head;
            return temp;
        }
        else
        {
            while(curr->next->data<data)
            {
                curr=curr->next;
            }
            temp->next=curr->next;
            curr->next=temp;
            return head;
        }
    }
};

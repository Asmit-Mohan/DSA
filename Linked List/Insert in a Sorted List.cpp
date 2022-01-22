class Solution
{
  public:
    Node *sortedInsert(struct Node* head, int data)
    {
        Node* temp = new Node(data);
        if(head->next==NULL)
        {
            if(head->data>data)
            {
                temp->next=head;
                head->next=NULL;
                head=temp;
            }
            else
            {
                head->next=temp;
                temp->next=NULL;
            }
        }
        else if(head->data>=data)
        {
            temp->next=head;
            head=temp;
        }
        else
        {
            Node* ptr=head;
            Node* preptr;
            while(ptr!=NULL&&ptr->data<data)
            {
                preptr=ptr;
                ptr=ptr->next;
            }
            preptr->next=temp;
            temp->next=ptr;
        }
        return head;
    }
};

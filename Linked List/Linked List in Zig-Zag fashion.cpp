class Solution
{
    public:
    Node *zigZag(Node* head)
    {
        int pos=0;
        Node* ptr=head;
        while(ptr!=NULL&&ptr->next!=NULL)
        {
            if(pos%2==0)
            {
                if(ptr->data>ptr->next->data)
                {
                    swap(ptr->data,ptr->next->data);
                }
            }
            else
            {
                if(ptr->data<ptr->next->data)
                {
                    swap(ptr->data,ptr->next->data);
                }
            }
            pos++;
            ptr=ptr->next;
        }
        return head;
    }
};

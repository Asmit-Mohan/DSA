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

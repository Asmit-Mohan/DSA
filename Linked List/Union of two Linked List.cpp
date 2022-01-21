struct Node* makeUnion(struct Node* head1, struct Node* head2)
{
    set<int,greater<int>>s;
    Node* ptr1 = head1;
    Node* ptr2 = head2;
    while(ptr1||ptr2)
    {
        if(ptr1)
        {
            s.insert(ptr1->data);
            ptr1 = ptr1 -> next;
        }
        if(ptr2)
        {
            s.insert(ptr2->data);
            ptr2 = ptr2 -> next;
        }
    }
    Node* p = NULL;
    for(auto i = s.begin();i!=s.end();i++)
    {
        Node* temp = new Node(*i);
        temp->next = p;
        p = temp;
    }
    return p;
}

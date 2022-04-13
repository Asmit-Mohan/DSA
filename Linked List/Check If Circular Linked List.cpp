bool isCircular(Node *head)
{
    if(head->next==head)
    {
        return 1;
    }
    Node* temp=head->next;
    while(temp!=NULL&&temp!=head)
    {
        if(temp->next==head)
        {
            return 1;
        }
        temp=temp->next;
    }
    return 0;
}

int GetNth(struct node* head, int index)
{
    node* ptr=head;
    for(int i=1;i<index;i++)
    {
        ptr=ptr->next;
    }
    return ptr->data;
}

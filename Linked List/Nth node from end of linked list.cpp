/* Time :- O(N) Space :- O(1) */

int getNthFromLast(Node *head, int n)
{
    Node* temp=head;
    int m=0;
    while(temp!=NULL)
    {
        temp=temp->next;
        m++;
    }
    if(n>m)
    {
        return -1;
    }
    else
    {
    m=m-n+1;
    temp=head;
    while(--m)
    {
        temp=temp->next;
    }
    return temp->data;
    }
}

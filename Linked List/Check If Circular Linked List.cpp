/* Time :- O(N) Space :- O(1) */

bool isCircular(Node *head)
{
    if(head->next==NULL)
    {
        return 0;
    }
    if(head->next->next==head)
    {
        return true;
    }
    
    Node* temp = head->next;
    while(temp->next!=head)
    {
        if(temp->next==NULL)
        {
            return 0;
        }
        temp=temp->next;
    }
    return 1;
}

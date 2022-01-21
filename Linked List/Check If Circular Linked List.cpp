bool isCircular(Node *head)
{
    if(head->next==NULL)
    {
        return 0;
    }
    else if(head->next==head)
    {
        return 1;
    }
    else
    {
        int flag=0;
        Node* ptr=head;
        while(ptr!=NULL)
        {
            if(ptr->next==head)
            {
                flag=1;
                break;
            }
            ptr=ptr->next;
        }
        return flag;
    }
}

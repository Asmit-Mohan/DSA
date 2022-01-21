/*Approach 1*/

Node* deleteMid(Node* head)
{
    int count=0;
    Node* ptr=head;
    while(ptr!=NULL)
    {
        count++;
        ptr=ptr->next;
    }
    if(count%2!=0)
    {
        count=(count+1)/2;
    }
    else
    {
        count=(count/2)+1;
    }
        ptr=head;
        count=count-2;
        while(count--)
        {
            ptr=ptr->next;
        }
        ptr->next=ptr->next->next;
        return head;
}

/*Approach 2*/

Node* deleteMid(Node* head)
{
    if(head==NULL||head->next==NULL)
    {
        Node* temp=NULL;
        return temp;
    }
    else if(head->next->next==NULL)
    {
        head->next=NULL;
        return head;
    }
    else
    {
        Node* slow=head;
        Node* fast=head;
        while(fast!=NULL&&fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        slow->data=slow->next->data;
        slow->next=slow->next->next;
        return head;
    }
}

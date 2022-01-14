void MyQueue:: push(int x)
{
    QueueNode* res=new QueueNode(x);
    res->next=NULL;
    if(front==NULL)
    {
        front=rear=res;
    }
    rear->next=res;
    rear=rear->next;   
}
int MyQueue :: pop()
{
    if(front==NULL)
    {
        front=rear=NULL;
        return -1;
    }
    int temp=front->data;
    if(front==rear)
    {
        front=rear=NULL;
    }
    else
    {
        front=front->next;
    }
    return temp;          
}

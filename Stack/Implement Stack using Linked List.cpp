void MyStack ::push(int x) 
{
    StackNode* ptr=new StackNode(x);
    ptr->data=x;
    ptr->next=top;
    top=ptr; 
}

int MyStack ::pop() 
{
    int t=-1;
    if(top!=NULL)
    {
        t=top->data;
        top=top->next;
    }
    return t;
}

void MyStack :: push(int x)
{
    top++;
    arr[top]=x;
}

int MyStack :: pop()
{
    if(top==-1)
    {
        return -1;
    }
    else
    {
    top--;
    return arr[top];       
    }     
}

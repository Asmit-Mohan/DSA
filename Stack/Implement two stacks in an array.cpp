/* Time :- O(1) Space :- O(1) For all 4 operations */

void twoStacks :: push1(int x)
{
    if(top1<top2)
    {
        arr[++top1]=x;
    }
}
void twoStacks ::push2(int x)
{
    if(top1<top2)
    {
        arr[--top2]=x;
    }
}
int twoStacks ::pop1()
{
	if(top1==-1)
	{
	    return -1;
	}
	else
	{
	return arr[top1--];
	}
}
int twoStacks :: pop2()
{
	if(top2==size)
	{
	    return -1;
	}
	else
	{
	    return arr[top2++];
	}
}

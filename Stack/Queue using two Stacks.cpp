/* Time :- O(n) for pop() and O(1) for push() && Space :- O(1) */

void StackQueue :: push(int x)
{
     s1.push(x);
}
int StackQueue :: pop()
{
        if(s1.empty())
        {
            return -1;
        }
        while(!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        int top=s2.top();
        s2.pop();
        while(!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
        return top;  
}

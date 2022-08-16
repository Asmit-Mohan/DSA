/* Time :- O(1) for push() and O(N) for pop() && Space :- O(1) for both method */

void QueueStack :: push(int x)
{
    q1.push(x);
    while(!q1.empty()) 
    {
        q2.push(q1.front());
        q1.pop();
    }
}
int QueueStack :: pop()
{
        int temp;
        int count=0;
        if(q2.empty())
        {
            return -1;
        }
        else
        {
            while(!q2.empty())
            {
                q1.push(q2.front());
                q2.pop();
                count++;
            }
            count--;
            while(count--)
            {

                 q2.push(q1.front());
                 q1.pop();
            }
            temp=q1.front();
            q1.pop();
        }
        return temp;     
}

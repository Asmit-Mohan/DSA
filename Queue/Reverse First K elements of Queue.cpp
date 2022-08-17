/* Time :- O(N) Space :- O(K) */

queue<int> modifyQueue(queue<int> q, int k)
{
    stack<int>s;
    int size=q.size();
    
    for(int i=0;i<k;i++)
    {
        s.push(q.front());
        q.pop();
    }
    while(!s.empty())
    {
        q.push(s.top());
        s.pop();
    }
    size=size-k;
    
    while(size--)
    {
        q.push(q.front());
        q.pop();
    }
    return q;
}

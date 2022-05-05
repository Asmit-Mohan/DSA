void interLeaveQueue(queue < int > & q) 
{
    queue<int>q1;
	queue<int>q2;
	int n=q.size()/2;
	while(n--)
	{
		q1.push(q.front());
		q.pop();
	}
	n=q.size();
	while(n--)
	{
		q2.push(q.front());
		q.pop();
	}
	while(!q1.empty()&&!q2.empty())
	{
		q.push(q1.front());
		q1.pop();
		q.push(q2.front());
		q2.pop();
	}
}

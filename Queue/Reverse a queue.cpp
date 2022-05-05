void reverse(queue < int > & q)
{
  if(q.size()==1)
	{
		return;
	}
	int temp=q.front();
	q.pop();
	reverse(q);
	q.push(temp);
}

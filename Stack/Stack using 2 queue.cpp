/* Time :- O(1) for push() and O(N) for pop() && Space :- O(1) for both method */

class Stack
{
	queue<int> q1, q2;
	public:
	
	void push(int x)
	{
		q2.push(x);
		while (!q1.empty())
		{
			q2.push(q1.front());
			q1.pop();
		}
		queue<int> q = q1;
		q1 = q2;
		q2 = q;
	}

	void pop()
	{
		if (q1.empty())
		{
			return;
		}
		else
		{
			q1.pop();
		}
	}

	int top()
	{
		if (q1.empty())
		{
			return -1;
		}
		else
		{
			return q1.front();
		}
	}

	int size()
	{
		return q1.size();
	}
};

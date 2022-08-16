/* Time :- O(n) */

void print(list<int> &A)
{
    if(A.empty())
	{
        cout << -1 << "\n";
        return;
    }
    for(auto x: A)
    {
        cout << x << " ";
    }
    cout << "\n";	
}

/* Time :- O(1) */

void remove_from_back(list<int> &A)
{
   A.pop_back();
}

/* Time :- O(1) */

void remove_from_front(list<int> &A)
{
   A.pop_front();
}

/* Time :- O(1) */

void add_to_list(list<int> &A,int x)
{ 
    A.push_back(x);
}

/* Time :- O(nlogn) */

void sort_list(list<int> &A)
{
    A.sort();
}

/* Time :- O(N) */

void reverse_list(list<int> &A)
{
    A.reverse();
}

/* Time :- O(1) */

int size_of_list(list<int> &A)
{
    return A.size();
}

/* Time :- O(1) */

void add_from_front(list<int> &A,int x)
{
    A.emplace_front(x);	
}

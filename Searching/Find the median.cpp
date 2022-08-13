/* Time :- O(Nlogn) Space :- O(1) */

class Solution
{
public:
    int find_median(vector<int> v)
    {
	sort(v.begin(),v.end());
	if(v.size()%2!=0)
	{
	    return v[v.size()/2];
	}
	else
	{
	    int a=v[v.size()/2];
	    int b=v[v.size()/2-1];
	    return (a+b)/2;
	}
    }
};

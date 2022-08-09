/* Time :- O(N+M) Space :- O(M) */ 

class Solution
{
	public:
	vector<long long> findMissing(long long A[], long long B[], int N, int M) 
	{ 
	   unordered_set<long long>s;
	   vector<long long>v;
	   for(int i=0;i<M;i++)
	   {
	        s.insert(B[i]);
	   }
	   for(int i=0;i<N;i++)
	   {
		if(s.find(A[i])==s.end())
		{
		   v.push_back(A[i]);
		}
	   }
	   return v;
	} 
};

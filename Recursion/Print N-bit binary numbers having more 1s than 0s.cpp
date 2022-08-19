/* Time :- O(2^n) Space :- O[n*(2^n)] */

/* Solve function time complexity is O(1) and solve function is called O(2^n) times so overall time is --> O(2^n) */

class Solution
{
public:	
    void solve(string op,int one,int zero,int n,vector<string>&ans)
    {
        if(n==0)
        {
            ans.push_back(op);
            return;
        }
        string op1=op;
        op1.push_back('1');
        solve(op1,one-1,zero,n-1,ans);
        if(zero>one)
        {
            string op2=op;
            op2.push_back('0');
            solve(op2,one,zero-1,n-1,ans);
        }
        return;
    }
	vector<string> NBitBinary(int N)
	{
	    string op;
	    int one=N-1;
	    int zero=N;
	    op.push_back('1');
	    vector<string>ans;
	    solve(op,one,zero,N-1,ans);
	    return ans;
	}
};

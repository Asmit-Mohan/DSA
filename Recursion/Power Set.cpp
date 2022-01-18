class Solution
{
	public:
	void solve(string s,string op,vector<string>&ans)
	{
	    if(s.length()==0)
	    {
	        if(op!="")
	        {
	            ans.push_back(op); /*Not Required Empty String*/
	        }
	        return;
	    }
	    string op1=op;
	    string op2=op;
	    op2.push_back(s[0]);
	    s.erase(s.begin()+0);
	    solve(s,op1,ans);
	    solve(s,op2,ans);
	    return;
	}
	vector<string> AllPossibleStrings(string s)
	{
		 string op="";
		 vector<string>ans;
		 solve(s,op,ans);
		 sort(ans.begin(),ans.end());
		 return ans;
	}
};

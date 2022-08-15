/* Time :- O(N) Space :- O(N) */

class Solution
{
public:
    string removeDuplicates(string str)
    {
	 string ans="";
	 unordered_map<char,bool>mp;   
	 for(auto x : str)
	 {
	     if(mp.find(x)==mp.end())
	     {
	         ans+=x;
	         mp[x]=1;
	     }
	 }
        return ans;
    }
};

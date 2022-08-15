/* GFG Order Preserved as in given input string [Not Lexicographical order] Time :- O(N) Space :- O(N) */

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

/* Leetcode :- Lexicographical Ordering */

class Solution
{
public:
    string removeDuplicateLetters(string s)
    {
        int hash[26]={0};
        int visited[26]={0};
        string ans="";
        
        for(auto x : s)
        {
            hash[x-'a']++;
        }
        
        for(auto it : s)
        {
            hash[it-'a']--;
            if(visited[it-'a']==0)
            {
                while(ans.length()>0&&ans.back()>it&&hash[ans.back()-'a']>0)
                {
                    visited[ans.back()-'a']=0;
                    ans.pop_back();
                }
                ans.push_back(it);
                visited[it-'a']=1;
            }
        }
        return ans;
    }
};

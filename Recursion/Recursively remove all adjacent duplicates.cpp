/* Using Recursion */

class Solution
{
public:
     void solve(string &s, int i)
     {
        if(i == 0 || s.length() == 0)
        {
            return;
        }
        if(s[i]== s[i-1])
        {
            s.erase(i-1,2);
        }
        solve(s,i-1);
     }
    string removeDuplicates(string s)
    {
         solve(s, s.length() - 1);
         return s;
    }
};

/* Using Stack :- O(N) Space :- O(N) */

class Solution
{
public:
    string removeDuplicates(string s)
    {
    string res="";
    stack<char> st;
    for(int i=0;i<s.size();i++)
    {
        if(st.size()==0)
        {
            st.push(s[i]);
        }
        else
        {
            if(st.top() == s[i])
            {
                st.pop();
            }
            else
            {
                st.push(s[i]);
            }
        }
    }
    
    while(!st.empty())
    {
        char top = st.top();
        st.pop();
        res.push_back(top);
    }
    reverse(res.begin(),res.end());
    return res;
    }
};

/*Without Stack*/
class Solution
{
public:
string removeDuplicates(string s)
{
	string str="";
	string old="temp";   //can be any string to avoid garbage
	while(old!=str)
	{
		int i=0;
		old=str;
		str="";
		while(s[i])
		{
			if(s[i]!=s[i+1])
			{
				str+=s[i];
				i++;
			}
			if(s[i+1] && s[i+1]==s[i])
			{
				while(s[i+1] && s[i]==s[i+1])
				{
					i++;
				}
				i++;
			}
		}
		s=str;
	}
	return str;
}
};

// we have to repeat ur code until there are no duplicates in the string.
// we are using this ie. while(old!=str) becoz code of techdose failed in below commented test case
// abccbccba  -> Its Correct output is (empty string) And Your Code's output is: abbba

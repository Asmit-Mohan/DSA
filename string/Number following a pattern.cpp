/* Approach 1 Time :- O(N) Space :- O(N) */

class Solution
{   
public:
    string printMinNumberForPattern(string str)
    {
        int n=str.size();
        stack<int>s;
        string ans="";
        
        for(int i=0;i<=n;i++)
        {
            s.push(i+1);
            
            if(str[i]=='I' or i==n)
            {
                while(!s.empty())
                {
                    ans+=to_string(s.top());
                    s.pop();
                }
            }
        }
        return ans; 
    }
};

/* Approach 2 Time :- O(N) Space :- O(1) */

class Solution
{   
public:
string findMinNumberPattern(string str)
{
    string ans = "";  
    int i = 0;
    int cur = 1; 
    int dCount = 0; 
	
    while (i < str.length())
    {
        char ch = str[i];
        if (i == 0 && ch == 'I')
        {
            ans += to_string(cur);
            cur++;
        }
        if (ch == 'D')
        {
            dCount++;
        }
 
        int j = i + 1;
        while (j < str.length()&& str[j] == 'D')
	{
            dCount++;
            j++;
        }
 
        int k = dCount; 
        while (dCount >= 0)
        {
            ans += to_string(cur + dCount);
            dCount--;
        }
        cur += (k + 1);
        dCount = 0;
        i = j;
    }
    return ans; 
   }
};

/* Time :- O(N*N) Space :- O(2*N) */

class Solution
{
public:
    bool repeatedSubstringPattern(string s)
    {
        int n=s.size(); 
        string temp=s+s;
        
        for(int i=1;i<n;i++)
        {
            string ans=temp.substr(i,n);
            if(ans==s)
            {
                return true;
            }
        }
        return false;
    }
};

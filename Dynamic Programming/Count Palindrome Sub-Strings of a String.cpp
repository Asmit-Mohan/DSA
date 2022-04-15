/*Brute Force Time :- O(N^3) Space :- O(1) */

bool ispalin(char arr[],int i,int j)
{
    int flag=1;
    while(i<j)
    {
        if(arr[i]!=arr[j])
        {
            flag=0;
            break;
        }
        i++;
        j--;
    }
    return flag;
}

int CountPS(char arr[], int n)
{
    int count=0;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            count=count+ispalin(arr,i,j);
        }
    }
    return count;
}

/*DP Approach Time :- O(N^2) Space :- O(N^2) */

class Solution
{
public:
bool isPal(int i,int j,string& s,vector<vector<int> >& dp)
{
    if(i>=j)
    {
        return dp[i][j]=1;
    }
    if(dp[i][j] != -1)
    {
        return dp[i][j];
    }
    if(s[i] != s[j])
    {
        return dp[i][j] = 0;
    }
    return dp[i][j] = isPal(i+1,j-1,s,dp);   
}    
    
int countSubstrings(string s)
{
    if(s.length()==1)
    {
        return 1;
    }
    
    int n = s.size();
    int count = 0;
    vector<vector<int>> dp(n,vector<int>(n,-1));
    
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            if(isPal(i,j,s,dp))
            {
                count++;
            }
        }
    }
    return count;
}
};

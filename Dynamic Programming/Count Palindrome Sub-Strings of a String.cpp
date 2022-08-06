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
    int dp[1001][1001];
    bool isPalin(int i,int j,string &str)
    {
        if(i>=j)
        {
            return dp[i][j]=1;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        if(str[i]!=str[j])
        {
            return dp[i][j]=0;
        }
        return dp[i][j]=isPalin(i+1,j-1,str);
    }
    
    int countSubstrings(string str)
    {
        int count=0;
        int n=str.length();
        memset(dp,-1,sizeof(dp));
        
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                if(isPalin(i,j,str))
                {
                    count++;
                }
            }
        }
        return count;
    }
};

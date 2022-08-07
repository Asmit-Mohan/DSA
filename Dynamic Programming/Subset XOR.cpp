/* Time :-  O(N*Log(max(arr[i]))) Space:- O(N*N) */ 

class Solution
{
public:
    int subsetXOR(vector<int> arr, int n, int k)
    {
        int max_ele=arr[0];
        for(int i=1;i<n;i++)
        {
            if(arr[i]>max_ele)
            {
                max_ele=arr[i];
            }
        }
       int w = (1 << (int)(log2(max_ele) + 1) ) - 1;
       if(k>w)
       {
           return 0;
       }
       int dp[n+1][w+1];
       for(int i=0;i<n+1;i++)
       {
           for(int j=0;j<w+1;j++)
           {
               dp[i][j]=0;
           }
       }
       dp[0][0]=1;
       for(int i=1;i<n+1;i++)
       {
           for(int j=0;j<w+1;j++)
           {
               dp[i][j]=dp[i-1][j^arr[i-1]]+dp[i-1][j];
           }
       }
       return dp[n][k];
    }
};

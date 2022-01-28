/*Approach 1 Time :- O(N^2) Space :- O(N) */

class Solution
{
public:
    int lengthOfLIS(vector<int>& arr)
    {
        if(arr.size()==1)
        {
            return 1;
        }
        int n=arr.size();
        int dp[10001]={0};
        int res=INT_MIN;
        dp[0]=1;
        
        for(int i=1;i<n;i++)
        {
            int ans=0;
            for(int j=0;j<i;j++)
            {
                if(arr[i]>arr[j])
                {
                    if(dp[j]>ans)
                    {
                        ans=dp[j];
                    }
                }
            }
            
              dp[i]=ans+1;
              res=max(res,dp[i]);
        }
        return res;
    }
};

/*Approach 2 Time :- O(N*LOGN) Space :- O(N) */

class Solution
{
public:
    int lengthOfLIS(vector<int>& a)
    {
       int n=a.size();
       vector<int>v;
       v.push_back(a[0]);
       for(int i=1;i<n;i++)
       {
           if(a[i]>v.back())
           {
               v.push_back(a[i]);
           }
           else
           {
               int idx=lower_bound(v.begin(),v.end(),a[i])-v.begin();
               v[idx]=a[i];
           }
       }
       return v.size();
    }
};

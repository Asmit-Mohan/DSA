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

/* Approach 2 Variation of LCS */

class Solution
{
public:
    int LCS(vector<int>& nums,vector<int>& nums2)
    {
        int m=nums.size();
        int n=nums2.size();
        int dp[m+1][n+1];
        
        for(int i=0;i<m+1;i++)
        {
            for(int j=0;j<n+1;j++)
            {
                if(i==0 || j==0)
                {
                    dp[i][j]=0;
                }
            }
        }
        
         for(int i=1;i<m+1;i++)
         {
            for(int j=1;j<n+1;j++)
            {
                if(nums[i-1]==nums2[j-1])
                {
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else
                {
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[m][n];
    }
    
    int lengthOfLIS(vector<int>& nums)
    {
        vector<int>nums2;
        set<int>s;
        
        for(int i=0;i<nums.size();i++)
        {
            s.insert(nums[i]);
        }
        for(auto x : s)
        {
            nums2.push_back(x);
        }
    
        return LCS(nums,nums2);
    }
};

/*Approach 3 Time :- O(N*LOGN) Space :- O(N) */

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

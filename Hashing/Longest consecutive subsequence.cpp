/* Approach 1  --> Efficient Approach Time :- O(N) Space :- O( Maximum of arr[i] ) */

class Solution
{
    public:
    int findLongestConseqSubseq(int arr[], int n)
    {
      int x[100001]={0};
      for(int i=0;i<n;i++)
      {
          x[arr[i]]++;
      }
      int ans=0;
      int maxi=INT_MIN;
      for(int i=0;i<100001;i++)
      {
          if(x[i]>0)
          {
              ans++;
          }
          else
          {
              ans=0;
          }
          maxi=max(maxi,ans);
      }
      return maxi;
    }
};

/* Approach 2 Less Efficient Time :- O(Nlogn) Space :- O(1) */

class Solution
{
public:
    int longestConsecutive(vector<int>& nums)
    {
        int n=nums.size();
        if(n==0)
        {
            return 0;
        }
        if(n==1)
        {
            return 1;
        }
        sort(nums.begin(),nums.end());
        long long count=1;
        long long ans=0;
        for(int i=1;i<n;i++)
        {
            if(nums[i]==nums[i-1])
            {
                continue;
            }
            if((nums[i]-nums[i-1])==1)
            {
                count++;
                ans=max(ans,count);
            }
            else
            {
                count=1;
            }
        }
        if(ans==0)
        {
            return 1;
        }
        return ans;    
    }
};

/* Time :- O(N*N) Space O(1) */

class Solution
{
  public:
  long long left(int l,int r,vector<long long int>& nums)
  {
       long long ans=1;
       for(int i=l;i<=r;i++)
       {
           ans=ans*nums[i];
       }
       return ans;
  }
  long long right(int l,int r,vector<long long int>& nums)
  {
       long long ans=1;
       for(int i=l;i<r;i++)
       {
           ans=ans*nums[i];
       }
       return ans;
  }
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n)
    {
        vector<long long int>v(n,0);
        for(int i=1;i<n;i++)
        {
            long long l=left(0,i-1,nums);
            long long r=right(i+1,n,nums);
            long long ans=l*r;
            v[i]=ans;
        }
        long long ans=1;
        for(int i=1;i<n;i++)
        {
            ans=ans*nums[i];
        }
        v[0]=ans;
        return v;
    }
}

/* Time :- O(N) Space :- O(N) */

class Solution
{
public:
    vector<int> productExceptSelf(vector<int>& nums)
    {
        vector<int>left(nums.size(),1);
        vector<int>right(nums.size(),1);
        vector<int>ans;
        int n=nums.size();
        
        for(int i=1;i<n;i++)
        {
            left[i]=left[i-1]*nums[i-1];
        }
        for(int i=n-2;i>=0;i--)
        {
            right[i]=right[i+1]*nums[i+1];
        }
        for(int i=0;i<n;i++)
        {
            ans.push_back(left[i]*right[i]);
        }
        return ans;
    }
};

/* Time :- O(N) Space :- O(1) */

class Solution
{
public:
    vector<int> productExceptSelf(vector<int>& nums)
    {
        int n = nums.size();
        vector<int>right(n,1);
        right[n-1]=nums[n-1];
        
        for(int i=n-2;i>=0;i--)
        {
            right[i] = nums[i]*right[i+1];
        }
        
        int left=1;
        for(int i=0;i<n;i++)
        {
            if(i==n-1)
            {
                right[i] = left;
            }
            else
            {
                right[i] = right[i+1]*left;
                left = left * nums[i];
            }
        }
        return right;
    }
};

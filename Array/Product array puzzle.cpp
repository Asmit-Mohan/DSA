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
class Solution
{
  public:
    int maxLen(int A[], int n)
    {
        int z=0;
        int o=0;
        for(int i=0;i<n;i++)
        {
            if(A[i]==0)
            {
                z++;
            }
            else
            {
                o++;
            }
            if(A[i]==0)
            {
                A[i]=-1;
            }
        }
        
        if(o==z)
        {
            return n;
        }
        /*Now the problem is largest subarray with sum==0*/
        int sum=0;
        int ans=0;
        int j=0;
        unordered_map<int,int> mp;
        mp[0]=0;
        int k=0;
        
        while(j<n)
        {
            sum=sum+A[j];
            if(mp.find(sum-k)!=mp.end())  
            {
                ans=max(ans,j-mp[sum-k]+1);
            }
            if(mp.find(sum)==mp.end())
            {
                 mp[sum]=j+1;
            }
            j++;
        }
        return ans;
           
    }
};
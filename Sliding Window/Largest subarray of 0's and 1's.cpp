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
                A[i]=-1;
            }
            else
            {
                o++;
            }
        }
        
        if(o==z)
        {
            return n;
        }
        /*Now the problem is largest subarray with sum==0*/
        int sum=0;
        int ans=INT_MIN;
        int j=0;
        unordered_map<int,int> mp;
        mp[0]=0;
        
        while(j<n)
        {
            sum=sum+A[j];
            if(mp.find(sum)!=mp.end())  
            {
                ans=max(ans,j-mp[sum]+1);
            }
            else
            {
                 mp[sum]=j+1;
            }
            j++;
        }
        return ans==INT_MIN?0:ans;
           
    }
};

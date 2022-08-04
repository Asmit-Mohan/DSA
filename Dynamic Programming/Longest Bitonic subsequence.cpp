/* Time :- O(N*N) Space :- O(N) */

class Solution
{
    public:
    int LongestBitonicSequence(vector<int>nums)
    {
        int n=nums.size();
        int lis[n];
        memset(lis,0,sizeof(lis));
        for(int i=0;i<n;i++)
        {
            int maxi=0;
            for(int j=0;j<i;j++)
            {
                if(nums[i]>nums[j])
                {
                    if(lis[j]>maxi)
                    {
                        maxi=lis[j];
                    }
                }
            }
            lis[i]=maxi+1;
        }
        
        int lds[n];
        memset(lds,0,sizeof(lds));
        for(int i=n-1;i>=0;i--)
        {
            int maxi=0;
            for(int j=n-1;j>i;j--)
            {
                if(nums[i]>nums[j])
                {
                    if(lds[j]>maxi)
                    {
                        maxi=lds[j];
                    }
                }
            }
            lds[i]=maxi+1;
        }
        int res=0;
        for(int i=0;i<n;i++)
        {
            if(lis[i]+lds[i]-1>res)
            {
                res=lis[i]+lds[i]-1;
            }
        }
        return res;
    }
};

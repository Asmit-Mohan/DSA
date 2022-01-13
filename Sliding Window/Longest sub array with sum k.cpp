class Solution
{
    public:
    int lenOfLongSubarr(int A[],  int n, int k) 
    { 
        int sum=0;
        int ans=0;
        int j=0;
        unordered_map<int,int> mp;
        mp[0]=0;
        
        while(j<n)
        {
            sum=sum+A[j];
            if(mp.find(sum-k)!=mp.end())  
            {
                ans=max(ans,j-mp[sum-k]+1);
            }
            /*if sum got then size of subarray is current index - index of last element of previous subarray*/
            if(mp.find(sum)==mp.end())
            {
                 mp[sum]=j+1;
            }
            j++;
            /*if not then store sum as key and in pair position of last element of that subarray*/
        }
        
        return ans;
    } 
};
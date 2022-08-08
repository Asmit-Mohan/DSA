/* Time :- O(N) Space :- O(N) */

class Solution
{
public:	
    int longSubarrWthSumDivByK(int arr[], int n, int k)
    {
        unordered_map<int,int>mp;
        mp[0]=0;
        int ans=0;
        int sum=0;
        int j=0;
        
        while(j<n)
        {
            sum=sum+arr[j];
            int remain=sum%k;
            if(remain<0)
            {
                remain=remain+k;   /* To make remainder positive, to search in the map */
            }
            
            if(mp.find(remain)!=mp.end())
            {
                ans=max(ans,j-mp[remain]+1);
            }
            
            if(mp.find(remain)==mp.end())
            {
                mp[remain]=j+1;
            }
            j++;
        }
        return ans;  
    }
};

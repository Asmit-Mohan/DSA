/* Time :- O(N) Space :- O(N) */

class Solution
{
    public:
    ll findSubarray(vector<ll> arr, int n)
    {
         ll sum=0;
         ll count=0;
         unordered_map<ll,ll>mp;
         for(int i=0;i<n;i++)
         {
             sum=sum+arr[i];
             if(sum==0)
             {
                 count++;
             }
             if(mp.find(sum)!=mp.end())
             {
                 count+=mp[sum];
             }
             mp[sum]++;
         }
         return count;
    }
};

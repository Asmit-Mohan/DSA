/* Leetcode Question */
class Solution
{
public:
    bool canArrange(vector<int>& arr, int k)
    {
         unordered_map<int,int>mp;
        
         for(auto x : arr)
         {
             int temp = ((x%k)+k)%k;
             mp[temp]++;
         }
         
        for(auto x:arr)
        {
            int rem=(x%k + k)%k;
            if(rem==0)                         
            { 
                if(mp[rem] % 2 ==1)
                {
                    return false;
                }
            }         
            else if(mp[rem] != mp[k - rem])
            {
                return false;
            }
        }
        return true;
    }
};

/* GFG Question Count Pairs Sum Divisible By K */

class Solution
{
    public:
    long long countKdivPairs(int arr[], int n, int K)
    {
        unordered_map<int,int>mp;
        long long ans=0;
        for(int i=0;i<n;i++)
        {
            int key=arr[i];
            int remain=arr[i]%K;
            
            if(remain==0 && mp.find(0)!=mp.end())
            {
                ans+=mp[0];
            }
            else if(mp.find(K-remain)!=mp.end())
            {
                ans+=mp[K-remain];
            }
            mp[remain]++;
        }
        return ans;
    }
};

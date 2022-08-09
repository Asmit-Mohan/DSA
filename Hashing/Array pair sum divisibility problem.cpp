/* Time :- O(N) Space :- O(K) --> Only remainder space */

/* Leetcode Question */

class Solution
{
public:
    bool canArrange(vector<int>& arr, int k)
    {
        unordered_map<int,int> mp;
        
        for(int i=0;i<arr.size();i++)
        {
            mp[(arr[i]%k+k)%k]++;     /* In case of negative arr[i] */
        }
        
        for(int remain=0;remain<k;remain++)
        {
            if(remain!=0 && mp[remain]!=mp[k-remain])
            {
                return false;
            }
            
            if(remain==0&&(mp[remain]%2!=0))
            {
                return false;
            }
        }
        return true;
    }
};


/* GFG Question Count Pairs Sum Divisible By K */

/* Time :- O(N) Space :- O(K) --> Only remainder space */

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

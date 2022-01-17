class Solution
{   
public:
    int getPairsCount(int arr[], int n, int k)
    {
        unordered_map<int,int>mp;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int temp=k-arr[i];
            if(mp[temp])
            {
                ans=ans+mp[temp];
            }
            mp[arr[i]]++;
        }
        return ans;
    }
};

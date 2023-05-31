/* Approach 1  --> Efficient Approach Time :- O(N) Space :- O(N) */

class Solution
{
public:
    int longestConsecutive(vector<int>& nums)
    {
        int ans=INT_MIN;
        unordered_map<int,int>mp;

        for(auto x : nums)
        {
            mp[x]++;
        }
        for(int i=0;i<nums.size();i++)
        {
            int count=0;
            int temp=nums[i];
            if(mp.find(temp-1)==mp.end())
            {
                while(mp.find(temp)!=mp.end())
                {
                    temp++;
                    count++;
                }
                ans=max(ans,count);
            }
        }
        return ans==INT_MIN?0:ans;          
    }
};

/* Approach 2 Less Efficient Time :- O(Nlogn) Space :- O(1) */

class Solution
{
public:
    int longestConsecutive(vector<int>& nums)
    {
        int n=nums.size();
        if(n==0)
        {
            return 0;
        }
        if(n==1)
        {
            return 1;
        }
        sort(nums.begin(),nums.end());
        long long count=1;
        long long ans=0;
        for(int i=1;i<n;i++)
        {
            if(nums[i]==nums[i-1])
            {
                continue;
            }
            if((nums[i]-nums[i-1])==1)
            {
                count++;
                ans=max(ans,count);
            }
            else
            {
                count=1;
            }
        }
        if(ans==0)
        {
            return 1;
        }
        return ans;    
    }
};

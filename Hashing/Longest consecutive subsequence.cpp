/* Approach 1  --> Efficient Approach Time :- O(N) Space :- O(N) */

class Solution
{
public:
    int longestConsecutive(vector<int>& nums)
    {
        int ans=0;
        unordered_set<int>s;
        
        for(int i=0;i<nums.size();i++)
        {
            s.insert(nums[i]);
        }
        
        for(int i=0;i<nums.size();i++)
        {
            if(s.find(nums[i]-1)==s.end())
            {
                int temp = nums[i];
                while(s.find(temp)!=s.end())
                {
                    temp++;
                }
                ans=max(ans,temp-nums[i]);        
            }
        }
        return ans;
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

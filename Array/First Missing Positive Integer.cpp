class Solution
{
public:
    int firstMissingPositive(vector<int>& nums)
    {
        int ans=1;
        int k=0;
        int c=0;
        unordered_map<int,int>mp;
        
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>0)
            {
                c++;
            }
            mp[nums[i]]=i;  
        }
        
        while(k<c)
        {
            if(mp.find(ans)==mp.end()) 
            {
                return ans;
            }
            ans++;
            k++;
        }
        return ans;
    }
};

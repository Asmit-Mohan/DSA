/* Time :- O(N*N) Space :- O(N*N) */

class Solution
{
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4)
    {
        unordered_map<int,int> mp;
        for(auto x : nums1)
        {
            for(auto y : nums2)
            {
                int sum = x+y;
                mp[sum]++;
            }
        }
        
        int ans = 0;
        for(auto x : nums3)
        {
            for(auto y : nums4)
            {
                int sum = -(x+y);
                ans = ans + mp[sum];
            }
        }
        
        return ans;
    }
};

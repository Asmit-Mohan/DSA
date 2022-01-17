class Solution
{
    public:
    vector<vector<int> > fourSum(vector<int> &nums, int target)
    {
        int n = nums.size();
        if (n < 4)
        {
            return {};
        }
        sort( nums.begin(), nums.end());
        vector<vector<int>> result;
        for (int i = 0; i < n - 2; ++i)
        {
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
            for (int j = i + 1; j < n - 1; ++j)
            {
                if (j > i + 1 && nums[j] == nums[j - 1])
                {
                    continue;
                }
                
                int l = j + 1;
                int r = n - 1;
                int t = target - nums[i] - nums[j];
                while (l < r)
                {
                int sum = nums[l] + nums[r];
                if (sum == t)
                {
                        vector<int>temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(nums[l]);
                        temp.push_back(nums[r]);
                        
                        result.push_back(temp);
                        l++;
                        while (l < r && nums[l] == nums[l - 1])
                        {
                            l++;
                        }
                    }
                    else if (sum < t)
                    {
                        l++;
                    }
                    else
                    {
                        r--;
                    }
                }
            }
        }
        return result;
    }
};

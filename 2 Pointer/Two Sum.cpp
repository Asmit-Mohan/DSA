class Solution
{
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        int n=nums.size();
        vector<int>temp(n);
        set<int>ans;
        for(int i=0;i<n;i++)
        {
            temp[i]=nums[i];
        }
        sort(nums.begin(),nums.end());
        int a,b;
        int l=0;
        int r=n-1;
        while(l<r)
        {
            if(nums[l]+nums[r]==target)
            {
                a=nums[l];
                b=nums[r];
                break;
            }
            else if(nums[l]+nums[r]>target)
            {
                r--;
            }
            else
            {
                l++;
            }
        }
        for(int i=0;i<n;i++)
        {
            if(temp[i]==a)
            {
                ans.insert(i);
            }
        }
        for(int i=0;i<n;i++)
        {
            if(temp[i]==b)
            {
                ans.insert(i);
            }
        }
        vector<int>res;
        set<int>::iterator itr;
        for (itr = ans.begin(); itr != ans.end(); itr++)
        {
            res.push_back(*itr);
        }
        return res;
    }
};

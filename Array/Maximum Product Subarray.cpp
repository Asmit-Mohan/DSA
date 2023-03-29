/* Approach 1 */

class Solution
{
public:
    int maxProduct(vector<int>&nums)
    {
        int ans=nums[0];
        int mx=ans;
        int mn=ans;
        
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]<0)
            {
               swap(mx,mn);
            }

            mx=max(nums[i],mx*nums[i]);
            mn=min(nums[i],mn*nums[i]);
            ans=max(ans,mx);
        }
        return ans;    
    }
};

/* Approach 2 */

class Solution
{
public:
    int maxProduct(vector<int>& nums)
    {
        int ans = INT_MIN;
        int p = 1;
        for(int i=0;i<nums.size();i++)
        {
            p=p*nums[i];
            ans=max(p,ans);
            if(p==0)
            {
                p=1;
            }
        }
        p=1;
        for(int i=nums.size()-1;i>=0;i--)
        {
            p=p*nums[i];
            ans =max(ans,p);
            if(p==0)
            {
                p=1;
            }
        }
        return ans;
    }
};

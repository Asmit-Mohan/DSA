class Solution
{
public:
    vector<int> majorityElement(vector<int>& nums)
    {
        int ans1,ans2;
        int count1=0;
        int count2=0;
        
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==ans1)
            {
                count1++;
            }
            else if(nums[i]==ans2)
            {
                count2++;
            }
            else if(count1==0)
            {
                count1=1;
                ans1=nums[i];
            }
            else if(count2==0)
            {
                 count2=1;
                 ans2=nums[i];
            }
            else
            {
                count1--;
                count2--;
            }
        }
        vector<int>v;
        int temp1=ceil(nums.size()/3)+1;
        int temp2=ceil(nums.size()/3)+1;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==ans1)
            {
                temp1--;
            }
            if(nums[i]==ans2)
            {
                temp2--;
            }
        }
        if(temp1<=0)
        {
            v.push_back(ans1);
        }
        if(temp2<=0)
        {
            v.push_back(ans2);
        }
        
        return v;
    }
};

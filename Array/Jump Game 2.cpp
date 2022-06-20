class Solution
{
public:
    int jump(vector<int>& nums)
    {
        int n=nums.size();
        int step=0;
        int current=0;
        int maxreach=0;
        
        for(int i=0;i<n-1;i++)
        {
            maxreach=max(maxreach,i+nums[i]);
            if(i==current)
            {
                step++;
                current=maxreach;
            }
        }
        return step;
    }
};

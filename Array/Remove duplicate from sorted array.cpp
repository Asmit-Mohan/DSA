class Solution
{
public:
    int removeDuplicates(vector<int>& nums)
    {
        int x,a;
        for(int i = 0; i < nums.size(); i++)
        {
            x = nums[i];
            while(i < nums.size() && x == nums[i])
            {
                i++;
            }
            i--;
            nums[a++] = x;
        }
        return a;
    }
};

class Solution
{
public:
    int removeDuplicates(vector<int>& nums)
    {
        int count=0;

        for(int i=0;i<nums.size();i++)
        {
            int temp = nums[i];
            while(i<nums.size()&&temp==nums[i])
            {
                i++;
            }
            i--;
            nums[count++]=temp;
        }
        return count;    
    }
};

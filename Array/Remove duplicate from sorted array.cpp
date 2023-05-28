/* Approach 1 */

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

/* Approach 2 */

class Solution
{
public:
    int removeDuplicates(vector<int>& arr)
    {
        int idx=0;
        int n=arr.size();
        for(int i=0;i<n;i++)
        {
            if(arr[i]!=arr[idx])
            {
                idx++;
                arr[idx]=arr[i];
            }
        }
        return idx+1;
    }
};

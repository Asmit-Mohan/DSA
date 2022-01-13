class Solution
{
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k)
    {
        if(k<=1)
        {
            return 0;
        }
        int n = nums.size();
        // cumulative product of subarray
        int product = 1;
        //count will maintain (the sum) of number of subarrays ending at ith index. 
        int ans = 0;
        // valid left pointer 
        int i = 0;
        // right iterator pointer
        int j = 0;
        
        while(j<n)
        {
            // get cumulative product 
            product =  product*nums[j];
            // loop till product < k to find valid subarray range
            // subarray range holds the valid num of subarrays whos product < k
            while(product>=k)
            {
                product = product/nums[i];
                i++;
            }
            // count valid product subarray
            ans= ans+(j -i + 1);
            j++;
        }
        return ans;
    }
};

/**
 * The idea is always keep an max-product-window less than K;
 * Every time add a new number on the right(j), reduce numbers on the left(i), until the subarray product fit less than k again, (subarray could be empty);
 * Each step introduces x new subarrays, where x is the size of the current window (j + 1 - i);
 * example:
 * for window (5, 2, 6), when 6 is introduced, it add 3 new subarray:
 *       (6)
 *    (2, 6)
 * (5, 2, 6)
 */
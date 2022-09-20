/* Approach 1 Brute Optimal Solution */

void sort012(int a[], int n)
{
    int one=0;
    int two=0;
    int zero=0;
    
    for(int i=0;i<n;i++)
    {
        if(a[i]==0)
        {
            zero++;
        }
        else if(a[i]==1)
        {
            one++;
        }
        else
        {
            two++;
        }
    }
    
    for(int i=0;i<n;i++)
    {
       if(zero!=0&&one!=0&&two!=0)
       {
            a[i]=0;
            zero--;
       }
       else if(zero==0&&one!=0&&two!=0)
       {
            a[i]=1;
            one--;
       }
       else
       {
            a[i]=2;
            two--;
       }
    }
}

/* Approach 2 Efficient using The Dutch Nation Flag Problem */

class Solution
{
public:
    void sortColors(vector<int>& nums)
    {
        int i=0;
        int j=0;
        int k=nums.size()-1;
        
        while(i<=k)
        {
            if(nums[i]==0)
            {
                swap(nums[i],nums[j]);
                i++;
                j++;
            }
            else if(nums[i]==2)
            {
                swap(nums[i],nums[k]);
                k--;
            }
            else
            {
                i++;
            }
        }
    }
};

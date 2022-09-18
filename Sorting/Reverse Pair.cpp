class Solution
{
public:
    void merge(vector<int> &nums,int low,int mid,int high,int &count)
    {
        int k=0;
        int j=mid;
        
        for(int i=low; i<mid; i++)
        {
            while(j<=high and nums[i]>2LL*nums[j])
            {
                j++;
            }
            count+=(j-mid);
        }
        
        int i = low;
        j = mid;
        vector<int> temp(high-low+1);
        
        while(i<mid and j<=high)
        {
            if(nums[i]<nums[j])
            {
                temp[k++]=nums[i++];
            }
            else
            {
                temp[k++]=nums[j++];
            }
        }
        
        while(i<mid)
        {
            temp[k++]=nums[i++];
        }
        while(j<=high)
        {
            temp[k++]=nums[j++];
        }
        for(int k=low; k<=high; k++)
        {
            nums[k]=temp[k-low];
        }
    }
    
    void merge_sort(vector<int> &nums,int low,int high,int &count)
    {
        if(low >= high)
        {
            return;
        }
        
        int mid=low+(high-low)/2;
        merge_sort(nums,low,mid,count);
        merge_sort(nums,mid+1,high,count);
        merge(nums,low,mid+1,high,count);
    }
    
    int reversePairs(vector<int>& nums) 
    {
        int count=0;
        merge_sort(nums,0,nums.size()-1,count);
        return count;
    }
};

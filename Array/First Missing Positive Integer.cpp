/* Naive Approach */
class Solution
{
public:
    int firstMissingPositive(vector<int>& nums)
    {
        int ans=1;
        int k=0;
        int c=0;
        unordered_map<int,int>mp;
        
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>0)
            {
                c++;
            }
            mp[nums[i]]=i;  
        }
        
        while(k<c)
        {
            if(mp.find(ans)==mp.end()) 
            {
                return ans;
            }
            ans++;
            k++;
        }
        return ans;
    }
};

/* Space Optimised Approach */

class Solution
{
public:
    int firstMissingPositive(vector<int>& arr)
    {
        int n=arr.size();
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i]<=0||arr[i]>n)
            {
                arr[i]=n+1;
            }
        }
        
        for(int i=0;i<n;i++)
        {
            if(abs(arr[i])>n)
            {
                continue;
            }
            else if(arr[abs(arr[i])-1]>0)
            {
                arr[abs(arr[i])-1]=-arr[abs(arr[i])-1];
            }
        }
        
        for(int i=0;i<n;i++)
        {
            if(arr[i]>0)
            {
                return i+1;
            }
        }
        return n+1;
    }
};

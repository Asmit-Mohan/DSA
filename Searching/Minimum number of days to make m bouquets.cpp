class Solution
{
public:
    bool isValid(vector<int>arr,int m,int k,int mid)
    {
        int count=0;
        int ans=0;
        for(int i=0;i<arr.size();i++)
        {
            if(mid>=arr[i])
            {
                count++;
            }
            else
            {
                count=0;
            }
            if(count==k)
            {
                ans++;
                count=0;
            }
        }
        return ans>=m?1:0;
    }
    int minDays(vector<int>& arr, int m, int k)
    {
        if((m*k)>arr.size())
        {
            return -1;
        }
        int low=INT_MAX;
        int high=INT_MIN;
        int ans=INT_MAX;
        
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i]<low)
            {
                low=arr[i];
            }
            if(arr[i]>high)
            {
                high=arr[i];
            }
        }
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(isValid(arr,m,k,mid))
            {
                ans=min(ans,mid);
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return ans==INT_MAX?-1:ans;
    }
};

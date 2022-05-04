class Solution
{
    public:
    int minSubset(vector<int> &arr,int n)
    {
        sort(arr.begin(),arr.end());
        reverse(arr.begin(),arr.end());
        
        int count=0;
        long long int sum=0;
        
        for(int i=0;i<n;i++)
        {
            sum+=arr[i];
        }
        long long int res=0;
        for(int i=0;i<n;i++)
        {
            count++;
            res=res+arr[i];
            if(res>(sum-res))
            {
                break;
            }
        }
        return count;
    }
};

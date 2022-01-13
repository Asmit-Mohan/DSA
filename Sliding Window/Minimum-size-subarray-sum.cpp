class Solution
{
public:
    int minSubArrayLen(int k, vector<int>& arr)
    {
         int ans=INT_MAX;
         int i=0;
         int j=0;
         int sum=0;
         int N=arr.size();
        
         while(j<N)
         {
             sum=sum+arr[j];
             if(sum<k)
             {
                 j++;
             }
             
             else if(sum>=k)
             {
                 while(sum>=k)
                 {
                     ans=min(ans,j-i+1);
                     sum=sum-arr[i];
                     i++;
                 }
                 j++;
             }
         }
        if (ans == INT_MAX || ans < 0)
        {
            return 0;
        }
         return ans;
    }
};
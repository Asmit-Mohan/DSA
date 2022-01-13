class Solution
{   
public:
    int maximumSumSubarray(int K,vector<int> &Arr,int N)
    {
         int i=0;
         int j=0;
         int mx=INT_MIN;
         int sum=0;
         while(j<N)
         {
             sum=sum+Arr[j];
             if(j-i+1==K)
             {
                 mx=max(mx,sum);
                 sum=sum-Arr[i];
                 i++;
                 j++;
             }
             else
             {
                 j++;
             }
         }
         return mx ;
    }
};
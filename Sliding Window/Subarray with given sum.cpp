/* Time :- O(N) Space :- O(1) */

class Solution
{
    public:
    vector<int> subarraySum(int arr[], int N, long long k)
    {
         
         int i=0;
         int j=0;
         int sum=0;
         vector<int>v; /* OF fixed size of 2 that is why constant space */
         
         while(j<N)
         {
             sum=sum+arr[j];
             if(sum<k)
             {
                 j++;
             }
 
             if(sum==k)
             {
                 v.push_back(i+1);
                 v.push_back(j+1);
                 break;
             }
 
             if(sum>k)
             {
                 while(sum>k)
                 {
                     sum=sum-arr[i];
                     i++;
                 }
                 if(sum==k)
                 {
                     v.push_back(i+1);
                     v.push_back(j+1);
                     break;
                 }
                 j++;
             }
         }
         if(v.size()==0)
         {
             v.push_back(-1);
             return v;
         }
         else
         {
             return v;    
         }
    }
};

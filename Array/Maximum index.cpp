class Solution
{
    public:
    int maxIndexDiff(int arr[], int n) 
    { 
       int left[n];
       int right[n];
       
       left[0]=arr[0];
       for(int i=1;i<n;i++)
       {
           left[i]=min(left[i-1],arr[i]);
       }
       
       right[n-1]=arr[n-1];
       for(int i=n-2;i>=0;i--)
       {
           right[i]=max(right[i+1],arr[i]);
       }
       
       int i=0;
       int j=0;
       int ans=INT_MIN;
       
       while(i<n&&j<n)
       {
           if(right[j]>=left[i])
           {
               ans=max(ans,j-i);
               j++;
           }
           else
           {
               i++;
           }
       }
       return ans;
    }
};

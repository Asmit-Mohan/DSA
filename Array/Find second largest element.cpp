int print2largest(int arr[], int n)
    {
         int pre=-1;
         int curr=-1;
         for(int i=0;i<n;i++)
         {
             if(arr[i]>curr)
             {
                 pre=curr;
                 curr=arr[i];
             }
             else if(arr[i]>pre&&arr[i]<curr)
             {
                 pre=arr[i];
             }
         }
         return pre;
    }
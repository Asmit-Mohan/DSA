vector<int> minAnd2ndMin(int arr[], int n)
{
    int pre=100001;
    int curr=100001;
    vector<int>v;
    for(int i=0;i<n;i++)
         {
             if(arr[i]<curr)
             {
                 pre=curr;
                 curr=arr[i];
             }
             else if(arr[i]<pre&&arr[i]>curr)
             {
                 pre=arr[i];
             }
         }
         if(pre!=100001&&curr!=100001)
         {
             v.push_back(pre);
             v.push_back(curr);
         }
         else
         {
             v.push_back(-1);
             return v;
         }
             reverse(v.begin(),v.end());
             return v;
}
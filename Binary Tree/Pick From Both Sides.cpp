int Solution::solve(vector<int> &arr, int k)
{
    int total=0;
    for(auto x : arr)
    {
        total+=x;
    }
    k=arr.size()-k;
    if(k==0)
    {
        return total;
    }
        int i=0;
        int j=0;
        int mx=INT_MAX;
        int sum=0;

        while(j<arr.size())
        {
             sum=sum+arr[j];
             if(j-i+1==k)
             {
                 mx=min(mx,sum);
                 sum=sum-arr[i];
                 i++;
                
             }
              j++;
           
        }
        return total-mx;
}

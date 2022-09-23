int findMinimumCoins(int target) 
{
  int ans=0;
  int arr[] = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
  int n = 9;
    
  for (int i = n - 1; i >= 0; i--)
  {
        if(arr[i]<=target)
        {
             int req = target/arr[i];
             target = target - (req*arr[i]);
             ans=ans+req;
        }
  }
  return ans;  
}

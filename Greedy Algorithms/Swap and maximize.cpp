/* Time :- O(Nlogn) Space :- O(1) */

long long int maxSum(int arr[], int n)
{
    sort(arr,arr+n);
    long long sum=0;
    
    int i=0;
    int j=n-1;
    
    while(i<j)
    {
        int diff = abs(arr[i]-arr[j]);
        sum = sum + (2*diff);
        i++;
        j--;
    }
    return sum;
}

/* Time :- O(N*N) [Average and Worst case] :- O(N) [Best Case] Space :- O(1) */

class Solution
{
    public:
    void insert(int arr[], int i)
    {
        int j=i-1;
        int current = arr[i];
        
        while(j>=0&&arr[j]>current) 
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=current;
    }
  
    public:
    void insertionSort(int arr[], int n)
    {
        for(int i=1;i<n;i++)
        {
           insert(arr,i);  
        }
    }
};

/* Recursive Approach O(N*N) [Average and Worst case] :- O(N) [Best Case] Space :- O(N) [ Auxiliary Stack Space ] */

void insertionSortRecursive(int arr[], int n)
{
    if (n < 2)
    {
        return;
    }
    insertionSortRecursive( arr, n-1 );
    int last = arr[n-1];
    int j = n-2;
    while (j >= 0 && arr[j] > last)
    {
        arr[j+1] = arr[j];
        j--;
    }
    arr[j+1] = last;
}

/* Key Points :- (1) It is appropriate for data sets which are already partially sorted (2) In-place Algorithm (3) Stable Algorithm */

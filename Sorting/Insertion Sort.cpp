class Solution
{
    public:
    void insert(int arr[], int i)
    {
        int j=i-1;
        int current = arr[i];
        
        while(j>=0&&arr[j]>arr[i]) 
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

class Solution
{
    public:
    void heapify(int arr[], int n, int i)
    {
        int left=(2*i)+1;
        int right=(2*i)+2;
        int largest=i;
        
        if(left<n&&arr[left]>arr[largest])
        {
            largest=left;
        }
        
        if(right<n&&arr[right]>arr[largest])
        {
            largest=right;
        }
        
        if(i!=largest)
        {
            swap(arr[i],arr[largest]);
            heapify(arr,n,largest);
        }
    }
    
    void buildHeap(int arr[], int n)  /* TC:- O(N) */
    {
        for(int i=n/2-1;i>=0;i--)
        {
            heapify(arr,n,i);
        }
    }
    
    void heapSort(int arr[], int n)
    {
        buildHeap(arr,n);
        for(int i=n-1;i>=0;i--)
        {
            swap(arr[i],arr[0]);  /*We are swapping first element from last element because array is sorted in ascending order*/
            heapify(arr,i,0);  /*And decreasing size of head by 1*/
        }
    }
};

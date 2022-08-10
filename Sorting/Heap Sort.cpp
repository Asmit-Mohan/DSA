/* Time :- O(Nlogn) Space :- O(1) */

class Solution
{
    public:
    void heapify(int arr[], int n, int i)       /* Time :- O(logn) */
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
    
    void buildHeap(int arr[], int n)           /* Time :- O(n*logn) */
    {
        for(int i=n/2-1;i>=0;i--)
        {
            heapify(arr,n,i);
        }
    }
    
    void heapSort(int arr[], int n)
    {
        buildHeap(arr,n);  
        for(int i=n-1;i>=0;i--)              /* Time :- O(n*logn) */
        {
            swap(arr[i],arr[0]);  
            heapify(arr,i,0);
        }
    }
};

/* Key Points :- 

1. Heapify Function Time :- O(log(n)) and Build-Heap :- O(n). 
2. Insertion and Deletion for O(logn) since height of complete binary tree is O(logn) and heap are almost complete binary tree except last level.
3. In Place :- Yes
4. Stable :- No, because the operations that are performed in a heap can change the relative ordering of the equivalent keys. But we can make it.
5. Heap are not divide and conquer rather it uses a heap data structure to efficiently sort its elements.
6. Done in two stage first creation of max heap from array then swapping least from greatest to make min heap ie. sorted form ascending order.

*/

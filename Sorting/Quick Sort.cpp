/* Time :- O(Nlogn) [Average Case and Best Case] :- O(N*N) [Worst case complexity] Space :- O(1) */

/* Worst case when the partition process always picks the greatest or smallest element as the pivot when sorted in ascending or descending order */ 

class Solution
{
    public:
    void quickSort(int arr[], int low, int high)
    {
       if(low<high)
       {
           int pivot=partition(arr,low,high);
           quickSort(arr,low,pivot-1);
           quickSort(arr,pivot+1,high);
       }
    }
    
    public:
    int partition (int arr[], int low, int high)
    {
       int pivot=arr[low];
       int l=low+1;
       int r=high;
       
       while(l<=r)
       {
           while(pivot>=arr[l])
           {
               l++;
           }
           while(pivot<arr[r])
           {
               r--;
           }
           if(l<r)
           {
               swap(arr[l],arr[r]);
               l++;
               r--;
           }
       }
       swap(arr[r],arr[low]);
       return r;
    }
};

/* Key points :- 

1. It is not stable algorithm.
2. It is an in-place sorting algorithm.
3. It is preferred over merge sort [Not in case of linked list] as space is O(1) only.
4. More optimised version is randomised quick sort.
5. Recurrence :- T(n) = 2T(n/2) + O(n) [Average and Best Case]
6. Recurrence :- T(n) = T(n-1)  + O(n) [ Worst Case ]

*/

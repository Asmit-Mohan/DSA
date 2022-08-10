/* Time :- O(Nlogn) [All Cases] Space :- O(N) */ 

class Solution
{
    public:
    void merge(int arr[], int low, int mid, int high)
    {
        int i=low;
        int j=mid+1;
        int idx=low;
        
        int temp[high+1];
        
        while(i<=mid&&j<=high)
        {
            if(arr[i]>arr[j])
            {
                temp[idx++]=arr[j++];
            }
            else
            {
                temp[idx++]=arr[i++];
            }
        }
        
        while(i<=mid)
        {
            temp[idx++]=arr[i++];
        }
        while(j<=high)
        {
            temp[idx++]=arr[j++];
        }
        
        for(int i=low;i<=high;i++)
        {
            arr[i]=temp[i];
        }
    }
    
    public:
    void mergeSort(int arr[], int low, int high)
    {
        if(low<high)
        {
            int mid=low+(high-low)/2;
            mergeSort(arr,low,mid);
            mergeSort(arr,mid+1,high);
            merge(arr,low,mid,high);
        }
    }
};

/* Key Points :-

1. T(n) = 2T(n/2) + θ(n) [ All cases ]
2. In Place :- Nope
3. Stable :- Yes
4. Preferred over quick sort in case of linked list since mid element can  be get in O(1) Space and no furthur space is required for merging.

*/

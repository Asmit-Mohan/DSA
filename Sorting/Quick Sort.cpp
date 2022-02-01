    void quickSort(int arr[], int low, int high)
    {
        if(low<high)
        {
            int pivot_idx=partition(arr,low,high);
            quickSort(arr,low,pivot_idx-1);
            quickSort(arr,pivot_idx+1,high);
        }
    }


    int partition (int arr[], int low, int high)
    {
        int pivot=arr[low];
        int l=low+1;
        int r=high;
        while(l<=r)
        {
            while(arr[l]<=pivot)
            {
                l++;
            }
            while(arr[r]>pivot)
            {
                r--;
            }
            if(r>l)
            {
                swap(arr[l],arr[r]);
                l++;
                r--;
            }
        }
        swap(arr[low],arr[r]);
        return r;
    }

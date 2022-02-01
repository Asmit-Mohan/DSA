class Solution
{
    public:
    void merge(int arr[], int l, int mid, int r)
    {
        int i=l;
        int j=mid+1;
        int k=l;
        int temp[1000000];
        
        while(i<=mid&&j<=r)
        {
            if(arr[i]<=arr[j])
            {
                temp[k]=arr[i];
                i++;
            }
            else
            {
                temp[k]=arr[j];
                j++;
            }
            k++;
        }
       
            if(i>mid)
            {
                while(j<=r)
                {
                    temp[k]=arr[j];
                    j++;
                    k++;
                }
            }
            
            if(j>r)
            {
                while(i<=mid)
                {
                    temp[k]=arr[i];
                    i++;
                    k++;
                }
            }
        
        for(int i=l;i<=r;i++)
        {
            arr[i]=temp[i];
        }
    }
  
    public:
    void mergeSort(int arr[], int l, int r)
    {
        if(l<r)
        {
            int mid=(l+r)/2;
            mergeSort(arr,l,mid);
            mergeSort(arr,mid+1,r);
            merge(arr,l,mid,r);
        }
    }
};

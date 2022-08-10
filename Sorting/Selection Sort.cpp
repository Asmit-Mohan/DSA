/* Approach 1 Time :- O(N*N) Space :- O(1) */

class Solution
{
    public:
    int select(int arr[], int n)
    {
        for(int i=0;i<n-1;i++)
        {
            int idx=i;
            for(int j=i+1;j<n;j++)
            {
                if(arr[idx]>arr[j])
                {
                    idx=j;
                }
            }
            if(idx!=i)
            {
                swap(arr[idx],arr[i]);
            }
        }
    }
     
    void selectionSort(int arr[], int n)
    {
       select(arr,n);
    }
};

/* Approach 2 Recursion Time :- O(N*N) Space :- O(N) */

int minIndex(int a[], int i, int j)
{
    if (i == j)
    {
        return i;
    }
    int k = minIndex(a, i + 1, j);
    return (a[i] < a[k])? i : k;
}
 
void recurSelectionSort(int a[], int n, int index = 0)
{
    if (index == n)
    {
        return;
    }
    int k = minIndex(a, index, n-1);
    if (k != index)
    {
        swap(a[k], a[index]);
    }
    recurSelectionSort(a, n, index + 1);
}

/* Key points :- The default implementation is not stable. However it can be made stable. It is in-place algo since it does not require extra space */

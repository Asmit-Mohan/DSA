/*Approach 1 Time :- O(max(m,n)) Space:- O(m+n) */

class Solution
{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
    int arr[m+n];
    int i =0;
    int j =0;
    int t=0;
    
    while(i<n && j<m)
    {
    if(arr1[i]<arr2[j])
    {
        arr[t] = arr1[i];
        i++;
    }
    else
    {
        arr[t] = arr2[j];
        j++;
    }
        t++;
    }
     while(i<n)
    {
        arr[t] = arr1[i];
        i++;
        t++;
    }
    
    while(j<m)
    {
        arr[t] = arr2[j];
        j++;
        t++;
    }
    return arr[k-1];
    }
};

/*Approach 2 Efficient Approach*/


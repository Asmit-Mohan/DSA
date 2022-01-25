/*Approach 1 (Naive) Time :- O(K) Space O(1) */

class Solution
{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
       int i=0;
       int j=0;
       int temp;
       while(k>0 && i<n && j<m)
       {
           if(arr1[i] < arr2[j])
           {
               temp = arr1[i];
               i++;
           }
           else
           {
               temp = arr2[j];
               j++;
           }
           k--;
       }
       
       while(k > 0 && i<n)
       {
           temp = arr1[i];
           i++;
           k--;
       }
       while(k>0 && j<m)
       {
           temp = arr2[j];
           j++;
           k--;
       }
       return temp;
    }
};

/*Efficient Approach (Binary Search) Time :- O(Log(min(n,m))) Space :- O(1) */


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

class Solution
{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        if(n>m)
        {
           return  kthElement(arr2,arr1,m,n,k);
        }
        int low=max(0,k-m);
        int high=min(k,n);
        
        while(low<=high)
        {
            int cut1=low+(high-low)/2;
            int cut2=k-cut1;
            
            int left1 = cut1 == 0 ? INT_MIN : arr1[cut1-1];
            int left2 = cut2 == 0 ? INT_MIN : arr2[cut2-1];
            
            int right1 = cut1 == n ? INT_MAX : arr1[cut1];
            int right2 = cut2 == m ? INT_MAX : arr2[cut2];
            
            if(left1<=right2&&left2<=right1)
            {
               return max(left1,left2);
            }
            else if(left1>right2)
            {
                high=cut1-1;   
            }
            else
            {
                low=cut1+1;
            }
        }
    }
};

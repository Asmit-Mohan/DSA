/* Approach 1 Time :- O(N*N) [Average, Worst, Best] Space :- O(1) */

class Solution
{
    public:
    void bubbleSort(int arr[], int n)
    {
       int temp;
       for(int i=0;i<n-1;i++)
       {
           for(int j=0;j<n-i-1;j++)
           {
               if(arr[j]>arr[j+1])
               {
                   temp=arr[i];
                   arr[i]=arr[j];
                   arr[j]=temp;
               }
           }
       }
    }
};

/* Approach 2 Time :- O(N*N) [Average, Worst]  :- O(N) [Best, when array is sorted] Space :- O(1) */    

void bubbleSort(int arr[], int n)
{
   int i, j;
   bool swapped;
   for (i = 0; i < n-1; i++)
   {
         swapped = false;
         for (j = 0; j < n-i-1; j++)
         {
            if (arr[j] > arr[j+1])
            {
               swap(arr[j], arr[j+1]);
               swapped = true;
            }
         }
         if (swapped == false)  --> /* That means array is already sorted */
         {
             break;
         }
   }
}

/* Approach 3 Recursion */

void bubblesort(int arr[], int n)
{
    if (n == 0 || n == 1)
    {
        return;
    }
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            swap(arr[i], arr[i + 1]);
        }
    }
    bubblesort(arr, n - 1);
}

/* Bubble sort performs swapping of adjacent pairs without the use of any major data structure. Hence Bubble sort algorithm is an in-place algorithm */
/* Bubble Sort is stable algorithms */

/* Time :- O(Nlogn) Space :- O(N) */

#include<stdio.h>
#include<math.h>
#include<time.h>
#include<stdlib.h>
int N = 20;
int A[20];

void swap(int dex1, int dex2)
{
     int temp = A[dex1];
     A[dex1] = A[dex2];
     A[dex2] = temp;
}

int partition(int start, int end)
{
     int i = start + 1;
     int j = i;
     int pivot = start;
     for (; i < end; i++)
     {
        if (A[i] < A[pivot])
        {
           swap(i, j);
           j++;
        }
     }
     if (j <= end)
     {
        swap(pivot, (j - 1));
     }
     return j - 1;
}

void quick_sort(int start, int end, int K)
{
     int part;
     if (start < end)
     {
        part = partition(start, end);
        if (part == K - 1)
        {
            printf("kth smallest element : %d ", A[part]);
        }
        if (part > K - 1)
        {
            quick_sort(start, part, K);
        }
        else
        {
            quick_sort(part + 1, end, K);
        }
     }
     return;
}

int main()
{
     int n;
     printf("Enter number of integer here:-");
     scanf("%d", &n);
     for(int i=0;i<n;i++)
     {
        scanf("%d", &A[i]); 
     }
     printf("The original sequence is: ");
     for (int i = 0; i < n; i++)
     {
         printf("%d ", A[i]);
     }
     printf("\nEnter the Kth smallest you want to find:-");
     int k;
     scanf("%d", &k);
     quick_sort(0, n, k);
}

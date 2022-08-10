/* Time :- O(Nlogn) [Average and Best] :- O(n*n) [Worst] Space :- O(1) */

#include <stdio.h>
#include <stdlib.h>
#define MAX 20

void random_shuffle(int arr[])
{
    int i, j, temp;
    for (i = MAX - 1; i > 0; i--)
    {
        j = rand()%(i + 1);
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}
 
void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int partion(int arr[], int l, int r)
{
    int pivotIndex = l + rand()%(r - l + 1); 
    int pivot;
    int i = l - 1;
    int j;
    pivot = arr[pivotIndex];
    swap(&arr[pivotIndex], &arr[r]);
    for (j = l; j < r; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
 
    }
    swap(&arr[i+1], &arr[r]);
    return i + 1;
}
 
void quick_sort(int arr[], int l, int r)
{
    int pivot;
    if (l < r)
    {
        pivot = partion(arr, l, r);
        quick_sort(arr, l, pivot-1);
        quick_sort(arr, pivot+1, r);
    }
}

int main()
{
    int i;
    int arr[MAX];
    for (i = 0; i < MAX; i++)
    arr[i] = i;
    random_shuffle(arr); 
    quick_sort(arr, 0, MAX-1); 
    for (i = 0; i < MAX; i++)
    printf("%d \n", arr[i]);
    return 0;
}

/* Key points :- 

1. Differnece from quick sort :- there is very low probability of bad splits in randomized quicksort. 
2. worst case when all elements are same or array is already sorted.

*/

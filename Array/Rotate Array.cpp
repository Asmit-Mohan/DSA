void rotateArr(int arr[], int d, int n)
{
    int l=0;
    int r=d-1;
    while (l<r)   /*Reversing first d elements*/   /*2 1*/
    {
        int temp = arr[l];
        arr[l] = arr[r];
        arr[r] = temp;
        l++;
        r--;
    }
    l=d;
    r=n-1;
    while (l<r)  /*Reversing all the elements after d*/  /*5 4 3*/
    {
        int temp = arr[l];
        arr[l] = arr[r];
        arr[r] = temp;
        l++;
        r--;
    }
    l=0;
    r=n-1;
    while (l<r)  /*Reversing whole array*/  /*Fron 2 1 5 4 3*/  /*to 3 4 5 1 2*/
    {
        int temp = arr[l];
        arr[l] = arr[r];
        arr[r] = temp;
        l++;
        r--;
    }
}
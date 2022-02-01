/*Approach 1*/

class Solution
{
    public:
    void insert(int arr[], int i)
    {
        for(int j=0;j<i;j++)
        {
            if(arr[j]>arr[i])
            {
                int temp=arr[j];
                arr[j]=arr[i];
                arr[i]=temp;
            }
        }
    }
    public:
    void insertionSort(int arr[], int n)
    {
        for(int i=0;i<n;i++)
        {
            insert(arr,i);
        }
    }
};

/*Approach 2*/

class Solution
{
    public:
    void insert(int arr[], int i)
    {
        int j=i-1;
        while(j>=0&&arr[j]>arr[i]) 
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=arr[i];
    }
  
    public:
    void insertionSort(int arr[], int n)
    {
        for(int i=1;i<n;i++)
        {
           insert(arr,i);  
        }
    }
};

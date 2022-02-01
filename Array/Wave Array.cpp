class Solution
{
    public:
    void convertToWave(int *arr, int n)
    {
        int temp;
        if(n%2!=0)
        {
            for(int i=0;i<n-1;i=i+2)
            {
                temp=arr[i];
                arr[i]=arr[i+1];
                arr[i+1]=temp; 
            }
            
        }
        else
        {
            for(int i=0;i<n;i=i+2)
            {
                temp=arr[i];
                arr[i]=arr[i+1];
                arr[i+1]=temp;
            }
        }
    }
};

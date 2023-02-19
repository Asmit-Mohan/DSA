class Solution
{   
public:
    void segregate0and1(int arr[], int n)
    {
        int i=0;
        int j=0;
        
        while(j<n)
        {
            if(arr[j]==0)
            {
                swap(arr[i],arr[j]);
                i++;
            }
            j++;
        }
    }
};

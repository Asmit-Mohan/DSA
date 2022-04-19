class Solution
{
public:
    int remove_duplicate(int arr[],int n)
    {
        int idx=0;
        
        for(int i=0;i<n;i++)
        {
            if(arr[i]!=arr[idx])
            {
                idx++;
                arr[idx]=arr[i];
            }
        }
        return idx+1;
    }
};

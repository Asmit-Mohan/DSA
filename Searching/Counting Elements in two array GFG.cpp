/* Time :- O(Mlogn + Nlogn) Space :- O(1) --> No Extra Space other than ans vector */

class Solution
{
  public:
    int solve(int arr[],int n,int target)
    {
        int low=0;
        int high=n-1;
        
        while(low<=high)
        {
            int mid=low+(high-low)/2;   
            if(arr[mid]<=target)
            {
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        return high;
    }
    
    vector<int> countEleLessThanOrEqual(int arr1[], int arr2[],int m, int n)
    {
        sort(arr2,arr2+n);
        vector<int>v;
        
        for(int i=0;i<m;i++)
        {
            v.push_back(solve(arr2,n,arr1[i])+1);
        }
        return v;
    }
};

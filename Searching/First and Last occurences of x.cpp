/* Time :- O(logn) Space :- O(1) */

class Solution
{
  public:
    vector<int> firstAndLast(vector<int> &arr, int n, int x)
    {
        int l=0;
        int r=n-1;
        int flag=0;
        int mid;
        while(l<=r)
        {
            mid=l+(r-l)/2;
            if(arr[mid]==x)
            {
                flag=1;
                break;
            }
            else if(arr[mid]>x)
            {
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        vector<int>v;
        if(flag==0)
        {
            v.push_back(-1);
            return v;
        }
        else
        {
            l=mid;
            r=mid;
            while(l>=0&&arr[l]==x)
            {
                l--;
            }
            while(r<n&&arr[r]==x)
            {
                r++;
            }
            v.push_back(l+1);
            v.push_back(r-1);
            return v;
        }
    }
};

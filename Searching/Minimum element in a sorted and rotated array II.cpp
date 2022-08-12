/* Time :- O(logn) Space :- O(1) */

class Solution
{
public:
   int findMin(vector<int>& a)
   {
        int n=a.size();
        int l=0;
        int r=n-1;
        while(l<r)
        {
            int mid=l+((r-l)/2);
            if(a[mid]>a[r])
            {
               l=mid+1; 
            }
            else if(a[mid]<a[r])
            {
               r=mid;
            }
            else
            {
                r--;
            }
        }
        return a[l];
    }
};

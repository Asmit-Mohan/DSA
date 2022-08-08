/* Time :- O(Nlogn) Space :- O(1) */

class Solution
{
    public:
        int closestToZero(int arr[], int n)
        {
            sort(arr,arr+n);
            int ans=INT_MAX;
            int res=-1;
            int l=0,r=n-1;
            while(l<r)
            {
                int diff=arr[l]+arr[r];
                if(diff==0)
                {
                    return 0;
                }
                else if(diff<0)
                {
                    l++;
                }
                else
                {
                    r--;
                }
                if(abs(diff)<ans)
                {
                    ans=abs(diff);
                    res=diff;
                }
                else if(abs(diff)==ans)
                {
                    res=max(res,diff);
                }
            }
            return res;
        }
};

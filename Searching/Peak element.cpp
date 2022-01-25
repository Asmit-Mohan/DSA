class Solution
{
    public:
    int peakElement(int a[], int n)
    {
        int l=0;
        int r=n-1;
        while(l<=r)
        {
            int mid=l+((r-l)/2);
            if(a[mid]>a[mid+1]&&a[mid]>a[mid-1]&&mid!=n-1)
            {
                  return mid;
            }
            else if(a[mid]>a[mid-1]&&mid==n-1)
            {
                  return mid;
            }
            else if(a[mid]<a[mid+1])
            {
                l=mid+1;
            }
            else
            {
                r=mid-1;
            }
        }
    }
};

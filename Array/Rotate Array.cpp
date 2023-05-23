class Solution
{
public:
    void revFunc(vector<int>& arr, int l, int r)
    {
        while(l<=r)
        {
            swap(arr[l],arr[r]);
            l++;
            r--;
        }
    }

    void rotate(vector<int>& arr, int k)
    {
        int n = size(arr);
        k = k%n;
        revFunc(arr,n-k,n-1);
        revFunc(arr,0,n-k-1);
        revFunc(arr,0,n-1);
	} 
};

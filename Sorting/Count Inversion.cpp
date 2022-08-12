/* Time :- O(Nlogn) Space :- O(N) */

#define ll long long int
class Solution
{
    public:
    ll merge(ll arr[], ll left, ll mid, ll right, ll A[])
    {
        ll inv_count=0;
        ll i=left;
        ll j=mid;
        ll k=left;
        
        while (i <= mid-1 && j <= right)
        {
            if (arr[i] <= arr[j])
            {
                A[k++] = arr[i++];
            }
            else
            {
                A[k++] = arr[j++];
                inv_count = inv_count+(mid-i);
            }
        }
        while (i <= mid-1)
        {
            A[k++] = arr[i++];
        }
        
        while (j <= right)
        {
            A[k++] = arr[j++];
        }
        for (i = left; i <= right; i++)
        {
            arr[i] = A[i];
        }
        return inv_count;
    }
    
    ll mergeSort(ll arr[], ll l, ll r, ll A[])
    {
        if(l>=r)
        {
            return 0;
        }
        ll mid = (l+r)>>1;
        ll res =0;
        res += mergeSort(arr, l, mid, A);
        res += mergeSort(arr, mid + 1, r, A);
        res += merge(arr, l, mid+1, r, A);
        return res;
    }
    
    ll inversionCount(ll arr[], ll N)
    {
        ll A[N];
        return mergeSort(arr, 0, N - 1, A);
    }
};

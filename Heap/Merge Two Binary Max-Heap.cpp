class Solution
{
    public:
    void heapify(vector<int>&arr, int n, int i)
    {
        int largest = i;
        int l = 2 * i + 1;   //Left Child
        int r = 2 * i + 2;   //Right Child
     
        // If left child is larger than root
        if (l < n && arr[l] > arr[largest])
        {
            largest = l;
        }
        
        // If right child is larger than largest so far
        if (r < n && arr[r] > arr[largest])
        {
            largest = r;
        }
        
        // If largest is not root
        if (largest != i)
        {
            swap(arr[i], arr[largest]);
            heapify(arr, n, largest);   // Recursively heapify the affected sub-tree
        }
    }

    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m)
    {
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            ans.push_back(a[i]);    
        }
        for(int i=0;i<m;i++)
        {
            ans.push_back(b[i]);    
        }
        
        int len=ans.size();
        int startIdx = (len / 2) - 1;
        for (int i = startIdx; i >= 0; i--)
        {
            heapify(ans, len, i);
        }
        return ans;
    }
};

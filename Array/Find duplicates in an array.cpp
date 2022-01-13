class Solution
{
  public:
    vector<int> duplicates(int arr[], int n)
    {
        vector<int>v;
        for(int i=0;i<n;i++)
        {
            arr[arr[i]%n]+=n;
        }
        for(int i=0;i<n;i++)
        {
            arr[i]/=n;
            if(arr[i]>1)
            {
                v.push_back(i);
            }
        }
        if(v.size()==0)
        {
            v.push_back(-1);
        }
        return v;
    }
};
class Solution
{
    public:
    int doUnion(int a[], int n, int b[], int m)
    {
        unordered_set <int> s;
        int count=0;
        for(int i=0;i<n;i++)
        {
        if(s.find(a[i])==s.end())
        {
            s.insert(a[i]);
            count++;
        }
        }
        for(int i=0;i<m;i++)
        {
        if(s.find(b[i])==s.end())
        {
            s.insert(b[i]);
            count++;
        }
        }
        return count;
    }
};

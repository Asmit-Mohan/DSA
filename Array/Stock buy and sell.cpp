class Solution
{
public:
    vector<vector<int>>stockBuySell(vector<int> a, int n)
    {
       vector<vector<int>> v;
       int i=0,buy=0,sell=0;
       for(int i=1;i<n;i++)
       {
           if(a[i]>a[i-1])
           {
               buy=i-1;
               sell=i;
               v.push_back({buy,sell});
           }
       }
       return v;
    }
};

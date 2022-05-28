class Solution
{
public:
    static bool comp(vector<int> &a,vector<int>&b)
    {
        return (a[0]<b[0]) || (a[0]==b[0] && a[1]>b[1]);   
    }
    
    int LIS(vector<int>& a)
    {
       int n=a.size();
       vector<int>v;
       v.push_back(a[0]);
       for(int i=1;i<n;i++)
       {
           if(a[i]>v.back())
           {
               v.push_back(a[i]);
           }
           else
           {
               int idx=lower_bound(v.begin(),v.end(),a[i])-v.begin();
               v[idx]=a[i];
           }
       }
       return v.size();
    }
    
    int maxEnvelopes(vector<vector<int>>& arr)
    {
        sort(arr.begin(),arr.end(),comp);
        vector<int>temp;
        for(int i=0;i<arr.size();i++)
        {
            temp.push_back(arr[i][1]);
        }
        return LIS(temp);
    }
};

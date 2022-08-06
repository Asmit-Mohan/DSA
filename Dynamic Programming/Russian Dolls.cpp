/* Time :- O(Nlogn) and Space :- O(N) */

class Solution
{
public:
    static int comp(vector<int>&a,vector<int>&b)
    {
       return (a[0]<b[0])||(a[0]==b[0]&&a[1]>b[1]);
    }
    
    int LIS(vector<int>&temp)
    {
        int n=temp.size();
        vector<int>v;
        v.push_back(temp[0]);
        
        for(int i=1;i<n;i++)
        {
            if(v.back()<temp[i])
            {
                v.push_back(temp[i]);
            }
            else
            {
                int idx = lower_bound(v.begin(),v.end(),temp[i])-v.begin();
                v[idx]=temp[i];
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

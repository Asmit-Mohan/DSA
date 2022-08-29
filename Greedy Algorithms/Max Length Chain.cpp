/* Time :- O(Nlogn) Space :- O(N) */

class Solution
{
public:
    static bool comp(pair<int,int>a,pair<int,int>b)
    {
        return a.second<b.second;    
    }
    
    int maxChainLen(struct val p[],int n)
    {
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++)
        {
            v.push_back({p[i].first,p[i].second});
        }
    
        int ans=1;
        sort(v.begin(),v.end(),comp);    
        pair<int,int>temp = v[0];
        
        for(int i=1;i<n;i++)
        {
            if(v[i].first>temp.second)
            {
               ans++;
               temp = v[i];
            }
        }
        return ans;
    }
};

/* Time :- O(Nlogn) Space :- O(1) */

class Solution
{
public:
    bool static comp(val fst,val sec)
    {
        return fst.second<sec.second;
    }
    
    int maxChainLen(struct val p[],int n)
    {
        sort(p,p+n,comp);
        int ans=0;
        int prev=-1e9;
        for(int i=0;i<n;i++)
        {
            if(p[i].first>prev)
            {
                prev=p[i].second;
                ans++;
            }
        }
        return ans;
    }
};

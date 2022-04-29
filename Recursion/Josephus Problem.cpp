class Solution
{
public:
    int ans;
    void solve(int index,int k,int n,vector<int>v)
    {
        if(v.size()==1)   /* Last value will be postion of Josephus*/
        {
            ans=v[0];
            return;
        }
        index=(index+k)%v.size();   /* In case circular ie, last index move to starting postion */
        v.erase(v.begin()+index);   
        solve(index,k,n,v);
    }
    
    int findTheWinner(int n, int k)
    {
        int index=0;
        vector<int>v;
        for(int i=1;i<=n;i++)
        {
            v.push_back(i);
        }
        k--;                 /* Because indexing starts from current person */
        solve(index,k,n,v);
        return ans;
    }
};

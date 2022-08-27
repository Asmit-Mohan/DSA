

class Solution
{
    public:
    vector <int> bellman_ford(int n, vector<vector<int>> adj, int S)
    {
        vector<int>dist(n,100000000);
        dist[S]=0;
        
        for(int i=1;i<n;i++)
        {
            for(auto itr : adj)
            {
                int u=itr[0];
                int v=itr[1];
                int wt=itr[2];
                if((dist[u]+wt)<dist[v])
                {
                    dist[v]=dist[u]+wt;
                }
            }
        }
        
        int flag=1;
        
        for(int i=1;i<n;i++)
        {
            for(auto itr : adj)
            {
                int u=itr[0];
                int v=itr[1];
                int wt=itr[2];
                if((dist[u]+wt)<dist[v])
                {
                    flag=0;
                    break;
                }
            }
            if(flag==0)
            {
                break;
            }
        }
        
        if(flag==0)
        {
            // cout<<"Have a Negative Weight Cycle";
        }
        else
        {
           return dist;    
        }
    }
};

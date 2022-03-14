class Solution
{
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k)
    {
         if(n <= 1)
         {
             return 0;
         }
        
        vector<pair<int,int>> adj[n+1];
        vector<int>dist(n+1,INT_MAX);
        dist[k]=0;
        
        for(int i=0;i<times.size();i++)
        {
            adj[times[i][0]].push_back({times[i][1],times[i][2]});         
        }
        
        queue<int>q;
        q.push(k);
        int ans=0;
        
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            for(auto it : adj[node])
            {
                int key=it.first;
                int val=it.second;
                
                if(dist[key]>dist[node]+val)
                {
                    dist[key]=dist[node]+val;
                    q.push(key);
                }
            }
        }
        for(int i=1;i<=n;i++)
        {
            ans=max(ans,dist[i]);
        }
        if(ans==0||ans==INT_MAX)
        {
            return -1;
        }
        else
        {
            return ans;
        }
    }
};

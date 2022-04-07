class Solution
{
public:
    
    bool canVisitAllRooms(vector<vector<int>>& rooms)
    {
        int n=rooms.size();
        vector<int> adj[n];
        queue<int>q;
        vector<int>vis(n,0);
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<rooms[i].size();j++)
            {
                adj[i].push_back(rooms[i][j]);
            }
        }
        q.push(0);
        vis[0]=1;
        while(!q.empty())   
        {
            int node=q.front();
            q.pop();
            for(auto it : adj[node])
            {
                if(vis[it]==0)
                {
                    q.push(it);
                    vis[it]=1;
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            if(vis[i]==0)
            {
                return 0;
            }
        }
        return 1;
    }
};

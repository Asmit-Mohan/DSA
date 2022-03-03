/*Using BFS*/

class Solution
{
public:
    bool validPath(int v, vector<vector<int>>& edges, int src, int des)
    {
        if(v==1||src==des)
        {
            return true;
        }
        
        vector<int>adj[v];
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]); 
            adj[edges[i][1]].push_back(edges[i][0]);     
        }
    
        vector<int>vis(v,0);
        queue<int> q;
        vis[src] = 1;
        q.push(src);
        
        while(!q.empty())
        {
            int temp = q.front();
            q.pop();
            
            for(auto it : adj[temp])
            {
                if(vis[it] == 0)
                {
                    if(it==des)
                    {
                        return true;
                    }
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
        
        return false; 
    }
};

/*Using DFS*/

class Solution
{
public:
    
    bool solve(int src,int des,vector<int>&vis,vector<int>adj[])
    {
        if(src==des)
        {
            return true;
        }
        
        vis[src]=1;
        for(auto x : adj[src])
        {
           if(vis[x]==0)
           {
               if(solve(x, des, vis, adj))
               {
                   return true;
               }
           }
        }
        return false;
    }
    
    bool validPath(int v, vector<vector<int>>& edges, int src, int des)
    {
        if(v==1||src==des)
        {
            return true;
        }

        vector<int>adj[v];
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]); 
            adj[edges[i][1]].push_back(edges[i][0]);     
        }
        
        vector<int>vis(v,0);
        return solve(src,des,vis,adj);
    }
};

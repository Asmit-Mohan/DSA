class Solution
{
public:
vector<int>bfsOfGraph(int v, vector<int> adj[])
{
    vector<int> bfs;
    vector<int>vis(v,0);
    queue<int> q;
    vis[0] = 1;
    q.push(0);
    while(!q.empty())
    {
        int temp = q.front();
        bfs.push_back(temp);
        q.pop();
        for(auto it : adj[temp])
        {
            if(vis[it] == 0)
            {
                vis[it] = 1;
                q.push(it);
            }
        }
    }
    return bfs;
    }
};

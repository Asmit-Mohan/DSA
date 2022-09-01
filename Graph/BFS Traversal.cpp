/* Time :- O(V+E) Space :- O(V) + O(V) + O(V) */

class Solution
{
  public:
    vector<int> bfsOfGraph(int V, vector<int> adj[])
    {
       vector<int>ans;
       vector<bool>visited(V,0);
       
       queue<int>q;
       q.push(0);
       visited[0]=true;
       
       while(!q.empty())
       {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            
            for(auto x : adj[node])
            {
                if(visited[x]==0)
                {
                    visited[x]=1;
                    q.push(x);
                }
            }
       }
       return ans;
    }
};

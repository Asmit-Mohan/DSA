class Solution
{
    public:
    void toposort(int node,stack<int>&s,vector<int>&vis,vector<vector<int>> adj[])
    {
          vis[node]=1;
          for(auto x : adj[node])
          {
              if(vis[x.first]==0)
              {
                  toposort(x.first,s,vis,adj);
              }
          }
          s.push(node);
    }
    
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int src)
    {
       stack<int>s;
       vector<int>vis(V,0);
       for(int i=0;i<V;i++)
       {
       	   if(vis[i]==0)
       	   {
    		   toposort(i,s,vis,adj);  
       	   }
       }
       int dis[V];
       for(int i=0;i<V;i++)
       {
       	   dis[i]=INT_MAX;
       }
       dis[src]=0;
       while(!s.empty())
       {
       	   int front=s.top();
       	   s.pop();
       	   if(dis[front]!=INT_MAX)
       	   {
       	   	   for(auto it : adj[front])
       	   	   {
       	   	   	  if(dis[it.first]>dis[node]+it.second)
       	   	   	  {
       	   	   	  	   dis[it.first]=dis[node]+it.second;
       	   	   	  }
       	   	   }
       	   }
       }
       return dis;     /* If any dis[i] == INT_MAX print "Node not accessable else print dis[i]*/
    }
};

/* Why we have used here Topo Sort ?

Topological sort ensures that we are picking up nodes that come first while travelling from the source, 
this, in turn, will ensure that every node will have at least one condition that it can be reached from the source.

Processing the vertices in topological order ensures that by the time you get to a vertex, 
you've already processed all the vertices that can precede it.

*/

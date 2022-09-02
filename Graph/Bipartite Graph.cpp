/* BFS Time :- O(V+E) Space :- O(V) */

class Solution
{
public:
   bool solve(int color[],int i,vector<int>adj[])
   {
      queue<int>q;
      q.push(i);
      color[i]=1;
      
      while(!q.empty())
      {
        int node=q.front();
        q.pop();
        for(auto x : adj[node])
        {
            if(color[x]==-1)
            {
                color[x]=1-color[node];
                q.push(x);
            }
            else if(color[x]==color[node])
            {
                return false;
            }
        }
     }
     return true;
   }
	
    bool isBipartite(int V, vector<int>adj[])
    {
        int color[V];
        memset(color,-1,sizeof color);
        for(int i=0;i<V;i++)
        {
            if(color[i]==-1)
            {
                if(!solve(color,i,adj))
                {
                    return false;
                }
            }
        }
        return true;
    }
};

/* DFS Time :- O(V+E) Space :- O(V) */

class Solution
{
public:
    bool solve(int node,vector<int>&color,vector<int>adj[])
    {
      if(color[node]==-1)
      {
          color[node]=1;
      }
      for(auto it : adj[node])
      {
          if(color[it]==-1)
          {
             color[it]=1-color[node];
             if(!solve(it,color,adj))
             {
                return false;
             }
          }
          else if(color[it]==color[node])
          {
              return false;
          }
      }
      return true;
   }
  
   bool isBipartite(int V, vector<int>adj[])
   {
      vector<int>color(V,-1);
      for(int i=0;i<V;i++)
      {
           if(color[i]==-1)
           {
               if(!solve(i,color,adj))
               {
                   return false;
               }
            }
       }
       return true;
   }
};
  
/* One Key point is that if a graph having a odd length cyclic then it is not Bipartite Graph */

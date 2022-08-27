/* Approach 1 (BFS) Time :- O(V+E) Space :- O(V) + O(V) */

class Solution
{
public:
	bool isBipartite(int V, vector<int>adj[])
	{
	    vector<int>color(V,-1);
	    queue<int>q;
	    
	    for(int i=0;i<V;i++)
	    {
	        if(color[i]==-1)
	        {
	            color[i]=0;
	            q.push(i);
	            while(!q.empty())
	            {
	                int node=q.front();
	                q.pop();
    	                for(auto it : adj[node])
    	                {
				if(color[it]==-1)
				{
				    color[it]=1-color[node];
				    q.push(it);
				}
				else
				{
				    if(color[it]==color[node])
				    {
					return false;
				    }
				}
    	                   }
	               }
	           }
	      }
	 return true;
      }
};

/* Approach 2 (DFS) Time :- O(V+E) Space :- O(V) + O(V) */

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

/* Here we are not using visited array because colors is acting as visited array as, one any vertex is colored that means it is visisted so 
   when we are checking colored or not that means we are checking it is visited or not */
  
/* One Key point is that if a graph having a odd length cyclic then it is not Bipartite Graph */

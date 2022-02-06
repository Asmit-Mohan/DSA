/* Brute Force Approach Time O(More than N^2) Space O(N) */

class Solution
{
	public:
    int spanningTree(int N, vector<vector<int>> adj[])
    {
        int key[N];
        bool mst[N];
        int parent[N];
        
        for(int i=0;i<N;i++)
        {
            key[i]=INT_MAX;
            mst[i]=false;
        }
        key[0]=0;
        parent[0]=-1;
        
        for (int count = 0; count < N - 1; count++)
        { 
            int mini = INT_MAX;
            int u; 
            for (int v = 0; v < N; v++) 
            {
                if (mst[v] == false && key[v] < mini) 
                {
                    mini = key[v];
                    u=v; 
                }
            }
            
            mst[u]=true; 
            
            for (auto it : adj[u])
            {
                int v = it[0];
                int weight = it[1];
                if (mst[v] == false && weight < key[v]) 
                {
                    parent[v] = u;
                    key[v] = weight; 
                }
            }
        }
        
        int ans=0;
        for(int i=0;i<N;i++)
        {
            if(key[i]!=INT_MAX)
            {
                ans=ans+key[i];
            }
        }
        return ans;
    }
};



/* Efficient Approach Time O(NLogN) Space O(N) */    --> Comparing to get minimum key takes time of O(N) which can be resolved by taking a min heap

class Solution
{
	public:
    int spanningTree(int N, vector<vector<int>> adj[])
    {
        int key[N];
        bool mst[N];
        int parent[N];
        
        for(int i=0;i<N;i++)
        {
            key[i]=INT_MAX;
            mst[i]=false;
        }
        key[0]=0;
        parent[0]=-1;
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;   /* 1st Distance and 2nd Node*/
        pq.push({0,0}); 
        
        while(!pq.empty())
        {
            int node=pq.top().second;
            pq.pop();
            mst[node]=true;
            
            for(auto it : adj[node])
            {
                int v=it[0];
                int weight=it[1];
                if(mst[v]==false&&weight<key[v])
                {
                    parent[v]=node;
                    key[v]=weight;
                    pq.push({key[v],v});
                }
            }
        }
        
        int ans=0;
        for(int i=0;i<N;i++)
        {
            if(key[i]!=INT_MAX)
            {
                ans=ans+key[i];
            }
        }
        return ans;
    }
};

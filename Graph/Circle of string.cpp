class Solution
{
    public:
    void dfs(vector<int> adj[], vector<int>& vis, int src)
    {
        vis[src] = 1;
        for(auto& it: adj[src])
        {
            if(vis[it]==0)
            {
                dfs(adj,vis,it);
            }
        }
    }
    
    int isCircle(int N, vector<string> arr)
    {
        vector<int>adj[26];
        vector<int>inDegree(26,0);
        vector<int>outDegree(26,0);
        
        for(int i=0;i<arr.size();i++)
        {
            int a=arr[i][0]-'a';
            int b=arr[i][arr[i].length()-1]-'a';
            adj[a].push_back(b);
            inDegree[b]++;
            outDegree[a]++;
        }
        
        for(int i=0;i<26;i++)
        {
            if(inDegree[i]!=outDegree[i])
            {
                return 0;
            }
        }
        
        int src;
        for(int i=0;i<26;i++)
        {
            if(outDegree[i])
            {
                src=i;
                break;
            }
        }
        
        vector<int>vis(26, 0);
        dfs(adj, vis, src);  
        for(int i=0; i<26; i++)
        {
            if(outDegree[i] && vis[i]==0) 
            {
                return 0;
            }
        }
        return 1;
    }
};

/* Intution :- 

1. Make a directed graph 

2. If Eulerian Path then return true else false

3. Eulerian if :- 
   a. InDegree and outDegree of every vertex is same
   b. single component graph
   
4. Calling DFS once because to be in single component all nodes should be traversed in single DFS Call. 

*/

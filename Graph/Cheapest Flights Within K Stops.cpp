class Solution
{
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k)
    {
        vector<vector< pair<int,int> >> adj(n);
        
        for(int i=0;i<flights.size();i++)
        {
            adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
        
        vector<int> dist(n,pow(10,4)*n);
        vector<int> prev(n);
        dist[src] = 0;
        prev = dist;
        k++;
        
        while( k-- )
        {
            for( int i = 0 ; i < adj.size() ; i++ )
            {
                for( int j = 0; j < adj[i].size(); j++ )
                {
                    int v = adj[i][j].first;
                    int weight = adj[i][j].second;
                    if( dist[ v ] > prev[i] + weight )
                    {
                        dist[ v ] = prev[i] + weight;
                    }
                }
            }
            prev = dist;
        }
        
        if( prev[dst] == pow(10,4)*n )
        {
            return -1;
        }
        else
        {
            return prev[dst];
        }
    }
};

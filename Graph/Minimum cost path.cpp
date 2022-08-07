#define pp pair<int,pair<int,int>>
class Solution
{
    public:
    bool isSafe(int row,int col,int n)
    {
        if(row<0||col<0||row>=n||col>=n)
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
    
   int minimumCostPath(vector<vector<int>>& grid) 
   {
       int n=grid.size();
       vector<vector<int>> dist(n,vector<int>(n,INT_MAX));
       priority_queue<pp,vector<pp>,greater<pp>> pq;
       
       pq.push({grid[0][0],{0,0}});
       
       dist[0][0]=grid[0][0];
       int xArr[]={-1,1,0,0};
       int yArr[]={0,0,-1,1};
       
       while(!pq.empty())
       {
           int weight=pq.top().first;
           int row=pq.top().second.first;
           int col=pq.top().second.second;
           pq.pop();
           
           for(int i=0;i<4;i++)
           {
               int xNew = row + xArr[i];
               int yNew = col + yArr[i];
               
               if(isSafe(xNew,yNew,n))
               {
                   if(dist[xNew][yNew]>weight+grid[xNew][yNew])
                   {
                       dist[xNew][yNew] = weight+grid[xNew][yNew];
                       pq.push({dist[xNew][yNew],{xNew,yNew}});
                   }
               }
           }
       }
       return dist[n-1][n-1];
   }
};

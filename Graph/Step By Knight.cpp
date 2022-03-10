class Solution 
{
    public:
    bool isValid(int x,int y,int n)
    {
        if(x>=0&&x<n&&y>=0&&y<n)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    int startX=KnightPos[0]-1;
	    int startY=KnightPos[1]-1;
	    
      int endX=TargetPos[0]-1;
	    int endY=TargetPos[1]-1;
	    
	    if(startX==endX&&startY==endY)
	    {
	        return 0;
	    }
	    
	    queue<pair<int,int>>q;
	    q.push({startX,startY});
	    vector<vector<int>>v(N,vector<int>(N,0));
	    v[startX][startY]=1;
	    int ans=0;
	    
	    while(!q.empty())
	    {
	        int size=q.size();
	        ans++;
	        while(size--)
	        {
    	        pair<int,int>temp=q.front();
    	        q.pop();
    	        int xCor=temp.first;
    	        int yCor=temp.second;
    	        int xArr[8]={1,2,-2,-1,-2,-1,1,2};
    	        int yArr[8]={2,1,1,2,-1,-2,-2,-1};
    	        
    	        for(int i=0;i<8;i++)
    	        {
    	            int x=xCor+xArr[i];
    	            int y=yCor+yArr[i];
    	            
    	            if(x==endX&&y==endY)
    	            {
    	                return ans;
    	            }
    	            
    	            else if(isValid(x,y,N)&&v[x][y]==0)
    	            {
    	                q.push({x,y});
    	                v[x][y]=1;
    	            }
    	        }
	        }
	    }
	    return ans;
	}
};

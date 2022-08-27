class Solution
{
public:
    void dfs(int i,int j,int oldColor,int newColor,vector<vector<int>>& image)
    {
        int row=image.size();
        int col=image[0].size();
        
        if(i<0 || j<0 || i==row || j==col)
        {
            return;
        }
        
        if(image[i][j]!=oldColor)
        {
            return;
        }
        
        image[i][j]=newColor;
        
        dfs(i-1,j,oldColor,newColor,image);
        dfs(i,j-1,oldColor,newColor,image);
        dfs(i+1,j,oldColor,newColor,image);
        dfs(i,j+1,oldColor,newColor,image);
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor)
    {
        if(image[sr][sc]!=newColor)
        {
            dfs(sr,sc,image[sr][sc],newColor,image);
        }
        return image;
    }
};

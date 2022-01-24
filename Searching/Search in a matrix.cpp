class Solution
{
public:	
	int matSearch (vector<vector<int>> &arr, int N, int M, int X)
	{
	   int row=0;
	   int col=M-1;
	   while(row<N&&col>-1)
	   {
	       if(arr[row][col]==X)
	       {
	           return 1;
	       }
	       else if(arr[row][col]>X)
	       {
	           col--;
	       }
	       else
	       {
	           row++;
	       }
	   }
	   return 0;
	}
};

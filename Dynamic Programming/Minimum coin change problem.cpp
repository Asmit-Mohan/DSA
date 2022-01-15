class Solution
{
public:
int minCoins(int coins[], int M, int V) 
{
long long t[M+1][V+1];
for( int i = 0 ; i < M+1; i++ )
{
    t[i][0]=0;
}
for( int j = 0 ; j < V+1 ; j++ )
{
    t[0][j]=INT_MAX;
}
for( int i = 1 ; i <= M ; i++)
{
  for( int j = 1 ; j <= V ; j++)
  {
      if( coins[i-1]<= j )
      {
          t[i][j]=min(1+t[i][j-coins[i-1]], t[i-1][j] );
      }
      else
      {
          t[i][j]=t[i-1][j];
      }
  }
}
if( t[M][V] == INT_MAX)
{
    return -1 ;
}
return t[M][V];
}
};

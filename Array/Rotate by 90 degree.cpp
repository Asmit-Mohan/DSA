/* Approach 1 */

void rotate(vector<vector<int> >& matrix)
{
    int n=matrix.size();
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            swap(matrix[i][j],matrix[j][i]);
        }
    }
    for(int i=0;i<n/2;i++)
    {
        for(int j=0;j<n;j++)
        {
            swap(matrix[i][j],matrix[n-i-1][j]);
        }
    }
}

/* Approach 2 */

void rotate(vector<vector<int> >& matrix)
{
    for(int i=0;i<matrix.size();i++)
    {
        reverse(matrix[i].begin(),matrix[i].end());
    }
    
    for(int i=0;i<matrix.size();i++)
    {
        for(int j=i+1;j<matrix[0].size();j++)
        {
            swap(matrix[i][j],matrix[j][i]);
        }
}

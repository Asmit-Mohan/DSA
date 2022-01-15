vector<int> longestCommonSubsequence(vector<int> a, vector<int> b)
{
    int m=a.size();
    int n=b.size();
    int t[m+1][n+1];
    int i,j;
     for(i=0;i<m+1;i++)
    {
        for(j=0;j<n+1;j++)
        {
            if(i==0||j==0)
            {
                t[i][j]=0;
            }
        }
    }
    for(i=1;i<m+1;i++)
    {
        for(j=1;j<n+1;j++)
        {
            if(a[i-1]==b[j-1])
            {
                t[i][j]=1+t[i-1][j-1];
            }
            else
            {
                t[i][j]=max(t[i][j-1],t[i-1][j]);
            }
        }
    }
    vector<int>v;
    i--;
    j--;
    while(i>0&&j>0)
    {
        if(a[i-1]==b[j-1])
        {
            v.push_back(a[i-1]);
            i--;
            j--;    
        }
        else
        {
            if(t[i-1][j]>t[i][j-1])
            {
                i--;
            }
            else
            {
                j--;
            }
        }
    }
    reverse(v.begin(),v.end());   
    return v;
}

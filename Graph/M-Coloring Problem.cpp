bool isPossible(int node,int v,int col,bool graph[101][101],int color[])
{
    for(int i=0;i<v;i++)
    {
        if(i!=node&&graph[node][i]==1&&color[i]==col)
        {
            return false;
        }
    }
    return true;
}

bool solve(int node, int v,int m,int color[],bool graph[101][101])
{
    if(node==v)
    {
        return true;
    }
    for(int i=1;i<=m;i++)
    {
        if(isPossible(node, v, i,graph,color))
        {
            color[node]=i;
            if(solve(node+1,v,m,color,graph))
            {
                return true;
            }
            else
            {
                color[node]=0;
            }
        }
    }
    return false;
}

bool graphColoring(bool graph[101][101], int m, int V)
{
    int color[V]={0};
    if(solve(0,V,m,color,graph))
    {
        return true;
    }
    else
    {
        return false;
    }
}

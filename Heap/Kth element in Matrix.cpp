/*Approach 1 :- Not Optimised*/

int kthSmallest(int mat[MAX][MAX], int n, int k)
{
      priority_queue <int> pq;
       for(int i=0;i<n;i++)
       {
           for(int j=0;j<n;j++)
           {
               pq.push(mat[i][j]);
               if(pq.size()>k)
               {
                   pq.pop();
               }
           }
       }
       return pq.top();
}

/*Optimised Approach Using Binary Search*/

int solve(int val,int mat[][MAX], int n)
{
    int start=0;
    int end=n-1;
    int count=0;
    
    while(start<n&&end>=0)
    {
        if(mat[end][start]>val)
        {
            end--;
        }
        else
        {
            count=count+end+1;
            start++;
        }
    }
    return count;
}

int kthSmallest(int mat[MAX][MAX], int n, int k)
{
    int low=mat[0][0];
    int high=mat[n-1][n-1];
    int ans;
    
    while(low<=high)
    {
        int mid=(low+high)>>1;
        if(solve(mid,mat,n)<k)
        {
            low=mid+1;
        }
        else 
        {
           ans=mid;
           high=mid-1;
        }
    }
    return ans;
}

/* Approach 1 Time :- O(N*N*logk) Space :- O(k) */

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

/* Approach 2 Time :- O(N*logn) Space :- O(1) */

class Solution
{
public: 
    int solve(int val,vector<vector<int>>& mat)
    {
        int n=mat.size();
        int low=0;
        int high=n-1;
        int ans=0;
        
        while(low<n&&high>=0)
        {
            if(mat[low][high]>val)
            {
                high--;
            }
            else
            {
                low++;
                ans=ans+(high+1);
            }
        }
        return ans;
    }
    
    int kthSmallest(vector<vector<int>>& mat, int k)
    {
        int n=mat.size();
        int low=mat[0][0];
        int high=mat[n-1][n-1];
        int res=0;
        
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            int ans=solve(mid,mat);
            if(ans<k)
            {
                low=mid+1;
            }
            else
            {
                res=mid;
                high=mid-1;
            }
        }
        return res;
    }
};

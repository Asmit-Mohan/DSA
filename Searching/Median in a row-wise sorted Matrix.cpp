/* Approach 1 Brute Force Time :- O(r*c) Space :- O(r*c) */

class Solution
{   
public:
    int median(vector<vector<int>> &arr, int r, int c)
    {
        vector<int>v;
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                v.push_back(arr[i][j]);
            }
        }
        sort(v.begin(),v.end());
        return v[v.size() / 2];
    }
};


/* Approach 2 (Binary Search) Time :- O(R*Log(C)) Space :- O(1) */

class Solution
{   
public:
   int solve(int res,vector<int>v)
    {
        int low=0;
        int high=v.size()-1;
        while(low<=high)       /*O(Logc)*/
        {
            int mid=(low+high)>>1;
            if(v[mid]<=res)
            {
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        return low;
    }
    int median(vector<vector<int>> &matrix, int r, int c)
    {
        int low=1;
        int high=INT_MAX;
        int req=(r*c)/2;
        while(low<=high)
        {
            int mid=(low+high)>>1;
            int sum=0;
            for(int i=0;i<matrix.size();i++)       /*O(R)*/
            {
                sum=sum+solve(mid,matrix[i]);
            }
            if(sum<=req)
            {
               low=mid+1;
            } 
            else
            {
                high=mid-1;
            }
        }
        return low;
    }
};

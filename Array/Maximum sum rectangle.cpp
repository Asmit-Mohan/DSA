class Solution
{
  public:
    int kadane(int arr[],int n)
    {
        int post=0;
        int pre=INT_MIN;
        
        for(int i=0;i<n;i++)
        {
            post=post+arr[i];
            if(post<arr[i])
            {
                post=arr[i];
            }
            pre=max(pre,post);
        }
        return pre;
    }
    
    int maximumSumRectangle(int R, int C, vector<vector<int>> M)
    {
        int ans=INT_MIN;
        
        for(int row=0;row<R;row++)
        {
            int temp[C]={0};
            
            for(int i=row;i<R;i++)
            {
                for(int j=0;j<C;j++)
                {
                    temp[j]=temp[j]+M[i][j];
                }
                ans=max(ans,kadane(temp,C));
            }
        }
        return ans;
    }
};

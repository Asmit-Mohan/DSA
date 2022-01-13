class Solution
{   
    public: 
    vector<int> spirallyTraverse(vector<vector<int>> arr, int r, int c) 
    {
        int top=0;
        int left=0;
        int right=c-1;
        int down=r-1;
        vector<int>v;
        while(top<=down&&left<=right)
        {
           for(int i=left;i<=right;i++)
           {
               v.push_back(arr[top][i]);
           }
           top++;
           for(int i=top;i<=down;i++)
           {
               v.push_back(arr[i][right]);
           }
           right--;
           if(top<=down)
           {
               for(int i=right;i>=left;i--)
               {
                  v.push_back(arr[down][i]);
               }
               down--;
           }
            if(left<=right)
            {
                for(int i=down;i>=top;i--)
                {
                    v.push_back(arr[i][left]);
                }
                left++;   
            }
        }
        return v;
    }
};
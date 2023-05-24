class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>>& arr)
    {
        vector<int>ans;

        int top=0;
        int left=0;
        int right=arr[0].size()-1;
        int down=arr.size()-1;

        while(top<=down&&left<=right)
        {
            for(int i=left;i<=right;i++)
            {
                ans.push_back(arr[top][i]);
            }
            top++;

            for(int i=top;i<=down;i++)
            {
                ans.push_back(arr[i][right]);
            }
            right--;

            if(top<=down)
            {
                for(int i=right;i>=left;i--)
                {
                    ans.push_back(arr[down][i]);
                }
                down--;
            }

            if(left<=right)
            {
                for(int i=down;i>=top;i--)
                {
                    ans.push_back(arr[i][left]);
                }
                left++;
            }
        }
        return ans;
    }
};

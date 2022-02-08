class Solution
{
public:
    vector<int> findDisappearedNumbers(vector<int>& arr)
    {
          vector<int>ans;
          for(int i=0;i<arr.size();i++)
          {
              if(arr[abs(arr[i])-1]>0)
              {
                 arr[abs(arr[i])-1]=-arr[abs(arr[i])-1];
              }
          }
        
          for(int i=0;i<arr.size();i++)
          {
              if(arr[i]>0)
              {
                  ans.push_back(i+1);
              }
          }
        return ans;
    }
};

class Solution
{
  public:
    vector <int> countDistinct (int A[], int n, int k)
    {
    unordered_map<int,int> mp;
    for(int i = 0; i < k; i++)  //First window
    {
        mp[arr[i]]++;
    }
    vector<int> res;
    res.push_back(mp.size());
    for(int i = k; i < n; i++)
    {
        mp[arr[i - k]]--;         //decrease  count of any respective key
        if(mp[arr[i - k]] == 0)  //If no duplicate cases are count is zero earlier 1 in above step
        {
            mp.erase(arr[i - k]);  //remove that element
        }
        mp[arr[i]]++;              //add futher element
        res.push_back(mp.size()); 
    }
    return res;
    }
};
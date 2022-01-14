class Solution
{
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x)
    {
       priority_queue <pair<int,int>> pq;
       //First int is Diff(key here) and second one is array value(which is to return).
       // In case key is same then max heap method is applied to second element of pair.
       for(int i=0;i<arr.size();i++)
       {
           pq.push({abs(arr[i]-x),arr[i]});
           if(pq.size()>k)
           {
               pq.pop();
           }
       }
       vector <int> v;
       while(!pq.empty())
       {
           //pair<int,int> p=pq.top();
           v.push_back(pq.top().second);
           pq.pop();
       }
        sort(v.begin(),v.end());
        return v;
    }
};

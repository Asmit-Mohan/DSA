class Solution
{
public:
    vector<int> maximizeArray(int arr1[], int arr2[], int n)
    {
        vector<int>ans;
        priority_queue<int>pq;
        for(int i=0;i<n;i++)
        {
            pq.push(arr1[i]);
            pq.push(arr2[i]);
        }
        unordered_set<int>s;
        while(!pq.empty())
        {
            if(s.size()==n)
            {
                break;
            }
            s.insert(pq.top());
            pq.pop();
        }
        for(int i=0;i<n;i++)
        {
            if(ans.size()==n)
            {
                break;
            }
            if(s.count(arr2[i])>0)
            {
                ans.push_back(arr2[i]);
                s.erase(arr2[i]);
            }
        }
        
        for(int i=0;i<n;i++)
        {
            if(ans.size()==n)
            {
                break;
            }
            if(s.count(arr1[i])>0)
            {
                ans.push_back(arr1[i]);
                s.erase(arr1[i]);
            }
        }
        return ans;
    }
};

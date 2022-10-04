class Solution
{
public:
    int furthestBuilding(vector<int>& arr, int b, int l)
    {
        priority_queue<int, vector<int>, greater<int>>pq;
        for(int i=0; i<arr.size()-1;i++)
        {
            if(arr[i+1]>arr[i])
            {
                pq.push(arr[i+1]-arr[i]);
            }
            if(pq.size()>l)
            {
                b =  b - pq.top();
                pq.pop();
                if(b < 0)
                {
                    return i;
                }
            }            
        }
        return arr.size()-1;        
    }
};

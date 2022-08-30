/* Time :- O(Nlogn) Space :- O[Max(arr[i].Dealine)] */

class Solution 
{
    public:
    static bool comp(Job a, Job b)
    {
        return a.profit>b.profit;
    }
    
    bool isPossible(vector<int>&visited,int dead)
    {
        for(int i=1;i<dead;i++)
        {
            if(visited[i]==0)
            {
                visited[i]=1;
                return 1;
            }
        }
        return 0;
    }
    
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        sort(arr,arr+n,comp);
        
        int num=0;
        int total=0;
        vector<int>ans;
        vector<int>visited(101,0);
        
        for(int i=0;i<n;i++)
        {
            if(visited[arr[i].dead]==0)
            {
                num++;
                visited[arr[i].dead]=1;
                total = total + arr[i].profit;
            }
            else
            {
                if(isPossible(visited,arr[i].dead))
                {
                    num++;
                    total = total + arr[i].profit;
                }
            }
        }
        
        ans.push_back(num);
        ans.push_back(total);
        return ans;
    } 
};

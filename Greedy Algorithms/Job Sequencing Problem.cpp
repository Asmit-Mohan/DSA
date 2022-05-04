class Solution /* Striver Code */
{
    public:
    static bool comp (Job a,Job b)
    {
        return a.profit>b.profit;
    }
    
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        sort(arr,arr+n,comp);
        int maxi=arr[0].dead;
        
        for(int i=0;i<n;i++)
        {
            maxi=max(maxi,arr[i].dead);
        }
        
        int complete[maxi+1]={0};
        int days=0;
        int profit=0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=arr[i].dead;j>0;j--)
            {
                if(complete[j]==0)
                {
                    complete[j]=1;
                    profit+=arr[i].profit;
                    days++;
                    break;
                }
            }
        }
        return {days,profit};
    } 
};

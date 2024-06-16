class Solution
{
public:
    int maxScore(vector<int>& arr, int k)
    {
    int sum=0;
    for(auto x : arr)
    {
        sum+=x;
    }
      
    k=arr.size()-k;
    if(k==0)
    {
        return sum;
    }
    
    int i=0;
    int j=0;
    int total=0;
    int ans=INT_MAX;
    
    while(j<arr.size())
    {
        total+=arr[j];
        if(j-i+1==k)
        {
            ans=min(ans,total);
            total=total-arr[i];
            i++;
            j++;
        }
        else
        {
            j++;
        }        
    }
    return sum-ans;
    }
};

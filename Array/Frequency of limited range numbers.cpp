/* Approach Using Space */

class Solution
{
public:
void frequencyCount(vector<int>& arr,int N, int P)
{ 
    unordered_map<int,int>mp;
    for(int i = 0 ; i < N ; i++ )
    {
        mp[arr[i]]++ ;
    }
    for(int i = 1 ; i <= N ; i++ )
    {
        arr[i-1] = mp[i];
    }
}
};

/* Optimised Approach */

class Solution
{
    public:
    void frequencyCount(vector<int>& arr,int n, int P)
    { 
        for(int i=0;i<n;i++)
        {
            arr[i]=arr[i]-1;
        }
        
        for(int i=0;i<n;i++)
        {
            if(arr[i]%P<n)
            {
                arr[arr[i]%P]=arr[arr[i]%P]+P;
            }
        }
        
        for(int i=0;i<n;i++)
        {
            arr[i]=arr[i]/P;
        }
    }
};

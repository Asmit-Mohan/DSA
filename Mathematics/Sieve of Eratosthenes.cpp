class Solution
{
public:
    vector<int> sieveOfEratosthenes(int N)
    {
        bool arr[N+1];
        memset(arr, true, sizeof(arr));
        arr[0]=false;
        arr[1]=false;
        for(int i=2;i<N;i++)
        {
            if(arr[i]==true)
            {
                for(int j=i*i;j<=N;j=j+i)
                {
                    arr[j]=false;
                }
            }
        }
        vector<int>v;
        for(int i=2;i<=N;i++)
        {
            if(arr[i]==true)
            {
                v.push_back(i);
            }
        }
        return v;
    }
};

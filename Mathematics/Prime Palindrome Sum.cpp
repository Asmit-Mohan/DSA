class Solution
{
    public:
    void palin(int n,long long &sum)
    {
    int temp = n;
    int rev=0;
    while (n != 0)
    {
        int remain = n % 10;
        rev = rev * 10 + remain;
        n = n/10;
    }
    if (temp == rev)
    {
        sum=sum+rev;
    }
    }
    long long getPPS(int a, int b)
    {
        bool arr[b+1];
        memset(arr, true, sizeof(arr));
        arr[0]=false;
        arr[1]=false;
        for(int i=2;i<=sqrt(b);i++)
        {
            if(arr[i]==true)
            {
                for(int j=i*i;j<=b;j=j+i)
                {
                    arr[j]=false;
                }
            }
        }
        vector<int>v;
        for(int i=a;i<=b;i++)
        {
            if(arr[i]==true)
            {
                v.push_back(i);
            }
        }
        long long sum=0;
        for(int i=0;i<v.size();i++)
        {
            palin(v[i],sum);
        }
        return sum;
    }
};

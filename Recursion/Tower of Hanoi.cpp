class Solution
{
public:
    int count=0;
    void solve(int src,int des,int help,int n)
    {
        count++;
        if(n==1)
        {
            cout<<"move disk " << n <<" from rod " << src << " to rod " << des<<endl;
            return;
        }
        solve(src,help,des,n-1);
        cout<<"move disk " << n <<" from rod " << src << " to rod " << des<<endl;
        solve(help,des,src,n-1);
        return;
    }
    
    long long toh(int N, int s, int d, int h)
    {
        solve(s,d,h,N);
        return count;
    }
};

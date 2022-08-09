/* Time :- O(Nlogn) Space :- O(N) */

class Solution
{
    public:
    vector<pair<int,int>> allPairs(int A[], int B[], int N, int M, int X)
    {
        vector<pair<int,int>>v;
        unordered_set<int>s;
        for(int i=0;i<M;i++)
        {
            s.insert(B[i]);
        }
        for(int i=0;i<N;i++)
        {
            if(s.find(X-A[i])!=s.end())
            {
                v.push_back({A[i],X-A[i]});
            }
        }
        sort(v.begin(), v.end());
        return v;
    }
};

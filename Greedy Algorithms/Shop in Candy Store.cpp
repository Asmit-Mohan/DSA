class Solution
{
public:
    vector<int> candyStore(int candies[], int n, int K)
    {
       int min=0;
       int max=0;
       sort(candies,candies+n);
       int i=0;
       int j=n-1;
       
       while(i<=j)
       {
           min+=candies[i];
           i++;
           j=j-K;
       }
       reverse(candies,candies+n);
       i=0;
       j=n-1;
       
       while(i<=j)
       {
           max+=candies[i];
           i++;
           j=j-K;
       }
       
       return {min,max};
    }
};

/* Time :- O(Nlogn) Space :- O(1) */

class Solution
{
public:
    vector<int> candyStore(int candies[], int n, int K)
    {
       int i=0;
       int j=n-1; 
       int min=0;
       int max=0;
       
       sort(candies,candies+n);
       
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

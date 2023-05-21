/* Time :- O(NloglogN) Space :- O(N) */
   
class Solution
{
public:
    vector<int> sieveOfEratosthenes(int N)
    {
       vector<int>ans;
       vector<bool>hash(N+1,true);
       
       hash[0]=false;
       hash[1]=false;
       
       for(int i=2;i<=N;i++)
       {
           if(hash[i])
           {
               for(int j=i*i;j<=N;j=j+i)
               {
                   hash[j]=false;
               }
           }
       }
       
       for(int i=0;i<=N;i++)
       {
           if(hash[i])
           {
               ans.push_back(i);
           }
       }
       return ans;
    }
};

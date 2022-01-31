class Solution
{
public:
    vector<int> distributeCandies(int candies, int person)
    {
       int j=0;
       vector<int>ans(person,0);
       while(candies>0)
       {
           for(int i=0;i<person;i++)
           {
               j++;
               candies=candies-j;
               if(candies<=0)
               {
                   ans[i]=ans[i]+candies+j;
                   break;
               }
               else
               {
                   ans[i]=ans[i]+j;
               }
           }
       }
       return ans;
     }
};

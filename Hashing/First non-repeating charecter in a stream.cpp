/* Time :- O(N*26) Space :- O(26) */

class Solution
{
     public:
     string FirstNonRepeating(string A)
     {
     unordered_map<char,int>mp;
     queue<char>q;
     string ans="";
     
     for(int i=0;i<A.size();i++)
     {
         if(mp[A[i]]==0)
         {
             q.push(A[i]);
         }
         
         mp[A[i]]++;
         
         while(!q.empty() && mp[q.front()]>1)
         {
             q.pop();
         }
         
         if(!q.empty())
         {
             ans+=q.front();
         }
         else
         {
             ans+='#';
         }
     }
     return ans;
   }
};

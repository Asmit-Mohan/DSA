/* Time :- O(N) Space :- O(N) */

class Solution
{
public:	
   vector<int> barcketNumbers(string S)
   {
      vector<int>v;
      int count=0;
      stack<int>s;
        
      for(int i=0;i<S.length();i++)
      {
         if(S[i]=='(')
         {
             v.push_back(++count);
             s.push(count);
         }
         else if(S[i]==')')
         {
             v.push_back(s.top());
             s.pop();
         }
      }
      return v;
    }
};

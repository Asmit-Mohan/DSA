/*Approach :- 1 O(n) space and O(n) time */
int countRev (string s)
{
   stack<char>st;
   int count1=0,count2=0;
   for(int i=0;i<s.length();i++)
   {
      if(s[i]=='{')
      {
          st.push('{');
          count2++;
      }
      else
      {
          if(!st.empty())
          {
              st.pop();
              count2--;
          }
          else
          {
              count1++;
          }
      }
  }
  if((count1+count2)%2!=0)
  {
      return -1;
  }
  count1=ceil(count1/2.0);
  count2=ceil(count2/2.0);
  return count1+count2;     
}

/*Efficient Approach time O(n) and constant space*/

int countRev(string s)
{
   if(s.length()%2!=0)
   {
       return -1;
   }
   int count=0;
   int ans=0;
   for(int i=0;i<s.length();i++)
   {
       if(s[i]=='{')
       {
           count++;
       }
       else
       {
           count--;
       }
       if(count<0)
       {
           ans++;
           count=1;
       }
   }
   return ans+count/2;
}


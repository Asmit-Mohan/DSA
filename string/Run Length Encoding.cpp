string encode(string str)
{     
   string ans="";
   int count=1;
   int i;
   for(i=0;i<str.length()-1;i++)
   {
       if(str[i]==str[i+1])
       {
           count++;
       }
       else
       {
           ans=ans+str[i];
           ans=ans+to_string(count);
           count=1;
       }
   }
   ans=ans+str[i];
   ans=ans+to_string(count);
   return ans;
}     

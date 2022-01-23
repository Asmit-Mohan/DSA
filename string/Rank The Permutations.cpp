class Solution
{
public:
    int rank(string S)
    {
       string k = S;
       sort(k.begin(),k.end());
       set<char>s;
       for(int i=0;i<S.size();i++)
       {
           s.insert(S[i]);
       }
       
       if(S.size()!=s.size())
       {
           return 0;
       }
       
       int ans=1;
       while(k!=S)
       {
          next_permutation(k.begin() , k.end()); /* Time Complexity of next_permutation is O(N) in worst case*/
          ans++;
          ans=ans%1000003; 
       }
       return ans%1000003;
    }
};

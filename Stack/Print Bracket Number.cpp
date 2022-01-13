class Solution
{
public:	
	vector<int> barcketNumbers(string S)
	{
       int count=0;
       stack<int>s;
       vector<int>v;
       for(int i=0;i<S.length();i++)
       {
           if(S[i]=='(')
           {
               v.push_back(++count);
               s.push(count);
           }
           else
           {
               v.push_back(s.top());
               s.pop();
           }
       }
       return v;
	}
};

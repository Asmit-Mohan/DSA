class Solution
{
public:
int evaluatePostfix(string S)
{
stack<int>s;
char c;
for(int i=0;i<S.size();i++)
{
if(isdigit(S[i]))   
{
s.push(S[i]-'0');  //Char to int conversion
}
else
{
c=S[i];
int va1=s.top();
s.pop();
int va2=s.top();
s.pop();
switch(c)
{
case '+':
s.push(va2+va1);
break;
case '-':
s.push(va2-va1);
break;
case '*':
s.push(va2*va1);
break;
case '/':
s.push(va2/va1);
break;
}
}
}
return s.top();
}
};

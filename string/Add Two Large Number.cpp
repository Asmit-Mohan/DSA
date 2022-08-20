/* Time :- O(N) Space :- O(N) */

class Solution
{
    public:
    string findSum(string num1, string num2)
    {
        if(num2.size()>num1.size())
        {
            return findSum(num2,num1);  /* Assuming num1 always greater or equal */
        }
        
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
        int i=0;
        int j=0;
        int carry=0;
        int data=0;
        string ans="";
        
        while(i<num1.length()&&j<num2.length())
        {
            data=(num1[i]-'0'+num2[j]-'0'+carry);
            carry=data/10;
            data=data%10;
            ans.push_back(data+'0');
            i++;
            j++;
        }
        while(i<num1.size())
        {
            data=(num1[i]-'0'+carry);
            carry=data/10;
            data=data%10;
            ans.push_back(data+'0');
            i++;
        }
        if(carry)
        {
            ans.push_back(carry+'0');
        }
        
        reverse(ans.begin(),ans.end());
        while(ans[0]=='0'&&ans.size())
        {
            ans.erase(ans.begin());
        }
        return ans.size()==0?"0":ans;        
    }
};

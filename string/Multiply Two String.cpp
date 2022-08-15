/* Approach 1 */

class Solution
{
public:
    string multiply(string num1, string num2)
    {
        int n = num1.size();
        int m = num2.size();
        string ans(n + m, '0');
      
        for(int i = n - 1; i >= 0; i--)
        {
            for(int j = m - 1; j >= 0; j--)
            {
                int mul = (num1[i] - '0') * (num2[j] - '0');
                int sum = (ans[i + j + 1]-'0') + mul;
                ans[i+j+1] = sum % 10 + '0';
                ans[i+j] += sum / 10 ;
            }
       }
      
       for(int i = 0; i < m + n; i++)
       {
          if(ans[i] !='0') 
	  {
	      return ans.substr(i);
          }
       }
       return "0"; 
    }
};

/* Approach 2 */

class Solution
{
public:
    
    string addStrings(string num1, string num2)
    {
        if(num1=="0")
        {
            return num2;
        }
        if(num2=="0")
        {
            return num1;
        }
        
        if(num2.size()>num1.size())
        {
            return addStrings(num2,num1);  /* Assuming num1 always greater or equal */
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
        return ans;
    }
    
    string multiply(string num1, string num2)
    {    
        string ans = "";
        int powN = 0;
        
        for(int i=num2.size()-1; i>=0; i--)
        {
            string temp = "";
            temp.append(powN, '0');
            int tempSum = 0;
            
            for(int j=num1.size()-1; j>=0; j--)
            {
                tempSum += (num1[j] - '0')*(num2[i] - '0');
                temp = to_string(tempSum%10) + temp;
                tempSum = tempSum/10;
            }
            
            if(tempSum)
            {
                temp = to_string(tempSum) + temp;
            }
            ans = addStrings(ans, temp);
            powN++;
        }
        
        while(ans[0] == '0')
        {
            ans.erase(ans.begin());
        }
        if(ans == "")
        {
            return "0";
        }
        return ans;
    }
};

class Solution
{
public:
    vector<int> factorial(int N)
    {
        vector<int> v;
        if(N==0)
        {
            return v;
        }
        v.push_back(1);
        
        int carry=0;
        int prod=1;
        
        for(int i=2;i<=N;i++)
        {
            for(int j=0;j<v.size();j++)
            {
                prod=v[j]*i+carry;
                v[j]=prod%10;
                carry=prod/10;
            }
            while(carry>0)
            {
                v.push_back(carry%10);
                carry = carry/10;
            }
        }
        reverse(v.begin(),v.end());
        return v;     
    }
};

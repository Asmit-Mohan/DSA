class Solution
{
public:
    bool isHappy(int n)
    {
        if(n/10==0)
        {
            if(n%10==1)
            {
                return true;
            }
            if(n%10<5)
            {
                return false;
            }
        }
        
        int sum=0;
        while(n>0)   
        {
            sum = sum + (n%10)*(n%10);
            n=n/10;
        }
        return isHappy(sum);
    }
};

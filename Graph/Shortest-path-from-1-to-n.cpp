class Solution
{   
public:
    int minimumStep(int n)
    {
        int count=0;
        while(n>1)
        {
            if(n%3==0)
            {
                count++;
                n=n/3;
            }
            else
            {
                n--;
                count++;
            }
        }
        return count;
    }
};

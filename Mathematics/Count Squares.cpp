class Solution
{
  public:
    int countSquares(int N)
    {
        int temp=sqrt(N);
        if((temp*temp)==N)
        {
            return temp-1;   
        }
        else
        {
            return temp;
        }
    }
};
class Solution
{
  public:
    int canReach(int arr[], int N)
    {
        int reach=0;
        for(int i=0;i<N;i++)
        {
            if(reach<i)  /*Means reach had left behind the current index*/
            {
                return 0;
            }
            else if(reach>=N-1)  /*if current reach has been reached or crossed to last index*/
            {
                return 1;
            }
            else
            {
                reach=max(reach,i+arr[i]);  /*keep updating the maxi. reach point index*/
            }
        }
    }
};
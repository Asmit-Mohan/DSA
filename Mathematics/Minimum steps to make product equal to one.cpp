class Solution
{
  public:
    int makeProductOne(int arr[], int n)
    {
        int count=0;
        int pro=1;
        int zeroNum=0;
        for(int i=0;i<n;i++)
        {
            count=count+(abs(abs(arr[i])-1));
            if(arr[i]<0)
            {
                pro=pro*-1;
            }
            else if(arr[i]>0)
            {
                pro=pro*1;
            }
            else
            {
                zeroNum++;
            }
        }
        if(pro==-1&&zeroNum==0)
        {
            count=count+2;
        }
        return count;
    }
};
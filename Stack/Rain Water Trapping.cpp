/* Time :- O(N) Space :- O(N) */

class Solution
{
public:
 int trap(vector<int>& height)
 {
    int len=height.size();
    int mxl[len];
    int mxr[len];
    mxl[0]=height[0];
    
    for(int i=1;i<len;i++)
    {
        mxl[i]=max(mxl[i-1],height[i]);
    }
    
    mxr[len-1]=height[len-1];
    for(int i=len-2;i>=0;i--)
    {
        mxr[i]=max(mxr[i+1],height[i]);
    }
    
    int water[len];
    for(int i=0;i<len;i++)
    {
        water[i]=min(mxl[i],mxr[i])-height[i];
    }
    
    int sum=0;
    for(int i=0;i<len;i++)
    {
        sum=sum+water[i];
    }
    return sum;
  }
};

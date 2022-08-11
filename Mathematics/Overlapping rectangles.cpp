/* GFG */

class Solution
{
  public:
    int doOverlap(int L1[], int R1[], int L2[], int R2[])
    {
        if(L1[0]>R2[0] || L2[0]>R1[0])
        {
            return false;
        }
        else if(L1[1]<R2[1] || L2[1]<R1[1])
        {
            return false;
        }
        else
        {
            return true;
        }
    }
};
 
/* Leetcode */

class Solution
{
   public:
   bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) 
   {
       if(rec1[0]>=rec2[2] || rec2[0]>=rec1[2])
       {
           return false;
       }
       else if(rec2[1]>=rec1[3] || rec1[1]>=rec2[3]) 
       {
           return false;
       }
       else
       {
           return true;
       }
   }
};

/* Time :- O(logn) Space :- O(1) */

/*Number of times array is rotated equals to index of minimum element*/

class Solution
{
public:	
   int findKRotation(int a[], int n)
   {
      int l=0;
      int r=n-1;
      while(l<r)
      {
         int mid=l+(r-l)/2;
         if(a[mid]>a[r])
         {
             l=mid+1;      //It means r is near rotated sorted point
         }
         else
         {
             r=mid;      //r is greater then all element next to r will be grater then move to mid
         }
     }
     return l;
   }
};

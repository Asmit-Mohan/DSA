class Solution
{
  public:
    int assignMiceHoles(int n , int m[] , int h[])
    {
        /*Here We can put every mouse to its nearest hole to minimize the time.
        This can be done by sorting the positions of mice and holes 
        and obtain diff of rat pos and hole pos and then find max pos diff..*/
        sort(m,m+n);
        sort(h,h+n);
        int maxi=INT_MIN;
        for(int i=0;i<n;i++)
        {
           int temp=abs(m[i]-h[i]);
           maxi=max(maxi,temp);
        }
        return maxi;
    }
};

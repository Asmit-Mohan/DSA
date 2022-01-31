class Solution
{
public:	
	int search(int A[], int N)
	{
	    if(N==1)
	    {
	        return A[0];
	    }
        else if(A[0]!=A[1])
        {
            return A[0];
        }
        else if(A[N-1]!=A[N-2])
        {
            return A[N-1];
        }
        else
        {
              int l=0;
              int r=N-1;
              while(l<=r)
              {
                  int mid=l+(r-l)/2;
                  if(A[mid]!=A[mid+1]&&A[mid]!=A[mid-1])    /*if not equal to its neighbour then it is answer*/
                  {
                      return A[mid];
                  }
                  else if(A[mid]==A[mid-1]) 
                  {
                      int lcount=mid-l+1;
                      if(lcount%2==0)
                      {
                          l=mid+1;
                      }
                      else
                      {
                          r=mid-2;      /*because mid and mid-1 are same*/
                      }
                  }
                  else if(A[mid]==A[mid+1])
                  {
                      int rcount=r-mid+1;
                      if(rcount%2==0)
                      {
                          r=mid-1;
                      }
                      else
                      {
                          l=mid+2;      /*because mid and mid+1 are same*/
                      }
                  }
              }
          }
     }
};

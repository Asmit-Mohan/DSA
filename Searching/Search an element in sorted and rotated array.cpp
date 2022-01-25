int binary(vector<int> arr,int l,int r,int k)
{
    int mid=l+(r-l)/2;
    while(l<r)
    {
        if(arr[mid]==k)
        {
            return mid;
        }
        else if(arr[mid]>k)
        {
            r=mid-1;
        }
        else
        {
            l=mid+1;
        }
    }
    return 0;
}
int solve(vector<int> a, int n)
{
	int l=0;
    int r=n-1;
    while(l<r)
    {
        int mid=l+((r-l)/2);
        if(a[mid]>a[r])
        {
           l=mid+1;  //It means r is near rotated sorted point
        }
        else
        {
           r=mid; //r is greater then all element next to r will be grater then move to mid
        }
    }
    return l;
}

int Search(vector<int> vec, int K)
{
     int idx=solve(vec,vec.size());
     if(K==vec[idx])
     {
         return idx;
     }
     
     if(K==vec[vec.size()-1])
     {
         return vec.size()-1;
     }
     
     int ans1=binary(vec,idx,vec.size()-1,K);
     int ans2=binary(vec,0,idx-1,K);
     
     if(ans1==0)
     {
         return ans2;
     }
     else if(ans2==0)
     {
         return ans1;
     }
     else
     {
         return -1;
     }
}

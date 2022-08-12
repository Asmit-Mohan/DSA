/* Approach 1 (STL) Time :- O(m+n) Space :- O(m+n) */

class Solution
{
       public: 
       vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
       {
              set<int>s1,s2,s3;
              vector<int>v;
              for(int i=0;i<n1;i++)
              {
                  s1.insert(A[i]);
              }
              for(int i=0;i<n2;i++)
              {
                  if(s1.find(B[i])!=s1.end())
                  {
                      s2.insert(B[i]);
                  }
              }
              for(int i=0;i<n3;i++)
              {
                  if(s2.find(C[i])!=s2.end())
                  {
                      s3.insert(C[i]);
                  }
              }
              set<int>::iterator itr;
              for (itr=s3.begin(); itr != s3.end(); itr++)
              {
                  v.push_back(*itr);
              }
              return v;
        }
};

/*Approach 2 (Binary Search) --> Time :- suppose min of n1,n2,n3 is n1 -->  O(n1*[log(n2)+log(n3)]) Space :- O(min(n1,n2,n3)) */

class Solution
{
   public:    
   int bSearch(int target,int n,int arr[])
    {
        int low=0;
        int high=n;
        while(low<=high)
        {
            int  mid=low+(high-low)/2;
            if(arr[mid]==target)
            {
                return 1;
            }
            else if(arr[mid]>target)
            {
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return 0;
    }
    vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
    {
        vector<int>ans;
        set<int>s;
        int range=min(min(n1,n2),n3);
        
        if(range==n1)
        {
            for(int i=0;i<n1;i++)
            {
                int flag1=bSearch(A[i],n2,B);
                int flag2=bSearch(A[i],n3,C);
                if(flag1&&flag2)
                {
                    s.insert(A[i]);
                }
            }
        }
        else if(range==n2)
        {
            for(int i=0;i<n2;i++)
            {
                int flag1=bSearch(B[i],n1,A);
                int flag2=bSearch(B[i],n3,C);
                if(flag1&&flag2)
                {
                    s.insert(B[i]);
                }
            }
        }
        else
        {
            for(int i=0;i<n3;i++)
            {
                int flag1=bSearch(C[i],n1,A);
                int flag2=bSearch(C[i],n2,B);
                if(flag1&&flag2)
                {
                    s.insert(C[i]);
                }
            }
        }
        
        for(auto x : s)
        {
            ans.push_back(x);
        }
        if(ans.size()==0)
        {
            ans.push_back(-1);
        }
        return ans;
    }
};

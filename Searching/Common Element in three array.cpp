/*Approach 1 (STL)*/

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

/*Approach 2 (Binary Search)*/

class Solution
{
   public:    
   vector <int> commonElements (int a[], int b[], int c[], int n1, int n2, int n3)
       {
           int n = min(n1,min(n1,n2));
           set<int>ans;
           if(n == n1)
           {
               for(int i=0;i<n1;i++)
               {
                   if(binary_search(b,b+n2,a[i])== true && binary_search(c,c+n3,a[i])==true)
                   {
                       ans.insert(a[i]);
                   }
               }
           }
           else if(n==n2)
           {
               for(int i =0;i<n2;i++)
               {
                   if(binary_search(a,a+n1,b[i])== true && binary_search(c,c+n3,b[i])==true)
                   {
                       ans.insert(b[i]);
                   }
               }
           }
           else if(n == n3)
           {
               vector<int>v(n3,0);
               for(int i =0;i<n3;i++)
               {
                   if(binary_search(a,a+n1,c[i])== true && binary_search(b,b+n2,c[i])==true)
                   {
                       ans.insert(c[i]);
                   }
               }
           }
           vector<int>res;
           for(auto it:ans)
           {
               res.push_back(it);
           }
           if(res.size()==0)
           {
               res.push_back(-1);
           }
           return res;
       }
};

vector<long long> printFirstNegativeInteger(long long int A[],long long int N, long long int K)
{
    vector<long long>v;
    int i=0;
    int j=0;
    queue<long long>temp;
    while(j<N)
    {
       if(A[j]<0)
       {
          temp.push(A[j]);
       }
       if(j-i+1==K)
       {
           if(temp.size()>0)
           {
             v.push_back(temp.front());
             if(A[i]==temp.front())
             {
                temp.pop();
             }
           }
           else
           {
               v.push_back(0);
           }
           i++;
           j++;
       }
       else
       {
          j++;   
       }
    }
    return v;
}
class Solution
{
public:
    int buyMaximumProducts(int n, int total, int arr[])
    {
       vector<pair<int,int>>v;
       int count=0;
       for(int i=0;i<n;i++)
       {
           v.push_back({arr[i],i+1});
       }
       sort(v.begin(),v.end());
       for(int i=0;i<v.size();i++)
       {
           int amount=v[i].first;
           int quantity=v[i].second;
           int temp=amount*quantity;
           
           if(total==0)
           {
               break;
           }
           
           if(temp<=total)
           {
               count+=quantity;
               total-=temp;
           }
           else
           {
               int flag=total/amount;
               count+=flag;
               total-=(flag*amount);
           }
       }
       return count;
    }
};

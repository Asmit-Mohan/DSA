class Solution
{   
public:
    void threeWayPartition(vector<int>& array,int a, int b)
    {
      int i=0;
      int l=0;
      int h=array.size()-1;
      while(i<=h)
      {
          if(array[i]<a)
          {
              swap(array[i++],array[l++]);
          }
          else if(array[i]>b)
          {
              swap(array[i],array[h--]);
          }
          else
          {
              i++;
          }
      }
    }
};

/* Time :- O(Nlogn) Space :- O(1) */

class Solution
{
    public:
    static bool comp(Item a,Item b)
    {
        double r1=(double)a.value / (double)a.weight;
        double r2=(double)b.value / (double)b.weight;
        return r1>r2;
    }
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        sort(arr, arr + n, comp);  //Decending order sort
        int curweight=0;
        double finalvalue=0.0;
        
        for(int i=0;i<n;i++)
        {
            if(curweight+arr[i].weight<=W)
            {
                curweight += arr[i].weight;
                finalvalue += arr[i].value;
            }
            else
            {
                int remain=W-curweight;
                finalvalue += (arr[i].value/(double)arr[i].weight)*(double)remain;
                break;
            }
        }
        return finalvalue;
    }
};

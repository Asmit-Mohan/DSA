/* Time :- O(N) Space :- O(1) */

class Solution
{
public:
    int sum(vector<int>arr)
    {
        int sum=0;
        for(int i=0;i<arr.size();i++)
        {
            sum+=arr[i];
        }
        return sum;
    }
    
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
    {
        int gasSum = sum(gas);
        int costSum = sum(cost);
        if(gasSum<costSum)
        {
            return -1;
        }
        
        int total=0;
        int ans=0;
        
        for(int i=0;i<gas.size();i++)
        {
            total+=gas[i]-cost[i];
            
            if(total<0)
            {
                total=0;
                ans=i+1;
            }
        }
        return ans;
    }
};

/* Intution :- If total gas available is less than required gas return -1 */

/* Else we will check for total gas at each step if it is negative that means that is not my starting        point so put it zero and assume that may be next step ie. i+1 will be answer */

/* Due to unique solution once total becomes > 0 then ans will not be changed */

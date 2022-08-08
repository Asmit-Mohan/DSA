/* Time :- O(Nlogn) Space :- O(N) */

class Solution
{
public:
    int minValue(string s, int k)
    {
        int hash[27]={0};
        priority_queue <int> pq;
        int sum=0;
        for(int i=0;i<s.size();i++)
        {
            hash[s[i]-'a']++;
        }
        for(int i=0;i<26;i++)
        {
            if(hash[i]>0)
            {
                pq.push(hash[i]);
            }
        }
        while(k--)
        {
             int temp=pq.top();
             pq.pop();
             temp--;
             pq.push(temp);
        }
        while(pq.size()>0)
        {
            int temp=pq.top();
            pq.pop();
            sum=sum+(temp*temp);
        }
        return sum;
    }
};

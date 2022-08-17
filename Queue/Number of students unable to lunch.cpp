/* Time :- O(N) Space :- O(N) */

class Solution
{
public:
    int countStudents(vector<int>& st, vector<int>& sand)
    {
        int i=0;
        int j=0;
        queue<int>q;
        
        while(i<st.size()&&j<sand.size())
        {
            if(st[i]==sand[j])
            {
                i++;
                j++;
            }
            else
            {
                q.push(st[i]);
                i++;
            }
        }
        
        if(i==st.size()&&j==sand.size())
        {
            return 0;
        }
        
        int count=0;
        
        while(j!=sand.size())
        {
            if(q.front()==sand[j])
            {
                q.pop();
                j++;
                count=0;
            }
            else
            {
                q.push(q.front());
                q.pop();
                count++;
            }
            if(count==q.size())
            {
                break;
            }
        }
        return q.size();
    }
};

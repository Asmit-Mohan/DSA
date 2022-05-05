class Solution
{
public:
    int countStudents(vector<int>& st, vector<int>& snd)
    {
        int i=0,j=0;
        queue<int> q;
        while(i!=st.size() && j!=snd.size())
        {
            if(st[i]==snd[j])
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
        
        if(i==st.size() && j==snd.size())
        {
            return 0; 
        }
        int count=0;
        while(j!=snd.size())
        {
            
            if(q.front()==snd[j])
            {
                q.pop();
                j++;
                count=0;
            }
            else
            {
                q.push(q.front());
                q.pop();
                ++count;
            }
            if(count==q.size())
            {
                break;
            }
        }
        return q.size();
    }
};

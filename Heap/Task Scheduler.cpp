class Solution  /*Neetcode Explanation*/
{
public:
    int leastInterval(vector<char>& tasks, int n)    
    {
        if(n==0)
        {
            return tasks.size();
        }
        
        int timeElapsed = 0;
        priority_queue<pair<int, int>> pq;
        queue<pair<int, int>> wait;
        int freq[26]={0};
        
        for(char ch : tasks)
        {
            freq[ch - 'A']++;
        }
        for(int i=0; i<26; i++)
        {
            if(freq[i] > 0)
            {
                pq.push({freq[i],0});
            }
        }
        
        while(!pq.empty() || wait.size() != 0)
        {
            if(!pq.empty())
            {
                pair<int,int> curr = pq.top();
                pq.pop();
                if(--curr.first > 0)
                {
                    curr.second = timeElapsed + n;
                    wait.push(curr);
                }
            }
            
            while(wait.size() != 0 && wait.front().second == timeElapsed)
            {
                pair<int, int> canChoose = wait.front();
                wait.pop();
                canChoose.second = 0;
                pq.push(canChoose);
            }   
            timeElapsed++;
        }
        return timeElapsed;
    }
};

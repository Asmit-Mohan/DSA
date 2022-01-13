class Solution
{
public:
int search(string pat, string txt)
{
unordered_map <char,int> m;
for(int i=0;i<pat.size();i++)
{
   m[pat[i]]++;     // Will store the count of all charecters of pat.
}
int k = pat.size();     // window size as in every window we will have size of pattern only
int count = m.size();  // number of alphabet in pat string.
int ans = 0;           // count number of anagram
int i = 0, j = 0;
while(j < txt.size())
{
	if(m.find(txt[j]) != m.end()) // if say pat is aaba then if a found in txt.
	{
	m[txt[j]]--;            // then decrease count of a in map.
	if(m[txt[j]] == 0)
	{
	    count--;   // it means all a in aaba are present in txt then number alphabet decreases. 
	}
	}
	if(j - i + 1 < k)
	{
	    j++;
	}
	else if(j - i + 1 == k)
	{
		if(count == 0)       // it means all alphabet are present in txt in same frequency ie. pattern
		{
		    ans++;  // count anagram
		}
		if(m.find(txt[i]) != m.end())   
		{
			m[txt[i]]++;
			if(m[txt[i]] == 1)
			{
			    count++;
			}
		}
		i++;
		j++;
	}
}
return ans;	  
}
};
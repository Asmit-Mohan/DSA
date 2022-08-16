/* Time :- O(n) Space :- O(n) */

#include <bits/stdc++.h>
using namespace std;
int main()
{
	string str="Geeks for Geeks A Computer Science portal for Geeks";
	string res;
	unordered_set<string>s;
	stringstream ss(str);
	string word;
	
	while(ss>>word)
	{
		s.insert(word);
	}
	for(auto itr = s.begin(); itr != s.end(); ++itr)
	{
		res=res+(*itr)+" ";
	}
	cout<<res;
	return 0;
}

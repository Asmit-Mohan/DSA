#include <bits/stdc++.h>
using namespace std;
int main()
{
	string str="Geeks for Geeks A Computer Science portal for Geeks";
	string res;
	stringstream ss(str);
	string word;
	while(ss>>word)
	{
		reverse(word.begin(),word.end());
		res=res+word+" ";
	}
	cout<<res;
	return 0;
}

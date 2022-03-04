#include <bits/stdc++.h>
using namespace std;
int calculate_sum(string str)
{
	string temp = "";
	int sum = 0;
	for (char ch: str)
	{
		if (isdigit(ch))
			temp += ch;
		else
		{
			sum += atoi(temp.c_str());
			temp = "";
		}
	}
	return sum + atoi(temp.c_str());
}
int main()
{
	string str;
	cin >> str;
	cout << calculate_sum(str);
	return 0;
}

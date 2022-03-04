#include <iostream>
#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
int findSum(string str)
{
    string temp = "";
    int sum = 0;
    for (char ch : str) {
        if (isdigit(ch))
            temp += ch;
        else {
            sum += atoi(temp.c_str());
            temp = "";
        }
    }
    return sum + atoi(temp.c_str());
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    string str;
    cin>>str;
    cout << findSum(str);
    return 0;
}

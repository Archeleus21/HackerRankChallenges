// NumberLineJumps.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'kangaroo' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. INTEGER x1
 *  2. INTEGER v1
 *  3. INTEGER x2
 *  4. INTEGER v2
 */

string kangaroo(int x1, int v1, int x2, int v2)
{
	if (v1 <= v2)
	{
		return "NO";
	}
	if ((x2 - x1) % (v1 - v2) == 0)
	{
		return "YES";
	}
	else
	{
		return "NO";
	}
}

int main()
{
	
}

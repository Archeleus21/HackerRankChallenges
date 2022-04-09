// BetweenTwoSets.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'getTotalX' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY a
 *  2. INTEGER_ARRAY b
 */

 //get greatest common denominator
int getGCD(int n1, int n2)
{
	if (n2 == 0) {
		return n1;
	}
	return getGCD(n2, n1 % n2);
}

//get lowest common multiple
int getLCM(int n1, int n2)
{
	if (n1 == 0 || n2 == 0)
		return 0;
	else {
		int gcd = getGCD(n1, n2);
		return abs(n1 * n2) / gcd;
	}
}

int getTotalX(vector<int>& a, vector<int>& b) {
	int result = 0;

	//get LCM of all integers in a
	int lcm = a[0];
	for (auto n : a)
	{
		lcm = getLCM(lcm, n);
	}

	//get GDC of all integers in a
	int gcd = b[0];
	for (auto n : b)
	{
		gcd = getGCD(gcd, n);
	}

	//count multiples of lcm that divided gcd
	int multiple = 0;
	while (multiple <= gcd)
	{
		multiple += lcm;

		if (gcd % multiple == 0)
		{
			result++;
		}
	}

	return result;
}

int main()
{
	
}

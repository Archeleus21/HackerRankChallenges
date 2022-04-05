// RepeatingString.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'repeatedString' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. STRING s
 *  2. LONG_INTEGER n
 */

long repeatedString(string s, long n) {
	long long len = s.length();

	//count number of times 'a' appears in the initial string
	long long count = 0;
	for (long i = 0; i < len; i++)
	{
		if (s[i] == 'a')
		{
			++count;
		}
	}

	//get how many times the string is repeated
	long long repeatedTimes = n / len;

	//find the length of the string left after the repetitions
	long long stringLeftLength = n - (len * repeatedTimes);

	//count the remaining repetitions
	int extra = 0;
	for (long i = 0; i < stringLeftLength; i++)
	{
		if (s[i] == 'a')
		{
			++extra;
		}
	}

	long long totalCount = (repeatedTimes * count) + extra;
	return totalCount;
}

int main()
{
    std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

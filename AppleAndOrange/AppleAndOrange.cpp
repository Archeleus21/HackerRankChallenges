// AppleAndOrange.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'countApplesAndOranges' function below.
 *
 * The function accepts following parameters:
 *  1. INTEGER s
 *  2. INTEGER t
 *  3. INTEGER a
 *  4. INTEGER b
 *  5. INTEGER_ARRAY apples
 *  6. INTEGER_ARRAY oranges
 */

void countApplesAndOranges(int& s, int& t, int& a, int& b, vector<int>& apples, vector<int>& oranges)
{
	//fruit distance from house
	int d = 0;
	int mCount = 0;
	int nCount = 0;

	//get distance of apples from house
	for (int& m : apples)
	{
		//get distance of apples
		d = m + a;
		//check if they fell on the house
		if (d >= s && d <= t)
		{
			mCount++;//add to count if apples are on the house
		}
	}
	for (int& n : oranges)
	{
		//get distance of oranges
		d = n + b;
		//check if oranges fell on the house
		if (d >= s && d <= t)
		{
			nCount++;
		}
	}
	cout << mCount << "\n" << nCount << endl;
}
int main()
{
    
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

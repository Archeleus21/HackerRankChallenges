#include <iostream>
#include <map>
#include <vector>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'sockMerchant' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER_ARRAY ar
 */

int sockMerchant(int n, vector<int>& ar) {
	//map to store data and count occurances
	map<int, int> countP;
	int pairs = 0; //count up per pair

	//itereate throught map
	for (int& n : ar)
	{
		countP[n]++;
		if (!(countP[n] % 2))
		{
			pairs++;
		}
	}
	return pairs;
}
#include <iostream>
#include <sstream>
#include <ostream>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'countingValleys' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER steps
 *  2. STRING path
 */

int countingValleys(int steps, string path) {
	int seaLevel = 0;
	int valley = 0;

	for (int i = 0; i < steps; i++)
	{
		if (path[i] == 'U')
		{
			seaLevel++;
			if (seaLevel == 0)
			{
				valley++;
			}
		}
		else
		{
			seaLevel--;
		}
	}
	return valley;
}

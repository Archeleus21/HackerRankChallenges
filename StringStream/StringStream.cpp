#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

vector<int> parseInts(string str) {
	// Complete this function
	vector<int> vStr; //store integers
	stringstream ss(str); //read str

	//store values from str
	int n;
	//comma dilimeter
	char ch;

	//loop through str
	while (ss)
	{
		//check for integers
		if (ss.peek() != ',')
		{
			//add to vector
			if (ss >> n)
			{
				vStr.push_back(n);
			}
		}
		else
		{
			//skip if its a comma
			ss >> ch;
		}
	}
	return vStr;
}

int main() {
	string str;
	cin >> str;
	vector<int> integers = parseInts(str);
	for (int i = 0; i < integers.size(); i++) {
		cout << integers[i] << "\n";
	}

	return 0;
}
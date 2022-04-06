// GradingStudents.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

vector<int>& gradingStudents(vector<int>& grades)
{
	int n; //store new grade

	//foreach loop to go through the array
	for (int& grade : grades)
	{
		//check grades to be rounded
		if (grade >= 38)
		{
			n = grade % 5; //get remainder/difference
			if (n >= 3)
			{
				grade += (5 - n);
			}
		}
	}

	return grades;
}

int main()
{
    std::cout << "Hello World!\n";
}


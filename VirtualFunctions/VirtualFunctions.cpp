#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Person {
protected:
	int age;
	string name;

public:
	Person() {}
	virtual void getdata() {}
	virtual void putdata() {}

	~Person() {}

};

class Professor : public Person
{
private:
	int publications, cur_id;
	static int id;

public:
	Professor() {
		id++;
		cur_id = id;
	}

	void getdata() {
		// No need for getline()
		cin >> name >> age >> publications;
		// id++;
	}

	void putdata() {
		cout << name << " " << age << " " << publications << " " << cur_id << endl;
	}

	~Professor() {}
};

class Student : public Person
{
private:
	const int MAX = 6;
	int* marks = new int[MAX];
	int cur_id;
	static int id;

public:
	Student() {
		id++;
		cur_id = id;
	}
	void getdata()
	{
		// Store the student's name and age
		cin >> name >> age;

		// Populate the marks
		for (int i = 0; i < MAX; i++)
		{
			cin >> marks[i];
		}
	}

	void putdata() {
		// Display the student's name and age
		cout << name << " " << age << " ";

		// Compute the sum of the marks
		int sum = 0;
		// Print the marks
		for (int i = 0; i < MAX; i++)
		{
			sum += marks[i];
		}

		// Display the sum of the marks and cur_id;
		cout << sum << " " << cur_id << endl;
	}

	~Student() {
		delete[] marks;
	}
};

// Initialize static variables
int Professor::id = 0;
int Student::id = 0;

int main() {

	int n, val;
	cin >> n; //The number of objects that is going to be created.
	Person *per[n];

	for (int i = 0; i < n; i++) {

		cin >> val;
		if (val == 1) {
			// If val is 1 current object is of type Professor
			per[i] = new Professor;

		}
		else per[i] = new Student; // Else the current object is of type Student

		per[i]->getdata(); // Get the data from the user.

	}

	for (int i = 0; i < n; i++)
		per[i]->putdata(); // Print the required output for each object.

	return 0;

}

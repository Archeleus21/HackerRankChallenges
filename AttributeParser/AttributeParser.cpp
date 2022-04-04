// AttributeParser.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <map>
#include <sstream>
#include <string>

using namespace std;

int main()
{
	//store number of lines and number of queries
	int n, q;
	//store the query data as a string
	string s = "", attr_name;
	//create map container
	map<string, string> m;
	//get input
	cin >> n >> q;
	//remote next line character
	cin.ignore();

	//first loop to check data
	for (int i = 0; i < n; i++)
	{
		//create strings to grab data.
		string line, tag, extract;
		getline(cin, line);
		//push string into ss object
		stringstream ss(line);

		//go through the HRML lines provided
		while (getline(ss, extract, ' '))  //the empty space is a delimeter showing the end of a subset of data
		{
			//check if it is a tag
			if (extract[0] == '<')
			{
				//if it is an open tag
				if (extract[1] != '/')
				{
					//remove everything before the first index, "<"
					tag = extract.substr(1);
					//for tags without attributes, <a> or <tag1>
					if (tag[tag.length() - 1] == '>')
					{
						//remove closing bracket at the end of the string, ">"
						tag.pop_back();
					}
					//check if nesting another tag is needed, if it's empty than it doesnt need nesting
					if (s.size() > 0)
					{
						//concatinate string and nested tag
						s += "." + tag;
					}
					else
					{
						//tag does not need need to be nested
						s = tag;
					}
				}
				//if the tag is a closing tag
				else
				{
					//removed everything before the 2 index, '<''/' then find the closing bracket '>' minus 2 removes the last index
					tag = extract.substr(2, (extract.find('>') - 2));
					//check if nested tag needs to be closed
					size_t pos = s.find("." + tag);
					if (pos != string::npos)
					{
						//removed the nested tag
						s = s.substr(0, pos);
					}
					else
					{
						//all the tags have been closed we can clear the s variable
						s = "";
					}
				}
			}
			//checks the attributes value
			else if (extract[0] == '"')
			{
				//get the full value and get the last quotations
				size_t pos = extract.find_last_of('"');
				string attr_value = extract.substr(1, pos - 1);
				//finally add value to the map
				m[attr_name] = attr_value;
			}
			else
			{
				if (extract != "=")
				{
					//it's definitely an attribute name
					attr_name = s + "~" + extract;	
				}
			}
		}
	}
	//get the values from the queries
	string query;
	for (int i = 0; i < q; i++)
	{
		getline(cin, query);

		//searching the map
		map<string, string>::iterator itr = m.find(query);
		if (itr != m.end())
		{
			cout << itr->second << endl;
		}
		else
		{
			cout << "Not Found!" << endl;
		}
	}


	return 0;
}

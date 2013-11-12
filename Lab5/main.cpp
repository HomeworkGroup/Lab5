#include <iostream>
#include <fstream>
#include "StudentTestScores.h"
using namespace std;

int main()
{
    //Get the file name
    string file_name;
    ifstream file;

    do
    {
        cout << "Please enter the file name: ";
        cin >> file_name;
        file.open(file_name);
    } while (!file.is_open() && cout << "Invalid file name!\n"); //How does this work?
    
    //Get the number of students
    string line_buf;
    int student_number;

    file >> line_buf;
    student_number = atoi(line_buf.c_str());
    if (student_number <= 0)
    {
        cout << "No student has taken the test.";
        return 1;
    }

    //A loop to process the data
	StudentTestScores student;
	string student_name;
	string buf;
	int test_number;
	double test_score;

    while (student_number--)
	{
		file >> line_buf;
		int i = 0;
		for (; line_buf[i] != '\t'; i++) student_name += line_buf[i];
		for (; line_buf[i] != '\t'; i++) buf += line_buf[i];
		test_number = atoi(buf.c_str());
		while (test_number--)
		{
			for (; line_buf[i] != '\t'; i++) buf += line_buf[i];
			test_score = atof(buf.c_str());
			//This changes test_score every time the loop executes, right? I think we should set up an array test_scores[].
		}

		//Will we pass the variables student_name, test_number, etc., to the student object's parametrized constructor?

		student.displayTestScores();
	}

    return 0;
}
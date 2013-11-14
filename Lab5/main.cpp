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
    } while (!file.is_open() && cout << "Invalid file name!\n");
    
    //Get the number of students
    string line_buf;
    int student_number;

    getline(file, line_buf);
    student_number = atoi(line_buf.c_str());
    if (student_number <= 0)
    {
        cout << "No student has taken the test.";
        return 1;
    }

    //A loop to process the data
    string student_name;
    string buf;
    int test_number;
    double test_score;

    while (student_number--)
    {
        getline(file, line_buf);
        int i = 0;
    
        student_name.clear();
        while (line_buf[i] != '\t' && i < (int) line_buf.length()) student_name += line_buf[i++];
        i++;

        buf.clear();
        while (line_buf[i] != '\t' && i < (int) line_buf.length()) buf += line_buf[i++];
        i++;
        test_number = atoi(buf.c_str());
        if (test_number < 0)
        {
            cout << "Invalid test number!\n";
            continue;
        }
    
        StudentTestScores * student = new StudentTestScores(student_name, test_number);
    
		int n = 0;
        while (test_number--)
        {
            buf.clear();
            while (line_buf[i] != '\t' && i < (int) line_buf.length()) buf += line_buf[i++];
            i++;
            test_score = atof(buf.c_str());
        
            student->setOneTestScore(n, test_score);

            n++;
        }

        student->displayTestScores();
    
        delete student;
    }

	cin.get(); cin.get();
    return 0;
}
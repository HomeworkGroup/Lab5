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

    getline(file,line_buf);
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
        getline(file,line_buf);
        int i = 0;
    
        for (; line_buf[i] != '\t'; i++) student_name += line_buf[i];
        student.setName(student_name);
    
        for (; line_buf[i] != '\t'; i++) buf += line_buf[i];
        test_number = atoi(buf.c_str());
        if (test_number < 0)
        {
            cout << "Invalid test number!\n";
            continue;
        }
        student.setTestNumber(test_number);
    
        while (test_number--)
        {
            int n = 0;
            for (; line_buf[i] != '\t'; i++) buf += line_buf[i];
            test_score = atof(buf.c_str());
        
            student.setOneTestScore(n, test_score);
            //This changes test_score every time the loop executes, right? I think we should set up an array test_scores[].
            n++;
        }

        student.displayTestScores();
    }

    return 0;
}
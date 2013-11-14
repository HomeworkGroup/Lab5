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

    //We don't care about the students number
    string line_buf;
    getline(file, line_buf);

    //A loop to process the data
    string student_name;
    string buf;
    int i, n;
    int test_number;
    double test_score;
    StudentTestScores * student;
    while (!file.eof())
    {
        i = 0;
        getline(file, line_buf);

        student_name.clear();
        while (i < (int) line_buf.length() && line_buf[i] != '\t') student_name += line_buf[i++];
        i++;

        buf.clear();
        while (i < (int) line_buf.length() && line_buf[i] != '\t') buf += line_buf[i++];
        i++;
        test_number = atoi(buf.c_str());
        if (test_number < 0)
        {
            cout << "Invalid test number!\n";
            continue;
        }

        student = new StudentTestScores(student_name, test_number);

        n = 0;
        while (test_number--)
        {
            buf.clear();
            while (i < (int) line_buf.length() && line_buf[i] != '\t') buf += line_buf[i++];
            //For invalid test_number
            if (buf == "")
            {
                cout << "Invalid test number!\n";
                delete student;
                student = 0;
                break;
            }
            i++;
            test_score = atof(buf.c_str());

            student->setOneTestScore(n, test_score);
            n++;
        }

        if (student)
        {
            student->displayTestScores();
            delete student;
        }
    }

    cin.get(); cin.get();
    return 0;
}
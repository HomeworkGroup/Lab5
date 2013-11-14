#ifndef STUDENTTESTSCORES_H
#define STUDENTTESTSCORES_H

#include <string>
#include <iostream>

using namespace std;

class StudentTestScores;
ostream& operator<<(ostream& ostr, const StudentTestScores &obj);
istream& operator>>(istream& istr, StudentTestScores &obj);

class StudentTestScores
{
private:
    string studentName;
    int numTestScores;
    double *testScores;
public:
    //New default constructor
    StudentTestScores(); 
    StudentTestScores(string, int);
    StudentTestScores(const StudentTestScores &other);      // class copy constructor
    ~StudentTestScores();  				// class destructor


    void displayTestScores();

    //  *** ADD accessors & mutators HERE

    void setName(string name);
    void setOneTestScore(int index, double score);

    double getAverage();
    string getLetterGrade();
    string getName();
    double getOneTestScore(int index);

    // overload assignment operator HERE
    StudentTestScores operator=(const StudentTestScores& other);

    // *** Stream I/O operations here
    friend ostream& operator<<(ostream& ostr, const StudentTestScores &obj);
    friend istream& operator>>(istream& istr, StudentTestScores &obj);
};

#endif 


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
    double * testScores;
public:
    // class constructor
    StudentTestScores(); 
    StudentTestScores(string, int);
    // class copy constructor
    StudentTestScores(const StudentTestScores &other);
    // class destructor
    ~StudentTestScores();

    // *** ADD a display member function that displays
    void displayTestScores();

    //  *** ADD accessors & mutators HERE
    void setName(string name);
    void setOneTestScore(int index, double score);
    string getName();
    double getOneTestScore(int index);

    double getAverage() const;
    string getLetterGrade() const;

    // overload assignment operator HERE
    StudentTestScores operator=(const StudentTestScores& other);

    // *** Stream I/O operations here
    friend ostream& operator<<(ostream& ostr, const StudentTestScores &obj);
    friend istream& operator>>(istream& istr, StudentTestScores &obj);
};

#endif 


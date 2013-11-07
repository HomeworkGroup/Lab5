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
	double *testScores;
	int numTestScores;
   public:
	StudentTestScores(string name="", int numScores=0);	// class constructor	
	StudentTestScores(const StudentTestScores &other);      // class copy constructor
	~StudentTestScores();  				// class destructor

//  *** ADD a display member function that displays a student's test scores in the 
// following format:
//  student Name <tab> number of test scores <tab> test scores separated by tabs <endl>

	void displayTestScores();							
	
//  *** ADD accessors & mutators HERE

	void setName(string name);
	//void setTestScores(int numScores);
	void setOneTestScore(int index, int score);

	string getName();
	double getOneTestScore(int index);

// overload assignment operator HERE

	StudentTestScores operator=(const StudentTestScores& other);

// *** Stream I/O operations here
	friend ostream& operator<<(ostream& ostr, const StudentTestScores &obj);
	friend istream& operator>>(istream& istr, StudentTestScores &obj);
};

#endif 


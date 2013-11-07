#include <iostream>
#include <string>
#include "StudentTestScores.h"
using namespace std;


StudentTestScores::StudentTestScores(string name, int numScores)
{
	/* while(name=="")
	{
		cout<<"Student name has not been specified. Please enter student name: ";
		getline(cin, name);
	} */

	/* while( numScores == 0)
	{
		cout<<"Number of test scores has not been specified. Please enter number of scores: ";
		cin>>numScores;
	} */
	
	studentName = name;
	numTestScores = numScores;

	if(numScores <= 0)
		testScores = NULL;
	else
	{
		testScores = new double[numTestScores];

		cout<<"Student: "<<studentName<<endl;
		for(int i=0; i<numTestScores; i++)
		{
			cout<<"Enter test score "<<(i+1)<<": ";
			cin>>testScores[i];
		}
	}
}

StudentTestScores::~StudentTestScores()
{
	delete [] testScores;
}

StudentTestScores::StudentTestScores(const StudentTestScores &other)
{
	studentName = other.studentName;
	numTestScores = other.numTestScores;
	testScores = new double[numTestScores];
	for(int i=0; i<numTestScores; i++)
		testScores[i] = other.testScores[i];
}

void StudentTestScores::displayTestScores()
{
	cout<<studentName<<'\t';
	cout<<numTestScores;
	for(int i=0; i<numTestScores; i++)
		cout<<'\t'<<testScores[i];
	cout<<endl;
}

void StudentTestScores::setName(string name)
{
	studentName = name;
}

//void StudentTestScores::setTestScores(int numScores)
//{
//	numTestScores = numScores;
//	testScores = new double[numTestScores];
//
//	cout<<"Student: "<<studentName<<endl;
//
//	for(int i=0; i<numTestScores; i++)
//	{
//		cout<<"Enter test score "<<(i+1)<<": ";
//		cin>>testScores[i];
//	}
//}

void StudentTestScores::setOneTestScore(int index, int score)
{
	testScores[index] = score;
}

string StudentTestScores::getName()
{
	return studentName;
}

double StudentTestScores::getOneTestScore(int index)
{
	return testScores[index];
}

StudentTestScores StudentTestScores::operator=(const StudentTestScores &other)
{
	delete [] testScores;
	studentName = other.studentName;
	numTestScores = other.numTestScores;
	testScores = new double[numTestScores];
	for(int i=0; i<numTestScores; i++)
		testScores[i] = other.testScores[i];

	return other;
}

ostream& operator<<(ostream& ostr, const StudentTestScores& obj)
{
	ostr<<"Student: "<<obj.studentName<<endl;
	ostr<<"Number of scores: "<<obj.numTestScores<<endl;
	
	ostr<<"Here are the scores: "<<endl;
	for(int i=0; i<obj.numTestScores; i++)
	{
		ostr<<(i+1)<<": "<<obj.testScores[i]<<endl;
	}

	return ostr;
}

istream& operator>>(istream& istr, StudentTestScores& obj)
{
	cout<<"Enter student name: ";
	getline(istr, obj.studentName);
	cout<<"Enter number of scores: ";
	istr>>obj.numTestScores;

	obj.testScores = new double[obj.numTestScores];
	for(int i=0; i<obj.numTestScores; i++)
	{
		cout<<"Enter test score "<<(i+1)<<": ";
		istr>>obj.testScores[i];
	}

	return istr;
}
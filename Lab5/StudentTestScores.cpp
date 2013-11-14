#include "StudentTestScores.h"

StudentTestScores::StudentTestScores()
{
    StudentTestScores("", 0);
}

StudentTestScores::StudentTestScores(string name, int numscores)
{
    studentName = name;
    numTestScores = numscores;
    testScores = numscores ? new double[numscores] : 0;

}

StudentTestScores::~StudentTestScores()
{
    delete[] testScores;
}

StudentTestScores::StudentTestScores(const StudentTestScores &other)
{
    studentName = other.studentName;
    numTestScores = other.numTestScores;
    testScores = new double[numTestScores];
    for (int i = 0; i<numTestScores; i++)
        testScores[i] = other.testScores[i];
}

void StudentTestScores::displayTestScores()
{
    cout << studentName << '\t';
    cout << numTestScores;
    for (int i = 0; i<numTestScores; i++)
        cout << '\t' << testScores[i];
    cout << '\t' << getAverage() << '\t';
    cout << getLetterGrade();
    cout << endl;
}

void StudentTestScores::setName(string name)
{
    studentName = name;
}

void StudentTestScores::setOneTestScore(int index, double score)
{
    testScores[index] = score;
}

double StudentTestScores::getAverage()
{
    double sum = 0;

    for (int i = 0; i<numTestScores; i++)
    {
        sum += testScores[i];
    }

    return (sum / numTestScores);
}

string StudentTestScores::getLetterGrade()
{
    if (!testScores)
        return "U";

    double avg = getAverage();

    if (avg >= 90.0)
        return "A";
    else if (avg >= 80.0 && avg<90.0)
        return "B";
    else if (avg >= 70.0 && avg<80.0)
        return "C";
    else if (avg >= 60.0 && avg<70.0)
        return "D";
    else if (avg<60.0)
        return "F";
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
    delete[] testScores;
    studentName = other.studentName;
    numTestScores = other.numTestScores;
    testScores = new double[numTestScores];
    for (int i = 0; i<numTestScores; i++)
        testScores[i] = other.testScores[i];

    return other;
}

ostream& operator<<(ostream& ostr, const StudentTestScores& obj)
{
    StudentTestScores dummy = obj;

    ostr << dummy.studentName << '\t';
    ostr << dummy.numTestScores;
    for (int i = 0; i<dummy.numTestScores; i++)
        ostr << '\t' << dummy.testScores[i];
    ostr << '\t' << dummy.getAverage() << '\t';
    ostr << dummy.getLetterGrade();
    ostr << endl;

    return ostr;
}

istream& operator>>(istream& istr, StudentTestScores& obj)
{
    cout << "Enter student name: ";
    getline(istr, obj.studentName);
    cout << "Enter number of scores: ";
    istr >> obj.numTestScores;

    obj.testScores = new double[obj.numTestScores];
    for (int i = 0; i<obj.numTestScores; i++)
    {
        cout << "Enter test score " << (i + 1) << ": ";
        istr >> obj.testScores[i];
    }

    return istr;
}
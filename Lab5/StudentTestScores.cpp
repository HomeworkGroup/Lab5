#include "StudentTestScores.h"

// class constructor
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

// class destructor
StudentTestScores::~StudentTestScores()
{
    if (testScores)
    {
        delete [] testScores;
    }
}

// class copy constructor
StudentTestScores::StudentTestScores(const StudentTestScores &other)
{
    *this = other;
}

// *** ADD a display member function that displays
void StudentTestScores::displayTestScores()
{
    cout << *this;
}

void StudentTestScores::setName(string name)
{
    studentName = name;
}

void StudentTestScores::setOneTestScore(int i, double score)
{
    if ((testScores) && (i >= 0) && (i < numTestScores))
    {
        testScores[i] = score;
    }
}

string StudentTestScores::getName()
{
    return studentName;
}

double StudentTestScores::getOneTestScore(int i)
{
    if ((testScores) && (i >= 0) && (i < numTestScores))
    {
        return testScores[i];
    }
    else
    {
        return -1;
    }
}

double StudentTestScores::getAverage() const
{
    if (numTestScores)
    {
        double sum = 0;
        for (int i = 0; i < numTestScores; i++)
        {
            sum += testScores[i];
        }
        return sum / numTestScores;
    }
    else
    {
        return -1;
    }
}

string StudentTestScores::getLetterGrade() const
{
    if (!numTestScores)
    {
        return "U";
    }
    else
    {
        if ((getAverage() >= 90) && (getAverage() <= 100))
        {
            return "A";
        }
        else if ((getAverage() >= 80) && (getAverage() < 90))
        {
            return "B";
        }
        else if ((getAverage() >= 70) && (getAverage() < 80))
        {
            return "C";
        }
        else if ((getAverage() >= 60) && (getAverage() < 70))
        {
            return "D";
        }
        else if ((getAverage() >= 0) && (getAverage() < 60))
        {
            return "F";
        }
        else
        {
            return "X";
        }
    }
}

const StudentTestScores & StudentTestScores::operator = (const StudentTestScores &other)
{
    //a little optimization
    if (this == &other)
    {
        return other;
    }

    studentName = other.studentName;
    numTestScores = other.numTestScores;
    if (testScores)
    {
        delete [] testScores;
    }
    testScores = 0;
    if (other.testScores)
    {
        testScores = new double[other.numTestScores];
        memcpy(testScores, other.testScores, sizeof(double) * other.numTestScores);
    }

    return other;
}

// *** Stream I/O operations here
istream & operator >> (istream & in, StudentTestScores &other)
{
    if (other.testScores)
    {
        delete [] other.testScores;
    }

    in >> other.studentName >> other.numTestScores;
    other.testScores = other.numTestScores ? new double[other.numTestScores] : 0;
    for (int i = 0; i < other.numTestScores; i++)
    {
        in >> other.testScores[i];
    }

    return in;
}

ostream & operator << (ostream & out, const StudentTestScores &other)
{
    out << other.studentName << "\t" << other.numTestScores << "\t";
    for (int i = 0; i < other.numTestScores; i++)
    {
        out << other.testScores[i] << "\t";
    }
    out << other.getAverage() << "\t" << other.getLetterGrade();
    out << endl;

    return out;
}
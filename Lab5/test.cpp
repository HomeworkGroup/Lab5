#include <iostream>
#include "StudentTestScores.h"
using namespace std;

int main()
{
	StudentTestScores x("Jane Doe", 3);
	cout<<endl<<x;

	StudentTestScores y = x;
	cout<<endl<<y;

	cin.get(); cin.get();
	return 0;
}
#include "program.h"
int ShowMember()
{
	ifstream ifs("listOfMember.txt");
	if (ifs.fail())
	{
		cout << "File Open error!" << endl;
		return -1;
	}

	int n=0;
	ifs >> n;
	ifs.ignore(numeric_limits<streamsize>::max(), '\n');

	if (n == 0)
		return -1;

	for (int i = 0; i < 11; i++)
	{
		Member m;
		ifs >> m;
		if(i!=1)
			cout << m;
	}

	return 1;

}
int ShowLecture()
{
	ifstream ifs("listOfLecture.txt");
	if (ifs.fail())
	{
		cout << "File Open error!" << endl;
		return -1;
	}

	int n = 0;
	ifs >> n;
	ifs.ignore(numeric_limits<streamsize>::max(), '\n');

	if (n == 0)
		return -1;
	for (int i = 0; i < 10; i++)
	{
		Lecture m;
		ifs >> m;
		cout << m;
	}
	return 1;
}
int ShowPurchase()
{
	ifstream ifs("listOfPurchase.txt");
	if (ifs.fail())
	{
		cout << "File Open error!" << endl;
		return -1;
	}

	int n = 0;
	ifs >> n;
	ifs.ignore(numeric_limits<streamsize>::max(), '\n');

	if (n == 0)
		return -1;
	for (int i = 0; i < 10; i++)
	{
		Purchase m;
		ifs >> m;
		cout << m;
	}

	return 1;
}
#include "Lecture.h"
#include "recfile.h"
#include <fstream>
#include <vector>

using namespace std;

int main()
{
	int n;
	ifstream ifs("listOfLecture.txt");
	if (ifs.fail())
	{
		cout << "File Open error!" << endl;
		return -1;
	}

	ifs.seekg(0, ios::beg);
	ifs >> n;
	ifs.ignore(numeric_limits<streamsize>::max(), '\n');


	DelimFieldBuffer buffer('|', 256);
	RecordFile <Lecture> StudentFile(buffer);

	// Write test
	StudentFile.Create("fileOfLecture.dat", ios::out | ios::trunc);
	for (int i = 0; i < n; i++) {
		Lecture s;
		ifs >> s;
		int recaddr;
		if ((recaddr = StudentFile.Write(s)) == -1)
			cout << "Write Error!" << endl;
		else
			cout << "Write at " << recaddr << endl;
	}
	StudentFile.Close();


	// Read test
	StudentFile.Open("fileOfLecture.dat", ios::in);
	for (int i = 0; i < 10; i++) {
		Lecture s;
		StudentFile.Read(s);
		cout << s;
	}
	StudentFile.Close();

	return 0;
}
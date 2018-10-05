#include "Member.h"
#include "recfile.h"
#include <fstream>
#include <vector>

using namespace std;

int main()
{
	int n;
	ifstream ifs("listOfMember.txt");
	if (ifs.fail())
	{
		cout << "File Open error!" << endl;
		return -1;
	}

	ifs.seekg(0, ios::beg);
	ifs >> n;
	ifs.ignore(numeric_limits<streamsize>::max(), '\n');


	DelimFieldBuffer buffer('|', 256);
	RecordFile <Member> StudentFile(buffer);

	// Write test
	StudentFile.Create("fileOfMember.dat", ios::out | ios::trunc);
	for (int i = 0; i < n; i++) {
		Member s;
		ifs >> s;
		int recaddr;
		if ((recaddr = StudentFile.Write(s)) == -1)
			cout << "Write Error!" << endl;
		else
			cout << "Write at " << recaddr << endl;
	}
	StudentFile.Close();


	// Read test
	StudentFile.Open("fileOfMember.dat", ios::in);
	for (int i = 0; i < 10; i++) {
		Member s;
		StudentFile.Read(s);
		cout << s;
	}
	StudentFile.Close();

	return 0;
}
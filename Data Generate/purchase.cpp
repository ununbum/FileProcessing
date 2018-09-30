#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>


int main()
{
	FILE* member = fopen("member.txt", "r");
	FILE* lecture = fopen("lecture.txt", "r");
	FILE* fp = fopen("listOfPurchase.txt", "w");
	char data1[1000][300];
	char data2[1000][300];
	char list[200];
	int i;
	int purchaseID;
	int member_ind;
	int lecture_ind;
	int mileage;
	for (i = 0; i < 1000; i++)
	{
		fgets(data1[i], 300, member);
		data1[i][strlen(data1[i]) - 1] = '\0';
		fgets(data2[i], 300, lecture);
		data2[i][strlen(data2[i]) - 1] = '\0';
	}

	srand(time(NULL));
	for (i = 0; i < 10000; i++)
	{
		purchaseID = rand();
		mileage = rand() % 10;
		member_ind = rand() % 1000;
		lecture_ind = rand() % 1000;
		sprintf(list, "%06d%010d|%s|%s|%07d000\n", i, purchaseID, data1[member_ind], data2[lecture_ind], mileage);
		fwrite(list, strlen(list), 1, fp);
	}
	
	fclose(fp);
	fclose(member);
	fclose(lecture);
}
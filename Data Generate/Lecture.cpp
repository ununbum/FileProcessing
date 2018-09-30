#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

char teacher[10][20] = { {"Alarak"},{"Artanis"},{"Zeratul"},{"Deathwing"},{"Maiev"},{"Ana Amari"},{"Medivh"},{"Ragnaros"},{"Genji Shimada"},{"Hanzo Shimada"} };
char Subject[10][30] = { {"Algorithm"},{"Data Structure"},{ "C Programing" },{ "Graphics" },{ "DatBase" },{ "File Structure" },{ "Embeded Software Programming" },{ "Gososil" },{ "Computer Architechure" },{ "Assembly Language" } };
char textbook[10][30] = { {"Double A"},{ "Milk" },{"None escape their shadow." },{ "I AM DEATHWING" },{ "THE DESTROYER" },{ "THE END OF ALL THINGS" },{ " INEVITABLE" },{ "INDOMITABLE" },{ "I AM THE CATACLYSM!" },{ "My life for Aiur." } };
char level[4][2] = { {"A"},{"B"},{"C"},{"D"} };
char extension[2][2] = { {"Y"},{"N"} };

int main()
{
	int i;
	int subject_ind;
	int teacher_ind;
	int textbook_ind;
	long long LectureID;
	int level_ind;
	int price;
	int Extension;
	int Due;
	char list[300];
	char full_name[20];
	char ID[20];
	FILE *fp = fopen("listOfLecture.txt", "w");
	FILE *fp2 = fopen("lecture.txt", "w");
	for (i = 0; i < 300; i++)
		list[i] = '\0';

	srand(time(NULL));
	for (i = 0; i < 1000; i++)
	{
		subject_ind = rand() % 10;
		teacher_ind = rand() % 10;
		textbook_ind = rand() % 10;
		LectureID = rand();
		level_ind = rand() % 4;
		price = (rand() % 100);
		Extension = rand() % 2;
		Due = 30 * (rand() % 3 + 1);
		sprintf(ID, "%04d%08d\n",i,LectureID);
		sprintf(list,"%04d%08lld|%s|%s|%d0,000|%s|%d|%s|%s\n",i,LectureID, Subject[subject_ind],level[level_ind],price,extension[Extension],Due,teacher[teacher_ind],textbook[textbook_ind]);
		fwrite(list, strlen(list), 1, fp);
		fwrite(ID, strlen(ID),1,fp2);
	}
	fclose(fp);
}
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>


char family_name[7][5] = { {"Kim"},{"Lee"},{"Park"},{"Choi"},{"Son"},{"Lim"},{"Ha"} };
char name[18][7] = {{"Seung"},{"Kyung"},{"Jun"},{"Sang"},{"Chang"},{"Woo"},{"Hyeun"},{"Jeung"},{"Soo"},{"Young"},{"Chai"},{"June"},{"Jeung"},{"Dae"},{"Seung"},{"Ki"},{"Kwang"},{"Han"}};
char last_name[18][6] = { {"Hyeun"},{"Gu"},{ "ik" },{ "Hyun" },{ "Ho" },{ "Min" },{ "Jin" },{ "Soo" },{ "Yeon" },{ "Young" },{ "June" },{ "Moo" },{ "Yeob" },{"Geun"},{ "Moon" },{ "Chul" },{ "Hee" },{"Gill"}};
char Address[7][20] = { {"Seoul"},{ "Gwang Ju" },{ "Dae Jeaun" },{ "Lebanon" },{ "Dae Gu" },{ "Pusan" },{ "SiGong" } };


int main()
{
	int i;
	int family_ind;
	int name_ind;
	int last_name_ind;
	int Address_ind;
	int mileage;
	int phone_middle;
	int phone_last;
	char list[200];
	char full_name[20];
	char ID[20];
	FILE *fp = fopen("listOfMember.txt","w");
	FILE *fp2 = fopen("member.txt", "w");

	for (i = 0; i < 200; i++)
		list[i] = '\0';

	srand(time(NULL));
	for (i = 0; i < 1000; i++)
	{
		family_ind = rand() % 7;
		name_ind = rand() % 18;
		last_name_ind = rand() % 18;
		Address_ind = rand() % 7;
		mileage = rand() % 10000000000;
		phone_middle = rand() % 10000;
		phone_last = rand() % 10000;
		sprintf(full_name, "%s %s %s\0", family_name[family_ind], name[name_ind], last_name[last_name_ind]);
		sprintf(ID, "%c%c%c%d\n", family_name[family_ind][0], name[name_ind][0], last_name[last_name_ind][0], phone_middle);
		sprintf(list, "%c%c%c%d|%c%c%c%d|%s|010-%04d-%04d|%s|%010d\n", family_name[family_ind][0], name[name_ind][0], last_name[last_name_ind][0], phone_middle, family_name[family_ind][1], name[name_ind][1], last_name[last_name_ind][1], phone_last, full_name, phone_middle, phone_last, Address[Address_ind], mileage);
		fwrite(list,strlen(list),1,fp);
		fwrite(ID, strlen(ID), 1, fp2);
	}



}
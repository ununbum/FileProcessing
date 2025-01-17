#ifndef PROGRAM_H
#define PROGRAM_H
#include "member.h"
#include "Lecture.h"
#include "Purchase.h"
#include "recfile.h"
#include "delim.h"
#include <iostream>
#include <string>
#include <fstream>
#include <queue>

void show(int data);
void make(int data);
void search_data(int data);
void insert(int data);
void delete_data(int data);
void update_data(int data);


int membertest();
int lecturetest();
int purchasetest();


int ShowMember();
int ShowLecture();
int ShowPurchase();


Member SearchMember(const char * MID,int * recaddr);
Lecture SearchLecture(const char * LID, int * recaddr);
Purchase SearchPurchase(const char * PID, int * recaddr);
void SearchPurchase_by_memid(const char * PID, int * recaddr);
void SearchPurchase_by_lecid(const char * LID, int *recaddr);

int InsertMember(Member  m);
int InsertLecture(Lecture  l);
int InsertPurchase(Purchase  p);

int DeleteMember(Member  m, int recaddr,int flag=1);
int DeleteLecture(Lecture  l, int recaddr, int flag = 1);
int DeletePurchase(Purchase  p, int recaddr);
void DeletePurchase_by_memid(Member m);
void DeletePurchase_by_lecid(Lecture m);

int UpdateMember(Member  m,int recaddr);
int UpdateLecture(Lecture  l, int recaddr);
int UpdatePurchase(Purchase  p, int recaddr);


void printMemeber(Member m, int recaddr);
void printLecture(Lecture l,int recaddr);
void printPurchase(Purchase p,int recaddr);

Member  getMember();
Lecture  getLecture();
Purchase  getPurchase();

Member  ModifyMember(Member);
Lecture ModifyLecture(Lecture );
Purchase ModifyPurchase(Purchase );

#endif
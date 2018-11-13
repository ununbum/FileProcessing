#ifndef PROGRAM_H
#define PROGRAM_H
#include "member.h"
#include "Lecture.h"
#include "Purchase.h"
#include "recfile.h"
#include "delim.h"
#include "fixfld.h"
#include "indfile.h"
#include "textind.h"
#include "tindbuff.h"
#include <iostream>
#include <string>
#include <fstream>
#include <queue>

void make_index_member();
void make_index_lecture();
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

/*
Member SearchMember(const char * MID,int * recaddr);
Lecture SearchLecture(const char * LID, int * recaddr);*/
template <class RecType>
RecType Search(TextIndexedFile<Member> StdIdxedFile, const char * MID, int * recaddr);
Purchase SearchPurchase(const char * PID, int * recaddr);
Purchase SearchPurchase_by_memid(const char * PID, int * recaddr);
Purchase SearchPurchase_by_lecid(const char * LID, int *recaddr);

int InsertMember(Member  m);
int InsertLecture(Lecture  l);
int InsertPurchase(Purchase  p);

int DeleteMember(Member  m, int recaddr,int flag=1);
int DeleteLecture(Lecture  l, int recaddr, int flag = 1);
int DeletePurchase(Purchase  p, int recaddr);
void DeletePurchase_by_memid(Member m);
void DeletePurchase_by_lecid(Lecture m);

int UpdateMember(Member  m,int recaddr,int flag);
int UpdateLecture(Lecture  l, int recaddr,int flag);
int UpdatePurchase(Purchase  p, int recaddr,int flag);


void printMemeber(Member m, int recaddr);
void printLecture(Lecture l,int recaddr);
void printPurchase(Purchase p,int recaddr);

Member  getMember();
Lecture  getLecture();
Purchase  getPurchase(int flag);

Member  ModifyMember(Member);
Lecture ModifyLecture(Lecture );
Purchase ModifyPurchase(Purchase ,int);

Member login(int * recaddr);

#endif
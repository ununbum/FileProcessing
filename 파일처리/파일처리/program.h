#ifndef PROGRAM_H
#define PROGRAM_H
#include "Member.h"
#include "Lecture.h"
#include "Purchase.h"
#include "recfile.h"
#include <iostream>
#include <fstream>
#include <vector>


int membertest();
int lecturetest();
int purchasetest();


int ShowMember();
int ShowLecture();
int ShowPurchase();


Member& SearchMember(const char * MID,int * recaddr);
Lecture& SearchLecture(const char * LID, int * recaddr);
Purchase& SearchPurchase(const char * PID, int * recaddr);


int InsertMember(Member  m);
int InsertLecture(Lecture  l);
int InsertPurchase(Purchase  p);

int DeleteMember(const char * MID);
int DeleteLecture(const char * LID);
int DeletePurchase(const char * PID);

int UpdateMember(Member  m,int recaddr);
int UpdateLecture(Lecture  l, int recaddr);
int UpdatePurchase(Purchase  p, int recaddr);

#endif
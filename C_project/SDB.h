#ifndef SDB_H
#define SDB_H

#include<stdlib.h>

#include "STD.h"

typedef struct {
	uint32 Student_ID;
	uint32 Student_year;
	
	uint32 Course1_ID;
	uint32 Course1_grade;
	
	uint32 Course2_ID;
	uint32 Course2_grade;
	
	uint32 Course3_ID;
	uint32 Course3_grade;
} Student;

typedef struct {
	uint8 size;
	uint8 counter;
	Student **studPtrs;
} Db;

Student* createStudent();
Db* createStudentsDataBase(uint8);
bool SDB_isFull(Db*);
bool SDB_isEmpty(Db*);
uint8 SDB_GetUsedSize(Db*);
bool SDB_AddEntry(Db*);
void SDB_DeletEntry(Db*, uint32);
bool SDB_ReadEntry(Db*, uint32);
void SDB_GetList(Db*);
bool SDB_isIdExist(Db*, uint32);
void SDB_destroy(Db*);

#endif

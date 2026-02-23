#include<stdio.h>

#include "SDB.h"

Student* createStudent() {
 	Student* student = (Student*)malloc(sizeof(Student));
 	if (!student) return NULL;
 	
 	printf("Enter student's id: ");
 	if (scanf("%d", &student->Student_ID) != 1) return NULL;
 	
 	printf("Enter student's year: ");
 	if (scanf("%d", &student->Student_year) != 1) return NULL;
 	
 	printf("Enter student's Course 1 id: ");
 	if (scanf("%d", &student->Course1_ID) != 1) return NULL;
 	
 	printf("Enter student's Course 1 grade: ");
 	if (scanf("%d", &student->Course1_grade) != 1) return NULL;
 	
 	printf("Enter student's Course 2 id: ");
 	if (scanf("%d", &student->Course2_ID) != 1) return NULL;
 	
 	printf("Enter student's Course 2 grade: ");
 	if (scanf("%d", &student->Course2_grade) != 1) return NULL;
 	
 	printf("Enter student's Course 3 id: ");
 	if (scanf("%d", &student->Course3_ID) != 1) return NULL;
 	
 	printf("Enter student's Course 3 grade: ");
 	if (scanf("%d", &student->Course3_grade) != 1) return NULL;
 	
 	return student;
}

Db* createStudentsDataBase(uint8 size) {
	Db* db = (Db*)malloc(sizeof(Db));
	if (!db) {
		printf("Failed to create database\n");
		
		return NULL;
	}
	
	db->size = size;
	db->counter = 0;
  	db->studPtrs = (Student**)malloc(sizeof(Student*) * size);
  	if (!db->studPtrs) {
		printf("Failed to create database\n");
		
		return NULL;
	}
  
	  for (size_t i = 0; i < size; ++i) {
	    db->studPtrs[i] = NULL;
	  }
  
  	return db;
}

bool SDB_isFull(Db *dbPtr) {
	return dbPtr->counter == dbPtr->size ? true : false;
}

bool SDB_isEmpty(Db *dbPtr) {
	return dbPtr->counter == 0 ? true : false;
}

uint8 SDB_GetUsedSize(Db *dbPtr) {
	return dbPtr->counter;
}

bool SDB_AddEntry(Db *dbPtr) {
	if (!SDB_isFull(dbPtr)) {
		for (uint8 i = 0; i < dbPtr->size; ++i) {
			if (!dbPtr->studPtrs[i]) {
				dbPtr->studPtrs[i] = createStudent();
				if(!dbPtr->studPtrs[i]) {
					printf("Failed to create student\n");
					
					return false;
				}
				
				++dbPtr->counter;
				
				return true;
			}
		}
	}
	
	printf("Can't add entry, the data base is full\n");
	return false;
}

void SDB_DeletEntry(Db *dbPtr, uint32 id) {
	if (!SDB_isEmpty(dbPtr)) {
		for (uint8 i = 0; i < dbPtr->size; ++i) {
			if (dbPtr->studPtrs[i] && dbPtr->studPtrs[i]->Student_ID == id) {
				free(dbPtr->studPtrs[i]);
				dbPtr->studPtrs[i] = NULL;
				--dbPtr->counter;
				
				printf("The student with id %d was deleted\n", id);
				
				break;
			}
		}
	} else {
		printf("Can't delete entry, the data base is empty\n");
	}
}
bool SDB_ReadEntry(Db *dbPtr, uint32 id) {
	for (uint8 i = 0; i < dbPtr->size; ++i) {
		if (dbPtr->studPtrs[i] && dbPtr->studPtrs[i]->Student_ID == id) {
			printf("Student's data: \n");
			printf("Id: %d\n", dbPtr->studPtrs[i]->Student_ID);
			printf("Year: %d\n", dbPtr->studPtrs[i]->Student_year);
			
			printf("Course 1 id: %d\n", dbPtr->studPtrs[i]->Course1_ID);
			printf("Course 1 grade: %d\n", dbPtr->studPtrs[i]->Course1_grade);
			
			printf("Course 2 id: %d\n", dbPtr->studPtrs[i]->Course2_ID);
			printf("Course 2 grade: %d\n", dbPtr->studPtrs[i]->Course2_grade);
			
			printf("Course 3 id: %d\n", dbPtr->studPtrs[i]->Course3_ID);
			printf("Course 3 grade: %d\n", dbPtr->studPtrs[i]->Course3_grade);
			
			return true;
		}
	}

	printf("Can't read entry, the id %d doesn't exist in the database\n", id);
	
	return false;
}

void SDB_GetList(Db *dbPtr) {
	if (!SDB_isEmpty(dbPtr)) {
		printf("Students' ids: ");
		for (uint8 i = 0; i < dbPtr->size; ++i) {
			if (dbPtr->studPtrs[i]) {
				printf("%d ", dbPtr->studPtrs[i]->Student_ID);
			}
		}
		printf("\n");
	} else {
		printf("Can't get list, the data base is empty\n");
	}
}
bool SDB_isIdExist(Db *dbPtr, uint32 id) {
	for (uint8 i = 0; i < dbPtr->size; ++i) {
		if (dbPtr->studPtrs[i] && dbPtr->studPtrs[i]->Student_ID == id) return true;
	}
	
	return false;
}

void SDB_destroy(Db* dbPtr) {
	if (!SDB_isEmpty(dbPtr)) {
		for (uint8 i = 0; i < dbPtr->size; ++i) {
			if (dbPtr->studPtrs[i]) {
				free(dbPtr->studPtrs[i]);
				dbPtr->studPtrs[i] = NULL;
			}
		}
	}

	free(dbPtr->studPtrs);
	dbPtr->studPtrs = NULL;
	
	free(dbPtr);
	dbPtr = NULL;

	printf("The database was deleted\n");
}

#include<stdio.h>

#include "SDBAPP.h"

bool SDB_action(Db* db, uint8 action) {
	uint32 student_id;
	switch(action) {
		case 0:
			printf("Terminating the app\n");
			return false;
		case 1:
			SDB_AddEntry(db) ? printf("Entry added successfully\n") : printf("Faild to add entry\n");
			break;
		case 2:
			printf("The used size in the database is: %hhd\n", SDB_GetUsedSize(db));
			break;
		case 3:
			printf("Enter the student's id: ");
			if (scanf("%d", &student_id) == 1) {
				SDB_ReadEntry(db, student_id);
			} else {
				printf("Please enter a valid id\n");
			}
			break;
		case 4:
			SDB_GetList(db);
			break;
		case 5:
			printf("Enter the student's id to search for: ");
			if (scanf("%d", &student_id) == 1) {
				SDB_isIdExist(db, student_id) ? printf("The id %d exists in the database\n", student_id) : printf("The id %d doesn't exist in the database\n", student_id);
			} else {
				printf("Please enter a valid id\n");
			}
			break;
		case 6:
			printf("Enter the student's id to delete: ");
			if (scanf("%d", &student_id) == 1) {
				SDB_DeletEntry(db, student_id);
			} else {
				printf("Please enter a valid id\n");
			}
			break;
		case 7:
			SDB_isFull(db) ? printf("The database is full\n") : printf("The database is not full\n");
			break;
		default:
			printf("Please enter a valid action\n");
		}

	printf("\n");

	return true;
}

void SDB_APP() {
	Db* db = createStudentsDataBase(10);
	if (db) {
		uint8 action;
		
		while (true) {
			printf("To add entry, enter 1\n");
			printf("To get used size in the database, enter 2\n");
			printf("To read student's data, enter 3\n");
			printf("To get the list of all student's IDs, enter 4\n");
			printf("To check if ID exists in the database, enter 5\n");
			printf("To delete a student, enter 6\n");
			printf("To check if database is full, enter 7\n");
			printf("To exit, enter 0\n");

			printf("\n");
			printf("Enter action: ");
			
			if (scanf("%hhd", &action) == 1) {
				if (!SDB_action(db, action)) break;
			}
		}
		
		SDB_destroy(db);
		
		printf("App terminated\n");
		
		return;
	}
	
	printf("Failed to create the database, app terminated\n");
}

// Библиотека телефонного справочника

// описывает структуру одной записи и операции над нею

#pragma once

#define NAME_LENGTH 50
#define PHONE_LENGTH 15

struct Record
{
	char name[NAME_LENGTH];
	int sex;
	int age;
	char phone[PHONE_LENGTH];
	Record* next;
};


void PrintRecord(const Record*);
void PrintFileRecord(FILE*, const Record*);


int ScanFileRecord(FILE*, Record*);
Record* ScanFileRecord(FILE*);
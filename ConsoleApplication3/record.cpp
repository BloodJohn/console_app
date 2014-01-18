#include "stdafx.h"
#include "record.h"

//приватная функция библиотеки
void ReplaceStr(const char* source, char* destination, const char oldChar, const char newChar);

void PrintRecord(const Record *itemPrint)
{
	printf("%s %d %d %s\n", itemPrint->name, itemPrint->age, itemPrint->sex, itemPrint->phone);
}

void PrintFileRecord(FILE* pFile, const Record* itemPrint)
{
	char name[50];
	char phone[15];

	ReplaceStr(itemPrint->name, name, ' ', '_');
	ReplaceStr(itemPrint->phone, phone, ' ', '_');

	fprintf(pFile, "%s %d %d %s\n", name, itemPrint->age, itemPrint->sex, phone);
}

int ScanFileRecord(FILE* pFile, Record* itemScan)
{
	int result = fscanf(pFile, "%s %d %d %s\n", itemScan->name, &itemScan->age, &itemScan->sex, itemScan->phone);

	if (4 == result)
	{
		ReplaceStr(itemScan->name, itemScan->name, '_', ' ');
		ReplaceStr(itemScan->phone, itemScan->phone, '_', ' ');
	}

	return result;
}

Record* ScanFileRecord(FILE* pFile)
{
	Record* result = new Record();
	int scanResult = ScanFileRecord(pFile, result);

	if (ScanFileRecord(pFile, result)) return result;

	delete result;
	return NULL;
}

void ReplaceStr(const char* source, char* destination, const char oldChar, const char newChar)
{
	//копируем символ строки, и смещаем указатели на символ вправо, пока не наткнемся на нулевой символ
	while (0 != *source)
	{
		if (oldChar == *source)
			*destination = newChar;
		else
			*destination = *source;

		source++;
		destination++;
	}

	//заканчиваем копию нулевым байтом
	*destination = 0;
}
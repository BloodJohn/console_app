// Библиотека телефонного справочника
// описывает структуру одной записи
// и операции над нею


struct Record
{
	char name[50];
	int sex;
	int age;
	char phone[15];
	Record* next;
};


void PrintRecord(const Record*);
void PrintFileRecord(FILE*, const Record*);


int ScanFileRecord(FILE*, Record*);
Record* ScanFileRecord(FILE*);
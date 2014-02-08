#include <stdio.h> //работа с потоками
#include <malloc.h> //работа с динамической памятью

#define NAME_LENGTH 50
#define PHONE_LENGTH 15

class Record
{
public:
	char name[NAME_LENGTH];
	int sex;
	int age;
	char phone[PHONE_LENGTH];

	Record() {}
	~Record() { if (NULL != name) free(name); }

	void Print() const;
	void FPrint(FILE* pFile) const;
	int FScan(FILE* pFile);

private:

	void ReplaceStr(const char* source, char* destination, const char oldChar, const char newChar) const;
};
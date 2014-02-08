#include "record.h"

void Record::Print() const
{
	printf("%d %d %s\n", age, sex, name);
}

void Record::FPrint(FILE* pFile) const
{
	char nameNoSpace[NAME_LENGTH], phoneNoSpace[PHONE_LENGTH];

	ReplaceStr(name, nameNoSpace, ' ', '_');
	ReplaceStr(phone, phoneNoSpace, ' ', '_');

	fprintf(pFile, "%s %d %d %s\n", nameNoSpace, age, sex, phoneNoSpace);
}

int Record::FScan(FILE* pFile)
{
	int result = fscanf_s(pFile, "%s %d %d %s\n", name, &age, &sex, phone);

	if (4 == result)
	{
		ReplaceStr(name, name, '_', ' ');
		ReplaceStr(phone, phone, '_', ' ');
	}

	return result;

}

void Record::ReplaceStr(const char* source, char* destination, const char oldChar, const char newChar) const
{
	while (*destination++ = *source++)
	{
		if (oldChar == *source)
		{
			*destination++ = newChar;
			source++;
		}
	}
}
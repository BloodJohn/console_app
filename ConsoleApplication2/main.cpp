// директивы подключения заголовочных файлов
#include "stdio.h" // поиск файла в текущей директории
#include <malloc.h> // поиск файла в системных директориях
#include <string.h>


class Record
{
public:
    char* name;
    int sex;
    int age;

	Record() {}
	~Record() { if (NULL != name) free(name); }

	void Print();
	void FPrint(FILE* pFile);
	int FScan(FILE* pFile);
};

int main ()
{

    Record item;

    item.name = (char*)malloc((strlen("John")+1) * sizeof(char)); 
	if (item.name == NULL) return -1;
    strncpy(item.name, "John", strlen("John")+1);

    item.sex = 1;
    item.age = 33;

    FILE* pFile;
    pFile = fopen ("myfile.txt","a");
    
    if (pFile != NULL)
    {
        item.FPrint(pFile);
        fclose(pFile);
    }

    pFile = fopen ("myfile.txt","r");
    if (pFile != NULL)
    {
        while (item.FScan(pFile) != EOF)
        {
            item.Print();
        }
        fclose(pFile);
    }

    scanf("%s\n");
	
	free(item.name);

    return 0;
}

void Record::Print()
{
	printf ("%d %d %s\n",age, sex, name);
}

void Record::FPrint(FILE* pFile)
{
	fprintf (pFile, "%d %d %s\n",age, sex, name);
}

int Record::FScan(FILE* pFile)
{
	return fscanf (pFile, "%d %d %s\n", age, sex, name);
}

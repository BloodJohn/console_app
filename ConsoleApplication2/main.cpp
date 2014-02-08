// директивы подключения заголовочных файлов
#include <stdio.h> //работа с потоками
#include <string.h> //работа со строками
#include "record.h" // поиск файла в текущей директории


int main()
{

	Record item;

	strcpy_s(item.name, "John Blood");
	strcpy_s(item.phone, "+7(921)1231234");

	item.sex = 1;
	item.age = 33;

	FILE* pFile = fopen("myfile.txt", "a");
	if (pFile != NULL)
	{
		item.FPrint(pFile);
		fclose(pFile);
	}

	pFile = fopen("myfile.txt", "r");
	if (pFile != NULL)
	{
		while (item.FScan(pFile) != EOF)
		{
			item.Print();
		}
		fclose(pFile);
	}

	getchar();

	free(item.name);

	return 0;
}
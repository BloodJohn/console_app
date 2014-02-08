#include "stdafx.h"
#include "record.h"

int main()
{
	Record *headItem = NULL;
	Record *currentItem = NULL;
	Record *newItem;

	FILE* pFile = fopen("myfile.txt", "r");
	if (pFile != NULL)
	{
		while (newItem = ScanFileRecord(pFile))
		{
			if (NULL == currentItem)
			{
				headItem = newItem;
				currentItem = headItem;
			}
			else
			{
				currentItem->next = newItem;
				currentItem = currentItem->next;
			}
		}
		fclose(pFile);

		for (currentItem = headItem; currentItem != NULL; currentItem = currentItem->next)
		{
			PrintRecord(currentItem);
		}
	}

	getchar(); // ждем ввода, чтобы консоль не закрывалась
	return 0;
}


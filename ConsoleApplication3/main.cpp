//директивы подключени€ заголовочных файлов
#include "stdio.h" //поиск файла в текущей директории
#include <malloc.h> //поиск файла в стандартных директори€х
#include <string.h>

//объ€вление структуры
typedef struct
{
    char* name; //указатель, нужно оттдельно выдел€ть пам€ть по указанному адресу
    int sex; //стековый объект
    int age; //стековый объект
} Record;

//объ€вление прототипов функций
void PrintRecord(Record&); //декларирование типов параметров
void FPrintRecord(FILE*, Record&);
int FScanRecord(FILE*, Record&);

void main () //основна€ функци€, котора€ вызываетс€ при выполнении программы
{
    //объ€вление переменной
    Record item;

    //выделение пам€ти дл€ указател€ под массив символов
    item.name = (char*)malloc(strlen("John") * sizeof(char));
    
    //копирование байтов в выделенный участок пам€ти
    strcpy(item.name, "John");

    //инициализаци€ полей структуры
    item.sex = 1;
    item.age = 33;

    FILE* pFile; //объ€вление переменной, указател€ на файл
    pFile = fopen ("myfile.txt","a+"); //открытие файла в режиме записи
    FPrintRecord(pFile, item); //вызов функции печати в файл
    fclose(pFile); //закрытие файла

    pFile = fopen ("myfile.txt","r");
    while (FScanRecord(pFile, item) != EOF) //чтение из файла, пока читаетс€
        PrintRecord(item); //выводим каждую запись на консоль
    fclose(pFile);

    scanf("%s", item.name); //ждем ввода, чтобы консоль не закрывалась

    free(item.name);//освобождаем пам€ть
}

//определение реализации функции
void PrintRecord(Record& item)
{
    //выводим данные на консоль
    printf ("%d %d %s\n",item.age, item.sex, item.name);
}

void FPrintRecord(FILE* pFile, Record& item)
{
    //пишем данные в файл (сериализаци€ объекта)
    fprintf (pFile, "%d %d %s\n",item.age, item.sex, item.name);
}

int FScanRecord(FILE* pFile, Record& item)
{
    //читаем данные из файла (десериализаци€ объекта)
    return fscanf (pFile, "%d %d %s\n", &item.age, &item.sex, item.name);
}
//��������� ����������� ������������ ������
#include "stdio.h" //����� ����� � ������� ����������
#include <malloc.h> //����� ����� � ����������� �����������
#include <string.h>

//���������� ���������
typedef struct
{
    char* name; //���������, ����� ��������� �������� ������ �� ���������� ������
    int sex; //�������� ������
    int age; //�������� ������
} Record;

//���������� ���������� �������
void PrintRecord(Record&); //�������������� ����� ����������
void FPrintRecord(FILE*, Record&);
int FScanRecord(FILE*, Record&);

void main () //�������� �������, ������� ���������� ��� ���������� ���������
{
    //���������� ����������
    Record item;

    //��������� ������ ��� ��������� ��� ������ ��������
    item.name = (char*)malloc(strlen("John") * sizeof(char));
    
    //����������� ������ � ���������� ������� ������
    strcpy(item.name, "John");

    //������������� ����� ���������
    item.sex = 1;
    item.age = 33;

    FILE* pFile; //���������� ����������, ��������� �� ����
    pFile = fopen ("myfile.txt","a+"); //�������� ����� � ������ ������
    FPrintRecord(pFile, item); //����� ������� ������ � ����
    fclose(pFile); //�������� �����

    pFile = fopen ("myfile.txt","r");
    while (FScanRecord(pFile, item) != EOF) //������ �� �����, ���� ��������
        PrintRecord(item); //������� ������ ������ �� �������
    fclose(pFile);

    scanf("%s", item.name); //���� �����, ����� ������� �� �����������

    free(item.name);//����������� ������
}

//����������� ���������� �������
void PrintRecord(Record& item)
{
    //������� ������ �� �������
    printf ("%d %d %s\n",item.age, item.sex, item.name);
}

void FPrintRecord(FILE* pFile, Record& item)
{
    //����� ������ � ���� (������������ �������)
    fprintf (pFile, "%d %d %s\n",item.age, item.sex, item.name);
}

int FScanRecord(FILE* pFile, Record& item)
{
    //������ ������ �� ����� (�������������� �������)
    return fscanf (pFile, "%d %d %s\n", &item.age, &item.sex, item.name);
}
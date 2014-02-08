//Односвязный список (Single linked list)

//Список операций для управления списком

#pragma once

#include "record.h"

Record* GetNext(Record* current);

Record* InsertIntoList(Record* previous, Record* newItem);

Record* AppendHeadList(Record* head, Record* newItem);

Record* CutFromList(Record* previous);

Record* CuteHeadFromList(Record* head);

Record* Swap(Record* prevLeft, Record* prevRight);

Record* SwapHead(Record* head, Record* prevRight);

Record* SortList(Record* head);
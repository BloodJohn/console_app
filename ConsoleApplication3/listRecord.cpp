#include "stdafx.h"

Record* GetNext(Record* current)
{
	if (NULL == current) return NULL;

	return current->next;
}

Record* InsertIntoList(Record* previous, Record* newItem)
{
	if (NULL == previous) return newItem;
	if (NULL == newItem) return previous;

	Record* oldNext = previous->next;
	previous->next = newItem;
	newItem->next = oldNext;

	return newItem;
}

Record* AppendHeadList(Record* head, Record* newItem)
{
	if (NULL == head) return newItem;
	if (NULL == newItem) return head;

	newItem->next = head;
	return newItem;
}

Record* CutFromList(Record* previous)
{
	if (NULL == previous) return NULL;
	if (NULL == previous->next) return previous;

	Record* removeItem = previous->next;
	Record* newNext = removeItem->next;
}

Record* CuteHeadFromList(Record* head)
{
	if (NULL == head) return NULL;
	Record* newHead = head->next;
	head->next = NULL;

	return newHead;
}

Record* Swap(Record* prevLeft, Record* prevRight);

Record* SwapHead(Record* head, Record* prevRight);
#include "stdafx.h"

int IsLeftLessThanRight(Record* left, Record* right)
{
	if (NULL == left) return 0;
	if (NULL == right) return 0;

	if (left->age < right->age) return 1;
	return 0;
}

Record* FindPrevMinItem(Record* head)
{
	Record* prevMinItem = NULL;
	Record* minItem = head;
	Record* prevCurrentItem = NULL;
	Record* currentItem = head;

	while (currentItem != NULL)
	{
		if (IsLeftLessThanRight(currentItem, minItem))
		{
			minItem = currentItem;
			prevMinItem = prevCurrentItem;
		} 
		prevCurrentItem = currentItem;
		currentItem = currentItem->next;
	}

	return prevMinItem;
}

Record* AppendNextSortItem(Record* tailSortedList, Record* headUnsortedList)
{
	if (NULL == headUnsortedList) return NULL;

	Record* prevMinItem = FindPrevMinItem(headUnsortedList);

	if (NULL == prevMinItem) 
		return headUnsortedList;

	Record* minItem = CutFromList(prevMinItem);

	if (NULL == tailSortedList) 
		return AppendHeadList(headUnsortedList, minItem);

	return InsertIntoList(tailSortedList, minItem);
}


Record* SortList(Record* head)
{
	if (NULL == head) return NULL;

	Record* headSortedList = AppendNextSortItem(NULL, head);
	if (NULL == headSortedList->next) return headSortedList;
	Record* tailSortedList = headSortedList;
	

	while (tailSortedList->next != NULL)
	{
		tailSortedList = AppendNextSortItem(tailSortedList, tailSortedList->next);
	}

	return headSortedList;
}
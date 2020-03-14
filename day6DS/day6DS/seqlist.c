#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <malloc.h>

typedef int SLDataType;
typedef struct SeqList  //顺序表的动态实现
{
	SLDataType* _array;
	size_t _size;
	size_t _capicity;
}SeqList;

void SeqListInit(SeqList* ps, size_t capacity)  //顺序表的初始化
{
	assert(ps);   //查看指针是否为空
	ps->_array = (SLDataType)malloc(sizeof(SLDataType) * capacity);
	ps->_size = 0;
	ps->_capicity = capacity;
}

void SeqListDestory(SeqList* ps)   //顺序表的销毁
{
	assert(ps);
	if (ps->_array)
	{
		free(ps->_array);
		ps->_array = NULL;
		ps->_size = 0;
		ps->_capicity = 0;
	}
}

void CheckCapacity(SeqList* ps)      //容量内存的修改
{
	assert(ps);
	if (ps->_capicity == ps->_size)
	{
		ps->_capicity = ps->_capicity * 2;
		ps->_array = realloc(ps->_array, sizeof(SLDataType) * ps->_capicity);
		assert(ps->_array);
	}
}

void SeqListPushBack(SeqList* ps, SLDataType x)   //顺序表的尾插
{
	assert(ps);
	CheckCapacity(ps);
	ps->_array[ps->_size] = x;
	ps->_size++;
}

void SeqListPopBack(SeqList* ps)      //顺序表的尾删
{
	assert(ps);
	ps->_size--;
}

void SeqListPushFront(SeqList* ps, SLDataType x)    //顺序表的头插
{
	assert(ps);
	CheckCapacity(ps);
	int end = ps->_size;
	while (end > 0)
	{
		ps->_array[end] = ps->_array[end - 1];
		end--;
	}
	ps->_array[0] = x;
	ps->_size++;
}

void SeqListPopFront(SeqList* ps)         //顺序表的头删
{
	assert(ps);
	size_t begin = 0;
	while (begin < ps->_size)
	{
		ps->_array[begin] = ps->_array[begin + 1];
		begin++;
	}
	ps->_size--;
}

int SeqListFind(SeqList* ps, SLDataType x)
{
	assert(ps);
	for (size_t i = 0; i < ps->_size; ++i)
	{
		if (ps->_array[i] == x)
			return i;
	}
	printf("没有找到");
}

void SeqListInsert(SeqList* ps, size_t pos, SLDataType x)
{
	assert(ps);
	CheckCapacity(ps);
	int end = ps->_size;
	if (end > pos)
	{
		ps->_array[end] = ps->_array[end - 1];
		end--;
	}
	ps->_array[pos] = x;
	ps->_size++;
}

void SeqListErase(SeqList* ps, size_t pos)
{
	assert(ps);
	size_t begin = pos;
	while (begin < ps->_size)
	{
		ps->_array[begin] = ps->_array[begin + 1];
		begin++;
	}
	ps->_size--;
}

void SeqListRemove(SeqList* ps, SLDataType x)   //移除指定元素
{
	assert(ps);
	size_t cur = 0;
	size_t dst = 0;
	while (cur < ps->_size)
	{
		if (ps->_array[cur] != x)
		{
			ps->_array[dst] = ps->_array[cur];
			dst++;
		}
		cur++;
	}
	ps->_size = dst;
}

void SeqListModify(SeqList* ps, size_t pos, SLDataType x)   //修改指定位置的为x
{
	assert(ps);
	ps->_array[pos] = x;
}

void SeqListPrint(SeqList* ps)
{
	assert(ps);
	for (size_t i = 0; i < ps->_size; ++i)
	{
		printf("%d", ps->_array[i]);
	}
	printf("\t");
}

void SeqListBubbleSort(SeqList* ps)
{

}

int SeqListBinaryFind(SeqList* ps, SLDataType x)
{

}

void SeqListRemoveAll(SeqList* ps,SLDataType x)
{

}

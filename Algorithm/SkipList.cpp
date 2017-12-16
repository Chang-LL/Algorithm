#include "stdafx.h"
#include "SkipList.h"

template<typename T>
SkipList<T>::SkipList(T large, int mLev)
{
	maxLevel = mLev; levels = 0;
	head = new SNode<T>(maxLevel + 1);
	tail = new SNode<T>(0);
	last = new Snode<T>*[maxLevel + 1];
	tail->element.key = large;
	for (int i = 0; i <= maxLevel; i++)
		head->link[i] = tail;
}

template<typename T>
SkipList<T>::~SkipList()
{
}

template<typename T>
ResultCode SkipList<T>::Insert(T x)
{
	if (x >= tail->element)return RangeError;
	SNode<T>*p = SaveSearch(x);
	if (p->element == x)return Duplicate;
	int lev = Level();
	if (lev > levels) {
		lev = ++levels;
		last[lev] = head;
	}
	Snode<T>* y = new Snode<T>(lev + 1);
	y->element = x;
	for (int i = 0; i <= lev; i++)
	{
		y->link[i] = last[i]->link[i];
		last[i]->link[i] = y;
	}
	return Success;
}

template<typename T>
int SkipList<T>::Level()
{
	int lev = 0;
	while (rand() <= RAND_MAX / 2)lev++;
	return(lev <= maxLevel) ? lev : maxLevel;
}

template<typename T>
SNode<T>* SkipList<T>::SaveSearch(T x)
{
	SNode<T>*p = head;
	for (int i = levels; i >= 0; i--)
	{
		whlie(p->link[i]->element < x)p = p->link[i];
		last[i] = p;
	}
	return (p->link[0]);
}

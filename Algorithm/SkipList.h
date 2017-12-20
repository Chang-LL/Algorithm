#pragma once
#include"SPTree.h"
template<typename T>
struct SNode
{
	T element;
	SNode<T>**link;
	SNode(int mSize)
	{
		link = new SNode*[mSize];
	}
	~SNode() { delete[]link; }
};
template<typename T>
class SkipList
{
public:
	SkipList(T large,int mLev);
	~SkipList();
	ResultCode Insert(T x);
private:
	int Level();
	SNode<T>*SaveSearch(T x);
	int maxLevel, levels;
	SNode<T>*head, *tail, **last;
};


#include "stdafx.h"
#include "SPTree.h"




template<class T, class K>
ResultCode SPTree<T, K>::Insert(T x)
{
	return Insert(root, x);
}

template<class T, class K>
ResultCode SPTree<T, K>::Insert(BTNode<T>*& p, T x)
{//жиди==
	ResultCode result = Success;
	BTNode<T>*r;
	if (p == NULL)
	{
		p = new BTNode<T>(x);
		return result;
	}
	if (x == p->element)
	{
		result = Duplicate;
		return result;
	}
	if (x < p->element) {
		r = p->lChild;
		if (r == nullptr)
		{
			r = new BTNode<T>(x);
			r->rChild = p;
			p = r;
			return result;
		}
		else if (x == r->element)
		{
			RRot(p); result = Duplicate;
			return result;
		}
		if (x < r->element)
		{
			result = Insert(r->rChild, x);
			RRot(p);
		}
		else {
			result = Insert(r->rChild, x);
			LRot(r); p->lChild = r;

		}
		RRot(p);
	}
	else
	{
		r = p->rChild;
		if (r == nullptr)
		{
			r = new BTNode<T>(x);
			r->lChild = p;
			p = r;
			return result;
		}
		else if (x == r->element)
		{
			LRot(p);
			result = Duplicate; return result;
		}
		if (x > r->element)
		{
			LRot(p);
		}
		else {
			result = Insert(r->lChild, x);
			RRot(r); p->rChild = r;
		}
		LRot(p);
	}
	return result;
}

template<class T, class K>
void SPTree<T, K>::LRot(BTNode<T>*& p)
{
	BTNode<T>*r = p->rChild;
	p->rChild = r->lChild;
	p->lChild = p;
	p = r;
}

template<class T, class K>
void SPTree<T, K>::RRot(BTNode<T>*& p)
{
	BTNode<T>*r = p->lChild;
	p->lChild = r->rChild;
	r->rChild = p;
	p = r;
}

#pragma once
enum ResultCode{Underflow,Overflow,Success,
	Duplicate,Fail,NotPresent,RangeError};
template<class T>
struct BTNode
{
	T element;
	BTNode* lChild, *rChild;
	BTNode(const T&x)
	{
		element = x;
		lChild = nullptr;
		rChild = nullptr;
	}
};
template<class T,class K>
class SPTree
{
public:
	SPTree() { root = nullptr; };
	ResultCode Insert(T x);
	~SPTree();
protected:
	BTNode<T>*root;
private:
	ResultCode Insert(BTNode<T>* &p, T x);
	void LRot(BTNode<T>*&p);
	void RRot(BTNode<T>*&p);
};


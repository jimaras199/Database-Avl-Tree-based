#pragma once
#include "AVLHashTable.h"
#include "allFactStructure.h"
#include "interfacetxt.h"
#include "AVLHashTable.h"
#include <cstdio>
#include <sstream>
#include <forward_list>

using namespace std;

class AVLTree
{
private:

	class Node
	{
	public:
		size_t			HashV = NULL;
		GeneralFact* Data = nullptr;
		Node* Left = nullptr;
		Node* Right = nullptr;

		Node()
			: HashV(NULL), Data(nullptr), Left(nullptr), Right(nullptr) {}

		//Default Constructor Node
		Node(GeneralFact* NewData, size_t hashv)
			: Data(NewData), Left(nullptr), Right(nullptr), HashV(hashv) {}

		 //w/ string
		Node(GeneralFact* NewData, string line)
			: Data(NewData), Left(nullptr), Right(nullptr)
		{
			HashV = hash< string >{}(line);
		}

		//Constructor Node
		Node(GeneralFact* NewData, Node* LeftPtr, Node* RightPtr, size_t HV)
			: Data(NewData), Left(LeftPtr), Right(RightPtr), HashV(HV)
		{}

		~Node()
		{
			if (Data != nullptr)
			{
				delete Data;
				Data = nullptr;
				HashV = NULL;
				Left = nullptr;
				Right = nullptr;
			}
		}

		//Copy Constructor Node
		Node(Node& other)
		{
			if (this != &other)
			{
				if (this->Left != nullptr && other.Left != nullptr)
					this->Left = &other;
				if (this->Right != nullptr && other.Right != nullptr)
					this->Right = &other;
				this->Data = other.Data;
				this->Left = other.Left;
				this->Right = other.Right;
				this->HashV = other.HashV;
			}
		}


		//Copy operator Node
		Node operator=(Node& other)
		{
			if (this != &other)
			{
				if (this->Left != nullptr && other.Left != nullptr)
					this->Left = &other;
				if (this->Right != nullptr && other.Right != nullptr)
					this->Right = &other;
				this->Data = other.Data;
				this->Left = other.Left;
				this->Right = other.Right;
				this->HashV = other.HashV;
			}
			return *this;
		}

		// Move constructor Node
		Node(Node&& other) noexcept
			: Data(nullptr), Left(nullptr), Right(nullptr), HashV(NULL)
		{
			*this = move(other);
		}

		Node& operator=(Node&& other) noexcept
		{
			if (this != &other)
			{
				if (this->Left != nullptr && other.Left != nullptr)
					this->Left = &other;
				if (this->Right != nullptr && other.Right != nullptr)
					this->Right = &other;
				delete(Left);
				delete(Right);
				delete(Data);
				HashV = NULL;

				this->Data = other.Data;
				this->Left = other.Left;
				this->Right = other.Right;
				this->HashV = other.HashV;

				other.Data = nullptr;
				other.Left = nullptr;
				other.Right = nullptr;
				other.HashV = NULL;
			}
			return *this;
		}
	};

	Node*	Root = nullptr;
	size_t	NumNodes = 0;

	int height(Node* p);
	int difference(Node* p);
	Node* rr_rotat(Node* p);
	Node* ll_rotat(Node* p);
	Node* lr_rotat(Node* p);
	Node* rl_rotat(Node* p);
	Node* balance(Node* p);
	Node* Insert(Node* r, GeneralFact* v,size_t hashv);
	typename AVLTree::Node* Release(Node* r);
	AVLTree::Node* delNode(Node* r, size_t Hash, bool* ptrdup);
	AVLTree::Node* delNode(Node* r, factstar* fs, bool* ptrdup);
	AVLTree::Node* delNode(Node* r, factUnderInspection* fs, bool* ptrdup);
	string show(Node* p);
	void storeToVector(Node* node, vector<string>* ptr);

public:
	AVLTree() noexcept
		: Root(nullptr), NumNodes(0)
	{}	// Default constructor

	AVLTree(Node* node1)
		:Root(node1) {}

	AVLTree(GeneralFact* fact,string line)
		: Root(new Node(fact,line)) {}


	~AVLTree() noexcept
	{
		Root = Release(Root); //delete all function
	}	// Destructor


	// Copy constructor
	AVLTree(const AVLTree& other)
	{
		if (this != &other)
		{
			this->Root = other.Root;
			this->NumNodes = other.NumNodes;
		}
	}

	// Move constructor
	AVLTree(AVLTree&& other)noexcept
		: Root(nullptr), NumNodes(0)
	{
		*this = other;
	}

	// Copy operator
	AVLTree operator=(const AVLTree& other)
	{
		if (this != &other)
		{
			this->Root = other.Root;
			this->NumNodes = other.NumNodes;
		}
		return *this;
	}

	// Move operator
	AVLTree& operator=(AVLTree&& other)noexcept
	{
		if (this != &other)
		{
			Root = nullptr;
			Root = other.Root;
			other.Root = nullptr;
		}
		return *this;
	}

	int height()
	{
		height(this->Root);
	}
	int difference()
	{
		difference(this->Root);
	}
	Node* rr_rotat()
	{
		rr_rotat(this->Root);
	}
	Node* ll_rotat()
	{
		ll_rotat(this->Root);
	}
	Node* lr_rotat()
	{
		lr_rotat(this->Root);
	}
	Node* rl_rotat()
	{
		rl_rotat(this->Root);
	}
	Node* balance()
	{
		balance(this->Root);
	}
	Node* Insert(GeneralFact* v,size_t hashv)
	{
		return Insert(this->Root, v, hashv);
	}
	friend class HashTable;
	friend typename AVLTree::Node* FindMin(AVLTree::Node* root);
	friend void readnodes(Node* n, list<string>* ptr);
	friend void readnodes(Node* n, forward_list<string>* ptr);
	friend void readnodes(Node* n, string* ptr);
	friend void readnodes(AVLTree::Node* n, factstar* ptr, list<string>* ptrL);
	friend void readnodes(AVLTree::Node* n, factUnderInspection* ptr, list<string>* ptrL);
	friend void readnodes(AVLTree::Node* n, factstar* ptr, forward_list<string>* ptrFL);
	friend void readnodes(AVLTree::Node* n, factUnderInspection* ptr, forward_list<string>* ptrFL);
	friend void readnodes(AVLTree::Node* n, factstar* ptr, bool* flag);
	friend void readnodes(AVLTree::Node* n, factUnderInspection* ptr, bool* flag);
	friend void readnodes(AVLTree::Node* n, size_t hashv, bool* flag);
	friend void readnodes(AVLTree::Node* n, size_t hashv, list<string>* ptrL);
	friend void readnodes(AVLTree::Node* n, size_t hashv, forward_list<string>* ptrFL);
	friend string readnodesreturn(AVLTree::Node* n, size_t hashv, bool* flag, string* result);
	friend string readnodesreturn(AVLTree::Node* n, factUnderInspection* ptr, bool* flag, string* result);
	friend string readnodesreturn(AVLTree::Node* n, factstar* ptr, bool* flag, string* result);
};

//====================PRIVATE CODES OF FUNCTIONS

int AVLTree::height(Node* p) {
	int h = 0;
	if (p != NULL)
	{
		int l_height = height(p->Left);
		int r_height = height(p->Right);
		int max_height = max(l_height, r_height);
		h = max_height + 1;
	}
	return h;
}

int AVLTree::difference(Node* p) {
	int l_height = height(p->Left);
	int r_height = height(p->Right);
	int fb = l_height - r_height;
	return fb;
}

typename AVLTree::Node* AVLTree::rr_rotat(Node* p) 
{
	Node* t;
	t = p->Right;
	p->Right = t->Left;
	t->Left = p;
	return t;
}

typename AVLTree::Node* AVLTree::ll_rotat(Node* p) 
{
	Node* t;
	t = p->Left;
	p->Left = t->Right;
	t->Right = p;
	return t;
}

typename AVLTree::Node* AVLTree::lr_rotat(Node* p) 

{
	Node* t;
	t = p->Left;
	p->Left = rr_rotat(t);
	return ll_rotat(p);
}

typename AVLTree::Node* AVLTree::rl_rotat(Node* p) 

{
	Node* t;
	t = p->Right;
	p->Right = ll_rotat(t);
	return rr_rotat(p);
}

typename AVLTree::Node* AVLTree::balance(Node* t) 
{
	if (t != nullptr)
	{
		int bal_factor = difference(t);
		if (bal_factor > 1) {
			if (difference(t->Left) > 0)
				t = ll_rotat(t);
			else
				t = lr_rotat(t);
		}
		else if (bal_factor < -1) {
			if (difference(t->Right) > 0)
				t = rl_rotat(t);
			else
				t = rr_rotat(t);
		}
	}
	return t;
}

typename AVLTree::Node* AVLTree::Insert(Node* r, GeneralFact* v,size_t hashv)
{
	if (r == nullptr)
	{
		r = new Node(v,hashv);
		NumNodes++;
		return r;
	}
	else if (r->HashV < hashv)
	{
		r->Right = Insert(r->Right, v, hashv);
	}
	else
	{
		r->Left = Insert(r->Left, v, hashv);
	}
	return r;
}

typename AVLTree::Node* AVLTree::Release(Node* r)
{
	if (r != nullptr)
	{
		Release(r->Left);
		Release(r->Right);
		delete(r);
		this->NumNodes--;
		r = nullptr;
	}
	return r;
}

typename AVLTree::Node* AVLTree::delNode(Node* r, size_t Hash, bool* ptrdup)
{
	if (r == nullptr) return nullptr;
	if (Hash < r->HashV) r->Left = delNode(r->Left, Hash, ptrdup);
	else if (Hash > r->HashV) r->Right = delNode(r->Right, Hash, ptrdup);
	else if (r->Left == nullptr && r->Right == nullptr)
	{
		*ptrdup = false;
		delete r;
		r = nullptr;
		NumNodes--;
	}
	else if (r->Left == nullptr)
	{
		*ptrdup = false;
		Node* n = r;
		r = r->Right;
		delete n;
		NumNodes--;
	}
	else if (r->Right == nullptr)
	{
		*ptrdup = false;
		Node* n = r;
		r = r->Left;
		delete n;
		NumNodes--;
	}
	else
	{
		*ptrdup = false;
		Node* n = FindMin(r->Right);
		string tmp = makeStringOf(n->Data);
		delete r->Data;
		r->Data = makeInstanceOf(tmp);
		r->HashV = n->HashV;
		r->Right = delNode(r->Right, n->HashV, ptrdup);
	}
	return r;
}

typename AVLTree::Node* AVLTree::delNode(Node* r, factstar* fs, bool* ptrdup)
{
	if (r == nullptr) return r;

	if (r->Left != nullptr && r != nullptr) r->Left = delNode(r->Left, fs, ptrdup);
	if (r->Right != nullptr && r != nullptr) r->Right = delNode(r->Right, fs, ptrdup);
	if (matchfactsstar(r->Data, fs))
	{
		*ptrdup = false;
		if (r->Left == nullptr && r->Right == nullptr)
		{
			delete r;
			r = nullptr;
			NumNodes--;
		}
		else if (r->Left == nullptr)
		{
			Node* n = r;
			r = r->Right;
			delete n;
			NumNodes--;
		}
		else if (r->Right == nullptr)
		{
			Node* n = r;
			r = r->Left;
			delete n;
			NumNodes--;
		}
		else
		{
			Node* n = FindMin(r->Right);
			string tmp = makeStringOf(n->Data);
			delete r->Data;
			r->Data = makeInstanceOf(tmp);
			r->HashV = n->HashV;
			r->Right = delNode(r->Right, n->HashV, ptrdup);
		}
	}return r;
}

typename AVLTree::Node* AVLTree::delNode(Node* r, factUnderInspection* fs, bool* ptrdup)
{
	if (r == nullptr) return r;

	if (r->Left != nullptr && r != nullptr) r->Left = delNode(r->Left, fs, ptrdup);
	if (r->Right != nullptr && r != nullptr) r->Right = delNode(r->Right, fs, ptrdup);
	if (matchfactsSpec(r->Data, fs))
	{
		*ptrdup = false;
		if (r->Left == nullptr && r->Right == nullptr)
		{
			delete r;
			r = nullptr;
			NumNodes--;
		}
		else if (r->Left == nullptr)
		{
			Node* n = r;
			r = r->Right;
			delete n;
			NumNodes--;
		}
		else if (r->Right == nullptr)
		{
			Node* n = r;
			r = r->Left;
			delete n;
			NumNodes--;
		}
		else
		{
			Node* n = FindMin(r->Right);
			string tmp = makeStringOf(n->Data);
			delete r->Data;
			r->Data = makeInstanceOf(tmp);
			r->HashV = n->HashV;
			r->Right = delNode(r->Right, n->HashV, ptrdup);
		}
	}return r;
}

typename AVLTree::Node* FindMin(AVLTree::Node* root)
{
	auto ptr = root;
	while (ptr && ptr->Left != nullptr)
		ptr = ptr->Left;
	return ptr;
}

string AVLTree::show(Node* p)
{
	string ss;
	if (p->Right != nullptr)
		ss += show(p->Right);
	if (p->Left != nullptr)
		ss += show(p->Left);
	return makeStringOf(p->Data) + "\n";
}

void AVLTree::storeToVector(Node* node, vector<string>* ptr)
{
	if (node == nullptr) return;
	if (node->Left != nullptr)
	{
		storeToVector(node->Left, ptr);
	}
	if (node->Right != nullptr)
	{
		storeToVector(node->Right, ptr);
	}
	ptr->push_back(makeStringOf(node->Data));
}
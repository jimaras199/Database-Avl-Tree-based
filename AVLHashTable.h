#pragma once
#include "AVL.h"
#include "interfacetxt.h"
#include <list>
#include <forward_list>

using namespace std;

constexpr auto N = 997;
//constexpr auto N = 1;

class HashTable
{
	std::vector<AVLTree>	Table;
public:

	HashTable()
	{
		Table.reserve(N);
		for (int i = 0; i < N; i++)
			Table.push_back(AVLTree());
	}	

	///	@brief loads data to the memory
	///	@param Line <- fact to be loaded
	void assertz(string Line);

	/// @brief looks for fact
	/// @param Line <- fact to look out
	/// @return true if dound else false
	bool findfact(string Line);

	/// @brief erases data from the memory
	/// @param Line <- 3 cases-examples: 
	/// @param "(*)" <- all data || 
	/// @param "type_def(1,"something",2,*)" <- all the specific type data and matched parameters till "*" || 
	/// @param "type_def(1,"boolean",1,"standard",0,"single_t",0,0,0)" <- all the excact copies.
	void retractall(string Line);

	/// @brief loads file of data to the memory
	/// @param Line <- name(with extension e.x.: .txt) of file to be loaded
	void consult(string Line);

	/// @brief extracts all the loaded data to file(using existing file will override its components)
	/// @param Line <- name(with extension e.x.: .txt) of file to be extracted
	void save(string filename);

	/// @brief combines 2 simple lists into 1 simple list
	/// @param T <- template parameter
	/// @param list1 <- to be considered as the initial of the list
	/// @param list2 <- to be considered as the sequel of the list
	/// @param list3 <- to be considered as the extracted list
	/// @returns list3
	template<typename T>
	list<T> concat(list<T> list1, list<T> list2, list<T> list3);

	/// @brief extracts all the loaded data to string
	list<string> exportToList();

	/// @brief extracts all the loaded data to forward list of strings
	forward_list<string> exportToFList();

	/// @brief extracts all the loaded data to strings separated with coma
	string exportToString();

	/// @brief extracts all the matched data with Line to simple list of strings
	/// @param Line <- fact to be compared
	list<string> matchedToList(string Line); 

	/// @brief extracts all the matched data with Line to forward list of strings
	/// @param Line <- fact to be compared
	forward_list<string> matchedToFList(string Line);
}HT;

void HashTable::assertz(string Line)
{
	string factInput;
	int		Treepos;
	size_t  fullhash;
	fullhash = (hash<string>{}(factInput));
	Treepos = fullhash % N;
	Table[Treepos].Root = Table[Treepos].Insert(Table[Treepos].Root, makeInstanceOf(Line), fullhash);
	Table[Treepos].Root = Table[Treepos].balance(Table[Treepos].Root);
}

bool HashTable::findfact(string Line)
{
	size_t Treepos = 0;
	bool flag = false;
	bool* ptrflg = &flag;

	if (Line.find("*", 0) != Line.npos)
	{
		factstar fs;
		fs = makefactstar(Line);
		factstar* ptrfs = &fs;
		for (int i = N - 1; i >= 0; i--)
		{
			if (Table[i].NumNodes)
			{
				readnodes(Table[i].Root, ptrfs, ptrflg);
				if (flag) return true;
			}
		}
	}
	else
	{
		size_t Hash = (hash<string>{}(Line));
		Treepos = Hash % N;
		if (Table[Treepos].NumNodes)
		{
			readnodes(Table[Treepos].Root, Hash, ptrflg);
			if (flag) return true;
		}
	}
	return false;
}

void HashTable::retractall(string Line)
{
	bool duplicate = false;
	bool* ptrdup = &duplicate;
	size_t Factcount = 0, FactcountTree = 0, Treepos = 0;

	for (int k = 0; k < N; k++)
		FactcountTree += Table[k].NumNodes;

	if (!FactcountTree) 
	{
		return;
	}
	else if (Line == "(*)") 
	{
		for (int i = N - 1; i >= 0; i--)
		{
			if (Table[i].NumNodes)
			{
				Table[i].~AVLTree();
			}
		}
	}
	else if (Line.find("*", 0) != Line.npos)
	{
		factstar fs;
		fs = makefactstar(Line);
		factstar* ptrfs = &fs;
		for (int i = N - 1; i >= 0; i--)
		{
			if (Table[i].NumNodes)
			{
				while (!duplicate)//check for duplicate
				{
					*ptrdup = true;
					Table[i].Root = Table[i].delNode(Table[i].Root, ptrfs, ptrdup);
					Table[i].Root = Table[i].balance(Table[i].Root);
				}
				*ptrdup = false;
			}
		}
	}
	else
	{
		size_t Hash = (hash<string>{}(Line));
		Treepos = Hash % N;
		while (!duplicate)//check for duplicate
		{
			*ptrdup = true;
			Table[Treepos].Root = Table[Treepos].delNode(Table[Treepos].Root, Hash, ptrdup);
			Table[Treepos].Root = Table[Treepos].balance(Table[Treepos].Root);
		}
		*ptrdup = false;
	}
}

void HashTable::consult(string Line)
{
	vector<string>			AllLines;
	string					ALine;
	int						Treepos{};
	size_t					fullhash;
	ifstream File;

	File.open(Line , fstream::in);

	if (File.is_open())
	{
		while (getline(File, ALine))
		{
			AllLines.push_back(ALine);
		}
		File.close();
		AllLines.shrink_to_fit();
		for (int i = 0; i < AllLines.size(); i++)
		{
			fullhash = (hash<string>{}(AllLines[i]));
			Treepos = fullhash % N;
			Table[Treepos].Root = Table[Treepos].Insert(Table[Treepos].Root, makeInstanceOf(AllLines[i]), fullhash);
			Table[Treepos].Root = Table[Treepos].balance(Table[Treepos].Root);
		}
	}
}

void HashTable::save(string filename)
{
	size_t			ts, Factcount = 0;
	vector<string>	AllLines;
	vector<string>* ptr = &AllLines;

	for (int i = 0; i < N; i++)
		Factcount += Table[i].NumNodes;
	if (Factcount)
	{
		fstream     File(filename, ios::out | ios::in | ios::trunc);

		if (!File.is_open())
			return;
		
		for (int i = 0; i < N; i++)
		{
			Table[i].storeToVector(Table[i].Root, ptr);
		}

		sort(AllLines.begin(), AllLines.end());

		ts = AllLines.size();
		for (int i = 0; i < ts; i++)
		{
			File << AllLines[i] << endl;
		}
		File.close();
	}
}

template<typename T>
list<T> HashTable::concat(list<T> list1, list<T> list2, list<T> list3)
{
	if (!list1.empty())
		for (T x : list1)
			list3.push_back(x);
	if (!list2.empty())
		for (T x : list2)
			list3.push_back(x);
	return list3;
}

list<string> HashTable::exportToList()
{
	list<string> result{};

	for (int i = 0; i < N; i++)
	{
		if (Table[i].Root != nullptr)
			readnodes(Table[i].Root, &result);
	}
	return result;
}

forward_list<string> HashTable::exportToFList()
{
	forward_list<string> result{};

	for (int i = 0; i < N; i++)
	{
		if (Table[i].Root != nullptr)
			readnodes(Table[i].Root, &result);
	}
	return result;
}

string HashTable::exportToString()
{
	string result{};

	for (int i = 0; i < N; i++)
	{
		if (Table[i].Root != nullptr)
			readnodes(Table[i].Root, &result);
	}
	return result;
}

list<string> HashTable::matchedToList(string Line)
{
	list<string>	result{};

	factstar fc;
	fc = makefactstar(Line);
	for (int i = 0; i < N; i++)
	{
		if(Table[i].Root != nullptr)
		{
			readnodes(Table[i].Root, &fc, &result);
		}
	}
	return result;
}

forward_list<string> HashTable::matchedToFList(string Line)
{
	forward_list<string>	result{};

	factstar fc;
	fc = makefactstar(Line);
	for (int i = 0; i < N; i++)
	{
		if (Table[i].Root != nullptr)
		{
			readnodes(Table[i].Root, &fc, &result);
		}
	}
	return result;
}

void readnodes(AVLTree::Node* n, list<string>* ptr)
{
	if (n->Left != nullptr)
		readnodes(n->Left, ptr);
	if (n->Right != nullptr)
		readnodes(n->Right, ptr);
	ptr->push_back(makeStringOf(n->Data));
}

void readnodes(AVLTree::Node* n, factstar* ptr, list<string>* ptrL)
{
	if (n->Left != nullptr)
		readnodes(n->Left, ptr, ptrL);
	if (n->Right != nullptr)
		readnodes(n->Right, ptr, ptrL);
	if (matchfactsstar(n->Data, ptr))
		ptrL->push_back(makeStringOf(n->Data));
}

void readnodes(AVLTree::Node* n, factstar* ptr, forward_list<string>* ptrFL)
{
	if (n->Left != nullptr)
		readnodes(n->Left, ptr, ptrFL);
	if (n->Right != nullptr)
		readnodes(n->Right, ptr, ptrFL);
	if (matchfactsstar(n->Data, ptr))
		ptrFL->push_front(makeStringOf(n->Data));
}

void readnodes(AVLTree::Node* n, forward_list<string>* ptr)
{
	if (n->Left != nullptr)
		readnodes(n->Left, ptr);
	if (n->Right != nullptr)
		readnodes(n->Right, ptr);
	ptr->push_front(makeStringOf(n->Data));
}

void readnodes(AVLTree::Node* n, string* ptr)
{
	if (n->Left != nullptr)
		readnodes(n->Left, ptr);
	if (n->Right != nullptr)
		readnodes(n->Right, ptr);
	*ptr += makeStringOf(n->Data);
	*ptr += ",";
}

void readnodes(AVLTree::Node* n, factstar* ptr, bool* flag)
{
	if (matchfactsstar(n->Data, ptr))
		*flag = true;
	if (!(*flag) && n->Left != nullptr)
		readnodes(n->Left, ptr, flag);
	if (!(*flag) && n->Right != nullptr)
		readnodes(n->Right, ptr, flag);
}

void readnodes(AVLTree::Node* n, size_t hashv, bool* flag)
{
	if (n == nullptr) return;
	if (n->HashV == hashv)
	{
		*flag = true;
		return;
	}
	if (n->HashV > hashv && !(*flag))
		readnodes(n->Left, hashv, flag);
	if (n->HashV < hashv && !(*flag))
		readnodes(n->Right, hashv, flag);
}
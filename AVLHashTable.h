#pragma once
#include "AVL.h"
#include "interfacetxt.h"
#include <list>
#include <forward_list>

using namespace std;

constexpr auto N = 997;
//constexpr auto N = 1;

//checks  for factUnderInspection
bool check4spec(string inputline);

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

	/// @brief looks for fact and returns it
	/// @return the parameter in string form
	string findandreturn(string Line);

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
	//template<typename T>
	//list<T> concat(list<T> list1, list<T> list2, list<T> list3);

	/// @brief combines 2 strings into 1 string
	/// @param T <- template parameter
	/// @param list1 <- to be considered as the initial of the string
	/// @param list2 <- to be considered as the sequel of the string
	/// @param list3 <- to be considered as the extracted string
	/// @returns string3
	void concat(string string1, string string2, string string3);

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
	else if (check4spec(Line))
	{
		factUnderInspection fs;
		fs = makeInstanceOfSpecFact(Line);
		factUnderInspection* ptrfs = &fs;
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

string HashTable::findandreturn(string Line)
{
	size_t Treepos = 0;
	bool flag = false;
	bool* ptrflg = &flag;
	string res;

	if (Line.find("*", 0) != Line.npos)
	{
		factstar fs;
		fs = makefactstar(Line);
		factstar* ptrfs = &fs;
		for (int i = N - 1; i >= 0; i--)
		{
			if (Table[i].NumNodes)
			{
				res = readnodesreturn(Table[i].Root, ptrfs, ptrflg);
				if (res != "")
					return res;
			}
		}
		return "";
	}
	else if (check4spec(Line))
	{
		factUnderInspection fs;
		fs = makeInstanceOfSpecFact(Line);
		factUnderInspection* ptrfs = &fs;
		for (int i = N - 1; i >= 0; i--)
		{
			if (Table[i].NumNodes)
			{
				res = readnodesreturn(Table[i].Root, ptrfs, ptrflg);
				if (res != "")
					return res;
			}
		}
		return "";
	}
	else
	{
		size_t Hash = (hash<string>{}(Line));
		Treepos = Hash % N;
		if (Table[Treepos].NumNodes)
		{
			res = readnodesreturn(Table[Treepos].Root, Hash, ptrflg);
			if (res != "")
				return res;
		}
		return "";
	}
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
	else if (check4spec(Line))
	{
		factUnderInspection fs;
		fs = makeInstanceOfSpecFact(Line);
		factUnderInspection* ptrfs = &fs;
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

//template<typename T>
 
//list<T> HashTable::concat(list<T> list1, list<T> list2, list<T> list3)

//{
//	if (!list1.empty())
//		for (T x : list1)
//			list3.push_back(x);
//	if (!list2.empty())
//		for (T x : list2)
//			list3.push_back(x);
//	return list3;
//}

void HashTable::concat(string string1, string string2, string string3)
{
	string3 += string1;
	string3 += string2;
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
	if (Line.find("*", 0) != Line.npos)
	{
		factstar fc;
		fc = makefactstar(Line);
		for (int i = 0; i < N; i++)
		{
			if (Table[i].Root != nullptr)
			{
				readnodes(Table[i].Root, &fc, &result);
			}
		}
	}
	else if (check4spec(Line))
	{
		factUnderInspection fc;
			fc = makeInstanceOfSpecFact(Line);
			for (int i = 0; i < N; i++)
			{
				if (Table[i].Root != nullptr)
				{
					readnodes(Table[i].Root, &fc, &result);
				}
			}

	}
	else
	{
		size_t Treepos;
		size_t Hash = (hash<string>{}(Line));
		Treepos = Hash % N;
		if (Table[Treepos].NumNodes)
		{
			readnodes(Table[Treepos].Root, Hash, &result);
		}
	}
	return result;
}

forward_list<string> HashTable::matchedToFList(string Line)
{
	forward_list<string>	result{};

	if (Line.find("*", 0) != Line.npos)
	{
		factstar fc;
		fc = makefactstar(Line);
		for (int i = 0; i < N; i++)
		{
			if (Table[i].Root != nullptr)
			{
				readnodes(Table[i].Root, &fc, &result);
			}
		}
	}
	else if (check4spec(Line))
	{
		factUnderInspection fc;
		fc = makeInstanceOfSpecFact(Line);
		for (int i = 0; i < N; i++)
		{
			if (Table[i].Root != nullptr)
			{
				readnodes(Table[i].Root, &fc, &result);
			}
		}

	}
	else
	{
		size_t Treepos;
		size_t Hash = (hash<string>{}(Line));
		Treepos = Hash % N;
		if (Table[Treepos].NumNodes)
		{
			readnodes(Table[Treepos].Root, Hash, &result);
		}
	}
	return result;
}

//checks for factUnderInspection
bool check4spec(string inputline)
{
	string ALine, subl;
	size_t pos = 0, brpos = 0;
	ALine = inputline.substr(0, inputline.find(pa, 0));
	pos += ALine.length();
	subl = inputline.substr(++pos, inputline.length() - pos); // ++pos getting after the first  parenthesis
	if (subl.find(co, 0) == subl.npos)
	{
		if (subl.find(br, 0) == 0)
			subl = inputline.substr(++pos, inputline.length() - pos);
		if (subl.find(us, 0) == 0)
			return true;
		else return false;
	}
	do
	{
		if (((subl.find(br, 0)) == 0))
		{
			brpos = subl.find(brcl, 0);
			subl = inputline.substr(++pos, inputline.length() - pos);
			while (subl.find(co, 0) < brpos)
			{
				if ((subl.find(us, 0)) != 0)
				{
					ALine = subl.substr(0, subl.find(co, 0));
					pos += ALine.length();
				}
				else
				{
					return true;
				}
				subl = inputline.substr(++pos, inputline.length() - pos);
				brpos = subl.find(brcl, 0);
			}
			if (subl.find(us, 0) != 0)
			{
				ALine = subl.substr(0, subl.find(brcl, 0));
				pos += ALine.size();
			}
			else
			{
				return true;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);
		}
		else if ((subl.find(us, 0)) != 0)
		{
			ALine = subl.substr(0, subl.find(co, 0));
			pos += ALine.length();
		}
		else
		{
			return true;
		}
		subl = inputline.substr(++pos, inputline.length() - pos);
	} while (subl.find(co, 0) != subl.npos);
	if (subl.find(br, 0) == 0)
		subl = inputline.substr(++pos, inputline.length() - pos);
	if (subl.find(us, 0) == 0)
		return true;
	return false;
}

/// @brief returns a posisioned parameter
/// @param inputline <- fact
/// @param pospar <- the target parameter
/// @return the target parameter otherwise ""
string returnpar(string inputline, int pospar)
{
	string ALine, subl;
	size_t pos = 0, brpos = 0, index = 0;
	ALine = inputline.substr(0, inputline.find(pa, 0));
	pos += ALine.length();
	subl = inputline.substr(++pos, inputline.length() - pos); // ++pos getting after the first  parenthesis
	if (subl.find(co, 0) == subl.npos)
	{
		if (subl.find(br, 0) == 0)
			subl = inputline.substr(++pos, inputline.length() - pos);
			ALine = subl.substr(0, subl.rfind(pacl, 0));
			if(pospar == 1)
				return ALine;
		if (subl.find(us, 0) == 0)
		{
			++pos;
			++index;
		}
	}
	do
	{
		if (((subl.find(br, 0)) == 0))
		{
			brpos = subl.find(brcl, 0);
			subl = inputline.substr(++pos, inputline.length() - pos);
			while (subl.find(co, 0) < brpos)
			{
				++index;
				if ((subl.find(us, 0)) != 0)
				{
					ALine = subl.substr(0, subl.find(co, 0));
					if (pospar == index)
						return ALine;
					pos += ALine.length();
				}
				else
				{
					++pos;
					++index;
				}
				subl = inputline.substr(++pos, inputline.length() - pos);
				brpos = subl.find(brcl, 0);
			}
			if (subl.find(us, 0) != 0)
			{
				++index;
				ALine = subl.substr(0, subl.find(brcl, 0));
				if (pospar == index)
					return ALine;
				pos += ALine.size();
			}
			else
			{
				++pos;
				++index;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);
		}
		else if ((subl.find(us, 0)) != 0)
		{
			++index;
			ALine = subl.substr(0, subl.find(co, 0));
			if (pospar == index)
				return ALine;
			pos += ALine.length();
		}
		else
		{
			++pos;
			++index;
		}
		subl = inputline.substr(++pos, inputline.length() - pos);
	} while (subl.find(co, 0) != subl.npos);
	if (subl.find(br, 0) == 0)
		subl = inputline.substr(++pos, inputline.length() - pos);
		ALine = subl.substr(0, subl.find(brcl, 0));
		if (pospar == index)
			return ALine;
	if (subl.find(us, 0) == 0)
		++pos;
	return "";
}

/// @brief search for a vector from a fact and returns it
/// @param obj target fact
/// @param vec vector place
/// @return vector from a fact
vector<int> returnVec(GeneralFact* obj, size_t vec)
{
	vector<int> res;
	string ALine;
	ALine = typeid(*obj).name();
	ALine = ALine.substr(6);
	string ch = ALine.substr(0, 1);
	const char* sh = ch.c_str();
	switch (*sh)
	{
		case 'c':
		{
			if ("call_stmt" == ALine)
			{
				call_stmt* ptr = dynamic_cast<call_stmt*>(obj);
				res = ptr->r;
			}
			else if ("calls_list" == ALine)
			{
				calls_list* ptr = dynamic_cast<calls_list*>(obj);
				res = ptr->r;
			}
			else if ("cessor_kind" == ALine)
			{
				cessor_kind* ptr = dynamic_cast<cessor_kind*>(obj);
				res = ptr->u;
			}
			else if ("compo_stmt" == ALine)
			{
				compo_stmt* ptr = dynamic_cast<compo_stmt*>(obj);
				res = ptr->r;
			}
			else if ("composites_list" == ALine)
			{
				composites_list* ptr = dynamic_cast<composites_list*>(obj);
				res = ptr->e;
			}
			else if ("conditional_incomplete" == ALine)
			{
				conditional_incomplete* ptr = dynamic_cast<conditional_incomplete*>(obj);
				switch (vec)
				{
					case 1:
					{
						res = ptr->t;
					}
					break;
					case 2:
					{
						res = ptr->y;
					}
					break;
					case 3:
					{
						res = ptr->u;
					}
					break;
					case 4:
					{
						res = ptr->i;
					}
					break;
					case 5:
					{
						res = ptr->o;
					}
					break;
					case 6:
					{
						res = ptr->p;
					}
					break;
				}
			}
			else if ("conditional_operations" == ALine)
			{
				conditional_operations* ptr = dynamic_cast<conditional_operations*>(obj);
				switch (vec)
				{
					case 1:
					{
						res = ptr->t;
					}
					break;
					case 2:
					{
						res = ptr->y;
					}
					break;
					case 3:
					{
						res = ptr->u;
					}
					break;
					case 4:
					{
						res = ptr->i;
					}
					break;
				}
			}
		}
		break;
		case 'd':
		{
			if ("dataflow" == ALine)
			{
				dataflow* ptr = dynamic_cast<dataflow*>(obj);
				res = ptr->q;
			}
		}
		break;
		case 'e':
		{
			if ("end_if" == ALine)
			{
				end_if* ptr = dynamic_cast<end_if*>(obj);
				res = ptr->w;
			}

		}
		break;
		case 'i':
		{
			if ("ifthen" == ALine)
			{
				ifthen* ptr = dynamic_cast<ifthen*>(obj);
				switch (vec)
				{
					case 1:
					{
						res = ptr->q;
					}
					break;
					case 2:
					{
						res = ptr->w;
					}
					break;
					case 3:
					{
						res = ptr->e;
					}
					break;
				}
			}
		}
		break;
		case 'j':
		{
			if ("jump" == ALine)	//losing align after 15 else if 
			{
				jump* ptr = dynamic_cast<jump*>(obj);
				res = ptr->q;
			}
		}
		break;
		case 'l':
		{
			if ("linear_incomplete_node" == ALine)
			{
				linear_incomplete_node* ptr = dynamic_cast<linear_incomplete_node*>(obj);
				switch (vec)
				{
					case 1:
					{
						res = ptr->r;
					}
					break;
					case 2:
					{
						res = ptr->t;
					}
					break;
				}
			}
		}
		break;
		case 'm':
		{
			if ("mixed_incomplete_state_lists" == ALine)
			{
				mixed_incomplete_state_lists* ptr = dynamic_cast<mixed_incomplete_state_lists*>(obj);
				switch (vec)
				{
					case 1:
					{
						res = ptr->r;
					}
					break;
					case 2:
					{
						res = ptr->t;
					}
					break;
				}
			}
		}
		break;
		case 'o':
		{
			if ("op_guards" == ALine)
			{
				op_guards* ptr = dynamic_cast<op_guards*>(obj);
				switch (vec)
				{
					case 1:
					{
						res = ptr->e;
					}
					break;
					case 2:
					{
						res = ptr->r;
					}
					break;
				}
			}
		}
		break;
		case 'p':
		{
			if ("possible_end_if" == ALine)
			{
				possible_end_if* ptr = dynamic_cast<possible_end_if*>(obj);
				res = ptr->w;
			}
			else if ("predecessors" == ALine)
			{
				predecessors* ptr = dynamic_cast<predecessors*>(obj);
				res = ptr->e;
			}
		}
		break;
		case 'r':
		{
			if ("raw_dependencies" == ALine)
			{
				raw_dependencies* ptr = dynamic_cast<raw_dependencies*>(obj);
				switch (vec)
				{
				case 1:
				{
					res = ptr->e;
				}
				break;
				case 2:
				{
					res = ptr->r;
				}
				break;
				}
			}
			else if ("rec_stmt" == ALine)
			{
				rec_stmt* ptr = dynamic_cast<rec_stmt*>(obj);
				res = ptr->e;
			}
			else if ("record_aggregates_list" == ALine)
			{
				record_aggregates_list* ptr = dynamic_cast<record_aggregates_list*>(obj);
				res = ptr->e;
			}
			else if ("reentrant_triangle" == ALine)
			{
				reentrant_triangle* ptr = dynamic_cast<reentrant_triangle*>(obj);
				switch (vec)
				{
				case 1:
				{
					res = ptr->t;
				}
				break;
				case 2:
				{
					res = ptr->y;
				}
				break;
				case 3:
				{
					res = ptr->u;
				}
				break;
				case 4:
				{
					res = ptr->i;
				}
				break;
				case 5:
				{
					res = ptr->o;
				}
				break;
				case 6:
				{
					res = ptr->p;
				}
				break;
				}
			}
			else if ("return_cos" == ALine)
			{
				return_cos* ptr = dynamic_cast<return_cos*>(obj);
				res = ptr->q;
			}
		}
		break;
		case 's':
		{
			if ("state" == ALine)
			{
				state* ptr = dynamic_cast<state*>(obj);
				switch (vec)
				{
				case 1:
				{
					res = ptr->u;
				}
				break;
				case 2:
				{
					res = ptr->i;
				}
				break;
				}
			}
			else if ("subprogram_call" == ALine)
			{
				subprogram_call* ptr = dynamic_cast<subprogram_call*>(obj);
				res = ptr->q;
			}
		}
		break;
		case 'v':
		{
			if ("var_guards" == ALine)
			{
				var_guards* ptr = dynamic_cast<var_guards*>(obj);
				switch (vec)
				{
				case 1:
				{
					res = ptr->e;
				}
				break;
				case 2:
				{
					res = ptr->r;
				}
				break;
				}
			}
		}
		break;
		case 'w':
		{
			if ("war_dependencies" == ALine)
			{
				war_dependencies* ptr = dynamic_cast<war_dependencies*>(obj);
				switch (vec)
				{
				case 1:
				{
					res = ptr->e;
				}
				break;
				case 2:
				{
					res = ptr->r;
				}
				break;
				}
			}
			else if ("waw_dependencies" == ALine)
			{
				waw_dependencies* ptr = dynamic_cast<waw_dependencies*>(obj);
				switch (vec)
				{
				case 1:
				{
					res = ptr->e;
				}
				break;
				case 2:
				{
					res = ptr->r;
				}
				break;
				}
			}
		}
		break;
	}
	return res;
}

/// @brief returns the vector<return_nested_conditional_end> of a nested_cond_fact
/// @param obj <- nested_cond_fact
/// @return nested_cond_fact::w (2nd member)
vector<nested_conditional_end> return_nested_conditional_end(GeneralFact* obj)
{
	vector<nested_conditional_end> res;
	nested_cond_fact* ptr = dynamic_cast<nested_cond_fact*>(obj);
	res = ptr->w;
	return res;
}

string nce_str(vector< nested_conditional_end> v)
{
	string s{};
	s += br;
	for (int i = 0; i < v.size()-1; i++)
	{
		s += v[i].q + co;
		s += v[i].w + co;
		s += v[i].e + co;
	}
	s += v.back().q + co;
	s += v.back().w + co;
	s += v.back().e + brcl;
	return s;
}

// returns the Value of data_stmt
string last_from_lo(string inputline)
{
	string ALine;
	ALine = inputline.substr(inputline.find(pa, 0) + 1, inputline.find(pacl, 0));
	ALine.resize(ALine.size() - 1);
	return ALine;
}

// returns the second parameter of global_declarations
int last_from_global_declarations(GeneralFact* obj)
{
		global_declarations* ptr = dynamic_cast<global_declarations*>(obj);
		return ptr->w;
}

// returns the first parameter of global_declarations
vector<local_object> first_from_global_declarations(GeneralFact* obj)
{
	global_declarations* ptr = dynamic_cast<global_declarations*>(obj);
	return ptr->q;
}


//stores all data to list
void readnodes(AVLTree::Node* n, list<string>* ptr)
{
	if (n->Left != nullptr)
		readnodes(n->Left, ptr);
	if (n->Right != nullptr)
		readnodes(n->Right, ptr);
	ptr->push_back(makeStringOf(n->Data));
}

//stores all data to forward list
void readnodes(AVLTree::Node* n, forward_list<string>* ptr)
{
	if (n->Left != nullptr)
		readnodes(n->Left, ptr);
	if (n->Right != nullptr)
		readnodes(n->Right, ptr);
	ptr->push_front(makeStringOf(n->Data));
}

//stores all data to string separated with coma
void readnodes(AVLTree::Node* n, string* ptr)
{
	if (n->Left != nullptr)
		readnodes(n->Left, ptr);
	if (n->Right != nullptr)
		readnodes(n->Right, ptr);
	*ptr += makeStringOf(n->Data);
	*ptr += ",";
}

//stores matched data(factstar) to list
void readnodes(AVLTree::Node* n, factstar* ptr, list<string>* ptrL)
{
	if (n->Left != nullptr)
		readnodes(n->Left, ptr, ptrL);
	if (n->Right != nullptr)
		readnodes(n->Right, ptr, ptrL);
	if (matchfactsstar(n->Data, ptr))
		ptrL->push_back(makeStringOf(n->Data));
}

//stores matched data(factUnderInspection) to list
void readnodes(AVLTree::Node* n, factUnderInspection* ptr, list<string>* ptrL)
{
	if (n->Left != nullptr)
		readnodes(n->Left, ptr, ptrL);
	if (n->Right != nullptr)
		readnodes(n->Right, ptr, ptrL);
	if (matchfactsSpec(n->Data, ptr))
		ptrL->push_back(makeStringOf(n->Data));
}

//stores matched data(factstar) to forward list
void readnodes(AVLTree::Node* n, factstar* ptr, forward_list<string>* ptrFL)
{
	if (n->Left != nullptr)
		readnodes(n->Left, ptr, ptrFL);
	if (n->Right != nullptr)
		readnodes(n->Right, ptr, ptrFL);
	if (matchfactsstar(n->Data, ptr))
		ptrFL->push_front(makeStringOf(n->Data));
}

//stores matched data(factUnderInspection) to forward list
void readnodes(AVLTree::Node* n, factUnderInspection* ptr, forward_list<string>* ptrFL)
{
	if (n->Left != nullptr)
		readnodes(n->Left, ptr, ptrFL);
	if (n->Right != nullptr)
		readnodes(n->Right, ptr, ptrFL);
	if (matchfactsSpec(n->Data, ptr))
		ptrFL->push_front(makeStringOf(n->Data));
}

//stores matched data(GeneralFact) to list
void readnodes(AVLTree::Node* n, size_t hashv, list<string>* ptrL)
{
	if (n->Left != nullptr)
		readnodes(n->Left, hashv, ptrL);
	if (n->Right != nullptr)
		readnodes(n->Right, hashv, ptrL);
	if (n->HashV == hashv)
		ptrL->push_back(makeStringOf(n->Data));
}

//stores matched data(GeneralFact) to forward list
void readnodes(AVLTree::Node* n, size_t hashv, forward_list<string>* ptrFL)
{
	if (n->Left != nullptr)
		readnodes(n->Left, hashv, ptrFL);
	if (n->Right != nullptr)
		readnodes(n->Right, hashv, ptrFL);
	if (n->HashV == hashv)
		ptrFL->push_front(makeStringOf(n->Data));
}

//checks for data using factstar
void readnodes(AVLTree::Node* n, factstar* ptr, bool* flag)
{
	if (matchfactsstar(n->Data, ptr))
		*flag = true;
	if (!(*flag) && n->Left != nullptr)
		readnodes(n->Left, ptr, flag);
	if (!(*flag) && n->Right != nullptr)
		readnodes(n->Right, ptr, flag);
}

//checks for data using factUnderInspection
void readnodes(AVLTree::Node* n, factUnderInspection* ptr, bool* flag)
{
	if (matchfactsSpec(n->Data, ptr))
		*flag = true;
	if (!(*flag) && n->Left != nullptr)
		readnodes(n->Left, ptr, flag);
	if (!(*flag) && n->Right != nullptr)
		readnodes(n->Right, ptr, flag);
}

//checks for data using GeneralFact
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

//checks for data using factstar and return the posisioned parameter
string readnodesreturn(AVLTree::Node* n, factstar* ptr, bool* flag)
{
	if (matchfactsstar(n->Data, ptr))
	{
		return makeStringOf(n->Data);
		*flag = true;
	}
	if (!(*flag) && n->Left != nullptr)
		readnodes(n->Left, ptr, flag);
	if (!(*flag) && n->Right != nullptr)
		readnodes(n->Right, ptr, flag);
	return""; 
}

//checks for data using factUnderInspection and return the posisioned parameter
string readnodesreturn(AVLTree::Node* n, factUnderInspection* ptr, bool* flag)
{
	if (matchfactsSpec(n->Data, ptr))
	{
		return makeStringOf(n->Data);
		*flag = true;
	}
	if (!(*flag) && n->Left != nullptr)
		readnodes(n->Left, ptr, flag);
	if (!(*flag) && n->Right != nullptr)
		readnodes(n->Right, ptr, flag);
	return"";
}

//checks for data using GeneralFact and return the posisioned parameter
string readnodesreturn(AVLTree::Node* n, size_t hashv, bool* flag)
{
	if (n->HashV == hashv)
	{
		*flag = true;
		return makeStringOf(n->Data);
	}
	if (n->HashV > hashv && !(*flag))
		readnodes(n->Left, hashv, flag);
	if (n->HashV < hashv && !(*flag))
		readnodes(n->Right, hashv, flag);
	return"";
}
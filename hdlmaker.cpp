#include "AVLHashTable.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream> 
#include <stdio.h>
#include <typeinfo>
#include <functional>
#include <cstdio>
#include <sstream>
#include <forward_list>
#include <iostream>
#include <ctime>
#include <time.h>

using namespace std;

//feedback functions
void itf_not_found_message();
void itf_found_message();
void report_global_constraint();
/////////////////////

bool generate_top(string pathln, string exec, string cmdl);
void assert_global_constraint_conditionally0(string Line = "");
void assert_global_constraint_conditionally1(string Line = "");
void assert_global_constraint_conditionally2(string Line = "");
void assert_global_constraint_conditionally3(string Line = "");
void assert_mp_conditionally(string Line = "");
void assert_hdl_conditionally(string Line = "");
bool check_for_program_name(string path = "", string exename = "");
void extract_loops_from_all_modules(int entry);
void extract_loops(string name, int entry);
void build_loop_cond(string name,int entry);
void add_while_loop(string Module, int If_statement, int Condition_statement, int End_of_loop, int Body_first, int Body_last, int While_loop_entry);
void trace_previous_assign_op(string Module_name, int Condition_statement, int* Assign_stmt);
void add_for_loop(string Module_name, int If_entry, int Condition_statement, int End_of_loop, int Header_start, int Increment_instruction, int Increment_variable, int Start_value, int End_value, int Increment_step, int Body_first, int Body_last, int Iterations, int For_loop_entry);
bool trace_back(string Module, int Previous, int Variable, int* Result);
void calc_target_var(string Module, int Operator, int Left, int Right, int* Result);

//in language add 16 on page search
//ITF_lib "as76das" "asdafgg125hdsg" "hdf12sbshd"
int main(int argc, char* argv[])
{
	//creating command line
	string cmdl{}, pathln{}, exec{}, tmp{};
	for (int i = 1; i < argc; i++)
		cmdl = cmdl + argv[i] + co;
	cmdl.resize(cmdl.length() - 1); //removing last coma.
	///////////////////////
	//creating path and executable name
	tmp = argv[0];
	size_t found = tmp.find_last_of("/\\");
	pathln = tmp.substr(0, found);
	exec = tmp.substr(found + 1);
	///////////////////////
	//cout << cmdl << endl;
	generate_top(pathln,exec,cmdl);
	return 0;
}

//essential functions
bool Iscmdlinearg(string Line) 
{
	if (Line.find(co, 0) != Line.npos) return true;
	return false;
}
void fronttoken(string Line="", string token="", string rest="")
{
	size_t pos = 0;
	token = Line.substr(0, Line.find(co, 0));
	pos = token.length();
	rest = Line.substr(pos, Line.length() - pos);
}
/////////////////////

bool generate_top(string pathln, string exec, string cmdl)
{
	//line 33885
	string Line; //a line from the call in cmd
	ifstream File;

	File.open("TYPESOPSDB.DBA", fstream::in);
	if (!File.is_open())
	{
		itf_not_found_message();
	}
	else
	{
		cout << " HDL maker started, please wait..." << endl;
		HT.assertz("consecutive_106(\"false\")");
		assert_global_constraint_conditionally0(cmdl);
		check_for_program_name(pathln, exec);
		itf_found_message();
		report_global_constraint();
		HT.consult("TYPESOPSDB.DBA");
		if (HT.findfact("hdl_style(\"Hdlform\")"))
		{
			extract_loops_from_all_modules(2);
		}
	}
	return 0;

}

void itf_not_found_message()
{
	fstream File("hdlmaker.log", ios::app);
	stringstream line;
	string str;
	
	line << " hdlmaker CCC compiler run on: " << __DATE__ << endl;
	line << "        ...with errors    at: " << __TIME__ << endl << endl;
	line << " hdlmaker CCC compiler runtime error : " << endl;
	line << "    there is no TYPESOPSDB.DBA file....; run first the front-end CCC compiler SUBADA.EXE" << endl;
	str = line.str();
	File << str;
	File.close();
}
void itf_found_message()
{
	fstream File("hdlmaker.log", ios::app);
	stringstream line;
	string str;
	line << endl;
	line << "------------------------------------------------------------------" << endl;
	line << "  ITF file itf_fact.dba was processed on: " << __DATE__ << endl;
	line << "   hdlmaker compilation started successfully at: " << __TIME__ << endl << endl;
	line << "------------------------------------------------------------------" << endl;
	str = line.str();
	File << str;
	File.close();
}
void report_global_constraint()
{
	if (HT.findfact("global_resource(\"Global_constraint\")"))
	{
		fstream File("hdlmaker.log", ios::app);
		stringstream line;
		string str;
		line << endl;
		line << "  Global constraint from command-line is " << endl;
		line << "            Global_constraint     parallel operations at maximum " << endl;
		line << "------------------------------------------------------------------" << endl << endl;
		str = line.str();
		File << str;
		File.close();
	}
	else return;
}

 //This predicate is used for the assertion of the massively parallel
 //  (mp) FSM generation fact.
 //  use example:
 // assert_mp_conditionally(Massively_parallel)
 // when no command - line options, then massively parallel by default
void assert_mp_conditionally(string Line)
{
	if (Line == "")
		HT.assertz("massively_parallel_style(1)");
	else if (Line == "mp")
		HT.assertz("massively_parallel_style(1)");
}

/* This predicate is used for the assertion of the HDL type */
void assert_hdl_conditionally(string Line)
{
	if (Line == "") HT.assertz("hdl_style(\"vhdl\")");
	else if (Line != "" && Line != "verilog") HT.assertz("hdl_style(\"vhdl\")");
	else if (Line == "vhdl") HT.assertz("hdl_style(\"vhdl\")");
	else if (Line == "verilog") HT.assertz("hdl_style(\"verilog\")");
	else if (Line == "c") HT.assertz("hdl_style(\"c\")");
}

/* (un)Sets the debug_mode(2) especially for the HDLMAKER */
void set_debug(string Line)
{
	if (Line == "debug")
		if (!HT.findfact("debug_mode(2)")) HT.assertz("debug_mode(2)");
}
void reset_debug()
{
	HT.retractall("debug_mode(*)");
}
void set_cac(string Line)
{
	if (!HT.findfact("cac_mode(*)")) HT.assertz("cac_mode(1)");
}
void reset_cac()
{
	HT.retractall("cac_mode(*)");
}

// This is used to assert the HDL type (VHDL, or Verilog)
void assert_global_constraint_conditionally0(string Line)
{
	string Line2 = "", Line3 = "";
	if (Line == "")
	{
		assert_hdl_conditionally("");
		assert_mp_conditionally("");
	}
	else if (Line == "debug")		//line 32835
	{
		set_debug("debug");
		assert_hdl_conditionally("");
		assert_mp_conditionally("");
	}
	else if (Iscmdlinearg(Line))
	{
		fronttoken(Line, Line2, Line3);
		if (Line2 == "")
		{
			assert_hdl_conditionally("");
			assert_mp_conditionally("");
		}
		else if(Line2 == "cac")
		{
			set_cac("cac");
			assert_hdl_conditionally("c");
			HT.assertz("massively_parallel_style(1)");
		}
		else if (Line2 == "debug")
		{
			set_debug("debug");
			if (Line3.empty())
			{
				string HDL1 = "";
				fronttoken(Line3, HDL1, Line3);
				if (HDL1 != "debug")
				{
					assert_hdl_conditionally(HDL1);
					assert_global_constraint_conditionally1(Line3);
				}
				else if (HDL1 == "debug")
				{
					set_debug("debug");
					if (Line3.empty())
					{
						string HDL2 = "";
						fronttoken(Line3, HDL2, Line3);
						if (!HDL2.empty())
						{
							if (!Line3.empty())
							{
								assert_hdl_conditionally(HDL2);
								assert_global_constraint_conditionally1(Line3);
							}
							else
							{
								Line3.clear();
								assert_hdl_conditionally(HDL2);
							}
						}
					}
				}
			}
			else
			{
				assert_hdl_conditionally("");
				assert_mp_conditionally("");
			}
		}
		else if (Line2 != "debug" && Line2 != "cac")
		{
			assert_hdl_conditionally(Line2);
			assert_global_constraint_conditionally1(Line3);
		}
		else if (Line2 == "debug")
		{
			set_debug("debug");
			if (Line3 != "")
			{
				fronttoken(Line3, Line2, Line3);
				if (Line2 != "debug")
				{
					assert_hdl_conditionally(Line2);
					assert_global_constraint_conditionally1(Line3);
				}
			}
		}//line 32878
	}
}

// Now this predicate is used for the assertion of other command-line parameter facts as well
void assert_global_constraint_conditionally1(string Line)
{
	string Line2 = "", Line3 = "";
	if (Line.empty()) assert_mp_conditionally("");
	else
	{
		fronttoken(Line, Line2, Line3);
		if (Line2.empty())
		{
			assert_mp_conditionally(Line2);
			return;
		}
		fronttoken(Line, Line2, Line3);
		assert_mp_conditionally(Line2);
		assert_global_constraint_conditionally2(Line3);
	}
}

//26 / 6 / 2018 this predicate is used for the assertion of syncronous or asynchronous reset style of the generated coprocessors FSMs
void assert_global_constraint_conditionally2(string Line)
{
	string Line2 = "", Line3 = "";
	if (Line.empty())
	{
		HT.assertz("resetstyle(\"syncreset\")");
		return;
	}
	fronttoken(Line, Line2, Line3);
	if (!Line2.empty())
	{
		if (Line3.empty()) HT.assertz("resetstyle(" + Line2 + ")");
		else
		{
			HT.assertz("resetstyle(" + Line2 + ")");
			assert_global_constraint_conditionally3(Line3);
		}
	}
	else HT.assertz("resetstyle(\"syncreset\")");
}

//28/6/2018 this predicate is used for the prevention of hierarchy checking of modules and reliance on the validity of the input code order.
void assert_global_constraint_conditionally3(string Line)
{
	if (Line.empty()) HT.assertz("checkstyle(\"checkhierarchy\")");
	else
	{
		string Line2 = "", Line3 = "";
		fronttoken(Line, Line2, Line3);
		if (Line2 == "checkhierarchy") HT.assertz("checkstyle(\"checkhierarchy\")");
		else HT.assertz("checkstyle(\"dontcheckhierarchy\")");
	}
}

bool check_for_program_name(string pathln, string exec)
{
	fstream File("hdlmaker.log", ios::app);
	stringstream line;
	string str;

	line << "------------------------------------------------------------------" << endl;
	line << " home directory = " + pathln << endl;
	line << " executable name = " + exec << endl;
	line << "------------------------------------------------------------------" << endl;
	str = line.str();
	File << str;
	//terminate_if_not_hdlmaker_exe(ExeName)
	if (exec != "hdlmaker.exe")
	{
		line.clear();
		str.clear();
		line << " incorrect or illegal program name " + exec << endl;
		str = line.str();
		File << str;
		File.close();
		exit(0);
	}
	File.close();

	return true;
}

void extract_loops_from_all_modules(int Entry)
{
	if (!HT.findfact("hierarchy_part(" + to_string(Entry) + ",*)"))
	{
		return;
	}
	else if (HT.findfact("hierarchy_part(" + to_string(Entry) + ",_,_,\"libpart\",_,_,_)"))
	{
		string Module_name;
		int Next_entry;
		HT.assertz("last_for_loop_entry(0)");
		HT.assertz("last_while_loop_entry(0)");
		//string var2 = HT.findandreturn("hierarchy_part(" + to_string(Entry) + ",_,_,\"libpart\",_,_,_)");
		//size_t pos{};
		//string parameter{};
		//var2 = var2.substr(var2.find(co, 0), var2.npos);
		//parameter = var2.substr(0, var2.find(co, 0));
		//pos += parameter.length();
		//var2 = var2.substr(++pos, var2.length() - pos);
		//parameter = var2.substr(0, var2.find(co, 0));
		Module_name = stoi(returnpar(HT.findandreturn("hierarchy_part(" + to_string(Entry) + ",_,_,\"libpart\",_,_,_)"), 2));
		extract_loops(Module_name,1);
		HT.retractall("last_for_loop_entry(*)");
		HT.retractall("last_while_loop_entry(*)");
		Next_entry = Entry + 1;
		extract_loops_from_all_modules(Next_entry);
	}

}

void extract_loops(string name, int Entry)
{
	if (!HT.findfact("prog_stmt(" + name + "," + to_string(Entry) + ",*)"))
	{
		return;
	}
	else
	{
		int Next_entry;
		build_loop_cond(name, Entry);
		Next_entry = Entry + 1;
		extract_loops(name, Next_entry);
	}
}

//Checks if there is a for loop and builds the associated fact
void build_loop_cond(string name, int Entry)
{
	int op, One_after_110, Target_statement, If_entry, Condition, Body_first, Previous_statement, Previous_target, Condition_statement,
		Body_last, End_of_loop, Increment_instruction, Condition_statement1, Inc_op, For_loop_variable, Loop_comparison, Increment_variable,
		End_val_data, Initiation_statement, Init_constant, Initiation_statement_b, Init_constant_b, Increment_step, Up_limit, Low_limit,
		Iterations, Assign_stmt, Start_val_data, Header_start, Condition_operator, Init_variable, Decrement_variable, Decrement_instruction, Decrement_step;
	string Kind;
	if (HT.findfact("prog_stmt(" + name + "," + to_string(Entry) + ",_,_,_,_,_,_)"))
	{
		op = stoi(returnpar(HT.findandreturn("prog_stmt(" + name + "," + to_string(Entry) + ",_,Op,_,_,_,_)"), 4));
		if (op != 110)
			return;
		One_after_110 = stoi(returnpar(HT.findandreturn("prog_stmt(" + name + "," + to_string(Entry) + ",_,110,_,_,_,_)"), 8));
		if (!HT.findfact("prog_stmt(" + name + ",_,_,106,_,_," + to_string(One_after_110) + ",_)"))
			return;
		/* now when the target stmt of the jump is larger than its Entry, (which comes from
		if then else statements in ADA */
		Target_statement = stoi(returnpar(HT.findandreturn("prog_stmt(" + name + "," + to_string(Entry) + ",_,110,_,_,_,_)"), 8));
		if (Target_statement > Entry) //comes from ifthenelse
			return;
		/* now just the case that it is a while loop, without a Condition operation */
		if (HT.findfact("prog_stmt(" + name + "," + to_string(Entry) + ",_,110,_,_,_," + to_string(One_after_110) + ")"))
		{
			If_entry = stoi(returnpar(HT.findandreturn("prog_stmt(" + name + "," + to_string(Entry) + ",_,110,_,_," + to_string(One_after_110) + ",_)"), 7));
			Condition = stoi(returnpar(HT.findandreturn("prog_stmt(" + name + "," + to_string(If_entry) + ",_,106,_,_," + to_string(One_after_110) + ",_)"), 6));
			Body_first = stoi(returnpar(HT.findandreturn("prog_stmt(" + name + "," + to_string(If_entry) + ",_,106,_," + to_string(Condition) + "," + to_string(One_after_110) + ",_)"), 8));
			if (If_entry < Entry)
			{
				Previous_statement = If_entry - 1;
				if (HT.findfact("prog_stmt(" + name + "," + to_string(Previous_statement) + ",_,_,_,_,_,_)"))
				{
					Previous_target = stoi(returnpar(HT.findandreturn("prog_stmt(" + name + "," + to_string(Previous_statement) + ",_,_,_,_,_,_)"), 6));
					/* now just the case that it is a while loop, without a Condition operation */
					if (Previous_target != Condition)
					{
						Condition_statement = If_entry;
						Body_last = Entry - 1;
						End_of_loop = Entry;
						add_while_loop(name, If_entry, Condition_statement, End_of_loop, Body_first, Body_last, 0);
						return;
					}
					/* now just the case that it is a while loop, with a Condition operation */
					else if (Previous_target == Condition)
					{
						Condition_statement = Previous_target;
						Body_last = Entry - 1;
						End_of_loop = Entry;
						add_while_loop(name, If_entry, Condition_statement, End_of_loop, Body_first, Body_last, 0);
						return;
					}
					/* now just the case that it is a while loop, with the 106 being the first operation in the program */
					else if (!HT.findfact("prog_stmt(" + name + "," + to_string(Previous_statement) + ",_,_,_,_,_,_)"))
					{
						Condition_statement = Previous_target;
						Body_last = Entry - 1;
						End_of_loop = Entry;
						add_while_loop(name, If_entry, Condition_statement, End_of_loop, Body_first, Body_last, 0);
						return;
					}
				}
			}
		}
	}
	/* now just the case that it is a while loop, with (maybe) a loop-like condition operation,
    but it is not an increment operation, thus it is a while */
	else if (HT.findfact("prog_stmt(" + name + "," + to_string(Entry) + ",_,110,_,_,_,_)"))
	{
		Condition_statement = stoi(returnpar(HT.findandreturn("prog_stmt(" + name + "," + to_string(Entry) + ",_,110,_,_,_,_)"), 7));
		One_after_110 = stoi(returnpar(HT.findandreturn("prog_stmt(" + name + "," + to_string(Entry) + ",_,110,_,_," + to_string(Condition_statement) + ",_)"), 8));
		if (Condition_statement < Entry)
		{
			if (HT.findfact("prog_stmt(" + name + ",_,_,106,_,_," + to_string(One_after_110) + ",_)"))
			{
				If_entry = stoi(returnpar(HT.findandreturn("prog_stmt(" + name + ",_,_,106,_,_," + to_string(One_after_110) + ",_)"), 2));
				Condition = stoi(returnpar(HT.findandreturn("prog_stmt(" + name + "," + to_string(If_entry) + ",_,106,_,_," + to_string(One_after_110) + ",_)"), 6));
				Body_first = stoi(returnpar(HT.findandreturn("prog_stmt(" + name + "," + to_string(If_entry) + ",_,106,_," + to_string(Condition) + "," + to_string(One_after_110) + ",_)"), 8));
				if (If_entry < Entry)
				{
					if (Condition_statement <= If_entry - 1)
					{
						Increment_instruction = Entry - 1;
						/* now find the pseudo-increment instruction that exists only in for loops */
						if (HT.findfact("prog_stmt(" + name + "," + to_string(Increment_instruction) + ",_,_,_,_,_,_)"))
						{
							Inc_op = stoi(returnpar(HT.findandreturn("prog_stmt(" + name + "," + to_string(Increment_instruction) + ",_,_,_,_,_,_)"), 4));
							Condition_statement1 = stoi(returnpar(HT.findandreturn("prog_stmt(" + name + "," + to_string(Increment_instruction) + ",_," + to_string(Inc_op) + ",_,_,_,_)"), 8));
							if (Inc_op != 104)
							{
								if (Condition_statement1 <= Entry)
								{
									if (Condition_statement1 > If_entry)
									{
										Body_last = Increment_instruction;
										End_of_loop = Entry;
										add_while_loop(name, If_entry, Condition_statement, End_of_loop, Body_first, Body_last, 0);
										return;
									}
								}
							}
						}
						/* now just the case that it is a while loop, without a loop-like condition operation, thus it is a while */
						/* now find the loop variable which forms the condition */
						else if (HT.findfact("prog_stmt(" + name + ",_,_,_,_,_," + to_string(Condition) + "," + to_string(Body_first) + ")"))
						{
							Loop_comparison = stoi(returnpar(HT.findandreturn("prog_stmt(" + name + ",_,_,_,_,_," + to_string(Condition) + "," + to_string(Body_first) + ")"), 2));
							For_loop_variable = stoi(returnpar(HT.findandreturn("prog_stmt(" + name + "," + to_string(Loop_comparison) + ",_,_,_,_," + to_string(Condition) + "," + to_string(Body_first) + ")"), 5));
							if (!HT.findfact("prog_stmt(" + name + "," + to_string(Increment_instruction) + ",_,_,_," + to_string(For_loop_variable) + ",_,_)"))
							{
								Body_last = Increment_instruction;
								End_of_loop = Entry;
								add_while_loop(name, If_entry, Condition_statement, End_of_loop, Body_first, Body_last, 0);
								return;
							}
						}
						/* now just the case that it is a while loop, without a loop-like condition operation, thus it is a while */
						/* now find the loop variable which forms the condition */
						/* now find the pseudo-increment instruction that exists only in for loops */
						else if (HT.findfact("prog_stmt(" + name + ",_,_,_,_,_," + to_string(Condition) + "," + to_string(Body_first) + ")"))
						{
							Loop_comparison = stoi(returnpar(HT.findandreturn("prog_stmt(" + name + ",_,_,_,_,_," + to_string(Condition) + "," + to_string(Body_first) + ")"), 2));
							For_loop_variable = stoi(returnpar(HT.findandreturn("prog_stmt(" + name + "," + to_string(Loop_comparison) + ",_,_,_,_," + to_string(Condition) + "," + to_string(Body_first) + ")"), 6));
							if (!HT.findfact("prog_stmt(" + name + "," + to_string(Increment_instruction) + ",_,_,_," + to_string(For_loop_variable) + ",_,_)"))
							{
								Body_last = Increment_instruction;
								End_of_loop = Entry;
								add_while_loop(name, If_entry, Condition_statement, End_of_loop, Body_first, Body_last, 0);
								return;
							}
						}
					}
					/* now the case of a for loop, with an increment instruction, just before the jump
					and the upper limit of the loop being assigned to a constant*/
					if (HT.findfact("prog_stmt(" + name + "," + to_string(Condition_statement) + ",_,14,_,_,_," + to_string(If_entry) + ")"))
					{
						Increment_variable = stoi(returnpar(HT.findandreturn("prog_stmt(" + name + "," + to_string(Condition_statement) + ",_,14,_,_,_," + to_string(If_entry) + ")"), 5));
						End_val_data = stoi(returnpar(HT.findandreturn("prog_stmt(" + name + "," + to_string(Condition_statement) + ",_,14," + to_string(Increment_variable) + ",_,_," + to_string(If_entry) + ")"), 6));
						Condition = stoi(returnpar(HT.findandreturn("prog_stmt(" + name + "," + to_string(Condition_statement) + ",_,14," + to_string(Increment_variable) + "," + to_string(End_val_data) + ",_," + to_string(If_entry) + ")"), 7));
						Initiation_statement = Condition_statement - 1;
						if (HT.findfact("prog_stmt(" + name + "," + to_string(Initiation_statement) + ",_,102,0,_," + to_string(Increment_variable) + "," + to_string(Condition_statement) + ")"))
						{
							Init_constant = stoi(returnpar(HT.findandreturn("prog_stmt(" + name + "," + to_string(Initiation_statement) + ",_,102,0,_," + to_string(Increment_variable) + "," + to_string(Condition_statement) + ")"), 6));
							Initiation_statement_b = Initiation_statement - 1;
							if (HT.findfact("prog_stmt(" + name + "," + to_string(Initiation_statement_b) + ",_,102,0,_," + to_string(End_val_data) + "," + to_string(Initiation_statement) + ")"))
							{
								Init_constant_b = stoi(returnpar(HT.findandreturn("prog_stmt(" + name + "," + to_string(Initiation_statement_b) + ",_,102,0,_," + to_string(End_val_data) + "," + to_string(Initiation_statement) + ")"), 6));
								//% now find the values of the lowand up limit
								if (HT.findfact("data_stmt(" + name + ",_," + to_string(Init_constant) + ",  _,\"const\",_)"))
								{
									Low_limit = stoi(last_from_data_stmt(returnpar(HT.findandreturn("data_stmt(" + name + ",_," + to_string(Init_constant) + ", _,\"const\",\"i(Low_limit)\")"), 6)));
									if (HT.findfact("data_stmt(" + name + ",_," + to_string(Init_constant_b) + ",  _,\"const\",_)"))
									{
										Up_limit = stoi(last_from_data_stmt(returnpar(HT.findandreturn("data_stmt(" + name + ",_," + to_string(Init_constant) + ", _,\"const\",\"i(Low_limit)\")"), 6)));
										Increment_instruction = Entry - 1;
										if (HT.findfact("prog_stmt(" + name + "," + to_string(Increment_instruction) + ",_,104," + to_string(Increment_variable) + ",_," + to_string(Increment_variable) + "," + to_string(Entry) + ")"))
										{
											Increment_step = stoi(returnpar(HT.findandreturn("prog_stmt(" + name + "," + to_string(Increment_instruction) + ",_,104," + to_string(Increment_variable) + ",_," + to_string(Increment_variable) + "," + to_string(Entry) + ")"), 6));
											Iterations = (Up_limit - Low_limit + 1) / Increment_step;
											trace_previous_assign_op(name, Condition_statement, &Assign_stmt);
											if (HT.findfact("prog_stmt(" + name + "," + to_string(Assign_stmt) + ",_,102,_,_," + to_string(Increment_variable) + ",_)"))
											{
												Start_val_data = stoi(returnpar(HT.findandreturn("prog_stmt(" + name + "," + to_string(Assign_stmt) + ",_,102,_,_," + to_string(Increment_variable) + ",_)"), 6));
												End_of_loop = Entry;
												Header_start = Assign_stmt;
												//% Body_last = Increment_instruction - 1, % this produces wrong results in cccutils
												Body_last = Entry - 1;
												add_for_loop(name, If_entry, Condition_statement, End_of_loop, Header_start,
												Increment_instruction, Increment_variable, Start_val_data, End_val_data,
												Increment_step, Body_first, Body_last, Iterations, 0);
												return;
											}
										}
									}
								}
								/* now the case of a for loop, with an increment instruction, just before the jump
								with the upper limit being hold by a constant */
								else if (HT.findfact("data_stmt(" + name + ",_," + to_string(Init_constant) + ",  _,\"const\",_)"))
								{
									Low_limit = stoi(last_from_data_stmt(returnpar(HT.findandreturn("data_stmt(" + name + ",_," + to_string(Init_constant) + ", _,\"const\",_)"), 6)));
									if (HT.findfact("data_stmt(" + name + ",_," + to_string(End_val_data) + ",  _,\"const\",_)"))
									{
										Up_limit = stoi(last_from_data_stmt(returnpar(HT.findandreturn("data_stmt(" + name + ",_," + to_string(End_val_data) + ", _,\"const\",_)"), 6)));
										Increment_instruction = Entry - 1;
										if (HT.findfact("prog_stmt(" + name + "," + to_string(Increment_instruction) + ",_,104," + to_string(Increment_variable) + ",_," + to_string(Increment_variable) + "," + to_string(Entry) + ")"))
										{
											Increment_step = stoi(returnpar(HT.findandreturn("prog_stmt(" + name + "," + to_string(Increment_instruction) + ",_,104," + to_string(Increment_variable) + ",_," + to_string(Increment_variable) + "," + to_string(Entry) + ")"), 6));
											Iterations = (Up_limit - Low_limit + 1) / Increment_step;
											trace_previous_assign_op(name, Condition_statement, &Assign_stmt);
											if (HT.findfact("prog_stmt(" + name + "," + to_string(Assign_stmt) + ",_,102,_,_," + to_string(Increment_variable) + ",_)"))
											{
												Start_val_data = stoi(returnpar(HT.findandreturn("prog_stmt(" + name + "," + to_string(Assign_stmt) + ",_,102,_,_," + to_string(Increment_variable) + ",_)"), 6));
												End_of_loop = Entry;
												Header_start = Assign_stmt;
												//% Body_last = Increment_instruction - 1, % this produces wrong results in cccutils
												Body_last = Entry - 1;
												add_for_loop(name, If_entry, Condition_statement, End_of_loop, Header_start,
												Increment_instruction, Increment_variable, Start_val_data, End_val_data,
												Increment_step, Body_first, Body_last, Iterations, 0);
												return;
											}
										}
									}
								}
								/* now the case of a for loop, with an increment instruction, just before the jump
								and the upper limit of the loop being calculated and hold on a variable, with previous
								add, minus, etc. operations */
								else if (HT.findfact("data_stmt(" + name + ",_," + to_string(End_val_data) + ",_,\"var\",\"sym(\"node\")\")"))
								{
									if (HT.findfact("data_stmt(" + name + ",_," + to_string(Init_constant) + ",_,\"const\",_)"))
									{
										Low_limit = stoi(last_from_data_stmt(returnpar(HT.findandreturn("data_stmt(" + name + ",_," + to_string(Init_constant) + ",_,\"const\",_)"), 6)));
										if (trace_back(name, Initiation_statement, End_val_data, &Up_limit))
										{
											Increment_instruction = Entry - 1;
											if (HT.findfact("prog_stmt(" + name + "," + to_string(Increment_instruction) + ",_,104," + to_string(Increment_variable) + ",_," + to_string(Increment_variable) + "," + to_string(Entry) + ")"))
											{
												Increment_step = stoi(returnpar(HT.findandreturn("prog_stmt(" + name + "," + to_string(Increment_instruction) + ",_,104," + to_string(Increment_variable) + ",_," + to_string(Increment_variable) + "," + to_string(Entry) + ")"), 6));
												Iterations = (Up_limit - Low_limit + 1) / Increment_step;
												trace_previous_assign_op(name, Condition_statement, &Assign_stmt);
												if (HT.findfact("prog_stmt(" + name + "," + to_string(Assign_stmt) + ",_,102,_,_," + to_string(Increment_variable) + ",_)"))
												{
													Start_val_data = stoi(returnpar(HT.findandreturn("prog_stmt(" + name + "," + to_string(Assign_stmt) + ",_,102,_,_," + to_string(Increment_variable) + ",_)"), 6));
													End_of_loop = Entry;
													Header_start = Assign_stmt;
													Body_last = Entry - 1;
													// 14 or 13 parameters??
													add_for_loop(name, If_entry, Condition_statement, End_of_loop, Header_start,
													Increment_instruction, Increment_variable, Start_val_data, End_val_data,
													Increment_step, Body_first, Body_last, Iterations, 0);
													return;
												}
											}
										}
										else
										{
											Increment_instruction = Entry - 1;
											if (HT.findfact("prog_stmt(" + name + "," + to_string(Increment_instruction) + ",_,104," + to_string(Increment_variable) + ",_," + to_string(Increment_variable) + "," + to_string(Entry) + ")"))
											{
												trace_previous_assign_op(name, Condition_statement, &Assign_stmt);
												if (HT.findfact("prog_stmt(" + name + "," + to_string(Assign_stmt) + ",_,102,_,_," + to_string(Increment_variable) + ",_)"))
												{
													End_of_loop = Entry;
													Header_start = Assign_stmt;
													Body_last = Entry - 1;
													//% now create a pseudo - while loop, since you don't know the upper limit of the for loop
													add_while_loop(name, If_entry, Condition_statement, End_of_loop,Body_first, Body_last, 0);
													return;
												}
											}
										}
									}
								}
							}
							else if (HT.findfact("data_stmt(" + name + ",_," + to_string(Init_constant) + ",  _,\"const\",_)"))
							{
								if (HT.findfact("data_stmt(" + name + ",_," + to_string(End_val_data) + ",  _,_,_)"))
								{
									Kind = stoi(last_from_data_stmt(returnpar(HT.findandreturn("data_stmt(" + name + ",_," + to_string(End_val_data) + ",  _,_,_)"), 5)));
									if (Kind != "const")
									{
										Increment_instruction = Entry - 1;
										if (HT.findfact("prog_stmt(" + name + "," + to_string(Increment_instruction) + ",_,104," + to_string(Increment_variable) + ",_," + to_string(Increment_variable) + "," + to_string(Entry) + ")"))
										{
											trace_previous_assign_op(name, Condition_statement, &Assign_stmt);
											if (HT.findfact("prog_stmt(" + name + "," + to_string(Assign_stmt) + ",_,102,_,_," + to_string(Increment_variable) + ",_)"))
											{
												End_of_loop = Entry;
												Header_start = Assign_stmt;
												Body_last = Entry - 1;
												add_while_loop(name, If_entry, Condition_statement, End_of_loop, Body_first, Body_last, 0);
											}
										}
									}
								}
							}
						}
						/* 14/11/2020: now the case of a for loop, with an increment instruction, just before the jump
						and the lower/upper limits of the loop being calculated and hold by variables, whose
						value cannot be calculated so it is converted into a while loop	*/
						else if (HT.findfact("prog_stmt(" + name + "," + to_string(Initiation_statement) + ",_,102,0,_," + to_string(Increment_variable) + "," + to_string(Condition_statement) + ")"))
						{
							Init_variable = stoi(returnpar(HT.findandreturn("prog_stmt(" + name + "," + to_string(Increment_instruction) + ",_,104," + to_string(Increment_variable) + ",_," + to_string(Increment_variable) + "," + to_string(Entry) + ")"), 6));
							if (HT.findfact("data_stmt(" + name + ",_," + to_string(End_val_data) + ",  _,\"var\",\"sym(\"node\")\")"))
							{
								if (HT.findfact("data_stmt(" + name + ",_," + to_string(Init_variable) + ",  _,\"var\",_)"))
								{
									if (!trace_back(name, Initiation_statement, End_val_data, 0))
									{
										Increment_instruction = Entry - 1;
										if (HT.findfact("prog_stmt(" + name + "," + to_string(Increment_instruction) + ",_,104," + to_string(Increment_variable) + ",_," + to_string(Increment_variable) + "," + to_string(Entry) + ")"))
										{
											trace_previous_assign_op(name, Condition_statement, &Assign_stmt);
											if (HT.findfact("prog_stmt(" + name + "," + to_string(Assign_stmt) + ",_,102,_,_," + to_string(Increment_variable) + ",_)"))
											{
												End_of_loop = Entry;
												Header_start = Assign_stmt;
												Body_last = Entry - 1;
												add_while_loop(name, If_entry, Condition_statement, End_of_loop, Body_first, Body_last, 0);
											}
										}
									}
								}
							}
						}

					}
					/* 12/11/2020: now the case of a for loop, with an increment instruction, just before the jump
					with the upper limit being hold by a constant */
					if (HT.findfact("prog_stmt(" + name + "," + to_string(Condition_statement) + ",_,_,_,_," + to_string(Condition) + "," + to_string(If_entry) + ")"))
					{
						Condition_operator = stoi(returnpar(HT.findandreturn("prog_stmt(" + name + "," + to_string(Condition_statement) + ",_,_,_,_," + to_string(Condition) + "," + to_string(If_entry) + ")"), 4));
						Increment_variable = stoi(returnpar(HT.findandreturn("prog_stmt(" + name + "," + to_string(Condition_statement) + ",_," + to_string(Condition_operator) + ",_,_," + to_string(Condition) + "," + to_string(If_entry) + ")"), 5));
						End_val_data = stoi(returnpar(HT.findandreturn("prog_stmt(" + name + "," + to_string(Condition_statement) + ",_," + to_string(Condition_operator) + "," + to_string(Increment_variable) + ",_," + to_string(Condition) + "," + to_string(If_entry) + ")"), 6));
						if (Condition_operator >= 11 && Condition_operator <= 58)
						{
							Initiation_statement = Condition_statement - 1;
							if (HT.findfact("prog_stmt(" + name + "," + to_string(Initiation_statement) + ",_,102,0,_," + to_string(Increment_variable) + "," + to_string(Condition_statement) + ")"))
							{
								Init_constant = stoi(returnpar(HT.findandreturn("prog_stmt(" + name + "," + to_string(Initiation_statement) + ",_,102,0,_," + to_string(Increment_variable) + "," + to_string(Condition_statement) + ")"), 6));
								//% now find the values of the lowand up limit
								if (HT.findfact("data_stmt(" + name + ",_," + to_string(Init_constant) + ",  _,\"const\",_)"))
								{
									Low_limit = stoi(last_from_data_stmt(returnpar(HT.findandreturn("data_stmt(" + name + ",_," + to_string(Init_constant) + ", _,\"const\",_)"), 6)));
									if (HT.findfact("data_stmt(" + name + ",_," + to_string(End_val_data) + ",  _,\"const\",_)"))
									{
										Up_limit = stoi(last_from_data_stmt(returnpar(HT.findandreturn("data_stmt(" + name + ",_," + to_string(End_val_data) + ", _,\"const\",_)"), 6)));
										Increment_instruction = Entry - 1;
										if (HT.findfact("prog_stmt(" + name + "," + to_string(Increment_instruction) + ",_,104," + to_string(Increment_variable) + ",_," + to_string(Increment_variable) + "," + to_string(Entry) + ")"))
										{
											Increment_step = stoi(returnpar(HT.findandreturn("prog_stmt(" + name + "," + to_string(Increment_instruction) + ",_,104," + to_string(Increment_variable) + ",_," + to_string(Increment_variable) + "," + to_string(Entry) + ")"), 6));
											Iterations = (Up_limit - Low_limit + 1) / Increment_step;
											trace_previous_assign_op(name, Condition_statement, &Assign_stmt);
											if (HT.findfact("prog_stmt(" + name + "," + to_string(Assign_stmt) + ",_,102,_,_," + to_string(Increment_variable) + ",_)"))
											{
												Start_val_data = stoi(returnpar(HT.findandreturn("prog_stmt(" + name + "," + to_string(Assign_stmt) + ",_,102,_,_," + to_string(Increment_variable) + ",_)"), 6));
												End_of_loop = Entry;
												Header_start = Assign_stmt;
												//% Body_last = Increment_instruction - 1, % this produces wrong results in cccutils
												Body_last = Entry - 1;
												add_for_loop(name, If_entry, Condition_statement, End_of_loop, Header_start,
												Increment_instruction, Increment_variable, Start_val_data, End_val_data,
												Increment_step, Body_first, Body_last, Iterations, 0);
												return;
											}
										}
									}
								}
							}
						}
					}
					/* now the case of a for loop, with a decrement instruction, just before the jump
					and the upper limit of the loop being assigned to a constant*/
					else if (HT.findfact("prog_stmt(" + name + "," + to_string(Condition_statement) + ",_,16,_," + to_string(End_val_data) + "," + to_string(Condition) + "," + to_string(If_entry) + ")"))
					{
						Decrement_variable = stoi(returnpar(HT.findandreturn("prog_stmt(" + name + "," + to_string(Condition_statement) + ",_,16,_," + to_string(End_val_data) + "," + to_string(Condition) + "," + to_string(If_entry) + ")"), 5));
						Initiation_statement = Condition_statement - 1;
						if (HT.findfact("prog_stmt(" + name + "," + to_string(Initiation_statement) + ",_,102,0,_," + to_string(Decrement_variable) + "," + to_string(Condition_statement) + ")"))
						{
							Init_variable = stoi(returnpar(HT.findandreturn("prog_stmt(" + name + "," + to_string(Initiation_statement) + ",_,102,0,_," + to_string(Decrement_variable) + "," + to_string(Condition_statement) + ")"), 6));
							if (HT.findfact("data_stmt(" + name + ",_," + to_string(Init_variable) + ", _,\"var\",\"sym(\"node\")\")"))
							{
								if (HT.findfact("data_stmt(" + name + ",_," + to_string(End_val_data) + ",2,\"const\",_)"))
								{
									Low_limit = stoi(last_from_data_stmt(returnpar(HT.findandreturn("data_stmt(" + name + ",_," + to_string(End_val_data) + ",2,\"const\",_)"), 6)));
									if (trace_back(name, Initiation_statement, Init_variable, &Up_limit))
									{
										Decrement_instruction = Entry - 1;
										if (HT.findfact("prog_stmt(" + name + "," + to_string(Decrement_instruction) + ",_,105," + to_string(Decrement_variable) + ",_," + to_string(Decrement_variable) + "," + to_string(Entry) + ")"))
										{
											Decrement_step = stoi(returnpar(HT.findandreturn("prog_stmt(" + name + "," + to_string(Decrement_instruction) + ",_,105," + to_string(Decrement_variable) + ",_," + to_string(Decrement_variable) + "," + to_string(Entry) + ")"), 6));
											Iterations = (Up_limit - Low_limit + 1);
											trace_previous_assign_op(name, Condition_statement, &Assign_stmt);
											if (HT.findfact("prog_stmt(" + name + "," + to_string(Assign_stmt) + ",_,102,_,_," + to_string(Decrement_variable) + ",_)"))
											{
												Start_val_data = stoi(returnpar(HT.findandreturn("prog_stmt(" + name + "," + to_string(Assign_stmt) + ",_,102,_,_," + to_string(Decrement_variable) + ",_)"), 6));
												End_of_loop = Entry;
												Header_start = Assign_stmt;
												Body_last = Entry - 1;
												add_for_loop(name, If_entry, Condition_statement, End_of_loop, Header_start,
												Decrement_instruction, Decrement_variable, Start_val_data, End_val_data,
												Decrement_step, Body_first, Body_last, Iterations, 0);
											}
										}
									}
								}
							}
							Init_constant = stoi(returnpar(HT.findandreturn("prog_stmt(" + name + "," + to_string(Initiation_statement) + ",_,102,0,_," + to_string(Decrement_variable) + "," + to_string(Condition_statement) + ")"), 6));
							Initiation_statement_b = Initiation_statement - 1;
							if (HT.findfact("prog_stmt(" + name + "," + to_string(Initiation_statement_b) + ",_,102,0,_," + to_string(End_val_data) + "," + to_string(Initiation_statement) + ")"))
							{
								Init_constant_b = stoi(returnpar(HT.findandreturn("prog_stmt(" + name + "," + to_string(Initiation_statement_b) + ",_,102,0,_," + to_string(End_val_data) + "," + to_string(Initiation_statement) + ")"), 6));
								if (HT.findfact("data_stmt(" + name + ",_," + to_string(Init_constant) + ",  _,\"const\",_)"))
								{
									Up_limit = stoi(last_from_data_stmt(returnpar(HT.findandreturn("data_stmt(" + name + ",_," + to_string(End_val_data) + ", _,\"const\",_)"), 6)));
									if (HT.findfact("data_stmt(" + name + ",_," + to_string(Init_constant_b) + ",  _,\"const\",_)"))
									{
										Low_limit = stoi(last_from_data_stmt(returnpar(HT.findandreturn("data_stmt(" + name + ",_," + to_string(End_val_data) + ", _,\"const\",_)"), 6)));
										Decrement_instruction = Entry - 1;
										if (HT.findfact("prog_stmt(" + name + "," + to_string(Decrement_instruction) + ",_,105," + to_string(Decrement_variable) + ",_," + to_string(Decrement_variable) + "," + to_string(Entry) + ")"))
										{
											Decrement_step = stoi(returnpar(HT.findandreturn("prog_stmt(" + name + "," + to_string(Decrement_instruction) + ",_,105," + to_string(Decrement_variable) + ",_," + to_string(Decrement_variable) + "," + to_string(Entry) + ")"), 6));
											Iterations = (Up_limit - Low_limit + 1) / Decrement_step;
											trace_previous_assign_op(name, Condition_statement, &Assign_stmt);
											if (HT.findfact("prog_stmt(" + name + "," + to_string(Assign_stmt) + ",_,102,_,_," + to_string(Decrement_variable) + ",_)"))
											{
												Start_val_data = stoi(returnpar(HT.findandreturn("prog_stmt(" + name + "," + to_string(Assign_stmt) + ",_,102,_,_," + to_string(Decrement_variable) + ",_)"), 6));
												End_of_loop = Entry;
												Header_start = Assign_stmt;
												Body_last = Entry - 1;
												// 13 or 14 parameters
												add_for_loop(name, If_entry, Condition_statement, End_of_loop, Header_start,
												Decrement_instruction, Decrement_variable, Start_val_data, End_val_data,
												Decrement_step, Body_first, Body_last, Iterations, 0);
											}
										}
									}
								}
							}
							else if (HT.findfact("data_stmt(" + name + ",_," + to_string(Init_constant) + ",  _,\"const\",_)"))
							{
								Up_limit = stoi(last_from_data_stmt(returnpar(HT.findandreturn("data_stmt(" + name + ",_," + to_string(Init_constant) + ", _,\"const\",_)"), 6)));
								if (HT.findfact("data_stmt(" + name + ",_," + to_string(End_val_data) + ",  _,\"const\",_)"))
								{
									Low_limit = stoi(last_from_data_stmt(returnpar(HT.findandreturn("data_stmt(" + name + ",_," + to_string(End_val_data) + ", _,\"const\",_)"), 6)));
									Decrement_instruction = Entry - 1;
									if (HT.findfact("prog_stmt(" + name + "," + to_string(Decrement_instruction) + ",_,105," + to_string(Decrement_variable) + ",_," + to_string(Decrement_variable) + "," + to_string(Entry) + ")"))
									{
										Decrement_step = stoi(returnpar(HT.findandreturn("prog_stmt(" + name + "," + to_string(Decrement_instruction) + ",_,105," + to_string(Decrement_variable) + ",_," + to_string(Decrement_variable) + "," + to_string(Entry) + ")"), 6));
										Iterations = (Up_limit - Low_limit + 1) / Decrement_step;
										trace_previous_assign_op(name, Condition_statement, &Assign_stmt);
										if (HT.findfact("prog_stmt(" + name + "," + to_string(Assign_stmt) + ",_,102,_,_," + to_string(Decrement_variable) + ",_)"))
										{
											Start_val_data = stoi(returnpar(HT.findandreturn("prog_stmt(" + name + "," + to_string(Assign_stmt) + ",_,102,_,_," + to_string(Decrement_variable) + ",_)"), 6));
											End_of_loop = Entry;
											Header_start = Assign_stmt;
											Body_last = Entry - 1;
											// 13 or 14
											add_for_loop(name, If_entry, Condition_statement, End_of_loop, Header_start,
											Decrement_instruction, Decrement_variable, Start_val_data, End_val_data,
											Decrement_step, Body_first, Body_last, Iterations, 0);
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}

/* Adds a for_loop fact */
void add_while_loop(string Module, int If_statement, int Condition_statement, int End_of_loop, int Body_first, int Body_last, int While_loop_entry)
{
	int Last_while_loop;
	if (HT.findfact("last_while_loop_entry(*)"))
	{
		Last_while_loop = stoi(returnpar(HT.findandreturn("last_while_loop_entry(*)"), 1));
		While_loop_entry = Last_while_loop + 1;
		HT.assertz("while_loop("+to_string(While_loop_entry)+","+ Module+"," + to_string(If_statement)+"," + to_string(Condition_statement)+"," + to_string(End_of_loop)+"," + to_string(Body_first)+"," + to_string(Body_last)+")");
	}
}

void trace_previous_assign_op(string Module_name, int Condition_statement, int* Assign_stmt)
{
	int  Previous_stmt, Previous_op;
	*Assign_stmt = Condition_statement - 1;
	if (HT.findfact("prog_stmt(" + Module_name + "," + to_string(*Assign_stmt) + ",_,102,_,_,_,_)"))
		return;
	Previous_stmt = Condition_statement - 1;
	if (HT.findfact("prog_stmt(" + Module_name + "," + to_string(Previous_stmt) + ",_,_,_,_,_,_)"))
	{
		Previous_op = stoi(returnpar(HT.findandreturn("prog_stmt(" + Module_name + "," + to_string(Previous_stmt) + ",_,_,_,_,_,_)"), 4));
		if (Previous_op != 102 && Previous_stmt >= 1)
			trace_previous_assign_op(Module_name, Previous_stmt, Assign_stmt);
	}
}

void add_for_loop(string Module_name, int If_entry, int Condition_statement, int End_of_loop, int Header_start, int Increment_instruction, int Increment_variable, int Start_value, int End_value, int Increment_step, int Body_first, int Body_last, int Iterations, int For_loop_entry)
{
	if (HT.findfact("last_for_loop_entry(*)"))
	{
		int Last_for_loop;
		Last_for_loop = stoi(returnpar(HT.findandreturn("last_for_loop_entry(*)"), 1));
		For_loop_entry = Last_for_loop + 1;
		// for_loop w/ 13 or 14 parameters?
		HT.assertz("for_loop(" + to_string(For_loop_entry) + "," + Module_name + "," + to_string(If_entry) + "," + to_string(Condition_statement) + "," + to_string(End_of_loop) + "," + to_string(Header_start) + "," + to_string(Increment_instruction) + "," + to_string(Increment_variable) + "," + to_string(Start_value) + "," + to_string(End_value) + "," + to_string(Increment_step) + "," + to_string(Body_first) + "," + to_string(Body_last) + ")"); // made for case w/ 13 parameters
		HT.retractall("last_for_loop_entry(*)");
		HT.assertz("last_for_loop_entry(For_loop_entry)");
	}
}

/* Traces back the last operation which targets the variable */
bool trace_back(string Module, int Previous, int Variable, int *Result)
{
	if (!HT.findfact("prog_stmt(" + Module + "," + to_string(Previous) + ",_,_,_,_,_,_)") && *Result == 0)
		return false;
	else if (HT.findfact("prog_stmt(" + Module + "," + to_string(Previous) + ",_,_,_,_," + to_string(Variable) + ",_)"))
	{
		int Operator, Left, Right, Target;
		Operator = stoi(returnpar(HT.findandreturn("prog_stmt(" + Module + "," + to_string(Previous) + ",_,_,_,_," + to_string(Variable) + ",_)"), 4));
		Left = stoi(returnpar(HT.findandreturn("prog_stmt(" + Module + "," + to_string(Previous) + ",_," + to_string(Operator) + ",_,_," + to_string(Variable) + ",_)"), 5));
		Right = stoi(returnpar(HT.findandreturn("prog_stmt(" + Module + "," + to_string(Previous) + ",_," + to_string(Operator) + "," + to_string(Left) + ",_," + to_string(Variable) + ",_)"), 6));
		if (Operator != 110)
		{
			calc_target_var(Module, Operator, Left, Right, Result);
		}
	}
	else if (HT.findfact("prog_stmt(" + Module + "," + to_string(Previous) + ",_,_,_,_,_,_)"))
	{
		int Target, Next_previous;
		Target = stoi(returnpar(HT.findandreturn("prog_stmt(" + Module + "," + to_string(Previous) + ",_,_,_,_,_,_)"), 7));
		if (Target != Variable)
		{
			Next_previous = Target - 1;
			trace_back(Module, Next_previous, Variable, Result);
		}
	}
	return true;
}

/* Calculate the value of variable on a targeting operation */
void calc_target_var(string Module, int Operator, int Left, int Right, int* Result)
{
	if (HT.findfact("data_stmt(" + Module + ",_," + to_string(Right) + ",_,\"const\",_)"))
	{
		int Right_Value, Left_Value;
		Right_Value = stoi(last_from_data_stmt(returnpar(HT.findandreturn("data_stmt(" + Module + ",_," + to_string(Right) + ",_,\"const\",_)"), 6)));
		Left_Value = stoi(last_from_data_stmt(returnpar(HT.findandreturn("data_stmt(" + Module + ",_," + to_string(Left) + ",_,\"const\",_)"), 6)));
		if (Operator == 60)
			*Result -= Right_Value;
		else if (Operator == 62)
			*Result = Left_Value + Right_Value;
		else if (Operator == 63)
			*Result = Left_Value - Right_Value;
		else if (Operator == 64)
			*Result = Left_Value * Right_Value;
		else if (Operator == 65)
			*Result = Left_Value / Right_Value;
		else if (Operator == 102)
			*Result = Right_Value;
	}
}
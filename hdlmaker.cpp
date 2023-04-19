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
void code_for_module_created_message(string Module, int ModCount);
void write_custom_block(string Module_name, string hdlform, vector<local_object>* local_list);
string write_title(string Module_name, string Hdlform, string Tool);
string write_ieee_packages(string str1, string str2);
string write_global_package(string Module, string str1, string str2);
string print_global_constants(int DEntry, string HDL);
string print_global_constant(int DEntry, string str);
string type_value(string PModule, int Data_entry, string str);
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
void add_while_loop(string Module, int If_statement, int Condition_statement, int End_of_loop, int Body_first, int Body_last, int* While_loop_entry);
void trace_previous_assign_op(string Module_name, int Condition_statement, int* Assign_stmt);
void add_for_loop(string Module_name, int If_entry, int Condition_statement, int End_of_loop, int Header_start, int Increment_instruction, int Increment_variable, int Start_value, int End_value, int Increment_step, int Body_first, int Body_last, int Iterations, int* For_loop_entry);
bool trace_back(string Module, int Previous, int Variable, int* Result);
void calc_target_var(string Module, int Operator, int Left, int Right, int* Result);
void generate_hdl_recursive(string Hdlform, string Tool, int Entry);
void store_package_name(int Entry, string Module);
void increment_module_counter();
void generate_hdl_2(string Hdlform, string tool, string Module_name, int Level);
bool custom_block(string* Module_name);
void get_and_append_local(string Module_name, vector<local_object> LList,int Onumber, vector<local_object>* cosLList,int* cosOnumber);
void add_local_conditionally(string Module_name, vector<local_object> In_local_list, int In_local_entry, vector<local_object>* Out_list, int* Last_entry);
void append_local(vector<local_object> T1, local_object Local1, vector<local_object>* T2);
void parent_type_is_integer(int Type, int* Par_Size);


//determ i=input o=output
//in language add 16 on page search
//ITF_lib "as76das" "asdafgg125hdsg" "hdf12sbshd"
//C:\Users\dima\source\repos\ITF_lib
int main(int argc, char* argv[])
{
	int ch = 5;
	switch (ch)
	{
	case 0:
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
		generate_top(pathln, exec, cmdl);
	}
	break;
	case 1:
	{
		HT.consult("examples.txt");
		HT.save("save01.txt");
		HT.consult("save01.txt");
		HT.save("save02.txt");
	}
	break;
	case 2:
	{
		vector<string>			AllLines;
		string					ALine;
		int						Treepos{};
		ifstream File;

		File.open("examplesInsOfSpFact_pos_par.txt", fstream::in);

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
				makeInstanceOfSpecFact(AllLines[i]);
				cout << AllLines[i] << endl;
			}
		}

	}
	case 3:
	{
		vector<string>			AllLines;
		string					ALine;
		int						Treepos{};
		ifstream File;

		HT.consult("examples.txt");

		File.open("examplesInsOfSpFact_pos_par.txt", fstream::in);

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
				HT.matchedToFList(AllLines[i]);
				//cout << AllLines[i] << endl;
			}
		}

	}
	break;
	case 4:
	{
		//cout << last_from_data_stmt("sym(\"sfhgsdfhs\")") << endl;
		//cout << last_from_data_stmt("i(12430)") << endl;
		//cout << last_from_data_stmt("bol(036356)") << endl;

		string asd = "abcdefg";
		if (asd.substr(0, 3) == "abc")
			cout << "ok" << endl;
	}
	case 5:
	{
		//// (data_stmt) done: makeStringOf, makeInstanceOf, makefactstar, makeInstanceOfSpecFact, matchfactsSpec, makefactstar
		
		//cout <<   makeStringOf(makeInstanceOf("data_stmt(\"pythagoras_test\",\"s_base\",1,2,\"const\",i(0))"))					  << endl;
		//cout << 		makeStringOf(makeInstanceOf("data_stmt(\"init_arrays\",\"s\",1,12,\"par_out\",sym(\"s\"))"))			  << endl;
		//cout << makeStringOf(makeInstanceOf("data_stmt(\"int_to_bit_vector\",\"const1\",8,1,\"const\",bol(1))"))				  << endl;
		//cout << makeStringOf(makeInstanceOf("data_stmt(\"int_to_bit_vector\",\"const1\",8,1,\"const\",bit_wire(\"std_logic\"))")) << endl;
		//
		//  makefactstar("data_stmt(\"pythagoras_test\",\"s_base\",1,2,\"const\",i(0))");
		//		  makefactstar("data_stmt(\"init_arrays\",\"s\",1,12,\"par_out\",sym(\"s\"))");
		//makefactstar("data_stmt(\"int_to_bit_vector\",\"const1\",8,1,\"const\",bol(1))");
		//makefactstar("data_stmt(\"int_to_bit_vector\",\"const1\",8,1,\"const\",bit_wire(\"std_logic\"))");
		//  makefactstar("data_stmt(\"pythagoras_test\",\"s_base\",1,2,\"const\",i(*))");
		//		  makefactstar("data_stmt(\"init_arrays\",\"s\",1,12,\"par_out\",sym(*))");
		//makefactstar("data_stmt(\"int_to_bit_vector\",\"const1\",8,1,\"const\",bol(*))");
		//makefactstar("data_stmt(\"int_to_bit_vector\",\"const1\",8,1,\"const\",bit_wire(*))");
		//  makefactstar("data_stmt(\"pythagoras_test\",\"s_base\",1,2,\"const\",*)");
		//		  makefactstar("data_stmt(\"init_arrays\",\"s\",1,12,\"par_out\",*)");
		//makefactstar("data_stmt(\"int_to_bit_vector\",\"const1\",8,1,\"const\",*)");
		//makefactstar("data_stmt(\"int_to_bit_vector\",\"const1\",8,1,\"const\",*)");
		//
		//  makeInstanceOfSpecFact("data_stmt(\"pythagoras_test\",\"s_base\",1,2,\"const\",i(0))");
		//		makeInstanceOfSpecFact("data_stmt(\"init_arrays\",\"s\",1,12,\"par_out\",sym(\"s\"))");
		//makeInstanceOfSpecFact("data_stmt(\"int_to_bit_vector\",\"const1\",8,1,\"const\",bol(1))");
		//makeInstanceOfSpecFact("data_stmt(\"int_to_bit_vector\",\"const1\",8,1,\"const\",bit_wire(\"std_logic\"))");
		//  makeInstanceOfSpecFact("data_stmt(\"pythagoras_test\",\"s_base\",1,2,\"const\",i(_))");
		//		makeInstanceOfSpecFact("data_stmt(\"init_arrays\",\"s\",1,12,\"par_out\",sym(_))");
		//makeInstanceOfSpecFact("data_stmt(\"int_to_bit_vector\",\"const1\",8,1,\"const\",bol(_))");
		//makeInstanceOfSpecFact("data_stmt(\"int_to_bit_vector\",\"const1\",8,1,\"const\",bit_wire(_))");
		//  makeInstanceOfSpecFact("data_stmt(\"pythagoras_test\",\"s_base\",1,2,\"const\",_)");
		//		makeInstanceOfSpecFact("data_stmt(\"init_arrays\",\"s\",1,12,\"par_out\",_)");
		//makeInstanceOfSpecFact("data_stmt(\"int_to_bit_vector\",\"const1\",8,1,\"const\",_)");
		//makeInstanceOfSpecFact("data_stmt(\"int_to_bit_vector\",\"const1\",8,1,\"const\",_)");
		//
		//factUnderInspection FUI{};
		//FUI = makeInstanceOfSpecFact("data_stmt(\"pythagoras_test\",\"s_base\",1,2,\"const\",i(_))");
		//cout << matchfactsSpec(makeInstanceOf("data_stmt(\"pythagoras_test\",\"s_base\",1,2,\"const\",i(0))"), &FUI) << endl;
		//FUI = makeInstanceOfSpecFact("data_stmt(\"init_arrays\",\"s\",1,12,\"par_out\",_)");
		//cout << matchfactsSpec(makeInstanceOf("data_stmt(\"init_arrays\",\"s\",1,12,\"par_out\",sym(\"s\"))"), &FUI) << endl;
		//FUI = makeInstanceOfSpecFact("data_stmt(\"int_to_bit_vector\",\"const1\",8,1,\"const\",bol(0))");
		//cout << matchfactsSpec(makeInstanceOf("data_stmt(\"int_to_bit_vector\",\"const1\",8,1,\"const\",bol(1))"), &FUI) << endl;
		//FUI = makeInstanceOfSpecFact("data_stmt(\"int_to_bit_vector\",\"const1\",8,1,\"const\",bol(1))");
		//cout << matchfactsSpec(makeInstanceOf("data_stmt(\"int_to_bit_vector\",\"const1\",8,1,\"const\",bit_wire(\"std_logic\"))"), &FUI) << endl;
		//
		//factstar FUI{};
		//FUI = makefactstar("data_stmt(\"pythagoras_test\",\"s_base\",1,2,\"const\",i(*))");
		//cout << matchfactsstar(makeInstanceOf("data_stmt(\"pythagoras_test\",\"s_base\",1,2,\"const\",i(0))"), &FUI) << endl;
		//FUI = makefactstar("data_stmt(\"init_arrays\",\"s\",1,12,\"par_out\",*)");
		//cout << matchfactsstar(makeInstanceOf("data_stmt(\"init_arrays\",\"s\",1,12,\"par_out\",sym(\"s\"))"), &FUI) << endl;
		//FUI = makefactstar("data_stmt(\"int_to_bit_vector\",\"const1\",8,1,\"const\",bol(0))");
		//cout << matchfactsstar(makeInstanceOf("data_stmt(\"int_to_bit_vector\",\"const1\",8,1,\"const\",bol(1))"), &FUI) << endl;
		//FUI = makefactstar("data_stmt(\"int_to_bit_vector\",\"const1\",8,1,\"const\",bol(1))");
		//cout << matchfactsstar(makeInstanceOf("data_stmt(\"int_to_bit_vector\",\"const1\",8,1,\"const\",bit_wire(\"std_logic\"))"), &FUI) << endl;

		//// (special_dt) done: makeStringOf, makeInstanceOf, makefactstar, makeInstanceOfSpecFact, makeInstanceOfSpecFact, matchfactsstar
		
		//cout <<		 makeStringOf(makeInstanceOf("special_dt(\"init_arrays\",-5,\"porta_tg_S_base\",32,\"std_logic\",\"const\",i(0))")) << endl;
		//cout << 			makeStringOf(makeInstanceOf("special_dt(\"init_arrays\",-6,\"temp_addr1\",32,\"std_logic\",\"var\",sym(\"node\"))")) << endl;
		//cout <<		 makeStringOf(makeInstanceOf("special_dt(\"init_arrays\",-5,\"porta_tg_S_base\",32,\"std_logic\",\"const\",bol(1))")) << endl;
		//cout << makeStringOf(makeInstanceOf("special_dt(\"init_arrays\",-4,\"porta_tg_mema_wr_en\",1,\"std_logic\",\"par_out\",bit_wire(\"std_logic\"))")) << endl;
		//
		//makefactstar("special_dt(\"init_arrays\",-5,\"porta_tg_S_base\",32,\"std_logic\",\"const\",i(0))");
		//makefactstar("special_dt(\"init_arrays\",-6,\"temp_addr1\",32,\"std_logic\",\"var\",sym(\"node\"))");
		//makefactstar("special_dt(\"init_arrays\",-5,\"porta_tg_S_base\",32,\"std_logic\",\"const\",bol(1))");
		//makefactstar("special_dt(\"init_arrays\",-4,\"porta_tg_mema_wr_en\",1,\"std_logic\",\"par_out\",bit_wire(\"std_logic\"))");
		//
		//makefactstar("special_dt(\"init_arrays\",-5,\"porta_tg_S_base\",32,\"std_logic\",\"const\",i(*))");
		//makefactstar("special_dt(\"init_arrays\",-6,\"temp_addr1\",32,\"std_logic\",\"var\",sym(*))");
		//makefactstar("special_dt(\"init_arrays\",-5,\"porta_tg_S_base\",32,\"std_logic\",\"const\",bol(*))");
		//makefactstar("special_dt(\"init_arrays\",-4,\"porta_tg_mema_wr_en\",1,\"std_logic\",\"par_out\",bit_wire(*))");
		//
		//makefactstar("special_dt(\"init_arrays\",-5,\"porta_tg_S_base\",32,\"std_logic\",\"const\",*)");
		//makefactstar("special_dt(\"init_arrays\",-6,\"temp_addr1\",32,\"std_logic\",\"var\",*)");
		//makefactstar("special_dt(\"init_arrays\",-5,\"porta_tg_S_base\",32,\"std_logic\",\"const\",*)");
		//makefactstar("special_dt(\"init_arrays\",-4,\"porta_tg_mema_wr_en\",1,\"std_logic\",\"par_out\",*)");
		//
		//makeInstanceOfSpecFact("special_dt(\"init_arrays\",-5,\"porta_tg_S_base\",32,\"std_logic\",\"const\",i(0))");
		//makeInstanceOfSpecFact("special_dt(\"init_arrays\",-6,\"temp_addr1\",32,\"std_logic\",\"var\",sym(\"node\"))");
		//makeInstanceOfSpecFact("special_dt(\"init_arrays\",-5,\"porta_tg_S_base\",32,\"std_logic\",\"const\",bol(1))");
		//makeInstanceOfSpecFact("special_dt(\"init_arrays\",-4,\"porta_tg_mema_wr_en\",1,\"std_logic\",\"par_out\",bit_wire(\"std_logic\"))");
		//
		//makeInstanceOfSpecFact("special_dt(\"init_arrays\",-5,\"porta_tg_S_base\",32,\"std_logic\",\"const\",i(_))");
		//makeInstanceOfSpecFact("special_dt(\"init_arrays\",-6,\"temp_addr1\",32,\"std_logic\",\"var\",sym(_))");
		//makeInstanceOfSpecFact("special_dt(\"init_arrays\",-5,\"porta_tg_S_base\",32,\"std_logic\",\"const\",bol(_))");
		//makeInstanceOfSpecFact("special_dt(\"init_arrays\",-4,\"porta_tg_mema_wr_en\",1,\"std_logic\",\"par_out\",bit_wire(_))");
		//
		//makeInstanceOfSpecFact("special_dt(\"init_arrays\",-5,\"porta_tg_S_base\",32,\"std_logic\",\"const\",_)");
		//makeInstanceOfSpecFact("special_dt(\"init_arrays\",-6,\"temp_addr1\",32,\"std_logic\",\"var\",_)");
		//makeInstanceOfSpecFact("special_dt(\"init_arrays\",-5,\"porta_tg_S_base\",32,\"std_logic\",\"const\",_)");
		//makeInstanceOfSpecFact("special_dt(\"init_arrays\",-4,\"porta_tg_mema_wr_en\",1,\"std_logic\",\"par_out\",_)");
		//
		//factUnderInspection FUI{};
		//FUI = makeInstanceOfSpecFact("special_dt(\"init_arrays\",-5,\"porta_tg_S_base\",32,\"std_logic\",\"const\",i(_))");
		//cout << matchfactsSpec(makeInstanceOf("special_dt(\"init_arrays\",-5,\"porta_tg_S_base\",32,\"std_logic\",\"const\",i(0))"), & FUI);
		//FUI = makeInstanceOfSpecFact("special_dt(\"init_arrays\",-6,\"temp_addr1\",32,\"std_logic\",\"var\",_)");
		//cout << matchfactsSpec(makeInstanceOf("special_dt(\"init_arrays\",-6,\"temp_addr1\",32,\"std_logic\",\"var\",sym(\"node\"))"), & FUI);
		//FUI = makeInstanceOfSpecFact("special_dt(\"init_arrays\",-5,\"porta_tg_S_base\",32,\"std_logic\",\"const\",bol(0))");
		//cout << matchfactsSpec(makeInstanceOf("special_dt(\"init_arrays\",-5,\"porta_tg_S_base\",32,\"std_logic\",\"const\",bol(1))"), & FUI);
		//FUI = makeInstanceOfSpecFact("special_dt(\"init_arrays\",-4,\"porta_tg_mema_wr_en\",1,\"std_logic\",\"par_out\",bol(1))");
		//cout << matchfactsSpec(makeInstanceOf("special_dt(\"init_arrays\",-4,\"porta_tg_mema_wr_en\",1,\"std_logic\",\"par_out\",bit_wire(\"std_logic\"))"), &FUI);
		//
		//factstar FUI{};
		//FUI = makefactstar("special_dt(\"init_arrays\",-5,\"porta_tg_S_base\",32,\"std_logic\",\"const\",i(*))");
		//cout << matchfactsstar(makeInstanceOf("special_dt(\"init_arrays\",-5,\"porta_tg_S_base\",32,\"std_logic\",\"const\",i(0))"), &FUI);
		//FUI = makefactstar("special_dt(\"init_arrays\",-6,\"temp_addr1\",32,\"std_logic\",\"var\",*)");
		//cout << matchfactsstar(makeInstanceOf("special_dt(\"init_arrays\",-6,\"temp_addr1\",32,\"std_logic\",\"var\",sym(\"node\"))"), &FUI);
		//FUI = makefactstar("special_dt(\"init_arrays\",-5,\"porta_tg_S_base\",32,\"std_logic\",\"const\",bol(0))");
		//cout << matchfactsstar(makeInstanceOf("special_dt(\"init_arrays\",-5,\"porta_tg_S_base\",32,\"std_logic\",\"const\",bol(1))"), &FUI);
		//FUI = makefactstar("special_dt(\"init_arrays\",-4,\"porta_tg_mema_wr_en\",1,\"std_logic\",\"par_out\",bol(1))");
		//cout << matchfactsstar(makeInstanceOf("special_dt(\"init_arrays\",-4,\"porta_tg_mema_wr_en\",1,\"std_logic\",\"par_out\",bit_wire(\"std_logic\"))"), &FUI);

	}
	break;
	default:
		break;
	}
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
		if (HT.findfact("hdl_style(*)"))
		{
			string Hdlform;
			Hdlform = returnpar(HT.findandreturn("hdl_style(*)"), 1);
			extract_loops_from_all_modules(2);
			generate_hdl_recursive(Hdlform, "synergy", 1);
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
void assert_mp_conditionally(string Massively_parallel)
{
	if (Massively_parallel == "")
		HT.assertz("massively_parallel_style(1)");
	else if (Massively_parallel == "mp")
		HT.assertz("massively_parallel_style(1)");
}

/* This predicate is used for the assertion of the HDL type */
void assert_hdl_conditionally(string Hdl)
{
	if (Hdl == "") HT.assertz("hdl_style(\"vhdl\")");
	else if (Hdl != "" && Hdl != "verilog") HT.assertz("hdl_style(\"vhdl\")");
	else if (Hdl == "vhdl") HT.assertz("hdl_style(\"vhdl\")");
	else if (Hdl == "verilog") HT.assertz("hdl_style(\"verilog\")");
	else if (Hdl == "c") HT.assertz("hdl_style(\"c\")");
}

/* (un)Sets the debug_mode(2) especially for the HDLMAKER */
void set_debug(string Line)
{
	if (Line == "debug")
		if (!HT.findfact("debug_mode(2)")) 
			HT.assertz("debug_mode(2)");
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
void assert_global_constraint_conditionally0(string Command_line_args)
{
	string Hdl = "", Rest_of_command_line = "";
	if (Command_line_args == "")
	{
		assert_hdl_conditionally("");
		assert_mp_conditionally("");
		return;
	}
	else if (Command_line_args == "debug")		//line 32835
	{
		set_debug("debug");
		assert_hdl_conditionally("");
		assert_mp_conditionally("");
		return;
	}
	else
	{
		fronttoken(Command_line_args, Hdl, Rest_of_command_line);
		if (Hdl == "")
		{
			assert_hdl_conditionally("");
			assert_mp_conditionally("");
			return;
		}
		else if (Hdl == "debug")
		{
			set_debug("debug");
			if (!Rest_of_command_line.empty())
			{
				string Hdl1 = "", Rest_of_command_line1 = "";
				fronttoken(Rest_of_command_line, Hdl1, Rest_of_command_line1);
				if (Hdl1 != "debug")
				{
					assert_hdl_conditionally(Hdl1);
					assert_global_constraint_conditionally1(Rest_of_command_line1);
					return;
				}
				else if (Hdl1 == "debug")
				{
					set_debug("debug");
					if (!Rest_of_command_line1.empty())
					{
						string Hdl2 = "", Rest_of_command_line2 = "";
						fronttoken(Rest_of_command_line1, Hdl2, Rest_of_command_line2);
						if (!Hdl2.empty())
						{
							if (Rest_of_command_line2.empty())
							{
								assert_hdl_conditionally(Hdl2);
								return;
							}
							else if (!Rest_of_command_line2.empty())
							{
								assert_hdl_conditionally(Hdl2);
								assert_global_constraint_conditionally1(Rest_of_command_line2);
								return;
							}
						}
					}
				}
			}
			assert_hdl_conditionally("");
			assert_mp_conditionally("");
			return;
		}
		else if (Hdl != "debug" && Hdl != "cac")
		{
			assert_hdl_conditionally(Hdl);
			assert_global_constraint_conditionally1(Rest_of_command_line);
		}
		else if (Hdl == "cac")
		{
			set_cac("cac");
			assert_hdl_conditionally("c");
			HT.assertz("massively_parallel_style(1)");
			return;
		}
	}
}

// Now this predicate is used for the assertion of other command-line parameter facts as well
void assert_global_constraint_conditionally1(string Command_line_args)
{
	string Massively_parallel = "", Rest_of_command_line = "";
	if (Command_line_args.empty())
		assert_mp_conditionally("");
	else
	{
		fronttoken(Command_line_args, Massively_parallel, Rest_of_command_line);
		if (Massively_parallel.empty())
		{
			assert_mp_conditionally(Massively_parallel);
		}
		else if (!Command_line_args.empty())
		{
			fronttoken(Command_line_args, Massively_parallel, Rest_of_command_line);
			assert_mp_conditionally(Massively_parallel);
			assert_global_constraint_conditionally2(Rest_of_command_line);
		}
	}
}

//26 / 6 / 2018 this predicate is used for the assertion of syncronous or asynchronous reset style of the generated coprocessors FSMs
void assert_global_constraint_conditionally2(string Command_line_args)
{
	string SyncAsyncReset = "", Rest_cl_args = "";
	if (Command_line_args.empty())
	{
		HT.assertz("resetstyle(\"syncreset\")");
		return;
	}
	else
	{
		fronttoken(Command_line_args, SyncAsyncReset, Rest_cl_args);
		if (!SyncAsyncReset.empty() && SyncAsyncReset.empty())
			HT.assertz("resetstyle(" + SyncAsyncReset + ")");
		else if (!SyncAsyncReset.empty() && !Rest_cl_args.empty())
		{
			HT.assertz("resetstyle(" + SyncAsyncReset + ")");
			assert_global_constraint_conditionally3(Rest_cl_args);
		}
		else if (SyncAsyncReset.empty())
			HT.assertz("resetstyle(\"syncreset\")");
		else if (!SyncAsyncReset.empty())
		{
			HT.assertz("resetstyle(" + SyncAsyncReset + ")");
			assert_global_constraint_conditionally3(Rest_cl_args);
		}
	}
}

//28/6/2018 this predicate is used for the prevention of hierarchy checking of modules and reliance on the validity of the input code order.
void assert_global_constraint_conditionally3(string Command_line_args)
{
	if (Command_line_args.empty())
		HT.assertz("checkstyle(\"checkhierarchy\")");
	else
	{
		string Check = "", Rest_cl_args = "";
		fronttoken(Command_line_args, Check, Rest_cl_args);
		if (Check == "checkhierarchy") 
			HT.assertz("checkstyle(\"checkhierarchy\")");
		else 
			HT.assertz("checkstyle(\"dontcheckhierarchy\")");
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
		return;
	else if (HT.findfact("hierarchy_part(" + to_string(Entry) + ",_,_,\"libpart\",_,_,_)"))
	{
		string Module_name;
		int Next_entry;
		Module_name = stoi(returnpar(HT.findandreturn("hierarchy_part(" + to_string(Entry) + ",_,_,\"libpart\",_,_,_)"), 2));
		HT.assertz("last_for_loop_entry(0)");
		HT.assertz("last_while_loop_entry(0)");
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
		return;
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
		Iterations, Assign_stmt, Start_val_data, Header_start, Condition_operator, Init_variable, Decrement_variable, Decrement_instruction, 
		Decrement_step, While_loop_entry, For_loop_entry;
	string Kind;
	if (HT.findfact("prog_stmt(" + name + "," + to_string(Entry) + ",_,_,_,_,_,_)"))
	{
		op = stoi(returnpar(HT.findandreturn("prog_stmt(" + name + "," + to_string(Entry) + ",_,_,_,_,_,_)"), 4));
		if (op != 110)
			return;
		One_after_110 = stoi(returnpar(HT.findandreturn("prog_stmt(" + name + "," + to_string(Entry) + ",_,110,_,_,_,_)"), 8));
		if (!HT.findfact("prog_stmt(" + name + ",_,_,106,_,_," + to_string(One_after_110) + ",_)"))
			return;
		/* now when the target stmt of the jump is larger than its Entry, (which comes from
		if then else statements in ADA */
		Target_statement = stoi(returnpar(HT.findandreturn("prog_stmt(" + name + "," + to_string(Entry) + ",_,110,_,_,_,_)"), 7));
		if (Target_statement > Entry) //comes from ifthenelse
			return;
		/* now just the case that it is a while loop, without a Condition operation */
		if (HT.findfact("prog_stmt(" + name + "," + to_string(Entry) + ",_,110,_,_,_,_)"))
		{
			If_entry = stoi(returnpar(HT.findandreturn("prog_stmt(" + name + "," + to_string(Entry) + ",_,110,_,_,_,_)"), 7));
			Condition_statement = stoi(returnpar(HT.findandreturn("prog_stmt(" + name + "," + to_string(Entry) + ",_,110,_,_,_," + to_string(One_after_110) + ")"), 7));
			if (HT.findfact("prog_stmt(" + name + "," + to_string(If_entry) + ",_,106,_,_," + to_string(One_after_110) + ",_)"))
			{
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
							add_while_loop(name, If_entry, Condition_statement, End_of_loop, Body_first, Body_last, &While_loop_entry);
							return;
						}
						/* now just the case that it is a while loop, with a Condition operation */
						else if (Previous_target == Condition)
						{
							Condition_statement = Previous_target;
							Body_last = Entry - 1;
							End_of_loop = Entry;
							add_while_loop(name, If_entry, Condition_statement, End_of_loop, Body_first, Body_last, &While_loop_entry);
							return;
						}
					}
					/* now just the case that it is a while loop, with the 106 being the first operation in the program */
					else if (!HT.findfact("prog_stmt(" + name + "," + to_string(Previous_statement) + ",_,_,_,_,_,_)"))
					{
						Condition_statement = Previous_statement;
						Body_last = Entry - 1;
						End_of_loop = Entry;
						add_while_loop(name, If_entry, Condition_statement, End_of_loop, Body_first, Body_last, &While_loop_entry);
						return;
					}
				}
			}
			/* now just the case that it is a while loop, with (maybe) a loop-like condition operation,
			but it is not an increment operation, thus it is a while */
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
											add_while_loop(name, If_entry, Condition_statement, End_of_loop, Body_first, Body_last, &While_loop_entry);
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
									add_while_loop(name, If_entry, Condition_statement, End_of_loop, Body_first, Body_last, &While_loop_entry);
									return;
								}
							}
							Loop_comparison = stoi(returnpar(HT.findandreturn("prog_stmt(" + name + ",_,_,_,_,_," + to_string(Condition) + "," + to_string(Body_first) + ")"), 2));
							For_loop_variable = stoi(returnpar(HT.findandreturn("prog_stmt(" + name + "," + to_string(Loop_comparison) + ",_,_,_,_," + to_string(Condition) + "," + to_string(Body_first) + ")"), 6));
							if (!HT.findfact("prog_stmt(" + name + "," + to_string(Increment_instruction) + ",_,_,_," + to_string(For_loop_variable) + ",_,_)"))
							{
								Body_last = Increment_instruction;
								End_of_loop = Entry;
								add_while_loop(name, If_entry, Condition_statement, End_of_loop, Body_first, Body_last, &While_loop_entry);
								return;
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
								Init_variable = stoi(returnpar(HT.findandreturn("prog_stmt(" + name + "," + to_string(Initiation_statement) + ",_,102,0,_," + to_string(Increment_variable) + "," + to_string(Condition_statement) + ")"), 6));
								if (HT.findfact("data_stmt(" + name + ",_," + to_string(End_val_data) + ",_,\"var\",\"sym(\"node\")\")"))
								{
									if (HT.findfact("data_stmt(" + name + ",_," + to_string(Init_constant) + ",_,\"const\",i(*))"))
									{
										Low_limit = stoi(returnpar(HT.findandreturn("data_stmt(" + name + ",_," + to_string(Init_constant) + ",_,\"const\",i(*))"), 7));
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
													add_for_loop(name, If_entry, Condition_statement, End_of_loop, Header_start,
													Increment_instruction, Increment_variable, Start_val_data, End_val_data,
													Increment_step, Body_first, Body_last, Iterations, &For_loop_entry);
													return;
												}
											}
										}
										else if (!trace_back(name, Initiation_statement, End_val_data, 0))
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
													add_while_loop(name, If_entry, Condition_statement, End_of_loop, Body_first, Body_last, &While_loop_entry);
													return;
												}
											}
										}
									}
									if (HT.findfact("data_stmt(" + name + ",_," + to_string(End_val_data) + ",_,\"var\",sym(\"node\"))"))
									{
										if (HT.findfact("data_stmt(" + name + ",_," + to_string(Init_variable) + ",_,\"var\",_)"))
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
														add_while_loop(name, If_entry, Condition_statement, End_of_loop, Body_first, Body_last, &While_loop_entry);
														return;
													}
												}
											}
										}
									}
								}
								Initiation_statement_b = Initiation_statement - 1;
								if (HT.findfact("prog_stmt(" + name + "," + to_string(Initiation_statement_b) + ",_,102,0,_," + to_string(End_val_data) + "," + to_string(Initiation_statement) + ")"))
								{
									Init_constant_b = stoi(returnpar(HT.findandreturn("prog_stmt(" + name + "," + to_string(Initiation_statement_b) + ",_,102,0,_," + to_string(End_val_data) + "," + to_string(Initiation_statement) + ")"), 6));
									//% now find the values of the lowand up limit
									if (HT.findfact("data_stmt(" + name + ",_," + to_string(Init_constant) + ",  _,\"const\",i(*))"))
									{
										Low_limit = stoi(returnpar(HT.findandreturn("data_stmt(" + name + ",_," + to_string(Init_constant) + ", _,\"const\",i(*)))"), 7));
										if (HT.findfact("data_stmt(" + name + ",_," + to_string(Init_constant_b) + ",  _,\"const\",i(*)))") || HT.findfact("data_stmt(" + name + ",_," + to_string(End_val_data) + ",  _,\"const\",_)"))
										{
											Up_limit = stoi(returnpar(HT.findandreturn("data_stmt(" + name + ",_," + to_string(Init_constant) + ", _,\"const\",i(*)))"), 7));
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
													Increment_step, Body_first, Body_last, Iterations, &For_loop_entry);
													return;
												}
											}
										}
									}								
								}
								else if (HT.findfact("data_stmt(" + name + ",_," + to_string(Init_constant) + ",  _,\"const\",i(*))"))
								{
									Low_limit = stoi(returnpar(HT.findandreturn("data_stmt(" + name + ",_," + to_string(Init_constant) + ", _,\"const\",i(*))"), 7));
									if (HT.findfact("data_stmt(" + name + ",_," + to_string(End_val_data) + ",  _,\"const\",i(*))"))
									{
										Up_limit = stoi(returnpar(HT.findandreturn("data_stmt(" + name + ",_," + to_string(End_val_data) + ",  _,\"const\",i(*))"), 7));
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
												add_for_loop(name, If_entry, Condition_statement, End_of_loop, Header_start,
												Increment_instruction, Increment_variable, Start_val_data, End_val_data,
												Increment_step, Body_first, Body_last, Iterations, &For_loop_entry);
												return;
											}

										}
									}
									if (HT.findfact("data_stmt(" + name + ",_," + to_string(End_val_data) + ",  _,_,_)"))
									{
										Kind = stoi(returnpar(HT.findandreturn("data_stmt(" + name + ",_," + to_string(End_val_data) + ",  _,_,_)"), 5));
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
													add_while_loop(name, If_entry, Condition_statement, End_of_loop, Body_first, Body_last, &While_loop_entry);
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
									if (HT.findfact("data_stmt(" + name + ",_," + to_string(Init_constant) + ",_,\"const\",i(*))"))
									{
										Low_limit = stoi(returnpar(HT.findandreturn("data_stmt(" + name + ",_," + to_string(Init_constant) + ",_,\"const\",i(*))"), 7));
										if (HT.findfact("data_stmt(" + name + ",_," + to_string(End_val_data) + ",  _,\"const\",i(*))"))
										{
											Up_limit = stoi(returnpar(HT.findandreturn("data_stmt(" + name + ",_," + to_string(End_val_data) + ", _,\"const\",i(*))"), 7));
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
													Increment_step, Body_first, Body_last, Iterations, &For_loop_entry);
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
								Init_constant = stoi(returnpar(HT.findandreturn("prog_stmt(" + name + "," + to_string(Initiation_statement) + ",_,102,0,_," + to_string(Decrement_variable) + "," + to_string(Condition_statement) + ")"), 6));
								Init_variable = stoi(returnpar(HT.findandreturn("prog_stmt(" + name + "," + to_string(Initiation_statement) + ",_,102,0,_," + to_string(Decrement_variable) + "," + to_string(Condition_statement) + ")"), 6));
								Initiation_statement_b = Initiation_statement - 1;
								if (HT.findfact("data_stmt(" + name + ",_," + to_string(Init_variable) + ", _,\"var\",\"sym(\"node\")\")"))
								{
									if (HT.findfact("data_stmt(" + name + ",_," + to_string(End_val_data) + ",2,\"const\",i(*))"))
									{
										Low_limit = stoi(returnpar(HT.findandreturn("data_stmt(" + name + ",_," + to_string(End_val_data) + ",2,\"const\",i(*))"), 7));
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
													Decrement_step, Body_first, Body_last, Iterations, &For_loop_entry);
												}
											}
										}
									}
								}
								/* now the case of a for loop, with a decrement instruction, just before the jump
								and the	upper limit of the loop being assigned to a constant*/
								Init_constant = stoi(returnpar(HT.findandreturn("prog_stmt(" + name + "," + to_string(Initiation_statement) + ",_,102,0,_," + to_string(Decrement_variable) + "," + to_string(Condition_statement) + ")"), 6));
								if (HT.findfact("prog_stmt(" + name + "," + to_string(Initiation_statement_b) + ",_,102,0,_," + to_string(End_val_data) + "," + to_string(Initiation_statement) + ")"))
								{
									Init_constant_b = stoi(returnpar(HT.findandreturn("prog_stmt(" + name + "," + to_string(Initiation_statement_b) + ",_,102,0,_," + to_string(End_val_data) + "," + to_string(Initiation_statement) + ")"), 6));
									if (HT.findfact("data_stmt(" + name + ",_," + to_string(Init_constant) + ",  _,\"const\",i(*))"))
									{
										Up_limit = stoi(returnpar(HT.findandreturn("data_stmt(" + name + ",_," + to_string(End_val_data) + ",_,\"const\",i(*))"), 7));
										if (HT.findfact("data_stmt(" + name + ",_," + to_string(Init_constant_b) + ",  _,\"const\",i(*))"))
										{
											Low_limit = stoi(returnpar(HT.findandreturn("data_stmt(" + name + ",_," + to_string(End_val_data) + ",_,\"const\",i(*))"), 7));
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
													Decrement_step, Body_first, Body_last, Iterations, &For_loop_entry);
												}
											}
										}
									}
								}
								else if (HT.findfact("data_stmt(" + name + ",_," + to_string(Init_constant) + ",  _,\"const\",i(*))"))
								{
									Up_limit = stoi(returnpar(HT.findandreturn("data_stmt(" + name + ",_," + to_string(Init_constant) + ", _,\"const\",i(*))"), 7));
									if (HT.findfact("data_stmt(" + name + ",_," + to_string(End_val_data) + ",  _,\"const\",i(*))"))
									{
										Low_limit = stoi(returnpar(HT.findandreturn("data_stmt(" + name + ",_," + to_string(End_val_data) + ", _,\"const\",i(*))"), 7));
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
												Decrement_step, Body_first, Body_last, Iterations, &For_loop_entry);
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
}

/* Adds a for_loop fact */
void add_while_loop(string Module, int If_statement, int Condition_statement, int End_of_loop, int Body_first, int Body_last, int* While_loop_entry)
{
	int Last_while_loop;
	if (HT.findfact("last_while_loop_entry(*)"))
	{
		Last_while_loop = stoi(returnpar(HT.findandreturn("last_while_loop_entry(*)"), 1));
		*While_loop_entry = Last_while_loop + 1;
		HT.assertz("while_loop("+to_string(*While_loop_entry)+","+ Module+"," + to_string(If_statement)+"," + to_string(Condition_statement)+"," + to_string(End_of_loop)+"," + to_string(Body_first)+"," + to_string(Body_last)+")");
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

void add_for_loop(string Module_name, int If_entry, int Condition_statement, int End_of_loop, int Header_start, int Increment_instruction, int Increment_variable, int Start_value, int End_value, int Increment_step, int Body_first, int Body_last, int Iterations, int* For_loop_entry)
{
	if (HT.findfact("last_for_loop_entry(*)"))
	{
		int Last_for_loop;
		Last_for_loop = stoi(returnpar(HT.findandreturn("last_for_loop_entry(*)"), 1));
		*For_loop_entry = Last_for_loop + 1;
		// for_loop w/  14 parameters
		HT.assertz("for_loop(" + to_string(*For_loop_entry) + "," + Module_name + "," + to_string(If_entry) + "," + to_string(Condition_statement) + "," + to_string(End_of_loop) + "," + to_string(Header_start) + "," + to_string(Increment_instruction) + "," + to_string(Increment_variable) + "," + to_string(Start_value) + "," + to_string(End_value) + "," + to_string(Increment_step) + "," + to_string(Body_first) + "," + to_string(Body_last) + ","+ to_string(Iterations) +")"); 
		HT.retractall("last_for_loop_entry(*)");
		HT.assertz("last_for_loop_entry(For_loop_entry)");
	}
}

/* Traces back the last operation which targets the variable */
bool trace_back(string Module, int Previous, int Variable, int *Result)
{
	if (HT.findfact("prog_stmt(" + Module + "," + to_string(Previous) + ",_,_,_,_,_,_)") && *Result == 0)
		return false; // if not found return false --> not(prog_stmt(Module, Previous,  _,  _, _,  _,  _,  _))
	else if (HT.findfact("prog_stmt(" + Module + "," + to_string(Previous) + ",_,_,_,_," + to_string(Variable) + ",_)"))
	{
		int Operator, Left, Right;
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
			Next_previous = Previous - 1;
			trace_back(Module, Next_previous, Variable, Result);
		}
	}
	return true;
}

/* Calculate the value of variable on a targeting operation */
void calc_target_var(string Module, int Operator, int Left, int Right, int* Result)
{
	if (HT.findfact("data_stmt(" + Module + ",_," + to_string(Right) + ",_,\"const\",i(*))"))
	{
		int Right_Value, Left_Value;
		Right_Value = stoi(returnpar(HT.findandreturn("data_stmt(" + Module + ",_," + to_string(Right) + ",_,\"const\",i(*))"), 7));
		Left_Value = stoi(returnpar(HT.findandreturn("data_stmt(" + Module + ",_," + to_string(Left) + ",_,\"const\",i(*))"), 7));
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

void generate_hdl_recursive(string Hdlform, string Tool, int Entry)
{
	if (HT.findfact("hierarchy_part(" + to_string(Entry) + ", _, _, \"libpart\",_,_,_)"))
		return;
	else
	{
		HT.assertz("last_for_loop_entry(0)");
		HT.assertz("last_while_loop_entry(0)");
		if (HT.findfact("hierarchy_part(" + to_string(Entry) + ",_,_,\"libpart\",_,_,_)"))
		{
			int Level, ModCount;
			string Module;
			Module = returnpar(HT.findandreturn("hierarchy_part(" + to_string(Entry) + ",_,_,\"libpart\",_,_,_)"), 2);
			Level = stoi(returnpar(HT.findandreturn("hierarchy_part(" + to_string(Entry) + "," + Module + ",_,\"libpart\",_,_,_)"), 3));
			store_package_name(Entry, Module);
			//%write(" HDL code for module : ", Module, " is being created...")
			increment_module_counter();
			if (HT.findfact("module_counter(*)"))
			{
				ModCount = stoi(returnpar(HT.findandreturn("module_counter(_)"), 1));
				code_for_module_created_message(Module, ModCount);
				cout << "started on : " << __DATE__ << ", at: " << __TIME__;
				HT.assertz("current_module(" + Module + ")");
			}
		}
	}
}

void store_package_name(int Entry, string Module)
{
	if (Entry > 1)
		return;
	else
	{
		if (HT.findfact("hierarchy_part(1," + Module + ",_,_,_,_,_)"))
		{
			string Vcomscript1, Vcomscript_content, Logfile_content;
			HT.assertz("package_name(" + Module + ")");
			HT.concat("vcom_", Module, Vcomscript1);
			HT.concat(Vcomscript1, ".bat", Vcomscript_content);

			fstream     File("Vcomscript", ios::out | ios::in | ios::trunc);
			if (File.is_open())
			{
				File << Vcomscript_content << endl;
				File.close();
			}
			else 
				return;
			
			HT.concat(Vcomscript1, ".log", Logfile_content);

			fstream     File2("Logfile", ios::out | ios::in | ios::trunc);
			if (File.is_open())
			{
				File2 << Logfile_content << endl;
				File2.close();
			}
			else
				return;
		}
	}
}

void increment_module_counter()
{
	if (!HT.findfact("module_counter(*)"))
		HT.assertz("module_counter(0)");
	else
	{
		int x, z;
		x = stoi(returnpar(HT.findandreturn("module_counter(*)"), 1));
		z = x + 1;
		HT.retractall("module_counter(" + to_string(x) + ")");
		HT.assertz("module_counter(" + to_string(z) + ")");
	}
}

void code_for_module_created_message(string Module, int ModCount)
{
	if (!HT.findfact("cac_mode(*)"))
		cout << " HDL code for module no : " << to_string(ModCount) << " : " << Module << " is being created...";
	else 
		cout << " CycleAccurateSimulator code for module no: " << to_string(ModCount) << " : " << Module << " is being created...";
}

void generate_hdl_2(string Hdlform, string tool, string Module_name, int Level)
{
	int cosOnumber;
	if (Level > 0)
	{
		if (custom_block(&Module_name))
		{
			if (HT.findfact("global_declarations(*)"))
			{
				int Last_local_entry0, Next_local_entry;
				vector<local_object> Local_list0, Local_list1;
				Last_local_entry0 = last_from_global_declarations(makeInstanceOf(HT.findandreturn("global_declarations(*)")));
				Local_list0 = first_from_global_declarations(makeInstanceOf(HT.findandreturn("global_declarations(*)")));
				Next_local_entry = Last_local_entry0 + 1;
				get_and_append_local(Module_name, Local_list0, Next_local_entry, &Local_list1, &cosOnumber);
				write_custom_block(Module_name, Hdlform, &Local_list1);
			}
		}
	}
}

/* The following is true if the module name is a custom block */
bool custom_block(string* Module_name)
{
	return HT.findfact("combo(_," + *Module_name + ",_)") || HT.findfact("sequence(_," + *Module_name + ",_)");
}

void get_and_append_local(string Module_name, vector<local_object> LList, int Onumber, vector<local_object>* cosLList, int* cosOnumber)
{
	if (*cosOnumber == 0 && !HT.findfact("local_object(" + Module_name + "," + to_string(*cosOnumber) + ",_,_,_,_,_,_,_)"))
		return;
	else if (*cosOnumber > 0 && !HT.findfact("local_object(" + Module_name + "," + to_string(*cosOnumber) + ",_,_,_,_,_,_,_)"))
	{
		*cosOnumber = Onumber - 1;
	}
	else
	{
		add_local_conditionally(Module_name, LList, Onumber, cosLList, cosOnumber);
	}
}

void add_local_conditionally(string Module_name, vector<local_object> In_local_list, int In_local_entry, vector<local_object>* Out_list, int* Last_entry)
{
	string Object_name, Top_package_module, Kind, Ltype, Tkind, Ovalue;
	int Next_local_entry, OrderNo, Osize;
	if (HT.findfact("local_object(" + Module_name + "," + to_string(In_local_entry) + ",_,_,_,_,_,_,_)"))
	{
		Object_name = returnpar(HT.findandreturn("local_object(" + Module_name + "," + to_string(In_local_entry) + ",_,_,_,_,_,_,_)"), 4);
		Kind = returnpar(HT.findandreturn("local_object(" + Module_name + "," + to_string(In_local_entry) + ",_,_,_,_,_,_,_)"), 3);
		OrderNo = stoi(returnpar(HT.findandreturn("local_object(" + Module_name + "," + to_string(In_local_entry) + ",_,_,_,_,_,_,_)"), 5));
		Ltype = returnpar(HT.findandreturn("local_object(" + Module_name + "," + to_string(In_local_entry) + ",_,_,_,_,_,_,_)"), 6);
		Tkind = returnpar(HT.findandreturn("local_object(" + Module_name + "," + to_string(In_local_entry) + ",_,_,_,_,_,_,_)"), 7);
		Osize = stoi(returnpar(HT.findandreturn("local_object(" + Module_name + "," + to_string(In_local_entry) + ",_,_,_,_,_,_,_)"), 8));
		Ovalue = returnpar(HT.findandreturn("local_object(" + Module_name + "," + to_string(In_local_entry) + ",_,_,_,_,_,_,_)"), 9);

		Next_local_entry = In_local_entry + 1;
		if (HT.findfact("hierarchy_part(1,_,0,_,_,_,_)"))
		{
			Top_package_module = returnpar(HT.findandreturn("hierarchy_part(1,_,0,_,_,_,_)"), 2);
			if (Top_package_module != Module_name)
			{
				if (!HT.findfact("local_object(" + Top_package_module + ",_,_," + Object_name + ",_,_,_,_,_)"))
				{
					vector<local_object> Next_local_list{};
					local_object Local1;
					local_object* ptr = dynamic_cast<local_object*>(makeInstanceOf(HT.findandreturn("local_object(" + Module_name + "," + to_string(In_local_entry) + "," + Kind + "," + Object_name + "," + to_string(OrderNo) + "," + Ltype + "," + Tkind + "," + to_string(Osize) + "," + Ovalue + ")")));
					Local1 = *ptr;
					append_local(In_local_list, Local1, &Next_local_list);
					get_and_append_local(Module_name, Next_local_list, Next_local_entry, Out_list, Last_entry);
					return;
				}
			}
			if (HT.findfact("local_object(" + Top_package_module + ",_,_," + Object_name + ",_,_,_,_,_)"))
			{
				if (Top_package_module != Module_name)
				{
					vector<local_object> Next_local_list;
					Next_local_list = In_local_list;
					get_and_append_local(Module_name, Next_local_list, Next_local_entry, Out_list, Last_entry);
					return;
				}
				else
				{
					vector<local_object> Next_local_list{};
					local_object Local;
					local_object* ptr = dynamic_cast<local_object*>(makeInstanceOf(HT.findandreturn("local_object(" + Module_name + "," + to_string(In_local_entry) + "," + Kind + "," + Object_name + "," + to_string(OrderNo) + "," + Ltype + "," + Tkind + "," + to_string(Osize) + "," + Ovalue + ")")));
					Local = *ptr;
					append_local(In_local_list, Local, &Next_local_list);
					get_and_append_local(Module_name, Next_local_list, Next_local_entry, Out_list, Last_entry);
					return;
				}
			}
		}
	}
}

void append_local(vector<local_object> T1, local_object Local1, vector<local_object>* T2)
{
	*T2 = T1;
	T2->push_back(Local1);
}

void write_custom_block(string Module_name, string hdlform, vector<local_object>* local_list)
{
	if (hdlform == "vhdl")
	{
		string Tool, Fname, Hdlform;
		Hdlform = "vhdl";
		Tool = "synergy";
		HT.concat(Module_name, ".vhd", Fname);

		

		fstream     File("Fname", ios::out | ios::in | ios::trunc);
		if (File.is_open())
		{
			File << write_title(Module_name, Hdlform, Tool) << endl;
			File << "--::::: VHDL custom block: " << Module_name << " ::::::--" << endl;
			File << "-----------------------------------------------------" << endl;
			File << write_ieee_packages("vhdl", "synergy") << endl;
			File << write_global_package(Module_name, Hdlform, Tool);
			File.close();
		}

	}
}

string write_title(string Module_name, string Hdlform, string Tool)
{
	stringstream ss{};
	if (Hdlform == "vhdl")
	{
		ss << endl << endl << "---------------------------------------------------------------" << endl << "--::::::::: C CUBED COMPILATION ->  VHDL RTL MODEL ::::::::::--" <<
			endl << endl << "--::::::::: performed on design module: '" << Module_name << "'" <<
			endl << endl << "------------ HDL created on: " << __DATE__ << endl << "------------ HDL created at: " << __TIME__ <<
			endl << endl << "--::: The C-cubed compiler, back-end version: CCC_be_6 ::::--" << endl << "--:::::: Copyright(c) 2007-2020, by Michael F. Dossis  :::::::--" <<
			endl << "----------------------------------------------------------------" << endl << endl;
	}
	else if (Hdlform == "verilog")
	{
		ss << endl << endl << "/*---------------------------------------------------------------*/" << endl << "/*--::::::::: C CUBED COMPILATION ->  Verilog RTL MODEL ::::::::::--*/" <<
			endl << endl << "/*--::::::::: performed on design module: '" << Module_name << "'*/" <<
			endl << endl << "//------------ HDL created on: " << __DATE__ << endl << "//------------ HDL created at: " << __TIME__ <<
			endl << endl << "/*--::: The C-cubed compiler, back-end version: CCC_be_6 ::::--*/" << endl << "/*--:::::: Copyright(c) 2007-2020, by Michael F. Dossis  :::::::--*/" <<
			endl << "/*----------------------------------------------------------------*/" << endl << endl;
	}

	return ss.str();
}

string write_ieee_packages(string str1, string str2)
{
	stringstream ss{};
	if (str1 == "vhdl" && str2 == "synergy")
	{
		ss << "  LIBRARY IEEE; " << endl << "  USE IEEE.std_logic_1164.ALL; " << endl
			<< "  USE IEEE.std_logic_arith.ALL; " << endl << "  USE IEEE.std_logic_signed.ALL; " << endl;
	}
	else if (str1 == "c" && str2 == "gnu")
	{
		ss << "#include <stdio.h>" << endl << "#include <stdlib.h>" << endl << "#include <math.h>" << endl;
	}
	return ss.str();
}

string write_global_package(string Module, string str1, string str2)
{
	stringstream ss;

	if (str1 == "vhdl" && str2 == "synergy")
	{
		if (HT.findfact("hierarchy_part(1,_,0,\"libpart\",_,_,_)"))
		{
			string Package_name;
			Package_name = returnpar(HT.findandreturn("hierarchy_part(1,_,0,\"libpart\",_,_,_)"), 2);
			ss << "  PACKAGE " << Package_name << " IS " << endl;
			ss << print_global_constants(1, "vhdl") << endl;
		}
	}
	return ss.str(); //temporary
}

string  print_global_constants(int DEntry, string HDL)
{
	if (HT.findfact("hierarchy_part(1,_,0,\"libpart\",_,_,_)"))
	{
		string Package_name;
		Package_name = returnpar(HT.findandreturn("hierarchy_part(1,_,0,\"libpart\",_,_,_)"), 2);
		if (HT.findfact("data_stmt(" + Package_name + ",_," + to_string(DEntry) + ",_,_,_)"))
			return ""; //temporary
	}
	else
	{
		print_global_constant(DEntry, HDL);
		return ""; //temporary
	}
}

string print_global_constant(int DEntry, string str)
{
	stringstream ss;
	if (str == "vhdl")
	{
		if (HT.findfact("hierarchy_part(1,_,0,\"libpart\",_,_,_)"))
		{
			int Type_entry, Type_size, Highest_order;
			string Const_name, Package_name, Kind;
			Package_name = returnpar(HT.findandreturn("hierarchy_part(1,_,0,\"libpart\",_,_,_)"), 2);
			if (HT.findfact("data_stmt(" + Package_name + ",_," + to_string(DEntry) + ",1,\"const\",_)"))
			{
				Const_name = returnpar(HT.findandreturn("data_stmt(" + Package_name + ",_," + to_string(DEntry) + ",1,\"const\",_)"), 2);
				cout << "   CONSTANT " << Const_name << " : boolean := ";
				type_value(Package_name, DEntry, "vhdl");
				cout << ";" << endl;
			}
			else if (HT.findfact("data_stmt(" + Package_name + ",_," + to_string(DEntry) + ",_,_,_)"))
			{
				Kind = returnpar(HT.findandreturn("data_stmt(" + Package_name + ",_," + to_string(DEntry) + ",_,_,_)"), 5);
				if (Kind != "const")
					return"";
			}
			else if (HT.findfact("data_stmt(" + Package_name + ",_," + to_string(DEntry) + ",_,\"const\",_)"))
			{
				Const_name = returnpar(HT.findandreturn("data_stmt(" + Package_name + ",_," + to_string(DEntry) + ",_,\"const\",_)"), 2);
				Type_entry = stoi(returnpar(HT.findandreturn("data_stmt(" + Package_name + ",_," + to_string(DEntry) + ",_,\"const\",_)"), 4));
				parent_type_is_integer(Type_entry, &Type_size);
				Highest_order = Type_size - 1;
				ss << "   CONSTANT " << Const_name << " : std_logic_vector(" << Highest_order << " DOWNTO 0) := std_logic_vector(conv_unsigned(";
				type_value(Package_name, DEntry, "vhdl");
				ss << ", " << Type_size << "))" << ";" << endl;
			}
		}

	}
	else if (str == "verilog")
	{

	}
	return ss.str();
}

void parent_type_is_integer(int Type, int* Par_Size)
{
	if (HT.findfact("type_def(2,_,_,_,_,_,_,_,_)"))
	{
		int Parent;
		Parent = stoi(returnpar(HT.findandreturn("type_def(2,_,_,_,_,_,_,_,_)"), 5));
		*Par_Size = stoi(returnpar(HT.findandreturn("type_def(2,_,_,_,_,_,_,_,_)"), 2));
		if (Parent == 0)
			return;
	}
	else if (HT.findfact("type_def(" + to_string(Type) + ",_,_,_,_,_,_,_,_)"))
	{
		int Parent;
		Parent = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Type) + ",_,_,_,_,_,_,_,_)"), 5));
		if (Type != 2 && Parent != 0)
		{
			parent_type_is_integer(Parent, Par_Size);
			return;
		}
	}
}

/* The following is used to print the name of the variable, or the value of the constant */
string type_value(string PModule, int Data_entry, string str)
{
	if (str == "vhdl")
	{
		if (!HT.findfact("data_stmt(" + PModule + ",_," + to_string(Data_entry) + ",_,_,_)"))
		{
			return "";
		}
		else if (!HT.findfact("data_stmt(" + PModule + ",_," + to_string(Data_entry) + ",_,\"var\",_)"))
		{
			string Var_name;
			Var_name = returnpar(HT.findandreturn("data_stmt(" + PModule + ",_," + to_string(Data_entry) + ",_,\"var\",_)"), 2);
			return "CONV_INTEGER(" + Var_name + ")";
		}
		else if (!HT.findfact("data_stmt(" + PModule + ",_," + to_string(Data_entry) + ",_,\"const\",i(*))"))
			return returnpar(HT.findandreturn("data_stmt(" + PModule + ",_," + to_string(Data_entry) + ",_,\"const\",i(*))"), 7);
		else if (!HT.findfact("data_stmt(" + PModule + ",_," + to_string(Data_entry) + ",_,\"const\",bol(*))"))
		{
			string cond;
			cond = returnpar(HT.findandreturn("data_stmt(" + PModule + ",_," + to_string(Data_entry) + ",_,\"const\",bol(*))"), 7);
			if (cond == "0")
				return "false";
			else
				return "true";
		}
		else if (!HT.findfact("data_stmt(" + PModule + ",_," + to_string(Data_entry) + ",_,\"par_in\",_)"))
		{
			string Var_name;
			Var_name = returnpar(HT.findandreturn("data_stmt(" + PModule + ",_," + to_string(Data_entry) + ",_,\"par_in\",_)"), 2);
			return "CONV_INTEGER(" + Var_name + ")";
		}
	}
	else if (str == "verilog")
	{
		if (!HT.findfact("data_stmt(" + PModule + ",_," + to_string(Data_entry) + ",_,\"var\",_)"))
		{
			string Var_name;
			Var_name = returnpar(HT.findandreturn("data_stmt(" + PModule + ",_," + to_string(Data_entry) + ",_,\"var\",_)"), 2);
			return Var_name;
		}
		else if (!HT.findfact("data_stmt(" + PModule + ",_," + to_string(Data_entry) + ",_,\"const\",i(*))"))
			return returnpar(HT.findandreturn("data_stmt(" + PModule + ",_," + to_string(Data_entry) + ",_,\"const\",i(*))"), 7);
		else if (!HT.findfact("data_stmt(" + PModule + ",_," + to_string(Data_entry) + ",_,\"const\",bol(*))"))
		{
			string cond;
			cond = returnpar(HT.findandreturn("data_stmt(" + PModule + ",_," + to_string(Data_entry) + ",_,\"const\",bol(*))"), 7);
			if (cond == "0")
				return "false";
			else
				return "true";
		}
		else if (!HT.findfact("data_stmt(" + PModule + ",_," + to_string(Data_entry) + ",_,\"par_in\",_)"))
		{
			string Var_name;
			Var_name = returnpar(HT.findandreturn("data_stmt(" + PModule + ",_," + to_string(Data_entry) + ",_,\"par_in\",_)"), 2);
			return Var_name;
		}
	}
	else if (str == "c")
	{
		if (!HT.findfact("data_stmt(" + PModule + ",_," + to_string(Data_entry) + ",_,\"var\",_)"))
		{
			string Var_name;
			Var_name = returnpar(HT.findandreturn("data_stmt(" + PModule + ",_," + to_string(Data_entry) + ",_,\"var\",_)"), 2);
			return Var_name;
		}
		else if (!HT.findfact("data_stmt(" + PModule + ",_," + to_string(Data_entry) + ",_,\"const\",i(*))"))
			return returnpar(HT.findandreturn("data_stmt(" + PModule + ",_," + to_string(Data_entry) + ",_,\"const\",i(*))"), 7);
		else if (!HT.findfact("data_stmt(" + PModule + ",_," + to_string(Data_entry) + ",_,\"const\",bol(*))"))
		{
			string cond;
			cond = returnpar(HT.findandreturn("data_stmt(" + PModule + ",_," + to_string(Data_entry) + ",_,\"const\",bol(*)"), 7);
			if (cond == "0")
				return "false";
			else
				return "true";
		}
		else if (!HT.findfact("data_stmt(" + PModule + ",_," + to_string(Data_entry) + ",_,\"par_in\",_)"))
		{
			string Var_name;
			Var_name = returnpar(HT.findandreturn("data_stmt(" + PModule + ",_," + to_string(Data_entry) + ",_,\"par_in\",_)"), 2);
			return Var_name;
		}
		else if (!HT.findfact("data_stmt(" + PModule + ",_," + to_string(Data_entry) + ",_,\"par_inout\",_)"))
		{
			string Var_name;
			Var_name = returnpar(HT.findandreturn("data_stmt(" + PModule + ",_," + to_string(Data_entry) + ",_,\"par_inout\",_)"), 2);
			return Var_name;
		}
		if (!HT.findfact("data_stmt(" + PModule + ",_," + to_string(Data_entry) + ",_,_,_)"))
		{
			if (!HT.findfact("special_dt(" + PModule + "," + to_string(Data_entry) + ",_,_,_,\"const\",i(*))"))
			{
				return returnpar(HT.findandreturn("special_dt(" + PModule + "," + to_string(Data_entry) + ",_,_,_,\"const\",i(*))"), 8);
			}
		}
	}
}
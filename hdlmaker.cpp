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

//feedback and typing predicates
void itf_not_found_message();
void itf_found_message();
void report_global_constraint();
void code_for_module_created_message(string Module, int ModCount);
void write_custom_block(string Module_name, string hdlform, vector<local_object> Local_list);
string write_title(string Module_name, string Hdlform, string Tool);
string write_ieee_packages(string str1, string str2);
string write_global_package(string Module, string str1, string str2);
string print_global_constants(int DEntry, string HDL);
string print_global_constant(int DEntry, string str);
string type_value(string PModule, int Data_entry, string str);
string print_array_types(int Entry, string HDL);
string print_array_type(int Entry, string str);
string print_records_fields_declarations(int First_entry, int Dimmension, int Current_entry, string hdlform);
string print_records_fields_declarations_core(int First_entry, int Dimmension, int Current_entry, int* Next_entry, string str);
string print_custom_functions_title(string Package_name, string str);
string write_boolean_default_procedures_headers(string str);
string write_boolean_default_procedures_for_type(int Entry, int Level, string str);
string write_boolean_default_procedures_for_type_core(int Entry, int Level, string str);
string print_custom_function_headers(string Module, int Entry, string EndSt);
string print_custom_function_header(int int1, string PModule, string VarSignal, string EndStr, string str, int* int2);
string write_cus_function_header_params(string PModule, int Entry, string VarSignal, string HDL);
string write_cus_function_header_param(int Entry, string PModule, string Data_name, int Type, string InOutType, string str1, string str2);
string write_inout_type(string str1, string str2);
string write_cus_func_param_type(string PModule, string str, int int1, string Separator);
string write_size(int int1, string str1, string str2, string str3, int int2);
string write_verilog_dimmension_component_recursively(int Comp_type);
string continue_verilog_dimmension_component(int Comp_type);
string print_verilog_array_decl(int Type_number, string Local_name, string Separator);
string write_comma_cond(int Entry);
string write_c_dimmension_component_recursively(int Comp_type);
string continue_c_dimmension_component(int Comp_type);
string write_separator_cond(string Separator, string PModule, int Entry, string HDL, int Type);
string print_custom_functions_cond(string Module, string HDL);
string print_custom_functions(string Module, int Entry, string HDL);
string print_custom_function(int int1, string Module, string PModule, string HDL);
string print_local_variables(string PModule, int Dentry, string HDL, int ExcludingEntry);
string print_local_variable_cond_cond(string PModule,int Dentry, string HDL, int ExcludingEntry);
string print_local_variable_cond(string PModule, int Dentry, string HDL);
string write_constant_type(int Type);
string write_constant_value(int Type, string be, int af, string HDL);
string print_custom_body(string Module, string PModule, int Oentry, string Intend, string HDL);
string print_custom_statement(string Module, string PModule, int var3, string Intend, string* Next_intend, string Lang);
string type_op_triple(string Module_name, string Res_name, string Left_name, string Right_name, string Res_kind, string Left_kind, string Right_kind, string Op_string, string Assignment_string, string Hdl);
string writevhdl(string HDL, string Module_name, string Dname, string Kind);
string write_hdl_dep_operator_symbol(string Symbol, string HDL);
string print_possible_return(string PModule, string ResData, string RightData, string Assignment_string, string HDL, int* int1);
string write_mod_rem_operator(string HDL, string Symbol);
string print_custom_record_index_parameters(string Module, string Module_name, vector<int> Rec_list, string Kind);
string print_custom_record_index_parameter(string PModule, int Parameter, string Kind);
string print_custom_record_index_comma_cond(vector<int> Rec_list, string Kind);
string print_custom_array_index_parameters(string Module_name, vector<int> Par_list, string HDL);
string print_custom_array_index_parameter(string PModule, int Parameter, string HDL);
string print_while_loop_tail_cond(string PModule, int Cond_stmt, int Condition_end, int End_of_loop, string Intend, string* Out_intend, string Lang);
string write_end_of_loop(string Next_intend, string Lang);
string print_after_return0(int var1, string var2, string var3);
string print_after_return1(int var1, string var2);
string print_after_return2(int var1, string var2);
string print_after_return3(int var1, string var2, string var3);
string write_c_star(string Kind);
string print_after_return4(int var1, string var2, vector<int> var3);
string print_after_return5(int var1, string var2, vector<int> var3);
string print_after_return6(int var1, string var2, string var3);
string print_after_return7(int var1, string var2, string var3, vector<int> var4);
string print_after_return8(int var1, string var2, string var3, vector<int> var4, string var5);
string lookahead_prog_entry(string PModule, int Oentry, string In_intend, string* Out_intend);
string write_nested_cond_fact(string str);
string print_custom_function_cond(string Module, string Module1, int Entry, string HDL);
string write_boolean_default_procedures_bodies(string HDL);
string print_range_types_in_c(int Entry, string HDL);
string print_range_type_in_c(int Type_entry);
string print_record_types_in_c(int Type_entry, string HDL);
string print_record_type_in_c(int Type_entry, string HDL);
string print_c_array_types(int In_entry);
string print_c_array_type(int Type_entry);
string write_custom_block_interface(string Module_name, string Entity_name, string HDL, vector<local_object> Local_list);
string write_interface_header(string HDL, string str);
string write_io_ports(string Module, int In_entry, string Hdl, string Tool, string Usage);
string write_io_ports_core_cond(local_object Local, string HDL, string Tool, string str);
string write_io_port(local_object Local, string HDL, string tool);
string print_conditional_end_of_statement(int num);
string print_vhdl_par_out_name_cond(string Module_name, string Local_name);
string write_verilog_array_index_registers(string Module_name, string Local_name, int Type_number, int Num_dim, int Comp_num_dim, int In_index);
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
bool parent_type_is_integer(int Type, int* Par_Size);
void print_custom_function_cond_core(string Module, string Module1, int Entry, int* DFC);
void dont_find_call_in_range(int Em1, int EEm1, int Em, int InDFC, int* OutDFC);
void find_child_type(int Type_number, int* Child_type);
void translate_type_in_c(string str1, string* str2);
void language_separator(string str1, string* str2);
bool it_is_io_parameter(string str);
bool custom_block(string Module_name);
bool not_a_for_loop(string PModule, int Operation);
bool not_a_while_loop(string PModule, int Operation);
void conv_kind(string PModule, string Data, string* Kind);
bool is_relational_op(string str);
bool mod_or_rem_operator(string Op_symbol);
void push_cond_end(string PModule, int Entry, string Kind);
void pop_cond_end(string PModule);
void is_it_the_last_io(string Module_name, string HDL, int Current_entry, int* Last);
void replace_chars_in_string(string Local_name, string Ch1, string Ch2, string* NewName);

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
bool searchstring(string SourceStr, string SearchStr, size_t* Pos)
{
	*Pos = SourceStr.find(SearchStr, 0);
	if (*Pos != SourceStr.npos)
		return true;
	return false;
}
void str_len(string StringArg, size_t* Lenght)
{
	*Lenght = StringArg.length();
}
void str_len(string* StringArg, size_t Lenght)
{
	for (int i = 0; i < Lenght; i++)
		*StringArg += " ";
}
bool str_len(string StringArg, size_t Lenght)
{
	return Lenght == StringArg.length();
}
void substring(string Str_in, size_t Pos, size_t Len, string* Str_out)
{
	*Str_out = Str_in.substr(Pos, Len);
}
/////////////////////

//determ i=input o=output
//in language add 16 on page search
//ITF_lib "as76das" "asdafgg125hdsg" "hdf12sbshd"
//D:\VSprojects\repos\ITF_lib
int main(int argc, char* argv[])
{
	int ch = 0;
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
	break;
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
		//string asd = "abcdefg";
		//if (asd.substr(0, 3) == "abc")
		//	cout << "ok" << endl;

		//cout << returnpar("local_object(\"pythagoras_test\",1,\"constant\",\"s_base\",1,\"integer\",\"standard\",32,i(0))", 9);

		string str;
		if (HT.concat("asd", "fgh", "asdfgh"))
			cout << "same" << endl;
		if (HT.concat(&str, "fgh", "asdfgh"))
			cout << "same 1st*" << endl;
		if (HT.concat("asd", &str, "asdfgh"))
			cout << "same 2nd*" << endl;
		HT.concat("asd", "fgh", &str);
	}
	break;
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

		//// (special_dt) done: makeStringOf, makeInstanceOf, makefactstar, makeInstanceOfSpecFact, matchfactsSpec, matchfactsstar
		
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

		//// (nested_cond_fact) done: makeStringOf, makeInstanceOf, makefactstar, makeInstanceOfSpecFact, matchfactsSpec, matchfactsstar

		//cout << makeStringOf(makeInstanceOf("nested_cond_fact(\"garlic\",[\"asd\",8,\"zxc\"])")) << endl;
		//cout << makeStringOf(makeInstanceOf("nested_cond_fact(\"garlic\",[\"asd\",8,\"zxc\",\"basd\",9,\"bzxc\"])")) << endl;
		//
		//makefactstar("nested_cond_fact(*)");
		//makefactstar("nested_cond_fact(\"garlic\",*)");
		//makefactstar("nested_cond_fact(\"garlic\",[\"asd\",8,\"zxc\"])");
		//makefactstar("nested_cond_fact(\"garlic\",[\"asd\",8,\"zxc\",\"basd\",8,\"bzxc\"])");
		//
		//makeInstanceOfSpecFact("nested_cond_fact(_,[])");
		//makeInstanceOfSpecFact("nested_cond_fact(\"garlic\",[])");
		//makeInstanceOfSpecFact("nested_cond_fact(_,[\"asd\",8,\"zxc\"])");
		//makeInstanceOfSpecFact("nested_cond_fact(\"garlic\",[\"asd\",8,\"zxc\",\"basd\",8,\"bzxc\"])");
		//
		//factUnderInspection FUI{};
		//FUI = makeInstanceOfSpecFact("nested_cond_fact(_,[\"asd\",8,\"zxc\",\"basd\",8,\"bzxc\"])");
		//cout << matchfactsSpec(makeInstanceOf("nested_cond_fact(\"garlic\",[\"asd\",8,\"zxc\",\"basd\",8,\"bzxc\"])"), & FUI);
		//FUI = makeInstanceOfSpecFact("nested_cond_fact(\"qe\",[\"asd\",8,\"zxc\",\"basd\",8,\"bzxc\"])");
		//cout << matchfactsSpec(makeInstanceOf("nested_cond_fact(\"garlic\",[\"asd\",8,\"zxc\",\"basd\",8,\"bzxc\"])"), & FUI);
		//FUI = makeInstanceOfSpecFact("nested_cond_fact(\"garlic\",[\"asd\",8,\"zxc\",\"basd\",128,\"bzxc\"])");
		//cout << matchfactsSpec(makeInstanceOf("nested_cond_fact(\"garlic\",[\"asd\",8,\"zxc\",\"basd\",8,\"bzxc\"])"), & FUI);
		//FUI = makeInstanceOfSpecFact("nested_cond_fact(\"garlic\",[\"asd\",8,\"zxc\"])");
		//cout << matchfactsSpec(makeInstanceOf("nested_cond_fact(\"garlic\",[\"asd\",8,\"zxc\",\"basd\",8,\"bzxc\"])"), & FUI);
		//
		//factstar FUI{};
		//FUI = makefactstar("nested_cond_fact(\"garlic\",[\"asd\",8,\"zxc\",\"basd\",8,\"bzdaxc\"])");
		//cout << matchfactsstar(makeInstanceOf("nested_cond_fact(\"garlic\",[\"asd\",8,\"zxc\",\"basd\",8,\"bzxc\"])"), &FUI);
		//FUI = makefactstar("nested_cond_fact(\"garlxic\",*)");
		//cout << matchfactsstar(makeInstanceOf("nested_cond_fact(\"garlic\",[\"asd\",8,\"zxc\",\"basd\",8,\"bzxc\"])"), &FUI);
		//FUI = makefactstar("nested_cond_fact(*)");
		//cout << matchfactsstar(makeInstanceOf("nested_cond_fact(\"garlic\",[\"asd\",8,\"zxc\",\"basd\",8,\"bzxc\"])"), &FUI);
		
	}
	break;
	default:
		break;
	}
	return 0;
}

//essential functions
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
		HT.assertz("for_loop(" + to_string(*For_loop_entry) + "," + Module_name + "," + to_string(If_entry) + "," + to_string(Condition_statement) + "," + to_string(End_of_loop) + "," + to_string(Header_start) + "," + to_string(Increment_instruction) + "," + to_string(Increment_variable) + "," + to_string(Start_value) + "," + to_string(End_value) + "," + to_string(Increment_step) + "," + to_string(Body_first) + "," + to_string(Body_last) + ","+ to_string(Iterations) +")"); 
		HT.retractall("last_for_loop_entry(*)");
		HT.assertz("last_for_loop_entry(For_loop_entry)");
	}
}

/* Traces back the last operation which targets the variable */
bool trace_back(string Module, int Previous, int Variable, int *Result)
{
	if (!HT.findfact("prog_stmt(" + Module + "," + to_string(Previous) + ",*)"))
	{
		*Result = 0;
		return false;
	}
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
	if (Entry <= 1)
	{
		if (HT.findfact("hierarchy_part(1," + Module + ",_,_,_,_,_)"))
		{
			string Vcomscript1, Vcomscript_content, Logfile_content;
			HT.assertz("package_name(" + Module + ")");
			HT.concat("vcom_", Module, &Vcomscript1);
			HT.concat(Vcomscript1, ".bat", &Vcomscript_content);

			fstream     File("Vcomscript", ios::out | ios::in | ios::trunc);
			if (File.is_open())
			{
				File << Vcomscript_content << endl;
				File.close();
			}
			else 
				return;
			
			HT.concat(Vcomscript1, ".log", &Logfile_content);

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
				write_custom_block(Module_name, Hdlform, Local_list1);
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
	if ((*cosOnumber == 0 && Onumber == 0) && !HT.findfact("local_object(" + Module_name + "," + to_string(*cosOnumber) + ",*)"))
		return;
	else if (Onumber > 0 && !HT.findfact("local_object(" + Module_name + "," + to_string(*cosOnumber) + ",*)"))
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

void write_custom_block(string Module_name, string hdlform, vector<local_object> Local_list)
{
	if (hdlform == "vhdl")
	{
		string Tool, Fname, Hdlform, Global_package, Entity_name;
		Hdlform = "vhdl";
		Tool = "synergy";
		HT.concat(Module_name, ".vhd", &Fname);		

		fstream     File("Fname", ios::out | ios::in | ios::trunc);
		if (File.is_open())
		{
			File << write_title(Module_name, Hdlform, Tool) << endl;
			File << "--::::: VHDL custom block: " << Module_name << " ::::::--" << endl;
			File << "-----------------------------------------------------" << endl;
			File << write_ieee_packages("vhdl", "synergy") << endl;
			File << write_global_package(Module_name, Hdlform, Tool);
			File << endl << endl;
			File << write_ieee_packages("vhdl", "synergy");
			File << "  LIBRARY WORK; " << endl;
			if (HT.findfact("hierarchy_part(1,_, 0,\"libpart\", _, _, _),"))
			{
				Global_package = returnpar(HT.findandreturn("hierarchy_part(1,_, 0,\"libpart\", _, _, _),"), 2);
				File << "  USE WORK." << Global_package << ".ALL; " << endl << endl;
				HT.concat(Module_name, "_cus_block", &Entity_name);
				File << write_custom_block_interface(Module_name, Entity_name, "vhdl", Local_list) << endl;

			}

			//File.close();
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
			ss << print_array_types(1, "vhdl");
			ss << print_custom_functions_title(Package_name, "vhdl");
			ss << write_boolean_default_procedures_headers("vhdl");
			ss << print_custom_function_headers(Module, 1, ";");
			ss << "  END " << Package_name << ";" << endl << endl;
			ss << "  PACKAGE BODY " << Package_name << " IS " << endl;
			ss << print_custom_functions_cond(Module, "vhdl") << endl;
			ss << write_boolean_default_procedures_bodies("vhdl");
			ss << "  END " << Package_name << ";" << endl << endl;
		}
	}
	else if (str1 == "verilog" && str2 == "synergy")
	{
		if (HT.findfact("hierarchy_part(1,_,0,\"libpart\",_,_,_)"))
		{
			string Package_name;
			Package_name = returnpar(HT.findandreturn("hierarchy_part(1,_,0,\"libpart\",_,_,_)"), 2);
			ss << "/* from ADA package: " << Package_name << " now follow the constants, types and custom functions, if any */ " << endl;
			ss << print_global_constants(1, "verilog") << endl;
			ss << print_custom_functions_title(Package_name, "verilog");
			ss << print_custom_functions_cond(Module, "verilog") << endl;
			ss << endl;
		}
	}
	else if (str1 == "c" && str2 == "gnu")
	{
		if (HT.findfact("hierarchy_part(1,_,0,\"libpart\",_,_,_)"))
		{
			string Package_name;
			Package_name = returnpar(HT.findandreturn("hierarchy_part(1,_,0,\"libpart\",_,_,_)"), 2);
			ss << "/* from ADA package: " << Package_name << " now follow the constants, types and custom functions, if any */ " << endl;
			ss << print_range_types_in_c(1, "c") << endl;
			ss << print_record_types_in_c(1, "c") << endl;
			ss << print_c_array_types(1);
			ss << print_global_constants(1, "c") << endl;
			ss << print_custom_functions_title(Package_name, "verilog");
			ss << print_custom_functions(Module, 1, "c") << endl;
			ss << endl;
		}
	}
	return ss.str();
}

string  print_global_constants(int DEntry, string HDL)
{
	stringstream ss;
	int Next_entry;
	if (HT.findfact("hierarchy_part(1,_,0,\"libpart\",_,_,_)"))
	{
		string Package_name;
		Package_name = returnpar(HT.findandreturn("hierarchy_part(1,_,0,\"libpart\",_,_,_)"), 2);
		if (HT.findfact("data_stmt(" + Package_name + ",_," + to_string(DEntry) + ",_,_,_)"))
			return ss.str();
	}
	else
	{
		ss << print_global_constant(DEntry, HDL);
		Next_entry = DEntry + 1;
		print_global_constants(Next_entry, HDL);
	}
	return ss.str();
}

string print_global_constant(int DEntry, string str)
{
	stringstream ss;
	int Type_entry, Type_size, Highest_order;
	string Const_name, Package_name, Kind, Type_name;
	if (str == "vhdl")
	{
		if (HT.findfact("hierarchy_part(1,_,0,\"libpart\",_,_,_)"))
		{
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
		if (HT.findfact("hierarchy_part(1,_,0,\"libpart\",_,_,_)"))
		{
			Package_name = returnpar(HT.findandreturn("hierarchy_part(1,_,0,\"libpart\",_,_,_)"), 2);

			if (HT.findfact("data_stmt(" + Package_name + ",_," + to_string(DEntry) + ",1,\"const\",_)"))
			{
				Const_name = returnpar(HT.findandreturn("data_stmt(" + Package_name + ",_," + to_string(DEntry) + ",1,\"const\",_)"), 2);
				ss << "   `define " << Const_name << " = ";
				type_value(Package_name, DEntry, "verilog");
				ss << ";" << endl;
			}
			else if (HT.findfact("data_stmt(" + Package_name + ",_," + to_string(DEntry) + ",1,_,_)"))
			{
				Kind = returnpar(HT.findandreturn("data_stmt(" + Package_name + ",_," + to_string(DEntry) + ",1,_,_)"), 5);
				if (Kind != "const")
					ss << "";
			}
			else if (HT.findfact("data_stmt(" + Package_name + ",_," + to_string(DEntry) + ",_,\"const\",_)"))
			{
				Const_name = returnpar(HT.findandreturn("data_stmt(" + Package_name + ",_," + to_string(DEntry) + ",_,\"const\",_)"), 2);
				Type_entry = stoi(returnpar(HT.findandreturn("data_stmt(" + Package_name + ",_," + to_string(DEntry) + ",_,\"const\",_)"), 4));
				parent_type_is_integer(Type_entry, 0);
				ss << "   parameter " << Const_name << " = ";
				type_value(Package_name, DEntry, "verilog");
				ss << ";" << endl;
			}
		}
	}
	else if (str == "c")
	{
		if (HT.findfact("hierarchy_part(1,_,0,\"libpart\",_,_,_)"))
		{
			Package_name = returnpar(HT.findandreturn("hierarchy_part(1,_,0,\"libpart\",_,_,_)"), 2);
			if (HT.findfact("data_stmt(" + Package_name + ",_," + to_string(DEntry) + ",_,\"const\",_)"))
			{
				Const_name = returnpar(HT.findandreturn("data_stmt(" + Package_name + ",_," + to_string(DEntry) + ",_,\"const\",_)"), 2);
				Type_entry = stoi(returnpar(HT.findandreturn("data_stmt(" + Package_name + ",_," + to_string(DEntry) + ",_,\"const\",_)"), 4));
				parent_type_is_integer(Type_entry, 0);
				if (HT.findfact("type_def(Type_entry,_,_,_,_,\"single_t\",_,_,_)"))
				{
					Type_name = stoi(returnpar(HT.findandreturn("type_def(Type_entry,_,_,_,_,\"single_t\",_,_,_)"), 2));

					ss << "const " << Type_name << " " << Const_name << " = ";
					type_value(Package_name, DEntry, "verilog");
					ss << ";" << endl;
				}
				else if (HT.findfact("data_stmt(" + Package_name + ",_," + to_string(DEntry) + ",1,\"const\",_)"))
				{
					Const_name = returnpar(HT.findandreturn("data_stmt(" + Package_name + ",_," + to_string(DEntry) + ",1,\"const\",_)"), 2);
					ss << "const bool " << Const_name << " = ";
					type_value(Package_name, DEntry, "verilog");
					ss << ";" << endl;
				}
				else if (HT.findfact("data_stmt(" + Package_name + ",_," + to_string(DEntry) + ",1,_,_)"))
				{
					Kind = returnpar(HT.findandreturn("data_stmt(" + Package_name + ",_," + to_string(DEntry) + ",1,_,_)"), 5);
					if (Kind != "const")
						ss << "";
				}
			}
		}
	}
	return ss.str();
}

bool parent_type_is_integer(int Type, int* Par_Size)
{
	if (Type == 2)
	{
		if (HT.findfact("type_def(2,_,_,_,_,_,_,_,_)"))
		{
			int Parent;
			Parent = stoi(returnpar(HT.findandreturn("type_def(2,_,_,_,_,_,_,_,_)"), 5));
			if (Parent == 0)
			{
				*Par_Size = stoi(returnpar(HT.findandreturn("type_def(2,_,_,_,_,_,_,_,_)"), 3));
				return true;
			}
		}
	}
	else if (HT.findfact("type_def(" + to_string(Type) + ",_,_,_,_,_,_,_,_)"))
	{
		int Parent;
		Parent = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Type) + ",_,_,_,_,_,_,_,_)"), 5));
		if (Type != 2 && Parent != 0)
		{
			parent_type_is_integer(Parent, Par_Size);
		}
	}
	return false;
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
	return "ERROR function: type_value the third parameter was not vhdl or verilog or c";
}

string print_array_types(int Entry, string HDL)
{
	stringstream ss;
	int Next_entry;
	if (!HT.findfact("type_def(" + to_string(Entry) + ",*)"))
	{
		ss << "";
	}
	else
	{
		ss << print_array_type(Entry, HDL);
		Next_entry = Entry + 1;
		ss << print_array_types(Next_entry, HDL);
	}
	return ss.str();
}

/**------ From 6/12/05 print_array_types prints records as well ------**/
/*-- before 29/4/2015 this predicate was used for VHDL types only
	 after (inclusive) 29/4/2015, the C cycle-accurate simulator case
	 was added as well --*/
string print_array_type(int Entry, string str)
{
	stringstream ss;
	if (!HT.findfact("type_def(" + to_string(Entry) + ",*)"))
	{
		return ss.str();
	}
	else
	{
		string Type_name, Comp_name, Comp_kind, Parent_kind, Array_name, Just_field_type_name, Type_built, Type_kind;
		int Dimmension, First_comp_type_entry, First_index, Comp_type, Last_index, Comp_size, Comp_msb, Comp_dim, Parent_type, Array_size,
			Parent_Type_name;
		if (str == "vhdl")
		{
			if (HT.findfact("type_def(" + to_string(Entry) + ",_,_,\"user\",_,\"record_t\",_,_,_)"))
			{
				Type_name = returnpar(HT.findandreturn("type_def(" + to_string(Entry) + ",_,_,\"user\",_,\"record_t\",_,_,_)"), 2);
				Dimmension = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Entry) + ",_,_,\"user\",_,\"record_t\",_,_,_)"), 8));
				First_comp_type_entry = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Entry) + ",_,_,\"user\",_,\"record_t\",_,_,_)"), 9));
				ss << "   TYPE " << Type_name << " IS RECORD " << endl;
				if (First_comp_type_entry > 1)
				{
					print_records_fields_declarations(First_comp_type_entry, Dimmension, First_comp_type_entry, "vhdl");
					ss << "   END RECORD; " << endl << endl;

				}
			}
			else if (HT.findfact("type_def(" + to_string(Entry) + ",_,_,\"user\",0,\"vectorarray_t\",_,_,_)"))
			{
				Type_name = returnpar(HT.findandreturn("type_def(" + to_string(Entry) + ",_,_,\"user\",_,\"vectorarray_t\",_,_,_)"), 2);
				First_index = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Entry) + ",_,_,\"user\",_,\"vectorarray_t\",_,_,_)"), 7));
				Dimmension = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Entry) + ",_,_,\"user\",_,\"vectorarray_t\",_,_,_)"), 8));
				Comp_type = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Entry) + ",_,_,\"user\",_,\"vectorarray_t\",_,_,_)"), 9));
				Last_index = First_index + Dimmension - 1;
				{
					if (Comp_type > 1)
					{
						if (HT.findfact("type_def(" + to_string(Comp_type) + ",*)"))
						{
							Comp_name = returnpar(HT.findandreturn("type_def(" + to_string(Comp_type) + ",*)"), 2);
							Comp_size = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Comp_type) + ",*)"), 3));
							Comp_kind = returnpar(HT.findandreturn("type_def(" + to_string(Comp_type) + ",*)"), 6);
							Comp_dim = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Comp_type) + ",*)"), 8));
							if (Comp_kind != "single_t")
							{
								if (Comp_dim > 0)
								{
									if (Comp_size > 1)
									{
										ss << "   TYPE " << Type_name << " IS ARRAY (" << First_index << " TO " << Last_index << ") OF " << Comp_name << ";" << endl << endl;
									}
								}
							}
						}
					}
				}
			}
			else if (HT.findfact("type_def(" + to_string(Entry) + ",_,_,\"user\",_,\"vectorarray_t\",_,_,2)"))
			{
				Type_name = returnpar(HT.findandreturn("type_def(" + to_string(Entry) + ",_,_,\"user\",_,\"vectorarray_t\",_,_,2)"), 2);
				Parent_type = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Entry) + ",_,_,\"user\",_,\"vectorarray_t\",_,_,2)"), 5));
				First_index = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Entry) + ",_,_,\"user\",_,\"vectorarray_t\",_,_,2)"), 7));
				Dimmension = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Entry) + ",_,_,\"user\",_,\"vectorarray_t\",_,_,2)"), 8));
				if (HT.findfact("type_def(" + to_string(Parent_type) + ",*)"))
				{
					Parent_kind = returnpar(HT.findandreturn("type_def(" + to_string(Parent_type) + ",*)"), 6);
					if (Parent_kind != "record_t")
					{
						Last_index = First_index + Dimmension - 1;
						ss << "   TYPE " << Type_name << " IS ARRAY (" << First_index << " TO " << Last_index << ") OF std_logic_vector(31 DOWNTO 0) ;" << endl << endl;
					}
				}
			}
			else if (HT.findfact("type_def(" + to_string(Entry) + ",_,_,\"user\",_,\"vectorarray_t\",_,_,1)"))
			{
				Type_name = returnpar(HT.findandreturn("type_def(" + to_string(Entry) + ",_,_,\"user\",_,\"vectorarray_t\",_,_,1)"), 2);
				First_index = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Entry) + ",_,_,\"user\",_,\"vectorarray_t\",_,_,1)"), 7));
				Dimmension = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Entry) + ",_,_,\"user\",_,\"vectorarray_t\",_,_,1)"), 8));
				Last_index = First_index + Dimmension - 1;
				if (HT.findfact("type_def(1,*)"))
				{
					ss << "   TYPE " << Type_name << " IS ARRAY (" << First_index << " TO " << Last_index << ") OF boolean;" << endl << endl;
				}
			}
			if (HT.findfact("type_def(" + to_string(Entry) + ",_,_,\"user\",_,\"vectorarray_t\",_,_,_)"))
			{
				Type_name = returnpar(HT.findandreturn("type_def(" + to_string(Entry) + ",_,_,\"user\",_,\"vectorarray_t\",_,_,_)"), 2);
				First_index = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Entry) + ",_,_,\"user\",_,\"vectorarray_t\",_,_,_)"), 7));
				Dimmension = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Entry) + ",_,_,\"user\",_,\"vectorarray_t\",_,_,_)"), 8));
				Comp_type = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Entry) + ",_,_,\"user\",_,\"vectorarray_t\",_,_,_)"), 9));
				Last_index = First_index + Dimmension - 1;
				if (Comp_type > 1)
				{
					if (HT.findfact("type_def(" + to_string(Comp_type) + ",_,_,_,_,\"single_t\",_,_,_)"))
					{
						Comp_size = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Comp_type) + ",_,_,_,_,\"single_t\",_,_,_)"), 3));
						if (Comp_size > 1)
						{
							Comp_msb = Comp_size - 1;
							ss << "   TYPE " << Type_name << " IS ARRAY (" << First_index << " TO " << Last_index << ") OF std_logic_vector(" << Comp_msb << " DOWNTO 0);" << endl << endl;
						}
					}
				}
			}
			if (HT.findfact("type_def(" + to_string(Entry) + ",_,_,\"user\",_,\"vectorarray_t\",_,_,_)"))
			{
				Type_name = returnpar(HT.findandreturn("type_def(" + to_string(Entry) + ",_,_,\"user\",_,\"vectorarray_t\",_,_,_)"), 2);
				Parent_type = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Entry) + ",_,_,\"user\",_,\"vectorarray_t\",_,_,_)"), 5));
				First_index = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Entry) + ",_,_,\"user\",_,\"vectorarray_t\",_,_,_)"), 7));
				Dimmension = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Entry) + ",_,_,\"user\",_,\"vectorarray_t\",_,_,_)"), 8));
				Comp_type = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Entry) + ",_,_,\"user\",_,\"vectorarray_t\",_,_,_)"), 9));
				if (HT.findfact("type_def(" + to_string(Parent_type) + ",*)"))
				{
					Parent_kind = returnpar(HT.findandreturn("type_def(" + to_string(Parent_type) + ",*)"), 6);
					if (Parent_kind != "record_t")
					{
						Last_index = First_index + Dimmension - 1;
						if (Comp_type > 1)
						{
							if (HT.findfact("type_def(" + to_string(Comp_type) + ",*)"))
							{
								Comp_name = returnpar(HT.findandreturn("type_def(" + to_string(Comp_type) + ",*)"), 2);
								Comp_size = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Comp_type) + ",*)"), 3));
								Comp_kind = returnpar(HT.findandreturn("type_def(" + to_string(Comp_type) + ",*)"), 6);
								Comp_dim = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Comp_type) + ",*)"), 8));
								if (Comp_kind != "single_t")
								{
									if (Comp_dim > 0)
									{
										if (Comp_size > 1)
										{
											ss << "   TYPE " << Type_name << " IS ARRAY (" << First_index << " TO " << Last_index << ") OF " << Comp_name << ";" << endl << endl;
										}
									}
								}
							}
						}
					}
				}
			}
			if (HT.findfact("type_def(" + to_string(Entry) + ",_,_,\"user\",_,\"vectorarray_t\",_,_,_)"))
			{
				Type_name = returnpar(HT.findandreturn("type_def(" + to_string(Entry) + ",_,_,\"user\",_,\"vectorarray_t\",_,_,_)"), 2);
				Comp_size = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Entry) + ",_,_,\"user\",_,\"vectorarray_t\",_,_,_)"), 3));
				Parent_type = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Entry) + ",_,_,\"user\",_,\"vectorarray_t\",_,_,_)"), 5));
				First_index = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Entry) + ",_,_,\"user\",_,\"vectorarray_t\",_,_,_)"), 7));
				Dimmension = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Entry) + ",_,_,\"user\",_,\"vectorarray_t\",_,_,_)"), 8));
				Comp_type = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Entry) + ",_,_,\"user\",_,\"vectorarray_t\",_,_,_)"), 9));
				Last_index = First_index + Dimmension - 1;
				if (Comp_type > 1)
				{
					if (HT.findfact("type_def(" + to_string(Comp_type) + ",_,_,_,_,_,_,_,2)"))
					{
						Array_name = returnpar(HT.findandreturn("type_def(" + to_string(Comp_type) + ",_,_,_,_,_,_,_,2)"), 2);
						Array_size = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Comp_type) + ",_,_,_,_,_,_,_,2)"), 3));
						Comp_kind = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Comp_type) + ",_,_,_,_,_,_,_,2)"), 6));
						Comp_dim = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Comp_type) + ",_,_,_,_,_,_,_,2)"), 8));
						if (Comp_kind != "single_t")
						{
							if (HT.findfact("type_def(" + to_string(Parent_type) + ",_,_,\"user\",_,\"record_t\",_,_,_)"))
							{
								Parent_Type_name = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Parent_type) + ",_,_,\"user\",_,\"record_t\",_,_,_)"), 2));
								if (Comp_dim > 0)
								{
									if (Comp_size > 1)
									{
										if(HT.concat(".", &Just_field_type_name, Type_name))
											ss << "   TYPE " << Parent_Type_name << "_" << Just_field_type_name << " IS ARRAY (" << First_index << " TO " << Last_index << ") OF std_logic_vector(31 DOWNTO 0) ;" << endl << endl;
									}
								}
							}
						}
					}
				}
			}
			if (HT.findfact("type_def(" + to_string(Entry) + ",_,_,\"user\",_,\"vectorarray_t\",_,_,_)"))
			{
				Type_name = returnpar(HT.findandreturn("type_def(" + to_string(Entry) + ",_,_,\"user\",_,\"vectorarray_t\",_,_,_)"), 2);
				First_index = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Entry) + ",_,_,\"user\",_,\"vectorarray_t\",_,_,_)"), 7));
				Dimmension = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Entry) + ",_,_,\"user\",_,\"vectorarray_t\",_,_,_)"), 8));
				Comp_type = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Entry) + ",_,_,\"user\",_,\"vectorarray_t\",_,_,_)"), 9));
				Last_index = First_index + Dimmension - 1;
				if (Comp_type > 1)
				{
					if (HT.findfact("type_def(" + to_string(Comp_type) + ",*)"))
					{
						Comp_size = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Entry) + ",*)"), 3));
						if (Comp_size == 1)
						{
							ss << "   TYPE " << Type_name << " IS ARRAY (" << First_index << " TO " << Last_index << ") OF std_logic;" << endl << endl;
						}
					}
				}
			}
			if (HT.findfact("type_def(" + to_string(Entry) + ",*)"))
			{
				Type_built = returnpar(HT.findandreturn("type_def(" + to_string(Entry) + ",*)"), 4);
				Type_kind = returnpar(HT.findandreturn("type_def(" + to_string(Entry) + ",*)"), 6);
				if (Type_built != "user" || Type_kind != "vectorarray_t" || Type_kind != "record_t")
				{
					ss << "";
				}
			}
		}
	}
	return ss.str();
}

string print_records_fields_declarations(int First_entry, int Dimmension, int Current_entry, string hdlform)
{
	stringstream ss;
	int Next_entry;
	if (Dimmension == Current_entry - First_entry)
		ss << "";
	else
	{
		ss << print_records_fields_declarations_core(First_entry, Dimmension, Current_entry, &Next_entry, hdlform);
		ss << print_records_fields_declarations(First_entry, Dimmension, Next_entry, hdlform);
	}
	return ss.str();
}

string print_records_fields_declarations_core(int First_entry, int Dimmension, int Current_entry, int* Next_entry, string str)
{
	stringstream ss;
	string Type_name, Field_type, Type_kind, Inherent_type_name, Parent_type;
	int Size, MSB_ord, Inherent_type_entry, Comp_type;
	if (str != "c")
	{
		if (Dimmension > Current_entry - First_entry)
		{
			if (HT.findfact("type_def(" + to_string(Current_entry) + ",_,_,_,_,\"single_t\",_,_,_)"))
			{
				Type_name = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Current_entry) + ",_,_,_,_,\"single_t\",_,_,_)"), 2));
				Size = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Current_entry) + ",_,_,_,_,\"single_t\",_,_,_)"), 3));
				MSB_ord = Size - 1;
				if (HT.concat(".", &Field_type, Type_name))
				{
					ss << "    " << Field_type << " : std_logic_vector(" << MSB_ord << " DOWNTO 0);" << endl;
					*Next_entry = Current_entry + 1;
				}
			}
			else if (HT.findfact("type_def(" + to_string(Current_entry) + ",_,_,_,_,\"single_t\",_,_,_)"))
			{
				Type_name = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Current_entry) + ",_,_,_,_,\"single_t\",_,_,_)"), 2));
				Type_kind = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Current_entry) + ",_,_,_,_,\"single_t\",_,_,_)"), 6));
				Inherent_type_entry = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Current_entry) + ",_,_,_,_,\"single_t\",_,_,_)"), 2));
				if (Type_kind != "single_t")
				{
					if (HT.findfact("type_def(" + to_string(Inherent_type_entry) + ",*)"))
					{
						Inherent_type_name = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Inherent_type_entry) + ",*)"), 9));
						if (HT.concat(".", &Field_type, Type_name))
						{
							ss << "    " << Field_type << " : " << Inherent_type_name << ";" << endl;
							*Next_entry = Current_entry + 1;
						}
					}
				}
			}
		}
	}
	else
	{
		if (Dimmension > Current_entry - First_entry)
		{
			if (HT.findfact("type_def(" + to_string(Current_entry) + ",_,_,_,_,\"single_t\",_,_,_)"))
			{
				Type_name = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Current_entry) + ",_,_,_,_,\"single_t\",_,_,_)"), 2));
				if (HT.concat(".", &Field_type, Type_name))
				{
					if (HT.findfact("type_def(_," + Type_name + ",*)"))
					{
						Comp_type = stoi(returnpar(HT.findandreturn("type_def(_," + Type_name + ",*)"), 9));
						if (HT.findfact("type_def(" + to_string(Comp_type) + ",*)"))
						{
							Parent_type = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Comp_type) + ",*)"), 2));
							ss << "    " << Parent_type << " " << Field_type << ";" << endl;
							*Next_entry = Current_entry + 1;
						}
					}
				}
			}
			else if (HT.findfact("type_def(" + to_string(Current_entry) + ",_,_,_,_,_,_,_,_)"))
			{
				Type_name = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Current_entry) + ",_,_,_,_,\"single_t\",_,_,_)"), 2));
				Type_kind = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Current_entry) + ",_,_,_,_,\"single_t\",_,_,_)"), 6));
				Inherent_type_entry = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Current_entry) + ",_,_,_,_,\"single_t\",_,_,_)"), 9));
				if (Type_kind != "single_t")
				{
					if (HT.findfact("type_def(" + to_string(Inherent_type_entry) + ",*)"))
					{
						Inherent_type_name = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Inherent_type_entry) + ",*)"), 2));
						if (HT.concat(".", &Field_type, Type_name))
						{
							ss << "    " << Inherent_type_name << " " << Field_type << " ;" << endl;
							*Next_entry = Current_entry + 1;
						}
					}
				}
			}
		}
	}
	return ss.str();
}

string print_custom_functions_title(string Package_name, string str)
{
	stringstream ss;
	if (!HT.findfact("custom_block(*)"))
		ss << "";
	else
	{
		ss << endl;
		if (str == "vhdl")
			ss << "-- now the custom functions/tasks found in " << Package_name << " --" << endl << endl;
		else if (str == "verilog")
			ss << "/* now the custom functions/tasks found in " << Package_name << " */" << endl << endl;
	}
	return ss.str();
}

/* to print the default boolean<->std_logic conversion routines,
   if there are arrays of booleans types in this ITF */
string write_boolean_default_procedures_headers(string str)
{
	stringstream ss;
	if (str == "vhdl" && HT.findfact("type_def(_,_,_,_,_,_,_,_,1)") && str == "vhdl")
	{
		ss << write_boolean_default_procedures_for_type(1, 0, "vhdl");
		ss << "   FUNCTION bool_vec_to_std_logic(inboolean : IN boolean) RETURN std_logic;" << endl;
		ss << "   FUNCTION std_logic_to_bool_vec(insignal : IN std_logic) RETURN boolean;" << endl;
	}
	return ss.str();
}

/* recursive: to print the default boolean<->std_logic conversion routines,
   if there are arrays of booleans types in this ITF .
   First parameter (Level) = 0 for headers; 1 for bodies */
string write_boolean_default_procedures_for_type(int Entry, int Level, string str)
{
	stringstream ss;
	int Next_entry;
	if (HT.findfact("type_def(" + to_string(Entry) + ", *)") && str == "vhdl")
	{
		ss << write_boolean_default_procedures_for_type_core(Entry, Level, "vhdl");
		Next_entry = Entry + 1;
		write_boolean_default_procedures_for_type(Next_entry, Level, "vhdl");
	}
	return ss.str();
}

/* core of recursion: to print the default boolean<->std_logic conversion routines,
   if there are arrays of booleans types in this ITF .
   First parameter (Level) = 0 for headers; 1 for bodies */
string write_boolean_default_procedures_for_type_core(int Entry, int Level, string str)
{
	stringstream ss;
	string Type_name;
	if (HT.findfact("type_def(" + to_string(Entry) + ",_,_,_,_,\"vectorarray_t\",_,_,1)") && str == "vhdl")
	{
		if (Level == 0)
		{
			Type_name = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Entry) + ",_,_,_,_,\"vectorarray_t\",_,_,1)"), 2));
			ss << "   FUNCTION bool_vec_to_std_logic(invec : IN " << Type_name << ") RETURN std_logic_vector;" << endl;
			ss << "   FUNCTION std_logic_to_bool_vec(invec : IN std_logic_vector) RETURN " << Type_name << ";" << endl;
		}
		else if (Level == 1)
		{
			ss << "   FUNCTION bool_vec_to_std_logic(invec : IN " << Type_name << ") RETURN std_logic_vector IS" << endl;
			ss << "    VARIABLE vector1 : std_logic_vector(invec'HIGH DOWNTO invec'LOW);" << endl;
			ss << "    BEGIN" << endl;
			ss << "      FOR i in invec'LOW TO invec'HIGH LOOP" << endl;
			ss << "        IF invec(i) THEN" << endl;
			ss << "          vector1(i) := '1';" << endl;
			ss << "        ELSE" << endl;
			ss << "          vector1(i) := '0';" << endl;
			ss << "        END IF;" << endl;
			ss << "      END LOOP;" << endl;
			ss << "      RETURN vector1;" << endl;
			ss << "    END bool_vec_to_std_logic;" << endl
				<< endl;
			ss << "   FUNCTION std_logic_to_bool_vec(invec : IN std_logic_vector) RETURN " << Type_name << " IS" << endl;
			ss << "    VARIABLE vector1 : " << Type_name << ";" << endl;
			ss << "    BEGIN" << endl;
			ss << "      FOR i in invec'LOW TO invec'HIGH LOOP" << endl;
			ss << "        IF invec(i) = '1' THEN" << endl;
			ss << "          vector1(i) := true;" << endl;
			ss << "        ELSE" << endl;
			ss << "          vector1(i) := false;" << endl;
			ss << "        END IF;" << endl;
			ss << "      END LOOP;" << endl;
			ss << "      RETURN vector1;" << endl;
			ss << "    END std_logic_to_bool_vec;" << endl
				<< endl;
		}
	}

	return ss.str();
}

/* use:
	print_custom_function_headers(Module, Entry, Ending_string)
   where Module is the top-level custom block, and
   Entry is the next entry to process (start from 2, the first
   after the package's name in the hierarchy table)
*/
string print_custom_function_headers(string Module, int Entry, string EndSt)
{
	stringstream ss;
	int Centry, DFC, Next_entry;
	string PModule;
	if (HT.findfact("combo(*)") && HT.findfact("sequence(*)") && HT.findfact("hierarchy_part(" + to_string(Entry) + ",*)"))
	{
		if (HT.findfact("hierarchy_part(_," + Module + ",_,\"libpart\",_,_,_)"))
		{
			Centry = stoi(returnpar(HT.findandreturn("hierarchy_part(_," + Module + ",_,\"libpart\",_,_,_)"), 1));
			if (Entry <= Centry)
			{
				if (HT.findfact("hierarchy_part(" + to_string(Entry) + ",_,_,\"libpart\",_,_,_)"))
				{
					PModule = returnpar(HT.findandreturn("hierarchy_part(" + to_string(Entry) + ",_,_,\"libpart\",_,_,_)"), 2);
					print_custom_function_cond_core(Module, PModule, Entry, &DFC);
					ss << print_custom_function_header(DFC, PModule, "variable", EndSt, "vhdl", 0);
					Next_entry = Entry + 1;
					ss << print_custom_function_headers(Module, Next_entry, EndSt);
				}
			}
		}
	}
	return ss.str();
}

void print_custom_function_cond_core(string Module, string Module1, int Entry, int* DFC)
{
	if (Module != Module1)
	{
		int Em1, Hier1, Em, Hier, EEm1;
		if (HT.findfact("hierarchy_part(_," + Module1 + ",_,_,_,_,_)"))
		{
			Em1 = stoi(returnpar(HT.findandreturn("hierarchy_part(_," + Module1 + ",_,_,_,_,_)"), 2));
			Hier1 = stoi(returnpar(HT.findandreturn("hierarchy_part(_," + Module1 + ",_,_,_,_,_)"), 5));
			if (HT.findfact("hierarchy_part(_," + Module + ",_,_,_,_,_)"))
			{
				Em = stoi(returnpar(HT.findandreturn("hierarchy_part(_," + Module + ",_,_,_,_,_)"), 2));
				Hier = stoi(returnpar(HT.findandreturn("hierarchy_part(_," + Module + ",_,_,_,_,_)"), 5));
				EEm1 = 1;
				dont_find_call_in_range(Em1, EEm1, Em, 0, DFC);
			}
		}
	}
	else
	{
		*DFC = 1;
	}
}

void dont_find_call_in_range(int Em1, int EEm1, int Em, int InDFC, int* OutDFC)
{
	if (EEm1 <= Em)
	{
		string Module;
		int Nem1;
		if (HT.findfact("hierarchy_part(" + to_string(EEm1) + ",*)"))
		{
			Module = returnpar(HT.findandreturn("hierarchy_part(" + to_string(EEm1) + ",*)"), 2);
			if (HT.findfact("call_stmt(" + Module + ",_," + to_string(Em1) + ",_)"))
			{
				*OutDFC = 1;
			}
			else
			{
				Nem1 = EEm1 + 1;
				dont_find_call_in_range(Em1, Nem1, Em, InDFC, OutDFC);
			}
		}
	}
}

string print_custom_function_header(int int1, string PModule, string VarSignal, string EndStr, string str, int* int2)
{
	stringstream ss;
	if (int1 == 0)
	{
		*int2 = 0;
		return ss.str();
	}
	if (!HT.findfact("custom_block(" + PModule + ")") && str == "vhdl")
	{
		return ss.str();
		*int2 = 0;
	}
	if (str == "vhdl" && int1 == 1)
	{
		if (HT.findfact("hierarchy_part(_," + PModule + ",_,\"libpart\",_,_,_)"))
		{
			if (HT.findfact("custom_block(" + PModule + ")"))
			{
				if (HT.findfact("data_stmt(" + PModule + "," + PModule + ",_,_,_,sym(" + PModule + "))"))
				{
					ss << endl << "   PROCEDURE " << PModule << "(" << endl;
					ss << write_cus_function_header_params(PModule, 1, "variable", "vhdl");
					ss << "                  ) " << EndStr << endl << endl;

				}
				else if (!HT.findfact("data_stmt(" + PModule + "," + PModule + ",_,_,\"par_out\",sym(" + PModule + "))"))
				{
					ss << endl << "   PROCEDURE " << PModule << "(" << endl;
					ss << write_cus_function_header_params(PModule, 1, VarSignal, "vhdl");
					ss << "                 ) " << EndStr << endl << endl;
				}
				*int2 = 0;
			}
		}
	}
	else if (str == "verilog")
	{
		if (!HT.findfact("custom_block(" + PModule + ")"))
		{
			return ss.str();
			*int2 = 0;
		}
		else if (HT.findfact("hierarchy_part(_," + PModule + ",_,\"libpart\",_,_,_)"))
		{
			if (custom_block(PModule))
			{
				if (HT.findfact("data_stmt(" + PModule + "," + PModule + ",_,_,_,sym(" + PModule + "))"))
				{
					ss << endl << "   task " << PModule << "_task(" << endl;
					ss <<write_cus_function_header_params(PModule, 1, "variable", "verilog");
					ss << "                  ) " << EndStr << endl << endl;
				}
				else if (!HT.findfact("data_stmt(" + PModule + "," + PModule + ",_,_,\"par_out\",sym(" + PModule + "))"))
				{
					ss << endl << "   task " << PModule << "_task(" << endl;
					ss << write_cus_function_header_params(PModule, 1, VarSignal, "verilog");
					ss << "                 ) " << EndStr << endl << endl;
				}
				*int2 = 0;
			}
		}
	}
	else if (int1 == 1 && str == "c")
	{
		int Func_type_entry, PModuleDataEntry;
		string Func_type_name, Func_type_kind;
		if (HT.findfact("hierarchy_part(_," + PModule + ",_,\"libpart\",_,_,_)"))
		{
			if (HT.findfact("data_stmt(" + PModule + "," + PModule + ",_,_,_,sym(" + PModule + "))"))
			{
				Func_type_entry = stoi(returnpar(HT.findandreturn("data_stmt(" + PModule + "," + PModule + ",_,_,_,sym(" + PModule + "))"), 4));
				if (parent_type_is_integer(Func_type_entry, 0))
				{
					ss << endl << "  long long int " << PModule << "(" << endl;
					ss << write_cus_function_header_params(PModule, 1, "variable", "c");
					ss << "                  ) " << endl << endl;
				}
				else
				{
					if (HT.findfact("type_def(" + to_string(Func_type_entry) + ",*)"))
					{
						Func_type_name = returnpar(HT.findandreturn("type_def(" + to_string(Func_type_entry) + ",*)"), 2);
						Func_type_kind = returnpar(HT.findandreturn("type_def(" + to_string(Func_type_entry) + ",*)"), 6);
						if (Func_type_kind != "vectorarray_t")
						{
							ss << endl << "  " << Func_type_name << " " << PModule << "(" << endl;
							ss << write_cus_function_header_params(PModule, 1, "variable", "c");
							ss << "                  ) " << endl << endl;
						}
					}
				}
			}
			else if (!HT.findfact("data_stmt(" + PModule + "," + PModule + ",_,_,\"par_out\",sym(" + PModule + "))"))
			{
				ss << endl << "  void " << " " << PModule << "(" << endl;
				ss << write_cus_function_header_params(PModule, 1, VarSignal, "c");
				ss << "                 ) { " << endl << endl;
			}
			*int2 = 0;
		}
		else if (HT.findfact("hierarchy_part(_," + PModule + ",_,\"libpart\",_,_,_)"))
		{
			if (HT.findfact("data_stmt(" + PModule + "," + PModule + ",_,_,_,sym(" + PModule + "))"))
			{
				PModuleDataEntry = stoi(returnpar(HT.findandreturn("data_stmt(" + PModule + "," + PModule + ",_,_,_,sym(" + PModule + "))"), 3));
				Func_type_entry = stoi(returnpar(HT.findandreturn("data_stmt(" + PModule + "," + PModule + ",_,_,_,sym(" + PModule + "))"), 4));
				if (!parent_type_is_integer(Func_type_entry, 0))
				{
					if (HT.findfact("type_def(" + to_string(Func_type_entry) + ",_,_,_,\"vectorarray_t\",_,_,_)"))
					{
						Func_type_name = returnpar(HT.findandreturn("type_def(" + to_string(Func_type_entry) + ",_,_,_,\"vectorarray_t\",_,_,_)"), 2);
						ss << endl << "  " << Func_type_name << " *" << PModule << "(" << endl;
						ss << write_cus_function_header_params(PModule, 1, "variable", "c");
						ss << "                  ) " << endl << endl;
						int ReturnVarEntry;
						if (HT.findfact("prog_stmt(" + PModule + ",_,_,102,0,_," + to_string(PModuleDataEntry) + ",_)"))
						{
							ReturnVarEntry = stoi(returnpar(HT.findandreturn("prog_stmt(" + PModule + ",_,_,102,0,_," + to_string(PModuleDataEntry) + ",_)"), 6));
							*int2 = ReturnVarEntry;
							if (HT.findfact("data_stmt(" + PModule + ",_," + to_string(ReturnVarEntry) + "," + to_string(Func_type_entry) + ",\"var\",_)"))
							{
								string ReturnVarName = returnpar(HT.findandreturn("data_stmt(" + PModule + ",_," + to_string(ReturnVarEntry) + "," + to_string(Func_type_entry) + ",\"var\",_)"), 2);
								ss << "    { static " << Func_type_name << " " << ReturnVarName << ";" << endl;
							}
						}
					}
				}
			}
		}
	}
	return ss.str();
}

string write_cus_function_header_params(string PModule, int Entry, string VarSignal, string HDL)
{
	stringstream ss;
	string InOutType, Data_name, Separator;
	int Type, Next_entry;
	if (HT.findfact("data_stmt(" + PModule + ",_,"+to_string(Entry)+",_,_,_)"))
	{
		InOutType = returnpar(HT.findandreturn("data_stmt(" + PModule + ",_," + to_string(Entry) + ",_,_,_)"), 5);
		if(InOutType != "par_in" && InOutType != "par_inout" && InOutType != "par_out")
			return ss.str();
	}
	if(!HT.findfact("data_stmt(" + PModule + ",_," + to_string(Entry) + ",_,_,_)"))
		return ss.str();

	if (HT.findfact("data_stmt(" + PModule + ",_," + to_string(Entry) + ",_,_,_)"))
	{
		Data_name = returnpar(HT.findandreturn("data_stmt(" + PModule + ",_," + to_string(Entry) + ",_,_,_)"), 2);
		Type = stoi(returnpar(HT.findandreturn("data_stmt(" + PModule + ",_," + to_string(Entry) + ",_,_,_)"), 4));
		InOutType = returnpar(HT.findandreturn("data_stmt(" + PModule + ",_," + to_string(Entry) + ",_,_,_)"), 5);
		ss << write_cus_function_header_param(Entry, PModule, Data_name, Type, InOutType, "variable", HDL);
		language_separator(HDL, &Separator);
		ss << write_separator_cond(Separator, PModule, Entry, HDL, Type);
		Next_entry = Entry + 1;
		ss << write_cus_function_header_params(PModule, Next_entry, VarSignal, HDL);
	}
		
	return ss.str();
}

/* module name, name of the data object, type of the data,
   and par_in/par_out/par_inout */
string write_cus_function_header_param(int Entry, string PModule, string Data_name, int Type, string InOutType, string str1, string str2)
{
	stringstream ss;
	string Func_type_name, Type_kind, Kind, Type_name, CType_name;
	int Object_length, MSB_order, Size, MSB, Dimensions, Child_type, Child_size, Child_upper, LSB, Upper_bound;
	if (str2 == "vhdl")
	{
		if (PModule == Data_name)
		{
			if (HT.findfact("type_def(" + to_string(Type) + ",_,_,_,_,\"vectorarray_t\",_,_,_)"))
			{
				Func_type_name = returnpar(HT.findandreturn("type_def(" + to_string(Type) + ",_,_,_,_,\"vectorarray_t\",_,_,_)"), 2);
				Object_length = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Type) + ",_,_,_,_,\"vectorarray_t\",_,_,_)"), 3));
				ss << "                         " << PModule << "_function : OUT ";
				ss << Func_type_name;
			}
			else if (HT.findfact("type_def(" + to_string(Type) + ",*)"))
			{
				Object_length = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Type) + ",*)"), 3));
				Type_kind = returnpar(HT.findandreturn("type_def(" + to_string(Type) + ",*)"), 6);
				if (Type_kind != "vectorarray_t")
				{
					ss << "                         " << PModule << "_function : OUT ";
					MSB_order = Object_length - 1;
					ss << " std_logic_vector(" << MSB_order << " DOWNTO 0)"; // since this is usually the last parameter of the interface don't print ;
				}
			}

		}
		else if (str1 == "variable")
		{
			if (PModule != Data_name)
			{
				ss << "                         VARIABLE " << Data_name << " : ";
				ss << write_inout_type(InOutType, "vhdl");
				ss << write_cus_func_param_type(PModule, "if", Type, "");
			}
		}
		else if (str1 == "signal")
		{
			if (PModule != Data_name)
			{
				ss << "                         SIGNAL " << Data_name << " : ";
				ss << write_inout_type(InOutType, "vhdl");
				ss << write_cus_func_param_type(PModule, "if", Type, "");
			}
		}
	}
	else if (str2 == "verilog")
	{
		if (PModule == Data_name)
		{
			if (HT.findfact("type_def(" + to_string(Type) + ",*)"))
			{

				Size = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Type) + ",*)"), 3));
				Kind = returnpar(HT.findandreturn("type_def(" + to_string(Type) + ",*)"), 6);
				LSB = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Type) + ",*)"), 7));
				Dimensions = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Type) + ",*)"), 8));
				if (Kind == "single_t")
				{
					if (Size > 1)
					{
						MSB = Size - 1;
						ss << "                         output [" << MSB << ":0] " << PModule << "_function ";
					}
					else if (Size == 1)
					{
						ss << "                         output " << PModule << "_function ";
					}
				}
				else if (Kind == "record_t")
				{
					if (Size > 1)
					{
						Upper_bound = Size - 1;
						ss << "                         ";
						ss << write_inout_type(InOutType, "verilog");
						ss << " [" << Upper_bound << ":0] ";
						ss << PModule << "_function ";
						ss << write_verilog_dimmension_component_recursively(Type);
					}
				}
				else if (Dimensions > 1)
				{
					if (Kind != "record_t")
					{
						if (Size > 1)
						{
							MSB = Size - 1 - LSB;
							find_child_type(Type, &Child_type);
							if (HT.findfact("type_def(" + to_string(Child_type) + ",*)"))
							{
								Child_size = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Child_type) + ",*)"), 3));
								if (Child_size == 1)
								{
									ss << "                         ";
									ss << InOutType << "verilog";
									ss << " [" << LSB << ":" << MSB << "] ";
									ss << PModule << "_function ";
								}
							}
						}
					}
				}
			}
			else if (HT.findfact("type_def(" + to_string(Type) + ",*)"))
			{
				Size = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Type) + ",*)"), 3));
				Kind = returnpar(HT.findandreturn("type_def(" + to_string(Type) + ",*)"), 6);
				Dimensions = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Type) + ",*)"), 8));
				if (Dimensions > 1)
				{
					if (Kind != "record_t")
					{
						if (Size > 1)
						{
							find_child_type(Type, &Child_type);
							if (HT.findfact("type_def(" + to_string(Child_type) + ",*)"))
							{
								Child_size = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Child_type) + ",*)"), 3));
								if (Child_size > 1)
								{
									Child_upper = Child_size - 1;
									ss << "                         ";
									ss << write_inout_type(InOutType, "verilog");
									ss << " [" << Child_upper << ":0] ";
									ss << PModule << "_function ";
									ss << write_verilog_dimmension_component_recursively(Type);
								}
							}
						}
					}
				}
			}
		}
		else
		{
			if (HT.findfact("type_def(" + to_string(Type) + ",*)"))
			{
				Size = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Type) + ",*)"), 3));
				Kind = returnpar(HT.findandreturn("type_def(" + to_string(Type) + ",*)"), 6);
				Dimensions = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Type) + ",*)"), 8));
				if (Size == 1)
				{
					if (PModule != Data_name)
					{
						ss << "                         ";
						ss << write_inout_type(InOutType, "verilog");
						ss << "  ", Data_name;
					}
				}
				if (Dimensions == 0)
				{
					if (Size > 1)
					{
						MSB = Size - 1;
						ss << "                         ";
						ss << write_inout_type(InOutType, "verilog");
						ss << " [" << MSB << ":0] " << Data_name;
					}
				}
				else if (Dimensions > 1)
				{
					if (Kind != "record_t")
					{
						if (Size > 1)
						{
							find_child_type(Type, &Child_type);
							if (HT.findfact("type_def(" + to_string(Child_type) + ",*)"))
							{
								Child_size = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Child_type) + ",*)"), 3));
								if (Child_size > 1)
								{
									ss << "                         ";
									ss << write_inout_type(InOutType, "verilog");
									ss << print_verilog_array_decl(Type, Data_name, "");
									ss << write_verilog_dimmension_component_recursively(Type);
								}
								else if (Child_size == 1)
								{
									ss << "                         ";
									ss << write_inout_type(InOutType, "verilog");
									ss << " ";
									ss << print_verilog_array_decl(Type, Data_name, "");
									ss << write_verilog_dimmension_component_recursively(Type);
								}
							}
						}
					}
				}
				else if (Kind == "record_t")
				{
					if (Size > 1)
					{
						ss << "                         ";
						ss << write_inout_type(InOutType, "verilog");
						ss << print_verilog_array_decl(Type, Data_name, "");
						ss << write_verilog_dimmension_component_recursively(Type);
					}
				}
			}
		}
	}
	if (str2 == "c" && PModule != Data_name)
	{
		if (HT.findfact("type_def(" + to_string(Type) + ",*)"))
		{
			Type_name = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Type) + ",*)"), 2));
			Size = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Type) + ",*)"), 3));
			Kind = returnpar(HT.findandreturn("type_def(" + to_string(Type) + ",*)"), 6);
			Dimensions = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Type) + ",*)"), 8));
			if (Size == 1)
			{
				if (PModule != Data_name)
				{
					translate_type_in_c(Type_name, &CType_name);
					ss << write_comma_cond(Entry);
					ss << "                         " << CType_name << " ";
					ss << write_inout_type(InOutType, "c");
					ss << Data_name;
				}
			}
			else if (Dimensions == 0)
			{
				if (Size > 1)
				{
					translate_type_in_c(Type_name, &CType_name);
					ss << write_comma_cond(Entry);
					ss << "                         " << CType_name << " ";
					ss << write_inout_type(InOutType, "c");
					ss << Data_name;
				}
			}
			else if (Dimensions > 1)
			{
				if (Kind != "record_t")
				{
					if (Size > 1)
					{
						find_child_type(Type, &Child_type);
						if (HT.findfact("type_def(" + to_string(Child_type) + ",*)"))
						{
							Child_size = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Child_type) + ",*)"), 3));
							if (Child_size > 1)
							{
								ss << write_comma_cond(Entry);
								ss << "                         " << Type_name << " ";
								ss << "*" << Data_name << " ";
								ss << write_c_dimmension_component_recursively(Child_type);
							}
							else if (Child_size == 1)
							{
								ss << write_comma_cond(Entry);
								ss << "                         " << Type_name << " ";
								ss << "*" << Data_name << " ";
								ss << write_c_dimmension_component_recursively(Child_type);
							}
						}
					}
				}
				else
				{
					if (Size > 1)
					{
						ss << write_comma_cond(Entry);
						ss << "                         " << Type_name << " ";
						ss << Data_name << " ";
					}
				}
			}
		}
	}
	return ss.str();
}

string write_inout_type(string str1, string str2)
{
	stringstream ss;
	if(str2 == "vhdl")
	{
		if (str1 == "par_in")
			ss << "IN";
		if (str1 == "par_out")
			ss << "OUT";
		if (str1 == "par_inout")
			ss << "INOUT";
	}
	if (str2 == "verilog")
	{
		if (str1 == "par_in")
			ss << "input";
		if (str1 == "par_out")
			ss << "output";
		if (str1 == "par_inout")
			ss << "inout";
	}
	if (str2 == "c")
	{
		if (str1 == "par_in")
			ss << "";
		if (str1 == "par_out")
			ss << "*";
		if (str1 == "par_inout")
			ss << "*";
	}
	return ss.str();
}

/* Depending on the type of the data variable, of the custom function
   it writes ("completes") out the type of the parameter */
string write_cus_func_param_type(string PModule, string str, int int1, string Separator)
{
	stringstream ss;
	int Size, Sizeminusone, Local_size;
	if (int1 == 1)
	{
		ss << " std_logic" << Separator;
	}
	else if (int1 == 2 && str == "if")
	{
		ss << " std_logic_vector" << Separator;
	}
	else if (int1 == 2 && str == "body")
	{
		Size = 32;
		Sizeminusone = Size - 1;
		ss << " std_logic_vector(" << Sizeminusone << " DOWNTO 0) " << Separator;
	}
	else if (int1 == 2)
	{
		Size = 32;
		Sizeminusone = Size - 1;
		ss << " std_logic_vector(" << Sizeminusone << " DOWNTO 0) " << Separator;
	}
	else if (int1 > 1)
	{
		string Type_name;
		if (HT.findfact("type_def(" + to_string(int1) + ",\"positive\",32,\"standard\",2,\"single_t\",0,0,0)"))
		{
			if (!HT.findfact("data_stmt(" + PModule + "," + PModule + ",*)"))
			{
				Size = 32;
				Sizeminusone = Size - 1;
				ss << " std_logic_vector(" << Sizeminusone << " DOWNTO 0) " << Separator;
			}
		}
		else if (str == "if")
		{
			if (HT.findfact("type_def(" + to_string(int1) + ",\"positive\",32,\"standard\",2,\"single_t\",0,0,0)"))
			{
				if (!HT.findfact("data_stmt(" + PModule + "," + PModule + ",*)"))
					ss << " std_logic_vector" << Separator;
			}
		}
		else if (str == "body")
		{
			if (HT.findfact("type_def(" + to_string(int1) + ",\"positive\",32,\"standard\",2,\"single_t\",0,0,0)"))
			{
				if (!HT.findfact("data_stmt(" + PModule + "," + PModule + ",*)"))
				{
					Size = 32;
					Sizeminusone = Size - 1;
					ss << " std_logic_vector(" << Sizeminusone << " DOWNTO 0) " << Separator;
				}
			}
		}
		else if (HT.findfact("type_def(" + to_string(int1) + ",_,_,_,_,\"vectorarray_t\",_,_,_)"))
		{
			Type_name = returnpar(HT.findandreturn("type_def(" + to_string(int1) + ",_,_,_,_,\"vectorarray_t\",_,_,_)"), 2);
			ss << " ";
			ss << Type_name;
			ss << Separator;
		}
		else if (HT.findfact("type_def(" + to_string(int1) + ",_,_,_,_,\"vectorarray_t\",_,_,_)"))
		{
			Local_size = stoi(returnpar(HT.findandreturn("type_def(" + to_string(int1) + ",_,_,_,_,\"record_t\",_,_,_)"), 3));
			ss << " ";
			ss << write_size(Local_size, "std_logic", "vhdl", "synergy", 1);
			ss << Separator;
		}
	}
	else if (str == "body")
	{
		if (HT.findfact("type_def(" + to_string(int1) + ",_,_,_,2,\"single_t\",_,_,_)"))
		{
			Size = stoi(returnpar(HT.findandreturn("type_def(" + to_string(int1) + ",_,_,_,2,\"single_t\",_,_,_)"), 3));
			if (!HT.findfact("data_stmt(" + PModule + "," + PModule + ",*)"))
			{
				if (Size > 1)
				{
					Sizeminusone = Size - 1;
					ss << " std_logic_vector(" << Sizeminusone << " DOWNTO 0) " << Separator;
				}
				else if (Size == 1)
				{
					ss << " std_logic" << Separator;
				}
			}
		}
	}
	else if (str == "if")
	{
		if (HT.findfact("type_def(" + to_string(int1) + ",_,_,_,2,\"single_t\",_,_,_)"))
		{
			Size = stoi(returnpar(HT.findandreturn("type_def(" + to_string(int1) + ",_,_,_,2,\"single_t\",_,_,_)"), 3));
			if (Size > 1)
			{
				ss << " std_logic_vector" << Separator;
			}
			else if (Size == 1)
			{
				ss << " std_logic" << Separator;
			}
		}
	}
	else if (HT.findfact("type_def(" + to_string(int1) + ",_,_,_,2,\"single_t\",_,_,_)"))
	{
		Size = stoi(returnpar(HT.findandreturn("type_def(" + to_string(int1) + ",_,_,_,2,\"single_t\",_,_,_)"), 3));
		if (Size > 1)
		{
			Sizeminusone = Size - 1;
			ss << " std_logic_vector(" << Sizeminusone << " DOWNTO 0) " << Separator;
		}
		else if (Size == 1)
		{
			ss << " std_logic " << Separator;
		}
	}
	else if (!parent_type_is_integer(int1, 0))
	{
		if (HT.findfact("type_def(" + to_string(int1) + ",_,_,_,_,_,_,_,_)"))
		{
			Local_size = stoi(returnpar(HT.findandreturn("type_def(" + to_string(int1) + ",_,_,_,_,_,_,_,_)"), 3));
			ss << " ";
			ss << write_size(Local_size, "std_logic", "vhdl", "synergy", 0);
			ss << " " << Separator;
		}
	}
	return ss.str();
}

/* Now (23/12/11) updated to include both VHDL and Verilog as well 
 example:
	write_size(Length,Kind,HDL,Tool,Is_last_parameter)*/
string write_size(int int1, string str1, string str2, string str3, int int2)
{
	stringstream ss;
	int MSB_order;
	if (str1 == "std_logic" && str3 == "synergy")
	{
		if (str2 == "vhdl")
		{
			if (int1 == 1)
			{
				if (int2 == 0)
					ss << " std_logic;";
				else if (int2 == 1)
					ss << " std_logic";
			}
			else
			{
				MSB_order = int1 - 1;
				if (int2 == 0)
					ss << " std_logic_vector(" << MSB_order << " DOWNTO 0);";
				else if (int2 == 1)
					ss << " std_logic_vector(" << MSB_order << " DOWNTO 0)";
			}
		}
		if (str2 == "verilog" && int1 != 1)
		{
			MSB_order = int1 - 1;
			ss << " [" << MSB_order << ":0]";

		}
	}

	return ss.str();
}

/* This go through the hierarchy of arrays and finds the bottom
   record or single type number. Nevertheless, in Verilog only
   up to 2 dimmensions are allowed ("memories"), e.g.
   reg [31:0] my_memory [0:memsize-1];*/
void find_child_type(int Type_number, int* Child_type)
{
	int First_component;
	if (HT.findfact("type_def(" + to_string(Type_number) + ",_,_,_,_,\"vectorarray_t\",_,_,_)"))
	{
		First_component = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Type_number) + ",_,_,_,_,\"vectorarray_t\",_,_,_)"), 9));
		find_child_type(First_component, Child_type);
	}
	else if (HT.findfact("type_def(" + to_string(Type_number) + ",_,_,_,_,\"record_t\",_,_,_)"))
	{
		*Child_type = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Type_number) + ",_,_,_,_,\"record_t\",_,_,_)"), 1));
	}
	else if (HT.findfact("type_def(" + to_string(Type_number) + ",_,_,_,_,\"single_t\",_,_,_)"))
	{
		*Child_type = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Type_number) + ",_,_,_,_,\"single_t\",_,_,_)"), 1));
	}
}

string write_verilog_dimmension_component_recursively(int Comp_type)
{
	stringstream ss;
	if (Comp_type != 1)
	{
		int Comp_size, Comp_dim, Sec_comp_type, First_index, Last_index, Double_comp_type;
		string Comp_kind, Double_kind;
		if (HT.findfact("type_def(" + to_string(Comp_type) + ",*)"))
		{
			Comp_size = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Comp_type) + ",*)"), 3));
			Comp_kind = returnpar(HT.findandreturn("type_def(" + to_string(Comp_type) + ",*)"), 6);
			First_index = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Comp_type) + ",*)"), 7));
			Comp_dim = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Comp_type) + ",*)"), 8));
			Sec_comp_type = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Comp_type) + ",*)"), 9));
			if (Comp_kind == "vectorarray_t")
			{
				if (Comp_dim > 0)
				{
					if (Comp_size > 1)
					{
						Last_index = First_index + Comp_dim - 1;
						if (Sec_comp_type == 1)
						{
							ss << " [" << Last_index << ":" << First_index << "] ";
						}
						if (Sec_comp_type > 1)
						{
							if (HT.findfact("type_def(" + to_string(Sec_comp_type) + ",_,_,_,_,\"single_t\",_,_,0)"))
							{
								ss << " [" << Last_index << ":" << First_index << "] ";
							}
							else if (HT.findfact("type_def(" + to_string(Sec_comp_type) + ",_,_,_,_,\"record_t\",_,_,_)"))
							{
								Double_comp_type = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Sec_comp_type) + ",_,_,_,_,\"record_t\",_,_,_)"), 9));
								if (HT.findfact("type_def(" + to_string(Double_comp_type) + ",_,_,_,_,\"single_t\",_,_,_)"))
								{
									Double_kind = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Double_comp_type) + ",_,_,_,_,\"single_t\",_,_,_)"), 6));
									if (Double_kind == "single_t")
										ss << " [" << Last_index << ":" << First_index << "] ";
									else
									{
										ss << " [" << Last_index << ":" << First_index << "] ";
										ss << continue_verilog_dimmension_component(Sec_comp_type);
									}
								}
							}
							else if (HT.findfact("type_def(" + to_string(Sec_comp_type) + ",_,_,_,_,\"vectorarray_t\",_,_,_)"))
							{
								ss << " [" << Last_index << ":" << First_index << "] ";
								ss << continue_verilog_dimmension_component(Sec_comp_type);
							}
						}
					}
				}
			}

		}
	}
	return ss.str();
}

string continue_verilog_dimmension_component(int Comp_type)
{
	stringstream ss;
	int Comp_size, Comp_dim, Sec_comp_type, First_index, Last_index, Comp_msb;
	string Comp_kind, Child_kind;
	if (HT.findfact("type_def(" + to_string(Comp_type) + ",*)"))
	{
		Comp_size = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Comp_type) + ",*)"), 3));
		Comp_kind = returnpar(HT.findandreturn("type_def(" + to_string(Comp_type) + ",*)"), 6);
		First_index = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Comp_type) + ",*)"), 7));
		Comp_dim = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Comp_type) + ",*)"), 8));
		Sec_comp_type = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Comp_type) + ",*)"), 9));
		if (Comp_kind == "vectorarray_t")
		{
			if (Comp_dim > 0)
			{
				if (Sec_comp_type > 0)
				{
					if (HT.findfact("type_def(" + to_string(Sec_comp_type) + ",_,_,_,_,_,_,_,_)"))
					{
						Comp_kind = returnpar(HT.findandreturn("type_def(" + to_string(Sec_comp_type) + ",_,_,_,_,_,_,_,_)"), 6);
						Last_index = First_index + Comp_dim - 1;
						if (Child_kind != "single_t")
						{
							ss << " [" << Last_index << ":" << First_index << "] ";
							ss << write_verilog_dimmension_component_recursively(Sec_comp_type);
						}
						return ss.str();
					}
					Last_index = First_index + Comp_dim - 1;
					Sec_comp_type = 1;
					ss << " [" << Last_index << ":" << First_index << "] ";

				}
			}
		}
		else if (Comp_kind == "record_t")
		{
			if (Comp_size > 1)
			{
				if (Comp_dim > 0)
				{
					if (Sec_comp_type > 0)
					{
						Comp_msb = Comp_size - 1;
						ss << " [" << Comp_msb << ":0]";
					}
				}
			}
		}

	}
	return ss.str();
}

// It prints the array declaration, just after the input/output/reg words.
string print_verilog_array_decl(int Type_number, string Local_name, string Separator)
{
	stringstream ss;
	int Child_type, Child_size, Child_upper, Size, Upper;
	string Dotted_field, Just_recname , Underscored_name, Just_field, Underscored_field;
	if (HT.findfact("type_def(" + to_string(Type_number) + ",_,_,\"user\",_,\"vectorarray_t\",_,_,_)"))
	{
		Dotted_field = returnpar(HT.findandreturn("type_def(" + to_string(Type_number) + ",_,_,\"user\",_,\"vectorarray_t\",_,_,_)"), 2);
		find_child_type(Type_number, &Child_type);
		if (HT.findfact("type_def(" + to_string(Child_type) + ",*)"))
		{
			Child_size = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Child_type) + ",*)"), 3));
			// lines 8638 8652 have identical conditions cannot udentify the flow
			if (Child_size > 1)
			{
				Child_upper = Child_size - 1;
				if (HT.concat(".", &Just_field, Dotted_field))
				{
					if (HT.concat(&Just_recname, Dotted_field, Local_name))
					{
						HT.concat("_", Just_field, &Underscored_field);
						HT.concat(Just_recname, Underscored_field, &Underscored_name);
						ss << " [" << Child_upper << ":0] " << Underscored_name << " ";
						ss << write_verilog_dimmension_component_recursively(Type_number);
						ss << Separator;
					}
				}
			}
		}

	}
	else if (HT.findfact("type_def(" + to_string(Type_number) + ",*)"))
	{
		Child_type = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Type_number) + ",*)"), 9));
		if (HT.findfact("type_def(" + to_string(Child_type) + ",*)"))
		{
			Child_size = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Type_number) + ",*)"), 3));
			if (Child_size == 1)
			{
				ss << Separator;
			}
		}
	}
	else if (HT.findfact("type_def(" + to_string(Type_number) + ",_,_,_,_,_,_,_,1)"))
	{
		Size = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Type_number) + ",_,_,_,_,_,_,_,1)"), 3));
		if (Size > 1)
		{
			Upper = Size - 1;
			ss << " [" << Upper << ":0] " << Local_name << Separator;
		}
	}
	return ss.str();
}

void translate_type_in_c(string str1, string* str2)
{
	if (str1 == "boolean")
		*str2 = "long long int";
	if (str1 == "integer")
		*str2 = "long long int";
	if (str1 == "fixed_point")
		*str2 = "long long int";
	if (str1 == "character")
		*str2 = "int";
	if (str1 == "natural")
		*str2 = "long long int";
	if (str1 == "positive")
		*str2 = "long long int";
}

string write_comma_cond(int Entry)
{
	stringstream ss;
	string Separator;
	if (Entry == 1)
		ss << endl;
	else if (Entry > 1)
	{
		ss << " ";
		language_separator("c", &Separator);
		ss << Separator;
		ss << " ";
		ss << endl;
	}
	return ss.str();
}

void  language_separator(string str1, string* str2)
{
	if (str1 == "vhdl")
		*str2 = ";";
	if (str1 == "verilog")
		*str2 = ",";
	if (str1 == "c")
		*str2 = ",";
}

string write_c_dimmension_component_recursively(int Comp_type)
{
	stringstream ss;
	if (Comp_type != 1)
	{
		int Comp_size, Comp_dim, Sec_comp_type;
		string Comp_kind;
		if (HT.findfact("type_def(" + to_string(Comp_type) + ",*)"))
		{
			Comp_size = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Comp_type) + ",*)"), 3));
			Comp_kind = returnpar(HT.findandreturn("type_def(" + to_string(Comp_type) + ",*)"), 6);
			Comp_dim = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Comp_type) + ",*)"), 8));
			Sec_comp_type = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Comp_type) + ",*)"), 9));
			ss << " [" << Comp_dim << "] ";
			ss << continue_c_dimmension_component(Sec_comp_type);
		}
	}
	return ss.str();
}

string continue_c_dimmension_component(int Comp_type)
{
	stringstream ss;
	int Comp_size, Comp_dim, Sec_comp_type;
	string Comp_kind;
	if (HT.findfact("type_def(" + to_string(Comp_type) + ",*)"))
	{
		Comp_size = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Comp_type) + ",*)"), 3));
		Comp_kind = returnpar(HT.findandreturn("type_def(" + to_string(Comp_type) + ",*)"), 6);
		Comp_dim = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Comp_type) + ",*)"), 8));
		Sec_comp_type = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Comp_type) + ",*)"), 9));
		if (Comp_kind == "vectorarray_t")
		{
			if (Comp_dim > 0)
			{
				if (Sec_comp_type > 0)
				{
					if (Sec_comp_type == 1)
						ss << " [" << Comp_dim << "] ";
					else if (Sec_comp_type > 1)
					{
						ss << " [" << Comp_dim << "] ";
						ss << write_c_dimmension_component_recursively(Sec_comp_type);
					}
				}
			}
		}
	}
	return ss.str();
}

string write_separator_cond(string Separator, string PModule, int Entry, string HDL, int Type)
{
	stringstream ss;
	if (HDL != "c")
	{
		int Next_entry;
		string Kind;
		if (Type == 1)
		{
			Next_entry = Entry + 1;
			if (!HT.findfact("data_stmt(" + PModule + "," + PModule + "," + to_string(Entry) + ",_,\"par_out\",_)"))
			{
				if (HT.findfact("data_stmt(" + PModule + ",_," + to_string(Next_entry) + ",_,_,_)"))
				{
					Kind = (HT.findandreturn("data_stmt(" + PModule + ",_," + to_string(Next_entry) + ",_,_,_)"), 5);
					if (it_is_io_parameter(Kind))
					{
						ss << Separator << endl;
					}
				}
			}
		}
		else if (!parent_type_is_integer(Type, 0))
		{
			Next_entry = Entry + 1;
			if (HT.findfact("data_stmt(" + PModule + ",_," + to_string(Next_entry) + ",_,_,_)"))
			{
				Kind = (HT.findandreturn("data_stmt(" + PModule + ",_," + to_string(Next_entry) + ",_,_,_)"), 5);
				if (!it_is_io_parameter(Kind))
					ss << endl;
				else
					ss << Separator << endl;				
			}
		}
		else if (parent_type_is_integer(Type, 0))
		{
			Next_entry = Entry + 1;
			if (HT.findfact("data_stmt(" + PModule + ",_," + to_string(Next_entry) + ",_,_,_)"))
			{
				Kind = (HT.findandreturn("data_stmt(" + PModule + ",_," + to_string(Next_entry) + ",_,_,_)"), 5);
				if (it_is_io_parameter(Kind))
					ss << Separator << endl;
				else
					ss << endl;
			}
		}
		else if (HT.findfact("data_stmt(" + PModule + "," + PModule + "," + to_string(Entry) + ",_,_,_)"))
		{
			ss << endl;
		}

	}
	return ss.str();
}

bool it_is_io_parameter(string str)
{
	if (str == "par_in" || str == "par_out" || str == "par_inout")
		return true;
	return false;
}

string print_custom_functions_cond(string Module, string HDL)
{
	stringstream ss;
	if (HT.findfact("combo(*)") && HT.findfact("sequence(*)"))
		ss << print_custom_functions(Module, 1, HDL) << endl;
	return ss.str();
}

/* use:
	print_custom_functions(Module, Entry, HDL_language)
   where Module is the top-level custom block, and
   Entry is the next entry to process (start from 1, the first
   after the package's name in the hierarchy table)*/
string print_custom_functions(string Module, int Entry, string HDL)
{
	stringstream ss;
	string PModule;
	int Centry, Next_entry;
	if ((HDL == "vhdl" || HDL == "verilog") && (!HT.findfact("combo(*)") && !HT.findfact("sequence(*)")))
		return ss.str();
	if (HT.findfact("hierarchy_part(" + to_string(Entry) + ",_,_,\"libpart\",_,_,_)"))
	{
		PModule = returnpar(HT.findandreturn("hierarchy_part(" + to_string(Entry) + "," + PModule + ",_,\"libpart\",_,_,_)"), 2);
		if (Module == PModule)
		{
			if (!custom_block(Module))
				return ss.str();
		}
		else if (Module != PModule)
		{
			ss << print_custom_function_cond(Module, PModule, Entry, HDL);
			Next_entry = Entry + 1;
			ss << print_custom_functions(Module, Next_entry, HDL);
		}

	}
	else if (HT.findfact("hierarchy_part(_," + Module + ",_,\"libpart\",_,_,_)"))
	{
		Centry = stoi(returnpar(HT.findandreturn("hierarchy_part(_," + Module + ",_,\"libpart\",_,_,_)"), 1));
		if (Entry <= Centry)
		{
			if (HDL != "c")
			{
				if (HT.findfact("hierarchy_part(" + to_string(Entry) + ",_,_,\"libpart\",_,_,_)"))
				{
					PModule = returnpar(HT.findandreturn("hierarchy_part(" + to_string(Entry) + "," + PModule + ",_,\"libpart\",_,_,_)"), 2);
					if (Module == PModule)
					{
						if (custom_block(Module))
							print_custom_function(1, "", PModule, HDL);
					}
				}
			}
		}

	}

	return ss.str();
}

bool custom_block(string Module_name)
{
	if (HT.findfact("combo(_," + Module_name + ",_)") || HT.findfact("combo(_," + Module_name + ",_)"))
		return true;
	return false;
}

string print_custom_function(int int1, string Module, string PModule, string HDL)
{
	stringstream ss;
	if (int1 == 1)
	{
		string Intend0, Func_type_kind, Func_type_name;
		int PModuleDataEntry, Func_type_entry, ExcludingEntry;
		if (HDL == "vhdl")
		{
			if (custom_block(PModule))
			{
				ss << print_custom_function_header(1, PModule, "variable", "IS", "vhdl", 0);
				ss << print_local_variables(PModule, 1, "vhdl", 0);
				ss << "    BEGIN" << endl;
				Intend0 = "     ";
				ss << print_custom_body(Module, PModule, 1, Intend0, "vhdl");
				ss << "    END " << PModule << ";" << endl << endl;
			}
		}
		else if (HDL == "verilog")
		{
			if (custom_block(PModule))
			{
				ss << print_custom_function_header(1, PModule, "variable", ";", "verilog", 0);
				ss << "    begin:" << PModule << "_task_block" << endl;
				ss << print_local_variables(PModule, 1, "verilog", 0);
				Intend0 = "     ";
				ss << print_custom_body("", PModule, 1, Intend0, "verilog");
				ss << "    end " << endl;
				ss << "   endtask" << endl << endl;
			}

		}
		else if (HDL == "c")
		{
			if (HT.findfact("data_stmt(" + PModule + "," + PModule + ",_,_,_,sym(" + PModule + "))"))
			{
				Func_type_name = stoi(returnpar(HT.findandreturn("data_stmt(" + PModule + "," + PModule + ",_,_,_,sym(" + PModule + "))"), 2));
				PModuleDataEntry = stoi(returnpar(HT.findandreturn("data_stmt(" + PModule + "," + PModule + ",_,_,_,sym(" + PModule + "))"), 3));
				Func_type_entry = stoi(returnpar(HT.findandreturn("data_stmt(" + PModule + "," + PModule + ",_,_,_,sym(" + PModule + "))"), 4));
				if (HT.findfact("type_def("+to_string(Func_type_entry)+","+Func_type_name+",_,_,_,\"vectorarray_t\",_,_,_)"))
				{
					ss << print_custom_function_header(1, PModule, "variable", ";", "c", &ExcludingEntry);
					ss << print_local_variables(PModule, 1, "c", ExcludingEntry);
					Intend0 = "     ";
					ss << print_custom_body("", PModule, 1, Intend0, "c");
					ss << "   }" << endl << endl;
				}
				else if (HT.findfact("type_def(" + to_string(Func_type_entry) + ",*)"))
				{
					Func_type_kind = returnpar(HT.findandreturn("type_def(" + to_string(Func_type_entry) + ",*)"), 6);
					if (Func_type_kind != "vectorarray_t")
					{
						ss << print_custom_function_header(1, PModule, "variable", ";", "c", 0);
						ss << "    {" << endl;
						ss << print_local_variables(PModule, 1, "c", 0);
						Intend0 = "     ";
						ss << print_custom_body("", PModule, 1, Intend0, "c");
						ss << "   }" << endl << endl;
					}
				}
			}
			else if (!HT.findfact("data_stmt(" + PModule + "," + PModule + ",*)"))
			{
				ss << print_custom_function_header(1, PModule, "variable", ";", "c", 0);
				ss << print_local_variables(PModule, 1, "c", 0);
				Intend0 = "     ";
				ss << print_custom_body("", PModule, 1, Intend0, "c");
				ss << "   }" << endl << endl;
			}
		}
	}
	return ss.str();
}

string print_local_variables(string PModule, int Dentry, string HDL, int ExcludingEntry)
{
	stringstream ss;
	int Next_entry;
	if (HT.findfact("data_stmt(" + PModule + ",_," + to_string(Dentry) + ",_,_,_)"))
	{
		ss << print_local_variable_cond_cond(PModule, Dentry, HDL, ExcludingEntry);
		Next_entry = Dentry + 1;
		ss << print_local_variables(PModule, Next_entry, HDL, ExcludingEntry);

	}
	return ss.str();
}

string print_local_variable_cond_cond(string PModule, int Dentry, string HDL, int ExcludingEntry)
{
	stringstream ss;
	if (HDL != "c")
	{
		ss << print_local_variable_cond(PModule, Dentry, HDL);
	}
	else if (HDL == "c" && ExcludingEntry == 0)
	{
		ss << print_local_variable_cond(PModule, Dentry, "c");
	}
	else if (Dentry != ExcludingEntry)
		ss << print_local_variable_cond(PModule, Dentry, "c");
	return ss.str();
}

string print_local_variable_cond(string PModule, int Dentry, string HDL)
{
	stringstream ss;
	string Dname, Valuebe, Symbol, Kind, Ctype_name, Func_mod;
	int Type, Valueaf, Type_entry, Size, Number_of_dimmensions, MSB, First_component, Component_size, First_index,
		Child_type, Call_index, Called_entry;
	if (HT.findfact("data_stmt(" + PModule + ",_," + to_string(Dentry) + ",_,\"par_in\",_)") ||
		HT.findfact("data_stmt(" + PModule + ",_," + to_string(Dentry) + ",_,\"par_out\",_)") ||
		HT.findfact("data_stmt(" + PModule + ",_," + to_string(Dentry) + ",_,\"par_inout\",_)"))
		return ss.str();
	else if (HDL == "vhdl")
	{
		if (HT.findfact("data_stmt(" + PModule + ",_," + to_string(Dentry) + ",_,\"var\",_)"))
		{
			Dname = returnpar(HT.findandreturn("data_stmt(" + PModule + ",_," + to_string(Dentry) + ",_,\"var\",_)"), 2);
			Type = stoi(returnpar(HT.findandreturn("data_stmt(" + PModule + ",_," + to_string(Dentry) + ",_,\"var\",_)"), 4));
			ss << "      VARIABLE " << Dname << " : ";
			ss << write_cus_func_param_type(PModule, "body", Type, ";") << endl;
		}
		else if (HT.findfact("data_stmt(" + PModule + ",_," + to_string(Dentry) + ",_,\"const\",_)"))
		{
			Dname = returnpar(HT.findandreturn("data_stmt(" + PModule + ",_," + to_string(Dentry) + ",_,\"const\",_)"), 2);
			Type = stoi(returnpar(HT.findandreturn("data_stmt(" + PModule + ",_," + to_string(Dentry) + ",_,\"const\",_)"), 4));
			Valuebe = returnpar(HT.findandreturn("data_stmt(" + PModule + ",_," + to_string(Dentry) + ",_,\"const\",_)"), 6);
			Valueaf = stoi(returnpar(HT.findandreturn("data_stmt(" + PModule + ",_," + to_string(Dentry) + ",_,\"const\",_)"), 7));
			if (Type > 1)
			{
				ss << "      CONSTANT " << Dname << " : ";
				ss << write_constant_type(Type);
				ss << " := ";
				ss << write_constant_value(Type, Valuebe, Valueaf, "vhdl");
				ss << "      VARIABLE var" << Dname << " : ";
				ss << write_cus_func_param_type(PModule, "body", Type, ";") << endl;
			}
			else if (Valuebe == "bol" && (Valueaf == 0 || Valueaf == 1))
			{
				if (Type == 1)
				{
					ss << "      CONSTANT " << Dname << " : std_logic := '" << Valueaf <<"';";
					ss << endl;
					ss << "      VARIABLE var" << Dname << " : ";
					ss << write_cus_func_param_type(PModule, "body", Type, ";") << endl;
				}
			}
		}
	}
	else if (HDL == "verilog")
	{
		if (HT.findfact("data_stmt(" + PModule + ",_," + to_string(Dentry) + ",_,\"var\",_)"))
		{
			Dname = returnpar(HT.findandreturn("data_stmt(" + PModule + ",_," + to_string(Dentry) + ",_,\"var\",_)"), 2);
			Type_entry = stoi(returnpar(HT.findandreturn("data_stmt(" + PModule + ",_," + to_string(Dentry) + ",_,\"var\",_)"), 4));
			Valuebe = returnpar(HT.findandreturn("data_stmt(" + PModule + ",_," + to_string(Dentry) + ",_,\"var\",_)"), 6);
			Valueaf = stoi(returnpar(HT.findandreturn("data_stmt(" + PModule + ",_," + to_string(Dentry) + ",_,\"var\",_)"), 7));
			if (HT.findfact("type_def(" + to_string(Type_entry) + ",*)"))
			{
				Size = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Type_entry) + ",*)"), 3));
				First_index = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Type_entry) + ",*)"), 7));
				Number_of_dimmensions = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Type_entry) + ",*)"), 8));
				First_component = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Type_entry) + ",*)"), 9));
				if (Size > 1)
				{
					if (Number_of_dimmensions == 0)
					{
						MSB = Size - 1;
						ss << "      reg [" << MSB << ":0] " << Dname << ";" << endl;
					}
				}
				else if (HT.findfact("type_def(" + to_string(First_component) + ",*)"))
				{
					Component_size = stoi(returnpar(HT.findandreturn("type_def(" + to_string(First_component) + ",*)"), 3));
					if (Size > 1)
					{
						if (Component_size > 1)
						{
							if (Number_of_dimmensions != 0)
							{
								ss << "      reg ";
								ss << print_verilog_array_decl(Type_entry, Dname, " ; ") << endl;
							}
						}
						else if (Component_size == 1)
						{
							if (Number_of_dimmensions != 0)
							{
								MSB = Number_of_dimmensions - 1 - First_index;
								ss << "      reg [" << First_index << ":" << MSB << "] " << Dname << ";" << endl;
							}
						}
					}
				}
				else if (Size == 1)
				{
					ss << "      reg " << Dname << ";" << endl;

				}
			}
		}
		else if (HT.findfact("data_stmt(" + PModule + ",_," + to_string(Dentry) + ",_,\"const\",_)"))
		{
			Dname = returnpar(HT.findandreturn("data_stmt(" + PModule + ",_," + to_string(Dentry) + ",_,\"const\",_)"), 2);
			Type = stoi(returnpar(HT.findandreturn("data_stmt(" + PModule + ",_," + to_string(Dentry) + ",_,\"const\",_)"), 4));
			Valuebe = returnpar(HT.findandreturn("data_stmt(" + PModule + ",_," + to_string(Dentry) + ",_,\"const\",_)"), 6);
			Valueaf = stoi(returnpar(HT.findandreturn("data_stmt(" + PModule + ",_," + to_string(Dentry) + ",_,\"const\",_)"), 7));
			ss << "      parameter " << Dname << " = ";
			ss << write_constant_value(Type, Valuebe, Valueaf, "verilog");

		}
	}
	else if (HDL == "c")
	{
		if (HT.findfact("data_stmt(" + PModule + ",_," + to_string(Dentry) + ",_,\"var\",_)"))
		{
			Dname = returnpar(HT.findandreturn("data_stmt(" + PModule + ",_," + to_string(Dentry) + ",_,\"var\",_)"), 2);
			Type_entry = stoi(returnpar(HT.findandreturn("data_stmt(" + PModule + ",_," + to_string(Dentry) + ",_,\"var\",_)"), 4));
			Valuebe = returnpar(HT.findandreturn("data_stmt(" + PModule + ",_," + to_string(Dentry) + ",_,\"var\",_)"), 6);
			Valueaf = stoi(returnpar(HT.findandreturn("data_stmt(" + PModule + ",_," + to_string(Dentry) + ",_,\"var\",_)"), 7));
			if (HT.findfact("type_def(" + to_string(Type_entry) + ",*)"))
			{
				Symbol = returnpar(HT.findandreturn("type_def(" + to_string(Type_entry) + ",*)"), 2);
				Size = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Type_entry) + ",*)"), 3));
				Kind = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Type_entry) + ",*)"), 6));
				Number_of_dimmensions = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Type_entry) + ",*)"), 8));
				First_component = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Type_entry) + ",*)"), 9));
				if (Kind != "vectorarray_t")
				{
					if (Kind != "record_t")
					{
						if (Size > 1)
						{
							if (Number_of_dimmensions == 0)
							{
								translate_type_in_c(Symbol, &Ctype_name);
								ss << "      " << Ctype_name << " " << Dname << ";" << endl;
							}
						}
					}
					else
					{
						if (HT.findfact("type_def(" + to_string(First_component) + ",*)"))
						{
							if (Size > 1)
							{
								if (Number_of_dimmensions != 0)
								{
									ss << "      " << Symbol << " " << Dname << ";" << endl;
								}
							}
						}
					}
				}
				else if (Kind == "vectorarray_t")
				{
					if (HT.findfact("type_def(" + to_string(First_component) + ",*)"))
					{
						find_child_type(Type_entry, &Child_type);
						if (HT.findfact("type_def(" + to_string(Child_type) + ",*)"))
						{
							if (HT.findfact("prog_stmt(" + PModule + ",_,0,109,0,_," + to_string(Dentry) + ",_)"))
							{
								Call_index = stoi(returnpar(HT.findandreturn("prog_stmt(" + PModule + ",_,0,109,0,_," + to_string(Dentry) + ",_)"), 6));
								if (HT.findfact("call_stmt(" + PModule + "," + to_string(Call_index) + ",*)"))
								{
									Called_entry = stoi(returnpar(HT.findandreturn("call_stmt(" + PModule + "," + to_string(Call_index) + ",*)"), 3));
									if (HT.findfact("hierarchy_part(" + to_string(Called_entry) + ",_,_,\"libpart\",_,_,_)"))
									{
										Func_mod = stoi(returnpar(HT.findandreturn("hierarchy_part(" + to_string(Called_entry) + ",_,_,\"libpart\",_,_,_)"), 2));
										if (HT.findfact("data_stmt(" + Func_mod + "," + Func_mod + ",_,_,\"par_out\",sym(" + Func_mod + "))"))
										{
											ss << "      " << Symbol << " *" << Dname << ";" << endl;
										}
										else
										{
											ss << "      " << Symbol << " *" << Dname << ";" << endl;
											ss << "      " << Dname << " = (" << Symbol << "*) malloc(sizeof(" << Symbol << "));" << endl;
										}
									}
								}
							}
							else
							{
								ss << "      " << Symbol << " *" << Dname << ";" << endl;
								ss << "      " << Dname << " = (" << Symbol << "*) malloc(sizeof(" << Symbol << "));" << endl;
							}
						}
					}
				}
				else if (Size == 1)
				{
					translate_type_in_c(Symbol, &Ctype_name);
					ss << "      " << Ctype_name << " " << Dname << ";" << endl;
				}
			}
		}
		else if (HT.findfact("data_stmt(" + PModule + ",_," + to_string(Dentry) + ",_,\"const\",_)"))
		{
			Dname = returnpar(HT.findandreturn("data_stmt(" + PModule + ",_," + to_string(Dentry) + ",_,\"const\",_)"), 2);
			Type_entry = stoi(returnpar(HT.findandreturn("data_stmt(" + PModule + ",_," + to_string(Dentry) + ",_,\"const\",_)"), 4));
			Valuebe = returnpar(HT.findandreturn("data_stmt(" + PModule + ",_," + to_string(Dentry) + ",_,\"const\",_)"), 6);
			Valueaf = stoi(returnpar(HT.findandreturn("data_stmt(" + PModule + ",_," + to_string(Dentry) + ",_,\"const\",_)"), 7));
			if (HT.findfact("type_def(" + to_string(Type_entry) + ",*)"))
			{
				Symbol = returnpar(HT.findandreturn("type_def(" + to_string(Type_entry) + ",*)"), 2);
				translate_type_in_c(Symbol, &Ctype_name);
				ss << "      const " << Ctype_name << " " << Dname << " = ";
				ss << write_constant_value(Type_entry, Valuebe, Valueaf, "c");
			}
		}
	}
	return ss.str();
}

string write_constant_type(int Type)
{
	stringstream ss;
	string Type_name;
	int Size, Sizeminusone;
	if (Type == 1)
		ss << " boolean";
	else if (Type > 1)
	{
		if (HT.findfact("type_def(" + to_string(Type) + ",\"integer\",32,\"standard\",0,\"single_t\",0,0,0)"))
		{
			Size = 32;
			Sizeminusone = Size - 1;
			ss << " std_logic_vector(" << Sizeminusone << " DOWNTO 0)";
		}
		else if (HT.findfact("type_def(" + to_string(Type) + ",\"positive\",32,\"standard\",2,\"single_t\",0,0,0)"))
		{
			Size = 32;
			Sizeminusone = Size - 1;
			ss << " std_logic_vector(" << Sizeminusone << " DOWNTO 0)";
		}
		else if (HT.findfact("type_def(" + to_string(Type) + ",_,_,_,_,\"vectorarray_t\",_,_,_)"))
		{
			Type_name = returnpar(HT.findandreturn("type_def(" + to_string(Type) + ",_,_,_,_,\"vectorarray_t\",_,_,_)"), 2);
			ss << " " << Type_name;
		}
		else if (HT.findfact("type_def(" + to_string(Type) + ",_,_,_,_,\"record_t\",_,_,_)"))
		{
			Type_name = returnpar(HT.findandreturn("type_def(" + to_string(Type) + ",_,_,_,_,\"record_t\",_,_,_)"), 2);
			ss << " " << Type_name;
		}

	}
	else if (HT.findfact("type_def(" + to_string(Type) + ",_,_,_,_,\"single_t\",_,_,_)"))
	{
		Size = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Type) + ",_,_,_,_,\"single_t\",_,_,_)"), 3));
		if (Size > 1)
		{
			Sizeminusone = Size - 1;
			ss << " std_logic_vector(" << Sizeminusone << " DOWNTO 0)";
		}
		else if (Size == 1)
		{
			ss << " std_logic ";
		}
	}
	else if (!parent_type_is_integer(Type, 0))
	{
		if (HT.findfact("type_def(" + to_string(Type) + ",*)"))
		{
			Type_name = returnpar(HT.findandreturn("type_def(" + to_string(Type) + ",*)"), 2);
			ss << " " << Type_name;
		}
	}
	return ss.str();
}

string write_constant_value(int Type, string be, int af, string HDL)
{
	stringstream ss;
	int Size;
	if (HDL == "vhdl")
	{
		if (Type == 1 && be == "bol")
		{
			if (af == 0)
				ss << " false ;" << endl;
			else 
				ss << " true ;" << endl;
		}
		else if (HT.findfact("type_def(" + to_string(Type) + ",_,_,_,2,\"single_t\",_,_,_)") && be == "i")
		{
			Size = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Type) + ",_,_,_,2,\"single_t\",_,_,_)"), 3));
			if (Size == 1)
				ss << " '" << af << "' ;  -- integer constants are converted into std_logic" << endl;
			else if (Size > 1)
				ss << "std_logic_vector(conv_unsigned(" << af << ", " << Size <<
				"));  -- integer constants are converted into std_logic" << endl;
		}
		else if (Type == 2 && be == "i")
		{
			Size = 32;
			ss << "std_logic_vector(conv_unsigned(" << af << ", " << Size <<
				"));  -- integer constants are converted into std_logic" << endl;
		}
	}
	else if (HDL == "verilog" || HDL == "c")
	{
		if (Type == 1 && be == "bol")
		{
			if (af == 0)
				ss << " 0 ;" << endl;
			else
				ss << " 1 ;" << endl;
		}
		if (be == "i")
		{
			if (parent_type_is_integer(Type, 0))
				ss << " " << af << " ;  /*-- integer constants -- */" << endl;
		}
	}
	return ss.str();
}

string print_custom_body(string Module, string PModule, int Oentry, string Intend, string HDL)
{
	stringstream ss;
	string Next_intend0, Next_intend;
	int Next_entry;
	if (HT.findfact("prog_stmt(" + PModule + "," + to_string(Oentry) + ",*)"))
	{
		ss << print_custom_statement(Module, PModule, Oentry, Intend, &Next_intend0, HDL);
		ss << lookahead_prog_entry(PModule, Oentry, Next_intend0, &Next_intend);
		Next_entry = Oentry + 1;
		ss << print_custom_body(Module, PModule, Next_entry, Next_intend, HDL);
	}
	return ss.str();
}

string print_custom_statement(string Module, string PModule, int var3, string Intend, string* Next_intend, string Lang)
{
	stringstream ss;
	int Op, Left, Right, Result, Previous_of_result, PRop, Jumptoop, Ltype, Offset, Child_type, Ctype, Rtype, Type,
		Called_entry, Next_entry, Target, False_target, End_of_loop, Increment_variable, Start_d, End_d, Cond_result,
		Cond_type, Cond_size, If_statement, Condition_start, Body_last, Condition_end, ResType, FunctionNameEntry;

	int DoIt = 0; //TEMPORARY

	string OpString, Rdata, ResData, Right_kind{}, Ldata, REsType, Left_kind{}, Res_kind, Index, ArrayName, RecName,
		Child_type_name, Resdata, Source, Kind, Res_name, Called_name, Inc_var_name, Cond_name, Next_intend1, Next_intend2,
		Rkind, ResTypeName, Result_type0, Result_target;
	vector<int> Rec_list, Par_list, Rec_par_list;
	if (Lang == "vhdl")
	{
		if (HT.findfact("prog_stmt(" + PModule + "," + to_string(var3) + ",*)"))
		{
			Op = stoi(returnpar(HT.findandreturn("prog_stmt(" + PModule + "," + to_string(var3) + ",*)"), 4));
			Left = stoi(returnpar(HT.findandreturn("prog_stmt(" + PModule + "," + to_string(var3) + ",*)"), 5));
			Right = stoi(returnpar(HT.findandreturn("prog_stmt(" + PModule + "," + to_string(var3) + ",*)"), 6));
			Result = stoi(returnpar(HT.findandreturn("prog_stmt(" + PModule + "," + to_string(var3) + ",*)"), 7));
			Next_entry = stoi(returnpar(HT.findandreturn("prog_stmt(" + PModule + "," + to_string(var3) + ",*)"), 8));
			if (Op < 102)
			{
				if (not_a_for_loop(PModule, var3))
				{
					if (not_a_while_loop(PModule, var3))
					{
						if (HT.findfact("op_def(" + to_string(Op) + ",_,\"unop\",_,_,_,_)"))
						{
							OpString = returnpar(HT.findandreturn("op_def(" + to_string(Op) + ",_,\"unop\", _, _, _, _)"), 2);
							if (OpString == "not")
							{
								if (HT.findfact("data_stmt(" + PModule + ",_," + to_string(Right) + ",_,_,_)"))
								{
									Rdata = stoi(returnpar(HT.findandreturn("data_stmt(" + PModule + ",_," + to_string(Right) + ",_,_,_)"), 2));
									if (HT.findfact("data_stmt(" + PModule + ",_," + to_string(Result) + ",_,_,_)"))
									{
										ResData = returnpar(HT.findandreturn("data_stmt(" + PModule + ",_," + to_string(Result) + ",_,_,_)"), 2);
										conv_kind(PModule, Rdata, &Right_kind);
										*Next_intend = Intend;
										ss << Intend;
										ss << Rdata << " := NOT " << ResData << "; " << endl;
									}
								}
							}
							else if (HT.findfact("data_stmt(" + PModule + ",_," + to_string(Right) + ",_,_,_)"))
							{
								Rdata = stoi(returnpar(HT.findandreturn("data_stmt(" + PModule + ",_," + to_string(Right) + ",_,_,_)"), 2));
								if (HT.findfact("data_stmt(" + PModule + ",_," + to_string(Result) + ",_,_,_)"))
								{
									ResData = returnpar(HT.findandreturn("data_stmt(" + PModule + ",_," + to_string(Result) + ",_,_,_)"), 2);
									*Next_intend = Intend;
									ss << Intend;
									ss << print_possible_return(PModule, ResData, Rdata, " := ", "vhdl", 0);
									ss << OpString << " " << Rdata << ";" << endl;
								}
							}
						}
						else if (HT.findfact("op_def(" + to_string(Op) + ",_,\"binop\",_,_,_,_)"))
						{
							OpString = returnpar(HT.findandreturn("op_def(" + to_string(Op) + ",_,\"binop\",_,_,_,_)"), 2);
							if (is_relational_op(OpString))
							{
								if (HT.findfact("data_stmt(" + PModule + ",_," + to_string(Left) + ",_,_,_)"))
								{
									Ldata = returnpar(HT.findandreturn("data_stmt(" + PModule + ",_," + to_string(Left) + ",_,_,_)"), 2);
									if (HT.findfact("data_stmt(" + PModule + ",_," + to_string(Right) + ",_,_,_)"))
									{
										Rdata = returnpar(HT.findandreturn("data_stmt(" + PModule + ",_," + to_string(Right) + ",_,_,_)"), 2);
										if (HT.findfact("data_stmt(" + PModule + ",_," + to_string(Result) + ",_,_,_)"))
										{
											ResData = returnpar(HT.findandreturn("data_stmt(" + PModule + ",_," + to_string(Result) + ",_,_,_)"), 2);
											REsType = returnpar(HT.findandreturn("data_stmt(" + PModule + ",_," + to_string(Result) + ",_,_,_)"), 4);
											if (HT.findfact("type_def(" + REsType + ",_,1,_,_,_,_,_,_)"))
											{
												conv_kind(PModule, Rdata, &Right_kind);
												conv_kind(PModule, Ldata, &Left_kind);
												*Next_intend = Intend;
												ss << Intend;
												ss << "IF " << Ldata << " " << OpString << " " << Rdata << " THEN " << ResData << " :='1'; ELSE " <<
													ResData << " := '0'; END IF; " << endl;
											}
										}
									}
								}
							}
							else if (!is_relational_op(OpString))
							{
								if (HT.findfact("data_stmt(" + PModule + ",_," + to_string(Left) + ",_,_,_)"))
								{
									Ldata = returnpar(HT.findandreturn("data_stmt(" + PModule + ",_," + to_string(Left) + ",_,_,_)"), 2);
									if (HT.findfact("data_stmt(" + PModule + ",_," + to_string(Right) + ",_,_,_)"))
									{
										Rdata = returnpar(HT.findandreturn("data_stmt(" + PModule + ",_," + to_string(Right) + ",_,_,_)"), 2);
										if (HT.findfact("data_stmt(" + PModule + ",_," + to_string(Result) + ",_,_,_)"))
										{
											ResData = returnpar(HT.findandreturn("data_stmt(" + PModule + ",_," + to_string(Result) + ",_,_,_)"), 2);
											Res_kind = returnpar(HT.findandreturn("data_stmt(" + PModule + ",_," + to_string(Result) + ",_,_,_)"), 5);
											conv_kind(PModule, Rdata, &Right_kind);
											conv_kind(PModule, Ldata, &Left_kind);
											*Next_intend = Intend;
											ss << Intend;
											ss << type_op_triple(PModule, ResData, Ldata, Rdata,
															 Res_kind, Left_kind, Right_kind,
															 OpString, " := ", "vhdl") << endl;
										}
									}
								}
							}
						}
					}
				}
			}
			else if (Op == 102)
			{
				if (not_a_for_loop(PModule, var3))
				{
					if (not_a_while_loop(PModule, var3))
					{
						if (Right > 0)
						{
							if (HT.findfact("data_stmt(" + PModule + ",_," + to_string(Right) + ",_,_,_)"))
							{
								Rdata = stoi(returnpar(HT.findandreturn("data_stmt(" + PModule + ",_," + to_string(Right) + ",_,_,_)"), 2));
								if (HT.findfact("data_stmt(" + PModule + ",_," + to_string(Result) + ",_,_,_)"))
								{
									*Next_intend = Intend;
									ss << Intend;
									ss << print_possible_return(PModule, ResData, Rdata, " := ", "vhdl", 0);
									ss << Rdata << ";" << endl;
								}
							}
						}
						else if (Right < 0)
						{
							if (HT.findfact("rec_stmt(" + PModule + ", " + to_string(Right) + ",*)"))
							{
								Rec_list = returnVec(makeInstanceOf(HT.findandreturn("rec_stmt(" + PModule + ", " + to_string(Right) + ",*)")), 1);
								if (HT.findfact("data_stmt(" + PModule + ",_," + to_string(Result) + ",_,_,_)"))
								{
									ResData = returnpar(HT.findandreturn("data_stmt(" + PModule + ",_," + to_string(Result) + ",_,_,_)"), 2);
									if (HT.findfact("data_stmt(" + PModule + ",_," + to_string(Left) + ",_,_,_)"))
									{
										Ldata = returnpar(HT.findandreturn("data_stmt(" + PModule + ",_," + to_string(Left) + ",_,_,_)"), 2);
										*Next_intend = Intend;
										ss << Intend;
										ss << print_possible_return(PModule, ResData, Ldata, " := ", "vhdl", 0);
										ss << " (";
										ss << print_custom_record_index_parameters("", PModule, Rec_list, "record");
										ss << ");" << endl;
									}
								}
							}
						}
					}
				}
			}
			else if (Op == 103 || Op == 104 || Op == 105)
			{
				if (not_a_for_loop(PModule, var3))
				{
					if (not_a_while_loop(PModule, var3))
					{
						if (HT.findfact("data_stmt(" + PModule + ",_," + to_string(Left) + ",_,_,_)"))
						{
							Ldata = returnpar(HT.findandreturn("data_stmt(" + PModule + ",_," + to_string(Left) + ",_,_,_)"), 2);
							if (HT.findfact("data_stmt(" + PModule + ",_," + to_string(Result) + ",_,_,_)"))
							{
								Rdata = returnpar(HT.findandreturn("data_stmt(" + PModule + ",_," + to_string(Result) + ",_,_,_)"), 2);
								*Next_intend = Intend;
								if (Op == 105)
									ss << Intend << Rdata << " := " << Ldata << " - " << Right << ";" << endl;
								else
									ss << Intend << Rdata << " := " << Ldata << " + " << Right << ";" << endl;
							}
						}
					}
				}
			}
			else if (Op == 106)
			{
				if (not_a_for_loop(PModule, var3))
				{
					if (not_a_while_loop(PModule, var3))
					{
						Previous_of_result = Result - 1;
						if (HT.findfact("prog_stmt(" + PModule + "," + to_string(Previous_of_result) + ",*)"))
						{
							PRop = stoi(returnpar(HT.findandreturn("data_stmt(" + PModule + ",_," + to_string(Result) + ",_,_,_)"), 2));
							if (PRop != 110)
							{
								if (HT.findfact("data_stmt(" + PModule + ",_," + to_string(Right) + ",_,_,_)"))
								{
									Rdata = returnpar(HT.findandreturn("data_stmt(" + PModule + ",_," + to_string(Right) + ",_,_,_)"), 2);
									push_cond_end(PModule, Result, "END IF");
									HT.concat(Intend, " ", Next_intend);
									ss << Intend << "IF " << Rdata << " = '1' THEN " << endl;
								}
							}
						}
						else if (HT.findfact("prog_stmt(" + PModule + "," + to_string(Previous_of_result) + ",_,110,_,_,_,_)"))
						{
							Jumptoop = stoi(returnpar(HT.findandreturn("prog_stmt(" + PModule + "," + to_string(Previous_of_result) + ",_,110,_,_,_,_)"), 7));
							if (Jumptoop < Previous_of_result)
							{
								if (HT.findfact("data_stmt(" + PModule + ",_," + to_string(Right) + ",_,_,_)"))
								{
									Rdata = returnpar(HT.findandreturn("data_stmt(" + PModule + ",_," + to_string(Right) + ",_,_,_)"), 2);
									push_cond_end(PModule, Result, "END IF");
									HT.concat(Intend, " ", Next_intend);
									ss << Intend << "IF " << Rdata << " = '1' THEN " << endl;
								}
							}
							else if (Jumptoop > Previous_of_result)
							{
								if (HT.findfact("data_stmt(" + PModule + ",_," + to_string(Right) + ",_,_,_)"))
								{
									Rdata = returnpar(HT.findandreturn("data_stmt(" + PModule + ",_," + to_string(Right) + ",_,_,_)"), 2);
									push_cond_end(PModule, Result, "ELSE");
									HT.concat(Intend, " ", Next_intend);
									ss << Intend << "IF " << Rdata << " = '1' THEN " << endl;
								}
							}
						}
					}
				}
			}
			else if (Op == 107)
			{
				if (Right > 0)
				{
					if (not_a_for_loop(PModule, var3))
					{
						if (not_a_while_loop(PModule, var3))
						{
							if (HT.findfact("data_stmt(" + PModule + ",_," + to_string(Right) + ",_,_,_)"))
							{
								Index = returnpar(HT.findandreturn("data_stmt(" + PModule + ",_," + to_string(Right) + ",_,_,_)"), 2);
								if (HT.findfact("data_stmt(" + PModule + ",_," + to_string(Left) + ",_,_,_)"))
								{
									ArrayName = returnpar(HT.findandreturn("data_stmt(" + PModule + ",_," + to_string(Right) + ",_,_,_)"), 2);
									Ltype = stoi(returnpar(HT.findandreturn("data_stmt(" + PModule + ",_," + to_string(Right) + ",_,_,_)"), 4));
									if (HT.findfact("type_def(" + to_string(Ltype) + ",_,_,_,_,\"vectorarray_t\",_,_,_)"))
									{
										if (HT.findfact("data_stmt(" + PModule + ",_," + to_string(Result) + ",_,_,_)"))
										{
											Rdata = returnpar(HT.findandreturn("data_stmt(" + PModule + ",_," + to_string(Result) + ",_,_,_)"), 2);
											*Next_intend = Intend;
											ss << Intend;
											ss << print_possible_return(PModule, ResData, ArrayName, " := ", "vhdl", 0);
											ss << ArrayName << "(CONV_INTEGER(" << Index << "));" << endl;
										}
									}
								}
							}
							else if (HT.findfact("data_stmt(" + PModule + ",_," + to_string(Right) + ",_,\"const\",i(*))"))
							{
								Index = returnpar(HT.findandreturn("data_stmt(" + PModule + ",_," + to_string(Right) + ",_,\"const\",i(*))"), 2);
								Offset = stoi(returnpar(HT.findandreturn("data_stmt(" + PModule + ",_," + to_string(Right) + ",_,\"const\",i(*))"), 7));
								if (HT.findfact("data_stmt(" + PModule + ",_," + to_string(Left) + ",_,_,_)"))
								{
									RecName = returnpar(HT.findandreturn("data_stmt(" + PModule + ",_," + to_string(Left) + ",_,_,_)"), 2);
									Ltype = stoi(returnpar(HT.findandreturn("data_stmt(" + PModule + ",_," + to_string(Left) + ",_,_,_)"), 4));
									if (HT.findfact("type_def(" + to_string(Ltype) + ",_,_,_,_,\"record_t\",_,_,_)"))
									{
										Child_type = Ltype + Offset;
										if (HT.findfact("type_def(" + to_string(Ltype) + ",*)"))
										{
											Child_type_name = returnpar(HT.findandreturn("type_def(" + to_string(Ltype) + ",*)"), 2);
											Ctype = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Ltype) + ",*)"), 9));
											if (HT.findfact("data_stmt(" + PModule + ",_," + to_string(Result) + ",_,_,_)"))
											{
												Resdata = returnpar(HT.findandreturn("data_stmt(" + PModule + ",_," + to_string(Result) + ",_,_,_)"), 2);
												Rtype = stoi(returnpar(HT.findandreturn("data_stmt(" + PModule + ",_," + to_string(Result) + ",_,_,_)"), 4));
												Ctype = Rtype;
												*Next_intend = Intend;
												ss << Intend;
												ss << print_possible_return(PModule, ResData, RecName, " := ", "vhdl", 0);
												ss << RecName << Child_type_name << ";" << endl;
											}
										}
									}
								}
							}
						}
					}
				}
				else if (Right < 0)
				{
					if (not_a_for_loop(PModule, var3))
					{
						if (not_a_while_loop(PModule, var3))
						{
							if (HT.findfact("compo_stmt(" + PModule + "," + to_string(Right) + ",_)"))
							{
								Par_list = returnVec(makeInstanceOf(HT.findandreturn("compo_stmt(" + PModule + "," + to_string(Right) + ",_)")), 1);
								if (HT.findfact("data_stmt(" + PModule + ",_," + to_string(Left) + ",_,_,_)"))
								{
									ArrayName = returnpar(HT.findandreturn("data_stmt(" + PModule + ",_," + to_string(Right) + ",_,_,_)"), 2);
									if (HT.findfact("data_stmt(" + PModule + ",_," + to_string(Result) + ",_,_,_)"))
									{
										Resdata = returnpar(HT.findandreturn("data_stmt(" + PModule + ",_," + to_string(Right) + ",_,_,_)"), 2);		
										*Next_intend = Intend;
										ss << Intend;
										ss << print_possible_return(PModule, ResData, ArrayName, " := ", "vhdl", 0);
										ss << ArrayName;
										ss << print_custom_array_index_parameters(PModule, Par_list, "vhdl");
										ss << ";" << endl;
									}
								}
							}
						}
					}
				}
			}
			else if (Op == 108)
			{
				if (Right > 0)
				{
					if (not_a_for_loop(PModule, var3))
					{
						if (not_a_while_loop(PModule, var3))
						{
							if (HT.findfact("data_stmt(" + PModule + ",_," + to_string(Right) + ",_,_,_)"))
							{
								Index = returnpar(HT.findandreturn("data_stmt(" + PModule + ",_," + to_string(Right) + ",_,_,_)"), 2);
								if (HT.findfact("data_stmt(" + PModule + ",_," + to_string(Left) + ",_,_,_)"))
								{
									Source = returnpar(HT.findandreturn("data_stmt(" + PModule + ",_," + to_string(Right) + ",_,_,_)"), 2);
									Type = stoi(returnpar(HT.findandreturn("data_stmt(" + PModule + ",_," + to_string(Right) + ",_,_,_)"), 4));
									if (Type > 1)
									{
										if (HT.findfact("data_stmt(" + PModule + "," + ArrayName + "," + to_string(Result) + ",*),  "))
										{
											*Next_intend = Intend;
											ss << Intend << ArrayName << "(CONV_INTEGER(" << Index << ")) := " << Source << ";" << endl;
										}
									}
								}
								else if (HT.findfact("data_stmt(" + PModule + ",_," + to_string(Left) + ",1,\"const\",_)"))
								{
									Source = returnpar(HT.findandreturn("data_stmt(" + PModule + ",_," + to_string(Right) + ",_,_,_)"), 2);
									if (HT.findfact("data_stmt(" + PModule + "," + ArrayName + "," + to_string(Result) + ",*),  "))
									{
										*Next_intend = Intend;
										ss << Intend;
										ss << "IF " << Source << " THEN " << ArrayName << "(CONV_INTEGER(" << Index << ")) := '1'; ELSE " << ArrayName << "(CONV_INTEGER(" << Index << ")) := '0'; END IF;" << endl;

									}
								}
								else if (HT.findfact("data_stmt(" + PModule + ",_," + to_string(Left) + ",1,\"const\",_)"))
								{
									Source = returnpar(HT.findandreturn("data_stmt(" + PModule + ",_," + to_string(Right) + ",_,_,_)"), 2);
									Kind = returnpar(HT.findandreturn("data_stmt(" + PModule + ",_," + to_string(Right) + ",_,_,_)"), 5);
									if (Kind != "const")
									{
										if (HT.findfact("data_stmt(" + PModule + "," + ArrayName + "," + to_string(Result) + ",*),  "))
										{
											*Next_intend = Intend;
											ss << Intend;
											ss << "IF " << Source << "= '1' THEN " << ArrayName << "(CONV_INTEGER(" << Index << ")) := '1'; ELSE " << ArrayName << "(CONV_INTEGER(" << Index << ")) := '0'; END IF;" << endl;
										}
									}
								}
								else if (Left < 0)
								{
									if (HT.findfact("rec_stmt(" + PModule + ", " + to_string(Left) + ",*)"))
									{
										Rec_par_list = returnVec(makeInstanceOf(HT.findandreturn("rec_stmt(" + PModule + ", " + to_string(Left) + ",*)")), 1);
										if (HT.findfact("data_stmt(" + PModule + "," + ArrayName + "," + to_string(Result) + ",*),  "))
										{
											*Next_intend = Intend;
											ss << Intend << ArrayName << "(CONV_INTEGER(" << Index << ")) := (";
											ss << print_custom_record_index_parameters("", PModule, Rec_par_list, "record");
											ss << ");" << endl;
										}
									}
								}
							}
						}
					}
				}
				else if (Right < 0)
				{
					if (not_a_for_loop(PModule, var3))
					{
						if (not_a_while_loop(PModule, var3))
						{
							if (HT.findfact("compo_stmt(" + PModule + "," + to_string(Right) + ",*)"))
							{
								Par_list = returnVec(makeInstanceOf(HT.findandreturn("compo_stmt(" + PModule + "," + to_string(Right) + ",*)")), 1);
								if (Left > 0)
								{
									if (HT.findfact("data_stmt(" + PModule + ",_," + to_string(Left) + ",*)"))
									{
										Source = returnpar(HT.findandreturn("data_stmt(" + PModule + ",_," + to_string(Left) + ",*)"), 2);
										if (HT.findfact("data_stmt(" + PModule + "," + ArrayName + "," + to_string(Result) + ",*),  "))
										{
											*Next_intend = Intend;
											ss << Intend << ArrayName << "";
											ss << print_custom_array_index_parameters(PModule, Par_list, "vhdl");
											ss << " := " << Source << ";" << endl;
										}										
									}
								}
								else if (Left < 0)
								{
									if (HT.findfact("rec_stmt(" + PModule + ", " + to_string(Left) + ",*)"))
									{
										Rec_list = returnVec(makeInstanceOf(HT.findandreturn("rec_stmt(" + PModule + ", " + to_string(Left) + ",*)")), 3);
										if (HT.findfact("data_stmt(" + PModule + "," + ArrayName + "," + to_string(Result) + ",*),  "))
										{
											*Next_intend = Intend;
											ss << Intend << ArrayName << "";
											ss << print_custom_array_index_parameters(PModule, Par_list, "vhdl");
											ss << " := (";
											ss << print_custom_record_index_parameters("", PModule, Rec_list, "record");
											ss << ");" << endl;
										}
									}
								}
							}
						}
					}
				}
			}
			else if (Op == 109)
			{
				if (Result > 0)
				{
					if (HT.findfact("data_stmt(" + PModule + ",_," + to_string(Result) + ",*)"))
					{
						Res_name = returnpar(HT.findandreturn("data_stmt(" + PModule + ",_," + to_string(Result) + ",*)"), 2);
						if (HT.findfact("call_stmt(" + PModule + "," + to_string(Right) + ",*)"))
						{
							Called_entry = stoi(returnpar(HT.findandreturn("call_stmt(" + PModule + "," + to_string(Right) + ",*)"), 3));
							Par_list = returnVec(makeInstanceOf(HT.findandreturn("call_stmt(" + PModule + "," + to_string(Right) + ",*)")), 4);
							ss << print_custom_record_index_parameters("", PModule, Par_list, "constants");
							if (HT.findfact("hierarchy_part(" + to_string(Called_entry) + ",_,_,\"libpart\",_,_,_)"))
							{
								Called_name = stoi(returnpar(HT.findandreturn("hierarchy_part(" + to_string(Called_entry) + ",_,_,\"libpart\",_,_,_)"), 3));
								ss << Intend;
								ss << Called_name << "(";
								ss << print_custom_record_index_parameters(Module, PModule, Par_list, "function");
								ss << ", " << Res_name;
								ss << ");" << endl;
							}
						}
					}
				}
				else if (Result == 0)
				{
					if (HT.findfact("call_stmt(" + PModule + "," + to_string(Right) + ",*)"))
					{
						Called_entry = stoi(returnpar(HT.findandreturn("call_stmt(" + PModule + "," + to_string(Right) + ",*)"), 3));
						Par_list = returnVec(makeInstanceOf(HT.findandreturn("call_stmt(" + PModule + "," + to_string(Right) + ",*)")), 4);
						ss << print_custom_record_index_parameters("", PModule, Par_list, "constants");
						if (HT.findfact("hierarchy_part(" + to_string(Called_entry) + ",_,_,\"libpart\",_,_,_)"))
						{
							Called_name = stoi(returnpar(HT.findandreturn("hierarchy_part(" + to_string(Called_entry) + ",_,_,\"libpart\",_,_,_)"), 3));
							ss << Intend << Called_name << "(";
							ss << print_custom_record_index_parameters(Module, PModule, Par_list, "function");
							ss << ");" << endl;
						}
					}
				}
				*Next_intend = Intend;
			}
			else if (Op == 110)
			{
				if (Result >= Next_entry)
				{
					if (not_a_for_loop(PModule, var3))
					{
						if (not_a_while_loop(PModule, var3))
						{
							if (HT.findfact("nested_cond_fact(" + PModule + ",[" + PModule + "," + to_string(Next_entry) + ",\"ELSE\",_,_,_])"))
							{
								string Out_intend;
								pop_cond_end(PModule);
								if (HT.concat(&Out_intend, " ", Intend)) 
								{
									ss << Out_intend << "ELSE " << endl;
									push_cond_end(PModule, Result, "END IF");
									HT.concat(Out_intend, " ", Next_intend);
								}
							}
						}
					}
				}
			}
		}
		else if (HT.findfact("prog_stmt(" + PModule + "," + to_string(var3) + ",_,110,_,_,_,_)"))
		{
			Target = stoi(returnpar(HT.findandreturn("prog_stmt(" + PModule + "," + to_string(var3) + ",_,110,_,_,_,_)"), 7));
			Next_entry = stoi(returnpar(HT.findandreturn("prog_stmt(" + PModule + "," + to_string(var3) + ",_,110,_,_,_,_)"), 8));
			if (Target < var3)
			{
				if (HT.findfact("for_loop(_," + PModule + ",_,_," + to_string(var3) + ",_,_,_,_,_,_,_,_,_)"))
				{
					if (HT.findfact("nested_cond_fact(" + PModule + ",[" + PModule + "," + to_string(Next_entry) + ",\"END LOOP\"])"))
					{
						pop_cond_end(PModule);
						HT.concat(Next_intend, " ", Intend);
						ss << *Next_intend << "END LOOP;" << endl;
					}
				}
			}
		}
		else if (HT.findfact("prog_stmt(" + PModule + "," + to_string(var3) + ",_,106,0,_,_,_)"))
		{
			Cond_result = stoi(returnpar(HT.findandreturn("prog_stmt(" + PModule + "," + to_string(var3) + ",_,106,0,_,_,_)"), 6));
			False_target = stoi(returnpar(HT.findandreturn("prog_stmt(" + PModule + "," + to_string(var3) + ",_,106,0,_,_,_)"), 7));
			if (HT.findfact("for_loop(_," + PModule + "," + to_string(var3) + ",_,_,_,_,_,_,_,1,_,_,_)"))
			{
				End_of_loop = stoi(returnpar(HT.findandreturn("for_loop(_," + PModule + "," + to_string(var3) + ",_,_,_,_,_,_,_,1,_,_,_)"), 5));
				Increment_variable = stoi(returnpar(HT.findandreturn("for_loop(_," + PModule + "," + to_string(var3) + ",_,_,_,_,_,_,_,1,_,_,_)"), 8));
				Start_d = stoi(returnpar(HT.findandreturn("for_loop(_," + PModule + "," + to_string(var3) + ",_,_,_,_,_,_,_,1,_,_,_)"), 9));
				End_d = stoi(returnpar(HT.findandreturn("for_loop(_," + PModule + "," + to_string(var3) + ",_,_,_,_,_,_,_,1,_,_,_)"), 10));
				if (False_target == End_of_loop + 1)
				{
					if(HT.findfact("data_stmt("+PModule+",_,"+ to_string(Increment_variable)+",_,\"var\",sym(_))"))
					{
						Inc_var_name = returnpar(HT.findandreturn("data_stmt(" + PModule + ",_," + to_string(Increment_variable) + ",_,\"var\",sym(_))"), 2);
						push_cond_end(PModule, False_target, "END LOOP");
						ss << Intend << "FOR " << Inc_var_name << " IN ";
						ss << type_value(PModule, Start_d, "vhdl");
						ss << " TO ";
						ss << type_value(PModule, End_d, "vhdl");
						ss << " LOOP " << endl;
						HT.concat(Intend, " ", Next_intend);
					}
				}
			}
			else if (HT.findfact("while_loop(_," + PModule + "," + to_string(var3) + ",_,_,_,_)"))
			{
				End_of_loop = stoi(returnpar(HT.findandreturn("while_loop(_," + PModule + "," + to_string(var3) + ",_,_,_,_)"), 5));
				if (HT.findfact("data_stmt("+PModule+",_,"+to_string(Cond_result)+",_,_,_)"))
				{
					Cond_name = returnpar(HT.findandreturn("data_stmt(" + PModule + ",_," + to_string(Cond_result) + ",_,_,_)"), 2);
					Cond_type = stoi(returnpar(HT.findandreturn("data_stmt(" + PModule + ",_," + to_string(Cond_result) + ",_,_,_)"), 4));
					if (HT.findfact("type_def(" + to_string(Cond_type) + ",*)"))
					{
						Cond_size = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Cond_type) + ",*)"), 3));
						if (Cond_size == 1)
						{
							if (False_target == End_of_loop + 1)
							{
								push_cond_end(PModule, False_target, "END LOOP");
								ss << Intend << "WHILE (" << Cond_name << "='1') LOOP " << endl;
								HT.concat(Intend, " ", Next_intend);
							}
						}
						else if (Cond_size > 1)
						{
							if (False_target == End_of_loop + 1)
							{
								push_cond_end(PModule, False_target, "END LOOP");
								ss << Intend << "WHILE (" << Cond_name << "(0)='1') LOOP " << endl;
								HT.concat(Intend, " ", Next_intend);
							}
						}
					}
				}
			}
		}
		else if (HT.findfact("prog_stmt(" + PModule + "," + to_string(var3) + ",_,110,0,_,_,_)"))
		{
			False_target = stoi(returnpar(HT.findandreturn("prog_stmt(" + PModule + "," + to_string(var3) + ",_,110,0,_,_,_)"), 7));
			Next_entry = stoi(returnpar(HT.findandreturn("prog_stmt(" + PModule + "," + to_string(var3) + ",_,110,0,_,_,_)"), 8));
			if (False_target < var3)
			{
				if (HT.findfact("while_loop(_," + PModule + ",_,_," + to_string(var3) + ",_,_)"))
				{
					If_statement = stoi(returnpar(HT.findandreturn("while_loop(_," + PModule + "," + to_string(var3) + ",_," + to_string(var3) + ",_,_)"), 3));
					Condition_start = stoi(returnpar(HT.findandreturn("while_loop(_," + PModule + "," + to_string(var3) + ",_," + to_string(var3) + ",_,_)"), 4));
					Body_last = stoi(returnpar(HT.findandreturn("while_loop(_," + PModule + "," + to_string(var3) + ",_," + to_string(var3) + ",_,_)"), 7));
					if (var3 == Body_last + 1)
					{
						Condition_end = If_statement - 1;
						if (HT.findfact("nested_cond_fact(" + PModule + ",[" + PModule + "," + to_string(Next_entry) + ",\"END LOOP\"])"))
						{
							pop_cond_end(PModule);
							ss << print_while_loop_tail_cond(PModule, Condition_start, Condition_end, var3, Intend, Next_intend, "vhdl");
						}
					}
				}
			}
		}
	}
	if (Lang == "verilog")
	{
		if (HT.findfact("prog_stmt(" + PModule + "," + to_string(var3) + ",*)"))
		{
			Op = stoi(returnpar(HT.findandreturn("prog_stmt(" + PModule + "," + to_string(var3) + ",*)"), 4));
			Left = stoi(returnpar(HT.findandreturn("prog_stmt(" + PModule + "," + to_string(var3) + ",*)"), 5));
			Right = stoi(returnpar(HT.findandreturn("prog_stmt(" + PModule + "," + to_string(var3) + ",*)"), 6));
			Result = stoi(returnpar(HT.findandreturn("prog_stmt(" + PModule + "," + to_string(var3) + ",*)"), 7));
			Next_entry = stoi(returnpar(HT.findandreturn("prog_stmt(" + PModule + "," + to_string(var3) + ",*)"), 8));
			if (Op < 102)
			{
				if (not_a_for_loop(PModule, var3))
				{
					if (not_a_while_loop(PModule, var3))
					{
						if (HT.findfact("op_def(" + to_string(Op) + ",_,\"unop\",_,_,_,_)"))
						{
							OpString = returnpar(HT.findandreturn("op_def(" + to_string(Op) + ",_,\"unop\", _, _, _, _)"), 2);
							if (HT.findfact("data_stmt(" + PModule + ",_," + to_string(Right) + ",_,_,_)"))
							{
								Rdata = stoi(returnpar(HT.findandreturn("data_stmt(" + PModule + ",_," + to_string(Right) + ",_,_,_)"), 2));
								if (HT.findfact("data_stmt(" + PModule + ",_," + to_string(Result) + ",_,_,_)"))
								{
									ResData = returnpar(HT.findandreturn("data_stmt(" + PModule + ",_," + to_string(Result) + ",_,_,_)"), 2);

									*Next_intend = Intend;
									ss << Intend;
									ss << print_possible_return(PModule, ResData, Rdata, " = ", "verilog", 0);
									ss << OpString << " " << Rdata << ";" << endl;
								}
							}
						}
						else if (HT.findfact("op_def(" + to_string(Op) + ",_,\"binop\",_,_,_,_)"))
						{
							OpString = returnpar(HT.findandreturn("op_def(" + to_string(Op) + ",_,\"binop\",_,_,_,_)"), 2);
							if (HT.findfact("data_stmt(" + PModule + ",_," + to_string(Left) + ",_,_,_)"))
							{
								Ldata = returnpar(HT.findandreturn("data_stmt(" + PModule + ",_," + to_string(Left) + ",_,_,_)"), 2);
								if (HT.findfact("data_stmt(" + PModule + ",_," + to_string(Right) + ",_,_,_)"))
								{
									Rdata = returnpar(HT.findandreturn("data_stmt(" + PModule + ",_," + to_string(Right) + ",_,_,_)"), 2);
									if (HT.findfact("data_stmt(" + PModule + ",_," + to_string(Result) + ",_,_,_)"))
									{
										ResData = returnpar(HT.findandreturn("data_stmt(" + PModule + ",_," + to_string(Result) + ",_,_,_)"), 2);
										Res_kind = returnpar(HT.findandreturn("data_stmt(" + PModule + ",_," + to_string(Result) + ",_,_,_)"), 5);
										conv_kind(PModule, Rdata, &Right_kind);
										conv_kind(PModule, Ldata, &Left_kind);
										*Next_intend = Intend;
										ss << Intend;
										ss << type_op_triple(PModule, ResData, Ldata, Rdata, Res_kind, Left_kind, Right_kind, OpString, " = ", "verilog") << endl;
									}
								}
							}
						}
					}
				}
			}
			else if (Op == 102)
			{
				if (not_a_for_loop(PModule, var3))
				{
					if (not_a_while_loop(PModule, var3))
					{
						if (Right > 0)
						{
							if (HT.findfact("data_stmt(" + PModule + ",_," + to_string(Right) + ",_,_,_)"))
							{
								Rdata = stoi(returnpar(HT.findandreturn("data_stmt(" + PModule + ",_," + to_string(Right) + ",_,_,_)"), 2));
								if (HT.findfact("data_stmt(" + PModule + ",_," + to_string(Result) + ",_,_,_)"))
								{
									ResData = stoi(returnpar(HT.findandreturn("data_stmt(" + PModule + ",_," + to_string(Result) + ",_,_,_)"), 2));
									*Next_intend = Intend;
									ss << Intend;
									ss << print_possible_return(PModule, ResData, Rdata, " = ", "verilog", 0);
									ss << Rdata << ";" << endl;
								}
							}
						}
						else if (Right < 0)
						{
							if (HT.findfact("rec_stmt(" + PModule + ", " + to_string(Right) + ",*)"))
							{
								Rec_list = returnVec(makeInstanceOf(HT.findandreturn("rec_stmt(" + PModule + ", " + to_string(Right) + ",*)")), 1);
								if (HT.findfact("data_stmt(" + PModule + ",_," + to_string(Result) + ",_,_,_)"))
								{
									ResData = returnpar(HT.findandreturn("data_stmt(" + PModule + ",_," + to_string(Result) + ",_,_,_)"), 2);
									if (HT.findfact("data_stmt(" + PModule + ",_," + to_string(Right) + ",_,_,_)"))
									{
										Rdata = returnpar(HT.findandreturn("data_stmt(" + PModule + ",_," + to_string(Right) + ",_,_,_)"), 2);
										*Next_intend = Intend;
										ss << print_possible_return(PModule, ResData, Rdata, " = ", "verilog", 0);
										ss << " (";
										ss << print_custom_record_index_parameters("", PModule, Rec_list, "record");
										ss << ");" << endl;
									}
								}
							}
						}
					}
				}
			}
			else if (Op == 103 || Op == 104 || Op == 105)
			{
				if (not_a_for_loop(PModule, var3))
				{
					if (not_a_while_loop(PModule, var3))
					{
						if (HT.findfact("data_stmt(" + PModule + ",_," + to_string(Left) + ",_,_,_)"))
						{
							Ldata = returnpar(HT.findandreturn("data_stmt(" + PModule + ",_," + to_string(Left) + ",_,_,_)"), 2);
							if (HT.findfact("data_stmt(" + PModule + ",_," + to_string(Result) + ",_,_,_)"))
							{
								Rdata = returnpar(HT.findandreturn("data_stmt(" + PModule + ",_," + to_string(Result) + ",_,_,_)"), 2);
								*Next_intend = Intend;
								if (Op == 105)
									ss << Intend << Rdata << " := " << Ldata << " - " << Right << ";" << endl;
								else
									ss << Intend << Rdata << " := " << Ldata << " + " << Right << ";" << endl;
							}
						}
					}
				}
			}
			else if (Op == 106)
			{
				if (not_a_for_loop(PModule, var3))
				{
					if (not_a_while_loop(PModule, var3))
					{
						Previous_of_result = Result - 1;
						if (HT.findfact("prog_stmt(" + PModule + "," + to_string(Previous_of_result) + ",*)"))
						{
							PRop = stoi(returnpar(HT.findandreturn("data_stmt(" + PModule + ",_," + to_string(Result) + ",_,_,_)"), 2));
							if (PRop != 110)
							{
								if (HT.findfact("data_stmt(" + PModule + ",_," + to_string(Right) + ",_,_,_)"))
								{
									Rdata = returnpar(HT.findandreturn("data_stmt(" + PModule + ",_," + to_string(Right) + ",_,_,_)"), 2);
									push_cond_end(PModule, Result, "END IF");
									HT.concat(Intend, " ", &Next_intend1);
									ss << Next_intend1 << "if (" << Rdata << ") " << endl;
									HT.concat(Next_intend1, " ", &Next_intend2);
									ss << Next_intend2 << "begin" << endl;
									HT.concat(Next_intend2, " ", Next_intend);
								}
							}
						}
						else if (HT.findfact("prog_stmt(" + PModule + "," + to_string(Previous_of_result) + ",_,110,_,_,_,_)"))
						{
							Jumptoop = stoi(returnpar(HT.findandreturn("prog_stmt(" + PModule + "," + to_string(Previous_of_result) + ",_,110,_,_,_,_)"), 7));
							if (Jumptoop < Previous_of_result)
							{
								if (HT.findfact("data_stmt(" + PModule + ",_," + to_string(Right) + ",_,_,_)"))
								{
									Rdata = returnpar(HT.findandreturn("data_stmt(" + PModule + ",_," + to_string(Right) + ",_,_,_)"), 2);
									push_cond_end(PModule, Result, "END IF");
									HT.concat(Intend, " ", &Next_intend1);
									ss << Next_intend1 << "if (" << Rdata << ") " << endl;
									HT.concat(Next_intend1, " ", &Next_intend2);
									ss << Next_intend2 << "begin" << endl;
									HT.concat(Next_intend2, " ", Next_intend);
								}
							}
							else if (Jumptoop > Previous_of_result)
							{
								if (HT.findfact("data_stmt(" + PModule + ",_," + to_string(Right) + ",_,_,_)"))
								{
									Rdata = returnpar(HT.findandreturn("data_stmt(" + PModule + ",_," + to_string(Right) + ",_,_,_)"), 2);
									push_cond_end(PModule, Result, "ELSE");
									HT.concat(Intend, " ", &Next_intend1);
									ss << Next_intend1 << "if (" << Rdata << ") " << endl;
									HT.concat(Next_intend1, " ", &Next_intend2);
									ss << Next_intend2 << "begin" << endl;
									HT.concat(Next_intend2, " ", Next_intend);
								}
							}
						}
					}
				}
			}
			else if (Op == 107)
			{
				if (Right > 0)
				{
					if (not_a_for_loop(PModule, var3))
					{
						if (not_a_while_loop(PModule, var3))
						{
							if (HT.findfact("data_stmt(" + PModule + ",_," + to_string(Right) + ",_,_,_)"))
							{
								Index = returnpar(HT.findandreturn("data_stmt(" + PModule + ",_," + to_string(Right) + ",_,_,_)"), 2);
								if (HT.findfact("data_stmt(" + PModule + ",_," + to_string(Left) + ",_,_,_)"))
								{
									ArrayName = returnpar(HT.findandreturn("data_stmt(" + PModule + ",_," + to_string(Right) + ",_,_,_)"), 2);
									if (HT.findfact("data_stmt(" + PModule + ",_," + to_string(Result) + ",_,_,_)"))
									{
										Resdata = returnpar(HT.findandreturn("data_stmt(" + PModule + ",_," + to_string(Result) + ",_,_,_)"), 2);
										*Next_intend = Intend;
										ss << Intend;
										ss << print_possible_return(PModule, ResData, ArrayName, " := ", "verilog", 0);
										ss << ArrayName << "[" << Index << "];" << endl;
									}
								}
							}
						}
					}
				}
				else if (Right < 0)
				{
					if (not_a_for_loop(PModule, var3))
					{
						if (not_a_while_loop(PModule, var3))
						{
							if (HT.findfact("compo_stmt(" + PModule + "," + to_string(Right) + ",_)"))
							{
								Par_list = returnVec(makeInstanceOf(HT.findandreturn("compo_stmt(" + PModule + "," + to_string(Right) + ",_)")), 1);
								if (HT.findfact("data_stmt(" + PModule + ",_," + to_string(Left) + ",_,_,_)"))
								{
									ArrayName = returnpar(HT.findandreturn("data_stmt(" + PModule + ",_," + to_string(Left) + ",_,_,_)"), 2);
									if (HT.findfact("data_stmt(" + PModule + ",_," + to_string(Result) + ",_,_,_)"))
									{
										Resdata = returnpar(HT.findandreturn("data_stmt(" + PModule + ",_," + to_string(Result) + ",_,_,_)"), 2);
										*Next_intend = Intend;
										ss << Intend;
										ss << print_possible_return(PModule, ResData, ArrayName, " = ", "verilog", 0);
										ss << ArrayName;
										ss << print_custom_array_index_parameters(PModule, Par_list, "verilog");
										ss << ";" << endl;
									}
								}
							}
						}
					}
				}
			}
			else if (Op == 108)
			{
				if (Right > 0)
				{
					if (not_a_for_loop(PModule, var3))
					{
						if (not_a_while_loop(PModule, var3))
						{
							if (HT.findfact("data_stmt(" + PModule + ",_," + to_string(Right) + ",_,_,_)"))
							{
								Index = returnpar(HT.findandreturn("data_stmt(" + PModule + ",_," + to_string(Right) + ",_,_,_)"), 2);
								if (HT.findfact("data_stmt(" + PModule + ",_," + to_string(Left) + ",_,_,_)"))
								{
									Source = returnpar(HT.findandreturn("data_stmt(" + PModule + ",_," + to_string(Right) + ",_,_,_)"), 2);
									if (HT.findfact("data_stmt(" + PModule + "," + ArrayName + "," + to_string(Result) + ",*),  "))
									{
										*Next_intend = Intend;
										ss << Intend << ArrayName << "[" << Index << "] = " << Source << ";" << endl;
									}
								}
							}
						}
					}
				}
				else if (Right < 0)
				{
					if (not_a_for_loop(PModule, var3))
					{
						if (not_a_while_loop(PModule, var3))
						{
							if (HT.findfact("compo_stmt(" + PModule + "," + to_string(Right) + ",*)"))
							{
								Par_list = returnVec(makeInstanceOf(HT.findandreturn("compo_stmt(" + PModule + "," + to_string(Right) + ",*)")), 1);
								if (Left > 0)
								{
									if (HT.findfact("data_stmt(" + PModule + ",_," + to_string(Left) + ",*)"))
									{
										Source = returnpar(HT.findandreturn("data_stmt(" + PModule + ",_," + to_string(Left) + ",*)"), 2);
										if (HT.findfact("data_stmt(" + PModule + "," + ArrayName + "," + to_string(Result) + ",*),  "))
										{
											*Next_intend = Intend;
											ss << Intend << ArrayName << "";
											ss << print_custom_array_index_parameters(PModule, Par_list, "verilog");
											ss << " = " << Source << ";" << endl;
										}
									}
								}
								else if (Left < 0)
								{
									if (HT.findfact("rec_stmt(" + PModule + ", " + to_string(Left) + ",*)"))
									{
										Rec_list = returnVec(makeInstanceOf(HT.findandreturn("rec_stmt(" + PModule + ", " + to_string(Left) + ",*)")), 3);
										if (HT.findfact("data_stmt(" + PModule + "," + ArrayName + "," + to_string(Result) + ",*),  "))
										{
											*Next_intend = Intend;
											ss << Intend << ArrayName << "";
											ss << print_custom_array_index_parameters(PModule, Par_list, "verilog");
											ss << " = (";
											ss << print_custom_record_index_parameters("", PModule, Rec_list, "record");
											ss << ");" << endl;
										}
									}
								}
							}
						}
					}
				}
			}
			else if (Op == 109)
			{
				if (Result > 0)
				{
					if (HT.findfact("data_stmt(" + PModule + ",_," + to_string(Result) + ",*)"))
					{
						Res_name = returnpar(HT.findandreturn("data_stmt(" + PModule + ",_," + to_string(Result) + ",*)"), 2);
						if (HT.findfact("call_stmt(" + PModule + "," + to_string(Right) + ",*)"))
						{
							Called_entry = stoi(returnpar(HT.findandreturn("call_stmt(" + PModule + "," + to_string(Right) + ",*)"), 3));
							Par_list = returnVec(makeInstanceOf(HT.findandreturn("call_stmt(" + PModule + "," + to_string(Right) + ",*)")), 4);
							if (HT.findfact("hierarchy_part(" + to_string(Called_entry) + ",_,_,\"libpart\",_,_,_)"))
							{
								Called_name = returnpar(HT.findandreturn("hierarchy_part(" + to_string(Called_entry) + ",_,_,\"libpart\",_,_,_)"), 2);
								ss << Intend;
								ss << Called_name << "(";
								ss << print_custom_record_index_parameters("", PModule, Par_list, "function");
								ss << ", " << Res_name;
								ss << ");" << endl;
							}
						}
					}
				}
				else if (Result == 0)
				{
					if (HT.findfact("call_stmt(" + PModule + "," + to_string(Right) + ",*)"))
					{
						Called_entry = stoi(returnpar(HT.findandreturn("call_stmt(" + PModule + "," + to_string(Right) + ",*)"), 3));
						Par_list = returnVec(makeInstanceOf(HT.findandreturn("call_stmt(" + PModule + "," + to_string(Right) + ",*)")), 4);
						if (HT.findfact("hierarchy_part(" + to_string(Called_entry) + ",_,_,\"libpart\",_,_,_)"))
						{
							Called_name = returnpar(HT.findandreturn("hierarchy_part(" + to_string(Called_entry) + ",_,_,\"libpart\",_,_,_)"), 2);
							ss << Intend << Called_name << "(";
							ss << print_custom_record_index_parameters("", PModule, Par_list, "function");
							ss << ");" << endl;
						}
					}
				}
				*Next_intend = Intend;
			}
			else if (Op == 110)
			{
				if (Result >= Next_entry)
				{
					if (not_a_for_loop(PModule, var3))
					{
						if (not_a_while_loop(PModule, var3))
						{
							if (HT.findfact("nested_cond_fact(" + PModule + ",[" + PModule + "," + to_string(Next_entry) + ",\"ELSE\",_,_,_])"))
							{
								string Out_intend, Out_intend1;
								pop_cond_end(PModule);
								ss << Intend << "end" << endl;
								if (HT.concat(&Out_intend1, " ", Intend))
								{
									ss << Out_intend1 << "else " << endl;
									HT.concat(Out_intend1, " ", &Out_intend);
									ss << Out_intend << "begin " << endl;
									push_cond_end(PModule, Target, "END IF");
									HT.concat(Out_intend, " ", Next_intend);
								}
							}
						}
					}
				}
			}
		}
		else if (HT.findfact("prog_stmt(" + PModule + "," + to_string(var3) + ",_,110,_,_,_,_)"))
		{
			Target = stoi(returnpar(HT.findandreturn("prog_stmt(" + PModule + "," + to_string(var3) + ",_,110,_,_,_,_)"), 7));
			Next_entry = stoi(returnpar(HT.findandreturn("prog_stmt(" + PModule + "," + to_string(var3) + ",_,110,_,_,_,_)"), 8));
			if (Target < var3)
			{
				if (HT.findfact("for_loop(_,"+PModule+",_,_,"+to_string(var3) + ",_,_,_,_,_,_,_,_,_)"))
				{
					if (HT.findfact("nested_cond_fact(" + PModule + ",[" + PModule + "," + to_string(Next_entry) + ",\"END LOOP\"])"))
					{
						pop_cond_end(PModule);
						if (HT.concat(Next_intend, " ", Intend))
						{
							ss << Next_intend << "end;" << endl;
						}
					}
				}
			}
		}
		else if (HT.findfact("prog_stmt(" + PModule + "," + to_string(var3) + ",_,106,0,_,_,_)"))
		{
			Cond_result = stoi(returnpar(HT.findandreturn("prog_stmt(" + PModule + "," + to_string(var3) + ",_,106,0,_,_,_)"), 6));
			False_target = stoi(returnpar(HT.findandreturn("prog_stmt(" + PModule + "," + to_string(var3) + ",_,106,0,_,_,_)"), 7));
			if (HT.findfact("for_loop(_," + PModule + "," + to_string(var3) + ",_,_,_,_,_,_,_,1,_,_,_)"))
			{
				End_of_loop = stoi(returnpar(HT.findandreturn("for_loop(_," + PModule + "," + to_string(var3) + ",_,_,_,_,_,_,_,1,_,_,_)"), 5));
				Increment_variable = stoi(returnpar(HT.findandreturn("for_loop(_," + PModule + "," + to_string(var3) + ",_,_,_,_,_,_,_,1,_,_,_)"), 8));
				Start_d = stoi(returnpar(HT.findandreturn("for_loop(_," + PModule + "," + to_string(var3) + ",_,_,_,_,_,_,_,1,_,_,_)"), 9));
				End_d = stoi(returnpar(HT.findandreturn("for_loop(_," + PModule + "," + to_string(var3) + ",_,_,_,_,_,_,_,1,_,_,_)"), 10));
				if (False_target == End_of_loop + 1)
				{
					if (HT.findfact("data_stmt(" + PModule + ",_," + to_string(Increment_variable) + ",_,\"var\",sym(_))"))
					{
						Inc_var_name = returnpar(HT.findandreturn("data_stmt(" + PModule + ",_," + to_string(Increment_variable) + ",_,\"var\",sym(_))"), 2);
						push_cond_end(PModule, False_target, "END LOOP");
						ss << Intend << " for(" << Inc_var_name << "=";
						ss << type_value(PModule, Start_d, "verilog");
						ss << ";" << Inc_var_name << "<=";
						ss << type_value(PModule, End_d, "verilog");
						ss << ";" << Inc_var_name << "=" << Inc_var_name << "+1)" << endl;
						HT.concat(Intend, " ", &Next_intend1);
						ss << Next_intend1 << " begin" << endl;
						HT.concat(Next_intend1, " ", Next_intend);
					}
				}
			}
			else if (HT.findfact("while_loop(_," + PModule + "," + to_string(var3) + ",_,_,_,_)"))
			{
				End_of_loop = stoi(returnpar(HT.findandreturn("while_loop(_," + PModule + "," + to_string(var3) + ",_,_,_,_)"), 5));
				if (HT.findfact("data_stmt(" + PModule + ",_," + to_string(Cond_result) + ",_,_,_)"))
				{
					Cond_name = returnpar(HT.findandreturn("data_stmt(" + PModule + ",_," + to_string(Cond_result) + ",_,_,_)"), 2);
					if (False_target == End_of_loop + 1)
					{
						push_cond_end(PModule, False_target, "END LOOP");
						ss << Intend << " while (" << Cond_name << ") " << endl;
						HT.concat(Intend, " ", &Next_intend1);
						ss << Next_intend1 << " begin" << endl;
						HT.concat(Next_intend1, " ", Next_intend);
					}
				}
			}
		}
		else if (HT.findfact("prog_stmt(" + PModule + "," + to_string(var3) + ",_,110,0,_,_,_)"))
		{
			False_target = stoi(returnpar(HT.findandreturn("prog_stmt(" + PModule + "," + to_string(var3) + ",_,110,0,_,_,_)"), 7));
			Next_entry = stoi(returnpar(HT.findandreturn("prog_stmt(" + PModule + "," + to_string(var3) + ",_,110,0,_,_,_)"), 8));
			if (False_target < var3)
			{
				if (HT.findfact("while_loop(_," + PModule + ",_,_," + to_string(var3) + ",_,_)"))
				{
					If_statement = stoi(returnpar(HT.findandreturn("while_loop(_," + PModule + "," + to_string(var3) + ",_," + to_string(var3) + ",_,_)"), 3));
					Condition_start = stoi(returnpar(HT.findandreturn("while_loop(_," + PModule + "," + to_string(var3) + ",_," + to_string(var3) + ",_,_)"), 4));
					Body_last = stoi(returnpar(HT.findandreturn("while_loop(_," + PModule + "," + to_string(var3) + ",_," + to_string(var3) + ",_,_)"), 7));
					if (var3 == Body_last + 1)
					{
						if (End_of_loop == Body_last + 1)
						{
							Condition_end = If_statement - 1;
							if (HT.findfact("nested_cond_fact(" + PModule + ",[" + PModule + "," + to_string(Next_entry) + ",\"END LOOP\"])"))
							{
								pop_cond_end(PModule);
								print_while_loop_tail_cond(PModule, Condition_start, Condition_end, var3, Intend, Next_intend, "verilog");
							}
						}
					}
				}
			}
		}
	}
	if (Lang == "c")
	{
		if (HT.findfact("prog_stmt(" + PModule + "," + to_string(var3) + ",*)"))
		{
			Op = stoi(returnpar(HT.findandreturn("prog_stmt(" + PModule + "," + to_string(var3) + ",*)"), 4));
			Left = stoi(returnpar(HT.findandreturn("prog_stmt(" + PModule + "," + to_string(var3) + ",*)"), 5));
			Right = stoi(returnpar(HT.findandreturn("prog_stmt(" + PModule + "," + to_string(var3) + ",*)"), 6));
			Result = stoi(returnpar(HT.findandreturn("prog_stmt(" + PModule + "," + to_string(var3) + ",*)"), 7));
			Next_entry = stoi(returnpar(HT.findandreturn("prog_stmt(" + PModule + "," + to_string(var3) + ",*)"), 8));
			if (Op < 102)
			{
				if (not_a_for_loop(PModule, var3))
				{
					if (not_a_while_loop(PModule, var3))
					{
						if (HT.findfact("op_def(" + to_string(Op) + ",\"abs\",\"unop\",_,_,_,_)"))
						{
							if (HT.findfact("data_stmt(" + PModule + ",_," + to_string(Right) + ",_,_,_)"))
							{
								Rdata = stoi(returnpar(HT.findandreturn("data_stmt(" + PModule + ",_," + to_string(Right) + ",_,_,_)"), 2));
								if (HT.findfact("data_stmt(" + PModule + ",_," + to_string(Result) + ",_,_,_)"))
								{
									ResData = returnpar(HT.findandreturn("data_stmt(" + PModule + ",_," + to_string(Result) + ",_,_,_)"), 2);
									*Next_intend = Intend;
									ss << Intend;
									ss << print_possible_return(PModule, ResData, Rdata, " = ", "c", &DoIt);
									ss << print_after_return2(DoIt, Rdata);
									ss << ";" << endl;
								}
							}
						}
						else if (HT.findfact("op_def("+to_string(Op)+",\"not\",\"unop\",_,_,_,_)") || HT.findfact("op_def(" + to_string(Op) + ",\"abs\",\"unop\",_,_,_,_)"))
						{
							if (HT.findfact("data_stmt(" + PModule + ",_," + to_string(Right) + ",_,_,_)"))
							{
								Rdata = stoi(returnpar(HT.findandreturn("data_stmt(" + PModule + ",_," + to_string(Right) + ",_,_,_)"), 2));
								if (HT.findfact("data_stmt(" + PModule + ",_," + to_string(Result) + ",_,_,_)"))
								{
									ResData = returnpar(HT.findandreturn("data_stmt(" + PModule + ",_," + to_string(Result) + ",_,_,_)"), 2);
									*Next_intend = Intend;
									ss << Intend;
									ss << print_possible_return(PModule, ResData, Rdata, " = ", "c", &DoIt);
									ss << print_after_return1(DoIt, Rdata);
									ss << ";" << endl;
								}
							}
						}
						else if (HT.findfact("op_def(" + to_string(Op) + ",_,\"unop\",_,_,_,_)"))
						{
							OpString = returnpar(HT.findandreturn("op_def(" + to_string(Op) + ",_,\"unop\", _, _, _, _)"), 2);
							if (OpString != "not")
							{
								if (OpString != "abs")
								{
									if (HT.findfact("data_stmt(" + PModule + ",_," + to_string(Right) + ",_,_,_)"))
									{
										Rdata = stoi(returnpar(HT.findandreturn("data_stmt(" + PModule + ",_," + to_string(Right) + ",_,_,_)"), 2));
										if (HT.findfact("data_stmt(" + PModule + ",_," + to_string(Result) + ",_,_,_)"))
										{
											ResData = returnpar(HT.findandreturn("data_stmt(" + PModule + ",_," + to_string(Result) + ",_,_,_)"), 2);
											*Next_intend = Intend;
											ss << Intend;
											ss << print_possible_return(PModule, ResData, Rdata, " = ", "c", &DoIt); // ask what value DoIt should get
											ss << print_after_return0(DoIt, OpString, Rdata);
											ss << ";" << endl;
										}
									}
								}
							}
						}
						else if (HT.findfact("op_def(" + to_string(Op) + ",_,\"binop\",_,_,_,_)"))
						{
							OpString = returnpar(HT.findandreturn("op_def(" + to_string(Op) + ",_,\"binop\",_,_,_,_)"), 2);
							if (HT.findfact("data_stmt(" + PModule + ",_," + to_string(Left) + ",_,_,_)"))
							{
								Ldata = returnpar(HT.findandreturn("data_stmt(" + PModule + ",_," + to_string(Left) + ",_,_,_)"), 2);
								if (HT.findfact("data_stmt(" + PModule + ",_," + to_string(Right) + ",_,_,_)"))
								{
									Rdata = returnpar(HT.findandreturn("data_stmt(" + PModule + ",_," + to_string(Right) + ",_,_,_)"), 2);
									if (HT.findfact("data_stmt(" + PModule + ",_," + to_string(Result) + ",_,_,_)"))
									{
										ResData = returnpar(HT.findandreturn("data_stmt(" + PModule + ",_," + to_string(Result) + ",_,_,_)"), 2);
										Res_kind = returnpar(HT.findandreturn("data_stmt(" + PModule + ",_," + to_string(Result) + ",_,_,_)"), 5);
										conv_kind(PModule, Rdata, &Right_kind);
										conv_kind(PModule, Ldata, &Left_kind);
										*Next_intend = Intend;
										ss << Intend;
										ss << type_op_triple(PModule, ResData, Ldata, Rdata, Res_kind, Left_kind, Right_kind, OpString, " = ", "c") << endl;
									}
								}
							}
						}
					}
				}
			}
			else if (Op == 102)
			{
				if (not_a_for_loop(PModule, var3))
				{
					if (not_a_while_loop(PModule, var3))
					{
						if (Right > 0)
						{
							if (HT.findfact("data_stmt(" + PModule + ",_," + to_string(Right) + ",_,_,_)"))
							{
								Rdata = stoi(returnpar(HT.findandreturn("data_stmt(" + PModule + ",_," + to_string(Right) + ",_,_,_)"), 2));
								Rkind = returnpar(HT.findandreturn("data_stmt(" + PModule + ",_," + to_string(Right) + ",_,_,_)"), 5);
								if (HT.findfact("data_stmt(" + PModule + ",_," + to_string(Result) + ",_,_,_)"))
								{
									ResData = stoi(returnpar(HT.findandreturn("data_stmt(" + PModule + ",_," + to_string(Result) + ",_,_,_)"), 2));
									*Next_intend = Intend;
									ss << Intend;
									ss << print_possible_return(PModule, ResData, Rdata, " = ", "c", &DoIt);
									ss << print_after_return3(DoIt, Rkind, Rdata);
									ss << ";" << endl;
								}
							}
						}
						else if (Right < 0)
						{
							if (HT.findfact("rec_stmt(" + PModule + ", " + to_string(Right) + ",*)"))
							{
								Rec_list = returnVec(makeInstanceOf(HT.findandreturn("rec_stmt(" + PModule + ", " + to_string(Right) + ",*)")), 3);
								if (HT.findfact("data_stmt(" + PModule + ",_," + to_string(Result) + ",_,_,_)"))
								{
									ResData = returnpar(HT.findandreturn("data_stmt(" + PModule + ",_," + to_string(Result) + ",_,_,_)"), 2);
									ResType = stoi(returnpar(HT.findandreturn("data_stmt(" + PModule + ",_," + to_string(Result) + ",_,_,_)"), 4));
									if (HT.findfact("data_stmt(" + PModule + ",_," + to_string(Left) + ",_,_,_)"))
									{
										Ldata = returnpar(HT.findandreturn("data_stmt(" + PModule + ",_," + to_string(Right) + ",_,_,_)"), 2);
										if (HT.findfact("type_def(" + to_string(ResType) + ",_,_,_,_,\"record_t\",_,_,_)"))
										{
											ResTypeName = returnpar(HT.findandreturn("type_def(" + to_string(ResType) + ",_,_,_,_,\"record_t\",_,_,_)"), 2);
											*Next_intend = Intend;
											ss << Intend;
											HT.concat(ResTypeName, " ", &Result_type0);
											HT.concat(Result_type0, ResData, &Result_target);
											ss << print_possible_return(PModule, Result_target, Ldata, " = ", "c", &DoIt);
											ss << print_after_return4(DoIt, PModule, Rec_list);
											ss << ";" << endl;
										}
										else if (HT.findfact("type_def(" + to_string(ResType) + ",_,_,_,_,\"vectorarray_t\",_,_,_)"))
										{
											ResTypeName = returnpar(HT.findandreturn("type_def(" + to_string(ResType) + ",_,_,_,_,\"vectorarray_t\",_,_,_)"), 2);
											*Next_intend = Intend;
											ss << Intend;
											HT.concat(ResTypeName, " ", &Result_type0);
											HT.concat(Result_type0, ResData, &Result_target);
											ss << print_possible_return(PModule, Result_target, Ldata, " = ", "c", &DoIt);
											ss << print_after_return5(DoIt, PModule, Rec_list);
											ss << ";" << endl;
										}
									}
								}
							}
						}
					}
				}
			}
			else if (Op == 103 || Op == 104 || Op == 105)
			{
				if (not_a_for_loop(PModule, var3))
				{
					if (not_a_while_loop(PModule, var3))
					{
						if (HT.findfact("data_stmt(" + PModule + ",_," + to_string(Left) + ",_,_,_)"))
						{
							Ldata = returnpar(HT.findandreturn("data_stmt(" + PModule + ",_," + to_string(Left) + ",_,_,_)"), 2);
							if (HT.findfact("data_stmt(" + PModule + ",_," + to_string(Result) + ",_,_,_)"))
							{
								Rdata = returnpar(HT.findandreturn("data_stmt(" + PModule + ",_," + to_string(Result) + ",_,_,_)"), 2);
								*Next_intend = Intend;
								if (Op == 105)
									ss << Intend << Rdata << " = " << Ldata << " - " << Right << ";" << endl;
								else
									ss << Intend << Rdata << " = " << Ldata << " + " << Right << ";" << endl;
							}
						}
					}
				}
			}
			else if (Op == 106)
			{
				if (not_a_for_loop(PModule, var3))
				{
					if (not_a_while_loop(PModule, var3))
					{
						Previous_of_result = Result - 1;
						if (HT.findfact("prog_stmt(" + PModule + "," + to_string(Previous_of_result) + ",*)"))
						{
							PRop = stoi(returnpar(HT.findandreturn("data_stmt(" + PModule + ",_," + to_string(Result) + ",_,_,_)"), 2));
							if (PRop != 110)
							{
								if (HT.findfact("data_stmt(" + PModule + ",_," + to_string(Right) + ",_,_,_)"))
								{
									Rdata = returnpar(HT.findandreturn("data_stmt(" + PModule + ",_," + to_string(Right) + ",_,_,_)"), 2);
									push_cond_end(PModule, Result, "END IF");
									HT.concat(Intend, " ", &Next_intend1);
									ss << Next_intend1 << "if (" << Rdata << ") " << endl;
									HT.concat(Next_intend1, " ", &Next_intend2);
									ss << Next_intend2 << "{" << endl;
									HT.concat(Next_intend2, " ", Next_intend);
								}
							}
						}
						else if (HT.findfact("prog_stmt(" + PModule + "," + to_string(Previous_of_result) + ",_,110,_,_,_,_)"))
						{
							Jumptoop = stoi(returnpar(HT.findandreturn("prog_stmt(" + PModule + "," + to_string(Previous_of_result) + ",_,110,_,_,_,_)"), 7));
							if (Jumptoop < Previous_of_result)
							{
								if (HT.findfact("data_stmt(" + PModule + ",_," + to_string(Right) + ",_,_,_)"))
								{
									Rdata = returnpar(HT.findandreturn("data_stmt(" + PModule + ",_," + to_string(Right) + ",_,_,_)"), 2);
									push_cond_end(PModule, Result, "END IF");
									HT.concat(Intend, " ", &Next_intend1);
									ss << Next_intend1 << "if (" << Rdata << ") " << endl;
									HT.concat(Next_intend1, " ", &Next_intend2);
									ss << Next_intend2 << "{" << endl;
									HT.concat(Next_intend2, " ", Next_intend);
								}
							}
							else if (Jumptoop > Previous_of_result)
							{
								if (HT.findfact("data_stmt(" + PModule + ",_," + to_string(Right) + ",_,_,_)"))
								{
									Rdata = returnpar(HT.findandreturn("data_stmt(" + PModule + ",_," + to_string(Right) + ",_,_,_)"), 2);
									push_cond_end(PModule, Result, "ELSE");
									HT.concat(Intend, " ", &Next_intend1);
									ss << Next_intend1 << "if (" << Rdata << ") " << endl;
									HT.concat(Next_intend1, " ", &Next_intend2);
									ss << Next_intend2 << "{" << endl;
									HT.concat(Next_intend2, " ", Next_intend);
								}
							}
						}
					}
				}
			}
			else if (Op == 107)
			{
				if (Right > 0)
				{
					if (not_a_for_loop(PModule, var3))
					{
						if (not_a_while_loop(PModule, var3))
						{
							if (HT.findfact("data_stmt(" + PModule + ",_," + to_string(Right) + ",_,_,_)"))
							{
								Index = returnpar(HT.findandreturn("data_stmt(" + PModule + ",_," + to_string(Right) + ",_,_,_)"), 2);
								if (HT.findfact("data_stmt(" + PModule + ",_," + to_string(Left) + ",_,_,_)"))
								{
									ArrayName = returnpar(HT.findandreturn("data_stmt(" + PModule + ",_," + to_string(Right) + ",_,_,_)"), 2);
									if (HT.findfact("data_stmt(" + PModule + ",_," + to_string(Result) + ",_,_,_)"))
									{
										Resdata = returnpar(HT.findandreturn("data_stmt(" + PModule + ",_," + to_string(Result) + ",_,_,_)"), 2);
										*Next_intend = Intend;
										ss << Intend;
										ss << print_possible_return(PModule, ResData, ArrayName, " = ", "c", &DoIt);
										ss << print_after_return6(DoIt, ArrayName, Index);
										ss << ";" << endl;
									}
								}
							}
						}
					}
				}
				else if (Right < 0)
				{
					if (not_a_for_loop(PModule, var3))
					{
						if (not_a_while_loop(PModule, var3))
						{
							if (HT.findfact("compo_stmt(" + PModule + "," + to_string(Right) + ",_)"))
							{
								Par_list = returnVec(makeInstanceOf(HT.findandreturn("compo_stmt(" + PModule + "," + to_string(Right) + ",_)")), 1);
								if (HT.findfact("data_stmt(" + PModule + ",_," + to_string(Left) + ",_,_,_)"))
								{
									ArrayName = returnpar(HT.findandreturn("data_stmt(" + PModule + ",_," + to_string(Right) + ",_,_,_)"), 2);
									if (HT.findfact("data_stmt(" + PModule + ",_," + to_string(Result) + ",_,_,_)"))
									{
										Resdata = returnpar(HT.findandreturn("data_stmt(" + PModule + ",_," + to_string(Right) + ",_,_,_)"), 2);
										*Next_intend = Intend;
										ss << Intend;
										ss << print_possible_return(PModule, ResData, ArrayName, " = ", "c", &DoIt);
										ss << print_after_return7(DoIt, ArrayName, PModule, Par_list);
										ss << ";" << endl;
									}
								}
							}
						}
					}
				}
			}
			else if (Op == 108)
			{
				if (Right > 0)
				{
					if (not_a_for_loop(PModule, var3))
					{
						if (not_a_while_loop(PModule, var3))
						{
							if (HT.findfact("data_stmt(" + PModule + ",_," + to_string(Right) + ",_,_,_)"))
							{
								Index = returnpar(HT.findandreturn("data_stmt(" + PModule + ",_," + to_string(Right) + ",_,_,_)"), 2);
								if (HT.findfact("data_stmt(" + PModule + ",_," + to_string(Left) + ",_,_,_)"))
								{
									Source = returnpar(HT.findandreturn("data_stmt(" + PModule + ",_," + to_string(Right) + ",_,_,_)"), 2);
									if (HT.findfact("data_stmt(" + PModule + "," + ArrayName + "," + to_string(Result) + ",*),  "))
									{
										if (!HT.findfact("data_stmt(" + PModule + "," + PModule + ",_,_,\"par_out\",_)"))
										{
											*Next_intend = Intend;
											ss << Intend << "(* " << ArrayName << ")[" << Index << "] = " << Source << ";" << endl;
										}
										else if (HT.findfact("data_stmt(" + PModule + "," + PModule + ",_,_,\"par_out\",_)"))
										{
											FunctionNameEntry = stoi(returnpar(HT.findandreturn("data_stmt(" + PModule + "," + PModule + ",_,_,\"par_out\",_)"), 3));
											if (HT.findfact("prog_stmt(" + PModule + ",_,0,102,0," + to_string(Result) + "," + to_string(FunctionNameEntry) + ",_)"))
											{
												*Next_intend = Intend;
												ss << Intend << " " << ArrayName << "[" << Index << "] = " << Source << ";" << endl;
											}
											else
											{
												*Next_intend = Intend;													
												ss << Intend << "(* " << ArrayName << ")[" << Index << "] = " << Source << ";" << endl;
											}
										}
									}
								}
								else if (HT.findfact("data_stmt(" + PModule + "," + ArrayName + "," + to_string(Result) + ",*)"))
								{
									if (Left < 0)
									{
										if (HT.findfact("rec_stmt(" + PModule + "," + to_string(Left) + ",*)"))
										{
											Rec_list = returnVec(makeInstanceOf(HT.findandreturn("rec_stmt(" + PModule + ", " + to_string(Right) + ",*)")), 3);
											*Next_intend = Intend;
											ss << Intend << ArrayName << "[" << Index << "] = ";
											ss << " {";
											ss << print_custom_record_index_parameters("", PModule, Rec_list, "record");
											ss << "};" << endl;
										}
									}
								}
								else if (Left < 0)
								{
									if (HT.findfact("rec_stmt(" + PModule + ", " + to_string(Left) + ",*)"))
									{
										Rec_par_list = returnVec(makeInstanceOf(HT.findandreturn("rec_stmt(" + PModule + ", " + to_string(Left) + ",*)")), 1);
										if (HT.findfact("data_stmt(" + PModule + "," + ArrayName + "," + to_string(Result) + ",*)"))
										{
											ResType = stoi(returnpar(HT.findandreturn("data_stmt(" + PModule + ",_," + to_string(Right) + ",_,_,_)"), 4));
											if (HT.findfact("type_def("+to_string(ResType)+",_,_,_,_,\"record_t\",_,_,_)"))
											{
												ResTypeName = returnpar(HT.findandreturn("type_def(" + to_string(ResType) + ",_,_,_,_,\"record_t\",_,_,_)"), 2);
												*Next_intend = Intend;
												HT.concat(ResTypeName, " ", &Result_type0);
												HT.concat(Result_type0, ArrayName, &Result_target);
												ss << Intend << Result_target << " ";
												ss << print_custom_array_index_parameters(PModule, Par_list, "verilog");
												ss << " = ";
												ss << " {";
												ss << print_custom_record_index_parameters("", PModule, Rec_list, "record");
												ss << "};" << endl;
											}
										}
									}
								}
							}
						}
					}
				}
			}
			else if (Op == 109)
			{
				if (Result > 0)
				{
					if (HT.findfact("data_stmt(" + PModule + ",_," + to_string(Result) + ",*)"))
					{
						Res_name = returnpar(HT.findandreturn("data_stmt(" + PModule + ",_," + to_string(Result) + ",*)"), 2);
						if (HT.findfact("call_stmt(" + PModule + "," + to_string(Right) + ",*)"))
						{
							Called_entry = stoi(returnpar(HT.findandreturn("call_stmt(" + PModule + "," + to_string(Right) + ",*)"), 3));
							Par_list = returnVec(makeInstanceOf(HT.findandreturn("call_stmt(" + PModule + "," + to_string(Right) + ",*)")), 4);
							if (HT.findfact("hierarchy_part(" + to_string(Called_entry) + ",_,_,\"libpart\",_,_,_)"))
							{
								Called_name = returnpar(HT.findandreturn("hierarchy_part(" + to_string(Called_entry) + ",_,_,\"libpart\",_,_,_)"), 2);
								ss << Intend;
								ss << print_possible_return(PModule, Res_name, Called_name, " = ", "c", &DoIt);
								ss << print_after_return8(DoIt, Called_name, PModule, Par_list, Res_name);
								ss << ";" << endl;
							}
						}
					}
				}
				else if (Result == 0)
				{
					if (HT.findfact("call_stmt(" + PModule + "," + to_string(Right) + ",*)"))
					{
						Called_entry = stoi(returnpar(HT.findandreturn("call_stmt(" + PModule + "," + to_string(Right) + ",*)"), 3));
						Par_list = returnVec(makeInstanceOf(HT.findandreturn("call_stmt(" + PModule + "," + to_string(Right) + ",*)")), 4);
						if (HT.findfact("hierarchy_part(" + to_string(Called_entry) + ",_,_,\"libpart\",_,_,_)"))
						{
							Called_name = returnpar(HT.findandreturn("hierarchy_part(" + to_string(Called_entry) + ",_,_,\"libpart\",_,_,_)"), 2);
							ss << Intend << Called_name << "(";
							ss << print_custom_record_index_parameters("", PModule, Par_list, "function");
							ss << ");" << endl;
						}
					}
				}
				*Next_intend = Intend;
			}
			else if (Op == 110)
			{
				if (Result >= Next_entry)
				{
					if (not_a_for_loop(PModule, var3))
					{
						if (not_a_while_loop(PModule, var3))
						{
							if (HT.findfact("nested_cond_fact(" + PModule + ",[" + PModule + "," + to_string(Next_entry) + ",\"ELSE\",_,_,_])"))
							{
								string Out_intend, Out_intend1;
								pop_cond_end(PModule);
								ss << Intend << "}" << endl;
								if (HT.concat(&Out_intend1, " ", Intend))
								{
									ss << Out_intend1 << "else " << endl;
									HT.concat(Out_intend1, " ", &Out_intend);
									ss << Out_intend << "{ " << endl;
									push_cond_end(PModule, Target, "END IF");
									HT.concat(Out_intend, " ", Next_intend);
								}
							}
						}
					}
				}
			}
		}
		else if (HT.findfact("prog_stmt(" + PModule + "," + to_string(var3) + ",_,110,_,_,_,_)"))
		{
			Target = stoi(returnpar(HT.findandreturn("prog_stmt(" + PModule + "," + to_string(var3) + ",_,110,_,_,_,_)"), 7));
			Next_entry = stoi(returnpar(HT.findandreturn("prog_stmt(" + PModule + "," + to_string(var3) + ",_,110,_,_,_,_)"), 8));
			if (Target < var3)
			{
				if (HT.findfact("for_loop(_," + PModule + ",_,_," + to_string(var3) + ",_,_,_,_,_,_,_,_,_)"))
				{
					if (HT.findfact("nested_cond_fact(" + PModule + ",[" + PModule + "," + to_string(Next_entry) + ",\"END LOOP\"])"))
					{
						pop_cond_end(PModule);
						if (HT.concat(Next_intend, " ", Intend))
						{
							ss << *Next_intend << "}" << endl;
						}
					}
				}
			}
		}
		else if (HT.findfact("prog_stmt(" + PModule + "," + to_string(var3) + ",_,106,0,_,_,_)"))
		{
			Cond_result = stoi(returnpar(HT.findandreturn("prog_stmt(" + PModule + "," + to_string(var3) + ",_,106,0,_,_,_)"), 6));
			False_target = stoi(returnpar(HT.findandreturn("prog_stmt(" + PModule + "," + to_string(var3) + ",_,106,0,_,_,_)"), 7));
			if (HT.findfact("for_loop(_," + PModule + "," + to_string(var3) + ",_,_,_,_,_,_,_,1,_,_,_)"))
			{
				End_of_loop = stoi(returnpar(HT.findandreturn("for_loop(_," + PModule + "," + to_string(var3) + ",_,_,_,_,_,_,_,1,_,_,_)"), 5));
				Increment_variable = stoi(returnpar(HT.findandreturn("for_loop(_," + PModule + "," + to_string(var3) + ",_,_,_,_,_,_,_,1,_,_,_)"), 8));
				Start_d = stoi(returnpar(HT.findandreturn("for_loop(_," + PModule + "," + to_string(var3) + ",_,_,_,_,_,_,_,1,_,_,_)"), 9));
				End_d = stoi(returnpar(HT.findandreturn("for_loop(_," + PModule + "," + to_string(var3) + ",_,_,_,_,_,_,_,1,_,_,_)"), 10));
				if (False_target == End_of_loop + 1)
				{
					if (HT.findfact("data_stmt(" + PModule + ",_," + to_string(Increment_variable) + ",_,\"var\",sym(*))"))
					{
						Inc_var_name = returnpar(HT.findandreturn("data_stmt(" + PModule + ",_," + to_string(Increment_variable) + ",_,\"var\",sym(*))"), 2);
						push_cond_end(PModule, False_target, "END LOOP");
						ss << Intend << " for(" << Inc_var_name << "=";
						ss << type_value(PModule, Start_d, "verilog");
						ss << ";" << Inc_var_name << "<=";
						ss << type_value(PModule, End_d, "verilog");
						ss << ";" << Inc_var_name << "=" << Inc_var_name << "+1)" << endl;
						HT.concat(Intend, " ", &Next_intend1);
						ss << Next_intend1 << " {" << endl;
						HT.concat(Next_intend1, " ", Next_intend);
					}
				}
			}
			else if (HT.findfact("while_loop(_," + PModule + "," + to_string(var3) + ",_,_,_,_)"))
			{
				End_of_loop = stoi(returnpar(HT.findandreturn("while_loop(_," + PModule + "," + to_string(var3) + ",_,_,_,_)"), 5));
				if (HT.findfact("data_stmt(" + PModule + ",_," + to_string(Cond_result) + ",_,_,_)"))
				{
					Cond_name = returnpar(HT.findandreturn("data_stmt(" + PModule + ",_," + to_string(Cond_result) + ",_,_,_)"), 2);
					if (False_target == End_of_loop + 1)
					{
						push_cond_end(PModule, False_target, "END LOOP");
						ss << Intend << " while (" << Cond_name << ") " << endl;
						HT.concat(Intend, " ", &Next_intend1);
						ss << Next_intend1 << " {" << endl;
						HT.concat(Next_intend1, " ", Next_intend);
					}
				}
			}
		}
		else if (HT.findfact("prog_stmt(" + PModule + "," + to_string(var3) + ",_,110,0,_,_,_)"))
		{
			False_target = stoi(returnpar(HT.findandreturn("prog_stmt(" + PModule + "," + to_string(var3) + ",_,110,0,_,_,_)"), 7));
			Next_entry = stoi(returnpar(HT.findandreturn("prog_stmt(" + PModule + "," + to_string(var3) + ",_,110,0,_,_,_)"), 8));
			if (False_target < var3)
			{
				if (HT.findfact("while_loop(_," + PModule + ",_,_," + to_string(var3) + ",_,_)"))
				{
					If_statement = stoi(returnpar(HT.findandreturn("while_loop(_," + PModule + "," + to_string(var3) + ",_," + to_string(var3) + ",_,_)"), 3));
					Condition_start = stoi(returnpar(HT.findandreturn("while_loop(_," + PModule + "," + to_string(var3) + ",_," + to_string(var3) + ",_,_)"), 4));
					Body_last = stoi(returnpar(HT.findandreturn("while_loop(_," + PModule + "," + to_string(var3) + ",_," + to_string(var3) + ",_,_)"), 7));
					if (Condition_start < If_statement)
					{
						if (var3 == Body_last + 1)
						{
							if (End_of_loop == Body_last + 1)
							{
								Condition_end = If_statement - 1;
								if (HT.findfact("nested_cond_fact(" + PModule + ",[" + PModule + "," + to_string(Next_entry) + ",\"END LOOP\"])"))
								{
									pop_cond_end(PModule);
									print_while_loop_tail_cond(PModule, Condition_start, Condition_end, var3, Intend, Next_intend, "c");
								}
							}
						}
					}
					else if (Condition_start == If_statement)
					{
						if (HT.concat(Next_intend, " ", Intend))
							ss << write_end_of_loop(*Next_intend, Lang) << endl;
					}
				}
			}
		}
	}
	return ss.str();
}

bool not_a_for_loop(string PModule, int Operation)
{
	return (!HT.findfact("for_loop(_," + PModule + ",_,_,_,_," + to_string(Operation) + ",_,_,_,_,_,_,_)") ||
		!HT.findfact("for_loop(_," + PModule + ",_,_,_," + to_string(Operation) + ",_,_,_,_,_,_,_,_)") ||
		!HT.findfact("for_loop(_," + PModule + ",_,_," + to_string(Operation) + ",_,_,_,_,_,_,_,_,_)") ||
		!HT.findfact("for_loop(_," + PModule + ",_," + to_string(Operation) + ",_,_,_,_,_,_,_,_,_,_)") ||
		!HT.findfact("for_loop(_," + PModule + "," + to_string(Operation) + ",_,_,_,_,_,_,_,_,_,_,_)"));
}

bool not_a_while_loop(string PModule, int Operation)
{
	return (!HT.findfact("while_loop(_," + PModule + "," + to_string(Operation) + ",_,_,_,_)") ||
		!HT.findfact("while_loop(_," + PModule + ",_,_," + to_string(Operation) + ",_,_)"));
}

void conv_kind(string PModule, string Data, string* Kind)
{
	int Increment_variable;
	if (HT.findfact("data_stmt(" + PModule + ","+Data+",*)"))
	{
		*Kind = returnpar(HT.findandreturn("data_stmt(" + PModule + "," + Data + ",*)"), 4);
		Increment_variable = stoi(returnpar(HT.findandreturn("data_stmt(" + PModule + "," + Data + ",*)"), 3));
		if (HT.findfact("for_loop(_," + PModule + ",_,_,_,_,_," + to_string(Increment_variable) + ",_,_,_,_,_,_)"))
			*Kind = "loop_var";
	}
}

bool is_relational_op(string str)
{
	return str == "=" && str == "<" && str == "<=" && str == ">"
		&& str == ">=" && str == "and" && str == "or" && str == "xor" && str == "not";
}

string type_op_triple(string Module_name, string Res_name, string Left_name, string Right_name, string Res_kind, string Left_kind, string Right_kind, string Op_string, string Assignment_string, string Hdl)
{
	stringstream ss;
	int Res_type, Res_size, Res_upper, Right_type, Right_size;
	if (mod_or_rem_operator(Op_string))
	{
		if (Hdl == "vhdl")
		{
			if (HT.findfact("hdl_style(\"vhdl\")"))
			{
				if (HT.findfact("data_stmt(" + Module_name + "," + Res_name + ",*)"))
				{
					Res_type = stoi(returnpar(HT.findandreturn("data_stmt(" + Module_name + "," + Res_name + ",*)"), 4));
					if (HT.findfact("type_def(" + to_string(Res_type) + ",_,1,_,_,_,_,_,_)"))
					{
						if (HT.findfact("data_stmt(" + Module_name + "," + Right_name + ",*)"))
						{
							Right_type = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Res_type) + ",*)"), 4));
							if (HT.findfact("type_def(" + to_string(Right_type) + ",*)"))
							{
								Right_size = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Right_type) + ",*)"), 3));
								ss << print_possible_return(Module_name, Res_name, Right_name, Assignment_string, "vhdl", 0);
								ss << "conv_std_logic_vector(CONV_INTEGER(";
								ss << Left_name << ") ";
								ss << write_mod_rem_operator("vhdl", Op_string);
								ss << " CONV_INTEGER(";
								ss << Right_name;
								ss << "), " << Right_size << ") (0);";
							}
						}
					}
					else if (HT.findfact("type_def(" + to_string(Res_type) + ",*)"))
					{
						Res_size = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Res_type) + ",*)"), 3));
						if (Res_type > 1)
						{
							if (Res_size > 1)
							{
								Res_upper = Res_size - 1;
								if (HT.findfact("data_stmt(" + Module_name + "," + Right_name + ",*)"))
								{
									Right_type = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Res_type) + ",*)"), 4));
									if (HT.findfact("type_def(" + to_string(Right_type) + ",*)"))
									{
										Right_size = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Right_type) + ",*)"), 3));
										ss << print_possible_return(Module_name, Res_name, Right_name, Assignment_string, "vhdl", 0);
										ss << "conv_std_logic_vector(CONV_INTEGER(";
										ss << Left_name;
										ss << ") ";
										ss << write_mod_rem_operator("vhdl", Op_string);
										ss << " CONV_INTEGER(";
										ss << Right_name;
										ss << "), " << Right_size << ") (" << Res_upper << " downto 0);";
									}
								}
							}
						}
					}
				}
			}
		}
		else if (Hdl == "verilog")
		{
			if (HT.findfact("data_stmt(" + Module_name + "," + Res_name + ",*)"))
			{
				Res_type = stoi(returnpar(HT.findandreturn("data_stmt(" + Module_name + "," + Res_name + ",*)"), 4));
				if (HT.findfact("type_def(" + to_string(Res_type) + ",*)"))
				{
					Res_size = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Res_type) + ",*)"), 3));
					if (Res_size > 1)
					{
						ss << Res_name << Assignment_string << Left_name << " ";
						ss << write_mod_rem_operator(Hdl, Op_string);
						ss << " " << Right_name << ";";
					}
				}
			}
		}
		else if (Hdl == "c")
		{
			if (HT.findfact("data_stmt(" + Module_name + "," + Res_name + ",_,_,\"par_out\",_)"))
			{
				Res_type = stoi(returnpar(HT.findandreturn("data_stmt(" + Module_name + "," + Res_name + ",_,_,\"par_out\",_)"), 4));
				if (HT.findfact("print_C_main_body(1)"))
				{
					if (HT.findfact("type_def(" + to_string(Res_type) + ",*)"))
					{
						Res_size = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Res_type) + ",*)"), 3));
						if (Res_size > 1)
						{
							ss << Res_name << Assignment_string << Left_name << " ";
							ss << write_mod_rem_operator(Hdl, Op_string);
							ss << " ", Right_name, ";";
						}
					}
				}
				else if (!HT.findfact("print_C_main_body(*)"))
				{
					if (HT.findfact("type_def(" + to_string(Res_type) + ",*)"))
					{
						Res_size = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Res_type) + ",*)"), 3));
						if (Res_size > 1)
						{
							ss << "*" << Res_name << Assignment_string << Left_name << " ";
							ss << write_mod_rem_operator(Hdl, Op_string);
							ss << " " << Right_name << ";";
						}
					}
				}
				
			}
			else if (HT.findfact("data_stmt(" + Module_name + "," + Res_name + ",_,_,\"par_inout\",_)"))
			{
				Res_type = stoi(returnpar(HT.findandreturn("data_stmt(" + Module_name + "," + Res_name + ",_,_,\"par_inout\",_)"), 4));
				if (HT.findfact("print_C_main_body(1)"))
				{
					if (HT.findfact("type_def(" + to_string(Res_type) + ",*)"))
					{
						Res_size = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Res_type) + ",*)"), 3));
						if (Res_size > 1)
						{
							ss << Res_name << Assignment_string << Left_name << " ";
							ss << write_mod_rem_operator(Hdl, Op_string);
							ss << " ", Right_name, ";";
						}
					}
				}
				else if (!HT.findfact("print_C_main_body(*)"))
				{
					if (HT.findfact("type_def(" + to_string(Res_type) + ",*)"))
					{
						Res_size = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Res_type) + ",*)"), 3));
						if (Res_size > 1)
						{
							ss << "*" << Res_name << Assignment_string << Left_name << " ";
							ss << write_mod_rem_operator(Hdl, Op_string);
							ss << " " << Right_name << ";";
						}
					}
				}
			}
		}
		else if (Hdl != "vhdl")
		{
			if (HT.findfact("data_stmt(" + Module_name + "," + Res_name + ",*)"))
			{
				Res_type = stoi(returnpar(HT.findandreturn("data_stmt(" + Module_name + "," + Res_name + ",*)"), 4));
				if (HT.findfact("type_def(" + Res_name + ",_,1,_,_,_,_,_,_"))
				{
					ss << Res_name << Assignment_string << Left_name << " ";
					ss << write_mod_rem_operator(Hdl, Op_string);
					ss << " " << Right_name << ";";
					return ss.str();
				}
				Res_kind = returnpar(HT.findandreturn("data_stmt(" + Module_name + "," + Res_name + ",*)"), 5);
				if (Res_kind != "par_out")
				{
					if (Res_kind != "par_inout")
					{
						if (HT.findfact("type_def(" + to_string(Res_type) + ",*)"))
						{
							Res_size = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Res_type) + ",*)"), 3));
							if (Res_size > 1)
							{
								ss << Res_name << Assignment_string << Left_name << " ";
								write_mod_rem_operator(Hdl, Op_string);
								ss << " " << Right_name << ";";
							}
						}
					}
				}
			}
		}
	}
	if (Op_string != "*")
	{
		if (Op_string != "/")
		{
			if (Op_string != "**")
			{
				if (Module_name != Res_name)
				{
					if (Res_kind != "par_inout")
					{
						ss << Res_name;
						ss << Assignment_string;
						if (HT.findfact("hdl_style(" + Hdl + ")"))
						{
							ss << writevhdl(Hdl, Module_name, Left_name, Left_kind);
							ss << " ";
							ss << write_hdl_dep_operator_symbol(Op_string, Hdl);
							ss << " ";
							ss << writevhdl(Hdl, Module_name, Right_name, Right_kind);
							ss << ";";
						}
					}
					else if (Res_kind == "par_inout")
					{
						ss << Res_name << "_regout";
						ss << " <= ";
						if (HT.findfact("hdl_style(" + Hdl + ")"))
						{
							ss << writevhdl(Hdl, Module_name, Left_name, Left_kind);
							ss << " ";
							ss << write_hdl_dep_operator_symbol(Op_string, Hdl);
							ss << " ";
							ss << writevhdl(Hdl, Module_name, Right_name, Right_kind);
							ss << ";";
						}
					}
				}
				else if (Module_name == Res_name)
				{
					if (HT.findfact("hdl_style(" + Hdl + ")"))
					{
						// related to functions with argument _ (* in definition) : pass in nullptr argument and regulate the body in such way as both cases with nullptr or otherwise are handled correctly.
						ss << print_possible_return(Module_name, Res_name, Left_name, Assignment_string, Hdl, 0);
						ss << writevhdl(Hdl, Module_name, Left_name, Left_kind);
						ss << " ";
						ss << write_hdl_dep_operator_symbol(Op_string, Hdl);
						ss << " ";
						ss << writevhdl(Hdl, Module_name, Right_name, Right_kind);
						ss << ";";
					}
				}
			}
			else if (Hdl == "vhdl")
			{
				if (HT.findfact("hdl_style(\"vhdl\")"))
				{
					if (HT.findfact("data_stmt(" + Module_name + "," + Res_name + ",*)"))
					{
						Res_type = stoi(returnpar(HT.findandreturn("data_stmt(" + Module_name + "," + Res_name + ",*)"), 4));
						if (HT.findfact("type_def(" + to_string(Res_type) + ",*)"))
						{
							Res_size = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Res_type) + ",*)"), 3));
							print_possible_return(Module_name, Res_name, Left_name, Assignment_string, "vhdl", 0);
							ss << "conv_std_logic_vector(CONV_INTEGER(";
							ss << Left_name;
							ss << ") ** CONV_INTEGER(";
							ss << Right_name;
							ss << "), " << Res_size << ");";
						}
					}
				}
			}
			else if (Hdl != "vhdl")
			{
				if (HT.findfact("data_stmt(" + Module_name + "," + Res_name + ",*)"))
				{
					Res_type = stoi(returnpar(HT.findandreturn("data_stmt(" + Module_name + "," + Res_name + ",*)"), 4));
					if (HT.findfact("type_def(" + to_string(Res_type) + ",*)"))
					{
						ss << Res_name << Assignment_string << Left_name << " ** " << Right_name << ";";
					}
				}
			}
		}
		else if (Hdl == "vhdl")
		{
			if (HT.findfact("hdl_style(\"vhdl\")"))
			{
				if (HT.findfact("data_stmt(" + Module_name + "," + Res_name + ",*)"))
				{
					Res_type = stoi(returnpar(HT.findandreturn("data_stmt(" + Module_name + "," + Res_name + ",*)"), 4));
					if (HT.findfact("type_def(" + to_string(Res_type) + ",*)"))
					{
						Res_size = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Res_type) + ",*)"), 3));
						ss << print_possible_return(Module_name, Res_name, Left_name, Assignment_string, "vhdl", 0);
						ss << "conv_std_logic_vector(CONV_INTEGER(";
						ss << Left_name;
						ss << ") / CONV_INTEGER(";
						ss << Right_name;
						ss << "), " << Res_size << ");";
					}
				}
			}
		}
		else if(Hdl == "c")
		{
			if (HT.findfact("data_stmt(" + Module_name + "," + Res_name + ",_,_,\"par_out\",_)")) 
			{
				Res_type = stoi(returnpar(HT.findandreturn("data_stmt(" + Module_name + "," + Res_name + ",_,_,\"par_out\",_)"), 4));
				if (!HT.findfact("print_C_main_body(*)"))
					if (HT.findfact("type_def(" + to_string(Res_type) + ",*)"))
						ss << "*" << Res_name << Assignment_string << Left_name << " / " << Right_name << ";";
				else if (HT.findfact("print_C_main_body(1)"))
					if (HT.findfact("type_def(" + to_string(Res_type) + ",*)"))
						ss << Res_name << Assignment_string << Left_name << " / " << Right_name << ";";
			}
			else if (HT.findfact("data_stmt(" + Module_name + "," + Res_name + ",_,_,\"par_inout\",_)"))
			{
				Res_type = stoi(returnpar(HT.findandreturn("data_stmt(" + Module_name + "," + Res_name + ",_,_,\"par_inout\",_)"), 4));
				if (!HT.findfact("print_C_main_body(*)"))
					if (HT.findfact("type_def(" + to_string(Res_type) + ",*)"))
						ss << "*" << Res_name << Assignment_string << Left_name << " / " << Right_name << ";";
					else if (HT.findfact("print_C_main_body(1)"))
						if (HT.findfact("type_def(" + to_string(Res_type) + ",*)"))
							ss << Res_name << Assignment_string << Left_name << " / " << Right_name << ";";
			}
			else if (HT.findfact("data_stmt(" + Module_name + "," + Res_name + ",*)"))
			{
				Res_type = stoi(returnpar(HT.findandreturn("data_stmt(" + Module_name + "," + Res_name + ",*)"), 4));
				Res_kind = returnpar(HT.findandreturn("data_stmt(" + Module_name + "," + Res_name + ",*)"), 5);
				if (Res_kind != "par_out")
				{
					if (Res_kind != "par_inout")
					{
						if (HT.findfact("type_def(" + to_string(Res_type) + ",*)"))
							ss << Res_name << Assignment_string << Left_name << " / " << Right_name << ";";
					}
				}
			}
		}
		else if (Hdl == "verilog")
		{
			if (HT.findfact("data_stmt(" + Module_name + "," + Res_name + ",_,_,\"par_out\",_)"))
			{
				Res_type = stoi(returnpar(HT.findandreturn("data_stmt(" + Module_name + "," + Res_name + ",_,_,\"par_out\",_)"), 4));
				//Res_kind = returnpar(HT.findandreturn("data_stmt(" + Module_name + "," + Res_name + ",*)"), 5);
				if (HT.findfact("print_C_main_body(1)"))
					if (HT.findfact("type_def(" + to_string(Res_type) + ",*)"))
						ss << Res_name << Assignment_string << Left_name << " / " << Right_name << ";";
			}
			else if (HT.findfact("data_stmt(" + Module_name + "," + Res_name + ",_,_,\"par_inout\",_)"))
			{
				Res_type = stoi(returnpar(HT.findandreturn("data_stmt(" + Module_name + "," + Res_name + ",_,_,\"par_inout\",_)"), 4));
				if (HT.findfact("print_C_main_body(1)"))
					if (HT.findfact("type_def(" + to_string(Res_type) + ",*)"))
						ss << Res_name << Assignment_string << Left_name << " / " << Right_name << ";";
			}
		}
	}
	else if (Hdl == "vhdl")
	{
		if (HT.findfact("hdl_style(\"vhdl\")"))
		{
			if (HT.findfact("data_stmt(" + Module_name + "," + Res_name + ",*)"))
			{
				Res_type = stoi(returnpar(HT.findandreturn("data_stmt(" + Module_name + "," + Res_name + ",*)"), 4));
				if (HT.findfact("type_def(" + to_string(Res_type) + ",*)"))
				{
					Res_size = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Res_type) + ",*)"), 3));
					ss << print_possible_return(Module_name, Res_name, Left_name, Assignment_string, "vhdl", 0);
					ss << "conv_std_logic_vector(CONV_INTEGER(";
					ss << Left_name;
					ss << ") * CONV_INTEGER(";
					ss << Right_name;
					ss << "), " << Res_size << ");";

				}
			}
		}
	}
	else if (Hdl != "vhdl")
		ss << Res_name << Assignment_string << " " << Left_name << " * " << Right_name << ";";
	return ss.str();
}

string writevhdl(string HDL, string Module_name, string Dname, string Kind)
{
	stringstream ss;
	int Type;
	if (HDL == "verilog")
		ss << Dname;
	else if (Kind != "loop_var")
		ss << Dname;
	else if (!HT.findfact("custom_block("+ Module_name +")"))
		ss << Dname;
	else if (HDL == "vhdl")
	{
		if (HT.findfact("data_stmt(" + Module_name + "," + Dname + ",*)"))
		{
			Type = stoi(returnpar(HT.findandreturn("data_stmt(" + Module_name + "," + Dname + ",*)"), 4));
			parent_type_is_integer(Type, 0);
			ss << Dname;
		}
	}
	else if(HDL == "c")
	{
		ss << Dname;
	}
	return ss.str();
}

string write_hdl_dep_operator_symbol(string Symbol, string HDL)
{
	stringstream ss;
	if (HDL == "vhdl")
	{
		if (Symbol != "<count>" && Symbol != "<increm>" && Symbol != "<decrem>" &&
		Symbol != "<ifthen>" && Symbol != "<read>" && Symbol != "<write>" &&
		Symbol != "<call>" && Symbol != "<jump>")
			ss << Symbol;
		else if (Symbol == "<count>")
			ss << "+";
		else if (Symbol == "<increm>")
			ss << "+";
		else if (Symbol == "<decrem>")
			ss << "-";
	}
	else if (HDL == "verilog")
	{
		if (Symbol == "and")
			ss << " & ";
		else if (Symbol == "or")
			ss << " | ";
		else if (Symbol == "not")
			ss << " ~";
		else if (Symbol == "xor")
			ss << " ^ ";
		else if (Symbol == "/=")
			ss << " != ";
		else if (Symbol == "=")
			ss << "==";
		else if (Symbol == "<" && Symbol == ">" && Symbol == "<=" && Symbol == ">=" && Symbol == "+" && Symbol == "-" && Symbol == "*" && Symbol == "/")
			ss << Symbol;
		else if (Symbol == "mod")
			ss << "%";
		else if (Symbol == "rem")
			ss << " remainder operator doesn't exist in Verilog";
		else if (Symbol == "abs")
			ss << " absolute value operator doesn't exist in Verilog";
	}
	else if (HDL == "c")
	{
		if (Symbol == "and")
			ss << " && ";
		else if (Symbol == "or")
			ss << " || ";
		else if (Symbol == "not")
			ss << " !";
		else if (Symbol == "xor")
			ss << " ^ ";
		else if (Symbol == "/=")
			ss << " != ";
		else if (Symbol == "=")
			ss << "==";
		else if (Symbol == "<" && Symbol == ">" && Symbol == "<=" && Symbol == ">=" && Symbol == "+" && Symbol == "-" && Symbol == "*" && Symbol == "/")
			ss << Symbol;
		else if (Symbol == "mod")
			ss << " % ";
		else if (Symbol == "rem")
			ss << " % ";
		else if (Symbol == "abs")
			ss << " abs(";
		else if (Symbol == "<count>")
			ss << " + ";
		else if (Symbol == "<increm>")
			ss << " + ";
		else if (Symbol == "<decrem>")
			ss << " - ";
		else if (Symbol == "<ifthen>")
			ss << " if ";
		else if (Symbol == "**")
			ss << " The power operator doesn't exist in ANSI-C ";
	}
	return ss.str();
}

string print_possible_return(string PModule, string ResData, string RightData, string Assignment_string, string HDL, int* int1)
{
	stringstream ss;
	int ResType;
	string Kind, TypeKind;
	if (HDL != "c")
	{
		if (PModule != ResData)
		{
			if (!HT.findfact("mem_port(_,_," + PModule + "," + PModule + ",_,_,_,_,_,_,_,_,_)"))
			{
				ss << ResData << Assignment_string;
				*int1 = 1;
			}
		}
		else if(PModule == ResData)
		{
			if (!HT.findfact("mem_port(_,_," + ResData + "," + ResData + ",_,_,_,_,_,_,_,_,_)"))
			{
				ss << ResData << "_function " << Assignment_string << " ";
				*int1 = 1;
			}
		}
	}
	else
	{
		if (PModule != ResData)
		{
			if (!HT.findfact("mem_port(_,_," + PModule + "," + PModule + ",_,_,_,_,_,_,_,_,_)"))
			{
				if (HT.findfact("print_C_main_body(1)"))
				{
					if (HT.findfact("data_stmt(" + PModule + "," + ResData + ",_,_,\"par_out\",_)"))
					{
						ResType = stoi(returnpar(HT.findandreturn("data_stmt(" + PModule + "," + ResData + ",_,_,\"par_out\",_)"), 4));
						if (parent_type_is_integer(ResType, 0))
							ss << ResData << Assignment_string << " (long long int) ";
					}
					else if (HT.findfact("data_stmt(" + PModule + "," + ResData + ",_,_,\"par_inout\",_)"))
					{
						ResType = stoi(returnpar(HT.findandreturn("data_stmt(" + PModule + "," + ResData + ",_,_,\"par_inout\",_)"), 4));
						if (parent_type_is_integer(ResType, 0))
							ss << ResData << Assignment_string << " (long long int) ";
					}
					*int1 = 1;
				}
				else if (!HT.findfact("print_C_main_body(*)"))
				{
					if (HT.findfact("data_stmt(" + PModule + "," + ResData + ",_,_,\"par_out\",_)"))
					{
						ResType = stoi(returnpar(HT.findandreturn("data_stmt(" + PModule + "," + ResData + ",_,_,\"par_out\",_)"), 4));
						if (parent_type_is_integer(ResType, 0))
							ss << "*" << ResData << Assignment_string << " (long long int) ";
					}
					else if (HT.findfact("data_stmt(" + PModule + "," + ResData + ",_,_,\"par_inout\",_)"))
					{
						ResType = stoi(returnpar(HT.findandreturn("data_stmt(" + PModule + "," + ResData + ",_,_,\"par_inout\",_)"), 4));
						if (parent_type_is_integer(ResType, 0))
							ss << "*" << ResData << Assignment_string << " (long long int) ";
					}
					*int1 = 1;
				}
				else if (HT.findfact("data_stmt(" + PModule + "," + ResData + ",_,_,_,_)"))
				{
					ResType = stoi(returnpar(HT.findandreturn("data_stmt(" + PModule + "," + ResData + ",_,_,_,_)"), 4));
					Kind = returnpar(HT.findandreturn("data_stmt(" + PModule + "," + ResData + ",_,_,_,_)"), 5);
					if (Kind != "par_out")
					{
						if (Kind != "par_inout")
						{
							if (parent_type_is_integer(ResType, 0))
								ss << ResData << Assignment_string << " (long long int) ";
						}
					}
					else if (!parent_type_is_integer(ResType, 0))
					{
						ss << ResData << Assignment_string;
					}
					*int1 = 1;
				}
			}
		}
		else if (PModule == ResData)
		{
			if (!HT.findfact("mem_port(_,_," + ResData + "," + ResData + ",_,_,_,_,_,_,_,_,_)"))
			{
				if (HT.findfact("data_stmt(" + ResData + "," + ResData + ",_,_,\"par_out\",_)"))
				{
					ResType = stoi(returnpar(HT.findandreturn("data_stmt(" + ResData + "," + ResData + ",_,_,\"par_out\",_)"), 4));
					if (HT.findfact("type_def(" + to_string(ResType) + ",_,_,_,_,\"vectorarray_t\",_,_,_)"))
					{
						ss << "return &" << RightData;
						*int1 = 1;
					}
					if (HT.findfact("type_def(" + to_string(ResType) + ",_,_,_,_,_,_,_,_)"))
					{
						TypeKind = stoi(returnpar(HT.findandreturn("type_def(" + to_string(ResType) + ",_,_,_,_,_,_,_,_)"), 4));
						if (TypeKind == "vectorarray_t")
						{
							ss << "return " << RightData;
							*int1 = 1;
						}
					}

				}
			}
		}
	}
	return ss.str();
}

bool mod_or_rem_operator(string Op_symbol)
{
	return Op_symbol == "mod" || Op_symbol == "rem";
}

string write_mod_rem_operator(string HDL, string Symbol)
{
	stringstream ss;
	if (Symbol == "mod")
	{
		if (HDL == "vhdl")
			ss << "mod";
		else if (HDL == "verilog" || HDL == "c")
			ss << "%";
	}
	else if (Symbol == "rem")
	{
		if (HDL == "vhdl")
			ss << "rem";
		else if (HDL == "verilog" || HDL == "c")
			ss << "%";
	}
	return ss.str();
}

string print_custom_record_index_parameters(string Module, string Module_name, vector<int> Rec_list, string Kind)
{
	stringstream ss;
	if (!Rec_list.empty())
	{
		ss << print_custom_record_index_parameter(Module_name, Rec_list.front(), Kind);
		Rec_list.erase(Rec_list.begin()); //transforming Rec_list to Par_tail
		ss << print_custom_record_index_comma_cond(Rec_list, Kind);
		ss << print_custom_record_index_parameters(Module, Module_name, Rec_list, Kind);
	}
	return ss.str();
}

string print_custom_record_index_parameter(string PModule, int Parameter, string Kind)
{
	stringstream ss;
	string HDL, Par_name, Type_kind;
	int Type;
	if (Kind == "record")
	{
		if (HT.findfact("hdl_style(\"c\")"))
		{
			if (HT.findfact("data_stmt(" + PModule + ",_," + to_string(Parameter) + ",_,_,_)"))
			{
				Par_name = returnpar(HT.findandreturn("data_stmt(" + PModule + ",_," + to_string(Parameter) + ",_,_,_)"), 2);
				ss << Par_name;
			}
		}
	}
	else if (Kind != "constants")
	{
		if (Kind != "function")
		{
			if (HT.findfact("hdl_style(*)"))
			{
				HDL = returnpar(HT.findandreturn("hdl_style(*)"), 1);
				if (HDL != "c")
				{
					if (HT.findfact("data_stmt(" + PModule + ",_," + to_string(Parameter) + ",_,_,_)"))
					{
						Par_name = returnpar(HT.findandreturn("data_stmt(" + PModule + ",_," + to_string(Parameter) + ",_,_,_)"), 2);
						ss << Par_name;
					}
				}
			}
		}
		else if (Kind == "function")
		{
			if (HT.findfact("hdl_style(\"c\")"))
			{
				if (HT.findfact("data_stmt(" + PModule + ",_," + to_string(Parameter) + ",_,_,_)"))
				{
					Par_name = returnpar(HT.findandreturn("data_stmt(" + PModule + ",_," + to_string(Parameter) + ",_,_,_)"), 2);
					Type = stoi(returnpar(HT.findandreturn("data_stmt(" + PModule + ",_," + to_string(Parameter) + ",_,_,_)"), 4));
					Kind = returnpar(HT.findandreturn("data_stmt(" + PModule + ",_," + to_string(Parameter) + ",_,_,_)"), 5);
					if (Kind == "par_in")
						ss << Par_name;
					else if (HT.findfact("type_def(" + to_string(Type) + ",_,_,_,_,\"vectorarray_t\",_,_,_)"))
					{
						if (Kind != "par_in")
							ss << Par_name;
					}
					else if (HT.findfact("type_def(" + to_string(Type) + ",*)"))
					{
						Type_kind = returnpar(HT.findandreturn("type_def(" + to_string(Type) + ",*)"), 6);
						if (Type_kind != "vectorarray_t")
						{
							if (Kind != "par_in")
								ss << "&" << Par_name;
						}
					}
				}
			}
			else if (HT.findfact("hdl_style(*)"))
			{
				HDL = returnpar(HT.findandreturn("hdl_style(*)"), 1);
				if (HDL != "vhdl")
				{
					if (HT.findfact("data_stmt(" + PModule + ",_," + to_string(Parameter) + ",_,_,_)"))
					{
						Par_name = returnpar(HT.findandreturn("data_stmt(" + PModule + ",_," + to_string(Parameter) + ",_,_,_)"), 2);
						ss << Par_name;
					}
				}
				else if (HDL == "vhdl")
				{
					if (HT.findfact("data_stmt(" + PModule + ",_," + to_string(Parameter) + ",_,_,_)"))
					{
						Par_name = returnpar(HT.findandreturn("data_stmt(" + PModule + ",_," + to_string(Parameter) + ",_,_,_)"), 2);
						Kind = returnpar(HT.findandreturn("data_stmt(" + PModule + ",_," + to_string(Parameter) + ",_,_,_)"), 5);
						if (Kind != "const")
							ss << Par_name;
						if (Kind == "const")
							ss << "var" << Par_name;
					}
				}
			}
		}
	}
	else if (Kind == "constants")
	{
		if (HT.findfact("hdl_style(*)"))
		{
			HDL = returnpar(HT.findandreturn("hdl_style(*)"), 1);
			if (HDL != "c")
			{
				if (HT.findfact("data_stmt(" + PModule + ",_," + to_string(Parameter) + ",_,_,_)"))
				{
					Par_name = returnpar(HT.findandreturn("data_stmt(" + PModule + ",_," + to_string(Parameter) + ",_,_,_)"), 2);
					Kind = returnpar(HT.findandreturn("data_stmt(" + PModule + ",_," + to_string(Parameter) + ",_,_,_)"), 5);
					if (Kind != "const")
						ss << "     var" << Par_name << " := " << Par_name << ";" << endl;
				}
			}
		}
	}
	return ss.str();
}

string print_custom_record_index_comma_cond(vector<int> Rec_list, string Kind)
{
	stringstream ss;
	if (!Rec_list.empty() && Kind != "constants")
		ss << ", ";
	return ss.str();
}

void push_cond_end(string PModule, int Entry, string Kind)
{
	vector<nested_conditional_end> Org_stack;
	if (HT.findfact("nested_cond_fact(" + PModule + ",*)"))
	{
		Org_stack = return_nested_conditional_end(makeInstanceOf(HT.findandreturn("nested_cond_fact(" + PModule + ",*)")));
		if (!Org_stack.empty())
		{
			HT.retractall("nested_cond_fact(" + PModule + ",*)");
			HT.assertz("nested_cond_fact(" + PModule + ",[" + PModule + "," + to_string(Entry) + "," + Kind + "])");
		}
		else
		{
			vector<nested_conditional_end> New_stack;
			nested_conditional_end headbegin(PModule, Entry, Kind);
			New_stack.push_back(headbegin);
			for (int i = 0; i < Org_stack.size(); i++)
				New_stack.push_back(Org_stack[i]);
			HT.retractall("nested_cond_fact(" + PModule + ",*)");
			HT.assertz("nested_cond_fact(" + PModule + ","+nce_str(New_stack)+")");
		}
	}
	else if (!HT.findfact("nested_cond_fact(" + PModule + ",*)"))
	{
		HT.assertz("nested_cond_fact(" + PModule + ",[" + PModule + "," + to_string(Entry) + "," + Kind + "])");
	}
}

string print_custom_array_index_parameters(string Module_name, vector<int> Par_list, string HDL)
{
	stringstream ss;
	if (!Par_list.empty())
	{
		ss << print_custom_array_index_parameter(Module_name, Par_list.front(), HDL);
		Par_list.erase(Par_list.begin()); //transforming Par_list to Par_tail		
		ss << print_custom_array_index_parameters(Module_name, Par_list, HDL);
	}
	return ss.str();
}

string print_custom_array_index_parameter(string PModule, int Parameter, string HDL)
{
	stringstream ss;
	string Par_name;
	if (HT.findfact("data_stmt(" + PModule + ",_," + to_string(Parameter) + ",_,_,_)"))
	{
		Par_name = returnpar(HT.findandreturn("data_stmt(" + PModule + ",_," + to_string(Parameter) + ",_,_,_)"), 2);
		if (HDL == "vhdl")
			ss << "(CONV_INTEGER(" << Par_name << "))";
		else if (HDL == "verilog")
			ss << "[" << Par_name << "]";
	}
	return ss.str();
}

void pop_cond_end(string PModule)
{
	vector<nested_conditional_end> Tstack;
	if (HT.findfact("nested_cond_fact(" + PModule + ",*)"))
	{
		Tstack = return_nested_conditional_end(makeInstanceOf(HT.findandreturn("nested_cond_fact(" + PModule + ",*)")));
		if (!Tstack.empty())
		{
			HT.retractall("nested_cond_fact(" + PModule + ",*)");
			HT.assertz("nested_cond_fact(" + PModule + "," + nce_str(Tstack) + ")");
		}
	}
}

string print_while_loop_tail_cond(string PModule, int Cond_stmt, int Condition_end, int End_of_loop, string Intend, string* Out_intend, string Lang)
{
	stringstream ss;
	int If_then_stmt, Next_cond_stmt;
	if (Cond_stmt == Condition_end)
	{
		If_then_stmt = Cond_stmt + 1;
		if (HT.findfact("while_loop(_," + PModule + "," + to_string(If_then_stmt) + ",_,_,_,_)"))
		{
			ss << print_custom_statement("", PModule, Cond_stmt, Intend, Out_intend, Lang);
			ss << write_end_of_loop(*Out_intend, Lang) << endl;
		}
	}
	else if (Cond_stmt == End_of_loop)
	{
		If_then_stmt = Condition_end + 1;
		if (HT.findfact("while_loop(_," + PModule + "," + to_string(If_then_stmt) + ",_,_,_,_)"))
		{
			if (HT.concat(Out_intend, " ", Intend))  // reduce the intend by one / line 12774
				ss << write_end_of_loop(*Out_intend, Lang) << endl;
		}
	}
	else if (Cond_stmt < End_of_loop)
	{
		if (Cond_stmt < Condition_end)
		{
			If_then_stmt = Condition_end + 1;
			if (HT.findfact("while_loop(_," + PModule + "," + to_string(If_then_stmt) + ",_,_,_,_)"))
			{
				ss << print_custom_statement("", PModule, Cond_stmt, Intend, Out_intend, Lang);
				Next_cond_stmt = Cond_stmt + 1;
				ss << print_while_loop_tail_cond(PModule, Next_cond_stmt, Condition_end, End_of_loop, *Out_intend, Out_intend, Lang);
			}
		}
	}
	return ss.str();
}

string write_end_of_loop(string Next_intend, string Lang)
{
	stringstream ss;
	if (Lang == "vhdl")
		ss << Next_intend << "END LOOP;";
	else if (Lang == "verilog")
		ss << Next_intend << "end;";
	else if (Lang == "c")
		ss << Next_intend << "}";
	return ss.str();
}

string print_after_return0(int var1, string var2, string var3)
{
	stringstream ss;
	if (var1 == 1)
	{
		ss << var2 << " " << var3;
	}
	return ss.str();
}

string print_after_return1(int var1, string var2)
{
	stringstream ss;
	if (var1 == 1)
	{
		ss << "! " << var2;
	}
	return ss.str();
}

string print_after_return2(int var1, string var2)
{
	stringstream ss;
	if (var1 == 1)
	{
		ss << "abs( " << var2;
	}
	return ss.str();
}

string print_after_return3(int var1, string var2, string var3)
{
	stringstream ss;
	if(var1 == 1)
	{
		ss << write_c_star(var2);
		ss << var3;
	}
	return ss.str();
}

string write_c_star(string Kind)
{
	stringstream ss;
	if (Kind == "par_out" || Kind == "par_inout")
		ss << "*";
	return ss.str();
}

string print_after_return4(int var1, string var2, vector<int> var3)
{
	stringstream ss;
	if (var1 == 1)
	{
		ss << " {";
		ss << print_custom_record_index_parameters("", var2, var3, "record");
		ss << "}";
	}
	return ss.str();
}

string print_after_return5(int var1, string var2, vector<int> var3)
{
	stringstream ss;
	if (var1 == 1)
	{
		ss << " {";
		ss << print_custom_record_index_parameters("", var2, var3, "function");
		ss << "}";
	}
	return ss.str();
}

string print_after_return6(int var1, string var2, string var3)
{
	stringstream ss;
	if (var1 == 1)
	{
		ss << "(* " << var2 << ")[" << var3 << "]";
	}
	return ss.str();
}

string print_after_return7(int var1, string var2, string var3, vector<int> var4)
{
	stringstream ss;
	if (var1 == 1)
	{
		ss << "(* " << var2 << ")";
		ss << print_custom_array_index_parameters(var3, var4, "verilog");
		ss << ";";
	}
	return ss.str();
}

string print_after_return8(int var1, string var2, string var3, vector<int> var4, string var5)
{
	stringstream ss;
	if (var1 == 1)
	{
		ss << var2 << "(";
		ss << print_custom_record_index_parameters("", var3, var4, "function");
		ss << ")";
	}
	return ss.str();
}

string lookahead_prog_entry(string PModule, int Oentry, string In_intend, string* Out_intend)
{
	stringstream ss;
	vector<nested_conditional_end> nce;
	int Next_entry, Top_target;
	string Kind, Next_intend;
	if (HT.findfact("nested_cond_fact(" + PModule + ",*)"))
	{
		nce = return_nested_conditional_end(makeInstanceOf(HT.findandreturn("nested_cond_fact(" + PModule + ",*)")));
		if (!nce.empty())
		{
			if (HT.findfact("prog_stmt(" + PModule + "," + to_string(Oentry) + ",*)"))
			{
				Next_entry = stoi(returnpar(HT.findandreturn("prog_stmt(" + PModule + "," + to_string(Oentry) + ",*)"), 8));
				if (HT.findfact("nested_cond_fact(" + PModule + ",[" + PModule + ",_,_])"))
				{
					Top_target = stoi(returnpar(HT.findandreturn("nested_cond_fact(" + PModule + ",[" + PModule + ",_,_])"), 3));
					Kind = returnpar(HT.findandreturn("nested_cond_fact(" + PModule + ",[" + PModule + ",_,_])"), 4);
					if (Next_entry != Top_target)
					{
						*Out_intend = In_intend;
					}
					else
					{
						pop_cond_end(PModule);
						if (HT.concat(&Next_intend, " ", In_intend))
						{
							ss << Next_intend;
							ss << write_nested_cond_fact(Kind) << endl;
							ss << lookahead_prog_entry(PModule, Oentry, Next_intend, Out_intend);
						}
					}
				}
			}
		}
		else
			*Out_intend = In_intend;
	}
	else
		*Out_intend = In_intend;
	return ss.str();
}

string write_nested_cond_fact(string str)
{
	stringstream ss;
	if (HT.findfact("hdl_style(\"vhdl\")"))
	{
		if (str == "END IF")
			ss << "end if;";
		else if (str == "END LOOP")
			ss << "end loop;";
	}
	else if (HT.findfact("hdl_style(\"verilog\")"))
	{
		if (str == "END IF")
			ss << "end;";
		else if (str == "END LOOP")
			ss << "end;";
	}
	return ss.str();
}

string print_custom_function_cond(string Module, string Module1, int Entry, string HDL)
{
	stringstream ss;
	int Em, DFC;
	string Check;
	if (HT.findfact("hierarchy_part(_," + Module + ",_,_,_,_,_)"))
	{
		Em = stoi(returnpar(HT.findandreturn("hierarchy_part(_," + Module + ",_,_,_,_,_)"), 1));
		if (!HT.findfact("call_stmt(_,_," + to_string(Entry) + ",_)") || Entry >= Em)
			return ss.str();
	}
	else if(HT.findfact("checkstyle(\"checkhierarchy\")"))
	{
		print_custom_function_cond_core(Module, Module1, Entry, &DFC);
		ss << print_custom_function(DFC, Module, Module1, HDL);
	}
	else if (HT.findfact("checkstyle(*)"))
	{
		Check = returnpar(HT.findandreturn("checkstyle(*)"), 1);
		if (Check != "checkhierarchy" || !HT.findfact("checkstyle(*)"))
			ss << print_custom_function(1, Module, Module1, HDL);
	}
	return ss.str();
}

string write_boolean_default_procedures_bodies(string HDL)
{
	stringstream ss;
	if (HT.findfact("type_def(_,_,_,_,_,_,_,_,1)"))
	{
		write_boolean_default_procedures_for_type(1, 1, "vhdl");
		ss << "   FUNCTION bool_vec_to_std_logic(inboolean : IN boolean) RETURN std_logic IS" << endl;
		ss << "    VARIABLE signal1 : std_logic;" << endl;
		ss << "    BEGIN" << endl;
		ss << "        IF inboolean THEN" << endl;
		ss << "          signal1 := '1';" << endl;
		ss << "        ELSE" << endl;
		ss << "          signal1 := '0';" << endl;
		ss << "        END IF;" << endl;
		ss << "      RETURN signal1;" << endl;
		ss << "    END bool_vec_to_std_logic;" << endl;
		ss << endl;
		ss << "   FUNCTION std_logic_to_bool_vec(insignal : IN std_logic) RETURN boolean IS" << endl;
		ss << "    VARIABLE signal1 : boolean;" << endl;
		ss << "    BEGIN" << endl;
		ss << "        IF insignal = '1' THEN" << endl;
		ss << "          signal1 := true;" << endl;
		ss << "        ELSE" << endl;
		ss << "          signal1 := false;" << endl;
		ss << "        END IF;" << endl;
		ss << "      RETURN signal1;" << endl;
		ss << "    END std_logic_to_bool_vec;" << endl;
		ss << endl;
	}
	return ss.str();
}

string print_range_types_in_c(int Entry, string HDL)
{
	stringstream ss;
	int Next_entry;
	if (HT.findfact("type_def(" + to_string(Entry) + ",_,_,_,_,_,_,_,_)") && HDL == "c")
	{
		ss << print_range_type_in_c(Entry);
		Next_entry = Entry + 1;
		ss << print_range_types_in_c(Next_entry, "c");
	}
	return ss.str();
}

string print_range_type_in_c(int Type_entry)
{
	stringstream ss;
	string Type_name;
	if (HT.findfact("type_def(" + to_string(Type_entry) + ",_,_,_,_,\"single_t\",_,_,_)"))
	{
		Type_name = returnpar(HT.findandreturn("type_def(" + to_string(Type_entry) + ",_,_,_,_,\"single_t\",_,_,_)"), 2);
		if (parent_type_is_integer(Type_entry, 0))
			ss << "typedef long long int " << Type_name << " ;" << endl;
	}
	return ss.str();
}

string print_record_types_in_c(int Type_entry, string HDL)
{
	stringstream ss;
	int Next_entry;
	if (HT.findfact("type_def(" + to_string(Type_entry) + ",*)"))
	{
		ss << print_record_type_in_c(Type_entry, "c");
		Next_entry = Type_entry + 1;
		ss << print_record_types_in_c(Next_entry, "c");
	}
	return ss.str();
}

string print_record_type_in_c(int Type_entry, string HDL)
{
	stringstream ss;
	string Type_name;
	int Dimmension, First_comp_type_entry;
	if (HT.findfact("type_def(" + to_string(Type_entry) + ",_,_,\"user\",_,\"record_t\",_,_,_)"))
	{
		Type_name = returnpar(HT.findandreturn("type_def(" + to_string(Type_entry) + ",_,_,\"user\",_,\"record_t\",_,_,_)"), 2);
		Dimmension = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Type_entry) + ",_,_,\"user\",_,\"record_t\",_,_,_)"), 8));
		First_comp_type_entry = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Type_entry) + ",_,_,\"user\",_,\"record_t\",_,_,_)"), 9));
		ss << "typedef   struct {" << endl;
		if (First_comp_type_entry > 1)
		{
			ss << print_records_fields_declarations(First_comp_type_entry, Dimmension, First_comp_type_entry, "c");
			ss << "   } " << Type_name << ";" << endl;
		}
	}
	return ss.str();
}

string print_c_array_types(int In_entry)
{
	stringstream ss;
	int Next_entry;
	if (HT.findfact("type_def(" + to_string(In_entry) + ",*)"))
	{
		ss << print_c_array_type(In_entry);
		Next_entry = In_entry + 1;
		ss << print_c_array_types(Next_entry);
	}
	return ss.str();
}

string print_c_array_type(int Type_entry)
{
	stringstream ss;
	if (Type_entry != 7)
	{
		if (HT.findfact("hdl_style(\"c\")"))
		{
			int Dimmension, Comp_type, Comp_size;
			string Type_name, Comp_name;
			if (HT.findfact("type_def(" + to_string(Type_entry) + ",_,_,\"user\",_,\"vectorarray_t\",_,_,_)"))
			{
				Type_name = returnpar(HT.findandreturn("type_def(" + to_string(Type_entry) + ",_,_,\"user\",_,\"vectorarray_t\",_,_,_)"), 2);
				Dimmension = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Type_entry) + ",_,_,\"user\",_,\"vectorarray_t\",_,_,_)"), 8));
				Comp_type = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Type_entry) + ",_,_,\"user\",_,\"vectorarray_t\",_,_,_)"), 9));
				if (parent_type_is_integer(Comp_type, 0))
				{
					if (Comp_type > 1)
					{
						if (HT.findfact("type_def(" + to_string(Comp_type) + ",_,_,\"user\",_,\"single_t\",_,_,_)"))
						{
							Comp_size = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Comp_type) + ",_,_,\"user\",_,\"single_t\",_,_,_)"), 3));
							if (Comp_size > 1)
								ss << "typedef long long int " << Type_name << " [" << Dimmension << "] ;" << endl;
						}
					}
				}
				else
				{
					if (Comp_type > 1)
					{
						if (HT.findfact("type_def(" + to_string(Comp_type) + ",*)"))
						{
							Comp_name = returnpar(HT.findandreturn("type_def(" + to_string(Comp_type) + ",*)"), 2);
							Comp_size = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Comp_type) + ",*)"), 3));
							if (Comp_size > 1 || Comp_size == 1)
							{
								ss << "typedef " << Comp_name << " " << Type_name << " [" << Dimmension << "] ;" << endl;
							}
						}
					}
				}
			}
			else if (HT.findfact("type_def(" + to_string(Type_entry) + ",_,_,\"user\",_,\"vectorarray_t\",_,_,1)"))
			{
				Type_name = returnpar(HT.findandreturn("type_def(" + to_string(Type_entry) + ",_,_,\"user\",_,\"vectorarray_t\",_,_,1)"), 2);
				Dimmension = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Type_entry) + ",_,_,\"user\",_,\"vectorarray_t\",_,_,1)"), 8));
				if (HT.findfact("type_def(1,*)"))
				{
					ss << "typedef long long int " << Type_name << " [" << Dimmension << "] ;" << endl;
				}
			}
		}
	}
	return ss.str();
}

string write_custom_block_interface(string Module_name, string Entity_name, string HDL, vector<local_object> Local_list)
{
	stringstream ss;
	ss << "  ENTITY " << Entity_name << " IS" << endl;
	ss << write_interface_header("vhdl", "synergy");
	ss << write_io_ports(Module_name, 1, "vhdl", "synergy", "custom");

	return ss.str();
}

string write_interface_header(string HDL, string str)
{
	stringstream ss;
	if (HDL == "vhdl" && str == "synergy")
		ss << "   port(  " << endl;
	return ss.str();
}

string write_io_ports(string Module, int In_entry, string Hdl, string Tool, string Usage)
{
	stringstream ss;
	GeneralFact* Local;
	if (HT.findfact("local_object(" + Module + "," + to_string(In_entry) + ",*)"))
	{
		Local = makeInstanceOf(HT.findandreturn("local_object(" + Module + "," + to_string(In_entry) + ",*)"));
		local_object* ptr = dynamic_cast<local_object*>(Local);
		ss << write_io_ports_core_cond(*ptr, Hdl, Tool, Usage);

	}

	return ss.str();
}

string write_io_ports_core_cond(local_object Local, string HDL, string Tool, string str)
{
	stringstream ss;
	string Module, Name;
	GeneralFact* ptr;
	ptr = &Local;
	Module = returnpar(HT.findandreturn(makeStringOf(ptr)), 1);
	Name = returnpar(HT.findandreturn(makeStringOf(ptr)), 4);
	if (Module == Name)
	{
		ss << write_io_port(Local, HDL, Tool) << endl;
	}
	return ss.str();
}

/** probably needs more work for std_logic, referenced(Type_name)...**/
/** which is the 5th field of local_object **/
/** also the userrecord case should be added in the future for IN, OUT,
	and INOUT ports **/
string  write_io_port(local_object Local, string HDL, string tool)
{
	stringstream ss;
	string Module, var3, Local_name, Local_type, var7, var9, NewName;
	int Current_entry, var5, Local_size, LastIO, Componenttype;
	GeneralFact* ptr = &Local;
	Module = returnpar(makeStringOf(ptr), 1);
	Current_entry = stoi(returnpar(makeStringOf(ptr), 2));
	var3 = returnpar(makeStringOf(ptr), 3);
	Local_name = returnpar(makeStringOf(ptr), 4);
	var5 = stoi(returnpar(makeStringOf(ptr), 5));
	Local_type = returnpar(makeStringOf(ptr), 6);
	var7 = returnpar(makeStringOf(ptr), 7);
	Local_size = stoi(returnpar(makeStringOf(ptr), 8));
	var9 = returnpar(makeStringOf(ptr), 9);
	if (HDL == "vhdl" && tool == "synergy")
	{
		if (var3 == "par_in")
		{
			if (var7 == "standard")
			{
				if (Local_type != "bool")
				{
					ss << "        " << Local_name << " : IN ";
					ss << write_size(Local_size, "std_logic", "vhdl", "synergy", 0);
					ss << endl;
				}
				else
				{
					is_it_the_last_io(Module, "vhdl", Current_entry, &LastIO);
					ss << "        " << Local_name << " : IN std_logic";
					ss << print_conditional_end_of_statement(0);
					ss << endl;
				}
			}
			else if (var7 == "user")
			{
				if (HT.findfact("type_def(_," + Local_type + "," + to_string(Local_size) + ",\"user\",0,\"vectorarray_t\",0," + to_string(Local_size) + ",1)"))
				{
					ss << "        " << Local_name << " : IN ";
					is_it_the_last_io(Module, "vhdl", Current_entry, &LastIO);
					ss << write_size(Local_size, "std_logic", "vhdl", "synergy", LastIO);
					ss << endl;
				}
				else if (HT.findfact("type_def(_," + Local_type + "," + to_string(Local_size) + ",\"user\",_,\"single_t\",_,_,_)"))
				{
					ss << "        " << Local_name << " : IN ";
					is_it_the_last_io(Module, "vhdl", Current_entry, &LastIO);
					ss << write_size(Local_size, "std_logic", "vhdl", "synergy", LastIO) << endl;
				}
				else if (HT.findfact("type_def(_," + Local_type + "," + to_string(Local_size) + ",\"user\",0,\"vectorarray_t\",_,_,_)"))
				{
					is_it_the_last_io(Module, "vhdl", Current_entry, &LastIO);
					ss << "        " << Local_name << " : IN " << Local_type;
					ss << print_conditional_end_of_statement(LastIO);
					ss << endl;
				}
				else if (HT.findfact("type_def(_," + Local_type + "," + to_string(Local_size) + ",\"user\",0,\"record_t\",_,_,_)"))
				{
					is_it_the_last_io(Module, "vhdl", Current_entry, &LastIO);
					ss << "        " << Local_name << " : IN " << Local_type;
					ss << print_conditional_end_of_statement(LastIO);
					ss << endl;
				}
			}
			else if (var7 == "userarray")
			{
				if (Local_type != "bool")
				{
					ss << "        ";
					if (HT.findfact("type_def(_," + Local_type + "," + to_string(Local_size) + ",_,_,\"vectorarray_t\",_," + to_string(Local_size) + ",1)"))
					{
						is_it_the_last_io(Module, "vhdl", Current_entry, &LastIO);
						ss << Local_name << " : IN";
						ss << write_size(Local_size, "std_logic", "vhdl", "synergy", LastIO) << endl;
					}
					else if (HT.findfact("type_def(_," + Local_type + "," + to_string(Local_size) + ",_,_,_,_,_,_)"))
					{
						Componenttype = stoi(returnpar(HT.findandreturn("type_def(_," + Local_type + "," + to_string(Local_size) + ",_,_,_,_,_,_)"), 9));
						if (Componenttype != 1)
						{
							is_it_the_last_io(Module, "vhdl", Current_entry, &LastIO);
							ss << print_vhdl_par_out_name_cond(Module, Local_name);
							ss << " : IN " << Local_type;
							ss << print_conditional_end_of_statement(LastIO);
							ss << endl;
						}
					}
				}
			}
			else if (var7 == "userrecord")
			{
				if (Local_type != "bool")
				{
					is_it_the_last_io(Module, "vhdl", Current_entry, &LastIO);
					replace_chars_in_string(Local_name, ".", "_", &NewName);
					ss << "        " << NewName << " : IN " << Local_type;
					ss << print_conditional_end_of_statement(LastIO);
					ss << endl;
				}
			}
		}
		else if (var3 == "par_out")
		{
			if (var7 == "standard")
			{
				if (Local_type != "bool")
				{
					ss << "        ";
					ss << print_vhdl_par_out_name_cond(Module, Local_name);
					ss << " : OUT ";
					ss << write_size(Local_size, "std_logic", "vhdl", "synergy", 0) << endl;
				}
				else
				{
					is_it_the_last_io(Module, "vhdl", Current_entry, &LastIO);
					ss << "        ";
					ss << print_vhdl_par_out_name_cond(Module, Local_name);
					ss << " : OUT std_logic";
					ss << print_conditional_end_of_statement(0);
					ss << endl;
				}
			}
			else if (var7 == "user")
			{
				if (HT.findfact("type_def(_," + Local_type + "," + to_string(Local_size) + ",\"user\",0,\"vectorarray_t\",0," + to_string(Local_size) + ",1)"))
				{
					is_it_the_last_io(Module, "vhdl", Current_entry, &LastIO);
					ss << "        " << Local_name << " : OUT ";
					ss << write_size(Local_size, "std_logic", "vhdl", "synergy", 0) << endl;
				}
				else if (HT.findfact("type_def(_," + Local_type + "," + to_string(Local_size) + ",\"user\",_,\"single_t\",_,_,_)"))
				{
					is_it_the_last_io(Module, "vhdl", Current_entry, &LastIO);
					ss << "        " << Local_name << " : OUT ";
					ss << write_size(Local_size, "std_logic", "vhdl", "synergy", 0) << endl;
				}
				else if (HT.findfact("type_def(_," + Local_type + "," + to_string(Local_size) + ",\"user\",0,\"vectorarray_t\",_,_,_)"))
				{
					is_it_the_last_io(Module, "vhdl", Current_entry, &LastIO);
					ss << "        " << Local_name << " : OUT " << Local_type;
					print_conditional_end_of_statement(0);
					ss << endl;
				}
				else if (HT.findfact("type_def(_," + Local_type + "," + to_string(Local_size) + ",\"user\",0,\"record_t\",_,_,_)"))
				{
					is_it_the_last_io(Module, "vhdl", Current_entry, &LastIO);
					ss << "        " << Local_name << " : OUT " << Local_type;
					ss << print_conditional_end_of_statement(0);
					ss << endl;
				}
			}
			else if (var7 == "userarray")
			{
				if (Local_type != "bool")
				{
					is_it_the_last_io(Module, "vhdl", Current_entry, &LastIO);
					if (HT.findfact("type_def(_," + Local_type + "," + to_string(Local_size) + ",_,_,\"vectorarray_t\",_," + to_string(Local_size) + ",1)"))
					{
						ss << "        ";
						is_it_the_last_io(Module, "vhdl", Current_entry, &LastIO);
						ss << Local_name << " : OUT";
						ss << write_size(Local_size, "std_logic", "vhdl", "synergy", 0) << endl;
					}
					else if (HT.findfact("type_def(_," + Local_type + "," + to_string(Local_size) + ",_,_,_,_,_,_)"))
					{
						Componenttype = stoi(returnpar(HT.findandreturn("type_def(_," + Local_type + "," + to_string(Local_size) + ",_,_,_,_,_,_)"), 9));
						if (Componenttype != 1)
						{
							ss << "        ";
							ss << print_vhdl_par_out_name_cond(Module, Local_name);
							ss << " : OUT " << Local_type;
							ss << print_conditional_end_of_statement(0);
							ss << endl;
						}
					}
				}
			}
			else if (var7 == "userrecord")
			{
				if (Local_type != "bool")
				{
					is_it_the_last_io(Module, "vhdl", Current_entry, &LastIO);
					ss << "        ";
					replace_chars_in_string(Local_name, ".", "_", &NewName);
					ss << print_vhdl_par_out_name_cond(Module, NewName);
					ss << " : OUT " << Local_type;
					ss << print_conditional_end_of_statement(LastIO);
					ss << endl;
				}
			}
		}
		else if (var3 == "par_inout")
		{
			if (var7 == "standard")
			{
				if (Local_type != "bool")
				{
					is_it_the_last_io(Module, "vhdl", Current_entry, &LastIO);
					ss << "        " << Local_name << " : INOUT ";
					ss << write_size(Local_size, "std_logic", "vhdl", "synergy", LastIO) << endl;
				}
				else
				{
					is_it_the_last_io(Module, "vhdl", Current_entry, &LastIO);
					ss << "        ";
					ss << print_vhdl_par_out_name_cond(Module, Local_name);
					ss << " : INOUT std_logic";
					ss << print_conditional_end_of_statement(LastIO);
					ss << endl;
				}
			}
			else if (var7 == "user")
			{
				if (HT.findfact("type_def(_," + Local_type + "," + to_string(Local_size) + ",\"user\",0,\"vectorarray_t\",_," + to_string(Local_size) + ",1)"))
				{
					is_it_the_last_io(Module, "vhdl", Current_entry, &LastIO);
					ss << "        " << Local_name << " : INOUT ";
					ss << write_size(Local_size, "std_logic", "vhdl", "synergy", LastIO) << endl;
				}
				else if (HT.findfact("type_def(_," + Local_type + "," + to_string(Local_size) + ",\"user\",_,\"single_t\",_,_,_)"))
				{
					is_it_the_last_io(Module, "vhdl", Current_entry, &LastIO);
					ss << "        " << Local_name << " : INOUT ";
					ss << write_size(Local_size, "std_logic", "vhdl", "synergy", LastIO) << endl;
				}
				else if (HT.findfact("type_def(_," + Local_type + "," + to_string(Local_size) + ",\"user\",0,\"vectorarray_t\",_,_,_)"))
				{
					is_it_the_last_io(Module, "vhdl", Current_entry, &LastIO);
					ss << "        " << Local_name << " : INOUT " << Local_type;
					ss << print_conditional_end_of_statement(LastIO);
					ss << endl;
				}
				else if (HT.findfact("type_def(_," + Local_type + "," + to_string(Local_size) + ",\"user\",0,\"record_t\",_,_,_)"))
				{
					is_it_the_last_io(Module, "vhdl", Current_entry, &LastIO);
					ss << "        " << Local_name << " : INOUT " << Local_type;
					ss << print_conditional_end_of_statement(LastIO);
					ss << endl;
				}
			}
			else if (var7 == "userarray")
			{
				if (Local_type != "bool")
				{
					is_it_the_last_io(Module, "vhdl", Current_entry, &LastIO);
					ss << "        ";
					if (HT.findfact("type_def(_," + Local_type + "," + to_string(Local_size) + ",_,_,\"vectorarray_t\",_," + to_string(Local_size) + ",1)"))
					{
						ss << Local_name << " : INOUT";
						ss << write_size(Local_size, "std_logic", "vhdl", "synergy", LastIO) << endl;
					}
					else if (HT.findfact("type_def(_," + Local_type + "," + to_string(Local_size) + ",_,_,_,_,_,_)"))
					{
						Componenttype = stoi(returnpar(HT.findandreturn("type_def(_," + Local_type + "," + to_string(Local_size) + ",_,_,_,_,_,_)"), 9));
						if (Componenttype != 1)
						{
							ss << print_vhdl_par_out_name_cond(Module, Local_name);
							ss << " : INOUT " << Local_type;
							ss << print_conditional_end_of_statement(LastIO);
							ss << endl;
						}
					}
				}
			}
			else if (var7 == "userrecord")
			{
				if (Local_type != "bool")
				{
					is_it_the_last_io(Module, "vhdl", Current_entry, &LastIO);
					replace_chars_in_string(Local_name, ".", "_", &NewName);
					ss << "        " << NewName << " : INOUT " << Local_type;
					ss << print_conditional_end_of_statement(LastIO);
					ss << endl;
				}
			}
		}
	}
	else if (HDL == "verilog" && tool == "synergy")
	{
		string Type_kind, Replacement_name;
		int Type_number, First_comp_type, Comp_size, Numb_of_dim, Child_type, Child_size, Child_upper;
		if (var3 == "par_in")
		{
			if (Local_type != "bool" && Local_type != "userarray" && Local_type != "userrecord")
			{
				if (HT.findfact("type_def(_,"+Local_type+",_,_,_,_,_,_,_)"))
				{
					Type_kind = returnpar(HT.findandreturn("type_def(_," + Local_type + ",_,_,_,_,_,_,_)"), 6);
					if (Type_kind != "vectorarray_t")
					{
						ss << "   input ";
						ss << write_size(Local_size, "std_logic", "verilog", "synergy", 1);
						ss << " " << Local_name << " ; " << endl;
					}
				}
			}
			else if (Local_type == "std_logic")
			{
				ss << "   input ";
				ss << write_size(Local_size, "std_logic", "verilog", "synergy", 1);
				ss << " " << Local_name << " ; " << endl;
			}
			else if (var7 == "standard")
			{
				if (HT.findfact("type_def(_," + Local_type + ",_,_,_,\"vectorarray_t\",_,_,_)"))
				{
					Type_number = stoi(returnpar(HT.findandreturn("type_def(_," + Local_type + ",_,_,_,\"vectorarray_t\",_,_,_)"), 1));
					First_comp_type = stoi(returnpar(HT.findandreturn("type_def(_," + Local_type + ",_,_,_,\"vectorarray_t\",_,_,_)"), 9));
					if (HT.findfact("data_stmt(" + Module + ",_," + to_string(var5) + "," + to_string(Type_number) + ",_,_)"))
					{
						Replacement_name = returnpar(HT.findandreturn("data_stmt(" + Module + ",_," + to_string(var5) + "," + to_string(Type_number) + ",_,_)"), 2);
						if (HT.findfact("mem_port(_,_," + Module + "," + Replacement_name + ",_,_,_,_,_,_,_,_,_)"))
						{
							ss << "   input ";
							if (HT.findfact("type_def(" + to_string(First_comp_type) + ",_,1,_,_,_,_,_,_)"))
							{
								ss << " " << Local_name << " ; " << endl;
							}
							else if (HT.findfact("type_def(" + to_string(First_comp_type) + ",*)"))
							{
								Comp_size = stoi(returnpar(HT.findandreturn("type_def(" + to_string(First_comp_type) + ",*)"), 3));
								if (Comp_size > 1)
								{
									write_size(Local_size, "std_logic", "verilog", "synergy", 1);
									ss << " " << Local_name << " ; " << endl;
								}
							}
						}
					}
				}
			}
			else if (var7 == "user")
			{
				if (HT.findfact("type_def(_," + Local_type + ",_,_,_,\"vectorarray_t\",_,_,_)"))
				{
					Type_number = stoi(returnpar(HT.findandreturn("type_def(_," + Local_type + ",_,_,_,\"vectorarray_t\",_,_,_)"), 1));
					Numb_of_dim  = stoi(returnpar(HT.findandreturn("type_def(_," + Local_type + ",_,_,_,\"vectorarray_t\",_,_,_)"), 8));
					First_comp_type = stoi(returnpar(HT.findandreturn("type_def(_," + Local_type + ",_,_,_,\"vectorarray_t\",_,_,_)"), 9));
					if (HT.findfact("data_stmt(" + Module + ",_," + to_string(var5) + "," + to_string(Type_number) + ",_,_)"))
					{
						Replacement_name = returnpar(HT.findandreturn("data_stmt(" + Module + ",_," + to_string(var5) + "," + to_string(Type_number) + ",_,_)"), 2);
						if (HT.findfact("mem_port(_,_," + Module + "," + Replacement_name + ",_,_,_,_,_,_,_,_,_)"))
						{
							ss << "   input ";
							find_child_type(Type_number, &Child_type);
							if (HT.findfact("type_def(" + to_string(Child_type) + ",*)"))
							{
								Child_size = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Child_type) + ",*)"), 3));
								if (Child_size > 1)
								{
									Child_upper = Child_size - 1;
									ss << " [" << Child_upper << ":0] " << Local_name << " ";
									ss << write_verilog_dimmension_component_recursively(Type_number);
									ss << " ; " << endl;
									ss << write_verilog_array_index_registers(Module, Local_name, Type_number, Numb_of_dim, Numb_of_dim, 1);
								}
							}
						}
					}
					ss << "        " << Local_name << " : IN ";
					is_it_the_last_io(Module, "vhdl", Current_entry, &LastIO);
					ss << write_size(Local_size, "std_logic", "vhdl", "synergy", LastIO);
					ss << endl;
				}
				else if (HT.findfact("type_def(_," + Local_type + "," + to_string(Local_size) + ",\"user\",_,\"single_t\",_,_,_)"))
				{
					ss << "        " << Local_name << " : IN ";
					is_it_the_last_io(Module, "vhdl", Current_entry, &LastIO);
					ss << write_size(Local_size, "std_logic", "vhdl", "synergy", LastIO) << endl;
				}
				else if (HT.findfact("type_def(_," + Local_type + "," + to_string(Local_size) + ",\"user\",0,\"vectorarray_t\",_,_,_)"))
				{
					is_it_the_last_io(Module, "vhdl", Current_entry, &LastIO);
					ss << "        " << Local_name << " : IN " << Local_type;
					ss << print_conditional_end_of_statement(LastIO);
					ss << endl;
				}
				else if (HT.findfact("type_def(_," + Local_type + "," + to_string(Local_size) + ",\"user\",0,\"record_t\",_,_,_)"))
				{
					is_it_the_last_io(Module, "vhdl", Current_entry, &LastIO);
					ss << "        " << Local_name << " : IN " << Local_type;
					ss << print_conditional_end_of_statement(LastIO);
					ss << endl;
				}
			}
			else if (var7 == "userarray")
			{
				if (Local_type != "bool")
				{
					ss << "        ";
					if (HT.findfact("type_def(_," + Local_type + "," + to_string(Local_size) + ",_,_,\"vectorarray_t\",_," + to_string(Local_size) + ",1)"))
					{
						is_it_the_last_io(Module, "vhdl", Current_entry, &LastIO);
						ss << Local_name << " : IN";
						ss << write_size(Local_size, "std_logic", "vhdl", "synergy", LastIO) << endl;
					}
					else if (HT.findfact("type_def(_," + Local_type + "," + to_string(Local_size) + ",_,_,_,_,_,_)"))
					{
						Componenttype = stoi(returnpar(HT.findandreturn("type_def(_," + Local_type + "," + to_string(Local_size) + ",_,_,_,_,_,_)"), 9));
						if (Componenttype != 1)
						{
							is_it_the_last_io(Module, "vhdl", Current_entry, &LastIO);
							ss << print_vhdl_par_out_name_cond(Module, Local_name);
							ss << " : IN " << Local_type;
							ss << print_conditional_end_of_statement(LastIO);
							ss << endl;
						}
					}
				}
			}
			else if (var7 == "userrecord")
			{
				if (Local_type != "bool")
				{
					is_it_the_last_io(Module, "vhdl", Current_entry, &LastIO);
					replace_chars_in_string(Local_name, ".", "_", &NewName);
					ss << "        " << NewName << " : IN " << Local_type;
					ss << print_conditional_end_of_statement(LastIO);
					ss << endl;
				}
			}
		}
		else if (var3 == "par_out")
		{
			if (var7 == "standard")
			{
				if (Local_type != "bool")
				{
					ss << "        ";
					ss << print_vhdl_par_out_name_cond(Module, Local_name);
					ss << " : OUT ";
					ss << write_size(Local_size, "std_logic", "vhdl", "synergy", 0) << endl;
				}
				else
				{
					is_it_the_last_io(Module, "vhdl", Current_entry, &LastIO);
					ss << "        ";
					ss << print_vhdl_par_out_name_cond(Module, Local_name);
					ss << " : OUT std_logic";
					ss << print_conditional_end_of_statement(0);
					ss << endl;
				}
			}
			else if (var7 == "user")
			{
				if (HT.findfact("type_def(_," + Local_type + "," + to_string(Local_size) + ",\"user\",0,\"vectorarray_t\",0," + to_string(Local_size) + ",1)"))
				{
					is_it_the_last_io(Module, "vhdl", Current_entry, &LastIO);
					ss << "        " << Local_name << " : OUT ";
					ss << write_size(Local_size, "std_logic", "vhdl", "synergy", 0) << endl;
				}
				else if (HT.findfact("type_def(_," + Local_type + "," + to_string(Local_size) + ",\"user\",_,\"single_t\",_,_,_)"))
				{
					is_it_the_last_io(Module, "vhdl", Current_entry, &LastIO);
					ss << "        " << Local_name << " : OUT ";
					ss << write_size(Local_size, "std_logic", "vhdl", "synergy", 0) << endl;
				}
				else if (HT.findfact("type_def(_," + Local_type + "," + to_string(Local_size) + ",\"user\",0,\"vectorarray_t\",_,_,_)"))
				{
					is_it_the_last_io(Module, "vhdl", Current_entry, &LastIO);
					ss << "        " << Local_name << " : OUT " << Local_type;
					print_conditional_end_of_statement(0);
					ss << endl;
				}
				else if (HT.findfact("type_def(_," + Local_type + "," + to_string(Local_size) + ",\"user\",0,\"record_t\",_,_,_)"))
				{
					is_it_the_last_io(Module, "vhdl", Current_entry, &LastIO);
					ss << "        " << Local_name << " : OUT " << Local_type;
					ss << print_conditional_end_of_statement(0);
					ss << endl;
				}
			}
			else if (var7 == "userarray")
			{
				if (Local_type != "bool")
				{
					is_it_the_last_io(Module, "vhdl", Current_entry, &LastIO);
					if (HT.findfact("type_def(_," + Local_type + "," + to_string(Local_size) + ",_,_,\"vectorarray_t\",_," + to_string(Local_size) + ",1)"))
					{
						ss << "        ";
						is_it_the_last_io(Module, "vhdl", Current_entry, &LastIO);
						ss << Local_name << " : OUT";
						ss << write_size(Local_size, "std_logic", "vhdl", "synergy", 0) << endl;
					}
					else if (HT.findfact("type_def(_," + Local_type + "," + to_string(Local_size) + ",_,_,_,_,_,_)"))
					{
						Componenttype = stoi(returnpar(HT.findandreturn("type_def(_," + Local_type + "," + to_string(Local_size) + ",_,_,_,_,_,_)"), 9));
						if (Componenttype != 1)
						{
							ss << "        ";
							ss << print_vhdl_par_out_name_cond(Module, Local_name);
							ss << " : OUT " << Local_type;
							ss << print_conditional_end_of_statement(0);
							ss << endl;
						}
					}
				}
			}
			else if (var7 == "userrecord")
			{
				if (Local_type != "bool")
				{
					is_it_the_last_io(Module, "vhdl", Current_entry, &LastIO);
					ss << "        ";
					replace_chars_in_string(Local_name, ".", "_", &NewName);
					ss << print_vhdl_par_out_name_cond(Module, NewName);
					ss << " : OUT " << Local_type;
					ss << print_conditional_end_of_statement(LastIO);
					ss << endl;
				}
			}
		}
		else if (var3 == "par_inout")
		{
			if (var7 == "standard")
			{
				if (Local_type != "bool")
				{
					is_it_the_last_io(Module, "vhdl", Current_entry, &LastIO);
					ss << "        " << Local_name << " : INOUT ";
					ss << write_size(Local_size, "std_logic", "vhdl", "synergy", LastIO) << endl;
				}
				else
				{
					is_it_the_last_io(Module, "vhdl", Current_entry, &LastIO);
					ss << "        ";
					ss << print_vhdl_par_out_name_cond(Module, Local_name);
					ss << " : INOUT std_logic";
					ss << print_conditional_end_of_statement(LastIO);
					ss << endl;
				}
			}
			else if (var7 == "user")
			{
				if (HT.findfact("type_def(_," + Local_type + "," + to_string(Local_size) + ",\"user\",0,\"vectorarray_t\",_," + to_string(Local_size) + ",1)"))
				{
					is_it_the_last_io(Module, "vhdl", Current_entry, &LastIO);
					ss << "        " << Local_name << " : INOUT ";
					ss << write_size(Local_size, "std_logic", "vhdl", "synergy", LastIO) << endl;
				}
				else if (HT.findfact("type_def(_," + Local_type + "," + to_string(Local_size) + ",\"user\",_,\"single_t\",_,_,_)"))
				{
					is_it_the_last_io(Module, "vhdl", Current_entry, &LastIO);
					ss << "        " << Local_name << " : INOUT ";
					ss << write_size(Local_size, "std_logic", "vhdl", "synergy", LastIO) << endl;
				}
				else if (HT.findfact("type_def(_," + Local_type + "," + to_string(Local_size) + ",\"user\",0,\"vectorarray_t\",_,_,_)"))
				{
					is_it_the_last_io(Module, "vhdl", Current_entry, &LastIO);
					ss << "        " << Local_name << " : INOUT " << Local_type;
					ss << print_conditional_end_of_statement(LastIO);
					ss << endl;
				}
				else if (HT.findfact("type_def(_," + Local_type + "," + to_string(Local_size) + ",\"user\",0,\"record_t\",_,_,_)"))
				{
					is_it_the_last_io(Module, "vhdl", Current_entry, &LastIO);
					ss << "        " << Local_name << " : INOUT " << Local_type;
					ss << print_conditional_end_of_statement(LastIO);
					ss << endl;
				}
			}
			else if (var7 == "userarray")
			{
				if (Local_type != "bool")
				{
					is_it_the_last_io(Module, "vhdl", Current_entry, &LastIO);
					ss << "        ";
					if (HT.findfact("type_def(_," + Local_type + "," + to_string(Local_size) + ",_,_,\"vectorarray_t\",_," + to_string(Local_size) + ",1)"))
					{
						ss << Local_name << " : INOUT";
						ss << write_size(Local_size, "std_logic", "vhdl", "synergy", LastIO) << endl;
					}
					else if (HT.findfact("type_def(_," + Local_type + "," + to_string(Local_size) + ",_,_,_,_,_,_)"))
					{
						Componenttype = stoi(returnpar(HT.findandreturn("type_def(_," + Local_type + "," + to_string(Local_size) + ",_,_,_,_,_,_)"), 9));
						if (Componenttype != 1)
						{
							ss << print_vhdl_par_out_name_cond(Module, Local_name);
							ss << " : INOUT " << Local_type;
							ss << print_conditional_end_of_statement(LastIO);
							ss << endl;
						}
					}
				}
			}
			else if (var7 == "userrecord")
			{
				if (Local_type != "bool")
				{
					is_it_the_last_io(Module, "vhdl", Current_entry, &LastIO);
					replace_chars_in_string(Local_name, ".", "_", &NewName);
					ss << "        " << NewName << " : INOUT " << Local_type;
					ss << print_conditional_end_of_statement(LastIO);
					ss << endl;
				}
			}
		}
	}

	return ss.str();
}

void is_it_the_last_io(string Module_name, string HDL, int Current_entry, int* Last)
{
	int Next_entry;
	Next_entry = Current_entry + 1;
	if (!HT.findfact("local_object(" + Module_name + "," + to_string(Next_entry) + ",*)"))
		*Last = 1;
	else
		*Last = 0;
}

string print_conditional_end_of_statement(int num)
{
	stringstream ss;
	if (!num)
		ss << ";";
	return ss.str();
}

string print_vhdl_par_out_name_cond(string Module_name, string Local_name)
{
	stringstream ss;
	if (Module_name == Local_name)
	{
		if (custom_block(Module_name))
			ss << Local_name << "_out";
		else
			ss << Local_name;
	}
	else
		ss << Local_name;
	return ss.str();
}

void replace_chars_in_string(string Local_name, string Ch1, string Ch2, string* NewName)
{
	size_t DotPos, Length, BefDot, AfDot, Name2Length;
	string Name1, Name2, LLname;
	if (searchstring(Local_name, Ch1, &DotPos))
	{
		str_len(Local_name, &Length);
		BefDot = DotPos - 1;
		AfDot = DotPos + 1;
		Name2Length = Length - DotPos;
		substring(Local_name, 1, BefDot, &Name1);
		substring(Local_name, AfDot, Name2Length, &Name2);
		HT.concat(Name1, Ch2, &LLname);
		HT.concat(LLname, Name2, NewName);
	}
	else
		*NewName = Local_name;
}

string write_verilog_array_index_registers(string Module_name, string Local_name, int Type_number, int Num_dim, int Comp_num_dim, int In_index)
{
	stringstream ss;
	int Comp_type;
	string Type_name, Just_field, Just_parent;
	if (Comp_num_dim == 0)
	{
		if (In_index == 1)
		{
			if (HT.findfact("type_def(" + to_string(Type_number) + ",*)"))
			{
				Comp_type = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Type_number) + ",*)"), 9));
				if (HT.findfact("type_def(" + to_string(Comp_type) + ",_,_,_,_,_,_,0,_)"))
					ss << "   integer " << Local_name << "_i ;" << endl;
				else if (HT.findfact("type_def(" + to_string(Comp_type) + ",_,_,_,_,\"record_t\",_,_,_)"))
					ss << "   integer " << Local_name << "_i ;" << endl;
			}
		}
		if (In_index > 1)
		{
			if (HT.findfact("type_def(" + to_string(Type_number) + ",*)"))
				ss << "   integer " << Local_name << "_i" << In_index << " ;" << endl;
		}
	}
	else if (Comp_num_dim > 0)
	{
		if (HT.findfact("type_def("+to_string(Type_number)+",_,_,_,_,\"vectorarray_t\",_,_,_)"))
		{
			Type_name = returnpar(HT.findandreturn("type_def(" + to_string(Type_number) + ",_,_,_,_,\"vectorarray_t\",_,_,_)"), 2);
			Comp_type = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Type_number) + ",_,_,_,_,\"vectorarray_t\",_,_,_)"), 9));
			if (HT.concat(".", &Just_field, Type_name))
				if (HT.concat(&Just_parent, Type_name, Local_name))
					ss << "   integer " << Just_parent << "_" << Just_field << "_i" << In_index << " ;" << endl;
		}
	}
	return ss.str();
}
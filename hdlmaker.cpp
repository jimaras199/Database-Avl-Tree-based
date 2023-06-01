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
#include <ctype.h>

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
string print_local_variable_cond_cond(string PModule, int Dentry, string HDL, int ExcludingEntry);
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
string write_interface_tail(string Module_name, string HDL, string Tool);
string write_verilog_ports(string Module_name, int In_entry, string HDL);
string write_verilog_port(string Module_name, local_object Local, string HDL);
string write_sens_list_cus_block(string Module_name, int In_entry);
string write_comma_cond_input(string Module_name, int In_entry);
string write_cus_block_process_io_variables(string Module_name, int Entry, string HDL);
string write_cus_block_process_io_variable(string Module_name, int Entry, string HDL);
string write_cus_block_process_input_var_assignments(string Module_name, int Entry, string WS, int* Last_entry);
string write_block_call(string Module_name, int int1, string WS);
string write_all_io_list_cus_block_with_var_suffix(string Module_name, int Entry);
string write_comma_cond_all(string Module_name, int In_entry, string str);
string write_cus_block_process_output_var_assignments(string Module_name, int Entry, string WS);
string write_cus_block_process_output_var_assignment(string Module_name, int Entry, string WS);
string write_custom_call_no_state(string Called_module_name, string HDL);
string write_block_call_real_ios(string Module_name, int int1, string WS);
string write_all_io_list_cus_block_real_ios(string Module_name, int Entry);
string write_interface(string Module_name, string Schedule, int var3, string HDL, string Tool);
string write_standard_call_ports(string Module, string Schedule, int Call_entry);
string write_standard_ports_for_called_module(string Module, string Schedule, int Call_entry, int Called_module_entry);
string write_polymorfic_IO_exression(string Module, string Schedule_name, int State, string Called_Module_name, string Signal_name, int Next_order, int Max_order, string First_space, string Condition_op_string, string Suffix_string, int InRealCount, int PruneLastString);
string type_core_IO_expression(string Called_Module_name, int var2, string Signal_name, int var4, int Max_order, string var6, string Condition_op_string, string Suffix_string, int InRealCount, int* OutRealCount, int PruneLastString);
string produce_real_same_calls_count(string First_space, int Called_module_entry, int State, string Signal_name, string Suffix_string, string Condition_op_string, int Same_order, int Same_total, int Next_order, int Total_order, int Max_order, int InRealCount, int* OutRealCount, int PruneLastString);
string write_or_prune(int InRealCount, int Total_order, string Condition_op_string, int int1);
string write_standard_verilog_call_decls(string Module, int Call_entry);
string write_standard_verilog_decls_for_called_module(string Module, int Call_entry, int Called_module_entry);
string write_verilog_call_ios(string Module, int Call_entry);
string write_content_header(string Module_name, string HDL, string Tool);
string print_states_type(int Last_state);
string write_state_symbols(int Last_state, int var2);
string write_state_symbols_core(int Last_state, int Current_number, int* Previous_state, int* Next_number);
string new_state_symbols_line(int Current_number);
string write_next_state_variable(string Module_name, string HDL, int Upper);
string write_locals(string Module, int In_entry, string Hdl, string Tool);
string write_local_conditionally(string Module, local_object Local, string Hdl, string Tool);
string write_local(local_object Local, string HDL, string Tool, string Suffix);
string write_value(string Local_value, int Local_size, string Type_name, string HDL, string Tool);
string write_type(int Type_number);
string write_standard_call_signals(string Schedule, string Module, int Call_entry);
string write_standard_signals_for_called_module(string New_schedule, string Module, int Call_entry, int Called_module_entry);
string write_dp_signal_declarations();
string write_datapath_signals(int Op_entry);
string write_datapath_signals_core(int Op_entry, int* Next_entry);
string declare_output_signal(string Output_instance, int Size);
string write_signal_declaration(string Instance, int Type, int Size);
string declare_input_signal(string In_instance, int Size);
string write_constant_signal_declaration(string In_instance, int Size);
string write_content_body_header(string Module, string HDL, string Tool, string Schedule);
string write_call_assignments(string Module, int Call_entry, string Schedule);
string write_call_assignment(string Module, int Call_entry, string New_schedule);
string write_polymorfic_IO_assignment(string Module, string Schedule_name, string Called_Module_name, string Destination_Signal_name, string Source_Signal_name, int Next_order, int Max_order, string First_space, string Condition_op_string, string Suffix_string);
string type_core_IO_assignment(string Called_Module_name, string Destination_Signal_name, string Source_Signal_name, int Next_order, int Max_order, string First_space, string Condition_op_string, string Suffix_string);
string write_fsm(string Module_name, int int1, int State_number, string Hdlform, string Tool);
string write_fsm_header(string Module_name, int int1, string HDL, string Tool);
string write_aux_std_logic_vectors_wrapper(string Module_name, int Next_number, string HDL, string Tool);
string write_aux_std_logic_vectors(string Module_name, int Number, string HDL, string Tool);
string write_aux_std_logic_vector(local_object Local);
string write_all_cus_blocks_io_variables(string Module_name, int Module_entry, string HDL);
string write_cus_block_variables_cond(string Module_name, int Module_entry, string HDL);
string write_aux_conditional_variables(string Module_name, int Entry, string HDL);
string write_aux_conditional_variable(string Module_name, int Entry, string HDL);
string reset_locals(string Module_name, string Schedule, int Entry, string HDL, string Tool);
string reset_local(string Schedule, local_object Local, string HDL, string Tool);
string reset_record_field(string Kind, int Field_number, int Number_of_fields, int Current_comp_type, string HDL);
string reset_record_field_core(string Kind, int Field_number, int Number_of_fields, int Current_comp_type, string HDL, int* Next_field_number, int* Next_comp_type);
string reset_multi_array(string Local_name, int Type_entry, int Dimension_depth, int* Total_depth, int* Last_comp_type, int Declare_index);
string reset_a_dimension(string Local_name, int Type_entry, int Dimension_depth, string HDL, int Declare_index);
string declare_index(int Declare, string Local_name, int Dimension_depth);
string write_array_dim_depth(string Local_name, int Input_index, int Dimension_depth);
string write_array_dim_depth_core(string Local_name, int Input_index, int Dimension_depth, int* Next_index);
string write_array_comp_reset_value(int Last_comp_type);
string write_record_reset_aggregate(int In_dim, int Number_of_dims, int In_comp);
string write_array_end_loop(int Dimension_depth);
string write_array_end_loop_core(int Dimension_depth, int* Next_dimension_depth);
string write_depending_on_kind(string Local_name, string Local_kind, string* Local_name_app);
string reset_struct_field(string Top_kind, string Prefix_name, int Field_number, int Number_of_fields, int Current_comp_type, string HDL);
string reset_struct_field_cond(string Top_kind, string Prefix_name, int Current_comp_type, string HDL);
string reset_call_ports_unopt(string Module_name, string HDL, int C_entry);
string reset_call_ports_core_unopt(string Module_name, string HDL, int C_entry, int* Next_entry);
string finds_par_and_resets_formal_ios_unopt(string Module_name, string HDL, int C_entry, int Function_entry, int Function_max_calls, int num);
string resets_standard_call_ios_unopt(string Module_name, string HDL, int C_entry, int Function_entry, int Function_max_calls, int num);
string write_fsm_clock_header(string HDL, string Tool);
string write_states(string Module_name, int Number, string HDL, string Tool);
string write_state(string Module_name, state_node SN, string HDL, string Tool);
string write_state_operations(string Module_name, int State, vector<int> Op_list);
string output_operations(string Module_name, vector<int> Op_list, string HDL, string Tool);
string print_all_kinds_of_operation(string Module_name, int Operation, string HDL, string Tool);
string output_operation(string Module_name, int Operation, string HDL, string Tool);
string write_param_list(string Module, vector<int> Param_list);
string write_vhdl_array_index(string Module_name, int Right_op);
string print_array_index_parameters(string Module_name, vector<int> List);
string print_array_index_parameter(string Module_name, int Right_op);
string type_op_tuple(string Module_name, string Res_name, string Right_name, string str4, string str5, string Op_string);
string type_op_tuple1(string Module_name, string Res_name, string Right_name, string str4, string str5, string Op_string);
string write_verilog_aggregate(string Module_name, int Cur_index, string Res_name, vector<int> List);
string write_verilog_array_index(string Module_name, int Right_op);
string output_special_operation(string Module, int Operation, string HDL, string Tool);
string write_special_comment(string HDL);
string write_record_special_operation(string Module, int Result, int Down_limit, vector<int> List);
string write_record_special_operation_core(string Module, int Result, int Down_limit, int Par, int* Next_down_limit);
string print_object_bit_range(int Upper_bound, int Lower_bound, string HDL);
string print_first_concat_symbol(string HDL);
string print_record_object_components(string Module, string Object_name, int Next_comp, int First_comp, int Next_low_bound);
string print_record_field(string Record_name, string Field_name, int Field_size, int int2, int int3, int Low_bound, string HDL);
string print_concat(string HDL);
string print_last_concat_symbol(string HDL);
string print_record_fields_concatenation(string Sd_name, int Sd_type, int Field_type, string HDL);
string write_assignment_to_a_record(string Module, string Operator, string Sd_name, string Rd_name, int Num_of_elements, int Input_elem_number, int Input_shift_offset, string HDL);
string write_assignment_to_a_record_core(string Module, string Operator, string Sd_name, string Rd_name, int Input_elem_number, int Num_of_elements, int Input_shift_offset, int* Element_width, string HDL);
string write_record_field_target_assignment(string op, string Rd_name, string Element_name, int Input_shift_offset, string Sd_name, string HDL);
string print_special_triplet_op(string HDL, string Operator, string Rd_name, int Rd_width, string Left_name, int Left_width, string Right_name, int Right_width);
string print_right_side_multdiv(string Operator, string Left, string Right, int Data_width, string HDL);
string write_record_assignment_to_variable(string Module, string Sd_name, int Left_op, int Left_type, int No_of_fields, int First_field_type);
string conditionally_write_shift(string Total_name, int Shifts);
string conditionally_write_field_or(int First_type, int Field_type);
string write_long_int_conditionally(int Width);
string type_aggregate_record_shifts(string Module, vector<int> Field_list, int Total_fields, vector<int> Total_shift_list);
string type_field_shifts(string Module, vector<int> List1, vector<int> List2, int In_field_no, int Target_field_no);
string write_output_state_assignments(string Module_name, int State, vector<int> List);
string write_output_state_assignment(string Module_name, int State, int Op);
string write_call(string WS, string Module_name, int State, int Next_state, int int1, vector<int> Total_ops, int Operation, string HDL, string Order);
string print_call_input_par_assignments_parcs(string Module_name, vector<int> List, string Order);
string print_call_input_par_assignment_parcs(string Module_name, int Head_op, int Par_entry, string Order);
string print_call_input_par_assignment_parcs_core(string Module_name, int Head_op, int Par_entry, string Order, int* Next_entry);
string write_conditionally_next_state(string Module, int Next_state);
string print_call_output_par_assignments_parcs(string Module_name, vector<int> List, string Order);
string print_call_output_par_assignment_parcs(string Module_name, int Head_op, int Par_entry, string Order);
string print_call_output_par_assignment_parcs_core(string Module_name, int Head_op, int Par_entry, string Order, int* Next_entry);
string print_function_input_assignment(string Module_name, string Called_module_name, string Actual_param_name, int Actual_par_entry, string Formal_param_name, int Target_entry);
string write_total_order_assignment_conditional(string WS, int Total_order, int CurrentDepth);
string write_next_state_conditionally(string WS, int CurrentDepth, int Next_state);
string write_cus_block_call_input_var_assignments(string Module_name, string Called_module_name, int Entry, vector<int> List1, string WS, int* One_after, vector<int>* Rest_params, string HDL);
string write_cus_block_call_input_var_assignments_core(string Module_name, string Called_module_name, int Entry, vector<int> List, string WS, string HDL, int* Next_entry);
string write_cus_block_call_input_var_assignment(string Module_name, string Called_module_name, int Entry, int Actual_param, string WS, string HDL);
string write_cus_block_call_output_var_assignments(string Module_name, string Called_module_name, int Formal_entry, vector<int> List, string WS);
string write_cus_block_call_output_var_assignments_core(string Module_name, string Called_module_name, int Formal_entry, vector<int> List, string WS, int* Next_entry);
string write_cus_block_call_output_var_assignment(string Module_name, string Called_module_name, int Formal_entry, int Actual_param, string WS);
string write_custom_call_actuals(string Module_name, int Call_entry, string HDL);
string write_procedure_task_call_actuals(string Module_name, int Call_entry, string HDL);
string write_procedure_actual_parameters(string Module_name, string Called_module, vector<int> List, int In_formal_entry);
string write_function_out_param_aux_cond(string Called_module);
string write_parameter_assignments(string Module_name, string Called_module, vector<int> List, int In_formal_entry);
string write_parameter_assignment(string Module_name, string Called_module, int Actual, int Formal);
string write_function_task_call_actuals(string Module_name, int Op_entry, int Call_entry, string HDL);
string write_actual_or_formal_parameter(string Module, string Called_module, int Actual, int Formal);
string write_c_actual_parameters(string Module_name, string Called_module, vector<int> List, int In_formal_entry);
string write_parkind_c(string str);
string write_c_parameter(string Module, string Called_module, int Actual, int Formal);
/////////////////////

void generate_top(string pathln, string exec, string cmdl);
void assert_global_constraint_conditionally0(string Line = "");
void assert_global_constraint_conditionally1(string Line = "");
void assert_global_constraint_conditionally2(string Line = "");
void assert_global_constraint_conditionally3(string Line = "");
void assert_mp_conditionally(string Line = "");
void assert_hdl_conditionally(string Line = "");
void check_for_program_name(string path = "", string exename = "");
void extract_loops_from_all_modules(int entry);
void extract_loops(string name, int entry);
void build_loop_cond(string name, int entry);
void add_while_loop(string Module, int If_statement, int Condition_statement, int End_of_loop, int Body_first, int Body_last, int* While_loop_entry);
void trace_previous_assign_op(string Module_name, int Condition_statement, int* Assign_stmt);
void add_for_loop(string Module_name, int If_entry, int Condition_statement, int End_of_loop, int Header_start, int Increment_instruction, int Increment_variable, int Start_value, int End_value, int Increment_step, int Body_first, int Body_last, int Iterations, int* For_loop_entry);
bool trace_back(string Module, int Previous, int Variable, int* Result);
void calc_target_var(string Module, int Operator, int Left, int Right, int* Result);
void generate_hdl_recursive(string Hdlform, string Tool, int Entry);
void store_package_name(int Entry, string Module);
void increment_module_counter();
void generate_hdl_2(string Hdlform, string tool, string Module_name, int Level);
void get_and_append_local(string Module_name, vector<local_object> LList, int Onumber, vector<local_object>* cosLList, int* cosOnumber);
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
bool is_it_the_last_io(string Module_name, string HDL, int Current_entry, int* Last);
void replace_chars_in_string(string Local_name, string Ch1, string Ch2, string* NewName);
void log2n(int Init_number, int Input_number, int var3, int* Log2);
bool io_exists(string Module_name, int Entry, string* Data);
bool is_output(string str);
void consult_memory_ports(string Memory_file_name);
void consult_cus_blocks(string Cus_blocks_file_name);
void remove_modules_instances();
void eliminating_garbage_from_memory(string Module);
void read_last_state(int* Last_state);
void read_local_list(vector<local_object>* Local_list);
void consult_permanent_conditionally(string Module);
void write_unoptimised_hdl(string Module_name, int int1, int int2, string HDL, string Tool, int Last_st);
void find_correct_max_call_order(string Module_name, int Called_Module_entry, int Input_order, int* Order);
void make_order_string(int Same_order, int Same_total, string* Order);
bool parcs_or_parcsif(string New_schedule);
void find_correct_order(string Module, int Call_entry, int* MaxOrder);
void max_(int A, int B, int* C);
bool out_of_types_op(int Operator);
bool out_of_logical_op(int Operator);
bool out_of_standard_types(int Type);
bool derived_type(int Type, int Ref);
void find_rec_field_string(int First_field_type, int Field_num, string* Field_string);
bool one_of_two_not_same_array(string str1, string str2, int int1, int int2);
void find_record_field_bounds(int Acc_lower_bound, int Field_num, int In_field_count, int In_field_type, int* Upper_bound, int* Lower_bound);
void translate_operator_symbol(string Op_string, string* C_op_string, string* CloseParenthesis, string* ExtraAss);
bool get_data_name(string Module, int Entry_number, string* LowName, int* Width);
void last_field_shift(int No_of_fields, int First_field_type, int In_shift_amount, int* Total_shift_amount);
void total_number_of_aggregate_fields(string Module, vector<int> List, int In_shifts, int In_total_fields, int* Total_fields, int* Last_field, vector<int> In_shift_list, vector<int>* Total_shift_list);
void append_list(vector<int> List1, int Local, vector<int>* List2);
bool is_exception_output_operator(int Op_numb);
void read_current_depth(int* CurrentDepth);
bool it_is_input_kind(string str);
bool it_is_output_kind(string str);

//essential functions
bool Iscmdlinearg(string Line)
{
	if (Line.find(co, 0) != Line.npos) return true;
	return false;
}
void fronttoken(string Line = "", string token = "", string rest = "")
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
bool upper_lower(string Upper, string Lower)
{
	char* ch1 = Upper.data();
	for (int i = 0; i <= strlen(ch1); i++) 
	{
		if (ch1[i] >= 65 && ch1[i] <= 90)
		{
			ch1[i] = ch1[i] + 32;
		}
	}
	char* ch2 = Lower.data();
	for (int i = 0; i <= strlen(ch2); i++) 
	{
		if (ch2[i] >= 65 && ch2[i] <= 90)
		{
			ch2[i] = ch2[i] + 32;
		}
	}
	Upper = ch1;
	Lower = ch2;
	if (Upper == Lower)
		return true;
	return false;
}
void upper_lower(string* Upper, string Lower)
{
	char* ch2 = Lower.data();
	for (int i = 0; i <= strlen(ch2); i++)
	{
		if (ch2[i] >= 97 && ch2[i] <= 122)
		{
			ch2[i] = ch2[i] - 32;
		}
	}
	*Upper = ch2;
}
void upper_lower(string Upper, string* Lower)
{
	char* ch1 = Upper.data();
	for (int i = 0; i <= strlen(ch1); i++)
	{
		if (ch1[i] >= 65 && ch1[i] <= 90)
		{
			ch1[i] = ch1[i] + 32;
		}
	}
	*Lower = ch1;
}
bool str_int(string str, int int1)
{
	return str == to_string(int1);
}
void str_int(string* str, int int1)
{
	*str = to_string(int1);
}
void str_int(string str, int* int1)
{
	*int1 = stoi(str);
}
/////////////////////


//in language add 16 on page search
//ITF_lib "as76das" "asdafgg125hdsg" "hdf12sbshd"
//D:\VSprojects\repos\ITF_lib
int main(int argc, char* argv[])
{
	int ch = 4;
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

		//string str;
		//if (HT.concat("asd", "fgh", "asdfgh"))
		//	cout << "same" << endl;
		//if (HT.concat(&str, "fgh", "asdfgh"))
		//	cout << "same 1st*" << endl;
		//if (HT.concat("asd", &str, "asdfgh"))
		//	cout << "same 2nd*" << endl;
		//HT.concat("asd", "fgh", &str);

		//write_value("bol(1)", 1, "asd", "asdas", "jakfg");


		//GeneralFact* GF;
		//GF = makeInstanceOf("state_node(\"init_arrays\",1,dataflow([1],2))");
		//makeStringOf(makeInstanceOf("dataflow([1],2)"));
		//state_node* SN = dynamic_cast<state_node*>(GF);
		//cout << typeid(*SN).name();
		//cout << returnpar(makeStringOf(GF), 1);


		//string Upper = "ZXCV";
		//string Lower = "zxcv";
		//if (upper_lower(Upper, Lower))
		//	cout << "identical" << endl;
		//else cout << "different" << endl;

		//string Upper;
		//string Lower = "mbbjdsfksd";
		//upper_lower(&Upper, Lower);
		//	cout << Upper << endl;
		//
		//upper_lower(Upper, &Lower);
		//	cout << Lower << endl;
		
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


void generate_top(string pathln, string exec, string cmdl)
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
		HT.consult("TYPESOPSDB.DBA", "hdlmaker_dbase");
		if (HT.findfact("hdl_style(*)"))
		{
			string Hdlform;
			Hdlform = returnpar(HT.findandreturn("hdl_style(*)"), 1);
			extract_loops_from_all_modules(2);
			generate_hdl_recursive(Hdlform, "synergy", 1);
		}
	}
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

void check_for_program_name(string pathln, string exec)
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
		extract_loops(Module_name, 1);
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
		HT.assertz("while_loop(" + to_string(*While_loop_entry) + "," + Module + "," + to_string(If_statement) + "," + to_string(Condition_statement) + "," + to_string(End_of_loop) + "," + to_string(Body_first) + "," + to_string(Body_last) + ")");
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
		HT.assertz("for_loop(" + to_string(*For_loop_entry) + "," + Module_name + "," + to_string(If_entry) + "," + to_string(Condition_statement) + "," + to_string(End_of_loop) + "," + to_string(Header_start) + "," + to_string(Increment_instruction) + "," + to_string(Increment_variable) + "," + to_string(Start_value) + "," + to_string(End_value) + "," + to_string(Increment_step) + "," + to_string(Body_first) + "," + to_string(Body_last) + "," + to_string(Iterations) + ")");
		HT.retractall("last_for_loop_entry(*)");
		HT.assertz("last_for_loop_entry(For_loop_entry)");
	}
}

/* Traces back the last operation which targets the variable */
bool trace_back(string Module, int Previous, int Variable, int* Result)
{
	if (!HT.findfact("prog_stmt(" + Module + "," + to_string(Previous) + ",*)"))
	{
		*Result = 0;
		return true;
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
			return true;
		}
	}
	else if (HT.findfact("prog_stmt(" + Module + "," + to_string(Previous) + ",*)"))
	{
		int Target, Next_previous;
		Target = stoi(returnpar(HT.findandreturn("prog_stmt(" + Module + "," + to_string(Previous) + ",*)"), 7));
		if (Target != Variable)
		{
			Next_previous = Previous - 1;
			trace_back(Module, Next_previous, Variable, Result);
			return true;
		}
	}
	return false;
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
	if (!HT.findfact("hierarchy_part(" + to_string(Entry) + ", _, _, \"libpart\",_,_,_)"))
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
				generate_hdl_2(Hdlform, Tool, Module, Level);
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
	string Memory_file_name, Cus_blocks_file_name, Module_unoptimized_dbase_filename;
	int Last_local_entry0, Next_local_entry, Last_state;
	vector<local_object> Local_list0, Local_list1, Local_list;

	if (Level == 0)
	{
		HT.concat(Module_name, ".mem", &Memory_file_name);
		consult_memory_ports(Memory_file_name);
		HT.concat(Module_name, ".cus", &Cus_blocks_file_name);
		consult_cus_blocks(Cus_blocks_file_name);
		get_and_append_local(Module_name, Local_list0, 1, &Local_list0, &Last_local_entry0); // as second argument an empty vector
		global_declarations gd(Local_list0, Last_local_entry0);
		GeneralFact* ptr = &gd;
		HT.assertz(makeStringOf(ptr));
	}
	else if (Level > 0)
	{
		if (custom_block(Module_name))
		{
			if (HT.findfact("global_declarations(*)"))
			{
				Last_local_entry0 = last_from_global_declarations(makeInstanceOf(HT.findandreturn("global_declarations(*)")));
				Local_list0 = return_vec_lo(makeInstanceOf(HT.findandreturn("global_declarations(*)")));
				Next_local_entry = Last_local_entry0 + 1;
				get_and_append_local(Module_name, Local_list0, Next_local_entry, &Local_list1, 0);
				write_custom_block(Module_name, Hdlform, Local_list1);
			}
		}
		else
		{
			remove_modules_instances();
			if (!HT.findfact("combo(_," + Module_name + ",_)") && !HT.findfact("sequence(_," + Module_name + ",_)"))
			{
				HT.retractall("module_last_state(*)");
				HT.retractall("current_module(*)");
				HT.retractall("local_object(*)");
				HT.retractall("(*)", "hdlmaker_dbase");
				eliminating_garbage_from_memory(Module_name);
				HT.assertz("current_module(" + Module_name + ")");
				HT.concat(Module_name, "_unoptimized.pdb", &Module_unoptimized_dbase_filename);
				HT.consult("Module_unoptimized_dbase_filename", "hdlmaker_dbase");
				read_last_state(&Last_state);
				read_local_list(&Local_list);
				HT.retractall("old_schedule(*)");
				HT.assertz("old_schedule(\"specials\")");
				consult_permanent_conditionally(Module_name);
				write_unoptimised_hdl(Module_name, 1, 1, Hdlform, "synergy", Last_state);
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
	string Tool, Fname, Hdlform, Global_package, Entity_name;
	int  One_after_inputs;
	if (hdlform == "vhdl")
	{
		Hdlform = "vhdl";
		Tool = "synergy";
		HT.concat(Module_name, ".vhd", &Fname);

		fstream     File(Fname, ios::out | ios::in | ios::trunc);
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
				File << "  ARCHITECTURE behaviour OF " << Entity_name << " IS " << endl << endl;
				File << "   BEGIN " << endl;
				File << "    custom_behaviour_proc : PROCESS(";
				File << write_sens_list_cus_block(Module_name, 1);
				File << ")" << endl;
				File << write_cus_block_process_io_variables(Module_name, 1, "vhdl");
				File << "     BEGIN " << endl;
				File << write_cus_block_process_input_var_assignments(Module_name, 1, "      ", &One_after_inputs);
				File << write_block_call(Module_name, 2, "      ") << endl; // from now 2 / 1 / 2013, it is always a procedure
				File << write_cus_block_process_output_var_assignments(Module_name, One_after_inputs, "      ");
				File << "      results_ready <= '1'; " << endl;
				File << "     END PROCESS custom_behaviour_proc;" << endl;
				File << "   END behaviour;" << endl;
			}
			File.close();
		}
	}
	else if (hdlform == "verilog")
	{
		Hdlform = "verilog";
		Tool = "synergy";
		HT.concat(Module_name, ".sv", &Fname);
		fstream     File(Fname, ios::out | ios::in | ios::trunc);
		if (File.is_open())
		{
			File << write_title(Module_name, Hdlform, Tool) << endl;
			File << "/*--::::: Verilog custom block: " << Module_name << " ::::::--*/" << endl;
			File << "/*-----------------------------------------------------*/" << endl;
			HT.concat(Module_name, "_cus_block", &Entity_name);
			File << write_custom_block_interface(Module_name, Entity_name, "verilog", Local_list) << endl << endl;
			File << write_cus_block_process_io_variables(Module_name, 1, "verilog");
			File << write_global_package(Module_name, Hdlform, Tool);
			File << "   always @(*)  " << endl;
			File << "    begin " << endl;
			File << write_custom_call_no_state(Module_name, "verilog");
			File << "    end " << endl;
			File << " endmodule " << endl;
		}
		File.close();
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
		if (HT.findfact("type_def(2,*)"))
		{
			int Parent;
			Parent = stoi(returnpar(HT.findandreturn("type_def(2,*)"), 5));
			*Par_Size = stoi(returnpar(HT.findandreturn("type_def(2,*)"), 3));
			if (Parent == 0)
			{
				return true;
			}
		}
	}
	else if (HT.findfact("type_def(" + to_string(Type) + ",*)"))
	{
		int Parent;
		Parent = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Type) + ",*)"), 5));
		if (Type != 2 && Parent != 0)
		{
			parent_type_is_integer(Parent, Par_Size);
			return true;
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
										if (HT.concat(".", &Just_field_type_name, Type_name))
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
					ss << write_cus_function_header_params(PModule, 1, "variable", "verilog");
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
	if (HT.findfact("data_stmt(" + PModule + ",_," + to_string(Entry) + ",_,_,_)"))
	{
		InOutType = returnpar(HT.findandreturn("data_stmt(" + PModule + ",_," + to_string(Entry) + ",_,_,_)"), 5);
		if (InOutType != "par_in" && InOutType != "par_inout" && InOutType != "par_out")
			return ss.str();
	}
	if (!HT.findfact("data_stmt(" + PModule + ",_," + to_string(Entry) + ",_,_,_)"))
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
	if (str2 == "vhdl")
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
	string Dotted_field, Just_recname, Underscored_name, Just_field, Underscored_field;
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
	if (HT.findfact("combo(_," + Module_name + ",_)") || HT.findfact("sequence(_," + Module_name + ",_)"))
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
				if (HT.findfact("type_def(" + to_string(Func_type_entry) + "," + Func_type_name + ",_,_,_,\"vectorarray_t\",_,_,_)"))
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
					ss << "      CONSTANT " << Dname << " : std_logic := '" << Valueaf << "';";
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
		Cond_type, Cond_size, If_statement, Condition_start, Body_last, Condition_end, ResType, FunctionNameEntry, DoIt;
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
			else if (HT.findfact("for_loop(_," + PModule + ",_,_,_,_," + to_string(var3) + ",_,_,_,_,_,_,_)"))
			{
				*Next_intend = Intend;
			}
			else if (HT.findfact("for_loop(_," + PModule + ",_,_,_," + to_string(var3) + ",_,_,_,_,_,_,_,_)"))
			{
				*Next_intend = Intend;
			}
			else if (HT.findfact("for_loop(_," + PModule + ",_," + to_string(var3) + ",_,_,_,_,_,_,_,_,_,_)"))
			{
				*Next_intend = Intend;
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
					if (HT.findfact("data_stmt(" + PModule + ",_," + to_string(Increment_variable) + ",_,\"var\",sym(_))"))
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
				if (HT.findfact("data_stmt(" + PModule + ",_," + to_string(Cond_result) + ",_,_,_)"))
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
			else if (HT.findfact("for_loop(_," + PModule + ",_,_,_,_," + to_string(var3) + ",_,_,_,_,_,_,_)"))
			{
				*Next_intend = Intend;
			}
			else if (HT.findfact("for_loop(_," + PModule + ",_,_,_," + to_string(var3) + ",_,_,_,_,_,_,_,_)"))
			{
				*Next_intend = Intend;
			}
			else if (HT.findfact("for_loop(_," + PModule + ",_," + to_string(var3) + ",_,_,_,_,_,_,_,_,_,_)"))
			{
				*Next_intend = Intend;
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
						else if (HT.findfact("op_def(" + to_string(Op) + ",\"not\",\"unop\",_,_,_,_)") || HT.findfact("op_def(" + to_string(Op) + ",\"abs\",\"unop\",_,_,_,_)"))
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
											ss << print_possible_return(PModule, ResData, Rdata, " = ", "c", &DoIt);
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
											if (HT.findfact("type_def(" + to_string(ResType) + ",_,_,_,_,\"record_t\",_,_,_)"))
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
			else if (HT.findfact("for_loop(_," + PModule + ",_,_,_,_," + to_string(var3) + ",_,_,_,_,_,_,_)"))
			{
				*Next_intend = Intend;
			}
			else if (HT.findfact("for_loop(_," + PModule + ",_,_,_," + to_string(var3) + ",_,_,_,_,_,_,_,_)"))
			{
				*Next_intend = Intend;
			}
			else if (HT.findfact("for_loop(_," + PModule + ",_," + to_string(var3) + ",_,_,_,_,_,_,_,_,_,_)"))
			{
				*Next_intend = Intend;
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
	if (HT.findfact("data_stmt(" + PModule + "," + Data + ",*)"))
	{
		*Kind = returnpar(HT.findandreturn("data_stmt(" + PModule + "," + Data + ",*)"), 5);
		Increment_variable = stoi(returnpar(HT.findandreturn("data_stmt(" + PModule + "," + Data + ",*)"), 3));
		if (HT.findfact("for_loop(_," + PModule + ",_,_,_,_,_," + to_string(Increment_variable) + ",_,_,_,_,_,_)"))
			*Kind = "loop_var";
	}
}

bool is_relational_op(string str)
{
	return str == "=" || str == "<" || str == "<=" || str == ">"
		|| str == ">=" || str == "and" || str == "or" || str == "xor" || str == "not";
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
		else if (Hdl == "c")
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
	else if (!HT.findfact("custom_block(" + Module_name + ")"))
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
	else if (HDL == "c")
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
		else if (PModule == ResData)
		{
			if (!HT.findfact("mem_port(_,_," + ResData + "," + ResData + ",_,_,_,_,_,_,_,_,_)"))
			{
				ss << ResData << "_function " << Assignment_string << " ";
				*int1 = 1;
			}
			else
				*int1 = 1;
		}
	}
	else if (HDL == "c")
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
			else
				*int1 = 1;
		}
	}
	else
	{
		if (PModule != ResData)
		{
			if (HT.findfact("mem_port(_,_," + PModule + "," + PModule + ",_,_,_,_,_,_,_,_,_)"))
				*int1 = 1;
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
			HT.assertz("nested_cond_fact(" + PModule + "," + nce_str(New_stack) + ")");
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
		else
		{
			If_then_stmt--; // If_then_stmt = Condition_end, % in case that the conditional variable is located in the 106
			if (HT.findfact("while_loop(_," + PModule + "," + to_string(If_then_stmt) + ",_,_,_,_)"))
			{
				if (HT.concat(Out_intend, " ", Intend))  // reduce the intend by one / line 12774
					ss << write_end_of_loop(*Out_intend, Lang) << endl;
			}
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
	if (var1 == 1)
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
	else if (HT.findfact("checkstyle(\"checkhierarchy\")"))
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
	if (HDL == "vhdl")
	{
		ss << "  ENTITY " << Entity_name << " IS" << endl;
		ss << write_interface_header("vhdl", "synergy");
		ss << write_io_ports(Module_name, 1, "vhdl", "synergy", "custom");
		ss << "        results_ready : OUT std_logic" << endl;
		ss << write_interface_tail(Entity_name, "vhdl", "synergy");
	}
	else if (HDL == "verilog")
	{
		ss << "  module " << Entity_name << " (" << endl;
		ss << write_verilog_ports(Module_name, 1, "verilog");
		ss << "                  results_ready );" << endl;
		ss << write_io_ports(Module_name, 1, "verilog", "synergy", "regular");
		ss << "    output results_ready ;" << endl;
		ss << "       reg results_ready ;" << endl;
	}
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
	int Next_entry;
	if (HT.findfact("local_object(" + Module + "," + to_string(In_entry) + ",*)"))
	{
		Local = makeInstanceOf(HT.findandreturn("local_object(" + Module + "," + to_string(In_entry) + ",*)"));
		local_object* ptr = dynamic_cast<local_object*>(Local);
		ss << write_io_ports_core_cond(*ptr, Hdl, Tool, Usage);
		Next_entry = In_entry + 1;
		ss << write_io_ports(Module, Next_entry, Hdl, Tool, Usage);
	}
	return ss.str();
}

string write_io_ports_core_cond(local_object Local, string HDL, string Tool, string str)
{
	stringstream ss;
	string Module, Name, Ltype, Type, Kind, Value, Name1;
	int In_entry, Order, Size;
	GeneralFact* ptr;
	ptr = &Local;
	Module = returnpar(HT.findandreturn(makeStringOf(ptr)), 1);
	In_entry = stoi(returnpar(HT.findandreturn(makeStringOf(ptr)), 2));
	Ltype = returnpar(HT.findandreturn(makeStringOf(ptr)), 3);
	Name = returnpar(HT.findandreturn(makeStringOf(ptr)), 4);
	Order = stoi(returnpar(HT.findandreturn(makeStringOf(ptr)), 5));
	Type = returnpar(HT.findandreturn(makeStringOf(ptr)), 6);
	Kind = returnpar(HT.findandreturn(makeStringOf(ptr)), 7);
	Size = stoi(returnpar(HT.findandreturn(makeStringOf(ptr)), 8));
	Value = returnpar(HT.findandreturn(makeStringOf(ptr)), 9);
	if (str == "regular")
	{
		if (Module == Name)
			ss << write_io_port(Local, HDL, Tool);
	}
	else if (str == "custom")
	{
		if (Module == Name)
		{
			HT.concat(Name, "_out", &Name1);
			local_object Local1(Module, In_entry, Ltype, Name1, Order, Type, Kind, Size, Value);
			write_io_port(Local1, HDL, Tool);
		}
	}
	else if (Ltype == "par_in")
	{
		if (Module != Name)
		{
			if (!is_it_the_last_io(Module, "vhdl", In_entry, 0))
			{
				ss << write_io_port(Local, HDL, Tool);
			}
			else if (HT.findfact("local_object(" + Module + ",_,\"par_out\",_,_,_,_,_,_)"))
				ss << write_io_port(Local, HDL, Tool);
			else if (HT.findfact("local_object(" + Module + ",_,\"par_inout\",_,_,_,_,_,_)"))
				ss << write_io_port(Local, HDL, Tool);
			else
				ss << write_io_port(Local, HDL, Tool) << ";";
		}
	}
	else if (Module != Name)
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
	int Current_entry, var5, Local_size, LastIO, Componenttype, Type_size, Comp_type, Num_dim, First_dim, Last_dim, Upper_bound, Comp_num_dim,
		Array_index_size, Index_upper;
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
				else if (is_it_the_last_io(Module, "vhdl", Current_entry, &LastIO))
				{
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
					if (is_it_the_last_io(Module, "vhdl", Current_entry, &LastIO))
					{
						ss << write_size(Local_size, "std_logic", "vhdl", "synergy", LastIO);
						ss << endl;
					}
				}
				else if (HT.findfact("type_def(_," + Local_type + "," + to_string(Local_size) + ",\"user\",_,\"single_t\",_,_,_)"))
				{
					ss << "        " << Local_name << " : IN ";
					if (is_it_the_last_io(Module, "vhdl", Current_entry, &LastIO))
						ss << write_size(Local_size, "std_logic", "vhdl", "synergy", LastIO) << endl;
				}
				else if (HT.findfact("type_def(_," + Local_type + "," + to_string(Local_size) + ",\"user\",0,\"vectorarray_t\",_,_,_)"))
				{
					if (is_it_the_last_io(Module, "vhdl", Current_entry, &LastIO))
					{
						ss << "        " << Local_name << " : IN " << Local_type;
						ss << print_conditional_end_of_statement(LastIO);
						ss << endl;
					}
				}
				else if (HT.findfact("type_def(_," + Local_type + "," + to_string(Local_size) + ",\"user\",0,\"record_t\",_,_,_)"))
				{
					if (is_it_the_last_io(Module, "vhdl", Current_entry, &LastIO))
					{
						ss << "        " << Local_name << " : IN " << Local_type;
						ss << print_conditional_end_of_statement(LastIO);
						ss << endl;
					}
				}
			}
			else if (var7 == "userarray")
			{
				if (Local_type != "bool")
				{
					ss << "        ";
					if (HT.findfact("type_def(_," + Local_type + "," + to_string(Local_size) + ",_,_,\"vectorarray_t\",_," + to_string(Local_size) + ",1)"))
					{
						if (is_it_the_last_io(Module, "vhdl", Current_entry, &LastIO))
						{
							ss << Local_name << " : IN";
							ss << write_size(Local_size, "std_logic", "vhdl", "synergy", LastIO) << endl;
						}
					}
					else if (HT.findfact("type_def(_," + Local_type + "," + to_string(Local_size) + ",_,_,_,_,_,_)"))
					{
						Componenttype = stoi(returnpar(HT.findandreturn("type_def(_," + Local_type + "," + to_string(Local_size) + ",_,_,_,_,_,_)"), 9));
						if (Componenttype != 1)
						{
							if (is_it_the_last_io(Module, "vhdl", Current_entry, &LastIO))
							{
								ss << print_vhdl_par_out_name_cond(Module, Local_name);
								ss << " : IN " << Local_type;
								ss << print_conditional_end_of_statement(LastIO);
								ss << endl;
							}
						}
					}
				}
			}
			else if (var7 == "userrecord")
			{
				if (Local_type != "bool")
				{
					if (is_it_the_last_io(Module, "vhdl", Current_entry, &LastIO))
					{
						replace_chars_in_string(Local_name, ".", "_", &NewName);
						ss << "        " << NewName << " : IN " << Local_type;
						ss << print_conditional_end_of_statement(LastIO);
						ss << endl;
					}
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
				else if (is_it_the_last_io(Module, "vhdl", Current_entry, &LastIO))
				{
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
					if (is_it_the_last_io(Module, "vhdl", Current_entry, &LastIO))
					{
						ss << "        " << Local_name << " : OUT ";
						ss << write_size(Local_size, "std_logic", "vhdl", "synergy", 0) << endl;
					}
				}
				else if (HT.findfact("type_def(_," + Local_type + "," + to_string(Local_size) + ",\"user\",_,\"single_t\",_,_,_)"))
				{
					if (is_it_the_last_io(Module, "vhdl", Current_entry, &LastIO))
					{
						ss << "        " << Local_name << " : OUT ";
						ss << write_size(Local_size, "std_logic", "vhdl", "synergy", 0) << endl;
					}
				}
				else if (HT.findfact("type_def(_," + Local_type + "," + to_string(Local_size) + ",\"user\",0,\"vectorarray_t\",_,_,_)"))
				{
					if (is_it_the_last_io(Module, "vhdl", Current_entry, &LastIO))
					{
						ss << "        " << Local_name << " : OUT " << Local_type;
						print_conditional_end_of_statement(0);
						ss << endl;
					}
				}
				else if (HT.findfact("type_def(_," + Local_type + "," + to_string(Local_size) + ",\"user\",0,\"record_t\",_,_,_)"))
				{
					if (is_it_the_last_io(Module, "vhdl", Current_entry, &LastIO))
					{
						ss << "        " << Local_name << " : OUT " << Local_type;
						ss << print_conditional_end_of_statement(0);
						ss << endl;
					}
				}
			}
			else if (var7 == "userarray")
			{
				if (Local_type != "bool")
				{
					if (is_it_the_last_io(Module, "vhdl", Current_entry, &LastIO))
					{

						if (HT.findfact("type_def(_," + Local_type + "," + to_string(Local_size) + ",_,_,\"vectorarray_t\",_," + to_string(Local_size) + ",1)"))
						{
							ss << "        ";
							if (is_it_the_last_io(Module, "vhdl", Current_entry, &LastIO))
							{
								ss << Local_name << " : OUT";
								ss << write_size(Local_size, "std_logic", "vhdl", "synergy", 0) << endl;
							}
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
			}
			else if (var7 == "userrecord")
			{
				if (Local_type != "bool")
				{
					if (is_it_the_last_io(Module, "vhdl", Current_entry, &LastIO))
					{
						ss << "        ";
						replace_chars_in_string(Local_name, ".", "_", &NewName);
						ss << print_vhdl_par_out_name_cond(Module, NewName);
						ss << " : OUT " << Local_type;
						ss << print_conditional_end_of_statement(LastIO);
						ss << endl;
					}
				}
			}
		}
		else if (var3 == "par_inout")
		{
			if (var7 == "standard")
			{
				if (Local_type != "bool")
				{
					if (is_it_the_last_io(Module, "vhdl", Current_entry, &LastIO))
					{
						ss << "        " << Local_name << " : INOUT ";
						ss << write_size(Local_size, "std_logic", "vhdl", "synergy", LastIO) << endl;
					}
				}
				else if (is_it_the_last_io(Module, "vhdl", Current_entry, &LastIO))
				{
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
					if (is_it_the_last_io(Module, "vhdl", Current_entry, &LastIO))
					{
						ss << "        " << Local_name << " : INOUT ";
						ss << write_size(Local_size, "std_logic", "vhdl", "synergy", LastIO) << endl;
					}
				}
				else if (HT.findfact("type_def(_," + Local_type + "," + to_string(Local_size) + ",\"user\",_,\"single_t\",_,_,_)"))
				{
					if (is_it_the_last_io(Module, "vhdl", Current_entry, &LastIO))
					{
						ss << "        " << Local_name << " : INOUT ";
						ss << write_size(Local_size, "std_logic", "vhdl", "synergy", LastIO) << endl;
					}
				}
				else if (HT.findfact("type_def(_," + Local_type + "," + to_string(Local_size) + ",\"user\",0,\"vectorarray_t\",_,_,_)"))
				{
					if (is_it_the_last_io(Module, "vhdl", Current_entry, &LastIO))
					{
						ss << "        " << Local_name << " : INOUT " << Local_type;
						ss << print_conditional_end_of_statement(LastIO);
						ss << endl;
					}
				}
				else if (HT.findfact("type_def(_," + Local_type + "," + to_string(Local_size) + ",\"user\",0,\"record_t\",_,_,_)"))
				{
					if (is_it_the_last_io(Module, "vhdl", Current_entry, &LastIO))
					{
						ss << "        " << Local_name << " : INOUT " << Local_type;
						ss << print_conditional_end_of_statement(LastIO);
						ss << endl;
					}
				}
			}
			else if (var7 == "userarray")
			{
				if (Local_type != "bool")
				{
					if (is_it_the_last_io(Module, "vhdl", Current_entry, &LastIO))
					{
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
			}
			else if (var7 == "userrecord")
			{
				if (Local_type != "bool")
				{
					if (is_it_the_last_io(Module, "vhdl", Current_entry, &LastIO))
					{
						replace_chars_in_string(Local_name, ".", "_", &NewName);
						ss << "        " << NewName << " : INOUT " << Local_type;
						ss << print_conditional_end_of_statement(LastIO);
						ss << endl;
					}
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
			if (Local_type != "bool")
			{
				if (Local_type != "userarray" && Local_type != "userrecord")
				{
					if (HT.findfact("type_def(_," + Local_type + ",_,_,_,\"vectorarray_t\",_,_,_)"))
					{
						Type_number = stoi(returnpar(HT.findandreturn("type_def(_," + Local_type + ",_,_,_,\"vectorarray_t\",_,_,_)"), 1));
						Numb_of_dim = stoi(returnpar(HT.findandreturn("type_def(_," + Local_type + ",_,_,_,\"vectorarray_t\",_,_,_)"), 8));
						if (HT.findfact("data_stmt(" + Module + ",_," + to_string(var5) + "," + to_string(Type_number) + ",_,_)"))
						{
							Replacement_name = returnpar(HT.findandreturn("data_stmt(" + Module + ",_," + to_string(var5) + "," + to_string(Type_number) + ",_,_)"), 2);
							if (!HT.findfact("mem_port(_,_," + Module + "," + Replacement_name + ",_,_,_,_,_,_,_,_,_)"))
							{
								find_child_type(Type_number, &Child_type);
								if (HT.findfact("type_def(" + to_string(Child_type) + ",_,1,_,_,_,_,_,_)"))
								{
									ss << "   input ";
									ss << write_verilog_dimmension_component_recursively(Type_number);
									ss << " " << Local_name << " ; " << endl;
								}
								else if (HT.findfact("type_def(" + to_string(Child_type) + ",_,_,_,_,_,_,_,_)"))
								{
									Child_size = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Child_type) + ",_,_,_,_,_,_,_,_)"), 3));
									if (Child_size > 1)
									{
										Child_upper = Child_size - 1;
										ss << "   input ";
										ss << " [" << Child_upper << ":0] " << Local_name << " ";
										ss << write_verilog_dimmension_component_recursively(Type_number);
										ss << " ; " << endl;
										ss << write_verilog_array_index_registers(Module, Local_name, Type_number, Numb_of_dim, Numb_of_dim, 1);
									}
								}
							}
						}
					}
					else if (HT.findfact("type_def(_," + Local_type + ",_,_,_,_,_,_,_)"))
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
				else if (HT.findfact("type_def(_," + Local_type + ",_,_,_,_,_,_,_)"))
				{
					Type_size = stoi(returnpar(HT.findandreturn("type_def(_," + Local_type + ",_,_,_,_,_,_,_)"), 3));
					if (Type_size == 1)
						ss << "   input " << Local_name << " ;" << endl;
				}
			}
			else if (Local_type == "std_logic")
			{
				ss << "   input ";
				ss << write_size(Local_size, "std_logic", "verilog", "synergy", 1);
				ss << " " << Local_name << " ; " << endl;
			}
			else if (Local_type == "bool")
			{
				ss << "   input " << Local_name << " ;" << endl;
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
					Numb_of_dim = stoi(returnpar(HT.findandreturn("type_def(_," + Local_type + ",_,_,_,\"vectorarray_t\",_,_,_)"), 8));
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
								else if (Child_size == 1)
								{
									Child_upper = Child_size - 1;
									ss << write_verilog_dimmension_component_recursively(Type_number);
									ss << " " << Local_name << "; " << endl;
								}
							}
						}
					}
				}
			}
			else if (var7 == "userarray")
			{
				if (Local_type != "bool")
				{
					if (HT.findfact("type_def(_," + Local_type + ",_,_,_,_,_,_,_)"))
					{
						Type_number = stoi(returnpar(HT.findandreturn("type_def(_," + Local_type + ",_,_,_,_,_,_,_)"), 1));
						First_dim = stoi(returnpar(HT.findandreturn("type_def(_," + Local_type + ",_,_,_,_,_,_,_)"), 7));
						Num_dim = stoi(returnpar(HT.findandreturn("type_def(_," + Local_type + ",_,_,_,_,_,_,_)"), 8));
						Comp_type = stoi(returnpar(HT.findandreturn("type_def(_," + Local_type + ",_,_,_,_,_,_,_)"), 9));
						if (HT.findfact("type_def(" + to_string(Comp_type) + ",*)"))
						{
							Comp_size = stoi(returnpar(HT.findandreturn("type_def(_," + Local_type + ",*)"), 3));
							if (Comp_size > 1)
							{
								ss << "   input ";
								if (Current_entry > 0)
								{
									find_child_type(Type_number, &Child_type);
									if (HT.findfact("type_def(" + to_string(Child_type) + ",*)"))
									{
										Child_size = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Child_type) + ",*)"), 3));
										Child_upper = Child_size - 1;
										ss << " [" << Child_upper << ":0] " << Local_name << " ";
										ss << write_verilog_dimmension_component_recursively(Type_number);
										ss << " ; " << endl;
									}
								}
							}
							else if (Comp_size == 1)
							{
								Last_dim = Num_dim - 1;
								if (Last_dim > First_dim)
								{
									ss << "   input   ";
									ss << " [" << First_dim << ":" << Last_dim << "] " << Local_name << ";";
								}
							}
						}
					}
				}
			}
			else if (var7 == "userrecord")
			{
				if (Local_type != "bool")
				{
					ss << "   input ";
					if (Current_entry > 0)
					{
						if (HT.findfact("type_def(_," + Local_type + ",_,_,_,_,_,_,_)"))
						{
							Type_number = stoi(returnpar(HT.findandreturn("type_def(_," + Local_type + ",*)"), 1));
							Local_size = stoi(returnpar(HT.findandreturn("type_def(_," + Local_type + ",*)"), 3));
							Upper_bound = Local_size - 1;
							ss << " [" << Upper_bound << ":0] " << Local_name;
							ss << write_verilog_dimmension_component_recursively(Type_number);
							ss << " ; " << endl;
						}
					}
				}
			}
		}
		else if (var3 == "par_out")
		{
			if (Local_type != "bool")
			{
				if (HT.findfact("type_def(_," + Local_type + ",_,_,_,_,_,_,_)"))
				{
					Type_size = stoi(returnpar(HT.findandreturn("type_def(_," + Local_type + ",_,_,_,_,_,_,_)"), 3));
					if (Type_size == 1)
					{
						ss << "   output " << Local_name << " ;" << endl;
						ss << "   reg    " << Local_name << " ;" << endl;
					}
				}
				else if (var7 != "userarray")
				{
					if (var7 != "userrecord")
					{
						if (HT.findfact("type_def(_," + Local_type + ",_,_,_,\"vectorarray_t\",_,_,1)"))
						{
							Type_number = stoi(returnpar(HT.findandreturn("type_def(_," + Local_type + ",_,_,_,\"vectorarray_t\",_,_,1)"), 1));
							ss << "   output ";
							ss << write_verilog_dimmension_component_recursively(Type_number);
							ss << Local_name << " ;" << endl;
							ss << "      reg ";
							ss << write_verilog_dimmension_component_recursively(Type_number);
							ss << Local_name << " ;" << endl;
						}
						else if (HT.findfact("type_def(_," + Local_type + ",_,_,_,\"vectorarray_t\",_,_,_)"))
						{
							Type_number = stoi(returnpar(HT.findandreturn("type_def(_," + Local_type + ",_,_,_,\"vectorarray_t\",_,_,_)"), 1));
							Numb_of_dim = stoi(returnpar(HT.findandreturn("type_def(_," + Local_type + ",_,_,_,\"vectorarray_t\",_,_,_)"), 8));
							First_comp_type = stoi(returnpar(HT.findandreturn("type_def(_," + Local_type + ",_,_,_,\"vectorarray_t\",_,_,_)"), 9));
							if (First_comp_type <= 10)
							{
								if (First_comp_type > 1)
								{
									if (HT.findfact("data_stmt(" + Module + ",_," + to_string(var5) + "," + to_string(Type_number) + ",_,_)"))
									{
										Replacement_name = stoi(returnpar(HT.findandreturn("data_stmt(" + Module + ",_," + to_string(var5) + "," + to_string(Type_number) + ",_,_)"), 2));
										if (!HT.findfact("mem_port(_,_," + Module + "," + Replacement_name + ",_,_,_,_,_,_,_,_,_)"))
										{
											ss << "   output ";
											find_child_type(Type_number, &Child_type);
											if (HT.findfact("type_def(" + to_string(Child_type) + ",*)"))
											{
												Child_size = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Child_type) + ",*)"), 3));
												Child_upper = Child_size - 1;
												ss << " [" << Child_upper << ":0] " << Local_name << " ";
												ss << write_verilog_dimmension_component_recursively(Type_number);
												ss << " ; " << endl;
												ss << "   reg ";
												ss << " [" << Child_upper << ":0] " << Local_name << " ";
												ss << write_verilog_dimmension_component_recursively(Type_number);
												ss << " ; " << endl;
												ss << write_verilog_array_index_registers(Module, Local_name, Type_number, Numb_of_dim, 0, 1);
											}
										}
									}
								}
							}
							else if (HT.findfact("type_def(" + to_string(First_comp_type) + ",_,_,_,_,\"vectorarray_t\",_,_,_)"))
							{
								if (HT.findfact("data_stmt(" + Module + ",_," + to_string(var5) + "," + to_string(Type_number) + ",_,_)"))
								{
									Replacement_name = stoi(returnpar(HT.findandreturn("data_stmt(" + Module + ",_," + to_string(var5) + "," + to_string(Type_number) + ",_,_)"), 2));
									if (!HT.findfact("mem_port(_,_," + Module + "," + Replacement_name + ",_,_,_,_,_,_,_,_,_)"))
									{
										ss << "   output ";
										find_child_type(Type_number, &Child_type);
										if (HT.findfact("type_def(" + to_string(Child_type) + ",*)"))
										{
											Child_size = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Child_type) + ",*)"), 3));
											Child_upper = Child_size - 1;
											ss << " [" << Child_upper << ":0] " << Local_name << " ";
											ss << write_verilog_dimmension_component_recursively(Type_number);
											ss << " ; " << endl;
											ss << "   reg ";
											ss << " [" << Child_upper << ":0] " << Local_name << " ";
											ss << write_verilog_dimmension_component_recursively(Type_number);
											ss << " ; " << endl;
											ss << write_verilog_array_index_registers(Module, Local_name, Type_number, Numb_of_dim, Numb_of_dim, 1);
										}
									}
								}
							}
						}
						else if (HT.findfact("type_def(_," + Local_type + ",_,_,_,_,_,_,_)"))
						{
							Type_kind = stoi(returnpar(HT.findandreturn("type_def(_," + Local_type + ",_,_,_,_,_,_,_)"), 6));
							if (Type_kind != "vectorarray_t")
							{
								ss << "   output ";
								ss << write_size(Local_size, "std_logic", "verilog", "synergy", 1);
								ss << " " << Local_name << " ; " << endl;
								ss << "   reg    ";
								ss << write_size(Local_size, "std_logic", "verilog", "synergy", 1);
								ss << " " << Local_name << " ; " << endl;
							}
						}
					}
				}
			}
			else if (Local_type == "bool")
			{
				ss << "   output " << Local_name << " ;" << endl;
				ss << "   reg    " << Local_name << " ;" << endl;

			}
			else if (Local_type == "std_logic")
			{
				ss << "   input ";
				ss << write_size(Local_size, "std_logic", "verilog", "synergy", 1);
				ss << " " << Local_name << " ; " << endl;
				ss << "   reg    ";
				ss << write_size(Local_size, "std_logic", "verilog", "synergy", 1);
				ss << " " << Local_name << " ; " << endl;
			}
			else if (var7 == "standard")
			{
				if (HT.findfact("type_def(_," + Local_type + ",_,_,_,\"vectorarray_t\",_,_,_)"))
				{
					Type_number = stoi(returnpar(HT.findandreturn("type_def(_," + Local_type + ",_,_,_,\"vectorarray_t\",_,_,_)"), 1));
					if (HT.findfact("data_stmt(" + Module + ",_," + to_string(var5) + "," + to_string(Type_number) + ",_,_)"))
					{
						Replacement_name = stoi(returnpar(HT.findandreturn("data_stmt(" + Module + ",_," + to_string(var5) + "," + to_string(Type_number) + ",_,_)"), 2));
						if (HT.findfact("mem_port(_,_," + Module + "," + Replacement_name + ",_,_,_,_,_,_,_,_,_)"))
						{
							ss << "   output ";
							ss << write_size(Local_size, "std_logic", "verilog", "synergy", 1);
							ss << " " << Local_name << " ; " << endl;
							ss << "   reg    ";
							ss << write_size(Local_size, "std_logic", "verilog", "synergy", 1);
							ss << " " << Local_name << " ; " << endl;
						}
					}
				}
			}
			else if (var7 == "user")
			{
				if (HT.findfact("type_def(_," + Local_type + ",_,_,_,\"vectorarray_t\",_,_,_)"))
				{
					Type_number = stoi(returnpar(HT.findandreturn("type_def(_," + Local_type + ",_,_,_,\"vectorarray_t\",_,_,_)"), 1));
					Numb_of_dim = stoi(returnpar(HT.findandreturn("type_def(_," + Local_type + ",_,_,_,\"vectorarray_t\",_,_,_)"), 8));
					First_comp_type = stoi(returnpar(HT.findandreturn("type_def(_," + Local_type + ",_,_,_,\"vectorarray_t\",_,_,_)"), 9));
					if (First_comp_type <= 10)
					{
						if (HT.findfact("data_stmt(" + Module + ",_," + to_string(var5) + "," + to_string(Type_number) + ",_,_)"))
						{
							Replacement_name = stoi(returnpar(HT.findandreturn("data_stmt(" + Module + ",_," + to_string(var5) + "," + to_string(Type_number) + ",_,_)"), 2));
							if (HT.findfact("mem_port(_,_," + Module + "," + Replacement_name + ",_,_,_,_,_,_,_,_,_)"))
							{
								ss << "   output ";
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
										ss << "   reg ";
										ss << " [" << Child_upper << ":0] " << Local_name << " ";
										ss << write_verilog_dimmension_component_recursively(Type_number);
										ss << " ; " << endl;
										ss << write_verilog_array_index_registers(Module, Local_name, Type_number, Numb_of_dim, 0, 1);
									}
									else if (Child_size == 1)
									{
										ss << write_verilog_dimmension_component_recursively(Type_number);
										ss << Local_name << " ; " << endl;
										ss << "   reg ";
										ss << write_verilog_dimmension_component_recursively(Type_number);
										ss << Local_name << " ; " << endl;
									}
								}
							}
						}
					}
					else if (HT.findfact("type_def(" + to_string(First_comp_type) + ",_,_,_,_,\"vectorarray_t\",_,_,_)"))
					{
						if (HT.findfact("data_stmt(" + Module + ",_," + to_string(var5) + "," + to_string(Type_number) + ",_,_)"))
						{
							Replacement_name = stoi(returnpar(HT.findandreturn("data_stmt(" + Module + ",_," + to_string(var5) + "," + to_string(Type_number) + ",_,_)"), 2));
							if (HT.findfact("mem_port(_,_," + Module + "," + Replacement_name + ",_,_,_,_,_,_,_,_,_)"))
							{
								ss << "   output ";
								find_child_type(Type_number, &Child_type);
								if (HT.findfact("type_def(" + to_string(Child_type) + ",*)"))
								{
									Child_size = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Child_type) + ",*)"), 3));
									Child_upper = Child_size - 1;
									ss << " [" << Child_upper << ":0] " << Local_name << " ";
									ss << write_verilog_dimmension_component_recursively(Type_number);
									ss << " ; " << endl;
									ss << "   reg ";
									ss << " [" << Child_upper << ":0] " << Local_name << " ";
									ss << write_verilog_dimmension_component_recursively(Type_number);
									ss << " ; " << endl;
									ss << write_verilog_array_index_registers(Module, Local_name, Type_number, Numb_of_dim, Numb_of_dim, 1);
								}
							}
						}
					}
				}
			}
			else if (var7 == "userarray")
			{
				if (Local_type != "bool")
				{
					if (HT.findfact("type_def(_," + Local_type + ",_,_,_,\"vectorarray_t\",_,_,_)"))
					{
						Type_number = stoi(returnpar(HT.findandreturn("type_def(_," + Local_type + ",_,_,_,\"vectorarray_t\",_,_,_)"), 1));
						Num_dim = stoi(returnpar(HT.findandreturn("type_def(_," + Local_type + ",_,_,_,\"vectorarray_t\",_,_,_)"), 8));
						Comp_type = stoi(returnpar(HT.findandreturn("type_def(_," + Local_type + ",_,_,_,\"vectorarray_t\",_,_,_)"), 9));
						if (HT.findfact("type_def(" + to_string(Comp_type) + ",_,_,_,_,\"vectorarray_t\",_,_,_)"))
						{
							Comp_size = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Comp_type) + ",_,_,_,_,\"vectorarray_t\",_,_,_)"), 3));
							Comp_num_dim = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Comp_type) + ",_,_,_,_,\"vectorarray_t\",_,_,_)"), 8));
							if (Comp_size > 1)
							{
								if (Current_entry > 0)
								{
									find_child_type(Type_number, &Child_type);
									if (HT.findfact("type_def(" + to_string(Child_type) + ",*)"))
									{
										Child_size = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Child_type) + ",*)"), 3));
										Child_upper = Child_size - 1;
										ss << "   output ";
										ss << " [" << Child_upper << ":0] " << Local_name << " ";
										ss << write_verilog_dimmension_component_recursively(Type_number);
										ss << " ; " << endl;
										ss << "   reg ";
										ss << " [" << Child_upper << ":0] " << Local_name << " ";
										ss << write_verilog_dimmension_component_recursively(Type_number);
										ss << " ; " << endl;
										ss << write_verilog_array_index_registers(Module, Local_name, Type_number, Num_dim, Comp_num_dim, 1);
									}
								}
							}
						}
						else if (HT.findfact("type_def(" + to_string(Comp_type) + ",_,_,_,_,\"record_t\",_,_,_)"))
						{
							Comp_size = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Comp_type) + ",_,_,_,_,\"record_t\",_,_,_)"), 3));
							Comp_num_dim = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Comp_type) + ",_,_,_,_,\"record_t\",_,_,_)"), 8));
							if (Comp_size > 1)
							{
								if (Current_entry > 0)
								{
									find_child_type(Type_number, &Child_type);
									if (HT.findfact("type_def(" + to_string(Child_type) + ",*)"))
									{
										Child_size = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Child_type) + ",*)"), 3));
										Child_upper = Child_size - 1;
										ss << "   output ";
										ss << " [" << Child_upper << ":0] " << Local_name << " ";
										ss << write_verilog_dimmension_component_recursively(Type_number);
										ss << " ; " << endl;
										ss << "   reg ";
										ss << " [" << Child_upper << ":0] " << Local_name << " ";
										ss << write_verilog_dimmension_component_recursively(Type_number);
										ss << " ; " << endl;
										ss << write_verilog_array_index_registers(Module, Local_name, Type_number, Num_dim, 0, 1) << endl;
									}
								}
							}
						}
						else if (HT.findfact("type_def(" + to_string(Comp_type) + ",_,_,_,_,\"single_t\",_,_,_)"))
						{
							Comp_size = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Comp_type) + ",_,_,_,_,\"single_t\",_,_,_)"), 3));
							Comp_num_dim = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Comp_type) + ",_,_,_,_,\"single_t\",_,_,_)"), 8));
							if (Comp_size > 1)
							{
								if (Current_entry > 0)
								{
									find_child_type(Type_number, &Child_type);
									if (HT.findfact("type_def(" + to_string(Child_type) + ",*)"))
									{
										Child_size = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Child_type) + ",*)"), 3));
										Child_upper = Child_size - 1;
										ss << "   output ";
										ss << " [" << Child_upper << ":0] " << Local_name << " ";
										ss << write_verilog_dimmension_component_recursively(Type_number);
										ss << " ; " << endl;
										ss << "   reg ";
										ss << " [" << Child_upper << ":0] " << Local_name << " ";
										ss << write_verilog_dimmension_component_recursively(Type_number);
										ss << " ; " << endl;
										ss << write_verilog_array_index_registers(Module, Local_name, Type_number, Num_dim, 0, 1) << endl;
									}
								}
							}
						}
					}
					else if (HT.findfact("type_def(_," + Local_type + ",_,_,_,_,_,_,_)"))
					{
						Type_size = stoi(returnpar(HT.findandreturn("type_def(_," + Local_type + ",_,_,_,_,_,_,_)"), 3));
						First_dim = stoi(returnpar(HT.findandreturn("type_def(_," + Local_type + ",_,_,_,_,_,_,_)"), 7));
						Num_dim = stoi(returnpar(HT.findandreturn("type_def(_," + Local_type + ",_,_,_,_,_,_,_)"), 8));
						Comp_type = stoi(returnpar(HT.findandreturn("type_def(_," + Local_type + ",_,_,_,_,_,_,_)"), 9));
						if (HT.findfact("type_def(" + to_string(Comp_type) + ",_,_,_,_,_,_,_,_)"))
						{
							Comp_size = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Comp_type) + ",_,_,_,_,_,_,_,_)"), 3));
							if (Comp_size == 1)
							{
								Last_dim = Num_dim - 1;
								if (Last_dim > First_dim)
								{
									ss << "   output  ";
									ss << " [" << First_dim << ":" << Last_dim << "] " << Local_name << ";" << endl;
									ss << "      reg  ";
									ss << " [" << First_dim << ":" << Last_dim << "] " << Local_name << ";" << endl;
									log2n(Type_size, 1, 1, &Array_index_size);
									Index_upper = Array_index_size - 1;
									ss << "      reg  [" << Index_upper << ":0] " << Local_name << "_i ;" << endl;
								}
							}
						}
					}
				}
			}
			else if (var7 == "userrecord")
			{
				if (Local_type != "bool")
				{
					ss << "   output ";
					if (Current_entry > 0)
					{
						if (HT.findfact("type_def(_," + Local_type + ",_,_,_,_,_,_,_)"))
						{
							Type_number = stoi(returnpar(HT.findandreturn("type_def(_," + Local_type + ",_,_,_,_,_,_,_)"), 1));
							Local_size = stoi(returnpar(HT.findandreturn("type_def(_," + Local_type + ",_,_,_,_,_,_,_)"), 3));
							Upper_bound = Local_size - 1;
							ss << " [" << Upper_bound << ":0] " << Local_name;
							ss << write_verilog_dimmension_component_recursively(Type_number);
							ss << " ; " << endl;
							ss << "   reg  ";
							ss << " [" << Upper_bound << ":0] " << Local_name;
							ss << write_verilog_dimmension_component_recursively(Type_number);
							ss << " ; " << endl;
						}
					}
				}
			}
		}
		else if (var3 == "par_inout")
		{
			if (Local_type != "bool")
			{
				if (HT.findfact("type_def(_," + Local_type + ",_,_,_,_,_,_,_)"))
				{
					Type_size = stoi(returnpar(HT.findandreturn("type_def(_," + Local_type + ",_,_,_,_,_,_,_)"), 3));
					if (Type_size == 1)
					{
						ss << "   inout " << Local_name << " ;" << endl;
						ss << "   reg    " << Local_name << " ;" << endl;
					}
				}
				else if (var7 != "userarray")
				{
					if (var7 != "userrecord")
					{
						if (HT.findfact("type_def(_," + Local_type + ",_,_,_,\"vectorarray_t\",_,_,1)"))
						{
							Type_number = stoi(returnpar(HT.findandreturn("type_def(_," + Local_type + ",_,_,_,\"vectorarray_t\",_,_,1)"), 1));
							ss << "   inout ";
							ss << write_verilog_dimmension_component_recursively(Type_number);
							ss << Local_name << " ;" << endl;
							ss << "      reg ";
							ss << write_verilog_dimmension_component_recursively(Type_number);
							ss << Local_name << " ;" << endl;
						}
						else if (HT.findfact("type_def(_," + Local_type + ",_,_,_,\"vectorarray_t\",_,_,_)"))
						{
							Type_number = stoi(returnpar(HT.findandreturn("type_def(_," + Local_type + ",_,_,_,\"vectorarray_t\",_,_,_)"), 1));
							Numb_of_dim = stoi(returnpar(HT.findandreturn("type_def(_," + Local_type + ",_,_,_,\"vectorarray_t\",_,_,_)"), 8));
							First_comp_type = stoi(returnpar(HT.findandreturn("type_def(_," + Local_type + ",_,_,_,\"vectorarray_t\",_,_,_)"), 9));
							if (First_comp_type <= 10)
							{
								if (First_comp_type > 1)
								{
									if (HT.findfact("data_stmt(" + Module + ",_," + to_string(var5) + "," + to_string(Type_number) + ",_,_)"))
									{
										Replacement_name = stoi(returnpar(HT.findandreturn("data_stmt(" + Module + ",_," + to_string(var5) + "," + to_string(Type_number) + ",_,_)"), 2));
										if (!HT.findfact("mem_port(_,_," + Module + "," + Replacement_name + ",_,_,_,_,_,_,_,_,_)"))
										{
											ss << "   inout ";
											find_child_type(Type_number, &Child_type);
											if (HT.findfact("type_def(" + to_string(Child_type) + ",*)"))
											{
												Child_size = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Child_type) + ",*)"), 3));
												Child_upper = Child_size - 1;
												ss << " [" << Child_upper << ":0] " << Local_name << " ";
												ss << write_verilog_dimmension_component_recursively(Type_number);
												ss << " ; " << endl;
												ss << "   reg ";
												ss << " [" << Child_upper << ":0] " << Local_name << " ";
												ss << write_verilog_dimmension_component_recursively(Type_number);
												ss << " ; " << endl;
												ss << write_verilog_array_index_registers(Module, Local_name, Type_number, Numb_of_dim, 0, 1);
											}
										}
									}
								}
							}
							else if (HT.findfact("type_def(" + to_string(First_comp_type) + ",_,_,_,_,\"vectorarray_t\",_,_,_)"))
							{
								if (HT.findfact("data_stmt(" + Module + ",_," + to_string(var5) + "," + to_string(Type_number) + ",_,_)"))
								{
									Replacement_name = stoi(returnpar(HT.findandreturn("data_stmt(" + Module + ",_," + to_string(var5) + "," + to_string(Type_number) + ",_,_)"), 2));
									if (!HT.findfact("mem_port(_,_," + Module + "," + Replacement_name + ",_,_,_,_,_,_,_,_,_)"))
									{
										ss << "   inout ";
										find_child_type(Type_number, &Child_type);
										if (HT.findfact("type_def(" + to_string(Child_type) + ",*)"))
										{
											Child_size = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Child_type) + ",*)"), 3));
											Child_upper = Child_size - 1;
											ss << " [" << Child_upper << ":0] " << Local_name << " ";
											ss << write_verilog_dimmension_component_recursively(Type_number);
											ss << " ; " << endl;
											ss << "   reg ";
											ss << " [" << Child_upper << ":0] " << Local_name << " ";
											ss << write_verilog_dimmension_component_recursively(Type_number);
											ss << " ; " << endl;
											ss << write_verilog_array_index_registers(Module, Local_name, Type_number, Numb_of_dim, Numb_of_dim, 1);
										}
									}
								}
							}
						}
						else if (HT.findfact("type_def(_," + Local_type + ",_,_,_,_,_,_,_)"))
						{
							Type_kind = stoi(returnpar(HT.findandreturn("type_def(_," + Local_type + ",_,_,_,_,_,_,_)"), 6));
							if (Type_kind != "vectorarray_t")
							{
								ss << "   inout ";
								ss << write_size(Local_size, "std_logic", "verilog", "synergy", 1);
								ss << " " << Local_name << " ; " << endl;
								ss << "   reg    ";
								ss << write_size(Local_size, "std_logic", "verilog", "synergy", 1);
								ss << " " << Local_name << " ; " << endl;
							}
						}
					}
				}
			}
			else if (Local_type == "bool")
			{
				ss << "   inout " << Local_name << " ;" << endl;
				ss << "   reg    " << Local_name << " ;" << endl;
			}
			else if (Local_type == "std_logic")
			{
				ss << "   input ";
				ss << write_size(Local_size, "std_logic", "verilog", "synergy", 1);
				ss << " " << Local_name << " ; " << endl;
				ss << "   reg    ";
				ss << write_size(Local_size, "std_logic", "verilog", "synergy", 1);
				ss << " " << Local_name << " ; " << endl;
			}
			else if (var7 == "standard")
			{
				if (HT.findfact("type_def(_," + Local_type + ",_,_,_,\"vectorarray_t\",_,_,_)"))
				{
					Type_number = stoi(returnpar(HT.findandreturn("type_def(_," + Local_type + ",_,_,_,\"vectorarray_t\",_,_,_)"), 1));
					if (HT.findfact("data_stmt(" + Module + ",_," + to_string(var5) + "," + to_string(Type_number) + ",_,_)"))
					{
						Replacement_name = stoi(returnpar(HT.findandreturn("data_stmt(" + Module + ",_," + to_string(var5) + "," + to_string(Type_number) + ",_,_)"), 2));
						if (HT.findfact("mem_port(_,_," + Module + "," + Replacement_name + ",_,_,_,_,_,_,_,_,_)"))
						{
							ss << "   inout ";
							ss << write_size(Local_size, "std_logic", "verilog", "synergy", 1);
							ss << " " << Local_name << " ; " << endl;
							ss << "   reg    ";
							ss << write_size(Local_size, "std_logic", "verilog", "synergy", 1);
							ss << " " << Local_name << " ; " << endl;
						}
					}
				}
			}
			else if (var7 == "user")
			{
				if (HT.findfact("type_def(_," + Local_type + ",_,_,_,\"vectorarray_t\",_,_,_)"))
				{
					Type_number = stoi(returnpar(HT.findandreturn("type_def(_," + Local_type + ",_,_,_,\"vectorarray_t\",_,_,_)"), 1));
					Numb_of_dim = stoi(returnpar(HT.findandreturn("type_def(_," + Local_type + ",_,_,_,\"vectorarray_t\",_,_,_)"), 8));
					First_comp_type = stoi(returnpar(HT.findandreturn("type_def(_," + Local_type + ",_,_,_,\"vectorarray_t\",_,_,_)"), 9));
					if (First_comp_type <= 10)
					{
						if (HT.findfact("data_stmt(" + Module + ",_," + to_string(var5) + "," + to_string(Type_number) + ",_,_)"))
						{
							Replacement_name = stoi(returnpar(HT.findandreturn("data_stmt(" + Module + ",_," + to_string(var5) + "," + to_string(Type_number) + ",_,_)"), 2));
							if (HT.findfact("mem_port(_,_," + Module + "," + Replacement_name + ",_,_,_,_,_,_,_,_,_)"))
							{
								ss << "   inout ";
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
										ss << "   reg ";
										ss << " [" << Child_upper << ":0] " << Local_name << " ";
										ss << write_verilog_dimmension_component_recursively(Type_number);
										ss << " ; " << endl;
										ss << write_verilog_array_index_registers(Module, Local_name, Type_number, Numb_of_dim, 0, 1);
									}
									else if (Child_size == 1)
									{
										ss << write_verilog_dimmension_component_recursively(Type_number);
										ss << Local_name << " ; " << endl;
										ss << "   reg ";
										ss << write_verilog_dimmension_component_recursively(Type_number);
										ss << Local_name << " ; " << endl;
									}
								}
							}
						}
					}
					else if (HT.findfact("type_def(" + to_string(First_comp_type) + ",_,_,_,_,\"vectorarray_t\",_,_,_)"))
					{
						if (HT.findfact("data_stmt(" + Module + ",_," + to_string(var5) + "," + to_string(Type_number) + ",_,_)"))
						{
							Replacement_name = stoi(returnpar(HT.findandreturn("data_stmt(" + Module + ",_," + to_string(var5) + "," + to_string(Type_number) + ",_,_)"), 2));
							if (HT.findfact("mem_port(_,_," + Module + "," + Replacement_name + ",_,_,_,_,_,_,_,_,_)"))
							{
								ss << "   inout ";
								find_child_type(Type_number, &Child_type);
								if (HT.findfact("type_def(" + to_string(Child_type) + ",*)"))
								{
									Child_size = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Child_type) + ",*)"), 3));
									Child_upper = Child_size - 1;
									ss << " [" << Child_upper << ":0] " << Local_name << " ";
									ss << write_verilog_dimmension_component_recursively(Type_number);
									ss << " ; " << endl;
									ss << "   reg ";
									ss << " [" << Child_upper << ":0] " << Local_name << " ";
									ss << write_verilog_dimmension_component_recursively(Type_number);
									ss << " ; " << endl;
									ss << write_verilog_array_index_registers(Module, Local_name, Type_number, Numb_of_dim, Numb_of_dim, 1);
								}
							}
						}
					}
				}
			}
			else if (var7 == "userarray")
			{
				if (Local_type != "bool")
				{
					if (HT.findfact("type_def(_," + Local_type + ",_,_,_,\"vectorarray_t\",_,_,_)"))
					{
						Type_number = stoi(returnpar(HT.findandreturn("type_def(_," + Local_type + ",_,_,_,\"vectorarray_t\",_,_,_)"), 1));
						Num_dim = stoi(returnpar(HT.findandreturn("type_def(_," + Local_type + ",_,_,_,\"vectorarray_t\",_,_,_)"), 8));
						Comp_type = stoi(returnpar(HT.findandreturn("type_def(_," + Local_type + ",_,_,_,\"vectorarray_t\",_,_,_)"), 9));
						if (HT.findfact("type_def(" + to_string(Comp_type) + ",_,_,_,_,\"vectorarray_t\",_,_,_)"))
						{
							Comp_size = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Comp_type) + ",_,_,_,_,\"vectorarray_t\",_,_,_)"), 3));
							Comp_num_dim = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Comp_type) + ",_,_,_,_,\"vectorarray_t\",_,_,_)"), 8));
							if (Comp_size > 1)
							{
								if (Current_entry > 0)
								{
									find_child_type(Type_number, &Child_type);
									if (HT.findfact("type_def(" + to_string(Child_type) + ",*)"))
									{
										Child_size = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Child_type) + ",*)"), 3));
										Child_upper = Child_size - 1;
										ss << "   inout ";
										ss << " [" << Child_upper << ":0] " << Local_name << " ";
										ss << write_verilog_dimmension_component_recursively(Type_number);
										ss << " ; " << endl;
										ss << "   reg ";
										ss << " [" << Child_upper << ":0] " << Local_name << " ";
										ss << write_verilog_dimmension_component_recursively(Type_number);
										ss << " ; " << endl;
										ss << write_verilog_array_index_registers(Module, Local_name, Type_number, Num_dim, Comp_num_dim, 1);
									}
								}
							}
						}
						else if (HT.findfact("type_def(" + to_string(Comp_type) + ",_,_,_,_,\"record_t\",_,_,_)"))
						{
							Comp_size = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Comp_type) + ",_,_,_,_,\"record_t\",_,_,_)"), 3));
							Comp_num_dim = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Comp_type) + ",_,_,_,_,\"record_t\",_,_,_)"), 8));
							if (Comp_size > 1)
							{
								if (Current_entry > 0)
								{
									find_child_type(Type_number, &Child_type);
									if (HT.findfact("type_def(" + to_string(Child_type) + ",*)"))
									{
										Child_size = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Child_type) + ",*)"), 3));
										Child_upper = Child_size - 1;
										ss << "   inout ";
										ss << " [" << Child_upper << ":0] " << Local_name << " ";
										ss << write_verilog_dimmension_component_recursively(Type_number);
										ss << " ; " << endl;
										ss << "   reg ";
										ss << " [" << Child_upper << ":0] " << Local_name << " ";
										ss << write_verilog_dimmension_component_recursively(Type_number);
										ss << " ; " << endl;
										ss << write_verilog_array_index_registers(Module, Local_name, Type_number, Num_dim, 0, 1) << endl;
									}
								}
							}
						}
						else if (HT.findfact("type_def(" + to_string(Comp_type) + ",_,_,_,_,\"single_t\",_,_,_)"))
						{
							Comp_size = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Comp_type) + ",_,_,_,_,\"single_t\",_,_,_)"), 3));
							Comp_num_dim = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Comp_type) + ",_,_,_,_,\"single_t\",_,_,_)"), 8));
							if (Comp_size > 1)
							{
								if (Current_entry > 0)
								{
									find_child_type(Type_number, &Child_type);
									if (HT.findfact("type_def(" + to_string(Child_type) + ",*)"))
									{
										Child_size = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Child_type) + ",*)"), 3));
										Child_upper = Child_size - 1;
										ss << "   inout ";
										ss << " [" << Child_upper << ":0] " << Local_name << " ";
										ss << write_verilog_dimmension_component_recursively(Type_number);
										ss << " ; " << endl;
										ss << "   reg ";
										ss << " [" << Child_upper << ":0] " << Local_name << " ";
										ss << write_verilog_dimmension_component_recursively(Type_number);
										ss << " ; " << endl;
										ss << write_verilog_array_index_registers(Module, Local_name, Type_number, Num_dim, 0, 1) << endl;
									}
								}
							}
						}
					}
					else if (HT.findfact("type_def(_," + Local_type + ",_,_,_,_,_,_,_)"))
					{
						Type_size = stoi(returnpar(HT.findandreturn("type_def(_," + Local_type + ",_,_,_,_,_,_,_)"), 3));
						First_dim = stoi(returnpar(HT.findandreturn("type_def(_," + Local_type + ",_,_,_,_,_,_,_)"), 7));
						Num_dim = stoi(returnpar(HT.findandreturn("type_def(_," + Local_type + ",_,_,_,_,_,_,_)"), 8));
						Comp_type = stoi(returnpar(HT.findandreturn("type_def(_," + Local_type + ",_,_,_,_,_,_,_)"), 9));
						if (HT.findfact("type_def(" + to_string(Comp_type) + ",_,_,_,_,_,_,_,_)"))
						{
							Comp_size = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Comp_type) + ",_,_,_,_,_,_,_,_)"), 3));
							if (Comp_size == 1)
							{
								Last_dim = Num_dim - 1;
								if (Last_dim > First_dim)
								{
									ss << "   inout  ";
									ss << " [" << First_dim << ":" << Last_dim << "] " << Local_name << ";" << endl;
									ss << "      reg  ";
									ss << " [" << First_dim << ":" << Last_dim << "] " << Local_name << ";" << endl;
									log2n(Type_size, 1, 1, &Array_index_size);
									Index_upper = Array_index_size - 1;
									ss << "      reg  [" << Index_upper << ":0] " << Local_name << "_i ;" << endl;
								}
							}
						}
					}
				}
			}
			else if (var7 == "userrecord")
			{
				if (Local_type != "bool")
				{
					ss << "   inout ";
					if (Current_entry > 0)
					{
						if (HT.findfact("type_def(_," + Local_type + ",_,_,_,_,_,_,_)"))
						{
							Type_number = stoi(returnpar(HT.findandreturn("type_def(_," + Local_type + ",_,_,_,_,_,_,_)"), 1));
							Local_size = stoi(returnpar(HT.findandreturn("type_def(_," + Local_type + ",_,_,_,_,_,_,_)"), 3));
							Upper_bound = Local_size - 1;
							ss << " [" << Upper_bound << ":0] " << Local_name;
							ss << write_verilog_dimmension_component_recursively(Type_number);
							ss << " ; " << endl;
							ss << "   reg  ";
							ss << " [" << Upper_bound << ":0] " << Local_name;
							ss << write_verilog_dimmension_component_recursively(Type_number);
							ss << " ; " << endl;
						}
					}
				}
			}
		}
	}
	return ss.str();
}

bool is_it_the_last_io(string Module_name, string HDL, int Current_entry, int* Last)
{
	int Next_entry;
	Next_entry = Current_entry + 1;
	if (!HT.findfact("local_object(" + Module_name + "," + to_string(Next_entry) + ",*)"))
	{
		*Last = 1;
		return true;
	}
	else if (HT.findfact("local_object(" + Module_name + "," + to_string(Next_entry) + ",*)"))
	{
		*Last = 0;
		return true;
	}
	return false;
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
	int Comp_type, Parent_is_record, Dim_size, Next_index, Comp_num_dim1, Comp_type1, Upper_bound, Size;
	string Type_name, Just_field, Just_parent, Kind, Rec_kind, Kind1;
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
		if (HT.findfact("type_def(" + to_string(Type_number) + ",_,_,_,_,\"vectorarray_t\",_,_,_)"))
		{
			Type_name = returnpar(HT.findandreturn("type_def(" + to_string(Type_number) + ",_,_,_,_,\"vectorarray_t\",_,_,_)"), 2);
			Comp_type = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Type_number) + ",_,_,_,_,\"vectorarray_t\",_,_,_)"), 9));
			if (HT.concat(".", &Just_field, Type_name))
			{
				if (HT.concat(&Just_parent, Type_name, Local_name))
					ss << "   integer " << Just_parent << "_" << Just_field << "_i" << In_index << " ;" << endl;
			}
			else
				ss << "   integer " << Local_name << "_i" << In_index << " ;" << endl;
		}
		else if (HT.findfact("type_def(" + to_string(Type_number) + ",_,_,_,0,_,_,_,_)"))
		{
			Type_name = returnpar(HT.findandreturn("type_def(" + to_string(Type_number) + ",_,_,_,0,_,_,_,_)"), 2);
			Dim_size = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Type_number) + ",_,_,_,0,_,_,_,_)"), 8));
			Comp_type = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Type_number) + ",_,_,_,0,_,_,_,_)"), 9));
			if (HT.findfact("type_def(_,_,_,\"user\",_,\"vectorarray_t\",_,_," + to_string(Type_number) + ")"))
			{
				if (Comp_type > 10)
				{
					Next_index = In_index + 1;
					if (HT.findfact("type_def(" + to_string(Comp_type) + ",*)"))
					{
						Kind = returnpar(HT.findandreturn("type_def(" + to_string(Comp_type) + ",*)"), 6);
						Comp_num_dim1 = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Comp_type) + ",*)"), 8));
						Comp_type1 = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Comp_type) + ",*)"), 9));
						if (Kind != "record_t")
						{
							if (Kind != "single_t")
							{
								if (Comp_type1 != 2 && Comp_type1 != 5 && Comp_type1 != 9 && Comp_type1 != 10)
								{
									if (HT.findfact("type_def(" + to_string(Comp_type1) + ",*)"))
									{
										Upper_bound = Dim_size - 1;
										ss << "   reg  [" << Upper_bound << ":0] " << Local_name << "_regout";
										ss << write_verilog_dimmension_component_recursively(Type_number) << " ; " << endl;
										ss << "   integer " << Local_name << "_i" << In_index << " ;" << endl;
									}
								}
							}
						}
					}
				}
			}
			else if (Comp_type > 10)
			{
				Next_index = In_index + 1;
				if (HT.findfact("type_def(" + to_string(Comp_type) + ",*)"))
				{
					Kind = returnpar(HT.findandreturn("type_def(" + to_string(Comp_type) + ",*)"), 6);
					Comp_num_dim1 = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Comp_type) + ",*)"), 8));
					Comp_type1 = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Comp_type) + ",*)"), 9));
					if (HT.findfact("type_def(" + to_string(Comp_type1) + ",*)"))
					{
						Kind1 = returnpar(HT.findandreturn("type_def(" + to_string(Comp_type1) + ",*)"), 6);
						if (Kind != "record_t")
						{
							if (Kind != "single_t")
							{
								if (Kind1 != "vectorarray_t")
								{
									Upper_bound = Dim_size - 1;
									ss << "   reg  [" << Upper_bound << ":0] " << Local_name << "_regout_" << In_index;
									ss << write_verilog_dimmension_component_recursively(Type_number) << ";" << endl;
									ss << "   integer " << Local_name << "_i" << In_index << " ;" << endl;
									ss << "   reg  [" << Upper_bound << ":0] " << Local_name << "_regout_" << Next_index;
									ss << write_verilog_dimmension_component_recursively(Comp_type) << ";" << endl;
									ss << "   integer " << Local_name << "_i" << Next_index << " ;" << endl;
								}
							}
						}
					}
				}
			}
		}
		else if (HT.findfact("type_def(" + to_string(Type_number) + ",*)"))
		{
			Type_name = returnpar(HT.findandreturn("type_def(" + to_string(Type_number) + ",*)"), 2);
			Parent_is_record = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Type_number) + ",*)"), 5));
			Dim_size = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Type_number) + ",*)"), 8));
			Comp_type = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Type_number) + ",*)"), 9));
			if (HT.findfact("type_def(_,_,_,\"user\",_,\"vectorarray_t\",_,_," + to_string(Type_number) + ")"))
			{
				if (Comp_type > 10)
				{
					Next_index = In_index + 1;
					if (HT.findfact("type_def(" + to_string(Comp_type) + ",_,_,_,_,_,_,_,2)"))
					{
						Kind = returnpar(HT.findandreturn("type_def(" + to_string(Comp_type) + ",_,_,_,_,_,_,_,2)"), 6);
						Comp_num_dim1 = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Comp_type) + ",_,_,_,_,_,_,_,2)"), 8));
						if (Kind != "record_t")
						{
							if (Kind != "vectorarray_t")
							{
								if (HT.findfact("type_def(" + to_string(Parent_is_record) + ",*)"))
								{
									Rec_kind = returnpar(HT.findandreturn("type_def(" + to_string(Parent_is_record) + ",*)"), 6);
									if (Rec_kind != "record_t")
									{
										Size = Dim_size * 2;
										Upper_bound = Size - 1;
										ss << "   reg  [" << Upper_bound << ":0] " << Local_name << "_regout";
										ss << write_verilog_dimmension_component_recursively(Type_number);
										ss << " ; ";
									}
								}
							}
						}
					}
				}
			}
			else if (Comp_type > 10)
			{
				Next_index = In_index + 1;
				if (HT.findfact("type_def(" + to_string(Comp_type) + ",*)"))
				{
					Kind = returnpar(HT.findandreturn("type_def(" + to_string(Comp_type) + ",*)"), 6);
					Comp_num_dim1 = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Comp_type) + ",*)"), 8));
					Comp_type1 = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Comp_type) + ",*)"), 9));
					if (Kind != "record_t")
					{
						if (Kind != "single_t")
						{
							if (HT.findfact("type_def(" + to_string(Comp_type1) + ",*)"))
							{
								if (HT.findfact("type_def(" + to_string(Parent_is_record) + ",*)"))
								{
									Rec_kind = returnpar(HT.findandreturn("type_def(" + to_string(Parent_is_record) + ",*)"), 6);
									if (Rec_kind != "record_t")
									{
										Upper_bound = Dim_size - 1;
										ss << "   reg  [" << Upper_bound << ":0] " << Local_name << "_regout";
										ss << write_verilog_dimmension_component_recursively(Type_number);
										ss << " ; ";
									}
								}
								else if (HT.concat(".", &Just_field, Type_name))
								{
									if (HT.concat(&Just_parent, Type_name, Local_name))
									{
										ss << "   integer " << Just_parent << "_" << Just_field << "_i" << In_index << " ;" << endl;
										ss << write_verilog_array_index_registers(Module_name, Local_name, Comp_type, Comp_num_dim, Comp_num_dim1, Next_index);
									}
								}
								else
								{
									Upper_bound = Dim_size - 1;
									ss << "   reg  [" << Upper_bound << ":0] " << Local_name << "_regout_" << In_index;
									ss << write_verilog_dimmension_component_recursively(Type_number) << ";" << endl;
									ss << "   integer " << Local_name << "_i" << In_index << " ;" << endl;
									ss << write_verilog_array_index_registers(Module_name, Local_name, Comp_type, Comp_num_dim, Comp_num_dim1, Next_index);
								}
							}
						}
					}
				}
			}
		}
		else if (In_index > 1)
		{
			if (HT.findfact("type_def(" + to_string(Type_number) + ",_,_,_,_,_,_,_,_)"))
			{
				Comp_type = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Type_number) + ",_,_,_,_,_,_,_,_)"), 9));
				if (HT.findfact("type_def(" + to_string(Comp_type) + ",_,_,_,_,\"record_t\",_,_,_)"))
					ss << "   integer " << Local_name << "_i" << In_index << " ;" << endl;
			}
		}
	}
	return ss.str();
}

void log2n(int Init_number, int Input_number, int var3, int* Log2)
{
	int Next_number, Next_log;
	if (Input_number >= Init_number)
		*Log2 = var3;
	else
	{
		Next_number = Input_number * 2;
		Next_log = var3 + 1;
		log2n(Init_number, Next_number, Next_log, Log2);
	}
}

string write_interface_tail(string Module_name, string HDL, string Tool)
{
	stringstream ss;
	if (HDL == "vhdl" && Tool == "synergy")
	{
		ss << "       );" << endl;
		ss << "  END " << Module_name << " ;" << endl;
	}
	return ss.str();
}

string write_verilog_ports(string Module_name, int In_entry, string HDL)
{
	stringstream ss;
	GeneralFact* Local;
	int Next_entry;
	if (HDL == "verilog")
	{
		if (HT.findfact("local_object(" + Module_name + "," + to_string(In_entry) + ",*)"))
		{
			Local = makeInstanceOf(HT.findandreturn("local_object(" + Module_name + "," + to_string(In_entry) + ",*)"));
			local_object* ptr = dynamic_cast<local_object*>(Local);
			ss << write_verilog_port(Module_name, *ptr, "verilog");
			Next_entry = In_entry + 1;
			ss << write_verilog_ports(Module_name, Next_entry, "verilog");
		}
	}
	return ss.str();
}

string write_verilog_port(string Module_name, local_object Local, string HDL)
{
	stringstream ss;
	string var3, Local_name;
	GeneralFact* ptr = &Local;
	var3 = returnpar(makeStringOf(ptr), 3);
	Local_name = returnpar(makeStringOf(ptr), 4);//4
	if (HDL == "verilog")
	{
		if (var3 == "par_in" || var3 == "par_out" || var3 == "par_inout")
			ss << "                  " << Local_name << "," << endl;
	}
	return ss.str();
}

string write_sens_list_cus_block(string Module_name, int In_entry)
{
	stringstream ss;
	string Data;
	if (HT.findfact("data_stmt(" + Module_name + ",_," + to_string(In_entry) + ",_,\"par_in\",_)"))
	{
		Data = returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(In_entry) + ",_,\"par_in\",_)"), 2);
		ss << Data;
		ss << write_comma_cond_input(Module_name, In_entry);
		int Next_entry = In_entry + 1;
		ss << write_sens_list_cus_block(Module_name, Next_entry);
	}
	return ss.str();
}

string write_comma_cond_input(string Module_name, int In_entry)
{
	stringstream ss;
	int Next_entry = In_entry + 1;
	if (HT.findfact("data_stmt(" + Module_name + ",_, " + to_string(Next_entry) + ",_,\"par_in\",_)"))
		ss << ", ";
	return ss.str();
}

string write_cus_block_process_io_variables(string Module_name, int Entry, string HDL)
{
	stringstream ss;
	if (HT.findfact("data_stmt(" + Module_name + ",_," + to_string(Entry) + ",_,_,_)") &&
		!HT.findfact("data_stmt(" + Module_name + ",_," + to_string(Entry) + ",_,\"var\",_)") &&
		!HT.findfact("data_stmt(" + Module_name + ",_," + to_string(Entry) + ",_,\"const\",_)"))
	{
		ss << write_cus_block_process_io_variable(Module_name, Entry, HDL);
		int Next_entry = Entry + 1;
		ss << write_cus_block_process_io_variables(Module_name, Next_entry, HDL);
	}
	return ss.str();
}

string write_cus_block_process_io_variable(string Module_name, int Entry, string HDL)
{
	stringstream ss;
	string DName, Kind, Name1, Name2, Data_name;
	int Type_entry, Comp_type, Comp_size, Size, Last_dim, First_dim, Num_dim;
	if (HDL == "vhdl")
	{
		if (HT.findfact("data_stmt(" + Module_name + ",1," + to_string(Entry) + ",_,_,_)"))
		{
			DName = returnpar(HT.findandreturn("data_stmt(" + Module_name + ",1," + to_string(Entry) + ",_,_,_)"), 2);
			Type_entry = stoi(returnpar(HT.findandreturn("data_stmt(" + Module_name + ",1," + to_string(Entry) + ",_,_,_)"), 4));
			Kind = returnpar(HT.findandreturn("data_stmt(" + Module_name + ",1," + to_string(Entry) + ",_,_,_)"), 5);
			if (it_is_io_parameter(Kind))
				ss << "      VARIABLE " << Module_name << "_" << DName << "_var : std_logic ;" << endl;
		}
		if (HT.findfact("data_stmt(" + Module_name + ",_," + to_string(Entry) + ",_,_,_)"))
		{
			DName = returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Entry) + ",_,_,_)"), 2);
			Type_entry = stoi(returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Entry) + ",_,_,_)"), 4));
			Kind = returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Entry) + ",_,_,_)"), 5);
			if (it_is_io_parameter(Kind))
			{
				if (parent_type_is_integer(Type_entry, 0))
				{
					ss << "      VARIABLE " << Module_name << "_" << DName << "_var : ";
					ss << write_cus_func_param_type(Module_name, "body", Type_entry, ";") << endl;
				}
				else
				{
					ss << "      VARIABLE " << Module_name << "_" << DName << "_var : ";
					ss << write_cus_func_param_type(Module_name, "body", Type_entry, ";") << endl;
				}
			}
		}
	}
	else if (HDL == "verilog")
	{
		if (HT.findfact("data_stmt(" + Module_name + ",_," + to_string(Entry) + ",_,_,_)"))
		{
			DName = returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Entry) + ",_,_,_)"), 2);
			Type_entry = stoi(returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Entry) + ",_,_,_)"), 4));
			Kind = returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Entry) + ",_,_,_)"), 5);
			if (HT.findfact("type_def(" + to_string(Type_entry) + ",_,_,_,_,_,0,0,0)"))
			{
				Size = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Type_entry) + ",_,_,_,_,_,0,0,0)"), 4));
				if (Size == 1)
				{
					ss << "      reg ";
					HT.concat(Module_name, "_", &Name1);
					HT.concat(Name1, DName, &Name2);
					HT.concat(Name2, "_var", &Data_name);
					ss << Data_name << ";" << endl;
				}
				else if (Size > 1)
				{
					ss << "      reg ";
					HT.concat(Module_name, "_", &Name1);
					HT.concat(Name1, DName, &Name2);
					HT.concat(Name2, "_var", &Data_name);
					Last_dim = Size - 1;
					ss << " [" << Last_dim << ":" << "0" << "] " << Data_name << ";" << endl;
				}
			}
			else if (HT.findfact("type_def(" + to_string(Type_entry) + ",*)"))
			{
				First_dim = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Type_entry) + ",*)"), 7));
				Num_dim = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Type_entry) + ",*)"), 8));
				Comp_type = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Type_entry) + ",*)"), 9));
				if (HT.findfact("type_def(" + to_string(Comp_type) + ",*)"))
				{
					Comp_size = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Comp_type) + ",*)"), 3));
					if (it_is_io_parameter(Kind))
					{
						if (Comp_size > 1)
						{
							ss << "      reg ";
							HT.concat(Module_name, "_", &Name1);
							HT.concat(Name1, DName, &Name2);
							HT.concat(Name2, "_var", &Data_name);
							ss << print_verilog_array_decl(Type_entry, Data_name, ";") << endl;
						}
					}
					else if (Comp_size == 1)
					{
						ss << "      reg ";
						HT.concat(Module_name, "_", &Name1);
						HT.concat(Name1, DName, &Name2);
						HT.concat(Name2, "_var", &Data_name);
						Last_dim = Num_dim - 1;
						if (Last_dim > First_dim)
							ss << " [" << First_dim << ":" << Last_dim << "] " << Data_name << ";" << endl;
					}
				}
			}
		}
	}
	return ss.str();
}

string write_cus_block_process_input_var_assignments(string Module_name, int Entry, string WS, int* Last_entry)
{
	stringstream ss;
	string DName;
	if (!HT.findfact("data_stmt(" + Module_name + ",_," + to_string(Entry) + ",_,_,_)"))
		*Last_entry = Entry;
	else if (HT.findfact("data_stmt(" + Module_name + ",_," + to_string(Entry) + ",_,\"var\",_)"))
		*Last_entry = Entry;
	else if (HT.findfact("data_stmt(" + Module_name + ",_," + to_string(Entry) + ",_,\"const\",_)"))
		*Last_entry = Entry;
	else if (HT.findfact("data_stmt(" + Module_name + ",_," + to_string(Entry) + ",_,\"par_out\",_)"))
		*Last_entry = Entry;
	else if (HT.findfact("data_stmt(" + Module_name + ",_," + to_string(Entry) + ",_,\"par_inout\",_)"))
		*Last_entry = Entry;
	else if (HT.findfact("data_stmt(" + Module_name + ",_," + to_string(Entry) + ",_,\"par_in\",_)"))
	{
		DName = returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Entry) + ",_,\"par_in\",_)"), 2);
		ss << WS << Module_name << "_" << DName << "_var := " << DName << ";" << endl;
		int Next_entry = Entry + 1;
		ss << write_cus_block_process_input_var_assignments(Module_name, Next_entry, WS, Last_entry);
	}
	return ss.str();
}

string write_block_call(string Module_name, int int1, string WS)
{
	stringstream ss;
	if (int1 == 2)
	{
		ss << WS << Module_name << "(";
		ss << write_all_io_list_cus_block_with_var_suffix(Module_name, 1);
		ss << ");";
	}
	return ss.str();
}

string write_all_io_list_cus_block_with_var_suffix(string Module_name, int Entry)
{
	stringstream ss;
	string Data;
	int Next_entry;
	if (!HT.findfact("data_stmt(" + Module_name + ",_," + to_string(Entry) + ",_,\"par_in\",_)") &&
		!HT.findfact("data_stmt(" + Module_name + ",_," + to_string(Entry) + ",_,\"par_out\",_)") &&
		!HT.findfact("data_stmt(" + Module_name + ",_," + to_string(Entry) + ",_,\"par_inout\",_)"))
		return ss.str();
	else if (io_exists(Module_name, Entry, &Data))
	{
		ss << Module_name << "_" << Data << "_var";
		ss << write_comma_cond_all(Module_name, Entry, "general");
		Next_entry = Entry + 1;
		ss << write_all_io_list_cus_block_with_var_suffix(Module_name, Next_entry);
	}
	return ss.str();
}

bool io_exists(string Module_name, int Entry, string* Data)
{
	if (HT.findfact("data_stmt(" + Module_name + ",_," + to_string(Entry) + ",_,\"par_in\",_)"))
	{
		*Data = returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Entry) + ",_,\"par_in\",_)"), 2);
		return true;
	}
	if (HT.findfact("data_stmt(" + Module_name + ",_," + to_string(Entry) + ",_,\"par_out\",_)"))
	{
		*Data = returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Entry) + ",_,\"par_out\",_)"), 2);
		return true;
	}
	if (HT.findfact("data_stmt(" + Module_name + ",_," + to_string(Entry) + ",_,\"par_inout\",_)"))
	{
		*Data = returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Entry) + ",_,\"par_inout\",_)"), 2);
		return true;
	}
	return false;
}

string write_comma_cond_all(string Module_name, int In_entry, string str)
{
	stringstream ss;
	int Next_entry;
	Next_entry = In_entry + 1;
	if (!HT.findfact("data_stmt(" + Module_name + ",_," + to_string(Next_entry) + ",_,\"par_in\",_)") &&
		!HT.findfact("data_stmt(" + Module_name + ",_," + to_string(Next_entry) + ",_,\"par_out\",_)") &&
		!HT.findfact("data_stmt(" + Module_name + ",_," + to_string(Next_entry) + ",_,\"par_inout\",_)") &&
		str == "general")
	{
		return ss.str();
	}
	else if (!HT.findfact("data_stmt(" + Module_name + ",_," + to_string(Next_entry) + ",_,\"par_in\",_)") &&
	!HT.findfact("data_stmt(" + Module_name + ",_," + to_string(Next_entry) + ",_,\"par_inout\",_)") &&
	str == "wrapper_call")
	{
		return ss.str();
	}
	else if (HT.findfact("data_stmt(" + Module_name + ",_," + to_string(Next_entry) + ",_,\"par_in\",_)") ||
	HT.findfact("data_stmt(" + Module_name + ",_," + to_string(Next_entry) + ",_,\"par_out\",_)") ||
	HT.findfact("data_stmt(" + Module_name + ",_," + to_string(Next_entry) + ",_,\"par_inout\",_)"))
	{
		ss << ", ";
	}
	return ss.str();
}

string write_cus_block_process_output_var_assignments(string Module_name, int Entry, string WS)
{
	stringstream ss;
	int Next_entry;
	if (!HT.findfact("data_stmt(" + Module_name + ",_," + to_string(Entry) + ",_,\"var\",_)") ||
		!HT.findfact("data_stmt(" + Module_name + ",_," + to_string(Entry) + ",_,\"const\",_)"))
	{
		if (HT.findfact("data_stmt(" + Module_name + ",_," + to_string(Entry) + ",_,_,_)"))
		{
			ss << write_cus_block_process_output_var_assignment(Module_name, Entry, WS);
			Next_entry = Entry + 1;
			ss << write_cus_block_process_output_var_assignments(Module_name, Next_entry, WS);
		}
	}
	return ss.str();
}

string write_cus_block_process_output_var_assignment(string Module_name, int Entry, string WS)
{
	stringstream ss;
	string DName, Kind;
	if (!HT.findfact("data_stmt(" + Module_name + ",_," + to_string(Entry) + ",_,\"var\",_)") ||
		!HT.findfact("data_stmt(" + Module_name + ",_," + to_string(Entry) + ",_,\"const\",_)") ||
		!HT.findfact("data_stmt(" + Module_name + ",_," + to_string(Entry) + ",_,\"par_in\",_)"))
	{
		if (HT.findfact("data_stmt(" + Module_name + ",_," + to_string(Entry) + ",_,_,_)"))
		{
			DName = returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Entry) + ",_,_,_)"), 2);
			Kind = returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Entry) + ",_,_,_)"), 5);
			if (is_output(Kind))
			{
				ss << WS;
				ss << print_vhdl_par_out_name_cond(Module_name, DName);
				ss << " <= " << Module_name << "_" << DName << "_var;" << endl;
			}
		}
	}
	return ss.str();
}

bool is_output(string str)
{
	return str == "par_out" || str == "par_inout";
}

/* This is to write in Verilog the custom block call in the module body.
   Custom functions are treated as ADA procedures with no auxiliary variables. */
string write_custom_call_no_state(string Called_module_name, string HDL)
{
	stringstream ss;
	string WS, Module_name;
	int Called_module_entry, Call_entry, Res_entry;
	if (HDL == "verilog")
	{
		if (HT.findfact("hdl_style(\"verilog\")"))
		{
			if (HT.findfact("hierarchy_part(_," + Called_module_name + ",_,\"libpart\",_,_,_)"))
			{
				Called_module_entry = stoi(returnpar(HT.findandreturn("hierarchy_part(_," + Called_module_name + ",_,\"libpart\",_,_,_)"), 1));
				if (HT.findfact("call_stmt(_,_," + to_string(Called_module_entry) + ",_)"))
				{
					Call_entry = stoi(returnpar(HT.findandreturn("call_stmt(_,_," + to_string(Called_module_entry) + ",_)"), 2));
					if (HT.findfact("prog_stmt(_,_,_,109,0," + to_string(Call_entry) + ",0,_)"))
					{
						if (custom_block(Called_module_name))
						{
							WS = "      ";
							ss << WS;
							ss << " //------ this is a call to custom procedure block : " << Called_module_name << " -----" << endl;
							ss << write_block_call_real_ios(Called_module_name, 2, WS) << endl;
						}
					}
					else if (HT.findfact("prog_stmt(_,_,_,109,0," + to_string(Call_entry) + ",_,_)"))
					{
						Module_name = returnpar(HT.findandreturn("prog_stmt(_,_,_,109,0," + to_string(Call_entry) + ",_,_)"), 1);
						Res_entry = stoi(returnpar(HT.findandreturn("prog_stmt(_,_,_,109,0," + to_string(Call_entry) + ",_,_)"), 7));
						if (Res_entry > 0)
						{
							if (HT.findfact("data_stmt(" + Module_name + ",_," + to_string(Res_entry) + ",_,_,_)"))
							{
								if (custom_block(Called_module_name))
								{
									WS = "      ";
									ss << WS;
									ss << " //------ this is a call to custom function block : " << Called_module_name << " -----" << endl;
									ss << write_block_call_real_ios(Called_module_name, 2, WS) << endl;
								}
							}
						}
					}
				}
			}
		}
	}
	return ss.str();
}

string write_block_call_real_ios(string Module_name, int int1, string WS)
{
	stringstream ss;
	if (int1 == 2)
	{
		ss << WS << Module_name << "_task(";
		ss << write_all_io_list_cus_block_real_ios(Module_name, 1);
		ss << ");";
	}

	return ss.str();
}

string write_all_io_list_cus_block_real_ios(string Module_name, int Entry)
{
	stringstream ss;
	string Data;
	int Next_entry;
	if (!HT.findfact("data_stmt(" + Module_name + ",_," + to_string(Entry) + ",_,\"var\",_)") &&
		!HT.findfact("data_stmt(" + Module_name + ",_," + to_string(Entry) + ",_,\"const\",_)") &&
		!HT.findfact("data_stmt(" + Module_name + ",_," + to_string(Entry) + ",_,\"par_in\",_)"))
	{
		return ss.str();
	}
	else if (io_exists(Module_name, Entry, &Data))
	{
		ss << Data;
		ss << write_comma_cond_all(Module_name, Entry, "general");
		Next_entry = Entry + 1;
		ss << write_all_io_list_cus_block_real_ios(Module_name, Next_entry);
	}

	return ss.str();
}

void consult_memory_ports(string Memory_file_name)
{
	ifstream File;
	File.open(Memory_file_name, fstream::in);
	if (File.is_open())
	{
		HT.consult(Memory_file_name, "options_dbase");
	}
}

void consult_cus_blocks(string Cus_blocks_file_name)
{
	ifstream File;
	File.open(Cus_blocks_file_name, fstream::in);
	if (File.is_open())
	{
		HT.consult(Cus_blocks_file_name, "options_dbase");
	}
}

void remove_modules_instances()
{
	HT.retractall("op_instance(*)");
	HT.retractall("last_op_instance(*)");
	HT.retractall("op_in_a_state(*)");
	HT.retractall("last_op_in_a_state(*)");
	HT.retractall("signal_instance(*)");
	HT.retractall("last_signal_instance(*)");
	HT.retractall("output_instance(*)");
	HT.retractall("last_output_instance(*)");
	HT.retractall("operator_instance_stats(*)");
	HT.retractall("cf_previous_op(*)");
	HT.retractall("cf_previous_state(*)");
}

void eliminating_garbage_from_memory(string Module)
{
	HT.retractall("state(*)", "hdlmaker_dbase");
	HT.retractall("local_object(" + Module + ",*)", "hdlmaker_dbase");
	HT.retractall("state_node(" + Module + ",*)", "hdlmaker_dbase");
	HT.retractall("special_op(" + Module + ",*)", "hdlmaker_dbase");
	HT.retractall("op_guards(" + Module + ",*)", "hdlmaker_dbase");
	HT.retractall("var_guards(" + Module + ",*)", "hdlmaker_dbase");
	HT.retractall("guard_pair(" + Module + ",*)", "hdlmaker_dbase");
	HT.retractall("guard_cond(" + Module + ",*)", "hdlmaker_dbase");
	HT.retractall("cessor(" + Module + ",*)", "hdlmaker_dbase");
	HT.retractall("cessor_kind(" + Module + ",*)", "hdlmaker_dbase");
	HT.retractall("predecessors(" + Module + ",*)", "hdlmaker_dbase");
	HT.retractall("rescheduled(" + Module + ",*)", "hdlmaker_dbase");
	HT.retractall("last_rescheduled(" + Module + ",*)", "hdlmaker_dbase");
	HT.retractall("cf_previous_op(" + Module + ",*)", "hdlmaker_dbase");
	HT.retractall("op_belongs_to_state(" + Module + ",*)", "hdlmaker_dbase");
	//----------as it was from here and to the end
	HT.retractall("last_reentrant_triangle(*)", "hdlmaker_dbase");
	HT.retractall("last_schedule_state(*)", "hdlmaker_dbase");
	HT.retractall("linear_incomplete_node(*)", "hdlmaker_dbase");
	HT.retractall("operator_instances(*)", "hdlmaker_dbase");
	HT.retractall("operation_order(*)", "hdlmaker_dbase");
	HT.retractall("totalmax_call_order(*)", "hdlmaker_dbase");
	HT.retractall("module_local_list(*)", "hdlmaker_dbase");
	HT.retractall("module_local_list_parcs(*)", "hdlmaker_dbase");
	HT.retractall("total_local_entry(*)", "hdlmaker_dbase");
	HT.retractall("global_nils(*)", "hdlmaker_dbase");
	HT.retractall("last_operation_order(*)", "options_dbase");
	HT.assertz("global_nils(*)", "hdlmaker_dbase");
}

void read_last_state(int* Last_state)
{
	if (!HT.findfact("module_last_state(*)"))
		*Last_state = 0;
	else
		*Last_state = stoi(returnpar(HT.findandreturn("module_last_state(*)"), 1));
}

void read_local_list(vector<local_object>* Local_list)
{
	if (HT.findfact("module_local_list(*)"))
		*Local_list = return_vec_lo(makeInstanceOf(HT.findandreturn("module_last_state(*)")));
}

void consult_permanent_conditionally(string Module)
{
	string Permanent_DBA;
	HT.concat(Module, "_permanent.DBA", &Permanent_DBA);

	ifstream File;
	File.open(Permanent_DBA, fstream::in);
	if (File.is_open())
	{
		HT.consult(Permanent_DBA, "options_dbase");
	}
}

void write_unoptimised_hdl(string Module_name, int int1, int int2, string HDL, string Tool, int Last_st)
{
	if (int1 == 1 && int2 == 1)
	{
		string Schedule, Hdlform, Tool, Fname;
		int Last_state_plus_one;
		if (HDL == "vhdl")
		{
			if (HT.findfact("cac_mode(*)"))
			{
				Schedule = "specials";
				Hdlform = "vhdl";
				Tool = "synergy";
				HT.retractall("current_hdl_style(*)");
				HT.assertz("current_hdl_style(\"vhdl\")");
				HT.retractall("hdl_style(*)");
				HT.assertz("hdl_style(\"vhdl\")");
				HT.retractall("added_aux_call_signals(" + Module_name + ",*)");
				HT.concat(Module_name, ".vhd", &Fname);

				fstream     File(Fname, ios::out | ios::in | ios::trunc);
				if (File.is_open())
				{
					File << write_title(Module_name, Hdlform, Tool) << endl;
					File << write_ieee_packages("vhdl", "synergy") << endl;
					File << write_global_package(Module_name, Hdlform, Tool);
					File << write_interface(Module_name, "specials", 1, Hdlform, Tool) << endl;
					HT.retractall("added_aux_call_ios1(" + Module_name + ",*)");
					File << write_content_header(Module_name, Hdlform, Tool) << endl;
					Last_state_plus_one = Last_st + 1;
					File << print_states_type(Last_state_plus_one) << endl;
					File << write_locals(Module_name, 1, Hdlform, Tool);
					File << write_standard_call_signals(Schedule, Module_name, 1);
					File << write_dp_signal_declarations();
					File << write_content_body_header(Module_name, Hdlform, Tool, Schedule) << endl;
					File << write_fsm(Module_name, 1, 1, Hdlform, Tool);
				}
			}
		}
	}
}

string write_interface(string Module_name, string Schedule, int var3, string HDL, string Tool)
{
	stringstream ss;
	string Global_package, CustomFile;
	if (Tool == "synergy")
	{
		if (HDL == "vhdl")
		{
			ss << endl << endl;
			if (HT.findfact("hierarchy_part(1,_,0,\"libpart\",_,_,_)"))
			{
				Global_package = returnpar(HT.findandreturn("hierarchy_part(1,_,0,\"libpart\",_,_,_)"), 2);
				HT.concat(Global_package, ".cus", &CustomFile);
				if (!HT.findfact("call_stmt(" + Module_name + ",_,_,_)"))
				{
					ss << write_ieee_packages("vhdl", "synergy");
					ss << "  LIBRARY WORK; " << endl;
					ss << "  USE WORK." << Global_package << ".ALL; " << endl << endl;
					ss << "  ENTITY " << Module_name << " IS" << endl;
					ss << write_interface_header("vhdl", "synergy");
					ss << "        clock, reset, start, results_read : IN std_logic;" << endl;
					HT.retractall("added_aux_call_ios(" + Module_name + ",_)");
					ss << write_standard_call_ports(Module_name, Schedule, 1);
					ss << write_io_ports(Module_name, 1, "vhdl", "synergy", "regular");
					ss << "        done, busy : OUT std_logic" << endl;
					ss << write_interface_tail(Module_name, "vhdl", "synergy");
				}
				else
				{
					ifstream File;
					File.open(CustomFile, fstream::in);
					if (!File.is_open())
					{
						if (HT.findfact("call_stmt(" + Module_name + ",_,_,_)"))
						{
							ss << write_ieee_packages("vhdl", "synergy");
							ss << "  LIBRARY WORK; " << endl;
							ss << "  USE WORK." << Global_package << ".ALL; " << endl << endl;
							ss << "  ENTITY " << Module_name << " IS" << endl;
							ss << write_interface_header("vhdl", "synergy");
							ss << "        clock, reset, start, results_read : IN std_logic;" << endl;
							HT.retractall("added_aux_call_ios(" + Module_name + ",_)");
							ss << write_standard_call_ports(Module_name, Schedule, 1);
							ss << write_io_ports(Module_name, 1, "vhdl", "synergy", "regular");
							ss << "        done, busy : OUT std_logic" << endl;
							ss << write_interface_tail(Module_name, "vhdl", "synergy");
						}
					}
					else if (HT.findfact("call_stmt(" + Module_name + ",_,_,_)"))
					{
						ss << write_ieee_packages("vhdl", "synergy");
						ss << "  LIBRARY WORK; " << endl;
						ss << "  USE WORK." << Global_package << ".ALL; " << endl << endl;
						ss << "  ENTITY " << Module_name << " IS" << endl;
						ss << write_interface_header("vhdl", "synergy");
						ss << "        clock, reset, start, results_read : IN std_logic;" << endl;
						HT.retractall("added_aux_call_ios(" + Module_name + ",_)");
						ss << write_standard_call_ports(Module_name, Schedule, 1);
						ss << write_io_ports(Module_name, 1, "vhdl", "synergy", "regular");
						ss << "        done, busy : OUT std_logic" << endl;
						ss << write_interface_tail(Module_name, "vhdl", "synergy");
					}
				}
			}
		}
		else if (HDL == "verilog")
		{
			ss << "  module " << Module_name << " (" << endl;
			ss << "             clock, reset, start, results_read," << endl;
			ss << write_verilog_ports(Module_name, 1, "verilog");
			HT.retractall("added_aux_call_ios(" + Module_name + ",*)");
			ss << write_standard_call_ports(Module_name, Schedule, 1);
			ss << "             done, busy ); " << endl << endl;
			ss << "   /*---- now list of module I/O types ----*/" << endl;
			ss << "   input clock, reset, start, results_read;" << endl;
			ss << "   output done, busy;" << endl;
			ss << "   reg    done, busy;" << endl;
			HT.retractall("added_aux_call_ios(" + Module_name + ",*)"); // why retracting all second time?
			ss << write_standard_verilog_call_decls(Module_name, 1);
			ss << write_verilog_call_ios(Module_name, 1);
			ss << write_io_ports(Module_name, 1, "verilog", "synergy", "regular") << endl;
			ss << "   /*---- now list of module internal signals ----*/" << endl;
		}
	}
	else if (Tool == "gnu" && HDL == "c")
	{
		ss << "  void main() { " << endl;
		ss << "   /*---- now list of module local declarations ----*/" << endl;
	}
	return ss.str();
}

string write_standard_call_ports(string Module, string Schedule, int Call_entry)
{
	stringstream ss;
	int Called_module_entry, Next_entry;
	if (HT.findfact("call_stmt(" + Module + "," + to_string(Call_entry) + ",_,_)"))
	{
		Called_module_entry = stoi(returnpar(HT.findandreturn("call_stmt(" + Module + "," + to_string(Call_entry) + ",_,_)"), 3));
		ss << write_standard_ports_for_called_module(Module, Schedule, Call_entry, Called_module_entry);
		Next_entry = Call_entry + 1;
		ss << write_standard_call_ports(Module, Schedule, Next_entry);
	}
	return ss.str();
}

string write_standard_ports_for_called_module(string Module, string Schedule, int Call_entry, int Called_module_entry)
{
	stringstream ss;
	string Called_module_name, Module_name;
	int Order, Orderout, Max_order, Max_order1;
	if (HT.findfact("hierarchy_part(" + to_string(Called_module_entry) + ",_,_,_,_,_,_)"))
	{
		Called_module_name = returnpar(HT.findandreturn("hierarchy_part(" + to_string(Called_module_entry) + ",_,_,_,_,_,_)"), 2);
		if (custom_block(Called_module_name))
			return ss.str();
	}
	else if (HT.findfact("added_aux_call_ios(" + Module + "," + to_string(Called_module_entry) + ")"))
	{
		return ss.str();
	}
	else if (HT.findfact("hdl_style(\"vhdl\")"))
	{
		if (HT.findfact("call_stmt(" + Module + "," + to_string(Call_entry) + "," + to_string(Called_module_entry) + ",_)"))
		{
			if (!HT.findfact("added_aux_call_ios(" + Module + "," + to_string(Called_module_entry) + ")"))
			{
				if (HT.findfact("hierarchy_part(" + to_string(Called_module_entry) + "," + Called_module_name + ",*)"))
				{
					if (!custom_block(Called_module_name))
					{
						if (HT.findfact("totalmax_call_order(" + Module + ",\"parcsif\", 1)"))
						{
							if (!HT.findfact("max_parallel_call_order(" + Module + ",\"parcsif\"," + to_string(Called_module_entry) + ",_)"))
							{
								if (HT.findfact("max_op_order(" + Module + ",\"parcsif\",1)"))
								{
									ss << "        " << Called_module_name << "_results_read :  OUT std_logic;" << endl;
									ss << "        " << Called_module_name << "_start :  OUT std_logic;" << endl;
									ss << "        " << Called_module_name << "_done :  IN std_logic;" << endl;
									ss << "        " << Called_module_name << "_busy :  IN std_logic;" << endl;
									HT.assertz("added_aux_call_ios(" + Module + "," + to_string(Called_module_entry) + ")");
								}
							}
							else if (HT.findfact("max_parallel_call_order(" + Module + ",\"parcsif\"," + to_string(Called_module_entry) + ",1)"))
							{
								if (HT.findfact("max_op_order(" + Module + ",\"parcsif\",1)"))
								{
									ss << "        " << Called_module_name << "_results_read :  OUT std_logic;" << endl;
									ss << "        " << Called_module_name << "_start :  OUT std_logic;" << endl;
									ss << "        " << Called_module_name << "_done :  IN std_logic;" << endl;
									ss << "        " << Called_module_name << "_busy :  IN std_logic;" << endl;
									HT.assertz("added_aux_call_ios(" + Module + "," + to_string(Called_module_entry) + ")");
								}
							}
						}
						else if (!HT.findfact("totalmax_call_order(" + Module + ",\"parcsif\",*)"))
						{
							if (HT.findfact("max_parallel_call_order(" + Module + ",\"parcsif\"," + to_string(Called_module_entry) + ",1)"))
							{
								ss << "        " << Called_module_name << "_results_read :  OUT std_logic;" << endl;
								ss << "        " << Called_module_name << "_start :  OUT std_logic;" << endl;
								ss << "        " << Called_module_name << "_done :  IN std_logic;" << endl;
								ss << "        " << Called_module_name << "_busy :  IN std_logic;" << endl;
								HT.assertz("added_aux_call_ios(" + Module + "," + to_string(Called_module_entry) + ")");
							}
							else if (!HT.findfact("max_parallel_call_order(" + Module + ",\"parcsif\"," + to_string(Called_module_entry) + ",*)"))
							{
								if (HT.findfact("max_op_order(_,\"parcsif\",_)"))
								{
									Module_name = returnpar(HT.findandreturn("max_op_order(_,\"parcsif\",_)"), 1);
									Order = stoi(returnpar(HT.findandreturn("max_op_order(_,\"parcsif\",_)"), 3));
									find_correct_max_call_order(Module_name, Called_module_entry, Order, &Orderout);
									if (Orderout == 1)
									{
										ss << "        " << Called_module_name << "_results_read :  OUT std_logic;" << endl;
										ss << "        " << Called_module_name << "_start :  OUT std_logic;" << endl;
										ss << "        " << Called_module_name << "_done :  IN std_logic;" << endl;
										ss << "        " << Called_module_name << "_busy :  IN std_logic;" << endl;
										HT.assertz("added_aux_call_ios(" + Module + "," + to_string(Called_module_entry) + ")");
									}
									else if (Orderout > 1)
									{
										ss << "        ";
										ss << write_polymorfic_IO_exression(Module, "parcs", 0, Called_module_name, "results_read", 1, Orderout, "        ", "", " : OUT std_logic;", 1, 0) << "        ";
										ss << write_polymorfic_IO_exression(Module, "parcs", 0, Called_module_name, "start", 1, Orderout, "        ", "", " : OUT std_logic;", 1, 0) << "        ";
										ss << write_polymorfic_IO_exression(Module, "parcs", 0, Called_module_name, "done", 1, Orderout, "        ", "", " : IN std_logic;", 1, 0) << "        ";
										ss << write_polymorfic_IO_exression(Module, "parcs", 0, Called_module_name, "busy", 1, Orderout, "        ", "", " : IN std_logic;", 1, 0);
										HT.assertz("added_aux_call_ios(" + Module + "," + to_string(Called_module_entry) + ")");
									}
								}
							}
						}
					}
				}
			}
			else if (!HT.findfact("totalmax_call_order(" + Module + "," + Schedule + ",_)"))
			{
				if (!HT.findfact("max_parallel_call_order(" + Module + "," + Schedule + "," + to_string(Called_module_entry) + ",_)"))
				{
					if (!HT.findfact("max_op_order(" + Module + "," + Schedule + ",_)"))
					{
						if (!HT.findfact("added_aux_call_ios(" + Module + "," + Schedule + ")"))
						{
							if (HT.findfact("hierarchy_part(" + to_string(Called_module_entry) + "," + Called_module_name + ",*)"))
							{
								if (!custom_block(Called_module_name))
								{
									ss << "        " << Called_module_name << "_results_read :  OUT std_logic;" << endl;
									ss << "        " << Called_module_name << "_start :  OUT std_logic;" << endl;
									ss << "        " << Called_module_name << "_done :  IN std_logic;" << endl;
									ss << "        " << Called_module_name << "_busy :  IN std_logic;" << endl;
									HT.assertz("added_aux_call_ios(" + Module + "," + to_string(Called_module_entry) + ")");
								}
							}
						}
					}
				}
			}
		}
		else if (parcs_or_parcsif(Schedule))
		{
			if (HT.findfact("totalmax_call_order(" + Module + ",\"parcsif\",_)"))
			{
				Max_order = stoi(returnpar(HT.findandreturn("totalmax_call_order(" + Module + ",\"parcsif\",_)"), 3));
				if (!HT.findfact("max_parallel_call_order(" + Module + "," + Schedule + "," + to_string(Called_module_entry) + ",_)"))
				{
					if (HT.findfact("call_stmt(" + Module + "," + to_string(Call_entry) + "," + to_string(Called_module_entry) + ",_)"))
					{
						if (!HT.findfact("added_aux_call_ios(" + Module + "," + to_string(Called_module_entry) + ")"))
						{
							if (!HT.findfact("max_op_order(" + Module + ",\"parcsif\",_)"))
							{
								if (HT.findfact("hierarchy_part(" + to_string(Called_module_entry) + "," + Called_module_name + ",*)"))
								{
									if (!custom_block(Called_module_name))
									{
										ss << "        " << Called_module_name << "_results_read :  OUT std_logic;" << endl;
										ss << "        " << Called_module_name << "_start :  OUT std_logic;" << endl;
										ss << "        " << Called_module_name << "_done :  IN std_logic;" << endl;
										ss << "        " << Called_module_name << "_busy :  IN std_logic;" << endl;
										HT.assertz("added_aux_call_ios( " + Module + "," + to_string(Called_module_entry) + ")");
									}
								}
							}
						}
					}
				}
				else if (Max_order == 1)
				{
					if (HT.findfact("max_parallel_call_order(" + Module + "," + Schedule + "," + to_string(Called_module_entry) + "," + to_string(Max_order) + ")"))
					{
						if (HT.findfact("call_stmt(" + Module + "," + to_string(Call_entry) + "," + to_string(Called_module_entry) + ",_)"))
						{
							if (!HT.findfact("added_aux_call_ios(" + Module + "," + to_string(Called_module_entry) + ")"))
							{
								if (HT.findfact("hierarchy_part(" + to_string(Called_module_entry) + "," + Called_module_name + ",*)"))
								{
									if (!custom_block(Called_module_name))
									{
										ss << "        " << Called_module_name << "_results_read :  OUT std_logic;" << endl;
										ss << "        " << Called_module_name << "_start :  OUT std_logic;" << endl;
										ss << "        " << Called_module_name << "_done :  IN std_logic;" << endl;
										ss << "        " << Called_module_name << "_busy :  IN std_logic;" << endl;
										HT.assertz("added_aux_call_ios( " + Module + "," + to_string(Called_module_entry) + ")");
									}
								}
							}
						}
					}
				}
				else if (Max_order > 1)
				{
					find_correct_max_call_order(Module, Called_module_entry, Max_order, &Orderout);
					if (Orderout == 1)
					{
						if (HT.findfact("call_stmt(" + Module + "," + to_string(Call_entry) + "," + to_string(Called_module_entry) + ",_)"))
						{
							if (!HT.findfact("added_aux_call_ios(" + Module + "," + to_string(Called_module_entry) + ")"))
							{
								if (HT.findfact("hierarchy_part(" + to_string(Called_module_entry) + "," + Called_module_name + ",*)"))
								{
									if (!custom_block(Called_module_name))
									{
										ss << "        " << Called_module_name << "_results_read :  OUT std_logic;" << endl;
										ss << "        " << Called_module_name << "_start :  OUT std_logic;" << endl;
										ss << "        " << Called_module_name << "_done :  IN std_logic;" << endl;
										ss << "        " << Called_module_name << "_busy :  IN std_logic;" << endl;
										HT.assertz("added_aux_call_ios( " + Module + "," + to_string(Called_module_entry) + ")");
									}
								}
							}
						}
					}
					else if (Orderout > 1)
					{
						if (HT.findfact("call_stmt(" + Module + "," + to_string(Call_entry) + "," + to_string(Called_module_entry) + ",_)"))
						{
							if (!HT.findfact("added_aux_call_ios(" + Module + "," + to_string(Called_module_entry) + ")"))
							{
								if (HT.findfact("hierarchy_part(" + to_string(Called_module_entry) + "," + Called_module_name + ",*)"))
								{
									if (!custom_block(Called_module_name))
									{
										ss << "        ";
										ss << write_polymorfic_IO_exression(Module, "parcs", 0, Called_module_name, "results_read", 1, Orderout, "        ", "", " : OUT std_logic;", 1, 0);
										ss << "        ";
										ss << write_polymorfic_IO_exression(Module, "parcs", 0, Called_module_name, "start", 1, Orderout, "        ", "", " : OUT std_logic;", 1, 0);
										ss << "        ";
										ss << write_polymorfic_IO_exression(Module, "parcs", 0, Called_module_name, "done", 1, Orderout, "        ", "", " : IN std_logic;", 1, 0);
										ss << "        ";
										ss << write_polymorfic_IO_exression(Module, "parcs", 0, Called_module_name, "busy", 1, Orderout, "        ", "", " : IN std_logic;", 1, 0);
										HT.assertz("added_aux_call_ios( " + Module + "," + to_string(Called_module_entry) + ")");
									}
								}
							}
						}
					}
					else if (HT.findfact("max_parallel_call_order(" + Module + "," + Schedule + "," + to_string(Called_module_entry) + ",_)"))
					{
						Max_order1 = stoi(returnpar(HT.findandreturn("max_parallel_call_order(" + Module + "," + Schedule + "," + to_string(Called_module_entry) + ",_)"), 4));
						if (Max_order1 <= Max_order)
						{
							if (HT.findfact("call_stmt(" + Module + "," + to_string(Call_entry) + "," + to_string(Called_module_entry) + ",_)"))
							{
								if (!HT.findfact("added_aux_call_ios(" + Module + "," + to_string(Called_module_entry) + ")"))
								{
									if (HT.findfact("hierarchy_part(" + to_string(Called_module_entry) + "," + Called_module_name + ",*)"))
									{
										if (!custom_block(Called_module_name))
										{
											ss << "        ";
											ss << write_polymorfic_IO_exression(Module, "parcs", 0, Called_module_name, "results_read", 1, Max_order1, "        ", "", " : OUT std_logic;", 1, 0);
											ss << "        ";
											ss << write_polymorfic_IO_exression(Module, "parcs", 0, Called_module_name, "start", 1, Max_order1, "        ", "", " : OUT std_logic;", 1, 0);
											ss << "        ";
											ss << write_polymorfic_IO_exression(Module, "parcs", 0, Called_module_name, "done", 1, Max_order1, "        ", "", " : IN std_logic;", 1, 0);
											ss << "        ";
											ss << write_polymorfic_IO_exression(Module, "parcs", 0, Called_module_name, "busy", 1, Max_order1, "        ", "", " : IN std_logic;", 1, 0);
											HT.assertz("added_aux_call_ios( " + Module + "," + to_string(Called_module_entry) + ")");
										}
									}
								}
							}
						}
						else if (Max_order1 >= Max_order)
						{
							if (HT.findfact("call_stmt(" + Module + "," + to_string(Call_entry) + "," + to_string(Called_module_entry) + ",_)"))
							{
								if (!HT.findfact("added_aux_call_ios(" + Module + "," + to_string(Called_module_entry) + ")"))
								{
									if (HT.findfact("hierarchy_part(" + to_string(Called_module_entry) + "," + Called_module_name + ",*)"))
									{
										if (!custom_block(Called_module_name))
										{
											ss << "        ";
											ss << write_polymorfic_IO_exression(Module, "parcs", 0, Called_module_name, "results_read", 1, Max_order, "        ", "", " : OUT std_logic;", 1, 0);
											ss << "        ";
											ss << write_polymorfic_IO_exression(Module, "parcs", 0, Called_module_name, "start", 1, Max_order, "        ", "", " : OUT std_logic;", 1, 0);
											ss << "        ";
											ss << write_polymorfic_IO_exression(Module, "parcs", 0, Called_module_name, "done", 1, Max_order, "        ", "", " : IN std_logic;", 1, 0);
											ss << "        ";
											ss << write_polymorfic_IO_exression(Module, "parcs", 0, Called_module_name, "busy", 1, Max_order, "        ", "", " : IN std_logic;", 1, 0);
											HT.assertz("added_aux_call_ios( " + Module + "," + to_string(Called_module_entry) + ")");
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
	else if (Schedule == "specials")
	{
		if (HT.findfact("hdl_style(\"verilog\")"))
		{
			if (HT.findfact("call_stmt(" + Module + "," + to_string(Call_entry) + "," + to_string(Called_module_entry) + ",_)"))
			{
				if (!HT.findfact("added_aux_call_ios(" + Module + "," + to_string(Called_module_entry) + ")"))
				{
					if (HT.findfact("hierarchy_part(" + to_string(Called_module_entry) + "," + Called_module_name + ",*)"))
					{
						if (!custom_block(Called_module_name))
						{
							ss << "                  " << Called_module_name << "_results_read," << endl;
							ss << "                  " << Called_module_name << "_start," << endl;
							ss << "                  " << Called_module_name << "_done," << endl;
							ss << "                  " << Called_module_name << "_busy," << endl;
							HT.assertz("added_aux_call_ios( " + Module + "," + to_string(Called_module_entry) + ")");
						}
					}
				}
			}
		}
	}
	else if (HT.findfact("hdl_style(\"verilog\")"))
	{
		if (parcs_or_parcsif(Schedule))
		{
			if (HT.findfact("max_parallel_call_order(" + Module + "," + Schedule + "," + to_string(Called_module_entry) + ",_)"))
			{
				Max_order = stoi(returnpar(HT.findandreturn("max_parallel_call_order(" + Module + "," + Schedule + "," + to_string(Called_module_entry) + ",_)"), 4));
				if (Max_order == 1)
				{
					if (HT.findfact("call_stmt(" + Module + "," + to_string(Call_entry) + "," + to_string(Called_module_entry) + ",_)"))
					{
						if (!HT.findfact("added_aux_call_ios(" + Module + "," + to_string(Called_module_entry) + ")"))
						{
							if (HT.findfact("hierarchy_part(" + to_string(Called_module_entry) + "," + Called_module_name + ",*)"))
							{
								if (!custom_block(Called_module_name))
								{
									ss << "                  " << Called_module_name << "_results_read," << endl;
									ss << "                  " << Called_module_name << "_start," << endl;
									ss << "                  " << Called_module_name << "_done," << endl;
									ss << "                  " << Called_module_name << "_busy," << endl;
									HT.assertz("added_aux_call_ios( " + Module + "," + to_string(Called_module_entry) + ")");
								}
							}
						}
					}
				}
			}
			else if (HT.findfact("totalmax_call_order(" + Module + ",\"parcs\",_)"))
			{
				Max_order = stoi(returnpar(HT.findandreturn("totalmax_call_order(" + Module + ",\"parcs\",_)"), 3));
				if (!HT.findfact("max_parallel_call_order(" + Module + "," + Schedule + "," + to_string(Called_module_entry) + ",_)"))
				{
					if (HT.findfact("call_stmt(" + Module + "," + to_string(Call_entry) + "," + to_string(Called_module_entry) + ",_)"))
					{
						if (!HT.findfact("added_aux_call_ios(" + Module + "," + to_string(Called_module_entry) + ")"))
						{
							if (HT.findfact("hierarchy_part(" + to_string(Called_module_entry) + "," + Called_module_name + ",*)"))
							{
								if (!custom_block(Called_module_name))
								{
									ss << "                  " << Called_module_name << "_results_read," << endl;
									ss << "                  " << Called_module_name << "_start," << endl;
									ss << "                  " << Called_module_name << "_done," << endl;
									ss << "                  " << Called_module_name << "_busy," << endl;
									HT.assertz("added_aux_call_ios( " + Module + "," + to_string(Called_module_entry) + ")");
								}
							}
						}
					}
				}
				else if (Max_order > 1)
				{
					if (HT.findfact("max_parallel_call_order(" + Module + "," + Schedule + "," + to_string(Called_module_entry) + ",_)"))
					{
						Max_order1 = stoi(returnpar(HT.findandreturn("max_parallel_call_order(" + Module + "," + Schedule + "," + to_string(Called_module_entry) + ",_)"), 4));
						if (Max_order1 == 1)
						{
							if (HT.findfact("call_stmt(" + Module + "," + to_string(Call_entry) + "," + to_string(Called_module_entry) + ",_)"))
							{
								if (!HT.findfact("added_aux_call_ios(" + Module + "," + to_string(Called_module_entry) + ")"))
								{
									if (HT.findfact("hierarchy_part(" + to_string(Called_module_entry) + "," + Called_module_name + ",*)"))
									{
										if (!custom_block(Called_module_name))
										{
											ss << "                  " << Called_module_name << "_results_read," << endl;
											ss << "                  " << Called_module_name << "_start," << endl;
											ss << "                  " << Called_module_name << "_done," << endl;
											ss << "                  " << Called_module_name << "_busy," << endl;
											HT.assertz("added_aux_call_ios( " + Module + "," + to_string(Called_module_entry) + ")");
										}
									}
								}
							}
						}
						if (HT.findfact("call_stmt(" + Module + "," + to_string(Call_entry) + "," + to_string(Called_module_entry) + ",_)"))
						{
							if (!HT.findfact("added_aux_call_ios(" + Module + "," + to_string(Called_module_entry) + ")"))
							{
								if (HT.findfact("hierarchy_part(" + to_string(Called_module_entry) + "," + Called_module_name + ",*)"))
								{
									if (!custom_block(Called_module_name))
									{
										ss << "                  ";
										ss << write_polymorfic_IO_exression(Module, "parcs", 0, Called_module_name, "results_read", 1, Max_order1, "                  ", "", ",", 1, 0);
										ss << "                  ";
										ss << write_polymorfic_IO_exression(Module, "parcs", 0, Called_module_name, "start", 1, Max_order1, "                  ", "", ",", 1, 0);
										ss << "                  ";
										ss << write_polymorfic_IO_exression(Module, "parcs", 0, Called_module_name, "done", 1, Max_order1, "                  ", "", ",", 1, 0);
										ss << "                  ";
										ss << write_polymorfic_IO_exression(Module, "parcs", 0, Called_module_name, "busy", 1, Max_order1, "                  ", "", ",", 1, 0);
										HT.assertz("added_aux_call_ios( " + Module + "," + to_string(Called_module_entry) + ")");
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return ss.str();
}

void find_correct_max_call_order(string Module_name, int Called_Module_entry, int Input_order, int* Order)
{
	int Next_order;
	if (HT.findfact("operation_order(" + Module_name + ",\"parcsif\",_,_," + to_string(Called_Module_entry) + ",_," + to_string(Input_order) + ",_,_,_,_)"))
		*Order = Input_order;
	else if (Input_order == 0)
		*Order = 0;
	else if (!HT.findfact("operation_order(" + Module_name + ",\"parcsif\",_,_," + to_string(Called_Module_entry) + ",_," + to_string(Input_order) + ",_,_,_,_)"))
	{
		Next_order = Input_order - 1;
		find_correct_max_call_order(Module_name, Called_Module_entry, Next_order, Order);
	}
}

string write_polymorfic_IO_exression(string Module, string Schedule_name, int State, string Called_Module_name, string Signal_name, int Next_order, int Max_order, string First_space, string Condition_op_string, string Suffix_string, int InRealCount, int PruneLastString)
{
	stringstream ss;
	int NextRealCount, Order_plus_1;
	if (Next_order <= Max_order)
	{
		ss << type_core_IO_expression(Called_Module_name, State, Signal_name, Next_order, Max_order, First_space, Condition_op_string, Suffix_string, InRealCount, &NextRealCount, PruneLastString);
		Order_plus_1 = Next_order + 1;
		ss << write_polymorfic_IO_exression(Module, Schedule_name, State, Called_Module_name, Signal_name, Order_plus_1, Max_order, First_space, Condition_op_string, Suffix_string, NextRealCount, PruneLastString);
	}
	return ss.str();
}

string type_core_IO_expression(string Called_Module_name, int var2, string Signal_name, int var4, int Max_order, string var6, string Condition_op_string, string Suffix_string, int InRealCount, int* OutRealCount, int PruneLastString)
{
	stringstream ss;
	string Module_name, Next_order_str, StrOrder;
	int Called_module_entry, Same_order, Same_total, Total_order;
	if (var4 > Max_order)
		*OutRealCount = InRealCount;
	else if (var4 == 1)
	{
		if (var2 == 0)
		{
			ss << Called_Module_name << "_1_" << Signal_name << Suffix_string << " ";
			ss << write_or_prune(InRealCount, Max_order, Condition_op_string, PruneLastString) << endl;
			*OutRealCount = InRealCount + 1;
		}
		else if (HT.findfact("current_module(*)"))
		{
			Module_name = stoi(returnpar(HT.findandreturn("current_module(*)"), 1));
			if (var2 > 0)
			{
				if (HT.findfact("operation_order(" + Module_name + ",\"parcsif\"," + to_string(var2) + ",_,_,_,_,1,_,_,_)"))
				{
					Called_module_entry = stoi(returnpar(HT.findandreturn("operation_order(" + Module_name + ",\"parcsif\"," + to_string(var2) + ",_,_,_,_,1,_,_,_)"), 5));
					Same_order = stoi(returnpar(HT.findandreturn("operation_order(" + Module_name + ",\"parcsif\"," + to_string(var2) + ",_,_,_,_,1,_,_,_)"), 6));
					Same_total = stoi(returnpar(HT.findandreturn("operation_order(" + Module_name + ",\"parcsif\"," + to_string(var2) + ",_,_,_,_,1,_,_,_)"), 7));
					Total_order = stoi(returnpar(HT.findandreturn("operation_order(" + Module_name + ",\"parcsif\"," + to_string(var2) + ",_,_,_,_,1,_,_,_)"), 9));
					ss << produce_real_same_calls_count(var6, Called_module_entry, var2, Signal_name, Suffix_string, Condition_op_string, Same_order, Same_total, 1, Total_order, Max_order, InRealCount, OutRealCount, PruneLastString);

				}
			}
		}
	}
	else if (var2 == 0)
	{
		if (var4 > 1)
		{
			if (var4 < Max_order)
			{
				Next_order_str = to_string(InRealCount);
				HT.concat("_", Next_order_str, &StrOrder);
				ss << var6 << Called_Module_name << StrOrder << "_" << Signal_name << Suffix_string << " ";
				ss << write_or_prune(InRealCount, Max_order, Condition_op_string, PruneLastString) << endl;
				*OutRealCount = InRealCount + 1;
			}
		}
		else if (var4 == Max_order)
		{
			if (var4 == 1)
			{
				Next_order_str = to_string(var4);
				HT.concat("_", Next_order_str, &StrOrder);
				ss << Called_Module_name << StrOrder << "_" << Signal_name << Suffix_string << endl;
				*OutRealCount = InRealCount + 1;
			}
			else if (var4 > 1)
			{
				Next_order_str = to_string(var4);
				HT.concat("_", Next_order_str, &StrOrder);
				ss << var6 << Called_Module_name << StrOrder << "_" << Signal_name << Suffix_string << endl;
				*OutRealCount = InRealCount + 1;
			}
		}
	}
	else if (HT.findfact("current_module(" + Module_name + ")"))
	{
		if (var2 > 0)
		{
			if (HT.findfact("operation_order(" + Module_name + ",\"parcsif\"," + to_string(var2) + ",_,_,_,_," + to_string(var4) + ",_,_,_)"))
			{
				Called_module_entry = stoi(returnpar(HT.findandreturn("operation_order(" + Module_name + ",\"parcsif\"," + to_string(var2) + ",_,_,_,_," + to_string(var4) + ",_,_,_)"), 5));
				Same_order = stoi(returnpar(HT.findandreturn("operation_order(" + Module_name + ",\"parcsif\"," + to_string(var2) + ",_,_,_,_," + to_string(var4) + ",_,_,_)"), 6));
				Same_total = stoi(returnpar(HT.findandreturn("operation_order(" + Module_name + ",\"parcsif\"," + to_string(var2) + ",_,_,_,_," + to_string(var4) + ",_,_,_)"), 7));
				Total_order = stoi(returnpar(HT.findandreturn("operation_order(" + Module_name + ",\"parcsif\"," + to_string(var2) + ",_,_,_,_," + to_string(var4) + ",_,_,_)"), 9));
				ss << produce_real_same_calls_count(var6, Called_module_entry, var2, Signal_name, Suffix_string, Condition_op_string, Same_order, Same_total, var4, Total_order, Max_order, InRealCount, OutRealCount, PruneLastString);
			}
		}
	}
	return ss.str();
}

string write_or_prune(int InRealCount, int Total_order, string Condition_op_string, int int1)
{
	stringstream ss;
	if (int1 == 0)
		ss << Condition_op_string;
	else if (int1 == 1)
		if (InRealCount < Total_order)
			ss << Condition_op_string;
	return ss.str();
}

string produce_real_same_calls_count(string First_space, int Called_module_entry, int State, string Signal_name, string Suffix_string, string Condition_op_string, int Same_order, int Same_total, int Next_order, int Total_order, int Max_order, int InRealCount, int* OutRealCount, int PruneLastString)
{
	stringstream ss;
	string Called_Module_name, StrOrder, Next_order_str;
	if (State > 0)
	{
		if (Same_order > 0)
		{
			if (Same_total > 0)
			{
				if (InRealCount == 1)
				{
					if (Max_order > 0)
					{
						if (HT.findfact("hierarchy_part(" + to_string(Called_module_entry) + ",_,_,\"libpart\",_,_,_)"))
						{
							Called_Module_name = returnpar(HT.findandreturn("hierarchy_part(" + to_string(Called_module_entry) + ",_,_,\"libpart\",_,_,_)"), 1);
							make_order_string(Same_order, Same_total, &StrOrder);
							ss << Called_Module_name << StrOrder << "_" << Signal_name << Suffix_string << " ";
							ss << write_or_prune(InRealCount, Total_order, Condition_op_string, PruneLastString) << endl;
							*OutRealCount = InRealCount + 1;
						}
					}
					else if (Max_order == 1)
					{
						if (HT.findfact("hierarchy_part(" + to_string(Called_module_entry) + ",_,_,\"libpart\",_,_,_)"))
						{
							Called_Module_name = returnpar(HT.findandreturn("hierarchy_part(" + to_string(Called_module_entry) + ",_,_,\"libpart\",_,_,_)"), 1);
							Next_order_str = to_string(Same_order);
							HT.concat("_", Next_order_str, &StrOrder);
							ss << Called_Module_name << StrOrder << "_" << Signal_name << Suffix_string << endl;
							*OutRealCount = InRealCount + 1;
						}
					}
				}
				else if (InRealCount > 1)
				{
					if (Max_order > 1)
					{
						if (HT.findfact("hierarchy_part(" + to_string(Called_module_entry) + ",_,_,\"libpart\",_,_,_)"))
						{
							make_order_string(Same_order, Same_total, &StrOrder);
							ss << First_space << Called_Module_name << StrOrder << "_" << Signal_name << Suffix_string << " ";
							ss << write_or_prune(InRealCount, Total_order, Condition_op_string, PruneLastString) << endl;
							*OutRealCount = InRealCount + 1;
						}
					}
				}
			}
		}
	}
	else if (Same_order == 0 && Same_total == 0)
		*OutRealCount = InRealCount;
	return ss.str();
}

void make_order_string(int Same_order, int Same_total, string* Order)
{
	if (Same_total == 1)
		*Order = "";
	else if (Same_total > 1)
	{
		string Order1 = to_string(Same_order);
		HT.concat("_", Order1, Order);
	}
}

bool parcs_or_parcsif(string New_schedule)
{
	return New_schedule == "parcs" || New_schedule == "parcsif";
}

string write_standard_verilog_call_decls(string Module, int Call_entry)
{
	stringstream ss;
	int Called_module_entry, Next_entry;
	if (HT.findfact("call_stmt(" + Module + "," + to_string(Call_entry) + ",_,_)"))
	{
		Called_module_entry = stoi(returnpar(HT.findandreturn("call_stmt(" + Module + "," + to_string(Call_entry) + ",_,_)"), 3));
		ss << write_standard_verilog_decls_for_called_module(Module, Call_entry, Called_module_entry);
		Next_entry = Call_entry + 1;
		ss << write_standard_verilog_call_decls(Module, Next_entry);
	}
	return ss.str();
}

string write_standard_verilog_decls_for_called_module(string Module, int Call_entry, int Called_module_entry)
{
	stringstream ss;
	string Called_module_name;
	int Max_order;
	if (HT.findfact("old_schedule(\"specials\")"))
	{
		if (HT.findfact("call_stmt(" + Module + "," + to_string(Call_entry) + "," + to_string(Called_module_entry) + ",*)"))
		{
			if (!HT.findfact("added_aux_call_ios(" + Module + "," + to_string(Called_module_entry) + ")"))
			{
				if (HT.findfact("hierarchy_part(" + to_string(Called_module_entry) + ",*)"))
				{
					Called_module_name = returnpar(HT.findandreturn("hierarchy_part(" + to_string(Called_module_entry) + ",*)"), 2);
					if (!custom_block(Called_module_name))
					{
						ss << "   output " << Called_module_name << "_results_read; " << endl;
						ss << "   reg    " << Called_module_name << "_results_read; " << endl;
						ss << "   output " << Called_module_name << "_start;" << endl;
						ss << "   reg    " << Called_module_name << "_start;" << endl;
						ss << "   input  " << Called_module_name << "_done; " << endl;
						ss << "   input  " << Called_module_name << "_busy; " << endl;
						HT.assertz("added_aux_call_ios( " + Module + "," + to_string(Called_module_entry) + ")");
					}
				}
			}
		}
	}
	else if (HT.findfact("new_schedule(\"parcsif\")"))
	{
		if (HT.findfact("max_parallel_call_order(" + Module + ",\"parcsif\"," + to_string(Called_module_entry) + ",*)"))
		{
			Max_order = stoi(returnpar(HT.findandreturn("max_parallel_call_order(" + Module + ",\"parcsif\"," + to_string(Called_module_entry) + ",*)"), 4));
			if (Max_order == 1)
			{
				if (HT.findfact("call_stmt(" + Module + "," + to_string(Call_entry) + "," + to_string(Called_module_entry) + ",*)"))
				{
					if (!HT.findfact("added_aux_call_ios(" + Module + "," + to_string(Called_module_entry) + ")"))
					{
						if (HT.findfact("hierarchy_part(" + to_string(Called_module_entry) + ",*)"))
						{
							Called_module_name = returnpar(HT.findandreturn("hierarchy_part(" + to_string(Called_module_entry) + ",*)"), 2);
							if (!custom_block(Called_module_name))
							{
								ss << "   output " << Called_module_name << "_results_read; " << endl;
								ss << "   reg    " << Called_module_name << "_results_read; " << endl;
								ss << "   output " << Called_module_name << "_start;" << endl;
								ss << "   reg    " << Called_module_name << "_start;" << endl;
								ss << "   input  " << Called_module_name << "_done; " << endl;
								ss << "   input  " << Called_module_name << "_busy; " << endl;
								HT.assertz("added_aux_call_ios( " + Module + "," + to_string(Called_module_entry) + ")");
							}
						}
					}
				}
			}
		}
	}
	else if (HT.findfact("hdl_style(\"verilog\")"))
	{
		if (HT.findfact("new_schedule(\"parcsif\")"))
		{
			if (HT.findfact("max_parallel_call_order(" + Module + ",\"parcsif\"," + to_string(Called_module_entry) + ",*)"))
			{
				Max_order = stoi(returnpar(HT.findandreturn("max_parallel_call_order(" + Module + ",\"parcsif\"," + to_string(Called_module_entry) + ",*)"), 4));
				if (Max_order > 1)
				{
					if (HT.findfact("call_stmt(" + Module + "," + to_string(Call_entry) + "," + to_string(Called_module_entry) + ",*)"))
					{
						if (!HT.findfact("added_aux_call_ios(" + Module + "," + to_string(Called_module_entry) + ")"))
						{
							if (HT.findfact("hierarchy_part(" + to_string(Called_module_entry) + ",*)"))
							{
								Called_module_name = returnpar(HT.findandreturn("hierarchy_part(" + to_string(Called_module_entry) + ",*)"), 2);
								if (!custom_block(Called_module_name))
								{
									ss << "             output ";
									write_polymorfic_IO_exression(Module, "parcs", 0, Called_module_name, "results_read", 1, Max_order, "             output ", "", ";", 1, 0);
									ss << "             reg    ";
									write_polymorfic_IO_exression(Module, "parcs", 0, Called_module_name, "results_read", 1, Max_order, "             reg    ", "", ";", 1, 0);
									ss << "             output ";
									write_polymorfic_IO_exression(Module, "parcs", 0, Called_module_name, "start", 1, Max_order, "             output ", "", ";", 1, 0);
									ss << "             reg    ";
									write_polymorfic_IO_exression(Module, "parcs", 0, Called_module_name, "start", 1, Max_order, "             reg    ", "", ";", 1, 0);
									ss << "             input  ";
									write_polymorfic_IO_exression(Module, "parcs", 0, Called_module_name, "done", 1, Max_order, "             input  ", "", ";", 1, 0);
									ss << "             input  ";
									write_polymorfic_IO_exression(Module, "parcs", 0, Called_module_name, "busy", 1, Max_order, "             input  ", "", ";", 1, 0);
									HT.assertz("added_aux_call_ios( " + Module + "," + to_string(Called_module_entry) + ")");
								}
							}
						}
					}
				}
			}
		}
	}
	return ss.str();
}

string write_verilog_call_ios(string Module, int Call_entry)
{
	stringstream ss;
	int Called_module_entry, Next_entry;
	string Called_module_name;
	if (HT.findfact("added_aux_call_ios(" + Module + ",*)"))
	{
		Called_module_entry = stoi(returnpar(HT.findandreturn("added_aux_call_ios(" + Module + ",*)"), 2));
		if (HT.findfact("hierarchy_part(" + to_string(Called_module_entry) + ",*)"))
		{
			Called_module_name = returnpar(HT.findandreturn("hierarchy_part(" + to_string(Called_module_entry) + ",*)"), 2);
			ss << "   output " << Called_module_name << "_results_read; " << endl;
			ss << "   reg    " << Called_module_name << "_results_read; " << endl;
			ss << "   output " << Called_module_name << "_start; " << endl;
			ss << "   reg    " << Called_module_name << "_start; " << endl;
			Next_entry = Call_entry + 1;
			ss << write_verilog_call_ios(Module, Next_entry);
		}
	}
	return ss.str();
}

string write_content_header(string Module_name, string HDL, string Tool)
{
	stringstream ss;
	if (Tool == "synergy")
	{
		if (HDL == "vhdl")
		{
			ss << endl << "  ARCHITECTURE rtl OF " << Module_name << " IS " << endl << endl;
			ss << "   SIGNAL done_int : std_logic;" << endl;
		}
		else if (HDL == "verilog")
		{
			ss << "   reg   done_int;" << endl;
		}
	}
	return ss.str();
}

string print_states_type(int Last_state)
{
	stringstream ss;
	string Module_name;
	int All_states, Log2state, State_reg_upper_bound;
	if (HT.findfact("hdl_style(\"vhdl\")"))
	{
		ss << "   TYPE states_type IS (";
		ss << write_state_symbols(Last_state, 1);
		ss << ");" << endl;
		ss << "   SIGNAL state : states_type;  -- this stores the current and next state of the circuit" << endl;
	}
	else if (HT.findfact("hdl_style(\"verilog\")"))
	{
		if (HT.findfact("current_module(*)"))
		{
			Module_name = returnpar(HT.findandreturn("current_module(*)"), 1);
			ss << endl;
			ss << "   /* now list the states  */" << endl;
			ss << "   parameter ";
			ss << write_state_symbols(Last_state, 1);
			ss << "    ;" << endl;
			All_states = Last_state + 1;
			log2n(All_states, 1, 1, &Log2state);
			State_reg_upper_bound = Log2state - 1;
			ss << "   // The following state variable holds the current and next state of the FSM" << endl;
			ss << "   (* safe_fsm *)" << endl;
			ss << "   reg   [" << State_reg_upper_bound << ":0] state ;  // synthesis safe_fsm" << endl;
			ss << write_next_state_variable(Module_name, "verilog", State_reg_upper_bound) << endl;
		}
	}

	return ss.str();
}

string write_state_symbols(int Last_state, int var2)
{
	stringstream ss;
	int Previous_state, Next_number;
	if (Last_state == 0)
		if (HT.findfact("hdl_style(\"vhdl\")"))
			ss << "state_0";
		else if (HT.findfact("hdl_style(\"verilog\")"))
			ss << "state_0 = 0";
		else
		{
			ss << write_state_symbols_core(Last_state, var2, &Previous_state, &Next_number);
			ss << write_state_symbols(Previous_state, Next_number);
		}
	return ss.str();
}

string write_state_symbols_core(int Last_state, int Current_number, int* Previous_state, int* Next_number)
{
	stringstream ss;
	int Modulo5;
	if (HT.findfact("hdl_style(\"vhdl\")"))
	{
		if (Last_state > 0)
		{
			ss << "state_" << Last_state << ", ";
			Modulo5 = Current_number % 5;
			ss << new_state_symbols_line(Modulo5);
			*Previous_state = Last_state - 1;
			*Next_number = Current_number + 1;
		}
	}
	else if (HT.findfact("hdl_style(\"verilog\")"))
	{
		if (Last_state > 0)
		{
			Modulo5 = Current_number % 5;
			ss << new_state_symbols_line(Modulo5);
			ss << "state_" << Last_state << " = " << Last_state << ", ";
			*Previous_state = Last_state - 1;
			*Next_number = Current_number + 1;
		}
	}
	return ss.str();
}

string new_state_symbols_line(int Current_number)
{
	stringstream ss;
	if (Current_number == 1)
	{
		if (HT.findfact("hdl_style(\"vhdl\")"))
			ss << endl << "                        ";
		else if (HT.findfact("hdl_style(\"verilog\")"))
			ss << endl << "          ";
	}
	return ss.str();
}

string write_next_state_variable(string Module_name, string HDL, int Upper)
{
	stringstream ss;
	int TotalCallOrder;
	if (HT.findfact("totalmax_call_order(" + Module_name + ",\"parcsif\",*)"))
	{
		TotalCallOrder = stoi(returnpar(HT.findandreturn("totalmax_call_order(" + Module_name + ",\"parcsif\",*)"), 3));
		if (TotalCallOrder >= 1)
		{
			if (HDL == "vhdl")
			{
				ss << "     TYPE STATES_ARRAY IS ARRAY (integer RANGE <>) OF STATES_TYPE;" << endl;
				ss << "     VARIABLE state_var : STATES_ARRAY(" << TotalCallOrder << " DOWNTO 1);" << endl;
			}
			else if (HDL == "verilog")
				ss << "     reg [" << Upper << ":0] state_var [" << TotalCallOrder << ":1] ;" << endl;
		}
	}
	return ss.str();
}

string write_locals(string Module, int In_entry, string Hdl, string Tool)
{
	stringstream ss;
	int Next_entry;
	GeneralFact* Local;
	if (HT.findfact("local_object(" + Module + "," + to_string(In_entry) + ",*)"))
	{
		Local = makeInstanceOf(HT.findandreturn("local_object(" + Module + "," + to_string(In_entry) + ",*)"));
		local_object* ptr = dynamic_cast<local_object*>(Local);
		ss << write_local_conditionally(Module, *ptr, Hdl, Tool);
		Next_entry = In_entry + 1;
		ss << write_locals(Module, Next_entry, Hdl, Tool);
	}
	return ss.str();
}

string write_local_conditionally(string Module, local_object Local, string Hdl, string Tool)
{
	stringstream ss;
	string Name, Package;
	if (HT.findfact("data_stmt(" + Package + "," + Name + ",_,_,\"const\",_)"))
	{
		Package = returnpar(HT.findandreturn("package_name(*)"), 1);
		GeneralFact* ptr;
		ptr = &Local;
		Name = returnpar(HT.findandreturn(makeStringOf(ptr)), 4);
		if (HT.findfact("package_name(*)"))
			ss << write_local(Local, Hdl, Tool, "");
	}
	return ss.str();
}

string write_local(local_object Local, string HDL, string Tool, string Suffix)
{
	stringstream ss;
	string Module, var3, Local_name, Type_name, var7, Local_value, Kind, Parent_name, Just_local_field, JustParent, Type_kind, NewName,
		Parent_kind, Local_name1, Comp_kind, be, af;
	int Current_entry, var5, Local_size, Parent_type, Up_limit, Child_type, Type_number, Parent_size, Type_size, MSB, Num_dim, Comp_type,
		Comp_size, Comp_num_dim, First_dim, Last_dim, Upper_bound;
	GeneralFact* ptr;
	ptr = &Local;
	Module = returnpar(makeStringOf(ptr), 1);
	Current_entry = stoi(returnpar(makeStringOf(ptr), 2));
	var3 = returnpar(makeStringOf(ptr), 3);
	Local_name = returnpar(makeStringOf(ptr), 4);
	var5 = stoi(returnpar(makeStringOf(ptr), 5));
	Type_name = returnpar(makeStringOf(ptr), 6);
	var7 = returnpar(makeStringOf(ptr), 7);
	Local_size = stoi(returnpar(makeStringOf(ptr), 8));
	Local_value = returnpar(makeStringOf(ptr), 9);
	be = Local_value.substr(0, Local_value.find(pa, 0));
	af = Local_value.substr(be.length() + 1, Local_value.find(pacl, 0));
	af.resize(af.size() - 1);

	if (Tool == "synergy")
	{
		if (HDL == "vhdl")
		{
			if (var3 == "par_in" || var3 == "par_out" || var3 == "par_inout")
				return ss.str();
			if (var3 == "signal")
			{
				if (var7 == "standard")
				{
					if (Type_name == "bool")
					{
						ss << "   SIGNAL " << Local_name << " : std_logic;" << endl;
					}
					else if (Type_name == "std_logic")
					{
						ss << "   SIGNAL " << Local_name << " : ";
						ss << write_size(Local_size, "std_logic", "vhdl", "synergy", 0) << endl;
					}
					else if (Type_name == "integer")
					{
						ss << "   SIGNAL " << Local_name << " : ";
						ss << write_size(Local_size, "std_logic", "vhdl", "synergy", 0) << endl;
					}
					else if (HT.findfact("type_def(_," + Type_name + ",_,_,2,_,_,_,_)"))
					{
						ss << "   SIGNAL " << Local_name << " : ";
						ss << write_size(Local_size, "std_logic", "vhdl", "synergy", 0) << endl;
					}
					else if (HT.findfact("type_def(_," + Type_name + ",_,_,_,\"single_t\",_,_,2)"))
					{
						Parent_type = stoi(returnpar(HT.findandreturn("type_def(_," + Type_name + ",_,_,_,\"single_t\",_,_,2)"), 5));
						if (HT.findfact("type_def(" + to_string(Parent_type) + ",_,_,_,_,\"record_t\",_,_,_)"))
						{
							ss << "   SIGNAL " << Local_name << " : ";
							ss << write_size(Local_size, "std_logic", "vhdl", "synergy", 0) << endl;

						}
					}
					else if (HT.findfact("type_def(_," + Type_name + ",_,_,_,_,_,_,_)"))
					{
						Parent_type = stoi(returnpar(HT.findandreturn("type_def(_," + Type_name + ",_,_,_,_,_,_,_)"), 5));
						if (Parent_type != 2)
						{
							ss << "   SIGNAL " << Local_name << " : ";
							ss << Type_name << " ;" << endl;
						}
					}
				}
				else if (var7 == "userarray")
				{
					if (HT.findfact("type_def(_," + Type_name + "," + to_string(Local_size) + ",_,_,\"vectorarray_t\",_," + to_string(Local_size) + ",1)"))
					{
						Up_limit = Local_size - 1;
						ss << "   SIGNAL " << Local_name << " : Std_logic_vector(" << Up_limit << " DOWNTO 0) ; " << endl;
					}
					else if (HT.findfact("type_def(_," + Type_name + ",_,_,_,\"vectorarray_t\",_,_,_)"))
					{
						Parent_type = stoi(returnpar(HT.findandreturn("type_def(_," + Type_name + ",_,_,_,\"vectorarray_t\",_,_,_)"), 5));
						Child_type = stoi(returnpar(HT.findandreturn("type_def(_," + Type_name + ",_,_,_,\"vectorarray_t\",_,_,_)"), 9));
						if (HT.findfact("type_def(" + to_string(Parent_type) + ",*)"))
						{
							Parent_name = returnpar(HT.findandreturn("type_def(" + to_string(Parent_type) + ",*)"), 2);
							Kind = returnpar(HT.findandreturn("type_def(" + to_string(Parent_type) + ",*)"), 6);
							if (Kind != "record_t")
							{
								if (Child_type != 1)
								{
									ss << "   SIGNAL " << Local_name << " : " << Type_name << " ; " << endl;
								}
							}
							else if (Child_type != 1)
								if (HT.concat(".", &Just_local_field, Type_name))
									if (HT.concat(&JustParent, Type_name, Local_name))
										ss << "   SIGNAL " << JustParent << "_" << Just_local_field << " : " << Parent_name << "_" << Just_local_field << " ; " << endl;
						}
					}
					else if (Local_name != "boolean")
					{
						if (HT.findfact("type_def(_," + Type_name + ",_,_,_,\"vectorarray_t\",_,_,_)"))
						{
							ss << "   SIGNAL " << Local_name << " : " << Type_name << " ; " << endl;
						}
					}
				}
				else if (var7 == "userrecord") // might be a mistake confusing Local_name with Type_name
				{
					if (Type_name == "boolean")
						ss << "   SIGNAL " << Local_name << " : boolean;" << endl;
					else if (Local_name != "boolean")
					{
						if (HT.findfact("type_def(_," + Type_name + "," + to_string(Local_size) + ",_,_,\"single_t\",_,_,_)"))
						{
							ss << "   SIGNAL " << Local_name << " : ";
							ss << write_size(Local_size, "std_logic", "vhdl", "synergy", 0) << endl;
						}
						else if (HT.findfact("type_def(_," + Type_name + "," + to_string(Local_size) + ",_,_,_,_,_,_)"))
						{
							Type_kind = returnpar(HT.findandreturn("type_def(_," + Type_name + ",_,_,_,_,_,_,_)"), 6);
							if (Type_kind != "single_t")
							{
								ss << "   SIGNAL " << Local_name << " : " << Type_name << " ; " << endl;
							}
						}
					}
				}
			}
			else if (var3 == "constant")
			{
				if (var7 == "standard")
				{
					replace_chars_in_string(Local_name, ".", "_", &NewName);
					if (NewName == Local_name)
					{
						ss << "   CONSTANT " << Local_name << " : ";
						ss << write_value(Local_value, Local_size, Type_name, "vhdl", "synergy") << endl;
					}
					else
					{
						ss << "   CONSTANT " << NewName << " : ";
						ss << write_value(Local_value, Local_size, Type_name, "vhdl", "synergy") << endl;
					}
				}
			}
		}
		else if (HDL == "verilog")
		{
			if (var3 == "par_in" || var3 == "par_out" || var3 == "par_inout")
				return ss.str();
			if (var3 == "signal")
			{
				if (var7 == "standard")
				{
					if (Type_name == "bool")
					{
						ss << "   reg  " << Local_name << Suffix << ";" << endl;
					}
					else if (Type_name == "std_logic")
					{
						ss << "   reg  ";
						ss << write_size(Local_size, "std_logic", "verilog", "synergy", 0);
						ss << " " << Local_name << Suffix << ";" << endl;
					}
					else if (HT.findfact("type_def(_," + Type_name + "," + to_string(Local_size) + ",\"user\",_,_,_,_,2)"))
					{
						Type_number = stoi(returnpar(HT.findandreturn("type_def(_," + Type_name + "," + to_string(Local_size) + ",\"user\",_,_,_,_,2)"), 1));
						Parent_type = stoi(returnpar(HT.findandreturn("type_def(_," + Type_name + "," + to_string(Local_size) + ",\"user\",_,_,_,_,2)"), 5));
						if (HT.findfact("type_def(" + to_string(Parent_type) + ",_,_,\"user\",_,_,_,_,_)"))
						{
							Parent_size = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Parent_type) + ",_,_,\"user\",_,_,_,_,_)"), 3));
							Parent_kind = returnpar(HT.findandreturn("type_def(" + to_string(Parent_type) + ",_,_,\"user\",_,_,_,_,_)"), 6);
							if (Parent_size >= Local_size)
							{
								if (Parent_kind != "single_t")
								{
									if (Parent_type < Type_number)
									{
										ss << "   reg  " << Local_name << Suffix << " ;" << endl;
									}
								}
							}
						}
					}
					else if (Local_size == 1)
					{
						if (HT.findfact("type_def(_," + Type_name + ",_,_,_,_,_,_,_)"))
						{
							Type_size = stoi(returnpar(HT.findandreturn("type_def(_," + Type_name + ",_,_,_,_,_,_,_)"), 3));
							if (Type_size == 1)
							{
								ss << "   reg  " << Local_name << Suffix << " ";
								ss << " ;" << endl;
							}
						}
					}
					else if (Type_name != "integer")
					{
						if (HT.findfact("type_def(_," + Type_name + ",_,2,_,_,_,_,_)"))
						{
							Type_size = stoi(returnpar(HT.findandreturn("type_def(_," + Type_name + ",_,2,_,_,_,_,_)"), 3));
							if (Type_size > 1)
							{
								MSB = Type_size - 1;
								ss << "   reg  [" << MSB << ":0] " << Local_name << Suffix << " ";
								ss << " ;" << endl;
							}
						}
						else if (HT.findfact("type_def(_," + Type_name + ",_,_,_,_,_,_,_)"))
						{
							Type_number = stoi(returnpar(HT.findandreturn("type_def(_," + Type_name + ",_,_,_,_,_,_,_)"), 1));
							Type_size = stoi(returnpar(HT.findandreturn("type_def(_," + Type_name + ",_,_,_,_,_,_,_)"), 3));
							if (Type_size > 1)
							{
								ss << "   reg  " << Local_name << Suffix << " ";
								ss << write_verilog_dimmension_component_recursively(Type_number);
								ss << " ;" << endl;
							}
						}

					}
					else if (Local_size > 1)
					{
						MSB = Local_size - 1;
						ss << "   reg  [" << MSB << ":0] " << Local_name << Suffix << " ";
						ss << " ;" << endl;
					}
				}
				else if (var7 == "userarray")
				{
					if (HT.findfact("type_def(_," + Type_name + ",_,_,_,_,_,_,_)"))
					{
						Type_number = stoi(returnpar(HT.findandreturn("type_def(_," + Type_name + ",_,_,_,_,_,_,_)"), 1));
						First_dim = stoi(returnpar(HT.findandreturn("type_def(_," + Type_name + ",_,_,_,_,_,_,_)"), 7));
						Num_dim = stoi(returnpar(HT.findandreturn("type_def(_," + Type_name + ",_,_,_,_,_,_,_)"), 8));
						Comp_type = stoi(returnpar(HT.findandreturn("type_def(_," + Type_name + ",_,_,_,_,_,_,_)"), 9));
						if (HT.findfact("type_def(" + to_string(Comp_type) + ",_,_,_,_,\"vectorarray_t\",_,_,_)"))
						{
							Comp_size = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Comp_type) + ",_,_,_,_,\"vectorarray_t\",_,_,_)"), 3));
							Comp_num_dim = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Comp_type) + ",_,_,_,_,\"vectorarray_t\",_,_,_)"), 8));
							if (Comp_size > 1)
							{
								ss << "   reg  ";
								HT.concat(Local_name, Suffix, &Local_name1);
								ss << print_verilog_array_decl(Type_number, Local_name1, " ; ") << endl;
								ss << write_verilog_array_index_registers(Module, Local_name, Type_number, Num_dim, Comp_num_dim, 1);
								ss << endl;
							}
						}
						else if (HT.findfact("type_def(" + to_string(Comp_type) + ",*)"))
						{
							Comp_size = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Comp_type) + ",*)"), 3));
							Comp_kind = returnpar(HT.findandreturn("type_def(" + to_string(Comp_type) + ",*)"), 6);
							Comp_num_dim = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Comp_type) + ",*)"), 8));
							if (Comp_kind != "vectorarray_t")
							{
								if (Comp_size > 1)
								{
									ss << "   reg  ";
									HT.concat(Local_name, Suffix, &Local_name1);
									ss << print_verilog_array_decl(Type_number, Local_name1, " ; ") << endl;
									ss << write_verilog_array_index_registers(Module, Local_name, Type_number, Num_dim, 0, 1);
									ss << endl;
								}
							}
							else if (Comp_size == 1)
							{
								Last_dim = Num_dim - 1;
								if (Last_dim > First_dim)
								{
									ss << "   reg   ";
									HT.concat(Local_name, Suffix, &Local_name1);
									ss << " [" << First_dim << ":" << Last_dim << "] " << Local_name1 << ";" << endl;
									ss << "   integer " << Local_name1 << "_i ;" << endl;
								}
							}
						}
					}
				}
				else if (var7 == "userrecord")
				{
					if (Type_name == "boolean")
					{
						ss << "   reg  ";
						ss << write_size(Local_size, "std_logic", "verilog", "synergy", 0);
						ss << " " << Local_name << Suffix << " ; " << endl;
					}
					else
					{
						ss << "   reg  ";
						if (HT.findfact("type_def(_," + Type_name + "," + to_string(Local_size) + ",_,_,_,_,_,_)"))
						{
							Type_number = stoi(returnpar(HT.findandreturn("type_def(_," + Type_name + "," + to_string(Local_size) + ",_,_,_,_,_,_)"), 1));
							Upper_bound = Local_size - 1;
							HT.concat(Local_name, Suffix, &Local_name1);
							ss << " [" << Upper_bound << ":0] " << Local_name1;
							ss << write_verilog_dimmension_component_recursively(Type_number);
							ss << " ;" << endl;

						}
					}
				}
			}
			else if (var3 == "constant")
			{
				if (var7 == "standard")
				{
					replace_chars_in_string(Local_name, ".", "_", &NewName);
					if (NewName == Local_name)
					{
						HT.concat(Local_name, Suffix, &Local_name1);
						ss << "   parameter " << Local_name1 << " = ";
						ss << write_value(Local_value, Local_size, Type_name, "verilog", "synergy") << endl;
					}
					else
					{
						HT.concat(NewName, Suffix, &Local_name1);
						ss << "   parameter " << Local_name1 << " = ";
						ss << write_value(Local_value, Local_size, Type_name, "verilog", "synergy") << endl;
					}
				}
			}
		}
	}
	else if (Tool == "gnu")
	{
		if (HDL == "c")
		{
			if (var3 != "constant")
			{
				if (var7 == "standard")
				{
					if (Type_name == "std_logic")
					{
						if (be == "sym")
						{
							ss << "     long long int " << Local_name << ";" << endl;

						}
					}
					else if (Type_name == "bool")
					{
						ss << "     long long int " << Local_name << ";" << endl;

					}
					else if (Local_value == "bit_wire(\"std_logic\")")
					{
						if (Local_size <= 32)
						{
							ss << "     long long int ";
							ss << " " << Local_name << ";" << endl;
						}
						else
						{
							ss << "     long long int ";
							ss << " " << Local_name << ";" << endl;
						}
					}
					else if (HT.findfact("type_def(_," + Type_name + "," + to_string(Local_size) + ",\"user\",_,_,_,_,2)"))
					{
						Type_number = stoi(returnpar(HT.findandreturn("type_def(_," + Type_name + "," + to_string(Local_size) + ",\"user\",_,_,_,_,2)"), 1));
						Parent_type = stoi(returnpar(HT.findandreturn("type_def(_," + Type_name + "," + to_string(Local_size) + ",\"user\",_,_,_,_,2)"), 5));
						if (HT.findfact("type_def(" + to_string(Parent_type) + ",_,_,\"user\",_,_,_,_,_)"))
						{
							Parent_size = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Parent_type) + ",_,_,\"user\",_,_,_,_,_)"), 3));
							Parent_kind = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Parent_type) + ",_,_,\"user\",_,_,_,_,_)"), 6));
							if (Parent_size >= Local_size)
							{
								if (Parent_kind != "single_t")
								{
									if (Parent_type < Type_number)
									{
										ss << "     long long int " << Local_name << " ;" << endl;
									}
								}
							}
						}
					}
					else if (Local_size == 1)
					{
						if (HT.findfact("type_def(_," + Type_name + ",_,_,_,_,_,_,_)"))
						{
							Type_size = stoi(returnpar(HT.findandreturn("type_def(_," + Type_name + ",_,_,_,_,_,_,_)"), 3));
							if (Type_size == 1)
							{
								ss << "     int " << Local_name << " ";
								ss << " ;" << endl;
							}
						}
					}
					else if (Type_name != "integer")
					{
						if (HT.findfact("type_def(_," + Type_name + ",_,_,2,_,_,_,_)"))
						{
							Type_size = stoi(returnpar(HT.findandreturn("type_def(_," + Type_name + ",_,_,2,_,_,_,_)"), 3));
							if (Type_size > 1)
							{
								ss << "     int " << Local_name << " ";
								ss << " ;" << endl;
							}
						}
						else if (HT.findfact("type_def(_," + Type_name + ",_,_,_,_,_,_,_)"))
						{
							Type_size = stoi(returnpar(HT.findandreturn("type_def(_," + Type_name + ",_,_,_,_,_,_,_)"), 3));
							if (Local_size != Type_size)
							{
								if (Type_size > 1)
								{
									ss << "     long long int " << Local_name << " ;" << endl;
								}
							}
							else
							{
								if (Type_size > 1)
								{
									ss << "     " << Type_name << " " << Local_name << " ";
									ss << " ;" << endl;
								}
							}
						}
					}
					else if (Type_name == "integer")
					{
						if (Local_size > 1)
						{
							ss << "     int " << Local_name << " ";
							ss << " ;" << endl;
						}
					}
				}
				else if (var7 == "userarray")
				{
					if (HT.findfact("type_def(_," + Type_name + ",_,_,_,_,_,_,2)"))
					{
						Type_size = stoi(returnpar(HT.findandreturn("type_def(_," + Type_name + ",_,_,_,_,_,_,2)"), 3));
						log2n(Type_size, 1, 1, 0);
						ss << "     " << Type_name << " *" << Local_name << " ;" << endl;
						ss << "     " << Local_name << " = (" << Type_name << "*) malloc(sizeof(" << Type_name << "));" << endl;
						ss << "     long long int " << Local_name << "_i ;" << endl;
					}
					else if (HT.findfact("type_def(_," + Type_name + ",_,_,_,_,_,_,_)"))
					{
						Type_size = stoi(returnpar(HT.findandreturn("type_def(_," + Type_name + ",_,_,_,_,_,_,_)"), 3));
						First_dim = stoi(returnpar(HT.findandreturn("type_def(_," + Type_name + ",_,_,_,_,_,_,_)"), 7));
						Num_dim = stoi(returnpar(HT.findandreturn("type_def(_," + Type_name + ",_,_,_,_,_,_,_)"), 8));
						Comp_type = stoi(returnpar(HT.findandreturn("type_def(_," + Type_name + ",_,_,_,_,_,_,_)"), 9));
						if (HT.findfact("type_def(" + to_string(Comp_type) + ",_,_,_,_,\"single_t\",_,_,2)"))
						{
							Comp_size = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Comp_type) + ",_,_,_,_,\"single_t\",_,_,2)"), 3));
							if (Comp_size > 1)
							{
								log2n(Type_size, 1, 1, 0); // for what? line: 15362
								ss << "     " << Type_name << " *" << Local_name << " ;" << endl;
								ss << "     " << Local_name << " = (" << Type_name << "*) malloc(sizeof(" << Type_name << "));" << endl;
								ss << "     long long int " << Local_name << "_i ;" << endl;
							}
						}
						else if (HT.findfact("type_def(" + to_string(Comp_type) + ",*)"))
						{
							Comp_size = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Comp_type) + ",*)"), 3));
							Comp_kind = returnpar(HT.findandreturn("type_def(" + to_string(Comp_type) + ",*)"), 6);
							if (Comp_size == 1)
							{
								Last_dim = Num_dim - 1;
								if (Last_dim > First_dim)
								{
									ss << "     " << Type_name << " *" << Local_name << " ;" << endl;
									ss << "     " << Local_name << " = (" << Type_name << "*) malloc(sizeof(" << Type_name << "));" << endl;
									ss << "     long long int " << Local_name << "_i ;" << endl;
								}
							}
							if (Comp_kind != "single_t")
							{
								if (Comp_size > 1)
								{
									ss << "     " << Type_name << " *" << Local_name << " ;" << endl;
									ss << "     " << Local_name << " = (" << Type_name << "*) malloc(sizeof(" << Type_name << "));" << endl;
									ss << "     long long int " << Local_name << "_i ;" << endl;
								}
							}
						}
					}
				}
				else if (var7 == "userrecord")
				{
					if (HT.findfact("type_def(_," + Type_name + "," + to_string(Local_size) + ",_,_,\"record_t\",0,_,_)"))
					{
						ss << "     " << Type_name << "  " << Local_name << " ;" << endl;
					}
				}
			}
			else if (var3 == "par_out")
			{
				if (be == "i")
					if (Type_name != "std_logic")
						ss << "     " << Type_name << "  " << Local_name << " ;" << endl;
			}
			else if (var3 == "par_inout")
			{
				if (be == "i")
					if (Type_name != "std_logic")
						ss << "     " << Type_name << "  " << Local_name << " ;" << endl;
					else
						ss << "     long long int   " << Local_name << " ;" << endl;
			}
			else if (var3 == "par_out")
			{
				if (be == "i")
					if (Type_name == "std_logic")
						ss << "     long long int   " << Local_name << " ;" << endl;
			}
			else if (var3 == "constant")
			{
				if (Type_name != "std_logic")
				{
					if (var5 != 0)
					{
						if (HT.findfact("type_def(_," + Type_name + ",_,_,_,_,_,_,_)"))
						{
							Type_number = stoi(returnpar(HT.findandreturn("type_def(_," + Type_name + ",_,_,_,_,_,_,_)"), 1));
							ss << "    const ";
							ss << write_type(Type_number);
							ss << Local_name << " = ";
							ss << type_value(Module, var5, "c");
							ss << " ;" << endl;
						}
					}
				}
				else if (Type_name == "bool")
				{
					if (HT.findfact("type_def(_,\"boolean\",_,_,_,_,_,_,_)"))
					{
						Type_number = stoi(returnpar(HT.findandreturn("type_def(_,\"boolean\",_,_,_,_,_,_,_)"), 1));
						ss << "    const int ";
						ss << Local_name << " = ";
						ss << type_value(Module, var5, "c");
						ss << " ;" << endl;
					}
				}
				else if (Type_name == "std_logic")
				{
					if (var5 != 0)
					{
						ss << "    const long long int ";
						ss << Local_name << " = ";
						ss << type_value(Module, var5, "c");
						ss << " ;" << endl;
					}
					else if (be == "i")
					{
						ss << "    const long long int ";
						ss << Local_name << " = " << af;
						ss << " ;" << endl;
					}
				}
			}
		}
	}
	return ss.str();
}

string write_value(string Local_value, int Local_size, string Type_name, string HDL, string Tool)
{
	stringstream ss;
	string be, af;
	int Upper_limit, Const_size;
	be = Local_value.substr(0, Local_value.find(pa, 0));
	af = Local_value.substr(be.length() + 1, Local_value.find(pacl, 0));
	af.resize(af.size() - 1);
	if (Tool == "synergy")
	{
		if (HDL == "vhdl")
		{
			if (Local_size == 1)
			{
				if (be == "bol")
				{
					if (af == "1")
						ss << " std_logic := '1' ; -- boolean value TRUE found";
					else if (af == "0")
						ss << " std_logic := '0' ; -- boolean value FALSE found";
				}
				else if (be == "i")
				{
					ss << " std_logic";
					ss << " := '" << af << "'";
					ss << ";  -- integer constants are converted into std_logic";
				}
			}
			else if (Local_size > 1)
			{
				ss << " std_logic_vector(";
				Upper_limit = Local_size - 1;
				ss << Upper_limit << " DOWNTO 0) := std_logic_vector(conv_unsigned(" << af;
				ss << ", " << Local_size << "));  -- integer constants are converted into std_logic";
			}
			else if (be == "chr")
			{
				ss << " character := std_logic_vector(conv_unsigned(" << af << " 8));  --ASCII code of a character value";
			}
			else if (be == "r")
			{
				ss << " real := " << af << ";  -- real values shouldn't be allowed in this version";
			}
			else if (be == "sym")
			{
				ss << " " << Type_name << " := " << af << ";";
			}
			else if (be == "str")
			{
				ss << " " << Type_name << " := " << af << ";  -- string values shouldn't allowed in this version";
			}
		}
		else if (HDL == "verilog")
		{
			if (Local_size == 1)
			{
				if (be == "bol")
				{
					if (af == "1")
						ss << "1'b1 ;";
					else if (af == "0")
						ss << "1'b0 ;";
				}
				else if (be == "i")
				{
					log2n(stoi(af), 1, 1, &Const_size);
					if (Const_size == 1)
					{
						ss << " 1'b";
						ss << af << ";";
					}
					else if (Const_size > 1)
						ss << " " << af << ";";
				}
			}
			else if (Local_size > 1)
			{
				ss << " " << af << ";";
			}
			else if (be == "chr")
			{
				ss << " " << af << ";";
			}
			else if (be == "r")
			{
				ss << " " << af << ";  // real values are not allowed in this version";
			}
			else if (be == "sym")
			{
				ss << " " << af << ";  // string names are not allowed as parameters";
			}
			else if (be == "str")
			{
				ss << " " << af << ";  // string values are not allowed in this version";
			}
		}
	}
	else if (Tool == "gnu")
	{
		if (be == "r")
			ss << " " << af << ";";
		else if (be == "chr")
			ss << " " << af << ";";
		else if (be == "i")
			ss << af << ";";
		else if (be == "bol")
			ss << " " << af << ";";
		else if (be == "str")
			ss << " " << af << ";  // string values are not allowed in this version";
	}
	return ss.str();
}

string write_type(int Type_number)
{
	stringstream ss;
	if (parent_type_is_integer(Type_number, 0))
		ss << " long long int ";
	else if (HT.findfact("type_def(" + to_string(Type_number) + ",*)"))
		ss << returnpar(HT.findandreturn("type_def(" + to_string(Type_number) + ",*)"), 2);
	return ss.str();
}

string write_standard_call_signals(string Schedule, string Module, int Call_entry)
{
	stringstream ss;
	int Called_module_entry, Next_entry;
	if (HT.findfact("call_stmt(" + Module + "," + to_string(Call_entry) + ",*)"))
	{
		Called_module_entry = stoi(returnpar(HT.findandreturn("call_stmt(" + Module + "," + to_string(Call_entry) + ",*)"), 3));
		ss << write_standard_signals_for_called_module(Schedule, Module, Call_entry, Called_module_entry);
		Next_entry = Call_entry + 1;
		ss << write_standard_call_signals(Schedule, Module, Next_entry);
	}
	return ss.str();
}

string write_standard_signals_for_called_module(string New_schedule, string Module, int Call_entry, int Called_module_entry)
{
	stringstream ss;
	string Called_module_name;
	int Max_order, Max_same;
	if (HT.findfact("added_aux_call_signals(" + Module + "," + to_string(Called_module_entry) + ")"))
		return ss.str();
	if (HT.findfact("hierarchy_part(" + to_string(Called_module_entry) + ",*)"))
	{
		Called_module_name = returnpar(HT.findandreturn("hierarchy_part(" + to_string(Called_module_entry) + ",*)"), 2);
		if (custom_block(Called_module_name))
			return ss.str();
	}
	if (New_schedule == "specials")
	{
		if (!HT.findfact("added_aux_call_signals(" + Module + "," + to_string(Called_module_entry) + ")"))
		{
			if (HT.findfact("hdl_style(\"vhdl\")"))
			{
				if (HT.findfact("hierarchy_part(" + to_string(Called_module_entry) + ",*)"))
				{
					Called_module_name = returnpar(HT.findandreturn("hierarchy_part(" + to_string(Called_module_entry) + ",*)"), 2);
					if (!custom_block(Called_module_name))
					{
						ss << "   SIGNAL " << Called_module_name << "_results_read_int :  std_logic;" << endl;
						ss << "   SIGNAL " << Called_module_name << "_start_int :  std_logic;" << endl;
						HT.assertz("added_aux_call_signals(" + Module + "," + to_string(Called_module_entry) + ")");
					}
				}
			}
			else if (HT.findfact("hdl_style(\"verilog\")"))
			{
				if (HT.findfact("hierarchy_part(" + to_string(Called_module_entry) + ",*)"))
				{
					Called_module_name = returnpar(HT.findandreturn("hierarchy_part(" + to_string(Called_module_entry) + ",*)"), 2);
					ss << "   reg " << Called_module_name << "_results_read_int ; " << endl;
					ss << "   reg " << Called_module_name << "_start_int ; " << endl;
					HT.assertz("added_aux_call_signals(" + Module + "," + to_string(Called_module_entry) + ")");
				}
			}
		}
	}
	else if (parcs_or_parcsif(New_schedule))
	{
		if (!HT.findfact("added_aux_call_signals(" + Module + "," + to_string(Called_module_entry) + ")"))
		{
			if (HT.findfact("hdl_style(\"vhdl\")"))
			{
				if (HT.findfact("hierarchy_part(" + to_string(Called_module_entry) + ",*)"))
				{
					Called_module_name = returnpar(HT.findandreturn("hierarchy_part(" + to_string(Called_module_entry) + ",*)"), 2);
					if (!custom_block(Called_module_name))
					{
						find_correct_order(Module, Call_entry, &Max_order);
						if (Max_order <= 1)
						{
							ss << "   SIGNAL " << Called_module_name << "_results_read_int :  std_logic;" << endl;
							ss << "   SIGNAL " << Called_module_name << "_start_int :  std_logic;" << endl;
							HT.assertz("added_aux_call_signals(" + Module + "," + to_string(Called_module_entry) + ")");
						}
						else if (Max_order > 1)
						{
							ss << "   SIGNAL ";
							ss << write_polymorfic_IO_exression(Module, "parcs", 0, Called_module_name, "results_read_int", 1, Max_order, "   SIGNAL ", "", " : std_logic;", 1, 0);
							ss << "   SIGNAL ";
							ss << write_polymorfic_IO_exression(Module, "parcs", 0, Called_module_name, "start_int", 1, Max_order, "   SIGNAL ", "", " : std_logic;", 1, 0);
							HT.assertz("added_aux_call_signals(" + Module + "," + to_string(Called_module_entry) + ")");
						}
					}
				}
			}
		}
		else if (HT.findfact("max_parallel_call_order(" + Module + "," + New_schedule + "," + to_string(Called_module_entry) + ",*)"))
		{
			Max_order = stoi(returnpar(HT.findandreturn("max_parallel_call_order(" + Module + "," + New_schedule + "," + to_string(Called_module_entry) + ",*)"), 4));
			if (Max_order == 1)
			{
				if (!HT.findfact("added_aux_call_signals(" + Module + "," + to_string(Called_module_entry) + ")"))
				{
					if (HT.findfact("hdl_style(\"vhdl\")"))
					{
						if (HT.findfact("hierarchy_part(" + to_string(Called_module_entry) + ",*)"))
						{
							Called_module_name = returnpar(HT.findandreturn("hierarchy_part(" + to_string(Called_module_entry) + ",*)"), 2);
							if (!custom_block(Called_module_name))
							{
								ss << "   SIGNAL " << Called_module_name << "_results_read_int : std_logic;" << endl;
								ss << "   SIGNAL " << Called_module_name << "_start_int : std_logic;" << endl;
								HT.assertz("added_aux_call_signals(" + Module + "," + to_string(Called_module_entry) + ")");
							}
						}
					}
					else if (HT.findfact("hdl_style(\"verilog\")"))
					{
						if (HT.findfact("hierarchy_part(" + to_string(Called_module_entry) + ",*)"))
						{
							Called_module_name = returnpar(HT.findandreturn("hierarchy_part(" + to_string(Called_module_entry) + ",*)"), 2);
							if (!custom_block(Called_module_name))
							{
								ss << "   reg " << Called_module_name << "_results_read_int ; " << endl;
								ss << "   reg " << Called_module_name << "_start_int ; " << endl;
								HT.assertz("added_aux_call_signals(" + Module + "," + to_string(Called_module_entry) + ")");
							}
						}
					}
				}
			}
			else if (Max_order > 1)
			{
				if (!HT.findfact("added_aux_call_signals(" + Module + "," + to_string(Called_module_entry) + ")"))
				{
					if (HT.findfact("hdl_style(\"vhdl\")"))
					{
						if (HT.findfact("hierarchy_part(" + to_string(Called_module_entry) + ",*)"))
						{
							Called_module_name = returnpar(HT.findandreturn("hierarchy_part(" + to_string(Called_module_entry) + ",*)"), 2);
							if (!custom_block(Called_module_name))
							{
								ss << "   SIGNAL ";
								ss << write_polymorfic_IO_exression(Module, "parcs", 0, Called_module_name, "results_read_int", 1, Max_order, "   SIGNAL ", "", " : std_logic;", 1, 0);
								ss << "   SIGNAL ";
								ss << write_polymorfic_IO_exression(Module, "parcs", 0, Called_module_name, "start_int", 1, Max_order, "   SIGNAL ", "", " : std_logic;", 1, 0);
								HT.assertz("added_aux_call_signals(" + Module + "," + to_string(Called_module_entry) + ")");
							}
						}
					}
					else if (HT.findfact("hdl_style(\"verilog\")"))
					{
						if (HT.findfact("hierarchy_part(" + to_string(Called_module_entry) + ",*)"))
						{
							Called_module_name = returnpar(HT.findandreturn("hierarchy_part(Called_module_entry,*)"), 2);
							if (!custom_block(Called_module_name))
							{
								ss << "   reg ";
								ss << write_polymorfic_IO_exression(Module, "parcs", 0, Called_module_name, "results_read_int", 1, Max_order, "   reg ", "", " ;", 1, 0);
								ss << "   reg ";
								ss << write_polymorfic_IO_exression(Module, "parcs", 0, Called_module_name, "start_int", 1, Max_order, "   reg ", "", " ;", 1, 0);
								HT.assertz("added_aux_call_signals(" + Module + "," + to_string(Called_module_entry) + ")");
							}
						}
					}
				}
			}
		}
	}
	else if (HT.findfact("hdl_style(\"vhdl\")"))
	{
		if (parcs_or_parcsif(New_schedule))
		{
			if (HT.findfact("totalmax_call_order(" + Module + ",\"parcsif\",*)"))
			{
				Max_order = stoi(returnpar(HT.findandreturn("totalmax_call_order(" + Module + ",\"parcsif\",*)"), 3));
				if (Max_order == 1)
				{
					if (!HT.findfact("added_aux_call_signals(" + Module + "," + to_string(Called_module_entry) + ")"))
					{
						if (HT.findfact("hdl_style(\"vhdl\")"))
						{
							if (HT.findfact("hierarchy_part(" + to_string(Called_module_entry) + ",*)"))
							{
								Called_module_name = returnpar(HT.findandreturn("hierarchy_part(" + to_string(Called_module_entry) + ",*)"), 2);
								if (!custom_block(Called_module_name))
								{
									ss << "   SIGNAL " << Called_module_name << "_results_read_int : std_logic;" << endl;
									ss << "   SIGNAL " << Called_module_name << "_start_int : std_logic;" << endl;
									HT.assertz("added_aux_call_signals(" + Module + "," + to_string(Called_module_entry) + ")");
								}
							}
						}
					}
				}
				else if (Max_order > 1)
				{
					if (HT.findfact("operation_order(" + Module + "," + New_schedule + ",_,_," + to_string(Called_module_entry) + ",_,_,_,_,_,_)"))
					{
						Max_same = stoi(returnpar(HT.findandreturn("operation_order(" + Module + "," + New_schedule + ",_,_," + to_string(Called_module_entry) + ",_,_,_,_,_,_)"), 7));
						if (Max_same == 1)
						{
							if (!HT.findfact("added_aux_call_signals(" + Module + "," + to_string(Called_module_entry) + ")"))
							{
								if (HT.findfact("hdl_style(\"vhdl\")"))
								{
									if (HT.findfact("hierarchy_part(" + to_string(Called_module_entry) + ",*)"))
									{
										Called_module_name = returnpar(HT.findandreturn("hierarchy_part(" + to_string(Called_module_entry) + ",*)"), 2);
										if (!custom_block(Called_module_name))
										{
											ss << "   SIGNAL " << Called_module_name << "_results_read_int : std_logic;" << endl;
											ss << "   SIGNAL " << Called_module_name << "_start_int : std_logic;" << endl;
											HT.assertz("added_aux_call_signals(" + Module + "," + to_string(Called_module_entry) + ")");
										}
									}
								}
							}
						}
						else if (Max_same > 1)
						{
							if (Max_same <= Max_order)
							{
								if (!HT.findfact("added_aux_call_signals(" + Module + "," + to_string(Called_module_entry) + ")"))
								{
									if (HT.findfact("hdl_style(\"vhdl\")"))
									{
										if (HT.findfact("hierarchy_part(" + to_string(Called_module_entry) + ",*)"))
										{
											Called_module_name = returnpar(HT.findandreturn("hierarchy_part(" + to_string(Called_module_entry) + ",*)"), 2);
											if (!custom_block(Called_module_name))
											{
												ss << "   SIGNAL ";
												ss << write_polymorfic_IO_exression(Module, "parcs", 0, Called_module_name, "results_read_int", 1, Max_same, "   SIGNAL ", "", " : std_logic;", 1, 0);
												ss << "   SIGNAL ";
												ss << write_polymorfic_IO_exression(Module, "parcs", 0, Called_module_name, "start_int", 1, Max_same, "   SIGNAL ", "", " : std_logic;", 1, 0);
												HT.assertz("added_aux_call_signals(" + Module + "," + to_string(Called_module_entry) + ")");
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
	return ss.str();
}

void find_correct_order(string Module, int Call_entry, int* MaxOrder)
{
	int Called_module_entry, TM1, TM2, TM3, MAX1, MAX2;
	string Called_module_name;
	if (HT.findfact("call_stmt(" + Module + "," + to_string(Call_entry) + ",*)"))
	{
		Called_module_entry = stoi(returnpar(HT.findandreturn("call_stmt(" + Module + "," + to_string(Call_entry) + ",*)"), 3));
		if (HT.findfact("hierarchy_part(" + to_string(Called_module_entry) + ",*)"))
		{
			Called_module_name = returnpar(HT.findandreturn("hierarchy_part(" + to_string(Called_module_entry) + ",*)"), 3);
			if (!custom_block(Called_module_name))
			{
				if (HT.findfact("max_parallel_call_order(" + Module + ",\"parcsif\",*)"))
				{
					TM1 = stoi(returnpar(HT.findandreturn("max_parallel_call_order(" + Module + ",\"parcsif\",*)"), 4));
					if (HT.findfact("max_op_order(" + Module + ",\"parcsif\",*)"))
					{
						TM2 = stoi(returnpar(HT.findandreturn("max_op_order(" + Module + ",\"parcsif\",*)"), 3));
						if (HT.findfact("totalmax_call_order(" + Module + ",\"parcsif\",*)"))
						{
							TM3 = stoi(returnpar(HT.findandreturn("totalmax_call_order(" + Module + ",\"parcsif\",*)"), 3));
							max_(TM1, TM2, &MAX1);
							max_(MAX1, TM3, &MAX2);
							find_correct_max_call_order(Module, Called_module_entry, MAX2, MaxOrder);
						}
						else if (!HT.findfact("totalmax_call_order(" + Module + ",\"parcsif\",*)"))
						{
							max_(TM1, TM2, &MAX2);
							find_correct_max_call_order(Module, Called_module_entry, MAX2, MaxOrder);
						}
					}
					else if (!HT.findfact("max_op_order(" + Module + ",\"parcsif\",*)"))
					{
						if (HT.findfact("totalmax_call_order(" + Module + ",\"parcsif\",*)"))
						{
							TM3 = stoi(returnpar(HT.findandreturn("totalmax_call_order(" + Module + ",\"parcsif\",*)"), 3));
							max_(TM1, TM3, &MAX2);
							find_correct_max_call_order(Module, Called_module_entry, MAX2, MaxOrder);
						}
						else if (!HT.findfact("totalmax_call_order(" + Module + ",\"parcsif\",*)"))
						{
							find_correct_max_call_order(Module, Called_module_entry, TM1, MaxOrder);
						}
					}
				}
				else if (!HT.findfact("max_parallel_call_order(" + Module + ",\"parcsif\",*)"))
				{
					if (HT.findfact("max_op_order(" + Module + ",\"parcsif\",*)"))
					{
						TM2 = stoi(returnpar(HT.findandreturn("max_op_order(" + Module + ",\"parcsif\",*)"), 3));
						if (HT.findfact("totalmax_call_order(" + Module + ",\"parcsif\",*)"))
						{
							TM3 = stoi(returnpar(HT.findandreturn("totalmax_call_order(" + Module + ",\"parcsif\",*)"), 3));
							max_(TM2, TM3, &MAX2);
							find_correct_max_call_order(Module, Called_module_entry, MAX2, MaxOrder);
						}
						else if (!HT.findfact("totalmax_call_order(" + Module + ",\"parcsif\",*)"))
						{
							find_correct_max_call_order(Module, Called_module_entry, TM2, MaxOrder);
						}
					}
					else if (!HT.findfact("max_op_order(" + Module + ",\"parcsif\",*)"))
					{
						if (HT.findfact("totalmax_call_order(" + Module + ",\"parcsif\",*)"))
						{
							TM3 = stoi(returnpar(HT.findandreturn("totalmax_call_order(" + Module + ",\"parcsif\",*)"), 3));
							find_correct_max_call_order(Module, Called_module_entry, TM3, MaxOrder);
						}
						else if (!HT.findfact("totalmax_call_order(" + Module + ",\"parcsif\",*)"))
						{
							*MaxOrder = 1;
						}
					}
				}
			}
		}
	}
}

void max_(int A, int B, int* C)
{
	if (A >= B)
		*C = A;
	else
		*C = B;
}

string write_dp_signal_declarations()
{
	stringstream ss;
	if (!HT.findfact("massively_parallel_style(1)"))
	{
		if (HT.findfact("hdl_style(\"vhdl\")"))
		{
			if (!HT.findfact("massively_parallel_style(*)"))
			{
				ss << endl;
				ss << "     -- now the datapath (input/output) signal declarations follow --" << endl << endl;
				ss << write_datapath_signals(1);

			}
		}
		else if (HT.findfact("hdl_style(\"verilog\")"))
		{
			if (!HT.findfact("massively_parallel_style(*)"))
			{
				ss << endl;
				ss << "   /*-- now the datapath (input/output) signal declarations follow --*/" << endl << endl;
				ss << write_datapath_signals(1);
			}
		}
	}
	return ss.str();
}

string write_datapath_signals(int Op_entry)
{
	stringstream ss;
	int Next_entry;
	if (!HT.findfact("massively_parallel_style(1)") || HT.findfact("op_instance(" + to_string(Op_entry) + ",*)"))
	{
		ss << write_datapath_signals_core(Op_entry, &Next_entry);
		ss << write_datapath_signals(Next_entry);
	}
	return ss.str();
}

string write_datapath_signals_core(int Op_entry, int* Next_entry)
{
	stringstream ss;
	int Operator, OType, OSize, Parent_type, In1Type, In2Type, Dtype, Type_size, IN1T, IN2T, OT, Osize, In1size, In2size, OSize1,
		OutputType, Op_size;
	string Op_instance, Output_instance, In1_instance, In2_instance, Outtypename, In1typename, In2typename, Output_name, Module_name,
		Op_name, Opsymbol, Ouput_name, Module;
	if (HT.findfact("op_instance(" + to_string(Op_entry) + ",*)"))
	{
		Op_name = returnpar(HT.findandreturn("op_instance(" + to_string(Op_entry) + ",*)"), 2);
		Operator = stoi(returnpar(HT.findandreturn("op_instance(" + to_string(Op_entry) + ",*)"), 3));
		Op_size = stoi(returnpar(HT.findandreturn("op_instance(" + to_string(Op_entry) + ",*)"), 4));
		Op_instance = returnpar(HT.findandreturn("op_instance(" + to_string(Op_entry) + ",*)"), 5);
		if (out_of_types_op(Operator))
		{
			if (out_of_logical_op(Operator))
			{
				if (HT.findfact("op_def(" + to_string(Operator) + ",_,\"binop\",_,_,_,_)"))
				{
					HT.concat(Op_instance, "_out", &Output_instance);
					HT.concat(Op_instance, "_in1", &In1_instance);
					HT.concat(Op_instance, "_in2", &In2_instance);
					if (HT.findfact("output_instance(_,_,_," + Output_instance + ",_,_)"))
					{
						Output_name = returnpar(HT.findandreturn("output_instance(_,_,_," + Output_instance + ",_,_)"), 3);
						OType = stoi(returnpar(HT.findandreturn("output_instance(_,_,_," + Output_instance + ",_,_)"), 5));
						OSize = stoi(returnpar(HT.findandreturn("output_instance(_,_,_," + Output_instance + ",_,_)"), 6));
						if (OSize > 0)
						{
							if (OType >= 0)
							{
								if (OType > 10)
								{
									if (HT.findfact("type_def(" + to_string(OType) + ",_,_,\"user\",_,_,_,_,_)"))
									{
										Outtypename = returnpar(HT.findandreturn("type_def(" + to_string(OType) + ",_,_,\"user\",_,_,_,_,_)"), 2);
										Parent_type = stoi(returnpar(HT.findandreturn("type_def(" + to_string(OType) + ",_,_,\"user\",_,_,_,_,_)"), 5));
										if (out_of_standard_types(Parent_type))
										{
											ss << "   SIGNAL " << Output_instance << " : " << Outtypename << ";" << endl;
											if (HT.findfact("signal_instance(*)"))
											{
												In1Type = stoi(returnpar(HT.findandreturn("signal_instance(*)"), 5));
												if (HT.findfact("type_def(" + to_string(In1Type) + ",*)"))
												{
													In1typename = returnpar(HT.findandreturn("type_def(" + to_string(In1Type) + ",*)"), 2);
													ss << "   SIGNAL " << In1_instance << " : " << In1typename << ";" << endl;
													if (HT.findfact("signal_instance(*)"))
													{
														In2Type = stoi(returnpar(HT.findandreturn("signal_instance(*)"), 5));
														if (HT.findfact("type_def(" + to_string(In2Type) + ",*)"))
														{
															In2typename = returnpar(HT.findandreturn("type_def(" + to_string(In2Type) + ",*)"), 2);
															ss << "   SIGNAL " << In2_instance << " : " << In2typename << ";" << endl;
															*Next_entry = Op_entry + 1;
														}
													}
												}
											}
										}
										else if (Parent_type >= 1)
										{
											if (Parent_type <= 10)
											{
												if (HT.findfact("signal_instance(*)"))
												{
													declare_output_signal(Output_instance, OSize);
													declare_input_signal(In1_instance, OSize);
													declare_input_signal(In2_instance, OSize);
													*Next_entry = Op_entry + 1;
												}
											}
										}
									}
								}
								else if (OType <= 10)
								{
									if (HT.findfact("signal_instance(*)"))
									{
										ss << declare_output_signal(Output_instance, OSize);
										ss << declare_input_signal(In1_instance, OSize);
										ss << declare_input_signal(In2_instance, OSize);
										*Next_entry = Op_entry + 1;
									}
								}
							}
						}
						else if (OSize == 0)
						{
							if (HT.findfact("current_module(*)"))
							{
								Module_name = returnpar(HT.findandreturn("current_module(*)"), 1);
								if (HT.findfact("data_stmt(" + Module_name + "," + Output_name + ",_,_,_,_)"))
								{
									Dtype = stoi(returnpar(HT.findandreturn("current_module(*)"), 4));
									if (HT.findfact("type_def(" + to_string(Dtype) + ",*)"))
									{
										Type_size = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Dtype) + ",*)"), 3));
										if (HT.findfact("signal_instance(*)"))
										{
											ss << declare_output_signal(Output_instance, Type_size);
											ss << declare_input_signal(In1_instance, Type_size);
											ss << declare_input_signal(In2_instance, Type_size);
											*Next_entry = Op_entry + 1;
										}
									}
								}
							}
						}
					}
				}
			}
		}
		else if (Operator > 0)
		{
			if (Operator >= 7)
			{
				if (Operator <= 9)
				{
					if (HT.findfact("op_def(" + to_string(Operator) + ",_,\"binop\",_,_,_,_)"))
					{
						HT.concat(Op_instance, "_out", &Output_instance);
						if (HT.findfact("output_instance(_,_,_," + Output_instance + ",_,_)"))
						{
							Ouput_name = returnpar(HT.findandreturn("output_instance(_,_,_," + Output_instance + ",_,_)"), 3);
							OutputType = stoi(returnpar(HT.findandreturn("output_instance(_,_,_," + Output_instance + ",_,_)"), 5));
							if (HT.findfact("current_module(*)"))
							{
								Module = returnpar(HT.findandreturn("current_module(*)"), 1);
								if (HT.findfact("data_stmt(" + Module + "," + Ouput_name + ",*)"))
								{
									OT = stoi(returnpar(HT.findandreturn("data_stmt(" + Module + "," + Ouput_name + ",*)"), 4));
									if (HT.findfact("type_def(" + to_string(OutputType) + ",*)"))
									{
										Osize = stoi(returnpar(HT.findandreturn("type_def(" + to_string(OutputType) + ",*)"), 3));
										HT.concat(Op_instance, "_in1", &In1_instance);
										HT.concat(Op_instance, "_in2", &In2_instance);
										ss << declare_output_signal(Output_instance, Osize);
										ss << declare_input_signal(In1_instance, Osize);
										ss << declare_input_signal(In2_instance, Osize);
										*Next_entry = Op_entry + 1;
									}
								}
							}
						}
					}
				}
			}
			else if (Operator == 10)
			{
				if (HT.findfact("op_def(" + to_string(Operator) + ",_,\"unop\",_,_,_,_)"))
				{
					HT.concat(Op_instance, "_out", &Output_instance);
					if (HT.findfact("output_instance(_,_,_," + Output_instance + ",_,_)"))
					{
						Ouput_name = returnpar(HT.findandreturn("output_instance(_,_,_," + Output_instance + ",_,_)"), 3);
						if (HT.findfact("current_module(*)"))
						{
							Module = returnpar(HT.findandreturn("current_module(*)"), 1);
							if (HT.findfact("data_stmt(" + Module + "," + Ouput_name + ",*)"))
							{
								OT = stoi(returnpar(HT.findandreturn("data_stmt(" + Module + "," + Ouput_name + ",*)"), 4));
								if (HT.findfact("type_def(" + to_string(OT) + ",*)"))
								{
									Osize = stoi(returnpar(HT.findandreturn("type_def(" + to_string(OT) + ",*)"), 3));
									HT.concat(Op_instance, "_in2", &In2_instance);
									ss << declare_output_signal(Output_instance, Osize);
									ss << declare_input_signal(In2_instance, Osize);
									*Next_entry = Op_entry + 1;
								}
							}
						}
					}
				}
			}
			else if (Op_name != "mod")
			{
				if (!out_of_types_op(Operator))
				{
					if (out_of_logical_op(Operator))
					{
						if (HT.findfact("op_def(" + to_string(Operator) + ",_,\"binop\",_,_,_,_)"))
						{
							IN1T = stoi(returnpar(HT.findandreturn("op_def(" + to_string(Operator) + ",_,\"binop\",_,_,_,_)"), 4));
							IN2T = stoi(returnpar(HT.findandreturn("op_def(" + to_string(Operator) + ",_,\"binop\",_,_,_,_)"), 5));
							OT = stoi(returnpar(HT.findandreturn("op_def(" + to_string(Operator) + ",_,\"binop\",_,_,_,_)"), 6));
							if (HT.findfact("type_def(" + to_string(OT) + ",*)"))
							{
								Osize = stoi(returnpar(HT.findandreturn("type_def(" + to_string(OT) + ",*)"), 3));
								if (HT.findfact("type_def(" + to_string(IN1T) + ",*)"))
								{
									In1size = stoi(returnpar(HT.findandreturn("type_def(" + to_string(IN1T) + ",*)"), 3));
									if (HT.findfact("type_def(" + to_string(IN2T) + ",*)"))
									{
										In2size = stoi(returnpar(HT.findandreturn("type_def(" + to_string(IN2T) + ",*)"), 3));
										HT.concat(Op_instance, "_out", &Output_instance);
										HT.concat(Op_instance, "_in1", &In1_instance);
										HT.concat(Op_instance, "_in2", &In2_instance);
										ss << declare_output_signal(Output_instance, Osize);
										ss << declare_input_signal(In1_instance, In1size);
										ss << declare_input_signal(In2_instance, In2size);
										*Next_entry = Op_entry + 1;
									}
								}
							}
						}
					}
				}
			}
			else if (Op_name == "mod")
			{
				if (HT.findfact("op_def(" + to_string(Operator) + ",\"mod\",\"binop\",_,_,_,_)"))
				{
					IN1T = stoi(returnpar(HT.findandreturn("op_def(" + to_string(Operator) + ",\"mod\",\"binop\",_,_,_,_)"), 4));
					IN2T = stoi(returnpar(HT.findandreturn("op_def(" + to_string(Operator) + ",\"mod\",\"binop\",_,_,_,_)"), 5));
					OT = stoi(returnpar(HT.findandreturn("op_def(" + to_string(Operator) + ",\"mod\",\"binop\",_,_,_,_)"), 6));
					if (HT.findfact("type_def(" + to_string(OT) + ",*)"))
					{
						Osize = stoi(returnpar(HT.findandreturn("type_def(" + to_string(OT) + ",*)"), 3));
						if (HT.findfact("type_def(" + to_string(IN1T) + ",*)"))
						{
							In1size = stoi(returnpar(HT.findandreturn("type_def(" + to_string(IN1T) + ",*)"), 3));
							if (HT.findfact("type_def(" + to_string(IN2T) + ",*)"))
							{
								In2size = stoi(returnpar(HT.findandreturn("type_def(" + to_string(IN2T) + ",*)"), 3));
								HT.concat(Op_instance, "_out", &Output_instance);
								HT.concat(Op_instance, "_in1", &In1_instance);
								HT.concat(Op_instance, "_in2", &In2_instance);
								if (HT.findfact("output_instance(_,_,_," + Output_instance + ",_,_)"))
								{
									OSize1 = stoi(returnpar(HT.findandreturn("output_instance(_,_,_," + Output_instance + ",_,_)"), 3));
									ss << declare_output_signal(Output_instance, OSize1);
									ss << declare_input_signal(In1_instance, In1size);
									ss << declare_input_signal(In2_instance, In2size);
									*Next_entry = Op_entry + 1;
								}
							}
						}
					}
				}
			}
			else if (!out_of_types_op(Operator))
			{
				if (out_of_logical_op(Operator))
				{
					if (HT.findfact("op_def(" + to_string(Operator) + ",\"-\",\"unop\",_,_,_,_)"))
					{
						IN1T = stoi(returnpar(HT.findandreturn("op_def(" + to_string(Operator) + ",\"-\",\"unop\",_,_,_,_)"), 4));
						IN2T = stoi(returnpar(HT.findandreturn("op_def(" + to_string(Operator) + ",\"-\",\"unop\",_,_,_,_)"), 5));
						OT = stoi(returnpar(HT.findandreturn("op_def(" + to_string(Operator) + ",\"-\",\"unop\",_,_,_,_)"), 6));
						if (HT.findfact("type_def(" + to_string(OT) + ",*)"))
						{
							Osize = stoi(returnpar(HT.findandreturn("type_def(" + to_string(OT) + ",*)"), 3));
							if (HT.findfact("type_def(" + to_string(IN2T) + ",*)"))
							{
								In2size = stoi(returnpar(HT.findandreturn("type_def(" + to_string(IN2T) + ",*)"), 3));
								HT.concat(Op_instance, "_out", &Output_instance);
								HT.concat(Op_instance, "_in1", &In1_instance);
								HT.concat(Op_instance, "_in2", &In2_instance);
								ss << declare_output_signal(Output_instance, Osize);
								ss << declare_input_signal(In1_instance, In2size);
								ss << declare_input_signal(In2_instance, In2size);
								*Next_entry = Op_entry + 1;
							}
						}
					}
					else if (HT.findfact("op_def(" + to_string(Operator) + ",_,\"unop\",_,_,_,_)"))
					{
						Opsymbol = returnpar(HT.findandreturn("op_def(" + to_string(Operator) + ",_,\"unop\",_,_,_,_)"), 2);
						IN1T = stoi(returnpar(HT.findandreturn("op_def(" + to_string(Operator) + ",_,\"unop\",_,_,_,_)"), 4));
						IN2T = stoi(returnpar(HT.findandreturn("op_def(" + to_string(Operator) + ",_,\"unop\",_,_,_,_)"), 5));
						OT = stoi(returnpar(HT.findandreturn("op_def(" + to_string(Operator) + ",_,\"unop\",_,_,_,_)"), 6));
						if (Opsymbol != "-")
						{
							if (HT.findfact("type_def(" + to_string(OT) + ",*)"))
							{
								Osize = stoi(returnpar(HT.findandreturn("type_def(" + to_string(OT) + ",*)"), 3));
								if (HT.findfact("type_def(" + to_string(IN2T) + ",*)"))
								{
									In2size = stoi(returnpar(HT.findandreturn("type_def(" + to_string(IN2T) + ",*)"), 3));
									HT.concat(Op_instance, "_out", &Output_instance);
									HT.concat(Op_instance, "_in1", &In1_instance);
									HT.concat(Op_instance, "_in2", &In2_instance);
									ss << declare_output_signal(Output_instance, Osize);
									ss << declare_input_signal(In2_instance, In2size);
									*Next_entry = Op_entry + 1;
								}
							}
						}
					}
					else if (HT.findfact("op_def(" + to_string(Operator) + ",_,\"binop\",_,_,_,_)"))
					{
						HT.concat(Op_instance, "_out", &Output_instance);
						if (HT.findfact("output_instance(_,_,_," + Output_instance + ",_,_)"))
						{
							Ouput_name = returnpar(HT.findandreturn("output_instance(_,_,_," + Output_instance + ",_,_)"), 3);
							if (HT.findfact("current_module(*)"))
							{
								Module = returnpar(HT.findandreturn("current_module(*)"), 1);
								if (HT.findfact("data_stmt(" + Module + "," + Ouput_name + ",*)"))
								{
									OT = stoi(returnpar(HT.findandreturn("current_module(*)"), 3));
									if (HT.findfact("type_def(OT,*)"))
									{
										Osize = stoi(returnpar(HT.findandreturn("type_def(OT,*)"), 3));
										HT.concat(Op_instance, "_in1", &In1_instance);
										HT.concat(Op_instance, "_in2", &In2_instance);
										ss << declare_output_signal(Output_instance, Osize);
										ss << declare_input_signal(In1_instance, Osize);
										ss << declare_input_signal(In2_instance, Osize);
										*Next_entry = Op_entry + 1;
									}
								}
							}
						}
					}
				}
			}
		}
		else if (Operator <= 0)
		{
			HT.concat(Op_instance, "_out", &Output_instance);
			HT.concat(Op_instance, "_in1", &In1_instance);
			HT.concat(Op_instance, "_in2", &In2_instance);
			ss << declare_output_signal(Output_instance, Op_size);
			ss << declare_input_signal(In1_instance, Op_size);
			ss << declare_input_signal(In2_instance, Op_size);
			*Next_entry = Op_entry + 1;
		}
	}
	else if (HT.findfact("prog_stmt(_," + to_string(Op_entry) + ",_,_,_,_,_,_)"))
	{
		Module = returnpar(HT.findandreturn("prog_stmt(_," + to_string(Op_entry) + ",_,_,_,_,_,_)"), 1);
		Operator = stoi(returnpar(HT.findandreturn("prog_stmt(_," + to_string(Op_entry) + ",_,_,_,_,_,_)"), 4));
		if (HT.findfact("op_instance(_,_," + to_string(Operator) + ",_,_)"))
		{
			Op_instance = returnpar(HT.findandreturn("op_instance(_,_," + to_string(Operator) + ",_,_)"), 5);
			if (Operator > 0)
			{
				if (!out_of_types_op(Operator))
				{
					if (out_of_logical_op(Operator))
					{
						if (HT.findfact("op_def(" + to_string(Operator) + ",_,\"binop\",_,_,_,_)"))
						{
							HT.concat(Op_instance, "_out", &Output_instance);
							if (HT.findfact("output_instance(_,_,_," + Output_instance + ",_,_)"))
							{
								Ouput_name = stoi(returnpar(HT.findandreturn("output_instance(_,_,_," + Output_instance + ",_,_)"), 3));
								if (HT.findfact("current_module(*)"))
								{
									Module = returnpar(HT.findandreturn("current_module(*)"), 1);
									if (HT.findfact("data_stmt(" + Module + "," + Ouput_name + ",*)"))
									{
										OT = stoi(returnpar(HT.findandreturn("current_module(*)"), 3));
										if (HT.findfact("type_def(OT,*)"))
										{
											Osize = stoi(returnpar(HT.findandreturn("type_def(OT,*)"), 3));
											HT.concat(Op_instance, "_in1", &In1_instance);
											HT.concat(Op_instance, "_in2", &In2_instance);
											ss << declare_output_signal(Output_instance, Osize);
											ss << declare_input_signal(In1_instance, Osize);
											ss << declare_input_signal(In2_instance, Osize);
											*Next_entry = Op_entry + 1;
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
	return ss.str();
}

bool out_of_types_op(int Operator)
{
	return Operator == 102 || Operator == 103 || Operator == 104 || Operator == 105;
}

bool out_of_logical_op(int Operator)
{
	return Operator != 7 && Operator != 8 && Operator != 9 && Operator != 10;
}

string declare_output_signal(string Output_instance, int Size)
{
	stringstream ss;
	int Upper, Type, Size_;
	if (Size == 1)
	{
		if (HT.findfact("current_hdl_style(\"vhdl\")"))
		{
			if (HT.findfact("output_instance(_,_,_," + Output_instance + ",_,_)"))
			{
				Type = stoi(returnpar(HT.findandreturn("output_instance(_,_,_," + Output_instance + ",_,_)"), 5));
				if (Type > 1)
				{
					ss << write_signal_declaration(Output_instance, 0, 1);
				}
				else if (Type == 1)
				{
					ss << "   SIGNAL " << Output_instance << " : std_logic;" << endl;
				}
			}
		}
		else if (HT.findfact("current_hdl_style(\"verilog\")"))
		{
			if (HT.findfact("output_instance(_,_,_," + Output_instance + ",_,_)"))
			{
				Type = stoi(returnpar(HT.findandreturn("output_instance(_,_,_," + Output_instance + ",_,_)"), 5));
				if (Type > 1)
				{
					ss << write_signal_declaration(Output_instance, 0, 1);
				}
				else if (Type == 1)
				{
					ss << "   reg " << Output_instance << " ;" << endl;
				}
			}
		}
	}
	else if (Size == 0)
	{
		if (HT.findfact("current_hdl_style(\"vhdl\")"))
		{
			if (HT.findfact("output_instance(_,_,_," + Output_instance + ",_,_)"))
			{
				Type = stoi(returnpar(HT.findandreturn("output_instance(_,_,_," + Output_instance + ",_,_)"), 5));
				Size_ = stoi(returnpar(HT.findandreturn("output_instance(_,_,_," + Output_instance + ",_,_)"), 6));
				if (Size != 0)
				{
					if (Type == 1)
					{
						ss << "   SIGNAL " << Output_instance << " : std_logic;" << endl;
					}
					else if (Type != 1)
					{
						ss << write_signal_declaration(Output_instance, 0, Size_);
					}
				}
			}
			else if (HT.findfact("output_instance(_,_,_," + Output_instance + ",_,0)"))
			{
				Type = stoi(returnpar(HT.findandreturn("output_instance(_,_,_," + Output_instance + ",_,0)"), 5));
				if (HT.findfact("type_def(" + to_string(Type) + ",*)"))
				{
					Size_ = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Type) + ",*)"), 3));
					ss << write_signal_declaration(Output_instance, 0, Size_);
				}
			}
		}
		else if (HT.findfact("current_hdl_style(\"verilog\")"))
		{
			if (HT.findfact("output_instance(_,_,_," + Output_instance + ",_,_)"))
			{
				Type = stoi(returnpar(HT.findandreturn("output_instance(_,_,_," + Output_instance + ",_,_)"), 5));
				Size_ = stoi(returnpar(HT.findandreturn("output_instance(_,_,_," + Output_instance + ",_,_)"), 6));
				if (Size != 0)
				{
					if (Type == 1)
					{
						ss << "   reg " << Output_instance << " ;" << endl;
					}
					else if (Type != 1)
					{
						ss << write_signal_declaration(Output_instance, 0, Size);
					}
				}
			}
			else if (HT.findfact("output_instance(_,_,_," + Output_instance + ",_,0)"))
			{
				Type = stoi(returnpar(HT.findandreturn("output_instance(_,_,_," + Output_instance + ",_,0)"), 5));
				if (HT.findfact("type_def(" + to_string(Type) + ",*)"))
				{
					Size_ = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Type) + ",*)"), 3));
					ss << write_signal_declaration(Output_instance, 0, Size_);
				}
			}
		}
	}
	else if (HT.findfact("current_hdl_style(\"vhdl\")"))
	{
		if (Size > 1)
		{
			Upper = Size - 1;
			ss << "   SIGNAL " << Output_instance << " : std_logic_vector(" << Upper << " DOWNTO 0);" << endl;
		}
	}
	else if (HT.findfact("current_hdl_style(\"verilog\")"))
	{
		if (Size > 1)
		{
			Upper = Size - 1;
			ss << "   reg [" << Upper << ":0] " << Output_instance << ";" << endl;
		}
	}
	return ss.str();
}

string write_signal_declaration(string Instance, int Type, int Size)
{
	stringstream ss;
	int Upper_bound, Size_;
	if (Size == 1)
	{
		if (HT.findfact("hdl_style(\"vhdl\")"))
		{
			if (Type != 0)
			{
				if (Type != 1)
				{
					if (HT.findfact("type_def(" + to_string(Type) + ",*)"))
					{
						Size_ = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Type) + ",*)"), 3));
						if (Size_ == 1)
						{
							ss << "   SIGNAL " << Instance << " : std_logic;" << endl;
						}
					}
				}
			}
		}
	}
	else if (HT.findfact("hdl_style(\"vhdl\")"))
	{
		if (Type == 1)
		{
			ss << "   SIGNAL " << Instance << " : std_logic;" << endl;
		}
		else if (Type == 0)
		{
			if (Size == 1)
			{
				ss << "   SIGNAL " << Instance << " : std_logic;" << endl;
			}
			else if (Size > 1)
			{
				Upper_bound = Size - 1;
				ss << "   SIGNAL " << Instance << " : std_logic_vector(" << Upper_bound << " DOWNTO 0);" << endl;
			}
		}
		else if (HT.findfact("type_def(" + to_string(Type) + ",*)"))
		{
			Size_ = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Type) + ",*)"), 3));
			if (Size_ > 1)
			{
				Upper_bound = Size - 1;
				ss << "   SIGNAL " << Instance << " : std_logic_vector(" << Upper_bound << " DOWNTO 0);" << endl;
			}
		}
		else if (Size > 1)
		{
			Upper_bound = Size - 1;
			ss << "   SIGNAL " << Instance << " : std_logic_vector(" << Upper_bound << " DOWNTO 0);" << endl;

		}
	}
	else if (HT.findfact("hdl_style(\"verilog\")"))
	{
		if (Type == 1)
		{
			ss << "   reg   " << Instance << " ;" << endl;
		}
		else if (Type == 0)
		{
			if (Size == 1)
			{
				ss << "   reg   " << Instance << " ;" << endl;
			}
			else if (Size > 1)
			{
				Upper_bound = Size - 1;
				ss << "   reg   [" << Upper_bound << ":0]  " << Instance << " ;" << endl;
			}
			else if (HT.findfact("type_def(" + to_string(Type) + ",*)"))
			{
				Size_ = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Type) + ",*)"), 3));
				if (Size_ == 1)
				{
					if (Size <= Size_)
					{
						ss << "   reg   " << Instance << " ;" << endl;
					}
				}
				else if (Size == Size_)
				{
					if (Size_ > 1)
					{
						Upper_bound = Size_ - 1;
						ss << "   reg   [" << Upper_bound << ":0] " << Instance << ";" << endl;
					}
				}
				else if (Size >= Size_)
				{
					Upper_bound = Size - 1;
					ss << "   reg   [" << Upper_bound << ":0] " << Instance << ";" << endl;
				}
				else if (Size < Size_)
				{
					Upper_bound = Size_ - 1;
					ss << "   reg   [" << Upper_bound << ":0] " << Instance << ";" << endl;
				}
			}
		}
	}
	return ss.str();
}

string declare_input_signal(string In_instance, int Size)
{
	stringstream ss;
	int Upper, Dtype, Object_type_size, InSize, Type, Order_number, Special_size, Type_size, Max_size;
	string Input_name, Module_name;
	if (!HT.findfact("signal_instance(_," + In_instance + ",_,_,_,_,_)"))
	{
		return ss.str();
	}
	if (Size == 0)
	{
		if (HT.findfact("current_hdl_style(\"vhdl\")"))
		{
			if (HT.findfact("signal_instance(_," + In_instance + ",_,_,_,_,_)"))
			{
				Input_name = returnpar(HT.findandreturn("signal_instance(_," + In_instance + ",_,_,_,_,_)"), 3);
				if (HT.findfact("current_module(*)"))
				{
					Module_name = returnpar(HT.findandreturn("current_module(*)"), 1);
					if (HT.findfact("data_stmt(" + Module_name + "," + Input_name + ",_,_,_,_)"))
					{
						Dtype = stoi(returnpar(HT.findandreturn("data_stmt(" + Module_name + "," + Input_name + ",_,_,_,_)"), 4));
						if (HT.findfact("type_def(" + to_string(Dtype) + ",*)"))
						{
							Object_type_size = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Dtype) + ",*)"), 3));
							if (Object_type_size > 1)
							{
								Upper = Object_type_size - 1;
								ss << "   SIGNAL " << In_instance << " : std_logic_vector(" << Upper << " DOWNTO 0);" << endl;
							}
						}
					}
				}
			}
		}
		else if (HT.findfact("current_hdl_style(\"verilog\")"))
		{
			if (HT.findfact("signal_instance(_," + In_instance + ",_,_,_,_,_)"))
			{
				Input_name = returnpar(HT.findandreturn("signal_instance(_," + In_instance + ",_,_,_,_,_)"), 3);
				if (HT.findfact("current_module(*)"))
				{
					Module_name = returnpar(HT.findandreturn("current_module(*)"), 1);
					if (HT.findfact("data_stmt(" + Module_name + "," + Input_name + ",_,_,_,_)"))
					{
						Dtype = stoi(returnpar(HT.findandreturn("data_stmt(" + Module_name + "," + Input_name + ",_,_,_,_)"), 4));
						if (HT.findfact("type_def(" + to_string(Dtype) + ",*)"))
						{
							Object_type_size = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Dtype) + ",*)"), 3));
							if (Object_type_size > 1)
							{
								Upper = Object_type_size - 1;
								ss << "   reg [" << Upper << " :0]" << In_instance << ";" << endl;
							}
						}
					}
				}
			}
		}
	}
	else if (Size == 1)
	{
		if (HT.findfact("current_hdl_style(\"vhdl\")"))
		{
			if (HT.findfact("signal_instance(_," + In_instance + ",_,_,_,_,_)"))
			{
				Input_name = returnpar(HT.findandreturn("signal_instance(_," + In_instance + ",_,_,_,_,_)"), 3);
				InSize = stoi(returnpar(HT.findandreturn("signal_instance(_," + In_instance + ",_,_,_,_,_)"), 6));
				if (HT.findfact("current_module(*)"))
				{
					Module_name = returnpar(HT.findandreturn("current_module(*)"), 1);
					if (HT.findfact("data_stmt(" + Module_name + "," + Input_name + ",_,_,_,_)"))
					{
						Dtype = stoi(returnpar(HT.findandreturn("data_stmt(" + Module_name + "," + Input_name + ",_,_,_,_)"), 4));
						if (Dtype == 1)
						{
							ss << "   SIGNAL " << In_instance << " : std_logic;" << endl;
						}
						else if (Dtype != 1)
						{
							if (InSize == 1)
							{
								ss << "   SIGNAL " << In_instance << " : std_logic;" << endl;
							}
							else if (InSize > 1)
							{
								Upper = InSize - 1;
								ss << "   SIGNAL " << In_instance << " : std_logic_vector(" << Upper << " DOWNTO 0);" << endl;
							}
						}
					}
				}
			}
		}
		else if (HT.findfact("current_hdl_style(\"verilog\")"))
		{
			if (HT.findfact("signal_instance(_," + In_instance + ",_,_,_,_,_)"))
			{
				Input_name = returnpar(HT.findandreturn("signal_instance(_," + In_instance + ",_,_,_,_,_)"), 3);
				InSize = stoi(returnpar(HT.findandreturn("signal_instance(_," + In_instance + ",_,_,_,_,_)"), 6));
				if (HT.findfact("current_module(*)"))
				{
					Module_name = returnpar(HT.findandreturn("current_module(*)"), 1);
					if (HT.findfact("data_stmt(" + Module_name + "," + Input_name + ",_,_,_,_)"))
					{
						Dtype = stoi(returnpar(HT.findandreturn("data_stmt(" + Module_name + "," + Input_name + ",_,_,_,_)"), 4));
						if (Dtype == 1)
						{
							ss << "   reg " << In_instance << " ;" << endl;
						}
						else if (Dtype != 1)
						{
							if (InSize == 1)
							{
								ss << "   reg " << In_instance << " ;" << endl;
							}
							else if (InSize > 1)
							{
								Upper = InSize - 1;
								ss << "   reg [" << Upper << " :0] " << In_instance << ";" << endl;
							}
						}
					}
				}
			}
		}
	}
	else if (HT.findfact("signal_instance(_," + In_instance + ",\"constant\",_,_,_,_)"))
	{
		ss << write_constant_signal_declaration(In_instance, Size);
	}
	else if (HT.findfact("current_hdl_style(\"vhdl\")"))
	{
		if (HT.findfact("signal_instance(_," + In_instance + ",_,_,_,_,_)"))
		{
			if (Size > 1)
			{
				Upper = Size - 1;
				ss << "   SIGNAL " << In_instance << " : std_logic_vector(" << Upper << " DOWNTO 0);" << endl;
			}
		}
	}
	else if (HT.findfact("current_hdl_style(\"verilog\")"))
	{
		if (HT.findfact("signal_instance(_," + In_instance + ",_,_,_,_,_)"))
		{
			if (Size > 1)
			{
				Upper = Size - 1;
				ss << "   reg [" << Upper << ":0] " << In_instance << ";" << endl;
			}
		}
	}
	else if (HT.findfact("signal_instance(_," + In_instance + ",_,_,_,_,_)"))
	{
		Input_name = returnpar(HT.findandreturn("signal_instance(_," + In_instance + ",_,_,_,_,_)"), 3);
		Type = stoi(returnpar(HT.findandreturn("signal_instance(_," + In_instance + ",_,_,_,_,_)"), 5));
		if (HT.findfact("current_module(*)"))
		{
			Module_name = returnpar(HT.findandreturn("current_module(*)"), 1);
			if (Type > 0)
			{
				if (!HT.findfact("data_stmt(" + Module_name + "," + Input_name + ",_,_,_,_)"))
				{
					if (HT.findfact("special_dt(" + Module_name + ",_," + Input_name + ",_,_,_,_)"))
					{
						Order_number = stoi(returnpar(HT.findandreturn("special_dt(" + Module_name + ",_," + Input_name + ",_,_,_,_)"), 2));
						Special_size = stoi(returnpar(HT.findandreturn("special_dt(" + Module_name + ",_," + Input_name + ",_,_,_,_)"), 4));
						if (Order_number < 0)
						{
							if (HT.findfact("type_def(" + to_string(Type) + ",*)"))
							{
								Type_size = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Type) + ",*)"), 3));
								max_(Special_size, Type_size, &Max_size);
								ss << write_signal_declaration(In_instance, Type, Size);
							}
						}
					}
				}
			}
		}
	}
	return ss.str();
}

string write_constant_signal_declaration(string In_instance, int Size)
{
	stringstream ss;
	int Upper_bound, Type, Type_size;
	string Input_name, Module_name;
	if (Size == 1)
	{
		if (HT.findfact("hdl_style(\"vhdl\")"))
		{
			ss << "   SIGNAL " << In_instance << " : std_logic;" << endl;
		}
		else if (HT.findfact("hdl_style(\"verilog\")"))
		{
			ss << "   reg   " << In_instance << " ;" << endl;
		}
	}
	else if (Size == 0)
	{
		if (HT.findfact("hdl_style(\"vhdl\")"))
		{
			if (HT.findfact("signal_instance(_," + In_instance + ",_,_,_,_,_)"))
			{
				Input_name = returnpar(HT.findandreturn("signal_instance(_," + In_instance + ",_,_,_,_,_)"), 3);
				Type = stoi(returnpar(HT.findandreturn("signal_instance(_," + In_instance + ",_,_,_,_,_)"), 5));
				if (HT.findfact("current_module(*)"))
				{
					Module_name = returnpar(HT.findandreturn("current_module(*)"), 1);
					if (Type > 0)
					{
						if (HT.findfact("data_stmt(" + Module_name + "," + Input_name + ",_," + to_string(Type) + ",_,_)"))
						{
							if (HT.findfact("type_def(" + to_string(Type) + ",*)"))
							{
								Type_size = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Type) + ",*)"), 3));
								Upper_bound = Type_size - 1;
								ss << "   SIGNAL " << In_instance << " : std_logic_vector(" << Upper_bound << " DOWNTO 0);" << endl;
							}
						}
					}
				}
			}
		}
	}
	else if (HT.findfact("hdl_style(\"vhdl\")"))
	{
		if (Size > 1)
		{
			Upper_bound = Size - 1;
			ss << "   SIGNAL " << In_instance << " : std_logic_vector(" << Upper_bound << " DOWNTO 0);" << endl;
		}
	}
	else if (HT.findfact("hdl_style(\"verilog\")"))
	{
		if (Size > 1)
		{
			Upper_bound = Size - 1;
			ss << "   reg   [" << Upper_bound << ":0]  " << In_instance << ";" << endl;
		}
	}
	return ss.str();
}

bool out_of_standard_types(int Type)
{
	return Type == 0 || Type > 10;
}

string write_content_body_header(string Module, string HDL, string Tool, string Schedule)
{
	stringstream ss;
	if (Tool == "synergy")
	{
		if (HDL == "vhdl")
		{
			ss << endl << "  BEGIN  " << endl << endl;
			ss << "   done <= done_int;" << endl;
			ss << write_call_assignments(Module, 1, Schedule);
		}
		else if (HDL == "verilog")
		{
			ss << "   /*--- now some intermediate signal assignments ---*/ ";
			ss << endl;
			ss << "   always @(*)" << endl;
			ss << "    begin" << endl;
			ss << "      done <= done_int;" << endl;
			ss << write_call_assignments(Module, 1, Schedule);
			ss << "    end" << endl;
		}
	}
	else if (Tool == "gnu")
	{
		if (HDL == "c")
		{
			ss << "   int state<< Stop;  " << endl;
			ss << "   char Action<< Action1 = 'l'; " << endl;
			ss << "   printf(" << '"' << "FSM Started " << '\\' << "n" << '"' << ");" << endl;
			ss << "   Stop = 1;" << endl;
			ss << "   while (Action != 'q') {" << endl;
			ss << "     if (Stop != 0)" << endl;
			ss << "     do {" << endl;
			ss << "      printf(" << '"' << " type a simulator option: r(eset)<< n(ext state)<< i(nput settings) l(go-to-last state) o(utput values) p(rint arrays) or q(uit): " << '"' << ");" << endl;
			ss << "      Action = getch(); printf(" << '"' << " %c " << '\\' << "n" << '"' << "<< Action);" << endl;
			ss << "     if (Action == 'l') Stop = 0; }" << endl;
			ss << "     while ((Action != 'r') && (Action != 'n') && (Action != 'i') && (Action != 'l') && (Action != 'o') && (Action != 'p') && (Action != 'q'));" << endl;
			ss << "     if (Action == 'q') exit(0);  else" << endl;
			ss << "      if (Action == 'l')  Action1 = 'n';" << endl;
			ss << "      else Action1 = Action;" << endl;
			ss << "     printf(" << '"' << " executing simulator body " << '\\' << "n" << '"' << ");" << endl;
		}
	}
	return ss.str();
}

string write_call_assignments(string Module, int Call_entry, string Schedule)
{
	stringstream ss;
	int Next_entry;
	if (HT.findfact("call_stmt(" + Module + "," + to_string(Call_entry) + ",*)"))
	{
		ss << write_call_assignment(Module, Call_entry, Schedule);
		Next_entry = Call_entry + 1;
		ss << write_call_assignments(Module, Next_entry, Schedule);
	}
	return ss.str();
}

string write_call_assignment(string Module, int Call_entry, string New_schedule)
{
	stringstream ss;
	int Called_module_entry, TotalMax, TM1, TM2, TM3, MAX1, MAX2, Max_same, Gross_same;
	string Called_module_name;
	if (parcs_or_parcsif(New_schedule))
	{
		if (HT.findfact("hdl_style(\"vhdl\")"))
		{
			if (HT.findfact("call_stmt(" + Module + "," + to_string(Call_entry) + ",*)"))
			{
				Called_module_entry = stoi(returnpar(HT.findandreturn("call_stmt(" + Module + "," + to_string(Call_entry) + ",*)"), 3));
				if (HT.findfact("hierarchy_part(" + to_string(Called_module_entry) + ",*)"))
				{
					Called_module_name = returnpar(HT.findandreturn("hierarchy_part(" + to_string(Called_module_entry) + ",*)"), 2);
					if (!HT.findfact("added_aux_call_ios1(" + Module + ",_," + to_string(Called_module_entry) + ")"))
					{
						if (!custom_block(Called_module_name))
						{
							if (HT.findfact("max_parallel_call_order(" + Module + ",\"parcsif\",*)"))
							{
								TM1 = stoi(returnpar(HT.findandreturn("max_parallel_call_order(" + Module + ",\"parcsif\",*)"), 4));
								if (HT.findfact("max_op_order(" + Module + ",\"parcsif\",*)"))
								{
									TM2 = stoi(returnpar(HT.findandreturn("max_op_order(" + Module + ",\"parcsif\",*)"), 3));
									if (HT.findfact("totalmax_call_order(" + Module + ",\"parcsif\",*)"))
									{
										TM3 = stoi(returnpar(HT.findandreturn("totalmax_call_order(" + Module + ",\"parcsif\",*)"), 3));
										max_(TM1, TM2, &MAX1);
										max_(MAX1, TM3, &MAX2);
										find_correct_max_call_order(Module, Called_module_entry, MAX2, &TotalMax);
										if (TotalMax == 0)
										{
											ss << "   " << Called_module_name << "_start <= " << Called_module_name << "_start_int;" << endl;
											ss << "   " << Called_module_name << "_results_read <= " << Called_module_name << "_results_read_int;" << endl;
											HT.assertz("added_aux_call_ios1(" + Module + "," + to_string(Call_entry) + "," + to_string(Called_module_entry) + ")");
										}
									}
								}
							}
							else if (HT.findfact("max_parallel_call_order(" + Module + "," + New_schedule + "," + to_string(Called_module_entry) + ",0)"))
							{
								if (HT.findfact("operation_order(" + Module + "," + New_schedule + ",_,_," + to_string(Called_module_entry) + ",_,_,_,_,_,_)"))
								{
									Max_same = stoi(returnpar(HT.findandreturn("operation_order(" + Module + "," + New_schedule + ",_,_," + to_string(Called_module_entry) + ",_,_,_,_,_,_)"), 7));
									Gross_same = stoi(returnpar(HT.findandreturn("operation_order(" + Module + "," + New_schedule + ",_,_," + to_string(Called_module_entry) + ",_,_,_,_,_,_)"), 10));
									if (Max_same == 0)
									{
										if (Gross_same == 1)
										{
											ss << "   " << Called_module_name << "_start <= " << Called_module_name << "_start_int;" << endl;
											ss << "   " << Called_module_name << "_results_read <= " << Called_module_name << "_results_read_int;" << endl;
											HT.assertz("added_aux_call_ios1(" + Module + "," + to_string(Call_entry) + "," + to_string(Called_module_entry) + ")");
										}
									}
								}
							}
							else if (HT.findfact("max_parallel_call_order(" + Module + "," + New_schedule + "," + to_string(Called_module_entry) + ",*)"))
							{
								TotalMax = stoi(returnpar(HT.findandreturn("max_parallel_call_order(" + Module + "," + New_schedule + "," + to_string(Called_module_entry) + ",*)"), 4));
								if (TotalMax > 1)
								{
									ss << write_polymorfic_IO_assignment(Module, "parcs", Called_module_name, "start", "start_int", 1, TotalMax, "   ", "", "; ") << endl;
									ss << write_polymorfic_IO_assignment(Module, "parcs", Called_module_name, "results_read", "results_read_int", 1, TotalMax, "   ", "", "; ") << endl;
									HT.assertz("added_aux_call_ios1(" + Module + "," + to_string(Call_entry) + "," + to_string(Called_module_entry) + ")");
								}
							}
							else if (!HT.findfact("max_parallel_call_order(" + Module + "," + New_schedule + "," + to_string(Called_module_entry) + ",*)"))
							{
								if (HT.findfact("operation_order(" + Module + "," + New_schedule + ",_,_," + to_string(Called_module_entry) + ",_,_,_,_,_,_)"))
								{
									Max_same = stoi(returnpar(HT.findandreturn("max_parallel_call_order(" + Module + "," + New_schedule + "," + to_string(Called_module_entry) + ",*)"), 7));
									if (Max_same == 1)
									{
										ss << "   " << Called_module_name << "_start <= " << Called_module_name << "_start_int;" << endl;
										ss << "   " << Called_module_name << "_results_read <= " << Called_module_name << "_results_read_int;" << endl;
										HT.assertz("added_aux_call_ios1(" + Module + "," + to_string(Call_entry) + "," + to_string(Called_module_entry) + ")");
									}
									else if (Max_same > 1)
									{
										ss << write_polymorfic_IO_assignment(Module, "parcs", Called_module_name, "start", "start_int", 1, Max_same, "   ", "", "; ") << endl;
										ss << write_polymorfic_IO_assignment(Module, "parcs", Called_module_name, "results_read", "results_read_int", 1, Max_same, "   ", "", "; ") << endl;
										HT.assertz("added_aux_call_ios1(" + Module + "," + to_string(Call_entry) + "," + to_string(Called_module_entry) + ")");
									}
								}
							}
							else if (!HT.findfact("totalmax_call_order(" + Module + ",*)"))
							{
								ss << "   " << Called_module_name << "_start <= " << Called_module_name << "_start_int;" << endl;
								ss << "   " << Called_module_name << "_results_read <= " << Called_module_name << "_results_read_int;" << endl;
								HT.assertz("added_aux_call_ios1(" + Module + "," + to_string(Call_entry) + "," + to_string(Called_module_entry) + ")");
							}
							else if (HT.findfact("totalmax_call_order(" + Module + ",\"parcsif\",*)"))
							{
								TotalMax = stoi(returnpar(HT.findandreturn("totalmax_call_order(" + Module + ",\"parcsif\",*)"), 3));
								if (TotalMax == 1)
								{
									ss << "   " << Called_module_name << "_start <= " << Called_module_name << "_start_int;" << endl;
									ss << "   " << Called_module_name << "_results_read <= " << Called_module_name << "_results_read_int;" << endl;
									HT.assertz("added_aux_call_ios1(" + Module + "," + to_string(Call_entry) + "," + to_string(Called_module_entry) + ")");
								}
							}
							else
							{
								find_correct_order(Module, Call_entry, &TotalMax);
								if (TotalMax <= 1)
								{
									ss << "   " << Called_module_name << "_start <= " << Called_module_name << "_start_int;" << endl;
									ss << "   " << Called_module_name << "_results_read <= " << Called_module_name << "_results_read_int;" << endl;
									HT.assertz("added_aux_call_ios1(" + Module + "," + to_string(Call_entry) + "," + to_string(Called_module_entry) + ")");
								}
								else if (TotalMax > 1)
								{
									ss << write_polymorfic_IO_assignment(Module, "parcs", Called_module_name, "start", "start_int", 1, TotalMax, "   ", "", "; ") << endl;
									ss << write_polymorfic_IO_assignment(Module, "parcs", Called_module_name, "results_read", "results_read_int", 1, TotalMax, "   ", "", "; ") << endl;
									HT.assertz("added_aux_call_ios1(" + Module + "," + to_string(Call_entry) + "," + to_string(Called_module_entry) + ")");
								}
							}
						}
					}
				}
			}
		}
		else if (HT.findfact("hdl_style(\"verilog\")"))
		{
			if (HT.findfact("call_stmt(" + Module + "," + to_string(Call_entry) + ",*)"))
			{
				Called_module_entry = stoi(returnpar(HT.findandreturn("call_stmt(" + Module + "," + to_string(Call_entry) + ",*)"), 3));
				if (HT.findfact("hierarchy_part(" + to_string(Called_module_entry) + ",*)"))
				{
					Called_module_name = returnpar(HT.findandreturn("hierarchy_part(" + to_string(Called_module_entry) + ",*)"), 2);
					if (!HT.findfact("added_aux_call_ios1(" + Module + ",_," + to_string(Called_module_entry) + ")"))
					{
						if (!custom_block(Called_module_name))
						{
							if (HT.findfact("max_parallel_call_order(" + Module + "," + New_schedule + "," + to_string(Called_module_entry) + ",*)"))
							{
								TotalMax = stoi(returnpar(HT.findandreturn("max_parallel_call_order(" + Module + "," + New_schedule + "," + to_string(Called_module_entry) + ",*)"), 4));
								if (TotalMax > 1)
								{
									ss << write_polymorfic_IO_assignment(Module, "parcs", Called_module_name, "start", "start_int", 1, TotalMax, "      ", "", "; ") << endl;
									ss << write_polymorfic_IO_assignment(Module, "parcs", Called_module_name, "results_read", "results_read_int", 1, TotalMax, "      ", "", "; ") << endl;
									HT.assertz("added_aux_call_ios1(" + Module + "," + to_string(Call_entry) + "," + to_string(Called_module_entry) + ")");
								}
								else if (TotalMax == 1)
								{
									ss << "      " << Called_module_name << "_start <= " << Called_module_name << "_start_int;" << endl;
									ss << "      " << Called_module_name << "_results_read <= " << Called_module_name << "_results_read_int;" << endl;
									HT.assertz("added_aux_call_ios1(" + Module + "," + to_string(Call_entry) + "," + to_string(Called_module_entry) + ")");
								}
							}
							else if (!HT.findfact("max_parallel_call_order(" + Module + ",_," + to_string(Called_module_entry) + ",*)"))
							{
								ss << "      " << Called_module_name << "_start <= " << Called_module_name << "_start_int;" << endl;
								ss << "      " << Called_module_name << "_results_read <= " << Called_module_name << "_results_read_int;" << endl;
								HT.assertz("added_aux_call_ios1(" + Module + "," + to_string(Call_entry) + "," + to_string(Called_module_entry) + ")");
							}
						}
					}
				}
			}
		}
	}
	return ss.str();
}

string write_polymorfic_IO_assignment(string Module, string Schedule_name, string Called_Module_name, string Destination_Signal_name, string Source_Signal_name, int Next_order, int Max_order, string First_space, string Condition_op_string, string Suffix_string)
{
	stringstream ss;
	int Order_plus_1;
	if (Next_order <= Max_order)
	{
		ss << type_core_IO_assignment(Called_Module_name, Destination_Signal_name, Source_Signal_name, Next_order, Max_order, First_space, Condition_op_string, Suffix_string);
		Order_plus_1 = Next_order + 1;
		ss << write_polymorfic_IO_assignment(Module, Schedule_name, Called_Module_name, Destination_Signal_name, Source_Signal_name, Order_plus_1, Max_order, First_space, Condition_op_string, Suffix_string);
	}
	return ss.str();
}

string type_core_IO_assignment(string Called_Module_name, string Destination_Signal_name, string Source_Signal_name, int Next_order, int Max_order, string First_space, string Condition_op_string, string Suffix_string)
{
	stringstream ss;
	string Next_order_str, StrOrder;
	if (Next_order > Max_order)
		return ss.str();
	if (Next_order == 1)
	{
		ss << First_space << Called_Module_name << "_1_" << Destination_Signal_name << " <= " << Called_Module_name << "_1_" << Source_Signal_name << Suffix_string << " " << Condition_op_string << endl;
	}
	else if (Next_order > 1)
	{
		if (Next_order < Max_order)
		{
			Next_order_str = to_string(Next_order);
			HT.concat("_", Next_order_str, &StrOrder);
			ss << First_space << Called_Module_name << StrOrder << "_" << Destination_Signal_name << " <= " << Called_Module_name << StrOrder << "_" << Source_Signal_name << Suffix_string << " " << Condition_op_string << endl;
		}
	}
	else if (Next_order = Max_order)
	{
		if (Next_order == 1 || Next_order > 1)
		{
			Next_order_str = to_string(Next_order);
			HT.concat("_", Next_order_str, &StrOrder);
			ss << First_space << Called_Module_name << StrOrder << "_" << Destination_Signal_name << " <= " << Called_Module_name << StrOrder << "_" << Source_Signal_name << Suffix_string << endl;
		}
	}
	return ss.str();
}

string write_fsm(string Module_name, int int1, int State_number, string HDL, string Tool)
{
	stringstream ss;
	if (int1 == 1)
	{
		ss << write_fsm_header(Module_name, 1, HDL, Tool);
		reset_locals(Module_name, "specials", 1, HDL, Tool);
		HT.retractall("call_ios_have_been_reset(*)");
		ss << reset_call_ports_unopt(Module_name, "vhdl", 1) << endl;
		ss << endl;
		ss << write_fsm_clock_header(HDL, Tool);
		ss << write_states(Module_name, State_number, HDL, Tool);

	}
	return ss.str();
}

string write_fsm_header(string Module_name, int int1, string HDL, string Tool)
{
	stringstream ss;
	string ResetStyle;
	if (Tool == "synergy")
	{
		if (HDL == "vhdl")
		{
			if (HT.findfact("resetstyle(*)"))
			{
				ResetStyle = stoi(returnpar(HT.findandreturn("resetstyle(*)"), 1));
				if (ResetStyle != "syncreset")
				{
					ss << "    --- FSM and controller loging (plus massively-parallel ops) ---" << endl;
					ss << "    fsm_core : PROCESS (clock, reset) " << endl;
					ss << write_aux_std_logic_vectors_wrapper(Module_name, 1, "vhdl", "synergy");
					ss << write_all_cus_blocks_io_variables(Module_name, 1, "vhdl");
					ss << write_aux_conditional_variables(Module_name, 2, "vhdl");
					ss << write_next_state_variable(Module_name, "vhdl", 0);
					ss << "     BEGIN " << endl;
					ss << "      IF reset = '0' THEN " << endl;
					ss << "       done_int <= '0';" << endl;
					ss << "       busy <= '0';" << endl;
					ss << "       state <= state_0;" << endl;
				}
				else if (ResetStyle == "syncreset")
				{
					ss << "    --- FSM and controller loging (plus massively-parallel ops) ---" << endl;
					ss << "    fsm_core : PROCESS (clock) " << endl;
					ss << write_aux_std_logic_vectors_wrapper(Module_name, 1, "vhdl", "synergy");
					ss << write_all_cus_blocks_io_variables(Module_name, 1, "vhdl");
					ss << write_aux_conditional_variables(Module_name, 2, "vhdl");
					ss << write_next_state_variable(Module_name, "vhdl", 0);
					ss << "     BEGIN " << endl;
					ss << "      IF clock = '1' AND clock'event THEN " << endl;
					ss << "      IF reset = '0' THEN " << endl;
					ss << "       done_int <= '0';" << endl;
					ss << "       busy <= '0';" << endl;
					ss << "       state <= state_0;" << endl;
				}
			}
			else if (!HT.findfact("resetstyle(*)"))
			{
				HT.assertz("resetstyle(\"syncreset\")");
				ss << "    --- FSM and controller loging (plus massively-parallel ops) ---" << endl;
				ss << "    fsm_core : PROCESS (clock) " << endl;
				ss << write_aux_std_logic_vectors_wrapper(Module_name, 1, "vhdl", "synergy");
				ss << write_all_cus_blocks_io_variables(Module_name, 1, "vhdl");
				ss << write_aux_conditional_variables(Module_name, 2, "vhdl");
				ss << write_next_state_variable(Module_name, "vhdl", 0);
				ss << "     BEGIN " << endl;
				ss << "      IF clock = '1' AND clock'event THEN " << endl;
				ss << "      IF reset = '0' THEN " << endl;
				ss << "       done_int <= '0';" << endl;
				ss << "       busy <= '0';" << endl;
				ss << "       state <= state_0;" << endl;
			}
		}
		else if (HDL == "verilog")
		{
			if (HT.findfact("resetstyle(*)"))
			{
				ResetStyle = stoi(returnpar(HT.findandreturn("resetstyle(*)"), 1));
				if (ResetStyle != "syncreset")
				{
					ss << "    //--- FSM and controller loging (plus massively-parallel ops) ---" << endl;
					ss << "    always @(posedge clock or negedge reset) " << endl;
					ss << "     begin " << endl;
					ss << "      if (~reset)" << endl;
					ss << "       begin" << endl;
					ss << "        done_int <= 1'b0;" << endl;
					ss << "        busy <= 1'b0;" << endl;
					ss << "        state <= state_0;" << endl;
				}
				else if (ResetStyle == "syncreset")
				{
					ss << "    //--- FSM and controller loging (plus massively-parallel ops) ---" << endl;
					ss << "    always @(posedge clock) " << endl;
					ss << "     begin " << endl;
					ss << "      if (~reset)" << endl;
					ss << "       begin" << endl;
					ss << "        done_int <= 1'b0;" << endl;
					ss << "        busy <= 1'b0;" << endl;
					ss << "        state <= state_0;" << endl;
				}
			}
			else if (!HT.findfact("resetstyle(*)"))
			{
				HT.assertz("resetstyle(\"syncreset\")");
				ss << "    //--- FSM and controller loging (plus massively-parallel ops) ---" << endl;
				ss << "    always @(posedge clock) " << endl;
				ss << "     begin " << endl;
				ss << "      if (~reset)" << endl;
				ss << "       begin" << endl;
				ss << "        done_int <= 1'b0;" << endl;
				ss << "        busy <= 1'b0;" << endl;
				ss << "        state <= state_0;" << endl;
			}
		}
	}
	else if (Tool == "gnu")
	{
		if (HDL == "c")
		{
			ss << "     switch (Action1) {" << endl;
			ss << "      case 'r':" << endl;
			ss << "       printf(" << '"' << " reseting local signals and variables " << '\\' << 'n' << '"' << ");" << endl;
		}
	}
	return ss.str();
}

string write_aux_std_logic_vectors_wrapper(string Module_name, int Next_number, string HDL, string Tool)
{
	stringstream ss;
	if (Tool == "synergy")
	{
		if (HDL == "vhdl")
		{
			ss << write_aux_std_logic_vectors(Module_name, Next_number, "vhdl", "synergy");
		}
	}
	return ss.str();
}

string write_aux_std_logic_vectors(string Module_name, int Number, string HDL, string Tool)
{
	stringstream ss;
	GeneralFact* Local;
	int Next_number;
	if (Tool == "synergy")
	{
		if (HDL == "vhdl")
		{
			if (HT.findfact("local_object(" + Module_name + "," + to_string(Number) + ",*)"))
			{
				Local = makeInstanceOf(HT.findandreturn("local_object(" + Module_name + "," + to_string(Number) + ",*)"));
				local_object* ptr = dynamic_cast<local_object*>(Local);
				ss << write_aux_std_logic_vector(*ptr);
				Next_number = Number + 1;
				ss << write_aux_std_logic_vectors(Module_name, Next_number, "vhdl", "synergy");
			}
		}
	}
	return ss.str();
}

string write_aux_std_logic_vector(local_object Local)
{
	stringstream ss;
	string Local_type, var7, Local_name;
	int Local_size;
	GeneralFact* ptr;
	ptr = &Local;
	Local_name = returnpar(HT.findandreturn(makeStringOf(ptr)), 4);
	Local_type = returnpar(HT.findandreturn(makeStringOf(ptr)), 6);
	var7 = returnpar(HT.findandreturn(makeStringOf(ptr)), 7);
	Local_size = stoi(returnpar(HT.findandreturn(makeStringOf(ptr)), 8));
	if (Local_type == "std_logic" && var7 == "standard" && Local_size == 1)
		ss << "     variable " << Local_name << "_vector : std_logic_vector(1 DOWNTO 1);" << endl;
	return ss.str();
}

string write_all_cus_blocks_io_variables(string Module_name, int Module_entry, string HDL)
{
	stringstream ss;
	int Top_entry, Next_entry;
	if (HT.findfact("hierarchy_part(_," + Module_name + ",_,\"libpart\",_,_,_)"))
	{
		Top_entry = stoi(returnpar(HT.findandreturn("hierarchy_part(_," + Module_name + ",_,\"libpart\",_,_,_)"), 1));
		if (Module_entry != Top_entry)
		{
			ss << write_cus_block_variables_cond(Module_name, Module_entry, HDL);
			Next_entry = Module_entry + 1;
			write_all_cus_blocks_io_variables(Module_name, Next_entry, HDL);
		}
	}
	return ss.str();
}

string write_cus_block_variables_cond(string Module_name, int Module_entry, string HDL)
{
	stringstream ss;
	int Top_entry;
	string Called_module_name;
	if (HT.findfact("hierarchy_part(_," + Module_name + ",_,\"libpart\",_,_,_)"))
	{
		Top_entry = stoi(returnpar(HT.findandreturn("hierarchy_part(_," + Module_name + ",_,\"libpart\",_,_,_)"), 1));
		if (Module_entry < Top_entry)
		{
			if (HT.findfact("hierarchy_part(" + to_string(Module_entry) + ",_,_,\"libpart\",_,_,_)"))
			{
				Called_module_name = returnpar(HT.findandreturn("hierarchy_part(" + to_string(Module_entry) + ",_,_,\"libpart\",_,_,_)"), 2);
				if (custom_block(Called_module_name))
				{
					if (HT.findfact("call_stmt(" + Module_name + ",_," + to_string(Module_entry) + ",_)"))
					{
						ss << write_cus_block_process_io_variables(Called_module_name, 1, HDL);
					}
				}
			}
		}
	}
	return ss.str();
}

string  write_aux_conditional_variables(string Module_name, int Entry, string HDL)
{
	stringstream ss;
	int Next_entry;
	if (HT.findfact("prog_stmt(" + Module_name + "," + to_string(Entry) + ",*)"))
	{
		ss << write_aux_conditional_variable(Module_name, Entry, HDL);
		Next_entry = Entry + 1;
		ss << write_aux_conditional_variables(Module_name, Next_entry, HDL);
	}
	return ss.str();
}

string write_aux_conditional_variable(string Module_name, int Entry, string HDL)
{
	stringstream ss;
	int Cvar, Pentry, Pvar, Target, Ctype;
	string DName, Ckind;
	if (HDL == "vhdl")
	{
		if (Entry > 1)
		{
			if (HT.findfact("prog_stmt(" + Module_name + "," + to_string(Entry) + ",_,106,0,_,_,_)"))
			{
				Cvar = stoi(returnpar(HT.findandreturn("prog_stmt(" + Module_name + "," + to_string(Entry) + ",_,106,0,_,_,_)"), 6));
				Pentry = Entry - 1;
				if (HT.findfact("prog_stmt(" + Module_name + "," + to_string(Pentry) + ",_,_,_,_,_," + to_string(Entry) + ")"))
				{
					Pvar = stoi(returnpar(HT.findandreturn("prog_stmt(" + Module_name + "," + to_string(Pentry) + ",_,_,_,_,_," + to_string(Entry) + ")"), 7));
					if (Pvar != Cvar)
					{
						return ss.str();
					}
					Cvar = stoi(returnpar(HT.findandreturn("prog_stmt(" + Module_name + "," + to_string(Pentry) + ",_,_,_,_,_," + to_string(Entry) + ")"), 7));
					if (HT.findfact("data_stmt(" + Module_name + ",_," + to_string(Cvar) + ",_,\"const\",_)"))
					{
						return ss.str();
					}
					if (HT.findfact("data_stmt(" + Module_name + ",*)"))
					{
						DName = returnpar(HT.findandreturn("data_stmt(" + Module_name + ",*)"), 2);
						Ctype = stoi(returnpar(HT.findandreturn("data_stmt(" + Module_name + ",*)"), 4));
						Ckind = returnpar(HT.findandreturn("data_stmt(" + Module_name + ",*)"), 5);
						if (Ckind != "const")
						{
							if (!HT.findfact("variable_has_been_listed(" + Module_name + "," + DName + ")"))
							{
								ss << "        VARIABLE " << DName << "_conditional_variable : ";
								ss << write_cus_func_param_type(Module_name, "body", Ctype, ";") << endl;
								HT.assertz("variable_has_been_listed(" + Module_name + "," + DName + ")");
							}
						}
					}
				}
				else if (HT.findfact("prog_stmt(" + Module_name + "," + to_string(Pentry) + ",_,110,_,_,_,_)"))
				{
					Target = stoi(returnpar(HT.findandreturn("prog_stmt(" + Module_name + "," + to_string(Pentry) + ",_,110,_,_,_,_)"), 7));
					if (Target != Entry)
					{
						return ss.str();
					}
				}
			}
		}
	}
	return ss.str();
}

string reset_locals(string Module_name, string Schedule, int Entry, string HDL, string Tool)
{
	stringstream ss;
	GeneralFact* Local;
	int Next_entry;
	if (HT.findfact("local_object(" + Module_name + "," + to_string(Entry) + ",*)"))
	{
		Local = makeInstanceOf(HT.findandreturn("local_object(" + Module_name + "," + to_string(Entry) + ",*)"));
		local_object* ptr = dynamic_cast<local_object*>(Local);
		ss << reset_local(Schedule, *ptr, HDL, Tool);
		Next_entry = Entry + 1;
		ss << reset_locals(Module_name, Schedule, Next_entry, HDL, Tool);
	}
	return ss.str();
}

string reset_local(string Schedule, local_object Local, string HDL, string Tool)
{
	stringstream ss;
	string Module, Local_kind, Local_name, Type_name, var7, Local_value, be, af, Type_kind, Kind, Local_name_app, Just_field,
		Rec_name, Rec_underscored, Underscored_name, Name1, Name2, Prefix_name;
	int Current_entry, var5, Local_size, Size, ParentType, TypeEntry, InferType, Comp_type, Firstd, Dimmension, Comp_type_size,
		Lastd, Number_of_fields, First_comp_type, Type_entry, Dimension_depth, Last_comp_type, RecType, Inh_type, Comp_type1,
		Rec_field, Dim_minus_one;
	GeneralFact* ptr;
	ptr = &Local;
	Module = returnpar(makeStringOf(ptr), 1);
	Current_entry = stoi(returnpar(makeStringOf(ptr), 2));
	Local_kind = returnpar(makeStringOf(ptr), 3);
	Local_name = returnpar(makeStringOf(ptr), 4);
	var5 = stoi(returnpar(makeStringOf(ptr), 5));
	Type_name = returnpar(makeStringOf(ptr), 6);
	var7 = returnpar(makeStringOf(ptr), 7);
	Local_size = stoi(returnpar(makeStringOf(ptr), 8));
	Local_value = returnpar(makeStringOf(ptr), 9);
	be = Local_value.substr(0, Local_value.find(pa, 0));
	af = Local_value.substr(be.length() + 1, Local_value.find(pacl, 0));
	af.resize(af.size() - 1);
	if (Tool == "synergy")
	{
		if (HDL == "vhdl")
		{
			if (var7 == "standard")
			{
				if (be == "bit_wire" && af == "std_logic")
				{
					if (Local_kind != "variable")
					{
						if (Local_kind != "constant")
						{
							if (Local_kind != "par_in")
							{
								if (Local_size >= 1)
								{
									if (HT.findfact("type_def(_," + Type_name + ",_,\"user\",_,_,_,_,_)"))
									{
										Size = stoi(returnpar(HT.findandreturn("type_def(_," + Type_name + ",_,\"user\",_,_,_,_,_)"), 3));
										Type_kind = returnpar(HT.findandreturn("type_def(_," + Type_name + ",_,\"user\",_,_,_,_,_)"), 6);
										if (Type_kind != "single_t")
										{
											if (Size != Local_size)
											{
												ss << "       " << Local_name << " <= (OTHERS => '0');" << endl;
											}
										}
									}
								}
							}
						}
					}
				}
				else if (Type_name == "bool")
				{
					if (Local_size == 1)
					{
						if (Local_kind != "variable")
						{
							if (Local_kind != "constant")
							{
								if (Local_kind != "par_in")
								{
									ss << "       " << Local_name << " <= '0';" << endl;
								}
							}
						}
					}
				}
				else if (Type_name == "std_logic")
				{
					if (Local_kind != "variable")
					{
						if (Local_kind != "constant")
						{
							if (Local_kind != "par_in")
							{
								if (Local_size > 1)
								{
									ss << "       " << Local_name << " <= (OTHERS => '0');" << endl;
								}
							}
						}
					}
				}
				else if (Type_name == "integer")
				{
					if (Local_kind != "variable")
					{
						if (Local_kind != "constant")
						{
							if (Local_kind != "par_in")
							{
								if (Local_size > 1)
								{
									ss << "       " << Local_name << " <= (OTHERS => '0');" << endl;
								}
							}
						}
					}
				}
				else if (Type_name == "fixed_point")
				{
					if (Local_kind != "variable")
					{
						if (Local_kind != "constant")
						{
							if (Local_kind != "par_in")
							{
								if (Local_size > 1)
								{
									ss << "       " << Local_name << " <= (OTHERS => '0');" << endl;
								}
							}
						}
					}
				}
				else if (Type_name == "natural")
				{
					if (Local_kind != "variable")
					{
						if (Local_kind != "constant")
						{
							if (Local_kind != "par_in")
							{
								if (Local_size > 1)
								{
									ss << "       " << Local_name << " <= (OTHERS => '0');" << endl;
								}
							}
						}
					}
				}
				if (Local_kind != "variable")
				{
					if (Local_kind != "constant")
					{
						if (Local_kind != "par_in")
						{
							if (Local_size == 1)
							{
								if (HT.findfact("type_def(_," + Type_name + ",_,\"user\",_,\"single_t\",0,0,0)"))
								{
									TypeEntry = stoi(returnpar(HT.findandreturn("type_def(_," + Type_name + ",_,\"user\",_,\"single_t\",0,0,0)"), 1));
									Size = stoi(returnpar(HT.findandreturn("type_def(_," + Type_name + ",_,\"user\",_,\"single_t\",0,0,0)"), 3));
									ParentType = stoi(returnpar(HT.findandreturn("type_def(_," + Type_name + ",_,\"user\",_,\"single_t\",0,0,0)"), 5));
									InferType = stoi(returnpar(HT.findandreturn("type_def(_," + Type_name + ",_,\"user\",_,\"single_t\",0,0,0)"), 9));
									if (Size == 1)
									{
										if (InferType == 2)
										{
											if (HT.findfact("type_def(" + to_string(ParentType) + ",_,_,\"user\",_,\"record_t\",_,_,_)"))
											{
												if (TypeEntry > ParentType)
												{
													ss << "       " << Local_name << " <= (OTHERS => '0');" << endl;
												}
											}
										}
										else if (ParentType == 2)
										{
											ss << "       " << Local_name << " <= '0';" << endl;
										}
									}
									else if (Size > 1)
									{
										if (InferType == 2)
										{
											if (HT.findfact("type_def(" + to_string(ParentType) + ",_,_,\"user\",_,\"record_t\",_,_,_)"))
											{
												if (TypeEntry > ParentType)
												{
													ss << "       " << Local_name << " <= (OTHERS => '0');" << endl;
												}
											}
										}
									}
								}
								else if (HT.findfact("type_def(_,_,_,\"user\",_,\"single_t\",0,0,0)"))
								{
									Size = stoi(returnpar(HT.findandreturn("type_def(_,_,_,\"user\",_,\"single_t\",0,0,0)"), 3));
									ParentType = stoi(returnpar(HT.findandreturn("type_def(_,_,_,\"user\",_,\"single_t\",0,0,0)"), 5));
									if (Size == 1)
									{
										if (ParentType == 2)
										{
											ss << "       " << Local_name << " <= '0';" << endl;
										}
									}
								}
							}
							else if (Local_size > 1)
							{
								if (HT.findfact("type_def(_," + Type_name + ",_,\"user\",_,\"single_t\",0,0,0)"))
								{
									TypeEntry = stoi(returnpar(HT.findandreturn("type_def(_," + Type_name + ",_,\"user\",_,\"single_t\",0,0,0)"), 1));
									Size = stoi(returnpar(HT.findandreturn("type_def(_," + Type_name + ",_,\"user\",_,\"single_t\",0,0,0)"), 3));
									ParentType = stoi(returnpar(HT.findandreturn("type_def(_," + Type_name + ",_,\"user\",_,\"single_t\",0,0,0)"), 5));
									InferType = stoi(returnpar(HT.findandreturn("type_def(_," + Type_name + ",_,\"user\",_,\"single_t\",0,0,0)"), 9));
									if (Size > 1)
									{
										if (InferType == 2)
										{
											if (HT.findfact("type_def(" + to_string(ParentType) + ",_,_,\"user\",_,\"record_t\",_,_,_)"))
											{
												if (TypeEntry > ParentType)
												{
													ss << "       " << Local_name << " <= (OTHERS => '0');" << endl;
												}
											}
										}
										else if (ParentType == 2)
										{
											ss << "       " << Local_name << " <= (OTHERS => '0');" << endl;
										}
									}
									else if (Size == 1)
									{
										if (InferType == 2)
										{
											if (HT.findfact("type_def(" + to_string(ParentType) + ",_,_,\"user\",_,\"record_t\",_,_,_)"))
											{
												if (TypeEntry > ParentType)
												{
													ss << "       " << Local_name << " <= (OTHERS => '0');" << endl;
												}
											}
										}
									}
								}
								else if (HT.findfact("type_def(_,_,_,\"user\",_,\"single_t\",0,0,0)"))
								{
									Size = stoi(returnpar(HT.findandreturn("type_def(_,_,_,\"user\",_,\"single_t\",0,0,0)"), 3));
									ParentType = stoi(returnpar(HT.findandreturn("type_def(_,_,_,\"user\",_,\"single_t\",0,0,0)"), 5));
									if (Size > 1)
									{
										if (ParentType == 2)
										{
											ss << "       " << Local_name << " <= (OTHERS => '0');" << endl;
										}
									}
								}
							}
						}
					}
				}
			}
			else if (var7 == "userarray")
			{
				if (Local_kind != "variable")
				{
					if (Local_kind != "constant")
					{
						if (Local_kind != "par_in")
						{
							if (HT.findfact("type_def(_," + Type_name + "," + to_string(Local_size) + ",\"user\",0,\"vectorarray_t\",_,_,_)"))
							{
								Comp_type = stoi(returnpar(HT.findandreturn("type_def(_," + Type_name + "," + to_string(Local_size) + ",\"user\",0,\"vectorarray_t\",_,_,_)"), 9));
								if (HT.findfact("type_def(" + to_string(Comp_type) + ",\"boolean\",1,\"standard\",0,\"single_t\",0,0,0)"))
								{
									ss << "       " << Local_name << " <= (OTHERS => '0');" << endl;
								}
							}
							else if (HT.findfact("type_def(_," + Type_name + ",_,\"user\",0,\"vectorarray_t\",_,_,_)"))
							{
								Type_entry = stoi(returnpar(HT.findandreturn("type_def(_," + Type_name + ",_,\"user\",0,\"vectorarray_t\",_,_,_)"), 1));
								Firstd = stoi(returnpar(HT.findandreturn("type_def(_," + Type_name + ",_,\"user\",0,\"vectorarray_t\",_,_,_)"), 7));
								Dimmension = stoi(returnpar(HT.findandreturn("type_def(_," + Type_name + ",_,\"user\",0,\"vectorarray_t\",_,_,_)"), 8));
								Comp_type = stoi(returnpar(HT.findandreturn("type_def(_," + Type_name + ",_,\"user\",0,\"vectorarray_t\",_,_,_)"), 9));
								if (Comp_type > 1)
								{
									if (HT.findfact("type_def(" + to_string(Comp_type) + ",_,1,_,_,\"single_t\",_,_,_)"))
									{
										Lastd = Firstd + Dimmension - 1;
										ss << "       FOR " << Local_name << "_i IN " << Firstd << " TO " << Lastd << " LOOP" << endl;
										ss << "        " << Local_name << "(" << Local_name << "_i) <= '0';" << endl;
										ss << "       END LOOP;" << endl;
									}
									else if (HT.findfact("type_def(" + to_string(Comp_type) + ",_,_,_,_,\"single_t\",_,_,_)"))
									{
										Comp_type_size = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Comp_type) + ",_,_,_,_,\"single_t\",_,_,_)"), 3));
										if (Comp_type_size > 1)
										{
											Lastd = Firstd + Dimmension - 1;
											ss << "       FOR " << Local_name << "_i IN " << Firstd << " TO " << Lastd << " LOOP" << endl;
											ss << "        " << Local_name << "(" << Local_name << "_i) <= (OTHERS => '0');" << endl;
											ss << "       END LOOP;" << endl;
										}
									}
									else if (HT.findfact("type_def(" + to_string(Comp_type) + ", _, _, _, _, \"record_t\",_,_,_)"))
									{
										Number_of_fields = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Comp_type) + ",_,_,_,_,\"record_t\",_,_,_)"), 8));
										First_comp_type = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Comp_type) + ",_,_,_,_,\"record_t\",_,_,_)"), 9));
										Lastd = Firstd + Dimmension - 1;
										ss << "       FOR " << Local_name << "_i IN " << Firstd << " TO " << Lastd << " LOOP" << endl;
										ss << "        " << Local_name << "(" << Local_name << "_i) <= (";
										ss << reset_record_field("vectorarray_t", 1, Number_of_fields, First_comp_type, "vhdl");
										ss << ");" << endl;
										ss << "       END LOOP;" << endl;
									}
									else if (HT.findfact("type_def(" + to_string(Comp_type) + ", _, _, _, _, \"vectorarray_t\",_,_,_)"))
									{
										ss << reset_multi_array(Local_name, Type_entry, 1, &Dimension_depth, &Last_comp_type, 1);
										ss << "        " << Local_name;
										ss << write_array_dim_depth(Local_name, 1, Dimension_depth);
										ss << write_array_comp_reset_value(Last_comp_type);
										ss << write_array_end_loop(Dimension_depth);
									}
								}
							}
							else if (HT.findfact("type_def(_," + Type_name + ",_,\"user\",_,\"vectorarray_t\",_,_,_)"))
							{
								ParentType = stoi(returnpar(HT.findandreturn("type_def(_," + Type_name + ",_,\"user\",_,\"vectorarray_t\",_,_,_)"), 1));
								Firstd = stoi(returnpar(HT.findandreturn("type_def(_," + Type_name + ",_,\"user\",_,\"vectorarray_t\",_,_,_)"), 7));
								Dimmension = stoi(returnpar(HT.findandreturn("type_def(_," + Type_name + ",_,\"user\",_,\"vectorarray_t\",_,_,_)"), 8));
								Comp_type = stoi(returnpar(HT.findandreturn("type_def(_," + Type_name + ",_,\"user\",_,\"vectorarray_t\",_,_,_)"), 9));
								if (Comp_type > 1)
								{
									if (HT.findfact("type_def(" + to_string(ParentType) + ",_,_,_,_,\"record_t\",_,_,_)"))
									{
										Lastd = Firstd + Dimmension - 1;
										ss << "       " << Local_name << " <= (OTHERS => (OTHERS => '0'));" << endl;
									}
								}
							}
						}
					}
				}
			}
			else if (var7 == "userrecord")
			{
				if (Local_size == 1)
				{
					if (Local_kind != "variable")
					{
						if (Local_kind != "constant")
						{
							if (Local_kind != "par_in")
							{
								if (HT.findfact("type_def(1," + Type_name + ",_,_,_,\"single_t\",0,_,_)"))
								{
									ss << "       " << Local_name << " <= false;" << endl;
								}
								else if (HT.findfact("type_def(_," + Type_name + ",_,_,_,\"single_t\",0,_,1)"))
								{
									ss << "       " << Local_name << " <= false;" << endl;
								}
								else if (HT.findfact("type_def(_," + Type_name + ",_,_,_,\"single_t\",0,_,_)"))
								{
									Inh_type = stoi(returnpar(HT.findandreturn("type_def(_," + Type_name + ",_,_,_,\"single_t\",0,_,_)"), 9));
									if (Inh_type != 1)
									{
										ss << "       " << Local_name << " <= '0';" << endl;
									}
								}
							}
						}
					}
				}
				else if (Local_kind != "variable")
				{
					if (Local_kind != "constant")
					{
						if (Local_kind != "par_in")
						{
							if (HT.findfact("type_def(_," + Type_name + ",_,\"user\",0,\"record_t\",0,_,_)"))
							{
								RecType = stoi(returnpar(HT.findandreturn("type_def(_," + Type_name + ",_,\"user\",0,\"record_t\",0,_,_)"), 1));
								Number_of_fields = stoi(returnpar(HT.findandreturn("type_def(_," + Type_name + ",_,\"user\",0,\"record_t\",0,_,_)"), 8));
								First_comp_type = stoi(returnpar(HT.findandreturn("type_def(_," + Type_name + ",_,\"user\",0,\"record_t\",0,_,_)"), 9));
								if (HT.findfact("type_def(_,_,_,\"user\"," + to_string(RecType) + ",_,0,_,_)"))
								{
									Kind = returnpar(HT.findandreturn("type_def(_,_,_,\"user\"," + to_string(RecType) + ",_,0,_,_)"), 6);
									if (Kind != "vectorarray_t")
									{
										ss << "       " << Local_name << " <= ( ";
										ss << reset_record_field("record_t", 1, Number_of_fields, First_comp_type, "vhdl");
										ss << ");" << endl;
									}
								}
							}
							else if (HT.findfact("type_def(_," + Type_name + ",_,\"user\",0,\"record_t\",_,_,_)"))
							{
								RecType = stoi(returnpar(HT.findandreturn("type_def(_," + Type_name + ",_,\"user\",0,\"record_t\",_,_,_)"), 1));
								Number_of_fields = stoi(returnpar(HT.findandreturn("type_def(_," + Type_name + ",_,\"user\",0,\"record_t\",_,_,_)"), 8));
								First_comp_type = stoi(returnpar(HT.findandreturn("type_def(_," + Type_name + ",_,\"user\",0,\"record_t\",_,_,_)"), 9));
								if (HT.findfact("type_def(_,_,_,\"user\"," + to_string(RecType) + ",_,0,_,_)"))
								{
									Kind = returnpar(HT.findandreturn("type_def(_,_,_,\"user\"," + to_string(RecType) + ",_,0,_,_)"), 6);
									Comp_type = stoi(returnpar(HT.findandreturn("type_def(_,_,_,\"user\"," + to_string(RecType) + ",_,0,_,_)"), 9));
									if (Kind == "vectorarray_t")
									{
										if (Comp_type > 9)
										{
											ss << "       " << Local_name << " <= (OTHERS => (OTHERS => (OTHERS => '0'))) ;" << endl;
										}
									}
								}
							}
						}
					}
				}
				else if (HT.findfact("type_def(_," + Type_name + ",_,_,_,\"single_t\",0,_,_)"))
				{
					Inh_type = stoi(returnpar(HT.findandreturn("type_def(_," + Type_name + ",_,_,_,\"single_t\",0,_,_)"), 9));
					if (Inh_type != 1)
					{
						ss << "       " << Local_name << " <= ( OTHERS => '0' );" << endl;
					}
				}
			}
			else if (Type_name == "std_logic")
			{
				if (Local_size == 1)
				{
					if (Local_kind != "variable")
					{
						if (Local_kind != "constant")
						{
							if (Local_kind != "par_in")
							{
								ss << "       " << Local_name << " <= '0';" << endl;
							}
						}
					}
				}
			}
		}
		else if (HDL == "verilog")
		{
			if (var7 == "standard")
			{
				if (be == "bit_wire" && af == "std_logic")
				{
					if (Local_kind != "variable")
					{
						if (Local_kind != "constant")
						{
							if (Local_kind != "par_in")
							{
								if (Local_size >= 1)
								{
									if (HT.findfact("type_def(_," + Type_name + ",_,\"user\",_,_,_,_,_)"))
									{
										Size = stoi(returnpar(HT.findandreturn("type_def(_," + Type_name + ",_,\"user\",_,_,_,_,_)"), 3));
										Type_kind = returnpar(HT.findandreturn("type_def(_," + Type_name + ",_,\"user\",_,_,_,_,_)"), 6);
										if (Type_kind != "single_t")
										{
											if (Size != Local_size)
											{
												ss << write_depending_on_kind(Local_name, Local_kind, &Local_name_app);
												ss << "       " << Local_name_app << " <= 0;" << endl;
											}
										}
									}
								}
							}
						}
					}
				}
				else if (Local_size == 1)
				{
					if (Type_name == "bool")
					{
						if (Local_kind != "variable")
						{
							if (Local_kind != "constant")
							{
								if (Local_kind != "par_in")
								{
									ss << write_depending_on_kind(Local_name, Local_kind, &Local_name_app);
									ss << "       " << Local_name_app << " <= 1'b0;" << endl;
								}
							}
						}
					}
					else if (Type_name == "std_logic")
					{
						if (Local_kind != "variable")
						{
							if (Local_kind != "constant")
							{
								if (Local_kind != "par_in")
								{
									ss << write_depending_on_kind(Local_name, Local_kind, &Local_name_app);
									ss << "       " << Local_name_app << " <= 1'b0;" << endl;
								}
							}
						}
					}
					if (Local_kind != "variable")
					{
						if (Local_kind != "constant")
						{
							if (Local_kind != "par_in")
							{
								if (HT.findfact("type_def(_,Type_name,_,\"user\",_,\"single_t\",0,0,0)"))
								{
									Size = stoi(returnpar(HT.findandreturn("type_def(_,Type_name,_,\"user\",_,\"single_t\",0,0,0)"), 3));
									ParentType = stoi(returnpar(HT.findandreturn("type_def(_,Type_name,_,\"user\",_,\"single_t\",0,0,0)"), 5));
									if (Size >= 1)
									{
										if (ParentType == 2)
										{
											write_depending_on_kind(Local_name, Local_kind, &Local_name_app);
											ss << "       " << Local_name_app << " <= 0;" << endl;
										}
									}
								}
								else if (HT.findfact("type_def(_," + Type_name + ",_,\"user\",_,\"single_t\",0,0,_)"))
								{
									TypeEntry = stoi(returnpar(HT.findandreturn("type_def(_," + Type_name + ",_,\"user\",_,\"single_t\",0,0,_)"), 1));
									Size = stoi(returnpar(HT.findandreturn("type_def(_," + Type_name + ",_,\"user\",_,\"single_t\",0,0,_)"), 3));
									ParentType = stoi(returnpar(HT.findandreturn("type_def(_," + Type_name + ",_,\"user\",_,\"single_t\",0,0,_)"), 5));
									InferType = stoi(returnpar(HT.findandreturn("type_def(_," + Type_name + ",_,\"user\",_,\"single_t\",0,0,_)"), 9));
									if (Size >= 1)
									{
										if (InferType == 2)
										{
											if (HT.findfact("type_def(" + to_string(ParentType) + ",_,_,\"user\",_,\"record_t\",_,_,_)"))
											{
												if (TypeEntry > ParentType)
												{
													ss << write_depending_on_kind(Local_name, Local_kind, &Local_name_app);
													ss << "       " << Local_name_app << " <= 0;" << endl;
												}
											}
										}
									}
								}
							}
						}
					}
				}
				if (Local_size > 1)
				{
					if (Type_name == "std_logic")
					{
						if (Local_kind != "variable")
						{
							if (Local_kind != "constant")
							{
								if (Local_kind != "par_in")
								{
									ss << write_depending_on_kind(Local_name, Local_kind, &Local_name_app);
									ss << "       " << Local_name_app << " <= 0;" << endl;
								}
							}
						}
					}
					else if (Type_name == "integer")
					{
						if (Local_kind != "variable")
						{
							if (Local_kind != "constant")
							{
								if (Local_kind != "par_in")
								{
									ss << write_depending_on_kind(Local_name, Local_kind, &Local_name_app);
									ss << "       " << Local_name_app << " <= 0;" << endl;
								}
							}
						}
					}
					else if (Type_name == "fixed_point")
					{
						if (Local_kind != "variable")
						{
							if (Local_kind != "constant")
							{
								if (Local_kind != "par_in")
								{
									ss << write_depending_on_kind(Local_name, Local_kind, &Local_name_app);
									ss << "       " << Local_name_app << " <= 0;" << endl;
								}
							}
						}
					}
					else if (Type_name == "natural")
					{
						if (Local_kind != "variable")
						{
							if (Local_kind != "constant")
							{
								if (Local_kind != "par_in")
								{
									ss << write_depending_on_kind(Local_name, Local_kind, &Local_name_app);
									ss << "       " << Local_name_app << " <= 0;" << endl;
								}
							}
						}
					}
					if (Local_kind != "variable")
					{
						if (Local_kind != "constant")
						{
							if (Local_kind != "par_in")
							{
								if (HT.findfact("type_def(_,Type_name,_,\"user\",_,\"single_t\",0,0,0)"))
								{
									Size = stoi(returnpar(HT.findandreturn("type_def(_,Type_name,_,\"user\",_,\"single_t\",0,0,0)"), 3));
									ParentType = stoi(returnpar(HT.findandreturn("type_def(_,Type_name,_,\"user\",_,\"single_t\",0,0,0)"), 5));
									if (Size >= 1)
									{
										if (ParentType == 2)
										{
											write_depending_on_kind(Local_name, Local_kind, &Local_name_app);
											ss << "       " << Local_name_app << " <= 0;" << endl;
										}
									}
								}
								else if (HT.findfact("type_def(_," + Type_name + ",_,\"user\",_,\"single_t\",0,0,_)"))
								{
									TypeEntry = stoi(returnpar(HT.findandreturn("type_def(_," + Type_name + ",_,\"user\",_,\"single_t\",0,0,_)"), 1));
									Size = stoi(returnpar(HT.findandreturn("type_def(_," + Type_name + ",_,\"user\",_,\"single_t\",0,0,_)"), 3));
									ParentType = stoi(returnpar(HT.findandreturn("type_def(_," + Type_name + ",_,\"user\",_,\"single_t\",0,0,_)"), 5));
									InferType = stoi(returnpar(HT.findandreturn("type_def(_," + Type_name + ",_,\"user\",_,\"single_t\",0,0,_)"), 9));
									if (Size >= 1)
									{
										if (InferType == 2)
										{
											if (HT.findfact("type_def(" + to_string(ParentType) + ",_,_,\"user\",_,\"record_t\",_,_,_)"))
											{
												if (TypeEntry > ParentType)
												{
													ss << write_depending_on_kind(Local_name, Local_kind, &Local_name_app);
													ss << "       " << Local_name_app << " <= 0;" << endl;
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
			else if (var7 == "userarray")
			{
				if (Local_kind != "variable")
				{
					if (Local_kind != "constant")
					{
						if (Local_kind != "par_in")
						{
							if (HT.findfact("type_def(_," + Type_name + "," + to_string(Local_size) + ",\"user\",0,\"vectorarray_t\",_,_,_)"))
							{
								Comp_type = stoi(returnpar(HT.findandreturn("type_def(_," + Type_name + "," + to_string(Local_size) + ",\"user\",0,\"vectorarray_t\",_,_,_)"), 9));
								if (HT.findfact("type_def(" + to_string(Comp_type) + ",\"boolean\",1,\"standard\",0,\"single_t\",0,0,0)"))
								{
									ss << write_depending_on_kind(Local_name, Local_kind, &Local_name_app);
									ss << "       " << Local_name_app << " <= 0;" << endl;
								}
							}
							else if (HT.findfact("type_def(_," + Type_name + ",_,\"user\",0,\"vectorarray_t\",_,_,_)"))
							{
								Type_entry = stoi(returnpar(HT.findandreturn("type_def(_," + Type_name + ",_,\"user\",0,\"vectorarray_t\",_,_,_)"), 1));
								Firstd = stoi(returnpar(HT.findandreturn("type_def(_," + Type_name + ",_,\"user\",0,\"vectorarray_t\",_,_,_)"), 7));
								Dimmension = stoi(returnpar(HT.findandreturn("type_def(_," + Type_name + ",_,\"user\",0,\"vectorarray_t\",_,_,_)"), 8));
								Comp_type = stoi(returnpar(HT.findandreturn("type_def(_," + Type_name + ",_,\"user\",0,\"vectorarray_t\",_,_,_)"), 9));
								if (Comp_type > 1)
								{
									if (HT.findfact("type_def(" + to_string(Comp_type) + ",_,_,_,_,\"single_t\",_,_,_)"))
									{
										Comp_type_size = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Comp_type) + ",_,_,_,_,\"single_t\",_,_,_)"), 3));
										if (Comp_type_size > 1)
										{
											Lastd = Firstd + Dimmension - 1;
											ss << "       for  (" << Local_name << "_i = " << Firstd << "; " << Local_name << "_i <= " << Lastd << "; " << Local_name << "_i = " << Local_name << "_i + 1 )" << endl;
											ss << write_depending_on_kind(Local_name, Local_kind, &Local_name_app);
											ss << "        " << Local_name_app << "[" << Local_name << "_i] <= 0;" << endl;
										}
									}
									else if (HT.findfact("type_def(" + to_string(Comp_type) + ",_,1,_,_,\"single_t\",_,_,_)"))
									{
										Lastd = Firstd + Dimmension - 1;
										ss << write_depending_on_kind(Local_name, Local_kind, &Local_name_app);
										ss << "       " << Local_name_app << " <= 0;" << endl;
									}
									else if (HT.findfact("type_def(" + to_string(Comp_type) + ",_,_,_,_,\"record_t\",_,_,_)"))
									{
										Rec_field = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Comp_type) + ",_,_,_,_,\"record_t\",_,_,_)"), 9));
										if (HT.findfact("type_def(" + to_string(Rec_field) + ",_,_,_,_,\"single_t\",_,_,_)"))
										{
											Lastd = Firstd + Dimmension - 1;
											ss << write_depending_on_kind(Local_name, Local_kind, &Local_name_app);
											ss << "       for  (" << Local_name << "_i = " << Firstd << "; " << Local_name << "_i <= " << Lastd << "; " << Local_name << "_i = " << Local_name << "_i + 1 )" << endl;
											ss << "        " << Local_name_app << "[" << Local_name << "_i] <= 0;" << endl;
										}
									}
									else if (HT.findfact("type_def(" + to_string(Comp_type) + ",_,_,_,_,\"vectorarray_t\",_,_,_)"))
									{
										ss << reset_multi_array(Local_name, Type_entry, 1, &Dimension_depth, &Last_comp_type, 1);
										ss << write_depending_on_kind(Local_name, Local_kind, &Local_name_app);
										ss << "        " << Local_name_app;
										ss << write_array_dim_depth(Local_name, 1, Dimension_depth);
										ss << write_array_comp_reset_value(Last_comp_type);
										ss << ";" << endl;
									}
								}
							}
							else if (HT.findfact("type_def(_," + Type_name + ",_,\"user\",_,\"vectorarray_t\",_,_,_)"))
							{
								Comp_type = stoi(returnpar(HT.findandreturn("type_def(_," + Type_name + ",_,\"user\",_,\"vectorarray_t\",_,_,_)"), 1));
								Firstd = stoi(returnpar(HT.findandreturn("type_def(_," + Type_name + ",_,\"user\",_,\"vectorarray_t\",_,_,_)"), 7));
								Dimmension = stoi(returnpar(HT.findandreturn("type_def(_," + Type_name + ",_,\"user\",_,\"vectorarray_t\",_,_,_)"), 8));
								Comp_type1 = stoi(returnpar(HT.findandreturn("type_def(_," + Type_name + ",_,\"user\",_,\"vectorarray_t\",_,_,_)"), 9));
								if (Comp_type > 1)
								{
									if (HT.findfact("type_def(" + to_string(Comp_type1) + ",_,_,_,_,\"vectorarray_t\",_,_,2)"))
									{
										Comp_type_size = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Comp_type1) + ",_,_,_,_,\"vectorarray_t\",_,_,2)"), 3));
										if (Comp_type_size > 1)
										{
											Lastd = Firstd + Dimmension - 1;
											if (HT.concat(".", &Just_field, Type_name))
											{
												if (HT.concat(&Rec_name, Type_name, Local_name))
												{
													HT.concat(Rec_name, "_", &Rec_underscored);
													HT.concat(Rec_underscored, Just_field, &Underscored_name);
													ss << "       for  (" << Underscored_name << "_i1 = " << Firstd << "; " << Underscored_name << "_i1 <= " << Lastd << "; " << Underscored_name << "_i1 = " << Underscored_name << "_i1 + 1 )" << endl;
													ss << write_depending_on_kind(Underscored_name, Local_kind, &Local_name_app);
													ss << "        " << Local_name_app << "[" << Underscored_name << "_i1] <= 0;" << endl;
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
			else if (var7 == "userrecord")
			{
				if (Local_kind != "variable")
				{
					if (Local_kind != "constant")
					{
						if (Local_kind != "par_in")
						{
							if (Local_size == 1)
							{
								if (HT.findfact("type_def(_," + Type_name + ",_,\"user\",0,\"record_t\",0,_,_)"))
								{
									ss << write_depending_on_kind(Local_name, Local_kind, &Local_name_app);
									ss << "       " << Local_name_app << " <= 1'b0;" << endl;
								}
								else if (HT.findfact("type_def(_," + Type_name + ",_,_,_,\"single_t\",0,_,1)"))
								{
									ss << write_depending_on_kind(Local_name, Local_kind, &Local_name_app);
									ss << "       " << Local_name_app << " <= 1'b0;" << endl;
								}
								else if (HT.findfact("type_def(_," + Type_name + ",_,_,_,\"single_t\",0,_,_)"))
								{
									Inh_type = stoi(returnpar(HT.findandreturn("type_def(_," + Type_name + ",_,_,_,\"single_t\",0,_,_)"), 9));
									if (Inh_type != 1)
									{
										ss << write_depending_on_kind(Local_name, Local_kind, &Local_name_app);
										ss << "       " << Local_name_app << " <= 1'b0;" << endl;
									}
								}
							}
							else if (HT.findfact("type_def(_," + Type_name + ",_,\"user\",0,\"record_t\",0,_,_)"))
							{
								ss << write_depending_on_kind(Local_name, Local_kind, &Local_name_app);
								ss << "       " << Local_name_app << " <= 0;" << endl;
							}
							else if (HT.findfact("type_def(_," + Type_name + ",_,_,_,\"single_t\",0,_,_)"))
							{
								Inh_type = stoi(returnpar(HT.findandreturn("type_def(_," + Type_name + ",_,_,_,\"single_t\",0,_,_)"), 9));
								if (Inh_type != 1)
								{
									ss << write_depending_on_kind(Local_name, Local_kind, &Local_name_app);
									ss << "       " << Local_name_app << " <= 1'b0;" << endl;
								}
							}
						}
					}
				}
			}
		}
	}
	else if (Tool == "gnu")
	{
		if (HDL == "c")
		{
			if (Local_kind != "variable")
			{
				if (Local_kind != "constant")
				{
					if (Local_kind != "par_in")
					{
						if (var7 == "standard")
						{
							if (Local_size == 1)
							{
								if (Type_name == "bool")
								{
									ss << "       " << Local_name << " = 0;" << endl;
								}
								else if (Type_name == "std_logic")
								{
									ss << "       " << Local_name << " = 0;" << endl;
								}
								else if (HT.findfact("type_def(_," + Type_name + ",_,\"user\",_,\"single_t\",0,0,0)"))
								{
									Size = stoi(returnpar(HT.findandreturn("type_def(_," + Type_name + ",_,\"user\",_,\"single_t\",0,0,0)"), 3));
									ParentType = stoi(returnpar(HT.findandreturn("type_def(_," + Type_name + ",_,\"user\",_,\"single_t\",0,0,0)"), 5));
									if (Size >= 1)
									{
										if (ParentType == 2)
										{
											ss << "       " << Local_name << " = 0;" << endl;
										}
									}
								}
								else if (HT.findfact("type_def(_," + Type_name + ",_,\"user\",_,\"single_t\",0,0,_)"))
								{
									TypeEntry = stoi(returnpar(HT.findandreturn("type_def(_," + Type_name + ",_,\"user\",_,\"single_t\",0,0,0)"), 1));
									Size = stoi(returnpar(HT.findandreturn("type_def(_," + Type_name + ",_,\"user\",_,\"single_t\",0,0,0)"), 3));
									ParentType = stoi(returnpar(HT.findandreturn("type_def(_," + Type_name + ",_,\"user\",_,\"single_t\",0,0,0)"), 5));
									InferType = stoi(returnpar(HT.findandreturn("type_def(_," + Type_name + ",_,\"user\",_,\"single_t\",0,0,0)"), 9));
									if (InferType == 2)
									{
										if (HT.findfact("type_def(" + to_string(ParentType) + ",_,_,\"user\",_,\"record_t\",_,_,_)"))
										{
											if (TypeEntry > ParentType)
											{
												ss << "       " << Local_name << " = 0;" << endl;
											}
										}
									}
								}
								else if (be == "bit_wire" && af == "std_logic")
								{
									if (HT.findfact("type_def(_," + Type_name + ",_,\"user\",_,_,_,_,_)"))
									{
										Size = stoi(returnpar(HT.findandreturn("type_def(_," + Type_name + ",_,\"user\",_,_,_,_,_)"), 3));
										Type_kind = returnpar(HT.findandreturn("type_def(_," + Type_name + ",_,\"user\",_,_,_,_,_)"), 6);
										if (Type_kind != "single_t")
										{
											if (Size != Local_size)
											{
												ss << "       " << Local_name << " = 0;" << endl;
											}
										}
									}
								}
							}
							else if (Local_size > 1)
							{
								if (Type_name == "std_logic")
								{
									ss << "       " << Local_name << " = 0;" << endl;
								}
								else if (Type_name == "std_logic")
								{
									ss << "       " << Local_name << " = 0;" << endl;
								}
								else if (Type_name == "natural")
								{
									ss << "       " << Local_name << " = 0;" << endl;
								}
								else if (HT.findfact("type_def(_," + Type_name + ",_,\"user\",_,\"single_t\",0,0,0)"))
								{
									Size = stoi(returnpar(HT.findandreturn("type_def(_," + Type_name + ",_,\"user\",_,\"single_t\",0,0,0)"), 3));
									ParentType = stoi(returnpar(HT.findandreturn("type_def(_," + Type_name + ",_,\"user\",_,\"single_t\",0,0,0)"), 5));
									if (Size >= 1)
									{
										if (ParentType == 2)
										{
											ss << "       " << Local_name << " = 0;" << endl;
										}
									}
								}
								else if (HT.findfact("type_def(_," + Type_name + ",_,\"user\",_,\"single_t\",0,0,_)"))
								{
									TypeEntry = stoi(returnpar(HT.findandreturn("type_def(_," + Type_name + ",_,\"user\",_,\"single_t\",0,0,0)"), 1));
									Size = stoi(returnpar(HT.findandreturn("type_def(_," + Type_name + ",_,\"user\",_,\"single_t\",0,0,0)"), 3));
									ParentType = stoi(returnpar(HT.findandreturn("type_def(_," + Type_name + ",_,\"user\",_,\"single_t\",0,0,0)"), 5));
									InferType = stoi(returnpar(HT.findandreturn("type_def(_," + Type_name + ",_,\"user\",_,\"single_t\",0,0,0)"), 9));
									if (InferType == 2)
									{
										if (HT.findfact("type_def(" + to_string(ParentType) + ",_,_,\"user\",_,\"record_t\",_,_,_)"))
										{
											if (TypeEntry > ParentType)
											{
												ss << "       " << Local_name << " = 0;" << endl;
											}
										}
									}
								}
								else if (be == "bit_wire" && af == "std_logic")
								{
									if (HT.findfact("type_def(_," + Type_name + ",_,\"user\",_,_,_,_,_)"))
									{
										Size = stoi(returnpar(HT.findandreturn("type_def(_," + Type_name + ",_,\"user\",_,_,_,_,_)"), 3));
										Type_kind = returnpar(HT.findandreturn("type_def(_," + Type_name + ",_,\"user\",_,_,_,_,_)"), 6);
										if (Type_kind != "single_t")
										{
											if (Size != Local_size)
											{
												ss << "       " << Local_name << " = 0;" << endl;
											}
										}
									}
								}
							}
						}
						else if (var7 == "userarray")
						{
							if (HT.findfact("type_def(_," + Type_name + "," + to_string(Local_size) + ",\"user\",0,\"vectorarray_t\",_,_,_)"))
							{
								Comp_type = stoi(returnpar(HT.findandreturn("type_def(_," + Type_name + "," + to_string(Local_size) + ",\"user\",0,\"vectorarray_t\",_,_,_)"), 9));
								if (HT.findfact("type_def(" + to_string(Comp_type) + ",\"boolean\",1,\"standard\",0,\"single_t\",0,0,0)"))
								{
									ss << "       " << Local_name << " = 0;" << endl;
								}
							}
							else if (HT.findfact("type_def(_," + Type_name + ",_,\"user\",0,\"vectorarray_t\",_,_,_)"))
							{
								Type_entry = stoi(returnpar(HT.findandreturn("type_def(_," + Type_name + ",_,\"user\",0,\"vectorarray_t\",_,_,_)"), 1));
								Firstd = stoi(returnpar(HT.findandreturn("type_def(_," + Type_name + ",_,\"user\",0,\"vectorarray_t\",_,_,_)"), 7));
								Dimmension = stoi(returnpar(HT.findandreturn("type_def(_," + Type_name + ",_,\"user\",0,\"vectorarray_t\",_,_,_)"), 8));
								Comp_type = stoi(returnpar(HT.findandreturn("type_def(_," + Type_name + ",_,\"user\",0,\"vectorarray_t\",_,_,_)"), 9));
								if (Comp_type > 1)
								{
									if (HT.findfact("type_def(" + to_string(Comp_type) + ",_,1,_,_,\"single_t\",_,_,_)"))
									{
										Lastd = Firstd + Dimmension - 1;
										ss << "       for  (" << Local_name << "_i = " << Firstd << "; " << Local_name << "_i <= " << Lastd << "; " << Local_name << "_i = " << Local_name << "_i + 1 )" << endl;
										ss << "        (*" << Local_name << ")[" << Local_name << "_i] = 0;" << endl;
									}
									else if (HT.findfact("type_def(" + to_string(Comp_type) + ",_,_,_,_,\"single_t\",_,_,_)"))
									{
										Comp_type_size = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Comp_type) + ",_,_,_,_,\"single_t\",_,_,_)"), 3));
										if (Comp_type_size > 1)
										{
											Lastd = Firstd + Dimmension - 1;
											ss << "       for  (" << Local_name << "_i = " << Firstd << "; " << Local_name << "_i <= " << Lastd << "; " << Local_name << "_i = " << Local_name << "_i + 1 )" << endl;
											ss << "        (* " << Local_name << ")[" << Local_name << "_i] = 0;" << endl;
										}
									}
									else if (HT.findfact("type_def(" + to_string(Comp_type) + ",_,_,_,_,\"record_t\",_,_,_)"))
									{
										Number_of_fields = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Comp_type) + ",_,_,_,_,\"record_t\",_,_,_)"), 8));
										First_comp_type = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Comp_type) + ",_,_,_,_,\"record_t\",_,_,_)"), 9));
										Lastd = Firstd + Dimmension - 1;
										ss << "       for  (" << Local_name << "_i = " << Firstd << "; " << Local_name << "_i <= " << Lastd << "; " << Local_name << "_i = " << Local_name << "_i + 1 ) {" << endl;
										HT.concat(Local_name, ")[", &Name1);
										HT.concat(Name1, Local_name, &Name2);
										HT.concat(Name2, "_i]", &Prefix_name);
										ss << reset_struct_field("vectorarray_t", Prefix_name, 1, Number_of_fields, First_comp_type, "c") << endl;
										ss << "        }" << endl;
									}
									else if (HT.findfact("type_def(" + to_string(Comp_type) + ",_,_,_,_,\"vectorarray_t\",_,_,_)"))
									{
										ss << reset_multi_array(Local_name, Type_entry, 1, &Dimension_depth, &Last_comp_type, 1);
										ss << "        " << Local_name;
										ss << write_array_dim_depth(Local_name, 1, Dimension_depth);
										ss << write_array_comp_reset_value(Last_comp_type);
										Dim_minus_one = Dimension_depth - 1;
										ss << write_array_end_loop(Dim_minus_one);
									}
								}
							}
						}
						else if (var7 == "userrecord")
						{
							if (Local_size == 1)
							{
								if (HT.findfact("type_def(1," + Type_name + ",_,_,_,\"single_t\",0,_,1)"))
								{
									ss << "       " << Local_name << " = 0;" << endl;
								}
								else if (HT.findfact("type_def(1," + Type_name + ",_,_,_,\"single_t\",0,_,_)"))
								{
									ss << "       " << Local_name << " = 0;" << endl;
								}
								else if (HT.findfact("type_def(_," + Type_name + ",_,_,_,\"single_t\",0,_,_)"))
								{
									Inh_type = stoi(returnpar(HT.findandreturn("type_def(_," + Type_name + ",_,_,_,\"single_t\",0,_,_)"), 9));
									if (Inh_type != 1)
									{
										ss << "       " << Local_name << " = 0;" << endl;
									}
								}
							}
							else if (HT.findfact("type_def(_," + Type_name + ",_,\"user\",0,\"record_t\",0,_,_)"))
							{
								Number_of_fields = stoi(returnpar(HT.findandreturn("type_def(_," + Type_name + ",_,\"user\",0,\"record_t\",0,_,_)"), 8));
								First_comp_type = stoi(returnpar(HT.findandreturn("type_def(_," + Type_name + ",_,\"user\",0,\"record_t\",0,_,_)"), 9));
								ss << reset_struct_field("record_t", Local_name, 1, Number_of_fields, First_comp_type, "c") << endl;
							}
							else if (HT.findfact("type_def(_," + Type_name + ",_,_,_,\"single_t\",0,_,_)"))
							{
								Inh_type = stoi(returnpar(HT.findandreturn("type_def(_," + Type_name + ",_,_,_,\"single_t\",0,_,_)"), 9));
								ss << "       " << Local_name << " = 0;" << endl;
							}
						}
					}
				}
			}
		}
	}
	return ss.str();
}

string reset_record_field(string Kind, int Field_number, int Number_of_fields, int Current_comp_type, string HDL)
{
	stringstream ss;
	int Next_field_number, Next_comp_type;
	if (Field_number <= Number_of_fields)
	{
		ss << reset_record_field_core(Kind, Field_number, Number_of_fields, Current_comp_type, HDL, &Next_field_number, &Next_comp_type);
		ss << reset_record_field(Kind, Next_field_number, Number_of_fields, Next_comp_type, HDL);
	}

	return ss.str();
}

// has 2 times first the VHDL case with exact identical clauses
string reset_record_field_core(string Kind, int Field_number, int Number_of_fields, int Current_comp_type, string HDL, int* Next_field_number, int* Next_comp_type)
{
	stringstream ss;
	int Size, Fields_parent_type;
	string Not_a_single_type;
	if (HDL == "vhdl")
	{
		if (Field_number < Number_of_fields)
		{
			if (HT.findfact("type_def(" + to_string(Current_comp_type) + ",_,_,_,_,\"single_t\",0,0,_)"))
			{
				Size = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Current_comp_type) + ",_,_,_,_,\"single_t\",0,0,_)"), 3));
				Fields_parent_type = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Current_comp_type) + ",_,_,_,_,\"single_t\",0,0,_)"), 9));
				if (Fields_parent_type > 1)
				{
					if (Size > 1)
					{
						ss << " (OTHERS => '0'), ";
						*Next_field_number = Field_number + 1;
						*Next_comp_type = Current_comp_type + 1;
					}
					else if (Size == 1)
					{
						ss << " '0', ";
						*Next_field_number = Field_number + 1;
						*Next_comp_type = Current_comp_type + 1;
					}
				}
				else if (Fields_parent_type == 1)
				{
					ss << " false, ";
					*Next_field_number = Field_number + 1;
					*Next_comp_type = Current_comp_type + 1;
				}
			}
			else if (HT.findfact("type_def(" + to_string(Current_comp_type) + ",*)"))
			{
				Not_a_single_type = returnpar(HT.findandreturn("type_def(" + to_string(Current_comp_type) + ",*)"), 6);
				Fields_parent_type = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Current_comp_type) + ",*)"), 9));
				if (Not_a_single_type != "single_t")
				{
					ss << " (OTHERS => '0') ";
					*Next_field_number = Field_number + 1;
					*Next_comp_type = Current_comp_type + 1;
				}
			}
		}
	}
	return ss.str();
}

string reset_multi_array(string Local_name, int Type_entry, int Dimension_depth, int* Total_depth, int* Last_comp_type, int Declare_index)
{
	stringstream ss;
	string HDL;
	int Comp_type, Next_dimension_depth;
	if (HT.findfact("type_def(Type_entry,_,_,_,_,\"record_t\",_,_,_)") || HT.findfact("type_def(Type_entry,_,_,_,_,\"single_t\",_,_,_)"))
		return ss.str();
	if (HT.findfact("hdl_style(*)"))
	{
		HDL = returnpar(HT.findandreturn("hdl_style(*)"), 1);
		if (HT.findfact("type_def(" + to_string(Type_entry) + ",_,_,_,_,\"vectorarray_t\",_,_,_)"))
		{
			Comp_type = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Type_entry) + ",_,_,_,_,\"vectorarray_t\",_,_,_)"), 9));
			ss << reset_a_dimension(Local_name, Type_entry, Dimension_depth, HDL, Declare_index);
			Next_dimension_depth = Dimension_depth + 1;
			ss << reset_multi_array(Local_name, Comp_type, Next_dimension_depth, Total_depth, Last_comp_type, Declare_index);
		}
	}
	return ss.str();
}

string reset_a_dimension(string Local_name, int Type_entry, int Dimension_depth, string HDL, int Declare_index)
{
	stringstream ss;
	int Firstd, Dimmension, Lastd;
	if (HDL == "vhdl")
	{
		if (HT.findfact("type_def(" + to_string(Type_entry) + ",_,_,\"user\",0,\"vectorarray_t\",_,_,_)"))
		{
			Firstd = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Type_entry) + ",_,_,\"user\",0,\"vectorarray_t\",_,_,_)"), 7));
			Dimmension = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Type_entry) + ",_,_,\"user\",0,\"vectorarray_t\",_,_,_)"), 8));
			Lastd = Firstd + Dimmension - 1;
			ss << "       FOR " << Local_name << "_i" << Dimension_depth << " IN " << Firstd << " TO " << Lastd << " LOOP" << endl;
		}
	}
	else if (HDL == "verilog")
	{
		if (HT.findfact("type_def(" + to_string(Type_entry) + ",_,_,\"user\",0,\"vectorarray_t\",_,_,_)"))
		{
			Firstd = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Type_entry) + ",_,_,\"user\",0,\"vectorarray_t\",_,_,_)"), 7));
			Dimmension = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Type_entry) + ",_,_,\"user\",0,\"vectorarray_t\",_,_,_)"), 8));
			Lastd = Firstd + Dimmension - 1;
			ss << "       for  (" << Local_name << "_i" << Dimension_depth << " = " << Firstd << "; " << Local_name << "_i" << Dimension_depth << "  <= " << Lastd << "; " << Local_name << "_i" << Dimension_depth << " = " << Local_name << "_i" << Dimension_depth << " + 1 )" << endl;
		}
	}
	else if (HDL == "c")
	{
		if (HT.findfact("type_def(" + to_string(Type_entry) + ",_,_,\"user\",0,\"vectorarray_t\",_,_,_)"))
		{
			Firstd = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Type_entry) + ",_,_,\"user\",0,\"vectorarray_t\",_,_,_)"), 7));
			Dimmension = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Type_entry) + ",_,_,\"user\",0,\"vectorarray_t\",_,_,_)"), 8));
			Lastd = Firstd + Dimmension - 1;
			ss << declare_index(Declare_index, Local_name, Dimension_depth);
			ss << "       for  (" << Local_name << "_i" << Dimension_depth << " = " << Firstd << "; " << Local_name << "_i" << Dimension_depth << "  <= " << Lastd << "; " << Local_name << "_i" << Dimension_depth << " = " << Local_name << "_i" << Dimension_depth << " + 1 ) {" << endl;
		}
	}
	return ss.str();
}

string declare_index(int Declare, string Local_name, int Dimension_depth)
{
	stringstream ss;
	if (Declare == 1)
		ss << "       int " << Local_name << "_i" << Dimension_depth << " ;" << endl;
	return ss.str();
}

string write_array_dim_depth(string Local_name, int Input_index, int Dimension_depth) //recursive non stop?
{
	stringstream ss;
	if (Input_index != Dimension_depth)
	{
		int Next_index;
		ss << write_array_dim_depth_core(Local_name, Input_index, Dimension_depth, &Next_index);
		ss << write_array_dim_depth(Local_name, Next_index, Dimension_depth);
	}
	return ss.str();
}

string write_array_dim_depth_core(string Local_name, int Input_index, int Dimension_depth, int* Next_index)
{
	stringstream ss;
	if (HT.findfact("hdl_style(\"vhdl\")"))
	{
		if (Input_index < Dimension_depth)
		{
			ss << "(" << Local_name << "_i" << Input_index << ")";
			*Next_index = Input_index + 1;
		}
	}
	else if (HT.findfact("hdl_style(\"verilog\")") || HT.findfact("hdl_style(\"c\")"))
	{
		ss << "[" << Local_name << "_i" << Input_index << "]";
		*Next_index = Input_index + 1;
	}
	return ss.str();
}

string write_array_comp_reset_value(int Last_comp_type)
{
	stringstream ss;
	int Type_size, Number_of_dims, First_comp;
	if (Last_comp_type == 1)
	{
		if (HT.findfact("hdl_style(\"vhdl\")"))
		{
			if (HT.findfact("type_def(1,_,1,_,_,\"single_t\",_,_,_)"))
			{
				ss << " <= FALSE;" << endl;
			}
		}
		else if (HT.findfact("hdl_style(\"verilog\")"))
		{
			if (HT.findfact("type_def(1,_,1,_,_,\"single_t\",_,_,_)"))
			{
				ss << " <= 1'b0";
			}
		}
		else if (HT.findfact("hdl_style(\"c\")"))
		{
			if (HT.findfact("type_def(1,_,1,_,_,\"single_t\",_,_,_)"))
			{
				ss << " = 0;" << endl;
			}
		}
	}
	else if (HT.findfact("hdl_style(\"vhdl\")"))
	{
		if (HT.findfact("type_def(" + to_string(Last_comp_type) + ",_,1,_,_,\"single_t\",_,_,_)"))
		{
			if (Last_comp_type > 1)
			{
				ss << " <= '0';" << endl;
			}
		}
		else if (HT.findfact("type_def(" + to_string(Last_comp_type) + ",_,_,_,_,\"single_t\",_,_,_)"))
		{
			Type_size = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Last_comp_type) + ",_,_,_,_,\"single_t\",_,_,_)"), 3));
			if (Last_comp_type > 1)
			{
				if (Type_size > 1)
				{
					ss << " <= (OTHERS => '0');" << endl;
				}
			}
		}
		else if (HT.findfact("type_def(" + to_string(Last_comp_type) + ",_,_,_,_,\"record_t\",_,_,_)"))
		{
			Type_size = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Last_comp_type) + ",_,_,_,_,\"record_t\",_,_,_)"), 3));
			Number_of_dims = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Last_comp_type) + ",_,_,_,_,\"record_t\",_,_,_)"), 8));
			First_comp = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Last_comp_type) + ",_,_,_,_,\"record_t\",_,_,_)"), 9));
			if (Last_comp_type > 1)
			{
				if (Type_size > 1)
				{
					ss << " <= ( ";
					ss << write_record_reset_aggregate(0, Number_of_dims, First_comp);
					ss << ");" << endl;
				}
			}
		}
	}
	else if (HT.findfact("hdl_style(\"verilog\")"))
	{
		if (HT.findfact("type_def(" + to_string(Last_comp_type) + ",_,1,_,_,\"single_t\",_,_,_)"))
		{
			if (Last_comp_type > 1)
			{
				ss << " <= 1'b0";
			}
		}
		else if (HT.findfact("type_def(" + to_string(Last_comp_type) + ",_,_,_,_,\"single_t\",_,_,_)"))
		{
			Type_size = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Last_comp_type) + ",_,_,_,_,\"single_t\",_,_,_)"), 3));
			if (Last_comp_type > 1)
			{
				if (Type_size > 1)
				{
					ss << " <= 0";
				}
			}
		}
		else if (HT.findfact("type_def(" + to_string(Last_comp_type) + ",_,_,_,_,\"record_t\",_,_,_)"))
		{
			Type_size = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Last_comp_type) + ",_,_,_,_,\"record_t\",_,_,_)"), 3));
			if (Last_comp_type > 1)
			{
				if (Type_size > 1)
				{
					ss << " <= 0";
				}
			}
		}
	}
	else if (HT.findfact("hdl_style(\"c\")"))
	{
		if (HT.findfact("type_def(" + to_string(Last_comp_type) + ",_,1,_,_,\"single_t\",_,_,_)"))
		{
			if (Last_comp_type > 1)
			{
				ss << " = 0;" << endl;
			}
		}
		else if (HT.findfact("type_def(" + to_string(Last_comp_type) + ",_,_,_,_,\"single_t\",_,_,_)"))
		{
			Type_size = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Last_comp_type) + ",_,_,_,_,\"single_t\",_,_,_)"), 3));
			if (Last_comp_type > 1)
			{
				if (Type_size > 1)
				{
					ss << " = 0;" << endl;
				}
			}
		}
		else if (HT.findfact("type_def(" + to_string(Last_comp_type) + ",_,_,_,_,\"record_t\",_,_,_)"))
		{
			Type_size = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Last_comp_type) + ",_,_,_,_,\"record_t\",_,_,_)"), 3));
			if (Last_comp_type > 1)
			{
				if (Type_size > 1)
				{
					ss << " = 0;" << endl;
				}
			}
		}
	}
	return ss.str();
}

string write_record_reset_aggregate(int In_dim, int Number_of_dims, int In_comp)
{
	int Next_dim, Next_comp;
	stringstream ss;
	if (In_dim == Number_of_dims - 1)
	{
		if (HT.findfact("type_def(" + to_string(In_comp) + ",_,_,_,_,\"single_t\",_,_,_)"))
		{
			ss << "(OTHERS => '0')";
		}
	}
	else if (In_dim < Number_of_dims - 1)
	{
		if (HT.findfact("type_def(" + to_string(In_comp) + ",_,_,_,_,\"single_t\",_,_,_)"))
		{
			ss << "(OTHERS => '0'),";
			Next_dim = In_dim + 1;
			Next_comp = In_comp + 1;
			ss << write_record_reset_aggregate(Next_dim, Number_of_dims, Next_comp);
		}
	}
	return ss.str();
}

string write_array_end_loop(int Dimension_depth)
{
	stringstream ss;
	int Next_dimension_depth;
	if (Dimension_depth == 1)
	{
		if (HT.findfact("hdl_style(\"vhdl\")"))
			return ss.str();
		if (HT.findfact("hdl_style(\"verilog\")"))
			ss << ";" << endl;
		if (HT.findfact("hdl_style(\"c\")"))
			ss << "       };" << endl;
	}
	else
	{
		ss << write_array_end_loop_core(Dimension_depth, &Next_dimension_depth);
		ss << write_array_end_loop(Next_dimension_depth);
	}
	return ss.str();
}

string write_array_end_loop_core(int Dimension_depth, int* Next_dimension_depth)
{
	stringstream ss;
	if (HT.findfact("hdl_style(\"vhdl\")"))
	{
		if (Dimension_depth > 1)
		{
			ss << "       END LOOP;" << endl;
			*Next_dimension_depth = Dimension_depth - 1;
		}
	}
	else if (HT.findfact("hdl_style(\"verilog\")"))
	{
		if (Dimension_depth > 1)
			*Next_dimension_depth = Dimension_depth - 1;
	}
	if (HT.findfact("hdl_style(\"c\")"))
	{
		if (Dimension_depth > 1)
		{
			ss << "       }" << endl;
			*Next_dimension_depth = Dimension_depth - 1;
		}
	}
	return ss.str();
}

string write_depending_on_kind(string Local_name, string Local_kind, string* Local_name_app)
{
	stringstream ss;
	if (Local_kind == "par_inout")
	{
		HT.concat(Local_name, "_regout", Local_name_app);
	}
	return ss.str();
}

string reset_struct_field(string Top_kind, string Prefix_name, int Field_number, int Number_of_fields, int Current_comp_type, string HDL)
{
	stringstream ss;
	string Comp_name;
	int Next_field_number, Next_comp_type;
	if (HDL == "c")
	{
		if (Field_number == Number_of_fields)
		{
			if (Top_kind == "vectorarray_t")
			{
				if (HT.findfact("type_def(" + to_string(Current_comp_type) + ",_,_,_,_,\"single_t\",0,0,_)"))
				{
					Comp_name = returnpar(HT.findandreturn("type_def(" + to_string(Current_comp_type) + ",_,_,_,_,\"single_t\",0,0,_)"), 2);
					ss << "        (* " << Prefix_name << Comp_name << " = 0 ;" << endl;
				}
			}
			else if (HT.findfact("type_def(" + to_string(Current_comp_type) + ",_,_,_,_,\"single_t\",0,0,_)"))
			{
				if (Top_kind != "vectorarray_t")
				{
					ss << "        " << Prefix_name << Comp_name << " = 0 ;" << endl;
				}
			}
		}
		else if (Field_number < Number_of_fields)
		{
			ss << reset_struct_field_cond(Top_kind, Prefix_name, Current_comp_type, "c");
			Next_field_number = Field_number + 1;
			Next_comp_type = Current_comp_type + 1;
			ss << reset_struct_field(Top_kind, Prefix_name, Next_field_number, Number_of_fields, Next_comp_type, "c");
		}
	}
	return ss.str();
}

string reset_struct_field_cond(string Top_kind, string Prefix_name, int Current_comp_type, string HDL)
{
	stringstream ss;
	string Comp_name;
	if (HDL == "c")
	{
		if (Top_kind != "vectorarray_t")
		{
			if (HT.findfact("type_def(" + to_string(Current_comp_type) + ",_,_,_,_,\"single_t\",0,0,_)"))
			{
				Comp_name = returnpar(HT.findandreturn("type_def(" + to_string(Current_comp_type) + ",_,_,_,_,\"single_t\",0,0,_)"), 2);
				ss << "        " << Prefix_name << Comp_name << " = 0 ;" << endl;
			}
		}
		else if (Top_kind == "vectorarray_t")
		{
			if (HT.findfact("type_def(" + to_string(Current_comp_type) + ",_,_,_,_,\"single_t\",0,0,_)"))
			{
				Comp_name = returnpar(HT.findandreturn("type_def(" + to_string(Current_comp_type) + ",_,_,_,_,\"single_t\",0,0,_)"), 2);
				ss << "        (* " << Prefix_name << Comp_name << " = 0 ;" << endl;
			}
		}
	}
	return ss.str();
}

string reset_call_ports_unopt(string Module_name, string HDL, int C_entry)
{
	stringstream ss;
	int Next_entry;
	if (HDL == "vhdl")
	{
		if (HT.findfact("call_stmt(" + Module_name + "," + to_string(C_entry) + ",_,_)"))
		{
			ss << reset_call_ports_core_unopt(Module_name, "vhdl", C_entry, &Next_entry);
			ss << reset_call_ports_unopt(Module_name, "vhdl", Next_entry);
		}
	}
	return ss.str();
}

string reset_call_ports_core_unopt(string Module_name, string HDL, int C_entry, int* Next_entry)
{
	stringstream ss;
	int Called_mod_entry;
	string Cmodule_name;
	if (HDL == "vhdl")
	{
		if (HT.findfact("call_stmt(" + Module_name + "," + to_string(C_entry) + ",_,_)"))
		{
			Called_mod_entry = stoi(returnpar(HT.findandreturn("call_stmt(" + Module_name + "," + to_string(C_entry) + ",_,_)"), 3));
			if (HT.findfact("hierarchy_part(" + to_string(Called_mod_entry) + ",*)"))
			{
				Cmodule_name = returnpar(HT.findandreturn("hierarchy_part(" + to_string(Called_mod_entry) + ",*)"), 2);
				if (custom_block(Cmodule_name))
				{
					*Next_entry = C_entry + 1;
				}
				else if (HT.findfact("call_ios_have_been_reset(" + Cmodule_name + ")"))
				{
					*Next_entry = C_entry + 1;
				}
				else
				{
					finds_par_and_resets_formal_ios_unopt(Module_name, "vhdl", C_entry, Called_mod_entry, 1, 1);
					HT.assertz("call_ios_have_been_reset(" + Cmodule_name + ")");
					*Next_entry = C_entry + 1;
				}
			}
		}
	}
	return ss.str();
}

string finds_par_and_resets_formal_ios_unopt(string Module_name, string HDL, int C_entry, int Function_entry, int Function_max_calls, int num)
{
	stringstream ss;
	if (num == 1 && HDL == "vhdl")
		ss << resets_standard_call_ios_unopt(Module_name, "vhdl", C_entry, Function_entry, 1, 1);
	return ss.str();
}

string resets_standard_call_ios_unopt(string Module_name, string HDL, int C_entry, int Function_entry, int Function_max_calls, int num)
{
	stringstream ss;
	string Called_module_name;
	if (HDL == "vhdl")
	{
		if (Function_max_calls == 1)
		{
			if (HT.findfact("hierarchy_part(" + to_string(Function_entry) + ",_,_,\"libpart\",_,_,_)"))
			{
				Called_module_name = returnpar(HT.findandreturn("hierarchy_part(" + to_string(Function_entry) + ",_,_,\"libpart\",_,_,_)"), 2);
				if (custom_block(Called_module_name))
				{
					if (HT.findfact("hdl_style(\"vhdl\")"))
					{
						ss << "       " << Called_module_name << "_results_read_int <= '0';" << endl;
						ss << "       " << Called_module_name << "_start_int <= '0';" << endl;
					}
					else if (HT.findfact("hdl_style(\"verilog\")"))
					{
						ss << "       " << Called_module_name << "_results_read_int <= 1'b0;" << endl;
						ss << "       " << Called_module_name << "_start_int <= 1'b0;" << endl;
					}
				}
			}
		}
	}
	return ss.str();
}

string write_fsm_clock_header(string HDL, string Tool)
{
	stringstream ss;
	string ResetStyle;
	if (Tool == "synergy")
	{
		if (HDL == "vhdl")
		{
			if (HT.findfact("resetstyle(\"syncreset\")"))
			{
				ss << "      ELSE" << endl << endl;
				ss << "        CASE state IS " << endl << endl;
				ss << "          WHEN state_0 => " << endl;
				ss << "           IF results_read = '1' THEN done_int <= '0'; END IF;" << endl;
				ss << "           IF start = '1' THEN " << endl;
				ss << "            IF done_int = '0' OR results_read = '1' THEN " << endl;
				ss << "             busy <= '1';   -- processing started" << endl;
				ss << "             state <= state_1;" << endl;
				ss << "            END IF;" << endl;
				ss << "           ELSE" << endl;
				ss << "            state <= state_0;" << endl;
				ss << "           END IF ;" << endl << endl;
			}
			else if (HT.findfact("resetstyle(*)"))
			{
				ResetStyle = returnpar(HT.findandreturn("resetstyle(*)"), 1);
				if (ResetStyle != "syncreset")
				{
					ss << "      ELSIF clock = '1' AND clock'EVENT THEN " << endl << endl;
					ss << "        CASE state IS " << endl << endl;
					ss << "          WHEN state_0 => " << endl;
					ss << "           IF results_read = '1' THEN done_int <= '0'; END IF;" << endl;
					ss << "           IF start = '1' THEN " << endl;
					ss << "            IF done_int = '0' OR results_read = '1' THEN " << endl;
					ss << "             busy <= '1';   -- processing started" << endl;
					ss << "             state <= state_1;" << endl;
					ss << "            END IF;" << endl;
					ss << "           ELSE" << endl;
					ss << "            state <= state_0;" << endl;
					ss << "           END IF ;" << endl << endl;
				}
			}
		}
		else if (HDL == "verilog")
		{
			ss << "       end" << endl << endl;
			ss << "      else if (clock)" << endl << endl;
			ss << "        (* safe_fsm, full_case, parallel_case *)" << endl;
			ss << "        case (state)  // synthesis full_case" << endl << endl;
			ss << "          state_0 : " << endl;
			ss << "           begin " << endl;
			ss << "            if (results_read) done_int <= 1'b0; " << endl;
			ss << "            if (start) begin " << endl;
			ss << "             if (~done_int || results_read)" << endl;
			ss << "              begin " << endl;
			ss << "               busy <= 1'b1; //-- processing started " << endl;
			ss << "               state <= state_1;" << endl;
			ss << "              end " << endl;
			ss << "             end " << endl;
			ss << "            else" << endl;
			ss << "             state <= state_0;" << endl;
			ss << "           end " << endl << endl;
		}
	}
	else if (Tool == "gnu")
	{
		if (HDL == "c")
		{
			ss << "      case 'n': {" << endl;
			ss << "       switch (state) {" << endl;
			ss << "        case 0:" << endl;
			ss << "         printf(" << '"' << " initial state 0" << '\\' << 'n' << '"' << ");" << endl;
			ss << "         printf(" << '"' << " reading the design's inputs and synchronizing with the outside world..." << '\\' << 'n' << '"' << ");" << endl;
			ss << "         printf(" << '"' << " by pressing n you move to state 1" << '\\' << 'n' << '"' << ");" << endl;
			ss << "         state = 1; " << endl;
			ss << "         run_clock_cycles = run_clock_cycles + 1;" << endl;
			ss << "         break;" << endl;
		}
	}
	return ss.str();
}

string write_states(string Module_name, int Number, string HDL, string Tool)
{
	stringstream ss;
	GeneralFact* SN;
	if (HT.findfact("state_node(" + Module_name + "," + to_string(Number) + ",*)"))
	{
		SN = makeInstanceOf(HT.findandreturn("state_node(" + Module_name + "," + to_string(Number) + ",*)"));
		state_node* ptr = dynamic_cast<state_node*>(SN);
		ss << write_state(Module_name, *ptr, HDL, Tool);
	}
	return ss.str();
}

string write_state(string Module_name, state_node SN, string HDL, string Tool)
{
	stringstream ss;
	GeneralFact* GF;
	GF = &SN;
	state_node* ptr = &SN;
	string sntype;
	int State, Next_state, Call_entry, Called_module_entry;
	string Called_module_name;
	vector<int> Op_list;
	sntype = typeid(*ptr).name();
	sntype = sntype.substr(6);
	State = stoi(returnpar(HT.findandreturn(makeStringOf(GF)), 2));
	if (Tool == "synergy")
	{
		if (HDL == "vhdl")
		{
			if (sntype == "dataflow")
			{
				Next_state = return_par_of_sn(ptr, 1);
				Op_list = returnVec(GF, 1);
				ss << "          WHEN state_" << State << " =>" << endl;
				ss << "            state <= state_" << Next_state << ";" << endl;
				ss << write_state_operations(Module_name, State, Op_list);
				ss << endl;
			}
			else if (sntype == "subprogram_call")
			{
				Next_state = return_par_of_sn(ptr, 1);
				Op_list = returnVec(GF, 1);
				if (HT.findfact("prog_stmt(" + Module_name + "," + to_string(Op_list.front()) + ",_,109,0,_,_,_)"))
				{
					Call_entry = stoi(returnpar(HT.findandreturn("prog_stmt(" + Module_name + "," + to_string(Op_list.front()) + ",_,109,0,_,_,_)"), 6));
					if (HT.findfact("call_stmt(" + Module_name + "," + to_string(Call_entry) + ",*)"))
					{
						Called_module_entry = stoi(returnpar(HT.findandreturn("call_stmt(" + Module_name + "," + to_string(Call_entry) + ",*)"), 3));
						if (HT.findfact("hierarchy_part(" + to_string(Called_module_entry) + ",_,_,\"libpart\","+to_string(Called_module_entry)+",_,_)"))
						{
							Called_module_name = returnpar(HT.findandreturn("hierarchy_part(" + to_string(Called_module_entry) + ",_,_,\"libpart\"," + to_string(Called_module_entry) + ",_,_)"), 2);
							if (custom_block(Called_module_name))
							{
								ss << "          WHEN state_" << State << " =>" << endl;
								ss << "            state <= state_" << Next_state << ";" << endl;
								ss << write_call("           " , Module_name, State, Next_state, 1, Op_list, Op_list.front(), "vhdl", "");
								//continue
							}
						}
					}
				}
			}
		}
	}
	return ss.str();
}

string write_state_operations(string Module_name, int State, vector<int> Op_list)
{
	stringstream ss;
	string HDL;
	if (HT.findfact("massively_parallel_style(1)"))
	{
		if (HT.findfact("hdl_style(*)"))
		{
			HDL = returnpar(HT.findandreturn("hdl_style(*)"), 1);
			ss << output_operations(Module_name, Op_list, HDL, "synergy");
		}
	}
	else if (!HT.findfact("massively_parallel_style(*)"))
	{
		ss << write_output_state_assignments(Module_name, State, Op_list);
	}
	return ss.str();
}

string output_operations(string Module_name, vector<int> Op_list, string HDL, string Tool)
{
	stringstream ss;
	if (!Op_list.empty())
	{
		ss << print_all_kinds_of_operation(Module_name, Op_list.front(), HDL, Tool);
		Op_list.erase(Op_list.begin());
		ss << output_operations(Module_name, Op_list, HDL, Tool);
	}
	return ss.str();
}

string print_all_kinds_of_operation(string Module_name, int Operation, string HDL, string Tool)
{
	stringstream ss;
	if (Operation > 0)
	{
		ss << "             ";
		ss << output_operation(Module_name, Operation, HDL, Tool);
	}
	else if (Operation < 0)
	{
		ss << "             ";
		ss << output_special_operation(Module_name, Operation, HDL, Tool);
	}
	return ss.str();
}

string output_operation(string Module_name, int Operation, string HDL, string Tool)
{
	stringstream ss;
	int Right_op, Res_op, Res_type, Op_numb, Left_op, Left_type, Right_type, Size, Field_num, Records_type, First_field_type,
		First_index, Rec_type, Upper_bound, Lower_bound, Number_of_Elements, Element_type, UpLimit, Dimension_depth, Dim_minus_one,
		Comp_type;
	string Res_name, Op_string, Left_name, Right_name, Left_kind, Right_kind, Res_kind, Field_string, Right_category,
		Result_category, Re_kind, Rec_kind, Res_type_name, Field_name, Underscored_field, Res_rec, Underscored_rec_name, Kind,
		Type_name, CompType_name, Res_category, C_op_string, CloseParenthesis, ExtraAss;
	vector<int> Param_list;
	if (Tool == "synergy")
	{
		if (HDL == "vhdl")
		{
			if (Operation == 0)
			{
				ss << endl;
			}
			else if (HT.findfact("prog_stmt(" + Module_name + "," + to_string(Operation) + ",_,102,0,_,_,_)"))
			{
				Right_op = stoi(returnpar(HT.findandreturn("prog_stmt(" + Module_name + "," + to_string(Operation) + ",_,102,0,_,_,_)"), 6));
				Res_op = stoi(returnpar(HT.findandreturn("prog_stmt(" + Module_name + "," + to_string(Operation) + ",_,102,0,_,_,_)"), 7));
				if (HT.findfact("data_stmt(" + Module_name + ",_," + to_string(Right_op) + ",_,_,_)"))
				{
					Right_type = stoi(returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Right_op) + ",_,_,_)"), 4));
					if (HT.findfact("data_stmt(" + Module_name + ",_," + to_string(Res_op) + ",_,_,_)"))
					{
						Res_name = returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Res_op) + ",_,_,_)"), 2);
						Res_type = stoi(returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Res_op) + ",_,_,_)"), 4));
						if (HT.findfact("type_def(" + to_string(Right_type) + ",*)"))
						{
							Right_category = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Right_type) + ",*)"), 6));
							if (Right_category == "vectorarray_t")
							{
								if (HT.findfact("type_def(" + to_string(Res_type) + ",*)"))
								{
									Result_category = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Right_type) + ",*)"), 6));
									if (Result_category == "vectorarray_t")
									{
										if (HT.findfact("mem_port(_,_,Module_name,Res_name,_,_,_,_,_,_,_,_,_)"))
										{
											return ss.str();
										}
									}
								}
							}
						}
					}
				}
			}
			else if (HT.findfact("prog_stmt(" + Module_name + "," + to_string(Operation) + ",_,102,_,_,_,_)"))
			{
				Right_op = stoi(returnpar(HT.findandreturn("prog_stmt(" + Module_name + "," + to_string(Operation) + ",_,102,_,_,_,_)"), 6));
				Res_op = stoi(returnpar(HT.findandreturn("prog_stmt(" + Module_name + "," + to_string(Operation) + ",_,102,_,_,_,_)"), 7));
				if (Res_op != 0)
				{
					if (Right_op < 0)
					{
						if (HT.findfact("data_stmt(" + Module_name + ",_," + to_string(Res_op) + ",_,_,_)"))
						{
							Res_name = returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Res_op) + ",_,_,_)"), 2);
							Res_type = stoi(returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Res_op) + ",_,_,_)"), 4));
							if (HT.findfact("type_def(" + to_string(Res_type) + ",_,_,_,_,\"record_t\",_,_,_)"))
							{
								if (HT.findfact("rec_stmt(" + Module_name + "," + to_string(Right_op) + ",*)"))
								{
									Param_list = returnVec(makeInstanceOf(HT.findandreturn("rec_stmt(" + Module_name + "," + to_string(Right_op) + ",*)")), 1);
									ss << Res_name << " <= ( ";
									ss << write_param_list(Module_name, Param_list);
									ss << " );" << endl;
								}
							}
							else if (HT.findfact("type_def(" + to_string(Res_type) + ",_,_,_,_,\"vectorarray_t\",_,_,_)"))
							{
								if (HT.findfact("rec_stmt(" + Module_name + "," + to_string(Right_op) + ",*)"))
								{
									Param_list = returnVec(makeInstanceOf(HT.findandreturn("rec_stmt(" + Module_name + "," + to_string(Right_op) + ",*)")), 1);
									ss << Res_name << " <= ( ";
									ss << write_param_list(Module_name, Param_list);
									ss << " );" << endl;
								}
							}
						}
					}
				}
			}
			else if (HT.findfact("prog_stmt(" + Module_name + "," + to_string(Operation) + ",_,_,0,_,_,_)"))
			{
				Op_numb = stoi(returnpar(HT.findandreturn("prog_stmt(" + Module_name + "," + to_string(Operation) + ",_,_,0,_,_,_)"), 4));
				Right_op = stoi(returnpar(HT.findandreturn("prog_stmt(" + Module_name + "," + to_string(Operation) + ",_,_,0,_,_,_)"), 6));
				Res_op = stoi(returnpar(HT.findandreturn("prog_stmt(" + Module_name + "," + to_string(Operation) + ",_,_,0,_,_,_)"), 7));
				if (Op_numb < 59)
				{
					if (Op_numb != 10)
					{
						if (HT.findfact("op_def(" + to_string(Op_numb) + ",_,\"unop\",_,_,_,_)"))
						{
							Op_string = returnpar(HT.findandreturn("op_def(" + to_string(Op_numb) + ",_,\"unop\",_,_,_,_)"), 2);
							if (HT.findfact("data_stmt(" + Module_name + ",_," + to_string(Right_op) + ",_,_,_)"))
							{
								Right_name = returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Right_op) + ",_,_,_)"), 2);
								Right_type = stoi(returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Right_op) + ",_,_,_)"), 4));
								if (HT.findfact("data_stmt(" + Module_name + ",_," + to_string(Res_op) + ",_,_,_)"))
								{
									Res_name = returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Res_op) + ",_,_,_)"), 2);
									Res_type = stoi(returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Res_op) + ",_,_,_)"), 4));
									if (HT.findfact("type_def(" + to_string(Right_type) + ",*)"))
									{
										Right_category = returnpar(HT.findandreturn("type_def(" + to_string(Right_type) + ",*)"), 6);
										if (HT.findfact("type_def(" + to_string(Res_type) + ",*)"))
										{
											Result_category = returnpar(HT.findandreturn("type_def(" + to_string(Res_type) + ",*)"), 6);
											ss << "IF " << Op_string << " " << Right_name << " THEN " << Res_name << " <= '1'; ELSE " << Res_name << " <= '0'; END IF;" << endl;
										}
									}
								}
							}
						}
					}
					if (Op_numb == 10)
					{
						if (HT.findfact("op_def(" + to_string(Op_numb) + ",_,\"unop\",_,_,_,_)"))
						{
							Op_string = returnpar(HT.findandreturn("op_def(" + to_string(Op_numb) + ",_,\"unop\",_,_,_,_)"), 2);
							if (HT.findfact("data_stmt(" + Module_name + ",_," + to_string(Right_op) + ",_,_,_)"))
							{
								Right_name = returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Right_op) + ",_,_,_)"), 2);
								Right_type = stoi(returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Right_op) + ",_,_,_)"), 4));
								if (HT.findfact("data_stmt(" + Module_name + ",_," + to_string(Res_op) + ",_,_,_)"))
								{
									Res_name = returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Res_op) + ",_,_,_)"), 2);
									Res_type = stoi(returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Res_op) + ",_,_,_)"), 4));
									ss << Res_name << " <= not " << Right_name << " ; " << endl;
								}
							}
						}
					}
				}
				else if (Op_numb > 58)
				{
					if (Op_numb != 103 && Op_numb != 104 && Op_numb != 105 && Op_numb != 106 && Op_numb != 107 && Op_numb != 108 && Op_numb != 109 && Op_numb != 110)
					{
						if (HT.findfact("data_stmt(" + Module_name + ",_," + to_string(Right_op) + ",_,_,_)"))
						{
							Right_name = returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Right_op) + ",_,_,_)"), 2);
							Right_type = stoi(returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Right_op) + ",_,_,_)"), 4));
							Right_kind = returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Right_op) + ",_,_,_)"), 5);
							if (HT.findfact("data_stmt(" + Module_name + ",_," + to_string(Res_op) + ",_,_,_)"))
							{
								Res_name = returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Res_op) + ",_,_,_)"), 2);
								Res_type = stoi(returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Res_op) + ",_,_,_)"), 4));
								Res_kind = returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Res_op) + ",_,_,_)"), 5);
								if (HT.findfact("type_def(" + to_string(Right_type) + ",*)"))
								{
									Right_category = returnpar(HT.findandreturn("type_def(" + to_string(Right_type) + ",*)"), 6);
									if (HT.findfact("type_def(" + to_string(Res_type) + ",*)"))
									{
										Result_category = returnpar(HT.findandreturn("type_def(" + to_string(Res_type) + ",*)"), 6);
										if (one_of_two_not_same_array(Right_category, Result_category, Right_type, Res_type))
										{
											ss << type_op_tuple(Module_name, Res_name, Right_name, Res_kind, Right_kind, Op_string) << endl;
										}
									}
								}
							}
						}
						else if (HT.findfact("op_def(" + to_string(Op_numb) + ",_,\"unop\",_,_,_,_)"))
						{
							Op_string = returnpar(HT.findandreturn("op_def(" + to_string(Op_numb) + ",_,\"unop\",_,_,_,_)"), 2);
							if (HT.findfact("data_stmt(" + Module_name + ",_," + to_string(Right_op) + ",_,_,_)"))
							{
								Right_name = returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Right_op) + ",_,_,_)"), 2);
								Right_type = stoi(returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Right_op) + ",_,_,_)"), 4));
								Right_kind = returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Right_op) + ",_,_,_)"), 5);
								if (HT.findfact("data_stmt(" + Module_name + ",_," + to_string(Res_op) + ",_,_,_)"))
								{
									Res_name = returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Res_op) + ",_,_,_)"), 2);
									Res_type = stoi(returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Res_op) + ",_,_,_)"), 4));
									Res_kind = returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Res_op) + ",_,_,_)"), 5);
									if (HT.findfact("type_def(" + to_string(Right_type) + ",*)"))
									{
										Right_category = returnpar(HT.findandreturn("type_def(" + to_string(Right_type) + ",*)"), 6);
										if (Right_category == "vectorarray_t")
										{
											if (HT.findfact("type_def(" + to_string(Res_type) + ",*)"))
											{
												Result_category = returnpar(HT.findandreturn("type_def(" + to_string(Res_type) + ",*)"), 6);
												if (Result_category == "vectorarray_t")
												{
													if (!HT.findfact("mem_port(_,_," + Module_name + "," + Res_name + ",_,_,_,_,_,_,_,_,_)"))
													{
														ss << type_op_tuple1(Module_name, Res_name, Right_name, Res_kind, Right_kind, Op_string) << endl;
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
			else if (HT.findfact("prog_stmt(" + Module_name + "," + to_string(Operation) + ",_,104,_,_,_,_)"))
			{
				Right_op = stoi(returnpar(HT.findandreturn("prog_stmt(" + Module_name + "," + to_string(Operation) + ",_,104,_,_,_,_)"), 6));
				Res_op = stoi(returnpar(HT.findandreturn("prog_stmt(" + Module_name + "," + to_string(Operation) + ",_,104,_,_,_,_)"), 7));
				if (HT.findfact("data_stmt(" + Module_name + ",_," + to_string(Res_op) + ",_,_,_)"))
				{
					Res_name = returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Res_op) + ",_,_,_)"), 2);
					ss << Res_name;
					ss << " <= ";
					ss << Res_name;
					ss << " + ";
					ss << Right_op;
					ss << ";" << endl;
				}
			}
			else if (HT.findfact("prog_stmt(" + Module_name + "," + to_string(Operation) + ",_,105,_,_,_,_)"))
			{
				Right_op = stoi(returnpar(HT.findandreturn("prog_stmt(" + Module_name + "," + to_string(Operation) + ",_,105,_,_,_,_)"), 6));
				Res_op = stoi(returnpar(HT.findandreturn("prog_stmt(" + Module_name + "," + to_string(Operation) + ",_,105,_,_,_,_)"), 7));
				if (HT.findfact("data_stmt(" + Module_name + ",_," + to_string(Res_op) + ",_,_,_)"))
				{
					Res_name = returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Res_op) + ",_,_,_)"), 2);
					ss << Res_name;
					ss << " <= ";
					ss << Res_name;
					ss << " - ";
					ss << Right_op;
					ss << ";" << endl;
				}
			}
			else if (HT.findfact("prog_stmt(" + Module_name + "," + to_string(Operation) + ",_,106,0,_,_,_)"))
			{
				ss << endl;
			}
			else if (HT.findfact("prog_stmt(" + Module_name + "," + to_string(Operation) + ",_,107,_,_,_,_)"))
			{
				Left_op = stoi(returnpar(HT.findandreturn("prog_stmt(" + Module_name + "," + to_string(Operation) + ",_,107,_,_,_,_)"), 5));
				Right_op = stoi(returnpar(HT.findandreturn("prog_stmt(" + Module_name + "," + to_string(Operation) + ",_,107,_,_,_,_)"), 6));
				Res_op = stoi(returnpar(HT.findandreturn("prog_stmt(" + Module_name + "," + to_string(Operation) + ",_,107,_,_,_,_)"), 7));
				if (Res_op != 0)
				{
					if (HT.findfact("data_stmt(" + Module_name + ",_," + to_string(Left_op) + ",_,_,_)"))
					{
						Left_name = returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Left_op) + ",_,_,_)"), 2);
						Left_type = stoi(returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Left_op) + ",_,_,_)"), 4));
						if (HT.findfact("type_def(" + to_string(Left_type) + ",_,_,_,_,\"vectorarray_t\",_,_,_)"))
						{
							if (HT.findfact("data_stmt(" + Module_name + ",_," + to_string(Res_op) + ",_,_,_)"))
							{
								Res_name = returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Res_op) + ",_,_,_)"), 2);
								ss << Res_name << " <= ";
								ss << Left_name;
								ss << write_vhdl_array_index(Module_name, Right_op);
								ss << ";" << endl;
							}
						}
						else if (HT.findfact("type_def(" + to_string(Left_type) + ",_,_,_,_,\"record_t\",_,_,_)"))
						{
							First_field_type = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Left_type) + ",_,_,_,_,\"record_t\",_,_,_)"), 9));
							if (HT.findfact("data_stmt(" + Module_name + ",_," + to_string(Right_op) + ",_,\"const\",i(*))"))
							{
								Field_num = stoi(returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Right_op) + ",_,\"const\",i(*))"), 7));
								find_rec_field_string(First_field_type, Field_num, &Field_string);
								if (HT.findfact("data_stmt(" + Module_name + ",_," + to_string(Res_op) + ",_,_,_)"))
								{
									Res_name = returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Res_op) + ",_,_,_)"), 2);
									ss << Res_name << " <= ";
									ss << Left_name << Field_string << ";" << endl;
								}
							}
						}
					}
				}
			}
			else if (HT.findfact("prog_stmt(" + Module_name + "," + to_string(Operation) + ",_,108,_,_,_,_)"))
			{
				Field_num = stoi(returnpar(HT.findandreturn("prog_stmt(" + Module_name + "," + to_string(Operation) + ",_,108,_,_,_,_)"), 3));
				Left_op = stoi(returnpar(HT.findandreturn("prog_stmt(" + Module_name + "," + to_string(Operation) + ",_,108,_,_,_,_)"), 5));
				Right_op = stoi(returnpar(HT.findandreturn("prog_stmt(" + Module_name + "," + to_string(Operation) + ",_,108,_,_,_,_)"), 6));
				Res_op = stoi(returnpar(HT.findandreturn("prog_stmt(" + Module_name + "," + to_string(Operation) + ",_,108,_,_,_,_)"), 7));
				if (Res_op != 0)
				{
					if (Field_num > 0)
					{
						if (HT.findfact("data_stmt(" + Module_name + ",_," + to_string(Left_op) + ",_,_,_)"))
						{
							Left_name = returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Left_op) + ",_,_,_)"), 2);
							if (HT.findfact("data_stmt(" + Module_name + ",_," + to_string(Right_op) + ",_,_,_)"))
							{
								Right_name = returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Right_op) + ",_,_,_)"), 2);
								if (HT.findfact("data_stmt(" + Module_name + ",_," + to_string(Res_op) + ",_,_,_)"))
								{
									Res_name = returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Res_op) + ",_,_,_)"), 2);
									Res_type = stoi(returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Res_op) + ",_,_,_)"), 4));
									if (HT.findfact("type_def(" + to_string(Res_type) + ",_,_,_,_,\"vectorarray_t\",_,_,_)"))
									{
										Records_type = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Res_type) + ",_,_,_,_,\"vectorarray_t\",_,_,_)"), 9));
										if (HT.findfact("type_def(" + to_string(Records_type) + ",_,_,_,_,\"record_t\",_,_,_)"))
										{
											First_field_type = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Records_type) + ",_,_,_,_,\"record_t\",_,_,_)"), 9));
											find_rec_field_string(First_field_type, Field_num, &Field_string);
											ss << Res_name << "(CONV_INTEGER(" << Right_name << "))";
											ss << Field_string << " <= ";
											ss << Left_name << ";" << endl;
										}
									}
								}
							}
						}
					}
					else if (Left_op > 0)
					{
						if (HT.findfact("data_stmt(" + Module_name + ",_," + to_string(Left_op) + ",_,_,_)"))
						{
							Left_name = returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Left_op) + ",_,_,_)"), 2);
							if (HT.findfact("data_stmt(" + Module_name + ",_," + to_string(Res_op) + ",_,_,_)"))
							{
								Res_name = returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Res_op) + ",_,_,_)"), 2);
								Res_type = stoi(returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Res_op) + ",_,_,_)"), 4));
								if (HT.findfact("type_def(" + to_string(Res_type) + ",_,_,_,_,\"vectorarray_t\",_,_,_)"))
								{
									ss << Res_name;
									ss << write_vhdl_array_index(Module_name, Right_op);
									ss << " <= ";
									ss << Left_name << ";" << endl;
								}
							}
						}
					}
					else if (Left_op < 0)
					{
						if (HT.findfact("data_stmt(" + Module_name + ",_," + to_string(Res_op) + ",_,_,_)"))
						{
							Res_name = returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Res_op) + ",_,_,_)"), 2);
							Res_type = stoi(returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Res_op) + ",_,_,_)"), 4));
							if (HT.findfact("type_def(" + to_string(Res_type) + ",_,_,_,_,\"vectorarray_t\",_,_,_)"))
							{
								ss << Res_name;
								ss << write_vhdl_array_index(Module_name, Right_op);
								ss << " <= ";
								ss << "( ";
								if (HT.findfact("rec_stmt(" + Module_name + "," + to_string(Left_op) + ",*)"))
								{
									Param_list = returnVec(makeInstanceOf(HT.findandreturn("rec_stmt(" + Module_name + "," + to_string(Left_op) + ",*)")), 1);
									ss << write_param_list(Module_name, Param_list);
									ss << " );" << endl;
								}
							}
						}
					}
					else if (HT.findfact("data_stmt(" + Module_name + ",_," + to_string(Left_op) + ",_,_,_)"))
					{
						Left_name = returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Left_op) + ",_,_,_)"), 2);
						if (HT.findfact("data_stmt(" + Module_name + ",_," + to_string(Right_op) + ",_,\"const\",i(*))"))
						{
							Field_num = stoi(returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Right_op) + ",_,\"const\",i(*))"), 7));
							if (HT.findfact("data_stmt(" + Module_name + ",_," + to_string(Res_op) + ",_,_,_)"))
							{
								Res_name = returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Res_op) + ",_,_,_)"), 2);
								Res_type = stoi(returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Res_op) + ",_,_,_)"), 4));
								if (HT.findfact("type_def(" + to_string(Res_type) + ",_,_,_,_,\"record_t\",_,_,_)"))
								{
									First_field_type = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Res_type) + ",_,_,_,_,\"record_t\",_,_,_)"), 9));
									find_rec_field_string(First_field_type, Field_num, &Field_string);
									ss << Res_name << Field_string << " <= ";
									ss << Left_name << ";" << endl;
								}
							}
						}
					}
				}
			}
			else if (HT.findfact("prog_stmt(" + Module_name + "," + to_string(Operation) + ",_,109,0,_,_,_)"))
			{
				ss << endl;
				HT.assertz("found_call_operator(" + Module_name + "," + to_string(Operation) + ")");
			}
			else if (HT.findfact("prog_stmt(" + Module_name + "," + to_string(Operation) + ",_,110,0,_,_,_)"))
			{
				ss << endl;
			}
			else if (HT.findfact("prog_stmt(" + Module_name + "," + to_string(Operation) + ",*)"))
			{
				Op_numb = stoi(returnpar(HT.findandreturn("prog_stmt(" + Module_name + "," + to_string(Operation) + ",*)"), 4));
				Left_op = stoi(returnpar(HT.findandreturn("prog_stmt(" + Module_name + "," + to_string(Operation) + ",*)"), 5));
				Right_op = stoi(returnpar(HT.findandreturn("prog_stmt(" + Module_name + "," + to_string(Operation) + ",*)"), 6));
				Res_op = stoi(returnpar(HT.findandreturn("prog_stmt(" + Module_name + "," + to_string(Operation) + ",*)"), 7));
				if (Op_numb <= 58)
				{
					if (Op_numb != 7 && Op_numb != 8 && Op_numb != 9 && Op_numb != 10)
					{
						if (HT.findfact("op_def(" + to_string(Op_numb) + ",_,\"binop\",_,_,_,_)"))
						{
							Op_string = returnpar(HT.findandreturn("op_def(" + to_string(Op_numb) + ",_,\"binop\",_,_,_,_)"), 2);
							if (HT.findfact("data_stmt(" + Module_name + ",_," + to_string(Left_op) + ",_,_,_)"))
							{
								Left_name = returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Left_op) + ",_,_,_)"), 2);
								if (HT.findfact("data_stmt(" + Module_name + ",_," + to_string(Right_op) + ",_,_,_)"))
								{
									Right_name = returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Right_op) + ",_,_,_)"), 2);
									if (HT.findfact("data_stmt(" + Module_name + ",_," + to_string(Res_op) + ",_,_,_)"))
									{
										Res_name = returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Res_op) + ",_,_,_)"), 2);
										ss << "IF " << Left_name << " " << Op_string << " " << Right_name << " THEN " << Res_name << " <= '1'; ELSE " << Res_name << " <= '0'; END IF;" << endl;

									}
								}
							}
						}
					}
				}
				else if (Op_numb >= 7)
				{
					if (Op_numb != 103 && Op_numb != 104 && Op_numb != 105 && Op_numb != 106 && Op_numb != 107 && Op_numb != 108 && Op_numb != 109 && Op_numb != 110)
					{
						if (Op_numb > 58)
						{
							if (HT.findfact("op_def(" + to_string(Op_numb) + ",_,\"binop\",_,_,_,_)"))
							{
								Op_string = returnpar(HT.findandreturn("op_def(" + to_string(Op_numb) + ",_,\"binop\",_,_,_,_)"), 2);
								if (HT.findfact("data_stmt(" + Module_name + ",_," + to_string(Left_op) + ",_,_,_)"))
								{
									Left_name = returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Left_op) + ",_,_,_)"), 2);
									Left_kind = returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Left_op) + ",_,_,_)"), 5);
									if (HT.findfact("data_stmt(" + Module_name + ",_," + to_string(Right_op) + ",_,_,_)"))
									{
										Right_name = returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Right_op) + ",_,_,_)"), 2);
										Right_kind = returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Right_op) + ",_,_,_)"), 5);
										if (HT.findfact("data_stmt(" + Module_name + ",_," + to_string(Res_op) + ",_,_,_)"))
										{
											Res_name = returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Res_op) + ",_,_,_)"), 2);
											Res_kind = returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Res_op) + ",_,_,_)"), 5);
											ss << type_op_triple(Module_name, Res_name, Left_name, Right_name, Res_kind, Left_kind, Right_kind, Op_string, " <= ", "vhdl") << endl;
										}
									}
								}
							}
						}
					}
					if (Op_numb != 103 && Op_numb != 104 && Op_numb != 105 && Op_numb != 106 && Op_numb != 107 && Op_numb != 108 && Op_numb != 110)
					{
						if (HT.findfact("op_def(" + to_string(Op_numb) + ",_,\"binop\",_,_,_,_)"))
						{
							Op_string = returnpar(HT.findandreturn("op_def(" + to_string(Op_numb) + ",_,\"binop\",_,_,_,_)"), 2);
							if (HT.findfact("data_stmt(" + Module_name + ",_," + to_string(Left_op) + ",_,_,_)"))
							{
								Left_name = returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Left_op) + ",_,_,_)"), 2);
								Left_kind = returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Left_op) + ",_,_,_)"), 5);
								if (HT.findfact("data_stmt(" + Module_name + ",_," + to_string(Right_op) + ",_,_,_)"))
								{
									Right_name = returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Right_op) + ",_,_,_)"), 2);
									Right_kind = returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Right_op) + ",_,_,_)"), 5);
									if (HT.findfact("data_stmt(" + Module_name + ",_," + to_string(Res_op) + ",_,_,_)"))
									{
										Res_name = returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Res_op) + ",_,_,_)"), 2);
										Res_kind = returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Res_op) + ",_,_,_)"), 5);
										ss << type_op_triple(Module_name, Res_name, Left_name, Right_name, Res_kind, Left_kind, Right_kind, Op_string, " <= ", "vhdl") << endl;
									}
								}
							}
						}
					}
					else if (Op_numb <= 10)
					{
						if (HT.findfact("op_def(" + to_string(Op_numb) + ",_,\"binop\",_,_,_,_)"))
						{
							Op_string = returnpar(HT.findandreturn("op_def(" + to_string(Op_numb) + ",_,\"binop\",_,_,_,_)"), 2);
							if (HT.findfact("data_stmt(" + Module_name + ",_," + to_string(Left_op) + ",_,_,_)"))
							{
								Left_name = returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Left_op) + ",_,_,_)"), 2);
								Left_type = stoi(returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Left_op) + ",_,_,_)"), 4));
								if (HT.findfact("data_stmt(" + Module_name + ",_," + to_string(Right_op) + ",_,_,_)"))
								{
									Right_name = returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Right_op) + ",_,_,_)"), 2);
									Right_type = stoi(returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Right_op) + ",_,_,_)"), 4));
									if (HT.findfact("data_stmt(" + Module_name + ",_," + to_string(Res_op) + ",_,_,_)"))
									{
										Res_name = returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Res_op) + ",_,_,_)"), 2);
										Res_type = stoi(returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Res_op) + ",_,_,_)"), 4));
										if (HT.findfact("type_def(" + to_string(Left_type) + ",_,1,_,_,_,_,_,_)"))
										{
											if (HT.findfact("type_def(" + to_string(Right_type) + ",_,1,_,_,_,_,_,_)"))
											{
												if (HT.findfact("type_def(" + to_string(Res_type) + ",_,1,_,_,_,_,_,_)"))
												{
													ss << Res_name << " <= " << Left_name << " " << Op_string << " " << Right_name << ";" << endl;
												}
											}
										}
										else if (derived_type(Left_type, 2))
										{
											if (derived_type(Right_type, 2))
											{
												if (derived_type(Res_type, 2))
												{
													ss << Res_name << " <= " << Left_name << " " << Op_string << " " << Right_name << ";" << endl;
												}
												else if (derived_type(Res_type, 1))
												{
													if (HT.findfact("type_def(" + to_string(Res_type) + ",*)"))
													{
														Size = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Res_type) + ",*)"), 3));
														ss << "IF (" << Left_name << " " << Op_string << " " << Right_name << ") /= conv_std_logic_vector(0<<" << Size << ") THEN " << Res_name << " <= '1'; ELSE " << Res_name << " <= '0'; END IF;" << endl;
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
		else if (HDL == "verilog")
		{
			if (Operation == 0)
			{
				ss << endl;
			}
			else if (HT.findfact("prog_stmt(" + Module_name + "," + to_string(Operation) + ",_,102,0,_,_,_)"))
			{
				Right_op = stoi(returnpar(HT.findandreturn("prog_stmt(" + Module_name + "," + to_string(Operation) + ",_,102,0,_,_,_)"), 6));
				Res_op = stoi(returnpar(HT.findandreturn("prog_stmt(" + Module_name + "," + to_string(Operation) + ",_,102,0,_,_,_)"), 7));
				if (HT.findfact("data_stmt(" + Module_name + ",_," + to_string(Right_op) + ",_,_,_)"))
				{
					Right_type = stoi(returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Right_op) + ",_,_,_)"), 4));
					if (HT.findfact("data_stmt(" + Module_name + ",_," + to_string(Res_op) + ",_,_,_)"))
					{
						Res_name = returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Res_op) + ",_,_,_)"), 2);
						Res_type = stoi(returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Res_op) + ",_,_,_)"), 4));
						if (HT.findfact("type_def(" + to_string(Right_type) + ",*)"))
						{
							Right_category = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Right_type) + ",*)"), 6));
							if (Right_category == "vectorarray_t")
							{
								if (HT.findfact("type_def(" + to_string(Res_type) + ",*)"))
								{
									Result_category = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Right_type) + ",*)"), 6));
									if (Result_category == "vectorarray_t")
									{
										if (HT.findfact("mem_port(_,_,Module_name,Res_name,_,_,_,_,_,_,_,_,_)"))
										{
											return ss.str();
										}
									}
								}
							}
						}
					}
				}
			}
			else if (HT.findfact("prog_stmt(" + Module_name + "," + to_string(Operation) + ",_,102,_,_,_,_)"))
			{
				Right_op = stoi(returnpar(HT.findandreturn("prog_stmt(" + Module_name + "," + to_string(Operation) + ",_,102,_,_,_,_)"), 6));
				Res_op = stoi(returnpar(HT.findandreturn("prog_stmt(" + Module_name + "," + to_string(Operation) + ",_,102,_,_,_,_)"), 7));
				if (Res_op != 0)
				{
					if (Right_op < 0)
					{
						if (HT.findfact("data_stmt(" + Module_name + ",_," + to_string(Res_op) + ",_,_,_)"))
						{
							Res_name = returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Res_op) + ",_,_,_)"), 2);
							Res_type = stoi(returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Res_op) + ",_,_,_)"), 4));
							if (HT.findfact("type_def(" + to_string(Res_type) + ",_,_,_,_,\"record_t\",_,_,_)"))
							{
								if (HT.findfact("rec_stmt(" + Module_name + "," + to_string(Right_op) + ",*)"))
								{
									Param_list = returnVec(makeInstanceOf(HT.findandreturn("rec_stmt(" + Module_name + "," + to_string(Right_op) + ",*)")), 1);
									ss << Res_name << " <= { ";
									ss << write_param_list(Module_name, Param_list);
									ss << " };" << endl;
								}
							}
							else if (HT.findfact("type_def(" + to_string(Res_type) + ",_,_,_,_,\"vectorarray_t\",_,_,_)"))
							{
								First_index = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Res_type) + ",_,_,_,_,\"vectorarray_t\",_,_,_)"), 7));
								if (HT.findfact("rec_stmt(" + Module_name + "," + to_string(Right_op) + ",*)"))
								{
									Param_list = returnVec(makeInstanceOf(HT.findandreturn("rec_stmt(" + Module_name + "," + to_string(Right_op) + ",*)")), 1);
									ss << endl;
									ss << write_verilog_aggregate(Module_name, First_index, Res_name, Param_list);
								}
							}
						}
					}
				}
			}
			else if (HT.findfact("prog_stmt(" + Module_name + "," + to_string(Operation) + ",_,_,0,_,_,_)"))
			{
				Op_numb = stoi(returnpar(HT.findandreturn("prog_stmt(" + Module_name + "," + to_string(Operation) + ",_,_,0,_,_,_)"), 4));
				Right_op = stoi(returnpar(HT.findandreturn("prog_stmt(" + Module_name + "," + to_string(Operation) + ",_,_,0,_,_,_)"), 6));
				Res_op = stoi(returnpar(HT.findandreturn("prog_stmt(" + Module_name + "," + to_string(Operation) + ",_,_,0,_,_,_)"), 7));
				if (Op_numb != 103 && Op_numb != 104 && Op_numb != 105 && Op_numb != 106 && Op_numb != 107 && Op_numb != 108 && Op_numb != 109 && Op_numb != 110)
				{
					if (HT.findfact("op_def(" + to_string(Op_numb) + ",_,\"unop\",_,_,_,_)"))
					{
						Op_string = returnpar(HT.findandreturn("op_def(" + to_string(Op_numb) + ",_,\"unop\",_,_,_,_)"), 2);
						if (HT.findfact("data_stmt(" + Module_name + ",_," + to_string(Right_op) + ",_,_,_)"))
						{
							Right_name = returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Right_op) + ",_,_,_)"), 2);
							Right_type = stoi(returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Right_op) + ",_,_,_)"), 4));
							Right_kind = returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Right_op) + ",_,_,_)"), 5);
							if (HT.findfact("data_stmt(" + Module_name + ",_," + to_string(Res_op) + ",_,_,_)"))
							{
								Res_name = returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Res_op) + ",_,_,_)"), 2);
								Res_type = stoi(returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Res_op) + ",_,_,_)"), 4));
								Res_kind = returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Res_op) + ",_,_,_)"), 5);
								if (Res_kind != "par_inout")
								{
									if (HT.findfact("type_def(" + to_string(Right_type) + ",*)"))
									{
										Right_category = returnpar(HT.findandreturn("type_def(" + to_string(Right_type) + ",*)"), 6);
										if (HT.findfact("type_def(" + to_string(Res_type) + ",*)"))
										{
											Result_category = returnpar(HT.findandreturn("type_def(" + to_string(Res_type) + ",*)"), 6);
											if (one_of_two_not_same_array(Right_category, Result_category, Right_type, Res_type))
											{
												ss << Res_name << " <= " << Right_name << " ;" << endl;
											}
										}
									}
								}
								else if (Res_kind == "par_inout")
								{
									if (HT.findfact("type_def(" + to_string(Right_type) + ",*)"))
									{
										Right_category = returnpar(HT.findandreturn("type_def(" + to_string(Right_type) + ",*)"), 6);
										if (HT.findfact("type_def(" + to_string(Res_type) + ",*)"))
										{
											Result_category = returnpar(HT.findandreturn("type_def(" + to_string(Res_type) + ",*)"), 6);
											if (one_of_two_not_same_array(Right_category, Result_category, Right_type, Res_type))
											{
												ss << Res_name << "_regout <= " << Right_name << " ;" << endl;
											}
										}
									}
								}
								else if (HT.findfact("type_def(" + to_string(Right_type) + ",*)"))
								{
									Right_category = returnpar(HT.findandreturn("type_def(" + to_string(Right_type) + ",*)"), 6);
									if (Right_category == "vectorarray_t")
									{
										if (HT.findfact("type_def(" + to_string(Res_type) + ",*)"))
										{
											Result_category = returnpar(HT.findandreturn("type_def(" + to_string(Res_type) + ",*)"), 6);
											if (Result_category == "vectorarray_t")
											{
												if (!HT.findfact("mem_port(_,_," + Module_name + "," + Res_name + ",_,_,_,_,_,_,_,_,_)"))
												{
													ss << Res_name << " <= " << Right_name << " ;" << endl;
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
			else if (HT.findfact("prog_stmt(" + Module_name + "," + to_string(Operation) + ",_,104,_,_,_,_)"))
			{
				Right_op = stoi(returnpar(HT.findandreturn("prog_stmt(" + Module_name + "," + to_string(Operation) + ",_,104,_,_,_,_)"), 6));
				Res_op = stoi(returnpar(HT.findandreturn("prog_stmt(" + Module_name + "," + to_string(Operation) + ",_,104,_,_,_,_)"), 7));
				if (HT.findfact("data_stmt(" + Module_name + ",_," + to_string(Res_op) + ",_,_,_)"))
				{
					Res_name = returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Res_op) + ",_,_,_)"), 2);
					ss << Res_name;
					ss << " <= ";
					ss << Res_name;
					ss << " + ";
					ss << Right_op;
					ss << ";" << endl;
				}
			}
			else if (HT.findfact("prog_stmt(" + Module_name + "," + to_string(Operation) + ",_,105,_,_,_,_)"))
			{
				Right_op = stoi(returnpar(HT.findandreturn("prog_stmt(" + Module_name + "," + to_string(Operation) + ",_,105,_,_,_,_)"), 6));
				Res_op = stoi(returnpar(HT.findandreturn("prog_stmt(" + Module_name + "," + to_string(Operation) + ",_,105,_,_,_,_)"), 7));
				if (HT.findfact("data_stmt(" + Module_name + ",_," + to_string(Res_op) + ",_,_,_)"))
				{
					Res_name = returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Res_op) + ",_,_,_)"), 2);
					ss << Res_name;
					ss << " <= ";
					ss << Res_name;
					ss << " - ";
					ss << Right_op;
					ss << ";" << endl;
				}
			}
			else if (HT.findfact("prog_stmt(" + Module_name + "," + to_string(Operation) + ",_,106,0,_,_,_)"))
			{
				ss << endl;
			}
			else if (HT.findfact("prog_stmt(" + Module_name + "," + to_string(Operation) + ",_,107,_,_,_,_)"))
			{
				Left_op = stoi(returnpar(HT.findandreturn("prog_stmt(" + Module_name + "," + to_string(Operation) + ",_,107,_,_,_,_)"), 5));
				Right_op = stoi(returnpar(HT.findandreturn("prog_stmt(" + Module_name + "," + to_string(Operation) + ",_,107,_,_,_,_)"), 6));
				Res_op = stoi(returnpar(HT.findandreturn("prog_stmt(" + Module_name + "," + to_string(Operation) + ",_,107,_,_,_,_)"), 7));
				if (Res_op != 0)
				{
					if (HT.findfact("data_stmt(" + Module_name + ",_," + to_string(Left_op) + ",_,_,_)"))
					{
						Left_name = returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Left_op) + ",_,_,_)"), 2);
						Left_type = stoi(returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Left_op) + ",_,_,_)"), 4));
						if (HT.findfact("type_def(" + to_string(Left_type) + ",_,_,_,_,\"vectorarray_t\",_,_,_)"))
						{
							if (HT.findfact("data_stmt(" + Module_name + ",_," + to_string(Res_op) + ",_,_,_)"))
							{
								Res_name = returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Res_op) + ",_,_,_)"), 2);
								ss << Res_name << " <= ";
								ss << Left_name;
								ss << write_verilog_array_index(Module_name, Right_op);
								ss << ";" << endl;
							}
						}
						else if (HT.findfact("type_def(" + to_string(Left_type) + ",_,_,_,_,\"record_t\",_,_,_)"))
						{
							First_field_type = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Left_type) + ",_,_,_,_,\"record_t\",_,_,_)"), 9));
							if (HT.findfact("data_stmt(" + Module_name + ",_," + to_string(Right_op) + ",_,\"const\",i(*))"))
							{
								Field_num = stoi(returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Right_op) + ",_,\"const\",i(*))"), 7));
								if (HT.findfact("data_stmt(" + Module_name + ",_," + to_string(Res_op) + ",_,_,_)"))
								{
									Res_name = returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Res_op) + ",_,_,_)"), 2);
									find_record_field_bounds(0, Field_num, 1, First_field_type, &Upper_bound, &Lower_bound);
									ss << Res_name << " <= " << Left_name << "[" << Upper_bound << ":" << Lower_bound << "] ;" << endl;
								}
							}
						}
					}
				}
			}
			else if (HT.findfact("prog_stmt(" + Module_name + "," + to_string(Operation) + ",_,108,_,_,_,_)"))
			{
				Field_num = stoi(returnpar(HT.findandreturn("prog_stmt(" + Module_name + "," + to_string(Operation) + ",_,108,_,_,_,_)"), 3));
				Left_op = stoi(returnpar(HT.findandreturn("prog_stmt(" + Module_name + "," + to_string(Operation) + ",_,108,_,_,_,_)"), 5));
				Right_op = stoi(returnpar(HT.findandreturn("prog_stmt(" + Module_name + "," + to_string(Operation) + ",_,108,_,_,_,_)"), 6));
				Res_op = stoi(returnpar(HT.findandreturn("prog_stmt(" + Module_name + "," + to_string(Operation) + ",_,108,_,_,_,_)"), 7));
				if (Res_op != 0)
				{
					if (Field_num > 0)
					{
						if (HT.findfact("data_stmt(" + Module_name + ",_," + to_string(Left_op) + ",_,_,_)"))
						{
							Left_name = returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Left_op) + ",_,_,_)"), 2);
							if (HT.findfact("data_stmt(" + Module_name + ",_," + to_string(Right_op) + ",_,_,_)"))
							{
								Right_name = returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Right_op) + ",_,_,_)"), 2);
								if (HT.findfact("data_stmt(" + Module_name + ",_," + to_string(Res_op) + ",_,_,_)"))
								{
									Res_name = returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Res_op) + ",_,_,_)"), 2);
									Res_type = stoi(returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Res_op) + ",_,_,_)"), 4));
									if (HT.findfact("type_def(" + to_string(Res_type) + ",_,_,_,_,\"vectorarray_t\",_,_,_)"))
									{
										Records_type = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Res_type) + ",_,_,_,_,\"vectorarray_t\",_,_,_)"), 9));
										if (HT.findfact("type_def(" + to_string(Records_type) + ",_,_,_,_,\"record_t\",_,_,_)"))
										{
											First_field_type = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Records_type) + ",_,_,_,_,\"record_t\",_,_,_)"), 9));
											find_record_field_bounds(0, Field_num, 1, First_field_type, &Upper_bound, &Lower_bound);
											ss << Res_name << "[" << Right_name << "] <= " << Left_name << "[" << Upper_bound << ":" << Lower_bound << "] ;" << endl;
										}
									}
								}
							}
						}
					}
					else if (Left_op > 0)
					{
						if (HT.findfact("data_stmt(" + Module_name + ",_," + to_string(Left_op) + ",_,_,_)"))
						{
							Left_name = returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Left_op) + ",_,_,_)"), 2);
							if (HT.findfact("data_stmt(" + Module_name + ",_," + to_string(Res_op) + ",_,_,_)"))
							{
								Res_name = returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Res_op) + ",_,_,_)"), 2);
								Res_type = stoi(returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Res_op) + ",_,_,_)"), 4));
								Re_kind = returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Res_op) + ",_,_,_)"), 5);
								if (Re_kind != "par_inout")
								{
									if (HT.findfact("type_def(" + to_string(Res_type) + ",_,_,_,0,\"vectorarray_t\",_,_,_)"))
									{
										ss << Res_name;
										ss << write_verilog_array_index(Module_name, Right_op);
										ss << " <= ";
										ss << Left_name << ";" << endl;
									}
									else if (HT.findfact("type_def(" + to_string(Res_type) + ",_,_,_,_,\"vectorarray_t\",_,_,_)"))
									{
										Res_type_name = returnpar(HT.findandreturn("type_def(" + to_string(Res_type) + ",_,_,_,_,\"vectorarray_t\",_,_,_)"), 2);
										Rec_type = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Res_type) + ",_,_,_,_,\"vectorarray_t\",_,_,_)"), 5));
										if (HT.concat(".", &Field_name, Res_type_name))
										{
											if (HT.findfact("type_def(" + to_string(Rec_type) + ",_,_,_,_,\"record_t\",_,_,_)"))
											{
												HT.concat("_", Field_name, &Underscored_field);
												if (HT.concat(&Res_rec, Res_type_name, Res_name))
												{
													HT.concat(Res_rec, Underscored_field, &Underscored_rec_name);
													ss << Underscored_rec_name;
													ss << write_verilog_array_index(Module_name, Right_op);
													ss << " <= ";
													ss << Left_name << ";" << endl;
												}
											}
										}
										else if (HT.findfact("type_def(" + to_string(Rec_type) + ",*)"))
										{
											Rec_kind = returnpar(HT.findandreturn("type_def(" + to_string(Rec_type) + ",*)"), 6);
											if (Rec_kind != "record_t")
											{
												ss << Res_name;
												ss << write_verilog_array_index(Module_name, Right_op);
												ss << " <= ";
												ss << Left_name << ";" << endl;
											}
										}
									}
								}
								else if (Re_kind == "par_inout")
								{
									if (HT.findfact("type_def(" + to_string(Res_type) + ",_,_,_,_,\"vectorarray_t\",_,_,_)"))
									{
										ss << Res_name << "_regout";
										ss << write_verilog_array_index(Module_name, Right_op);
										ss << " <= ";
										ss << Left_name << ";" << endl;
									}
								}
							}
						}
					}
					else if (Left_op < 0)
					{
						if (HT.findfact("data_stmt(" + Module_name + ",_," + to_string(Res_op) + ",_,_,_)"))
						{
							Res_name = returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Res_op) + ",_,_,_)"), 2);
							Res_type = stoi(returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Res_op) + ",_,_,_)"), 4));
							if (HT.findfact("type_def(" + to_string(Res_type) + ",_,_,_,_,\"vectorarray_t\",_,_,_)"))
							{
								ss << Res_name;
								ss << write_verilog_array_index(Module_name, Right_op);
								ss << " <= ";
								ss << "{ ";
								if (HT.findfact("rec_stmt(" + Module_name + "," + to_string(Left_op) + ",*)"))
								{
									Param_list = returnVec(makeInstanceOf(HT.findandreturn("rec_stmt(" + Module_name + "," + to_string(Left_op) + ",*)")), 1);
									ss << write_param_list(Module_name, Param_list);
									ss << " };" << endl;
								}
							}
						}
					}
					else if (HT.findfact("data_stmt(" + Module_name + ",_," + to_string(Left_op) + ",_,_,_)"))
					{
						Left_name = returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Left_op) + ",_,_,_)"), 2);
						if (HT.findfact("data_stmt(" + Module_name + ",_," + to_string(Right_op) + ",_,\"const\",i(*))"))
						{
							Field_num = stoi(returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Right_op) + ",_,\"const\",i(*))"), 7));
							if (HT.findfact("data_stmt(" + Module_name + ",_," + to_string(Res_op) + ",_,_,_)"))
							{
								Res_name = returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Res_op) + ",_,_,_)"), 2);
								Res_type = stoi(returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Res_op) + ",_,_,_)"), 4));
								if (HT.findfact("type_def(" + to_string(Res_type) + ",_,_,_,_,\"record_t\",_,_,_)"))
								{
									First_field_type = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Res_type) + ",_,_,_,_,\"record_t\",_,_,_)"), 9));
									find_record_field_bounds(0, Field_num, 1, First_field_type, &Upper_bound, &Lower_bound);
									ss << Res_name << "[" << Upper_bound << ":" << Lower_bound << "] <= ";
									ss << Left_name << ";" << endl;
								}
							}
						}
					}
				}
			}
			else if (HT.findfact("prog_stmt(" + Module_name + "," + to_string(Operation) + ",_,109,0,_,_,_)"))
			{
				ss << endl;
				HT.assertz("found_call_operator(" + Module_name + "," + to_string(Operation) + ")");
			}
			else if (HT.findfact("prog_stmt(" + Module_name + "," + to_string(Operation) + ",_,110,0,_,_,_)"))
			{
				ss << endl;
			}
			else if (HT.findfact("prog_stmt(" + Module_name + "," + to_string(Operation) + ",*)"))
			{
				Op_numb = stoi(returnpar(HT.findandreturn("prog_stmt(" + Module_name + "," + to_string(Operation) + ",*)"), 4));
				Left_op = stoi(returnpar(HT.findandreturn("prog_stmt(" + Module_name + "," + to_string(Operation) + ",*)"), 5));
				Right_op = stoi(returnpar(HT.findandreturn("prog_stmt(" + Module_name + "," + to_string(Operation) + ",*)"), 6));
				Res_op = stoi(returnpar(HT.findandreturn("prog_stmt(" + Module_name + "," + to_string(Operation) + ",*)"), 7));
				if (Op_numb != 103 && Op_numb != 104 && Op_numb != 105 && Op_numb != 106 && Op_numb != 107 && Op_numb != 108 && Op_numb != 109 && Op_numb != 110)
				{
					if (HT.findfact("op_def(" + to_string(Op_numb) + ",_,\"binop\",_,_,_,_)"))
					{
						Op_string = returnpar(HT.findandreturn("op_def(" + to_string(Op_numb) + ",_,\"binop\",_,_,_,_)"), 2);
						if (HT.findfact("data_stmt(" + Module_name + ",_," + to_string(Left_op) + ",_,_,_)"))
						{
							Left_name = returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Left_op) + ",_,_,_)"), 2);
							Left_kind = returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Left_op) + ",_,_,_)"), 5);
							if (HT.findfact("data_stmt(" + Module_name + ",_," + to_string(Right_op) + ",_,_,_)"))
							{
								Right_name = returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Right_op) + ",_,_,_)"), 2);
								Right_kind = returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Right_op) + ",_,_,_)"), 5);
								if (HT.findfact("data_stmt(" + Module_name + ",_," + to_string(Res_op) + ",_,_,_)"))
								{
									Res_name = returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Res_op) + ",_,_,_)"), 2);
									Res_kind = returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Res_op) + ",_,_,_)"), 5);
									ss << type_op_triple(Module_name, Res_name, Left_name, Right_name, Res_kind, Left_kind, Right_kind, Op_string, " <= ", "verilog") << endl;
								}
							}
						}
					}
				}
				else if (Op_numb != 103 && Op_numb != 104 && Op_numb != 105 && Op_numb != 106 && Op_numb != 107 && Op_numb != 108 && Op_numb != 110)
				{
					if (HT.findfact("op_def(" + to_string(Op_numb) + ",_,\"binop\",_,_,_,_)"))
					{
						Op_string = returnpar(HT.findandreturn("op_def(" + to_string(Op_numb) + ",_,\"binop\",_,_,_,_)"), 2);
						if (HT.findfact("data_stmt(" + Module_name + ",_," + to_string(Left_op) + ",_,_,_)"))
						{
							Left_name = returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Left_op) + ",_,_,_)"), 2);
							Left_kind = returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Left_op) + ",_,_,_)"), 5);
							if (HT.findfact("data_stmt(" + Module_name + ",_," + to_string(Right_op) + ",_,_,_)"))
							{
								Right_name = returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Right_op) + ",_,_,_)"), 2);
								Right_kind = returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Right_op) + ",_,_,_)"), 5);
								if (HT.findfact("data_stmt(" + Module_name + ",_," + to_string(Res_op) + ",_,_,_)"))
								{
									Res_name = returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Res_op) + ",_,_,_)"), 2);
									Res_kind = returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Res_op) + ",_,_,_)"), 5);
									ss << type_op_triple(Module_name, Res_name, Left_name, Right_name, Res_kind, Left_kind, Right_kind, Op_string, " <= ", "verilog") << endl;
								}
							}
						}
					}
				}
			}
		}
	}
	else if (Tool == "gnu")
	{
		if (HDL == "c")
		{
			if (Operation == 0)
			{
				ss << endl;
			}
			else if (HT.findfact("prog_stmt(" + Module_name + "," + to_string(Operation) + ",_,102,_,_,_,_)"))
			{
				Right_op = stoi(returnpar(HT.findandreturn("prog_stmt(" + Module_name + "," + to_string(Operation) + ",_,102,_,_,_,_)"), 6));
				Res_op = stoi(returnpar(HT.findandreturn("prog_stmt(" + Module_name + "," + to_string(Operation) + ",_,102,_,_,_,_)"), 7));
				if (Res_op > 0)
				{
					if (Right_op > 0)
					{
						if (HT.findfact("data_stmt(" + Module_name + ",_," + to_string(Res_op) + ",_,_,_)"))
						{
							Res_name = returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Res_op) + ",_,_,_)"), 2);
							Res_type = stoi(returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Res_op) + ",_,_,_)"), 4));
							if (HT.findfact("type_def(" + to_string(Res_type) + ",_,_,_,_,\"vectorarray_t\",_,_,_)"))
							{
								Number_of_Elements = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Res_type) + ",_,_,_,_,\"vectorarray_t\",_,_,_)"), 8));
								Element_type = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Res_type) + ",_,_,_,_,\"vectorarray_t\",_,_,_)"), 9));
								if (HT.findfact("type_def(" + to_string(Element_type) + ",_,_,_,_,\"single_t\",_,_,_)"))
								{
									if (HT.findfact("data_stmt(" + Module_name + ",_," + to_string(Right_op) + "," + to_string(Res_type) + ",_,_)"))
									{
										Right_name = stoi(returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Right_op) + "," + to_string(Res_type) + ",_,_)"), 9));
										UpLimit = Number_of_Elements - 1;
										ss << "for  (" << Res_name << "_i = 0; " << Res_name << "_i  <= " << UpLimit << "; " << Res_name << "_i = " << Res_name << "_i + 1 ) { " << endl;
										ss << "                  (* " << Res_name << ")";
										ss << "[" << Res_name << "_i] ";
										ss << " = (* " << Right_name << ")";
										ss << "[" << Res_name << "_i] ";
										ss << "; }" << endl;
										ss << "         printf(" << '"' << Res_name << " = " << Right_name << '\\' << "n" << '"' << ");" << endl;
									}
								}
								else if (HT.findfact("type_def(" + to_string(Element_type) + ",*)"))
								{
									Kind = returnpar(HT.findandreturn("type_def(" + to_string(Element_type) + ",*)"), 6);
									if (Kind != "single_t")
									{
										if (HT.findfact("data_stmt(" + Module_name + ",_," + to_string(Right_op) + "," + to_string(Res_type) + ",_,_)"))
										{
											Right_name = stoi(returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Right_op) + "," + to_string(Res_type) + ",_,_)"), 9));
											ss << reset_multi_array(Res_name, Res_type, 1, &Dimension_depth, 0, 1);
											if (Dimension_depth > 1)
											{
												ss << "        (* " << Res_name << ")";
												ss << write_array_dim_depth(Res_name, 1, Dimension_depth);
												ss << " = (* " << Right_name << ")";
												ss << write_array_dim_depth(Res_name, 1, Dimension_depth);
												ss << ";" << endl;
												Dim_minus_one = Dimension_depth - 1;
												ss << write_array_end_loop(Dim_minus_one) << endl;
												ss << "         printf(" << '"' << Res_name << " = " << Right_name << '\\' << "n" << '"' << ");" << endl;
											}
										}
									}
								}
							}
						}
					}
				}
				else if (Res_op != 0)
				{
					if (Right_op < 0)
					{
						if (HT.findfact("data_stmt(" + Module_name + ",_," + to_string(Res_op) + ",_,_,_)"))
						{
							Res_name = returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Res_op) + ",_,_,_)"), 2);
							Res_type = stoi(returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Res_op) + ",_,_,_)"), 4));
							if (HT.findfact("type_def(" + to_string(Res_type) + ",_,_,_,_,\"record_t\",_,_,_)"))
							{
								Type_name = returnpar(HT.findandreturn("type_def(" + to_string(Res_type) + ",_,_,_,_,\"record_t\",_,_,_)"), 2);
								if (HT.findfact("rec_stmt(" + Module_name + "," + to_string(Right_op) + ",*)"))
								{
									Param_list = returnVec(makeInstanceOf(HT.findandreturn("rec_stmt(" + Module_name + "," + to_string(Right_op) + ",*)")), 1);
									ss << Type_name << " " << Res_name << " = { ";
									ss << write_param_list(Module_name, Param_list);
									ss << " };" << endl;
									ss << "         printf(" << '"' << Res_name << " = { " << endl;
									ss << write_param_list(Module_name, Param_list);
									ss << '"' << " } = {";
									ss << write_param_list(Module_name, Param_list);
									ss << "};" << endl;
								}
							}
							else if (HT.findfact("type_def(" + to_string(Res_type) + ",_,_,_,_,\"vectorarray_t\", _,_,_)"))
							{
								Comp_type = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Res_type) + ",_,_,_,_,\"vectorarray_t\", _,_,_)"), 9));
								if (HT.findfact("type_def(" + to_string(Comp_type) + ",*)"))
								{
									ss << Res_name << " = {";
									if (HT.findfact("rec_stmt(" + Module_name + "," + to_string(Right_op) + ",*)"))
									{
										Param_list = returnVec(makeInstanceOf(HT.findandreturn("rec_stmt(" + Module_name + "," + to_string(Right_op) + ",*)")), 1);
										ss << write_param_list(Module_name, Param_list);
										ss << " };" << endl;
										ss << "         printf(" << '"' << Res_name << " = { ";
										ss << write_param_list(Module_name, Param_list);
										ss << " } = " << '\\' << "n" << '"' << " { ";
										ss << write_param_list(Module_name, Param_list);
										ss << ";" << endl;
									}
								}
							}
						}
					}
				}
			}
			else if (HT.findfact("prog_stmt(" + Module_name + "," + to_string(Operation) + ",_,104,_,_,_,_)"))
			{
				Right_op = stoi(returnpar(HT.findandreturn("prog_stmt(" + Module_name + "," + to_string(Operation) + ",_,104,_,_,_,_)"), 6));
				Res_op = stoi(returnpar(HT.findandreturn("prog_stmt(" + Module_name + "," + to_string(Operation) + ",_,104,_,_,_,_)"), 7));
				if (HT.findfact("data_stmt(" + Module_name + ",_," + to_string(Res_op) + ",_,_,_)"))
				{
					Res_name = returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Res_op) + ",_,_,_)"), 2);
					ss << Res_name;
					ss << " = ";
					ss << Res_name;
					ss << " + ";
					ss << Right_op;
					ss << ";" << endl;
					ss << "         printf(" << '"' << Res_name << " = " << Res_name << " + " << Right_op << " = %d" << '\\' << "n" << '"' << ", " << Res_name << ");" << endl;
				}
			}
			else if (HT.findfact("prog_stmt(" + Module_name + "," + to_string(Operation) + ",_,105,_,_,_,_)"))
			{
				Right_op = stoi(returnpar(HT.findandreturn("prog_stmt(" + Module_name + "," + to_string(Operation) + ",_,105,_,_,_,_)"), 6));
				Res_op = stoi(returnpar(HT.findandreturn("prog_stmt(" + Module_name + "," + to_string(Operation) + ",_,105,_,_,_,_)"), 7));
				if (HT.findfact("data_stmt(" + Module_name + ",_," + to_string(Res_op) + ",_,_,_)"))
				{
					Res_name = returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Res_op) + ",_,_,_)"), 2);
					ss << Res_name;
					ss << " = ";
					ss << Res_name;
					ss << " - ";
					ss << Right_op;
					ss << ";" << endl;
					ss << "         printf(" << '"' << Res_name << " = " << Res_name << " - " << Right_op << " = %d" << '\\' << "n" << '"' << ", " << Res_name << ");" << endl;
				}
			}
			else if (HT.findfact("prog_stmt(" + Module_name + "," + to_string(Operation) + ",_,106,0,_,_,_)"))
			{
				ss << endl;
			}
			else if (HT.findfact("prog_stmt(" + Module_name + "," + to_string(Operation) + ",_,107,_,_,_,_)"))
			{
				Left_op = stoi(returnpar(HT.findandreturn("prog_stmt(" + Module_name + "," + to_string(Operation) + ",_,107,_,_,_,_)"), 5));
				Right_op = stoi(returnpar(HT.findandreturn("prog_stmt(" + Module_name + "," + to_string(Operation) + ",_,107,_,_,_,_)"), 6));
				Res_op = stoi(returnpar(HT.findandreturn("prog_stmt(" + Module_name + "," + to_string(Operation) + ",_,107,_,_,_,_)"), 7));
				if (Res_op != 0)
				{
					if (HT.findfact("data_stmt(" + Module_name + ",_," + to_string(Left_op) + ",_,_,_)"))
					{
						Left_name = returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Left_op) + ",_,_,_)"), 2);
						Left_type = stoi(returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Left_op) + ",_,_,_)"), 4));
						if (HT.findfact("type_def(" + to_string(Left_type) + ",_,_,_,_,\"vectorarray_t\",_,_,_)"))
						{
							if (HT.findfact("data_stmt(" + Module_name + ",_," + to_string(Res_op) + ",_,_,_)"))
							{
								Res_name = returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Res_op) + ",_,_,_)"), 2);
								ss << Res_name << " = ";
								ss << "(* " << Left_name << ")";
								ss << write_verilog_array_index(Module_name, Right_op);
								ss << ";" << endl;
								ss << "         printf(" << '"' << Res_name << " = " << Left_name;
								ss << write_verilog_array_index(Module_name, Right_op);
								ss << '\\' << "n" << '"' << ");" << endl;
							}
						}
						else if (HT.findfact("type_def(" + to_string(Left_type) + ",_,_,_,_,\"record_t\",_,_,_)"))
						{
							First_field_type = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Left_type) + ",_,_,_,_,\"record_t\",_,_,_)"), 9));
							if (HT.findfact("data_stmt(" + Module_name + ",_," + to_string(Right_op) + ",_,\"const\",i(*))"))
							{
								Field_num = stoi(returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Right_op) + ",_,\"const\",i(*))"), 7));
								find_rec_field_string(First_field_type, Field_num, &Field_string);
								if (HT.findfact("data_stmt(" + Module_name + ",_," + to_string(Res_op) + ",_,_,_)"))
								{
									Res_name = returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Res_op) + ",_,_,_)"), 2);
									ss << Res_name << " = ";
									ss << Left_name << Field_string << ";" << endl;
									ss << "         printf(" << '"' << Res_name << " = " << Left_name << Field_string << " = %d" << '\\' << "n" << '"' << ", " << Res_name << ");" << endl;
								}
							}
						}
					}
				}
			}
			else if (HT.findfact("prog_stmt(" + Module_name + "," + to_string(Operation) + ",_,108,_,_,_,_)"))
			{
				Field_num = stoi(returnpar(HT.findandreturn("prog_stmt(" + Module_name + "," + to_string(Operation) + ",_,108,_,_,_,_)"), 3));
				Left_op = stoi(returnpar(HT.findandreturn("prog_stmt(" + Module_name + "," + to_string(Operation) + ",_,108,_,_,_,_)"), 5));
				Right_op = stoi(returnpar(HT.findandreturn("prog_stmt(" + Module_name + "," + to_string(Operation) + ",_,108,_,_,_,_)"), 6));
				Res_op = stoi(returnpar(HT.findandreturn("prog_stmt(" + Module_name + "," + to_string(Operation) + ",_,108,_,_,_,_)"), 7));
				if (Field_num > 0)
				{
					if (Res_op != 0)
					{
						if (Right_op > 0)
						{
							if (HT.findfact("data_stmt(" + Module_name + ",_," + to_string(Left_op) + ",_,_,_)"))
							{
								Left_name = returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Left_op) + ",_,_,_)"), 2);
								Left_type = stoi(returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Left_op) + ",_,_,_)"), 4));
								if (HT.findfact("data_stmt(" + Module_name + ",_," + to_string(Right_op) + ",_,_,_)"))
								{
									Right_name = returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Right_op) + ",_,_,_)"), 2);
									if (HT.findfact("data_stmt(" + Module_name + ",_," + to_string(Res_op) + ",_,_,_)"))
									{
										Res_name = returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Res_op) + ",_,_,_)"), 2);
										Res_type = stoi(returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Res_op) + ",_,_,_)"), 4));
										if (HT.findfact("type_def(" + to_string(Res_type) + ",_,_,_,_,\"vectorarray_t\",_,_,_)"))
										{
											Records_type = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Res_type) + ",_,_,_,_,\"vectorarray_t\",_,_,_)"), 9));
											if (HT.findfact("type_def(" + to_string(Records_type) + ",_,_,_,_,\"record_t\",_,_,_)"))
											{
												Records_type = Left_type;
												ss << "(* " << Res_name << ")[" << Right_name << "] = " << Left_name << " ;" << endl;
												ss << "         printf(" << '"' << Res_name << "[" << Right_name << "] = " << Left_name << " %d" << '\\' << "n" << '"' << ", " << Res_name << "[" << Right_name << "]);" << endl;
											}
										}
									}
								}
							}
						}
						else if (Right_op < 0)
						{
							if (HT.findfact("data_stmt(" + Module_name + ",_," + to_string(Left_op) + ",_,_,_)"))
							{
								Left_name = returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Left_op) + ",_,_,_)"), 2);
								Left_type = stoi(returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Left_op) + ",_,_,_)"), 4));
								if (HT.findfact("data_stmt(" + Module_name + ",_," + to_string(Right_op) + ",_,_,_)"))
								{
									if (HT.findfact("data_stmt(" + Module_name + ",_," + to_string(Res_op) + ",_,_,_)"))
									{
										Res_name = returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Res_op) + ",_,_,_)"), 2);
										Res_type = stoi(returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Res_op) + ",_,_,_)"), 4));
										if (HT.findfact("type_def(" + to_string(Res_type) + ",_,_,_,_,\"vectorarray_t\",_,_,_)"))
										{
											Records_type = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Res_type) + ",_,_,_,_,\"vectorarray_t\",_,_,_)"), 9));
											if (HT.findfact("type_def(" + to_string(Records_type) + ",_,_,_,_,\"record_t\",_,_,_)"))
											{
												First_field_type = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Records_type) + ",_,_,_,_,\"record_t\",_,_,_)"), 9));
												find_rec_field_string(First_field_type, Field_num, &Field_string);
												if (HT.findfact("compo_stmt(" + Module_name + "," + to_string(Right_op) + ",*)"))
												{
													Param_list = returnVec(makeInstanceOf(HT.findandreturn("compo_stmt(" + Module_name + "," + to_string(Right_op) + ",*)")), 1);
													if (Records_type == Left_type)
													{
														ss << "(* " << Res_name << ")";
														ss << print_array_index_parameters(Module_name, Param_list);
														ss << Field_string << " = " << Left_name << " ;" << endl;
														ss << "         printf(" << '"' << Res_name;
														ss << print_array_index_parameters(Module_name, Param_list);
														ss << Field_string << " = " << Left_name << '\\' << "n" << '"' << ");" << endl;
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
				else if (Res_op != 0)
				{
					if (Left_op > 0)
					{
						if (HT.findfact("data_stmt(" + Module_name + ",_," + to_string(Left_op) + ",_,_,_)"))
						{
							Left_name = returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Left_op) + ",_,_,_)"), 2);
							if (HT.findfact("data_stmt(" + Module_name + ",_," + to_string(Res_op) + ",_,_,_)"))
							{
								Res_name = returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Res_op) + ",_,_,_)"), 2);
								Res_type = stoi(returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Res_op) + ",_,_,_)"), 4));
								if (HT.findfact("type_def(" + to_string(Res_type) + ",_,_,_,_,\"vectorarray_t\",_,_,_)"))
								{
									ss << "(* " << Res_name << ")";
									ss << write_verilog_array_index(Module_name, Right_op);
									ss << " = ";
									ss << Left_name << ";" << endl;
									ss << "         printf(" << '"' << Res_name;
									ss << write_verilog_array_index(Module_name, Right_op);
									ss << " = " << Left_name << " = %d" << '\\' << "n" << '"' << ", " << Res_name << ");" << endl;
								}
							}
						}
					}
					else if (Left_op < 0)
					{
						if (HT.findfact("data_stmt(" + Module_name + ",_," + to_string(Res_op) + ",_,_,_)"))
						{
							Res_name = returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Res_op) + ",_,_,_)"), 2);
							Res_type = stoi(returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Res_op) + ",_,_,_)"), 4));
							if (HT.findfact("type_def(" + to_string(Res_type) + ",_,_,_,_,\"vectorarray_t\",_,_,_)"))
							{
								Comp_type = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Res_type) + ",_,_,_,_,\"vectorarray_t\",_,_,_)"), 9));
								if (HT.findfact("type_def(" + to_string(Comp_type) + ",_,_,_,_,\"record_t\",_,_,_)"))
								{
									CompType_name = returnpar(HT.findandreturn("type_def(" + to_string(Comp_type) + ",_,_,_,_,\"record_t\",_,_,_)"), 2);
									ss << "(* " << Res_name << ")";
									ss << write_verilog_array_index(Module_name, Right_op);
									ss << " = (";
									ss << CompType_name;
									ss << ") { ";
									if (HT.findfact("rec_stmt(" + Module_name + "," + to_string(Left_op) + ",*)"))
									{
										Param_list = returnVec(makeInstanceOf(HT.findandreturn("rec_stmt(" + Module_name + "," + to_string(Left_op) + ",*)")), 1);
										ss << write_param_list(Module_name, Param_list);
										ss << " };" << endl;
										ss << "         printf(" << '"' << Res_name;
										ss << write_verilog_array_index(Module_name, Right_op);
										ss << " = (";
										ss << CompType_name;
										ss << ") {";
										if (HT.findfact("rec_stmt(" + Module_name + "," + to_string(Left_op) + ",*)"))
										{
											Param_list = returnVec(makeInstanceOf(HT.findandreturn("rec_stmt(" + Module_name + "," + to_string(Left_op) + ",*)")), 1);
											ss << write_param_list(Module_name, Param_list);
											ss << "}" << '\\' << "n" << '"' << ");" << endl;
										}
									}
								}
							}
						}
					}
					else if (HT.findfact("data_stmt(" + Module_name + ",_," + to_string(Left_op) + ",_,_,_)"))
					{
						Left_name = returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Left_op) + ",_,_,_)"), 2);
						if (HT.findfact("data_stmt(" + Module_name + ",_," + to_string(Right_op) + ",_,\"const\",i(*))"))
						{
							Field_num = stoi(returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Right_op) + ",_,\"const\",i(*))"), 7));
							if (HT.findfact("data_stmt(" + Module_name + ",_," + to_string(Res_op) + ",_,_,_)"))
							{
								Res_name = returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Res_op) + ",_,_,_)"), 2);
								Res_type = stoi(returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Res_op) + ",_,_,_)"), 4));
								if (HT.findfact("type_def(" + to_string(Res_type) + ",_,_,_,_,\"record_t\",_,_,_)"))
								{
									First_field_type = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Res_type) + ",_,_,_,_,\"record_t\",_,_,_)"), 9));
									find_rec_field_string(First_field_type, Field_num, &Field_string);
									ss << Res_name << Field_string << " = ";
									ss << Left_name << ";" << endl;
									ss << "         printf(" << '"' << Res_name << Field_string << " = " << Left_name << " = %d" << '\\' << "n" << '"' << ", " << Res_name << Field_string << ");" << endl;
								}
							}
						}
					}
				}
			}
			else if (HT.findfact("prog_stmt(" + Module_name + "," + to_string(Operation) + ",_,109,0,_,_,_)"))
			{
				ss << endl;
				HT.assertz("found_call_operator(" + Module_name + "," + to_string(Operation) + ")");
			}
			else if (HT.findfact("prog_stmt(" + Module_name + "," + to_string(Operation) + ",_,110,0,_,_,_)"))
			{
				ss << endl;
			}
			else if (HT.findfact("prog_stmt(" + Module_name + "," + to_string(Operation) + ",_,_,0,_,_,_)"))
			{
				Op_numb = stoi(returnpar(HT.findandreturn("prog_stmt(" + Module_name + "," + to_string(Operation) + ",_,_,0,_,_,_)"), 4));
				Right_op = stoi(returnpar(HT.findandreturn("prog_stmt(" + Module_name + "," + to_string(Operation) + ",_,_,0,_,_,_)"), 6));
				Res_op = stoi(returnpar(HT.findandreturn("prog_stmt(" + Module_name + "," + to_string(Operation) + ",_,_,0,_,_,_)"), 7));
				if (Op_numb != 103 && Op_numb != 104 && Op_numb != 105 && Op_numb != 106 && Op_numb != 107 && Op_numb != 108 && Op_numb != 109 && Op_numb != 110)
				{
					if (HT.findfact("op_def(" + to_string(Op_numb) + ",_,\"unop\",_,_,_,_)"))
					{
						Op_string = returnpar(HT.findandreturn("op_def(" + to_string(Op_numb) + ",_,\"unop\",_,_,_,_)"), 2);
						if (HT.findfact("data_stmt(" + Module_name + ",_," + to_string(Right_op) + ",_,_,_)"))
						{
							Right_name = returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Right_op) + ",_,_,_)"), 2);
							Right_type = stoi(returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Right_op) + ",_,_,_)"), 4));
							Right_kind = returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Right_op) + ",_,_,_)"), 5);
							if (HT.findfact("data_stmt(" + Module_name + ",_," + to_string(Res_op) + ",_,_,_)"))
							{
								Res_name = returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Res_op) + ",_,_,_)"), 2);
								Res_type = stoi(returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Res_op) + ",_,_,_)"), 4));
								Res_kind = returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Res_op) + ",_,_,_)"), 5);
								if (HT.findfact("type_def(" + to_string(Right_type) + ",*)"))
								{
									Right_category = returnpar(HT.findandreturn("type_def(" + to_string(Right_type) + ",*)"), 6);
									if (Right_category != "vectorarray_t")
									{
										if (HT.findfact("type_def(" + to_string(Res_type) + ",*)"))
										{
											Res_category = returnpar(HT.findandreturn("type_def(" + to_string(Res_type) + ",*)"), 6);
											if (Res_category != "vectorarray_t")
											{
												translate_operator_symbol(Op_string, &C_op_string, &CloseParenthesis, &ExtraAss);
												ss << Res_name << ExtraAss << " " << C_op_string << " " << CloseParenthesis << Right_name << " ;" << endl;
												ss << "         printf(" << '"' << Res_name << ExtraAss << C_op_string << CloseParenthesis << " ";
												ss << type_value(Module_name, Right_op, "c");
												ss << " = %d" << '\\' << "n" << '"' << ", " << Res_name << ");" << endl;
											}
										}
									}
									else if (Right_category == "vectorarray_t")
									{
										if (HT.findfact("type_def(" + to_string(Res_type) + ",*)"))
										{
											Res_category = returnpar(HT.findandreturn("type_def(" + to_string(Res_type) + ",*)"), 6);
											if (Res_category == "vectorarray_t")
											{
												translate_operator_symbol(Op_string, &C_op_string, &CloseParenthesis, &ExtraAss);
												ss << Res_name << ExtraAss << " " << C_op_string << " " << Right_name << CloseParenthesis << " ;" << endl;
												ss << "         printf(" << '"' << Res_name << ExtraAss << " " << C_op_string << " " << Right_name << CloseParenthesis << " = %d" << '\\' << "n" << '"' << ", " << Res_name << ");" << endl;
											}
										}
									}
									else if (HT.findfact("type_def(" + to_string(Res_type) + ",*)"))
									{
										Res_category = returnpar(HT.findandreturn("type_def(" + to_string(Res_type) + ",*)"), 6);
										if (one_of_two_not_same_array(Right_category, Res_category, Right_type, Res_type))
										{
											ss << type_op_tuple(Module_name, Res_name, Right_name, Res_kind, Right_kind, Op_string) << endl;
											translate_operator_symbol(Op_string, &C_op_string, &CloseParenthesis, &ExtraAss);
											ss << "         printf(" << '"' << Res_name << " " << ExtraAss << C_op_string << CloseParenthesis << " ";
											ss << type_value(Module_name, Right_op, "c");
											ss << " = %d" << '\\' << "n" << '"' << ", " << Res_name << ");" << endl;
										}
									}
								}
							}
						}
					}
				}
			}
			else if (HT.findfact("prog_stmt(" + Module_name + "," + to_string(Operation) + ",*)"))
			{
				Op_numb = stoi(returnpar(HT.findandreturn("prog_stmt(" + Module_name + "," + to_string(Operation) + ",*)"), 4));
				Left_op = stoi(returnpar(HT.findandreturn("prog_stmt(" + Module_name + "," + to_string(Operation) + ",*)"), 5));
				Right_op = stoi(returnpar(HT.findandreturn("prog_stmt(" + Module_name + "," + to_string(Operation) + ",*)"), 6));
				Res_op = stoi(returnpar(HT.findandreturn("prog_stmt(" + Module_name + "," + to_string(Operation) + ",*)"), 7));
				if (Op_numb != 103 && Op_numb != 104 && Op_numb != 105 && Op_numb != 106 && Op_numb != 107 && Op_numb != 108 && Op_numb != 109 && Op_numb != 110)
				{
					if (HT.findfact("op_def(" + to_string(Op_numb) + ",_,\"binop\",_,_,_,_)"))
					{
						Op_string = returnpar(HT.findandreturn("op_def(" + to_string(Op_numb) + ",_,\"binop\",_,_,_,_)"), 2);
						if (HT.findfact("data_stmt(" + Module_name + ",_," + to_string(Left_op) + ",_,_,_)"))
						{
							Left_name = returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Left_op) + ",_,_,_)"), 2);
							Left_kind = returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Left_op) + ",_,_,_)"), 5);
							if (HT.findfact("data_stmt(" + Module_name + ",_," + to_string(Right_op) + ",_,_,_)"))
							{
								Right_name = returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Right_op) + ",_,_,_)"), 2);
								Right_kind = returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Right_op) + ",_,_,_)"), 5);
								if (HT.findfact("data_stmt(" + Module_name + ",_," + to_string(Res_op) + ",_,_,_)"))
								{
									Res_name = returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Res_op) + ",_,_,_)"), 2);
									Res_kind = returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Res_op) + ",_,_,_)"), 5);
									ss << type_op_triple(Module_name, Res_name, Left_name, Right_name, Res_kind, Left_kind, Right_kind, Op_string, " = ", "c") << endl;
									ss << "         printf(" << '"' << Res_name << " = ";
									ss << type_value(Module_name, Left_op, "c");
									ss << " " << Op_string << " ";
									ss << type_value(Module_name, Right_op, "c");
									ss << " = %d" << '\\' << "n" << '"' << ", " << Res_name << ");" << endl;
								}
							}
						}
					}
				}
				else if (Op_numb != 103 && Op_numb != 104 && Op_numb != 105 && Op_numb != 106 && Op_numb != 107 && Op_numb != 108 && Op_numb != 110)
				{
					if (HT.findfact("op_def(" + to_string(Op_numb) + ",_,\"binop\",_,_,_,_)"))
					{
						Op_string = returnpar(HT.findandreturn("op_def(" + to_string(Op_numb) + ",_,\"binop\",_,_,_,_)"), 2);
						if (HT.findfact("data_stmt(" + Module_name + ",_," + to_string(Left_op) + ",_,_,_)"))
						{
							Left_name = returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Left_op) + ",_,_,_)"), 2);
							Left_kind = returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Left_op) + ",_,_,_)"), 5);
							if (HT.findfact("data_stmt(" + Module_name + ",_," + to_string(Right_op) + ",_,_,_)"))
							{
								Right_name = returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Right_op) + ",_,_,_)"), 2);
								Right_kind = returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Right_op) + ",_,_,_)"), 5);
								if (HT.findfact("data_stmt(" + Module_name + ",_," + to_string(Res_op) + ",_,_,_)"))
								{
									Res_name = returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Res_op) + ",_,_,_)"), 2);
									Res_kind = returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Res_op) + ",_,_,_)"), 5);
									ss << type_op_triple(Module_name, Res_name, Left_name, Right_name, Res_kind, Left_kind, Right_kind, Op_string, " = ", "c") << endl;
									ss << "         printf(" << '"' << Res_name << " = ";
									ss << type_value(Module_name, Left_op, "c");
									ss << " " << Op_string << " ";
									ss << type_value(Module_name, Right_op, "c");
									ss << " = %d" << '\\' << "n" << '"' << ", " << Res_name << ");" << endl;
								}
							}
						}
					}
				}
			}
		}
	}
	return ss.str();
}

string write_param_list(string Module, vector<int> Param_list)
{
	stringstream ss;
	string Object_name;

	if (!Param_list.empty())
	{
		if (Param_list.size() == 1)
		{
			if (HT.findfact("data_stmt(" + Module + ",_," + to_string(Param_list.front()) + ",_,_,_)"))
			{
				Object_name = returnpar(HT.findandreturn("data_stmt(" + Module + ",_," + to_string(Param_list.front()) + ",_,_,_)"), 2);
				ss << " " << Object_name;
			}
		}
		else if (HT.findfact("data_stmt(" + Module + "," + Object_name + "," + to_string(Param_list.front()) + ",_,_,_)"))
		{
			ss << " " << Object_name << ",";
			Param_list.erase(Param_list.begin());
			write_param_list(Module, Param_list);
		}
	}
	return ss.str();
}

bool derived_type(int Type, int Ref)
{
	int Type1;
	if (Type == Ref || HT.findfact("type_def(" + to_string(Type) + ",_,_,_," + to_string(Ref) + ",_,_,_,_)"))
		return true;
	else if (HT.findfact("type_def(" + to_string(Type) + ",*)"))
	{
		Type1 = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Type) + ",*)"), 5));
		if (HT.findfact("type_def(" + to_string(Type1) + ",_,_,_," + to_string(Ref) + ",_,_,_,_)"))
		{
			return true;
		}
	}
	return false;
}

string write_vhdl_array_index(string Module_name, int Right_op)
{
	stringstream ss;
	string Right_name;
	vector<int> Index_parameter_list;
	if (Right_op > 0)
	{
		if (HT.findfact("data_stmt(" + Module_name + ",_," + to_string(Right_op) + ",_,_,_)"))
		{
			Right_name = returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Right_op) + ",_,_,_)"), 2);
			ss << "(CONV_INTEGER(" << Right_name << "))";
		}
	}
	else if (Right_op < 0)
	{
		if (HT.findfact("compo_stmt(" + Module_name + "," + to_string(Right_op) + ",*)"))
		{
			Index_parameter_list = returnVec(makeInstanceOf(HT.findandreturn("compo_stmt(" + Module_name + "," + to_string(Right_op) + ",*)")), 1);
			ss << print_array_index_parameters(Module_name, Index_parameter_list);
		}
	}
	return ss.str();
}

string print_array_index_parameters(string Module_name, vector<int> List)
{
	stringstream ss;
	if (!List.empty())
	{
		ss << print_array_index_parameter(Module_name, List.front());
		List.erase(List.begin());
		ss << print_array_index_parameters(Module_name, List);
	}
	return ss.str();
}

string print_array_index_parameter(string Module_name, int Right_op)
{
	stringstream ss;
	string Right_name, Kind, Ivalue, HDL;
	if (HT.findfact("hdl_style(\"vhdl\")"))
	{
		if (HT.findfact("data_stmt(" + Module_name + ",_," + to_string(Right_op) + ",_,_,_)"))
		{
			Right_name = returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Right_op) + ",_,_,_)"), 2);
			Kind = returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Right_op) + ",_,_,_)"), 5);
			if (Kind != "par_out")
			{
				if (Kind != "const")
				{
					ss << "(CONV_INTEGER(" << Right_name << "))";
				}
			}
		}
		else if (HT.findfact("data_stmt(" + Module_name + ",_," + to_string(Right_op) + ",_,\"const\",i(*))"))
		{
			Ivalue = returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Right_op) + ",_,_,_)"), 7);
			ss << "(" << Ivalue << ")";
		}
	}
	else if (HT.findfact("hdl_style(*)"))
	{
		HDL = returnpar(HT.findandreturn("hdl_style(*)"), 1);
		if (HDL != "vhdl")
		{
			if (HT.findfact("data_stmt(" + Module_name + ",_," + to_string(Right_op) + ",_,_,_)"))
			{
				Right_name = returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Right_op) + ",_,_,_)"), 2);
				Kind = returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Right_op) + ",_,_,_)"), 5);
				if (Kind != "par_out")
				{
					if (Kind != "const")
					{
						ss << "[" << Right_name << "]";
					}
				}
			}
			else if (HT.findfact("data_stmt(" + Module_name + ",_," + to_string(Right_op) + ",_,\"const\",i(*))"))
			{
				Ivalue = returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Right_op) + ",_,_,_)"), 7);
				ss << "[" << Ivalue << "]";
			}
		}
	}
	return ss.str();
}

void find_rec_field_string(int First_field_type, int Field_num, string* Field_string)
{
	int Field_type_num;
	Field_type_num = First_field_type + Field_num - 1;
	if (HT.findfact("type_def(" + to_string(Field_type_num) + ",*)"))
	{
		*Field_string = returnpar(HT.findandreturn("type_def(" + to_string(Field_type_num) + ",*)"), 2);
	}
	else
	{
		*Field_string = "field_not_found";
	}
}

bool one_of_two_not_same_array(string str1, string str2, int int1, int int2)
{
	if (str1 != "vectorarray_t")
		return true;
	if (str2 != "vectorarray_t")
		return true;
	if (str1 == "vectorarray_t" && int1 != int2)
		return true;
	if (str2 == "vectorarray_t" && int1 != int2)
		return true;
	return false;
}

string type_op_tuple(string Module_name, string Res_name, string Right_name, string str4, string str5, string Op_string)
{
	stringstream ss;
	string HDL;
	int Res_type, Res_size, Right_type, Right_size, Res_up_limit, Right_up_limit;
	if (Op_string == "-")
	{
		if (HT.findfact("hdl_style(\"vhdl\")"))
		{
			if (HT.findfact("data_stmt(" + Module_name + "," + Res_name + ",*)"))
			{
				Res_type = stoi(returnpar(HT.findandreturn("data_stmt(" + Module_name + "," + Res_name + ",*)"), 4));
				if (HT.findfact("type_def(" + to_string(Res_type) + ",*)"))
				{
					Res_size = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Res_type) + ",*)"), 3));
					ss << Res_name << " <= conv_std_logic_vector((-conv_integer(";
					ss << Right_name << ")), " << Res_size << ");";
				}
			}
		}
		else if (HT.findfact("hdl_style(\"verilog\")"))
		{
			if (HT.findfact("data_stmt(" + Module_name + "," + Res_name + ",*)"))
			{
				Res_type = stoi(returnpar(HT.findandreturn("data_stmt(" + Module_name + "," + Res_name + ",*)"), 4));
				if (HT.findfact("type_def(" + to_string(Res_type) + ",*)"))
				{
					ss << Res_name << " <= - " << Right_name << ";";
				}
			}
		}
		else if (HT.findfact("hdl_style(\"c\")"))
		{
			if (HT.findfact("data_stmt(" + Module_name + "," + Res_name + ",*)"))
			{
				Res_type = stoi(returnpar(HT.findandreturn("data_stmt(" + Module_name + "," + Res_name + ",*)"), 4));
				if (HT.findfact("type_def(" + to_string(Res_type) + ",*)"))
				{
					ss << Res_name << " = -";
					ss << Right_name << ";";
				}
			}
		}
	}
	else if (Op_string == "abs")
	{
		if (HT.findfact("hdl_style(\"vhdl\")"))
		{
			if (HT.findfact("data_stmt(" + Module_name + "," + Res_name + ",*)"))
			{
				Res_type = stoi(returnpar(HT.findandreturn("data_stmt(" + Module_name + "," + Res_name + ",*)"), 4));
				if (HT.findfact("type_def(" + to_string(Res_type) + ",*)"))
				{
					Res_size = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Res_type) + ",*)"), 3));
					ss << Res_name << " <= conv_std_logic_vector(abs(conv_integer(";
					ss << Right_name << ")), " << Res_size << ");";
				}
			}
		}
		else if (HT.findfact("hdl_style(\"verilog\")"))
		{
			if (HT.findfact("data_stmt(" + Module_name + "," + Res_name + ",*)"))
			{
				Res_type = stoi(returnpar(HT.findandreturn("data_stmt(" + Module_name + "," + Res_name + ",*)"), 4));
				if (HT.findfact("type_def(" + to_string(Res_type) + ",*)"))
				{
					ss << "// The Abs operator doesn't exist in Verilog: " << endl;
					ss << "if (" << Res_name << " >= 0) " << Res_name << " <= " << Right_name << ";" << endl;
					ss << "       else " << Res_name << " <= - " << Right_name << ";";
				}
			}
		}
		else if (HT.findfact("hdl_style(\"c\")"))
		{
			if (HT.findfact("data_stmt(" + Module_name + "," + Res_name + ",*)"))
			{
				Res_type = stoi(returnpar(HT.findandreturn("data_stmt(" + Module_name + "," + Res_name + ",*)"), 4));
				if (HT.findfact("type_def(" + to_string(Res_type) + ",*)"))
				{
					ss << Res_name << " = abs(";
					ss << Right_name << ") ;";
				}
			}
		}
	}
	else if (Op_string == ":=")
	{
		if (HT.findfact("hdl_style(\"c\")"))
		{
			if (HT.findfact("data_stmt(" + Module_name + "," + Res_name + ",*)"))
			{
				Res_type = stoi(returnpar(HT.findandreturn("data_stmt(" + Module_name + "," + Res_name + ",*)"), 4));
				if (HT.findfact("type_def(" + to_string(Res_type) + ",*)"))
				{
					if (HT.findfact("data_stmt(" + Module_name + "," + Right_name + ",*)"))
					{
						Right_type = stoi(returnpar(HT.findandreturn("data_stmt(" + Module_name + "," + Right_name + ",*)"), 4));
						if (HT.findfact("type_def(" + to_string(Right_type) + ",*)"))
						{
							ss << Res_name << " = " << Right_name << " ;";
						}
					}
				}
			}
		}
		else if (HT.findfact("hdl_style(*)"))
		{
			HDL = returnpar(HT.findandreturn("hdl_style(*)"), 1);
			if (HDL != "c")
			{
				if (HT.findfact("data_stmt(" + Module_name + "," + Res_name + ",*)"))
				{
					Res_type = stoi(returnpar(HT.findandreturn("data_stmt(" + Module_name + "," + Res_name + ",*)"), 4));
					if (HT.findfact("type_def(" + to_string(Res_type) + ",*)"))
					{
						Res_size = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Res_type) + ",*)"), 3));
						if (HT.findfact("data_stmt(" + Module_name + "," + Right_name + ",*)"))
						{
							Right_type = stoi(returnpar(HT.findandreturn("data_stmt(" + Module_name + "," + Right_name + ",*)"), 4));
							if (HT.findfact("type_def(" + to_string(Right_type) + ",*)"))
							{
								Right_size = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Right_type) + ",*)"), 3));
								if (Res_size == 1)
								{
									ss << Res_name << " <= " << Right_name << " ;";
								}
								else if (Res_size <= Right_size)
								{
									if (Res_size > 1)
									{
										Res_up_limit = Res_size - 1;
										ss << Res_name << "(" << Res_up_limit << " DOWNTO 0) <= " << Right_name << "(" << Res_up_limit << " DOWNTO 0) ;";
									}
								}
								else if (Res_size >= Right_size)
								{
									if (Right_size > 1)
									{
										Right_up_limit = Right_size - 1;
										ss << Res_name << "(" << Right_up_limit << " DOWNTO 0) <= " << Right_name << "(" << Right_up_limit << " DOWNTO 0) ;";
									}
								}
							}
						}
					}
				}
			}
		}
	}
	else if (Op_string == "not")
	{
		if (HT.findfact("hdl_style(\"c\")"))
		{
			ss << Res_name << " <= ";
			ss << Right_name << ";";
			ss << " " << "!" << " ";
		}
	}
	else if (HT.findfact("hdl_style(\"c\")"))
	{
		if (Op_string != ":=" && Op_string != "-" && Op_string != "abs" && Op_string != "not")
		{
			ss << Res_name << " <= ";
			ss << " " << Op_string << " ";
			ss << Right_name << ";";
		}
	}
	else if (HT.findfact("hdl_style(*)"))
	{
		HDL = returnpar(HT.findandreturn("hdl_style(*)"), 1);
		if (HDL != "c")
		{
			if (Op_string != ":=" && Op_string != "-" && Op_string != "abs")
			{
				ss << Res_name << " <= ";
				ss << " " << Op_string << " ";
				ss << Right_name << ";";
			}
		}
	}
	return ss.str();
}

string type_op_tuple1(string Module_name, string Res_name, string Right_name, string str4, string str5, string Op_string)
{
	stringstream ss;
	int Res_type, Res_size, Right_type, Right_size;
	if (Op_string == "-")
	{
		if (HT.findfact("hdl_style(\"vhdl\")"))
		{
			if (HT.findfact("data_stmt(" + Module_name + "," + Res_name + ",*)"))
			{
				Res_type = stoi(returnpar(HT.findandreturn("data_stmt(" + Module_name + "," + Res_name + ",*)"), 4));
				if (HT.findfact("type_def(" + to_string(Res_type) + ",*)"))
				{
					ss << Res_name << " <= - ";
					ss << Right_name << ";";
				}
			}
		}
		else if (HT.findfact("hdl_style(\"verilog\")"))
		{
			if (HT.findfact("data_stmt(" + Module_name + "," + Res_name + ",*)"))
			{
				Res_type = stoi(returnpar(HT.findandreturn("data_stmt(" + Module_name + "," + Res_name + ",*)"), 4));
				if (HT.findfact("type_def(" + to_string(Res_type) + ",*)"))
				{
					ss << Res_name << " <= - " << Right_name << ";";
				}
			}
		}
	}
	else if (Op_string == "abs")
	{
		if (HT.findfact("hdl_style(\"vhdl\")"))
		{
			if (HT.findfact("data_stmt(" + Module_name + "," + Res_name + ",*)"))
			{
				Res_type = stoi(returnpar(HT.findandreturn("data_stmt(" + Module_name + "," + Res_name + ",*)"), 4));
				if (HT.findfact("type_def(" + to_string(Res_type) + ",*)"))
				{
					Res_size = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Res_type) + ",*)"), 3));
					ss << Res_name << " <= conv_std_logic_vector(abs(conv_integer(";
					ss << Right_name << ")), " << Res_size << ");";
				}
			}
		}
		else if (HT.findfact("hdl_style(\"verilog\")"))
		{
			if (HT.findfact("data_stmt(" + Module_name + "," + Res_name + ",*)"))
			{
				Res_type = stoi(returnpar(HT.findandreturn("data_stmt(" + Module_name + "," + Res_name + ",*)"), 4));
				if (HT.findfact("type_def(" + to_string(Res_type) + ",*)"))
				{
					ss << "// The Abs operator doesn't exist in Verilog: " << endl;
					ss << "if (" << Res_name << " >= 0) " << Res_name << " <= " << Right_name << ";" << endl;
					ss << "       else " << Res_name << " <= - " << Right_name << ";";
				}
			}
		}
	}
	else if (Op_string == ":=")
	{
		if (HT.findfact("data_stmt(" + Module_name + "," + Res_name + ",*)"))
		{
			Res_type = stoi(returnpar(HT.findandreturn("data_stmt(" + Module_name + "," + Res_name + ",*)"), 4));
			if (HT.findfact("type_def(" + to_string(Res_type) + ",*)"))
			{
				Res_size = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Res_type) + ",*)"), 3));
				if (HT.findfact("data_stmt(" + Module_name + "," + Right_name + ",*)"))
				{
					Right_type = stoi(returnpar(HT.findandreturn("data_stmt(" + Module_name + "," + Right_name + ",*)"), 4));
					if (HT.findfact("type_def(" + to_string(Right_type) + ",*)"))
					{
						Right_size = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Res_type) + ",*)"), 3));
						if (Res_size <= Right_size)
						{
							if (Res_size > 1)
							{
								ss << Res_name << " <= " << Right_name << ";";
							}
						}
						else if (Res_size >= Right_size)
						{
							if (Res_size > 1)
							{
								ss << Res_name << " <= " << Right_name << " ;"; //the same output for all cases?
							}
						}
						else
						{
							ss << Res_name << " <= " << Right_name << " ;";
						}
					}
				}
			}
		}
	}
	else if (Op_string != ":=" && Op_string != "-" && Op_string != "abs")
	{
		ss << Res_name << " <= ";
		ss << " " << Op_string << " ";
		ss << Right_name << ";";
	}
	return ss.str();
}

string write_verilog_aggregate(string Module_name, int Cur_index, string Res_name, vector<int> List)
{
	stringstream ss;
	string Object_name, Kind;
	int Next_index;
	if (!List.empty())
	{
		if (HT.findfact("data_stmt(_,_," + to_string(List.front()) + ",_,_,_)"))
		{
			Object_name = returnpar(HT.findandreturn("data_stmt(_,_," + to_string(List.front()) + ",_,_,_)"), 2);
			if (HT.findfact("data_stmt(" + Module_name + "," + Res_name + ",_,_,\"par_inout\",_)"))
			{
				ss << "             ";
				ss << Res_name << "_regout[" << Cur_index << "] <= " << Object_name << ";" << endl;
			}
			else if (HT.findfact("data_stmt(" + Module_name + "," + Res_name + ",*)"))
			{
				Kind = stoi(returnpar(HT.findandreturn("data_stmt(" + Module_name + "," + Res_name + ",*)"), 5));
				if (Kind != "par_inout")
				{
					ss << "             ";
					ss << Res_name << "[" << Cur_index << "] <= " << Object_name << ";" << endl;
				}
			}
		}
		else if (HT.findfact("data_stmt(" + Module_name + ",_," + to_string(List.front()) + ",_,_,_)"))
		{
			Object_name = returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(List.front()) + ",_,_,_)"), 2);
			if (HT.findfact("data_stmt(" + Module_name + "," + Res_name + ",_,_,\"par_inout\",_)"))
			{
				ss << "             ";
				ss << Res_name << "_regout[" << Cur_index << "] <= " << Object_name << ";" << endl;
				Next_index = Cur_index + 1;
				List.erase(List.begin());
				ss << write_verilog_aggregate(Module_name, Next_index, Res_name, List);
			}
			else if (HT.findfact("data_stmt(" + Module_name + "," + Res_name + ",*)"))
			{
				Kind = stoi(returnpar(HT.findandreturn("data_stmt(" + Module_name + "," + Res_name + ",*)"), 5));
				if (Kind != "par_inout")
				{
					ss << "             ";
					ss << Res_name << "[" << Cur_index << "] <= " << Object_name << ";" << endl;
					Next_index = Cur_index + 1;
					List.erase(List.begin());
					ss << write_verilog_aggregate(Module_name, Next_index, Res_name, List);
				}
			}
		}
	}
	return ss.str();
}

string  write_verilog_array_index(string Module_name, int Right_op)
{
	stringstream ss;
	string Right_name;
	vector<int> Index_parameter_list;
	if (Right_op > 0)
	{
		if (HT.findfact("data_stmt(" + Module_name + ",_," + to_string(Right_op) + ",_,_,_)"))
		{
			Right_name = returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Right_op) + ",_,_,_)"), 2);
			ss << "[" << Right_name << "]";
		}
	}
	else if (Right_op < 0)
	{
		if (HT.findfact("compo_stmt(" + Module_name + "," + to_string(Right_op) + ",*)"))
		{
			Index_parameter_list = returnVec(makeInstanceOf(HT.findandreturn("compo_stmt(" + Module_name + "," + to_string(Right_op) + ",*)")), 1);
			ss << print_array_index_parameters(Module_name, Index_parameter_list);
		}
	}
	return ss.str();
}

void find_record_field_bounds(int Acc_lower_bound, int Field_num, int In_field_count, int In_field_type, int* Upper_bound, int* Lower_bound)
{
	int Field_size, Next_acc_lower_bound, Next_field_count, Next_field_type;
	if (Field_num > In_field_count)
	{
		if (HT.findfact("type_def(" + to_string(In_field_type) + ",*)"))
		{
			Field_size = stoi(returnpar(HT.findandreturn("type_def(" + to_string(In_field_type) + ",*)"), 3));
			Next_acc_lower_bound = Acc_lower_bound + Field_size;
			Next_field_count = In_field_count + 1;
			Next_field_type = In_field_type + 1;
			find_record_field_bounds(Next_acc_lower_bound, Field_num, Next_field_count, Next_field_type, Upper_bound, Lower_bound);
		}
	}
	else if (HT.findfact("type_def(" + to_string(In_field_type) + ",*)"))
	{
		Field_size = stoi(returnpar(HT.findandreturn("type_def(" + to_string(In_field_type) + ",*)"), 3));
		*Lower_bound = Acc_lower_bound;
		*Upper_bound = Acc_lower_bound + Field_size - 1;
	}
}


void translate_operator_symbol(string Op_string, string* C_op_string, string* CloseParenthesis, string* ExtraAss)
{
	if (Op_string == "not")
	{
		*C_op_string = "!";
		*CloseParenthesis = "";
		*ExtraAss = "=";
	}
	else if (Op_string == ":=")
	{
		*C_op_string = "=";
		*CloseParenthesis = "";
		*ExtraAss = "";
	}
	else if (Op_string == "abs")
	{
		*C_op_string = "abs(";
		*CloseParenthesis = ")";
		*ExtraAss = "=";
	}
	else
	{
		*C_op_string = Op_string;
		*CloseParenthesis = "";
		*ExtraAss = "=";
	}
}

string output_special_operation(string Module, int Operation, string HDL, string Tool)
{
	stringstream ss;
	int Left_op, Result, Rd_width, Sd_with, Normal_op, Normal_source, Left_type, Left_size, Number_of_dim, First_comp, Rd_up_limit, 
		Last_comp, Last_size, Last_low_bound, Sd_width, Sd_type, No_of_fields, Last_field_type, Type, Size, Rtype, Sd_up_limit,
		Total_fields, Next_shift_offset, S1d_width, Right_op, S2d_width, Noperation, Ndata_entry, Base, Result_type, First_field_type,
		Res_op, Res_type, Record_type, Rec_width, Rd_type, Num_of_elements;
	string Operator, Rd_name, Sd_name, Normal_source_name, Package, Sd_name_lower, Rkind, S1d_name, S2d_name, Ndata_name, NewS1d_name,
		Rd_name1, S1d_name1, Type_kind, RType_kind, Record_type_name, Left_name, Rd_kind;
	vector<int> In_par_list, Field_list, Total_shift_list;
	if (HT.findfact("special_op(" + Module + "," + to_string(Operation) + "," + to_string(Operation) + ",*)"))
	{
		Operator = returnpar(HT.findandreturn("special_op(" + Module + "," + to_string(Operation) + "," + to_string(Operation) + ",*)"), 3);
		Left_op = stoi(returnpar(HT.findandreturn("special_op(" + Module + "," + to_string(Operation) + "," + to_string(Operation) + ",*)"), 4));
		Right_op = stoi(returnpar(HT.findandreturn("special_op(" + Module + "," + to_string(Operation) + "," + to_string(Operation) + ",*)"), 5));
		Result = stoi(returnpar(HT.findandreturn("special_op(" + Module + "," + to_string(Operation) + "," + to_string(Operation) + ",*)"), 6));
		Normal_op = stoi(returnpar(HT.findandreturn("special_op(" + Module + "," + to_string(Operation) + "," + to_string(Operation) + ",*)"), 9));
		if (HDL == "vhdl")
		{
			if (!HT.findfact("source_is_normal_dt(" + Module + "," + to_string(Operation) + "," + to_string(Left_op) + ")"))
			{
				if (Operator == "<=")
				{
					if (get_data_name(Module, Result, &Rd_name, &Rd_width))
					{
						if (Rd_width > 1)
						{
							if (HT.findfact("data_stmt(" + Module + "," + Rd_name + ",*)"))
							{
								Rtype = stoi(returnpar(HT.findandreturn("data_stmt(" + Module + "," + Rd_name + ",*)"), 4));
								if (HT.findfact("type_def(" + to_string(Rtype) + ",_," + to_string(Rd_width) + ",_,_,\"record_t\",_,_,_)"))
								{
									Total_fields = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Rtype) + ",_," + to_string(Rd_width) + ",_,_,\"record_t\",_,_,_)"), 8));
									Rd_up_limit = Rd_width - 1;
									if (get_data_name(Module, Left_op, &Sd_name, 0))
									{
										Next_shift_offset = 0;
										ss << write_assignment_to_a_record(Module, Operator, Sd_name, Rd_name, Total_fields, 0, Next_shift_offset, HDL);
										ss << write_special_comment(HDL) << endl;
									}
								}
							}
						}
					}
				}
			}
			else if (Operator == "+")
			{
				if (get_data_name(Module, Result, &Rd_name, &Rd_width))
				{
					if (Rd_width > 1)
					{
						if (get_data_name(Module, Left_op, &S1d_name, &S1d_width))
						{
							if (Right_op != 0)
							{
								if (get_data_name(Module, Right_op, &S2d_name, &S2d_width))
								{
									if (HT.findfact("change_op_number(" + Module + ",_," + to_string(Operation) + ")"))
									{
										Noperation = stoi(returnpar(HT.findandreturn("change_op_number(" + Module + ",_," + to_string(Operation) + ")"), 2));
										if (HT.findfact("prog_stmt(" + Module + "," + to_string(Noperation) + ",_,107,_,_,_,_)"))
										{
											Ndata_entry = stoi(returnpar(HT.findandreturn("prog_stmt(" + Module + "," + to_string(Noperation) + ",_,107,_,_,_,_)"), 5));
											if (HT.findfact("data_stmt(" + Module + ",_," + to_string(Ndata_entry) + ",_,_,_)"))
											{
												Ndata_name = returnpar(HT.findandreturn("data_stmt(" + Module + ",_," + to_string(Ndata_entry) + ",_,_,_)"), 2);
												if (HT.findfact("mem_port(_,_," + Module + "," + Ndata_name + ",_,_,_,_,_,_,_,_,_)"))
												{
													Base = stoi(returnpar(HT.findandreturn("mem_port(_,_," + Module + "," + Ndata_name + ",_,_,_,_,_,_,_,_,_)"), 12));
													if (Base != 0)
													{
														if (Rd_width <= S1d_width)
														{
															ss << Rd_name;
															if (Rd_width > 1)
															{
																Rd_up_limit = Rd_width - 1;
																ss << print_object_bit_range(Rd_up_limit, 0, HDL);
																replace_chars_in_string(S1d_name, ".", "_", &NewS1d_name);
																ss << " <= " << NewS1d_name;
																ss << print_object_bit_range(Rd_up_limit, 0, HDL);
																ss << " " << Operator << " conv_std_logic_vector(CONV_INTEGER(" << S2d_name << "), " << Rd_width << ")";
																ss << "; ";
																ss << write_special_comment(HDL) << endl;
															}
														}
													}
													else if (Base == 0)
													{
														if (Rd_width <= S1d_width)
														{
															ss << Rd_name;
															if (Rd_width > 1)
															{
																Rd_up_limit = Rd_width - 1;
																ss << print_object_bit_range(Rd_up_limit, 0, HDL);
																ss << " <= conv_std_logic_vector(CONV_INTEGER(" << S2d_name;
																ss << print_object_bit_range(Rd_up_limit, 0, HDL);
																ss << "), " << Rd_width << ")";
																ss << "; ";
																ss << write_special_comment(HDL) << endl;
															}
														}
													}
												}
											}
										}
										if (HT.findfact("prog_stmt(" + Module + "," + to_string(Noperation) + ",_,108,_,_,_,_)"))
										{
											Ndata_entry = stoi(returnpar(HT.findandreturn("prog_stmt(" + Module + "," + to_string(Noperation) + ",_,108,_,_,_,_)"), 7));
											if (HT.findfact("data_stmt(" + Module + ",_," + to_string(Ndata_entry) + ",*)"))
											{
												Ndata_name = returnpar(HT.findandreturn("data_stmt(" + Module + ",_," + to_string(Ndata_entry) + ",_,_,_)"), 2);
												if (HT.findfact("mem_port(_,_," + Module + "," + Ndata_name + ",_,_,_,_,_,_,_,_,_)"))
												{
													Base = stoi(returnpar(HT.findandreturn("mem_port(_,_," + Module + "," + Ndata_name + ",_,_,_,_,_,_,_,_,_)"), 12));
													if (Base != 0)
													{
														if (Rd_width <= S1d_width)
														{
															replace_chars_in_string(Rd_name, ".", "_", &Rd_name1);
															ss << Rd_name1;
															if (Rd_width > 1)
															{
																Rd_up_limit = Rd_width - 1;
																ss << print_object_bit_range(Rd_up_limit, 0, HDL);
																replace_chars_in_string(S1d_name, ".", "_", &S1d_name1);
																ss << " <= " << S1d_name1;
																ss << print_object_bit_range(Rd_up_limit, 0, HDL);
																ss << " " << Operator << " conv_std_logic_vector(CONV_INTEGER(" << S2d_name << "), " << Rd_width << ")";
																ss << "; ";
																ss << write_special_comment(HDL) << endl;
															}
														}
													}
													else if (Base == 0)
													{
														if (Rd_width <= S1d_width)
														{
															ss << Rd_name;
															if (Rd_width > 1)
															{
																Rd_up_limit = Rd_width - 1;
																ss << print_object_bit_range(Rd_up_limit, 0, HDL);
																ss << " <= conv_std_logic_vector(CONV_INTEGER(" << S2d_name;
																ss << print_object_bit_range(Rd_up_limit, 0, HDL);
																ss << "), " << Rd_width << ")";
																ss << "; ";
																ss << write_special_comment(HDL) << endl;
															}
														}
													}
												}
											}
										}
										else if (HT.findfact("prog_stmt(" + Module + "," + to_string(Noperation) + ",_,102,_,_,_,_)"))
										{
											Ndata_entry = stoi(returnpar(HT.findandreturn("prog_stmt(" + Module + "," + to_string(Noperation) + ",_,102,_,_,_,_)"), 5));
											if (HT.findfact("data_stmt(" + Module + ",_," + to_string(Ndata_entry) + ",*)"))
											{
												Ndata_name = returnpar(HT.findandreturn("data_stmt(" + Module + ",_," + to_string(Ndata_entry) + ",_,_,_)"), 2);
												if (HT.findfact("mem_port(_,_," + Module + "," + Ndata_name + ",_,_,_,_,_,_,_,_,_)"))
												{
													Base = stoi(returnpar(HT.findandreturn("mem_port(_,_," + Module + "," + Ndata_name + ",_,_,_,_,_,_,_,_,_)"), 12));
													if (Base != 0)
													{
														if (Rd_width <= S1d_width)
														{
															ss << Rd_name;
															if (Rd_width > 1)
															{
																Rd_up_limit = Rd_width - 1;
																ss << print_object_bit_range(Rd_up_limit, 0, HDL);
																ss << " <= " << S1d_name;
																ss << print_object_bit_range(Rd_up_limit, 0, HDL);
																ss << " " << Operator << " conv_std_logic_vector(CONV_INTEGER(" << S2d_name << "), " << S2d_width << ")";
																ss << "; ";
																ss << write_special_comment(HDL) << endl;
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
			}
		}
		else if (HDL == "verilog")
		{
			if (!HT.findfact("source_is_normal_dt(" + Module + "," + to_string(Operation) + "," + to_string(Left_op) + ")"))
			{
				if (Operator == "<=")
				{
					if (get_data_name(Module, Result, &Rd_name, &Rd_width))
					{
						if (Rd_width > 1)
						{
							if (HT.findfact("data_stmt(" + Module + "," + Rd_name + ",*)"))
							{
								Rtype = stoi(returnpar(HT.findandreturn("data_stmt(" + Module + "," + Rd_name + ",*)"), 4));
								if (HT.findfact("type_def(" + to_string(Rtype) + ",_," + to_string(Rd_width) + ",_,_,\"record_t\",_,_,_)"))
								{
									Rd_up_limit = Rd_width - 1;
									if (get_data_name(Module, Left_op, &Sd_name, 0))
									{
										ss << Rd_name;
										ss << print_object_bit_range(Rd_up_limit, 0, HDL);
										ss << " <= " << Sd_name;
										ss << print_object_bit_range(Rd_up_limit, 0, HDL);
										ss << ";";
										ss << write_special_comment(HDL) << endl;
									}
								}
							}
						}
					}
				}
			}
			else if (Operator == "+")
			{
				if (get_data_name(Module, Result, &Rd_name, &Rd_width))
				{
					if (Rd_width > 1)
					{
						if (get_data_name(Module, Left_op, &S1d_name, &S1d_width))
						{
							if (Right_op != 0)
							{
								if (get_data_name(Module, Right_op, &S2d_name, &S2d_width))
								{
									if (HT.findfact("change_op_number(" + Module + ",_," + to_string(Operation) + ")"))
									{
										Noperation = stoi(returnpar(HT.findandreturn("change_op_number(" + Module + ",_," + to_string(Operation) + ")"), 2));
										if (HT.findfact("prog_stmt(" + Module + "," + to_string(Noperation) + ",_,107,_,_,_,_)"))
										{
											Ndata_entry = stoi(returnpar(HT.findandreturn("prog_stmt(" + Module + "," + to_string(Noperation) + ",_,107,_,_,_,_)"), 5));
											if (HT.findfact("data_stmt(" + Module + ",_," + to_string(Ndata_entry) + ",_,_,_)"))
											{
												Ndata_name = returnpar(HT.findandreturn("data_stmt(" + Module + ",_," + to_string(Ndata_entry) + ",_,_,_)"), 2);
												if (HT.findfact("mem_port(_,_," + Module + "," + Ndata_name + ",_,_,_,_,_,_,_,_,_)"))
												{
													Base = stoi(returnpar(HT.findandreturn("mem_port(_,_," + Module + "," + Ndata_name + ",_,_,_,_,_,_,_,_,_)"), 12));
													if (Base != 0)
													{
														if (Rd_width <= S1d_width)
														{
															ss << Rd_name;
															if (Rd_width > 1)
															{
																Rd_up_limit = Rd_width - 1;
																ss << print_object_bit_range(Rd_up_limit, 0, HDL);
																ss << " <= " << S1d_name;
																ss << print_object_bit_range(Rd_up_limit, 0, HDL);
																ss << " " << Operator << " " << S2d_name;
																ss << "; ";
																ss << write_special_comment(HDL) << endl;
															}
														}
													}
													if (Base == 0)
													{
														if (Rd_width <= S1d_width)
														{
															ss << Rd_name;
															if (Rd_width > 1)
															{
																Rd_up_limit = Rd_width - 1;
																ss << print_object_bit_range(Rd_up_limit, 0, HDL);
																ss << " <= " << S2d_name;
																ss << print_object_bit_range(Rd_up_limit, 0, HDL);
																ss << "; ";
																ss << write_special_comment(HDL) << endl;
															}
														}
													}
												}
											}
										}
										if (HT.findfact("prog_stmt(" + Module + "," + to_string(Noperation) + ",_,108,_,_,_,_)"))
										{
											Ndata_entry = stoi(returnpar(HT.findandreturn("prog_stmt(" + Module + "," + to_string(Noperation) + ",_,108,_,_,_,_)"), 7));
											if (HT.findfact("data_stmt(" + Module + ",_," + to_string(Ndata_entry) + ",*)"))
											{
												Ndata_name = returnpar(HT.findandreturn("data_stmt(" + Module + ",_," + to_string(Ndata_entry) + ",_,_,_)"), 2);
												if (HT.findfact("mem_port(_,_," + Module + "," + Ndata_name + ",_,_,_,_,_,_,_,_,_)"))
												{
													Base = stoi(returnpar(HT.findandreturn("mem_port(_,_," + Module + "," + Ndata_name + ",_,_,_,_,_,_,_,_,_)"), 12));
													if (Base != 0)
													{
														if (Rd_width <= S1d_width)
														{
															if (Base != 0)
															{
																if (Rd_width <= S1d_width)
																{
																	ss << Rd_name;
																	if (Rd_width > 1)
																	{
																		Rd_up_limit = Rd_width - 1;
																		ss << print_object_bit_range(Rd_up_limit, 0, HDL);
																		ss << " <= " << S1d_name;
																		ss << print_object_bit_range(Rd_up_limit, 0, HDL);
																		ss << " " << Operator << " " << S2d_name;
																		ss << "; ";
																		ss << write_special_comment(HDL) << endl;
																	}
																}
															}
															else if (Base == 0)
															{
																if (Rd_width <= S1d_width)
																{
																	ss << Rd_name;
																	if (Rd_width > 1)
																	{
																		Rd_up_limit = Rd_width - 1;
																		ss << print_object_bit_range(Rd_up_limit, 0, HDL);
																		ss << " <= " << S2d_name;
																		ss << print_object_bit_range(Rd_up_limit, 0, HDL);
																		ss << "; ";
																		ss << write_special_comment(HDL) << endl;
																	}
																}
															}
														}
													}
												}
											}
										}
										else if (HT.findfact("prog_stmt(" + Module + "," + to_string(Noperation) + ",_,102,_,_,_,_)"))
										{
											Ndata_entry = stoi(returnpar(HT.findandreturn("prog_stmt(" + Module + "," + to_string(Noperation) + ",_,102,_,_,_,_)"), 5));
											if (HT.findfact("data_stmt(" + Module + ",_," + to_string(Ndata_entry) + ",*)"))
											{
												Ndata_name = returnpar(HT.findandreturn("data_stmt(" + Module + ",_," + to_string(Ndata_entry) + ",_,_,_)"), 2);
												if (HT.findfact("mem_port(_,_," + Module + "," + Ndata_name + ",_,_,_,_,_,_,_,_,_)"))
												{
													Base = stoi(returnpar(HT.findandreturn("mem_port(_,_," + Module + "," + Ndata_name + ",_,_,_,_,_,_,_,_,_)"), 12));
													if (Base != 0)
													{
														if (Rd_width <= S1d_width)
														{
															ss << Rd_name;
															if (Rd_width > 1)
															{
																Rd_up_limit = Rd_width - 1;
																ss << print_object_bit_range(Rd_up_limit, 0, HDL);
																ss << " <= " << S1d_name;
																ss << print_object_bit_range(Rd_up_limit, 0, HDL);
																ss << " " << Operator << " " << S2d_name;
																ss << "; ";
																ss << write_special_comment(HDL) << endl;
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
			}
		}
		else if (HDL == "c")
		{
			if (Operator == "<=")
			{
				if (Result != Left_op)
				{
					if (get_data_name(Module, Result, &Rd_name, &Rd_width))
					{
						if (Result < 0)
						{
							if (get_data_name(Module, Left_op, &Sd_name, &Sd_width))
							{
								if (Left_op < 0)
								{
									if (Rd_width == Sd_width)
									{
										ss << Rd_name << " = " << Sd_name << "; ";
										ss << write_special_comment(HDL) << endl;
										ss << "         printf(" << '"' << Rd_name << " = " << Sd_name << " = %d" << '\\' << "n" << '"' << ", " << Rd_name << "); " << endl;
									}
								}
								else if (Left_op > 0)
								{
									if (HT.findfact("data_stmt(" + Module + "," + Sd_name + "," + to_string(Left_op) + ",*)"))
									{
										Left_type = stoi(returnpar(HT.findandreturn("data_stmt(" + Module + "," + Sd_name + "," + to_string(Left_op) + ",*)"), 4));
										if (HT.findfact("type_def(" + to_string(Left_type) + ",_," + to_string(Sd_width) + ",_,_,_,_,_,_)"))
										{
											Type_kind = returnpar(HT.findandreturn("type_def(" + to_string(Left_type) + ",_," + to_string(Sd_width) + ",_,_,_,_,_,_)"), 6);
											if (Type_kind != "record_t" && Type_kind != "vectorarray_t")
											{
												if (Rd_width == Sd_width)
												{
													ss << Rd_name << " = " << Sd_name << "; ";
													ss << write_special_comment(HDL) << endl;
													ss << "         printf(" << '"' << Rd_name << " = " << Sd_name << " = %d" << '\\' << "n" << '"' << ", " << Rd_name << "); " << endl;
												}
											}
										}
									}
								}
							}
						}
						else if (HT.findfact("data_stmt(" + Module + "," + Rd_name + "," + to_string(Result) + ",*)"))
						{
							Type = stoi(returnpar(HT.findandreturn("data_stmt(" + Module + "," + Rd_name + "," + to_string(Result) + ",*)"), 4));
							if (HT.findfact("type_def(" + to_string(Type) + ",_," + to_string(Rd_width) + ",_,_,\"single_t\",_,_,_)"))
							{
								if (get_data_name(Module, Left_op, &Sd_name, &Sd_width))
								{
									if (Left_op < 0)
									{
										if (Rd_width == Sd_width)
										{
											ss << Rd_name << " = " << Sd_name << "; ";
											ss << write_special_comment(HDL) << endl;
											ss << "         printf(" << '"' << Rd_name << " = " << Sd_name << " = %d" << '\\' << "n" << '"' << ", " << Rd_name << "); " << endl;
										}
									}
								}
							}
						}
					}
				}
				else if (get_data_name(Module, Result, &Rd_name, &Rd_width))
				{
					if (Left_op == Result)
					{
						if (Left_op < 0)
						{
							if (HT.findfact("prog_stmt(" + Module + "," + to_string(Normal_op) + ",_,108," + to_string(Left_op) + ",_,_,_)"))
							{
								Res_op = stoi(returnpar(HT.findandreturn("prog_stmt(" + Module + "," + to_string(Normal_op) + ",_,108," + to_string(Left_op) + ",_,_,_)"), 7));
								if (HT.findfact("data_stmt(" + Module + ",_," + to_string(Res_op) + ",_,_,_)"))
								{
									Res_type = stoi(returnpar(HT.findandreturn("data_stmt(" + Module + ",_," + to_string(Res_op) + ",_,_,_)"), 4));
									if (HT.findfact("type_def(" + to_string(Res_type) + ",_,_,_,_,\"vectorarray_t\",_,_,_)"))
									{
										Record_type = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Res_type) + ",_,_,_,_,\"vectorarray_t\",_,_,_)"), 9));
										if (HT.findfact("type_def(" + to_string(Record_type) + ",_,_,_,_,\"record_t\",_,_,_)"))
										{
											Rec_width = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Record_type) + ",_,_,_,_,\"record_t\",_,_,_)"), 3));
											if (Rec_width == Rd_width)
											{
												ss << Rd_name << " = ";
												ss << write_long_int_conditionally(Rd_width);
												if (HT.findfact("rec_stmt(" + Module + "," + to_string(Left_op) + ",*)"))
												{
													Field_list = returnVec(makeInstanceOf(HT.findandreturn("rec_stmt(" + Module + "," + to_string(Left_op) + ",*)")), 1);
													vector<int> emptv;
													total_number_of_aggregate_fields(Module, Field_list, 0, 1, &Total_fields, 0, emptv, &Total_shift_list);
													ss << type_aggregate_record_shifts(Module, Field_list, Total_fields, Total_shift_list);
													ss << ";";
													ss << write_special_comment(HDL) << endl;
													ss << "         printf(" << '"' << Rd_name << " = ";
													ss << write_long_int_conditionally(Rd_width);
													ss << type_aggregate_record_shifts(Module, Field_list, Total_fields, Total_shift_list);
													ss << " = %d" << '\\' << "n" << '"' << ", " << Rd_name << "); " << endl;
												}
											}
										}
									}
								}
							}
						}
					}
					else if (HT.findfact("data_stmt(" + Module + "," + Rd_name + "," + to_string(Result) + ",*)"))
					{
						Result_type = stoi(returnpar(HT.findandreturn("data_stmt(" + Module + "," + Rd_name + "," + to_string(Result) + ",*)"), 4));
						if (HT.findfact("type_def(" + to_string(Result_type) + ",*)"))
						{
							RType_kind = returnpar(HT.findandreturn("type_def(" + to_string(Result_type) + ",*)"), 6);
							if (RType_kind != "record_t")
							{
								if (RType_kind != "vectorarray_t")
								{
									if (get_data_name(Module, Left_op, &Sd_name, &Sd_width))
									{
										if (Left_op > 0)
										{
											if (HT.findfact("data_stmt(" + Module + "," + Sd_name + "," + to_string(Left_op) + ",*)"))
											{
												Left_type = stoi(returnpar(HT.findandreturn("data_stmt(" + Module + "," + Sd_name + "," + to_string(Left_op) + ",*)"), 4));
												if (HT.findfact("type_def(" + to_string(Left_type) + ",_," + to_string(Sd_width) + ",_,_,_,_,_,_)"))
												{
													Type_kind = returnpar(HT.findandreturn("type_def(" + to_string(Left_type) + ",_," + to_string(Sd_width) + ",_,_,_,_,_,_)"), 6);
													if (Type_kind != "record_t" && Type_kind != "vectorarray_t")
													{
														if (Rd_width == Sd_width)
														{
															ss << Rd_name << " = " << Sd_name << "; ";
															ss << write_special_comment(HDL) << endl;
															ss << "         printf(" << '"' << Rd_name << " = " << Sd_name << " = %d" << '\\' << "n" << '"' << ", " << Rd_name << "); " << endl;
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
					else if (get_data_name(Module, Left_op, &Sd_name, &Sd_width))
					{
						if (Rd_width == Sd_width)
						{
							if (HT.findfact("data_stmt(" + Module + "," + Sd_name + "," + to_string(Left_op) + ",*)"))
							{
								Left_type = stoi(returnpar(HT.findandreturn("data_stmt(" + Module + "," + Sd_name + "," + to_string(Left_op) + ",*)"), 4));
								if (HT.findfact("type_def(" + to_string(Left_type) + ",_," + to_string(Sd_width) + ",_,_,\"record_t\",_,_,_)"))
								{
									No_of_fields = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Left_type) + ",_," + to_string(Sd_width) + ",_,_,\"record_t\",_,_,_)"), 8));
									First_field_type = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Left_type) + ",_," + to_string(Sd_width) + ",_,_,\"record_t\",_,_,_)"), 9));
									if (Rd_width == Sd_width)
									{
										if (Sd_width > 32)
										{
											ss << Rd_name << " = ";
											ss << " (long long int) ";
											ss << write_record_assignment_to_variable(Module, Sd_name, Left_op, Left_type, No_of_fields, First_field_type);
											ss << "; ";
											ss << write_special_comment(HDL) << endl;
											ss << "         printf(" << '"' << Rd_name << " = (long long int) ";
											ss << write_record_assignment_to_variable(Module, Sd_name, Left_op, Left_type, No_of_fields, First_field_type);
											ss << " = %d" << '\\' << "n" << '"' << ", " << Rd_name << "); " << endl;
										}
									}
								}
							}
						}
						else if (Rd_width != Sd_width)
						{
							if (Left_op < 0)
							{
								if (HT.findfact("prog_stmt(" + Module + "," + to_string(Normal_op) + ",_,108," + to_string(Left_op) + ",_,_,_)"))
								{
									Res_op = stoi(returnpar(HT.findandreturn("prog_stmt(" + Module + "," + to_string(Normal_op) + ",_,108," + to_string(Left_op) + ",_,_,_)"), 7));
									if (HT.findfact("data_stmt(" + Module + ",_," + to_string(Res_op) + ",_,_,_)"))
									{
										Res_type = stoi(returnpar(HT.findandreturn("data_stmt(" + Module + ",_," + to_string(Res_op) + ",_,_,_)"), 4));
										if (HT.findfact("type_def(" + to_string(Res_type) + ",_,_,_,_,\"vectorarray_t\",_,_,_)"))
										{
											Record_type = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Res_type) + ",_,_,_,_,\"vectorarray_t\",_,_,_)"), 9));
											if (HT.findfact("type_def(" + to_string(Record_type) + ",_,_,_,_,\"record_t\",_,_,_)"))
											{
												Rec_width = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Record_type) + ",_,_,_,_,\"record_t\",_,_,_)"), 3));
												if (Rec_width == Rd_width)
												{
													ss << Rd_name << " = ";
													ss << write_long_int_conditionally(Rd_width);
													if (HT.findfact("rec_stmt(" + Module + "," + to_string(Left_op) + ",*)"))
													{
														Field_list = returnVec(makeInstanceOf(HT.findandreturn("rec_stmt(" + Module + "," + to_string(Left_op) + ",*)")), 1);
														vector<int> emptv;
														total_number_of_aggregate_fields(Module, Field_list, 0, 1, &Total_fields, 0, emptv, &Total_shift_list);
														ss << type_aggregate_record_shifts(Module, Field_list, Total_fields, Total_shift_list);
														ss << ";";
														ss << write_special_comment(HDL) << endl;
														ss << "         printf(" << '"' << Rd_name << " = ";
														ss << write_long_int_conditionally(Rd_width);
														ss << type_aggregate_record_shifts(Module, Field_list, Total_fields, Total_shift_list);
														ss << " = %d" << '\\' << "n" << '"' << ", " << Rd_name << "); " << endl;
													}
												}
											}
										}
									}
								}
							}
						}
					}
					else if (!get_data_name(Module, Left_op, 0, 0))
					{
						if (Left_op < 0)
						{
							if (HT.findfact("prog_stmt(" + Module + "," + to_string(Normal_op) + ",_,108," + to_string(Left_op) + ",_,_,_)"))
							{
								Res_op = stoi(returnpar(HT.findandreturn("prog_stmt(" + Module + "," + to_string(Normal_op) + ",_,108," + to_string(Left_op) + ",_,_,_)"), 7));
								if (HT.findfact("data_stmt(" + Module + ",_," + to_string(Res_op) + ",_,_,_)"))
								{
									Res_type = stoi(returnpar(HT.findandreturn("data_stmt(" + Module + ",_," + to_string(Res_op) + ",_,_,_)"), 4));
									if (HT.findfact("type_def(" + to_string(Res_type) + ",_,_,_,_,\"vectorarray_t\",_,_,_)"))
									{
										Record_type = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Res_type) + ",_,_,_,_,\"vectorarray_t\",_,_,_)"), 9));
										if (HT.findfact("type_def(" + to_string(Record_type) + ",_,_,_,_,\"record_t\",_,_,_)"))
										{
											Rec_width = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Record_type) + ",_,_,_,_,\"record_t\",_,_,_)"), 3));
											if (Rec_width == Rd_width)
											{
												ss << Rd_name << " = ";
												ss << write_long_int_conditionally(Rd_width);
												if (HT.findfact("rec_stmt(" + Module + "," + to_string(Left_op) + ",*)"))
												{
													Field_list = returnVec(makeInstanceOf(HT.findandreturn("rec_stmt(" + Module + "," + to_string(Left_op) + ",*)")), 1);
													vector<int> emptv;
													total_number_of_aggregate_fields(Module, Field_list, 0, 1, &Total_fields, 0, emptv, &Total_shift_list);
													ss << type_aggregate_record_shifts(Module, Field_list, Total_fields, Total_shift_list);
													ss << ";";
													ss << write_special_comment(HDL) << endl;
													ss << "         printf(" << '"' << Rd_name << " = ";
													ss << write_long_int_conditionally(Rd_width);
													ss << type_aggregate_record_shifts(Module, Field_list, Total_fields, Total_shift_list);
													ss << " = %d" << '\\' << "n" << '"' << ", " << Rd_name << "); " << endl;
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
			else if (HT.findfact("source_is_normal_dt(" + Module + "," + to_string(Operation) + "," + to_string(Left_op) + ")"))
			{
				if (Operator == "<=")
				{
					if (Left_op < 0)
					{
						if (get_data_name(Module, Result, &Rd_name, 0))
						{
							if (HT.findfact("data_stmt("+Module+","+Rd_name+","+to_string(Result)+",_,_,_)"))
							{
								Res_type = stoi(returnpar(HT.findandreturn("data_stmt(" + Module + "," + Rd_name + "," + to_string(Result) + ",_,_,_)"), 4));
								if (HT.findfact("type_def("+to_string(Res_type)+",_,_,_,_,\"record_t\",_,_,_)"))
								{
									Record_type_name = returnpar(HT.findandreturn("type_def(" + to_string(Res_type) + ",_,_,_,_,\"record_t\",_,_,_)"), 2);
									ss << Record_type_name << " " << Rd_name << " = {";
									if (HT.findfact("rec_stmt(" + Module + "," + to_string(Left_op) + ",*)"))
									{
										In_par_list = returnVec(makeInstanceOf(HT.findandreturn("rec_stmt(" + Module + "," + to_string(Left_op) + ",*)")), 1);
										ss << write_param_list(Module, In_par_list);
										ss << "};";
										ss << write_special_comment(HDL) << endl;
									}
								}
							}
						}
					}
					else if (Left_op > 0)
					{
						if (HT.findfact("data_stmt(" + Module + ",_,"+to_string(Left_op)+",_,_,_)"))
						{
							Left_name = returnpar(HT.findandreturn("data_stmt(" + Module + ",_," + to_string(Left_op) + ",_,_,_)"), 2);
							Left_type = stoi(returnpar(HT.findandreturn("data_stmt(" + Module + ",_," + to_string(Left_op) + ",_,_,_)"), 4));
							if (HT.findfact("type_def(" + to_string(Left_type) + ",_,_,_,_,\"record_t\",_,_,_)"))
							{
								if (get_data_name(Module, Result, &Rd_name, 0))
								{
									if (get_data_name(Module, Left_op, &Sd_name, 0))
									{
										ss << Rd_name;
										ss << " = " << Sd_name;
										ss << ";";
										ss << write_special_comment(HDL) << endl;
										ss << "         printf(" << '"' << Rd_name << " = " << Sd_name << " = %d" << '\\' << "n" << '"' << ", " << Rd_name << "); " << endl;
									}
									else
									{
										ss << Rd_name << " = " << Left_name << ";";
										ss << write_special_comment(HDL) << endl;
										ss << "         printf(" << '"' << Rd_name << " = " << Left_name << " = %d" << '\\' << "n" << '"' << ", " << Rd_name << "); " << endl;
									}
								}
							}
						}
					}
				}
			}
			else if (!HT.findfact("source_is_normal_dt(" + Module + "," + to_string(Operation) + "," + to_string(Left_op) + ")"))
			{
				if (Operator == "<=")
				{
					if (get_data_name(Module, Result, &Rd_name, &Rd_width))
					{
						if (HT.findfact("data_stmt(" + Module + "," + Rd_name + "," + to_string(Result) + ",*)"))
						{
							Rd_type = stoi(returnpar(HT.findandreturn("data_stmt(" + Module + "," + Rd_name + "," + to_string(Result) + ",*)"), 4));
							if (HT.findfact("type_def(" + to_string(Rd_type) + ",*)"))
							{
								Rd_kind = returnpar(HT.findandreturn("type_def(" + to_string(Rd_type) + ",*)"), 6);
								Num_of_elements = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Rd_type) + ",*)"), 8));
								if (Rd_kind != "record_t")
								{
									if (get_data_name(Module, Left_op, &Sd_name, 0))
									{
										ss << Rd_name;
										ss << " = " << Sd_name;
										ss << ";";
										ss << write_special_comment(HDL) << endl;
										ss << "         printf(" << '"' << Rd_name << " = " << Sd_name << " = %d" << '\\' << "n" << '"' << ", " << Rd_name << "); " << endl;
									}
								}
								else if (Rd_kind == "record_t")
								{
									if (get_data_name(Module, Left_op, &Sd_name, 0))
									{
										ss << write_special_comment(HDL) << endl;
										Next_shift_offset = 0;
										ss << write_assignment_to_a_record(Module, Operator, Sd_name, Rd_name, Num_of_elements, 0, Next_shift_offset, HDL);
										ss << "         printf(" << '"' << Rd_name << " = " << Sd_name << " = %d" << '\\' << "n" << '"' << ", " << Rd_name << "); " << endl;
									}
								}
							}
						}
						else if (get_data_name(Module, Left_op, &Sd_name, 0))
						{
							if (HT.findfact("data_stmt(" + Module + "," + Sd_name + "," + to_string(Left_op) + ",*)"))
							{
								Sd_type = stoi(returnpar(HT.findandreturn("data_stmt(" + Module + "," + Sd_name + "," + to_string(Left_op) + ",*)"), 4));
								if (HT.findfact("type_def(" + to_string(Sd_type) + ",_," + to_string(Rd_width) + ",_,_,\"record_t\",_,_,_)"))
								{
									ss << Rd_name;
									ss << " = " << Sd_name;
									ss << ";";
									ss << write_special_comment(HDL) << endl;
									ss << "         printf(" << '"' << Rd_name << " = " << Sd_name << " = %d" << '\\' << "n" << '"' << " << " << Rd_name << "); " << endl;
								}
							}
						}
					}
				}
			}
			else if (Operator != "<=")
			{
				if (Operator != "**")
				{
					if (get_data_name(Module, Result, &Rd_name, &Rd_width))
					{
						if (Rd_width > 1)
						{
							if (get_data_name(Module, Left_op, &S1d_name, 0))
							{
								if (Right_op != 0)
								{
									if (get_data_name(Module, Right_op, &S2d_name, 0))
									{
										ss << Rd_name << " = " << S1d_name << " " << Operator << " " << S2d_name << ";";
										ss << write_special_comment(HDL) << endl;
										ss << "         printf(" << '"' << Rd_name << " = " << S1d_name << " " << Operator << " " << S2d_name << " = %d" << '\\' << "n" << '"' << ", " << Rd_name << "); " << endl;
									}
								}
							}
						}
					}
				}
			}
			else if (Operator == "**")
			{
				if (get_data_name(Module, Result, &Rd_name, &Rd_width))
				{
					if (Rd_width > 1)
					{
						if (get_data_name(Module, Left_op, &S1d_name, 0))
						{
							if (Right_op != 0)
							{
								if (get_data_name(Module, Right_op, &S2d_name, 0))
								{
									ss << Rd_name << " = pow(" << S1d_name << ", " << S2d_name << ");";
									ss << write_special_comment(HDL) << endl;
									ss << "         printf(" << '"' << Rd_name << " = pow(" << S1d_name << " , " << S2d_name << ") = %d" << '\\' << "n" << '"' << ", " << Rd_name << "); " << endl;
								}
							}
						}
					}
				}
			}
		}
		else if (HDL != "c")
		{
			if (HT.findfact("source_is_normal_dt(" + Module + "," + to_string(Operation) + "," + to_string(Left_op) + ")"))
			{
				if (Operator == "<=")
				{
					if (Left_op > 0)
					{
						if (HT.findfact("data_stmt(" + Module + ",_," + to_string(Left_op) + ",_,_,_)"))
						{
							Left_type = stoi(returnpar(HT.findandreturn("data_stmt(" + Module + ",_," + to_string(Left_op) + ",_,_,_)"), 4));
							if (HT.findfact("type_def(" + to_string(Left_type) + ",_,_,_,_,\"record_t\",_,_,_)"))
							{
								Left_size = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Left_type) + ",_,_,_,_,\"record_t\",_,_,_)"), 3));
								Number_of_dim = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Left_type) + ",_,_,_,_,\"record_t\",_,_,_)"), 8));
								First_comp = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Left_type) + ",_,_,_,_,\"record_t\",_,_,_)"), 9));
								if (get_data_name(Module, Result, &Rd_name, &Rd_width))
								{
									if (Rd_width > 1)
									{
										Rd_up_limit = Rd_width - 1;
										if (get_data_name(Module, Left_op, &Sd_name, 0))
										{
											ss << Rd_name;
											ss << print_object_bit_range(Rd_up_limit, 0, HDL);
											ss << " <= ";
											Last_comp = Number_of_dim + First_comp - 1;
											ss << print_first_concat_symbol(HDL);
											if (HT.findfact("type_def(" + to_string(Last_comp) + ",*)"))
											{
												Last_size = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Last_comp) + ",*)"), 3));
												Last_low_bound = Left_size - Last_size;
												ss << print_record_object_components(Module, Sd_name, Last_comp, First_comp, Last_low_bound);
												ss << print_last_concat_symbol(HDL);
												ss << " ; ";
												ss << write_special_comment(HDL) << endl;
											}
										}
									}
								}
							}
							else if (HT.findfact("type_def(" + to_string(Left_type) + ",_,_,_,_,\"single_t\",_,_,_)"))
							{
								get_data_name(Module, Result, &Rd_name, &Rd_width);
								if (Rd_width > 1)
								{
									Rd_up_limit = Rd_width - 1;
									get_data_name(Module, Left_op, &Sd_name, 0);
									ss << Rd_name;
									ss << print_object_bit_range(Rd_up_limit, 0, HDL);
									ss << " <= " << Sd_name;
									ss << print_object_bit_range(Rd_up_limit, 0, HDL);
									ss << ";";
									ss << write_special_comment(HDL) << endl;
								}
							}
						}
					}
				}
			}
			else if (!HT.findfact("source_is_normal_dt(" + Module + "," + to_string(Operation) + "," + to_string(Left_op) + ")"))
			{
				if (Operator == "<=")
				{
					if (get_data_name(Module, Result, &Rd_name, &Rd_width))
					{
						if (Rd_width > 1)
						{
							Rd_up_limit = Rd_width - 1;
							if (get_data_name(Module, Left_op, &Sd_name, &Sd_width))
							{
								if (!HT.findfact("data_stmt(" + Module + "," + Rd_name + ",*)"))
								{
									if (Sd_width == 1)
									{
										if (HT.findfact("package_name(*)"))
										{
											Package = returnpar(HT.findandreturn("package_name(*)"), 1);
											upper_lower(Sd_name, &Sd_name_lower);
											if (!HT.findfact("data_stmt(" + Package + "," + Sd_name_lower + ",_,_,\"const\",_)"))
											{
												ss << Rd_name;
												ss << "(0) <= " << Sd_name;
												ss << ";";
												ss << write_special_comment(HDL) << endl;
											}
										}
									}
									else if (Sd_width = Rd_width)
									{
										if (HT.findfact("package_name(*)"))
										{
											Package = returnpar(HT.findandreturn("package_name(*)"), 1);
											upper_lower(Sd_name, &Sd_name_lower);
											if (!HT.findfact("data_stmt(" + Package + "," + Sd_name_lower + ",_,_,\"const\",_)"))
											{
												ss << Rd_name;
												ss << print_object_bit_range(Rd_up_limit, 0, HDL);
												ss << " <= " << Sd_name;
												ss << print_object_bit_range(Rd_up_limit, 0, HDL);
												ss << ";";
												ss << write_special_comment(HDL) << endl;
											}
										}
									}
								}
								else if (HT.findfact("data_stmt(" + Module + "," + Rd_name + ",*)"))
								{
									Rtype = stoi(returnpar(HT.findandreturn("data_stmt(" + Module + "," + Rd_name + ",*)"), 4));
									if (HT.findfact("type_def(" + to_string(Rtype) + ",*)"))
									{
										Rkind = returnpar(HT.findandreturn("type_def(" + to_string(Rtype) + ",*)"), 6);
										if (Rkind != "record_t")
										{
											if (Sd_width >= Rd_width)
											{
												ss << Rd_name;
												ss << print_object_bit_range(Rd_up_limit, 0, HDL);
												ss << " <= " << Sd_name;
												ss << print_object_bit_range(Rd_up_limit, 0, HDL);
												ss << ";";
												ss << write_special_comment(HDL) << endl;
											}
											else if (Sd_width < Rd_width)
											{
												Sd_up_limit = Sd_width - 1;
												ss << Rd_name;
												ss << print_object_bit_range(Sd_up_limit, 0, HDL);
												ss << " <= " << Sd_name;
												ss << print_object_bit_range(Sd_up_limit, 0, HDL);
												ss << ";";
												ss << write_special_comment(HDL) << endl;
											}
										}
									}
								}
								else if (HT.findfact("package_name(*)"))
								{
									Package = returnpar(HT.findandreturn("package_name(*)"), 1);
									upper_lower(Sd_name, &Sd_name_lower);
									if (HT.findfact("data_stmt(" + Package + "," + Sd_name_lower + ",_,_,\"const\",_)"))
									{
										Type = stoi(returnpar(HT.findandreturn("data_stmt(" + Package + "," + Sd_name_lower + ",_,_,\"const\",_)"), 4));
										if (parent_type_is_integer(Type, &Size))
										{
											ss << Rd_name;
											ss << print_object_bit_range(Rd_up_limit, 0, HDL);
											ss << " <= conv_std_logic_vector(" << Sd_name << "," << Rd_width << ")";
											ss << ";";
											ss << write_special_comment(HDL) << endl;
										}
									}
								}
								else if (Sd_width > 1)
								{
									if (Sd_width == Rd_width)
									{
										if (HT.findfact("data_stmt(" + Module + "," + Sd_name + "," + to_string(Left_op) + ",*)"))
										{
											Sd_type = stoi(returnpar(HT.findandreturn("data_stmt(" + Module + "," + Sd_name + "," + to_string(Left_op) + ",*)"), 4));
											if (HT.findfact("type_def(" + to_string(Sd_type) + ",_," + to_string(Rd_width) + ",_,_,\"record_t\",_,_,_)"))
											{
												No_of_fields = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Sd_type) + ",_," + to_string(Rd_width) + ",_,_,\"record_t\",_,_,_)"), 8));
												ss << Rd_name;
												ss << print_object_bit_range(Rd_up_limit, 0, HDL);
												ss << " <= ";
												Last_field_type = Sd_type + No_of_fields;
												ss << print_record_fields_concatenation(Sd_name, Sd_type, Last_field_type, HDL);
												ss << ";";
												ss << write_special_comment(HDL) << endl;
											}
										}
									}
								}
								else if (Sd_width == 1)
								{
									if (Sd_width < Rd_width)
									{
										if (HT.findfact("data_stmt(" + Module + "," + Sd_name + "," + to_string(Left_op) + ",*)"))
										{
											Sd_type = stoi(returnpar(HT.findandreturn("data_stmt(" + Module + "," + Sd_name + "," + to_string(Left_op) + ",*)"), 4));
											if (HT.findfact("type_def(" + to_string(Sd_type) + ",_," + to_string(Rd_width) + ",_,_,\"record_t\",_,_,_)"))
											{
												No_of_fields = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Sd_type) + ",_," + to_string(Rd_width) + ",_,_,\"record_t\",_,_,_)"), 8));
												ss << Rd_name;
												ss << print_object_bit_range(Rd_up_limit, 0, HDL);
												ss << " <= ";
												Last_field_type = Sd_type + No_of_fields;
												ss << print_record_fields_concatenation(Sd_name, Sd_type, Last_field_type, HDL);
												ss << ";";
												ss << write_special_comment(HDL) << endl;
											}
										}
									}
								}
							}
						}
					}
				}
			}
			else if (Operator == "<=")
			{
				if (get_data_name(Module, Result, &Rd_name, &Rd_width))
				{
					if (Rd_width == 1)
					{
						if (get_data_name(Module, Left_op, &Sd_name, &Sd_with))
						{
							if (Sd_with == 1)
							{
								ss << Rd_name << " <= " << Sd_name << "; ";
								ss << write_special_comment(HDL) << endl;
							}
							else if (Sd_with > 1)
							{
								if (HT.findfact("prog_stmt(" + Module + "," + to_string(Normal_op) + ",*)"))
								{
									Normal_source = stoi(returnpar(HT.findandreturn("prog_stmt(" + Module + "," + to_string(Normal_op) + ",*)"), 5));
									if (HT.findfact("data_stmt(" + Module + ",_," + to_string(Normal_source) + ",_,_,_)"))
									{
										Normal_source_name = returnpar(HT.findandreturn("data_stmt(" + Module + ",_," + to_string(Normal_source) + ",_,_,_)"), 2);
										if (HT.findfact("mem_port(_,_," + Module + "," + Normal_source_name + ",_," + to_string(Sd_with) + ",_,_,_,_,_,_,_)"))
										{
											ss << Rd_name << " <= " << Sd_name << "(0); ";
											ss << write_special_comment(HDL) << endl;
										}
									}
								}
							}
						}
					}
					else if (Left_op < 0)
					{
						if (HT.findfact("rec_stmt(" + Module + "," + to_string(Left_op) + ",*)"))
						{
							In_par_list = returnVec(makeInstanceOf(HT.findandreturn("rec_stmt(" + Module + "," + to_string(Left_op) + ",*)")), 1);
							ss << write_record_special_operation(Module, Result, 0, In_par_list);
						}
					}
				}
			}
			else if (Operator == "*")
			{
				if (get_data_name(Module, Result, &Rd_name, &Rd_width))
				{
					if (Rd_width > 1)
					{
						Rd_up_limit = Rd_width - 1;
						if (get_data_name(Module, Left_op, &S1d_name, 0))
						{
							if (Right_op != 0)
							{
								if (get_data_name(Module, Right_op, &S2d_name, 0))
								{
									ss << Rd_name;
									ss << print_object_bit_range(Rd_up_limit, 0, HDL);
									ss << " <= ";
									ss << print_right_side_multdiv(Operator, S1d_name, S2d_name, Rd_width, HDL) << endl;
								}
							}
						}
					}
				}
			}
			else if (Operator == "**")
			{
				if (get_data_name(Module, Result, &Rd_name, &Rd_width))
				{
					if (Rd_width > 1)
					{
						Rd_up_limit = Rd_width - 1;
						if (get_data_name(Module, Left_op, &S1d_name, 0))
						{
							if (Right_op != 0)
							{
								if (get_data_name(Module, Right_op, &S2d_name, 0))
								{
									ss << Rd_name;
									ss << print_object_bit_range(Rd_up_limit, 0, HDL);
									ss << " <= ";
									ss << print_right_side_multdiv(Operator, S1d_name, S2d_name, Rd_width, HDL) << endl;
								}
							}
						}
					}
				}
			}
			else if (Operator == "/")
			{
				if(get_data_name(Module, Result, &Rd_name, &Rd_width))
				{
					if (Rd_width > 1)
					{
						Rd_up_limit = Rd_width - 1;
						if (get_data_name(Module, Left_op, &S1d_name, 0))
						{
							if (Right_op != 0)
							{
								if (get_data_name(Module, Right_op, &S2d_name, 0))
								{
									ss << Rd_name;
									ss << print_object_bit_range(Rd_up_limit, 0, HDL);
									ss << " <= ";
									ss << print_right_side_multdiv(Operator, S1d_name, S2d_name, Rd_width, HDL) << endl;
								}
							}
						}
					}
				}
			}
			else if (Operator != "<=" && Operator != "*" && Operator != "/" && Operator != "+")
			{
				if (get_data_name(Module, Result, &Rd_name, &Rd_width))
				{
					if (Rd_width > 1)
					{
						if (get_data_name(Module, Left_op, &S1d_name, &S1d_width))
						{
							if (Right_op != 0)
							{
								if (get_data_name(Module, Right_op, &S2d_name, &S2d_width))
								{
									if (HT.findfact("change_op_number(" + Module + ",_," + to_string(Operation) + ")"))
									{
										Noperation = stoi(returnpar(HT.findandreturn("change_op_number(" + Module + ",_," + to_string(Operation) + ")"), 2));
										if (HT.findfact("prog_stmt(" + Module + "," + to_string(Noperation) + ",_,107,_,_,_,_)"))
										{
											Ndata_entry = stoi(returnpar(HT.findandreturn("prog_stmt(" + Module + "," + to_string(Noperation) + ",_,107,_,_,_,_)"), 5));
											if (HT.findfact("data_stmt(" + Module + ",_," + to_string(Ndata_entry) + ",_,_,_)"))
											{
												Ndata_name = returnpar(HT.findandreturn("data_stmt(" + Module + ",_," + to_string(Ndata_entry) + ",_,_,_)"), 2);
												if (HT.findfact("mem_port(_,_," + Module + "," + Ndata_name + ", _, _, _, _, _, _, _, _, _)"))
												{
													Base = stoi(returnpar(HT.findandreturn("mem_port(_,_," + Module + "," + Ndata_name + ",_,_,_,_,_,_,_,_,_)"), 12));
													if (Rd_width <= S1d_width)
													{
														if (Rd_width <= S2d_width)
														{
															ss << Rd_name;
															if (Rd_width > 1)
															{
																Rd_up_limit = Rd_width - 1;
																ss << print_object_bit_range(Rd_up_limit, 0, HDL);
																ss << " <= " << S1d_name;
																ss << print_object_bit_range(Rd_up_limit, 0, HDL);
																ss << " " << Operator << " " << S2d_name;
																ss << print_object_bit_range(Rd_up_limit, 0, HDL);
																ss << "; ";
																ss << write_special_comment(HDL) << endl;
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
			}
			else if (Operator != "<=" && Operator != "*" && Operator != "/")
			{
				if (get_data_name(Module, Result, &Rd_name, &Rd_width))
				{
					if (Rd_width > 1)
					{
						if (get_data_name(Module, Left_op, &S1d_name, &S1d_width))
						{
							if (Right_op != 0)
							{
								if (get_data_name(Module, Right_op, &S2d_name, &S2d_width))
								{
									if (HT.findfact("change_op_number(" + Module + ",_," + to_string(Operation) + ")"))
									{
										Noperation = stoi(returnpar(HT.findandreturn("change_op_number(" + Module + ",_," + to_string(Operation) + ")"), 2));
										if (HT.findfact("prog_stmt(" + Module + "," + to_string(Noperation) + ",_,108,_,_,_,_)"))
										{
											Ndata_entry = stoi(returnpar(HT.findandreturn("prog_stmt(" + Module + "," + to_string(Noperation) + ",_,108,_,_,_,_)"), 7));
											if (HT.findfact("data_stmt(" + Module + ",_," + to_string(Ndata_entry) + ",*)"))
											{
												Ndata_name = returnpar(HT.findandreturn("data_stmt(" + Module + ",_," + to_string(Ndata_entry) + ",_,_,_)"), 2);
												if (HT.findfact("mem_port(_,_," + Module + "," + Ndata_name + ",_,_,_,_,_,_,_,_,_)"))
												{
													Base = stoi(returnpar(HT.findandreturn("mem_port(_,_," + Module + "," + Ndata_name + ",_,_,_,_,_,_,_,_,_)"), 12));
													if (Rd_width <= S1d_width)
													{
														if (Rd_width <= S2d_width)
														{
															ss << Rd_name;
															if (Rd_width > 1)
															{
																Rd_up_limit = Rd_width - 1;
																ss << print_object_bit_range(Rd_up_limit, 0, HDL);
																ss << " <= " << S1d_name;
																ss << print_object_bit_range(Rd_up_limit, 0, HDL);
																ss << " " << Operator << " " << S2d_name;
																ss << print_object_bit_range(Rd_up_limit, 0, HDL);
																ss << " + " << Base;
																ss << "; ";
																ss << write_special_comment(HDL) << endl;
															}
														}
													}
												}
											}
										}
									}
									else if (!HT.findfact("change_op_number(" + Module + ",_," + to_string(Operation) + ")"))
									{
										ss << print_special_triplet_op(HDL, Operator, Rd_name, Rd_width, S1d_name, S1d_width, S2d_name, S2d_width);
										ss << write_special_comment(HDL) << endl;
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return ss.str();
}

bool get_data_name(string Module, int Entry_number, string* LowName, int* Width)
{
	string Name;
	int Data_type;
	if (Entry_number < 0)
	{
		if (HT.findfact("special_dt(" + Module + "," + to_string(Entry_number) + ",_,_,\"std_logic\",_,_)"))
		{
			Name = returnpar(HT.findandreturn("special_dt(" + Module + "," + to_string(Entry_number) + ",_,_,\"std_logic\",_,_)"), 3);
			*Width = stoi(returnpar(HT.findandreturn("special_dt(" + Module + "," + to_string(Entry_number) + ",_,_,\"std_logic\",_,_)"), 4));
			upper_lower(Name, LowName);
			return true;
		}
	}
	else if (Entry_number > 0)
	{
		if (HT.findfact("data_stmt(" + Module + ",_," + to_string(Entry_number) + ",_,_,_)"))
		{
			Name= returnpar(HT.findandreturn("data_stmt(" + Module + ",_," + to_string(Entry_number) + ",_,_,_)"), 2);
			Data_type = stoi(returnpar(HT.findandreturn("data_stmt(" + Module + ",_," + to_string(Entry_number) + ",_,_,_)"), 4));
			if (HT.findfact("type_def(" + to_string(Data_type) + ",*)"))
			{
				*Width = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Data_type) + ",*)"), 3));
				upper_lower(Name, LowName);
				return true;
			}
		}
	}
	return false;
}

string write_special_comment(string HDL)
{
	stringstream ss;
	if (HDL == "vhdl")
		ss << " -- produced by special (probably external memory IO) sequence operation ";
	else if (HDL == "verilog")
		ss << " // produced by special (probably external memory IO) sequence operation ";
	else if (HDL == "c")
		ss << " /* produced by special (probably external memory IO) sequence operation */";
	return ss.str();
}

string write_record_special_operation(string Module, int Result, int Down_limit, vector<int> List)
{
	stringstream ss;
	int Next_down_limit;
	if (!List.empty())
	{
		ss << write_record_special_operation_core(Module, Result, Down_limit, List.front(), &Next_down_limit);
		List.erase(List.begin());
		write_record_special_operation(Module, Result, Next_down_limit, List);
	}
	return ss.str();
}

string write_record_special_operation_core(string Module, int Result, int Down_limit, int Par, int* Next_down_limit)
{
	stringstream ss;
	string Par_name, Rd_name;
	int Par_width, Up_limit;
	if (HT.findfact("hdl_style(\"vhdl\")"))
	{
		get_data_name(Module, Par, &Par_name, &Par_width);
		Up_limit = Down_limit + Par_width - 1;
		get_data_name(Module, Result, &Rd_name, 0);
		ss << Rd_name << "(" << Up_limit << " DOWNTO " << Down_limit << ") <= " << Par_name << "; " << " -- produced by special (probably external memory IO) sequence operation " << endl;
		ss << "            ";
		*Next_down_limit = Up_limit + 1;
	}
	else if (HT.findfact("hdl_style(\"verilog\")"))
	{
		get_data_name(Module, Par, &Par_name, &Par_width);
		Up_limit = Down_limit + Par_width - 1;
		get_data_name(Module, Result, &Rd_name, 0);
		ss << Rd_name << "[" << Up_limit << ":" << Down_limit << "] <= " << Par_name << "; " << " //-- produced by special (probably external memory IO) sequence operation " << endl;
		ss << "            ";
		*Next_down_limit = Up_limit + 1;
	}
	return ss.str();
}

string print_object_bit_range(int Upper_bound, int Lower_bound, string HDL)
{
	stringstream ss;
	if (HDL == "vhdl")
		ss << "(" << Upper_bound << " DOWNTO " << Lower_bound << ")";
	else if (HDL == "verilog")
		ss << "[" << Upper_bound << ":" << Lower_bound << "]";
	return ss.str();
}

string print_first_concat_symbol(string HDL)
{
	stringstream ss;
	if (HDL == "verilog")
		ss << "{";
	return ss.str();
}

string print_record_object_components(string Module, string Object_name, int Next_comp, int First_comp, int Next_low_bound)
{
	stringstream ss;
	string HDL, Comp_name;
	int Comp_size, First_dim, Field_number, Next_next_comp, Next_next_low_bound;
	if (First_comp == Next_comp)
	{
		if (HT.findfact("hdl_style(*)"))
		{
			HDL = returnpar(HT.findandreturn("hdl_style(*)"), 1);
			if (Next_comp > First_comp)
			{
				if (HT.findfact("type_def(" + to_string(First_comp) + ",_,_,_,_,\"single_t\",_,_,_)"))
				{
					Comp_name = returnpar(HT.findandreturn("type_def(" + to_string(First_comp) + ",_,_,_,_,\"single_t\",_,_,_)"), 2);
					Comp_size = stoi(returnpar(HT.findandreturn("type_def(" + to_string(First_comp) + ",_,_,_,_,\"single_t\",_,_,_)"), 3));
					First_dim = stoi(returnpar(HT.findandreturn("type_def(" + to_string(First_comp) + ",_,_,_,_,\"single_t\",_,_,_)"), 7));
					Field_number = Next_comp - First_comp;
					ss << print_record_field(Object_name, Comp_name, Comp_size, Field_number, First_dim, Next_low_bound, HDL);
					ss << print_concat(HDL);
					Next_next_comp = Next_comp - 1;
					Next_next_low_bound = Next_low_bound - Comp_size;
					ss << print_record_object_components(Module, Object_name, Next_next_comp, First_comp, Next_next_low_bound);

				}
			}
			else if (HT.findfact("type_def(" + to_string(First_comp) + ",_,_,_,_,\"single_t\",_,_,_)"))
			{
				Comp_name = returnpar(HT.findandreturn("type_def(" + to_string(First_comp) + ",_,_,_,_,\"single_t\",_,_,_)"), 2);
				Comp_size = stoi(returnpar(HT.findandreturn("type_def(" + to_string(First_comp) + ",_,_,_,_,\"single_t\",_,_,_)"), 3));
				First_dim = stoi(returnpar(HT.findandreturn("type_def(" + to_string(First_comp) + ",_,_,_,_,\"single_t\",_,_,_)"), 7));
				ss << print_record_field(Object_name, Comp_name, Comp_size, 1, First_dim, Next_low_bound, HDL);
			}
		}
	}
	return ss.str();
}

string print_record_field(string Record_name, string Field_name, int Field_size, int int2, int int3, int Low_bound, string HDL)
{
	stringstream ss;
	int Upper_bound, Lower_bound;
	if (HDL == "vhdl")
	{
		ss << Record_name << Field_name;
	}
	else if (HDL == "verilog")
	{
		Upper_bound = Low_bound + Field_size - 1;
		Lower_bound = Low_bound;
		ss << Record_name << "[" << Upper_bound << ":" << Lower_bound << "]";

	}
	return ss.str();
}

string print_concat(string HDL)
{
	stringstream ss;
	if (HDL == "vhdl") ss << " & ";
	else if (HDL == "verilog") ss << ", ";
	return ss.str();
}

string print_last_concat_symbol(string HDL)
{
	stringstream ss;
	if (HDL == "verilog") ss << "}";
	return ss.str();
}

string print_record_fields_concatenation(string Sd_name, int Sd_type, int Field_type, string HDL)
{
	stringstream ss;
	string Field_name;
	int Prev_field_type;
	if (HDL == "vhdl")
	{
		if (Field_type == Sd_type + 1)
		{
			if (HT.findfact("type_def(_,_,_,_,_,_,_,_,2)"))
			{
				Field_name = returnpar(HT.findandreturn("type_def(_,_,_,_,_,_,_,_,2)"), 2);
				ss << Sd_name << Field_name;
			}
		}
		else if (Field_type > Sd_type + 1)
		{
			if (HT.findfact("type_def(" + to_string(Field_type) + ",_,_,_,_,_,_,_,2)"))
			{
				Field_name = returnpar(HT.findandreturn("type_def(" + to_string(Field_type) + ",_,_,_,_,_,_,_,2)"), 2);
				ss << Sd_name << Field_name << " & ";
				Prev_field_type = Field_type - 1;
				ss << print_record_fields_concatenation(Sd_name, Sd_type, Prev_field_type, "vhdl");
			}
		}
	}
	return ss.str();
}

string write_assignment_to_a_record(string Module, string Operator, string Sd_name, string Rd_name, int Num_of_elements, int Input_elem_number, int Input_shift_offset, string HDL)
{
	stringstream ss;
	int Element_width, Next_shift_offset, Next_element;
	if (Input_elem_number != Num_of_elements)
	{
		ss << write_assignment_to_a_record_core(Module, Operator, Sd_name, Rd_name, Input_elem_number, Num_of_elements, Input_shift_offset, &Element_width, HDL);
		Next_shift_offset = Input_shift_offset + Element_width;
		Next_element = Input_elem_number + 1;
		ss << write_assignment_to_a_record(Module, Operator, Sd_name, Rd_name, Num_of_elements, Next_element, Next_shift_offset, HDL);
	}
	return ss.str();
}

string write_assignment_to_a_record_core(string Module, string Operator, string Sd_name, string Rd_name, int Input_elem_number, int Num_of_elements, int Input_shift_offset, int* Element_width, string HDL)
{
	stringstream ss;
	int Base_type, First_elem_type, Element_type;
	string Element_name;
	if (HDL == "vhdl" || HDL == "c")
	{
		if (Input_elem_number < Num_of_elements)
		{
			if (HT.findfact("data_stmt(" + Module + "," + Rd_name + ",*)"))
			{
				Base_type = stoi(returnpar(HT.findandreturn("data_stmt(" + Module + "," + Rd_name + ",*)"), 4));
				if (HT.findfact("type_def("+to_string(Base_type)+",_,_,_,_,\"record_t\",_,_,_)"))
				{
					First_elem_type = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Base_type) + ",_,_,_,_,\"record_t\",_,_,_)"), 9));
					Element_type = First_elem_type + Input_elem_number;
					if (HT.findfact("type_def("+to_string(Element_type)+",_,_,_,"+to_string(Base_type)+",\"single_t\",_,_,_)"))
					{
						Element_name = returnpar(HT.findandreturn("type_def(" + to_string(Element_type) + ",_,_,_," + to_string(Base_type) + ",\"single_t\",_,_,_)"), 2);
						*Element_width = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Element_type) + ",_,_,_," + to_string(Base_type) + ",\"single_t\",_,_,_)"), 3));
						if (HDL == "vhdl")
							ss << write_record_field_target_assignment(Operator, Rd_name, Element_name, Input_shift_offset, Sd_name, "vhdl");
						else
							ss << write_record_field_target_assignment(Operator, Rd_name, Element_name, Input_shift_offset, Sd_name, "c");
					}
				}
			}
		}

	}
	return ss.str();
}

string write_record_field_target_assignment(string op, string Rd_name, string Element_name, int Input_shift_offset, string Sd_name, string HDL)
{
	stringstream ss;
	int Elem_width, High_order, High_order1, Low_order;
	if (op == "<=")
	{
		if (HDL == "vhdl")
		{
			if (Input_shift_offset == 0)
			{
				if (HT.findfact("type_def(_," + Element_name + ",_,_,_,\"single_t\",_,_,_)"))
				{
					Elem_width = stoi(returnpar(HT.findandreturn("type_def(_," + Element_name + ",_,_,_,\"single_t\",_,_,_)"), 3));
					High_order = Elem_width - 1;
					ss << Rd_name << Element_name << " <= " << Sd_name << "(" << High_order << " DOWNTO 0);" << endl;
				}
			}
			else if (Input_shift_offset > 0)
			{
				if (HT.findfact("type_def(_," + Element_name + ",_,_,_,\"single_t\",_,_,_)"))
				{
					Elem_width = stoi(returnpar(HT.findandreturn("type_def(_," + Element_name + ",_,_,_,\"single_t\",_,_,_)"), 3));
					High_order1 = Elem_width - 1;
					High_order = Input_shift_offset + High_order1;
					Low_order = Input_shift_offset;
					ss << "            " << Rd_name << Element_name << " <= " << Sd_name << "(" << High_order << " DOWNTO " << Low_order << ");" << endl;
				}
			}
		}
		else if (HDL == "c")
		{
			if (Input_shift_offset == 0)
			{
				ss << "            " << Rd_name << Element_name << " = " << Sd_name << ";" << endl;
			}
			else if (Input_shift_offset > 0)
			{
				ss << "            " << Rd_name << Element_name << " = " << Sd_name << " << " << Input_shift_offset << ";" << endl;
			}
		}
	}
	return ss.str();
}

string  print_special_triplet_op(string HDL, string Operator, string Rd_name, int Rd_width, string Left_name, int Left_width, string Right_name, int Right_width)
{
	stringstream ss;
	int Rd_up_limit, Left_up_limit, Right_up_limit;
	if (Rd_width <= Left_width)
	{
		if (Rd_width <= Right_width)
		{
			ss << Rd_name;
			if (Rd_width > 1)
			{
				Rd_up_limit = Rd_width - 1;
				ss << print_object_bit_range(Rd_up_limit, 0, HDL);
				ss << " <= " << Left_name;
				ss << print_object_bit_range(Rd_up_limit, 0, HDL);
				ss << " " << Operator << " " << Right_name;
				ss << print_object_bit_range(Rd_up_limit, 0, HDL);
				ss << "; ";
			}
		}
	}
	else if (Rd_width >= Left_width)
	{
		if (Left_width <= Right_width)
		{
			ss << Rd_name;
			if (Left_width > 1)
			{
				Left_up_limit = Left_width - 1;
				ss << print_object_bit_range(Left_up_limit, 0, HDL);
				ss << " <= " << Left_name;
				ss << print_object_bit_range(Left_up_limit, 0, HDL);
				ss << " " << Operator << " " << Right_name;
				ss << print_object_bit_range(Left_up_limit, 0, HDL);
				ss << "; ";
			}
		}
	}
	else if (Rd_width >= Right_width)
	{
		if (Left_width >= Right_width)
		{
			ss << Rd_name;
			if (Right_width > 1)
			{
				Right_up_limit = Right_width - 1;
				ss << print_object_bit_range(Right_up_limit, 0, HDL);
				ss << " <= " << Left_name;
				ss << print_object_bit_range(Right_up_limit, 0, HDL);
				ss << " " << Operator << " " << Right_name;
				ss << print_object_bit_range(Right_up_limit, 0, HDL);
				ss << "; ";
			}
		}
	}
	return ss.str();
}

string print_right_side_multdiv(string Operator, string Left, string Right, int Data_width, string HDL)
{
	stringstream ss;
	if (HDL == "vhdl")
	{
		ss << "conv_std_logic_vector(CONV_INTEGER(" << Left << ") " << Operator << " CONV_INTEGER(" << Right << "), " << Data_width << "); " << " -- produced by special (probably external memory IO) sequence operation ";
	}
	else if (HDL == "verilog")
	{
		ss << Left << " " << Operator << " " << Right << " " << "; // produced by special (probably external memory IO) sequence operation ";
	}
	return ss.str();
}

string write_record_assignment_to_variable(string Module, string Sd_name, int Left_op, int Left_type, int No_of_fields, int First_field_type)
{
	stringstream ss;
	int Shifts, Field_type, Next_fields;
	string Field_name, Total_name;
	if (No_of_fields > 0)
	{
		last_field_shift(No_of_fields, First_field_type, 0, &Shifts);
		Field_type = First_field_type + No_of_fields - 1;
		if (HT.findfact("type_def("+to_string(Field_type)+",_,_,_,_,_,_,_,2)"))
		{
			Field_name = returnpar(HT.findandreturn("type_def(" + to_string(Field_type) + ",_,_,_,_,_,_,_,2)"), 2);
			HT.concat(Sd_name, Field_name, &Total_name);
			ss << conditionally_write_shift(Total_name, Shifts);
			ss << conditionally_write_field_or(First_field_type, Field_type);
			Next_fields = No_of_fields - 1;
			ss << write_record_assignment_to_variable(Module, Sd_name, Left_op, Left_type, Next_fields, First_field_type);
		}
	}
	return ss.str();
}

void last_field_shift(int No_of_fields, int First_field_type, int In_shift_amount, int* Total_shift_amount)
{
	int Field_size, Next_no_of_fields, Next_shift_amount, Next_Field_type;
	if (No_of_fields == 1)
	{
		*Total_shift_amount = In_shift_amount;
	}
	else if (No_of_fields > 1)
	{
		if (HT.findfact("type_def(" + to_string(First_field_type) + ",_,_,_,_,_,_,_,2)"))
		{
			Field_size = stoi(returnpar(HT.findandreturn("type_def(" + to_string(First_field_type) + ",_,_,_,_,_,_,_,2)"), 3));
			Next_no_of_fields = No_of_fields - 1;
			Next_shift_amount = In_shift_amount + Field_size;
			Next_Field_type = First_field_type + 1;
			last_field_shift(Next_no_of_fields, Next_Field_type, Next_shift_amount, Total_shift_amount);
		}
	}
}

string conditionally_write_shift(string Total_name, int Shifts)
{
	stringstream ss;
	if (Shifts == 0)
		ss << " " << Total_name;
	else if (Shifts > 0)
		ss << " " << Total_name << " << " << Shifts;
	return ss.str();
}

string conditionally_write_field_or(int First_type, int Field_type)
{
	stringstream ss;
	if (First_type < Field_type)
		ss << " | ";
	return ss.str();
}

string write_long_int_conditionally(int Width)
{
	stringstream ss;
	if (Width > 32)
		ss << "(long long int) ";
	return ss.str();
}

void total_number_of_aggregate_fields(string Module, vector<int> List, int In_shifts, int In_total_fields, int* Total_fields, int* Last_field, vector<int> In_shift_list, vector<int>* Total_shift_list)
{
	int Data_type, Next_total_fields, Data_size, Next_shift;
	vector<int> Shift_list, Next_shift_list;
	if (List.size() == 1)
	{
		*Last_field = List.front();
		if (HT.findfact("data_stmt(" + Module + ",_," + to_string(List.front()) + ",_,_,_)"))
		{
			Data_type = stoi(returnpar(HT.findandreturn("data_stmt(" + Module + ",_," + to_string(List.front()) + ",_,_,_)"), 4));
			if (HT.findfact("type_def(" + to_string(Data_type) + ",_,_,_,_,\"single_t\",_,_,_)"))
			{
				*Total_fields = In_total_fields;
				append_list(In_shift_list, In_shifts, &Shift_list);
			}
		}
	}
	if (List.size() > 1)
	{
		Next_total_fields = In_total_fields + 1;
		if (HT.findfact("data_stmt(" + Module + ",_," + to_string(List.front()) + ",_,_,_)"))
		{
			Data_type = stoi(returnpar(HT.findandreturn("data_stmt(" + Module + ",_," + to_string(List.front()) + ",_,_,_)"), 4));
			if (HT.findfact("type_def(" + to_string(Data_type) + ",_,_,_,_,\"single_t\",_,_,_)"))
			{
				Data_size = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Data_type) + ",_,_,_,_,\"single_t\",_,_,_)"), 3));
				Next_shift = In_shifts + Data_size;
				append_list(In_shift_list, In_shifts, &Next_shift_list);
				List.erase(List.begin());
				total_number_of_aggregate_fields(Module, List, Next_shift, Next_total_fields, Total_fields, Last_field, Next_shift_list, Total_shift_list);
			}
		}
	}
}

void append_list(vector<int> List1, int Local, vector<int>* List2)
{
	if (!List1.empty())
	{
		*List2 = List1;
		List2->push_back(Local);
	}
}

string type_aggregate_record_shifts(string Module, vector<int> Field_list, int Total_fields, vector<int> Total_shift_list)
{
	stringstream ss;
	string Data_name;
	int Next_target_field;
	if (Total_fields == 1)
	{
		if (HT.findfact("data_stmt(" + Module + ",_," + to_string(Field_list.front()) + ",_,_,_)"))
		{
			Data_name = returnpar(HT.findandreturn("data_stmt(" + Module + ",_," + to_string(Field_list.front()) + ",_,_,_)"), 2);
			ss << Data_name;
		}
		else if (Total_fields > 1)
		{
			ss << type_field_shifts(Module, Field_list, Total_shift_list, 1, Total_fields);
			ss << conditionally_write_field_or(1, Total_fields);
			Next_target_field = Total_fields - 1;
			ss << type_aggregate_record_shifts(Module, Field_list, Next_target_field, Total_shift_list);
		}
	}
	return ss.str();
}

string type_field_shifts(string Module, vector<int> List1, vector<int> List2, int In_field_no, int Target_field_no)
{
	stringstream ss;
	string Data_name;
	int Next_field_no;
	if (In_field_no == Target_field_no)
	{
		if (HT.findfact("data_stmt(" + Module + ",_,"+to_string(List1.front())+",_,_,_)"))
		{
			Data_name = returnpar(HT.findandreturn("data_stmt(" + Module + ",_," + to_string(List1.front()) + ",_,_,_)"), 2);
			ss << conditionally_write_shift(Data_name, List2.front());
		}
	}
	else if (In_field_no < Target_field_no)
	{
		Next_field_no = In_field_no + 1;
		List1.erase(List1.begin());
		List2.erase(List2.begin());
		type_field_shifts(Module, List1, List2, Next_field_no, Target_field_no);
	}
	return ss.str();
}

string write_output_state_assignments(string Module_name, int State, vector<int> List)
{
	stringstream ss;
	if (!List.empty())
	{
		ss << "            ";
		ss << write_output_state_assignment(Module_name, State, List.front());
		List.erase(List.begin());
		ss << write_output_state_assignments(Module_name, State, List);
	}
	return ss.str();
}

string write_output_state_assignment(string Module_name, int State, int Op)
{
	stringstream ss;
	int Op_numb, Res_op, Res_type, Res_size, Signal_type, Right_op, Right_type, Right_size, Ssize, Parent_type, Result, Size;
	string Res_name, State_numb, State_name, Signal_inst_name, Right_name, HDL, Result_name;
	if (HT.findfact("hdl_style(\"vhdl\")"))
	{
		if (Op > 0)
		{
			if (HT.findfact("prog_stmt(" + Module_name + "," + to_string(Op) + ",*)"))
			{
				Op_numb = stoi(returnpar(HT.findandreturn("prog_stmt(" + Module_name + "," + to_string(Op) + ",*)"), 4));
				Right_op = stoi(returnpar(HT.findandreturn("prog_stmt(" + Module_name + "," + to_string(Op) + ",*)"), 6));
				Res_op = stoi(returnpar(HT.findandreturn("prog_stmt(" + Module_name + "," + to_string(Op) + ",*)"), 7));
				if (Op_numb != 102 && Op_numb != 106 && Op_numb != 109 && Op_numb != 110)
				{
					if (!is_exception_output_operator(Op_numb))
					{
						if (HT.findfact("op_def(" + to_string(Op_numb) + ",*)"))
						{
							if (HT.findfact("data_stmt(" + Module_name + ",_," + to_string(Res_op) + ",_,_,_)"))
							{
								Res_name = returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Res_op) + ",_,_,_)"), 2);
								Res_type = stoi(returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Res_op) + ",_,_,_)"), 4));
								if (HT.findfact("type_def(" + to_string(Res_type) + ",*)"))
								{
									Res_size = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Res_type) + ",*)"), 3));
									if (Res_size == 1)
									{
										str_int(&State_numb, State);
										HT.concat("state_", State_numb, &State_name);
										if (HT.findfact("output_instance(_," + State_name + "," + Res_name + ",_,_,_)"))
										{
											Signal_inst_name = returnpar(HT.findandreturn("output_instance(_," + State_name + "," + Res_name + ",_,_,_)"), 4);
											Signal_type = stoi(returnpar(HT.findandreturn("output_instance(_," + State_name + "," + Res_name + ",_,_,_)"), 5));
											if (Signal_type == 1)
											{
												ss << Res_name << " <= " << Signal_inst_name << "; " << endl;
											}
										}
									}
								}
							}
						}
					}
					else if (out_of_logical_op(Op_numb))
					{
						if (HT.findfact("op_def(" + to_string(Op_numb) + ",*)"))
						{
							if (!is_exception_output_operator(Op_numb))
							{
								if (HT.findfact("data_stmt(" + Module_name + ",_," + to_string(Res_op) + ",_,_,_)"))
								{
									Res_name = returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Res_op) + ",_,_,_)"), 2);
									Res_type = stoi(returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Res_op) + ",_,_,_)"), 4));
									if (HT.findfact("type_def(" + to_string(Res_type) + ",*)"))
									{
										Res_size = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Res_type) + ",*)"), 3));
										if (Res_size > 1)
										{
											str_int(&State_numb, State);
											HT.concat("state_", State_numb, &State_name);
											if (HT.findfact("output_instance(_," + State_name + "," + Res_name + ",_,_,_)"))
											{
												Signal_inst_name = returnpar(HT.findandreturn("output_instance(_," + State_name + "," + Res_name + ",_,_,_)"), 4);
												Signal_type = stoi(returnpar(HT.findandreturn("output_instance(_," + State_name + "," + Res_name + ",_,_,_)"), 5));
												if (Signal_type == 1)
												{
													ss << Res_name << " <= " << Signal_inst_name << "; " << endl;
												}
											}
										}
									}
								}
							}
						}
					}
					else if (Op_numb >= 7)
					{
						if (Op_numb <= 10)
						{
							if (HT.findfact("op_def(" + to_string(Op_numb) + ",*)"))
							{
								if (!is_exception_output_operator(Op_numb))
								{
									if (HT.findfact("data_stmt(" + Module_name + ",_,"+to_string(Res_op)+",_,_,_)"))
									{
										Res_name = returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Res_op) + ",_,_,_)"), 2);
										Res_type = stoi(returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Res_op) + ",_,_,_)"), 4));
										if (HT.findfact("type_def("+to_string(Res_type)+",*)"))
										{
											Res_size = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Res_type) + ",*)"), 3));
											if (Res_size > 1)
											{
												str_int(&State_numb, State);
												HT.concat("state_", State_numb, &State_name);
												if (HT.findfact("output_instance(_,"+State_name+","+Res_name+",_,_,_)"))
												{
													Signal_inst_name = returnpar(HT.findandreturn("output_instance(_," + State_name + "," + Res_name + ",_,_,_)"), 4);
													Signal_type = stoi(returnpar(HT.findandreturn("output_instance(_," + State_name + "," + Res_name + ",_,_,_)"), 5));
													if (Signal_type == 1)
													{
														ss << Res_name << " <= " << Signal_inst_name << "; " << endl;
													}
												}
											}
										}
									}
								}
							}
						}
					}
					else if (HT.findfact("op_def(" + to_string(Op_numb) + ",*)"))
					{
						if (!is_exception_output_operator(Op_numb))
						{
							if (HT.findfact("data_stmt(" + Module_name + ",_," + to_string(Res_op) + ",_,_,_)"))
							{
								Res_name = returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Res_op) + ",_,_,_)"), 2);
								Res_type = stoi(returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Res_op) + ",_,_,_)"), 4));
								if (HT.findfact("type_def(" + to_string(Res_type) + ",*)"))
								{
									Res_size = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Res_type) + ",*)"), 3));
									if (Res_size > 1)
									{
										str_int(&State_numb, State);
										HT.concat("state_", State_numb, &State_name);
										if (HT.findfact("output_instance(_," + State_name + "," + Res_name + ",_,_,_)"))
										{
											Signal_inst_name = returnpar(HT.findandreturn("output_instance(_," + State_name + "," + Res_name + ",_,_,_)"), 4);
											Signal_type = stoi(returnpar(HT.findandreturn("output_instance(_," + State_name + "," + Res_name + ",_,_,_)"), 5));
											if (Signal_type > 1)
											{
												ss << Res_name << " <= " << Signal_inst_name << "; " << endl;
											}
										}
									}
									else if (Res_size == 1)
									{
										if (HT.findfact("data_stmt(" + Module_name + ",_," + to_string(Right_op) + ",_,_,_)"))
										{
											Right_name = returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Right_op) + ",_,_,_)"), 2);
											Right_type = stoi(returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Right_op) + ",_,_,_)"), 4));
											if (HT.findfact("type_def(" + to_string(Right_type) + ",*)"))
											{
												Right_size = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Right_type) + ",*)"), 3));
												if (Right_size == 1)
												{
													str_int(&State_numb, State);
													HT.concat("state_", State_numb, &State_name);
													if (HT.findfact("output_instance(_," + State_name + "," + Res_name + ",_,_,_)"))
													{
														Signal_inst_name = returnpar(HT.findandreturn("output_instance(_," + State_name + "," + Res_name + ",_,_,_)"), 4);
														Signal_type = stoi(returnpar(HT.findandreturn("output_instance(_," + State_name + "," + Res_name + ",_,_,_)"), 5));
														if (HT.findfact("type_def("+to_string(Signal_type)+",*)"))
														{
															Ssize = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Signal_type) + ",*)"), 3));
															Parent_type = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Signal_type) + ",*)"), 5));
															if (Parent_type == 2)
															{
																if (Ssize == 1)
																{
																	if (Res_type == Signal_type)
																	{
																		ss << Res_name << " <= " << Signal_inst_name << "; " << endl;
																	}
																}
															}
														}
													}
												}
												else if (Right_size > 1)
												{
													str_int(&State_numb, State);
													HT.concat("state_", State_numb, &State_name);
													if (HT.findfact("output_instance(_," + State_name + "," + Res_name + ",_,_,_)"))
													{
														Signal_inst_name = returnpar(HT.findandreturn("output_instance(_," + State_name + "," + Res_name + ",_,_,_)"), 4);
														ss << Res_name << " <= " << Signal_inst_name << "; " << endl;
													}
												}
											}
										}
										else
										{
											str_int(&State_numb, State);
											HT.concat("state_", State_numb, &State_name);
											if (HT.findfact("output_instance(_," + State_name + "," + Res_name + ",_,_,_)"))
											{
												Signal_inst_name = returnpar(HT.findandreturn("output_instance(_," + State_name + "," + Res_name + ",_,_,_)"), 4);
												Signal_type = stoi(returnpar(HT.findandreturn("output_instance(_," + State_name + "," + Res_name + ",_,_,_)"), 5));
												if (Signal_type == 2)
												{
													ss << Res_name << " <= " << Signal_inst_name << "(0); " << endl;
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
		else if (Op < 0)
		{
			if (HT.findfact("special_op(" + Module_name + "," + to_string(Op) + ",*)"))
			{
				Result = stoi(returnpar(HT.findandreturn("special_op(" + Module_name + "," + to_string(Op) + ",*)"), 6));
				if (get_data_name(Module_name, Result, &Result_name, 0))
				{
					str_int(&State_numb, State);
					HT.concat("state_", State_numb, &State_name);
					if (HT.findfact("output_instance(_," + State_name + "," + Result_name + ",_,_,_)"))
					{
						Result_name = returnpar(HT.findandreturn("output_instance(_," + State_name + "," + Result_name + ",_,_,_)"), 3);
						Signal_inst_name = returnpar(HT.findandreturn("output_instance(_," + State_name + "," + Result_name + ",_,_,_)"), 4);
						Size = stoi(returnpar(HT.findandreturn("output_instance(_," + State_name + "," + Result_name + ",_,_,_)"), 6));
						ss << Result_name << " <= conv_std_logic_vector(CONV_INTEGER(" << Signal_inst_name << "), " << Size << "); " << endl;
					}
				}
			}
		}
	}
	else if (HT.findfact("hdl_style(\"verilog\")"))
	{
		if (Op > 0)
		{
			if (HT.findfact("prog_stmt(" + Module_name + "," + to_string(Op) + ",*)"))
			{
				Op_numb = stoi(returnpar(HT.findandreturn("prog_stmt(" + Module_name + "," + to_string(Op) + ",*)"), 4));
				Res_op = stoi(returnpar(HT.findandreturn("prog_stmt(" + Module_name + "," + to_string(Op) + ",*)"), 7));
				if (Op_numb != 102 && Op_numb != 106 && Op_numb != 109 && Op_numb != 110)
				{
					if (HT.findfact("op_def(" + to_string(Op_numb) + ",*)"))
					{
						if (!is_exception_output_operator(Op_numb))
						{
							if (HT.findfact("data_stmt(" + Module_name + ",_," + to_string(Res_op) + ",_,_,_)"))
							{
								Res_name = returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Res_op) + ",_,_,_)"), 2);
								Res_type = stoi(returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Res_op) + ",_,_,_)"), 4));
								if (HT.findfact("type_def(" + to_string(Res_type) + ",*)"))
								{
									Res_size = stoi(returnpar(HT.findandreturn("type_def(" + to_string(Res_type) + ",*)"), 3));
									str_int(&State_numb, State);
									HT.concat("state_", State_numb, &State_name);
									if (HT.findfact("output_instance(_," + State_name + "," + Res_name + ",_,_,_)"))
									{
										Signal_inst_name = returnpar(HT.findandreturn("output_instance(_," + State_name + "," + Res_name + ",_,_,_)"), 4);
										ss << Res_name << " <= " << Signal_inst_name << "; " << endl;
									}
								}
							}
						}
					}
				}
			}
		}
		else if (Op < 0)
		{
			if (HT.findfact("special_op(" + Module_name + "," + to_string(Op) + ",*)"))
			{
				Result = stoi(returnpar(HT.findandreturn("special_op(" + Module_name + "," + to_string(Op) + ",*)"), 6));
				if (get_data_name(Module_name, Result, &Result_name, 0))
				{
					str_int(&State_numb, State);
					HT.concat("state_", State_numb, &State_name);
					if (HT.findfact("output_instance(_," + State_name + "," + Result_name + ",_,_,_)"))
					{
						Result_name = returnpar(HT.findandreturn("output_instance(_," + State_name + "," + Result_name + ",_,_,_)"), 3);
						Signal_inst_name = returnpar(HT.findandreturn("output_instance(_," + State_name + "," + Result_name + ",_,_,_)"), 4);
						ss << Result_name << " <= " << Signal_inst_name << "; " << endl;
					}
				}
			}
		}
	}
	else if (Op > 0)
	{
		if (HT.findfact("prog_stmt(" + Module_name + "," + to_string(Op) + ",*)"))
		{
			Op_numb = stoi(returnpar(HT.findandreturn("prog_stmt(" + Module_name + "," + to_string(Op) + ",*)"), 4));
			Right_op = stoi(returnpar(HT.findandreturn("prog_stmt(" + Module_name + "," + to_string(Op) + ",*)"), 6));
			Res_op = stoi(returnpar(HT.findandreturn("prog_stmt(" + Module_name + "," + to_string(Op) + ",*)"), 7));
			if (Op_numb != 102 && Op_numb != 106 && Op_numb != 109 && Op_numb != 110)
			{
				if (is_exception_output_operator(Op_numb))
				{
					if (HT.findfact("data_stmt(" + Module_name + ",_," + to_string(Res_op) + ",_,_,_)"))
					{
						Res_name = returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Res_op) + ",_,_,_)"), 2);
						str_int(&State_numb, State);
						HT.concat("state_", State_numb, &State_name);
						if (!HT.findfact("output_instance(_," + State_name + "," + Res_name + ",_,_,_)"))
						{
							if (HT.findfact("hdl_style(*)"))
							{
								HDL = returnpar(HT.findandreturn("hdl_style(*)"), 1);
								ss << output_operation(Module_name, Op, HDL, "synergy");
							}
						}
					}
					else if (HT.findfact("hdl_style(*)"))
					{
						HDL = returnpar(HT.findandreturn("hdl_style(*)"), 1);
						ss << output_operation(Module_name, Op, HDL, "synergy");
					}
				}
			}
		}
	}
	else if (Op < 0)
	{
		if (HT.findfact("special_op(" + Module_name + "," + to_string(Op) + ",*)"))
		{
			Result = stoi(returnpar(HT.findandreturn("special_op(" + Module_name + "," + to_string(Op) + ",*)"), 6));
			if (get_data_name(Module_name, Result, &Result_name, 0))
			{
				str_int(&State_numb, State);
				HT.concat("state_", State_numb, &State_name);
				if (!HT.findfact("output_instance(_," + State_name + "," + Result_name + ",_,_,_)"))
				{
					if (HT.findfact("hdl_style(*)"))
					{
						HDL = returnpar(HT.findandreturn("hdl_style(*)"), 1);
						ss << output_special_operation(Module_name, Op, HDL, "synergy");
					}
				}
			}
		}
	}
	return ss.str();
}

bool is_exception_output_operator(int Op_numb)
{
	return Op_numb == 102 || Op_numb == 106 || Op_numb == 107 || Op_numb == 108 || Op_numb == 109 || Op_numb == 110;
}

string write_call(string WS, string Module_name, int State, int Next_state, int int1, vector<int> Total_ops, int Operation, string HDL, string Order)
{
	stringstream ss;
	int Op_type, Call_entry, Called_module_entry, CurrentDepth, MaxOrder, Same_order, Total_order, Gross, Res_entry, Res_type, Max_order, Same_total;
	string Called_module_name, Ordercus, New_schedule, Res_name, WS1;
	vector<int> vecOp, Actual_params;
	vecOp.push_back(Operation);
	vector<int> emptv;

	if(int1 == 0)
		return ss.str();
	if (Operation > 0)
	{
		if (HT.findfact("prog_stmt(" + Module_name + "," + to_string(Operation) + ",*)"))
		{
			Op_type = stoi(returnpar(HT.findandreturn("prog_stmt(" + Module_name + "," + to_string(Operation) + ",*)"), 2));
			if (Op_type != 109)
				return ss.str();
		}
	}
	if (int1 == 1)
	{
		if (HT.findfact("prog_stmt(" + Module_name + "," + to_string(Operation) + ",_,109,0,_,_,_)"))
		{
			Call_entry = stoi(returnpar(HT.findandreturn("prog_stmt(" + Module_name + "," + to_string(Operation) + ",_,109,0,_,_,_)"), 6));
			if (HT.findfact("call_stmt(" + Module_name + "," + to_string(Call_entry) + ",*)"))
			{
				Called_module_entry = stoi(returnpar(HT.findandreturn("call_stmt(" + Module_name + "," + to_string(Call_entry) + ",*)"), 3));
				if (HT.findfact("hierarchy_part(" + to_string(Called_module_entry) + ",_,_,\"libpart\",0,0,0)"))
					return ss.str();
				else if (HT.findfact("hierarchy_part(" + to_string(Called_module_entry) + ",_,_,\"libpart\",0," + to_string(Called_module_entry) + ",0)"))
					return ss.str();
			}
		}
	}
	if (HDL == "vhdl")
	{
		if (int1 == 1)
		{
			if (HT.findfact("hdl_style(\"vhdl\")"))
			{
				if (HT.findfact("prog_stmt(" + Module_name + "," + to_string(Operation) + ",_,109,0,_,_,_)"))
				{
					Call_entry = stoi(returnpar(HT.findandreturn("prog_stmt(" + Module_name + "," + to_string(Operation) + ",_,109,0,_,_,_)"), 6));
					if (HT.findfact("call_stmt(" + Module_name + "," + to_string(Call_entry) + ",*)"))
					{
						Called_module_entry = stoi(returnpar(HT.findandreturn("call_stmt(" + Module_name + "," + to_string(Call_entry) + ",*)"), 3));
						if (HT.findfact("hierarchy_part(" + to_string(Called_module_entry) + ",_,_,\"libpart\"," + to_string(Called_module_entry) + ",_,_)"))
						{
							Called_module_name = returnpar(HT.findandreturn("hierarchy_part(" + to_string(Called_module_entry) + ",_,_,\"libpart\"," + to_string(Called_module_entry) + ",_,_)"), 2);
							if (custom_block(Called_module_name))
							{
								read_current_depth(&CurrentDepth);
								if (HT.findfact("operation_order(" + Module_name + ",\"parcsif\"," + to_string(State) + "," + to_string(Operation) + "," + to_string(Called_module_entry) + ",*)"))
								{
									find_correct_order(Module_name, Call_entry, &MaxOrder);
									if (MaxOrder <= 1)
									{
										ss << WS << "------ this is a call to module : " << Called_module_name << " -----" << endl;
										ss << print_call_input_par_assignments_parcs(Module_name, vecOp, "");
										ss << endl;
										ss << WS << "           IF " << Called_module_name << "_busy = '0' AND " << Called_module_name << "_done = '0' THEN" << endl;
										ss << WS << "            IF " << Called_module_name << "_results_read_int = '1' THEN" << endl;
										ss << WS << "              ";
										ss << WS << Called_module_name << "_start_int" << " <= '0';" << endl;
										ss << WS << "              ";
										ss << WS << Called_module_name << "_results_read_int" << " <= '0';" << endl;
										ss << WS << "              state <= state_";
										ss << write_conditionally_next_state(Module_name, Next_state);
										ss << WS << "             ELSE" << endl;
										ss << WS << "              " << Called_module_name << "_start_int <= '1';" << endl;
										ss << WS << "              state <= state_" << State << ";" << endl;
										ss << WS << "             END IF;" << endl;
										ss << WS << "           ELSIF " << Called_module_name << "_busy = '1' AND " << Called_module_name << "_start_int = '1'	THEN   -- when it begins" << endl;
										ss << WS << "            " << Called_module_name << "_start_int <= '0';" << endl;
										ss << WS << "            state <= state_" << State << ";" << endl;
										ss << WS << "           ELSIF " << Called_module_name << "_done = '1' 	THEN   -- when it is completed then read the results" << endl;
										ss << print_call_output_par_assignments_parcs(Module_name, vecOp, "");
										ss << WS << "            " << Called_module_name << "_start_int <= '0';" << endl;
										ss << WS << "            IF " << Called_module_name << "_results_read_int = '0' THEN  -- if it is done then indicate that the results are read" << endl;
										ss << WS << "             " << Called_module_name << "_results_read_int <= '1';" << endl;
										ss << WS << "             state <= state_" << State << ";" << endl;
										ss << WS << "            ELSIF ";
										ss << WS << Called_module_name << "_results_read_int" << " = '1'";
										ss << WS << "  THEN -- all calls are synchronized and completed " << endl;
										ss << WS << "             ";
										ss << WS << Called_module_name << "_results_read_int" << " <= '0';" << endl;
										ss << WS << "             state <= state_";
										ss << write_conditionally_next_state(Module_name, Next_state);
										ss << WS << "            END IF;" << endl;
										ss << WS << "           ELSE " << endl;
										ss << WS << "            state <= state_" << State << ";" << endl;
										ss << WS << "           END IF; " << endl;
									}
								}
							}
							if (!custom_block(Called_module_name))
							{
								read_current_depth(&CurrentDepth);
								if (HT.findfact("operation_order(" + Module_name + ",\"parcsif\"," + to_string(State) + "," + to_string(Operation) + "," + to_string(Called_module_entry) + ",*)"))
								{
									Same_order = stoi(returnpar(HT.findandreturn("operation_order(" + Module_name + ",\"parcsif\"," + to_string(State) + "," + to_string(Operation) + "," + to_string(Called_module_entry) + ",*)"), 6));
									Total_order = stoi(returnpar(HT.findandreturn("operation_order(" + Module_name + ",\"parcsif\"," + to_string(State) + "," + to_string(Operation) + "," + to_string(Called_module_entry) + ",*)"), 9));
									Gross = stoi(returnpar(HT.findandreturn("operation_order(" + Module_name + ",\"parcsif\"," + to_string(State) + "," + to_string(Operation) + "," + to_string(Called_module_entry) + ",*)"), 10));

									if (Total_order > 1)
									{
										if (HT.findfact("new_schedule(*)"))
										{
											New_schedule = returnpar(HT.findandreturn("new_schedule(*)"), 1);
											make_order_string(Same_order, Same_order, &Ordercus);
											find_correct_order(Module_name, Call_entry, &MaxOrder);
											if (MaxOrder > 1)
											{
												ss << print_call_input_par_assignments_parcs(Module_name, vecOp, Ordercus) << endl;
												ss << WS << "           IF " << Called_module_name << Ordercus << "_busy = '0' AND " << Called_module_name << Ordercus << "_done = '0' THEN" << endl;
												ss << WS << "            IF " << Called_module_name << Ordercus << "_results_read_int = '1' THEN" << endl;
												ss << WS << "             IF ";
												ss << write_polymorfic_IO_exression(Module_name, New_schedule, State, Called_module_name, "results_read_int", 1, Gross, "                                ", " AND ", " = '1'", 1, 1);
												ss << WS << "             THEN " << endl;
												ss << WS << "              ";
												ss << write_polymorfic_IO_exression(Module_name, New_schedule, State, Called_module_name, "start_int", 1, Gross, "                                ", "", " <= '0';", 1, 0);
												ss << WS << "              ";
												ss << write_polymorfic_IO_exression(Module_name, New_schedule, State, Called_module_name, "results_read_int", 1, Gross, "                                ", "", " <= '0';", 1, 0);
												ss << write_next_state_conditionally(WS, CurrentDepth, Next_state);
												ss << WS << "             END IF;" << endl;
												ss << WS << "            ELSE" << endl;
												ss << WS << "              " << Called_module_name << Ordercus << "_start_int <= '1';" << endl;
												ss << WS << "              state_var(" << CurrentDepth << ") := state_" << State << ";" << endl;
												ss << WS << "            END IF;" << endl;
												ss << WS << "           ELSIF " << Called_module_name << Ordercus << "_busy = '1' AND " << Called_module_name << Ordercus << "_start_int = '1'	THEN   -- when it begins" << endl;
												ss << WS << "            " << Called_module_name << Ordercus << "_start_int <= '0';" << endl;
												ss << WS << "            state_var(" << CurrentDepth << ") := state_" << State << ";" << endl;
												ss << WS << "           ELSIF " << Called_module_name << Ordercus << "_done = '1' 	THEN   -- when it is completed then read the results" << endl;
												ss << print_call_output_par_assignments_parcs(Module_name, vecOp, Ordercus);
												ss << WS << "            " << Called_module_name << Ordercus << "_start_int <= '0';" << endl;
												ss << WS << "            IF " << Called_module_name << Ordercus << "_results_read_int = '0' THEN  -- if it is done then indicate that the results are read" << endl;
												ss << WS << "             " << Called_module_name << Ordercus << "_results_read_int <= '1';" << endl;
												ss << WS << "             state_var(" << CurrentDepth << ") := state_" << State << ";" << endl;
												ss << WS << "            ELSIF ";
												ss << write_polymorfic_IO_exression(Module_name, New_schedule, State, Called_module_name, "results_read_int", 1, Gross, "                                        ", " AND ", " = '1'", 1, 1);
												ss << WS << "            THEN -- all calls are synchronized and completed " << endl;
												ss << WS << "              ";
												ss << write_polymorfic_IO_exression(Module_name, New_schedule, State, Called_module_name, "results_read_int", 1, Gross, "                                        ", "", " <= '0';", 1, 0);
												ss << write_next_state_conditionally(WS, CurrentDepth, Next_state);
												ss << WS << "            END IF;" << endl;
												ss << WS << "           ELSE " << endl;
												ss << WS << "            state_var(" << CurrentDepth << ") := state_" << State << ";" << endl;
												ss << WS << "           END IF; " << endl;
												ss << write_total_order_assignment_conditional(WS, Total_order, CurrentDepth);
											}
										}
									}
									else if (Same_order == 1)
									{
										find_correct_order(Module_name, Call_entry, &MaxOrder);
										if (MaxOrder > 1)
										{
											ss << WS << "------ this is a call to module : " << Called_module_name << " -----" << endl;
											ss << print_call_input_par_assignments_parcs(Module_name, vecOp, "_1") << endl;
											ss << WS << "           IF " << Called_module_name << "_1_busy = '0' AND " << Called_module_name << "_1_done = '0' THEN" << endl;
											ss << WS << "             IF " << Called_module_name << "_1_results_read_int = '1' THEN" << endl;
											ss << WS << "              ";
											ss << WS << Called_module_name << "_1_start_int" << " <= '0';" << endl;
											ss << WS << "              ";
											ss << WS << Called_module_name << "_1_results_read_int" << " <= '0';" << endl;
											ss << WS << "              state <= state_";
											ss << write_conditionally_next_state(Module_name, Next_state);
											ss << WS << "             ELSE" << endl;
											ss << WS << "              " << Called_module_name << "_1_start_int <= '1';" << endl;
											ss << WS << "              state <= state_" << State << ";" << endl;
											ss << WS << "             END IF;" << endl;
											ss << WS << "           ELSIF " << Called_module_name << "_1_busy = '1' AND " << Called_module_name << "_1_start_int = '1'	THEN   -- when it begins" << endl;
											ss << WS << "            " << Called_module_name << "_1_start_int <= '0';" << endl;
											ss << WS << "            state <= state_" << State << ";" << endl;
											ss << WS << "           ELSIF " << Called_module_name << "_1_done = '1' 	THEN   -- when it is completed then read the results" << endl;
											ss << print_call_output_par_assignments_parcs(Module_name, vecOp, "_1");
											ss << WS << "            " << Called_module_name << "_1_start_int <= '0';" << endl;
											ss << WS << "            IF " << Called_module_name << "_1_results_read_int = '0' THEN  -- if it is done then indicate that the results are read" << endl;
											ss << WS << "             " << Called_module_name << "_1_results_read_int <= '1';" << endl;
											ss << WS << "             state <= state_" << State << ";" << endl;
											ss << WS << "            ELSIF ";
											ss << WS << Called_module_name << "_1_results_read_int" << " = '1'";
											ss << WS << "  THEN -- all calls are synchronized and completed " << endl;
											ss << WS << "             ";
											ss << WS << Called_module_name << "_1_results_read_int" << " <= '0';" << endl;
											ss << WS << "             state <= state_";
											write_conditionally_next_state(Module_name, Next_state);
											ss << WS << "            END IF;" << endl;
											ss << WS << "           ELSE " << endl;
											ss << WS << "            state <= state_" << State << ";" << endl;
											ss << WS << "           END IF; " << endl;
										}
									}
									find_correct_order(Module_name, Call_entry, &MaxOrder);
									if (MaxOrder <= 1)
									{
										ss << WS << "------ this is a call to module : " << Called_module_name << " -----" << endl;
										ss << print_call_input_par_assignments_parcs(Module_name, vecOp, "") << endl;
										ss << WS << "           IF " << Called_module_name << "_busy = '0' AND " << Called_module_name << "_done = '0' THEN" << endl;
										ss << WS << "            IF " << Called_module_name << "_results_read_int = '1' THEN" << endl;
										ss << WS << "              ";
										ss << WS << Called_module_name << "_start_int" << " <= '0';" << endl;
										ss << WS << "              ";
										ss << WS << Called_module_name << "_results_read_int" << " <= '0';" << endl;
										ss << WS << "              state <= state_";
										ss << write_conditionally_next_state(Module_name, Next_state);
										ss << WS << "             ELSE" << endl;
										ss << WS << "              " << Called_module_name << "_start_int <= '1';" << endl;
										ss << WS << "              state <= state_" << State << ";" << endl;
										ss << WS << "             END IF;" << endl;
										ss << WS << "           ELSIF " << Called_module_name << "_busy = '1' AND " << Called_module_name << "_start_int = '1'	THEN   -- when it begins" << endl;
										ss << WS << "            " << Called_module_name << "_start_int <= '0';" << endl;
										ss << WS << "            state <= state_" << State << ";" << endl;
										ss << WS << "           ELSIF " << Called_module_name << "_done = '1' 	THEN   -- when it is completed then read the results" << endl;
										ss << print_call_output_par_assignments_parcs(Module_name, vecOp, "");
										ss << WS << "            " << Called_module_name << "_start_int <= '0';" << endl;
										ss << WS << "            IF " << Called_module_name << "_results_read_int = '0' THEN  -- if it is done then indicate that the results are read" << endl;
										ss << WS << "             " << Called_module_name << "_results_read_int <= '1';" << endl;
										ss << WS << "             state <= state_" << State << ";" << endl;
										ss << WS << "            ELSIF ";
										ss << WS << Called_module_name << "_results_read_int" << " = '1'";
										ss << WS << "  THEN -- all calls are synchronized and completed " << endl;
										ss << WS << "             ";
										ss << WS << Called_module_name << "_results_read_int" << " <= '0';" << endl;
										ss << WS << "             state <= state_";
										ss << write_conditionally_next_state(Module_name, Next_state);
										ss << WS << "            END IF;" << endl;
										ss << WS << "           ELSE " << endl;
										ss << WS << "            state <= state_" << State << ";" << endl;
										ss << WS << "           END IF; " << endl;
									}
								}
							}
						}
					}
				}
				else if (HT.findfact("prog_stmt(" + Module_name + "," + to_string(Operation) + ",_,109,0,_,0,_)"))
				{
					Call_entry = stoi(returnpar(HT.findandreturn("prog_stmt(" + Module_name + "," + to_string(Operation) + ",_,109,0,_,0,_)"), 6));
					if (HT.findfact("call_stmt(" + Module_name + "," + to_string(Call_entry) + ",*)"))
					{
						Called_module_entry = stoi(returnpar(HT.findandreturn("call_stmt(" + Module_name + "," + to_string(Call_entry) + ",*)"), 3));
						Actual_params = returnVec(makeInstanceOf(HT.findandreturn("call_stmt(" + Module_name + "," + to_string(Call_entry) + ",*)")), 1);
						if (HT.findfact("hierarchy_part(" + to_string(Called_module_entry) + ",_,_,\"libpart\"," + to_string(Called_module_entry) + ",_,_)"))
						{
							Called_module_name = returnpar(HT.findandreturn("hierarchy_part(" + to_string(Called_module_entry) + ",_,_,\"libpart\"," + to_string(Called_module_entry) + ",_,_)"), 2);
							if (custom_block(Called_module_name))
							{
								ss << WS;
								ss << " ------ this is a call to custom block : " << Called_module_name << " -----" << endl;
								ss << write_cus_block_call_input_var_assignments(Module_name, Called_module_name, 1, Actual_params, WS, 0, &emptv, "vhdl");
								ss << write_block_call(Called_module_name, 2, WS) << endl;
								ss << write_cus_block_call_output_var_assignments(Module_name, Called_module_name, 1, Actual_params, WS);
							}
						}
					}
				}
				else if (HT.findfact("prog_stmt(" + Module_name + "," + to_string(Operation) + ",_,109,0,_,_,_)"))
				{
					Call_entry = stoi(returnpar(HT.findandreturn("prog_stmt(" + Module_name + "," + to_string(Operation) + ",_,109,0,_,_,_)"), 6));
					Res_entry = stoi(returnpar(HT.findandreturn("prog_stmt(" + Module_name + "," + to_string(Operation) + ",_,109,0,_,_,_)"), 7));
					if (Res_entry > 0)
					{
						if (HT.findfact("data_stmt(" + Module_name + ",_,"+to_string(Res_entry)+",_,_,_)"))
						{
							Res_name = returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Res_entry) + ",_,_,_)"), 2);
							Res_type = stoi(returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Res_entry) + ",_,_,_)"), 4));
							if (!HT.findfact("type_def(" + to_string(Res_type) + ",_,_,_,_,\"vectorarray_t\",_,_,1)"))
							{
								if (HT.findfact("call_stmt(" + Module_name + "," + to_string(Call_entry) + ",*)"))
								{
									Called_module_entry = stoi(returnpar(HT.findandreturn("call_stmt(" + Module_name + "," + to_string(Call_entry) + ",*)"), 3));
									Actual_params = returnVec(makeInstanceOf(HT.findandreturn("call_stmt(" + Module_name + "," + to_string(Call_entry) + ",*)")), 1);
									if (HT.findfact("hierarchy_part(" + to_string(Called_module_entry) + ",_,_,\"libpart\"," + to_string(Called_module_entry) + ",_,_)"))
									{
										Called_module_name = returnpar(HT.findandreturn("hierarchy_part(" + to_string(Called_module_entry) + ",_,_,\"libpart\"," + to_string(Called_module_entry) + ",_,_)"), 2);
										if (custom_block(Called_module_name))
										{
											ss << WS;
											ss << " ------ this is a call to custom block : " << Called_module_name << " -----" << endl;
											ss << write_cus_block_call_input_var_assignments(Module_name, Called_module_name, 1, Actual_params, WS, 0, &emptv, "vhdl");
											ss << write_block_call(Called_module_name, 2, WS) << endl;
											ss << WS << Res_name << " <= " << Called_module_name << "_" << Called_module_name << "_var; -- default function output" << endl;
										}
									}
								}
							}
							else if (HT.findfact("type_def(" + to_string(Res_type) + ",_,_,_,_,\"vectorarray_t\",_,_,1)"))
							{
								if (HT.findfact("call_stmt(" + Module_name + "," + to_string(Call_entry) + ",*)"))
								{
									Called_module_entry = stoi(returnpar(HT.findandreturn("call_stmt(" + Module_name + "," + to_string(Call_entry) + ",*)"), 3));
									Actual_params = returnVec(makeInstanceOf(HT.findandreturn("call_stmt(" + Module_name + "," + to_string(Call_entry) + ",*)")), 1);
									if (HT.findfact("hierarchy_part(" + to_string(Called_module_entry) + ",_,_,\"libpart\"," + to_string(Called_module_entry) + ",_,_)"))
									{
										Called_module_name = returnpar(HT.findandreturn("hierarchy_part(" + to_string(Called_module_entry) + ",_,_,\"libpart\"," + to_string(Called_module_entry) + ",_,_)"), 2);
										if (custom_block(Called_module_name))
										{
											ss << WS;
											ss << " ------ this is a call to custom block : " << Called_module_name << " -----" << endl;
											ss << write_cus_block_call_input_var_assignments(Module_name, Called_module_name, 1, Actual_params, WS, 0, &emptv, "vhdl");
											ss << write_block_call(Called_module_name, 2, WS) << endl;
											ss << WS << Res_name << " <= " << Called_module_name << "_" << Called_module_name << "_var; -- default function output" << endl;
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
	else if (HDL == "verilog")
	{
		if (int1 == 1)
		{
			if (HT.findfact("new_schedule(*)"))
			{
				New_schedule = returnpar(HT.findandreturn("new_schedule(*)"), 1);
				if (HT.findfact("hdl_style(\"verilog\")"))
				{
					if (HT.findfact("prog_stmt(" + Module_name + "," + to_string(Operation) + ",_,109,0,_,_,_)"))
					{
						Call_entry = stoi(returnpar(HT.findandreturn("prog_stmt(" + Module_name + "," + to_string(Operation) + ",_,109,0,_,_,_)"), 6));
						if (HT.findfact("call_stmt(" + Module_name + "," + to_string(Call_entry) + ",*)"))
						{
							Called_module_entry = stoi(returnpar(HT.findandreturn("call_stmt(" + Module_name + "," + to_string(Call_entry) + ",*)"), 3));
							if (HT.findfact("hierarchy_part(" + to_string(Called_module_entry) + ",_,_,\"libpart\"," + to_string(Called_module_entry) + ",_,_)"))
							{
								Called_module_name = returnpar(HT.findandreturn("hierarchy_part(" + to_string(Called_module_entry) + ",_,_,\"libpart\"," + to_string(Called_module_entry) + ",_,_)"), 2);
								if (!custom_block(Called_module_name))
								{
									read_current_depth(&CurrentDepth);
									if (HT.findfact("operation_order(" + Module_name + ",\"parcsif\"," + to_string(State) + "," + to_string(Operation) + "," + to_string(Called_module_entry) + ",*)"))
									{
										Same_order = stoi(returnpar(HT.findandreturn("operation_order(" + Module_name + ",\"parcsif\"," + to_string(State) + "," + to_string(Operation) + "," + to_string(Called_module_entry) + ",*)"), 6));
										Same_total = stoi(returnpar(HT.findandreturn("operation_order(" + Module_name + ",\"parcsif\"," + to_string(State) + "," + to_string(Operation) + "," + to_string(Called_module_entry) + ",*)"), 7));
										Total_order = stoi(returnpar(HT.findandreturn("operation_order(" + Module_name + ",\"parcsif\"," + to_string(State) + "," + to_string(Operation) + "," + to_string(Called_module_entry) + ",*)"), 9));
										Gross = stoi(returnpar(HT.findandreturn("operation_order(" + Module_name + ",\"parcsif\"," + to_string(State) + "," + to_string(Operation) + "," + to_string(Called_module_entry) + ",*)"), 10));
										if (HT.findfact("max_parallel_call_order(" + Module_name + ",\"parcsif\"," + to_string(Called_module_entry) + ",*)"))
										{
											Max_order = stoi(returnpar(HT.findandreturn("max_parallel_call_order(" + Module_name + ",\"parcsif\"," + to_string(Called_module_entry) + ",*)"), 4));
											if (Total_order > 1)
											{
												make_order_string(Same_order, Same_total, &Order);
												ss << WS;
												ss << WS << " //------ this is a call to module : " << Called_module_name << " -----" << endl;
												ss << print_call_input_par_assignments_parcs(Module_name, vecOp, Order);
												ss << WS << "           if ((" << Called_module_name << Order << "_busy == 1'b0) && (" << Called_module_name << Order << "_done == 1'b0))" << endl;
												ss << WS << "            if (" << Called_module_name << Order << "_results_read_int == 1'b1) " << endl;
												ss << WS << "             begin" << endl;
												ss << WS << "              if (" << endl;
												ss << write_polymorfic_IO_exression(Module_name, New_schedule, State, Called_module_name, "results_read_int", 1, Gross, "                                ", " && ", " == 1'b1", 1, 1);
												ss << ")";
												ss << WS << "               begin" << endl;
												ss << write_polymorfic_IO_exression(Module_name, New_schedule, State, Called_module_name, "start_int", 1, Gross, "                                ", "", " <= 1'b0;", 1, 0);
												ss << WS << "                ";
												ss << write_polymorfic_IO_exression(Module_name, New_schedule, State, Called_module_name, "results_read_int", 1, Gross, "                                ", "", " <= 1'b0;", 1, 0);
												HT.concat(WS, "   ", &WS1);
												ss << write_next_state_conditionally(WS1, CurrentDepth, Next_state);
												ss << WS << "               end" << endl;
												ss << WS << "             end" << endl;
												ss << WS << "            else" << endl;
												ss << WS << "             begin" << endl;
												ss << WS << "              " << Called_module_name << Order << "_start_int <= 1'b1;" << endl;
												ss << WS << "              state_var[" << CurrentDepth << "] = state_" << State << ";" << endl;
												ss << WS << "             end" << endl;
												ss << WS << "           else if ((" << Called_module_name << Order << "_busy == 1'b1) && (" << Called_module_name << Order << "_start_int == 1'b1)) // when it begins" << endl;
												ss << WS << "            begin" << endl;
												ss << WS << "             " << Called_module_name << Order << "_start_int <= 1'b0;" << endl;
												ss << WS << "              state_var[" << CurrentDepth << "] = state_" << State << ";" << endl;
												ss << WS << "            end" << endl;
												ss << WS << "           else if (" << Called_module_name << Order << "_done == 1'b1) // when it is completed then read the results" << endl;
												ss << WS << "            begin" << endl;
												ss << print_call_output_par_assignments_parcs(Module_name, vecOp, Order);
												ss << WS << "             " << Called_module_name << Order << "_start_int <= 1'b0;" << endl;
												ss << WS << "              if (" << Called_module_name << Order << "_results_read_int == 1'b0)  //if it is done then indicate that the results are read" << endl;
												ss << WS << "               begin" << endl;
												ss << WS << "                " << Called_module_name << Order << "_results_read_int <= 1'b1;" << endl;
												ss << WS << "                 state_var[" << CurrentDepth << "] = state_" << State << ";" << endl;
												ss << WS << "               end" << endl;
												ss << WS << "              else if (";
												ss << write_polymorfic_IO_exression(Module_name, New_schedule, State, Called_module_name, "results_read_int", 1, Gross, "                                        ", " && ", " == 1'b1", 1, 1);
												ss << ")";
												ss << WS << "               begin    // all calls are synchronized and completed " << endl;
												ss << WS << "              ";
												ss << write_polymorfic_IO_exression(Module_name, New_schedule, State, Called_module_name, "results_read_int", 1, Gross, "                                        ", "", " <= 1'b0;", 1, 0);
												ss << write_next_state_conditionally(WS, CurrentDepth, Next_state) << endl;
												ss << WS << "               end" << endl;
												ss << WS << "            end" << endl;
												ss << WS << "           else " << endl;
												ss << WS << "            state_var[" << CurrentDepth << "] = state_" << State << ";" << endl;
												ss << write_total_order_assignment_conditional(WS, Total_order, CurrentDepth);
											}
										}
									}
								}
							}
						}
					}
				}
			}
			else if (HT.findfact("hdl_style(\"verilog\")"))
			{
				if (HT.findfact("prog_stmt(" + Module_name + "," + to_string(Operation) + ",_,109,0,_,_,_)"))
				{
					Call_entry = stoi(returnpar(HT.findandreturn("prog_stmt(" + Module_name + "," + to_string(Operation) + ",_,109,0,_,_,_)"), 6));
					if (HT.findfact("call_stmt(" + Module_name + "," + to_string(Call_entry) + ",*)"))
					{
						Called_module_entry = stoi(returnpar(HT.findandreturn("call_stmt(" + Module_name + "," + to_string(Call_entry) + ",*)"), 3));
						if (HT.findfact("hierarchy_part(" + to_string(Called_module_entry) + ",_,_,\"libpart\"," + to_string(Called_module_entry) + ",_,_)"))
						{
							Called_module_name = returnpar(HT.findandreturn("hierarchy_part(" + to_string(Called_module_entry) + ",_,_,\"libpart\"," + to_string(Called_module_entry) + ",_,_)"), 2);
							if (!custom_block(Called_module_name))
							{
								read_current_depth(&CurrentDepth);
								if (HT.findfact("operation_order(" + Module_name + ",\"parcsif\"," + to_string(State) + "," + to_string(Operation) + "," + to_string(Called_module_entry) + ",*)"))
								{
									Total_order = stoi(returnpar(HT.findandreturn("operation_order(" + Module_name + ",\"parcsif\"," + to_string(State) + "," + to_string(Operation) + "," + to_string(Called_module_entry) + ",*)"), 9));
									if (HT.findfact("max_parallel_call_order(" + Module_name + ",\"parcsif\"," + to_string(Called_module_entry) + ",*)"))
									{
										Max_order = stoi(returnpar(HT.findandreturn("max_parallel_call_order(" + Module_name + ",\"parcsif\"," + to_string(Called_module_entry) + ",*)"), 4));
										if (Total_order == 1)
										{
											if (Max_order == 1)
											{
												ss << WS;
												ss << WS << " //------ this is a call to module : " << Called_module_name << " -----" << endl;
												ss << print_call_input_par_assignments_parcs(Module_name, vecOp, "");
												ss << WS << "           if ((" << Called_module_name << "_busy == 1'b0) && (" << Called_module_name << "_done == 1'b0))" << endl;
												ss << WS << "            if (" << Called_module_name << "_results_read_int == 1'b1) " << endl;
												ss << WS << "             begin" << endl;
												ss << WS << "              " << Called_module_name << "_start_int <= 1'b0;" << endl;
												ss << WS << "              " << Called_module_name << "_results_read_int <= 1'b0;" << endl;
												ss << WS << "              state <= state_";
												ss << write_conditionally_next_state(Module_name, Next_state);
												ss << WS << "             end" << endl;
												ss << WS << "            else" << endl;
												ss << WS << "             begin" << endl;
												ss << WS << "              " << Called_module_name << "_start_int <= 1'b1;" << endl;
												ss << WS << "              state <= state_" << State << ";" << endl;
												ss << WS << "             end" << endl;
												ss << WS << "           else if ((" << Called_module_name << "_busy == 1'b1) && (" << Called_module_name << "_start_int == 1'b1)) " << endl;
												ss << WS << "            begin" << endl;
												ss << WS << "             " << Called_module_name << "_start_int <= 1'b0;" << endl;
												ss << WS << "              state <= state_" << State << ";" << endl;
												ss << WS << "            end" << endl;
												ss << WS << "           else if (" << Called_module_name << "_done == 1'b1) // when it is completed then read the results" << endl;
												ss << WS << "            begin" << endl;
												ss << print_call_output_par_assignments_parcs(Module_name, vecOp, "");
												ss << WS << "             " << Called_module_name << "_start_int <= 1'b0;" << endl;
												ss << WS << "              if (" << Called_module_name << "_results_read_int == 1'b0)  //if it is done then indicate that the results are read" << endl;
												ss << WS << "               begin" << endl;
												ss << WS << "                " << Called_module_name << "_results_read_int <= 1'b1;" << endl;
												ss << WS << "                state <= state_" << State << ";" << endl;
												ss << WS << "               end" << endl;
												ss << WS << "              else // if (" << Called_module_name << "_results_read_int == 1'b1) " << endl;
												ss << WS << "               begin    // all calls are synchronized and completed " << endl;
												ss << WS << "                " << Called_module_name << "_results_read_int <= 1'b0;" << endl;
												ss << WS << "                 state <= state_";
												ss << write_conditionally_next_state(Module_name, Next_state);
												ss << WS << "               end" << endl;
												ss << WS << "            end" << endl;
												ss << WS << "           else " << endl;
												ss << WS << "            state <= state_" << State << ";" << endl;
											}
											if (Max_order > 1)
											{
												ss << WS;
												ss << WS << " //------ this is a call to module : " << Called_module_name << " -----" << endl;
												ss << print_call_input_par_assignments_parcs(Module_name, vecOp, "_1");
												ss << WS << "           if ((" << Called_module_name << "_1_busy == 1'b0) && (" << Called_module_name << "_1_done == 1'b0))" << endl;
												ss << WS << "            if (" << Called_module_name << "_1_results_read_int == 1'b1) " << endl;
												ss << WS << "             begin" << endl;
												ss << WS << "              " << Called_module_name << "_1_start_int <= 1'b0;" << endl;
												ss << WS << "              " << Called_module_name << "_1_results_read_int <= 1'b0;" << endl;
												ss << WS << "              state <= state_";
												ss << write_conditionally_next_state(Module_name, Next_state);
												ss << WS << "             end" << endl;
												ss << WS << "            else" << endl;
												ss << WS << "             begin" << endl;
												ss << WS << "              " << Called_module_name << "_1_start_int <= 1'b1;" << endl;
												ss << WS << "              state <= state_" << State << ";" << endl;
												ss << WS << "             end" << endl;
												ss << WS << "           else if ((" << Called_module_name << "_1_busy == 1'b1) && (" << Called_module_name << "_1_start_int == 1'b1)) " << endl;
												ss << WS << "            begin" << endl;
												ss << WS << "             " << Called_module_name << "_1_start_int <= 1'b0;" << endl;
												ss << WS << "              state <= state_" << State << ";" << endl;
												ss << WS << "            end" << endl;
												ss << WS << "           else if (" << Called_module_name << "_1_done == 1'b1) // when it is completed then read the results" << endl;
												ss << WS << "            begin" << endl;
												ss << print_call_output_par_assignments_parcs(Module_name, vecOp, "_1");
												ss << WS << "             " << Called_module_name << "_1_start_int <= 1'b0;" << endl;
												ss << WS << "              if (" << Called_module_name << "_1_results_read_int == 1'b0)  //if it is done then indicate that the results are read" << endl;
												ss << WS << "               begin" << endl;
												ss << WS << "                " << Called_module_name << "_1_results_read_int <= 1'b1;" << endl;
												ss << WS << "                state <= state_" << State << ";" << endl;
												ss << WS << "               end" << endl;
												ss << WS << "              else // if (" << Called_module_name << "_1_results_read_int == 1'b1) " << endl;
												ss << WS << "               begin    // all calls are synchronized and completed " << endl;
												ss << WS << "                " << Called_module_name << "_1_results_read_int <= 1'b0;" << endl;
												ss << WS << "                 state <= state_";
												ss << write_conditionally_next_state(Module_name, Next_state);
												ss << WS << "               end" << endl;
												ss << WS << "            end" << endl;
												ss << WS << "           else " << endl;
												ss << WS << "            state <= state_" << State << ";" << endl;
											}
										}
									}
								}
							}
						}
					}
				}
				else if (HT.findfact("prog_stmt(" + Module_name + "," + to_string(Operation) + ",_,109,0,_,0,_)"))
				{
					Call_entry = stoi(returnpar(HT.findandreturn("prog_stmt(" + Module_name + "," + to_string(Operation) + ",_,109,0,_,0,_)"), 6));
					if (HT.findfact("call_stmt(" + Module_name + "," + to_string(Call_entry) + ",*)"))
					{
						Called_module_entry = stoi(returnpar(HT.findandreturn("call_stmt(" + Module_name + "," + to_string(Call_entry) + ",*)"), 3));
						if (HT.findfact("hierarchy_part(" + to_string(Called_module_entry) + ",_,_,\"libpart\"," + to_string(Called_module_entry) + ",_,_)"))
						{
							Called_module_name = returnpar(HT.findandreturn("hierarchy_part(" + to_string(Called_module_entry) + ",_,_,\"libpart\"," + to_string(Called_module_entry) + ",_,_)"), 2);
							if (custom_block(Called_module_name))
							{
								ss << WS;
								ss << " //------ this is a call to custom block : " << Called_module_name << " -----" << endl;
								ss << write_custom_call_actuals(Module_name, Call_entry, "verilog") << endl;
							}
						}
					}
				}
				else if (HT.findfact("prog_stmt(" + Module_name + "," + to_string(Operation) + ",_,109,0,_,_,_)"))
				{
					Call_entry = stoi(returnpar(HT.findandreturn("prog_stmt(" + Module_name + "," + to_string(Operation) + ",_,109,0,_,_,_)"), 6));
					Res_entry = stoi(returnpar(HT.findandreturn("prog_stmt(" + Module_name + "," + to_string(Operation) + ",_,109,0,_,_,_)"), 7));
					if (Res_entry > 0)
					{
						if (HT.findfact("data_stmt(" + Module_name + ",_," + to_string(Res_entry) + ",_,_,_)"))
						{
							if (HT.findfact("call_stmt(" + Module_name + "," + to_string(Call_entry) + ",_,_)"))
							{
								Called_module_entry = stoi(returnpar(HT.findandreturn("call_stmt(" + Module_name + "," + to_string(Call_entry) + ",_,_)"), 3));
								if (HT.findfact("hierarchy_part(" + to_string(Called_module_entry) + ",_,_,\"libpart\"," + to_string(Called_module_entry) + ",_,_)"))
								{
									Called_module_name = returnpar(HT.findandreturn("hierarchy_part(" + to_string(Called_module_entry) + ",_,_,\"libpart\"," + to_string(Called_module_entry) + ",_,_)"), 2);
									if(custom_block(Called_module_name))
									{
										ss << WS;
										ss << " //------ this is a call to custom block : " << Called_module_name << " -----" << endl;
										ss << write_custom_call_actuals(Module_name, Call_entry, "verilog") << endl;
									}
								}
							}
						}
					}
				}
			}
		}
	}
	else if (HDL == "c")
	{
		if (int1 == 1)
		{
			if (HT.findfact("hdl_style(\"c\")"))
			{
				if (HT.findfact("prog_stmt(" + Module_name + "," + to_string(Operation) + ",_,109,0,_,0,_)"))
				{
					Call_entry = stoi(returnpar(HT.findandreturn("prog_stmt(" + Module_name + "," + to_string(Operation) + ",_,109,0,_,0,_)"), 6));
					if (HT.findfact("call_stmt(" + Module_name + "," + to_string(Call_entry) + ",*)"))
					{
						Called_module_entry = stoi(returnpar(HT.findandreturn("call_stmt(" + Module_name + "," + to_string(Call_entry) + ",*)"), 3));
						if (HT.findfact("hierarchy_part(" + to_string(Called_module_entry) + ",_,_,\"libpart\"," + to_string(Called_module_entry) + ",_,_)"))
						{
							ss << write_custom_call_actuals(Module_name, Call_entry, "c") << endl;
						}
					}
				}
				else if (HT.findfact("prog_stmt(" + Module_name + "," + to_string(Operation) + ",_,109,0,_,_,_)"))
				{
					Call_entry = stoi(returnpar(HT.findandreturn("prog_stmt(" + Module_name + "," + to_string(Operation) + ",_,109,0,_,_,_)"), 6));
					Res_entry = stoi(returnpar(HT.findandreturn("prog_stmt(" + Module_name + "," + to_string(Operation) + ",_,109,0,_,_,_)"), 7));
					if (Res_entry > 0)
					{
						if (HT.findfact("data_stmt(" + Module_name + ",_," + to_string(Res_entry) + ",_,_,_)"))
						{
							if (HT.findfact("call_stmt(" + Module_name + "," + to_string(Call_entry) + ",_,_)"))
							{
								Called_module_entry = stoi(returnpar(HT.findandreturn("call_stmt(" + Module_name + "," + to_string(Call_entry) + ",_,_)"), 3));
								if (HT.findfact("hierarchy_part(" + to_string(Called_module_entry) + ",_,_,\"libpart\"," + to_string(Called_module_entry) + ",_,_)"))
								{
									ss << write_custom_call_actuals(Module_name, Call_entry, "c") << endl;
								}
							}
						}
					}
				}
			}
		}
	}
	return ss.str();
}

void read_current_depth(int* CurrentDepth)
{
	if (HT.findfact("complex_next_state_operation_depth(*)"))
		*CurrentDepth = stoi(returnpar(HT.findandreturn("complex_next_state_operation_depth(*)"), 1));
	else if (!HT.findfact("complex_next_state_operation_depth(*)"))
		*CurrentDepth = 0;
}

string print_call_input_par_assignments_parcs(string Module_name, vector<int> List, string Order)
{
	stringstream ss;
	if (List.empty())
	{
		print_call_input_par_assignment_parcs(Module_name, List.front(), 1, Order);
		List.erase(List.begin());
		print_call_input_par_assignments_parcs(Module_name, List, Order);
	}
	return ss.str();
}

string print_call_input_par_assignment_parcs(string Module_name, int Head_op, int Par_entry, string Order)
{
	stringstream ss;
	int Next_entry;
	if (HT.findfact("top_level_call(" + to_string(Par_entry) + ",_," + Module_name + ",_,_,_,_,_,_,_,_)"))
	{
		print_call_input_par_assignment_parcs_core(Module_name, Head_op, Par_entry, Order, &Next_entry);
		print_call_input_par_assignment_parcs(Module_name, Head_op, Next_entry, Order);
	}
	return ss.str();
}

string print_call_input_par_assignment_parcs_core(string Module_name, int Head_op, int Par_entry, string Order, int* Next_entry)
{
	stringstream ss;
	int Call_entry, Called_entry;
	string Called_module_name, Actual_param_name, Formal_param_name;
	if (HT.findfact("top_level_call(" + to_string(Par_entry) + ",_," + Module_name + ",_,_,_,_,_,_,_,\"par_in\")"))
	{
		*Next_entry = Par_entry + 1;
	}
	else if (HT.findfact("top_level_call(" + to_string(Par_entry) + ",_," + Module_name + ",_,_,_,_,_,_,_,\"par_inout\")"))
	{
		*Next_entry = Par_entry + 1;
	}
	else if (HT.findfact("prog_stmt(" + Module_name + "," + to_string(Head_op) + ",_,109,0,_,_,_)"))
	{
		Call_entry = stoi(returnpar(HT.findandreturn("prog_stmt(" + Module_name + "," + to_string(Head_op) + ",_,109,0,_,_,_)"), 6));
		if (!HT.findfact("top_level_call(" + to_string(Par_entry) + "," + to_string(Call_entry) + "," + Module_name + ",_,_,_,_,_,_,_,\"par_out\")"))
		{
			*Next_entry = Par_entry + 1;
		}
	}
	else if (Order == "")
	{
		if (HT.findfact("prog_stmt(" + Module_name + "," + to_string(Head_op) + ",_,109,0,_,_,_)"))
		{
			Call_entry = stoi(returnpar(HT.findandreturn("prog_stmt(" + Module_name + "," + to_string(Head_op) + ",_,109,0,_,_,_)"), 6));
			if (HT.findfact("call_stmt(" + Module_name + "," + to_string(Call_entry) + ",*)"))
			{
				Called_entry = stoi(returnpar(HT.findandreturn("call_stmt(" + Module_name + "," + to_string(Call_entry) + ",*)"), 3));
				if (HT.findfact("top_level_call(" + to_string(Par_entry) + "," + to_string(Call_entry) + "," + Module_name + ",_,_,"+to_string(Called_entry)+",_,_,_,_,\"par_out\")"))
				{
					Called_module_name = returnpar(HT.findandreturn("top_level_call(" + to_string(Par_entry) + "," + to_string(Call_entry) + "," + Module_name + ",_,_," + to_string(Called_entry) + ",_,_,_,_,\"par_out\")"), 5);
					Actual_param_name = returnpar(HT.findandreturn("top_level_call(" + to_string(Par_entry) + "," + to_string(Call_entry) + "," + Module_name + ",_,_," + to_string(Called_entry) + ",_,_,_,_,\"par_out\")"), 7);
					Formal_param_name = returnpar(HT.findandreturn("top_level_call(" + to_string(Par_entry) + "," + to_string(Call_entry) + "," + Module_name + ",_,_," + to_string(Called_entry) + ",_,_,_,_,\"par_out\")"), 9);
					if (!HT.findfact("mem_port(_,_," + Module_name + "," + Actual_param_name + ",_,_,_,_,_,_,_,_,_)"))
					{
						ss << "           " << Called_module_name << "_";
						ss << Formal_param_name << " <= " << Actual_param_name << ";" << endl;
						*Next_entry = Par_entry + 1;
					}
					else if (HT.findfact("mem_port(_,_," + Module_name + "," + Actual_param_name + ",_,_,_,_,_,_,_,_,_)"))
					{
						*Next_entry = Par_entry + 1;
					}
				}
			}
		}
	}
	else if (Order != "")
	{
		if (HT.findfact("prog_stmt(" + Module_name + "," + to_string(Head_op) + ",_,109,0,_,_,_)"))
		{
			Call_entry = stoi(returnpar(HT.findandreturn("prog_stmt(" + Module_name + "," + to_string(Head_op) + ",_,109,0,_,_,_)"), 6));
			if (HT.findfact("call_stmt(" + Module_name + "," + to_string(Call_entry) + ",*)"))
			{
				Called_entry = stoi(returnpar(HT.findandreturn("call_stmt(" + Module_name + "," + to_string(Call_entry) + ",*)"), 3));
				if (HT.findfact("top_level_call(" + to_string(Par_entry) + "," + to_string(Call_entry) + "," + Module_name + ",_,_," + to_string(Called_entry) + ",_,_,_,_,\"par_out\")"))
				{
					Called_module_name = returnpar(HT.findandreturn("top_level_call(" + to_string(Par_entry) + "," + to_string(Call_entry) + "," + Module_name + ",_,_," + to_string(Called_entry) + ",_,_,_,_,\"par_out\")"), 5);
					Actual_param_name = returnpar(HT.findandreturn("top_level_call(" + to_string(Par_entry) + "," + to_string(Call_entry) + "," + Module_name + ",_,_," + to_string(Called_entry) + ",_,_,_,_,\"par_out\")"), 7);
					Formal_param_name = returnpar(HT.findandreturn("top_level_call(" + to_string(Par_entry) + "," + to_string(Call_entry) + "," + Module_name + ",_,_," + to_string(Called_entry) + ",_,_,_,_,\"par_out\")"), 9);
					if (!HT.findfact("mem_port(_,_," + Module_name + "," + Actual_param_name + ",_,_,_,_,_,_,_,_,_)"))
					{
						ss << "           " << Called_module_name << Order << "_";
						ss << Formal_param_name << " <= " << Actual_param_name << ";" << endl;
						*Next_entry = Par_entry + 1;
					}
					else if (HT.findfact("mem_port(_,_," + Module_name + "," + Actual_param_name + ",_,_,_,_,_,_,_,_,_)"))
					{
						*Next_entry = Par_entry + 1;
					}
				}
			}
		}
	}
	return ss.str();
}

string write_conditionally_next_state(string Module, int Next_state)
{
	stringstream ss;
	string Schedule;
	if (HT.findfact("new_schedule(*)"))
	{
		Schedule = returnpar(HT.findandreturn("new_schedule(*)"), 1);
		if (HT.findfact("state(" + Module + "," + Schedule + "," + to_string(Next_state) + ",*)"))
		{
			ss << Next_state << ";" << endl;
		}
	}
	else if (HT.findfact("hdl_style(\"vhdl\")"))
	{
		if (HT.findfact("new_schedule(*)"))
		{
			Schedule = returnpar(HT.findandreturn("new_schedule(*)"), 1);
			if (!HT.findfact("state(" + Module + "," + Schedule + "," + to_string(Next_state) + ",*)"))
			{
				ss << "0;" << endl;
				ss << "                           done_int <= '1';   -- processing finished, results are ready !!!" << endl;
				ss << "                           busy <= '0'; " << endl;
			}
		}
	}
	else if (HT.findfact("hdl_style(\"verilog\")"))
	{
		if (HT.findfact("new_schedule(*)"))
		{
			Schedule = returnpar(HT.findandreturn("new_schedule(*)"), 1);
			if (!HT.findfact("state(" + Module + "," + Schedule + "," + to_string(Next_state) + ",*)"))
			{
				ss << "0;" << endl;
				ss << "                           done_int <= 1'b1;   //-- processing finished, results are ready !!!" << endl;
				ss << "                           busy <= 1'b0; " << endl;
			}
		}
	}
	return ss.str();
}

string print_call_output_par_assignments_parcs(string Module_name, vector<int> List, string Order)
{
	stringstream ss;
	if (!List.empty())
	{
		ss << print_call_output_par_assignment_parcs(Module_name, List.front(), 1, Order);
		List.erase(List.begin());
		ss << print_call_output_par_assignments_parcs(Module_name, List, Order);
	}
	return ss.str();
}

string print_call_output_par_assignment_parcs(string Module_name, int Head_op, int Par_entry, string Order)
{
	stringstream ss;
	int Next_entry;
	if (HT.findfact("top_level_call(" + to_string(Par_entry) + ",_," + Module_name + ",_,_,_,_,_,_,_,_)"))
	{
		ss << print_call_output_par_assignment_parcs_core(Module_name, Head_op, Par_entry, Order, &Next_entry);
		ss << print_call_output_par_assignment_parcs(Module_name, Head_op, Next_entry, Order);
	}
	return ss.str();
}

string print_call_output_par_assignment_parcs_core(string Module_name, int Head_op, int Par_entry, string Order, int* Next_entry)
{
	stringstream ss;
	int Call_entry, Target_entry, Called_entry, Actual_par_entry, Type_entry;
	string Called_module_name, Actual_param_name, Formal_param_name, Formalname1, Formalname2, Formalname3;
	if (HT.findfact("top_level_call(" + to_string(Par_entry) + ",_," + Module_name + ",_,_,_,_,_,_,_,\"par_out\")"))
	{
		*Next_entry = Par_entry + 1;
	}
	else if (HT.findfact("top_level_call(" + to_string(Par_entry) + ",_," + Module_name + ",_,_,_,_,_,_,_,\"par_inout\")"))
	{
		*Next_entry = Par_entry + 1;
	}
	else if (HT.findfact("hdl_style(\"vhdl\")"))
	{
		if (HT.findfact("prog_stmt(" + Module_name + "," + to_string(Head_op) + ",_,109,0,_,_,_)"))
		{
			Call_entry = stoi(returnpar(HT.findandreturn("prog_stmt(" + Module_name + "," + to_string(Head_op) + ",_,109,0,_,_,_)"), 6));
			Target_entry = stoi(returnpar(HT.findandreturn("prog_stmt(" + Module_name + "," + to_string(Head_op) + ",_,109,0,_,_,_)"), 7));
			if (HT.findfact("call_stmt(" + Module_name + "," + to_string(Call_entry) + ",*)"))
			{
				Called_entry = stoi(returnpar(HT.findandreturn("call_stmt(" + Module_name + "," + to_string(Call_entry) + ",*)"), 3));
				if (HT.findfact("top_level_call(" + to_string(Par_entry) + "," + to_string(Call_entry) + "," + Module_name + ",_,_," + to_string(Called_entry) + ",_,_,_,_,\"par_in\")"))
				{
					Called_module_name = returnpar(HT.findandreturn("top_level_call(" + to_string(Par_entry) + "," + to_string(Call_entry) + "," + Module_name + ",_,_," + to_string(Called_entry) + ",_,_,_,_,\"par_in\")"), 5);
					Actual_param_name = returnpar(HT.findandreturn("top_level_call(" + to_string(Par_entry) + "," + to_string(Call_entry) + "," + Module_name + ",_,_," + to_string(Called_entry) + ",_,_,_,_,\"par_in\")"), 7);
					Actual_par_entry = stoi(returnpar(HT.findandreturn("top_level_call(" + to_string(Par_entry) + "," + to_string(Call_entry) + "," + Module_name + ",_,_," + to_string(Called_entry) + ",_,_,_,_,\"par_in\")"), 8));
					Formal_param_name = returnpar(HT.findandreturn("top_level_call(" + to_string(Par_entry) + "," + to_string(Call_entry) + "," + Module_name + ",_,_," + to_string(Called_entry) + ",_,_,_,_,\"par_in\")"), 9);
					HT.concat(Called_module_name, Order, &Formalname1);
					HT.concat(Formalname1, "_", &Formalname2);
					HT.concat(Formalname2, Formal_param_name, &Formalname3);
					ss << print_function_input_assignment(Module_name, Called_module_name, Actual_param_name, Actual_par_entry, Formalname3, Target_entry);
					*Next_entry = Par_entry + 1;
				}
			}
		}
	}
	else if (HT.findfact("hdl_style(\"verilog\")"))
	{
		if (HT.findfact("prog_stmt(" + Module_name + "," + to_string(Head_op) + ",_,109,0,_,_,_)"))
		{
			Call_entry = stoi(returnpar(HT.findandreturn("prog_stmt(" + Module_name + "," + to_string(Head_op) + ",_,109,0,_,_,_)"), 6));
			Target_entry = stoi(returnpar(HT.findandreturn("prog_stmt(" + Module_name + "," + to_string(Head_op) + ",_,109,0,_,_,_)"), 7));
			if (HT.findfact("call_stmt(" + Module_name + "," + to_string(Call_entry) + ",*)"))
			{
				Called_entry = stoi(returnpar(HT.findandreturn("call_stmt(" + Module_name + "," + to_string(Call_entry) + ",*)"), 3));
				if (HT.findfact("top_level_call(" + to_string(Par_entry) + "," + to_string(Call_entry) + "," + Module_name + ",_,_," + to_string(Called_entry) + ",_,_,_,_,\"par_in\")"))
				{
					Called_module_name = returnpar(HT.findandreturn("top_level_call(" + to_string(Par_entry) + "," + to_string(Call_entry) + "," + Module_name + ",_,_," + to_string(Called_entry) + ",_,_,_,_,\"par_in\")"), 5);
					Actual_param_name = returnpar(HT.findandreturn("top_level_call(" + to_string(Par_entry) + "," + to_string(Call_entry) + "," + Module_name + ",_,_," + to_string(Called_entry) + ",_,_,_,_,\"par_in\")"), 7);
					Actual_par_entry = stoi(returnpar(HT.findandreturn("top_level_call(" + to_string(Par_entry) + "," + to_string(Call_entry) + "," + Module_name + ",_,_," + to_string(Called_entry) + ",_,_,_,_,\"par_in\")"), 8));
					Formal_param_name = returnpar(HT.findandreturn("top_level_call(" + to_string(Par_entry) + "," + to_string(Call_entry) + "," + Module_name + ",_,_," + to_string(Called_entry) + ",_,_,_,_,\"par_in\")"), 9);
					HT.concat(Called_module_name, Order, &Formalname1);
					HT.concat(Formalname1, "_", &Formalname2);
					HT.concat(Formalname2, Formal_param_name, &Formalname3);
					if (HT.findfact("data_stmt(" + Called_module_name + "," + Formal_param_name + ",*)"))
					{
						Type_entry = stoi(returnpar(HT.findandreturn("data_stmt(" + Called_module_name + "," + Formal_param_name + ",*)"), 4));
						if (HT.findfact("type_def(" + to_string(Type_entry) + ",_,_,_,0,_,_,_,_)"))
						{
							ss << print_function_input_assignment(Module_name, Called_module_name, Actual_param_name, Actual_par_entry, Formalname3, Target_entry);
							*Next_entry = Par_entry + 1;
						}
					}
				}
			}
		}
	}
	return ss.str();
}

string print_function_input_assignment(string Module_name, string Called_module_name, string Actual_param_name, int Actual_par_entry, string Formal_param_name, int Target_entry)
{
	stringstream ss;
	string tmpstr;
	if (Actual_param_name == "function_output")
	{
		if (Actual_par_entry == 0)
		{
			ss << "           ";
			if (HT.findfact("data_stmt(" + Module_name + ",_," + to_string(Target_entry) + ",_,_,_)"))
			{
				tmpstr = returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Target_entry) + ",_,_,_)"), 5);
				if (!HT.findfact("mem_port(_,_," + Module_name + "," + tmpstr + ",_,_,_,_,_,_,_,_,_)"))
				{
					ss << Actual_param_name << " <= " << Formal_param_name << ";" << endl;
				}
				else if (HT.findfact("mem_port(_,_," + Module_name + "," + tmpstr + ",_,_,_,_,_,_,_,_,_)"))
				{
					return ss.str();
				}
			}
		}
	}
	if (Actual_param_name != "function_output")
	{
		if (Actual_par_entry != 0)
		{
			if (!HT.findfact("mem_port(_,_," + Module_name + "," + Actual_param_name + ",_,_,_,_,_,_,_,_,_)"))
			{
				ss << "            ";
				ss << Actual_param_name << " <= " << Formal_param_name << ";" << endl;
			}
			else if (HT.findfact("mem_port(_,_," + Module_name + "," + Actual_param_name + ",_,_,_,_,_,_,_,_,_)"))
			{
				return ss.str();
			}
		}
	}
	return ss.str();
}

string write_total_order_assignment_conditional(string WS, int Total_order, int CurrentDepth)
{
	stringstream ss;
	if (CurrentDepth >= Total_order)
	{
		if (HT.findfact("hdl_style(\"vhdl\")"))
		{
			if (Total_order == CurrentDepth)
			{
				ss << WS << "    state <= state_var(" << Total_order << ");" << endl;
			}
		}
		else if (HT.findfact("hdl_style(\"verilog\")"))
		{
			if (Total_order == CurrentDepth)
			{
				ss << WS << "    state <= state_var[" << Total_order << "];" << endl;
			}
		}
	}
	return ss.str();
}

string write_next_state_conditionally(string WS, int CurrentDepth, int Next_state)
{
	stringstream ss;
	int PreviousDepth;
	if (HT.findfact("hdl_style(\"vhdl\")"))
	{
		if (CurrentDepth == 1)
		{
			ss << WS << "              state_var(" << CurrentDepth << ") := state_0;" << endl;
			ss << WS << "              done_int <= '1';   -- processing finished, results are ready !!!" << endl;
			ss << WS << "              busy <= '0'; " << endl;
		}
		else if (CurrentDepth > 1)
		{
			PreviousDepth = CurrentDepth - 1;
			ss << WS << "              state_var(" << CurrentDepth << ") := state_var(" << PreviousDepth << ");" << endl;
			ss << WS << "              IF state_var(" << PreviousDepth << ") = state_0 THEN" << endl;
			ss << WS << "               done_int <= '1';   -- processing finished, results are ready !!!" << endl;
			ss << WS << "               busy <= '0'; " << endl;
			ss << WS << "              END IF;" << endl;
		}
	}
	if (HT.findfact("hdl_style(\"verilog\")"))
	{
		if (CurrentDepth == 1)
		{
			ss << WS << "              state_var[" << CurrentDepth << "] = state_0;" << endl;
			ss << WS << "              done_int <= 1'b1;   //-- processing finished, results are ready !!!" << endl;
			ss << WS << "              busy <= 1'b0; " << endl;
		}
		else if (CurrentDepth > 1)
		{
			PreviousDepth = CurrentDepth - 1;
			ss << WS << "              state_var[" << CurrentDepth << "] = state_var[" << PreviousDepth << "];" << endl;
			ss << WS << "              if (state_var[" << PreviousDepth << "] == state_0) begin" << endl;
			ss << WS << "               done_int <= 1'b1;   //-- processing finished, results are ready !!!" << endl;
			ss << WS << "               busy <= 1'b0; " << endl;
			ss << WS << "              end" << endl;
		}
	}
	return ss.str();
}

string write_cus_block_call_input_var_assignments(string Module_name, string Called_module_name, int Entry, vector<int> List1, string WS, int* One_after, vector<int>* Rest_params, string HDL)
{
	stringstream ss;
	int Next_entry;
	if (List1.empty())
	{
		*One_after = Entry;
	}
	else if (HT.findfact("data_stmt("+Called_module_name+",_,"+to_string(Entry)+",_,_,_)"))
	{
		ss << write_cus_block_call_input_var_assignments_core(Module_name, Called_module_name, Entry, List1, WS, HDL, &Next_entry);
		List1.erase(List1.begin());
		ss << write_cus_block_call_input_var_assignments(Module_name, Called_module_name, Next_entry, List1, WS, One_after, Rest_params, HDL);
	}
	return ss.str();
}

string  write_cus_block_call_input_var_assignments_core(string Module_name, string Called_module_name, int Entry, vector<int> List, string WS, string HDL, int* Next_entry)
{
	stringstream ss;
	string Kind;
	if (HT.findfact("data_stmt(" + Called_module_name + ",_," + to_string(Entry) + ",_,_,_)"))
	{
		Kind = returnpar(HT.findandreturn("data_stmt(" + Called_module_name + ",_," + to_string(Entry) + ",_,_,_)"), 5);
		if (!it_is_input_kind(Kind))
		{
			*Next_entry = Entry + 1;
		}
		else if (it_is_input_kind(Kind))
		{
			ss << write_cus_block_call_input_var_assignment(Module_name, Called_module_name, Entry, List.front(), WS, HDL);
			*Next_entry = Entry + 1;
		}
	}
	return ss.str();
}

bool it_is_input_kind(string str)
{
	return str == "par_in" || str == "par_inout";
}

string write_cus_block_call_input_var_assignment(string Module_name, string Called_module_name, int Entry, int Actual_param, string WS, string HDL)
{
	stringstream ss;
	string Formal_par_name, Actual_par_name;
	int Type_entry;
	if (HT.findfact("data_stmt(" + Called_module_name + ",_," + to_string(Entry) + ",_,\"var\",_)") || HT.findfact("data_stmt(" + Called_module_name + ",_," + to_string(Entry) + ",_,\"const\",_)"))
	{
		return ss.str();
	}
	if (HDL == "vhdl")
	{
		if (HT.findfact("data_stmt(" + Called_module_name + ",_,"+to_string(Entry)+",1,_,_)"))
		{
			Formal_par_name = returnpar(HT.findandreturn("data_stmt(" + Called_module_name + ",_," + to_string(Entry) + ",1,_,_)"), 2);
			if (it_is_input_kind("par_inout"))
			{
				if (HT.findfact("data_stmt(" + Module_name + ",_,"+to_string(Actual_param)+",_,_,_)"))
				{
					Actual_par_name = returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Actual_param) + ",_,_,_)"), 2);
					ss << WS << Called_module_name << "_" << Formal_par_name << "_var := " << Actual_par_name << " ; " << endl;
				}
			}
		}
		else if (HT.findfact("data_stmt(" + Called_module_name + ",_," + to_string(Entry) + ",_,_,_)"))
		{
			Formal_par_name = returnpar(HT.findandreturn("data_stmt(" + Called_module_name + ",_," + to_string(Entry) + ",_,_,_)"), 2);
			Type_entry = stoi(returnpar(HT.findandreturn("data_stmt(" + Called_module_name + ",_," + to_string(Entry) + ",_,_,_)"), 4));
			if (it_is_input_kind("par_inout"))
			{
				if (HT.findfact("data_stmt(" + Module_name + ",_," + to_string(Actual_param) + ",_,_,_)"))
				{
					Actual_par_name = returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Actual_param) + ",_,_,_)"), 2);
					if (!HT.findfact("type_def(" + to_string(Type_entry) + ",_,_,_,_,\"vectorarray_t\",_,_,1)"))
					{
						ss << WS << Called_module_name << "_" << Formal_par_name << "_var := " << Actual_par_name << " ; " << endl;
					}
					else if (HT.findfact("type_def(" + to_string(Type_entry) + ",_,_,_,_,\"vectorarray_t\",_,_,1)"))
					{
						ss << WS << Called_module_name << "_" << Formal_par_name << "_var := " << Actual_par_name << " ; " << endl;
					}
				}
			}
		}
	}
	else if (HDL == "verilog")
	{
		if (HT.findfact("data_stmt(" + Called_module_name + ",_," + to_string(Entry) + ",_,_,_)"))
		{
			Formal_par_name = returnpar(HT.findandreturn("data_stmt(" + Called_module_name + ",_," + to_string(Entry) + ",_,_,_)"), 2);
			if (it_is_input_kind("par_inout"))
			{
				if (HT.findfact("data_stmt(" + Module_name + ",_," + to_string(Actual_param) + ",_,_,_)"))
				{
					Actual_par_name = returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Actual_param) + ",_,_,_)"), 2);
					ss << WS << Called_module_name << "_" << Formal_par_name << "_var := " << Actual_par_name << " ; " << endl;
				}
			}
		}
	}
	return ss.str();
}

string write_cus_block_call_output_var_assignments(string Module_name, string Called_module_name, int Formal_entry, vector<int> List, string WS)
{
	stringstream ss;
	int Next_entry;
	if (!List.empty())
	{
		if (HT.findfact("data_stmt(" + Called_module_name + ",_," + to_string(Formal_entry) + ",_,\"var\",_)") || HT.findfact("data_stmt(" + Called_module_name + ",_," + to_string(Formal_entry) + ",_,\"const\",_)"))
		{
			return ss.str();
		}
		if (!HT.findfact("data_stmt(" + Called_module_name + ",_," + to_string(Formal_entry) + ", _,_,_)"))
		{
			return ss.str();
		}
		ss << write_cus_block_call_output_var_assignments_core(Module_name, Called_module_name, Formal_entry, List, WS, &Next_entry);
		List.erase(List.begin());
		ss << write_cus_block_call_output_var_assignments(Module_name, Called_module_name, Next_entry, List, WS);
	}
	return ss.str();
}

string write_cus_block_call_output_var_assignments_core(string Module_name, string Called_module_name, int Formal_entry, vector<int> List, string WS, int* Next_entry)
{
	stringstream ss;
	string Kind;
	if (HT.findfact("data_stmt(" + Called_module_name + ",_," + to_string(Formal_entry) + ",_,_,_)"))
	{
		Kind = returnpar(HT.findandreturn("data_stmt(" + Called_module_name + ",_," + to_string(Formal_entry) + ",_,_,_)"), 5);
		if (!it_is_output_kind(Kind))
		{
			*Next_entry = Formal_entry + 1;
		}
		else if (it_is_output_kind(Kind))
		{
			ss << write_cus_block_call_output_var_assignment(Module_name, Called_module_name, Formal_entry, List.front(), WS);
			*Next_entry = Formal_entry + 1;
		}
	}
	return ss.str();
}

bool it_is_output_kind(string str)
{
	return str == "par_out" || str == "par_inout";
}

string write_cus_block_call_output_var_assignment(string Module_name, string Called_module_name, int Formal_entry, int Actual_param, string WS)
{
	stringstream ss;
	string Formal_par_name, Kind, Actual_par_name;
	int Formal_type, Actual_type;
	if (HT.findfact("data_stmt(" + Called_module_name + ",_," + to_string(Formal_entry) + ",_,\"var\",_)") || HT.findfact("data_stmt(" + Called_module_name + ",_," + to_string(Formal_entry) + ",_,\"const\",_)"))
	{
		return ss.str();
	}
	if (HT.findfact("data_stmt(" + Called_module_name + ",_," + to_string(Formal_entry) + ",_,_,_)"))
	{
		Formal_par_name = returnpar(HT.findandreturn("data_stmt(" + Called_module_name + ",_," + to_string(Formal_entry) + ",_,_,_)"), 2);
		Formal_type = stoi(returnpar(HT.findandreturn("data_stmt(" + Called_module_name + ",_," + to_string(Formal_entry) + ",_,_,_)"), 4));
		Kind = returnpar(HT.findandreturn("data_stmt(" + Called_module_name + ",_," + to_string(Formal_entry) + ",_,_,_)"), 5);
		if (it_is_output_kind(Kind))
		{
			if (HT.findfact("data_stmt(" + Module_name + ",_," + to_string(Actual_param) + ",_,_,_)"))
			{
				Actual_par_name = returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Actual_param) + ",_,_,_)"), 2);
				Actual_type = stoi(returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Actual_param) + ",_,_,_)"), 4));
				if (Formal_type > 1)
				{
					if (!HT.findfact("type_def(" + to_string(Formal_type) + ",_,_,_,_,\"vectorarray_t\",_,_,1)"))
					{
						ss << WS << Actual_par_name << " <= " << Called_module_name << "_" << Formal_par_name << "_var ; " << endl;
					}
					else if (HT.findfact("type_def(" + to_string(Formal_type) + ",_,_,_,_,\"vectorarray_t\",_,_,1)"))
					{
						ss << WS << Actual_par_name << " <= " << Called_module_name << "_" << Formal_par_name << "_var ; " << endl;
					}
				}
				else if (Formal_type == 1)
				{
					if (Actual_type == 1)
					{
						ss << WS << Actual_par_name << " <= " << Called_module_name << "_" << Formal_par_name << "_var ; " << endl;
					}
				}
			}
		}
	}
	return ss.str();
}

string write_custom_call_actuals(string Module_name, int Call_entry, string HDL)
{
	stringstream ss;
	int Called_module_entry, Res_entry, Operation;
	string Called_module_name, WS, Res_name;
	vector<int> Actual_params;
	if (HDL == "verilog")
	{
		if (HT.findfact("hdl_style(\"verilog\")"))
		{
			if (HT.findfact("hierarchy_part(_,_,_,\"libpart\",_,_,_)"))
			{
				Called_module_entry = stoi(returnpar(HT.findandreturn("hierarchy_part(_,_,_,\"libpart\",_,_,_)"), 1));
				Called_module_name = returnpar(HT.findandreturn("hierarchy_part(_,_,_,\"libpart\",_,_,_)"), 2);
				if (HT.findfact("call_stmt(" + Module_name + "," + to_string(Call_entry) + "," + to_string(Called_module_entry) + ",*)"))
				{
					if (HT.findfact("prog_stmt(" + Module_name + ",_,_,109,0,"+to_string(Call_entry)+",0,_)"))
					{
						if (custom_block(Called_module_name))
						{
							WS = "      ";
							ss << WS;
							ss << " //------ this is a call to custom procedure block : " << Called_module_name << " -----" << endl;
							ss << write_procedure_task_call_actuals(Module_name, Call_entry, "verilog") << endl;
						}
					}
					else if (HT.findfact("prog_stmt(" + Module_name + ",_,_,109,0," + to_string(Call_entry) + ",0,_)"))
					{
						Operation = stoi(returnpar(HT.findandreturn("prog_stmt(" + Module_name + ",_,_,109,0," + to_string(Call_entry) + ",0,_)"), 2));
						Res_entry = stoi(returnpar(HT.findandreturn("prog_stmt(" + Module_name + ",_,_,109,0," + to_string(Call_entry) + ",0,_)"), 7));
						if (Res_entry > 0)
						{
							if (HT.findfact("data_stmt(" + Module_name + ",_," + to_string(Res_entry) + ",_,_,_)"))
							{
								Res_name = returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Res_entry) + ",_,_,_)"), 2);
								if (custom_block(Called_module_name))
								{
									WS = "      ";
									ss << WS;
									ss << " //------ this is a call to custom function block : " << Called_module_name << " -----" << endl;
									ss << write_function_task_call_actuals(Module_name, Operation, Call_entry, "verilog") << endl;
									ss << "             " << Res_name << " <= " << Called_module_name << "_tmpout;" << endl;
								}
							}
						}
					}
				}
			}
		}
	}
	else if (HDL == "c")
	{
		if (HT.findfact("hdl_style(\"c\"),"))
		{
			if (HT.findfact("hierarchy_part(_,_,_,\"libpart\",_,_,_)"))
			{
				Called_module_entry = stoi(returnpar(HT.findandreturn("hierarchy_part(_,_,_,\"libpart\",_,_,_)"), 1));
				Called_module_name = returnpar(HT.findandreturn("hierarchy_part(_,_,_,\"libpart\",_,_,_)"), 2);
				if (HT.findfact("call_stmt(" + Module_name + "," + to_string(Call_entry) + "," + to_string(Called_module_entry) + ",*)"))
				{
					Actual_params = returnVec(makeInstanceOf(HT.findandreturn("call_stmt(" + Module_name + "," + to_string(Call_entry) + ",*)")), 1);
					if (HT.findfact("prog_stmt(" + Module_name + ",_,_,109,0," + to_string(Call_entry) + ",0,_)"))
					{
						WS = "         ";
						ss << WS;
						ss << " //------ this is a call to procedure (subroutine) : " << Called_module_name << " -----" << endl;
						ss << WS << Called_module_name << "(";
						ss << write_c_actual_parameters(Module_name, Called_module_name, Actual_params, 1);
						//write(");"), nl,
						//write(WS),
						//write("printf(", '"', Called_module_name, "("),
						//write_c_actual_parameters(Module_name, Called_module_name, Actual_params, 1),
						//write(")", '\\', "n", '"', ");"), nl.
					}
				}
			}
		}
	}
	return ss.str();
}

string write_procedure_task_call_actuals(string Module_name, int Call_entry, string HDL)
{
	stringstream ss;
	int Called_module_entry;
	string Called_module_name;
	vector<int> Actual_params;
	if (HDL == "verilog")
	{
		if (HT.findfact("call_stmt(" + Module_name + "," + to_string(Call_entry) + ",*)"))
		{
			Called_module_entry = stoi(returnpar(HT.findandreturn("call_stmt(" + Module_name + "," + to_string(Call_entry) + ",*)"), 3));
			Actual_params = returnVec(makeInstanceOf(HT.findandreturn("call_stmt(" + Module_name + "," + to_string(Call_entry) + ",*)")), 1);
			if (HT.findfact("hierarchy_part("+to_string(Called_module_entry)+",*)"))
			{
				Called_module_name = returnpar(HT.findandreturn("hierarchy_part(" + to_string(Called_module_entry) + ",*)"), 2);
				ss << "              " << Called_module_name << "_task(";
				ss << write_procedure_actual_parameters(Module_name, Called_module_name, Actual_params, 1);
				ss << ");  //-- from procedure call: " << Called_module_name << endl;
				ss << write_parameter_assignments(Module_name, Called_module_name, Actual_params, 1);
			}
		}
	}
	return ss.str();
}

string write_procedure_actual_parameters(string Module_name, string Called_module, vector<int> List, int In_formal_entry)
{
	stringstream ss;
	string  Object_name, Object_kind;
	int Next_formal_entry;
	if (!List.empty())
	{
		if (List.size() == 1)
		{
			if (HT.findfact("data_stmt(" + Called_module + ",_," + to_string(In_formal_entry) + ",_,\"par_in\",_)"))
			{
				if (HT.findfact("data_stmt(" + Module_name + ",_,"+to_string(List.front())+",_,_,_"))
				{
					Object_name = returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(List.front()) + ",_,_,_"), 2);
					ss << Object_name;
					ss << write_function_out_param_aux_cond(Called_module);
				}
			}
		}
		else if (List.size() > 2)
		{
			ss << write_actual_or_formal_parameter(Module_name, Called_module, List.front(), In_formal_entry);
			Next_formal_entry = In_formal_entry + 1;
			List.erase(List.begin());
			ss << write_procedure_actual_parameters(Module_name, Called_module, List, Next_formal_entry);
		}
		else if (HT.findfact("data_stmt(" + Called_module + ",_,"+to_string(In_formal_entry)+",_,_,_)"))
		{
			Object_name = returnpar(HT.findandreturn("data_stmt(" + Called_module + ",_," + to_string(In_formal_entry) + ",_,_,_)"), 2);
			Object_kind = returnpar(HT.findandreturn("data_stmt(" + Called_module + ",_," + to_string(In_formal_entry) + ",_,_,_)"), 5);
			if (it_is_output_kind(Object_kind))
			{
				ss << Object_name << "_tmpout";
				ss << write_function_out_param_aux_cond(Called_module);
			}
		}
	}
	return ss.str();
}

string write_function_out_param_aux_cond(string Called_module)
{
	stringstream ss;
	if (HT.findfact("data_stmt(" + Called_module + "," + Called_module + ",_,_,\"par_out\",_)"))
	{
		ss << ", " << Called_module << "_tmpout";
	}
	return ss.str();
}

string write_parameter_assignments(string Module_name, string Called_module, vector<int> List, int In_formal_entry)
{
	stringstream ss;
	int Next_formal_entry;
	if (!List.empty())
	{
		ss << write_parameter_assignment(Module_name, Called_module, List.front(), In_formal_entry);
		Next_formal_entry = In_formal_entry + 1;
		List.erase(List.begin());
		ss << write_parameter_assignments(Module_name, Called_module, List, Next_formal_entry);
	}
	return ss.str();
}

string write_parameter_assignment(string Module_name, string Called_module, int Actual, int Formal)
{
	stringstream ss;
	string Kind, Formal_name, Actual_name;
	if (HT.findfact("data_stmt(" + Called_module + ",_," + to_string(Formal) + ",_,_,_)"))
	{
		Formal_name = returnpar(HT.findandreturn("data_stmt(" + Called_module + ",_," + to_string(Formal) + ",_,_,_)"), 2);
		Kind = returnpar(HT.findandreturn("data_stmt(" + Called_module + ",_," + to_string(Formal) + ",_,_,_)"), 5);
		if (Kind != "par_out" || Kind != "par_inout")
		{
			return ss.str();
		}
		else if (it_is_output_kind(Kind))
		{
			if (HT.findfact("data_stmt(" + Module_name + ",_," + to_string(Actual) + ",_,_,_)"))
			{
				Actual_name = returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(Actual) + ",_,_,_)"), 2);
				ss << "             " << Actual_name << " <= " << Formal_name << "_tmpout;" << endl;
			}
		}
	}
	return ss.str();
}

string write_function_task_call_actuals(string Module_name, int Op_entry, int Call_entry, string HDL)
{
	stringstream ss;
	int Result, Called_module_entry;
	vector<int> Actual_params;
	string Called_module_name;
	if (HDL == "verilog")
	{
		if (HT.findfact("prog_stmt("+Module_name+","+to_string(Op_entry)+",_,109,_,"+to_string(Call_entry)+",_,_)"))
		{
			Result = stoi(returnpar(HT.findandreturn("prog_stmt(" + Module_name + "," + to_string(Op_entry) + ",_,109,_," + to_string(Call_entry) + ",_,_)"), 7));
			if (HT.findfact("call_stmt(" + Module_name + "," + to_string(Call_entry) + ",*)"))
			{
				Called_module_entry = stoi(returnpar(HT.findandreturn("call_stmt(" + Module_name + "," + to_string(Call_entry) + ",*)"), 3));
				Actual_params = returnVec(makeInstanceOf(HT.findandreturn("call_stmt(" + Module_name + "," + to_string(Call_entry) + ",*)")), 1);
				if (HT.findfact("hierarchy_part(" + to_string(Called_module_entry) + ",*)"))
				{
					Called_module_name = returnpar(HT.findandreturn("hierarchy_part(" + to_string(Called_module_entry) + ",*)"), 2);
					if (HT.findfact("data_stmt(" + Module_name + ",_," + to_string(Result) + ",_,_,_)"))
					{
						ss << "             " << Called_module_name << "_task(";
						ss << write_procedure_actual_parameters(Module_name, Called_module_name, Actual_params, 1);
						ss << ");   //-- from function call: " << Called_module_name << endl;
						ss << write_parameter_assignments(Module_name, Called_module_name, Actual_params, 1);
					}
				}
			}
		}
	}
	return ss.str();
}

string write_actual_or_formal_parameter(string Module, string Called_module, int Actual, int Formal)
{
	stringstream ss;
	string Object_name, Object_kind;
	if (HT.findfact("data_stmt(" + Called_module + ",_," + to_string(Formal) + ",_,\"par_in\",_)"))
	{
		if (HT.findfact("data_stmt(" + Module + ",_,"+to_string(Actual)+",_,_,_)"))
		{
			Object_name = returnpar(HT.findandreturn("data_stmt(" + Module + ",_," + to_string(Actual) + ",_,_,_)"), 2);
			ss << Object_name << ", ";
		}
	}
	if (HT.findfact("data_stmt(" + Called_module + ",_," + to_string(Formal) + ",_,_,_)"))
	{
		Object_name = returnpar(HT.findandreturn("data_stmt(" + Called_module + ",_," + to_string(Formal) + ",_,_,_)"), 2);
		Object_kind = returnpar(HT.findandreturn("data_stmt(" + Called_module + ",_," + to_string(Formal) + ",_,_,_)"), 5);
		if (it_is_output_kind(Object_kind))
		{
			ss << Object_name << "_tmpout, ";
		}
	}
	return ss.str();
}

string write_c_actual_parameters(string Module_name, string Called_module, vector<int> List, int In_formal_entry)
{
	stringstream ss;
	string Kind, Object_name, Type_kind;
	int Type, Next_formal_entry;
	if (!List.empty())
	{
		if (List.size() == 1)
		{
			if (HT.findfact("data_stmt(" + Called_module + ",_," + to_string(In_formal_entry) + ",_,_,_)"))
			{
				Kind = returnpar(HT.findandreturn("data_stmt(" + Called_module + ",_," + to_string(In_formal_entry) + ",_,_,_)"), 5);
				if (HT.findfact("data_stmt(" + Module_name + ",_," + to_string(List.front()) + ",_,_,_)"))
				{
					Object_name = returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(List.front()) + ",_,_,_)"), 2);
					Type = stoi(returnpar(HT.findandreturn("data_stmt(" + Module_name + ",_," + to_string(List.front()) + ",_,_,_)"), 2));
					if (HT.findfact("type_def(" + to_string(Type) + ",_,_,_,_,\"vectorarray_t\",_,_,_)"))
					{
						ss << Object_name;
					}
					else if (HT.findfact("type_def(" + to_string(Type) + ",*)"))
					{
						Type_kind = returnpar(HT.findandreturn("type_def(" + to_string(Type) + ",*)"), 6);
						if (Type_kind != "vectorarray_t")
						{
							ss << write_parkind_c(Kind);
							ss << Object_name;
						}
					}
				}
			}
		}
		else if (List.size() > 2)
		{
			ss << write_c_parameter(Module_name, Called_module, List.front(), In_formal_entry);
			Next_formal_entry = In_formal_entry + 1;
			List.erase(List.begin());
			ss << write_c_actual_parameters(Module_name, Called_module, List, Next_formal_entry);
		}
	}
	return ss.str();
}

string write_parkind_c(string str)
{
	stringstream ss;
	if (str == "par_out" || str == "par_inout")
	{
		ss << "&";
	}
	return ss.str();
}

string write_c_parameter(string Module, string Called_module, int Actual, int Formal)
{
	stringstream ss;
	string Kind, Object_name, Type_kind;
	int Type;
	if (HT.findfact("data_stmt(" + Called_module + ",_," + to_string(Formal) + ",_,_,_)"))
	{
		Kind = returnpar(HT.findandreturn("data_stmt(" + Called_module + ",_," + to_string(Formal) + ",_,_,_)"), 5);
		if (HT.findfact("data_stmt(" + Module + ",_," + to_string(Actual) + ",_,_,_)"))
		{
			Object_name = returnpar(HT.findandreturn("data_stmt(" + Module + ",_," + to_string(Actual) + ",_,_,_)"), 2);
			Type = stoi(returnpar(HT.findandreturn("data_stmt(" + Module + ",_," + to_string(Actual) + ",_,_,_)"), 2));
			if (HT.findfact("type_def(" + to_string(Type) + ",_,_,_,_,\"vectorarray_t\",_,_,_)"))
			{
				ss << Object_name << ", ";
			}
			else if (HT.findfact("type_def(" + to_string(Type) + ",*)"))
			{
				Type_kind = returnpar(HT.findandreturn("type_def(" + to_string(Type) + ",*)"), 6);
				if (Type_kind != "vectorarray_t")
				{
					ss << write_parkind_c(Kind);
					ss << Object_name << ", ";
				}
			}
		}
	}
	return ss.str();
}
#pragma once
#include "AVL.h"
#include "allFactStructure.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream> 
#include <stdio.h>
#include <typeinfo>
#include <functional>

using namespace std;

const char pa	= '(';	// parenthesis open

const char pacl = ')';	// parenthesis close 

const char co	= ',';	// coma

const char br	= '[';	// bracket open

const char brcl = ']';	// bracket close

const char us	= '_';	// underscore

const char str  =  '*'; // star

/// @brief makes string of data
/// @param obj <- the data
string makeStringOf(GeneralFact* obj)
{
	size_t			prlst;		// pre-last element of a vector
	stringstream	ss;
	string			ALine;

	ALine = typeid(*obj).name();
	ALine = ALine.substr(6);
	string ch = ALine.substr(0, 1);
	const char* sh = ch.c_str();
	switch (*sh)
	{
	case 'a':
	{
		if ("added_aux_call_ios" == ALine)
		{
			added_aux_call_ios* ptr = dynamic_cast<added_aux_call_ios*>(obj);
			ss << "added_aux_call_ios(" << ptr->q << co << ptr->w;
		}
		else if ("added_aux_call_ios1" == ALine)
		{
			added_aux_call_ios1* ptr = dynamic_cast<added_aux_call_ios1*>(obj);
			ss << "added_aux_call_ios1(" << ptr->q << co << ptr->w << co << ptr->e;
		}
		else if ("added_aux_call_signals" == ALine)
		{
			added_aux_call_signals* ptr = dynamic_cast<added_aux_call_signals*>(obj);
			ss << "added_aux_call_signals(" << ptr->q << co << ptr->w;
		}
		else if ("added_verilog_aux_call_outputs" == ALine)
		{
			added_verilog_aux_call_outputs* ptr = dynamic_cast<added_verilog_aux_call_outputs*>(obj);
			ss << "added_verilog_aux_call_outputs(" << ptr->q << co << ptr->w << co << ptr->e;
		}

		break;
	}
	case 'b':
	{

		break;
	}
	case 'c':
	{
		if ("cac_mode" == ALine)
		{
			cac_mode* ptr = dynamic_cast<cac_mode*>(obj);
			ss << "cac_mode(" << ptr->q;
		}
		else if ("call_ios_have_been_reset" == ALine)
		{
			call_ios_have_been_reset* ptr = dynamic_cast<call_ios_have_been_reset*>(obj);
			ss << "call_ios_have_been_reset(" << ptr->q;
		}
		else if ("call_stmt" == ALine)
		{
			call_stmt* ptr = dynamic_cast<call_stmt*>(obj);
			ss << "call_stmt(" << ptr->q << co << ptr->w << co << ptr->e << co << br;
			//vector
			if (!ptr->r.empty())
			{
				prlst = ptr->r.size() - 1;
				for (int ii = 0; ii < prlst; ++ii) // loop until pre-last element.
				{
					ss << ptr->r[ii] << co;
				}
				ss << ptr->r.back();
			}
			ss << brcl;
		}
		else if ("calls_list" == ALine)
		{
			calls_list* ptr = dynamic_cast<calls_list*>(obj);
			ss << "calls_list(" << ptr->q << co << ptr->w << co << ptr->e << co << br;
			//vector
			if (!ptr->r.empty())
			{
				prlst = ptr->r.size() - 1;
				for (int ii = 0; ii < prlst; ++ii) // loop until pre-last element.
				{
					ss << ptr->r[ii] << co;
				}
				ss << ptr->r.back();
			}
			ss << brcl;
		}
		else if ("cessor" == ALine)
		{
			cessor* ptr = dynamic_cast<cessor*>(obj);
			ss << "cessor(" << ptr->q << co << ptr->w << co << ptr->e;
		}
		else if ("cessor_kind" == ALine)
		{
			cessor_kind* ptr = dynamic_cast<cessor_kind*>(obj);
			ss << "cessor_kind(" << ptr->q << co << ptr->w << co << ptr->e << co << ptr->r
				<< co << ptr->t << co << ptr->y << co << br;
			//vector
			if (!ptr->u.empty())
			{
				prlst = ptr->u.size() - 1;
				for (int ii = 0; ii < prlst; ++ii) // loop until pre-last element.
				{
					ss << ptr->u[ii] << co;
				}
				ss << ptr->u.back();
			}
			ss << brcl;

		}
		else if ("cf_previous_op" == ALine)
		{
			cf_previous_op* ptr = dynamic_cast<cf_previous_op*>(obj);
			ss << "cf_previous_op(" << ptr->q << co << ptr->w << co << ptr->e << co << ptr->r;
		}
		else if ("cf_previous_state" == ALine)
		{
			cf_previous_state* ptr = dynamic_cast<cf_previous_state*>(obj);
			ss << "cf_previous_state(" << ptr->q << co << ptr->w << co << ptr->e << co << ptr->r;
		}
		else if ("change_op_number" == ALine)
		{
			change_op_number* ptr = dynamic_cast<change_op_number*>(obj);
			ss << "change_op_number(" << ptr->q << co << ptr->w << co << ptr->e;
		}
		else if ("checkstyle" == ALine)
		{
			checkstyle* ptr = dynamic_cast<checkstyle*>(obj);
			ss << "checkstyle(" << ptr->q;
		}
		else if ("combo" == ALine)
		{
			combo* ptr = dynamic_cast<combo*>(obj);
			ss << "combo(" << ptr->q << co << ptr->w << co << ptr->e;
		}
		else if ("complex_next_state_operation_depth" == ALine)
		{
			complex_next_state_operation_depth* ptr = dynamic_cast<complex_next_state_operation_depth*>(obj);
			ss << "complex_next_state_operation_depth(" << ptr->q;
		}
		else if ("compo_stmt" == ALine)
		{
			compo_stmt* ptr = dynamic_cast<compo_stmt*>(obj);
			ss << "compo_stmt(" << ptr->q << co << ptr->w << co << br;
			//vector
			if (!ptr->r.empty())
			{
				prlst = ptr->r.size() - 1;
				for (int ii = 0; ii < prlst; ++ii)
				{
					ss << ptr->r[ii] << co;
				}
				ss << ptr->r.back();
			}
			ss << brcl;
		}
		else if ("composites_list" == ALine)
	{
	composites_list* ptr = dynamic_cast<composites_list*>(obj);
	ss << "composites_list(" << ptr->q << co << ptr->w << co << br;
	//vector
	if (!ptr->e.empty())
	{
		prlst = ptr->e.size() - 1;
		for (int ii = 0; ii < prlst; ++ii) // loop until pre-last element.
		{
			ss << ptr->e[ii] << co;
		}
		ss << ptr->e.back();
	}
	ss << brcl;
	}
		else if ("conditional_incomplete" == ALine)
	{
	conditional_incomplete* ptr = dynamic_cast<conditional_incomplete*>(obj);
	ss << "conditional_incomplete(" << ptr->q << co << ptr->w << co << ptr->e << co << ptr->r << co << br;
	//vector
	if (!ptr->t.empty())
	{
		prlst = ptr->t.size() - 1;
		for (int ii = 0; ii < prlst; ++ii) // loop until pre-last element.
		{
			ss << ptr->t[ii] << co;
		}
		ss << ptr->t.back();
	}
	ss << brcl << co << br;
	//vector2
	if (!ptr->y.empty())
	{
		prlst = ptr->y.size() - 1;
		for (int ii = 0; ii < prlst; ++ii) // loop until pre-last element.
		{
			ss << ptr->y[ii] << co;
		}
		ss << ptr->y.back();
	}
	ss << brcl << co << br;
	//vector3
	if (!ptr->u.empty())
	{
		prlst = ptr->u.size() - 1;
		for (int ii = 0; ii < prlst; ++ii) // loop until pre-last element.
		{
			ss << ptr->u[ii] << co;
		}
		ss << ptr->u.back();
	}
	ss << brcl << co << br;
	//vector4
	if (!ptr->i.empty())
	{
		prlst = ptr->i.size() - 1;
		for (int ii = 0; ii < prlst; ++ii) // loop until pre-last element.
		{
			ss << ptr->i[ii] << co;
		}
		ss << ptr->i.back();
	}
	ss << brcl << co << br;
	//vector5
	if (!ptr->o.empty())
	{
		prlst = ptr->o.size() - 1;
		for (int ii = 0; ii < prlst; ++ii) // loop until pre-last element.
		{
			ss << ptr->o[ii] << co;
		}
		ss << ptr->o.back();
	}
	ss << brcl << co << br;
	//vector6
	if (!ptr->p.empty())
	{
		prlst = ptr->p.size() - 1;
		for (int ii = 0; ii < prlst; ++ii) // loop until pre-last element.
		{
			ss << ptr->p[ii] << co;
		}
		ss << ptr->p.back();
	}
	ss << brcl << co << ptr->a << co << ptr->s << co << ptr->d << co << ptr->f << co << ptr->g
		<< co << ptr->h << co << ptr->j << co << ptr->k << co << ptr->l << co << ptr->z
		<< co << ptr->x;
	}
		else if ("conditional_operations" == ALine)
	{
	conditional_operations* ptr = dynamic_cast<conditional_operations*>(obj);
	ss << "conditional_operations(" << ptr->q << co << ptr->w << co << ptr->e << co << ptr->r
		<< co << br;
	//vector
	if (!ptr->t.empty())
	{
		prlst = ptr->t.size() - 1;
		for (int ii = 0; ii < prlst; ++ii) // loop until pre-last element.
		{
			ss << ptr->t[ii] << co;
		}
		ss << ptr->t.back();
	}
	ss << brcl << co << br;
	//vector2
	if (!ptr->y.empty())
	{
		prlst = ptr->y.size() - 1;
		for (int ii = 0; ii < prlst; ++ii) // loop until pre-last element.
		{
			ss << ptr->y[ii] << co;
		}
		ss << ptr->y.back();
	}
	ss << brcl << co << br;
	//vector3
	if (!ptr->u.empty())
	{
		prlst = ptr->u.size() - 1;
		for (int ii = 0; ii < prlst; ++ii) // loop until pre-last element.
		{
			ss << ptr->u[ii] << co;
		}
		ss << ptr->u.back();
	}
	ss << brcl << co << br;
	//vector4
	if (!ptr->i.empty())
	{
		prlst = ptr->i.size() - 1;
		for (int ii = 0; ii < prlst; ++ii) // loop until pre-last element.
		{
			ss << ptr->i[ii] << co;
		}
		ss << ptr->i.back();
	}
	ss << brcl;
	}
		else if ("conditional_transitions" == ALine)
	{
	conditional_transitions* ptr = dynamic_cast<conditional_transitions*>(obj);
	ss << "conditional_transitions(" << ptr->q << co << ptr->w << co << ptr->e << co << ptr->r
		<< co << ptr->t << co << ptr->y << co << ptr->u << co << ptr->i;
	}
		else if ("consecutive_106" == ALine)
	{
	consecutive_106* ptr = dynamic_cast<consecutive_106*>(obj);
	ss << "consecutive_106(" << ptr->q;
	}
		else if ("current_hdl_style" == ALine)
		{
		current_hdl_style* ptr = dynamic_cast<current_hdl_style*>(obj);
		ss << "current_hdl_style(" << ptr->q;
		}
		else if ("current_module" == ALine)
	{
	current_module* ptr = dynamic_cast<current_module*>(obj);
	ss << "current_module(" << ptr->q;
	}
		else if ("current_total_max_order_entry" == ALine)
	{
	current_total_max_order_entry* ptr = dynamic_cast<current_total_max_order_entry*>(obj);
	ss << "current_total_max_order_entry(" << ptr->q;
	}

		break;
	}
	case 'd':
	{
		if ("data_stmt" == ALine)
			{
				data_stmt* ptr = dynamic_cast<data_stmt*>(obj);
				ss << "data_stmt("  << ptr->q << co << ptr->w << co << ptr->e << co << ptr->r
					<< co << ptr->t << co << ptr->y;
			}
		else if ("dataflow" == ALine)
		{
			state_node* ptr = dynamic_cast<state_node*>(obj);
			ss << "state_node(" << ptr->q << co << ptr->w << co;
			dataflow* ptr2 = dynamic_cast<dataflow*>(obj);
			ss << "dataflow(" << br;
			//vector
			if (!ptr2->q.empty())
			{
				prlst = ptr2->q.size() - 1;
				for (int ii = 0; ii < prlst; ++ii) // loop until pre-last element.
				{
					ss << ptr2->q[ii] << co;
				}
				ss << ptr2->q.back();
			}
			ss << brcl << co << ptr2->w << pacl;
		}
		else if ("debug_mode" == ALine)
		{
			debug_mode* ptr = dynamic_cast<debug_mode*>(obj);
			ss << "debug_mode(" << ptr->q;
		}

		break;
	}
	case 'e':
	{
		if ("end_if" == ALine)
		{
			end_if* ptr = dynamic_cast<end_if*>(obj);
			ss << "end_if(" << ptr->q << co << br;
			//vector
			if (!ptr->w.empty())
			{
				prlst = ptr->w.size() - 1;
				for (int ii = 0; ii < prlst; ++ii) // loop until pre-last element.
				{
					ss << ptr->w[ii] << co;
				}
				ss << ptr->w.back();
			}
			ss << brcl;

		}

		break;
	}
	case 'f':
	{
		if ("for_loop" == ALine)
		{
			for_loop* ptr = dynamic_cast<for_loop*>(obj);
			ss << "for_loop(" << ptr->q << co << ptr->w << co << ptr->e << co << ptr->r
				<< co << ptr->t << co << ptr->y << co << ptr->u << co << ptr->i << co << ptr->o
				<< co << ptr->p << co << ptr->a << co << ptr->s << co << ptr->d;
		}
		else if ("found_call_operator" == ALine)
		{
			found_call_operator* ptr = dynamic_cast<found_call_operator*>(obj);
			ss << "found_call_operator(" << ptr->q << co << ptr->w;
		}

		break;
	}
	case 'g':
	{
		if ("global_declarations" == ALine)
		{
			stringstream tt;
			int			ii = 0;
			size_t		vs;
			global_declarations* ptr = dynamic_cast<global_declarations*>(obj);
			ss << "global_declarations(" << br;
			if (!ptr->q.empty())
			{
				vs = ptr->q.size();
				for (int ii = 0; ii < vs; ii++)
				{
					ss << "local_object(" << ptr->q[ii].q << co << ptr->q[ii].w << co << ptr->q[ii].e << co << ptr->q[ii].r << co
						<< ptr->q[ii].t << co << ptr->q[ii].y << co << ptr->q[ii].u << co << ptr->q[ii].i << co << ptr->q[ii].o << pacl << co;
				}
				string tmp = ss.str();
				tmp.resize(tmp.size() - 1);  // getting rid of the last coma
				swap(ss, tt);
				ss << tmp;
			}
			ss << brcl << co << ptr->w;
		}
		else if ("global_nils" == ALine)
		{
			global_nils* ptr = dynamic_cast<global_nils*>(obj);
			ss << "global_nils(" << br;
			//vector
			if (!ptr->q.empty())
			{
				prlst = ptr->q.size() - 1;
				for (int ii = 0; ii < prlst; ++ii) // loop until pre-last element.
				{
					ss << "nil_node" << pa;

					ss << ptr->q[ii].q << co << ptr->q[ii].w << pacl << co;
				}
				ss << "nil_node" << pa << ptr->q.back().q << co << ptr->q.back().w;
				ss << pacl;
			}
			ss << brcl;
		}
		else if ("global_resource" == ALine)
		{
			global_resource* ptr = dynamic_cast<global_resource*>(obj);
			ss << "global_resource(" << ptr->q;
		}
		else if ("guard_cond" == ALine)
		{
			guard_cond* ptr = dynamic_cast<guard_cond*>(obj);
			ss << "guard_cond(" << ptr->q << co << ptr->w << co << ptr->e << co << ptr->r;
		}
		else if ("guard_pair" == ALine)
		{
			guard_pair* ptr = dynamic_cast<guard_pair*>(obj);
			ss << "guard_pair(" << ptr->q << co << ptr->w << co << ptr->e << co << ptr->r;
		}

		break;
	}
	case 'h':
	{
		if ("hdl_io_pass" == ALine)
		{
			hdl_io_pass* ptr = dynamic_cast<hdl_io_pass*>(obj);
			ss << "hdl_io_pass(" << ptr->q;
		}
		else if ("hdl_style" == ALine)
		{
			hdl_style* ptr = dynamic_cast<hdl_style*>(obj);
			ss << "hdl_style(" << ptr->q;
		}
		else if ("hierarchy_part" == ALine)
		{
			hierarchy_part* ptr = dynamic_cast<hierarchy_part*>(obj);
			ss << "hierarchy_part(" << ptr->q << co << ptr->w << co << ptr->e << co << ptr->r
				<< co << ptr->t << co << ptr->y << co << ptr->u;
		}

		break;
	}
	case 'i':
	{
		if ("ifthen" == ALine)
	{
	state_node* ptr = dynamic_cast<state_node*>(obj);
	ss << "state_node(" << ptr->q << co << ptr->w << co;
	ifthen* ptr2 = dynamic_cast<ifthen*>(obj);
	ss << "ifthen(" << br;
	//vector
	if (!ptr2->q.empty())
	{
		prlst = ptr2->q.size() - 1;
		for (int ii = 0; ii < prlst; ++ii) // loop until pre-last element.
		{
			ss << ptr2->q[ii] << co;
		}
		ss << ptr2->q.back();
	}
	ss << brcl << co << br;
	//vector2
	if (!ptr2->w.empty())
	{
		prlst = ptr2->w.size() - 1;
		for (int ii = 0; ii < prlst; ++ii) // loop until pre-last element.
		{
			ss << ptr2->w[ii] << co;
		}
		ss << ptr2->w.back();
	}
	ss << brcl << co << br;
	//vector3
	if (!ptr2->e.empty())
	{
		prlst = ptr2->e.size() - 1;
		for (int ii = 0; ii < prlst; ++ii) // loop until pre-last element.
		{
			ss << ptr2->e[ii] << co;
		}
		ss << ptr2->e.back();
	}
	ss << brcl << co << ptr2->r << co << ptr2->t << pacl;
	}
		else if ("incomplete_links" == ALine)
		{
			incomplete_links* ptr = dynamic_cast<incomplete_links*>(obj);
			ss << "incomplete_links(" << ptr->q << co << ptr->w << co << ptr->e << co << ptr->r
				<< co << ptr->t << co << ptr->y << co << ptr->u << co << ptr->i << co << ptr->o
				<< co << ptr->p;
		}
		else if ("it_includes_conditional_targeting" == ALine)
		{
			it_includes_conditional_targeting* ptr = dynamic_cast<it_includes_conditional_targeting*>(obj);
			ss << "it_includes_conditional_targeting(" << ptr->q << co << ptr->w << co << ptr->e;
		}
		else if ("it_includes_ifthen" == ALine)
		{
			it_includes_ifthen* ptr = dynamic_cast<it_includes_ifthen*>(obj);
			ss << "it_includes_ifthen(" << ptr->q << co << ptr->w << co << ptr->e;
		}

		break;
	}
	case 'j':
	{
		if ("joint_stmt" == ALine)
		{
			joint_stmt* ptr = dynamic_cast<joint_stmt*>(obj);
			ss << "joint_stmt(" << ptr->q << co << ptr->w << co << ptr->e << co << ptr->r
				<< co << ptr->t << co << ptr->y;
		}
		else if ("jump" == ALine)	//losing align after 15 else if 
		{
			state_node* ptr = dynamic_cast<state_node*>(obj);
			ss << "state_node(" << ptr->q << co << ptr->w << co;
			jump* ptr2 = dynamic_cast<jump*>(obj);
			ss << "jump" << pa << br;
			//vector
			if (!ptr2->q.empty())
			{
				prlst = ptr2->q.size() - 1;
				for (int ii = 0; ii < prlst; ++ii) // loop until pre-last element.
				{
					ss << ptr2->q[ii] << co;
				}
				ss << ptr2->q.back();
			}
			ss << brcl << co << ptr2->w << pacl;
		}

		break;
	}
	case 'k':
	{

		break;
	}
	case 'l':
	{
		if ("last_change_op_number" == ALine)
		{
			last_change_op_number* ptr = dynamic_cast<last_change_op_number*>(obj);
			ss << "last_change_op_number(" << ptr->q << co << ptr->w << co << ptr->e;
		}
		else if ("last_conditional_execution" == ALine)
		{
			last_conditional_execution* ptr = dynamic_cast<last_conditional_execution*>(obj);
			ss << "last_conditional_execution(" << ptr->q << co << ptr->w;
		}
		else if ("last_conditional_transition" == ALine)
		{
			last_conditional_transition* ptr = dynamic_cast<last_conditional_transition*>(obj);
			ss << "last_conditional_transition(" << ptr->q << co << ptr->w;
		}
		else if ("last_conditional_transition_of_schedule" == ALine)
		{
			last_conditional_transition_of_schedule* ptr = dynamic_cast<last_conditional_transition_of_schedule*>(obj);
			ss << "last_conditional_transition_of_schedule(" << ptr->q << co << ptr->w << co << ptr->e;
		}
		else if ("last_for_loop_entry" == ALine)
		{
			last_for_loop_entry* ptr = dynamic_cast<last_for_loop_entry*>(obj);
			ss << "last_for_loop_entry(" << ptr->q;
		}
		else if ("last_incomplete" == ALine)
		{
			last_incomplete* ptr = dynamic_cast<last_incomplete*>(obj);
			ss << "last_incomplete(" << ptr->q << co << ptr->w << co << ptr->e << co << ptr->r;
		}
		else if ("last_linear_incomplete_node" == ALine)
		{
			last_linear_incomplete_node* ptr = dynamic_cast<last_linear_incomplete_node*>(obj);
			ss << "last_linear_incomplete_node(" << ptr->q;
		}
		else if ("last_local_number" == ALine)
		{
			last_local_number* ptr = dynamic_cast<last_local_number*>(obj);
			ss << "last_local_number(" << ptr->q;
		}
		else if ("last_non_io_found" == ALine)
		{
			last_non_io_found* ptr = dynamic_cast<last_non_io_found*>(obj);
			ss << "last_non_io_found(" << ptr->q;
		}
		else if ("last_op_in_a_state" == ALine)
		{
			last_op_in_a_state* ptr = dynamic_cast<last_op_in_a_state*>(obj);
			ss << "last_op_in_a_state(" << ptr->q << co << ptr->w << co << ptr->e << co << ptr->r;
		}
		else if ("last_op_instance" == ALine)
		{
			last_op_instance* ptr = dynamic_cast<last_op_instance*>(obj);
			ss << "last_op_instance(" << ptr->q << co << ptr->w << co << ptr->e;
		}
		else if ("last_output_instance" == ALine)
		{
			last_output_instance* ptr = dynamic_cast<last_output_instance*>(obj);
			ss << "last_output_instance(" << ptr->q << co << ptr->w;
		}
		else if ("last_reentrant_triangle" == ALine)
		{
			last_reentrant_triangle* ptr = dynamic_cast<last_reentrant_triangle*>(obj);
			ss << "last_reentrant_triangle(" << ptr->q << co << ptr->w;
		}
		else if ("last_rescheduled" == ALine)
		{
			last_rescheduled* ptr = dynamic_cast<last_rescheduled*>(obj);
			ss << "last_rescheduled(" << ptr->q << co << ptr->w << co << ptr->e << co << ptr->r << co << ptr->t;
		}
		else if ("last_schedule_state" == ALine)
		{
			last_schedule_state* ptr = dynamic_cast<last_schedule_state*>(obj);
			ss << "last_schedule_state(" << ptr->q << co << ptr->w << co << ptr->e;
		}
		else if ("last_signal_instance" == ALine)
		{
			last_signal_instance* ptr = dynamic_cast<last_signal_instance*>(obj);
			ss << "last_signal_instance(" << ptr->q << co << ptr->w;
		}
		else if ("last_while_loop_entry" == ALine)
		{
			last_while_loop_entry* ptr = dynamic_cast<last_while_loop_entry*>(obj);
			ss << "last_while_loop_entry(" << ptr->q;
		}
		else if ("linear_incomplete_node" == ALine)
		{
			linear_incomplete_node* ptr = dynamic_cast<linear_incomplete_node*>(obj);
			ss << "linear_incomplete_node(" << ptr->q << co << ptr->w << co << ptr->e << co << ptr->y << co << br;
			//vector
			if (!ptr->r.empty())
			{
				prlst = ptr->r.size() - 1;
				for (int ii = 0; ii < prlst; ++ii) // loop until pre-last element.
				{
					ss << ptr->r[ii] << co;
				}
				ss << ptr->r.back();
			}
			ss << brcl << co << br;
			//vector2
			if (!ptr->t.empty())
			{
				prlst = ptr->t.size() - 1;
				for (int ii = 0; ii < prlst; ++ii) // loop until pre-last element.
				{
					ss << ptr->t[ii] << co;
				}
				ss << ptr->t.back();
			}
			ss << brcl;
		}
		else if ("local_ifthen_chain_end_operations_were_written" == ALine)
	{
	local_ifthen_chain_end_operations_were_written* ptr = dynamic_cast<local_ifthen_chain_end_operations_were_written*>(obj);
	ss << "local_ifthen_chain_end_operations_were_written(" << ptr->q;
	}
		else if ("local_object" == ALine)
	{
	local_object* ptr = dynamic_cast<local_object*>(obj);
	ss << "local_object(" << ptr->q << co << ptr->w << co << ptr->e << co << ptr->r
		<< co << ptr->t << co << ptr->y << co << ptr->u << co << ptr->i << co << ptr->o;
	}

		break;
	}
	case 'm':
	{
		if ("massively_parallel_style" == ALine)
		{
			massively_parallel_style* ptr = dynamic_cast<massively_parallel_style*>(obj);
			ss << "massively_parallel_style(" << ptr->q;
		}
		else if ("max_op_order" == ALine)
		{
			max_op_order* ptr = dynamic_cast<max_op_order*>(obj);
			ss << "max_op_order(" << ptr->q << co << ptr->w << co << ptr->e;
		}
		else if ("max_parallel_call_order" == ALine)
		{
			max_parallel_call_order* ptr = dynamic_cast<max_parallel_call_order*>(obj);
			ss << "max_parallel_call_order(" << ptr->q << co << ptr->w << co << ptr->e << co << ptr->r;
		}
		else if ("max_path" == ALine)
		{
			max_path* ptr = dynamic_cast<max_path*>(obj);
			ss << "max_path(" << ptr->q << co << ptr->w;
		}
		else if ("mem_port" == ALine)
		{
			mem_port* ptr = dynamic_cast<mem_port*>(obj);
			ss << "mem_port(" << ptr->q << co << ptr->w << co << ptr->e << co << ptr->r
				<< co << ptr->t << co << ptr->y << co << ptr->u << co << ptr->i << co << ptr->o
				<< co << ptr->p << co << ptr->a << co << ptr->s << co << ptr->d;
		}
		else if ("min_path" == ALine)
		{
			min_path* ptr = dynamic_cast<min_path*>(obj);
			ss << "min_path(" << ptr->q << co << ptr->w;
		}
		else if ("mixed_incomplete_state_lists" == ALine)
		{
			mixed_incomplete_state_lists* ptr = dynamic_cast<mixed_incomplete_state_lists*>(obj);
			ss << "mixed_incomplete_state_lists(" << ptr->q << co << ptr->w << co << ptr->e << co << br;
			//vector
			if (!ptr->r.empty())
			{
				prlst = ptr->r.size() - 1;
				for (int ii = 0; ii < prlst; ++ii) // loop until pre-last element.
				{
					ss << ptr->r[ii] << co;
				}
				ss << ptr->r.back();
			}
			ss << brcl << co << br;
			//vector2
			if (!ptr->t.empty())
			{
				prlst = ptr->t.size() - 1;
				for (int ii = 0; ii < prlst; ++ii) // loop until pre-last element.
				{
					ss << ptr->t[ii] << co;
				}
				ss << ptr->t.back();
			}
			ss << brcl;
		}
		else if ("module_g_resource" == ALine)
		{
			module_g_resource* ptr = dynamic_cast<module_g_resource*>(obj);
			ss << "module_g_resource(" << ptr->q << co << ptr->w;
		}
		else if ("module_last_state" == ALine)
		{
			module_last_state* ptr = dynamic_cast<module_last_state*>(obj);
			ss << "module_last_state(" << ptr->q;
		}
		else if ("module_local_list" == ALine)
		{
			stringstream tt;
			module_local_list* ptr = dynamic_cast<module_local_list*>(obj);
			int			ii = 0;
			size_t		vs;
			ss << "module_local_list(" << br;
			if (!ptr->q.empty())
			{
				vs = ptr->q.size();
				for (int ii = 0; ii < vs; ii++)
				{
					ss << "local_object(" << ptr->q[ii].q << co << ptr->q[ii].w << co << ptr->q[ii].e << co << ptr->q[ii].r << co
						<< ptr->q[ii].t << co << ptr->q[ii].y << co << ptr->q[ii].u << co << ptr->q[ii].i << co << ptr->q[ii].o << pacl << co;
				}
				string tmp = ss.str();
				tmp.resize(tmp.size() - 1);  // getting rid of the last
				swap(ss, tt);
				ss << tmp;
				ss << brcl;
			}
		}
		if ("module_local_list_parcs" == ALine)
		{
			stringstream tt;
			module_local_list_parcs* ptr = dynamic_cast<module_local_list_parcs*>(obj);
			int			ii = 0;
			size_t		vs;
			ss << "module_local_list_parcs(" << br;
			if (!ptr->q.empty())
			{
				vs = ptr->q.size();
				for (int ii = 0; ii < vs; ii++)
				{
					ss << "local_object(" << ptr->q[ii].q << co << ptr->q[ii].w << co << ptr->q[ii].e << co << ptr->q[ii].r << co
						<< ptr->q[ii].t << co << ptr->q[ii].y << co << ptr->q[ii].u << co << ptr->q[ii].i << co << ptr->q[ii].o << pacl << co;
				}
				string tmp = ss.str();
				tmp.resize(tmp.size() - 1);  // getting rid of the last
				swap(ss, tt);
				ss << tmp;
				ss << brcl;
			}
		}

		break;
	}
	case 'n':
	{
		if ("nested_cond_fact" == ALine)
	{
	nested_cond_fact* ptr = dynamic_cast<nested_cond_fact*>(obj);
	ss << "nested_cond_fact(" << ptr->q << co << br;
	//vector
	if (!ptr->w.empty())
	{
		prlst = ptr->w.size() - 1;
		for (int ii = 0; ii < prlst; ++ii) // loop until pre-last element.
		{
			ss << ptr->w[ii] << co;
		}
		ss << ptr->w.back();
	}
	ss << brcl;
	}
		else if ("new_schedule" == ALine)
		{
			new_schedule* ptr = dynamic_cast<new_schedule*>(obj);
			ss << "new_schedule(" << ptr->q;
		}

		break;
	}
	case 'o':
	{
		if ("old_schedule" == ALine)
		{
			old_schedule* ptr = dynamic_cast<old_schedule*>(obj);
			ss << "old_schedule(" << ptr->q;
		}
		else if ("op_belongs_to_state" == ALine)
		{
			op_belongs_to_state* ptr = dynamic_cast<op_belongs_to_state*>(obj);
			ss << "op_belongs_to_state(" << ptr->q << co << ptr->w << co << ptr->e << co << ptr->r;
		}
		else if ("op_def" == ALine)
		{
			op_def* ptr = dynamic_cast<op_def*>(obj);
			ss << "op_def(" << ptr->q << co << ptr->w << co << ptr->e << co << ptr->r
				<< co << ptr->t << co << ptr->y << co << ptr->u;
		}
		else if ("op_guards" == ALine)
		{
			op_guards* ptr = dynamic_cast<op_guards*>(obj);
			ss << "op_guards(" << ptr->q << co << ptr->w << co << br;
			//vector
			if (!ptr->e.empty())
			{
				prlst = ptr->e.size() - 1;
				for (int ii = 0; ii < prlst; ++ii) // loop until pre-last element.
				{
					ss << ptr->e[ii] << co;
				}
				ss << ptr->e.back();
			}
			ss << brcl << co << br;
			//vector2
			if (!ptr->r.empty())
			{
				prlst = ptr->r.size() - 1;
				for (int ii = 0; ii < prlst; ++ii) // loop until pre-last element.
				{
					ss << ptr->r[ii] << co;
				}
				ss << ptr->r.back();
			}
			ss << brcl;
		}
		else if ("op_in_a_state" == ALine)
		{
			op_in_a_state* ptr = dynamic_cast<op_in_a_state*>(obj);
			ss << "op_in_a_state(" << ptr->q << co << ptr->w << co << ptr->e << co << ptr->r
				<< co << ptr->t;
		}
		else if ("op_instance" == ALine)
		{
			op_instance* ptr = dynamic_cast<op_instance*>(obj);
			ss << "op_instance(" << ptr->q << co << ptr->w << co << ptr->e << co << ptr->r
				<< co << ptr->t;
		}
		else if ("op_resource" == ALine)
		{
			op_resource* ptr = dynamic_cast<op_resource*>(obj);
			ss << "op_resource(" << ptr->q << co << ptr->w << co << ptr->e;
		}
		else if ("operation_order" == ALine)
		{
			operation_order* ptr = dynamic_cast<operation_order*>(obj);
			ss << "operation_order(" << ptr->q << co << ptr->w << co << ptr->e << co << ptr->r
				<< co << ptr->t << co << ptr->y << co << ptr->u << co << ptr->i << co << ptr->o
				<< co << ptr->p;
		}
		else if ("operator_instance_stats" == ALine)
		{
			operator_instance_stats* ptr = dynamic_cast<operator_instance_stats*>(obj);
			ss << "operator_instance_stats(" << ptr->q << co << ptr->w << co << ptr->e << co << ptr->r;
		}
		else if ("operator_instances" == ALine)
		{
			operator_instances* ptr = dynamic_cast<operator_instances*>(obj);
			ss << "operator_instances(" << ptr->q << co << ptr->w;
		}
		else if ("output_filename" == ALine)
		{
			output_filename* ptr = dynamic_cast<output_filename*>(obj);
			ss << "output_filename(" << ptr->q;
		}
		else if ("output_instance" == ALine)
		{
			output_instance* ptr = dynamic_cast<output_instance*>(obj);
			ss << "output_instance(" << ptr->q << co << ptr->w << co << ptr->e << co << ptr->r
				<< co << ptr->t << co << ptr->y;
		}

		break;
	}
	case 'p':
	{
		if ("package_name" == ALine)
		{
			package_name* ptr = dynamic_cast<package_name*>(obj);
			ss << "package_name(" << ptr->q;
		}
		else if ("path" == ALine)
		{
			path* ptr = dynamic_cast<path*>(obj);
			ss << "path(" << ptr->q << co << ptr->w << co << ptr->e;
		}
		else if ("possible_end_if" == ALine)
		{
			possible_end_if* ptr = dynamic_cast<possible_end_if*>(obj);
			ss << "possible_end_if(" << ptr->q << co << br;
			//vector
			if (!ptr->w.empty())
			{
				prlst = ptr->w.size() - 1;
				for (int ii = 0; ii < prlst; ++ii) // loop until pre-last element.
				{
					ss << ptr->w[ii] << co;
				}
				ss << ptr->w.back();
			}
			ss << brcl;
		}
		else if ("pred_candidate_examined" == ALine)
		{
			pred_candidate_examined* ptr = dynamic_cast<pred_candidate_examined*>(obj);
			ss << "pred_candidate_examined(" << ptr->q << co << ptr->w << co << ptr->e;
		}
		else if ("predecessors" == ALine)
		{
			predecessors* ptr = dynamic_cast<predecessors*>(obj);
			ss << "predecessors(" << ptr->q << co << ptr->w << co << br;
			//vector
			if (!ptr->e.empty())
			{
				prlst = ptr->e.size() - 1;
				for (int ii = 0; ii < prlst; ++ii) // loop until pre-last element.
				{
					ss << ptr->e[ii] << co;
				}
				ss << ptr->e.back();
			}
			ss << brcl;


		}
		else if ("print_C_main_body" == ALine)
		{
			print_C_main_body* ptr = dynamic_cast<print_C_main_body*>(obj);
			ss << "print_C_main_body(" << ptr->q;
		}
		else if ("printed_formal_ios_of_called_module" == ALine)
		{
			printed_formal_ios_of_called_module* ptr = dynamic_cast<printed_formal_ios_of_called_module*>(obj);
			ss << "printed_formal_ios_of_called_module(" << ptr->q << co << ptr->w << co << ptr->e << co << ptr->r;
		}
		else if ("prog_stmt" == ALine)
		{
			prog_stmt* ptr = dynamic_cast<prog_stmt*>(obj);
			ss << "prog_stmt(" << ptr->q << co << ptr->w << co << ptr->e << co << ptr->r
				<< co << ptr->t << co << ptr->y << co << ptr->u << co << ptr->i;
		}

		break;
	}
	case 'q':
	{

		break;
	}
	case 'r':
	{
		if ("raw_cessor" == ALine)
	{
	raw_cessor* ptr = dynamic_cast<raw_cessor*>(obj);
	ss << "raw_cessor(" << ptr->q << co << ptr->w << co << ptr->e;
	}
		else if ("raw_dependencies" == ALine)
		{
			raw_dependencies* ptr = dynamic_cast<raw_dependencies*>(obj);
			ss << "raw_dependencies(" << ptr->q << co << ptr->w << co << br;
			//vector
			if (!ptr->e.empty())
			{
				prlst = ptr->e.size() - 1;
				for (int ii = 0; ii < prlst; ++ii) // loop until pre-last element.
				{
					ss << ptr->e[ii] << co;
				}
				ss << ptr->e.back();
			}
			ss << brcl << co << br;
			//vector2
			if (!ptr->r.empty())
			{
				prlst = ptr->r.size() - 1;
				for (int ii = 0; ii < prlst; ++ii) // loop until pre-last element.
				{
					ss << ptr->r[ii] << co;
				}
				ss << ptr->r.back();
			}
			ss << brcl;

		}
		else if ("rec_stmt" == ALine)
		{
			rec_stmt* ptr = dynamic_cast<rec_stmt*>(obj);
			ss << "rec_stmt(" << ptr->q << co << ptr->w << co << br;
			//vector
			if (!ptr->e.empty())
			{
				prlst = ptr->e.size() - 1;
				for (int ii = 0; ii < prlst; ++ii) // loop until pre-last element.
				{
					ss << ptr->e[ii] << co;
				}
				ss << ptr->e.back();
			}
			ss << brcl;
		}
		else if ("record_aggregates_list" == ALine)
		{
			record_aggregates_list* ptr = dynamic_cast<record_aggregates_list*>(obj);
			ss << "record_aggregates_list(" << ptr->q << co << ptr->w << co << br;
			//vector
			if (!ptr->e.empty())
			{
				prlst = ptr->e.size() - 1;
				for (int ii = 0; ii < prlst; ++ii) // loop until pre-last element.
				{
					ss << ptr->e[ii] << co;
				}
				ss << ptr->e.back();
			}
			ss << brcl;
		}
		else if ("reentrant_triangle" == ALine)
		{
			reentrant_triangle* ptr = dynamic_cast<reentrant_triangle*>(obj);
			ss << "reentrant_triangle(" << ptr->q << co << ptr->w << co << ptr->e << co << ptr->r << co << br;
			//vector
			if (!ptr->t.empty())
			{
				prlst = ptr->t.size() - 1;
				for (int ii = 0; ii < prlst; ++ii) // loop until pre-last element.
				{
					ss << ptr->t[ii] << co;
				}
				ss << ptr->t.back();
			}
			ss << brcl << co << br;
			//vector2
			if (!ptr->y.empty())
			{
				prlst = ptr->y.size() - 1;
				for (int ii = 0; ii < prlst; ++ii) // loop until pre-last element.
				{
					ss << ptr->y[ii] << co;
				}
				ss << ptr->y.back();
			}
			ss << brcl << co << br;
			//vector3
			if (!ptr->u.empty())
			{
				prlst = ptr->u.size() - 1;
				for (int ii = 0; ii < prlst; ++ii) // loop until pre-last element.
				{
					ss << ptr->u[ii] << co;
				}
				ss << ptr->u.back();
			}
			ss << brcl << co << br;
			//vector4
			if (!ptr->i.empty())
			{
				prlst = ptr->i.size() - 1;
				for (int ii = 0; ii < prlst; ++ii) // loop until pre-last element.
				{
					ss << ptr->i[ii] << co;
				}
				ss << ptr->i.back();
			}
			ss << brcl << co << br;
			//vector5
			if (!ptr->o.empty())
			{
				prlst = ptr->o.size() - 1;
				for (int ii = 0; ii < prlst; ++ii) // loop until pre-last element.
				{
					ss << ptr->o[ii] << co;
				}
				ss << ptr->o.back();
			}
			ss << brcl << co << br;
			//vector6
			if (!ptr->p.empty())
			{
				prlst = ptr->p.size() - 1;
				for (int ii = 0; ii < prlst; ++ii) // loop until pre-last element.
				{
					ss << ptr->p[ii] << co;
				}
				ss << ptr->p.back();
			}
			ss << brcl << co << ptr->a << co << ptr->s << co << ptr->d << co << ptr->f;
		}
		else if ("transition_to_be_rescheduled" == ALine)
	{
	transition_to_be_rescheduled* ptr = dynamic_cast<transition_to_be_rescheduled*>(obj);
	ss << "transition_to_be_rescheduled(" << ptr->q << co << ptr->w << co << ptr->e << co << ptr->r << co << ptr->t;
	}
		else if ("rescheduled" == ALine)
		{
			rescheduled* ptr = dynamic_cast<rescheduled*>(obj);
			ss << "rescheduled(" << ptr->q << co << ptr->w << co << ptr->e << co << ptr->r
				<< co << ptr->t;
		}
		else if ("resetstyle" == ALine)
		{
		resetstyle* ptr = dynamic_cast<resetstyle*>(obj);
		ss << "resetstyle(" << ptr->q;
		}
		else if ("return_cos" == ALine)
	{
	state_node* ptr = dynamic_cast<state_node*>(obj);
	ss << "state_node(" << ptr->q << co << ptr->w << co;
	return_cos* ptr2 = dynamic_cast<return_cos*>(obj);
	ss << "return(" << br;
	//vector
	if (!ptr2->q.empty())
	{
		prlst = ptr2->q.size() - 1;
		for (int ii = 0; ii < prlst; ++ii) // loop until pre-last element.
		{
			ss << ptr2->q[ii] << co;
		}
		ss << ptr2->q.back();
	}
	ss << brcl << pacl;
	}

		break;
	}
	case 's':
	{
		if ("schedule" == ALine)
		{
			schedule* ptr = dynamic_cast<schedule*>(obj);
			ss << "schedule(" << ptr->q << co << ptr->w << co << ptr->e << co << ptr->r;
		}
		else if ("sequence" == ALine)
		{
			sequence* ptr = dynamic_cast<sequence*>(obj);
			ss << "sequence(" << ptr->q << co << ptr->w << co << ptr->e;
		}
		else if ("signal_instance" == ALine)
		{
			signal_instance* ptr = dynamic_cast<signal_instance*>(obj);
			ss << "signal_instance(" << ptr->q << co << ptr->w << co << ptr->e << co << ptr->r
				<< co << ptr->t << co << ptr->y << co << ptr->u;
		}
		else if ("source_is_normal_dt" == ALine)
		{
			source_is_normal_dt* ptr = dynamic_cast<source_is_normal_dt*>(obj);
			ss << "source_is_normal_dt(" << ptr->q << co << ptr->w << co << ptr->e;
		}
		else if ("special_dt" == ALine)
		{
			special_dt* ptr = dynamic_cast<special_dt*>(obj);
			ss << "special_dt(" << ptr->q << co << ptr->w << co << ptr->e << co << ptr->r
				<< co << ptr->t << co << ptr->y << co << ptr->u;

		}
		else if ("special_op" == ALine)
		{
			special_op* ptr = dynamic_cast<special_op*>(obj);
			ss << "special_op(" << ptr->q << co << ptr->w << co << ptr->e << co << ptr->r
				<< co << ptr->t << co << ptr->y << co << ptr->u << co << ptr->i << co << ptr->o
				<< co << ptr->p;
		}
		else if ("state" == ALine)
		{
			state* ptr = dynamic_cast<state*>(obj);
			ss << "state(" << ptr->q << co << ptr->w << co << ptr->e << co << ptr->r
				<< co << ptr->t << co << ptr->y << co << br;
			//vector
			if (!ptr->u.empty())
			{
				prlst = ptr->u.size() - 1;
				for (int ii = 0; ii < prlst; ++ii) // loop until pre-last element.
				{
					ss << ptr->u[ii] << co;
				}
				ss << ptr->u.back();
			}
			ss << brcl << co << br;
			//vector2
			if (!ptr->i.empty())
			{
				prlst = ptr->i.size() - 1;
				for (int ii = 0; ii < prlst; ++ii) // loop until pre-last element.
				{
					ss << ptr->i[ii] << co;
				}
				ss << ptr->i.back();
			}
			ss << brcl;
		}
		else if ("subprogram_call" == ALine)
		{
			state_node* ptr = dynamic_cast<state_node*>(obj);
			ss << "state_node(" << ptr->q << co << ptr->w << co;
			subprogram_call* ptr2 = dynamic_cast<subprogram_call*>(obj);
			ss << "subprogram_call(" << br;
			//vector
			if (!ptr2->q.empty())
			{
				prlst = ptr2->q.size() - 1;
				for (int ii = 0; ii < prlst; ++ii) // loop until pre-last element.
				{
					ss << ptr2->q[ii] << co;
				}
				ss << ptr2->q.back();
			}
			ss << brcl << co << ptr2->w << pacl;
		}

		break;
	}
	case 't':
	{
		if ("targets_conditional_variable" == ALine)
		{
			targets_conditional_variable* ptr = dynamic_cast<targets_conditional_variable*>(obj);
			ss << "targets_conditional_variable(" << ptr->q << co << ptr->w << co << ptr->e << co << ptr->r;
		}
		else if ("top_level_call" == ALine)
		{
			top_level_call* ptr = dynamic_cast<top_level_call*>(obj);
			ss << "top_level_call(" << ptr->q << co << ptr->w << co << ptr->e << co << ptr->r
				<< co << ptr->t << co << ptr->y << co << ptr->u << co << ptr->i << co << ptr->o
				<< co << ptr->p << co << ptr->a;
		}
		else if ("top_level_call_parcs" == ALine)
		{
			top_level_call_parcs* ptr = dynamic_cast<top_level_call_parcs*>(obj);
			ss << "top_level_call_parcs(" << ptr->q << co << ptr->w << co << ptr->e << co << ptr->r
				<< co << ptr->t << co << ptr->y << co << ptr->u << co << ptr->i << co << ptr->o
				<< co << ptr->p << co << ptr->a;
		}
		else if ("top_module" == ALine)
		{
			top_module* ptr = dynamic_cast<top_module*>(obj);
			ss << "top_module(" << ptr->q;
		}
		else if ("total_local_entry" == ALine)
		{
			total_local_entry* ptr = dynamic_cast<total_local_entry*>(obj);
			ss << "total_local_entry(" << ptr->q;
		}
		else if ("totalmax_call_order" == ALine)
		{
			totalmax_call_order* ptr = dynamic_cast<totalmax_call_order*>(obj);
			ss << "totalmax_call_order(" << ptr->q << co << ptr->w << co << ptr->e;
		}
		else if ("totalmax_gross_depth" == ALine)
		{
			totalmax_gross_depth* ptr = dynamic_cast<totalmax_gross_depth*>(obj);
			ss << "totalmax_gross_depth(" << ptr->q << co << ptr->w << co << ptr->e;
		}
		else if ("transition_to_be_rescheduled" == ALine)
		{
			transition_to_be_rescheduled* ptr = dynamic_cast<transition_to_be_rescheduled*>(obj);
			ss << "transition_to_be_rescheduled(" << ptr->q << co << ptr->w << co << ptr->e << co << ptr->r << co << ptr->t;
		}
		else if ("type_def" == ALine)
		{
			type_def* ptr = dynamic_cast<type_def*>(obj);
			ss << "type_def(" << ptr->q << co << ptr->w << co << ptr->e << co << ptr->r
				<< co << ptr->t << co << ptr->y << co << ptr->u << co << ptr->i << co << ptr->o;
		}

		break;
	}
	case 'u':
	{

		break;
	}
	case 'v':
	{
		if ("var_guards" == ALine)
		{
			var_guards* ptr = dynamic_cast<var_guards*>(obj);
			ss << "var_guards(" << ptr->q << co << ptr->w << co << br;
			//vector
			if (!ptr->e.empty())
			{
				prlst = ptr->e.size() - 1;
				for (int ii = 0; ii < prlst; ++ii) // loop until pre-last element.
				{
					ss << ptr->e[ii] << co;
				}
				ss << ptr->e.back();
			}
			ss << brcl << co << br;
			//vector2
			if (!ptr->r.empty())
			{
				prlst = ptr->r.size() - 1;
				for (int ii = 0; ii < prlst; ++ii) // loop until pre-last element.
				{
					ss << ptr->r[ii] << co;
				}
				ss << ptr->r.back();
			}
			ss << brcl;
		}
		else if ("variable_has_been_listed" == ALine)
		{
			variable_has_been_listed* ptr = dynamic_cast<variable_has_been_listed*>(obj);
			ss << "variable_has_been_listed(" << ptr->q << co << ptr->w;
		}

		break;
	}
	case 'w':
	{
		if ("war_cessor" == ALine)
		{
			war_cessor* ptr = dynamic_cast<war_cessor*>(obj);
			ss << "war_cessor(" << ptr->q << co << ptr->w << co << ptr->e;
		}
		else if ("war_dependencies" == ALine)
		{
			war_dependencies* ptr = dynamic_cast<war_dependencies*>(obj);
			ss << "war_dependencies(" << ptr->q << co << ptr->w << co << br;
			//vector
			if (!ptr->e.empty())
			{
				prlst = ptr->e.size() - 1;
				for (int ii = 0; ii < prlst; ++ii) // loop until pre-last element.
				{
					ss << ptr->e[ii] << co;
				}
				ss << ptr->e.back();
			}
			ss << brcl << co << br;
			//vector2
			if (!ptr->r.empty())
			{
				prlst = ptr->r.size() - 1;
				for (int ii = 0; ii < prlst; ++ii) // loop until pre-last element.
				{
					ss << ptr->r[ii] << co;
				}
				ss << ptr->r.back();
			}
			ss << brcl;
		}
		else if ("waw_cessor" == ALine)
		{
			waw_cessor* ptr = dynamic_cast<waw_cessor*>(obj);
			ss << "waw_cessor(" << ptr->q << co << ptr->w << co << ptr->e;
		}
		else if ("waw_dependencies" == ALine)
		{
			waw_dependencies* ptr = dynamic_cast<waw_dependencies*>(obj);
			ss << "waw_dependencies(" << ptr->q << co << ptr->w << co << br;
			//vector
			if (!ptr->e.empty())
			{
				prlst = ptr->e.size() - 1;
				for (int ii = 0; ii < prlst; ++ii) // loop until pre-last element.
				{
					ss << ptr->e[ii] << co;
				}
				ss << ptr->e.back();
			}
			ss << brcl << co << br;
			//vector2
			if (!ptr->r.empty())
			{
				prlst = ptr->r.size() - 1;
				for (int ii = 0; ii < prlst; ++ii) // loop until pre-last element.
				{
					ss << ptr->r[ii] << co;
				}
				ss << ptr->r.back();
			}
			ss << brcl;

		}
		else if ("while_loop" == ALine)
		{
			while_loop* ptr = dynamic_cast<while_loop*>(obj);
			ss << "while_loop(" << ptr->q << co << ptr->w << co << ptr->e << co << ptr->r
				<< co << ptr->t << co << ptr->y << co << ptr->u;
		}

		break;
	}
	case 'x':
	{

		break;
	}
	case 'y':
	{

		break;
	}
	case 'z':
	{

		break;
	}
	GenfactError* ptr = new GenfactError("error for ");
	ptr->saying += typeid(*obj).name();
	ss << "Error at fact " << ptr->saying;
		
	}
	ss << pacl;
	ALine = ss.str();
	if (ALine == ")")
	cout << "lol" << endl;

	return ALine;


	//if ("type_def" == ALine)
	//{
	//	type_def* ptr = dynamic_cast<type_def*>(obj);
	//	ss << "type_def("  << ptr->q << co << ptr->w << co << ptr->e << co << ptr->r
	//		<< co << ptr->t << co << ptr->y << co << ptr->u << co << ptr->i << co << ptr->o;
	//}
	//else if ("op_def" == ALine)
	//{
	//	op_def* ptr = dynamic_cast<op_def*>(obj);
	//	ss << "op_def("  << ptr->q << co << ptr->w << co << ptr->e << co << ptr->r
	//		<< co << ptr->t << co << ptr->y << co << ptr->u;
	//}
	//else if ("hierarchy_part" == ALine)
	//{
	//	hierarchy_part* ptr = dynamic_cast<hierarchy_part*>(obj);
	//	ss << "hierarchy_part("  << ptr->q << co << ptr->w << co << ptr->e << co << ptr->r
	//		<< co << ptr->t << co << ptr->y << co << ptr->u;
	//}
	//else if ("data_stmt" == ALine)
	//{
	//	data_stmt* ptr = dynamic_cast<data_stmt*>(obj);
	//	ss << "data_stmt("  << ptr->q << co << ptr->w << co << ptr->e << co << ptr->r
	//		<< co << ptr->t << co << ptr->y;
	//}
	//else if ("prog_stmt" == ALine)
	//{
	//	prog_stmt* ptr = dynamic_cast<prog_stmt*>(obj);
	//	ss << "prog_stmt("  << ptr->q << co << ptr->w << co << ptr->e << co << ptr->r
	//		<< co << ptr->t << co << ptr->y << co << ptr->u << co << ptr->i;
	//}
	//else if ("joint_stmt" == ALine)
	//{
	//	joint_stmt* ptr = dynamic_cast<joint_stmt*>(obj);
	//	ss << "joint_stmt("  << ptr->q << co << ptr->w << co << ptr->e << co << ptr->r
	//		<< co << ptr->t << co << ptr->y;
	//}
	//else if ("call_stmt" == ALine)
	//{
	//	call_stmt* ptr = dynamic_cast<call_stmt*>(obj);
	//	ss << "call_stmt(" << ptr->q << co << ptr->w << co << ptr->e << co << br;
	//	//vector
	//	if (!ptr->r.empty())
	//	{
	//		prlst = ptr->r.size() - 1;
	//		for (int ii = 0; ii < prlst;++ii) // loop until pre-last element.
	//		{
	//			ss << ptr->r[ii] << co;
	//		}
	//		ss << ptr->r.back();
	//	}
	//	ss << brcl;
	//}
	//else if ("compo_stmt" == ALine)
	//{
	//	compo_stmt* ptr = dynamic_cast<compo_stmt*>(obj);
	//	ss << "compo_stmt(" << ptr->q << co << ptr->w << co << br;
	//	//vector
	//	if (!ptr->r.empty())
	//	{
	//		prlst = ptr->r.size() - 1;
	//		for (int ii = 0; ii < prlst; ++ii) 
	//		{
	//			ss << ptr->r[ii] << co;
	//		}
	//		ss << ptr->r.back();
	//	}
	//	ss << brcl;
	//}
	//else if ("rec_stmt" == ALine)
	//{
	//	rec_stmt* ptr = dynamic_cast<rec_stmt*>(obj);
	//	ss << "rec_stmt(" << ptr->q << co << ptr->w << co << br;
	//	//vector
	//	if (!ptr->e.empty())
	//	{
	//		prlst = ptr->e.size() - 1;
	//		for (int ii = 0; ii < prlst; ++ii) // loop until pre-last element.
	//		{
	//			ss << ptr->e[ii] << co;
	//		}
	//		ss << ptr->e.back();
	//	}
	//	ss << brcl;
	//}
	//else if ("special_op" == ALine)
	//{
	//	special_op* ptr = dynamic_cast<special_op*>(obj);
	//	ss << "special_op("  << ptr->q << co << ptr->w << co << ptr->e << co << ptr->r
	//		<< co << ptr->t << co << ptr->y << co << ptr->u << co << ptr->i << co << ptr->o
	//		<< co << ptr->p;
	//}
	//else if ("special_dt" == ALine)
	//{
	//	special_dt* ptr = dynamic_cast<special_dt*>(obj);
	//	ss << "special_dt("  << ptr->q << co << ptr->w << co << ptr->e << co << ptr->r
	//		<< co << ptr->t << co << ptr->y << co << ptr->u;
	//	
	//}
	//else if ("local_object" == ALine)
	//{
	//	local_object* ptr = dynamic_cast<local_object*>(obj);
	//	ss << "local_object("  << ptr->q << co << ptr->w << co << ptr->e << co << ptr->r
	//		<< co << ptr->t << co << ptr->y << co << ptr->u << co << ptr->i << co << ptr->o;
	//}
	//else if ("subprogram_call" == ALine)
	//{
	//	state_node* ptr = dynamic_cast<state_node*>(obj);
	//	ss << "state_node(" << ptr->q << co << ptr->w << co;
	//	subprogram_call* ptr2 = dynamic_cast<subprogram_call*>(obj);
	//	ss << "subprogram_call(" << br;
	//	//vector
	//	if (!ptr2->q.empty())
	//	{
	//		prlst = ptr2->q.size() - 1;
	//		for (int ii = 0; ii < prlst; ++ii) // loop until pre-last element.
	//		{
	//			ss << ptr2->q[ii] << co;
	//		}
	//		ss << ptr2->q.back();
	//	}
	//	ss << brcl << co << ptr2->w << pacl;
	//}
	//else if ("dataflow" == ALine)
	//{
	//	state_node* ptr = dynamic_cast<state_node*>(obj);
	//	ss << "state_node(" << ptr->q << co << ptr->w << co;
	//	dataflow* ptr2 = dynamic_cast<dataflow*>(obj);
	//	ss << "dataflow(" << br;
	//	//vector
	//	if (!ptr2->q.empty())
	//	{
	//		prlst = ptr2->q.size() - 1;
	//		for (int ii = 0; ii < prlst; ++ii) // loop until pre-last element.
	//		{
	//			ss << ptr2->q[ii] << co;
	//		}
	//		ss << ptr2->q.back();
	//	}
	//	ss << brcl << co << ptr2->w << pacl;
	//}
	//else if ("ifthen" == ALine)
	//{
	//	state_node* ptr = dynamic_cast<state_node*>(obj);
	//	ss << "state_node(" << ptr->q << co << ptr->w << co;
	//	ifthen* ptr2 = dynamic_cast<ifthen*>(obj);
	//	ss << "ifthen(" << br;
	//	//vector
	//	if (!ptr2->q.empty())
	//	{
	//		prlst = ptr2->q.size() - 1;
	//		for (int ii = 0; ii < prlst; ++ii) // loop until pre-last element.
	//		{
	//			ss << ptr2->q[ii] << co;
	//		}
	//		ss << ptr2->q.back();
	//	}
	//	ss << brcl << co << br;
	//	//vector2
	//	if (!ptr2->w.empty())
	//	{
	//		prlst = ptr2->w.size() - 1;
	//		for (int ii = 0; ii < prlst; ++ii) // loop until pre-last element.
	//		{
	//			ss << ptr2->w[ii] << co;
	//		}
	//		ss << ptr2->w.back();
	//	}
	//	ss << brcl << co << br;
	//	//vector3
	//	if (!ptr2->e.empty())
	//	{
	//		prlst = ptr2->e.size() - 1;
	//		for (int ii = 0; ii < prlst; ++ii) // loop until pre-last element.
	//		{
	//			ss << ptr2->e[ii] << co;
	//		}
	//		ss << ptr2->e.back();
	//	}
	//	ss << brcl << co << ptr2->r << co << ptr2->t << pacl;
	//}
	//else if ("jump" == ALine)	//losing align after 15 else if 
	//{
	//	state_node* ptr = dynamic_cast<state_node*>(obj);
	//	ss << "state_node(" << ptr->q << co << ptr->w << co;
	//	jump* ptr2 = dynamic_cast<jump*>(obj);
	//	ss << "jump" << pa << br;
	//	//vector
	//	if (!ptr2->q.empty())
	//	{
	//		prlst = ptr2->q.size() - 1;
	//		for (int ii = 0; ii < prlst; ++ii) // loop until pre-last element.
	//		{
	//			ss << ptr2->q[ii] << co;
	//		}
	//		ss << ptr2->q.back();
	//	}
	//	ss << brcl << co << ptr2->w << pacl;
	//}
	//else if ("return_cos" == ALine)
	//{
	//	state_node* ptr = dynamic_cast<state_node*>(obj);
	//	ss << "state_node(" << ptr->q << co << ptr->w << co;
	//	return_cos* ptr2 = dynamic_cast<return_cos*>(obj);
	//	ss << "return(" << br;
	//	//vector
	//	if (!ptr2->q.empty())
	//	{
	//		prlst = ptr2->q.size() - 1;
	//		for (int ii = 0; ii < prlst; ++ii) // loop until pre-last element.
	//		{
	//			ss << ptr2->q[ii] << co;
	//		}
	//		ss << ptr2->q.back();
	//	}
	//	ss << brcl << pacl;
	//}
	//else if ("change_op_number" == ALine)
	//{
	//	change_op_number* ptr = dynamic_cast<change_op_number*>(obj);
	//	ss << "change_op_number(" << ptr->q << co << ptr->w << co << ptr->e;
	//}
	//else if ("last_change_op_number" == ALine)
	//{
	//	last_change_op_number* ptr = dynamic_cast<last_change_op_number*>(obj);
	//	ss << "last_change_op_number(" << ptr->q << co << ptr->w << co << ptr->e;
	//}
	//else if ("op_guards" == ALine)
	//{
	//	op_guards* ptr = dynamic_cast<op_guards*>(obj);
	//	ss << "op_guards(" << ptr->q << co << ptr->w << co << br;
	//	//vector
	//	if (!ptr->e.empty())
	//	{
	//		prlst = ptr->e.size() - 1;
	//		for (int ii = 0; ii < prlst; ++ii) // loop until pre-last element.
	//		{
	//			ss << ptr->e[ii] << co;
	//		}
	//		ss << ptr->e.back();
	//	}
	//	ss << brcl << co << br;
	//	//vector2
	//	if (!ptr->r.empty())
	//	{
	//		prlst = ptr->r.size() - 1;
	//		for (int ii = 0; ii < prlst; ++ii) // loop until pre-last element.
	//		{
	//			ss << ptr->r[ii] << co;
	//		}
	//		ss << ptr->r.back();
	//	}
	//	ss << brcl;
	//}
	//else if ("var_guards" == ALine)
	//{
	//	var_guards* ptr = dynamic_cast<var_guards*>(obj);
	//	ss << "var_guards("  << ptr->q << co << ptr->w << co << br;
	//	//vector
	//	if (!ptr->e.empty())
	//	{
	//		prlst = ptr->e.size() - 1;
	//		for (int ii = 0; ii < prlst; ++ii) // loop until pre-last element.
	//		{
	//			ss << ptr->e[ii] << co;
	//		}
	//		ss << ptr->e.back();
	//	}
	//	ss << brcl << co << br;
	//	//vector2
	//	if (!ptr->r.empty())
	//	{
	//		prlst = ptr->r.size() - 1;
	//		for (int ii = 0; ii < prlst; ++ii) // loop until pre-last element.
	//		{
	//			ss << ptr->r[ii] << co;
	//		}
	//		ss << ptr->r.back();
	//	}
	//	ss << brcl;
	//}
	//else if ("guard_pair" == ALine)
	//{
	//	guard_pair* ptr = dynamic_cast<guard_pair*>(obj);
	//	ss << "guard_pair(" << ptr->q << co << ptr->w << co << ptr->e << co << ptr->r;
	//}
	//else if ("guard_cond" == ALine)
	//{
	//	guard_cond* ptr = dynamic_cast<guard_cond*>(obj);
	//	ss << "guard_cond("  << ptr->q << co << ptr->w << co << ptr->e << co << ptr->r;
	//}
	//else if ("predecessors" == ALine)
	//{
	//	predecessors* ptr = dynamic_cast<predecessors*>(obj);
	//	ss << "predecessors("  << ptr->q << co << ptr->w << co << br;
	//	//vector
	//	if (!ptr->e.empty())
	//	{
	//		prlst = ptr->e.size() - 1;
	//		for (int ii = 0; ii < prlst; ++ii) // loop until pre-last element.
	//		{
	//			ss << ptr->e[ii] << co;
	//		}
	//		ss << ptr->e.back();
	//	}
	//	ss << brcl;


	//}
	//else if ("cessor" == ALine)
	//{
	//	cessor* ptr = dynamic_cast<cessor*>(obj);
	//	ss << "cessor("  << ptr->q << co << ptr->w << co << ptr->e ;
	//}
	//else if ("cessor_kind" == ALine)
	//{
	//	cessor_kind* ptr = dynamic_cast<cessor_kind*>(obj);
	//	ss << "cessor_kind("  << ptr->q << co << ptr->w << co << ptr->e << co << ptr->r
	//		<< co << ptr->t << co << ptr->y << co << br;
	//	//vector
	//	if (!ptr->u.empty())
	//	{
	//		prlst = ptr->u.size() - 1;
	//		for (int ii = 0; ii < prlst; ++ii) // loop until pre-last element.
	//		{
	//			ss << ptr->u[ii] << co;
	//		}
	//		ss << ptr->u.back();
	//	}
	//	ss << brcl;

	//}
	//else if ("old_schedule" == ALine)
	//{
	//	old_schedule* ptr = dynamic_cast<old_schedule*>(obj);
	//	ss << "old_schedule("  << ptr->q;
	//}
	//else if ("new_schedule" == ALine)
	//{
	//	new_schedule* ptr = dynamic_cast<new_schedule*>(obj);
	//	ss << "new_schedule("  << ptr->q;
	//}
	//else if ("local_ifthen_chain_end_operations_were_written" == ALine)
	//{
	//	local_ifthen_chain_end_operations_were_written* ptr = dynamic_cast<local_ifthen_chain_end_operations_were_written*>(obj);
	//	ss << "local_ifthen_chain_end_operations_were_written("  << ptr->q;
	//}
	//else if ("calls_list" == ALine)
	//{
	//	calls_list* ptr = dynamic_cast<calls_list*>(obj);
	//	ss << "calls_list("  << ptr->q << co << ptr->w << co << ptr->e << co << br;
	//	//vector
	//	if (!ptr->r.empty())
	//	{
	//		prlst = ptr->r.size() - 1;
	//		for (int ii = 0; ii < prlst; ++ii) // loop until pre-last element.
	//		{
	//			ss << ptr->r[ii] << co;
	//		}
	//		ss << ptr->r.back();
	//	}
	//	ss << brcl;
	//}
	//else if ("composites_list" == ALine)
	//{
	//	composites_list* ptr = dynamic_cast<composites_list*>(obj);
	//	ss << "composites_list("  << ptr->q << co << ptr->w << co << br;
	//	//vector
	//	if (!ptr->e.empty())
	//	{
	//		prlst = ptr->e.size() - 1;
	//		for (int ii = 0; ii < prlst; ++ii) // loop until pre-last element.
	//		{
	//			ss << ptr->e[ii] << co;
	//		}
	//		ss << ptr->e.back();
	//	}
	//	ss << brcl;
	//}
	//else if ("record_aggregates_list" == ALine)
	//{
	//	record_aggregates_list* ptr = dynamic_cast<record_aggregates_list*>(obj);
	//	ss << "record_aggregates_list(" << ptr->q << co << ptr->w << co << br;
	//	//vector
	//	if (!ptr->e.empty())
	//	{
	//		prlst = ptr->e.size() - 1;
	//		for (int ii = 0; ii < prlst; ++ii) // loop until pre-last element.
	//		{
	//			ss << ptr->e[ii] << co;
	//		}
	//		ss << ptr->e.back();
	//	}
	//	ss << brcl;
	//}
	//else if ("mem_port" == ALine)
	//{
	//	mem_port* ptr = dynamic_cast<mem_port*>(obj);
	//	ss << "mem_port(" << ptr->q << co << ptr->w << co << ptr->e << co << ptr->r
	//		<< co << ptr->t << co << ptr->y << co << ptr->u << co << ptr->i << co << ptr->o
	//		<< co << ptr->p << co << ptr->a << co << ptr->s << co << ptr->d;
	//}
	//else if ("global_declarations" == ALine)
	//{
	//	stringstream tt;
	//	int			ii = 0;
	//	size_t		vs;
	//	global_declarations* ptr = dynamic_cast<global_declarations*>(obj);
	//	ss << "global_declarations(" << br;
	//	if (!ptr->q.empty())
	//	{
	//		vs = ptr->q.size();
	//		for (int ii = 0; ii < vs; ii++)
	//		{
	//			ss << "local_object(" << ptr->q[ii].q << co << ptr->q[ii].w << co << ptr->q[ii].e << co << ptr->q[ii].r << co
	//				<< ptr->q[ii].t << co << ptr->q[ii].y << co << ptr->q[ii].u << co << ptr->q[ii].i << co << ptr->q[ii].o << pacl << co;
	//		}
	//		string tmp = ss.str();
	//		tmp.resize(tmp.size() - 1);  // getting rid of the last coma
	//		swap(ss, tt);
	//		ss << tmp;
	//	}
	//	ss << brcl << co << ptr->w;
	//}
	//else if ("source_is_normal_dt" == ALine)
	//{
	//	source_is_normal_dt* ptr = dynamic_cast<source_is_normal_dt*>(obj);
	//	ss << "source_is_normal_dt("  << ptr->q << co << ptr->w << co << ptr->e;
	//}
	//else if ("combo" == ALine)
	//{
	//	combo* ptr = dynamic_cast<combo*>(obj);
	//	ss << "combo("  << ptr->q << co << ptr->w << co << ptr->e;
	//}
	//else if ("sequence" == ALine)
	//{
	//	sequence* ptr = dynamic_cast<sequence*>(obj);
	//	ss << "sequence("  << ptr->q << co << ptr->w << co << ptr->e;
	//}
	//else if ("for_loop" == ALine)
	//{
	//	for_loop* ptr = dynamic_cast<for_loop*>(obj);
	//	ss << "for_loop("  << ptr->q << co << ptr->w << co << ptr->e << co << ptr->r
	//		<< co << ptr->t << co << ptr->y << co << ptr->u << co << ptr->i << co << ptr->o
	//		<< co << ptr->p << co << ptr->a << co << ptr->s << co << ptr->d;
	//}
	//else if ("last_for_loop_entry" == ALine)
	//{
	//	last_for_loop_entry* ptr = dynamic_cast<last_for_loop_entry*>(obj);
	//	ss << "last_for_loop_entry("  << ptr->q;
	//}
	//else if ("while_loop" == ALine)
	//{
	//	while_loop* ptr = dynamic_cast<while_loop*>(obj);
	//	ss << "while_loop("  << ptr->q << co << ptr->w << co << ptr->e << co << ptr->r
	//		<< co << ptr->t << co << ptr->y << co << ptr->u;
	//}
	//else if ("last_while_loop_entry" == ALine)
	//{
	//	last_while_loop_entry* ptr = dynamic_cast<last_while_loop_entry*>(obj);
	//	ss << "last_while_loop_entry("  << ptr->q;
	//}
	//else if ("possible_end_if" == ALine)
	//{
	//	possible_end_if* ptr = dynamic_cast<possible_end_if*>(obj);
	//	ss << "possible_end_if("  << ptr->q << co << br;
	//	//vector
	//	if (!ptr->w.empty())
	//	{
	//		prlst = ptr->w.size() - 1;
	//		for (int ii = 0; ii < prlst; ++ii) // loop until pre-last element.
	//		{
	//			ss << ptr->w[ii] << co;
	//		}
	//		ss << ptr->w.back();
	//	}
	//	ss << brcl;
	//}
	//else if ("end_if" == ALine)
	//{
	//	end_if* ptr = dynamic_cast<end_if*>(obj);
	//	ss << "end_if("  << ptr->q << co << br;
	//	//vector
	//	if (!ptr->w.empty())
	//	{
	//		prlst = ptr->w.size() - 1;
	//		for (int ii = 0; ii < prlst; ++ii) // loop until pre-last element.
	//		{
	//			ss << ptr->w[ii] << co;
	//		}
	//		ss << ptr->w.back();
	//	}
	//	ss << brcl;

	//}
	//else if ("nested_cond_fact" == ALine)
	//{
	//	nested_cond_fact* ptr = dynamic_cast<nested_cond_fact*>(obj);
	//	ss << "nested_cond_fact("  << ptr->q << co << br;
	//	//vector
	//	if (!ptr->w.empty())
	//	{
	//		prlst = ptr->w.size() - 1;
	//		for (int ii = 0; ii < prlst; ++ii) // loop until pre-last element.
	//		{
	//			ss << ptr->w[ii] << co;
	//		}
	//		ss << ptr->w.back();
	//	}
	//	ss << brcl;
	//}
	//else if ("top_level_call" == ALine)
	//{
	//	top_level_call* ptr = dynamic_cast<top_level_call*>(obj);
	//	ss << "top_level_call("  << ptr->q << co << ptr->w << co << ptr->e << co << ptr->r
	//		<< co << ptr->t << co << ptr->y << co << ptr->u << co << ptr->i << co << ptr->o
	//		<< co << ptr->p << co << ptr->a;
	//}
	//else if ("top_level_call_parcs" == ALine)
	//{
	//	top_level_call_parcs* ptr = dynamic_cast<top_level_call_parcs*>(obj);
	//	ss << "top_level_call_parcs("  << ptr->q << co << ptr->w << co << ptr->e << co << ptr->r
	//		<< co << ptr->t << co << ptr->y << co << ptr->u << co << ptr->i << co << ptr->o
	//		<< co << ptr->p << co << ptr->a;
	//}
	//else if ("added_aux_call_ios" == ALine)
	//{
	//	added_aux_call_ios* ptr = dynamic_cast<added_aux_call_ios*>(obj);
	//	ss << "added_aux_call_ios("  << ptr->q << co << ptr->w ;
	//}
	//else if ("added_aux_call_ios1" == ALine)
	//{
	//	added_aux_call_ios1* ptr = dynamic_cast<added_aux_call_ios1*>(obj);
	//	ss << "added_aux_call_ios1("  << ptr->q << co << ptr->w << co << ptr->e;
	//}
	//else if ("added_aux_call_signals" == ALine)
	//{
	//	added_aux_call_signals* ptr = dynamic_cast<added_aux_call_signals*>(obj);
	//	ss << "added_aux_call_signals("  << ptr->q << co << ptr->w;
	//}
	//else if ("found_call_operator" == ALine)
	//{
	//	found_call_operator* ptr = dynamic_cast<found_call_operator*>(obj);
	//	ss << "found_call_operator("  << ptr->q << co << ptr->w;
	//}
	//else if ("added_verilog_aux_call_outputs" == ALine)
	//{
	//	added_verilog_aux_call_outputs* ptr = dynamic_cast<added_verilog_aux_call_outputs*>(obj);
	//	ss << "added_verilog_aux_call_outputs("  << ptr->q << co << ptr->w << co << ptr->e;
	//}
	//else if ("raw_dependencies" == ALine)
	//{
	//	raw_dependencies* ptr = dynamic_cast<raw_dependencies*>(obj);
	//	ss << "raw_dependencies("  << ptr->q << co << ptr->w << co << br;
	//	//vector
	//	if (!ptr->e.empty())
	//	{
	//		prlst = ptr->e.size() - 1;
	//		for (int ii = 0; ii < prlst; ++ii) // loop until pre-last element.
	//		{
	//			ss << ptr->e[ii] << co;
	//		}
	//		ss << ptr->e.back();
	//	}
	//	ss << brcl << co << br;
	//	//vector2
	//	if (!ptr->r.empty())
	//	{
	//		prlst = ptr->r.size() - 1;
	//		for (int ii = 0; ii < prlst; ++ii) // loop until pre-last element.
	//		{
	//			ss << ptr->r[ii] << co;
	//		}
	//		ss << ptr->r.back();
	//	}
	//	ss << brcl;

	//}
	//else if ("war_dependencies" == ALine)
	//{
	//	war_dependencies* ptr = dynamic_cast<war_dependencies*>(obj);
	//	ss << "war_dependencies(" << ptr->q << co << ptr->w << co << br;
	//	//vector
	//	if (!ptr->e.empty())
	//	{
	//		prlst = ptr->e.size() - 1;
	//		for (int ii = 0; ii < prlst; ++ii) // loop until pre-last element.
	//		{
	//			ss << ptr->e[ii] << co;
	//		}
	//		ss << ptr->e.back();
	//	}
	//	ss << brcl << co << br;
	//	//vector2
	//	if (!ptr->r.empty())
	//	{
	//		prlst = ptr->r.size() - 1;
	//		for (int ii = 0; ii < prlst; ++ii) // loop until pre-last element.
	//		{
	//			ss << ptr->r[ii] << co;
	//		}
	//		ss << ptr->r.back();
	//	}
	//	ss << brcl;
	//}
	//else if ("waw_dependencies" == ALine)
	//{
	//	waw_dependencies* ptr = dynamic_cast<waw_dependencies*>(obj);
	//	ss << "waw_dependencies("  << ptr->q << co << ptr->w << co << br;
	//	//vector
	//	if (!ptr->e.empty())
	//	{
	//		prlst = ptr->e.size() - 1;
	//		for (int ii = 0; ii < prlst; ++ii) // loop until pre-last element.
	//		{
	//			ss << ptr->e[ii] << co;
	//		}
	//		ss << ptr->e.back();
	//	}
	//	ss << brcl << co << br;
	//	//vector2
	//	if (!ptr->r.empty())
	//	{
	//		prlst = ptr->r.size() - 1;
	//		for (int ii = 0; ii < prlst; ++ii) // loop until pre-last element.
	//		{
	//			ss << ptr->r[ii] << co;
	//		}
	//		ss << ptr->r.back();
	//	}
	//	ss << brcl;

	//}
	//else if ("schedule" == ALine)
	//{
	//	schedule* ptr = dynamic_cast<schedule*>(obj);
	//	ss << "schedule("  << ptr->q << co << ptr->w << co << ptr->e << co << ptr->r;
	//}
	//else if ("last_conditional_execution" == ALine)
	//{
	//	last_conditional_execution* ptr = dynamic_cast<last_conditional_execution*>(obj);
	//	ss << "last_conditional_execution("  << ptr->q << co << ptr->w;
	//}
	//else if ("conditional_operations" == ALine)
	//{
	//	conditional_operations* ptr = dynamic_cast<conditional_operations*>(obj);
	//	ss << "conditional_operations("  << ptr->q << co << ptr->w << co << ptr->e << co << ptr->r
	//		<< co << br;
	//	//vector
	//	if (!ptr->t.empty())
	//	{
	//		prlst = ptr->t.size() - 1;
	//		for (int ii = 0; ii < prlst; ++ii) // loop until pre-last element.
	//		{
	//			ss << ptr->t[ii] << co;
	//		}
	//		ss << ptr->t.back();
	//	}
	//	ss << brcl << co << br;
	//	//vector2
	//	if (!ptr->y.empty())
	//	{
	//		prlst = ptr->y.size() - 1;
	//		for (int ii = 0; ii < prlst; ++ii) // loop until pre-last element.
	//		{
	//			ss << ptr->y[ii] << co;
	//		}
	//		ss << ptr->y.back();
	//	}
	//	ss << brcl << co << br;
	//	//vector3
	//	if (!ptr->u.empty())
	//	{
	//		prlst = ptr->u.size() - 1;
	//		for (int ii = 0; ii < prlst; ++ii) // loop until pre-last element.
	//		{
	//			ss << ptr->u[ii] << co;
	//		}
	//		ss << ptr->u.back();
	//	}
	//	ss << brcl << co << br;
	//	//vector4
	//	if (!ptr->i.empty())
	//	{
	//		prlst = ptr->i.size() - 1;
	//		for (int ii = 0; ii < prlst; ++ii) // loop until pre-last element.
	//		{
	//			ss << ptr->i[ii] << co;
	//		}
	//		ss << ptr->i.back();
	//	}
	//	ss << brcl;
	//}
	//else if ("last_conditional_transition_of_schedule" == ALine)
	//{
	//	last_conditional_transition_of_schedule* ptr = dynamic_cast<last_conditional_transition_of_schedule*>(obj);
	//	ss << "last_conditional_transition_of_schedule("  << ptr->q << co << ptr->w << co << ptr->e;
	//}
	//else if ("transition_to_be_rescheduled" == ALine)
	//{
	//	transition_to_be_rescheduled* ptr = dynamic_cast<transition_to_be_rescheduled*>(obj);
	//	ss << "transition_to_be_rescheduled(" << ptr->q << co << ptr->w << co << ptr->e << co << ptr->r << co << ptr->t;
	//}
	//else if ("last_conditional_transition" == ALine)
	//{
	//	last_conditional_transition* ptr = dynamic_cast<last_conditional_transition*>(obj);
	//	ss << "last_conditional_transition(" << ptr->q << co << ptr->w;
	//}
	//else if ("conditional_transitions" == ALine)
	//{
	//	conditional_transitions* ptr = dynamic_cast<conditional_transitions*>(obj);
	//	ss << "conditional_transitions(" << ptr->q << co << ptr->w << co << ptr->e << co << ptr->r
	//		<< co << ptr->t << co << ptr->y << co << ptr->u << co << ptr->i;
	//}
	//else if ("state" == ALine)
	//{
	//	state* ptr = dynamic_cast<state*>(obj);
	//	ss << "state(" << ptr->q << co << ptr->w << co << ptr->e << co << ptr->r
	//		<< co << ptr->t << co << ptr->y << co << br;
	//	//vector
	//	if (!ptr->u.empty())
	//	{
	//		prlst = ptr->u.size() - 1;
	//		for (int ii = 0; ii < prlst; ++ii) // loop until pre-last element.
	//		{
	//			ss << ptr->u[ii] << co;
	//		}
	//		ss << ptr->u.back();
	//	}
	//	ss << brcl << co << br;
	//	//vector2
	//	if (!ptr->i.empty())
	//	{
	//		prlst = ptr->i.size() - 1;
	//		for (int ii = 0; ii < prlst; ++ii) // loop until pre-last element.
	//		{
	//			ss << ptr->i[ii] << co;
	//		}
	//		ss << ptr->i.back();
	//	}
	//	ss << brcl;
	//}
	//else if ("rescheduled" == ALine)
	//{
	//	rescheduled* ptr = dynamic_cast<rescheduled*>(obj);
	//	ss << "rescheduled(" << ptr->q << co << ptr->w << co << ptr->e << co << ptr->r
	//		<< co << ptr->t;
	//}
	//else if ("last_rescheduled" == ALine)
	//{
	//	last_rescheduled* ptr = dynamic_cast<last_rescheduled*>(obj);
	//	ss << "last_rescheduled(" << ptr->q << co << ptr->w << co << ptr->e << co << ptr->r << co << ptr->t;
	//}
	//else if ("raw_cessor" == ALine)
	//{
	//	raw_cessor* ptr = dynamic_cast<raw_cessor*>(obj);
	//	ss << "raw_cessor(" << ptr->q << co << ptr->w << co << ptr->e;
	//}
	//else if ("war_cessor" == ALine)
	//{
	//	war_cessor* ptr = dynamic_cast<war_cessor*>(obj);
	//	ss << "war_cessor(" << ptr->q << co << ptr->w << co << ptr->e;
	//}
	//else if ("waw_cessor" == ALine)
	//{
	//	waw_cessor* ptr = dynamic_cast<waw_cessor*>(obj);
	//	ss << "waw_cessor(" << ptr->q << co << ptr->w << co << ptr->e;
	//}
	//else if ("op_resource" == ALine)
	//{
	//	op_resource* ptr = dynamic_cast<op_resource*>(obj);
	//	ss << "op_resource(" << ptr->q << co << ptr->w << co << ptr->e;
	//}
	//else if ("global_resource" == ALine)
	//{
	//	global_resource* ptr = dynamic_cast<global_resource*>(obj);
	//	ss << "global_resource(" << ptr->q;
	//}
	//else if ("module_g_resource" == ALine)
	//{
	//	module_g_resource* ptr = dynamic_cast<module_g_resource*>(obj);
	//	ss << "module_g_resource(" << ptr->q << co << ptr->w;
	//}
	//else if ("cf_previous_op" == ALine)
	//{
	//	cf_previous_op* ptr = dynamic_cast<cf_previous_op*>(obj);
	//	ss << "cf_previous_op(" << ptr->q << co << ptr->w << co << ptr->e << co << ptr->r;
	//}
	//else if ("cf_previous_state" == ALine)
	//{
	//	cf_previous_state* ptr = dynamic_cast<cf_previous_state*>(obj);
	//	ss << "cf_previous_state(" << ptr->q << co << ptr->w << co << ptr->e << co << ptr->r;
	//}
	//else if ("pred_candidate_examined" == ALine)
	//{
	//	pred_candidate_examined* ptr = dynamic_cast<pred_candidate_examined*>(obj);
	//	ss << "pred_candidate_examined(" << ptr->q << co << ptr->w << co << ptr->e;
	//}
	//else if ("reentrant_triangle" == ALine)
	//{
	//	reentrant_triangle* ptr = dynamic_cast<reentrant_triangle*>(obj);
	//	ss << "reentrant_triangle(" << ptr->q << co << ptr->w << co << ptr->e << co << ptr->r << co << br;
	//	//vector
	//	if (!ptr->t.empty())
	//	{
	//		prlst = ptr->t.size() - 1;
	//		for (int ii = 0; ii < prlst; ++ii) // loop until pre-last element.
	//		{
	//			ss << ptr->t[ii] << co;
	//		}
	//		ss << ptr->t.back();
	//	}
	//	ss << brcl << co << br;
	//	//vector2
	//	if (!ptr->y.empty())
	//	{
	//		prlst = ptr->y.size() - 1;
	//		for (int ii = 0; ii < prlst; ++ii) // loop until pre-last element.
	//		{
	//			ss << ptr->y[ii] << co;
	//		}
	//		ss << ptr->y.back();
	//	}
	//	ss << brcl << co << br;
	//	//vector3
	//	if (!ptr->u.empty())
	//	{
	//		prlst = ptr->u.size() - 1;
	//		for (int ii = 0; ii < prlst; ++ii) // loop until pre-last element.
	//		{
	//			ss << ptr->u[ii] << co;
	//		}
	//		ss << ptr->u.back();
	//	}
	//	ss << brcl << co << br;
	//	//vector4
	//	if (!ptr->i.empty())
	//	{
	//		prlst = ptr->i.size() - 1;
	//		for (int ii = 0; ii < prlst; ++ii) // loop until pre-last element.
	//		{
	//			ss << ptr->i[ii] << co;
	//		}
	//		ss << ptr->i.back();
	//	}
	//	ss << brcl << co << br;
	//	//vector5
	//	if (!ptr->o.empty())
	//	{
	//		prlst = ptr->o.size() - 1;
	//		for (int ii = 0; ii < prlst; ++ii) // loop until pre-last element.
	//		{
	//			ss << ptr->o[ii] << co;
	//		}
	//		ss << ptr->o.back();
	//	}
	//	ss << brcl << co << br;
	//	//vector6
	//	if (!ptr->p.empty())
	//	{
	//		prlst = ptr->p.size() - 1;
	//		for (int ii = 0; ii < prlst; ++ii) // loop until pre-last element.
	//		{
	//			ss << ptr->p[ii] << co;
	//		}
	//		ss << ptr->p.back();
	//	}
	//	ss << brcl << co << ptr->a << co << ptr->s << co << ptr->d << co << ptr->f;
	//}
	//else if ("last_reentrant_triangle" == ALine)
	//{
	//	last_reentrant_triangle* ptr = dynamic_cast<last_reentrant_triangle*>(obj);
	//	ss << "last_reentrant_triangle(" << ptr->q << co << ptr->w;
	//}
	//else if ("last_schedule_state" == ALine)
	//{
	//	last_schedule_state* ptr = dynamic_cast<last_schedule_state*>(obj);
	//	ss << "last_schedule_state(" << ptr->q << co << ptr->w << co << ptr->e;
	//}
	//else if ("conditional_incomplete" == ALine)
	//{
	//	conditional_incomplete* ptr = dynamic_cast<conditional_incomplete*>(obj);
	//	ss << "conditional_incomplete(" << ptr->q << co << ptr->w << co << ptr->e << co << ptr->r << co << br;
	//	//vector
	//	if (!ptr->t.empty())
	//	{
	//		prlst = ptr->t.size() - 1;
	//		for (int ii = 0; ii < prlst; ++ii) // loop until pre-last element.
	//		{
	//			ss << ptr->t[ii] << co;
	//		}
	//		ss << ptr->t.back();
	//	}
	//	ss << brcl << co << br;
	//	//vector2
	//	if (!ptr->y.empty())
	//	{
	//		prlst = ptr->y.size() - 1;
	//		for (int ii = 0; ii < prlst; ++ii) // loop until pre-last element.
	//		{
	//			ss << ptr->y[ii] << co;
	//		}
	//		ss << ptr->y.back();
	//	}
	//	ss << brcl << co << br;
	//	//vector3
	//	if (!ptr->u.empty())
	//	{
	//		prlst = ptr->u.size() - 1;
	//		for (int ii = 0; ii < prlst; ++ii) // loop until pre-last element.
	//		{
	//			ss << ptr->u[ii] << co;
	//		}
	//		ss << ptr->u.back();
	//	}
	//	ss << brcl << co << br;
	//	//vector4
	//	if (!ptr->i.empty())
	//	{
	//		prlst = ptr->i.size() - 1;
	//		for (int ii = 0; ii < prlst; ++ii) // loop until pre-last element.
	//		{
	//			ss << ptr->i[ii] << co;
	//		}
	//		ss << ptr->i.back();
	//	}
	//	ss << brcl << co << br;
	//	//vector5
	//	if (!ptr->o.empty())
	//	{
	//		prlst = ptr->o.size() - 1;
	//		for (int ii = 0; ii < prlst; ++ii) // loop until pre-last element.
	//		{
	//			ss << ptr->o[ii] << co;
	//		}
	//		ss << ptr->o.back();
	//	}
	//	ss << brcl << co << br;
	//	//vector6
	//	if (!ptr->p.empty())
	//	{
	//		prlst = ptr->p.size() - 1;
	//		for (int ii = 0; ii < prlst; ++ii) // loop until pre-last element.
	//		{
	//			ss << ptr->p[ii] << co;
	//		}
	//		ss << ptr->p.back();
	//	}
	//	ss << brcl << co << ptr->a << co << ptr->s << co << ptr->d << co << ptr->f << co << ptr->g
	//		<< co << ptr->h << co << ptr->j << co << ptr->k << co << ptr->l << co << ptr->z
	//		<< co << ptr->x;
	//}
	//else if ("mixed_incomplete_state_lists" == ALine)
	//{
	//	mixed_incomplete_state_lists* ptr = dynamic_cast<mixed_incomplete_state_lists*>(obj);
	//	ss << "mixed_incomplete_state_lists(" << ptr->q << co << ptr->w << co << ptr->e << co << br;
	//	//vector
	//	if (!ptr->r.empty())
	//	{
	//		prlst = ptr->r.size() - 1;
	//		for (int ii = 0; ii < prlst; ++ii) // loop until pre-last element.
	//		{
	//			ss << ptr->r[ii] << co;
	//		}
	//		ss << ptr->r.back();
	//	}
	//	ss << brcl << co << br;
	//	//vector2
	//	if (!ptr->t.empty())
	//	{
	//		prlst = ptr->t.size() - 1;
	//		for (int ii = 0; ii < prlst; ++ii) // loop until pre-last element.
	//		{
	//			ss << ptr->t[ii] << co;
	//		}
	//		ss << ptr->t.back();
	//	}
	//	ss << brcl;
	//}
	//else if ("linear_incomplete_node" == ALine)
	//{
	//	linear_incomplete_node* ptr = dynamic_cast<linear_incomplete_node*>(obj);
	//	ss << "linear_incomplete_node(" << ptr->q << co << ptr->w << co << ptr->e << co << ptr->y << co << br;
	//	//vector
	//	if (!ptr->r.empty())
	//	{
	//		prlst = ptr->r.size() - 1;
	//		for (int ii = 0; ii < prlst; ++ii) // loop until pre-last element.
	//		{
	//			ss << ptr->r[ii] << co;
	//		}
	//		ss << ptr->r.back();
	//	}
	//	ss << brcl << co << br;
	//	//vector2
	//	if (!ptr->t.empty())
	//	{
	//		prlst = ptr->t.size() - 1;
	//		for (int ii = 0; ii < prlst; ++ii) // loop until pre-last element.
	//		{
	//			ss << ptr->t[ii] << co;
	//		}
	//		ss << ptr->t.back();
	//	}
	//	ss << brcl;
	//}
	//else if ("incomplete_links" == ALine)
	//{
	//	incomplete_links* ptr = dynamic_cast<incomplete_links*>(obj);
	//	ss << "incomplete_links(" << ptr->q << co << ptr->w << co << ptr->e << co << ptr->r
	//		<< co << ptr->t << co << ptr->y << co << ptr->u << co << ptr->i << co << ptr->o
	//		<< co << ptr->p;
	//}
	//else if ("last_incomplete" == ALine)
	//{
	//	last_incomplete* ptr = dynamic_cast<last_incomplete*>(obj);
	//	ss << "last_incomplete(" << ptr->q << co << ptr->w << co << ptr->e << co << ptr->r;
	//}
	//else if ("global_nils" == ALine)
	//{
	//	global_nils* ptr = dynamic_cast<global_nils*>(obj);
	//	ss << "global_nils(" << br ;
	//	//vector
	//	if (!ptr->q.empty())
	//	{
	//		prlst = ptr->q.size() - 1;
	//		for (int ii = 0; ii < prlst; ++ii) // loop until pre-last element.
	//		{
	//			ss << "nil_node" << pa;

	//			ss << ptr->q[ii].q << co << ptr->q[ii].w << pacl << co;
	//		}
	//		ss << "nil_node" << pa << ptr->q.back().q << co << ptr->q.back().w;
	//		ss << pacl;
	//	}
	//	ss << brcl;
	//}
	//else if ("current_module" == ALine)
	//{
	//	current_module* ptr = dynamic_cast<current_module*>(obj);
	//	ss << "current_module(" << ptr->q;
	//}
	//else if ("last_linear_incomplete_node" == ALine)
	//{
	//	last_linear_incomplete_node* ptr = dynamic_cast<last_linear_incomplete_node*>(obj);
	//	ss << "last_linear_incomplete_node(" << ptr->q;
	//}
	//else if ("operator_instances" == ALine)
	//{
	//	operator_instances* ptr = dynamic_cast<operator_instances*>(obj);
	//	ss << "operator_instances(" << ptr->q << co << ptr->w;
	//}
	//else if ("massively_parallel_style" == ALine)
	//{
	//	massively_parallel_style* ptr = dynamic_cast<massively_parallel_style*>(obj);
	//	ss << "massively_parallel_style(" << ptr->q;
	//}
	//else if ("hdl_style" == ALine)
	//{
	//	hdl_style* ptr = dynamic_cast<hdl_style*>(obj);
	//	ss << "hdl_style(" << ptr->q;
	//}
	//else if ("op_instance" == ALine)
	//{
	//	op_instance* ptr = dynamic_cast<op_instance*>(obj);
	//	ss << "op_instance(" << ptr->q << co << ptr->w << co << ptr->e << co << ptr->r
	//		<< co << ptr->t;
	//}
	//else if ("last_op_instance" == ALine)
	//{
	//	last_op_instance* ptr = dynamic_cast<last_op_instance*>(obj);
	//	ss << "last_op_instance(" << ptr->q << co << ptr->w << co << ptr->e;
	//}
	//else if ("op_in_a_state" == ALine)
	//{
	//	op_in_a_state* ptr = dynamic_cast<op_in_a_state*>(obj);
	//	ss << "op_in_a_state(" << ptr->q << co << ptr->w << co << ptr->e << co << ptr->r
	//		<< co << ptr->t;
	//}
	//else if ("last_op_in_a_state" == ALine)
	//{
	//	last_op_in_a_state* ptr = dynamic_cast<last_op_in_a_state*>(obj);
	//	ss << "last_op_in_a_state(" << ptr->q << co << ptr->w << co << ptr->e << co << ptr->r;
	//}
	//else if ("signal_instance" == ALine)
	//{
	//	signal_instance* ptr = dynamic_cast<signal_instance*>(obj);
	//	ss << "signal_instance(" << ptr->q << co << ptr->w << co << ptr->e << co << ptr->r
	//		<< co << ptr->t << co << ptr->y << co << ptr->u;
	//}
	//else if ("last_signal_instance" == ALine)
	//{
	//	last_signal_instance* ptr = dynamic_cast<last_signal_instance*>(obj);
	//	ss << "last_signal_instance(" << ptr->q << co << ptr->w;
	//}
	//else if ("output_instance" == ALine)
	//{
	//	output_instance* ptr = dynamic_cast<output_instance*>(obj);
	//	ss << "output_instance(" << ptr->q << co << ptr->w << co << ptr->e << co << ptr->r
	//		<< co << ptr->t << co << ptr->y;
	//}
	//else if ("last_output_instance" == ALine)
	//{
	//	last_output_instance* ptr = dynamic_cast<last_output_instance*>(obj);
	//	ss << "last_output_instance(" << ptr->q << co << ptr->w;
	//}
	//else if ("operator_instance_stats" == ALine)
	//{
	//	operator_instance_stats* ptr = dynamic_cast<operator_instance_stats*>(obj);
	//	ss << "operator_instance_stats(" << ptr->q << co << ptr->w << co << ptr->e << co << ptr->r;
	//}
	//else if ("consecutive_106" == ALine)
	//{
	//	consecutive_106* ptr = dynamic_cast<consecutive_106*>(obj);
	//	ss << "consecutive_106(" << ptr->q;
	//}
	//else if ("operation_order" == ALine)
	//{
	//	operation_order* ptr = dynamic_cast<operation_order*>(obj);
	//	ss << "operation_order(" << ptr->q << co << ptr->w << co << ptr->e << co << ptr->r
	//		<< co << ptr->t << co << ptr->y << co << ptr->u << co << ptr->i << co << ptr->o
	//		<< co << ptr->p;
	//}
	//else if ("max_parallel_call_order" == ALine)
	//{
	//	max_parallel_call_order* ptr = dynamic_cast<max_parallel_call_order*>(obj);
	//	ss << "max_parallel_call_order(" << ptr->q << co << ptr->w << co << ptr->e << co << ptr->r;
	//}
	//else if ("max_op_order" == ALine)
	//{
	//	max_op_order* ptr = dynamic_cast<max_op_order*>(obj);
	//	ss << "max_op_order(" << ptr->q << co << ptr->w << co << ptr->e;
	//}
	//else if ("totalmax_call_order" == ALine)
	//{
	//	totalmax_call_order* ptr = dynamic_cast<totalmax_call_order*>(obj);
	//	ss << "totalmax_call_order(" << ptr->q << co << ptr->w << co << ptr->e;
	//}
	//else if ("totalmax_gross_depth" == ALine)
	//{
	//	totalmax_gross_depth* ptr = dynamic_cast<totalmax_gross_depth*>(obj);
	//	ss << "totalmax_gross_depth(" << ptr->q << co << ptr->w << co << ptr->e;
	//}
	//else if ("current_total_max_order_entry" == ALine)
	//{
	//	current_total_max_order_entry* ptr = dynamic_cast<current_total_max_order_entry*>(obj);
	//	ss << "current_total_max_order_entry(" << ptr->q;
	//}
	//else if ("module_last_state" == ALine)
	//{
	//	module_last_state* ptr = dynamic_cast<module_last_state*>(obj);
	//	ss << "module_last_state(" << ptr->q;
	//}
	//else if ("module_local_list" == ALine)
	//{
	//	stringstream tt;
	//	module_local_list* ptr = dynamic_cast<module_local_list*>(obj);
	//	int			ii = 0;
	//	size_t		vs;
	//	ss << "module_local_list(" << br;
	//	if (!ptr->q.empty())
	//	{
	//		vs = ptr->q.size();
	//		for (int ii = 0; ii < vs; ii++)
	//		{
	//			ss << "local_object(" << ptr->q[ii].q << co << ptr->q[ii].w << co << ptr->q[ii].e << co << ptr->q[ii].r << co
	//				<< ptr->q[ii].t << co << ptr->q[ii].y << co << ptr->q[ii].u << co << ptr->q[ii].i << co << ptr->q[ii].o << pacl << co;
	//		}
	//		string tmp = ss.str();
	//		tmp.resize(tmp.size() - 1);  // getting rid of the last
	//		swap(ss, tt);
	//		ss << tmp;
	//		ss << brcl;
	//	}
	//}
	//if(true)
	//{
	//	if ("module_local_list_parcs" == ALine )
	//	{
	//		stringstream tt;
	//		module_local_list_parcs* ptr = dynamic_cast<module_local_list_parcs*>(obj);
	//		int			ii = 0;
	//		size_t		vs;
	//		ss << "module_local_list_parcs(" << br;
	//		if (!ptr->q.empty())
	//		{
	//			vs = ptr->q.size();
	//			for (int ii = 0; ii < vs; ii++)
	//			{
	//				ss << "local_object(" << ptr->q[ii].q << co << ptr->q[ii].w << co << ptr->q[ii].e << co << ptr->q[ii].r << co
	//					<< ptr->q[ii].t << co << ptr->q[ii].y << co << ptr->q[ii].u << co << ptr->q[ii].i << co << ptr->q[ii].o << pacl << co;
	//			}
	//			string tmp = ss.str();
	//			tmp.resize(tmp.size() - 1);  // getting rid of the last
	//			swap(ss, tt);
	//			ss << tmp;
	//			ss << brcl;
	//		}
	//	}
	//	else if ("last_non_io_found" == ALine)
	//	{
	//		last_non_io_found* ptr = dynamic_cast<last_non_io_found*>(obj);
	//		ss << "last_non_io_found(" << ptr->q;
	//	}
	//	else if ("last_local_number" == ALine)
	//	{
	//		last_local_number* ptr = dynamic_cast<last_local_number*>(obj);
	//		ss << "last_local_number(" << ptr->q;
	//	}
	//	else if ("printed_formal_ios_of_called_module" == ALine)
	//	{
	//		printed_formal_ios_of_called_module* ptr = dynamic_cast<printed_formal_ios_of_called_module*>(obj);
	//		ss << "printed_formal_ios_of_called_module(" << ptr->q << co << ptr->w << co << ptr->e << co << ptr->r;
	//	}
	//	else if ("it_includes_ifthen" == ALine)
	//	{
	//		it_includes_ifthen* ptr = dynamic_cast<it_includes_ifthen*>(obj);
	//		ss << "it_includes_ifthen(" << ptr->q << co << ptr->w << co << ptr->e;
	//	}
	//	else if ("it_includes_conditional_targeting" == ALine)
	//	{
	//		it_includes_conditional_targeting* ptr = dynamic_cast<it_includes_conditional_targeting*>(obj);
	//		ss << "it_includes_conditional_targeting(" << ptr->q << co << ptr->w << co << ptr->e;
	//	}
	//	else if ("targets_conditional_variable" == ALine)
	//	{
	//		targets_conditional_variable* ptr = dynamic_cast<targets_conditional_variable*>(obj);
	//		ss << "targets_conditional_variable(" << ptr->q << co << ptr->w << co << ptr->e << co << ptr->r;
	//	}
	//	else if ("variable_has_been_listed" == ALine)
	//	{
	//		variable_has_been_listed* ptr = dynamic_cast<variable_has_been_listed*>(obj);
	//		ss << "variable_has_been_listed(" << ptr->q << co << ptr->w;
	//	}
	//	else if ("resetstyle" == ALine)
	//	{
	//		resetstyle* ptr = dynamic_cast<resetstyle*>(obj);
	//		ss << "resetstyle(" << ptr->q;
	//	}
	//	else if ("checkstyle" == ALine)
	//	{
	//		checkstyle* ptr = dynamic_cast<checkstyle*>(obj);
	//		ss << "checkstyle(" << ptr->q;
	//	}
	//	else if ("total_local_entry" == ALine )
	//	{
	//		total_local_entry* ptr = dynamic_cast<total_local_entry*>(obj);
	//		ss << "total_local_entry(" << ptr->q;
	//	}
	//	else if ("complex_next_state_operation_depth" == ALine)
	//	{
	//		complex_next_state_operation_depth* ptr = dynamic_cast<complex_next_state_operation_depth*>(obj);
	//		ss << "complex_next_state_operation_depth(" << ptr->q;
	//	}
	//	else if ("output_filename" == ALine)
	//	{
	//		output_filename* ptr = dynamic_cast<output_filename*>(obj);
	//		ss << "output_filename(" << ptr->q;
	//	}
	//	else if ("hdl_io_pass" == ALine)
	//	{
	//		hdl_io_pass* ptr = dynamic_cast<hdl_io_pass*>(obj);
	//		ss << "hdl_io_pass(" << ptr->q;
	//	}
	//	else if ("current_hdl_style" == ALine)
	//	{
	//		current_hdl_style* ptr = dynamic_cast<current_hdl_style*>(obj);
	//		ss << "current_hdl_style(" << ptr->q;
	//	}
	//	else if ("call_ios_have_been_reset" == ALine)
	//	{
	//		call_ios_have_been_reset* ptr = dynamic_cast<call_ios_have_been_reset*>(obj);
	//		ss << "call_ios_have_been_reset(" << ptr->q;
	//	}
	//	else if ("debug_mode" == ALine)
	//	{
	//		debug_mode* ptr = dynamic_cast<debug_mode*>(obj);
	//		ss << "debug_mode(" << ptr->q;
	//	}
	//	else if ("print_C_main_body" == ALine)
	//	{
	//		print_C_main_body* ptr = dynamic_cast<print_C_main_body*>(obj);
	//		ss << "print_C_main_body(" << ptr->q;
	//	}
	//	else if ("cac_mode" == ALine)
	//	{
	//		cac_mode* ptr = dynamic_cast<cac_mode*>(obj);
	//		ss << "cac_mode(" << ptr->q;
	//	}
	//	else if ("path" == ALine)
	//	{
	//		path* ptr = dynamic_cast<path*>(obj);
	//		ss << "path(" << ptr->q << co << ptr->w << co << ptr->e;
	//	}
	//	else if ("max_path" == ALine)
	//	{
	//		max_path* ptr = dynamic_cast<max_path*>(obj);
	//		ss << "max_path(" << ptr->q << co << ptr->w;
	//	}
	//	else if ("min_path" == ALine)
	//	{
	//		min_path* ptr = dynamic_cast<min_path*>(obj);
	//		ss << "min_path(" << ptr->q << co << ptr->w;
	//	}
	//	else if ("op_belongs_to_state" == ALine)
	//	{
	//		op_belongs_to_state* ptr = dynamic_cast<op_belongs_to_state*>(obj);
	//		ss << "op_belongs_to_state(" << ptr->q << co << ptr->w << co << ptr->e << co << ptr->r;
	//	}
	//	else if ("top_module" == ALine)
	//	{
	//		top_module* ptr = dynamic_cast<top_module*>(obj);
	//		ss << "top_module(" << ptr->q;
	//	}
	//	else if ("package_name" == ALine)
	//	{
	//		package_name* ptr = dynamic_cast<package_name*>(obj);
	//		ss << "package_name(" << ptr->q;
	//	}
	//	else 
	//	{
	//		GenfactError* ptr = new GenfactError("error for ");
	//		ptr->saying += typeid(*obj).name();
	//		ss << "Error at fact " << ptr->saying;
	//	}
	//}	// if (flag)
	//ss << pacl;
	//ALine = ss.str();
	//return ALine;
}

/// @brief makes data of string
/// @param inputline <- the string
GeneralFact* makeInstanceOf(string inputline)
{
	string          ALine, subl;
	size_t          pos, brpos;
	vector<int>				vq, vw, ve, vr, vt, vy;
	vector<local_object>	vobj;  // for these three specific facts global_declarations, module_local_list_parcs and module_local_list

	pos = 0;
	ALine = inputline.substr(0, inputline.find(pa, 0));
	pos += ALine.length();
	subl = inputline.substr(++pos, inputline.length() - pos); // ++pos getting after the first  parenthesis

	string ch = inputline.substr(0, inputline.find(1, 0));
	const char* sh = ch.c_str();
	switch (*sh)
	{
	case 'a':
	{
		if (ALine == "added_aux_call_ios")
		{
			int				w;
			string			q;

			ALine = subl.substr(0, subl.find(co, 0));
			q = ALine;
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);

			ALine = subl.substr(0, subl.rfind(pacl, 0));
			w = stoi(ALine);

			return new added_aux_call_ios(q, w);
		}
		else if (ALine == "added_aux_call_ios1")
		{
			int				w, e;
			string			q;

			ALine = subl.substr(0, subl.find(co, 0));
			q = ALine;
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);

			ALine = subl.substr(0, subl.find(co, 0));
			w = stoi(ALine);
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);

			ALine = subl.substr(0, subl.rfind(pacl, 0));
			e = stoi(ALine);

			return new added_aux_call_ios1(q, w, e);
		}
		else if (ALine == "added_aux_call_signals")
		{
			int				w;
			string			q;

			ALine = subl.substr(0, subl.find(co, 0));
			q = ALine;
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);

			ALine = subl.substr(0, subl.rfind(pacl, 0));
			w = stoi(ALine);

			return new added_aux_call_signals(q, w);
		}
		else if (ALine == "added_verilog_aux_call_outputs")
		{
			int				w;
			string			q, e;

			ALine = subl.substr(0, subl.find(co, 0));
			q = ALine;
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);

			ALine = subl.substr(0, subl.find(co, 0));
			w = stoi(ALine);
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);

			ALine = subl.substr(0, subl.rfind(pacl, 0));
			ALine.resize(ALine.size() - 1);
			e = ALine;

			return new added_verilog_aux_call_outputs(q, w, e);
		}
		break;
	}
	case 'b':
	{

		break;
	}
	case 'c':
	{
		if (ALine == "cac_mode")
		{
			int				q;

			ALine = subl.substr(0, subl.rfind(pacl, 0));
			q = stoi(ALine);

			return new cac_mode(q);
		}
		else if (ALine == "call_ios_have_been_reset")
		{
			string			q;

			ALine = subl.substr(0, subl.rfind(pacl, 0));
			ALine.resize(ALine.size() - 1);
			q = ALine;

			return new call_ios_have_been_reset(q);
		}
		else if (ALine == "call_stmt")
		{
			int					w, e;
			string				q;

			ALine = subl.substr(0, subl.find(co, 0));
			q = ALine;
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos); // getting after the coma

			ALine = subl.substr(0, subl.find(co, 0));
			w = stoi(ALine);
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);

			ALine = subl.substr(0, subl.find(co, 0));
			e = stoi(ALine);
			pos += ALine.length() + 1;			// +1 to get ahead of the first bracket
			subl = inputline.substr(++pos, inputline.length() - pos);

			//vector
			if ((subl.find(brcl, 0)) != 0)
			{
				brpos = subl.find(brcl, 0);
				while (subl.find(co, 0) < brpos)
				{
					ALine = subl.substr(0, subl.find(co, 0));
					vq.push_back(stoi(ALine));
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
					brpos -= ALine.length();
					brpos--;
				}
				ALine = subl.substr(0, brpos);
				vq.push_back(stoi(ALine));
			}
			return new call_stmt(w, e, q, vq);
			//for (int i : vq)
			//	cout << i << co;
		}
		else if (ALine == "calls_list")
		{
			int				w, e;
			string			q;

			ALine = subl.substr(0, subl.find(co, 0));
			q = ALine;
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);

			ALine = subl.substr(0, subl.find(co, 0));
			w = stoi(ALine);
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);

			ALine = subl.substr(0, subl.find(co, 0));
			e = stoi(ALine);
			pos += ALine.length() + 1;
			subl = inputline.substr(++pos, inputline.length() - pos);

			//vector
			if ((subl.find(brcl, 0)) != 0)
			{
				brpos = subl.find(brcl, 0);
				while (subl.find(co, 0) < brpos)
				{
					ALine = subl.substr(0, subl.find(co, 0));
					vq.push_back(stoi(ALine));
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
					brpos -= ALine.length();
					brpos--;
				}
				ALine = subl.substr(0, subl.find(brcl, 0));
				vq.push_back(stoi(ALine));
			}
			return new calls_list(q, w, e, vq);
		}
		else if (ALine == "cessor")
		{
			int				w, e;
			string			q;

			ALine = subl.substr(0, subl.find(co, 0));
			q = ALine;
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);

			ALine = subl.substr(0, subl.find(co, 0));
			w = stoi(ALine);
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);

			ALine = subl.substr(0, subl.rfind(pacl, 0));
			e = stoi(ALine);
			return new cessor(w, e, q);
		}
		else if (ALine == "cessor_kind")
		{
			vq.clear();
			int				e, r;
			string			q, w, t, y;

			ALine = subl.substr(0, subl.find(co, 0));
			q = ALine;
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);

			ALine = subl.substr(0, subl.find(co, 0));
			w = ALine;
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);

			ALine = subl.substr(0, subl.find(co, 0));
			e = stoi(ALine);
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);

			ALine = subl.substr(0, subl.find(co, 0));
			r = stoi(ALine);
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);

			ALine = subl.substr(0, subl.find(co, 0));
			t = ALine;
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);

			ALine = subl.substr(0, subl.find(co, 0));
			y = ALine;
			pos += ALine.length() + 1;
			subl = inputline.substr(++pos, inputline.length() - pos);

			//vector
			if ((subl.find(brcl, 0)) != 0)
			{
				brpos = subl.find(brcl, 0);
				while (subl.find(co, 0) < brpos)
				{
					ALine = subl.substr(0, subl.find(co, 0));
					vq.push_back(stoi(ALine));
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
					brpos -= ALine.length();
					brpos--;
				}
				ALine = subl.substr(0, subl.find(brcl, 0));
				vq.push_back(stoi(ALine));
			}
			return new cessor_kind(e, r, q, w, t, y, vq);
		}
		else if (ALine == "cf_previous_op")
		{
			int				w, e, r;
			string			q;

			ALine = subl.substr(0, subl.find(co, 0));
			q = ALine;
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);

			ALine = subl.substr(0, subl.find(co, 0));
			w = stoi(ALine);
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);

			ALine = subl.substr(0, subl.find(co, 0));
			e = stoi(ALine);
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);

			ALine = subl.substr(0, subl.rfind(pacl, 0));
			r = stoi(ALine);

			return new cf_previous_op(q, w, e, r);
		}
		else if (ALine == "cf_previous_state")
		{
			int				w, e, r;
			string			q;

			ALine = subl.substr(0, subl.find(co, 0));
			q = ALine;
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);

			ALine = subl.substr(0, subl.find(co, 0));
			w = stoi(ALine);
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);

			ALine = subl.substr(0, subl.find(co, 0));
			e = stoi(ALine);
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);

			ALine = subl.substr(0, subl.rfind(pacl, 0));
			r = stoi(ALine);

			return new cf_previous_state(q, w, e, r);
		}
		else if (ALine == "change_op_number")
	{
	int				w, e;
	string			q;

	ALine = subl.substr(0, subl.find(co, 0));
	q = ALine;
	pos += ALine.length();
	subl = inputline.substr(++pos, inputline.length() - pos);

	ALine = subl.substr(0, subl.find(co, 0));
	w = stoi(ALine);
	pos += ALine.length();
	subl = inputline.substr(++pos, inputline.length() - pos);

	ALine = subl.substr(0, subl.rfind(pacl, 0));
	e = stoi(ALine);

	return new change_op_number(e, w, q);
	}
		else if (ALine == "checkstyle")
		{
		string			q;

		ALine = subl.substr(0, subl.rfind(pacl, 0));
		ALine.resize(ALine.size() - 1);
		q = ALine;

		return new checkstyle(q);
		}
		else if (ALine == "combo")
	{
	int				q, e;
	string			w;

	ALine = subl.substr(0, subl.find(co, 0));
	q = stoi(ALine);
	pos += ALine.length();
	subl = inputline.substr(++pos, inputline.length() - pos);

	ALine = subl.substr(0, subl.find(co, 0));
	w = ALine;
	pos += ALine.length();
	subl = inputline.substr(++pos, inputline.length() - pos);

	ALine = subl.substr(0, subl.rfind(pacl, 0));
	e = stoi(ALine);

	return new combo(q, w, e);
	}
		else if (ALine == "complex_next_state_operation_depth")
		{
		int				q;

		ALine = subl.substr(0, subl.rfind(pacl, 0));
		q = stoi(ALine);

		return new complex_next_state_operation_depth(q);
		}
		else if (ALine == "compo_stmt")
	{
	vq.clear();
	int				w;
	string			q;

	ALine = subl.substr(0, subl.find(co, 0));
	q = ALine;
	pos += ALine.length();
	subl = inputline.substr(++pos, inputline.length() - pos);

	ALine = subl.substr(0, subl.find(co, 0));
	w = stoi(ALine);
	pos += ALine.length() + 1;
	subl = inputline.substr(++pos, inputline.length() - pos);

	//vector
	if ((subl.find(brcl, 0)) != 0)
	{
		brpos = subl.find(brcl, 0);
		while (subl.find(co, 0) < brpos)
		{
			ALine = subl.substr(0, subl.find(co, 0));
			vq.push_back(stoi(ALine));
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);
			brpos -= ALine.length();
			brpos--;
		}
		ALine = subl.substr(0, brpos);
		vq.push_back(stoi(ALine));
	}
	return new compo_stmt(w, q, vq);
	}
		else if (ALine == "composites_list")
	{
	vq.clear();
	int				w;
	string			q;

	ALine = subl.substr(0, subl.find(co, 0));
	q = ALine;
	pos += ALine.length();
	subl = inputline.substr(++pos, inputline.length() - pos);

	ALine = subl.substr(0, subl.find(co, 0));
	w = stoi(ALine);
	pos += ALine.length() + 1;
	subl = inputline.substr(++pos, inputline.length() - pos);

	//vector
	if ((subl.find(brcl, 0)) != 0)
	{
		brpos = subl.find(brcl, 0);
		while (subl.find(co, 0) < brpos)
		{
			ALine = subl.substr(0, subl.find(co, 0));
			vq.push_back(stoi(ALine));
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);
			brpos -= ALine.length();
			brpos--;
		}
		ALine = subl.substr(0, subl.find(brcl, 0));
		vq.push_back(stoi(ALine));
	}
	return new composites_list(q, w, vq);
	}
		else if (ALine == "conditional_incomplete")
	{
	int				e, r, a, s, d, f, g, h, j, k, l, z, x;
	string			q, w;

	ALine = subl.substr(0, subl.find(co, 0));
	q = ALine;
	pos += ALine.length();
	subl = inputline.substr(++pos, inputline.length() - pos);

	ALine = subl.substr(0, subl.find(co, 0));
	w = ALine;
	pos += ALine.length();
	subl = inputline.substr(++pos, inputline.length() - pos);

	ALine = subl.substr(0, subl.find(co, 0));
	e = stoi(ALine);
	pos += ALine.length();
	subl = inputline.substr(++pos, inputline.length() - pos);

	ALine = subl.substr(0, subl.find(co, 0));
	r = stoi(ALine);
	pos += ALine.length() + 1;
	subl = inputline.substr(++pos, inputline.length() - pos);

	//vector
	if ((subl.find(brcl, 0)) != 0)
	{
		brpos = subl.find(brcl, 0);
		while (subl.find(co, 0) < brpos)
		{
			ALine = subl.substr(0, subl.find(co, 0));
			vq.push_back(stoi(ALine));
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);
			brpos -= ALine.length();
			brpos--;
		}
		ALine = subl.substr(0, subl.find(brcl, 0));
		vq.push_back(stoi(ALine));
		pos += ALine.length() + 2;		// getting after bracket
		subl = inputline.substr(++pos, inputline.length() - pos);
	}
	else subl = inputline.substr(++++++pos, inputline.length() - pos);

	//vector2
	if ((subl.find(brcl, 0)) != 0)
	{
		brpos = subl.find(brcl, 0);
		while (subl.find(co, 0) < brpos)
		{
			ALine = subl.substr(0, subl.find(co, 0));
			vw.push_back(stoi(ALine));
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);
			brpos -= ALine.length();
			brpos--;
		}
		ALine = subl.substr(0, subl.find(brcl, 0));
		vw.push_back(stoi(ALine));
		pos += ALine.length() + 2;		// getting after bracket
		subl = inputline.substr(++pos, inputline.length() - pos);
	}
	else subl = inputline.substr(++++++pos, inputline.length() - pos);

	//vector3
	if ((subl.find(brcl, 0)) != 0)
	{
		brpos = subl.find(brcl, 0);
		while (subl.find(co, 0) < brpos)
		{
			ALine = subl.substr(0, subl.find(co, 0));
			ve.push_back(stoi(ALine));
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);
			brpos -= ALine.length();
			brpos--;
		}
		ALine = subl.substr(0, subl.find(brcl, 0));
		ve.push_back(stoi(ALine));
		pos += ALine.length() + 2;		// getting after bracket
		subl = inputline.substr(++pos, inputline.length() - pos);
	}
	else subl = inputline.substr(++++++pos, inputline.length() - pos);

	//vector4
	if ((subl.find(brcl, 0)) != 0)
	{
		brpos = subl.find(brcl, 0);
		while (subl.find(co, 0) < brpos)
		{
			ALine = subl.substr(0, subl.find(co, 0));
			vr.push_back(stoi(ALine));
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);
			brpos -= ALine.length();
			brpos--;
		}
		ALine = subl.substr(0, subl.find(brcl, 0));
		vr.push_back(stoi(ALine));
		pos += ALine.length() + 2;		// getting after bracket
		subl = inputline.substr(++pos, inputline.length() - pos);
	}
	else subl = inputline.substr(++++++pos, inputline.length() - pos);

	//vector5
	if ((subl.find(brcl, 0)) != 0)
	{
		brpos = subl.find(brcl, 0);
		while (subl.find(co, 0) < brpos)
		{
			ALine = subl.substr(0, subl.find(co, 0));
			vt.push_back(stoi(ALine));
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);
			brpos -= ALine.length();
			brpos--;
		}
		ALine = subl.substr(0, subl.find(brcl, 0));
		vt.push_back(stoi(ALine));
		pos += ALine.length() + 2;		// getting after bracket
		subl = inputline.substr(++pos, inputline.length() - pos);
	}
	else subl = inputline.substr(++++++pos, inputline.length() - pos);

	//vector6
	if ((subl.find(brcl, 0)) != 0)
	{
		brpos = subl.find(brcl, 0);
		while (subl.find(co, 0) < brpos)
		{
			ALine = subl.substr(0, subl.find(co, 0));
			vy.push_back(stoi(ALine));
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);
			brpos -= ALine.length();
			brpos--;
		}
		ALine = subl.substr(0, subl.find(brcl, 0));
		vy.push_back(stoi(ALine));
		pos += ALine.length() + 1;		// getting after bracket
		subl = inputline.substr(++pos, inputline.length() - pos);
	}
	else subl = inputline.substr(++++pos, inputline.length() - pos);

	ALine = subl.substr(0, subl.find(co, 0));
	a = stoi(ALine);
	pos += ALine.length();
	subl = inputline.substr(++pos, inputline.length() - pos);

	ALine = subl.substr(0, subl.find(co, 0));
	s = stoi(ALine);
	pos += ALine.length();
	subl = inputline.substr(++pos, inputline.length() - pos);

	ALine = subl.substr(0, subl.find(co, 0));
	d = stoi(ALine);
	pos += ALine.length();
	subl = inputline.substr(++pos, inputline.length() - pos);

	ALine = subl.substr(0, subl.find(co, 0));
	f = stoi(ALine);
	pos += ALine.length();
	subl = inputline.substr(++pos, inputline.length() - pos);

	ALine = subl.substr(0, subl.find(co, 0));
	g = stoi(ALine);
	pos += ALine.length();
	subl = inputline.substr(++pos, inputline.length() - pos);

	ALine = subl.substr(0, subl.find(co, 0));
	h = stoi(ALine);
	pos += ALine.length();
	subl = inputline.substr(++pos, inputline.length() - pos);

	ALine = subl.substr(0, subl.find(co, 0));
	j = stoi(ALine);
	pos += ALine.length();
	subl = inputline.substr(++pos, inputline.length() - pos);

	ALine = subl.substr(0, subl.find(co, 0));
	k = stoi(ALine);
	pos += ALine.length();
	subl = inputline.substr(++pos, inputline.length() - pos);

	ALine = subl.substr(0, subl.find(co, 0));
	l = stoi(ALine);
	pos += ALine.length();
	subl = inputline.substr(++pos, inputline.length() - pos);

	ALine = subl.substr(0, subl.find(co, 0));
	z = stoi(ALine);
	pos += ALine.length();
	subl = inputline.substr(++pos, inputline.length() - pos);

	ALine = subl.substr(0, subl.find(co, 0));
	x = stoi(ALine);

	return new conditional_incomplete(q, w, e, r, vq, vw, ve, vr, vt, vy, a, s, d, f, g, h, j, k, l, z, x);
	}
		else if (ALine == "conditional_operations")
	{
	int				e, r;
	string			q, w;

	ALine = subl.substr(0, subl.find(co, 0));
	q = ALine;
	pos += ALine.length();
	subl = inputline.substr(++pos, inputline.length() - pos);

	ALine = subl.substr(0, subl.find(co, 0));
	w = ALine;
	pos += ALine.length();
	subl = inputline.substr(++pos, inputline.length() - pos);

	ALine = subl.substr(0, subl.find(co, 0));
	e = stoi(ALine);
	pos += ALine.length();
	subl = inputline.substr(++pos, inputline.length() - pos);

	ALine = subl.substr(0, subl.find(co, 0));
	r = stoi(ALine);
	pos += ALine.length() + 1;
	subl = inputline.substr(++pos, inputline.length() - pos);

	//vector
	if ((subl.find(brcl, 0)) != 0)
	{
		brpos = subl.find(brcl, 0);
		while (subl.find(co, 0) < brpos)
		{
			ALine = subl.substr(0, subl.find(co, 0));
			vq.push_back(stoi(ALine));
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);
			brpos -= ALine.length();
			brpos--;
		}
		ALine = subl.substr(0, subl.find(brcl, 0));
		vq.push_back(stoi(ALine));
		pos += ALine.length() + 2;		// getting after bracket
		subl = inputline.substr(++pos, inputline.length() - pos);
	}
	else subl = inputline.substr(++++++pos, inputline.length() - pos);

	//vector2
	if ((subl.find(brcl, 0)) != 0)
	{
		brpos = subl.find(brcl, 0);
		while (subl.find(co, 0) < brpos)
		{
			ALine = subl.substr(0, subl.find(co, 0));
			vw.push_back(stoi(ALine));
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);
			brpos -= ALine.length();
			brpos--;
		}
		ALine = subl.substr(0, subl.find(brcl, 0));
		vw.push_back(stoi(ALine));
		pos += ALine.length() + 2;		// getting after bracket
		subl = inputline.substr(++pos, inputline.length() - pos);
	}
	else subl = inputline.substr(++++++pos, inputline.length() - pos);


	//vector3
	if ((subl.find(brcl, 0)) != 0)
	{
		brpos = subl.find(brcl, 0);
		while (subl.find(co, 0) < brpos)
		{
			ALine = subl.substr(0, subl.find(co, 0));
			ve.push_back(stoi(ALine));
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);
			brpos -= ALine.length();
			brpos--;
		}
		ALine = subl.substr(0, subl.find(brcl, 0));
		ve.push_back(stoi(ALine));
		pos += ALine.length() + 2;		// getting after bracket
		subl = inputline.substr(++pos, inputline.length() - pos);
	}
	else subl = inputline.substr(++++++pos, inputline.length() - pos);


	//vector4
	if ((subl.find(brcl, 0)) != 0)
	{
		brpos = subl.find(brcl, 0);
		while (subl.find(co, 0) < brpos)
		{
			ALine = subl.substr(0, subl.find(co, 0));
			vr.push_back(stoi(ALine));
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);
			brpos -= ALine.length();
			brpos--;
		}
		ALine = subl.substr(0, subl.find(brcl, 0));
		vr.push_back(stoi(ALine));
	}

	return new conditional_operations(q, w, e, r, vq, vw, ve, vr);
	}
		else if (ALine == "conditional_transitions")
	{
	int				e, r, t, y, u, i;
	string			q, w;

	ALine = subl.substr(0, subl.find(co, 0));
	q = ALine;
	pos += ALine.length();
	subl = inputline.substr(++pos, inputline.length() - pos);

	ALine = subl.substr(0, subl.find(co, 0));
	w = ALine;
	pos += ALine.length();
	subl = inputline.substr(++pos, inputline.length() - pos);

	ALine = subl.substr(0, subl.find(co, 0));
	e = stoi(ALine);
	pos += ALine.length();
	subl = inputline.substr(++pos, inputline.length() - pos);

	ALine = subl.substr(0, subl.find(co, 0));
	r = stoi(ALine);
	pos += ALine.length();
	subl = inputline.substr(++pos, inputline.length() - pos);

	ALine = subl.substr(0, subl.find(co, 0));
	t = stoi(ALine);
	pos += ALine.length();
	subl = inputline.substr(++pos, inputline.length() - pos);

	ALine = subl.substr(0, subl.find(co, 0));
	y = stoi(ALine);
	pos += ALine.length();
	subl = inputline.substr(++pos, inputline.length() - pos);

	ALine = subl.substr(0, subl.find(co, 0));
	u = stoi(ALine);
	pos += ALine.length();
	subl = inputline.substr(++pos, inputline.length() - pos);

	ALine = subl.substr(0, subl.rfind(pacl, 0));
	i = stoi(ALine);

	return new conditional_transitions(q, w, e, r, t, y, u, i);
	}
		else if (ALine == "consecutive_106")
	{
	string			q;

	ALine = subl.substr(0, subl.rfind(pacl, 0));
	ALine.resize(ALine.size() - 1);
	q = ALine;

	return new consecutive_106(q);
	}
		else if (ALine == "current_hdl_style")
		{
		string			q;

		ALine = subl.substr(0, subl.rfind(pacl, 0));
		ALine.resize(ALine.size() - 1);
		q = ALine;

		return new current_hdl_style(q);
		}
		else if (ALine == "current_module")
	{
	string			q;

	ALine = subl.substr(0, subl.rfind(pacl, 0));
	ALine.resize(ALine.size() - 1);
	q = ALine;

	return new current_module(q);
	}
		else if (ALine == "current_total_max_order_entry")
	{
	int				q;

	ALine = subl.substr(0, subl.rfind(pacl, 0));
	q = stoi(ALine);

	return new current_total_max_order_entry(q);
	}
		break;
	}
	case 'd':
	{
	if (ALine == "data_stmt")
	{
	int				e, r;
	string			q, w, t, y;

	ALine = subl.substr(0, subl.find(co, 0));
	q = ALine;
	pos += ALine.length();
	subl = inputline.substr(++pos, inputline.length() - pos);

	ALine = subl.substr(0, subl.find(co, 0));
	w = ALine;
	pos += ALine.length();
	subl = inputline.substr(++pos, inputline.length() - pos);

	ALine = subl.substr(0, subl.find(co, 0));
	e = stoi(ALine);
	pos += ALine.length();
	subl = inputline.substr(++pos, inputline.length() - pos);

	ALine = subl.substr(0, subl.find(co, 0));
	r = stoi(ALine);
	pos += ALine.length();
	subl = inputline.substr(++pos, inputline.length() - pos);

	ALine = subl.substr(0, subl.find(co, 0));
	t = ALine;
	pos += ALine.length();
	subl = inputline.substr(++pos, inputline.length() - pos);

	ALine = subl.substr(0, subl.rfind(pacl, 0));
	ALine.resize(ALine.size() - 1);
	y = ALine;
	return new data_stmt(e, r, q, w, t, y);
	}
	else if (ALine == "debug_mode")
	{
		int				q;

		ALine = subl.substr(0, subl.rfind(pacl, 0));
		q = stoi(ALine);

		return new debug_mode(q);
	}

		break;
	}
	case 'e':
	{
		if (ALine == "end_if")
	{
	vq.clear();
	string			q;

	ALine = subl.substr(0, subl.find(co, 0));
	q = ALine;
	pos += ALine.length() + 1;
	subl = inputline.substr(++pos, inputline.length() - pos);

	//vector
	if ((subl.find(brcl, 0)) != 0)
	{
		brpos = subl.find(brcl, 0);
		while (subl.find(co, 0) < brpos)
		{
			ALine = subl.substr(0, subl.find(co, 0));
			vq.push_back(stoi(ALine));
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);
			brpos -= ALine.length();
			brpos--;
		}
		ALine = subl.substr(0, subl.find(brcl, 0));
		vq.push_back(stoi(ALine));
	}
	return new end_if(q, vq);
	}

		break;
	}
	case 'f':
	{
		if (ALine == "for_loop")
		{
			int				q, e, r, t, y, u, i, o, p, a, s, d;
			string			w;

			ALine = subl.substr(0, subl.find(co, 0));
			q = stoi(ALine);
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);

			ALine = subl.substr(0, subl.find(co, 0));
			w = ALine;
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);

			ALine = subl.substr(0, subl.find(co, 0));
			e = stoi(ALine);
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);

			ALine = subl.substr(0, subl.find(co, 0));
			r = stoi(ALine);
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);

			ALine = subl.substr(0, subl.find(co, 0));
			t = stoi(ALine);
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);

			ALine = subl.substr(0, subl.find(co, 0));
			y = stoi(ALine);
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);

			ALine = subl.substr(0, subl.find(co, 0));
			u = stoi(ALine);
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);

			ALine = subl.substr(0, subl.find(co, 0));
			i = stoi(ALine);
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);

			ALine = subl.substr(0, subl.find(co, 0));
			o = stoi(ALine);
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);

			ALine = subl.substr(0, subl.find(co, 0));
			p = stoi(ALine);
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);

			ALine = subl.substr(0, subl.find(co, 0));
			a = stoi(ALine);
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);

			ALine = subl.substr(0, subl.find(co, 0));
			s = stoi(ALine);
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);

			ALine = subl.substr(0, subl.rfind(pacl, 0));
			d = stoi(ALine);

			return new for_loop(q, w, e, r, t, y, u, i, o, p, a, s, d);
		}
		else if (ALine == "found_call_operator")
		{
			int				w;
			string			q;

			ALine = subl.substr(0, subl.find(co, 0));
			q = ALine;
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);

			ALine = subl.substr(0, subl.rfind(pacl, 0));
			w = stoi(ALine);

			return new found_call_operator(q, w);
		}


		break;
	}
	case 'g':
	{
		if (ALine == "global_declarations")
		{
			vobj.clear();
			bool			flag2 = 1;
			int				w, t, i, p;
			string			q, r, e, y, u, o;

			subl = inputline.substr(++pos, inputline.length() - pos);

			//vector
			if ((subl.find(brcl, 0)) != 0)
			{
				brpos = subl.find(brcl, 0);
				while (flag2)
				{
					ALine = subl.substr(13, subl.find(co, 0) - 13); // 14 because   global_declerations(<<[local_object>>("linedraw",1,"constant
					q = ALine;
					pos += ALine.length() + 13;
					subl = inputline.substr(++pos, inputline.length() - pos);

					ALine = subl.substr(0, subl.find(co, 0));
					w = stoi(ALine);
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);

					ALine = subl.substr(0, subl.find(co, 0));
					e = ALine;
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);

					ALine = subl.substr(0, subl.find(co, 0));
					r = ALine;
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);

					ALine = subl.substr(0, subl.find(co, 0));
					t = stoi(ALine);
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);

					ALine = subl.substr(0, subl.find(co, 0));
					y = ALine;
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);

					ALine = subl.substr(0, subl.find(co, 0));
					u = ALine;
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);

					ALine = subl.substr(0, subl.find(co, 0));
					i = stoi(ALine);
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);

					if (inputline.find(co, pos) < brpos)
					{
						ALine = subl.substr(0, subl.find(co, 0));
						ALine.resize(ALine.size() - 1);
						o = ALine;
						vobj.push_back(local_object(t, w, i, q, e, y, u, r, o));
						pos += ALine.length() + 1;
						subl = inputline.substr(++pos, inputline.length() - pos);
					}
					else
					{
						flag2 = 0;
						ALine = subl.substr(0, subl.find(brcl, 0));
						ALine.resize(ALine.size() - 1);
						o = ALine;
						vobj.push_back(local_object(t, w, i, q, e, y, u, r, o));
						pos += ALine.length();
						subl = inputline.substr(++++++pos, inputline.length() - pos); // getting after »)],« 
					}
				}
			}
			else subl = inputline.substr(++++pos, inputline.length() - pos);
			ALine = subl.substr(0, subl.rfind(pacl, 0));
			p = stoi(ALine);
			vobj.shrink_to_fit();
			return new global_declarations(vobj, p);
		}
		else if (ALine == "global_nils")
		{
			vector<nil_node>	vnil;
			nil_node			nn(0, "");
			bool			flag2 = 1;
			subl = inputline.substr(++pos, inputline.length() - pos);

			//vector
			if ((subl.find(brcl, 0)) != 0)
			{
				brpos = subl.find(brcl, 0);
				while (flag2)
				{

					ALine = subl.substr(9, subl.find(co, 0) - 9);
					nn.q = stoi(ALine);
					pos += ALine.length() + 9;
					subl = inputline.substr(++pos, inputline.length() - pos);

					if (subl.find(co, 0) < brpos)
					{
						ALine = subl.substr(0, subl.find(co, 0));
						ALine.resize(ALine.size() - 1);
						nn.w = ALine;
						vnil.push_back(nn);
						pos += ALine.length() + 1;
						subl = inputline.substr(++pos, inputline.length() - pos);
					}
					else
					{
						flag2 = 0;
						subl.resize(subl.size() - 3);
						nn.w = subl;
						vnil.push_back(nn);
					}
				}
			}
			return new global_nils(vnil);
		}
		else if (ALine == "global_resource")
	{
	int				q;

	ALine = subl.substr(0, subl.rfind(pacl, 0));
	q = stoi(ALine);

	return new global_resource(q);
	}
		else if (ALine == "guard_cond")
	{
	int				w, e;
	string			q, r;

	ALine = subl.substr(0, subl.find(co, 0));
	q = ALine;
	pos += ALine.length();
	subl = inputline.substr(++pos, inputline.length() - pos);

	ALine = subl.substr(0, subl.find(co, 0));
	w = stoi(ALine);
	pos += ALine.length();
	subl = inputline.substr(++pos, inputline.length() - pos);

	ALine = subl.substr(0, subl.find(co, 0));
	e = stoi(ALine);
	pos += ALine.length();
	subl = inputline.substr(++pos, inputline.length() - pos);

	ALine = subl.substr(0, subl.rfind(pacl, 0));
	ALine.resize(ALine.size() - 1);
	r = ALine;

	return new guard_cond(w, e, q, r);
	}
		else if (ALine == "guard_pair")
	{
	int				w, e;
	string			q, r;

	ALine = subl.substr(0, subl.find(co, 0));
	q = ALine;
	pos += ALine.length();
	subl = inputline.substr(++pos, inputline.length() - pos);

	ALine = subl.substr(0, subl.find(co, 0));
	w = stoi(ALine);
	pos += ALine.length();
	subl = inputline.substr(++pos, inputline.length() - pos);

	ALine = subl.substr(0, subl.find(co, 0));
	e = stoi(ALine);
	pos += ALine.length();
	subl = inputline.substr(++pos, inputline.length() - pos);

	ALine = subl.substr(0, subl.rfind(pacl, 0));
	ALine.resize(ALine.size() - 1);
	r = ALine;

	return new guard_pair(w, e, q, r);
	}

		break;
	}
	case 'h':
	{
		if (ALine == "hdl_io_pass")
		{
			int				q;

			ALine = subl.substr(0, subl.rfind(pacl, 0));
			q = stoi(ALine);

			return new hdl_io_pass(q);
		}
		else if (ALine == "hdl_style")
		{
			string			q;

			ALine = subl.substr(0, subl.rfind(pacl, 0));
			ALine.resize(ALine.size() - 1);
			q = ALine;

			return new hdl_style(q);
		}
		else if (ALine == "hierarchy_part")
		{
			int				q, e, t, y, u;
			string			w, r;

			ALine = subl.substr(0, subl.find(co, 0));
			q = stoi(ALine);
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);

			ALine = subl.substr(0, subl.find(co, 0));
			w = ALine;
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);

			ALine = subl.substr(0, subl.find(co, 0));
			e = stoi(ALine);
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);

			ALine = subl.substr(0, subl.find(co, 0));
			r = ALine;
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);

			ALine = subl.substr(0, subl.find(co, 0));
			t = stoi(ALine);
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);

			ALine = subl.substr(0, subl.find(co, 0));
			y = stoi(ALine);
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);

			ALine = subl.substr(0, subl.rfind(pacl, 0));
			u = stoi(ALine);
			return new hierarchy_part(q, e, t, y, u, w, r);
		}

		break;
	}
	case 'i':
	{
		if (ALine == "incomplete_links")
		{
			int			q, w, e, r, t, y, u, i, o, p;

			ALine = subl.substr(0, subl.find(co, 0));
			q = stoi(ALine);
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);

			ALine = subl.substr(0, subl.find(co, 0));
			w = stoi(ALine);
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);

			ALine = subl.substr(0, subl.find(co, 0));
			e = stoi(ALine);
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);

			ALine = subl.substr(0, subl.find(co, 0));
			r = stoi(ALine);
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);

			ALine = subl.substr(0, subl.find(co, 0));
			t = stoi(ALine);
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);

			ALine = subl.substr(0, subl.find(co, 0));
			y = stoi(ALine);
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);

			ALine = subl.substr(0, subl.find(co, 0));
			u = stoi(ALine);
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);

			ALine = subl.substr(0, subl.find(co, 0));
			i = stoi(ALine);
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);

			ALine = subl.substr(0, subl.find(co, 0));
			o = stoi(ALine);
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);

			ALine = subl.substr(0, subl.rfind(pacl, 0));
			p = stoi(ALine);

			return new incomplete_links(q, w, e, r, t, y, u, i, o, p);
		}
		else if (ALine == "it_includes_conditional_targeting")
		{
			int				w, e;
			string			q;

			ALine = subl.substr(0, subl.find(co, 0));
			q = ALine;
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);

			ALine = subl.substr(0, subl.find(co, 0));
			w = stoi(ALine);
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);

			ALine = subl.substr(0, subl.rfind(pacl, 0));
			e = stoi(ALine);

			return new it_includes_conditional_targeting(q, w, e);
		}
		else if (ALine == "it_includes_ifthen")
		{
			int				w, e;
			string			q;

			ALine = subl.substr(0, subl.find(co, 0));
			q = ALine;
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);

			ALine = subl.substr(0, subl.find(co, 0));
			w = stoi(ALine);
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);

			ALine = subl.substr(0, subl.rfind(pacl, 0));
			e = stoi(ALine);

			return new it_includes_ifthen(q, w, e);
		}

		break;
	}
	case 'j':
	{
		if (ALine == "joint_stmt")
		{
			int				w, e, r, t, y;
			string			q;

			ALine = subl.substr(0, subl.find(co, 0));
			q = ALine;
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);

			ALine = subl.substr(0, subl.find(co, 0));
			w = stoi(ALine);
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);

			ALine = subl.substr(0, subl.find(co, 0));
			e = stoi(ALine);
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);

			ALine = subl.substr(0, subl.find(co, 0));
			r = stoi(ALine);
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);

			ALine = subl.substr(0, subl.find(co, 0));
			t = stoi(ALine);
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);

			ALine = subl.substr(0, subl.rfind(pacl, 0));
			y = stoi(ALine);
			return new joint_stmt(w, e, r, t, y, q);
		}

		break;
	}
	case 'k':
	{

		break;
	}
	case 'l':
	{
		if (ALine == "last_change_op_number")
	{
	int				w, e;
	string			q;

	ALine = subl.substr(0, subl.find(co, 0));
	q = ALine;
	pos += ALine.length();
	subl = inputline.substr(++pos, inputline.length() - pos);

	ALine = subl.substr(0, subl.find(co, 0));
	w = stoi(ALine);
	pos += ALine.length();
	subl = inputline.substr(++pos, inputline.length() - pos);

	ALine = subl.substr(0, subl.rfind(pacl, 0));
	e = stoi(ALine);

	return new last_change_op_number(e, w, q);
	}
		else if (ALine == "last_conditional_execution")
		{
			int				w;
			string			q;

			ALine = subl.substr(0, subl.find(co, 0));
			q = ALine;
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);

			ALine = subl.substr(0, subl.rfind(pacl, 0));
			w = stoi(ALine);
			return new last_conditional_execution(q, w);
		}
		else if (ALine == "last_conditional_transition")
		{
			int				w;
			string			q;

			ALine = subl.substr(0, subl.find(co, 0));
			q = ALine;
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);

			ALine = subl.substr(0, subl.rfind(pacl, 0));
			w = stoi(ALine);

			return new last_conditional_transition(q, w);
		}
		else if (ALine == "last_conditional_transition_of_schedule")
		{
			int				e;
			string			q, w;

			ALine = subl.substr(0, subl.find(co, 0));
			q = ALine;
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);

			ALine = subl.substr(0, subl.find(co, 0));
			w = ALine;
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);

			ALine = subl.substr(0, subl.rfind(pacl, 0));
			e = stoi(ALine);

			return new last_conditional_transition_of_schedule(q, w, e);
		}
		else if (ALine == "last_for_loop_entry")
		{
			int				q;

			ALine = subl.substr(0, subl.rfind(pacl, 0));
			q = stoi(ALine);

			return new last_for_loop_entry(q);
		}
		else if (ALine == "last_incomplete")
		{
			int				q, w, e;
			string			r;

			ALine = subl.substr(0, subl.find(co, 0));
			q = stoi(ALine);
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);

			ALine = subl.substr(0, subl.find(co, 0));
			w = stoi(ALine);
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);

			ALine = subl.substr(0, subl.find(co, 0));
			e = stoi(ALine);
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);

			ALine = subl.substr(0, subl.rfind(pacl, 0));
			ALine.resize(ALine.size() - 1);
			r = ALine;

			return new last_incomplete(q, w, e, r);
		}
		else if (ALine == "last_linear_incomplete_node")
	{
	int				q;

	ALine = subl.substr(0, subl.rfind(pacl, 0));
	q = stoi(ALine);

	return new last_linear_incomplete_node(q);
	}
		else if (ALine == "last_local_number")
		{
		int				q;

		ALine = subl.substr(0, subl.rfind(pacl, 0));
		q = stoi(ALine);

		return new last_local_number(q);
		}
		else if (ALine == "last_non_io_found")
		{
		int				q;

		ALine = subl.substr(0, subl.rfind(pacl, 0));
		q = stoi(ALine);

		return new last_non_io_found(q);
		}
		else if (ALine == "last_op_in_a_state")
	{
	int				q, r;
	string			w, e;

	ALine = subl.substr(0, subl.find(co, 0));
	q = stoi(ALine);
	pos += ALine.length();
	subl = inputline.substr(++pos, inputline.length() - pos);

	ALine = subl.substr(0, subl.find(co, 0));
	w = ALine;
	pos += ALine.length();
	subl = inputline.substr(++pos, inputline.length() - pos);

	ALine = subl.substr(0, subl.find(co, 0));
	e = ALine;
	pos += ALine.length();
	subl = inputline.substr(++pos, inputline.length() - pos);


	ALine = subl.substr(0, subl.rfind(pacl, 0));
	r = stoi(ALine);
	return new last_op_in_a_state(q, w, e, r);
	}
		else if (ALine == "last_op_instance")
	{
	int				q, e;
	string			w;

	ALine = subl.substr(0, subl.find(co, 0));
	q = stoi(ALine);
	pos += ALine.length();
	subl = inputline.substr(++pos, inputline.length() - pos);

	ALine = subl.substr(0, subl.find(co, 0));
	w = ALine;
	pos += ALine.length();
	subl = inputline.substr(++pos, inputline.length() - pos);


	ALine = subl.substr(0, subl.rfind(pacl, 0));
	e = stoi(ALine);
	return new last_op_instance(q, w, e);
	}
		else if (ALine == "last_output_instance")
	{
	int				q;
	string			w;

	ALine = subl.substr(0, subl.find(co, 0));
	q = stoi(ALine);
	pos += ALine.length();
	subl = inputline.substr(++pos, inputline.length() - pos);

	ALine = subl.substr(0, subl.rfind(pacl, 0));
	ALine.resize(ALine.size() - 1);
	w = ALine;

	return new last_output_instance(q, w);
	}
		else if (ALine == "last_reentrant_triangle")
	{
	int				w;
	string			q;

	ALine = subl.substr(0, subl.find(co, 0));
	q = ALine;
	pos += ALine.length();
	subl = inputline.substr(++pos, inputline.length() - pos);

	ALine = subl.substr(0, subl.rfind(pacl, 0));
	w = stoi(ALine);
	return new last_reentrant_triangle(q, w);
	}
		else if (ALine == "last_rescheduled")
	{
	int				e, t;
	string			q, w, r;

	ALine = subl.substr(0, subl.find(co, 0));
	q = ALine;
	pos += ALine.length();
	subl = inputline.substr(++pos, inputline.length() - pos);

	ALine = subl.substr(0, subl.find(co, 0));
	w = ALine;
	pos += ALine.length();
	subl = inputline.substr(++pos, inputline.length() - pos);

	ALine = subl.substr(0, subl.find(co, 0));
	e = stoi(ALine);
	pos += ALine.length();
	subl = inputline.substr(++pos, inputline.length() - pos);

	ALine = subl.substr(0, subl.find(co, 0));
	r = ALine;
	pos += ALine.length();
	subl = inputline.substr(++pos, inputline.length() - pos);

	ALine = subl.substr(0, subl.rfind(pacl, 0));
	t = stoi(ALine);

	return new last_rescheduled(w, e, q, r, t);
	}
		else if (ALine == "last_schedule_state")
	{
	int				e;
	string			q, w;

	ALine = subl.substr(0, subl.find(co, 0));
	q = ALine;
	pos += ALine.length();
	subl = inputline.substr(++pos, inputline.length() - pos);

	ALine = subl.substr(0, subl.find(co, 0));
	w = ALine;
	pos += ALine.length();
	subl = inputline.substr(++pos, inputline.length() - pos);

	ALine = subl.substr(0, subl.rfind(pacl, 0));
	e = stoi(ALine);

	return new last_schedule_state(q, w, e);
	}
		else if (ALine == "last_signal_instance")
	{
	int				q;
	string			w;

	ALine = subl.substr(0, subl.find(co, 0));
	q = stoi(ALine);
	pos += ALine.length();
	subl = inputline.substr(++pos, inputline.length() - pos);

	ALine = subl.substr(0, subl.rfind(pacl, 0));
	ALine.resize(ALine.size() - 1);
	w = ALine;

	return new last_signal_instance(q, w);
	}
		else if (ALine == "linear_incomplete_node")
	{
	vq.clear();
	vw.clear();
	int			e, y;
	string		q, w;

	ALine = subl.substr(0, subl.find(co, 0));
	q = ALine;
	pos += ALine.length();
	subl = inputline.substr(++pos, inputline.length() - pos);

	ALine = subl.substr(0, subl.find(co, 0));
	w = ALine;
	pos += ALine.length();
	subl = inputline.substr(++pos, inputline.length() - pos);

	ALine = subl.substr(0, subl.find(co, 0));
	e = stoi(ALine);
	pos += ALine.length();
	subl = inputline.substr(++pos, inputline.length() - pos);

	ALine = subl.substr(0, subl.find(co, 0));
	y = stoi(ALine);
	pos += ALine.length() + 1;
	subl = inputline.substr(++pos, inputline.length() - pos);

	//vector
	if ((subl.find(brcl, 0)) != 0)
	{
		brpos = subl.find(brcl, 0);
		while (subl.find(co, 0) < brpos)
		{
			ALine = subl.substr(0, subl.find(co, 0));
			vq.push_back(stoi(ALine));
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);
			brpos -= ALine.length();
			brpos--;
		}
		ALine = subl.substr(0, subl.find(brcl, 0));
		vq.push_back(stoi(ALine));
		pos += ALine.length() + 2;		// getting after bracket
		subl = inputline.substr(++pos, inputline.length() - pos);
	}
	else subl = inputline.substr(++++++pos, inputline.length() - pos);

	//vector2
	if ((subl.find(brcl, 0)) != 0)
	{
		brpos = subl.find(brcl, 0);
		while (subl.find(co, 0) < brpos)
		{
			ALine = subl.substr(0, subl.find(co, 0));
			vw.push_back(stoi(ALine));
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);
			brpos -= ALine.length();
			brpos--;
		}
		ALine = subl.substr(0, subl.find(brcl, 0));
		vw.push_back(stoi(ALine));
	}

	return new linear_incomplete_node(w, e, q, y, vq, vw);
	}
		else if (ALine == "local_ifthen_chain_end_operations_were_written")
	{
	int				q;

	ALine = subl.substr(0, subl.rfind(pacl, 0));
	q = stoi(ALine);

	return new local_ifthen_chain_end_operations_were_written(q);
	}
		else if (ALine == "local_object")
	{
	int				w, i, t;
	string			q, e, r, y, u, o;

	ALine = subl.substr(0, subl.find(co, 0));
	q = ALine;
	pos += ALine.length();
	subl = inputline.substr(++pos, inputline.length() - pos);

	ALine = subl.substr(0, subl.find(co, 0));
	w = stoi(ALine);
	pos += ALine.length();
	subl = inputline.substr(++pos, inputline.length() - pos);

	ALine = subl.substr(0, subl.find(co, 0));
	e = ALine;
	pos += ALine.length();
	subl = inputline.substr(++pos, inputline.length() - pos);

	ALine = subl.substr(0, subl.find(co, 0));
	r = ALine;
	pos += ALine.length();
	subl = inputline.substr(++pos, inputline.length() - pos);

	ALine = subl.substr(0, subl.find(co, 0));
	t = stoi(ALine);
	pos += ALine.length();
	subl = inputline.substr(++pos, inputline.length() - pos);

	ALine = subl.substr(0, subl.find(co, 0));
	y = ALine;
	pos += ALine.length();
	subl = inputline.substr(++pos, inputline.length() - pos);

	ALine = subl.substr(0, subl.find(co, 0));
	u = ALine;
	pos += ALine.length();
	subl = inputline.substr(++pos, inputline.length() - pos);

	ALine = subl.substr(0, subl.find(co, 0));
	i = stoi(ALine);
	pos += ALine.length();
	subl = inputline.substr(++pos, inputline.length() - pos);

	ALine = subl.substr(0, subl.rfind(pacl, 0));
	ALine.resize(ALine.size() - 1);
	o = ALine;
	return new local_object(t, w, i, q, e, y, u, r, o);
	}
		else if (ALine == "last_while_loop_entry")
	{
	int				q;

	ALine = subl.substr(0, subl.rfind(pacl, 0));
	q = stoi(ALine);

	return new last_for_loop_entry(q);
	}
		break;
	}
	case 'm':
	{
		 if (ALine == "massively_parallel_style")
	{
	int				q;

	ALine = subl.substr(0, subl.rfind(pacl, 0));
	q = stoi(ALine);

	return new massively_parallel_style(q);
	}
		 else if (ALine == "max_op_order")
		 {
			 int				e;
			 string			q, w;

			 ALine = subl.substr(0, subl.find(co, 0));
			 q = ALine;
			 pos += ALine.length();
			 subl = inputline.substr(++pos, inputline.length() - pos);

			 ALine = subl.substr(0, subl.find(co, 0));
			 w = ALine;
			 pos += ALine.length();
			 subl = inputline.substr(++pos, inputline.length() - pos);

			 ALine = subl.substr(0, subl.rfind(pacl, 0));
			 e = stoi(ALine);

			 return new max_op_order(q, w, e);
		 }
		 else if (ALine == "max_parallel_call_order")
		 {
			 int				e, r;
			 string			q, w;

			 ALine = subl.substr(0, subl.find(co, 0));
			 q = ALine;
			 pos += ALine.length();
			 subl = inputline.substr(++pos, inputline.length() - pos);

			 ALine = subl.substr(0, subl.find(co, 0));
			 w = ALine;
			 pos += ALine.length();
			 subl = inputline.substr(++pos, inputline.length() - pos);

			 ALine = subl.substr(0, subl.find(co, 0));
			 e = stoi(ALine);
			 pos += ALine.length();
			 subl = inputline.substr(++pos, inputline.length() - pos);

			 ALine = subl.substr(0, subl.rfind(pacl, 0));
			 r = stoi(ALine);

			 return new max_parallel_call_order(q, w, e, r);
		 }
		 else if (ALine == "max_path")
		 {
			 int				w;
			 string			q;

			 ALine = subl.substr(0, subl.find(co, 0));
			 q = ALine;
			 pos += ALine.length();
			 subl = inputline.substr(++pos, inputline.length() - pos);

			 ALine = subl.substr(0, subl.rfind(pacl, 0));
			 w = stoi(ALine);

			 return new max_path(q, w);
		 }
		 else if (ALine == "mem_port")
		 {
			 int				q, y, i, s;
			 string			w, e, r, t, u, o, p, a, d;

			 ALine = subl.substr(0, subl.find(co, 0));
			 q = stoi(ALine);
			 pos += ALine.length();
			 subl = inputline.substr(++pos, inputline.length() - pos);

			 ALine = subl.substr(0, subl.find(co, 0));
			 w = ALine;
			 pos += ALine.length();
			 subl = inputline.substr(++pos, inputline.length() - pos);

			 ALine = subl.substr(0, subl.find(co, 0));
			 e = ALine;
			 pos += ALine.length();
			 subl = inputline.substr(++pos, inputline.length() - pos);

			 ALine = subl.substr(0, subl.find(co, 0));
			 r = ALine;
			 pos += ALine.length();
			 subl = inputline.substr(++pos, inputline.length() - pos);

			 ALine = subl.substr(0, subl.find(co, 0));
			 t = ALine;
			 pos += ALine.length();
			 subl = inputline.substr(++pos, inputline.length() - pos);

			 ALine = subl.substr(0, subl.find(co, 0));
			 y = stoi(ALine);
			 pos += ALine.length();
			 subl = inputline.substr(++pos, inputline.length() - pos);

			 ALine = subl.substr(0, subl.find(co, 0));
			 u = ALine;
			 pos += ALine.length();
			 subl = inputline.substr(++pos, inputline.length() - pos);

			 ALine = subl.substr(0, subl.find(co, 0));
			 i = stoi(ALine);
			 pos += ALine.length();
			 subl = inputline.substr(++pos, inputline.length() - pos);

			 ALine = subl.substr(0, subl.find(co, 0));
			 o = ALine;
			 pos += ALine.length();
			 subl = inputline.substr(++pos, inputline.length() - pos);

			 ALine = subl.substr(0, subl.find(co, 0));
			 p = ALine;
			 pos += ALine.length();
			 subl = inputline.substr(++pos, inputline.length() - pos);

			 ALine = subl.substr(0, subl.find(co, 0));
			 a = ALine;
			 pos += ALine.length();
			 subl = inputline.substr(++pos, inputline.length() - pos);

			 ALine = subl.substr(0, subl.find(co, 0));
			 s = stoi(ALine);
			 pos += ALine.length();
			 subl = inputline.substr(++pos, inputline.length() - pos);

			 ALine = subl.substr(0, subl.rfind(pacl, 0));
			 ALine.resize(ALine.size() - 1);
			 d = ALine;

			 return new mem_port(q, w, e, r, t, y, u, i, o, p, a, s, d);
		 }
		 else if (ALine == "min_path")
		{
		int				w;
		string			q;

		ALine = subl.substr(0, subl.find(co, 0));
		q = ALine;
		pos += ALine.length();
		subl = inputline.substr(++pos, inputline.length() - pos);

		ALine = subl.substr(0, subl.rfind(pacl, 0));
		w = stoi(ALine);

		return new min_path(q, w);
		}
		 else if (ALine == "mixed_incomplete_state_lists")
	{
	vq.clear();
	vw.clear();
	int				e;
	string			q, w;

	ALine = subl.substr(0, subl.find(co, 0));
	q = ALine;
	pos += ALine.length();
	subl = inputline.substr(++pos, inputline.length() - pos);

	ALine = subl.substr(0, subl.find(co, 0));
	w = ALine;
	pos += ALine.length();
	subl = inputline.substr(++pos, inputline.length() - pos);

	ALine = subl.substr(0, subl.find(co, 0));
	e = stoi(ALine);
	pos += ALine.length() + 1;
	subl = inputline.substr(++pos, inputline.length() - pos);

	//vector
	if ((subl.find(brcl, 0)) != 0)
	{
		brpos = subl.find(brcl, 0);
		while (subl.find(co, 0) < brpos)
		{
			ALine = subl.substr(0, subl.find(co, 0));
			vq.push_back(stoi(ALine));
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);
			brpos -= ALine.length();
			brpos--;
		}
		ALine = subl.substr(0, subl.find(brcl, 0));
		vq.push_back(stoi(ALine));
		pos += ALine.length() + 2;		// getting after bracket
		subl = inputline.substr(++pos, inputline.length() - pos);
	}
	else subl = inputline.substr(++++++pos, inputline.length() - pos);

	//vector2
	if ((subl.find(brcl, 0)) != 0)
	{
		brpos = subl.find(brcl, 0);
		while (subl.find(co, 0) < brpos)
		{
			ALine = subl.substr(0, subl.find(co, 0));
			vw.push_back(stoi(ALine));
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);
			brpos -= ALine.length();
			brpos--;
		}
		ALine = subl.substr(0, subl.find(brcl, 0));
		vw.push_back(stoi(ALine));
	}

	return new mixed_incomplete_state_lists(w, e, q, vq, vw);
	}
		 else if (ALine == "module_g_resource")
	{
	int				w;
	string			q;

	ALine = subl.substr(0, subl.find(co, 0));
	q = ALine;
	pos += ALine.length();
	subl = inputline.substr(++pos, inputline.length() - pos);

	ALine = subl.substr(0, subl.rfind(pacl, 0));
	w = stoi(ALine);

	return new module_g_resource(q, w);
	}
		 else if (ALine == "module_last_state")
	{
	int				q;

	ALine = subl.substr(0, subl.rfind(pacl, 0));
	q = stoi(ALine);

	return new module_last_state(q);
	}
		 else if (ALine == "module_local_list")
	{
	vobj.clear();
	bool			flag2 = 1;
	int				w, t, i;
	string			q, r, e, y, u, o;

	subl = inputline.substr(++pos, inputline.length() - pos);

	//vector
	if ((subl.find(brcl, 0)) != 0)
	{
		brpos = subl.find(brcl, 0);
		while (flag2)
		{
			ALine = subl.substr(13, subl.find(co, 0) - 13); // 14 because   module_local_list(<<[local_object>>("linedraw",1,"constant
			q = ALine;
			pos += ALine.length() + 13;
			subl = inputline.substr(++pos, inputline.length() - pos);

			ALine = subl.substr(0, subl.find(co, 0));
			w = stoi(ALine);
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);

			ALine = subl.substr(0, subl.find(co, 0));
			e = ALine;
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);

			ALine = subl.substr(0, subl.find(co, 0));
			r = ALine;
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);

			ALine = subl.substr(0, subl.find(co, 0));
			t = stoi(ALine);
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);

			ALine = subl.substr(0, subl.find(co, 0));
			y = ALine;
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);

			ALine = subl.substr(0, subl.find(co, 0));
			u = ALine;
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);

			ALine = subl.substr(0, subl.find(co, 0));
			i = stoi(ALine);
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);

			if (inputline.find(co, pos) < brpos)
			{
				ALine = subl.substr(0, subl.find(co, 0));
				ALine.resize(ALine.size() - 1);
				o = ALine;
				vobj.push_back(local_object(t, w, i, q, e, y, u, r, o));
				pos += ALine.length() + 1;
				subl = inputline.substr(++pos, inputline.length() - pos);
			}
			else
			{
				flag2 = 0;
				ALine = subl.substr(0, subl.find(brcl, 0));
				ALine.resize(ALine.size() - 1);
				o = ALine;
				vobj.push_back(local_object(t, w, i, q, e, y, u, r, o));
				pos += ALine.length();
			}
		}
	}
	return new module_local_list(vobj);
	}
		 else if (ALine == "module_local_list_parcs")
	{
		vobj.clear();
		bool			flag2 = 1;
		int				w, t, i;
		string			q, r, e, y, u, o;

		subl = inputline.substr(++pos, inputline.length() - pos);

		//vector
		if ((subl.find(brcl, 0)) != 0)
		{
			brpos = subl.find(brcl, 0);
			while (flag2)
			{
				ALine = subl.substr(13, subl.find(co, 0) - 13); // 14 because   module_local_list_parcs(<<[local_object>>("linedraw",1,"constant
				q = ALine;
				pos += ALine.length() + 13;
				subl = inputline.substr(++pos, inputline.length() - pos);

				ALine = subl.substr(0, subl.find(co, 0));
				w = stoi(ALine);
				pos += ALine.length();
				subl = inputline.substr(++pos, inputline.length() - pos);

				ALine = subl.substr(0, subl.find(co, 0));
				e = ALine;
				pos += ALine.length();
				subl = inputline.substr(++pos, inputline.length() - pos);

				ALine = subl.substr(0, subl.find(co, 0));
				r = ALine;
				pos += ALine.length();
				subl = inputline.substr(++pos, inputline.length() - pos);

				ALine = subl.substr(0, subl.find(co, 0));
				t = stoi(ALine);
				pos += ALine.length();
				subl = inputline.substr(++pos, inputline.length() - pos);

				ALine = subl.substr(0, subl.find(co, 0));
				y = ALine;
				pos += ALine.length();
				subl = inputline.substr(++pos, inputline.length() - pos);

				ALine = subl.substr(0, subl.find(co, 0));
				u = ALine;
				pos += ALine.length();
				subl = inputline.substr(++pos, inputline.length() - pos);

				ALine = subl.substr(0, subl.find(co, 0));
				i = stoi(ALine);
				pos += ALine.length();
				subl = inputline.substr(++pos, inputline.length() - pos);

				if (inputline.find(co, pos) < brpos)
				{
					ALine = subl.substr(0, subl.find(co, 0));
					ALine.resize(ALine.size() - 1);
					o = ALine;
					vobj.push_back(local_object(t, w, i, q, e, y, u, r, o));
					pos += ALine.length() + 1;
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else
				{
					flag2 = 0;
					ALine = subl.substr(0, subl.find(brcl, 0));
					ALine.resize(ALine.size() - 1);
					o = ALine;
					vobj.push_back(local_object(t, w, i, q, e, y, u, r, o));
					pos += ALine.length();
				}
			}
		}
		return new module_local_list_parcs(vobj);
	}

		break;
	}
	case 'n':
	{
		 if (ALine == "nested_cond_fact")
	{
	vq.clear();
	string			q;

	ALine = subl.substr(0, subl.find(co, 0));
	q = ALine;
	pos += ALine.length() + 1;
	subl = inputline.substr(++pos, inputline.length() - pos);


	//vector
	if ((subl.find(brcl, 0)) != 0)
	{
		brpos = subl.find(brcl, 0);
		while (subl.find(co, 0) < brpos)
		{
			ALine = subl.substr(0, subl.find(co, 0));
			vq.push_back(stoi(ALine));
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);
			brpos -= ALine.length();
			brpos--;
		}
		ALine = subl.substr(0, subl.find(brcl, 0));
		vq.push_back(stoi(ALine));
	}
	return new nested_cond_fact(q, vq);
	}
		 else if (ALine == "new_schedule")
		 {
			 string			q;

			 ALine = subl.substr(0, subl.rfind(pacl, 0));
			 ALine.resize(ALine.size() - 1);
			 q = ALine;

			 return new new_schedule(q);
		 }

		break;
	}
	case 'o':
	{
		 if (ALine == "old_schedule")	{
	string			q;

	ALine = subl.substr(0, subl.rfind(pacl, 0));
	ALine.resize(ALine.size() - 1);
	q = ALine;
	return new old_schedule(q);
	}
		 else if (ALine == "op_belongs_to_state")
		 {
			 int				w, e, r;
			 string			q;

			 ALine = subl.substr(0, subl.find(co, 0));
			 q = ALine;
			 pos += ALine.length();
			 subl = inputline.substr(++pos, inputline.length() - pos);

			 ALine = subl.substr(0, subl.find(co, 0));
			 w = stoi(ALine);
			 pos += ALine.length();
			 subl = inputline.substr(++pos, inputline.length() - pos);

			 ALine = subl.substr(0, subl.find(co, 0));
			 e = stoi(ALine);
			 pos += ALine.length();
			 subl = inputline.substr(++pos, inputline.length() - pos);

			 ALine = subl.substr(0, subl.rfind(pacl, 0));
			 r = stoi(ALine);

			 return new op_belongs_to_state(q, w, e, r);
		 }
		 else if (ALine == "op_def")
		 {
			 int				q, r, t, y, u;
			 string			w, e;

			 ALine = subl.substr(0, subl.find(co, 0));
			 q = stoi(ALine);
			 pos += ALine.length();
			 subl = inputline.substr(++pos, inputline.length() - pos);

			 ALine = subl.substr(0, subl.find(co, 0));
			 w = ALine;
			 pos += ALine.length();
			 subl = inputline.substr(++pos, inputline.length() - pos);

			 ALine = subl.substr(0, subl.find(co, 0));
			 e = ALine;
			 pos += ALine.length();
			 subl = inputline.substr(++pos, inputline.length() - pos);

			 ALine = subl.substr(0, subl.find(co, 0));
			 r = stoi(ALine);
			 pos += ALine.length();
			 subl = inputline.substr(++pos, inputline.length() - pos);

			 ALine = subl.substr(0, subl.find(co, 0));
			 t = stoi(ALine);
			 pos += ALine.length();
			 subl = inputline.substr(++pos, inputline.length() - pos);

			 ALine = subl.substr(0, subl.find(co, 0));
			 y = stoi(ALine);
			 pos += ALine.length();
			 subl = inputline.substr(++pos, inputline.length() - pos);

			 ALine = subl.substr(0, subl.rfind(pacl, 0));
			 u = stoi(ALine);
			 return new op_def(q, r, t, y, u, w, e);
		 }
		 else if (ALine == "op_guards")
		 {
			 vq.clear();
			 vw.clear();
			 int				w;
			 string			q;

			 ALine = subl.substr(0, subl.find(co, 0));
			 q = ALine;
			 pos += ALine.length();
			 subl = inputline.substr(++pos, inputline.length() - pos);

			 ALine = subl.substr(0, subl.find(co, 0));
			 w = stoi(ALine);
			 pos += ALine.length() + 1;
			 subl = inputline.substr(++pos, inputline.length() - pos);

			 //vector
			 if ((subl.find(brcl, 0)) != 0)
			 {
				 brpos = subl.find(brcl, 0);
				 while (subl.find(co, 0) < brpos)
				 {
					 ALine = subl.substr(0, subl.find(co, 0));
					 vq.push_back(stoi(ALine));
					 pos += ALine.length();
					 subl = inputline.substr(++pos, inputline.length() - pos);
					 brpos -= ALine.length();
					 brpos--;
				 }
				 ALine = subl.substr(0, brpos);
				 vq.push_back(stoi(ALine));
				 pos += ALine.length() + 2;		// getting after bracket
				 subl = inputline.substr(++pos, inputline.length() - pos);
			 }
			 else subl = inputline.substr(++++++pos, inputline.length() - pos);

			 //vector2
			 if ((subl.find(brcl, 0)) != 0)
			 {
				 brpos = subl.find(brcl, 0);
				 while (subl.find(co, 0) < brpos)
				 {
					 ALine = subl.substr(0, subl.find(co, 0));
					 vw.push_back(stoi(ALine));
					 pos += ALine.length();
					 subl = inputline.substr(++pos, inputline.length() - pos);
					 brpos -= ALine.length();
					 brpos--;
				 }
				 ALine = subl.substr(0, subl.find(brcl, 0));
				 vw.push_back(stoi(ALine));
			 }

			 return new op_guards(w, q, vq, vw);
		 }
		 else if (ALine == "op_in_a_state")
	{
	int				q, r;
	string			w, e, t;

	ALine = subl.substr(0, subl.find(co, 0));
	q = stoi(ALine);
	pos += ALine.length();
	subl = inputline.substr(++pos, inputline.length() - pos);

	ALine = subl.substr(0, subl.find(co, 0));
	w = ALine;
	pos += ALine.length();
	subl = inputline.substr(++pos, inputline.length() - pos);

	ALine = subl.substr(0, subl.find(co, 0));
	e = ALine;
	pos += ALine.length();
	subl = inputline.substr(++pos, inputline.length() - pos);

	ALine = subl.substr(0, subl.find(co, 0));
	r = stoi(ALine);
	pos += ALine.length();
	subl = inputline.substr(++pos, inputline.length() - pos);


	ALine = subl.substr(0, subl.rfind(pacl, 0));
	ALine.resize(ALine.size() - 1);
	t = ALine;

	return new op_in_a_state(w, e, q, r, t);
	}
		 else if (ALine == "op_instance")
	{
	int				q, e, r;
	string			w, t;

	ALine = subl.substr(0, subl.find(co, 0));
	q = stoi(ALine);
	pos += ALine.length();
	subl = inputline.substr(++pos, inputline.length() - pos);

	ALine = subl.substr(0, subl.find(co, 0));
	w = ALine;
	pos += ALine.length();
	subl = inputline.substr(++pos, inputline.length() - pos);

	ALine = subl.substr(0, subl.find(co, 0));
	e = stoi(ALine);
	pos += ALine.length();
	subl = inputline.substr(++pos, inputline.length() - pos);

	ALine = subl.substr(0, subl.find(co, 0));
	r = stoi(ALine);
	pos += ALine.length();
	subl = inputline.substr(++pos, inputline.length() - pos);


	ALine = subl.substr(0, subl.rfind(pacl, 0));
	ALine.resize(ALine.size() - 1);
	t = ALine;

	return new op_instance(w, e, q, r, t);
	}
		 else if (ALine == "op_resource")
	{
	int				e;
	string			q, w;

	ALine = subl.substr(0, subl.find(co, 0));
	q = ALine;
	pos += ALine.length();
	subl = inputline.substr(++pos, inputline.length() - pos);

	ALine = subl.substr(0, subl.find(co, 0));
	w = ALine;
	pos += ALine.length();
	subl = inputline.substr(++pos, inputline.length() - pos);

	ALine = subl.substr(0, subl.rfind(pacl, 0));
	e = stoi(ALine);

	return new op_resource(q, w, e);
	}
		 else if (ALine == "operation_order")
	{
	int				e, r, t, y, u, i, o, p;
	string			q, w;

	ALine = subl.substr(0, subl.find(co, 0));
	q = ALine;
	pos += ALine.length();
	subl = inputline.substr(++pos, inputline.length() - pos);

	ALine = subl.substr(0, subl.find(co, 0));
	w = ALine;
	pos += ALine.length();
	subl = inputline.substr(++pos, inputline.length() - pos);

	ALine = subl.substr(0, subl.find(co, 0));
	e = stoi(ALine);
	pos += ALine.length();
	subl = inputline.substr(++pos, inputline.length() - pos);

	ALine = subl.substr(0, subl.find(co, 0));
	r = stoi(ALine);
	pos += ALine.length();
	subl = inputline.substr(++pos, inputline.length() - pos);

	ALine = subl.substr(0, subl.find(co, 0));
	t = stoi(ALine);
	pos += ALine.length();
	subl = inputline.substr(++pos, inputline.length() - pos);

	ALine = subl.substr(0, subl.find(co, 0));
	y = stoi(ALine);
	pos += ALine.length();
	subl = inputline.substr(++pos, inputline.length() - pos);

	ALine = subl.substr(0, subl.find(co, 0));
	u = stoi(ALine);
	pos += ALine.length();
	subl = inputline.substr(++pos, inputline.length() - pos);

	ALine = subl.substr(0, subl.find(co, 0));
	i = stoi(ALine);
	pos += ALine.length();
	subl = inputline.substr(++pos, inputline.length() - pos);

	ALine = subl.substr(0, subl.find(co, 0));
	o = stoi(ALine);
	pos += ALine.length();
	subl = inputline.substr(++pos, inputline.length() - pos);

	ALine = subl.substr(0, subl.rfind(pacl, 0));
	p = stoi(ALine);

	return new operation_order(q, w, e, r, t, y, u, i, o, p);
	}
		 else if (ALine == "operator_instance_stats")
	{
	int				w, e, r;
	string			q;

	ALine = subl.substr(0, subl.find(co, 0));
	q = ALine;
	pos += ALine.length();
	subl = inputline.substr(++pos, inputline.length() - pos);

	ALine = subl.substr(0, subl.find(co, 0));
	w = stoi(ALine);
	pos += ALine.length();
	subl = inputline.substr(++pos, inputline.length() - pos);

	ALine = subl.substr(0, subl.find(co, 0));
	e = stoi(ALine);
	pos += ALine.length();
	subl = inputline.substr(++pos, inputline.length() - pos);


	ALine = subl.substr(0, subl.rfind(pacl, 0));
	r = stoi(ALine);

	return new operator_instance_stats(q, w, e, r);
	}
		 else if (ALine == "operator_instances")
	{
	int				w;
	string			q;

	ALine = subl.substr(0, subl.find(co, 0));
	q = ALine;
	pos += ALine.length();
	subl = inputline.substr(++pos, inputline.length() - pos);

	ALine = subl.substr(0, subl.rfind(pacl, 0));
	w = stoi(ALine);

	return new operator_instances(q, w);
	}
		 else if (ALine == "output_filename")
		{
		string			q;

		ALine = subl.substr(0, subl.rfind(pacl, 0));
		ALine.resize(ALine.size() - 1);
		q = ALine;

		return new output_filename(q);
		}
		 else if (ALine == "output_instance")
	{
	int				q, t, y;
	string			w, e, r;

	ALine = subl.substr(0, subl.find(co, 0));
	q = stoi(ALine);
	pos += ALine.length();
	subl = inputline.substr(++pos, inputline.length() - pos);

	ALine = subl.substr(0, subl.find(co, 0));
	w = ALine;
	pos += ALine.length();
	subl = inputline.substr(++pos, inputline.length() - pos);

	ALine = subl.substr(0, subl.find(co, 0));
	e = ALine;
	pos += ALine.length();
	subl = inputline.substr(++pos, inputline.length() - pos);

	ALine = subl.substr(0, subl.find(co, 0));
	r = ALine;
	pos += ALine.length();
	subl = inputline.substr(++pos, inputline.length() - pos);

	ALine = subl.substr(0, subl.find(co, 0));
	t = stoi(ALine);
	pos += ALine.length();
	subl = inputline.substr(++pos, inputline.length() - pos);


	ALine = subl.substr(0, subl.rfind(pacl, 0));
	y = stoi(ALine);

	return new output_instance(q, w, e, r, t, y);
	}

		break;
	}
	case 'p':
	{
		 if (ALine == "package_name")
	{
	string			q;

	ALine = subl.substr(0, subl.rfind(pacl, 0));
	ALine.resize(ALine.size() - 1);
	q = ALine;
	return new package_name(q);
	}
		 else if (ALine == "path")
		 {
			 int				w, e;
			 string			q;

			 ALine = subl.substr(0, subl.find(co, 0));
			 q = ALine;
			 pos += ALine.length();
			 subl = inputline.substr(++pos, inputline.length() - pos);

			 ALine = subl.substr(0, subl.find(co, 0));
			 w = stoi(ALine);
			 pos += ALine.length();
			 subl = inputline.substr(++pos, inputline.length() - pos);

			 ALine = subl.substr(0, subl.rfind(pacl, 0));
			 e = stoi(ALine);

			 return new path(q, w, e);
		 }
		 else if (ALine == "possible_end_if")
		 {
			 vq.clear();
			 string			q;

			 ALine = subl.substr(0, subl.find(co, 0));
			 q = ALine;
			 pos += ALine.length() + 1;
			 subl = inputline.substr(++pos, inputline.length() - pos);

			 //vector
			 if ((subl.find(brcl, 0)) != 0)
			 {
				 brpos = subl.find(brcl, 0);
				 while (subl.find(co, 0) < brpos)
				 {
					 ALine = subl.substr(0, subl.find(co, 0));
					 vq.push_back(stoi(ALine));
					 pos += ALine.length();
					 subl = inputline.substr(++pos, inputline.length() - pos);
					 brpos -= ALine.length();
					 brpos--;
				 }
				 ALine = subl.substr(0, subl.find(brcl, 0));
				 vq.push_back(stoi(ALine));
			 }
			 return new possible_end_if(q, vq);
		 }
		 else if (ALine == "pred_candidate_examined")
		 {
			 int				w, e;
			 string			q;

			 ALine = subl.substr(0, subl.find(co, 0));
			 q = ALine;
			 pos += ALine.length();
			 subl = inputline.substr(++pos, inputline.length() - pos);

			 ALine = subl.substr(0, subl.find(co, 0));
			 w = stoi(ALine);
			 pos += ALine.length();
			 subl = inputline.substr(++pos, inputline.length() - pos);

			 ALine = subl.substr(0, subl.rfind(pacl, 0));
			 e = stoi(ALine);

			 return new pred_candidate_examined(q, w, e);
		 }
		 else if (ALine == "predecessors")
		 {
			 vq.clear();
			 int				w;
			 string			q;

			 ALine = subl.substr(0, subl.find(co, 0));
			 q = ALine;
			 pos += ALine.length();
			 subl = inputline.substr(++pos, inputline.length() - pos);

			 ALine = subl.substr(0, subl.find(co, 0));
			 w = stoi(ALine);
			 pos += ALine.length() + 1;
			 subl = inputline.substr(++pos, inputline.length() - pos);

			 //vector
			 if ((subl.find(brcl, 0)) != 0)
			 {
				 brpos = subl.find(brcl, 0);
				 while (subl.find(co, 0) < brpos)
				 {
					 ALine = subl.substr(0, subl.find(co, 0));
					 vq.push_back(stoi(ALine));
					 pos += ALine.length();
					 subl = inputline.substr(++pos, inputline.length() - pos);
					 brpos -= ALine.length();
					 brpos--;
				 }
				 ALine = subl.substr(0, subl.find(brcl, 0));
				 vq.push_back(stoi(ALine));
			 }
			 return new predecessors(w, q, vq);
		 }
		 else if (ALine == "print_C_main_body")
		{
		int				q;

		ALine = subl.substr(0, subl.rfind(pacl, 0));
		q = stoi(ALine);

		return new print_C_main_body(q);
		}
		 else if (ALine == "printed_formal_ios_of_called_module")
		{
		int				w, e;
		string			q, r;

		ALine = subl.substr(0, subl.find(co, 0));
		q = ALine;
		pos += ALine.length();
		subl = inputline.substr(++pos, inputline.length() - pos);

		ALine = subl.substr(0, subl.find(co, 0));
		w = stoi(ALine);
		pos += ALine.length();
		subl = inputline.substr(++pos, inputline.length() - pos);

		ALine = subl.substr(0, subl.find(co, 0));
		e = stoi(ALine);
		pos += ALine.length();
		subl = inputline.substr(++pos, inputline.length() - pos);

		ALine = subl.substr(0, subl.rfind(pacl, 0));
		ALine.resize(ALine.size() - 1);
		r = ALine;

		return new printed_formal_ios_of_called_module(q, w, e, r);
		}
		 else if (ALine == "prog_stmt")
	{
	int				w, e, r, t, y, u, i;
	string			q;

	ALine = subl.substr(0, subl.find(co, 0));
	q = ALine;
	pos += ALine.length();
	subl = inputline.substr(++pos, inputline.length() - pos);

	ALine = subl.substr(0, subl.find(co, 0));
	w = stoi(ALine);
	pos += ALine.length();
	subl = inputline.substr(++pos, inputline.length() - pos);

	ALine = subl.substr(0, subl.find(co, 0));
	e = stoi(ALine);
	pos += ALine.length();
	subl = inputline.substr(++pos, inputline.length() - pos);

	ALine = subl.substr(0, subl.find(co, 0));
	r = stoi(ALine);
	pos += ALine.length();
	subl = inputline.substr(++pos, inputline.length() - pos);

	ALine = subl.substr(0, subl.find(co, 0));
	t = stoi(ALine);
	pos += ALine.length();
	subl = inputline.substr(++pos, inputline.length() - pos);

	ALine = subl.substr(0, subl.find(co, 0));
	y = stoi(ALine);
	pos += ALine.length();
	subl = inputline.substr(++pos, inputline.length() - pos);

	ALine = subl.substr(0, subl.find(co, 0));
	u = stoi(ALine);
	pos += ALine.length();
	subl = inputline.substr(++pos, inputline.length() - pos);

	ALine = subl.substr(0, subl.rfind(pacl, 0));
	i = stoi(ALine);
	return new prog_stmt(w, e, r, t, y, u, i, q);
	}

		break;
	}
	case 'q':
	{

		break;
	}
	case 'r':
	{
		if (ALine == "raw_cessor")
		{
			int				w, e;
			string			q;

			ALine = subl.substr(0, subl.find(co, 0));
			q = ALine;
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);

			ALine = subl.substr(0, subl.find(co, 0));
			w = stoi(ALine);
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);

			ALine = subl.substr(0, subl.rfind(pacl, 0));
			e = stoi(ALine);

			return new raw_cessor(q, w, e);
		}
		else if (ALine == "raw_dependencies")
		{
			vq.clear();
			vw.clear();
			int				w;
			string			q;

			ALine = subl.substr(0, subl.find(co, 0));
			q = ALine;
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);

			ALine = subl.substr(0, subl.find(co, 0));
			w = stoi(ALine);
			pos += ALine.length() + 1;
			subl = inputline.substr(++pos, inputline.length() - pos);

			//vector
			if ((subl.find(brcl, 0)) != 0)
			{
				brpos = subl.find(brcl, 0);
				while (subl.find(co, 0) < brpos)
				{
					ALine = subl.substr(0, subl.find(co, 0));
					vq.push_back(stoi(ALine));
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
					brpos -= ALine.length();
					brpos--;
				}
				ALine = subl.substr(0, subl.find(brcl, 0));
				vq.push_back(stoi(ALine));
				pos += ALine.length() + 2;		// getting after bracket
				subl = inputline.substr(++pos, inputline.length() - pos);
			}
			else subl = inputline.substr(++++++pos, inputline.length() - pos);

			//vector2
			if ((subl.find(brcl, 0)) != 0)
			{
				brpos = subl.find(brcl, 0);
				while (subl.find(co, 0) < brpos)
				{
					ALine = subl.substr(0, subl.find(co, 0));
					vw.push_back(stoi(ALine));
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
					brpos -= ALine.length();
					brpos--;
				}
				ALine = subl.substr(0, subl.find(brcl, 0));
				vw.push_back(stoi(ALine));
			}
			return new raw_dependencies(q, w, vq, vw);
		}
		else if (ALine == "rec_stmt")
		{
			vq.clear();
			int				w;
			string			q;

			ALine = subl.substr(0, subl.find(co, 0));
			q = ALine;
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);

			ALine = subl.substr(0, subl.find(co, 0));
			w = stoi(ALine);
			pos += ALine.length() + 1;
			subl = inputline.substr(++pos, inputline.length() - pos);

			//vector
			if ((subl.find(brcl, 0)) != 0)
			{
				brpos = subl.find(brcl, 0);
				while (subl.find(co, 0) < brpos)
				{
					ALine = subl.substr(0, subl.find(co, 0));
					vq.push_back(stoi(ALine));
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
					brpos -= ALine.length();
					brpos--;
				}
				ALine = subl.substr(0, brpos);
				vq.push_back(stoi(ALine));
			}
			return new rec_stmt(w, q, vq);
		}
		else if (ALine == "record_aggregates_list")
	{
	vq.clear();
	int				w;
	string			q;

	ALine = subl.substr(0, subl.find(co, 0));
	q = ALine;
	pos += ALine.length();
	subl = inputline.substr(++pos, inputline.length() - pos);

	ALine = subl.substr(0, subl.find(co, 0));
	w = stoi(ALine);
	pos += ALine.length() + 1;
	subl = inputline.substr(++pos, inputline.length() - pos);

	//vector
	if ((subl.find(brcl, 0)) != 0)
	{
		brpos = subl.find(brcl, 0);
		while (subl.find(co, 0) < brpos)
		{
			ALine = subl.substr(0, subl.find(co, 0));
			vq.push_back(stoi(ALine));
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);
			brpos -= ALine.length();
			brpos--;
		}
		ALine = subl.substr(0, subl.find(brcl, 0));
		vq.push_back(stoi(ALine));
	}
	return new record_aggregates_list(q, w, vq);
	}
		else if (ALine == "reentrant_triangle")
	{
	int				w, e, r, a, s;
	string			q, d, f;

	ALine = subl.substr(0, subl.find(co, 0));
	q = ALine;
	pos += ALine.length();
	subl = inputline.substr(++pos, inputline.length() - pos);

	ALine = subl.substr(0, subl.find(co, 0));
	w = stoi(ALine);
	pos += ALine.length();
	subl = inputline.substr(++pos, inputline.length() - pos);

	ALine = subl.substr(0, subl.find(co, 0));
	e = stoi(ALine);
	pos += ALine.length();
	subl = inputline.substr(++pos, inputline.length() - pos);

	ALine = subl.substr(0, subl.find(co, 0));
	r = stoi(ALine);
	pos += ALine.length() + 1;
	subl = inputline.substr(++pos, inputline.length() - pos);

	//vector
	if ((subl.find(brcl, 0)) != 0)
	{
		brpos = subl.find(brcl, 0);
		while (subl.find(co, 0) < brpos)
		{
			ALine = subl.substr(0, subl.find(co, 0));
			vq.push_back(stoi(ALine));
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);
			brpos -= ALine.length();
			brpos--;
		}
		ALine = subl.substr(0, subl.find(brcl, 0));
		vq.push_back(stoi(ALine));
		pos += ALine.length() + 2;		// getting after bracket
		subl = inputline.substr(++pos, inputline.length() - pos);
	}
	else subl = inputline.substr(++++++pos, inputline.length() - pos);

	//vector2
	if ((subl.find(brcl, 0)) != 0)
	{
		brpos = subl.find(brcl, 0);
		while (subl.find(co, 0) < brpos)
		{
			ALine = subl.substr(0, subl.find(co, 0));
			vw.push_back(stoi(ALine));
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);
			brpos -= ALine.length();
			brpos--;
		}
		ALine = subl.substr(0, subl.find(brcl, 0));
		vw.push_back(stoi(ALine));
		pos += ALine.length() + 2;		// getting after bracket
		subl = inputline.substr(++pos, inputline.length() - pos);
	}
	else subl = inputline.substr(++++++pos, inputline.length() - pos);

	//vector3
	if ((subl.find(brcl, 0)) != 0)
	{
		brpos = subl.find(brcl, 0);
		while (subl.find(co, 0) < brpos)
		{
			ALine = subl.substr(0, subl.find(co, 0));
			ve.push_back(stoi(ALine));
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);
			brpos -= ALine.length();
			brpos--;
		}
		ALine = subl.substr(0, subl.find(brcl, 0));
		ve.push_back(stoi(ALine));
		pos += ALine.length() + 2;		// getting after bracket
		subl = inputline.substr(++pos, inputline.length() - pos);
	}
	else subl = inputline.substr(++++++pos, inputline.length() - pos);

	//vector4
	if ((subl.find(brcl, 0)) != 0)
	{
		brpos = subl.find(brcl, 0);
		while (subl.find(co, 0) < brpos)
		{
			ALine = subl.substr(0, subl.find(co, 0));
			vr.push_back(stoi(ALine));
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);
			brpos -= ALine.length();
			brpos--;
		}
		ALine = subl.substr(0, subl.find(brcl, 0));
		vr.push_back(stoi(ALine));
		pos += ALine.length() + 2;		// getting after bracket
		subl = inputline.substr(++pos, inputline.length() - pos);
	}
	else subl = inputline.substr(++++++pos, inputline.length() - pos);

	//vector5
	if ((subl.find(brcl, 0)) != 0)
	{
		brpos = subl.find(brcl, 0);
		while (subl.find(co, 0) < brpos)
		{
			ALine = subl.substr(0, subl.find(co, 0));
			vt.push_back(stoi(ALine));
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);
			brpos -= ALine.length();
			brpos--;
		}
		ALine = subl.substr(0, subl.find(brcl, 0));
		vt.push_back(stoi(ALine));
		pos += ALine.length() + 2;		// getting after bracket
		subl = inputline.substr(++pos, inputline.length() - pos);
	}
	else subl = inputline.substr(++++++pos, inputline.length() - pos);

	//vector6
	if ((subl.find(brcl, 0)) != 0)
	{
		brpos = subl.find(brcl, 0);
		while (subl.find(co, 0) < brpos)
		{
			ALine = subl.substr(0, subl.find(co, 0));
			vy.push_back(stoi(ALine));
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);
			brpos -= ALine.length();
			brpos--;
		}
		ALine = subl.substr(0, subl.find(brcl, 0));
		vy.push_back(stoi(ALine));
		pos += ALine.length() + 1;		// getting after bracket
		subl = inputline.substr(++pos, inputline.length() - pos);
	}
	else subl = inputline.substr(++++pos, inputline.length() - pos);

	ALine = subl.substr(0, subl.find(co, 0));
	a = stoi(ALine);
	pos += ALine.length();
	subl = inputline.substr(++pos, inputline.length() - pos);

	ALine = subl.substr(0, subl.find(co, 0));
	s = stoi(ALine);
	pos += ALine.length();
	subl = inputline.substr(++pos, inputline.length() - pos);

	ALine = subl.substr(0, subl.find(co, 0));
	d = ALine;
	pos += ALine.length();
	subl = inputline.substr(++pos, inputline.length() - pos);

	ALine = subl.substr(0, subl.find(co, 0));
	ALine.resize(ALine.size() - 1);
	f = ALine;

	return new reentrant_triangle(q, w, e, r, vq, vw, ve, vr, vt, vy, a, s, d, f);
	}
		else if (ALine == "rescheduled")
	{
	int				e, t;
	string			q, w, r;

	ALine = subl.substr(0, subl.find(co, 0));
	q = ALine;
	pos += ALine.length();
	subl = inputline.substr(++pos, inputline.length() - pos);

	ALine = subl.substr(0, subl.find(co, 0));
	w = ALine;
	pos += ALine.length();
	subl = inputline.substr(++pos, inputline.length() - pos);

	ALine = subl.substr(0, subl.find(co, 0));
	e = stoi(ALine);
	pos += ALine.length();
	subl = inputline.substr(++pos, inputline.length() - pos);

	ALine = subl.substr(0, subl.find(co, 0));
	r = ALine;
	pos += ALine.length();
	subl = inputline.substr(++pos, inputline.length() - pos);

	ALine = subl.substr(0, subl.rfind(pacl, 0));
	t = stoi(ALine);

	return new rescheduled(w, e, q, r, t);
	}
		else if (ALine == "resetstyle")
		{
		string			q;

		ALine = subl.substr(0, subl.rfind(pacl, 0));
		ALine.resize(ALine.size() - 1);
		q = ALine;

		return new resetstyle(q);
		}

		break;
	}
	case 's':
	{
		if (ALine == "schedule")
		{
			int				w, r;
			string			q, e;

			ALine = subl.substr(0, subl.find(co, 0));
			q = ALine;
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);

			ALine = subl.substr(0, subl.find(co, 0));
			w = stoi(ALine);
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);

			ALine = subl.substr(0, subl.find(co, 0));
			e = ALine;
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);

			ALine = subl.substr(0, subl.find(co, 0));
			r = stoi(ALine);

			return new schedule(q, w, e, r);
		}
		else if (ALine == "sequence")
		{
			int				q, e;
			string			w;

			ALine = subl.substr(0, subl.find(co, 0));
			q = stoi(ALine);
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);

			ALine = subl.substr(0, subl.find(co, 0));
			w = ALine;
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);

			ALine = subl.substr(0, subl.rfind(pacl, 0));
			e = stoi(ALine);

			return new sequence(q, w, e);
		}
		else if (ALine == "signal_instance")
		{
			int				q, t, y, u;
			string			w, e, r;

			ALine = subl.substr(0, subl.find(co, 0));
			q = stoi(ALine);
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);

			ALine = subl.substr(0, subl.find(co, 0));
			w = ALine;
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);

			ALine = subl.substr(0, subl.find(co, 0));
			e = ALine;
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);

			ALine = subl.substr(0, subl.find(co, 0));
			r = ALine;
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);

			ALine = subl.substr(0, subl.find(co, 0));
			t = stoi(ALine);
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);

			ALine = subl.substr(0, subl.find(co, 0));
			y = stoi(ALine);
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);

			ALine = subl.substr(0, subl.rfind(pacl, 0));
			u = stoi(ALine);

			return new signal_instance(q, w, e, r, t, y, u);
		}
		else if (ALine == "source_is_normal_dt")
		{
			int				w, e;
			string			q;

			ALine = subl.substr(0, subl.find(co, 0));
			q = ALine;
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);

			ALine = subl.substr(0, subl.find(co, 0));
			w = stoi(ALine);
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);

			ALine = subl.substr(0, subl.rfind(pacl, 0));
			e = stoi(ALine);

			return new source_is_normal_dt(q, w, e);
		}
		else if (ALine == "special_dt")
		{
			int				w, r;
			string			q, e, t, y, u;

			ALine = subl.substr(0, subl.find(co, 0));
			q = ALine;
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);

			ALine = subl.substr(0, subl.find(co, 0));
			w = stoi(ALine);
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);

			ALine = subl.substr(0, subl.find(co, 0));
			e = ALine;
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);

			ALine = subl.substr(0, subl.find(co, 0));
			r = stoi(ALine);
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);

			ALine = subl.substr(0, subl.find(co, 0));
			t = ALine;
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);

			ALine = subl.substr(0, subl.find(co, 0));
			y = ALine;
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);

			ALine = subl.substr(0, subl.rfind(pacl, 0));
			ALine.resize(ALine.size() - 1);
			u = ALine;
			return new special_dt(w, r, q, e, t, y, u);
		}
		else if (ALine == "special_op")
	{
	int				w, r, t, y, i, o, p;
	string			q, e, u;

	ALine = subl.substr(0, subl.find(co, 0));
	q = ALine;
	pos += ALine.length();
	subl = inputline.substr(++pos, inputline.length() - pos);

	ALine = subl.substr(0, subl.find(co, 0));
	w = stoi(ALine);
	pos += ALine.length();
	subl = inputline.substr(++pos, inputline.length() - pos);

	ALine = subl.substr(0, subl.find(co, 0));
	e = ALine;
	pos += ALine.length();
	subl = inputline.substr(++pos, inputline.length() - pos);

	ALine = subl.substr(0, subl.find(co, 0));
	r = stoi(ALine);
	pos += ALine.length();
	subl = inputline.substr(++pos, inputline.length() - pos);

	ALine = subl.substr(0, subl.find(co, 0));
	t = stoi(ALine);
	pos += ALine.length();
	subl = inputline.substr(++pos, inputline.length() - pos);

	ALine = subl.substr(0, subl.find(co, 0));
	y = stoi(ALine);
	pos += ALine.length();
	subl = inputline.substr(++pos, inputline.length() - pos);

	ALine = subl.substr(0, subl.find(co, 0));
	u = ALine;
	pos += ALine.length();
	subl = inputline.substr(++pos, inputline.length() - pos);

	ALine = subl.substr(0, subl.find(co, 0));
	i = stoi(ALine);
	pos += ALine.length();
	subl = inputline.substr(++pos, inputline.length() - pos);

	ALine = subl.substr(0, subl.find(co, 0));
	o = stoi(ALine);
	pos += ALine.length();
	subl = inputline.substr(++pos, inputline.length() - pos);

	ALine = subl.substr(0, subl.rfind(pacl, 0));
	p = stoi(ALine);
	return new special_op(w, r, t, y, i, o, p, q, e, u);
	}
		else if (ALine == "state")
	{
	vq.clear();
	vw.clear();
	int				e, t, y;
	string			q, w, r;

	ALine = subl.substr(0, subl.find(co, 0));
	q = ALine;
	pos += ALine.length();
	subl = inputline.substr(++pos, inputline.length() - pos);

	ALine = subl.substr(0, subl.find(co, 0));
	w = ALine;
	pos += ALine.length();
	subl = inputline.substr(++pos, inputline.length() - pos);

	ALine = subl.substr(0, subl.find(co, 0));
	e = stoi(ALine);
	pos += ALine.length();
	subl = inputline.substr(++pos, inputline.length() - pos);

	ALine = subl.substr(0, subl.find(co, 0));
	r = ALine;
	pos += ALine.length();
	subl = inputline.substr(++pos, inputline.length() - pos);

	ALine = subl.substr(0, subl.find(co, 0));
	t = stoi(ALine);
	pos += ALine.length();
	subl = inputline.substr(++pos, inputline.length() - pos);

	ALine = subl.substr(0, subl.find(co, 0));
	y = stoi(ALine);
	pos += ALine.length() + 1;
	subl = inputline.substr(++pos, inputline.length() - pos);

	//vector
	if ((subl.find(brcl, 0)) != 0)
	{
		brpos = subl.find(brcl, 0);
		while (subl.find(co, 0) < brpos)
		{
			ALine = subl.substr(0, subl.find(co, 0));
			vq.push_back(stoi(ALine));
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);
			brpos -= ALine.length();
			brpos--;
		}
		ALine = subl.substr(0, subl.find(brcl, 0));
		vq.push_back(stoi(ALine));
		pos += ALine.length() + 2;		// getting after bracket
		subl = inputline.substr(++pos, inputline.length() - pos);
	}
	else subl = inputline.substr(++++++pos, inputline.length() - pos);

	//vector2
	if ((subl.find(brcl, 0)) != 0)
	{
		brpos = subl.find(brcl, 0);
		while (subl.find(co, 0) < brpos)
		{
			ALine = subl.substr(0, subl.find(co, 0));
			vw.push_back(stoi(ALine));
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);
			brpos -= ALine.length();
			brpos--;
		}
		ALine = subl.substr(0, subl.find(brcl, 0));
		vw.push_back(stoi(ALine));
	}

	return new state(q, w, e, r, t, y, vq, vw);
	}
		else if (ALine == "state_node")
	{
	vq.clear();
	int				w, e, r;
	string			q;

	ALine = subl.substr(0, subl.find(co, 0));
	q = ALine;
	pos += ALine.length();
	subl = inputline.substr(++pos, inputline.length() - pos);

	ALine = subl.substr(0, subl.find(co, 0));
	w = stoi(ALine);
	pos += ALine.length();
	subl = inputline.substr(++pos, inputline.length() - pos);

	ALine = subl.substr(0, subl.find(pa, 0));
	pos += ALine.size() + 1;
	subl = inputline.substr(++pos, inputline.length() - pos);
	if (ALine == "subprogram_call")
	{
		//vector
		if ((subl.find(brcl, 0)) != 0)
		{
			brpos = subl.find(brcl, 0);
			while (subl.find(co, 0) < brpos)
			{
				ALine = subl.substr(0, subl.find(co, 0));
				vq.push_back(stoi(ALine));
				pos += ALine.length();
				subl = inputline.substr(++pos, inputline.length() - pos);
				brpos -= ALine.length();
				brpos--;
			}
			ALine = subl.substr(0, subl.find(brcl, 0));
			vq.push_back(stoi(ALine));
			pos += ALine.length() + 1;		// getting after bracket
			subl = inputline.substr(++pos, inputline.length() - pos);
		}
		else subl = inputline.substr(++++pos, inputline.length() - pos);

		ALine = subl.substr(0, subl.find(pacl, 0));
		e = stoi(ALine);
		return new subprogram_call(e, vq, w, q);
	}
	else if (ALine == "dataflow")
	{
		//vector
		if ((subl.find(brcl, 0)) != 0)
		{
			brpos = subl.find(brcl, 0);
			while (subl.find(co, 0) < brpos)
			{
				ALine = subl.substr(0, subl.find(co, 0));
				vq.push_back(stoi(ALine));
				pos += ALine.length();
				subl = inputline.substr(++pos, inputline.length() - pos);
				brpos -= ALine.length();
				brpos--;
			}
			ALine = subl.substr(0, subl.find(brcl, 0));
			vq.push_back(stoi(ALine));
			pos += ALine.length() + 1;		// getting after bracket
			subl = inputline.substr(++pos, inputline.length() - pos);
		}
		else subl = inputline.substr(++++pos, inputline.length() - pos);

		ALine = subl.substr(0, subl.find(pacl, 0));
		e = stoi(ALine);
		return new dataflow(e, vq, w, q);
	}
	else if (ALine == "ifthen")
	{
		vw.clear();
		ve.clear();

		//vector
		if ((subl.find(brcl, 0)) != 0)
		{
			brpos = subl.find(brcl, 0);
			while (subl.find(co, 0) < brpos)
			{
				ALine = subl.substr(0, subl.find(co, 0));
				vq.push_back(stoi(ALine));
				pos += ALine.length();
				subl = inputline.substr(++pos, inputline.length() - pos);
				brpos -= ALine.length();
				brpos--;
			}
			ALine = subl.substr(0, subl.find(brcl, 0));
			vq.push_back(stoi(ALine));
			pos += ALine.length() + 2;		// getting after bracket
			subl = inputline.substr(++pos, inputline.length() - pos);
		}
		else subl = inputline.substr(++++++pos, inputline.length() - pos);

		//vector2
		if ((subl.find(brcl, 0)) != 0)
		{
			brpos = subl.find(brcl, 0);
			while (subl.find(co, 0) < brpos)
			{
				ALine = subl.substr(0, subl.find(co, 0));
				vw.push_back(stoi(ALine));
				pos += ALine.length();
				subl = inputline.substr(++pos, inputline.length() - pos);
				brpos -= ALine.length();
				brpos--;
			}
			ALine = subl.substr(0, subl.find(brcl, 0));
			vw.push_back(stoi(ALine));
			pos += ALine.length() + 2;		// getting after bracket
			subl = inputline.substr(++pos, inputline.length() - pos);
		}
		else subl = inputline.substr(++++++pos, inputline.length() - pos);

		//vector3
		if ((subl.find(brcl, 0)) != 0)
		{
			brpos = subl.find(brcl, 0);
			while (subl.find(co, 0) < brpos)
			{
				ALine = subl.substr(0, subl.find(co, 0));
				ve.push_back(stoi(ALine));
				pos += ALine.length();
				subl = inputline.substr(++pos, inputline.length() - pos);
				brpos -= ALine.length();
				brpos--;
			}
			ALine = subl.substr(0, subl.find(brcl, 0));
			ve.push_back(stoi(ALine));
			pos += ALine.length() + 1;		// getting after bracket
			subl = inputline.substr(++pos, inputline.length() - pos);
		}
		else subl = inputline.substr(++++pos, inputline.length() - pos);

		subl = inputline.substr(pos, inputline.length() - pos);
		ALine = subl.substr(0, subl.find(co, 0));
		e = stoi(ALine);
		pos += ALine.length();
		subl = inputline.substr(++pos, inputline.length() - pos);

		ALine = subl.substr(0, subl.rfind(pacl, 0));
		r = stoi(ALine);
		pos += ALine.length();
		return new ifthen(e, r, vq, vw, ve, w, q);
	}
	else if (ALine == "jump")
	{
		//vector
		if ((subl.find(brcl, 0)) != 0)
		{
			brpos = subl.find(brcl, 0);
			while (subl.find(co, 0) < brpos)
			{
				ALine = subl.substr(0, subl.find(co, 0));
				vq.push_back(stoi(ALine));
				pos += ALine.length();
				subl = inputline.substr(++pos, inputline.length() - pos);
				brpos -= ALine.length();
				brpos--;
			}
			ALine = subl.substr(0, subl.find(brcl, 0));
			vq.push_back(stoi(ALine));
			pos += ALine.length() + 1;		// getting after bracket
			subl = inputline.substr(++pos, inputline.length() - pos);
		}
		else subl = inputline.substr(++++pos, inputline.length() - pos);

		ALine = subl.substr(0, subl.find(pacl, 0));
		e = stoi(ALine);
		return new jump(e, vq, w, q);
	}
	else if (ALine == "return")
	{
		//vector
		if ((subl.find(brcl, 0)) != 0)
		{
			brpos = subl.find(brcl, 0);
			while (subl.find(co, 0) < brpos)
			{
				ALine = subl.substr(0, subl.find(co, 0));
				vq.push_back(stoi(ALine));
				pos += ALine.length();
				subl = inputline.substr(++pos, inputline.length() - pos);
				brpos -= ALine.length();
				brpos--;
			}
			ALine = subl.substr(0, subl.find(brcl, 0));
			vq.push_back(stoi(ALine));
			pos += ALine.length() + 1;		// getting after bracket
			subl = inputline.substr(++pos, inputline.length() - pos);
		}

		return new return_cos(vq, w, q);
	}
	}

		break;
	}
	case 't':
	{
		if (ALine == "targets_conditional_variable")
		{
			int				w, e, r;
			string			q;

			ALine = subl.substr(0, subl.find(co, 0));
			q = ALine;
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);

			ALine = subl.substr(0, subl.find(co, 0));
			w = stoi(ALine);
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);

			ALine = subl.substr(0, subl.find(co, 0));
			e = stoi(ALine);
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);

			ALine = subl.substr(0, subl.rfind(pacl, 0));
			r = stoi(ALine);

			return new targets_conditional_variable(q, w, e, r);
		}
		else if (ALine == "top_level_call")
		{
			int				q, w, r, y, i, p;
			string			e, t, u, o, a;

			ALine = subl.substr(0, subl.find(co, 0));
			q = stoi(ALine);
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);

			ALine = subl.substr(0, subl.find(co, 0));
			w = stoi(ALine);
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);

			ALine = subl.substr(0, subl.find(co, 0));
			e = ALine;
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);

			ALine = subl.substr(0, subl.find(co, 0));
			r = stoi(ALine);
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);

			ALine = subl.substr(0, subl.find(co, 0));
			t = ALine;
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);

			ALine = subl.substr(0, subl.find(co, 0));
			y = stoi(ALine);
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);

			ALine = subl.substr(0, subl.find(co, 0));
			u = ALine;
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);

			ALine = subl.substr(0, subl.find(co, 0));
			i = stoi(ALine);
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);

			ALine = subl.substr(0, subl.find(co, 0));
			o = ALine;
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);

			ALine = subl.substr(0, subl.find(co, 0));
			p = stoi(ALine);
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);

			ALine = subl.substr(0, subl.find(pacl, 0));
			a = ALine;

			return new top_level_call(q, w, e, r, t, y, u, i, o, p, a);
		}
		else if (ALine == "top_level_call_parcs")
		{
			int				q, w, r, y, i, p;
			string			e, t, u, o, a;

			ALine = subl.substr(0, subl.find(co, 0));
			q = stoi(ALine);
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);

			ALine = subl.substr(0, subl.find(co, 0));
			w = stoi(ALine);
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);

			ALine = subl.substr(0, subl.find(co, 0));
			e = ALine;
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);

			ALine = subl.substr(0, subl.find(co, 0));
			r = stoi(ALine);
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);

			ALine = subl.substr(0, subl.find(co, 0));
			t = ALine;
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);

			ALine = subl.substr(0, subl.find(co, 0));
			y = stoi(ALine);
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);

			ALine = subl.substr(0, subl.find(co, 0));
			u = ALine;
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);

			ALine = subl.substr(0, subl.find(co, 0));
			i = stoi(ALine);
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);

			ALine = subl.substr(0, subl.find(co, 0));
			o = ALine;
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);

			ALine = subl.substr(0, subl.find(co, 0));
			p = stoi(ALine);
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);

			ALine = subl.substr(0, subl.find(pacl, 0));
			a = ALine;

			return new top_level_call_parcs(q, w, e, r, t, y, u, i, o, p, a);
		}
		else if (ALine == "top_module")
		{
		string			q;

		ALine = subl.substr(0, subl.rfind(pacl, 0));
		ALine.resize(ALine.size() - 1);
		q = ALine;

		return new top_module(q);
		}
		else if (ALine == "total_local_entry")
		{
		int				q;

		ALine = subl.substr(0, subl.rfind(pacl, 0));
		q = stoi(ALine);

		return new total_local_entry(q);
		}
		else if (ALine == "totalmax_call_order")
	{
	int				e;
	string			q, w;

	ALine = subl.substr(0, subl.find(co, 0));
	q = ALine;
	pos += ALine.length();
	subl = inputline.substr(++pos, inputline.length() - pos);

	ALine = subl.substr(0, subl.find(co, 0));
	w = ALine;
	pos += ALine.length();
	subl = inputline.substr(++pos, inputline.length() - pos);

	ALine = subl.substr(0, subl.rfind(pacl, 0));
	e = stoi(ALine);

	return new totalmax_call_order(q, w, e);
	}
		else if (ALine == "totalmax_gross_depth")
	{
	int				e;
	string			q, w;

	ALine = subl.substr(0, subl.find(co, 0));
	q = ALine;
	pos += ALine.length();
	subl = inputline.substr(++pos, inputline.length() - pos);

	ALine = subl.substr(0, subl.find(co, 0));
	w = ALine;
	pos += ALine.length();
	subl = inputline.substr(++pos, inputline.length() - pos);

	ALine = subl.substr(0, subl.rfind(pacl, 0));
	e = stoi(ALine);

	return new totalmax_gross_depth(q, w, e);
	}
		else if (ALine == "transition_to_be_rescheduled")
	{
	int				e, t;
	string			q, w, r;

	ALine = subl.substr(0, subl.find(co, 0));
	q = ALine;
	pos += ALine.length();
	subl = inputline.substr(++pos, inputline.length() - pos);

	ALine = subl.substr(0, subl.find(co, 0));
	w = ALine;
	pos += ALine.length();
	subl = inputline.substr(++pos, inputline.length() - pos);

	ALine = subl.substr(0, subl.find(co, 0));
	e = stoi(ALine);
	pos += ALine.length();
	subl = inputline.substr(++pos, inputline.length() - pos);


	ALine = subl.substr(0, subl.find(co, 0));
	r = ALine;
	pos += ALine.length();
	subl = inputline.substr(++pos, inputline.length() - pos);

	ALine = subl.substr(0, subl.rfind(pacl, 0));
	t = stoi(ALine);

	return new transition_to_be_rescheduled(w, e, q, r, t);
	}
		else if (ALine == "type_def")
	{
		int				q, e, t, u, i, o;
		string			w, r, y;

		ALine = subl.substr(0, subl.find(co, 0));
		q = stoi(ALine);
		pos += ALine.length();
		subl = inputline.substr(++pos, inputline.length() - pos);

		ALine = subl.substr(0, subl.find(co, 0));
		w = ALine;
		pos += ALine.length();
		subl = inputline.substr(++pos, inputline.length() - pos);

		ALine = subl.substr(0, subl.find(co, 0));
		e = stoi(ALine);
		pos += ALine.length();
		subl = inputline.substr(++pos, inputline.length() - pos);

		ALine = subl.substr(0, subl.find(co, 0));
		r = ALine;
		pos += ALine.length();
		subl = inputline.substr(++pos, inputline.length() - pos);

		ALine = subl.substr(0, subl.find(co, 0));
		t = stoi(ALine);
		pos += ALine.length();
		subl = inputline.substr(++pos, inputline.length() - pos);

		ALine = subl.substr(0, subl.find(co, 0));
		y = ALine;
		pos += ALine.length();
		subl = inputline.substr(++pos, inputline.length() - pos);

		ALine = subl.substr(0, subl.find(co, 0));
		u = stoi(ALine);
		pos += ALine.length();
		subl = inputline.substr(++pos, inputline.length() - pos);

		ALine = subl.substr(0, subl.find(co, 0));
		i = stoi(ALine);
		pos += ALine.length();
		subl = inputline.substr(++pos, inputline.length() - pos);

		ALine = subl.substr(0, subl.rfind(pacl, 0));
		ALine.resize(ALine.size() - 1);
		o = stoi(ALine);
		return new type_def(q, e, t, u, i, o, w, r, y);
	}

		break;
	}
	case 'u':
	{

		break;
	}
	case 'v':
	{
		if (ALine == "var_guards")
		{
			vq.clear();
			vw.clear();
			int				w;
			string			q;

			ALine = subl.substr(0, subl.find(co, 0));
			q = ALine;
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);

			ALine = subl.substr(0, subl.find(co, 0));
			w = stoi(ALine);
			pos += ALine.length() + 1;
			subl = inputline.substr(++pos, inputline.length() - pos);

			//vector
			if ((subl.find(brcl, 0)) != 0)
			{
				brpos = subl.find(brcl, 0);
				while (subl.find(co, 0) < brpos)
				{
					ALine = subl.substr(0, subl.find(co, 0));
					vq.push_back(stoi(ALine));
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
					brpos -= ALine.length();
					brpos--;
				}
				ALine = subl.substr(0, subl.find(brcl, 0));
				vq.push_back(stoi(ALine));
				pos += ALine.length() + 2;		// getting after bracket
				subl = inputline.substr(++pos, inputline.length() - pos);
			}
			else subl = inputline.substr(++++++pos, inputline.length() - pos);

			//vector2
			if ((subl.find(brcl, 0)) != 0)
			{
				brpos = subl.find(brcl, 0);
				while (subl.find(co, 0) < brpos)
				{
					ALine = subl.substr(0, subl.find(co, 0));
					vw.push_back(stoi(ALine));
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
					brpos -= ALine.length();
					brpos--;
				}
				ALine = subl.substr(0, subl.find(brcl, 0));
				vw.push_back(stoi(ALine));
			}

			return new var_guards(w, q, vq, vw);
		}
		else if (ALine == "variable_has_been_listed")
		{
			string			q, w;

			ALine = subl.substr(0, subl.find(co, 0));
			q = ALine;
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);

			ALine = subl.substr(0, subl.rfind(pacl, 0));
			ALine.resize(ALine.size() - 1);
			w = ALine;

			return new variable_has_been_listed(q, w);
		}

		break;
	}
	case 'w':
	{
		if (ALine == "war_dependencies")
		{
			int				w;
			string			q;

			ALine = subl.substr(0, subl.find(co, 0));
			q = ALine;
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);

			ALine = subl.substr(0, subl.find(co, 0));
			w = stoi(ALine);
			pos += ALine.length() + 1;
			subl = inputline.substr(++pos, inputline.length() - pos);

			//vector
			if ((subl.find(brcl, 0)) != 0)
			{
				brpos = subl.find(brcl, 0);
				while (subl.find(co, 0) < brpos)
				{
					ALine = subl.substr(0, subl.find(co, 0));
					vq.push_back(stoi(ALine));
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
					brpos -= ALine.length();
					brpos--;
				}
				ALine = subl.substr(0, subl.find(brcl, 0));
				vq.push_back(stoi(ALine));
				pos += ALine.length() + 2;		// getting after bracket
				subl = inputline.substr(++pos, inputline.length() - pos);
			}
			else subl = inputline.substr(++++++pos, inputline.length() - pos);

			//vector2
			if ((subl.find(brcl, 0)) != 0)
			{
				brpos = subl.find(brcl, 0);
				while (subl.find(co, 0) < brpos)
				{
					ALine = subl.substr(0, subl.find(co, 0));
					vw.push_back(stoi(ALine));
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
					brpos -= ALine.length();
					brpos--;
				}
				ALine = subl.substr(0, subl.find(brcl, 0));
				vw.push_back(stoi(ALine));
			}
			return new war_dependencies(q, w, vq, vw);
		}
		else if (ALine == "war_cessor")
		{
			int				w, e;
			string			q;

			ALine = subl.substr(0, subl.find(co, 0));
			q = ALine;
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);

			ALine = subl.substr(0, subl.find(co, 0));
			w = stoi(ALine);
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);

			ALine = subl.substr(0, subl.rfind(pacl, 0));
			e = stoi(ALine);

			return new war_cessor(q, w, e);
		}
		else if (ALine == "waw_cessor")
		{
			int				w, e;
			string			q;

			ALine = subl.substr(0, subl.find(co, 0));
			q = ALine;
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);

			ALine = subl.substr(0, subl.find(co, 0));
			w = stoi(ALine);
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);

			ALine = subl.substr(0, subl.rfind(pacl, 0));
			e = stoi(ALine);

			return new waw_cessor(q, w, e);
		}
		else if (ALine == "waw_dependencies")
		{
			vq.clear();
			vw.clear();
			int				w;
			string			q;

			ALine = subl.substr(0, subl.find(co, 0));
			q = ALine;
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);

			ALine = subl.substr(0, subl.find(co, 0));
			w = stoi(ALine);
			pos += ALine.length() + 1;
			subl = inputline.substr(++pos, inputline.length() - pos);

			//vector
			if ((subl.find(brcl, 0)) != 0)
			{
				brpos = subl.find(brcl, 0);
				while (subl.find(co, 0) < brpos)
				{
					ALine = subl.substr(0, subl.find(co, 0));
					vq.push_back(stoi(ALine));
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
					brpos -= ALine.length();
					brpos--;
				}
				ALine = subl.substr(0, subl.find(brcl, 0));
				vq.push_back(stoi(ALine));
				pos += ALine.length() + 2;		// getting after bracket
				subl = inputline.substr(++pos, inputline.length() - pos);
			}
			else subl = inputline.substr(++++++pos, inputline.length() - pos);

			//vector2
			if ((subl.find(brcl, 0)) != 0)
			{
				brpos = subl.find(brcl, 0);
				while (subl.find(co, 0) < brpos)
				{
					ALine = subl.substr(0, subl.find(co, 0));
					vw.push_back(stoi(ALine));
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
					brpos -= ALine.length();
					brpos--;
				}
				ALine = subl.substr(0, subl.find(brcl, 0));
				vw.push_back(stoi(ALine));
			}
			return new waw_dependencies(q, w, vq, vw);
		}
		else if (ALine == "while_loop")
	{
	int				q, e, r, t, y, u;
	string			w;

	ALine = subl.substr(0, subl.find(co, 0));
	q = stoi(ALine);
	pos += ALine.length();
	subl = inputline.substr(++pos, inputline.length() - pos);

	ALine = subl.substr(0, subl.find(co, 0));
	w = ALine;
	pos += ALine.length();
	subl = inputline.substr(++pos, inputline.length() - pos);

	ALine = subl.substr(0, subl.find(co, 0));
	e = stoi(ALine);
	pos += ALine.length();
	subl = inputline.substr(++pos, inputline.length() - pos);

	ALine = subl.substr(0, subl.find(co, 0));
	r = stoi(ALine);
	pos += ALine.length();
	subl = inputline.substr(++pos, inputline.length() - pos);

	ALine = subl.substr(0, subl.find(co, 0));
	t = stoi(ALine);
	pos += ALine.length();
	subl = inputline.substr(++pos, inputline.length() - pos);

	ALine = subl.substr(0, subl.find(co, 0));
	y = stoi(ALine);
	pos += ALine.length();
	subl = inputline.substr(++pos, inputline.length() - pos);

	ALine = subl.substr(0, subl.rfind(pacl, 0));
	u = stoi(ALine);

	return new while_loop(q, w, e, r, t, y, u);
	}

		break;
	}
	case 'x':
	{

		break;
	}
	case 'y':
	{

		break;
	}
	case 'z':
	{

		break;
	}
	}

	return new GenfactError(inputline);
}

/// @brief makes data with parameters until "*" of string
/// @param inputline <- the string
factstar makefactstar (string inputline)
{
	int						params = 0;
	string					ALine, subl;
	size_t					pos, brpos;
	bool					flag = 1, stop = 1;

	GeneralFact* ptr = nullptr;

	pos = 0;
	ALine = inputline.substr(0, inputline.find(pa, 0));
	pos += ALine.length();

	if (ALine == "type_def")
	{
		flag = 0;
		int				q{}, e{}, t{}, u{}, i{}, o{};
		string			w{}, r{}, y{};
		subl = inputline.substr(++pos, inputline.length() - pos);

		if ((subl.find(str, 0)) != 0)
		{
			params++;
			ALine = subl.substr(0, subl.find(co, 0));
			q = stoi(ALine);
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);
		}
		else stop = 0;
		if (stop)
		{
			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.find(co, 0));
				w = ALine;
				pos += ALine.length();
				subl = inputline.substr(++pos, inputline.length() - pos);
			}
			else stop = 0;
		}
		if (stop)
		{
			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.find(co, 0));
				e = stoi(ALine);
				pos += ALine.length();
				subl = inputline.substr(++pos, inputline.length() - pos);
			}
			else stop = 0;
		}
		if (stop)
		{
			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.find(co, 0));
				r = ALine;
				pos += ALine.length();
				subl = inputline.substr(++pos, inputline.length() - pos);
			}
			else stop = 0;
		}
		if (stop)
		{
			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.find(co, 0));
				t = stoi(ALine);
				pos += ALine.length();
				subl = inputline.substr(++pos, inputline.length() - pos);
			}
			else stop = 0;
		}
		if (stop)
		{
			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.find(co, 0));
				y = ALine;
				pos += ALine.length();
				subl = inputline.substr(++pos, inputline.length() - pos);
			}
			else stop = 0;
		}
		if (stop)
		{
			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.find(co, 0));
				u = stoi(ALine);
				pos += ALine.length();
				subl = inputline.substr(++pos, inputline.length() - pos);
			}
			else stop = 0;
		}
		if (stop)
		{
			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.find(co, 0));
				i = stoi(ALine);
				pos += ALine.length();
				subl = inputline.substr(++pos, inputline.length() - pos);
			}
			else stop = 0;
		}
		if (stop)
		{
			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.rfind(pacl, 0));
				ALine.resize(ALine.size() - 1);
				o = stoi(ALine);
			}
		}
		ptr = new type_def(q, e, t, u, i, o, w, r, y);
	}
	else if (ALine == "op_def")
	{
		flag = 0;
		int				q{}, r{}, t{}, y{}, u{};
		string			w{}, e{};
		subl = inputline.substr(++pos, inputline.length() - pos);

		if ((subl.find(str, 0)) != 0)
		{
			params++;
			ALine = subl.substr(0, subl.find(co, 0));
			q = stoi(ALine);
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);
		}
		else stop = 0;

		if (stop)
		{
			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.find(co, 0));
				w = ALine;
				pos += ALine.length();
				subl = inputline.substr(++pos, inputline.length() - pos);
			}
			else stop = 0;
		}

		if (stop)
		{
			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.find(co, 0));
				e = ALine;
				pos += ALine.length();
				subl = inputline.substr(++pos, inputline.length() - pos);
			}
			else stop = 0;
		}

		if (stop)
		{
			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.find(co, 0));
				r = stoi(ALine);
				pos += ALine.length();
				subl = inputline.substr(++pos, inputline.length() - pos);
			}
			else stop = 0;
		}

		if (stop)
		{
			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.find(co, 0));
				t = stoi(ALine);
				pos += ALine.length();
				subl = inputline.substr(++pos, inputline.length() - pos);
			}
			else stop = 0;
		}

		if (stop)
		{
			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.find(co, 0));
				y = stoi(ALine);
				pos += ALine.length();
				subl = inputline.substr(++pos, inputline.length() - pos);
			}
			else stop = 0;
		}

		if (stop)
		{
			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.rfind(pacl, 0));
				u = stoi(ALine);
			}
		}
		ptr = new op_def(q, r, t, y, u, w, e);
	}
	else if (ALine == "hierarchy_part")
	{
		flag = 0;
		int				q{}, e{}, t{}, y{}, u{};
		string			w{}, r{};
		subl = inputline.substr(++pos, inputline.length() - pos);

		if ((subl.find(str, 0)) != 0)
		{
			params++;
			ALine = subl.substr(0, subl.find(co, 0));
			q = stoi(ALine);
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);
		}
		else stop = 0;

		if (stop)
		{
			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.find(co, 0));
				w = ALine;
				pos += ALine.length();
				subl = inputline.substr(++pos, inputline.length() - pos);
			}
			else stop = 0;
		}

		if (stop)
		{
			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.find(co, 0));
				e = stoi(ALine);
				pos += ALine.length();
				subl = inputline.substr(++pos, inputline.length() - pos);
			}
			else stop = 0;
		}

		if (stop)
		{
			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.find(co, 0));
				r = ALine;
				pos += ALine.length();
				subl = inputline.substr(++pos, inputline.length() - pos);
			}
			else stop = 0;
		}

		if (stop)
		{
			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.find(co, 0));
				t = stoi(ALine);
				pos += ALine.length();
				subl = inputline.substr(++pos, inputline.length() - pos);
			}
			else stop = 0;
		}

		if (stop)
		{
			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.find(co, 0));
				y = stoi(ALine);
				pos += ALine.length();
				subl = inputline.substr(++pos, inputline.length() - pos);
			}
			else stop = 0;
		}

		if (stop)
		{
			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.rfind(pacl, 0));
				u = stoi(ALine);
			}
		}
		ptr = new hierarchy_part(q, e, t, y, u, w, r);
	}
	else if (ALine == "data_stmt")
	{
		flag = 0;
		int				e{}, r{};
		string			q{}, w{}, t{}, y{};
		subl = inputline.substr(++pos, inputline.length() - pos);

		if ((subl.find(str, 0)) != 0)
		{
			params++;
			ALine = subl.substr(0, subl.find(co, 0));
			q = ALine;
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);
		}
		else stop = 0;

		if (stop)
		{
			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.find(co, 0));
				w = ALine;
				pos += ALine.length();
				subl = inputline.substr(++pos, inputline.length() - pos);
			}
			else stop = 0;
		}
		if (stop)
		{
			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.find(co, 0));
				e = stoi(ALine);
				pos += ALine.length();
				subl = inputline.substr(++pos, inputline.length() - pos);
			}
			else stop = 0;
		}
		if (stop)
		{
			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.find(co, 0));
				r = stoi(ALine);
				pos += ALine.length();
				subl = inputline.substr(++pos, inputline.length() - pos);
			}
			else stop = 0;
		}
		if (stop)
		{
			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.find(co, 0));
				t = ALine;
				pos += ALine.length();
				subl = inputline.substr(++pos, inputline.length() - pos);
			}
			else stop = 0;
		}
		if (stop)
		{
			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.rfind(pacl, 0));
				ALine.resize(ALine.size() - 1);
				y = ALine;
			}
		}
		ptr = new data_stmt(e, r, q, w, t, y);
	}
	else if (ALine == "prog_stmt")
	{
		flag = 0;
		int				w{}, e{}, r{}, t{}, y{}, u{}, i{};
		string			q{};
		subl = inputline.substr(++pos, inputline.length() - pos);

		if ((subl.find(str, 0)) != 0)
		{
			params++;
			ALine = subl.substr(0, subl.find(co, 0));
			q = ALine;
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);
		}
		else stop = 0;
		if (stop)
		{
			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.find(co, 0));
				w = stoi(ALine);
				pos += ALine.length();
				subl = inputline.substr(++pos, inputline.length() - pos);
			}
			else stop = 0;
		}
		if (stop)
		{
			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.find(co, 0));
				e = stoi(ALine);
				pos += ALine.length();
				subl = inputline.substr(++pos, inputline.length() - pos);
			}
			else stop = 0;
		}
		if (stop)
		{
			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.find(co, 0));
				r = stoi(ALine);
				pos += ALine.length();
				subl = inputline.substr(++pos, inputline.length() - pos);
			}
			else stop = 0;
		}
		if (stop)
		{
			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.find(co, 0));
				t = stoi(ALine);
				pos += ALine.length();
				subl = inputline.substr(++pos, inputline.length() - pos);
			}
			else stop = 0;
		}
		if (stop)
		{
			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.find(co, 0));
				y = stoi(ALine);
				pos += ALine.length();
				subl = inputline.substr(++pos, inputline.length() - pos);
			}
			else stop = 0;
		}
		if (stop)
		{
			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.find(co, 0));
				u = stoi(ALine);
				pos += ALine.length();
				subl = inputline.substr(++pos, inputline.length() - pos);
			}
			else stop = 0;
		}
		if (stop)
		{
			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.rfind(pacl, 0));
				i = stoi(ALine);
			}
		}
		ptr = new prog_stmt(w, e, r, t, y, u, i, q);
	}
	else if (ALine == "joint_stmt")
	{
		flag = 0;
		int				w{}, e{}, r{}, t{}, y{};
		string			q{};
		subl = inputline.substr(++pos, inputline.length() - pos);

		if ((subl.find(str, 0)) != 0)
		{
			params++;
			ALine = subl.substr(0, subl.find(co, 0));
			q = ALine;
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);
		}
		else stop = 0;
		if (stop)
		{
			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.find(co, 0));
				w = stoi(ALine);
				pos += ALine.length();
				subl = inputline.substr(++pos, inputline.length() - pos);
			}
			else stop = 0;
		}
		if (stop)
		{
			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.find(co, 0));
				e = stoi(ALine);
				pos += ALine.length();
				subl = inputline.substr(++pos, inputline.length() - pos);
			}
			else stop = 0;
		}
		if (stop)
		{
			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.find(co, 0));
				r = stoi(ALine);
				pos += ALine.length();
				subl = inputline.substr(++pos, inputline.length() - pos);
			}
			else stop = 0;
		}
		if (stop)
		{
			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.find(co, 0));
				t = stoi(ALine);
				pos += ALine.length();
				subl = inputline.substr(++pos, inputline.length() - pos);
			}
			else stop = 0;
		}
		if (stop)
		{
			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.rfind(pacl, 0));
				y = stoi(ALine);
			}
		}
		ptr = new joint_stmt(w, e, r, t, y, q);
	}
	else if (ALine == "call_stmt")
	{
		flag = 0;
		int					w{}, e{};
		string				q{};
		vector<int>			vq;

		subl = inputline.substr(++pos, inputline.length() - pos);

		if ((subl.find(str, 0)) != 0)
		{
			params++;
			ALine = subl.substr(0, subl.find(co, 0));
			q = ALine;
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);
		}
		else stop = 0;
		if (stop)
		{
			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.find(co, 0));
				w = stoi(ALine);
				pos += ALine.length();
				subl = inputline.substr(++pos, inputline.length() - pos);
			}
			else stop = 0;
		}
		if (stop)
		{
			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.find(co, 0));
				e = stoi(ALine);
				pos += ALine.length();
				subl = inputline.substr(++pos, inputline.length() - pos);
			}
			else stop = 0;
		}
		if (stop)
		{
			if ((subl.find(str, 0)) != 0)
			{

				subl = inputline.substr(++pos, inputline.length() - pos);
				params++;
				//vector
				if ((subl.find(brcl, 0)) != 0)
				{
					brpos = subl.find(brcl, 0);
					while (subl.find(co, 0) < brpos)
					{
						ALine = subl.substr(0, subl.find(co, 0));
						vq.push_back(stoi(ALine));
						pos += ALine.length();
						brpos -= ALine.length();
						brpos--;
						subl = inputline.substr(++pos, inputline.length() - pos);
					}
					ALine = subl.substr(0, brpos);
					vq.push_back(stoi(ALine));
					pos += ALine.size();
					pos++;
				}
			}
		}
		ptr = new call_stmt(w, e, q, vq);
	}
	else if (ALine == "compo_stmt")
	{
		flag = 0;
		int				w{};
		string			q{};
		vector<int>	vq;

		subl = inputline.substr(++pos, inputline.length() - pos);

		if ((subl.find(str, 0)) != 0)
		{
			params++;
			ALine = subl.substr(0, subl.find(co, 0));
			q = ALine;
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);
		}
		else stop = 0;
		if (stop)
		{
			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.find(co, 0));
				w = stoi(ALine);
				pos += ALine.length();
				subl = inputline.substr(++pos, inputline.length() - pos);
			}
			else stop = 0;
		}
		if (stop)
		{
			if ((subl.find(str, 0)) != 0)
			{
				subl = inputline.substr(++pos, inputline.length() - pos);
				//vector
				params++;
				if ((subl.find(brcl, 0)) != 0)
				{
					brpos = subl.find(brcl, 0);
					while (subl.find(co, 0) < brpos)
					{
						ALine = subl.substr(0, subl.find(co, 0));
						vq.push_back(stoi(ALine));
						pos += ALine.length();
						brpos -= ALine.length();
						brpos--;
						subl = inputline.substr(++pos, inputline.length() - pos);
					}
					ALine = subl.substr(0, brpos);
					vq.push_back(stoi(ALine));
					pos += ALine.size();
				}
			}
		}
		ptr = new compo_stmt(w, q, vq);
	}
	else if (ALine == "rec_stmt")
	{
		flag = 0;
		int				w{};
		string			q{};
		vector<int>	vq;

		subl = inputline.substr(++pos, inputline.length() - pos);

		if ((subl.find(str, 0)) != 0)
		{
			params++;
			ALine = subl.substr(0, subl.find(co, 0));
			q = ALine;
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);
		}
		else stop = 0;
		if (stop)
		{
			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.find(co, 0));
				w = stoi(ALine);
				pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);
			}
			else stop = 0;
		}
		if (stop)
		{
			if ((subl.find(str, 0)) != 0)
			{
				subl = inputline.substr(++pos, inputline.length() - pos);
				//vector
				params++;
				if ((subl.find(brcl, 0)) != 0)
				{
					brpos = subl.find(brcl, 0);
					while (subl.find(co, 0) < brpos)
					{
						ALine = subl.substr(0, subl.find(co, 0));
						vq.push_back(stoi(ALine));
						pos += ALine.length();
						brpos -= ALine.length();
						brpos--;
						subl = inputline.substr(++pos, inputline.length() - pos);
					}
					ALine = subl.substr(0, brpos);
					vq.push_back(stoi(ALine));
					pos += ALine.size();
				}
			}
		}
		ptr = new rec_stmt(w, q, vq);
	}
	else if (ALine == "special_op")
	{
		flag = 0;
		int				w{}, r{}, t{}, y{}, i{}, o{}, p{};
		string			q{}, e{}, u{};

		subl = inputline.substr(++pos, inputline.length() - pos);

		if ((subl.find(str, 0)) != 0)
		{
			params++;
			ALine = subl.substr(0, subl.find(co, 0));
			q = ALine;
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);
		}
		else stop = 0;

		if (stop)
		{
			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.find(co, 0));
				w = stoi(ALine);
				pos += ALine.length();
				subl = inputline.substr(++pos, inputline.length() - pos);
			}
			else stop = 0;
		}
		if (stop)
		{
			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.find(co, 0));
				e = ALine;
				pos += ALine.length();
				subl = inputline.substr(++pos, inputline.length() - pos);
			}
			else stop = 0;
		}
		if (stop)
		{
			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.find(co, 0));
				r = stoi(ALine);
				pos += ALine.length();
				subl = inputline.substr(++pos, inputline.length() - pos);
			}
			else stop = 0;
		}
		if (stop)
		{
			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.find(co, 0));
				t = stoi(ALine);
				pos += ALine.length();
				subl = inputline.substr(++pos, inputline.length() - pos);
			}
			else stop = 0;
		}
		if (stop)
		{
			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.find(co, 0));
				y = stoi(ALine);
				pos += ALine.length();
				subl = inputline.substr(++pos, inputline.length() - pos);
			}
			else stop = 0;
		}
		if (stop)
		{
			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.find(co, 0));
				u = ALine;
				pos += ALine.length();
				subl = inputline.substr(++pos, inputline.length() - pos);
			}
			else stop = 0;
		}
		if (stop)
		{
			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.find(co, 0));
				i = stoi(ALine);
				pos += ALine.length();
				subl = inputline.substr(++pos, inputline.length() - pos);
			}
			else stop = 0;
		}
		if (stop)
		{
			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.find(co, 0));
				o = stoi(ALine);
				pos += ALine.length();
				subl = inputline.substr(++pos, inputline.length() - pos);
			}
			else stop = 0;
		}
		if (stop)
		{
			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.rfind(pacl, 0));
				p = stoi(ALine);
			}
		}
		ptr = new special_op(w, r, t, y, i, o, p, q, e, u);
	}
	else if (ALine == "special_dt")
	{
		flag = 0;
		int				w{}, r{};
		string			q{}, e{}, t{}, y{}, u{};

		subl = inputline.substr(++pos, inputline.length() - pos);

		if ((subl.find(str, 0)) != 0)
		{
			params++;
			ALine = subl.substr(0, subl.find(co, 0));
			q = ALine;
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);
		}
		else stop = 0;
		if (stop)
		{
			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.find(co, 0));
				w = stoi(ALine);
				pos += ALine.length();
				subl = inputline.substr(++pos, inputline.length() - pos);
			}
			else stop = 0;
		}
		if (stop)
		{
			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.find(co, 0));
				e = ALine;
				pos += ALine.length();
				subl = inputline.substr(++pos, inputline.length() - pos);
			}
			else stop = 0;
		}
		if (stop)
		{
			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.find(co, 0));
				r = stoi(ALine);
				pos += ALine.length();
				subl = inputline.substr(++pos, inputline.length() - pos);
			}
			else stop = 0;
		}
		if (stop)
		{
			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.find(co, 0));
				t = ALine;
				pos += ALine.length();
				subl = inputline.substr(++pos, inputline.length() - pos);
			}
			else stop = 0;
		}
		if (stop)
		{
			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.find(co, 0));
				y = ALine;
				pos += ALine.length();
				subl = inputline.substr(++pos, inputline.length() - pos);
			}
			else stop = 0;
		}
		if (stop)
		{
			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.rfind(pacl, 0));
				ALine.resize(ALine.size() - 1);
				u = ALine;
			}
		}
		ptr = new special_dt(w, r, q, e, t, y, u);
	}
	else if (ALine == "local_object")
	{
		flag = 0;
		int				w{}, i{}, t{};
		string			q{}, e{}, r{}, y{}, u{}, o{};

		subl = inputline.substr(++pos, inputline.length() - pos);

		if ((subl.find(str, 0)) != 0)
		{
			params++;
			ALine = subl.substr(0, subl.find(co, 0));
			q = ALine;
			pos += ALine.length();
			subl = inputline.substr(++pos, inputline.length() - pos);
		}
		else stop = 0;
		if (stop)
		{
			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.find(co, 0));
				w = stoi(ALine);
				pos += ALine.length();
				subl = inputline.substr(++pos, inputline.length() - pos);
			}
			else stop = 0;
		}
		if (stop)
		{
			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.find(co, 0));
				e = ALine;
				pos += ALine.length();
				subl = inputline.substr(++pos, inputline.length() - pos);
			}
			else stop = 0;
		}
		if (stop)
		{
			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.find(co, 0));
				r = ALine;
				pos += ALine.length();
				subl = inputline.substr(++pos, inputline.length() - pos);
			}
			else stop = 0;
		}
		if (stop)
		{
			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.find(co, 0));
				t = stoi(ALine);
				pos += ALine.length();
				subl = inputline.substr(++pos, inputline.length() - pos);
			}
			else stop = 0;
		}
		if (stop)
		{
			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.find(co, 0));
				y = ALine;
				pos += ALine.length();
				subl = inputline.substr(++pos, inputline.length() - pos);
			}
			else stop = 0;
		}
		if (stop)
		{
			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.find(co, 0));
				u = ALine;
				pos += ALine.length();
				subl = inputline.substr(++pos, inputline.length() - pos);
			}
			else stop = 0;
		}
		if (stop)
		{
			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.find(co, 0));
				i = stoi(ALine);
				pos += ALine.length();
				subl = inputline.substr(++pos, inputline.length() - pos);
			}
			else stop = 0;
		}
		if (stop)
		{
			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.rfind(pacl, 0));
				ALine.resize(ALine.size() - 1);
				o = ALine;
			}
		}
		ptr = new local_object(t, w, i, q, e, y, u, r, o);
	}
	else if (ALine == "state_node")
	{
		flag = 0;				// use do while
		int				w{}, e{}, r{};
		string			q{};
		vector<int>		vq, vw, ve;

		subl = inputline.substr(++pos, inputline.length() - pos);
			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.find(co, 0));
				q = ALine;
				pos += ALine.length();
				subl = inputline.substr(++pos, inputline.length() - pos);
			}
			else stop = 0;
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					w = stoi(ALine);
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(pa, 0));
					if (ALine == "subprogram_call")
					{
						pos += ALine.size();
						subl = inputline.substr(++pos, inputline.length() - pos);
						//vector
						if ((subl.find(str, 0)) != 0)
						{
							subl = inputline.substr(++pos, inputline.length() - pos);
							params++;
							if ((subl.find(brcl, 0)) != 0)
							{
								brpos = subl.find(brcl, 0);
								while (subl.find(co, 0) < brpos)
								{
									ALine = subl.substr(0, subl.find(co, 0));
									vq.push_back(stoi(ALine));
									pos += ALine.length();
									brpos -= ALine.length();
									brpos--;
									subl = inputline.substr(++pos, inputline.length() - pos);
								}
								ALine = subl.substr(0, brpos);
								pos += ALine.length();
								vq.push_back(stoi(ALine));
							}
							subl = inputline.substr(++++pos, inputline.length() - pos);
						}
						else stop = 0;

						if (stop)
						{
							if ((subl.find(str, 0)) != 0)
							{
								params++;
								ALine = subl.substr(0, subl.find(pacl, 0));
								e = stoi(ALine);
							}
						}
						ptr = new subprogram_call(e, vq, w, q);
					}
					else if (ALine == "dataflow")
					{
						pos += ALine.size();
						subl = inputline.substr(++pos, inputline.length() - pos);
						//vector
						if ((subl.find(str, 0)) != 0)
						{
							subl = inputline.substr(++pos, inputline.length() - pos);
							params++;
							if ((subl.find(brcl, 0)) != 0)
							{
								brpos = subl.find(brcl, 0);
								while (subl.find(co, 0) < brpos)
								{
									ALine = subl.substr(0, subl.find(co, 0));
									vq.push_back(stoi(ALine));
									pos += ALine.length();
									brpos -= ALine.length();
									brpos--;
									subl = inputline.substr(++pos, inputline.length() - pos);
								}
								ALine = subl.substr(0, brpos);
								pos += ALine.length();
								vq.push_back(stoi(ALine));
							}
							subl = inputline.substr(++++pos, inputline.length() - pos);
						}
						else stop = 0;

						if (stop)
						{
							if ((subl.find(str, 0)) != 0)
							{
								params++;
								ALine = subl.substr(0, subl.find(pacl, 0));
								e = stoi(ALine);
							}
						}
						ptr = new dataflow(e, vq, w, q);
					}
					else if (ALine == "ifthen")
					{
						pos += ALine.size();
						subl = inputline.substr(++pos, inputline.length() - pos);

						//vector
						if ((subl.find(str, 0)) != 0)
						{
							subl = inputline.substr(++pos, inputline.length() - pos);
							params++;
							if ((subl.find(brcl, 0)) != 0)
							{
								brpos = subl.find(brcl, 0);
								while (subl.find(co, 0) < brpos)
								{
									ALine = subl.substr(0, subl.find(co, 0));
									vq.push_back(stoi(ALine));
									pos += ALine.length();
									brpos -= ALine.length();
									brpos--;
									subl = inputline.substr(++pos, inputline.length() - pos);
								}
								ALine = subl.substr(0, brpos);
								pos += ALine.length();
								vq.push_back(stoi(ALine));
							}
							subl = inputline.substr(++++pos, inputline.length() - pos);
						}
						else stop = 0;

						//vector2
						if (stop)
						{
							if ((subl.find(str, 0)) != 0)
							{
								subl = inputline.substr(++pos, inputline.length() - pos);
								params++;
								if ((subl.find(brcl, 0)) != 0)
								{
									brpos = subl.find(brcl, 0);
									while (subl.find(co, 0) < brpos)
									{
										ALine = subl.substr(0, subl.find(co, 0));
										vw.push_back(stoi(ALine));
										pos += ALine.length();
										brpos -= ALine.length();
										brpos--;
										subl = inputline.substr(++pos, inputline.length() - pos);
									}
									ALine = subl.substr(0, brpos);
									vw.push_back(stoi(ALine));
									pos += ALine.size();
								}
								subl = inputline.substr(++++pos, inputline.length() - pos);
							}
							else stop = 0;
						}

						//vector3
						if (stop)
						{
							if ((subl.find(str, 0)) != 0)
							{
								subl = inputline.substr(++pos, inputline.length() - pos);
								params++;
								if ((subl.find(brcl, 0)) != 0)
								{
									brpos = subl.find(brcl, 0);
									while (subl.find(co, 0) < brpos)
									{
										ALine = subl.substr(0, subl.find(co, 0));
										ve.push_back(stoi(ALine));
										pos += ALine.length();
										brpos -= ALine.length();
										brpos--;
										subl = inputline.substr(++pos, inputline.length() - pos);
									}
									ALine = subl.substr(0, brpos);
									ve.push_back(stoi(ALine));
									pos += ALine.size();
								}
								subl = inputline.substr(++++pos, inputline.length() - pos);
							}
							else stop = 0;
						}

						if (stop)
						{
							if ((subl.find(str, 0)) != 0)
							{
								params++;
								subl = inputline.substr(pos, inputline.length() - pos);
								ALine = subl.substr(0, subl.find(co, 0));
								e = stoi(ALine);
								pos += ALine.length();
								subl = inputline.substr(++pos, inputline.length() - pos);
							}
							else stop = 0;
						}
						if (stop)
						{
							if ((subl.find(str, 0)) != 0)
							{
								params++;
								ALine = subl.substr(0, subl.rfind(pacl, 0));
								r = stoi(ALine);
								pos += ALine.length();
							}
						}
						ptr = new ifthen(e, r, vq, vw, ve, w, q);
					}
					else if (ALine == "jump")
					{
						pos += ALine.size();
						subl = inputline.substr(++pos, inputline.length() - pos);
						//vector
						if ((subl.find(str, 0)) != 0)
						{
							subl = inputline.substr(++pos, inputline.length() - pos);
							params++;
							if ((subl.find(brcl, 0)) != 0)
							{
								brpos = subl.find(brcl, 0);
								while (subl.find(co, 0) < brpos)
								{
									ALine = subl.substr(0, subl.find(co, 0));
									vq.push_back(stoi(ALine));
									pos += ALine.length();
									brpos -= ALine.length();
									brpos--;
									subl = inputline.substr(++pos, inputline.length() - pos);
								}
								ALine = subl.substr(0, brpos);
								pos += ALine.length();
								vq.push_back(stoi(ALine));
							}
							subl = inputline.substr(++++pos, inputline.length() - pos);
						}
						else stop = 0;
						
						if (stop)
						{
							if ((subl.find(str, 0)) != 0)
							{
								params++;
								ALine = subl.substr(0, subl.find(pacl, 0));
								e = stoi(ALine);
							}
						}
						ptr = new jump(e, vq, w, q);
					}
					else if (ALine == "return")
					{
						pos += ALine.size();	
						subl = inputline.substr(++pos, inputline.length() - pos);
						//vector
						if ((subl.find(str, 0)) != 0)
						{
							subl = inputline.substr(++pos, inputline.length() - pos);
							params++;
							if ((subl.find(brcl, 0)) != 0)
							{
								brpos = subl.find(brcl, 0);
								while (subl.find(co, 0) < brpos)
								{

									ALine = subl.substr(0, subl.find(co, 0));
									vq.push_back(stoi(ALine));
									pos += ALine.length();
									brpos -= ALine.length();
									brpos--;
									subl = inputline.substr(++pos, inputline.length() - pos);
								}
								ALine = subl.substr(0, brpos);
								pos += ALine.length() + 1;
								vq.push_back(stoi(ALine));
							}
						}
						ptr = new return_cos(vq, w, q);
					}
				}
				else ptr = new state_node(w, q);
			}
			else
			{  
				ptr = new state_node(w, q);
			}
	}
	else if (ALine == "change_op_number")
	{
		flag = 0;
		int				w{}, e{};
		string			q{};

		subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.find(co, 0));
				q = ALine;
				pos += ALine.length();
				subl = inputline.substr(++pos, inputline.length() - pos);
			}
			else stop = 0;
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					w = stoi(ALine);
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.rfind(pacl, 0));
					e = stoi(ALine);
				}
			}
		ptr = new change_op_number(e, w, q);
	}
	else if (ALine == "last_change_op_number")
	{
		flag = 0;
		int				w{}, e{};
		string			q{};
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.find(co, 0));
				q = ALine;
				pos += ALine.length();
				subl = inputline.substr(++pos, inputline.length() - pos);
			}
			else stop = 0;
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					w = stoi(ALine);
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.rfind(pacl, 0));
					e = stoi(ALine);
				}
			}
		ptr = new last_change_op_number(e, w, q);
	}
	else if (ALine == "op_guards")
	{
		flag = 0;
		int				w{};
		string			q{};
		vector<int>		vq, vw;

		subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.find(co, 0));
				q = ALine;
				pos += ALine.length();
				subl = inputline.substr(++pos, inputline.length() - pos);
			}
			else stop = 0;
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					w = stoi(ALine);
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					subl = inputline.substr(++pos, inputline.length() - pos);
					//vector
					params++;
					if ((subl.find(brcl, 0)) != 0)
					{
						brpos = subl.find(brcl, 0);
						while (subl.find(co, 0) < brpos)
						{
							ALine = subl.substr(0, subl.find(co, 0));
							vq.push_back(stoi(ALine));
							pos += ALine.length();
							brpos -= ALine.length();
							brpos--;
							subl = inputline.substr(++pos, inputline.length() - pos);
						}
						ALine = subl.substr(0, brpos);
						vq.push_back(stoi(ALine));
						pos += ALine.size();
					}
					subl = inputline.substr(++++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			
			//vector2
			if(stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					subl = inputline.substr(++pos, inputline.length() - pos);
					params++;
					if ((subl.find(brcl, 0)) != 0)
					{
						brpos = subl.find(brcl, 0);
						while (subl.find(co, 0) < brpos)
						{
							ALine = subl.substr(0, subl.find(co, 0));
							vw.push_back(stoi(ALine));
							pos += ALine.length();
							brpos -= ALine.length();
							brpos--;
							subl = inputline.substr(++pos, inputline.length() - pos);
						}
						ALine = subl.substr(0, brpos);
						vw.push_back(stoi(ALine));
						pos += ALine.size();
					}
				}
			}
		ptr = new op_guards(w, q, vq, vw);
	}
	else if (ALine == "var_guards")
	{
		flag = 0;
		int				w{};
		string			q{};
		vector<int>		vq, vw;

		subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.find(co, 0));
				q = ALine;
				pos += ALine.length();
				subl = inputline.substr(++pos, inputline.length() - pos);
			}
			else stop = 0;
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					w = stoi(ALine);
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
						 
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					subl = inputline.substr(++pos, inputline.length() - pos);
					//vector
					params++;
					if ((subl.find(brcl, 0)) != 0)
					{
						brpos = subl.find(brcl, 0);
						while (subl.find(co, 0) < brpos)
						{
							ALine = subl.substr(0, subl.find(co, 0));
							vq.push_back(stoi(ALine));
							pos += ALine.length();
							brpos -= ALine.length();
							brpos--;
							subl = inputline.substr(++pos, inputline.length() - pos);
						}
						ALine = subl.substr(0, brpos);
						vq.push_back(stoi(ALine));
						pos += ALine.size();
					}
					subl = inputline.substr(++++pos, inputline.length() - pos);
				}
				else stop = 0;
			}

			//vector2
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					subl = inputline.substr(++pos, inputline.length() - pos);
					params++;
					if ((subl.find(brcl, 0)) != 0)
					{
						brpos = subl.find(brcl, 0);
						while (subl.find(co, 0) < brpos)
						{
							ALine = subl.substr(0, subl.find(co, 0));
							vw.push_back(stoi(ALine));
							pos += ALine.length();
							brpos -= ALine.length();
							brpos--;
							subl = inputline.substr(++pos, inputline.length() - pos);
						}
						ALine = subl.substr(0, brpos);
						vw.push_back(stoi(ALine));
						pos += ALine.size();
					}
				}
			}
		ptr = new var_guards(w, q, vq, vw);
	}
	else if (ALine == "guard_pair")
	{
		flag = 0;
		int				w{}, e{};
		string			q{}, r{};

		subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.find(co, 0));
				q = ALine;
				pos += ALine.length();
				subl = inputline.substr(++pos, inputline.length() - pos);
			}
			else stop = 0;
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					w = stoi(ALine);
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					e = stoi(ALine);
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.rfind(pacl, 0));
					ALine.resize(ALine.size() - 1);
					r = ALine;
				}
			}
		ptr = new guard_pair(w, e, q, r);
	}
	else if (ALine == "guard_cond")
	{
		flag = 0;
		int				w{}, e{};
		string			q{}, r{};

		subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.find(co, 0));
				q = ALine;
				pos += ALine.length();
				subl = inputline.substr(++pos, inputline.length() - pos);
			}
			else stop = 0;
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					w = stoi(ALine);
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					e = stoi(ALine);
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.rfind(pacl, 0));
					ALine.resize(ALine.size() - 1);
					r = ALine;
				}
			}
		ptr = new guard_cond(w, e, q, r);
	}
	else if (ALine == "predecessors")
	{
		flag = 0;
		int				w{};
		string			q{};
		vector<int>		vq;

		subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.find(co, 0));
				q = ALine;
				pos += ALine.length();
				subl = inputline.substr(++pos, inputline.length() - pos);
			}
			else stop = 0;
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					w = stoi(ALine);
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}

			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{

					subl = inputline.substr(++pos, inputline.length() - pos);
					params++;
					//vector
					if ((subl.find(brcl, 0)) != 0)
					{
						brpos = subl.find(brcl, 0);
						while (subl.find(co, 0) < brpos)
						{
							ALine = subl.substr(0, subl.find(co, 0));
							vq.push_back(stoi(ALine));
							pos += ALine.length();
							brpos -= ALine.length();
							brpos--;
							subl = inputline.substr(++pos, inputline.length() - pos);
						}
						ALine = subl.substr(0, brpos);
						vq.push_back(stoi(ALine));
						pos += ALine.size();
						pos++;
					}
				}
			}
		ptr = new predecessors(w, q, vq);
	}
	else if (ALine == "cessor")
	{
		flag = 0;
		int				w{}, e{};
		string			q{};

		subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.find(co, 0));
				q = ALine;
				pos += ALine.length();
				subl = inputline.substr(++pos, inputline.length() - pos);
			}
			else stop = 0;
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					w = stoi(ALine);
					pos += ALine.length();
				}
				else stop = 0;
				subl = inputline.substr(++pos, inputline.length() - pos);
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.rfind(pacl, 0));
					e = stoi(ALine);
				}
			}
		ptr = new cessor(w, e, q);
	}
	else if (ALine == "cessor_kind")
	{
		flag = 0;
		int				e{}, r{};
		string			q{}, w{}, t{}, y{};
		vector<int>		vq;

		subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.find(co, 0));
				q = ALine;
				pos += ALine.length();
				subl = inputline.substr(++pos, inputline.length() - pos);
			}
			else stop = 0;
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					w = ALine;
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					e = stoi(ALine);
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					r = stoi(ALine);
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					t = ALine;
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					y = ALine;
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{

					subl = inputline.substr(++pos, inputline.length() - pos);
					params++;
					//vector
					if ((subl.find(brcl, 0)) != 0)
					{
						brpos = subl.find(brcl, 0);
						while (subl.find(co, 0) < brpos)
						{
							ALine = subl.substr(0, subl.find(co, 0));
							vq.push_back(stoi(ALine));
							pos += ALine.length();
							brpos -= ALine.length();
							brpos--;
							subl = inputline.substr(++pos, inputline.length() - pos);
						}
						ALine = subl.substr(0, brpos);
						vq.push_back(stoi(ALine));
						pos += ALine.size();
						pos++;
					}
				}
			}
		ptr = new cessor_kind(e, r, q, w, t, y, vq);
	}
	else if (ALine == "old_schedule")
	{
		flag = 0;
		string			q{};

		subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.rfind(pacl, 0));
				ALine.resize(ALine.size() - 1);
				q = ALine;
			}
		ptr = new old_schedule(q);
	}
	else if (ALine == "new_schedule")
	{
		flag = 0;
		string			q{};

		subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.rfind(pacl, 0));
				ALine.resize(ALine.size() - 1);
				q = ALine;
			}
		ptr = new new_schedule(q);
	}
	else if (ALine == "local_ifthen_chain_end_operations_were_written")
	{
		flag = 0;
		int				q{};

		subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.rfind(pacl, 0));
				ALine.resize(ALine.size() - 1);
				q = stoi(ALine);
			}
		ptr = new local_ifthen_chain_end_operations_were_written(q);
	}
	else if (ALine == "calls_list")
	{
		flag = 0;
		int				w{}, e{};
		string			q{};
		vector<int>		vq;

		subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.find(co, 0));
				q = ALine;
				pos += ALine.length();
				subl = inputline.substr(++pos, inputline.length() - pos);
			}
			else stop = 0;
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					w = stoi(ALine);
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					e = stoi(ALine);
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}

			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{

					subl = inputline.substr(++pos, inputline.length() - pos);
					params++;
					//vector
					if ((subl.find(brcl, 0)) != 0)
					{
						brpos = subl.find(brcl, 0);
						while (subl.find(co, 0) < brpos)
						{
							ALine = subl.substr(0, subl.find(co, 0));
							vq.push_back(stoi(ALine));
							pos += ALine.length();
							brpos -= ALine.length();
							brpos--;
							subl = inputline.substr(++pos, inputline.length() - pos);
						}
						ALine = subl.substr(0, brpos);
						vq.push_back(stoi(ALine));
						pos += ALine.size();
						pos++;
					}
				}
			}
		ptr = new calls_list(q, w, e, vq);
	}
	else if (ALine == "composites_list")
	{
		flag = 0;
		int				w{};
		string			q{};
		vector<int>		vq;

		subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.find(co, 0));
				q = ALine;
				pos += ALine.length();
				subl = inputline.substr(++pos, inputline.length() - pos);
			}
			else stop = 0;
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					w = stoi(ALine);
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}

			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{

					subl = inputline.substr(++pos, inputline.length() - pos);
					params++;
					//vector
					if ((subl.find(brcl, 0)) != 0)
					{
						brpos = subl.find(brcl, 0);
						while (subl.find(co, 0) < brpos)
						{
							ALine = subl.substr(0, subl.find(co, 0));
							vq.push_back(stoi(ALine));
							pos += ALine.length();
							brpos -= ALine.length();
							brpos--;
							subl = inputline.substr(++pos, inputline.length() - pos);
						}
						ALine = subl.substr(0, brpos);
						vq.push_back(stoi(ALine));
						pos += ALine.size();
						pos++;
					}
				}
			}
		ptr = new composites_list(q, w, vq);
	}
	else if (ALine == "record_aggregates_list")
	{
		flag = 0;
		int				w{};
		string			q{};
		vector<int>		vq;

		subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.find(co, 0));
				q = ALine;
				pos += ALine.length();
				subl = inputline.substr(++pos, inputline.length() - pos);
			}
			else stop = 0;
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					w = stoi(ALine);
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}

			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{

					subl = inputline.substr(++pos, inputline.length() - pos);
					params++;
					//vector
					if ((subl.find(brcl, 0)) != 0)
					{
						brpos = subl.find(brcl, 0);
						while (subl.find(co, 0) < brpos)
						{
							ALine = subl.substr(0, subl.find(co, 0));
							vq.push_back(stoi(ALine));
							pos += ALine.length();
							brpos -= ALine.length();
							brpos--;
							subl = inputline.substr(++pos, inputline.length() - pos);
						}
						ALine = subl.substr(0, brpos);
						vq.push_back(stoi(ALine));
						pos += ALine.size();
						pos++;
					}
				}
			}
		ptr = new record_aggregates_list(q, w, vq);
	}
	else if (ALine == "mem_port")
	{
		flag = 0;
		int				q{}, y{}, i{}, s{};
		string			w{}, e{}, r{}, t{}, u{}, o{}, p{}, a{}, d{};

		subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.find(co, 0));
				q = stoi(ALine);
				pos += ALine.length();
				subl = inputline.substr(++pos, inputline.length() - pos);
			}
			else stop = 0;
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					w = ALine;
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					e = ALine;
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					r = ALine;
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					t = ALine;
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					y = stoi(ALine);
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					u = ALine;
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					i = stoi(ALine);
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					o = ALine;
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					p = ALine;
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					a = ALine;
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					s = stoi(ALine);
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.rfind(pacl, 0));
					ALine.resize(ALine.size() - 1);
					d = ALine;
				}
			}
		ptr = new mem_port(q, w, e, r, t, y, u, i, o, p, a, s, d);
	}
	else if (ALine == "global_declarations")
	{
		flag = 0;
		int						w{}, t{}, i{}, p{};
		string					q{}, e{}, r{}, y{}, u{}, o{};
		vector<local_object>	vobj;

		subl = inputline.substr(++pos, inputline.length() - pos);
			if ((subl.find(str, 0)) != 0)
			{
				subl = inputline.substr(++pos, inputline.length() - pos);
				//vector
				if ((subl.find(brcl, 0)) != 0)
				{
					brpos = subl.find(brcl, 0);
					while (subl.find(co, 0) < brpos && stop)
					{
						if ((subl.find(str, 0)) != 0)
						{
							params++;
							pos += 13; // 13 because   global_declerations(<<[local_object>>("linedraw",1,"constant
							brpos -= 13;
							subl = inputline.substr(pos, inputline.length() - pos);
							ALine = subl.substr(0, subl.find(co, 0));
							q = ALine;
							pos += ALine.length();
							brpos -= ALine.length();
							brpos--;
							subl = inputline.substr(++pos, inputline.length() - pos);
							ALine = subl.substr(0, subl.find(co, 0));
							w = stoi(ALine);
							pos += ALine.length();
							brpos -= ALine.length();
							brpos--;
							subl = inputline.substr(++pos, inputline.length() - pos);
							ALine = subl.substr(0, subl.find(co, 0));
							e = ALine;
							pos += ALine.length();
							brpos -= ALine.length();
							brpos--;
							subl = inputline.substr(++pos, inputline.length() - pos);
							ALine = subl.substr(0, subl.find(co, 0));
							r = ALine;
							pos += ALine.length();
							brpos -= ALine.length();
							brpos--;
							subl = inputline.substr(++pos, inputline.length() - pos);
							ALine = subl.substr(0, subl.find(co, 0));
							t = stoi(ALine);
							pos += ALine.length();
							brpos -= ALine.length();
							brpos--;
							subl = inputline.substr(++pos, inputline.length() - pos);
							ALine = subl.substr(0, subl.find(co, 0));
							y = ALine;
							pos += ALine.length();
							brpos -= ALine.length();
							brpos--;
							subl = inputline.substr(++pos, inputline.length() - pos);
							ALine = subl.substr(0, subl.find(co, 0));
							u = ALine;
							pos += ALine.length();
							brpos -= ALine.length();
							brpos--;
							subl = inputline.substr(++pos, inputline.length() - pos);
							ALine = subl.substr(0, subl.find(co, 0));
							i = stoi(ALine);
							pos += ALine.length();
							brpos -= ALine.length();
							brpos--;
							subl = inputline.substr(++pos, inputline.length() - pos);
							if (subl.find(co, 0) < brpos) //last parameter
							{
								ALine = subl.substr(0, subl.find(co, 0));
								pos += ALine.length();
								brpos -= ALine.length();
								ALine.resize(ALine.size() - 1);
								o = ALine;
								pos++;
								brpos--;
							}
							else //last
							{
								ALine = subl.substr(0, subl.find(co, 0));
								pos += ALine.length();
								ALine.resize(ALine.size() - 2);
								brpos -= ALine.length();
								o = ALine;
							}
							vobj.push_back(*(new local_object(t, w, i, q, e, y, u, r, o)));
						}
						else stop = 0;
					}
					brpos--;
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else
				{
					params++;
					pos += 2;
					subl = inputline.substr(pos, inputline.length() - pos);
				}
			}
			else stop = 0;

			if (stop)
			{
				if (subl.find(us, 0) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					p = stoi(ALine);
				}
			}
		ptr = new global_declarations(vobj, p);
	}
	else if (ALine == "source_is_normal_dt")
	{
		flag = 0;
		int				w{}, e{};
		string			q{};

		subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.find(co, 0));
				q = ALine;
				pos += ALine.length();
				subl = inputline.substr(++pos, inputline.length() - pos);
			}
			else stop = 0;
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					w = stoi(ALine);
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.rfind(pacl, 0));
					e = stoi(ALine);
				}
			}
		ptr = new source_is_normal_dt(q, w, e);
	}
	else if (ALine == "combo")
	{
		flag = 0;
		int				q{}, e{};
		string			w{};

		subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.find(co, 0));
				q = stoi(ALine);
				pos += ALine.length();
				subl = inputline.substr(++pos, inputline.length() - pos);
			}
			else stop = 0;
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					w = ALine;
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.rfind(pacl, 0));
					e = stoi(ALine);
				}
			}
		ptr = new combo(q, w, e);
	}
	else if (ALine == "sequence")
	{
		flag = 0;
		int				q{}, e{};
		string			w{};
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.find(co, 0));
				q = stoi(ALine);
				pos += ALine.length();
				subl = inputline.substr(++pos, inputline.length() - pos);
			}
			else stop = 0;
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					w = ALine;
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.rfind(pacl, 0));
					e = stoi(ALine);
				}
			}
		ptr = new sequence(q, w, e);
	}
	else if (ALine == "for_loop")
	{
		flag = 0;
		int				q{}, e{}, r{}, t{}, y{}, u{}, i{}, o{}, p{}, a{}, s{}, d{};
		string			w{};

		subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.find(co, 0));
				q = stoi(ALine);
				pos += ALine.length();
				subl = inputline.substr(++pos, inputline.length() - pos);
			}
			else stop = 0;
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					w = ALine;
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					e = stoi(ALine);
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					r = stoi(ALine);
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					t = stoi(ALine);
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					y = stoi(ALine);
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					u = stoi(ALine);
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					i = stoi(ALine);
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					o = stoi(ALine);
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					p = stoi(ALine);
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					a = stoi(ALine);
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					s = stoi(ALine);
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.rfind(pacl, 0));
					d = stoi(ALine);
				}
			}
		ptr = new for_loop(q, w, e, r, t, y, u, i, o, p, a, s, d);
	}
	else if (ALine == "last_for_loop_entry")
	{
		flag = 0;
		int				q{};
			
		subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.rfind(pacl, 0));
				q = stoi(ALine);
			}
		ptr = new last_for_loop_entry(q);
	}
	else if (ALine == "while_loop")
	{
		flag = 0;
		int				q{}, e{}, r{}, t{}, y{}, u{};
		string			w{};

		subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.find(co, 0));
				q = stoi(ALine);
				pos += ALine.length();
				subl = inputline.substr(++pos, inputline.length() - pos);
			}
			else stop = 0;
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					w = ALine;
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					e = stoi(ALine);
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					r = stoi(ALine);
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					t = stoi(ALine);
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					y = stoi(ALine);
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.rfind(pacl, 0));
					u = stoi(ALine);
				}
			}
		ptr = new while_loop(q, w, e, r, t, y, u);
	}
	else if (ALine == "last_while_loop_entry")
	{
		flag = 0;
		int				q{};

		subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.rfind(pacl, 0));
				q = stoi(ALine);
			}
		ptr = new last_for_loop_entry(q);
	}
	else if (ALine == "possible_end_if")
	{
		flag = 0;
		string			q{};
		vector<int>		vq;

		subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.find(co, 0));
				q = ALine;
				pos += ALine.length();
				subl = inputline.substr(++pos, inputline.length() - pos);
			}
			else stop = 0;
  
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{

					subl = inputline.substr(++pos, inputline.length() - pos);
					params++;
					//vector
					if ((subl.find(brcl, 0)) != 0)
					{
						brpos = subl.find(brcl, 0);
						while (subl.find(co, 0) < brpos)
						{
							ALine = subl.substr(0, subl.find(co, 0));
							vq.push_back(stoi(ALine));
							pos += ALine.length();
							brpos -= ALine.length();
							brpos--;
							subl = inputline.substr(++pos, inputline.length() - pos);
						}
						ALine = subl.substr(0, brpos);
						vq.push_back(stoi(ALine));
						pos += ALine.size();
						pos++;
					}
				}
			}
		ptr = new possible_end_if(q, vq);
	}
	else if (ALine == "end_if")
	{
		flag = 0;
		string			q{};
		vector<int>		vq;

		subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.find(co, 0));
				q = ALine;
				pos += ALine.length();
				subl = inputline.substr(++pos, inputline.length() - pos);
			}
			else stop = 0;
  
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{

					subl = inputline.substr(++pos, inputline.length() - pos);
					params++;
					//vector
					if ((subl.find(brcl, 0)) != 0)
					{
						brpos = subl.find(brcl, 0);
						while (subl.find(co, 0) < brpos)
						{
							ALine = subl.substr(0, subl.find(co, 0));
							vq.push_back(stoi(ALine));
							pos += ALine.length();
							brpos -= ALine.length();
							brpos--;
							subl = inputline.substr(++pos, inputline.length() - pos);
						}
						ALine = subl.substr(0, brpos);
						vq.push_back(stoi(ALine));
						pos += ALine.size();
						pos++;
					}
				}
			}
		ptr = new end_if(q, vq);
	}
	else if (ALine == "nested_cond_fact")
	{
		flag = 0;
		string			q{};
		vector<int>		vq;

		subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.find(co, 0));
				q = ALine;
				pos += ALine.length();
				subl = inputline.substr(++pos, inputline.length() - pos);
			}
			else stop = 0;
  
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{

					subl = inputline.substr(++pos, inputline.length() - pos);
					params++;
					//vector
					if ((subl.find(brcl, 0)) != 0)
					{
						brpos = subl.find(brcl, 0);
						while (subl.find(co, 0) < brpos)
						{
							ALine = subl.substr(0, subl.find(co, 0));
							vq.push_back(stoi(ALine));
							pos += ALine.length();
							brpos -= ALine.length();
							brpos--;
							subl = inputline.substr(++pos, inputline.length() - pos);
						}
						ALine = subl.substr(0, brpos);
						vq.push_back(stoi(ALine));
						pos += ALine.size();
						pos++;
					}
				}
			}
		ptr = new nested_cond_fact(q, vq);
	}
	else if (ALine == "top_level_call")
	{
		flag = 0;
		int				q{}, w{}, r{}, y{}, i{}, p{};
		string			e{}, t{}, u{}, o{}, a{};

		subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.find(co, 0));
				q = stoi(ALine);
				pos += ALine.length();
				subl = inputline.substr(++pos, inputline.length() - pos);
			}
			else stop = 0;
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					w = stoi(ALine);
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					e = ALine;
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					r = stoi(ALine);
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					t = ALine;
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					y = stoi(ALine);
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					u = ALine;
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					i = stoi(ALine);
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					o = ALine;
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					p = stoi(ALine);
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.rfind(pacl, 0));
					ALine.resize(ALine.size() - 1);
					a = ALine;
				}
			}
		ptr = new top_level_call(q, w, e, r, t, y, u, i, o, p, a);
	}
	else if (ALine == "top_level_call_parcs")
	{
		flag = 0;
		int				q{}, w{}, r{}, y{}, i{}, p{};
		string			e{}, t{}, u{}, o{}, a{};

		subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.find(co, 0));
				q = stoi(ALine);
				pos += ALine.length();
				subl = inputline.substr(++pos, inputline.length() - pos);
			}
			else stop = 0;
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					w = stoi(ALine);
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					e = ALine;
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					r = stoi(ALine);
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					t = ALine;
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					y = stoi(ALine);
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					u = ALine;
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					i = stoi(ALine);
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					o = ALine;
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					p = stoi(ALine);
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.rfind(pacl, 0));
					ALine.resize(ALine.size() - 1);
					a = ALine;
				}
			}
		ptr = new top_level_call_parcs(q, w, e, r, t, y, u, i, o, p, a);
	}
	else if (ALine == "added_aux_call_ios")
	{
		flag = 0;
		int				w{};
		string			q{};

		subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.find(co, 0));
				q = ALine;
				pos += ALine.length();
				subl = inputline.substr(++pos, inputline.length() - pos);
			}
			else stop = 0;
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.rfind(pacl, 0));
					w = stoi(ALine);
				}
			}
		ptr = new added_aux_call_ios(q, w);
	}
	else if (ALine == "added_aux_call_ios1")
	{
		flag = 0;
		int				w{}, e{};
		string			q{};

		subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.find(co, 0));
				q = ALine;
				pos += ALine.length();
				subl = inputline.substr(++pos, inputline.length() - pos);
			}
			else stop = 0;
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					w = stoi(ALine);
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.rfind(pacl, 0));
					e = stoi(ALine);
				}
			}
		ptr = new added_aux_call_ios1(q, w, e);
	}
	else if (ALine == "added_aux_call_signals")
	{
		flag = 0;
		int				w{};
		string			q{};

		subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.find(co, 0));
				q = ALine;
				pos += ALine.length();
				subl = inputline.substr(++pos, inputline.length() - pos);
			}
			else stop = 0;
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.rfind(pacl, 0));
					w = stoi(ALine);
				}
			}
		ptr = new added_aux_call_signals(q, w);
	}
	else if (ALine == "found_call_operator")
	{
		flag = 0;
		int				w{};
		string			q{};

		subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.find(co, 0));
				q = ALine;
				pos += ALine.length();
				subl = inputline.substr(++pos, inputline.length() - pos);
			}
			else stop = 0;
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.rfind(pacl, 0));
					w = stoi(ALine);
				}
			}
		ptr = new found_call_operator(q, w);
	}
	else if (ALine == "added_verilog_aux_call_outputs")
	{
		flag = 0;
		int				w{};
		string			q{}, e{};

		subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.find(co, 0));
				q = ALine;
				pos += ALine.length();
				subl = inputline.substr(++pos, inputline.length() - pos);
			}
			else stop = 0;
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					w = stoi(ALine);
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.rfind(pacl, 0));
					ALine.resize(ALine.size() - 1);
					e = ALine;
				}
			}
		ptr = new added_verilog_aux_call_outputs(q, w, e);
	}
	else if (ALine == "raw_dependencies")
	{
		flag = 0;
		int				w{};
		string			q{};
		vector<int>		vq, vw;

		subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.find(co, 0));
				q = ALine;
				pos += ALine.length();
				subl = inputline.substr(++pos, inputline.length() - pos);
			}
			else stop = 0;
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					w = stoi(ALine);
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}

			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					subl = inputline.substr(++pos, inputline.length() - pos);
					//vector
					params++;
					if ((subl.find(brcl, 0)) != 0)
					{
						brpos = subl.find(brcl, 0);
						while (subl.find(co, 0) < brpos)
						{
							ALine = subl.substr(0, subl.find(co, 0));
							vq.push_back(stoi(ALine));
							pos += ALine.length();
							brpos -= ALine.length();
							brpos--;
							subl = inputline.substr(++pos, inputline.length() - pos);
						}
						ALine = subl.substr(0, brpos);
						vq.push_back(stoi(ALine));
						pos += ALine.size();
					}
					subl = inputline.substr(++++pos, inputline.length() - pos);
				}
				else stop = 0;
			}


			//vector2
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					subl = inputline.substr(++pos, inputline.length() - pos);
					params++;
					if ((subl.find(brcl, 0)) != 0)
					{
						brpos = subl.find(brcl, 0);
						while (subl.find(co, 0) < brpos)
						{
							ALine = subl.substr(0, subl.find(co, 0));
							vw.push_back(stoi(ALine));
							pos += ALine.length();
							brpos -= ALine.length();
							brpos--;
							subl = inputline.substr(++pos, inputline.length() - pos);
						}
						ALine = subl.substr(0, brpos);
						vw.push_back(stoi(ALine));
						pos += ALine.size();
					}
				}
			}
		ptr = new raw_dependencies(q, w, vq, vw);
	}
	else if (ALine == "war_dependencies")
	{
		flag = 0;
		int				w{};
		string			q{};
		vector<int>		vq, vw;

		subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.find(co, 0));
				q = ALine;
				pos += ALine.length();
				subl = inputline.substr(++pos, inputline.length() - pos);
			}
			else stop = 0;
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					w = stoi(ALine);
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}

			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					subl = inputline.substr(++pos, inputline.length() - pos);
					//vector
					params++;
					if ((subl.find(brcl, 0)) != 0)
					{
						brpos = subl.find(brcl, 0);
						while (subl.find(co, 0) < brpos)
						{
							ALine = subl.substr(0, subl.find(co, 0));
							vq.push_back(stoi(ALine));
							pos += ALine.length();
							brpos -= ALine.length();
							brpos--;
							subl = inputline.substr(++pos, inputline.length() - pos);
						}
						ALine = subl.substr(0, brpos);
						vq.push_back(stoi(ALine));
						pos += ALine.size();
					}
					subl = inputline.substr(++++pos, inputline.length() - pos);
				}
				else stop = 0;
			}

			//vector2
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					subl = inputline.substr(++pos, inputline.length() - pos);
					params++;
					if ((subl.find(brcl, 0)) != 0)
					{
						brpos = subl.find(brcl, 0);
						while (subl.find(co, 0) < brpos)
						{
							ALine = subl.substr(0, subl.find(co, 0));
							vw.push_back(stoi(ALine));
							pos += ALine.length();
							brpos -= ALine.length();
							brpos--;
							subl = inputline.substr(++pos, inputline.length() - pos);
						}
						ALine = subl.substr(0, brpos);
						vw.push_back(stoi(ALine));
						pos += ALine.size();
					}
				}
			}
		ptr = new war_dependencies(q, w, vq, vw);
	}
	else if (ALine == "waw_dependencies")
	{
		flag = 0;
		int				w{};
		string			q{};
		vector<int>		vq, vw;

		subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.find(co, 0));
				q = ALine;
				pos += ALine.length();
				subl = inputline.substr(++pos, inputline.length() - pos);
			}
			else stop = 0;
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					w = stoi(ALine);
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}

			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					subl = inputline.substr(++pos, inputline.length() - pos);
					//vector
					params++;
					if ((subl.find(brcl, 0)) != 0)
					{
						brpos = subl.find(brcl, 0);
						while (subl.find(co, 0) < brpos)
						{
							ALine = subl.substr(0, subl.find(co, 0));
							vq.push_back(stoi(ALine));
							pos += ALine.length();
							brpos -= ALine.length();
							brpos--;
							subl = inputline.substr(++pos, inputline.length() - pos);
						}
						ALine = subl.substr(0, brpos);
						vq.push_back(stoi(ALine));
						pos += ALine.size();
					}
					subl = inputline.substr(++++pos, inputline.length() - pos);
				}
				else stop = 0;
			}

			//vector2
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					subl = inputline.substr(++pos, inputline.length() - pos);
					params++;
					if ((subl.find(brcl, 0)) != 0)
					{
						brpos = subl.find(brcl, 0);
						while (subl.find(co, 0) < brpos)
						{
							ALine = subl.substr(0, subl.find(co, 0));
							vw.push_back(stoi(ALine));
							pos += ALine.length();
							brpos -= ALine.length();
							brpos--;
							subl = inputline.substr(++pos, inputline.length() - pos);
						}
						ALine = subl.substr(0, brpos);
						vw.push_back(stoi(ALine));
						pos += ALine.size();
					}
				}
			}
		ptr = new waw_dependencies(q, w, vq, vw);
	}
	else if (ALine == "schedule")
	{
		flag = 0;
		int				w{}, r{};
		string			q{}, e{};
		vector<int>		vq, vw, ve, vr;

		subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.find(co, 0));
				q = ALine;
				pos += ALine.length();
				subl = inputline.substr(++pos, inputline.length() - pos);
			}
			else stop = 0;
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					w = stoi(ALine);
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					e = ALine;
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					r = stoi(ALine);
				}
			}
		ptr = new schedule(q, w, e, r);
	}
	else if (ALine == "last_conditional_execution")
	{
		flag = 0;
		int				w{};
		string			q{};

		subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.find(co, 0));
				q = ALine;
				pos += ALine.length();
				subl = inputline.substr(++pos, inputline.length() - pos);
			}
			else stop = 0;
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.rfind(pacl, 0));
					w = stoi(ALine);
				}
			}
		ptr = new last_conditional_execution(q, w);
	}
	else if (ALine == "conditional_operations")
	{
		flag = 0;
		int				e{}, r{};
		string			q{}, w{};
		vector<int>		vq, vw, ve, vr;

		subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.find(co, 0));
				q = ALine;
				pos += ALine.length();
				subl = inputline.substr(++pos, inputline.length() - pos);
			}
			else stop = 0;
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					w = ALine;
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					e = stoi(ALine);
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					r = stoi(ALine);
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}

			//vector
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					subl = inputline.substr(++pos, inputline.length() - pos);
					params++;
					if ((subl.find(brcl, 0)) != 0)
					{
						brpos = subl.find(brcl, 0);
						while (subl.find(co, 0) < brpos)
						{
							ALine = subl.substr(0, subl.find(co, 0));
							vq.push_back(stoi(ALine));
							pos += ALine.length();
							brpos -= ALine.length();
							brpos--;
							subl = inputline.substr(++pos, inputline.length() - pos);
						}
						ALine = subl.substr(0, brpos);
						pos += ALine.length();
						vq.push_back(stoi(ALine));
					}
					subl = inputline.substr(++++pos, inputline.length() - pos);
				}
				else stop = 0;
			}

			//vector2
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					subl = inputline.substr(++pos, inputline.length() - pos);
					params++;
					if ((subl.find(brcl, 0)) != 0)
					{
						brpos = subl.find(brcl, 0);
						while (subl.find(co, 0) < brpos)
						{
							ALine = subl.substr(0, subl.find(co, 0));
							vw.push_back(stoi(ALine));
							pos += ALine.length();
							brpos -= ALine.length();
							brpos--;
							subl = inputline.substr(++pos, inputline.length() - pos);
						}
						ALine = subl.substr(0, brpos);
						vw.push_back(stoi(ALine));
						pos += ALine.size();
					}
					subl = inputline.substr(++++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			
			//vector3
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					subl = inputline.substr(++pos, inputline.length() - pos);
					params++;
					if ((subl.find(brcl, 0)) != 0)
					{
						brpos = subl.find(brcl, 0);
						while (subl.find(co, 0) < brpos)
						{
							ALine = subl.substr(0, subl.find(co, 0));
							ve.push_back(stoi(ALine));
							pos += ALine.length();
							brpos -= ALine.length();
							brpos--;
							subl = inputline.substr(++pos, inputline.length() - pos);
						}
						ALine = subl.substr(0, brpos);
						ve.push_back(stoi(ALine));
						pos += ALine.size();
					}
					subl = inputline.substr(++++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			
			//vector4
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					subl = inputline.substr(++pos, inputline.length() - pos);
					params++;
					if ((subl.find(brcl, 0)) != 0)
					{
						brpos = subl.find(brcl, 0);
						while (subl.find(co, 0) < brpos)
						{
							ALine = subl.substr(0, subl.find(co, 0));
							vr.push_back(stoi(ALine));
							pos += ALine.length();
							brpos -= ALine.length();
							brpos--;
							subl = inputline.substr(++pos, inputline.length() - pos);
						}
						ALine = subl.substr(0, brpos);
						vr.push_back(stoi(ALine));
						pos += ALine.size();
					}
				}
				else stop = 0;
			}
		ptr = new conditional_operations(q, w, e, r, vq, vw, ve, vr);
	}
	else if (ALine == "last_conditional_transition_of_schedule")
	{
		flag = 0;
		int				e{};
		string			q{}, w{};

		
		subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.find(co, 0));
				q = ALine;
				pos += ALine.length();
				subl = inputline.substr(++pos, inputline.length() - pos);
			}
			else stop = 0;
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					w = ALine;
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.rfind(pacl, 0));
					e = stoi(ALine);
				}
			}
		ptr = new last_conditional_transition_of_schedule(q, w, e);
	}
	else if (ALine == "transition_to_be_rescheduled")
	{
		flag = 0;
		int				e{}, t{};
		string			q{}, w{}, r{};

		subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.find(co, 0));
				q = ALine;
				pos += ALine.length();
				subl = inputline.substr(++pos, inputline.length() - pos);
			}
			else stop = 0;
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					w = ALine;
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					e = stoi(ALine);
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					r = ALine;
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.rfind(pacl, 0));
					t = stoi(ALine);
				}
			}
		ptr = new transition_to_be_rescheduled(w, e, q, r, t);
	}
	else if (ALine == "last_conditional_transition")
	{
		flag = 0;
		int				w{};
		string			q{};

		subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.find(co, 0));
				q = ALine;
				pos += ALine.length();
				subl = inputline.substr(++pos, inputline.length() - pos);
			}
			else stop = 0;
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.rfind(pacl, 0));
					w = stoi(ALine);
				}
			}
		ptr = new last_conditional_transition(q, w);
	}
	else if (ALine == "conditional_transitions")
	{
		flag = 0;
		int				e{}, r{}, t{}, y{}, u{}, i{};
		string			q{}, w{};

		subl = inputline.substr(++pos, inputline.length() - pos);
			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.find(co, 0));
				q = ALine;
				pos += ALine.length();
				subl = inputline.substr(++pos, inputline.length() - pos);
			}
			else stop = 0;
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					w = ALine;
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					e = stoi(ALine);
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					r = stoi(ALine);
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					t = stoi(ALine);
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					y = stoi(ALine);
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					u = stoi(ALine);
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.rfind(pacl, 0));
					i = stoi(ALine);
				}
			}
		ptr = new conditional_transitions(q, w, e, r, t, y, u, i);
	}
	else if (ALine == "state")
	{
		flag = 0;
		int				e{}, t{}, y{};
		string			q{}, w{}, r{};
		vector<int>		vq, vw;

		subl = inputline.substr(++pos, inputline.length() - pos);
			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.find(co, 0));
				q = ALine;
				pos += ALine.length();
				subl = inputline.substr(++pos, inputline.length() - pos);
			}
			else stop = 0;
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					w = ALine;
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					e = stoi(ALine);
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					r = ALine;
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					t = stoi(ALine);
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					y = stoi(ALine);
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}

			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					subl = inputline.substr(++pos, inputline.length() - pos);
					//vector
					params++;
					if ((subl.find(brcl, 0)) != 0)
					{
						brpos = subl.find(brcl, 0);
						while (subl.find(co, 0) < brpos)
						{
							ALine = subl.substr(0, subl.find(co, 0));
							vq.push_back(stoi(ALine));
							pos += ALine.length();
							brpos -= ALine.length();
							brpos--;
							subl = inputline.substr(++pos, inputline.length() - pos);
						}
						ALine = subl.substr(0, brpos);
						vq.push_back(stoi(ALine));
						pos += ALine.size();
					}
					subl = inputline.substr(++++pos, inputline.length() - pos);
				}
				else stop = 0;
			}

			//vector2
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					subl = inputline.substr(++pos, inputline.length() - pos);
					params++;
					if ((subl.find(brcl, 0)) != 0)
					{
						brpos = subl.find(brcl, 0);
						while (subl.find(co, 0) < brpos)
						{
							ALine = subl.substr(0, subl.find(co, 0));
							vw.push_back(stoi(ALine));
							pos += ALine.length();
							brpos -= ALine.length();
							brpos--;
							subl = inputline.substr(++pos, inputline.length() - pos);
						}
						ALine = subl.substr(0, brpos);
						vw.push_back(stoi(ALine));
						pos += ALine.size();
					}
				}
			}
		ptr = new state(q, w, e, r, t, y, vq, vw);
	}
	else if (ALine == "rescheduled")
	{
		flag = 0;
		int				e{}, t{};
		string			q{}, w{}, r{};

		subl = inputline.substr(++pos, inputline.length() - pos);
			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.find(co, 0));
				q = ALine;
				pos += ALine.length();
				subl = inputline.substr(++pos, inputline.length() - pos);
			}
			else stop = 0;
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					w = ALine;
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					e = stoi(ALine);
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					r = ALine;
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.rfind(pacl, 0));
					t = stoi(ALine);
				}
			}
		ptr = new rescheduled(w, e, q, r, t);
	}
	else if (ALine == "last_rescheduled")
	{
		flag = 0;
		int				e{}, t{};
		string			q{}, w{}, r{};

		subl = inputline.substr(++pos, inputline.length() - pos);
			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.find(co, 0));
				q = ALine;
				pos += ALine.length();
				subl = inputline.substr(++pos, inputline.length() - pos);
			}
			else stop = 0;
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					w = ALine;
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					e = stoi(ALine);
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					r = ALine;
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.rfind(pacl, 0));
					t = stoi(ALine);
				}
			}
		ptr = new last_rescheduled(w, e, q, r, t);
	}
	else if (ALine == "raw_cessor")
	{
		flag = 0;
		int				w{}, e{};
		string			q{};

		subl = inputline.substr(++pos, inputline.length() - pos);
			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.find(co, 0));
				q = ALine;
				pos += ALine.length();
				subl = inputline.substr(++pos, inputline.length() - pos);
			}
			else stop = 0;
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					w = stoi(ALine);
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.rfind(pacl, 0));
					e = stoi(ALine);
				}
			}
		ptr = new raw_cessor(q, w, e);
	}
	else if (ALine == "war_cessor")
	{
		flag = 0;
		int				w{}, e{};
		string			q{};

		subl = inputline.substr(++pos, inputline.length() - pos);
			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.find(co, 0));
				q = ALine;
				pos += ALine.length();
				subl = inputline.substr(++pos, inputline.length() - pos);
			}
			else stop = 0;
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					w = stoi(ALine);
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.rfind(pacl, 0));
					e = stoi(ALine);
				}
			}
		ptr = new war_cessor(q, w, e);
	}
	else if (ALine == "waw_cessor")
	{
		flag = 0;
		int				w{}, e{};
		string			q{};

		subl = inputline.substr(++pos, inputline.length() - pos);
			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.find(co, 0));
				q = ALine;
				pos += ALine.length();
				subl = inputline.substr(++pos, inputline.length() - pos);
			}
			else stop = 0;
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					w = stoi(ALine);
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.rfind(pacl, 0));
					e = stoi(ALine);
				}
			}
		ptr = new waw_cessor(q, w, e);
	}
	else if (ALine == "op_resource")
	{
		flag = 0;
		int				e{};
		string			q{}, w{};

		subl = inputline.substr(++pos, inputline.length() - pos);
			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.find(co, 0));
				q = ALine;
				pos += ALine.length();
				subl = inputline.substr(++pos, inputline.length() - pos);
			}
			else stop = 0;
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					w = ALine;
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.rfind(pacl, 0));
					e = stoi(ALine);
				}
			}
		ptr = new op_resource(q, w, e);
	}
	else if (ALine == "global_resource")
	{
		flag = 0;
		int				q{};

		subl = inputline.substr(++pos, inputline.length() - pos);
			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.rfind(pacl, 0));
				q = stoi(ALine);
			}
		ptr = new global_resource(q);
	}
	else if (ALine == "module_g_resource")
	{
		flag = 0;
		int				w{};
		string			q{};

		subl = inputline.substr(++pos, inputline.length() - pos);
			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.find(co, 0));
				q = ALine;
				pos += ALine.length();
				subl = inputline.substr(++pos, inputline.length() - pos);
			}
			else stop = 0;
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.rfind(pacl, 0));
					w = stoi(ALine);
				}
			}
		ptr = new module_g_resource(q, w);
	}
	else if (ALine == "cf_previous_op")
	{
		flag = 0;
		int				w{}, e{}, r{};
		string			q{};

		subl = inputline.substr(++pos, inputline.length() - pos);
			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.find(co, 0));
				q = ALine;
				pos += ALine.length();
				subl = inputline.substr(++pos, inputline.length() - pos);
			}
			else stop = 0;
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					w = stoi(ALine);
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					e = stoi(ALine);
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.rfind(pacl, 0));
					r = stoi(ALine);
				}
			}
		ptr = new cf_previous_op(q, w, e, r);
	}
	else if (ALine == "cf_previous_state")
	{
		flag = 0;
		int				w{}, e{}, r{};
		string			q{};

		subl = inputline.substr(++pos, inputline.length() - pos);
			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.find(co, 0));
				q = ALine;
				pos += ALine.length();
				subl = inputline.substr(++pos, inputline.length() - pos);
			}
			else stop = 0;
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					w = stoi(ALine);
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					e = stoi(ALine);
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.rfind(pacl, 0));
					r = stoi(ALine);
				}
			}
		ptr = new cf_previous_state(q, w, e, r);
	}
	else if (ALine == "pred_candidate_examined")
	{
		flag = 0;
		int				w{}, e{};
		string			q{};

		subl = inputline.substr(++pos, inputline.length() - pos);
			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.find(co, 0));
				q = ALine;
				pos += ALine.length();
				subl = inputline.substr(++pos, inputline.length() - pos);
			}
			else stop = 0;
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					w = stoi(ALine);
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.rfind(pacl, 0));
					e = stoi(ALine);
				}
			}
		ptr = new pred_candidate_examined(q, w, e);
	}
	else if (ALine == "reentrant_triangle")
	{
		flag = 0;
		int				w{}, e{}, r{}, a{}, s{};
		string			q{}, d{}, f{};
		vector<int>		vq, vw, ve, vr, vt, vy;

		subl = inputline.substr(++pos, inputline.length() - pos);
			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.find(co, 0));
				q = ALine;
				pos += ALine.length();
				subl = inputline.substr(++pos, inputline.length() - pos);
			}
			else stop = 0;
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					w = stoi(ALine);
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					e = stoi(ALine);
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					r = stoi(ALine);
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}

			//vector
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					subl = inputline.substr(++pos, inputline.length() - pos);
					params++;
					if ((subl.find(brcl, 0)) != 0)
					{
						brpos = subl.find(brcl, 0);
						while (subl.find(co, 0) < brpos)
						{
							ALine = subl.substr(0, subl.find(co, 0));
							vq.push_back(stoi(ALine));
							pos += ALine.length();
							brpos -= ALine.length();
							brpos--;
							subl = inputline.substr(++pos, inputline.length() - pos);
						}
						ALine = subl.substr(0, brpos);
						pos += ALine.length();
						vq.push_back(stoi(ALine));
					}
					subl = inputline.substr(++++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			
			//vector2
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					subl = inputline.substr(++pos, inputline.length() - pos);
					params++;
					if ((subl.find(brcl, 0)) != 0)
					{
						brpos = subl.find(brcl, 0);
						while (subl.find(co, 0) < brpos)
						{
							ALine = subl.substr(0, subl.find(co, 0));
							vw.push_back(stoi(ALine));
							pos += ALine.length();
							brpos -= ALine.length();
							brpos--;
							subl = inputline.substr(++pos, inputline.length() - pos);
						}
						ALine = subl.substr(0, brpos);
						vw.push_back(stoi(ALine));
						pos += ALine.size();
					}
					subl = inputline.substr(++++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			
			//vector3
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					subl = inputline.substr(++pos, inputline.length() - pos);
					params++;
					if ((subl.find(brcl, 0)) != 0)
					{
						brpos = subl.find(brcl, 0);
						while (subl.find(co, 0) < brpos)
						{
							ALine = subl.substr(0, subl.find(co, 0));
							ve.push_back(stoi(ALine));
							pos += ALine.length();
							brpos -= ALine.length();
							brpos--;
							subl = inputline.substr(++pos, inputline.length() - pos);
						}
						ALine = subl.substr(0, brpos);
						ve.push_back(stoi(ALine));
						pos += ALine.size();
					}
					subl = inputline.substr(++++pos, inputline.length() - pos);
				}
				else stop = 0;
			}

			//vector4
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					subl = inputline.substr(++pos, inputline.length() - pos);
					params++;
					if ((subl.find(brcl, 0)) != 0)
					{
						brpos = subl.find(brcl, 0);
						while (subl.find(co, 0) < brpos)
						{
							ALine = subl.substr(0, subl.find(co, 0));
							vr.push_back(stoi(ALine));
							pos += ALine.length();
							brpos -= ALine.length();
							brpos--;
							subl = inputline.substr(++pos, inputline.length() - pos);
						}
						ALine = subl.substr(0, brpos);
						vr.push_back(stoi(ALine));
						pos += ALine.size();
					}
					subl = inputline.substr(++++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			
			//vector5
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					subl = inputline.substr(++pos, inputline.length() - pos);
					params++;
					if ((subl.find(brcl, 0)) != 0)
					{
						brpos = subl.find(brcl, 0);
						while (subl.find(co, 0) < brpos)
						{
							ALine = subl.substr(0, subl.find(co, 0));
							vt.push_back(stoi(ALine));
							pos += ALine.length();
							brpos -= ALine.length();
							brpos--;
							subl = inputline.substr(++pos, inputline.length() - pos);
						}
						ALine = subl.substr(0, brpos);
						vt.push_back(stoi(ALine));
						pos += ALine.size();
					}
					subl = inputline.substr(++++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			
			//vector6
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					subl = inputline.substr(++pos, inputline.length() - pos);
					params++;
					if ((subl.find(brcl, 0)) != 0)
					{
						brpos = subl.find(brcl, 0);
						while (subl.find(co, 0) < brpos)
						{
							ALine = subl.substr(0, subl.find(co, 0));
							vy.push_back(stoi(ALine));
							pos += ALine.length();
							brpos -= ALine.length();
							brpos--;
							subl = inputline.substr(++pos, inputline.length() - pos);
						}
						ALine = subl.substr(0, brpos);
						vy.push_back(stoi(ALine));
						pos += ALine.size();
					}
					subl = inputline.substr(++++pos, inputline.length() - pos);
				}
				else stop = 0;
			}

			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					a = stoi(ALine);
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					s = stoi(ALine);
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					d = ALine;
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					ALine.resize(ALine.size() - 1);
					f = ALine;
				}
			}
		ptr = new reentrant_triangle(q, w, e, r, vq, vw, ve, vr, vt, vy, a, s, d, f);
	}
	else if (ALine == "last_reentrant_triangle")
	{
		flag = 0;
		int				w{};
		string			q{};

		subl = inputline.substr(++pos, inputline.length() - pos);
			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.find(co, 0));
				q = ALine;
				pos += ALine.length();
				subl = inputline.substr(++pos, inputline.length() - pos);
			}
			else stop = 0;
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.rfind(pacl, 0));
					w = stoi(ALine);
				}
			}
		ptr = new last_reentrant_triangle(q, w);
	}
	else if (ALine == "last_schedule_state")
	{
		flag = 0;
		int				e{};
		string			q{}, w{};

		subl = inputline.substr(++pos, inputline.length() - pos);
			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.find(co, 0));
				q = ALine;
				pos += ALine.length();
				subl = inputline.substr(++pos, inputline.length() - pos);
			}
			else stop = 0;
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					w = ALine;
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.rfind(pacl, 0));
					e = stoi(ALine);
				}
			}
		ptr = new last_schedule_state(q, w, e);
	}
	else if (ALine == "conditional_incomplete")
	{
		flag = 0;
		int				e{}, r{}, a{}, s{}, d{}, f{}, g{}, h{}, j{}, k{}, l{}, z{}, x{};
		string			q{}, w{};
		vector<int>		vq, vw, ve, vr, vt, vy;

		subl = inputline.substr(++pos, inputline.length() - pos);
			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.find(co, 0));
				q = ALine;
				pos += ALine.length();
				subl = inputline.substr(++pos, inputline.length() - pos);
			}
			else stop = 0;
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					w = ALine;
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					e = stoi(ALine);
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					r = stoi(ALine);
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}

			//vector
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					subl = inputline.substr(++pos, inputline.length() - pos);
					params++;
					if ((subl.find(brcl, 0)) != 0)
					{
						brpos = subl.find(brcl, 0);
						while (subl.find(co, 0) < brpos)
						{
							ALine = subl.substr(0, subl.find(co, 0));
							vq.push_back(stoi(ALine));
							pos += ALine.length();
							brpos -= ALine.length();
							brpos--;
							subl = inputline.substr(++pos, inputline.length() - pos);
						}
						ALine = subl.substr(0, brpos);
						pos += ALine.length();
						vq.push_back(stoi(ALine));
					}
					subl = inputline.substr(++++pos, inputline.length() - pos);
				}
				else stop = 0;
			}

			//vector2
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					subl = inputline.substr(++pos, inputline.length() - pos);
					params++;
					if ((subl.find(brcl, 0)) != 0)
					{
						brpos = subl.find(brcl, 0);
						while (subl.find(co, 0) < brpos)
						{
							ALine = subl.substr(0, subl.find(co, 0));
							vw.push_back(stoi(ALine));
							pos += ALine.length();
							brpos -= ALine.length();
							brpos--;
							subl = inputline.substr(++pos, inputline.length() - pos);
						}
						ALine = subl.substr(0, brpos);
						vw.push_back(stoi(ALine));
						pos += ALine.size();
					}
					subl = inputline.substr(++++pos, inputline.length() - pos);
				}
				else stop = 0;
			}

			//vector3
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					subl = inputline.substr(++pos, inputline.length() - pos);
					params++;
					if ((subl.find(brcl, 0)) != 0)
					{
						brpos = subl.find(brcl, 0);
						while (subl.find(co, 0) < brpos)
						{
							ALine = subl.substr(0, subl.find(co, 0));
							ve.push_back(stoi(ALine));
							pos += ALine.length();
							brpos -= ALine.length();
							brpos--;
							subl = inputline.substr(++pos, inputline.length() - pos);
						}
						ALine = subl.substr(0, brpos);
						ve.push_back(stoi(ALine));
						pos += ALine.size();
					}
					subl = inputline.substr(++++pos, inputline.length() - pos);
				}
				else stop = 0;
			}

			//vector4
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					subl = inputline.substr(++pos, inputline.length() - pos);
					params++;
					if ((subl.find(brcl, 0)) != 0)
					{
						brpos = subl.find(brcl, 0);
						while (subl.find(co, 0) < brpos)
						{
							ALine = subl.substr(0, subl.find(co, 0));
							vr.push_back(stoi(ALine));
							pos += ALine.length();
							brpos -= ALine.length();
							brpos--;
							subl = inputline.substr(++pos, inputline.length() - pos);
						}
						ALine = subl.substr(0, brpos);
						vr.push_back(stoi(ALine));
						pos += ALine.size();
					}
					subl = inputline.substr(++++pos, inputline.length() - pos);
				}
				else stop = 0;
			}

			//vector5
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					subl = inputline.substr(++pos, inputline.length() - pos);
					params++;
					if ((subl.find(brcl, 0)) != 0)
					{
						brpos = subl.find(brcl, 0);
						while (subl.find(co, 0) < brpos)
						{
							ALine = subl.substr(0, subl.find(co, 0));
							vt.push_back(stoi(ALine));
							pos += ALine.length();
							brpos -= ALine.length();
							brpos--;
							subl = inputline.substr(++pos, inputline.length() - pos);
						}
						ALine = subl.substr(0, brpos);
						vt.push_back(stoi(ALine));
						pos += ALine.size();
					}
					subl = inputline.substr(++++pos, inputline.length() - pos);
				}
				else stop = 0;
			}

			//vector6
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					subl = inputline.substr(++pos, inputline.length() - pos);
					params++;
					if ((subl.find(brcl, 0)) != 0)
					{
						brpos = subl.find(brcl, 0);
						while (subl.find(co, 0) < brpos)
						{
							ALine = subl.substr(0, subl.find(co, 0));
							vy.push_back(stoi(ALine));
							pos += ALine.length();
							brpos -= ALine.length();
							brpos--;
							subl = inputline.substr(++pos, inputline.length() - pos);
						}
						ALine = subl.substr(0, brpos);
						vy.push_back(stoi(ALine));
						pos += ALine.size();
					}
					subl = inputline.substr(++++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					a = stoi(ALine);
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					s = stoi(ALine);
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					d = stoi(ALine);
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					f = stoi(ALine);
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					g = stoi(ALine);
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					h = stoi(ALine);
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					j = stoi(ALine);
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					k = stoi(ALine);
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					l = stoi(ALine);
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					z = stoi(ALine);
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					x = stoi(ALine);
				}
			}
		ptr = new conditional_incomplete(q, w, e, r, vq, vw, ve, vr, vt, vy, a, s, d, f, g, h, j, k, l, z, x);
	}
	else if (ALine == "mixed_incomplete_state_lists")
	{
		flag = 0;
		int				e{};
		string			q{}, w{};
		vector<int>		vq, vw;

		subl = inputline.substr(++pos, inputline.length() - pos);
			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.find(co, 0));
				q = ALine;
				pos += ALine.length();
				subl = inputline.substr(++pos, inputline.length() - pos);
			}
			else stop = 0;
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					w = ALine;
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					e = stoi(ALine);
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}

			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					subl = inputline.substr(++pos, inputline.length() - pos);
					//vector
					params++;
					if ((subl.find(brcl, 0)) != 0)
					{
						brpos = subl.find(brcl, 0);
						while (subl.find(co, 0) < brpos)
						{
							ALine = subl.substr(0, subl.find(co, 0));
							vq.push_back(stoi(ALine));
							pos += ALine.length();
							brpos -= ALine.length();
							brpos--;
							subl = inputline.substr(++pos, inputline.length() - pos);
						}
						ALine = subl.substr(0, brpos);
						vq.push_back(stoi(ALine));
						pos += ALine.size();
					}
					subl = inputline.substr(++++pos, inputline.length() - pos);
				}
				else stop = 0;
			}


			//vector2
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					subl = inputline.substr(++pos, inputline.length() - pos);
					params++;
					if ((subl.find(brcl, 0)) != 0)
					{
						brpos = subl.find(brcl, 0);
						while (subl.find(co, 0) < brpos)
						{
							ALine = subl.substr(0, subl.find(co, 0));
							vw.push_back(stoi(ALine));
							pos += ALine.length();
							brpos -= ALine.length();
							brpos--;
							subl = inputline.substr(++pos, inputline.length() - pos);
						}
						ALine = subl.substr(0, brpos);
						vw.push_back(stoi(ALine));
						pos += ALine.size();
					}
				}
			}
		ptr = new mixed_incomplete_state_lists(w, e, q, vq, vw);
	}
	else if (ALine == "linear_incomplete_node")
	{
		flag = 0;
		int				e{}, y{};
		string			q{}, w{};
		vector<int>		vq, vw;

		subl = inputline.substr(++pos, inputline.length() - pos);
			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.find(co, 0));
				q = ALine;
				pos += ALine.length();
				subl = inputline.substr(++pos, inputline.length() - pos);
			}
			else stop = 0;
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					w = ALine;
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					e = stoi(ALine);
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					y = stoi(ALine);
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}

			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					subl = inputline.substr(++pos, inputline.length() - pos);
					//vector
					params++;
					if ((subl.find(brcl, 0)) != 0)
					{
						brpos = subl.find(brcl, 0);
						while (subl.find(co, 0) < brpos)
						{
							ALine = subl.substr(0, subl.find(co, 0));
							vq.push_back(stoi(ALine));
							pos += ALine.length();
							brpos -= ALine.length();
							brpos--;
							subl = inputline.substr(++pos, inputline.length() - pos);
						}
						ALine = subl.substr(0, brpos);
						vq.push_back(stoi(ALine));
						pos += ALine.size();
					}
					subl = inputline.substr(++++pos, inputline.length() - pos);
				}
				else stop = 0;
			}


			//vector2
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					subl = inputline.substr(++pos, inputline.length() - pos);
					params++;
					if ((subl.find(brcl, 0)) != 0)
					{
						brpos = subl.find(brcl, 0);
						while (subl.find(co, 0) < brpos)
						{
							ALine = subl.substr(0, subl.find(co, 0));
							vw.push_back(stoi(ALine));
							pos += ALine.length();
							brpos -= ALine.length();
							brpos--;
							subl = inputline.substr(++pos, inputline.length() - pos);
						}
						ALine = subl.substr(0, brpos);
						vw.push_back(stoi(ALine));
						pos += ALine.size();
					}
				}
			}
		ptr = new linear_incomplete_node(w, e, q, y, vq, vw);
	}
	else if (ALine == "incomplete_links")
	{
		flag = 0;
		int			q{}, w{}, e{}, r{}, t{}, y{}, u{}, i{}, o{}, p{};

		subl = inputline.substr(++pos, inputline.length() - pos);
			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.find(co, 0));
				q = stoi(ALine);
				pos += ALine.length();
				subl = inputline.substr(++pos, inputline.length() - pos);
			}
			else stop = 0;
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					w = stoi(ALine);
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					e = stoi(ALine);
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					r = stoi(ALine);
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					t = stoi(ALine);
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					y = stoi(ALine);
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					u = stoi(ALine);
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					i = stoi(ALine);
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					o = stoi(ALine);
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.rfind(pacl, 0));
					p = stoi(ALine);
				}
			}
		ptr = new incomplete_links(q, w, e, r, t, y, u, i, o, p);
	}
	else if (ALine == "last_incomplete")
	{
		flag = 0;
		int				q{}, w{}, e{};
		string			r{};

		subl = inputline.substr(++pos, inputline.length() - pos);
			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.find(co, 0));
				q = stoi(ALine);
				pos += ALine.length();
				subl = inputline.substr(++pos, inputline.length() - pos);
			}
			else stop = 0;
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					w = stoi(ALine);
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					e = stoi(ALine);
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.rfind(pacl, 0));
					ALine.resize(ALine.size() - 1);
					r = ALine;
				}
			}
		ptr = new last_incomplete(q, w, e, r);
	}
	else if (ALine == "global_nils")
	{
		flag = 0;
		vector<nil_node>	vnil{};
		nil_node			nn(0, "");
		int					iv = 0;

		subl = inputline.substr(++pos, inputline.length() - pos);
			if ((subl.find(str, 0)) != 0)
			{
				subl = inputline.substr(++pos, inputline.length() - pos);
				//vector
				if ((subl.find(brcl, 0)) != 0)
				{
					brpos = subl.find(brcl, 0);
					while (subl.find(co, 0) < brpos && stop)
					{
						if ((subl.find(str, 0)) != 0)
						{
							params++;
							pos += 9;  // 9 because global_nils([>>nil_node(<<_, \"true\")
							brpos -= 9;
							subl = inputline.substr(pos, inputline.length() - pos);
							ALine = subl.substr(0, subl.find(co, 0));
							nn.q = stoi(ALine);
							pos += ALine.length();
							brpos -= ALine.length();
							brpos--;
							subl = inputline.substr(++pos, inputline.length() - pos);
							if (subl.find(co, 0) < brpos) //last parameters
							{
								ALine = subl.substr(0, subl.find(co, 0));
								pos += ALine.length();
								brpos -= ALine.length();
								ALine.resize(ALine.size() - 1);
								nn.w = ALine;
							}
							else //last
							{
								subl.resize(subl.size() - 2);
								nn.w = subl;
							}
							vnil.push_back(nn);
							brpos--;
							subl = inputline.substr(++pos, inputline.length() - pos);
							iv++;
						}
						else stop = 0;
					}
				}
				else params++;
			}
		ptr = new global_nils(vnil);
	}
	else if (ALine == "current_module")
	{
		flag = 0;
		string			q{};

		subl = inputline.substr(++pos, inputline.length() - pos);
			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.rfind(pacl, 0));
				ALine.resize(ALine.size() - 1);
				q = ALine;
			}
		ptr = new current_module(q);
	}
	else if (ALine == "last_linear_incomplete_node")
	{
		flag = 0;
		int				q{};

		subl = inputline.substr(++pos, inputline.length() - pos);
			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.rfind(pacl, 0));
				q = stoi(ALine);
			}
		ptr = new last_linear_incomplete_node(q);
	}
	else if (ALine == "operator_instances")
	{
		flag = 0;
		int				w{};
		string			q{};

		subl = inputline.substr(++pos, inputline.length() - pos);
			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.find(co, 0));
				q = ALine;
				pos += ALine.length();
				subl = inputline.substr(++pos, inputline.length() - pos);
			}
			else stop = 0;
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.rfind(pacl, 0));
					w = stoi(ALine);
				}
			}
		ptr = new operator_instances(q, w);
	}
	else if (ALine == "massively_parallel_style")
	{
		flag = 0;
		int				q{};

		subl = inputline.substr(++pos, inputline.length() - pos);
			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.rfind(pacl, 0));
				q = stoi(ALine);
			}
		ptr = new massively_parallel_style(q);
	}
	else if (ALine == "hdl_style")
	{
		flag = 0;
		string			q{};

		subl = inputline.substr(++pos, inputline.length() - pos);
			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.rfind(pacl, 0));
				ALine.resize(ALine.size() - 1);
				q = ALine;
			}
		ptr = new hdl_style(q);
	}
	else if (ALine == "op_instance")
	{
		flag = 0;
		int				q{}, e{}, r{};
		string			w{}, t{};

		subl = inputline.substr(++pos, inputline.length() - pos);
			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.find(co, 0));
				q = stoi(ALine);
				pos += ALine.length();
				subl = inputline.substr(++pos, inputline.length() - pos);
			}
			else stop = 0;
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					w = ALine;
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					e = stoi(ALine);
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					r = stoi(ALine);
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.rfind(pacl, 0));
					ALine.resize(ALine.size() - 1);
					t = ALine;
				}
			}
		ptr = new op_instance(w, e, q, r, t);
	}
	else if (ALine == "last_op_instance")
	{
		flag = 0;
		int				q{}, e{};
		string			w{};

		subl = inputline.substr(++pos, inputline.length() - pos);
			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.find(co, 0));
				q = stoi(ALine);
				pos += ALine.length();
				subl = inputline.substr(++pos, inputline.length() - pos);
			}
			else stop = 0;
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					w = ALine;
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.rfind(pacl, 0));
					e = stoi(ALine);
				}
			}
		ptr = new last_op_instance(q, w, e);
	}
	else if (ALine == "op_in_a_state")
	{
		flag = 0;
		int				q{}, r{};
		string			w{}, e{}, t{};

		subl = inputline.substr(++pos, inputline.length() - pos);
			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.find(co, 0));
				q = stoi(ALine);
				pos += ALine.length();
				subl = inputline.substr(++pos, inputline.length() - pos);
			}
			else stop = 0;
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					w = ALine;
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					e = ALine;
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					r = stoi(ALine);
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.rfind(pacl, 0));
					ALine.resize(ALine.size() - 1);
					t = ALine;
				}
			}
		ptr = new op_in_a_state(w, e, q, r, t);
	}
	else if (ALine == "last_op_in_a_state")
	{
		flag = 0;
		int				q{}, r{};
		string			w{}, e{};

		subl = inputline.substr(++pos, inputline.length() - pos);
			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.find(co, 0));
				q = stoi(ALine);
				pos += ALine.length();
				subl = inputline.substr(++pos, inputline.length() - pos);
			}
			else stop = 0;
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					w = ALine;
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					e = ALine;
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.rfind(pacl, 0));
					r = stoi(ALine);
				}
			}
		ptr = new last_op_in_a_state(q, w, e, r);
	}
	else if (ALine == "signal_instance")
	{
		flag = 0;
		int				q{}, t{}, y{}, u{};
		string			w{}, e{}, r{};

		subl = inputline.substr(++pos, inputline.length() - pos);
			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.find(co, 0));
				q = stoi(ALine);
				pos += ALine.length();
				subl = inputline.substr(++pos, inputline.length() - pos);
			}
			else stop = 0;
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					w = ALine;
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					e = ALine;
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					r = ALine;
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					t = stoi(ALine);
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					y = stoi(ALine);
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.rfind(pacl, 0));
					u = stoi(ALine);
				}
			}
		ptr = new signal_instance(q, w, e, r, t, y, u);
	}
	else if (ALine == "last_signal_instance")
	{
		flag = 0;
		int				q{};
		string			w{};

		subl = inputline.substr(++pos, inputline.length() - pos);
			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.find(co, 0));
				q = stoi(ALine);
				pos += ALine.length();
				subl = inputline.substr(++pos, inputline.length() - pos);
			}
			else stop = 0;
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.rfind(pacl, 0));
					ALine.resize(ALine.size() - 1);
					w = ALine;
				}
			}
		ptr = new last_signal_instance(q, w);
	}
	else if (ALine == "output_instance")
	{
		flag = 0;
		int				q{}, t{}, y{};
		string			w{}, e{}, r{};

		subl = inputline.substr(++pos, inputline.length() - pos);
			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.find(co, 0));
				q = stoi(ALine);
				pos += ALine.length();
				subl = inputline.substr(++pos, inputline.length() - pos);
			}
			else stop = 0;
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					w = ALine;
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					e = ALine;
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					r = ALine;
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					t = stoi(ALine);
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.rfind(pacl, 0));
					y = stoi(ALine);
				}
			}
		ptr = new output_instance(q, w, e, r, t, y);
	}
	else if (ALine == "last_output_instance")
	{
		flag = 0;
		int				q{};
		string			w{};

		subl = inputline.substr(++pos, inputline.length() - pos);
			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.find(co, 0));
				q = stoi(ALine);
				pos += ALine.length();
				subl = inputline.substr(++pos, inputline.length() - pos);
			}
			else stop = 0;
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.rfind(pacl, 0));
					ALine.resize(ALine.size() - 1);
					w = ALine;
				}
			}
		ptr = new last_output_instance(q, w);
	}
	else if (ALine == "operator_instance_stats")
	{
		flag = 0;
		int				w{}, e{}, r{};
		string			q{};

		subl = inputline.substr(++pos, inputline.length() - pos);
			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.find(co, 0));
				q = ALine;
				pos += ALine.length();
				subl = inputline.substr(++pos, inputline.length() - pos);
			}
			else stop = 0;
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					w = stoi(ALine);
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					e = stoi(ALine);
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.rfind(pacl, 0));
					r = stoi(ALine);
				}
			}
		ptr = new operator_instance_stats(q, w, e, r);
	}
	else if (ALine == "consecutive_106")
	{
		flag = 0;
		string			q{};

		subl = inputline.substr(++pos, inputline.length() - pos);
			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.rfind(pacl, 0));
				ALine.resize(ALine.size() - 1);
				q = ALine;
			}
		ptr = new consecutive_106(q);
	}
	else if (ALine == "operation_order")
	{
		flag = 0;
		int				e{}, r{}, t{}, y{}, u{}, i{}, o{}, p{};
		string			q{}, w{};

		subl = inputline.substr(++pos, inputline.length() - pos);
			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.find(co, 0));
				q = ALine;
				pos += ALine.length();
				subl = inputline.substr(++pos, inputline.length() - pos);
			}
			else stop = 0;
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					w = ALine;
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					e = stoi(ALine);
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					r = stoi(ALine);
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					t = stoi(ALine);
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					y = stoi(ALine);
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					u = stoi(ALine);
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					i = stoi(ALine);
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					o = stoi(ALine);
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.rfind(pacl, 0));
					p = stoi(ALine);
				}
			}
		ptr = new operation_order(q, w, e, r, t, y, u, i, o, p);
	}
	else if (ALine == "max_parallel_call_order")
	{
		flag = 0;
		int				e{}, r{};
		string			q{}, w{};

		subl = inputline.substr(++pos, inputline.length() - pos);
			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.find(co, 0));
				q = ALine;
				pos += ALine.length();
				subl = inputline.substr(++pos, inputline.length() - pos);
			}
			else stop = 0;
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					w = ALine;
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					e = stoi(ALine);
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.rfind(pacl, 0));
					r = stoi(ALine);
				}
			}
		ptr = new max_parallel_call_order(q, w, e, r);
	}
	else if (ALine == "max_op_order")
	{
		flag = 0;
		int				e{};
		string			q{}, w{};

		subl = inputline.substr(++pos, inputline.length() - pos);
			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.find(co, 0));
				q = ALine;
				pos += ALine.length();
				subl = inputline.substr(++pos, inputline.length() - pos);
			}
			else stop = 0;
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					w = ALine;
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.rfind(pacl, 0));
					e = stoi(ALine);
				}
			}
		ptr = new max_op_order(q, w, e);
	}
	else if (ALine == "totalmax_call_order")
	{
		flag = 0;
		int				e{};
		string			q{}, w{};

		subl = inputline.substr(++pos, inputline.length() - pos);
			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.find(co, 0));
				q = ALine;
				pos += ALine.length();
				subl = inputline.substr(++pos, inputline.length() - pos);
			}
			else stop = 0;
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					w = ALine;
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.rfind(pacl, 0));
					e = stoi(ALine);
				}
			}
		ptr = new totalmax_call_order(q, w, e);
	}
	else if (ALine == "totalmax_gross_depth")
	{
		flag = 0;
		int				e{};
		string			q{}, w{};

		subl = inputline.substr(++pos, inputline.length() - pos);
			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.find(co, 0));
				q = ALine;
				pos += ALine.length();
				subl = inputline.substr(++pos, inputline.length() - pos);
			}
			else stop = 0;
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					w = ALine;
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.rfind(pacl, 0));
					e = stoi(ALine);
				}
			}
		ptr = new totalmax_gross_depth(q, w, e);
	}
	else if (ALine == "current_total_max_order_entry")
	{
		flag = 0;
		int				q{};

		subl = inputline.substr(++pos, inputline.length() - pos);
			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.rfind(pacl, 0));
				q = stoi(ALine);
			}
		ptr = new current_total_max_order_entry(q);
	}
	else if (ALine == "module_last_state")
	{
		flag = 0;
		int				q{};

		subl = inputline.substr(++pos, inputline.length() - pos);
			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.rfind(pacl, 0));
				q = stoi(ALine);
			}
		ptr = new module_last_state(q);
	}
	else if (ALine == "module_local_list")
	{
		flag = 0;
		int				iv = 0;
		int				w{}, t{}, i{};
		string			q{}, r{}, e{}, y{}, u{}, o{};
		vector<local_object>	vobj;

		subl = inputline.substr(++pos, inputline.length() - pos);
		if ((subl.find(str, 0)) != 0)
		{
			subl = inputline.substr(++pos, inputline.length() - pos);
			//vector
			if ((subl.find(brcl, 0)) != 0)
			{
				brpos = subl.find(brcl, 0);
				while (subl.find(co, 0) < brpos && stop)
				{
					if ((subl.find(str, 0)) != 0)
					{
						params++;
						pos += 13; // 13 because   global_declerations(<<[local_object>>("linedraw",1,"constant
						brpos -= 13;
						subl = inputline.substr(pos, inputline.length() - pos);
						ALine = subl.substr(0, subl.find(co, 0));
						q = ALine;
						pos += ALine.length();
						brpos -= ALine.length();
						brpos--;
						subl = inputline.substr(++pos, inputline.length() - pos);
						ALine = subl.substr(0, subl.find(co, 0));
						w = stoi(ALine);
						pos += ALine.length();
						brpos -= ALine.length();
						brpos--;
						subl = inputline.substr(++pos, inputline.length() - pos);
						ALine = subl.substr(0, subl.find(co, 0));
						e = ALine;
						pos += ALine.length();
						brpos -= ALine.length();
						brpos--;
						subl = inputline.substr(++pos, inputline.length() - pos);
						ALine = subl.substr(0, subl.find(co, 0));
						r = ALine;
						pos += ALine.length();
						brpos -= ALine.length();
						brpos--;
						subl = inputline.substr(++pos, inputline.length() - pos);
						ALine = subl.substr(0, subl.find(co, 0));
						t = stoi(ALine);
						pos += ALine.length();
						brpos -= ALine.length();
						brpos--;
						subl = inputline.substr(++pos, inputline.length() - pos);
						ALine = subl.substr(0, subl.find(co, 0));
						y = ALine;
						pos += ALine.length();
						brpos -= ALine.length();
						brpos--;
						subl = inputline.substr(++pos, inputline.length() - pos);
						ALine = subl.substr(0, subl.find(co, 0));
						u = ALine;
						pos += ALine.length();
						brpos -= ALine.length();
						brpos--;
						subl = inputline.substr(++pos, inputline.length() - pos);
						ALine = subl.substr(0, subl.find(co, 0));
						i = stoi(ALine);
						pos += ALine.length();
						brpos -= ALine.length();
						brpos--;
						subl = inputline.substr(++pos, inputline.length() - pos);
						if (subl.find(co, 0) < brpos) //last parameter
						{
							ALine = subl.substr(0, subl.find(co, 0));
							pos += ALine.length();
							brpos -= ALine.length();
							ALine.resize(ALine.size() - 1);
							o = ALine;
							pos++;
							brpos--;
						}
						else //last
						{
							ALine = subl.substr(0, subl.find(co, 0));
							ALine.resize(ALine.size() - 3);
							o = ALine;
						}
						vobj.push_back(*(new local_object(t, w, i, q, e, y, u, r, o)));
					}
					else stop = 0;
				}
				brpos--;
				subl = inputline.substr(++pos, inputline.length() - pos);
			}
		}
		ptr = new module_local_list(vobj);
	}
	if (flag)								//exeeded the limit of nested else if
	{
		if (ALine == "module_local_list_parcs")
		{
			flag = 0;
			int				iv = 0;
			int				w{}, t{}, i{};
			string			q{}, r{}, e{}, y{}, u{}, o{};
			vector<local_object>	vobj;

			subl = inputline.substr(++pos, inputline.length() - pos);
			if ((subl.find(str, 0)) != 0)
			{
				subl = inputline.substr(++pos, inputline.length() - pos);
				//vector
				if ((subl.find(brcl, 0)) != 0)
				{
					brpos = subl.find(brcl, 0);
					while (subl.find(co, 0) < brpos && stop)
					{
						if ((subl.find(str, 0)) != 0)
						{
							params++;
							pos += 13; // 13 because   global_declerations(<<[local_object>>("linedraw",1,"constant
							brpos -= 13;
							subl = inputline.substr(pos, inputline.length() - pos);
							ALine = subl.substr(0, subl.find(co, 0));
							q = ALine;
							pos += ALine.length();
							brpos -= ALine.length();
							brpos--;
							subl = inputline.substr(++pos, inputline.length() - pos);
							ALine = subl.substr(0, subl.find(co, 0));
							w = stoi(ALine);
							pos += ALine.length();
							brpos -= ALine.length();
							brpos--;
							subl = inputline.substr(++pos, inputline.length() - pos);
							ALine = subl.substr(0, subl.find(co, 0));
							e = ALine;
							pos += ALine.length();
							brpos -= ALine.length();
							brpos--;
							subl = inputline.substr(++pos, inputline.length() - pos);
							ALine = subl.substr(0, subl.find(co, 0));
							r = ALine;
							pos += ALine.length();
							brpos -= ALine.length();
							brpos--;
							subl = inputline.substr(++pos, inputline.length() - pos);
							ALine = subl.substr(0, subl.find(co, 0));
							t = stoi(ALine);
							pos += ALine.length();
							brpos -= ALine.length();
							brpos--;
							subl = inputline.substr(++pos, inputline.length() - pos);
							ALine = subl.substr(0, subl.find(co, 0));
							y = ALine;
							pos += ALine.length();
							brpos -= ALine.length();
							brpos--;
							subl = inputline.substr(++pos, inputline.length() - pos);
							ALine = subl.substr(0, subl.find(co, 0));
							u = ALine;
							pos += ALine.length();
							brpos -= ALine.length();
							brpos--;
							subl = inputline.substr(++pos, inputline.length() - pos);
							ALine = subl.substr(0, subl.find(co, 0));
							i = stoi(ALine);
							pos += ALine.length();
							brpos -= ALine.length();
							brpos--;
							subl = inputline.substr(++pos, inputline.length() - pos);
							if (subl.find(co, 0) < brpos) //last parameter
							{
								ALine = subl.substr(0, subl.find(co, 0));
								pos += ALine.length();
								brpos -= ALine.length();
								ALine.resize(ALine.size() - 1);
								o = ALine;
								pos++;
								brpos--;
							}
							else //last
							{
								ALine = subl.substr(0, subl.find(co, 0));
								ALine.resize(ALine.size() - 3);
								o = ALine;
							}
							vobj.push_back(*(new local_object(t, w, i, q, e, y, u, r, o)));
						}
						else stop = 0;
					}
					brpos--;
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
			}
			ptr = new module_local_list_parcs(vobj);
		}
		else if (ALine == "last_non_io_found")
		{
			int				q{};

			subl = inputline.substr(++pos, inputline.length() - pos);
			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.rfind(pacl, 0));
				q = stoi(ALine);
			}
			ptr = new last_non_io_found(q);
		}
		else if (ALine == "last_local_number")
		{
			int				q{};

			subl = inputline.substr(++pos, inputline.length() - pos);
			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.rfind(pacl, 0));
				q = stoi(ALine);
			}
			ptr = new last_local_number(q);
		}
		else if (ALine == "printed_formal_ios_of_called_module")
		{
			int				w{}, e{};
			string			q{}, r{};

			subl = inputline.substr(++pos, inputline.length() - pos);
			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.find(co, 0));
				q = ALine;
				pos += ALine.length();
				subl = inputline.substr(++pos, inputline.length() - pos);
			}
			else stop = 0;
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					w = stoi(ALine);
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					e = stoi(ALine);
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.rfind(pacl, 0));
					ALine.resize(ALine.size() - 1);
					r = ALine;
				}
			}
			ptr = new printed_formal_ios_of_called_module(q, w, e, r);
		}
		else if (ALine == "it_includes_ifthen")
		{
			int				w{}, e{};
			string			q{};

			subl = inputline.substr(++pos, inputline.length() - pos);
			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.find(co, 0));
				q = ALine;
				pos += ALine.length();
				subl = inputline.substr(++pos, inputline.length() - pos);
			}
			else stop = 0;
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					w = stoi(ALine);
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.rfind(pacl, 0));
					e = stoi(ALine);
				}
			}
			ptr = new it_includes_ifthen(q, w, e);
		}
		else if (ALine == "it_includes_conditional_targeting")
		{
			int				w{}, e{};
			string			q{};

			subl = inputline.substr(++pos, inputline.length() - pos);
			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.find(co, 0));
				q = ALine;
				pos += ALine.length();
				subl = inputline.substr(++pos, inputline.length() - pos);
			}
			else stop = 0;
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					w = stoi(ALine);
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.rfind(pacl, 0));
					e = stoi(ALine);
				}
			}
			ptr = new it_includes_conditional_targeting(q, w, e);
		}
		else if (ALine == "targets_conditional_variable")
		{
			int				w{}, e{}, r{};
			string			q{};

			subl = inputline.substr(++pos, inputline.length() - pos);
			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.find(co, 0));
				q = ALine;
				pos += ALine.length();
				subl = inputline.substr(++pos, inputline.length() - pos);
			}
			else stop = 0;
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					w = stoi(ALine);
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					e = stoi(ALine);
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.rfind(pacl, 0));
					r = stoi(ALine);
				}
			}
			ptr = new targets_conditional_variable(q, w, e, r);
		}
		else if (ALine == "variable_has_been_listed")
		{
			string			q{}, w{};

			subl = inputline.substr(++pos, inputline.length() - pos);
			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.find(co, 0));
				q = ALine;
				pos += ALine.length();
				subl = inputline.substr(++pos, inputline.length() - pos);
			}
			else stop = 0;
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.rfind(pacl, 0));
					ALine.resize(ALine.size() - 1);
					w = ALine;
				}
			}
			ptr = new variable_has_been_listed(q, w);
		}
		else if (ALine == "resetstyle")
		{
			string			q{};

			subl = inputline.substr(++pos, inputline.length() - pos);
			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.rfind(pacl, 0));
				ALine.resize(ALine.size() - 1);
				q = ALine;
			}
			ptr = new resetstyle(q);
		}
		else if (ALine == "checkstyle")
		{
			string			q{};

			subl = inputline.substr(++pos, inputline.length() - pos);
			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.rfind(pacl, 0));
				ALine.resize(ALine.size() - 1);
				q = ALine;
			}
			ptr = new checkstyle(q);
		}
		else if (ALine == "total_local_entry")
		{
			int				q{};

			subl = inputline.substr(++pos, inputline.length() - pos);
			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.rfind(pacl, 0));
				q = stoi(ALine);
			}
			ptr = new total_local_entry(q);
		}
		else if (ALine == "complex_next_state_operation_depth")
		{
			int				q{};

			subl = inputline.substr(++pos, inputline.length() - pos);
			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.rfind(pacl, 0));
				q = stoi(ALine);
			}
			ptr = new complex_next_state_operation_depth(q);
		}
		else if (ALine == "output_filename")
		{
			string			q{};

			subl = inputline.substr(++pos, inputline.length() - pos);
			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.rfind(pacl, 0));
				ALine.resize(ALine.size() - 1);
				q = ALine;
			}
			ptr = new output_filename(q);
		}
		else if (ALine == "hdl_io_pass")
		{
			int				q{};

			subl = inputline.substr(++pos, inputline.length() - pos);
			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.rfind(pacl, 0));
				q = stoi(ALine);
			}
			ptr = new hdl_io_pass(q);
		}
		else if (ALine == "current_hdl_style")
		{
			string			q{};

			subl = inputline.substr(++pos, inputline.length() - pos);
			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.rfind(pacl, 0));
				ALine.resize(ALine.size() - 1);
				q = ALine;
			}
			ptr = new current_hdl_style(q);
		}
		else if (ALine == "call_ios_have_been_reset")
		{
			string			q{};

			subl = inputline.substr(++pos, inputline.length() - pos);
			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.rfind(pacl, 0));
				ALine.resize(ALine.size() - 1);
				q = ALine;
			}
			ptr = new call_ios_have_been_reset(q);
		}
		else if (ALine == "debug_mode")
		{
			int				q{};

			subl = inputline.substr(++pos, inputline.length() - pos);
			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.rfind(pacl, 0));
				q = stoi(ALine);
			}
			ptr = new debug_mode(q);
		}
		else if (ALine == "print_C_main_body")
		{
			int				q{};

			subl = inputline.substr(++pos, inputline.length() - pos);
			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.rfind(pacl, 0));
				q = stoi(ALine);
			}
			ptr = new print_C_main_body(q);
		}
		else if (ALine == "cac_mode")
		{
			int				q{};

			subl = inputline.substr(++pos, inputline.length() - pos);
			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.rfind(pacl, 0));
				q = stoi(ALine);
			}
			ptr = new cac_mode(q);
		}
		else if (ALine == "path")
		{
			int				w{}, e{};
			string			q{};

			subl = inputline.substr(++pos, inputline.length() - pos);
			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.find(co, 0));
				q = ALine;
				pos += ALine.length();
				subl = inputline.substr(++pos, inputline.length() - pos);
			}
			else stop = 0;
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					w = stoi(ALine);
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.rfind(pacl, 0));
					e = stoi(ALine);
				}
			}
			ptr = new path(q, w, e);
		}
		else if (ALine == "max_path")
		{
			int				w{};
			string			q{};

			subl = inputline.substr(++pos, inputline.length() - pos);
			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.find(co, 0));
				q = ALine;
				pos += ALine.length();
				subl = inputline.substr(++pos, inputline.length() - pos);
			}
			else stop = 0;
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.rfind(pacl, 0));
					w = stoi(ALine);
				}
			}
			ptr = new max_path(q, w);
		}
		else if (ALine == "min_path")
		{
			int				w{};
			string			q{};

			subl = inputline.substr(++pos, inputline.length() - pos);
			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.find(co, 0));
				q = ALine;
				pos += ALine.length();
				subl = inputline.substr(++pos, inputline.length() - pos);
			}
			else stop = 0;
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.rfind(pacl, 0));
					w = stoi(ALine);
				}
			}
			ptr = new min_path(q, w);
		}
		else if (ALine == "op_belongs_to_state")
		{
			int				w{}, e{}, r{};
			string			q{};

			subl = inputline.substr(++pos, inputline.length() - pos);
			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.find(co, 0));
				q = ALine;
				pos += ALine.length();
				subl = inputline.substr(++pos, inputline.length() - pos);
			}
			else stop = 0;
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					w = stoi(ALine);
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.find(co, 0));
					e = stoi(ALine);
					pos += ALine.length();
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				else stop = 0;
			}
			if (stop)
			{
				if ((subl.find(str, 0)) != 0)
				{
					params++;
					ALine = subl.substr(0, subl.rfind(pacl, 0));
					r = stoi(ALine);
				}
			}
			ptr = new op_belongs_to_state(q, w, e, r);
		}
		else if (ALine == "top_module")
		{
			string			q{};

			subl = inputline.substr(++pos, inputline.length() - pos);
			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.rfind(pacl, 0));
				ALine.resize(ALine.size() - 1);
				q = ALine;
			}
			ptr = new top_module(q);
		}
		else if (ALine == "package_name")
		{
			string			q{};

			subl = inputline.substr(++pos, inputline.length() - pos);
			if ((subl.find(str, 0)) != 0)
			{
				params++;
				ALine = subl.substr(0, subl.rfind(pacl, 0));
				ALine.resize(ALine.size() - 1);
				q = ALine;
			}
			ptr = new package_name(q);
		}
		else
		{
			GenfactError* ptr = new GenfactError("error for " + inputline);
			cout << "unable to make instance of: " << inputline << endl;
		}
	}
	return factstar(ptr, params);
}

/// @brief makes data with specific parameters (ignored in position with '_')
/// @param inputline <- the string
factUnderInspection makeInstanceOfSpecFact(string inputline)
{
	vector<vector<bool>>	paramsV;
	vector<bool>			params;
	vector<int>				vq{}, vw{}, ve{}, vr{}, vt{}, vy{};
	vector<local_object>	vobj;
	string					ALine, subl;
	size_t					pos, brpos;
	bool					flag = 1;

	GeneralFact* ptr = new GenfactError("Error line: ");

	pos = 0;
	ALine = inputline.substr(0, inputline.find(pa, 0));
	pos += ALine.length();

	if (ALine == "type_def")
	{
		flag = 0;
		int				q{}, e{}, t{}, u{}, i{}, o{};
		string			w{}, r{}, y{};
		if (inputline != ALine)
		{
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				q = stoi(ALine);
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				w = ALine;
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				e = stoi(ALine);
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				r = ALine;
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				t = stoi(ALine);
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				y = ALine;
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				u = stoi(ALine);
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				i = stoi(ALine);
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.rfind(pacl, 0));
				ALine.resize(ALine.size() - 1);
				o = stoi(ALine);
				ptr = new type_def(q, e, t, u, i, o, w, r, y);
			}
			else params.push_back(0);
		}
		ptr = new type_def(q, e, t, u, i, o, w, r, y);
	}
	else if (ALine == "op_def")
	{
		flag = 0;
		int				q{}, r{}, t{}, y{}, u{};
		string			w{}, e{};
		if (inputline != ALine)
		{
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				q = stoi(ALine);
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				w = ALine;
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				e = ALine;
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				r = stoi(ALine);
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				t = stoi(ALine);
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				y = stoi(ALine);
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.rfind(pacl, 0));
				u = stoi(ALine);
			}
			else params.push_back(0);
		}
		ptr = new op_def(q, r, t, y, u, w, e);
	}
	else if (ALine == "hierarchy_part")
	{
		flag = 0;
		int				q{}, e{}, t{}, y{}, u{};
		string			w{}, r{};
		if (inputline != ALine)
		{
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				q = stoi(ALine);
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				w = ALine;
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				e = stoi(ALine);
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				r = ALine;
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				t = stoi(ALine);
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				y = stoi(ALine);
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.rfind(pacl, 0));
				u = stoi(ALine);
			}
			else params.push_back(0);
		}
		ptr = new hierarchy_part(q, e, t, y, u, w, r);
	}
	else if (ALine == "data_stmt")
	{
		flag = 0;
		int				e{}, r{};
		string			q{}, w{}, t{}, y{};
		if (inputline != ALine)
		{
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				q = ALine;
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				w = ALine;
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				e = stoi(ALine);
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				r = stoi(ALine);
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				t = ALine;
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.rfind(pacl, 0));
				ALine.resize(ALine.size() - 1);
				y = ALine;
			}
			else params.push_back(0);
		}
		ptr = new data_stmt(e, r, q, w, t, y);
	}
	else if (ALine == "prog_stmt")
	{
		flag = 0;
		int				w{}, e{}, r{}, t{}, y{}, u{}, i{};
		string			q{};
		if (inputline != ALine)
		{
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				q = ALine;
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				w = stoi(ALine);
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				e = stoi(ALine);
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				r = stoi(ALine);
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				t = stoi(ALine);
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				y = stoi(ALine);
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				u = stoi(ALine);
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.rfind(pacl, 0));
				i = stoi(ALine);
			}
			else params.push_back(0);
		}
		ptr = new prog_stmt(w, e, r, t, y, u, i, q);
	}
	else if (ALine == "joint_stmt")
	{
		flag = 0;
		int				w{}, e{}, r{}, t{}, y{};
		string			q{};
		if (inputline != ALine)
		{
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				q = ALine;
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				w = stoi(ALine);
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				e = stoi(ALine);
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				r = stoi(ALine);
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				t = stoi(ALine);
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.rfind(pacl, 0));
				y = stoi(ALine);
			}
			else params.push_back(0);
		}
		ptr = new joint_stmt(w, e, r, t, y, q);
	}
	else if (ALine == "call_stmt")
	{
		flag = 0;
		int					w{}, e{};
		string				q{};
		if (inputline != ALine)
		{
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				q = ALine;
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				w = stoi(ALine);
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				e = stoi(ALine);
				pos += ALine.length() + 1;			// +1 to get ahead of the first bracket
			}
			else
			{
				params.push_back(0);
				++++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);
			paramsV.resize(paramsV.size() + 1);
			if ((subl.find(brcl, 0)) != 0)
			{
				//vector
				params.push_back(1);
				brpos = subl.find(brcl, 0);
				while (subl.find(co, 0) < brpos)
				{
					if (subl.find(us, 0) != 0)
					{
						paramsV[0].push_back(1);
						ALine = subl.substr(0, subl.find(co, 0));
						vq.push_back(stoi(ALine));
						pos += ALine.length();
						brpos -= ALine.length();
					}
					else
					{
						paramsV[0].push_back(0);
						vq.push_back(0);
						pos++;
						brpos--;
					}
					brpos--;
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				if (subl.find(us, 0) != 0)
				{
					ALine = subl.substr(0, brpos);
					vq.push_back(stoi(ALine));
					paramsV[0].push_back(1);
					pos += ALine.size();
				}
				else
				{
					paramsV[0].push_back(0);
					vq.push_back(0);
					pos++;
				}
			}
			else params.push_back(0);
		}
		ptr = new call_stmt(w, e, q, vq);
	}
	else if (ALine == "compo_stmt")
	{
		flag = 0;
		int				w{};
		string			q{};
		if (inputline != ALine)
		{
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				q = ALine;
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				w = stoi(ALine);
				pos += ALine.length() + 1;
			}
			else
			{
				params.push_back(0);
				++++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);
			paramsV.resize(paramsV.size() + 1);
			if ((subl.find(brcl, 0)) != 0)
			{
				//vector
				params.push_back(1);
				brpos = subl.find(brcl, 0);
				while (subl.find(co, 0) < brpos)
				{
					if (subl.find(us, 0) != 0)
					{
						paramsV[0].push_back(1);
						ALine = subl.substr(0, subl.find(co, 0));
						vq.push_back(stoi(ALine));
						pos += ALine.length();
						brpos -= ALine.length();
					}
					else
					{
						paramsV[0].push_back(0);
						vq.push_back(0);
						pos++;
						brpos--;
					}
					brpos--;
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				if (subl.find(us, 0) != 0)
				{
					ALine = subl.substr(0, brpos);
					vq.push_back(stoi(ALine));
					paramsV[0].push_back(1);
					pos += ALine.size();
				}
				else
				{
					paramsV[0].push_back(0);
					vq.push_back(0);
					pos++;
				}
			}
			else params.push_back(0);
		}
		ptr = new compo_stmt(w, q, vq);
	}
	else if (ALine == "rec_stmt")
	{
		flag = 0;
		int				w{};
		string			q{};
		if (inputline != ALine)
		{
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				q = ALine;
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				w = stoi(ALine);
				pos += ALine.length() + 1;
			}
			else
			{
				params.push_back(0);
				++++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);
			paramsV.resize(paramsV.size() + 1);
			if ((subl.find(brcl, 0)) != 0)
			{
				//vector
				params.push_back(1);
				brpos = subl.find(brcl, 0);
				while (subl.find(co, 0) < brpos)
				{
					if (subl.find(us, 0) != 0)
					{
						paramsV[0].push_back(1);
						ALine = subl.substr(0, subl.find(co, 0));
						vq.push_back(stoi(ALine));
						pos += ALine.length();
						brpos -= ALine.length();
					}
					else
					{
						paramsV[0].push_back(0);
						vq.push_back(0);
						pos++;
						brpos--;
					}
					brpos--;
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				if (subl.find(us, 0) != 0)
				{
					ALine = subl.substr(0, brpos);
					vq.push_back(stoi(ALine));
					paramsV[0].push_back(1);
					pos += ALine.size();
				}
				else
				{
					paramsV[0].push_back(0);
					vq.push_back(0);
					pos++;
				}
			}
			else params.push_back(0);
		}
		ptr = new rec_stmt(w, q, vq);
	}
	else if (ALine == "special_op")
	{
		flag = 0;
		int				w{}, r{}, t{}, y{}, i{}, o{}, p{};
		string			q{}, e{}, u{};
		if (inputline != ALine)
		{
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				q = ALine;
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				w = stoi(ALine);
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				e = ALine;
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				r = stoi(ALine);
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				t = stoi(ALine);
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				y = stoi(ALine);
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				u = ALine;
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				i = stoi(ALine);
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				o = stoi(ALine);
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.rfind(pacl, 0));
				p = stoi(ALine);
			}
			else params.push_back(0);
		}
		ptr = new special_op(w, r, t, y, i, o, p, q, e, u);
	}
	else if (ALine == "special_dt")
	{
		flag = 0;
		int				w{}, r{};
		string			q{}, e{}, t{}, y{}, u{};
		if (inputline != ALine)
		{
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				q = ALine;
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				w = stoi(ALine);
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				e = ALine;
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				r = stoi(ALine);
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				t = ALine;
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				y = ALine;
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.rfind(pacl, 0));
				ALine.resize(ALine.size() - 1);
				u = ALine;
			}
			else params.push_back(0);
		}
		ptr = new special_dt(w, r, q, e, t, y, u);
	}
	else if (ALine == "local_object")
	{
		flag = 0;
		int				w{}, i{}, t{};
		string			q{}, e{}, r{}, y{}, u{}, o{};
		if (inputline != ALine)
		{
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				q = ALine;
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				w = stoi(ALine);
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				e = ALine;
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				r = ALine;
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				t = stoi(ALine);
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				y = ALine;
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				u = ALine;
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				i = stoi(ALine);
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.rfind(pacl, 0));
				ALine.resize(ALine.size() - 1);
				o = ALine;
			}
			else params.push_back(0);
		}
		ptr = new local_object(t, w, i, q, e, y, u, r, o);
	}
	else if (ALine == "state_node")
	{
		flag = 0;				// use do while
		int				w{}, e{}, r{};
		string			q{};
		bool			flag2 = true;
		if (inputline != ALine)
		{
			subl = inputline.substr(++pos, inputline.length() - pos);
			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				q = ALine;
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				pos++;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				w = stoi(ALine);
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				pos++;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				ALine = subl.substr(0, subl.find(pa, 0));
				if (subl == ALine)
				{
					params.push_back(1);
					flag2 = false;
					ALine.resize(ALine.size() - 1);
				}
				if (ALine == "subprogram_call")
				{
					if (flag2)
					{
						pos += ALine.size();	//passing the first bracket 
						subl = inputline.substr(++++pos, inputline.length() - pos);
						params.push_back(1);
						paramsV.resize(paramsV.size() + 1);
						//vector
						if ((subl.find(brcl, 0)) != 0)
						{
							params.push_back(1);
							brpos = subl.find(brcl, 0);
							while (subl.find(co, 0) < brpos)
							{
								if (subl.find(us, 0) != 0)
								{
									paramsV[0].push_back(1);
									ALine = subl.substr(0, subl.find(co, 0));
									vq.push_back(stoi(ALine));
									pos += ALine.length();
									brpos -= ALine.length();
								}
								else
								{
									paramsV[0].push_back(0);
									vq.push_back(0);
									pos++;
									brpos--;
								}
								brpos--;
								subl = inputline.substr(++pos, inputline.length() - pos);
							}
							if (subl.find(us, 0) != 0)
							{
								ALine = subl.substr(0, brpos);
								pos += ALine.length() + 1;
								vq.push_back(stoi(ALine));
								paramsV[0].push_back(1);
							}
							else
							{
								paramsV[0].push_back(0);
								vq.push_back(0);
								pos += 2;
							}
						}
						else
						{
							params.push_back(0);
							subl = inputline.substr(++pos, inputline.length() - pos);
						}
						subl = inputline.substr(++pos, inputline.length() - pos);

						if ((subl.find(us, 0)) != 0)
						{
							params.push_back(1);
							ALine = subl.substr(0, subl.find(pacl, 0));
							e = stoi(ALine);
						}
						else params.push_back(0);
					}
					ptr = new subprogram_call(e, vq, w, q);
				}
				else if (ALine == "dataflow")
				{
					if (flag2)
					{
						pos += ALine.size();	//passing the first bracket 
						subl = inputline.substr(++++pos, inputline.length() - pos);
						if (subl.find(pacl, 0) != 0)
						{
							params.push_back(1);
							paramsV.resize(paramsV.size() + 1);
							//vector
							if ((subl.find(brcl, 0)) != 0)
							{
								params.push_back(1);
								brpos = subl.find(brcl, 0);
								while (subl.find(co, 0) < brpos)
								{
									if (subl.find(us, 0) != 0)
									{
										paramsV[0].push_back(1);
										ALine = subl.substr(0, subl.find(co, 0));
										vq.push_back(stoi(ALine));
										pos += ALine.length();
										brpos -= ALine.length();
									}
									else
									{
										paramsV[0].push_back(0);
										vq.push_back(0);
										pos++;
										brpos--;
									}
									brpos--;
									subl = inputline.substr(++pos, inputline.length() - pos);
								}
								if (subl.find(us, 0) != 0)
								{
									ALine = subl.substr(0, brpos);
									pos += ALine.length() + 1;
									vq.push_back(stoi(ALine));
									paramsV[0].push_back(1);
								}
								else
								{
									paramsV[0].push_back(0);
									vq.push_back(0);
									pos += 2;
								}
							}
							else
							{
								params.push_back(0);
								subl = inputline.substr(++pos, inputline.length() - pos);
							}
							subl = inputline.substr(++pos, inputline.length() - pos);

							if ((subl.find(us, 0)) != 0)
							{
								params.push_back(1);
								ALine = subl.substr(0, subl.find(pacl, 0));
								e = stoi(ALine);
							}
							else params.push_back(0);
						}
						else params.push_back(0);
					}
					ptr = new dataflow(e, vq, w, q);
				}
				else if (ALine == "ifthen")
				{
					if (flag2)
					{
						pos += ALine.size();	//passing the first bracket 
						subl = inputline.substr(++++pos, inputline.length() - pos);
						params.push_back(1);
						paramsV.resize(paramsV.size() + 3);
						//vector
						if ((subl.find(brcl, 0)) != 0)
						{
							params.push_back(1);
							brpos = subl.find(brcl, 0);
							while (subl.find(co, 0) < brpos)
							{
								if (subl.find(us, 0) != 0)
								{
									paramsV[0].push_back(1);
									ALine = subl.substr(0, subl.find(co, 0));
									vq.push_back(stoi(ALine));
									pos += ALine.length();
									brpos -= ALine.length();
								}
								else
								{
									paramsV[0].push_back(0);
									vq.push_back(0);
									pos++;
									brpos--;
								}
								brpos--;
								subl = inputline.substr(++pos, inputline.length() - pos);
							}
							if (subl.find(us, 0) != 0)
							{
								ALine = subl.substr(0, brpos);
								pos += ALine.length() + 1;
								vq.push_back(stoi(ALine));
								paramsV[0].push_back(1);
							}
							else
							{
								paramsV[0].push_back(0);
								vq.push_back(0);
								pos += 2;
							}
						}
						else
						{
							params.push_back(0);
							pos++;
						}
						subl = inputline.substr(++++pos, inputline.length() - pos);

						//vector2
						if ((subl.find(brcl, 0)) != 0)
						{
							params.push_back(1);
							brpos = subl.find(brcl, 0);
							while (subl.find(co, 0) < brpos)
							{
								if (subl.find(us, 0) != 0)
								{
									paramsV[1].push_back(1);
									ALine = subl.substr(0, subl.find(co, 0));
									vw.push_back(stoi(ALine));
									pos += ALine.length();
									brpos -= ALine.length();
								}
								else
								{
									paramsV[1].push_back(0);
									vw.push_back(0);
									pos++;
									brpos--;
								}
								brpos--;
								subl = inputline.substr(++pos, inputline.length() - pos);
							}
							if (subl.find(us, 0) != 0)
							{
								ALine = subl.substr(0, brpos);
								vw.push_back(stoi(ALine));
								paramsV[1].push_back(1);
								pos += ALine.size() + 1;
							}
							else
							{
								paramsV[1].push_back(0);
								vw.push_back(0);
								pos += 2;
							}
						}
						else
						{
							params.push_back(0);
							pos++;
						}

						subl = inputline.substr(++++pos, inputline.length() - pos);

						//vector3
						if ((subl.find(brcl, 0)) != 0)
						{
							params.push_back(1);
							brpos = subl.find(brcl, 0);
							while (subl.find(co, 0) < brpos)
							{
								if (subl.find(us, 0) != 0)
								{
									paramsV[2].push_back(1);
									ALine = subl.substr(0, subl.find(co, 0));
									ve.push_back(stoi(ALine));
									pos += ALine.length();
									brpos -= ALine.length();
								}
								else
								{
									paramsV[2].push_back(0);
									ve.push_back(0);
									pos++;
									brpos--;
								}
								brpos--;
								subl = inputline.substr(++pos, inputline.length() - pos);
							}
							if (subl.find(us, 0) != 0)
							{
								ALine = subl.substr(0, brpos);
								ve.push_back(stoi(ALine));
								paramsV[2].push_back(1);
								pos += ALine.size();
							}
							else
							{
								paramsV[2].push_back(0);
								ve.push_back(0);
								pos++;
							}
						}
						else params.push_back(0);
						subl = inputline.substr(++++pos, inputline.length() - pos);

						if ((subl.find(us, 0)) != 0)
						{
							params.push_back(1);
							subl = inputline.substr(pos, inputline.length() - pos);
							ALine = subl.substr(0, subl.find(co, 0));
							e = stoi(ALine);
							pos += ALine.length();
						}
						else
						{
							params.push_back(0);
							++pos;
						}
						subl = inputline.substr(++pos, inputline.length() - pos);

						if ((subl.find(us, 0)) != 0)
						{
							params.push_back(1);

							ALine = subl.substr(0, subl.rfind(pacl, 0));
							r = stoi(ALine);
							pos += ALine.length();
						}
						else params.push_back(0);
					}
					ptr = new ifthen(e, r, vq, vw, ve, w, q);
				}
				else if (ALine == "jump")
				{
					if (flag2)
					{
						pos += ALine.size();	//passing the first bracket 
						subl = inputline.substr(++++pos, inputline.length() - pos);
						if (subl.find(pacl, 0) != 0)
						{
							params.push_back(1);
							paramsV.resize(paramsV.size() + 1);
							//vector
							if ((subl.find(brcl, 0)) != 0)
							{
								params.push_back(1);
								brpos = subl.find(brcl, 0);
								while (subl.find(co, 0) < brpos)
								{
									if (subl.find(us, 0) != 0)
									{
										paramsV[0].push_back(1);
										ALine = subl.substr(0, subl.find(co, 0));
										vq.push_back(stoi(ALine));
										pos += ALine.length();
										brpos -= ALine.length();
									}
									else
									{
										paramsV[0].push_back(0);
										vq.push_back(0);
										pos++;
										brpos--;
									}
									brpos--;
									subl = inputline.substr(++pos, inputline.length() - pos);
								}
								if (subl.find(us, 0) != 0)
								{
									ALine = subl.substr(0, brpos);
									pos += ALine.length() + 1;
									vq.push_back(stoi(ALine));
									paramsV[0].push_back(1);
								}
								else
								{
									paramsV[0].push_back(0);
									vq.push_back(0);
									pos += 2;
								}
							}
							else
							{
								params.push_back(0);
								subl = inputline.substr(++pos, inputline.length() - pos);
							}
							subl = inputline.substr(++pos, inputline.length() - pos);

							if ((subl.find(us, 0)) != 0)
							{
								params.push_back(1);
								ALine = subl.substr(0, subl.find(pacl, 0));
								e = stoi(ALine);
							}
							else params.push_back(0);
						}
						else params.push_back(0);
					}
					ptr = new jump(e, vq, w, q);
				}
				else if (ALine == "return")
				{
					if (flag2)
					{
						pos += ALine.size();	//passing the first bracket 
						subl = inputline.substr(++++pos, inputline.length() - pos);
						params.push_back(1);
						paramsV.resize(paramsV.size() + 1);
						//vector
						if ((subl.find(brcl, 0)) != 0)
						{
							params.push_back(1);
							brpos = subl.find(brcl, 0);
							while (subl.find(co, 0) < brpos)
							{
								if (subl.find(us, 0) != 0)
								{
									paramsV[0].push_back(1);
									ALine = subl.substr(0, subl.find(co, 0));
									vq.push_back(stoi(ALine));
									pos += ALine.length();
									brpos -= ALine.length();
								}
								else
								{
									paramsV[0].push_back(0);
									vq.push_back(0);
									pos++;
									brpos--;
								}
								brpos--;
								subl = inputline.substr(++pos, inputline.length() - pos);
							}
							if (subl.find(us, 0) != 0)
							{
								ALine = subl.substr(0, brpos);
								pos += ALine.length() + 1;
								vq.push_back(stoi(ALine));
								paramsV[0].push_back(1);
							}
							else
							{
								paramsV[0].push_back(0);
								vq.push_back(0);
								pos += 2;
							}
						}
						else
						{
							params.push_back(0);
							subl = inputline.substr(++pos, inputline.length() - pos);
						}
					}
					ptr = new return_cos(vq, w, q);
				}
			}
			else
			{
				params.push_back(0);
				ptr = new state_node(w, q);
			}
		}
		else ptr = new state_node(w, q);
	}
	else if (ALine == "change_op_number")
	{
		flag = 0;
		int				w{}, e{};
		string			q{};
		if (inputline != ALine)
		{
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				q = ALine;
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				w = stoi(ALine);
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.rfind(pacl, 0));
				e = stoi(ALine);
			}
			else params.push_back(0);
		}
		ptr = new change_op_number(e, w, q);
	}
	else if (ALine == "last_change_op_number")
	{
		flag = 0;
		int				w{}, e{};
		string			q{};
		if (inputline != ALine)
		{
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				q = ALine;
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				w = stoi(ALine);
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.rfind(pacl, 0));
				e = stoi(ALine);
			}
			else params.push_back(0);
		}
		ptr = new last_change_op_number(e, w, q);
	}
	else if (ALine == "op_guards")
	{
		flag = 0;
		int				w{};
		string			q{};
		if (inputline != ALine)
		{
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				q = ALine;
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				w = stoi(ALine);
				pos += ALine.length() + 1;
			}
			else
			{
				params.push_back(0);
				++++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);
			paramsV.resize(paramsV.size() + 2);
			if ((subl.find(brcl, 0)) != 0)
			{
				//vector
				params.push_back(1);
				brpos = subl.find(brcl, 0);
				while (subl.find(co, 0) < brpos)
				{
					if (subl.find(us, 0) != 0)
					{
						paramsV[0].push_back(1);
						ALine = subl.substr(0, subl.find(co, 0));
						vq.push_back(stoi(ALine));
						pos += ALine.length();
						brpos -= ALine.length();
					}
					else
					{
						paramsV[0].push_back(0);
						vq.push_back(0);
						pos++;
						brpos--;
					}
					brpos--;
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				if (subl.find(us, 0) != 0)
				{
					ALine = subl.substr(0, brpos);
					vq.push_back(stoi(ALine));
					paramsV[0].push_back(1);
					pos += ALine.size();
				}
				else
				{
					paramsV[0].push_back(0);
					vq.push_back(0);
					pos++;
				}
			}
			else params.push_back(0);
			subl = inputline.substr(++++++pos, inputline.length() - pos);

			//vector2
			if ((subl.find(brcl, 0)) != 0)
			{
				params.push_back(1);
				brpos = subl.find(brcl, 0);
				while (subl.find(co, 0) < brpos)
				{
					if (subl.find(us, 0) != 0)
					{
						paramsV[1].push_back(1);
						ALine = subl.substr(0, subl.find(co, 0));
						vw.push_back(stoi(ALine));
						pos += ALine.length();
						brpos -= ALine.length();
					}
					else
					{
						paramsV[1].push_back(0);
						vw.push_back(0);
						pos++;
						brpos--;
					}
					brpos--;
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				if (subl.find(us, 0) != 0)
				{
					ALine = subl.substr(0, brpos);
					vw.push_back(stoi(ALine));
					paramsV[1].push_back(1);
					pos += ALine.size();
				}
				else
				{
					paramsV[1].push_back(0);
					vw.push_back(0);
					pos++;
				}
			}
			else params.push_back(0);

		}
		ptr = new op_guards(w, q, vq, vw);
	}
	else if (ALine == "var_guards")
	{
		flag = 0;
		int				w{};
		string			q{};
		if (inputline != ALine)
		{
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				q = ALine;
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				w = stoi(ALine);
				pos += ALine.length() + 1;
			}
			else
			{
				params.push_back(0);
				++++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			paramsV.resize(paramsV.size() + 2);
			if ((subl.find(brcl, 0)) != 0)
			{
				//vector
				params.push_back(1);
				brpos = subl.find(brcl, 0);
				while (subl.find(co, 0) < brpos)
				{
					if (subl.find(us, 0) != 0)
					{
						paramsV[0].push_back(1);
						ALine = subl.substr(0, subl.find(co, 0));
						vq.push_back(stoi(ALine));
						pos += ALine.length();
						brpos -= ALine.length();
					}
					else
					{
						paramsV[0].push_back(0);
						vq.push_back(0);
						pos++;
						brpos--;
					}
					brpos--;
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				if (subl.find(us, 0) != 0)
				{
					ALine = subl.substr(0, brpos);
					vq.push_back(stoi(ALine));
					paramsV[0].push_back(1);
					pos += ALine.size();
				}
				else
				{
					paramsV[0].push_back(0);
					vq.push_back(0);
					pos++;
				}
			}
			else params.push_back(0);
			subl = inputline.substr(++++++pos, inputline.length() - pos);

			//vector2
			if ((subl.find(brcl, 0)) != 0)
			{
				params.push_back(1);
				brpos = subl.find(brcl, 0);
				while (subl.find(co, 0) < brpos)
				{
					if (subl.find(us, 0) != 0)
					{
						paramsV[1].push_back(1);
						ALine = subl.substr(0, subl.find(co, 0));
						vw.push_back(stoi(ALine));
						pos += ALine.length();
						brpos -= ALine.length();
					}
					else
					{
						paramsV[1].push_back(0);
						vw.push_back(0);
						pos++;
						brpos--;
					}
					brpos--;
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				if (subl.find(us, 0) != 0)
				{
					ALine = subl.substr(0, brpos);
					vw.push_back(stoi(ALine));
					paramsV[1].push_back(1);
					pos += ALine.size();
				}
				else
				{
					paramsV[1].push_back(0);
					vw.push_back(0);
					pos++;
				}
			}
			else params.push_back(0);
		}
		ptr = new var_guards(w, q, vq, vw);
	}
	else if (ALine == "guard_pair")
	{
		flag = 0;
		int				w{}, e{};
		string			q{}, r{};
		if (inputline != ALine)
		{
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				q = ALine;
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				w = stoi(ALine);
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				e = stoi(ALine);
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.rfind(pacl, 0));
				ALine.resize(ALine.size() - 1);
				r = ALine;
			}
			else params.push_back(0);
		}
		ptr = new guard_pair(w, e, q, r);
	}
	else if (ALine == "guard_cond")
	{
		flag = 0;
		int				w{}, e{};
		string			q{}, r{};
		if (inputline != ALine)
		{
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				q = ALine;
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				w = stoi(ALine);
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				e = stoi(ALine);
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.rfind(pacl, 0));
				ALine.resize(ALine.size() - 1);
				r = ALine;
			}
			else params.push_back(0);
		}
		ptr = new guard_cond(w, e, q, r);
	}
	else if (ALine == "predecessors")
	{
		vq.clear();
		flag = 0;
		int				w{};
		string			q{};
		if (inputline != ALine)
		{
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				q = ALine;
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				w = stoi(ALine);
				pos += ALine.length() + 1;
			}
			else
			{
				params.push_back(0);
				++++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);
			paramsV.resize(paramsV.size() + 1);
			//vector
			if ((subl.find(brcl, 0)) != 0)
			{
				params.push_back(1);
				brpos = subl.find(brcl, 0);
				while (subl.find(co, 0) < brpos)
				{
					if (subl.find(us, 0) != 0)
					{
						paramsV[0].push_back(1);
						ALine = subl.substr(0, subl.find(co, 0));
						vq.push_back(stoi(ALine));
						pos += ALine.length();
						brpos -= ALine.length();
					}
					else
					{
						paramsV[0].push_back(0);
						vq.push_back(0);
						pos++;
						brpos--;
					}
					brpos--;
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				if (subl.find(us, 0) != 0)
				{
					ALine = subl.substr(0, brpos);
					vq.push_back(stoi(ALine));
					paramsV[0].push_back(1);
					pos += ALine.size();
				}
				else
				{
					paramsV[0].push_back(0);
					vq.push_back(0);
					pos++;
				}
			}
			else params.push_back(0);
		}
		ptr = new predecessors(w, q, vq);
	}
	else if (ALine == "cessor")
	{
		flag = 0;
		int				w{}, e{};
		string			q{};
		if (inputline != ALine)
		{
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				q = ALine;
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				w = stoi(ALine);
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.rfind(pacl, 0));
				e = stoi(ALine);
			}
			else params.push_back(0);
		}
		ptr = new cessor(w, e, q);
	}
	else if (ALine == "cessor_kind")
	{
		vq.clear();
		flag = 0;
		int				e{}, r{};
		string			q{}, w{}, t{}, y{};
		if (inputline != ALine)
		{
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				q = ALine;
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				w = ALine;
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				e = stoi(ALine);
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				r = stoi(ALine);
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				t = ALine;
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				y = ALine;
				pos += ALine.length() + 1;
			}
			else
			{
				params.push_back(0);
				++++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);
			paramsV.resize(paramsV.size() + 1);
			//vector
			if ((subl.find(brcl, 0)) != 0)
			{
				params.push_back(1);
				brpos = subl.find(brcl, 0);
				while (subl.find(co, 0) < brpos)
				{
					if (subl.find(us, 0) != 0)
					{
						paramsV[0].push_back(1);
						ALine = subl.substr(0, subl.find(co, 0));
						vq.push_back(stoi(ALine));
						pos += ALine.length();
						brpos -= ALine.length();
					}
					else
					{
						paramsV[0].push_back(0);
						vq.push_back(0);
						pos++;
						brpos--;
					}
					brpos--;
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				if (subl.find(us, 0) != 0)
				{
					ALine = subl.substr(0, brpos);
					vq.push_back(stoi(ALine));
					paramsV[0].push_back(1);
					pos += ALine.size();
				}
				else
				{
					paramsV[0].push_back(0);
					vq.push_back(0);
					pos++;
				}
			}
			else params.push_back(0);
		}
		ptr = new cessor_kind(e, r, q, w, t, y, vq);
	}
	else if (ALine == "old_schedule")
	{
		flag = 0;
		string			q{};
		if (inputline != ALine)
		{
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.rfind(pacl, 0));
				ALine.resize(ALine.size() - 1);
				q = ALine;
			}
			else params.push_back(0);
		}
		ptr = new old_schedule(q);
	}
	else if (ALine == "new_schedule")
	{
		flag = 0;
		string			q{};
		if (inputline != ALine)
		{
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.rfind(pacl, 0));
				ALine.resize(ALine.size() - 1);
				q = ALine;
			}
			else params.push_back(0);
		}
		ptr = new new_schedule(q);
	}
	else if (ALine == "local_ifthen_chain_end_operations_were_written")
	{
		flag = 0;
		int				q{};
		if (inputline != ALine)
		{
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.rfind(pacl, 0));
				ALine.resize(ALine.size() - 1);
				q = stoi(ALine);
			}
			else params.push_back(0);
		}
		ptr = new local_ifthen_chain_end_operations_were_written(q);
	}
	else if (ALine == "calls_list")
	{
		vq.clear();
		flag = 0;
		int				w{}, e{};
		string			q{};
		if (inputline != ALine)
		{
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				q = ALine;
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				w = stoi(ALine);
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				e = stoi(ALine);
				pos += ALine.length() + 1;
			}
			else
			{
				params.push_back(0);
				++++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);
			paramsV.resize(paramsV.size() + 1);
			//vector
			if ((subl.find(brcl, 0)) != 0)
			{
				params.push_back(1);
				brpos = subl.find(brcl, 0);
				while (subl.find(co, 0) < brpos)
				{
					if (subl.find(us, 0) != 0)
					{
						paramsV[0].push_back(1);
						ALine = subl.substr(0, subl.find(co, 0));
						vq.push_back(stoi(ALine));
						pos += ALine.length();
						brpos -= ALine.length();
					}
					else
					{
						paramsV[0].push_back(0);
						vq.push_back(0);
						pos++;
						brpos--;
					}
					brpos--;
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				if (subl.find(us, 0) != 0)
				{
					ALine = subl.substr(0, brpos);
					vq.push_back(stoi(ALine));
					paramsV[0].push_back(1);
					pos += ALine.size();
				}
				else
				{
					paramsV[0].push_back(0);
					vq.push_back(0);
					pos++;
				}
			}
			else params.push_back(0);
		}
		ptr = new calls_list(q, w, e, vq);
	}
	else if (ALine == "composites_list")
	{
		flag = 0;
		int				w{};
		string			q{};
		if (inputline != ALine)
		{
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				q = ALine;
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				w = stoi(ALine);
				pos += ALine.length() + 1;
			}
			else
			{
				params.push_back(0);
				++++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);
			paramsV.resize(paramsV.size() + 1);
			//vector
			if ((subl.find(brcl, 0)) != 0)
			{
				params.push_back(1);
				brpos = subl.find(brcl, 0);
				while (subl.find(co, 0) < brpos)
				{
					if (subl.find(us, 0) != 0)
					{
						paramsV[0].push_back(1);
						ALine = subl.substr(0, subl.find(co, 0));
						vq.push_back(stoi(ALine));
						pos += ALine.length();
						brpos -= ALine.length();
					}
					else
					{
						paramsV[0].push_back(0);
						vq.push_back(0);
						pos++;
						brpos--;
					}
					brpos--;
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				if (subl.find(us, 0) != 0)
				{
					ALine = subl.substr(0, brpos);
					vq.push_back(stoi(ALine));
					paramsV[0].push_back(1);
					pos += ALine.size();
				}
				else
				{
					paramsV[0].push_back(0);
					vq.push_back(0);
					pos++;
				}
			}
			else params.push_back(0);
		}
		ptr = new composites_list(q, w, vq);
	}
	else if (ALine == "record_aggregates_list")
	{
		flag = 0;
		int				w{};
		string			q{};
		if (inputline != ALine)
		{
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				q = ALine;
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				w = stoi(ALine);
				pos += ALine.length() + 1;
			}
			else
			{
				params.push_back(0);
				++++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);
			paramsV.resize(paramsV.size() + 1);
			//vector
			if ((subl.find(brcl, 0)) != 0)
			{
				params.push_back(1);
				brpos = subl.find(brcl, 0);
				while (subl.find(co, 0) < brpos)
				{
					if (subl.find(us, 0) != 0)
					{
						paramsV[0].push_back(1);
						ALine = subl.substr(0, subl.find(co, 0));
						vq.push_back(stoi(ALine));
						pos += ALine.length();
						brpos -= ALine.length();
					}
					else
					{
						paramsV[0].push_back(0);
						vq.push_back(0);
						pos++;
						brpos--;
					}
					brpos--;
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				if (subl.find(us, 0) != 0)
				{
					ALine = subl.substr(0, brpos);
					vq.push_back(stoi(ALine));
					paramsV[0].push_back(1);
					pos += ALine.size();
				}
				else
				{
					paramsV[0].push_back(0);
					vq.push_back(0);
					pos++;
				}
			}
			else params.push_back(0);
		}
		ptr = new record_aggregates_list(q, w, vq);
	}
	else if (ALine == "mem_port")
	{
		flag = 0;
		int				q{}, y{}, i{}, s{};
		string			w{}, e{}, r{}, t{}, u{}, o{}, p{}, a{}, d{};
		if (inputline != ALine)
		{
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				q = stoi(ALine);
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				w = ALine;
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				e = ALine;
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				r = ALine;
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				t = ALine;
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				y = stoi(ALine);
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				u = ALine;
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				i = stoi(ALine);
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				o = ALine;
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				p = ALine;
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				a = ALine;
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				s = stoi(ALine);
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.rfind(pacl, 0));
				ALine.resize(ALine.size() - 1);
				d = ALine;
			}
			else params.push_back(0);
		}
		ptr = new mem_port(q, w, e, r, t, y, u, i, o, p, a, s, d);
	}
	else if (ALine == "global_declarations")
	{
		flag = 0;
		int						iv = 0;
		int						w{}, t{}, i{}, p{};
		string					q{}, e{}, r{}, y{}, u{}, o{};
		if (inputline != ALine)
		{
			subl = inputline.substr(++++pos, inputline.length() - pos);
			//vector
			if ((subl.find(brcl, 0)) != 0)
			{
				brpos = subl.find(brcl, 0);
				params.push_back(1);
				while (subl.find(co, 0) < brpos)
				{
					paramsV.resize(paramsV.size() + 1);

					if (subl.find(us, 0) != 0) // check up for the subfact
					{
						pos += 13; // 13 because   global_declerations(<<[local_object>>("linedraw",1,"constant
						brpos -= 13;
						subl = inputline.substr(pos, inputline.length() - pos);
						if (subl.find(us, 0) != 0) // check up for the first parameter of this subfact
						{
							paramsV[iv].push_back(1);
							ALine = subl.substr(0, subl.find(co, 0));
							q = ALine;
							pos += ALine.length();
							brpos -= ALine.length();
						}
						else
						{
							paramsV[iv].push_back(0);
							pos++;
							brpos--;
						}
						brpos--;
						subl = inputline.substr(++pos, inputline.length() - pos);

						if (subl.find(us, 0) != 0)
						{
							paramsV[iv].push_back(1);
							ALine = subl.substr(0, subl.find(co, 0));
							w = stoi(ALine);
							pos += ALine.length();
							brpos -= ALine.length();
						}
						else
						{
							paramsV[iv].push_back(0);
							pos++;
							brpos--;
						}
						brpos--;
						subl = inputline.substr(++pos, inputline.length() - pos);

						if (subl.find(us, 0) != 0)
						{
							paramsV[iv].push_back(1);
							ALine = subl.substr(0, subl.find(co, 0));
							e = ALine;
							pos += ALine.length();
							brpos -= ALine.length();
						}
						else
						{
							paramsV[iv].push_back(0);
							pos++;
							brpos--;
						}
						brpos--;
						subl = inputline.substr(++pos, inputline.length() - pos);

						if (subl.find(us, 0) != 0)
						{
							paramsV[iv].push_back(1);
							ALine = subl.substr(0, subl.find(co, 0));
							r = ALine;
							pos += ALine.length();
							brpos -= ALine.length();
						}
						else
						{
							paramsV[iv].push_back(0);
							pos++;
							brpos--;
						}
						brpos--;
						subl = inputline.substr(++pos, inputline.length() - pos);

						if (subl.find(us, 0) != 0)
						{
							paramsV[iv].push_back(1);
							ALine = subl.substr(0, subl.find(co, 0));
							t = stoi(ALine);
							pos += ALine.length();
							brpos -= ALine.length();
						}
						else
						{
							paramsV[iv].push_back(0);
							pos++;
							brpos--;
						}
						brpos--;
						subl = inputline.substr(++pos, inputline.length() - pos);

						if (subl.find(us, 0) != 0)
						{
							paramsV[iv].push_back(1);
							ALine = subl.substr(0, subl.find(co, 0));
							y = ALine;
							pos += ALine.length();
							brpos -= ALine.length();
						}
						else
						{
							paramsV[iv].push_back(0);
							pos++;
							brpos--;
						}
						brpos--;
						subl = inputline.substr(++pos, inputline.length() - pos);

						if (subl.find(us, 0) != 0)
						{
							paramsV[iv].push_back(1);
							ALine = subl.substr(0, subl.find(co, 0));
							u = ALine;
							pos += ALine.length();
							brpos -= ALine.length();
						}
						else
						{
							paramsV[iv].push_back(0);
							pos++;
							brpos--;
						}
						brpos--;
						subl = inputline.substr(++pos, inputline.length() - pos);

						if (subl.find(us, 0) != 0)
						{
							paramsV[iv].push_back(1);
							ALine = subl.substr(0, subl.find(co, 0));
							i = stoi(ALine);
							pos += ALine.length();
							brpos -= ALine.length();
						}
						else
						{
							paramsV[iv].push_back(0);
							pos++;
							brpos--;
						}
						brpos--;
						subl = inputline.substr(++pos, inputline.length() - pos);

						if (subl.find(co, 0) < brpos) //last parameter
						{
							if (subl.find(us, 0) != 0)
							{
								paramsV[iv].push_back(1);
								ALine = subl.substr(0, subl.find(co, 0));
								pos += ALine.length();
								brpos -= ALine.length();
								ALine.resize(ALine.size() - 1);
								o = ALine;
							}
							else
							{
								paramsV[iv].push_back(0);
								pos += 2;
								brpos -= 2;
							}
						}
						else //last
						{
							if (subl.find(us, 0) != 0)
							{
								paramsV[iv].push_back(1);
								ALine = subl.substr(0, subl.find(co, 0));
								pos += ALine.length();
								ALine.resize(ALine.size() - 2);
								brpos -= ALine.length();
								o = ALine;
							}
							else
							{
								paramsV[iv].push_back(0);
								pos += 3;
								brpos--;
							}
						}
						vobj.push_back(*(new local_object(t, w, i, q, e, y, u, r, o)));
					}
					else
					{
						vobj.push_back(*(new local_object(t, w, i, q, e, y, u, r, o)));
					}
					brpos--;
					subl = inputline.substr(++pos, inputline.length() - pos);
					iv++;
				}
			}
			else
			{
				params.push_back(0);
				pos += 2;
				subl = inputline.substr(pos, inputline.length() - pos);
			}
			if (subl.find(us, 0) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				p = stoi(ALine);
			}
			else params.push_back(0);
		}
		ptr = new global_declarations(vobj, p);
	}
	else if (ALine == "source_is_normal_dt")
	{
		flag = 0;
		int				w{}, e{};
		string			q{};
		if (inputline != ALine)
		{
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				q = ALine;
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				w = stoi(ALine);
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.rfind(pacl, 0));
				e = stoi(ALine);
			}
			else params.push_back(0);
		}
		ptr = new source_is_normal_dt(q, w, e);
	}
	else if (ALine == "combo")
	{
		flag = 0;
		int				q{}, e{};
		string			w{};
		if (inputline != ALine)
		{
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				q = stoi(ALine);
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				w = ALine;
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.rfind(pacl, 0));
				e = stoi(ALine);
			}
			else params.push_back(0);
		}
		ptr = new combo(q, w, e);
	}
	else if (ALine == "sequence")
	{
		flag = 0;
		int				q{}, e{};
		string			w{};
		if (inputline != ALine)
		{
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				q = stoi(ALine);
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				w = ALine;
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.rfind(pacl, 0));
				e = stoi(ALine);
			}
			else params.push_back(0);
		}
		ptr = new sequence(q, w, e);
	}
	else if (ALine == "for_loop")
	{
		flag = 0;
		int				q{}, e{}, r{}, t{}, y{}, u{}, i{}, o{}, p{}, a{}, s{}, d{};
		string			w{};
		if (inputline != ALine)
		{
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				q = stoi(ALine);
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				w = ALine;
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				e = stoi(ALine);
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				r = stoi(ALine);
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				t = stoi(ALine);
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				y = stoi(ALine);
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				u = stoi(ALine);
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				i = stoi(ALine);
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				o = stoi(ALine);
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				p = stoi(ALine);
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				a = stoi(ALine);
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				s = stoi(ALine);
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.rfind(pacl, 0));
				d = stoi(ALine);
			}
			else params.push_back(0);
		}
		ptr = new for_loop(q, w, e, r, t, y, u, i, o, p, a, s, d);
	}
	else if (ALine == "last_for_loop_entry")
	{
		flag = 0;
		int				q{};
		if (inputline != ALine)
		{
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.rfind(pacl, 0));
				q = stoi(ALine);
			}
			else params.push_back(0);
		}
		ptr = new last_for_loop_entry(q);
	}
	else if (ALine == "while_loop")
	{
		flag = 0;
		int				q{}, e{}, r{}, t{}, y{}, u{};
		string			w{};
		if (inputline != ALine)
		{
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				q = stoi(ALine);
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				w = ALine;
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				e = stoi(ALine);
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				r = stoi(ALine);
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				t = stoi(ALine);
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				y = stoi(ALine);
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.rfind(pacl, 0));
				u = stoi(ALine);
			}
			else params.push_back(0);
		}
		ptr = new while_loop(q, w, e, r, t, y, u);
	}
	else if (ALine == "last_while_loop_entry")
	{
		flag = 0;
		int				q{};
		if (inputline != ALine)
		{
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.rfind(pacl, 0));
				q = stoi(ALine);
			}
			else params.push_back(0);
		}
		ptr = new last_for_loop_entry(q);
	}
	else if (ALine == "possible_end_if")
	{
		flag = 0;
		string			q{};
		if (inputline != ALine)
		{
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				q = ALine;
				pos += ALine.length() + 1;
			}
			else
			{
				params.push_back(0);
				++++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);
			paramsV.resize(paramsV.size() + 1);
			if ((subl.find(brcl, 0)) != 0)
			{
				//vector
				params.push_back(1);
				brpos = subl.find(brcl, 0);
				while (subl.find(co, 0) < brpos)
				{
					if (subl.find(us, 0) != 0)
					{
						paramsV[0].push_back(1);
						ALine = subl.substr(0, subl.find(co, 0));
						vq.push_back(stoi(ALine));
						pos += ALine.length();
						brpos -= ALine.length();
					}
					else
					{
						paramsV[0].push_back(0);
						vq.push_back(0);
						pos++;
						brpos--;
					}
					brpos--;
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				if (subl.find(us, 0) != 0)
				{
					ALine = subl.substr(0, brpos);
					vq.push_back(stoi(ALine));
					paramsV[0].push_back(1);
					pos += ALine.size();
				}
				else
				{
					paramsV[0].push_back(0);
					vq.push_back(0);
					pos++;
				}
			}
			else params.push_back(0);
		}
		ptr = new possible_end_if(q, vq);
	}
	else if (ALine == "end_if")
	{
		vq.clear();
		flag = 0;
		string			q{};
		if (inputline != ALine)
		{
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				q = ALine;
				pos += ALine.length() + 1;
			}
			else
			{
				params.push_back(0);
				++++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);
			paramsV.resize(paramsV.size() + 1);
			if ((subl.find(brcl, 0)) != 0)
			{
				//vector
				params.push_back(1);
				brpos = subl.find(brcl, 0);
				while (subl.find(co, 0) < brpos)
				{
					if (subl.find(us, 0) != 0)
					{
						paramsV[0].push_back(1);
						ALine = subl.substr(0, subl.find(co, 0));
						vq.push_back(stoi(ALine));
						pos += ALine.length();
						brpos -= ALine.length();
					}
					else
					{
						paramsV[0].push_back(0);
						vq.push_back(0);
						pos++;
						brpos--;
					}
					brpos--;
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				if (subl.find(us, 0) != 0)
				{
					ALine = subl.substr(0, brpos);
					vq.push_back(stoi(ALine));
					paramsV[0].push_back(1);
					pos += ALine.size();
				}
				else
				{
					paramsV[0].push_back(0);
					vq.push_back(0);
					pos++;
				}
			}
			else params.push_back(0);
		}
		ptr = new end_if(q, vq);
	}
	else if (ALine == "nested_cond_fact")
	{
		vq.clear();
		flag = 0;
		string			q{};
		if (inputline != ALine)
		{
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				q = ALine;
				pos += ALine.length() + 1;
			}
			else
			{
				params.push_back(0);
				++++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);
			paramsV.resize(paramsV.size() + 1);
			if ((subl.find(brcl, 0)) != 0)
			{
				//vector
				params.push_back(1);
				brpos = subl.find(brcl, 0);
				while (subl.find(co, 0) < brpos)
				{
					if (subl.find(us, 0) != 0)
					{
						paramsV[0].push_back(1);
						ALine = subl.substr(0, subl.find(co, 0));
						vq.push_back(stoi(ALine));
						pos += ALine.length();
						brpos -= ALine.length();
					}
					else
					{
						paramsV[0].push_back(0);
						vq.push_back(0);
						pos++;
						brpos--;
					}
					brpos--;
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				if (subl.find(us, 0) != 0)
				{
					ALine = subl.substr(0, brpos);
					vq.push_back(stoi(ALine));
					paramsV[0].push_back(1);
					pos += ALine.size();
				}
				else
				{
					paramsV[0].push_back(0);
					vq.push_back(0);
					pos++;
				}
			}
			else params.push_back(0);
		}
		ptr = new nested_cond_fact(q, vq);
	}
	else if (ALine == "top_level_call")
	{
		flag = 0;
		int				q{}, w{}, r{}, y{}, i{}, p{};
		string			e{}, t{}, u{}, o{}, a{};
		if (inputline != ALine)
		{
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				q = stoi(ALine);
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				w = stoi(ALine);
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				e = ALine;
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				r = stoi(ALine);
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				t = ALine;
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				y = stoi(ALine);
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				u = ALine;
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				i = stoi(ALine);
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				o = ALine;
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				p = stoi(ALine);
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.rfind(pacl, 0));
				ALine.resize(ALine.size() - 1);
				a = ALine;
			}
			else params.push_back(0);
		}
		ptr = new top_level_call(q, w, e, r, t, y, u, i, o, p, a);
	}
	else if (ALine == "top_level_call_parcs")
	{
		flag = 0;
		int				q{}, w{}, r{}, y{}, i{}, p{};
		string			e{}, t{}, u{}, o{}, a{};
		if (inputline != ALine)
		{
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				q = stoi(ALine);
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				w = stoi(ALine);
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				e = ALine;
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				r = stoi(ALine);
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				t = ALine;
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				y = stoi(ALine);
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				u = ALine;
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				i = stoi(ALine);
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				o = ALine;
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				p = stoi(ALine);
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.rfind(pacl, 0));
				ALine.resize(ALine.size() - 1);
				a = ALine;
			}
			else params.push_back(0);
		}
		ptr = new top_level_call_parcs(q, w, e, r, t, y, u, i, o, p, a);
	}
	else if (ALine == "added_aux_call_ios")
	{
		flag = 0;
		int				w{};
		string			q{};
		if (inputline != ALine)
		{
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				q = ALine;
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.rfind(pacl, 0));
				w = stoi(ALine);
			}
			else params.push_back(0);
		}
		ptr = new added_aux_call_ios(q, w);
	}
	else if (ALine == "added_aux_call_ios1")
	{
		flag = 0;
		int				w{}, e{};
		string			q{};
		if (inputline != ALine)
		{
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				q = ALine;
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				w = stoi(ALine);
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.rfind(pacl, 0));
				e = stoi(ALine);
			}
			else params.push_back(0);
		}
		ptr = new added_aux_call_ios1(q, w, e);
	}
	else if (ALine == "added_aux_call_signals")
	{
		flag = 0;
		int				w{};
		string			q{};
		if (inputline != ALine)
		{
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				q = ALine;
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.rfind(pacl, 0));
				w = stoi(ALine);
			}
			else params.push_back(0);
		}
		ptr = new added_aux_call_signals(q, w);
	}
	else if (ALine == "found_call_operator")
	{
		flag = 0;
		int				w{};
		string			q{};
		if (inputline != ALine)
		{
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				q = ALine;
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.rfind(pacl, 0));
				w = stoi(ALine);
			}
			else params.push_back(0);
		}
		ptr = new found_call_operator(q, w);
	}
	else if (ALine == "added_verilog_aux_call_outputs")
	{
		flag = 0;
		int				w{};
		string			q{}, e{};
		if (inputline != ALine)
		{
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				q = ALine;
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				w = stoi(ALine);
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.rfind(pacl, 0));
				ALine.resize(ALine.size() - 1);
				e = ALine;
			}
			else params.push_back(0);
		}
		ptr = new added_verilog_aux_call_outputs(q, w, e);
	}
	else if (ALine == "raw_dependencies")
	{
		flag = 0;
		int				w{};
		string			q{};
		if (inputline != ALine)
		{
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				q = ALine;
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				w = stoi(ALine);
				pos += ALine.length() + 1;
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);
			paramsV.resize(paramsV.size() + 2);
			if ((subl.find(brcl, 0)) != 0)
			{
				//vector
				params.push_back(1);
				brpos = subl.find(brcl, 0);
				while (subl.find(co, 0) < brpos)
				{
					if (subl.find(us, 0) != 0)
					{
						paramsV[0].push_back(1);
						ALine = subl.substr(0, subl.find(co, 0));
						vq.push_back(stoi(ALine));
						pos += ALine.length();
						brpos -= ALine.length();
					}
					else
					{
						paramsV[0].push_back(0);
						vq.push_back(0);
						pos++;
						brpos--;
					}
					brpos--;
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				if (subl.find(us, 0) != 0)
				{
					ALine = subl.substr(0, brpos);
					vq.push_back(stoi(ALine));
					paramsV[0].push_back(1);
					pos += ALine.size();
				}
				else
				{
					paramsV[0].push_back(0);
					vq.push_back(0);
					pos++;
				}
			}
			else params.push_back(0);
			subl = inputline.substr(++++++pos, inputline.length() - pos);

			if ((subl.find(brcl, 0)) != 0)
			{
				//vector2
				params.push_back(1);
				brpos = subl.find(brcl, 0);
				while (subl.find(co, 0) < brpos)
				{
					if (subl.find(us, 0) != 0)
					{
						paramsV[1].push_back(1);
						ALine = subl.substr(0, subl.find(co, 0));
						vw.push_back(stoi(ALine));
						pos += ALine.length();
						brpos -= ALine.length();
					}
					else
					{
						paramsV[1].push_back(0);
						vw.push_back(0);
						pos++;
						brpos--;
					}
					brpos--;
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				if (subl.find(us, 0) != 0)
				{
					ALine = subl.substr(0, brpos);
					vw.push_back(stoi(ALine));
					paramsV[1].push_back(1);
					pos += ALine.size();
				}
				else
				{
					paramsV[1].push_back(0);
					vw.push_back(0);
					pos++;
				}
			}
			else params.push_back(0);
		}
		ptr = new raw_dependencies(q, w, vq, vw);
	}
	else if (ALine == "war_dependencies")
	{
		flag = 0;
		int				w{};
		string			q{};
		if (inputline != ALine)
		{
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				q = ALine;
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				w = stoi(ALine);
				pos += ALine.length() + 1;
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);
			paramsV.resize(paramsV.size() + 2);
			if ((subl.find(brcl, 0)) != 0)
			{
				//vector
				params.push_back(1);
				brpos = subl.find(brcl, 0);
				while (subl.find(co, 0) < brpos)
				{
					if (subl.find(us, 0) != 0)
					{
						paramsV[0].push_back(1);
						ALine = subl.substr(0, subl.find(co, 0));
						vq.push_back(stoi(ALine));
						pos += ALine.length();
						brpos -= ALine.length();
					}
					else
					{
						paramsV[0].push_back(0);
						vq.push_back(0);
						pos++;
						brpos--;
					}
					brpos--;
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				if (subl.find(us, 0) != 0)
				{
					ALine = subl.substr(0, brpos);
					vq.push_back(stoi(ALine));
					paramsV[0].push_back(1);
					pos += ALine.size();
				}
				else
				{
					paramsV[0].push_back(0);
					vq.push_back(0);
					pos++;
				}
			}
			else params.push_back(0);
			subl = inputline.substr(++++++pos, inputline.length() - pos);

			if ((subl.find(brcl, 0)) != 0)
			{
				//vector2
				params.push_back(1);
				brpos = subl.find(brcl, 0);
				while (subl.find(co, 0) < brpos)
				{
					if (subl.find(us, 0) != 0)
					{
						paramsV[1].push_back(1);
						ALine = subl.substr(0, subl.find(co, 0));
						vw.push_back(stoi(ALine));
						pos += ALine.length();
						brpos -= ALine.length();
					}
					else
					{
						paramsV[1].push_back(0);
						vw.push_back(0);
						pos++;
						brpos--;
					}
					brpos--;
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				if (subl.find(us, 0) != 0)
				{
					ALine = subl.substr(0, brpos);
					vw.push_back(stoi(ALine));
					paramsV[1].push_back(1);
					pos += ALine.size();
				}
				else
				{
					paramsV[1].push_back(0);
					vw.push_back(0);
					pos++;
				}
			}
			else params.push_back(0);
		}
		ptr = new war_dependencies(q, w, vq, vw);
	}
	else if (ALine == "waw_dependencies")
	{
		flag = 0;
		int				w{};
		string			q{};
		if (inputline != ALine)
		{
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				q = ALine;
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				w = stoi(ALine);
				pos += ALine.length() + 1;
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);
			paramsV.resize(paramsV.size() + 2);
			if ((subl.find(brcl, 0)) != 0)
			{
				//vector
				params.push_back(1);
				brpos = subl.find(brcl, 0);
				while (subl.find(co, 0) < brpos)
				{
					if (subl.find(us, 0) != 0)
					{
						paramsV[0].push_back(1);
						ALine = subl.substr(0, subl.find(co, 0));
						vq.push_back(stoi(ALine));
						pos += ALine.length();
						brpos -= ALine.length();
					}
					else
					{
						paramsV[0].push_back(0);
						vq.push_back(0);
						pos++;
						brpos--;
					}
					brpos--;
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				if (subl.find(us, 0) != 0)
				{
					ALine = subl.substr(0, brpos);
					vq.push_back(stoi(ALine));
					paramsV[0].push_back(1);
					pos += ALine.size();
				}
				else
				{
					paramsV[0].push_back(0);
					vq.push_back(0);
					pos++;
				}
			}
			else params.push_back(0);
			subl = inputline.substr(++++++pos, inputline.length() - pos);

			if ((subl.find(brcl, 0)) != 0)
			{
				//vector2
				params.push_back(1);
				brpos = subl.find(brcl, 0);
				while (subl.find(co, 0) < brpos)
				{
					if (subl.find(us, 0) != 0)
					{
						paramsV[1].push_back(1);
						ALine = subl.substr(0, subl.find(co, 0));
						vw.push_back(stoi(ALine));
						pos += ALine.length();
						brpos -= ALine.length();
					}
					else
					{
						paramsV[1].push_back(0);
						vw.push_back(0);
						pos++;
						brpos--;
					}
					brpos--;
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				if (subl.find(us, 0) != 0)
				{
					ALine = subl.substr(0, brpos);
					vw.push_back(stoi(ALine));
					paramsV[1].push_back(1);
					pos += ALine.size();
				}
				else
				{
					paramsV[1].push_back(0);
					vw.push_back(0);
					pos++;
				}
			}
			else params.push_back(0);
		}
		ptr = new waw_dependencies(q, w, vq, vw);
	}
	else if (ALine == "schedule")
	{
		flag = 0;
		int				w{}, r{};
		string			q{}, e{};
		if (inputline != ALine)
		{
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				q = ALine;
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				w = stoi(ALine);
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				e = ALine;
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				r = stoi(ALine);
			}
			else params.push_back(0);
		}
		ptr = new schedule(q, w, e, r);
	}
	else if (ALine == "last_conditional_execution")
	{
		flag = 0;
		int				w{};
		string			q{};
		if (inputline != ALine)
		{
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				q = ALine;
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.rfind(pacl, 0));
				w = stoi(ALine);
			}
			else params.push_back(0);
		}
		ptr = new last_conditional_execution(q, w);
	}
	else if (ALine == "conditional_operations")
	{
		flag = 0;
		int				e{}, r{};
		string			q{}, w{};
		if (inputline != ALine)
		{
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				q = ALine;
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				w = ALine;
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				e = stoi(ALine);
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				r = stoi(ALine);
				pos += ALine.length() + 1;
			}
			else
			{
				params.push_back(0);
				++++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);
			paramsV.resize(paramsV.size() + 4);
			if ((subl.find(brcl, 0)) != 0)
			{
				//vector
				params.push_back(1);
				brpos = subl.find(brcl, 0);
				while (subl.find(co, 0) < brpos)
				{
					if (subl.find(us, 0) != 0)
					{
						paramsV[0].push_back(1);
						ALine = subl.substr(0, subl.find(co, 0));
						vq.push_back(stoi(ALine));
						pos += ALine.length();
						brpos -= ALine.length();
					}
					else
					{
						paramsV[0].push_back(0);
						vq.push_back(0);
						pos++;
						brpos--;
					}
					brpos--;
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				if (subl.find(us, 0) != 0)
				{
					ALine = subl.substr(0, brpos);
					vq.push_back(stoi(ALine));
					paramsV[0].push_back(1);
					pos += ALine.size();
				}
				else
				{
					paramsV[0].push_back(0);
					vq.push_back(0);
					pos++;
				}
			}
			else params.push_back(0);
			subl = inputline.substr(++++++pos, inputline.length() - pos);

			if ((subl.find(brcl, 0)) != 0)
			{
				//vector2
				params.push_back(1);
				brpos = subl.find(brcl, 0);
				while (subl.find(co, 0) < brpos)
				{
					if (subl.find(us, 0) != 0)
					{
						paramsV[1].push_back(1);
						ALine = subl.substr(0, subl.find(co, 0));
						vw.push_back(stoi(ALine));
						pos += ALine.length();
						brpos -= ALine.length();
					}
					else
					{
						paramsV[1].push_back(0);
						vw.push_back(0);
						pos++;
						brpos--;
					}
					brpos--;
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				if (subl.find(us, 0) != 0)
				{
					ALine = subl.substr(0, brpos);
					vw.push_back(stoi(ALine));
					paramsV[1].push_back(1);
					pos += ALine.size();
				}
				else
				{
					paramsV[1].push_back(0);
					vw.push_back(0);
					pos++;
				}
			}
			else params.push_back(0);
			subl = inputline.substr(++++++pos, inputline.length() - pos);

			if ((subl.find(brcl, 0)) != 0)
			{
				//vector3
				params.push_back(1);
				brpos = subl.find(brcl, 0);
				while (subl.find(co, 0) < brpos)
				{
					if (subl.find(us, 0) != 0)
					{
						paramsV[2].push_back(1);
						ALine = subl.substr(0, subl.find(co, 0));
						ve.push_back(stoi(ALine));
						pos += ALine.length();
						brpos -= ALine.length();
					}
					else
					{
						paramsV[2].push_back(0);
						ve.push_back(0);
						pos++;
						brpos--;
					}
					brpos--;
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				if (subl.find(us, 0) != 0)
				{
					ALine = subl.substr(0, brpos);
					ve.push_back(stoi(ALine));
					paramsV[2].push_back(1);
					pos += ALine.size();
				}
				else
				{
					paramsV[2].push_back(0);
					ve.push_back(0);
					pos++;
				}
			}
			else params.push_back(0);
			subl = inputline.substr(++++++pos, inputline.length() - pos);

			if ((subl.find(brcl, 0)) != 0)
			{
				//vector4
				params.push_back(1);
				brpos = subl.find(brcl, 0);
				while (subl.find(co, 0) < brpos)
				{
					if (subl.find(us, 0) != 0)
					{
						paramsV[3].push_back(1);
						ALine = subl.substr(0, subl.find(co, 0));
						vr.push_back(stoi(ALine));
						pos += ALine.length();
						brpos -= ALine.length();
					}
					else
					{
						paramsV[3].push_back(0);
						vr.push_back(0);
						pos++;
						brpos--;
					}
					brpos--;
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				if (subl.find(us, 0) != 0)
				{
					ALine = subl.substr(0, brpos);
					vr.push_back(stoi(ALine));
					paramsV[3].push_back(1);
					pos += ALine.size();
				}
				else
				{
					paramsV[3].push_back(0);
					vr.push_back(0);
					pos++;
				}
			}
			else params.push_back(0);
		}
		ptr = new conditional_operations(q, w, e, r, vq, vw, ve, vr);
	}
	else if (ALine == "last_conditional_transition_of_schedule")
	{
		flag = 0;
		int				e{};
		string			q{}, w{};
		if (inputline != ALine)
		{
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				q = ALine;
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				w = ALine;
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.rfind(pacl, 0));
				e = stoi(ALine);
			}
			else params.push_back(0);
		}
		ptr = new last_conditional_transition_of_schedule(q, w, e);
	}
	else if (ALine == "transition_to_be_rescheduled")
	{
		flag = 0;
		int				e{}, t{};
		string			q{}, w{}, r{};
		if (inputline != ALine)
		{
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				q = ALine;
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				w = ALine;
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				e = stoi(ALine);
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				r = ALine;
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.rfind(pacl, 0));
				t = stoi(ALine);
			}
			else params.push_back(0);
		}
		ptr = new transition_to_be_rescheduled(w, e, q, r, t);
	}
	else if (ALine == "last_conditional_transition")
	{
		flag = 0;
		int				w{};
		string			q{};
		if (inputline != ALine)
		{
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				q = ALine;
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.rfind(pacl, 0));
				w = stoi(ALine);
			}
			else params.push_back(0);
		}
		ptr = new last_conditional_transition(q, w);
	}
	else if (ALine == "conditional_transitions")
	{
		flag = 0;
		int				e{}, r{}, t{}, y{}, u{}, i{};
		string			q{}, w{};
		if (inputline != ALine)
		{
			subl = inputline.substr(++pos, inputline.length() - pos);
			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				q = ALine;
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				w = ALine;
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				e = stoi(ALine);
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				r = stoi(ALine);
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				t = stoi(ALine);
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				y = stoi(ALine);
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				u = stoi(ALine);
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.rfind(pacl, 0));
				i = stoi(ALine);
			}
			else params.push_back(0);
		}
		ptr = new conditional_transitions(q, w, e, r, t, y, u, i);
	}
	else if (ALine == "state")
	{
		vq.clear();
		vw.clear();
		flag = 0;
		int				e{}, t{}, y{};
		string			q{}, w{}, r{};
		if (inputline != ALine)
		{
			subl = inputline.substr(++pos, inputline.length() - pos);
			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				q = ALine;
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				w = ALine;
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				e = stoi(ALine);
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				r = ALine;
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				t = stoi(ALine);
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				y = stoi(ALine);
				pos += ALine.length() + 1;
			}
			else
			{
				params.push_back(0);
				++++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);
			paramsV.resize(paramsV.size() + 2);
			if ((subl.find(brcl, 0)) != 0)
			{
				//vector
				params.push_back(1);
				brpos = subl.find(brcl, 0);
				while (subl.find(co, 0) < brpos)
				{
					if (subl.find(us, 0) != 0)
					{
						paramsV[0].push_back(1);
						ALine = subl.substr(0, subl.find(co, 0));
						vq.push_back(stoi(ALine));
						pos += ALine.length();
						brpos -= ALine.length();
					}
					else
					{
						paramsV[0].push_back(0);
						vq.push_back(0);
						pos++;
						brpos--;
					}
					brpos--;
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				if (subl.find(us, 0) != 0)
				{
					ALine = subl.substr(0, brpos);
					vq.push_back(stoi(ALine));
					paramsV[0].push_back(1);
					pos += ALine.size();
				}
				else
				{
					paramsV[0].push_back(0);
					vq.push_back(0);
					pos++;
				}
			}
			else params.push_back(0);
			subl = inputline.substr(++++++pos, inputline.length() - pos);

			if ((subl.find(brcl, 0)) != 0)
			{
				//vector2
				params.push_back(1);
				brpos = subl.find(brcl, 0);
				while (subl.find(co, 0) < brpos)
				{
					if (subl.find(us, 0) != 0)
					{
						paramsV[1].push_back(1);
						ALine = subl.substr(0, subl.find(co, 0));
						vw.push_back(stoi(ALine));
						pos += ALine.length();
						brpos -= ALine.length();
					}
					else
					{
						paramsV[1].push_back(0);
						vw.push_back(0);
						pos++;
						brpos--;
					}
					brpos--;
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				if (subl.find(us, 0) != 0)
				{
					ALine = subl.substr(0, brpos);
					vw.push_back(stoi(ALine));
					paramsV[1].push_back(1);
					pos += ALine.size();
				}
				else
				{
					paramsV[1].push_back(0);
					vw.push_back(0);
					pos++;
				}
			}
			else params.push_back(0);
		}
		ptr = new state(q, w, e, r, t, y, vq, vw);
	}
	else if (ALine == "rescheduled")
	{
		flag = 0;
		int				e{}, t{};
		string			q{}, w{}, r{};
		if (inputline != ALine)
		{
			subl = inputline.substr(++pos, inputline.length() - pos);
			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				q = ALine;
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				w = ALine;
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				e = stoi(ALine);
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				r = ALine;
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.rfind(pacl, 0));
				t = stoi(ALine);
			}
			else params.push_back(0);
		}
		ptr = new rescheduled(w, e, q, r, t);
	}
	else if (ALine == "last_rescheduled")
	{
		flag = 0;
		int				e{}, t{};
		string			q{}, w{}, r{};
		if (inputline != ALine)
		{
			subl = inputline.substr(++pos, inputline.length() - pos);
			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				q = ALine;
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				w = ALine;
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				e = stoi(ALine);
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				r = ALine;
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.rfind(pacl, 0));
				t = stoi(ALine);
			}
			else params.push_back(0);
		}
		ptr = new last_rescheduled(w, e, q, r, t);
	}
	else if (ALine == "raw_cessor")
	{
		flag = 0;
		int				w{}, e{};
		string			q{};
		if (inputline != ALine)
		{
			subl = inputline.substr(++pos, inputline.length() - pos);
			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				q = ALine;
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				w = stoi(ALine);
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.rfind(pacl, 0));
				e = stoi(ALine);
			}
			else params.push_back(0);
		}
		ptr = new raw_cessor(q, w, e);
	}
	else if (ALine == "war_cessor")
	{
		flag = 0;
		int				w{}, e{};
		string			q{};
		if (inputline != ALine)
		{
			subl = inputline.substr(++pos, inputline.length() - pos);
			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				q = ALine;
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				w = stoi(ALine);
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.rfind(pacl, 0));
				e = stoi(ALine);
			}
			else params.push_back(0);
		}
		ptr = new war_cessor(q, w, e);
	}
	else if (ALine == "waw_cessor")
	{
		flag = 0;
		int				w{}, e{};
		string			q{};
		if (inputline != ALine)
		{
			subl = inputline.substr(++pos, inputline.length() - pos);
			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				q = ALine;
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				w = stoi(ALine);
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.rfind(pacl, 0));
				e = stoi(ALine);
			}
			else params.push_back(0);
		}
		ptr = new waw_cessor(q, w, e);
	}
	else if (ALine == "op_resource")
	{
		flag = 0;
		int				e{};
		string			q{}, w{};
		if (inputline != ALine)
		{
			subl = inputline.substr(++pos, inputline.length() - pos);
			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				q = ALine;
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				w = ALine;
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.rfind(pacl, 0));
				e = stoi(ALine);
			}
			else params.push_back(0);
		}
		ptr = new op_resource(q, w, e);
	}
	else if (ALine == "global_resource")
	{
		flag = 0;
		int				q{};
		if (inputline != ALine)
		{
			subl = inputline.substr(++pos, inputline.length() - pos);
			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.rfind(pacl, 0));
				q = stoi(ALine);
			}
			else params.push_back(0);
		}
		ptr = new global_resource(q);
	}
	else if (ALine == "module_g_resource")
	{
		flag = 0;
		int				w{};
		string			q{};
		if (inputline != ALine)
		{
			subl = inputline.substr(++pos, inputline.length() - pos);
			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				q = ALine;
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.rfind(pacl, 0));
				w = stoi(ALine);
			}
			else params.push_back(0);
		}
		ptr = new module_g_resource(q, w);
	}
	else if (ALine == "cf_previous_op")
	{
		flag = 0;
		int				w{}, e{}, r{};
		string			q{};
		if (inputline != ALine)
		{
			subl = inputline.substr(++pos, inputline.length() - pos);
			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				q = ALine;
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				w = stoi(ALine);
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				e = stoi(ALine);
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.rfind(pacl, 0));
				r = stoi(ALine);
			}
			else params.push_back(0);
		}
		ptr = new cf_previous_op(q, w, e, r);
	}
	else if (ALine == "cf_previous_state")
	{
		flag = 0;
		int				w{}, e{}, r{};
		string			q{};
		if (inputline != ALine)
		{
			subl = inputline.substr(++pos, inputline.length() - pos);
			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				q = ALine;
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				w = stoi(ALine);
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				e = stoi(ALine);
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.rfind(pacl, 0));
				r = stoi(ALine);
			}
			else params.push_back(0);
		}
		ptr = new cf_previous_state(q, w, e, r);
	}
	else if (ALine == "pred_candidate_examined")
	{
		flag = 0;
		int				w{}, e{};
		string			q{};
		if (inputline != ALine)
		{
			subl = inputline.substr(++pos, inputline.length() - pos);
			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				q = ALine;
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				w = stoi(ALine);
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.rfind(pacl, 0));
				e = stoi(ALine);
			}
			else params.push_back(0);
		}
		ptr = new pred_candidate_examined(q, w, e);
	}
	else if (ALine == "reentrant_triangle")
	{
		flag = 0;
		int				w{}, e{}, r{}, a{}, s{};
		string			q{}, d{}, f{};
		if (inputline != ALine)
		{
			subl = inputline.substr(++pos, inputline.length() - pos);
			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				q = ALine;
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				w = stoi(ALine);
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				e = stoi(ALine);
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				r = stoi(ALine);
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++++pos, inputline.length() - pos);
			paramsV.resize(paramsV.size() + 6);
			if ((subl.find(brcl, 0)) != 0)
			{
				//vector
				params.push_back(1);
				brpos = subl.find(brcl, 0);
				while (subl.find(co, 0) < brpos)
				{
					if (subl.find(us, 0) != 0)
					{
						paramsV[0].push_back(1);
						ALine = subl.substr(0, subl.find(co, 0));
						vq.push_back(stoi(ALine));
						pos += ALine.length();
						brpos -= ALine.length();
					}
					else
					{
						paramsV[0].push_back(0);
						vq.push_back(0);
						pos++;
						brpos--;
					}
					brpos--;
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				if (subl.find(us, 0) != 0)
				{
					ALine = subl.substr(0, brpos);
					vq.push_back(stoi(ALine));
					paramsV[0].push_back(1);
					pos += ALine.size();
				}
				else
				{
					paramsV[0].push_back(0);
					vq.push_back(0);
					pos++;
				}
			}
			else params.push_back(0);
			subl = inputline.substr(++++++pos, inputline.length() - pos);

			if ((subl.find(brcl, 0)) != 0)
			{
				//vector2
				params.push_back(1);
				brpos = subl.find(brcl, 0);
				while (subl.find(co, 0) < brpos)
				{
					if (subl.find(us, 0) != 0)
					{
						paramsV[1].push_back(1);
						ALine = subl.substr(0, subl.find(co, 0));
						vw.push_back(stoi(ALine));
						pos += ALine.length();
						brpos -= ALine.length();
					}
					else
					{
						paramsV[1].push_back(0);
						vw.push_back(0);
						pos++;
						brpos--;
					}
					brpos--;
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				if (subl.find(us, 0) != 0)
				{
					ALine = subl.substr(0, brpos);
					vw.push_back(stoi(ALine));
					paramsV[1].push_back(1);
					pos += ALine.size();
				}
				else
				{
					paramsV[1].push_back(0);
					vw.push_back(0);
					pos++;
				}
			}
			else params.push_back(0);
			subl = inputline.substr(++++++pos, inputline.length() - pos);

			if ((subl.find(brcl, 0)) != 0)
			{
				//vector3
				params.push_back(1);
				brpos = subl.find(brcl, 0);
				while (subl.find(co, 0) < brpos)
				{
					if (subl.find(us, 0) != 0)
					{
						paramsV[2].push_back(1);
						ALine = subl.substr(0, subl.find(co, 0));
						ve.push_back(stoi(ALine));
						pos += ALine.length();
						brpos -= ALine.length();
					}
					else
					{
						paramsV[2].push_back(0);
						ve.push_back(0);
						pos++;
						brpos--;
					}
					brpos--;
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				if (subl.find(us, 0) != 0)
				{
					ALine = subl.substr(0, brpos);
					ve.push_back(stoi(ALine));
					paramsV[2].push_back(1);
					pos += ALine.size();
				}
				else
				{
					paramsV[2].push_back(0);
					ve.push_back(0);
					pos++;
				}
			}
			else params.push_back(0);
			subl = inputline.substr(++++++pos, inputline.length() - pos);

			if ((subl.find(brcl, 0)) != 0)
			{
				//vector4
				params.push_back(1);
				brpos = subl.find(brcl, 0);
				while (subl.find(co, 0) < brpos)
				{
					if (subl.find(us, 0) != 0)
					{
						paramsV[3].push_back(1);
						ALine = subl.substr(0, subl.find(co, 0));
						vr.push_back(stoi(ALine));
						pos += ALine.length();
						brpos -= ALine.length();
					}
					else
					{
						paramsV[3].push_back(0);
						vr.push_back(0);
						pos++;
						brpos--;
					}
					brpos--;
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				if (subl.find(us, 0) != 0)
				{
					ALine = subl.substr(0, brpos);
					vr.push_back(stoi(ALine));
					paramsV[3].push_back(1);
					pos += ALine.size();
				}
				else
				{
					paramsV[3].push_back(0);
					vr.push_back(0);
					pos++;
				}
			}
			else params.push_back(0);
			subl = inputline.substr(++++++pos, inputline.length() - pos);

			if ((subl.find(brcl, 0)) != 0)
			{
				//vector5
				params.push_back(1);
				brpos = subl.find(brcl, 0);
				while (subl.find(co, 0) < brpos)
				{
					if (subl.find(us, 0) != 0)
					{
						paramsV[4].push_back(1);
						ALine = subl.substr(0, subl.find(co, 0));
						vt.push_back(stoi(ALine));
						pos += ALine.length();
						brpos -= ALine.length();
					}
					else
					{
						paramsV[4].push_back(0);
						vt.push_back(0);
						pos++;
						brpos--;
					}
					brpos--;
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				if (subl.find(us, 0) != 0)
				{
					ALine = subl.substr(0, brpos);
					vt.push_back(stoi(ALine));
					paramsV[4].push_back(1);
					pos += ALine.size();
				}
				else
				{
					paramsV[4].push_back(0);
					vt.push_back(0);
					pos++;
				}
			}
			else params.push_back(0);
			subl = inputline.substr(++++++pos, inputline.length() - pos);

			if ((subl.find(brcl, 0)) != 0)
			{
				//vector6
				params.push_back(1);
				brpos = subl.find(brcl, 0);
				while (subl.find(co, 0) < brpos)
				{
					if (subl.find(us, 0) != 0)
					{
						paramsV[5].push_back(1);
						ALine = subl.substr(0, subl.find(co, 0));
						vy.push_back(stoi(ALine));
						pos += ALine.length();
						brpos -= ALine.length();
					}
					else
					{
						paramsV[5].push_back(0);
						vy.push_back(0);
						pos++;
						brpos--;
					}
					brpos--;
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				if (subl.find(us, 0) != 0)
				{
					ALine = subl.substr(0, brpos);
					vy.push_back(stoi(ALine));
					paramsV[5].push_back(1);
					pos += ALine.size();
				}
				else
				{
					paramsV[5].push_back(0);
					vy.push_back(0);
					pos++;
				}
			}
			else params.push_back(0);
			subl = inputline.substr(++++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				a = stoi(ALine);
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				s = stoi(ALine);
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				d = ALine;
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				ALine.resize(ALine.size() - 1);
				f = ALine;
			}
			else params.push_back(0);
		}
		ptr = new reentrant_triangle(q, w, e, r, vq, vw, ve, vr, vt, vy, a, s, d, f);
	}
	else if (ALine == "last_reentrant_triangle")
	{
		flag = 0;
		int				w{};
		string			q{};
		if (inputline != ALine)
		{
			subl = inputline.substr(++pos, inputline.length() - pos);
			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				q = ALine;
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.rfind(pacl, 0));
				w = stoi(ALine);
			}
			else params.push_back(0);
		}
		ptr = new last_reentrant_triangle(q, w);
	}
	else if (ALine == "last_schedule_state")
	{
		flag = 0;
		int				e{};
		string			q{}, w{};
		if (inputline != ALine)
		{
			subl = inputline.substr(++pos, inputline.length() - pos);
			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				q = ALine;
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				w = ALine;
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.rfind(pacl, 0));
				e = stoi(ALine);
			}
			else params.push_back(0);
		}
		ptr = new last_schedule_state(q, w, e);
	}
	else if (ALine == "conditional_incomplete")
	{
		flag = 0;
		int				e{}, r{}, a{}, s{}, d{}, f{}, g{}, h{}, j{}, k{}, l{}, z{}, x{};
		string			q{}, w{};
		if (inputline != ALine)
		{
			subl = inputline.substr(++pos, inputline.length() - pos);
			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				q = ALine;
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				w = ALine;
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				e = stoi(ALine);
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				r = stoi(ALine);
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++++pos, inputline.length() - pos);
			paramsV.resize(paramsV.size() + 6);
			if ((subl.find(brcl, 0)) != 0)
			{
				//vector
				params.push_back(1);
				brpos = subl.find(brcl, 0);
				while (subl.find(co, 0) < brpos)
				{
					if (subl.find(us, 0) != 0)
					{
						paramsV[0].push_back(1);
						ALine = subl.substr(0, subl.find(co, 0));
						vq.push_back(stoi(ALine));
						pos += ALine.length();
						brpos -= ALine.length();
					}
					else
					{
						paramsV[0].push_back(0);
						vq.push_back(0);
						pos++;
						brpos--;
					}
					brpos--;
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				if (subl.find(us, 0) != 0)
				{
					ALine = subl.substr(0, brpos);
					vq.push_back(stoi(ALine));
					paramsV[0].push_back(1);
					pos += ALine.size();
				}
				else
				{
					paramsV[0].push_back(0);
					vq.push_back(0);
					pos++;
				}
			}
			else params.push_back(0);
			subl = inputline.substr(++++++pos, inputline.length() - pos);

			if ((subl.find(brcl, 0)) != 0)
			{
				//vector2
				params.push_back(1);
				brpos = subl.find(brcl, 0);
				while (subl.find(co, 0) < brpos)
				{
					if (subl.find(us, 0) != 0)
					{
						paramsV[1].push_back(1);
						ALine = subl.substr(0, subl.find(co, 0));
						vw.push_back(stoi(ALine));
						pos += ALine.length();
						brpos -= ALine.length();
					}
					else
					{
						paramsV[1].push_back(0);
						vw.push_back(0);
						pos++;
						brpos--;
					}
					brpos--;
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				if (subl.find(us, 0) != 0)
				{
					ALine = subl.substr(0, brpos);
					vw.push_back(stoi(ALine));
					paramsV[1].push_back(1);
					pos += ALine.size();
				}
				else
				{
					paramsV[1].push_back(0);
					vw.push_back(0);
					pos++;
				}
			}
			else params.push_back(0);
			subl = inputline.substr(++++++pos, inputline.length() - pos);

			if ((subl.find(brcl, 0)) != 0)
			{
				//vector3
				params.push_back(1);
				brpos = subl.find(brcl, 0);
				while (subl.find(co, 0) < brpos)
				{
					if (subl.find(us, 0) != 0)
					{
						paramsV[2].push_back(1);
						ALine = subl.substr(0, subl.find(co, 0));
						ve.push_back(stoi(ALine));
						pos += ALine.length();
						brpos -= ALine.length();
					}
					else
					{
						paramsV[2].push_back(0);
						ve.push_back(0);
						pos++;
						brpos--;
					}
					brpos--;
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				if (subl.find(us, 0) != 0)
				{
					ALine = subl.substr(0, brpos);
					ve.push_back(stoi(ALine));
					paramsV[2].push_back(1);
					pos += ALine.size();
				}
				else
				{
					paramsV[2].push_back(0);
					ve.push_back(0);
					pos++;
				}
			}
			else params.push_back(0);
			subl = inputline.substr(++++++pos, inputline.length() - pos);

			if ((subl.find(brcl, 0)) != 0)
			{
				//vector4
				params.push_back(1);
				brpos = subl.find(brcl, 0);
				while (subl.find(co, 0) < brpos)
				{
					if (subl.find(us, 0) != 0)
					{
						paramsV[3].push_back(1);
						ALine = subl.substr(0, subl.find(co, 0));
						vr.push_back(stoi(ALine));
						pos += ALine.length();
						brpos -= ALine.length();
					}
					else
					{
						paramsV[3].push_back(0);
						vr.push_back(0);
						pos++;
						brpos--;
					}
					brpos--;
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				if (subl.find(us, 0) != 0)
				{
					ALine = subl.substr(0, brpos);
					vr.push_back(stoi(ALine));
					paramsV[3].push_back(1);
					pos += ALine.size();
				}
				else
				{
					paramsV[3].push_back(0);
					vr.push_back(0);
					pos++;
				}
			}
			else params.push_back(0);
			subl = inputline.substr(++++++pos, inputline.length() - pos);

			if ((subl.find(brcl, 0)) != 0)
			{
				//vector5
				params.push_back(1);
				brpos = subl.find(brcl, 0);
				while (subl.find(co, 0) < brpos)
				{
					if (subl.find(us, 0) != 0)
					{
						paramsV[4].push_back(1);
						ALine = subl.substr(0, subl.find(co, 0));
						vt.push_back(stoi(ALine));
						pos += ALine.length();
						brpos -= ALine.length();
					}
					else
					{
						paramsV[4].push_back(0);
						vt.push_back(0);
						pos++;
						brpos--;
					}
					brpos--;
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				if (subl.find(us, 0) != 0)
				{
					ALine = subl.substr(0, brpos);
					vt.push_back(stoi(ALine));
					paramsV[4].push_back(1);
					pos += ALine.size();
				}
				else
				{
					paramsV[4].push_back(0);
					vt.push_back(0);
					pos++;
				}
			}
			else params.push_back(0);
			subl = inputline.substr(++++++pos, inputline.length() - pos);

			if ((subl.find(brcl, 0)) != 0)
			{
				//vector6
				params.push_back(1);
				brpos = subl.find(brcl, 0);
				while (subl.find(co, 0) < brpos)
				{
					if (subl.find(us, 0) != 0)
					{
						paramsV[5].push_back(1);
						ALine = subl.substr(0, subl.find(co, 0));
						vy.push_back(stoi(ALine));
						pos += ALine.length();
						brpos -= ALine.length();
					}
					else
					{
						paramsV[5].push_back(0);
						vy.push_back(0);
						pos++;
						brpos--;
					}
					brpos--;
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				if (subl.find(us, 0) != 0)
				{
					ALine = subl.substr(0, brpos);
					vy.push_back(stoi(ALine));
					paramsV[5].push_back(1);
					pos += ALine.size();
				}
				else
				{
					paramsV[5].push_back(0);
					vy.push_back(0);
					pos++;
				}
			}
			else params.push_back(0);
			subl = inputline.substr(++++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				a = stoi(ALine);
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				s = stoi(ALine);
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				d = stoi(ALine);
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				f = stoi(ALine);
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				g = stoi(ALine);
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				h = stoi(ALine);
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				j = stoi(ALine);
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				k = stoi(ALine);
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				l = stoi(ALine);
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				z = stoi(ALine);
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				x = stoi(ALine);
			}
			else params.push_back(0);
		}
		ptr = new conditional_incomplete(q, w, e, r, vq, vw, ve, vr, vt, vy, a, s, d, f, g, h, j, k, l, z, x);
	}
	else if (ALine == "mixed_incomplete_state_lists")
	{
		flag = 0;
		int				e{};
		string			q{}, w{};
		if (inputline != ALine)
		{
			subl = inputline.substr(++pos, inputline.length() - pos);
			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				q = ALine;
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				w = ALine;
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				e = stoi(ALine);
				pos += ALine.length() + 1;
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);
			paramsV.resize(paramsV.size() + 2);
			if ((subl.find(brcl, 0)) != 0)
			{
				//vector
				params.push_back(1);
				brpos = subl.find(brcl, 0);
				while (subl.find(co, 0) < brpos)
				{
					if (subl.find(us, 0) != 0)
					{
						paramsV[0].push_back(1);
						ALine = subl.substr(0, subl.find(co, 0));
						vq.push_back(stoi(ALine));
						pos += ALine.length();
						brpos -= ALine.length();
					}
					else
					{
						paramsV[0].push_back(0);
						vq.push_back(0);
						pos++;
						brpos--;
					}
					brpos--;
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				if (subl.find(us, 0) != 0)
				{
					ALine = subl.substr(0, brpos);
					vq.push_back(stoi(ALine));
					paramsV[0].push_back(1);
					pos += ALine.size();
				}
				else
				{
					paramsV[0].push_back(0);
					vq.push_back(0);
					pos++;
				}
			}
			else params.push_back(0);
			subl = inputline.substr(++++++pos, inputline.length() - pos);

			if ((subl.find(brcl, 0)) != 0)
			{
				//vector2
				params.push_back(1);
				brpos = subl.find(brcl, 0);
				while (subl.find(co, 0) < brpos)
				{
					if (subl.find(us, 0) != 0)
					{
						paramsV[1].push_back(1);
						ALine = subl.substr(0, subl.find(co, 0));
						vw.push_back(stoi(ALine));
						pos += ALine.length();
						brpos -= ALine.length();
					}
					else
					{
						paramsV[1].push_back(0);
						vw.push_back(0);
						pos++;
						brpos--;
					}
					brpos--;
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				if (subl.find(us, 0) != 0)
				{
					ALine = subl.substr(0, brpos);
					vw.push_back(stoi(ALine));
					paramsV[1].push_back(1);
					pos += ALine.size();
				}
				else
				{
					paramsV[1].push_back(0);
					vw.push_back(0);
					pos++;
				}
			}
			else params.push_back(0);
		}
		ptr = new mixed_incomplete_state_lists(w, e, q, vq, vw);
	}
	else if (ALine == "linear_incomplete_node")
	{
		flag = 0;
		int			e{}, y{};
		string		q{}, w{};
		if (inputline != ALine)
		{
			subl = inputline.substr(++pos, inputline.length() - pos);
			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				q = ALine;
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				w = ALine;
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				e = stoi(ALine);
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				y = stoi(ALine);
				pos += ALine.length() + 1;
			}
			else
			{
				params.push_back(0);
				++++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);
			paramsV.resize(paramsV.size() + 2);
			if ((subl.find(brcl, 0)) != 0)
			{
				//vector
				params.push_back(1);
				brpos = subl.find(brcl, 0);
				while (subl.find(co, 0) < brpos)
				{
					if (subl.find(us, 0) != 0)
					{
						paramsV[0].push_back(1);
						ALine = subl.substr(0, subl.find(co, 0));
						vq.push_back(stoi(ALine));
						pos += ALine.length();
						brpos -= ALine.length();
					}
					else
					{
						paramsV[0].push_back(0);
						vq.push_back(0);
						pos++;
						brpos--;
					}
					brpos--;
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				if (subl.find(us, 0) != 0)
				{
					ALine = subl.substr(0, brpos);
					vq.push_back(stoi(ALine));
					paramsV[0].push_back(1);
					pos += ALine.size();
				}
				else
				{
					paramsV[0].push_back(0);
					vq.push_back(0);
					pos++;
				}
			}
			else params.push_back(0);
			subl = inputline.substr(++++++pos, inputline.length() - pos);

			if ((subl.find(brcl, 0)) != 0)
			{
				//vector2
				params.push_back(1);
				brpos = subl.find(brcl, 0);
				while (subl.find(co, 0) < brpos)
				{
					if (subl.find(us, 0) != 0)
					{
						paramsV[1].push_back(1);
						ALine = subl.substr(0, subl.find(co, 0));
						vw.push_back(stoi(ALine));
						pos += ALine.length();
						brpos -= ALine.length();
					}
					else
					{
						paramsV[1].push_back(0);
						vw.push_back(0);
						pos++;
						brpos--;
					}
					brpos--;
					subl = inputline.substr(++pos, inputline.length() - pos);
				}
				if (subl.find(us, 0) != 0)
				{
					ALine = subl.substr(0, brpos);
					vw.push_back(stoi(ALine));
					paramsV[1].push_back(1);
					pos += ALine.size();
				}
				else
				{
					paramsV[1].push_back(0);
					vw.push_back(0);
					pos++;
				}
			}
			else params.push_back(0);
		}
		ptr = new linear_incomplete_node(w, e, q, y, vq, vw);
	}
	else if (ALine == "incomplete_links")
	{
		flag = 0;
		int			q{}, w{}, e{}, r{}, t{}, y{}, u{}, i{}, o{}, p{};
		if (inputline != ALine)
		{
			subl = inputline.substr(++pos, inputline.length() - pos);
			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				q = stoi(ALine);
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				w = stoi(ALine);
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				e = stoi(ALine);
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				r = stoi(ALine);
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				t = stoi(ALine);
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				y = stoi(ALine);
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				u = stoi(ALine);
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				i = stoi(ALine);
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				o = stoi(ALine);
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.rfind(pacl, 0));
				p = stoi(ALine);
			}
			else params.push_back(0);
		}
		ptr = new incomplete_links(q, w, e, r, t, y, u, i, o, p);
	}
	else if (ALine == "last_incomplete")
	{
		flag = 0;
		int				q{}, w{}, e{};
		string			r{};
		if (inputline != ALine)
		{
			subl = inputline.substr(++pos, inputline.length() - pos);
			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				q = stoi(ALine);
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				w = stoi(ALine);
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				e = stoi(ALine);
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.rfind(pacl, 0));
				ALine.resize(ALine.size() - 1);
				r = ALine;
			}
			else params.push_back(0);
		}
		ptr = new last_incomplete(q, w, e, r);
	}
	else if (ALine == "global_nils")
	{
		flag = 0;
		vector<nil_node>	vnil{};
		nil_node			nn(0, "");
		int					iv = 0;
		if (inputline != ALine)
		{
			subl = inputline.substr(++++pos, inputline.length() - pos);
			paramsV.resize(paramsV.size() + 1);
			//vector
			if ((subl.find(brcl, 0)) != 0)
			{
				params.push_back(1);
				brpos = subl.find(brcl, 0);
				while (subl.find(co, 0) < brpos)
				{
					if (subl.find(us, 0) != 0) // check up for the subfact
					{
						pos += 9;  // 9 because global_nils([>>nil_node(<<_, \"true\")
						brpos -= 9;
						subl = inputline.substr(pos, inputline.length() - pos);
						if (subl.find(us, 0) != 0) // check up for the first parameter of this subfact
						{
							paramsV[iv].push_back(1);
							ALine = subl.substr(0, subl.find(co, 0));
							nn.q = stoi(ALine);
							pos += ALine.length();
							brpos -= ALine.length();
						}
						else
						{
							paramsV[iv].push_back(0);
							pos++;
							brpos--;
						}
						brpos--;
						subl = inputline.substr(++pos, inputline.length() - pos);

						if (subl.find(co, 0) < brpos) //last parameters
						{
							if (subl.find(us, 0) != 0)
							{
								paramsV[iv].push_back(1);
								ALine = subl.substr(0, subl.find(co, 0));
								pos += ALine.length();
								brpos -= ALine.length();
								ALine.resize(ALine.size() - 1);
								nn.w = ALine;
							}
							else
							{
								paramsV[iv].push_back(0);
								pos += 2;
								brpos -= 2;
							}
						}
						else //last
						{
							if (subl.find(us, 0) != 0)
							{
								paramsV[iv].push_back(1);
								subl.resize(subl.size() - 2);
								nn.w = subl;
							}
							else paramsV[iv].push_back(0);
						}

					}
					else
					{
						pos++;
						//paramsV[iv].push_back(0);
						brpos--;
					}
					vnil.push_back(nn);
					brpos--;
					subl = inputline.substr(++pos, inputline.length() - pos);
					iv++;
				}
			}
			else params.push_back(0);
		}
		ptr = new global_nils(vnil);
	}
	else if (ALine == "current_module")
	{
		flag = 0;
		string			q{};
		if (inputline != ALine)
		{
			subl = inputline.substr(++pos, inputline.length() - pos);
			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.rfind(pacl, 0));
				ALine.resize(ALine.size() - 1);
				q = ALine;
			}
			else params.push_back(0);
		}
		ptr = new current_module(q);
	}
	else if (ALine == "last_linear_incomplete_node")
	{
		flag = 0;
		int				q{};
		if (inputline != ALine)
		{
			subl = inputline.substr(++pos, inputline.length() - pos);
			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.rfind(pacl, 0));
				q = stoi(ALine);
			}
			else params.push_back(0);
		}
		ptr = new last_linear_incomplete_node(q);
	}
	else if (ALine == "operator_instances")
	{
		flag = 0;
		int				w{};
		string			q{};
		if (inputline != ALine)
		{
			subl = inputline.substr(++pos, inputline.length() - pos);
			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				q = ALine;
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.rfind(pacl, 0));
				w = stoi(ALine);
			}
			else params.push_back(0);
		}
		ptr = new operator_instances(q, w);
	}
	else if (ALine == "massively_parallel_style")
	{
		flag = 0;
		int				q{};
		if (inputline != ALine)
		{
			subl = inputline.substr(++pos, inputline.length() - pos);
			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.rfind(pacl, 0));
				q = stoi(ALine);
			}
			else params.push_back(0);
		}
		ptr = new massively_parallel_style(q);
	}
	else if (ALine == "hdl_style")
	{
		flag = 0;
		string			q{};
		if (inputline != ALine)
		{
			subl = inputline.substr(++pos, inputline.length() - pos);
			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.rfind(pacl, 0));
				ALine.resize(ALine.size() - 1);
				q = ALine;
			}
			else params.push_back(0);
		}
		ptr = new hdl_style(q);
	}
	else if (ALine == "op_instance")
	{
		flag = 0;
		int				q{}, e{}, r{};
		string			w{}, t{};
		if (inputline != ALine)
		{
			subl = inputline.substr(++pos, inputline.length() - pos);
			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				q = stoi(ALine);
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				w = ALine;
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				e = stoi(ALine);
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				r = stoi(ALine);
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.rfind(pacl, 0));
				ALine.resize(ALine.size() - 1);
				t = ALine;
			}
			else params.push_back(0);
		}
		ptr = new op_instance(w, e, q, r, t);
	}
	else if (ALine == "last_op_instance")
	{
		flag = 0;
		int				q{}, e{};
		string			w{};
		if (inputline != ALine)
		{
			subl = inputline.substr(++pos, inputline.length() - pos);
			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				q = stoi(ALine);
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				w = ALine;
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.rfind(pacl, 0));
				e = stoi(ALine);
			}
			else params.push_back(0);
		}
		ptr = new last_op_instance(q, w, e);
	}
	else if (ALine == "op_in_a_state")
	{
		flag = 0;
		int				q{}, r{};
		string			w{}, e{}, t{};
		if (inputline != ALine)
		{
			subl = inputline.substr(++pos, inputline.length() - pos);
			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				q = stoi(ALine);
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				w = ALine;
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				e = ALine;
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				r = stoi(ALine);
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.rfind(pacl, 0));
				ALine.resize(ALine.size() - 1);
				t = ALine;
			}
			else params.push_back(0);
		}
		ptr = new op_in_a_state(w, e, q, r, t);
	}
	else if (ALine == "last_op_in_a_state")
	{
		flag = 0;
		int				q{}, r{};
		string			w{}, e{};
		if (inputline != ALine)
		{
			subl = inputline.substr(++pos, inputline.length() - pos);
			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				q = stoi(ALine);
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				w = ALine;
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				e = ALine;
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.rfind(pacl, 0));
				r = stoi(ALine);
			}
			else params.push_back(0);
		}
		ptr = new last_op_in_a_state(q, w, e, r);
	}
	else if (ALine == "signal_instance")
	{
		flag = 0;
		int				q{}, t{}, y{}, u{};
		string			w{}, e{}, r{};
		if (inputline != ALine)
		{
			subl = inputline.substr(++pos, inputline.length() - pos);
			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				q = stoi(ALine);
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				w = ALine;
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				e = ALine;
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				r = ALine;
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				t = stoi(ALine);
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				y = stoi(ALine);
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.rfind(pacl, 0));
				u = stoi(ALine);
			}
			else params.push_back(0);
		}
		ptr = new signal_instance(q, w, e, r, t, y, u);
	}
	else if (ALine == "last_signal_instance")
	{
		flag = 0;
		int				q{};
		string			w{};
		if (inputline != ALine)
		{
			subl = inputline.substr(++pos, inputline.length() - pos);
			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				q = stoi(ALine);
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.rfind(pacl, 0));
				ALine.resize(ALine.size() - 1);
				w = ALine;
			}
			else params.push_back(0);
		}
		ptr = new last_signal_instance(q, w);
	}
	else if (ALine == "output_instance")
	{
		flag = 0;
		int				q{}, t{}, y{};
		string			w{}, e{}, r{};
		if (inputline != ALine)
		{
			subl = inputline.substr(++pos, inputline.length() - pos);
			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				q = stoi(ALine);
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				w = ALine;
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				e = ALine;
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				r = ALine;
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				t = stoi(ALine);
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.rfind(pacl, 0));
				y = stoi(ALine);
			}
			else params.push_back(0);
		}
		ptr = new output_instance(q, w, e, r, t, y);
	}
	else if (ALine == "last_output_instance")
	{
		flag = 0;
		int				q{};
		string			w{};
		if (inputline != ALine)
		{
			subl = inputline.substr(++pos, inputline.length() - pos);
			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				q = stoi(ALine);
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.rfind(pacl, 0));
				ALine.resize(ALine.size() - 1);
				w = ALine;
			}
			else params.push_back(0);
		}
		ptr = new last_output_instance(q, w);
	}
	else if (ALine == "operator_instance_stats")
	{
		flag = 0;
		int				w{}, e{}, r{};
		string			q{};
		if (inputline != ALine)
		{
			subl = inputline.substr(++pos, inputline.length() - pos);
			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				q = ALine;
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				w = stoi(ALine);
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				e = stoi(ALine);
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.rfind(pacl, 0));
				r = stoi(ALine);
			}
			else params.push_back(0);
		}
		ptr = new operator_instance_stats(q, w, e, r);
	}
	else if (ALine == "consecutive_106")
	{
		flag = 0;
		string			q{};
		if (inputline != ALine)
		{
			subl = inputline.substr(++pos, inputline.length() - pos);
			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.rfind(pacl, 0));
				ALine.resize(ALine.size() - 1);
				q = ALine;
			}
			else params.push_back(0);
		}
		ptr = new consecutive_106(q);
	}
	else if (ALine == "operation_order")
	{
		flag = 0;
		int				e{}, r{}, t{}, y{}, u{}, i{}, o{}, p{};
		string			q{}, w{};
		if (inputline != ALine)
		{
			subl = inputline.substr(++pos, inputline.length() - pos);
			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				q = ALine;
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				w = ALine;
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				e = stoi(ALine);
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				r = stoi(ALine);
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				t = stoi(ALine);
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				y = stoi(ALine);
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				u = stoi(ALine);
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				i = stoi(ALine);
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				o = stoi(ALine);
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.rfind(pacl, 0));
				p = stoi(ALine);
			}
			else params.push_back(0);
		}
		ptr = new operation_order(q, w, e, r, t, y, u, i, o, p);
	}
	else if (ALine == "max_parallel_call_order")
	{
		flag = 0;
		int				e{}, r{};
		string			q{}, w{};
		if (inputline != ALine)
		{
			subl = inputline.substr(++pos, inputline.length() - pos);
			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				q = ALine;
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				w = ALine;
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				e = stoi(ALine);
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.rfind(pacl, 0));
				r = stoi(ALine);
			}
			else params.push_back(0);
		}
		ptr = new max_parallel_call_order(q, w, e, r);
	}
	else if (ALine == "max_op_order")
	{
		flag = 0;
		int				e{};
		string			q{}, w{};
		if (inputline != ALine)
		{
			subl = inputline.substr(++pos, inputline.length() - pos);
			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				q = ALine;
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				w = ALine;
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.rfind(pacl, 0));
				e = stoi(ALine);
			}
			else params.push_back(0);
		}
		ptr = new max_op_order(q, w, e);
	}
	else if (ALine == "totalmax_call_order")
	{
		flag = 0;
		int				e{};
		string			q{}, w{};
		if (inputline != ALine)
		{
			subl = inputline.substr(++pos, inputline.length() - pos);
			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				q = ALine;
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				w = ALine;
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.rfind(pacl, 0));
				e = stoi(ALine);
			}
			else params.push_back(0);
		}
		ptr = new totalmax_call_order(q, w, e);
	}
	else if (ALine == "totalmax_gross_depth")
	{
		flag = 0;
		int				e{};
		string			q{}, w{};
		if (inputline != ALine)
		{
			subl = inputline.substr(++pos, inputline.length() - pos);
			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				q = ALine;
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.find(co, 0));
				w = ALine;
				pos += ALine.length();
			}
			else
			{
				params.push_back(0);
				++pos;
			}
			subl = inputline.substr(++pos, inputline.length() - pos);

			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.rfind(pacl, 0));
				e = stoi(ALine);
			}
			else params.push_back(0);
		}
		ptr = new totalmax_gross_depth(q, w, e);
	}
	else if (ALine == "current_total_max_order_entry")
	{
		flag = 0;
		int				q{};
		if (inputline != ALine)
		{
			subl = inputline.substr(++pos, inputline.length() - pos);
			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.rfind(pacl, 0));
				q = stoi(ALine);
			}
			else params.push_back(0);
		}
		ptr = new current_total_max_order_entry(q);
	}
	else if (ALine == "module_last_state")
	{
		flag = 0;
		int				q{};
		if (inputline != ALine)
		{
			subl = inputline.substr(++pos, inputline.length() - pos);
			if ((subl.find(us, 0)) != 0)
			{
				params.push_back(1);
				ALine = subl.substr(0, subl.rfind(pacl, 0));
				q = stoi(ALine);
			}
			else params.push_back(0);
		}
		ptr = new module_last_state(q);
	}
	else if (ALine == "module_local_list")
	{
		flag = 0;
		int				iv = 0;
		int				w{}, t{}, i{};
		string			q{}, r{}, e{}, y{}, u{}, o{};
		if (inputline != ALine)
		{
			subl = inputline.substr(++++pos, inputline.length() - pos);
			//vector
			if ((subl.find(brcl, 0)) != 0)
			{
				params.push_back(1);
				brpos = subl.find(brcl, 0);
				while (subl.find(co, 0) < brpos)
				{
					paramsV.resize(paramsV.size() + 1);
					if (subl.find(us, 0) != 0) // check up for the subfact
					{
						pos += 13; // 13 because   module_local_list(<<[local_object>>("linedraw",1,"constant
						brpos -= 13;
						subl = inputline.substr(pos, inputline.length() - pos);
						if (subl.find(us, 0) != 0) // check up for the first parameter of this subfact
						{
							paramsV[iv].push_back(1);
							ALine = subl.substr(0, subl.find(co, 0));
							q = ALine;
							pos += ALine.length();
							brpos -= ALine.length();
						}
						else
						{
							paramsV[iv].push_back(0);
							pos++;
							brpos--;
						}
						brpos--;
						subl = inputline.substr(++pos, inputline.length() - pos);

						if (subl.find(us, 0) != 0)
						{
							paramsV[iv].push_back(1);
							ALine = subl.substr(0, subl.find(co, 0));
							w = stoi(ALine);
							pos += ALine.length();
							brpos -= ALine.length();
						}
						else
						{
							paramsV[iv].push_back(0);
							pos++;
							brpos--;
						}
						brpos--;
						subl = inputline.substr(++pos, inputline.length() - pos);

						if (subl.find(us, 0) != 0)
						{
							paramsV[iv].push_back(1);
							ALine = subl.substr(0, subl.find(co, 0));
							e = ALine;
							pos += ALine.length();
							brpos -= ALine.length();
						}
						else
						{
							paramsV[iv].push_back(0);
							pos++;
							brpos--;
						}
						brpos--;
						subl = inputline.substr(++pos, inputline.length() - pos);

						if (subl.find(us, 0) != 0)
						{
							paramsV[iv].push_back(1);
							ALine = subl.substr(0, subl.find(co, 0));
							r = ALine;
							pos += ALine.length();
							brpos -= ALine.length();
						}
						else
						{
							paramsV[iv].push_back(0);
							pos++;
							brpos--;
						}
						brpos--;
						subl = inputline.substr(++pos, inputline.length() - pos);

						if (subl.find(us, 0) != 0)
						{
							paramsV[iv].push_back(1);
							ALine = subl.substr(0, subl.find(co, 0));
							t = stoi(ALine);
							pos += ALine.length();
							brpos -= ALine.length();
						}
						else
						{
							paramsV[iv].push_back(0);
							pos++;
							brpos--;
						}
						brpos--;
						subl = inputline.substr(++pos, inputline.length() - pos);

						if (subl.find(us, 0) != 0)
						{
							paramsV[iv].push_back(1);
							ALine = subl.substr(0, subl.find(co, 0));
							y = ALine;
							pos += ALine.length();
							brpos -= ALine.length();
						}
						else
						{
							paramsV[iv].push_back(0);
							pos++;
							brpos--;
						}
						brpos--;
						subl = inputline.substr(++pos, inputline.length() - pos);

						if (subl.find(us, 0) != 0)
						{
							paramsV[iv].push_back(1);
							ALine = subl.substr(0, subl.find(co, 0));
							u = ALine;
							pos += ALine.length();
							brpos -= ALine.length();
						}
						else
						{
							paramsV[iv].push_back(0);
							pos++;
							brpos--;
						}
						brpos--;
						subl = inputline.substr(++pos, inputline.length() - pos);

						if (subl.find(us, 0) != 0)
						{
							paramsV[iv].push_back(1);
							ALine = subl.substr(0, subl.find(co, 0));
							i = stoi(ALine);
							pos += ALine.length();
							brpos -= ALine.length();
						}
						else
						{
							paramsV[iv].push_back(0);
							pos++;
							brpos--;
						}
						brpos--;
						subl = inputline.substr(++pos, inputline.length() - pos);

						if (subl.find(co, 0) < brpos) //last parameter
						{
							if (subl.find(us, 0) != 0)
							{
								paramsV[iv].push_back(1);
								ALine = subl.substr(0, subl.find(co, 0));
								ALine.resize(ALine.size() - 1);
								pos += ALine.length();
								brpos -= ALine.length();
								o = ALine;
							}
							else
							{
								paramsV[iv].push_back(0);
								pos++;
								brpos--;
							}
						}
						else //last
						{
							if (subl.find(us, 0) != 0)
							{
								paramsV[iv].push_back(1);
								ALine = subl.substr(0, subl.find(co, 0));
								ALine.resize(subl.size() - 2);
								o = ALine;
							}
							else paramsV[iv].push_back(0);
						}
						vobj.push_back(*(new local_object(t, w, i, q, e, y, u, r, o)));
					}
					else
					{
						vobj.push_back(*(new local_object(t, w, i, q, e, y, u, r, o)));
					}
					pos += 2;
					brpos -= 2;
					subl = inputline.substr(pos, inputline.length() - pos);
					iv++;
				}
			}
			else params.push_back(0);
		}
		ptr = new module_local_list(vobj);
	}
	if (flag)								//exeeded the limit of nested else if
	{
		if (ALine == "module_local_list_parcs")
		{
			flag = 0;
			int				iv = 0;
			int				w{}, t{}, i{};
			string			q{}, r{}, e{}, y{}, u{}, o{};
			if (inputline != ALine)
			{
				subl = inputline.substr(++++pos, inputline.length() - pos);
				//vector
				if ((subl.find(brcl, 0)) != 0)
				{
					params.push_back(1);
					brpos = subl.find(brcl, 0);
					while (subl.find(co, 0) < brpos)
					{
						paramsV.resize(paramsV.size() + 1);
						if (subl.find(us, 0) != 0) // check up for the subfact
						{
							pos += 13; // 13 because   module_local_list(<<[local_object>>("linedraw",1,"constant
							brpos -= 13;
							subl = inputline.substr(pos, inputline.length() - pos);
							if (subl.find(us, 0) != 0) // check up for the first parameter of this subfact
							{
								paramsV[iv].push_back(1);
								ALine = subl.substr(0, subl.find(co, 0));
								q = ALine;
								pos += ALine.length();
								brpos -= ALine.length();
							}
							else
							{
								paramsV[iv].push_back(0);
								pos++;
								brpos--;
							}
							brpos--;
							subl = inputline.substr(++pos, inputline.length() - pos);

							if (subl.find(us, 0) != 0)
							{
								paramsV[iv].push_back(1);
								ALine = subl.substr(0, subl.find(co, 0));
								w = stoi(ALine);
								pos += ALine.length();
								brpos -= ALine.length();
							}
							else
							{
								paramsV[iv].push_back(0);
								pos++;
								brpos--;
							}
							brpos--;
							subl = inputline.substr(++pos, inputline.length() - pos);

							if (subl.find(us, 0) != 0)
							{
								paramsV[iv].push_back(1);
								ALine = subl.substr(0, subl.find(co, 0));
								e = ALine;
								pos += ALine.length();
								brpos -= ALine.length();
							}
							else
							{
								paramsV[iv].push_back(0);
								pos++;
								brpos--;
							}
							brpos--;
							subl = inputline.substr(++pos, inputline.length() - pos);

							if (subl.find(us, 0) != 0)
							{
								paramsV[iv].push_back(1);
								ALine = subl.substr(0, subl.find(co, 0));
								r = ALine;
								pos += ALine.length();
								brpos -= ALine.length();
							}
							else
							{
								paramsV[iv].push_back(0);
								pos++;
								brpos--;
							}
							brpos--;
							subl = inputline.substr(++pos, inputline.length() - pos);

							if (subl.find(us, 0) != 0)
							{
								paramsV[iv].push_back(1);
								ALine = subl.substr(0, subl.find(co, 0));
								t = stoi(ALine);
								pos += ALine.length();
								brpos -= ALine.length();
							}
							else
							{
								paramsV[iv].push_back(0);
								pos++;
								brpos--;
							}
							brpos--;
							subl = inputline.substr(++pos, inputline.length() - pos);

							if (subl.find(us, 0) != 0)
							{
								paramsV[iv].push_back(1);
								ALine = subl.substr(0, subl.find(co, 0));
								y = ALine;
								pos += ALine.length();
								brpos -= ALine.length();
							}
							else
							{
								paramsV[iv].push_back(0);
								pos++;
								brpos--;
							}
							brpos--;
							subl = inputline.substr(++pos, inputline.length() - pos);

							if (subl.find(us, 0) != 0)
							{
								paramsV[iv].push_back(1);
								ALine = subl.substr(0, subl.find(co, 0));
								u = ALine;
								pos += ALine.length();
								brpos -= ALine.length();
							}
							else
							{
								paramsV[iv].push_back(0);
								pos++;
								brpos--;
							}
							brpos--;
							subl = inputline.substr(++pos, inputline.length() - pos);

							if (subl.find(us, 0) != 0)
							{
								paramsV[iv].push_back(1);
								ALine = subl.substr(0, subl.find(co, 0));
								i = stoi(ALine);
								pos += ALine.length();
								brpos -= ALine.length();
							}
							else
							{
								paramsV[iv].push_back(0);
								pos++;
								brpos--;
							}
							brpos--;
							subl = inputline.substr(++pos, inputline.length() - pos);

							if (subl.find(co, 0) < brpos) //last parameter
							{
								if (subl.find(us, 0) != 0)
								{
									paramsV[iv].push_back(1);
									ALine = subl.substr(0, subl.find(co, 0));
									ALine.resize(ALine.size() - 1);
									pos += ALine.length();
									brpos -= ALine.length();
									o = ALine;
								}
								else
								{
									paramsV[iv].push_back(0);
									pos++;
									brpos--;
								}
							}
							else //last
							{
								if (subl.find(us, 0) != 0)
								{
									paramsV[iv].push_back(1);
									ALine = subl.substr(0, subl.find(co, 0));
									ALine.resize(subl.size() - 2);
									o = ALine;
								}
								else paramsV[iv].push_back(0);
							}
							vobj.push_back(*(new local_object(t, w, i, q, e, y, u, r, o)));
						}
						else
						{
							vobj.push_back(*(new local_object(t, w, i, q, e, y, u, r, o)));
						}
						pos += 2;
						brpos -= 2;
						subl = inputline.substr(pos, inputline.length() - pos);
						iv++;
					}
				}
				else params.push_back(0);
			}
			ptr = new module_local_list_parcs(vobj);
		}
		else if (ALine == "last_non_io_found")
		{
			int				q{};
			if (inputline != ALine)
			{
				subl = inputline.substr(++pos, inputline.length() - pos);
				if ((subl.find(us, 0)) != 0)
				{
					params.push_back(1);
					ALine = subl.substr(0, subl.rfind(pacl, 0));
					q = stoi(ALine);
				}
				else params.push_back(0);
			}
			ptr = new last_non_io_found(q);
		}
		else if (ALine == "last_local_number")
		{
			int				q{};
			if (inputline != ALine)
			{
				subl = inputline.substr(++pos, inputline.length() - pos);
				if ((subl.find(us, 0)) != 0)
				{
					params.push_back(1);
					ALine = subl.substr(0, subl.rfind(pacl, 0));
					q = stoi(ALine);
				}
				else params.push_back(0);
			}
			ptr = new last_local_number(q);
		}
		else if (ALine == "printed_formal_ios_of_called_module")
		{
			int				w{}, e{};
			string			q{}, r{};
			if (inputline != ALine)
			{
				subl = inputline.substr(++pos, inputline.length() - pos);
				if ((subl.find(us, 0)) != 0)
				{
					params.push_back(1);
					ALine = subl.substr(0, subl.find(co, 0));
					q = ALine;
					pos += ALine.length();
				}
				else
				{
					params.push_back(0);
					++pos;
				}
				subl = inputline.substr(++pos, inputline.length() - pos);

				if ((subl.find(us, 0)) != 0)
				{
					params.push_back(1);
					ALine = subl.substr(0, subl.find(co, 0));
					w = stoi(ALine);
					pos += ALine.length();
				}
				else
				{
					params.push_back(0);
					++pos;
				}
				subl = inputline.substr(++pos, inputline.length() - pos);

				if ((subl.find(us, 0)) != 0)
				{
					params.push_back(1);
					ALine = subl.substr(0, subl.find(co, 0));
					e = stoi(ALine);
					pos += ALine.length();
				}
				else
				{
					params.push_back(0);
					++pos;
				}
				subl = inputline.substr(++pos, inputline.length() - pos);

				if ((subl.find(us, 0)) != 0)
				{
					params.push_back(1);
					ALine = subl.substr(0, subl.rfind(pacl, 0));
					ALine.resize(ALine.size() - 1);
					r = ALine;
				}
				else params.push_back(0);
			}
			ptr = new printed_formal_ios_of_called_module(q, w, e, r);
		}
		else if (ALine == "it_includes_ifthen")
		{
			int				w{}, e{};
			string			q{};
			if (inputline != ALine)
			{
				subl = inputline.substr(++pos, inputline.length() - pos);
				if ((subl.find(us, 0)) != 0)
				{
					params.push_back(1);
					ALine = subl.substr(0, subl.find(co, 0));
					q = ALine;
					pos += ALine.length();
				}
				else
				{
					params.push_back(0);
					++pos;
				}
				subl = inputline.substr(++pos, inputline.length() - pos);

				if ((subl.find(us, 0)) != 0)
				{
					params.push_back(1);
					ALine = subl.substr(0, subl.find(co, 0));
					w = stoi(ALine);
					pos += ALine.length();
				}
				else
				{
					params.push_back(0);
					++pos;
				}
				subl = inputline.substr(++pos, inputline.length() - pos);

				if ((subl.find(us, 0)) != 0)
				{
					params.push_back(1);
					ALine = subl.substr(0, subl.rfind(pacl, 0));
					e = stoi(ALine);
				}
				else params.push_back(0);
			}
			ptr = new it_includes_ifthen(q, w, e);
		}
		else if (ALine == "it_includes_conditional_targeting")
		{
			int				w{}, e{};
			string			q{};
			if (inputline != ALine)
			{
				subl = inputline.substr(++pos, inputline.length() - pos);
				if ((subl.find(us, 0)) != 0)
				{
					params.push_back(1);
					ALine = subl.substr(0, subl.find(co, 0));
					q = ALine;
					pos += ALine.length();
				}
				else
				{
					params.push_back(0);
					++pos;
				}
				subl = inputline.substr(++pos, inputline.length() - pos);

				if ((subl.find(us, 0)) != 0)
				{
					params.push_back(1);
					ALine = subl.substr(0, subl.find(co, 0));
					w = stoi(ALine);
					pos += ALine.length();
				}
				else
				{
					params.push_back(0);
					++pos;
				}
				subl = inputline.substr(++pos, inputline.length() - pos);

				if ((subl.find(us, 0)) != 0)
				{
					params.push_back(1);
					ALine = subl.substr(0, subl.rfind(pacl, 0));
					e = stoi(ALine);
				}
				else params.push_back(0);
			}
			ptr = new it_includes_conditional_targeting(q, w, e);
		}
		else if (ALine == "targets_conditional_variable")
		{
			int				w{}, e{}, r{};
			string			q{};
			if (inputline != ALine)
			{
				subl = inputline.substr(++pos, inputline.length() - pos);
				if ((subl.find(us, 0)) != 0)
				{
					params.push_back(1);
					ALine = subl.substr(0, subl.find(co, 0));
					q = ALine;
					pos += ALine.length();
				}
				else
				{
					params.push_back(0);
					++pos;
				}
				subl = inputline.substr(++pos, inputline.length() - pos);

				if ((subl.find(us, 0)) != 0)
				{
					params.push_back(1);
					ALine = subl.substr(0, subl.find(co, 0));
					w = stoi(ALine);
					pos += ALine.length();
				}
				else
				{
					params.push_back(0);
					++pos;
				}
				subl = inputline.substr(++pos, inputline.length() - pos);

				if ((subl.find(us, 0)) != 0)
				{
					params.push_back(1);
					ALine = subl.substr(0, subl.find(co, 0));
					e = stoi(ALine);
					pos += ALine.length();
				}
				else
				{
					params.push_back(0);
					++pos;
				}
				subl = inputline.substr(++pos, inputline.length() - pos);

				if ((subl.find(us, 0)) != 0)
				{
					params.push_back(1);
					ALine = subl.substr(0, subl.rfind(pacl, 0));
					r = stoi(ALine);
				}
				else params.push_back(0);
			}
			ptr = new targets_conditional_variable(q, w, e, r);
		}
		else if (ALine == "variable_has_been_listed")
		{
			string			q{}, w{};
			if (inputline != ALine)
			{
				subl = inputline.substr(++pos, inputline.length() - pos);
				if ((subl.find(us, 0)) != 0)
				{
					params.push_back(1);
					ALine = subl.substr(0, subl.find(co, 0));
					q = ALine;
					pos += ALine.length();
				}
				else
				{
					params.push_back(0);
					++pos;
				}
				subl = inputline.substr(++pos, inputline.length() - pos);

				if ((subl.find(us, 0)) != 0)
				{
					params.push_back(1);
					ALine = subl.substr(0, subl.rfind(pacl, 0));
					ALine.resize(ALine.size() - 1);
					w = ALine;
				}
				else params.push_back(0);
			}
			ptr = new variable_has_been_listed(q, w);
		}
		else if (ALine == "resetstyle")
		{
			string			q{};
			if (inputline != ALine)
			{
				subl = inputline.substr(++pos, inputline.length() - pos);
				if ((subl.find(us, 0)) != 0)
				{
					params.push_back(1);
					ALine = subl.substr(0, subl.rfind(pacl, 0));
					ALine.resize(ALine.size() - 1);
					q = ALine;
				}
				else params.push_back(0);
			}
			ptr = new resetstyle(q);
		}
		else if (ALine == "checkstyle")
		{
			string			q{};
			if (inputline != ALine)
			{
				subl = inputline.substr(++pos, inputline.length() - pos);
				if ((subl.find(us, 0)) != 0)
				{
					params.push_back(1);
					ALine = subl.substr(0, subl.rfind(pacl, 0));
					ALine.resize(ALine.size() - 1);
					q = ALine;
				}
				else params.push_back(0);
			}
			ptr = new checkstyle(q);
		}
		else if (ALine == "total_local_entry")
		{
			int				q{};
			if (inputline != ALine)
			{
				subl = inputline.substr(++pos, inputline.length() - pos);
				if ((subl.find(us, 0)) != 0)
				{
					params.push_back(1);
					ALine = subl.substr(0, subl.rfind(pacl, 0));
					q = stoi(ALine);
				}
				else params.push_back(0);
			}
			ptr = new total_local_entry(q);
		}
		else if (ALine == "complex_next_state_operation_depth")
		{
			int				q{};
			if (inputline != ALine)
			{
				subl = inputline.substr(++pos, inputline.length() - pos);
				if ((subl.find(us, 0)) != 0)
				{
					params.push_back(1);
					ALine = subl.substr(0, subl.rfind(pacl, 0));
					q = stoi(ALine);
				}
				else params.push_back(0);
			}
			ptr = new complex_next_state_operation_depth(q);
		}
		else if (ALine == "output_filename")
		{
			string			q{};
			if (inputline != ALine)
			{
				subl = inputline.substr(++pos, inputline.length() - pos);
				if ((subl.find(us, 0)) != 0)
				{
					params.push_back(1);
					ALine = subl.substr(0, subl.rfind(pacl, 0));
					ALine.resize(ALine.size() - 1);
					q = ALine;
				}
				else params.push_back(0);
			}
			ptr = new output_filename(q);
		}
		else if (ALine == "hdl_io_pass")
		{
			int				q{};
			if (inputline != ALine)
			{
				subl = inputline.substr(++pos, inputline.length() - pos);
				if ((subl.find(us, 0)) != 0)
				{
					params.push_back(1);
					ALine = subl.substr(0, subl.rfind(pacl, 0));
					q = stoi(ALine);
				}
				else params.push_back(0);
			}
			ptr = new hdl_io_pass(q);
		}
		else if (ALine == "current_hdl_style")
		{
			string			q{};
			if (inputline != ALine)
			{
				subl = inputline.substr(++pos, inputline.length() - pos);
				if ((subl.find(us, 0)) != 0)
				{
					params.push_back(1);
					ALine = subl.substr(0, subl.rfind(pacl, 0));
					ALine.resize(ALine.size() - 1);
					q = ALine;
				}
				else params.push_back(0);
			}
			ptr = new current_hdl_style(q);
		}
		else if (ALine == "call_ios_have_been_reset")
		{
			string			q{};
			if (inputline != ALine)
			{
				subl = inputline.substr(++pos, inputline.length() - pos);
				if ((subl.find(us, 0)) != 0)
				{
					params.push_back(1);
					ALine = subl.substr(0, subl.rfind(pacl, 0));
					ALine.resize(ALine.size() - 1);
					q = ALine;
				}
				else params.push_back(0);
			}
			ptr = new call_ios_have_been_reset(q);
		}
		else if (ALine == "debug_mode")
		{
			int				q{};
			if (inputline != ALine)
			{
				subl = inputline.substr(++pos, inputline.length() - pos);
				if ((subl.find(us, 0)) != 0)
				{
					params.push_back(1);
					ALine = subl.substr(0, subl.rfind(pacl, 0));
					q = stoi(ALine);
				}
				else params.push_back(0);
			}
			ptr = new debug_mode(q);
		}
		else if (ALine == "print_C_main_body")
		{
			int				q{};
			if (inputline != ALine)
			{
				subl = inputline.substr(++pos, inputline.length() - pos);
				if ((subl.find(us, 0)) != 0)
				{
					params.push_back(1);
					ALine = subl.substr(0, subl.rfind(pacl, 0));
					q = stoi(ALine);
				}
				else params.push_back(0);
			}
			ptr = new print_C_main_body(q);
		}
		else if (ALine == "cac_mode")
		{
			int				q{};
			if (inputline != ALine)
			{
				subl = inputline.substr(++pos, inputline.length() - pos);
				if ((subl.find(us, 0)) != 0)
				{
					params.push_back(1);
					ALine = subl.substr(0, subl.rfind(pacl, 0));
					q = stoi(ALine);
				}
				else params.push_back(0);
			}
			ptr = new cac_mode(q);
		}
		else if (ALine == "path")
		{
			int				w{}, e{};
			string			q{};
			if (inputline != ALine)
			{
				subl = inputline.substr(++pos, inputline.length() - pos);
				if ((subl.find(us, 0)) != 0)
				{
					params.push_back(1);
					ALine = subl.substr(0, subl.find(co, 0));
					q = ALine;
					pos += ALine.length();
				}
				else
				{
					params.push_back(0);
					++pos;
				}
				subl = inputline.substr(++pos, inputline.length() - pos);

				if ((subl.find(us, 0)) != 0)
				{
					params.push_back(1);
					ALine = subl.substr(0, subl.find(co, 0));
					w = stoi(ALine);
					pos += ALine.length();
				}
				else
				{
					params.push_back(0);
					++pos;
				}
				subl = inputline.substr(++pos, inputline.length() - pos);

				if ((subl.find(us, 0)) != 0)
				{
					params.push_back(1);
					ALine = subl.substr(0, subl.rfind(pacl, 0));
					e = stoi(ALine);
				}
				else params.push_back(0);
			}
			ptr = new path(q, w, e);
		}
		else if (ALine == "max_path")
		{
			int				w{};
			string			q{};
			if (inputline != ALine)
			{
				subl = inputline.substr(++pos, inputline.length() - pos);
				if ((subl.find(us, 0)) != 0)
				{
					params.push_back(1);
					ALine = subl.substr(0, subl.find(co, 0));
					q = ALine;
					pos += ALine.length();
				}
				else
				{
					params.push_back(0);
					++pos;
				}
				subl = inputline.substr(++pos, inputline.length() - pos);

				if ((subl.find(us, 0)) != 0)
				{
					params.push_back(1);
					ALine = subl.substr(0, subl.rfind(pacl, 0));
					w = stoi(ALine);
				}
				else params.push_back(0);
			}
			ptr = new max_path(q, w);
		}
		else if (ALine == "min_path")
		{
			int				w{};
			string			q{};
			if (inputline != ALine)
			{
				subl = inputline.substr(++pos, inputline.length() - pos);
				if ((subl.find(us, 0)) != 0)
				{
					params.push_back(1);
					ALine = subl.substr(0, subl.find(co, 0));
					q = ALine;
					pos += ALine.length();
				}
				else
				{
					params.push_back(0);
					++pos;
				}
				subl = inputline.substr(++pos, inputline.length() - pos);

				if ((subl.find(us, 0)) != 0)
				{
					params.push_back(1);
					ALine = subl.substr(0, subl.rfind(pacl, 0));
					w = stoi(ALine);
				}
				else params.push_back(0);
			}
			ptr = new min_path(q, w);
		}
		else if (ALine == "op_belongs_to_state")
		{
			int				w{}, e{}, r{};
			string			q{};
			if (inputline != ALine)
			{
				subl = inputline.substr(++pos, inputline.length() - pos);
				if ((subl.find(us, 0)) != 0)
				{
					params.push_back(1);
					ALine = subl.substr(0, subl.find(co, 0));
					q = ALine;
					pos += ALine.length();
				}
				else
				{
					params.push_back(0);
					++pos;
				}
				subl = inputline.substr(++pos, inputline.length() - pos);

				if ((subl.find(us, 0)) != 0)
				{
					params.push_back(1);
					ALine = subl.substr(0, subl.find(co, 0));
					w = stoi(ALine);
					pos += ALine.length();
				}
				else
				{
					params.push_back(0);
					++pos;
				}
				subl = inputline.substr(++pos, inputline.length() - pos);

				if ((subl.find(us, 0)) != 0)
				{
					params.push_back(1);
					ALine = subl.substr(0, subl.find(co, 0));
					e = stoi(ALine);
					pos += ALine.length();
				}
				else
				{
					params.push_back(0);
					++pos;
				}
				subl = inputline.substr(++pos, inputline.length() - pos);

				if ((subl.find(us, 0)) != 0)
				{
					params.push_back(1);
					ALine = subl.substr(0, subl.rfind(pacl, 0));
					r = stoi(ALine);
				}
				else params.push_back(0);
			}
			ptr = new op_belongs_to_state(q, w, e, r);
		}
		else if (ALine == "top_module")
		{
			string			q{};
			if (inputline != ALine)
			{
				subl = inputline.substr(++pos, inputline.length() - pos);
				if ((subl.find(us, 0)) != 0)
				{
					params.push_back(1);
					ALine = subl.substr(0, subl.rfind(pacl, 0));
					ALine.resize(ALine.size() - 1);
					q = ALine;
				}
				else params.push_back(0);
			}
			ptr = new top_module(q);
		}
		else if (ALine == "package_name")
		{
			string			q{};
			if (inputline != ALine)
			{
				subl = inputline.substr(++pos, inputline.length() - pos);
				if ((subl.find(us, 0)) != 0)
				{
					params.push_back(1);
					ALine = subl.substr(0, subl.rfind(pacl, 0));
					ALine.resize(ALine.size() - 1);
					q = ALine;
				}
				else params.push_back(0);
			}
			ptr = new package_name(q);
		}
		else
		{
			GenfactError* ptr = new GenfactError("error for " + inputline);
			//cout << "unable to make instance of: " << inputline << endl;
		}
	}
	params.shrink_to_fit();
	params.shrink_to_fit();
	return factUnderInspection(ptr, params, paramsV);
}

/// @brief compares 2 data
/// @param Treesfact <- loaded data
/// @param obj <- data to compare (/w '_')
/// @return if matched 1 else 0
size_t matchfactsSpec(GeneralFact* Treesfact, factUnderInspection* obj) // node of a tree, fact with underscores
{
	bool					flag = 1;
	vector<bool>			tcmp = obj->getcmp();
	vector<vector<bool>>	tcmpV = obj->getcmpV();
	GeneralFact* fact = obj->fact;

	//cout << endl << "controll" << endl
	//	<< typeid(*fact).name() << endl
	//	<< typeid(*Treesfact).name() << endl;

	//cout << typeid(*Treesfact).name() << endl;

	if (typeid(type_def) == typeid(*fact) && typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		type_def* ptr = dynamic_cast<type_def*>(fact);
		type_def* ptr2 = dynamic_cast<type_def*>(Treesfact);

		if (!tcmp.empty())
		{
			if (tcmp[0])
				if (ptr->q != ptr2->q) return 0;

			if (tcmp[1])
				if (ptr->w != ptr2->w) return 0;

			if (tcmp[2])
				if (ptr->e != ptr2->e) return 0;

			if (tcmp[3])
				if (ptr->r != ptr2->r) return 0;

			if (tcmp[4])
				if (ptr->t != ptr2->t) return 0;

			if (tcmp[5])
				if (ptr->y != ptr2->y) return 0;

			if (tcmp[6])
				if (ptr->u != ptr2->u) return 0;

			if (tcmp[7])
				if (ptr->i != ptr2->i) return 0;

			if (tcmp[8])
				if (ptr->o != ptr2->o) return 0;
		}
	}
	else if (typeid(op_def) == typeid(*fact) && typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		op_def* ptr = dynamic_cast<op_def*>(fact);
		op_def* ptr2 = dynamic_cast<op_def*>(Treesfact);
		if (!tcmp.empty())
		{
			if (tcmp[0])
				if (ptr->q != ptr2->q) return 0;

			if (tcmp[1])
				if (ptr->w != ptr2->w) return 0;

			if (tcmp[2])
				if (ptr->e != ptr2->e) return 0;

			if (tcmp[3])
				if (ptr->r != ptr2->r) return 0;

			if (tcmp[4])
				if (ptr->t != ptr2->t) return 0;

			if (tcmp[5])
				if (ptr->y != ptr2->y) return 0;

			if (tcmp[6])
				if (ptr->u != ptr2->u) return 0;
		}
	}
	else if (typeid(hierarchy_part) == typeid(*fact) && typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		hierarchy_part* ptr = dynamic_cast<hierarchy_part*>(fact);
		hierarchy_part* ptr2 = dynamic_cast<hierarchy_part*>(Treesfact);
		if (!tcmp.empty())
		{
			if (tcmp[0])
				if (ptr->q != ptr2->q) return 0;

			if (tcmp[1])
				if (ptr->w != ptr2->w) return 0;

			if (tcmp[2])
				if (ptr->e != ptr2->e) return 0;

			if (tcmp[3])
				if (ptr->r != ptr2->r) return 0;

			if (tcmp[4])
				if (ptr->t != ptr2->t) return 0;

			if (tcmp[5])
				if (ptr->y != ptr2->y) return 0;

			if (tcmp[6])
				if (ptr->u != ptr2->u) return 0;
		}
	}
	else if (typeid(data_stmt) == typeid(*fact) && typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		data_stmt* ptr = dynamic_cast<data_stmt*>(fact);
		data_stmt* ptr2 = dynamic_cast<data_stmt*>(Treesfact);
		if (!tcmp.empty())
		{
			if (tcmp[0])
				if (ptr->q != ptr2->q) return 0;

			if (tcmp[1])
				if (ptr->w != ptr2->w) return 0;

			if (tcmp[2])
				if (ptr->e != ptr2->e) return 0;

			if (tcmp[3])
				if (ptr->r != ptr2->r) return 0;

			if (tcmp[4])
				if (ptr->t != ptr2->t) return 0;

			if (tcmp[5])
				if (ptr->y != ptr2->y) return 0;
		}
	}
	else if (typeid(prog_stmt) == typeid(*fact) && typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		prog_stmt* ptr = dynamic_cast<prog_stmt*>(fact);
		prog_stmt* ptr2 = dynamic_cast<prog_stmt*>(Treesfact);
		if (!tcmp.empty())
		{
			if (tcmp[0])
				if (ptr->q != ptr2->q) return 0;

			if (tcmp[1])
				if (ptr->w != ptr2->w) return 0;

			if (tcmp[2])
				if (ptr->e != ptr2->e) return 0;

			if (tcmp[3])
				if (ptr->r != ptr2->r) return 0;

			if (tcmp[4])
				if (ptr->t != ptr2->t) return 0;

			if (tcmp[5])
				if (ptr->y != ptr2->y) return 0;

			if (tcmp[6])
				if (ptr->u != ptr2->u) return 0;

			if (tcmp[7])
				if (ptr->i != ptr2->i) return 0;
		}
	}
	else if (typeid(joint_stmt) == typeid(*fact) && typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		joint_stmt* ptr = dynamic_cast<joint_stmt*>(fact);
		joint_stmt* ptr2 = dynamic_cast<joint_stmt*>(Treesfact);
		if (!tcmp.empty())
		{
			if (tcmp[0])
				if (ptr->q != ptr2->q) return 0;

			if (tcmp[1])
				if (ptr->w != ptr2->w) return 0;

			if (tcmp[2])
				if (ptr->e != ptr2->e) return 0;

			if (tcmp[3])
				if (ptr->r != ptr2->r) return 0;

			if (tcmp[4])
				if (ptr->t != ptr2->t) return 0;

			if (tcmp[5])
				if (ptr->y != ptr2->y) return 0;
		}
	}
	else if (typeid(call_stmt) == typeid(*fact) && typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		call_stmt* ptr = dynamic_cast<call_stmt*>(fact);
		call_stmt* ptr2 = dynamic_cast<call_stmt*>(Treesfact);

		if (!tcmp.empty())
		{
			if (tcmp[0])
				if (ptr->q != ptr2->q) return 0;

			if (tcmp[1])
				if (ptr->w != ptr2->w) return 0;

			if (tcmp[2])
				if (ptr->e != ptr2->e) return 0;

			//vector // prevent from vector out of range....
			if (tcmp[3])
			{
				if (tcmpV[0].size() > ptr->r.size())
					return 0;

				size_t	siz = tcmpV[0].size();
				for (int i = 0; i < siz; i++)
					if (tcmpV[0][i])
						if (!(ptr->r[i] == ptr2->r[i])) return 0;
			}
		}
	}
	else if (typeid(compo_stmt) == typeid(*fact) && typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		compo_stmt* ptr = dynamic_cast<compo_stmt*>(fact);
		compo_stmt* ptr2 = dynamic_cast<compo_stmt*>(Treesfact);

		if (!tcmp.empty())
		{
			if (tcmpV[0].size() > ptr->r.size())
				return 0;

			if (tcmp[0])
				if (ptr->q != ptr2->q) return 0;

			if (tcmp[1])
				if (ptr->w != ptr2->w) return 0;

			//vector 
			if (tcmp[2])
			{
				if (tcmpV[0].size() > ptr->r.size())
					return 0;
				size_t	siz = tcmpV[0].size();
				for (int i = 0; i < siz; i++)
					if (tcmpV[0][i])
						if (!(ptr->r[i] == ptr2->r[i])) return 0;
			}
		}
	}
	else if (typeid(rec_stmt) == typeid(*fact) && typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		rec_stmt* ptr = dynamic_cast<rec_stmt*>(fact);
		rec_stmt* ptr2 = dynamic_cast<rec_stmt*>(Treesfact);

		if (!tcmp.empty())
		{

			if (tcmp[0])
				if (ptr->q != ptr2->q) return 0;

			if (tcmp[1])
				if (ptr->w != ptr2->w) return 0;

			//vector 
			if (tcmp[2])
			{
				if (tcmpV[0].size() > ptr->e.size())
					return 0;

				size_t	siz = tcmpV[0].size();
				for (int i = 0; i < siz; i++)
					if (tcmpV[0][i])
						if (!(ptr->e[i] == ptr2->e[i])) return 0;
			}
		}
	}
	else if (typeid(special_op) == typeid(*fact) && typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		special_op* ptr = dynamic_cast<special_op*>(fact);
		special_op* ptr2 = dynamic_cast<special_op*>(Treesfact);
		if (!tcmp.empty())
		{
			if (tcmp[0])
				if (ptr->q != ptr2->q) return 0;

			if (tcmp[1])
				if (ptr->w != ptr2->w) return 0;

			if (tcmp[2])
				if (ptr->e != ptr2->e) return 0;

			if (tcmp[3])
				if (ptr->r != ptr2->r) return 0;

			if (tcmp[4])
				if (ptr->t != ptr2->t) return 0;

			if (tcmp[5])
				if (ptr->y != ptr2->y) return 0;

			if (tcmp[6])
				if (ptr->u != ptr2->u) return 0;

			if (tcmp[7])
				if (ptr->i != ptr2->i) return 0;

			if (tcmp[8])
				if (ptr->o != ptr2->o) return 0;

			if (tcmp[9])
				if (ptr->p != ptr2->p) return 0;
		}
	}
	else if (typeid(special_dt) == typeid(*fact) && typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		special_dt* ptr = dynamic_cast<special_dt*>(fact);
		special_dt* ptr2 = dynamic_cast<special_dt*>(Treesfact);
		if (!tcmp.empty())
		{
			if (tcmp[0])
				if (ptr->q != ptr2->q) return 0;

			if (tcmp[1])
				if (ptr->w != ptr2->w) return 0;

			if (tcmp[2])
				if (ptr->e != ptr2->e) return 0;

			if (tcmp[3])
				if (ptr->r != ptr2->r) return 0;

			if (tcmp[4])
				if (ptr->t != ptr2->t) return 0;

			if (tcmp[5])
				if (ptr->y != ptr2->y) return 0;

			if (tcmp[6])
				if (ptr->u != ptr2->u) return 0;
		}
	}
	else if (typeid(local_object) == typeid(*fact) && typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		local_object* ptr = dynamic_cast<local_object*>(fact);
		local_object* ptr2 = dynamic_cast<local_object*>(Treesfact);
		if (!tcmp.empty())
		{
			if (tcmp[0])
				if (ptr->q != ptr2->q) return 0;

			if (tcmp[1])
				if (ptr->w != ptr2->w) return 0;

			if (tcmp[2])
				if (ptr->e != ptr2->e) return 0;

			if (tcmp[3])
				if (ptr->r != ptr2->r) return 0;

			if (tcmp[4])
				if (ptr->t != ptr2->t) return 0;

			if (tcmp[5])
				if (ptr->y != ptr2->y) return 0;

			if (tcmp[6])
				if (ptr->u != ptr2->u) return 0;

			if (tcmp[7])
				if (ptr->i != ptr2->i) return 0;

			if (tcmp[8])
				if (ptr->o != ptr2->o) return 0;
		}
	}
	else if (typeid(subprogram_call) == typeid(*fact) && typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		subprogram_call* ptr = dynamic_cast<subprogram_call*>(fact);
		subprogram_call* ptr2 = dynamic_cast<subprogram_call*>(Treesfact);
		state_node* ptr1 = dynamic_cast<state_node*>(fact);
		state_node* ptr12 = dynamic_cast<state_node*>(Treesfact);
		if (tcmp[0])
			if (ptr1->q != ptr12->q) return 0;

		if (tcmp[1])
			if (ptr1->w != ptr12->w) return 0;

		if (tcmp.size() != 3)
		{
			//vector
			if (tcmp[3])
			{
				if (tcmpV[0].size() > ptr->q.size())
					return 0;

				size_t	siz = tcmpV[0].size();
				for (int i = 0; i < siz; i++)
					if (tcmpV[0][i])
						if (ptr->q[i] != ptr2->q[i]) return 0;
			}

			if (tcmp[4])
				if (ptr->w != ptr2->w) return 0;

		}
	}
	else if (typeid(dataflow) == typeid(*fact) && typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		dataflow* ptr = dynamic_cast<dataflow*>(fact);
		dataflow* ptr2 = dynamic_cast<dataflow*>(Treesfact);
		state_node* ptr1 = dynamic_cast<state_node*>(fact);
		state_node* ptr12 = dynamic_cast<state_node*>(Treesfact);

		if (tcmp[0])
			if (ptr1->q != ptr12->q) return 0;

		if (tcmp[1])
			if (ptr1->w != ptr12->w) return 0;

		if (tcmp.size() != 3)
		{
			//vector
			if (tcmp[3])
			{
				if (tcmpV[0].size() > ptr->q.size())
					return 0;

				size_t	siz = tcmpV[0].size();
				for (int i = 0; i < siz; i++)
					if (tcmpV[0][i])
						if (ptr->q[i] != ptr2->q[i]) return 0;
			}

			if (tcmp[4])
				if (ptr->w != ptr2->w) return 0;
		}

	}
	else if (typeid(ifthen) == typeid(*fact) && typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		ifthen* ptr = dynamic_cast<ifthen*>(fact);
		ifthen* ptr2 = dynamic_cast<ifthen*>(Treesfact);
		state_node* ptr1 = dynamic_cast<state_node*>(fact);
		state_node* ptr12 = dynamic_cast<state_node*>(Treesfact);

		if (tcmp[0])
			if (ptr1->q != ptr12->q) return 0;

		if (tcmp[1])
			if (ptr1->w != ptr12->w) return 0;

		if (tcmp.size() != 3)
		{
			//vector
			if (tcmp[3])
			{
				if (tcmpV[0].size() > ptr->q.size())
					return 0;

				size_t	siz = tcmpV[0].size();
				for (int i = 0; i < siz; i++)
					if (tcmpV[0][i])
						if (ptr->q[i] != ptr2->q[i]) return 0;
			}
			//vector2
			if (tcmp[4])
			{
				if (tcmpV[1].size() > ptr->w.size())
					return 0;

				size_t	siz = tcmpV[1].size();
				for (int i = 0; i < siz; i++)
					if (tcmpV[1][i])
						if (ptr->w[i] != ptr2->w[i]) return 0;
			}

			//vector3
			if (tcmp[5])
			{
				if (tcmpV[2].size() > ptr->e.size())
					return 0;

				size_t	siz = tcmpV[2].size();
				for (int i = 0; i < siz; i++)
					if (tcmpV[2][i])
						if (ptr->e[i] != ptr2->e[i]) return 0;
			}

			if (tcmp[6])
				if (ptr->r != ptr2->r) return 0;

			if (tcmp[7])
				if (ptr->t != ptr2->t) return 0;
		}
	}
	else if (typeid(jump) == typeid(*fact) && typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		jump* ptr = dynamic_cast<jump*>(fact);
		jump* ptr2 = dynamic_cast<jump*>(Treesfact);
		state_node* ptr1 = dynamic_cast<state_node*>(fact);
		state_node* ptr12 = dynamic_cast<state_node*>(Treesfact);

		if (tcmp[0])
			if (ptr1->q != ptr12->q) return 0;

		if (tcmp[1])
			if (ptr1->w != ptr12->w) return 0;

		if (tcmp.size() != 3)
		{
			//vector
			if (tcmp[3])
			{
				if (tcmpV[0].size() > ptr->q.size())
					return 0;
				size_t	siz = tcmpV[0].size();
				for (int i = 0; i < siz; i++)
					if (tcmpV[0][i])
						if (ptr->q[i] != ptr2->q[i]) return 0;
			}

			if (tcmp[4])
				if (ptr->w != ptr2->w) return 0;
		}
	}
	else if (typeid(return_cos) == typeid(*fact) && typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		return_cos* ptr = dynamic_cast<return_cos*>(fact);
		return_cos* ptr2 = dynamic_cast<return_cos*>(Treesfact);
		state_node* ptr1 = dynamic_cast<state_node*>(fact);
		state_node* ptr12 = dynamic_cast<state_node*>(Treesfact);

		if (tcmp[0])
			if (ptr1->q != ptr12->q) return 0;

		if (tcmp[1])
			if (ptr1->w != ptr12->w) return 0;

		if (tcmp.size() != 3)
		{
			if (tcmpV[0].size() > ptr->q.size())
				return 0;

			//vector
			if (tcmp[3])
			{
				size_t	siz = tcmpV[0].size();
				for (int i = 0; i < siz; i++)
					if (tcmpV[0][i])
						if (!(ptr->q[i] == ptr2->q[i])) return 0;
			}
		}
	}
	else if (typeid(state_node) == typeid(*fact))
	{
		if (typeid(subprogram_call) == typeid(*Treesfact) || typeid(dataflow) == typeid(*Treesfact) ||
			typeid(ifthen) == typeid(*Treesfact) || typeid(jump) == typeid(*Treesfact) ||
			typeid(return_cos) == typeid(*Treesfact))
		{
			flag = 0;
			state_node* ptr = dynamic_cast<state_node*>(fact);
			state_node* ptr2 = dynamic_cast<state_node*>(Treesfact);
			if (!tcmp.empty())
			{
				if (tcmp[0])
					if (ptr->q != ptr2->q) return 0;

				if (tcmp[1])
					if (ptr->w != ptr2->w) return 0;
			}
		}
	}
	else if (typeid(change_op_number) == typeid(*fact) && typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		change_op_number* ptr = dynamic_cast<change_op_number*>(fact);
		change_op_number* ptr2 = dynamic_cast<change_op_number*>(Treesfact);
		if (!tcmp.empty())
		{
			if (tcmp[0])
				if (ptr->q != ptr2->q) return 0;

			if (tcmp[1])
				if (ptr->w != ptr2->w) return 0;

			if (tcmp[2])
				if (ptr->e != ptr2->e) return 0;
		}
	}
	else if (typeid(last_change_op_number) == typeid(*fact) && typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		last_change_op_number* ptr = dynamic_cast<last_change_op_number*>(fact);
		last_change_op_number* ptr2 = dynamic_cast<last_change_op_number*>(Treesfact);
		if (!tcmp.empty())
		{
			if (tcmp[0])
				if (ptr->q != ptr2->q) return 0;

			if (tcmp[1])
				if (ptr->w != ptr2->w) return 0;

			if (tcmp[2])
				if (ptr->e != ptr2->e) return 0;
		}
	}
	else if (typeid(op_guards) == typeid(*fact) && typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		op_guards* ptr = dynamic_cast<op_guards*>(fact);
		op_guards* ptr2 = dynamic_cast<op_guards*>(Treesfact);

		if (!tcmp.empty())
		{
			if (tcmp[0])
				if (ptr->q != ptr2->q) return 0;

			if (tcmp[1])
				if (ptr->w != ptr2->w) return 0;

			//vector
			if (tcmp[2])
			{
				if (tcmpV[0].size() > ptr->e.size())
					return 0;

				size_t	siz = tcmpV[0].size();
				for (int i = 0; i < siz; i++)
					if (tcmpV[0][i])
						if (ptr->e[i] != ptr2->e[i]) return 0;
			}
			//vector2
			if (tcmp[3])
			{
				if (tcmpV[1].size() > ptr->r.size())
					return 0;

				size_t	siz = tcmpV[1].size();
				for (int i = 0; i < siz; i++)
					if (tcmpV[1][i])
						if (ptr->r[i] != ptr2->r[i]) return 0;
			}
		}
	}
	else if (typeid(var_guards) == typeid(*fact) && typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		var_guards* ptr = dynamic_cast<var_guards*>(fact);
		var_guards* ptr2 = dynamic_cast<var_guards*>(Treesfact);

		if (!tcmp.empty())
		{
			if (tcmp[0])
				if (ptr->q != ptr2->q) return 0;

			if (tcmp[1])
				if (ptr->w != ptr2->w) return 0;

			//vector
			if (tcmp[2])
			{

				if (tcmpV[0].size() > ptr->q.size())
					return 0;

				size_t	siz = tcmpV[0].size();
				for (int i = 0; i < siz; i++)
					if (tcmpV[0][i])
						if (!(ptr->e[i] == ptr2->e[i])) return 0;
			}
			//vector2
			if (tcmp[3])
			{
				if (tcmpV[1].size() > ptr->q.size())
					return 0;

				size_t	siz = tcmpV[1].size();
				for (int i = 0; i < siz; i++)
					if (tcmpV[1][i])
						if (!(ptr->r[i] == ptr2->r[i])) return 0;
			}
		}
	}
	else if (typeid(guard_pair) == typeid(*fact) && typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		guard_pair* ptr = dynamic_cast<guard_pair*>(fact);
		guard_pair* ptr2 = dynamic_cast<guard_pair*>(Treesfact);
		if (!tcmp.empty())
		{
			if (tcmp[0])
				if (ptr->q != ptr2->q) return 0;

			if (tcmp[1])
				if (ptr->w != ptr2->w) return 0;

			if (tcmp[2])
				if (ptr->e != ptr2->e) return 0;

			if (tcmp[3])
				if (ptr->r != ptr2->r) return 0;
		}
	}
	else if (typeid(guard_cond) == typeid(*fact) && typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		guard_cond* ptr = dynamic_cast<guard_cond*>(fact);
		guard_cond* ptr2 = dynamic_cast<guard_cond*>(Treesfact);
		if (!tcmp.empty())
		{
			if (tcmp[0])
				if (ptr->q != ptr2->q) return 0;

			if (tcmp[1])
				if (ptr->w != ptr2->w) return 0;

			if (tcmp[2])
				if (ptr->e != ptr2->e) return 0;

			if (tcmp[3])
				if (ptr->r != ptr2->r) return 0;
		}
	}
	else if (typeid(predecessors) == typeid(*fact) && typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		predecessors* ptr = dynamic_cast<predecessors*>(fact);
		predecessors* ptr2 = dynamic_cast<predecessors*>(Treesfact);

		if (!tcmp.empty())
		{
			if (tcmp[0])
				if (ptr->q != ptr2->q) return 0;

			if (tcmp[1])
				if (ptr->w != ptr2->w) return 0;

			//vector
			if (tcmp[2])
			{
				if (tcmpV[0].size() > ptr->e.size())
					return 0;

				size_t	siz = tcmpV[0].size();
				for (int i = 0; i < siz; i++)
					if (tcmpV[0][i])
						if (!(ptr->e[i] == ptr2->e[i])) return 0;
			}
		}
	}
	else if (typeid(cessor) == typeid(*fact) && typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		cessor* ptr = dynamic_cast<cessor*>(fact);
		cessor* ptr2 = dynamic_cast<cessor*>(Treesfact);
		if (!tcmp.empty())
		{
			if (tcmp[0])
				if (ptr->q != ptr2->q) return 0;

			if (tcmp[1])
				if (ptr->w != ptr2->w) return 0;

			if (tcmp[2])
				if (ptr->e != ptr2->e) return 0;
		}
	}
	else if (typeid(cessor_kind) == typeid(*fact) && typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		cessor_kind* ptr = dynamic_cast<cessor_kind*>(fact);
		cessor_kind* ptr2 = dynamic_cast<cessor_kind*>(Treesfact);

		if (!tcmp.empty())
		{
			if (tcmp[0])
				if (ptr->q != ptr2->q) return 0;

			if (tcmp[1])
				if (ptr->w != ptr2->w) return 0;

			if (tcmp[2])
				if (ptr->e != ptr2->e) return 0;

			if (tcmp[3])
				if (ptr->r != ptr2->r) return 0;

			if (tcmp[4])
				if (ptr->t != ptr2->t) return 0;

			if (tcmp[5])
				if (ptr->y != ptr2->y) return 0;

			//vector
			if (tcmp[6])
			{
				if (tcmpV[0].size() > ptr->u.size())
					return 0;

				size_t	siz = tcmpV[0].size();
				for (int i = 0; i < siz; i++)
					if (tcmpV[0][i])
						if (!(ptr->u[i] == ptr2->u[i])) return 0;
			}
		}
	}
	else if (typeid(old_schedule) == typeid(*fact) && typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		old_schedule* ptr = dynamic_cast<old_schedule*>(fact);
		old_schedule* ptr2 = dynamic_cast<old_schedule*>(Treesfact);
		if (!tcmp.empty())
		{
			if (tcmp[0])
				if (ptr->q != ptr2->q) return 0;
		}
	}
	else if (typeid(new_schedule) == typeid(*fact) && typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		new_schedule* ptr = dynamic_cast<new_schedule*>(fact);
		new_schedule* ptr2 = dynamic_cast<new_schedule*>(Treesfact);
		if (!tcmp.empty())
		{
			if (tcmp[0])
				if (ptr->q != ptr2->q) return 0;
		}
	}
	else if (typeid(local_ifthen_chain_end_operations_were_written) == typeid(*fact) && typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		local_ifthen_chain_end_operations_were_written* ptr = dynamic_cast<local_ifthen_chain_end_operations_were_written*>(fact);
		local_ifthen_chain_end_operations_were_written* ptr2 = dynamic_cast<local_ifthen_chain_end_operations_were_written*>(Treesfact);
		if (!tcmp.empty())
		{
			if (tcmp[0])
				if (ptr->q != ptr2->q) return 0;
		}
	}
	else if (typeid(calls_list) == typeid(*fact) && typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		calls_list* ptr = dynamic_cast<calls_list*>(fact);
		calls_list* ptr2 = dynamic_cast<calls_list*>(Treesfact);

		if (!tcmp.empty())
		{
			if (tcmp[0])
				if (ptr->q != ptr2->q) return 0;

			if (tcmp[1])
				if (ptr->w != ptr2->w) return 0;

			if (tcmp[2])
				if (ptr->e != ptr2->e) return 0;

			//vector
			if (tcmp[3])
			{
				if (tcmpV[0].size() > ptr->r.size())
					return 0;

				size_t	siz = tcmpV[0].size();
				for (int i = 0; i < siz; i++)
					if (tcmpV[0][i])
						if (!(ptr->r[i] == ptr2->r[i])) return 0;
			}
		}
	}
	else if (typeid(composites_list) == typeid(*fact) && typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		composites_list* ptr = dynamic_cast<composites_list*>(fact);
		composites_list* ptr2 = dynamic_cast<composites_list*>(Treesfact);

		if (!tcmp.empty())
		{
			if (tcmp[0])
				if (ptr->q != ptr2->q) return 0;

			if (tcmp[1])
				if (ptr->w != ptr2->w) return 0;

			//vector
			if (tcmp[2])
			{
				if (tcmpV[0].size() > ptr->e.size())
					return 0;

				size_t	siz = tcmpV[0].size();
				for (int i = 0; i < siz; i++)
					if (tcmpV[0][i])
						if (!(ptr->e[i] == ptr2->e[i])) return 0;
			}
		}
	}
	else if (typeid(record_aggregates_list) == typeid(*fact) && typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		record_aggregates_list* ptr = dynamic_cast<record_aggregates_list*>(fact);
		record_aggregates_list* ptr2 = dynamic_cast<record_aggregates_list*>(Treesfact);

		if (!tcmp.empty())
		{
			if (tcmp[0])
				if (ptr->q != ptr2->q) return 0;

			if (tcmp[1])
				if (ptr->w != ptr2->w) return 0;

			//vector
			if (tcmp[2])
			{
				if (tcmpV[0].size() > ptr->e.size())
					return 0;

				size_t	siz = tcmpV[0].size();
				for (int i = 0; i < siz; i++)
					if (tcmpV[0][i])
						if (!(ptr->e[i] == ptr2->e[i])) return 0;
			}
		}
	}
	else if (typeid(mem_port) == typeid(*fact) && typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		mem_port* ptr = dynamic_cast<mem_port*>(fact);
		mem_port* ptr2 = dynamic_cast<mem_port*>(Treesfact);
		if (!tcmp.empty())
		{
			if (tcmp[0])
				if (ptr->q != ptr2->q) return 0;

			if (tcmp[1])
				if (ptr->w != ptr2->w) return 0;

			if (tcmp[2])
				if (ptr->e != ptr2->e) return 0;

			if (tcmp[3])
				if (ptr->r != ptr2->r) return 0;

			if (tcmp[4])
				if (ptr->t != ptr2->t) return 0;

			if (tcmp[5])
				if (ptr->y != ptr2->y) return 0;

			if (tcmp[6])
				if (ptr->u != ptr2->u) return 0;

			if (tcmp[7])
				if (ptr->i != ptr2->i) return 0;

			if (tcmp[8])
				if (ptr->o != ptr2->o) return 0;

			if (tcmp[9])
				if (ptr->p != ptr2->p) return 0;

			if (tcmp[10])
				if (ptr->a != ptr2->a) return 0;

			if (tcmp[11])
				if (ptr->s != ptr2->s) return 0;

			if (tcmp[12])
				if (ptr->d != ptr2->d) return 0;
		}
	}
	else if (typeid(global_declarations) == typeid(*fact) && typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		global_declarations* ptr = dynamic_cast<global_declarations*>(fact);
		global_declarations* ptr2 = dynamic_cast<global_declarations*>(Treesfact);

		if (!tcmp.empty())
		{

			//vector
			if (tcmp[0])
			{
				if (tcmp.size() > ptr->q.size())
					return 0;

				size_t	siz = tcmpV[0].size();
				for (int i = 0; i < siz; i++)
				{
					if (tcmpV[i][0])
					{
						if (ptr->q[i].q != ptr2->q[i].q) return 0;
					}
					if (tcmpV[i][1])
					{
						if (ptr->q[i].w != ptr2->q[i].w) return 0;
					}
					if (tcmpV[i][2])
					{
						if (ptr->q[i].e != ptr2->q[i].e) return 0;
					}
					if (tcmpV[i][3])
					{
						if (ptr->q[i].r != ptr2->q[i].r) return 0;
					}
					if (tcmpV[i][4])
					{
						if (ptr->q[i].t != ptr2->q[i].t) return 0;
					}
					if (tcmpV[i][5])
					{
						if (ptr->q[i].y != ptr2->q[i].y) return 0;
					}
					if (tcmpV[i][6])
					{
						if (ptr->q[i].u != ptr2->q[i].u) return 0;
					}
					if (tcmpV[i][7])
					{
						if (ptr->q[i].i != ptr2->q[i].i) return 0;
					}
					if (tcmpV[i][8])
					{
						if (ptr->q[i].o != ptr2->q[i].o) return 0;
					}
				}
			}
			if (tcmp[1])
				if (ptr->w != ptr2->w) return 0;
		}
	}
	else if (typeid(source_is_normal_dt) == typeid(*fact) && typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		source_is_normal_dt* ptr = dynamic_cast<source_is_normal_dt*>(fact);
		source_is_normal_dt* ptr2 = dynamic_cast<source_is_normal_dt*>(Treesfact);
		if (!tcmp.empty())
		{
			if (tcmp[0])
				if (ptr->q != ptr2->q) return 0;

			if (tcmp[1])
				if (ptr->w != ptr2->w) return 0;

			if (tcmp[2])
				if (ptr->e != ptr2->e) return 0;
		}
	}
	else if (typeid(combo) == typeid(*fact) && typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		combo* ptr = dynamic_cast<combo*>(fact);
		combo* ptr2 = dynamic_cast<combo*>(Treesfact);
		if (!tcmp.empty())
		{
			if (tcmp[0])
				if (ptr->q != ptr2->q) return 0;

			if (tcmp[1])
				if (ptr->w != ptr2->w) return 0;

			if (tcmp[2])
				if (ptr->e != ptr2->e) return 0;
		}
	}
	else if (typeid(sequence) == typeid(*fact) && typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		sequence* ptr = dynamic_cast<sequence*>(fact);
		sequence* ptr2 = dynamic_cast<sequence*>(Treesfact);
		if (!tcmp.empty())
		{
			if (tcmp[0])
				if (ptr->q != ptr2->q) return 0;

			if (tcmp[1])
				if (ptr->w != ptr2->w) return 0;

			if (tcmp[2])
				if (ptr->e != ptr2->e) return 0;
		}
	}
	else if (typeid(for_loop) == typeid(*fact) && typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		for_loop* ptr = dynamic_cast<for_loop*>(fact);
		for_loop* ptr2 = dynamic_cast<for_loop*>(Treesfact);
		if (!tcmp.empty())
		{
			if (tcmp[0])
				if (ptr->q != ptr2->q) return 0;

			if (tcmp[1])
				if (ptr->w != ptr2->w) return 0;

			if (tcmp[2])
				if (ptr->e != ptr2->e) return 0;

			if (tcmp[3])
				if (ptr->r != ptr2->r) return 0;

			if (tcmp[4])
				if (ptr->t != ptr2->t) return 0;

			if (tcmp[5])
				if (ptr->y != ptr2->y) return 0;

			if (tcmp[6])
				if (ptr->u != ptr2->u) return 0;

			if (tcmp[7])
				if (ptr->i != ptr2->i) return 0;

			if (tcmp[8])
				if (ptr->o != ptr2->o) return 0;

			if (tcmp[9])
				if (ptr->p != ptr2->p) return 0;

			if (tcmp[10])
				if (ptr->a != ptr2->a) return 0;

			if (tcmp[11])
				if (ptr->s != ptr2->s) return 0;

			if (tcmp[12])
				if (ptr->d != ptr2->d) return 0;
		}
	}
	else if (typeid(last_for_loop_entry) == typeid(*fact) && typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		last_for_loop_entry* ptr = dynamic_cast<last_for_loop_entry*>(fact);
		last_for_loop_entry* ptr2 = dynamic_cast<last_for_loop_entry*>(Treesfact);
		if (!tcmp.empty())
		{
			if (tcmp[0])
				if (ptr->q != ptr2->q) return 0;
		}
	}
	else if (typeid(while_loop) == typeid(*fact) && typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		while_loop* ptr = dynamic_cast<while_loop*>(fact);
		while_loop* ptr2 = dynamic_cast<while_loop*>(Treesfact);
		if (!tcmp.empty())
		{
			if (tcmp[0])
				if (ptr->q != ptr2->q) return 0;

			if (tcmp[1])
				if (ptr->w != ptr2->w) return 0;

			if (tcmp[2])
				if (ptr->e != ptr2->e) return 0;

			if (tcmp[3])
				if (ptr->r != ptr2->r) return 0;

			if (tcmp[4])
				if (ptr->t != ptr2->t) return 0;

			if (tcmp[5])
				if (ptr->y != ptr2->y) return 0;

			if (tcmp[6])
				if (ptr->u != ptr2->u) return 0;
		}
	}
	else if (typeid(last_while_loop_entry) == typeid(*fact) && typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		last_while_loop_entry* ptr = dynamic_cast<last_while_loop_entry*>(fact);
		last_while_loop_entry* ptr2 = dynamic_cast<last_while_loop_entry*>(Treesfact);
		if (!tcmp.empty())
		{
			if (tcmp[0])
				if (ptr->q != ptr2->q) return 0;
		}
	}
	else if (typeid(possible_end_if) == typeid(*fact) && typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		possible_end_if* ptr = dynamic_cast<possible_end_if*>(fact);
		possible_end_if* ptr2 = dynamic_cast<possible_end_if*>(Treesfact);
		if (tcmpV[0].size() > ptr->w.size())
			return 0;

		if (!tcmp.empty())
		{
			if (tcmp[0])
				if (ptr->q != ptr2->q) return 0;

			//vector
			if (tcmp[1])
			{
				size_t	siz = tcmpV[0].size();
				for (int i = 0; i < siz; i++)
					if (tcmpV[0][i])
						if (!(ptr->w[i] == ptr2->w[i])) return 0;
			}
		}
	}
	else if (typeid(end_if) == typeid(*fact) && typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		end_if* ptr = dynamic_cast<end_if*>(fact);
		end_if* ptr2 = dynamic_cast<end_if*>(Treesfact);

		if (!tcmp.empty())
		{
			if (tcmp[0])
				if (ptr->q != ptr2->q) return 0;

			//vector
			if (tcmp[1])
			{
				if (tcmpV[0].size() > ptr->w.size())
					return 0;

				size_t	siz = tcmpV[0].size();
				for (int i = 0; i < siz; i++)
					if (tcmpV[0][i])
						if (!(ptr->w[i] == ptr2->w[i])) return 0;
			}
		}
	}
	else if (typeid(nested_cond_fact) == typeid(*fact) && typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		nested_cond_fact* ptr = dynamic_cast<nested_cond_fact*>(fact);
		nested_cond_fact* ptr2 = dynamic_cast<nested_cond_fact*>(Treesfact);

		if (!tcmp.empty())
		{
			if (tcmp[0])
				if (ptr->q != ptr2->q) return 0;

			//vector
			if (tcmp[1])
			{
				if (tcmpV[0].size() > ptr->w.size())
					return 0;

				size_t	siz = tcmpV[0].size();
				for (int i = 0; i < siz; i++)
					if (tcmpV[0][i])
						if (!(ptr->w[i] == ptr2->w[i])) return 0;
			}
		}
	}
	else if (typeid(top_level_call) == typeid(*fact) && typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		top_level_call* ptr = dynamic_cast<top_level_call*>(fact);
		top_level_call* ptr2 = dynamic_cast<top_level_call*>(Treesfact);
		if (!tcmp.empty())
		{
			if (tcmp[0])
				if (ptr->q != ptr2->q) return 0;

			if (tcmp[1])
				if (ptr->w != ptr2->w) return 0;

			if (tcmp[2])
				if (ptr->e != ptr2->e) return 0;

			if (tcmp[3])
				if (ptr->r != ptr2->r) return 0;

			if (tcmp[4])
				if (ptr->t != ptr2->t) return 0;

			if (tcmp[5])
				if (ptr->y != ptr2->y) return 0;

			if (tcmp[6])
				if (ptr->u != ptr2->u) return 0;

			if (tcmp[7])
				if (ptr->i != ptr2->i) return 0;

			if (tcmp[8])
				if (ptr->o != ptr2->o) return 0;

			if (tcmp[9])
				if (ptr->p != ptr2->p) return 0;
		}
	}
	else if (typeid(top_level_call_parcs) == typeid(*fact) && typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		top_level_call_parcs* ptr = dynamic_cast<top_level_call_parcs*>(fact);
		top_level_call_parcs* ptr2 = dynamic_cast<top_level_call_parcs*>(Treesfact);
		if (!tcmp.empty())
		{
			if (tcmp[0])
				if (ptr->q != ptr2->q) return 0;

			if (tcmp[1])
				if (ptr->w != ptr2->w) return 0;

			if (tcmp[2])
				if (ptr->e != ptr2->e) return 0;

			if (tcmp[3])
				if (ptr->r != ptr2->r) return 0;

			if (tcmp[4])
				if (ptr->t != ptr2->t) return 0;

			if (tcmp[5])
				if (ptr->y != ptr2->y) return 0;

			if (tcmp[6])
				if (ptr->u != ptr2->u) return 0;

			if (tcmp[7])
				if (ptr->i != ptr2->i) return 0;

			if (tcmp[8])
				if (ptr->o != ptr2->o) return 0;

			if (tcmp[9])
				if (ptr->p != ptr2->p) return 0;
		}
	}
	else if (typeid(added_aux_call_ios) == typeid(*fact) && typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		added_aux_call_ios* ptr = dynamic_cast<added_aux_call_ios*>(fact);
		added_aux_call_ios* ptr2 = dynamic_cast<added_aux_call_ios*>(Treesfact);
		if (!tcmp.empty())
		{
			if (tcmp[0])
				if (ptr->q != ptr2->q) return 0;

			if (tcmp[1])
				if (ptr->w != ptr2->w) return 0;
		}
	}
	else if (typeid(added_aux_call_ios1) == typeid(*fact) && typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		added_aux_call_ios1* ptr = dynamic_cast<added_aux_call_ios1*>(fact);
		added_aux_call_ios1* ptr2 = dynamic_cast<added_aux_call_ios1*>(Treesfact);
		if (!tcmp.empty())
		{
			if (tcmp[0])
				if (ptr->q != ptr2->q) return 0;

			if (tcmp[1])
				if (ptr->w != ptr2->w) return 0;

			if (tcmp[2])
				if (ptr->e != ptr2->e) return 0;
		}
	}
	else if (typeid(added_aux_call_signals) == typeid(*fact) && typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		added_aux_call_signals* ptr = dynamic_cast<added_aux_call_signals*>(fact);
		added_aux_call_signals* ptr2 = dynamic_cast<added_aux_call_signals*>(Treesfact);
		if (!tcmp.empty())
		{
			if (tcmp[0])
				if (ptr->q != ptr2->q) return 0;

			if (tcmp[1])
				if (ptr->w != ptr2->w) return 0;
		}
	}
	else if (typeid(found_call_operator) == typeid(*fact) && typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		found_call_operator* ptr = dynamic_cast<found_call_operator*>(fact);
		found_call_operator* ptr2 = dynamic_cast<found_call_operator*>(Treesfact);
		if (!tcmp.empty())
		{
			if (tcmp[0])
				if (ptr->q != ptr2->q) return 0;

			if (tcmp[1])
				if (ptr->w != ptr2->w) return 0;
		}
	}
	else if (typeid(added_verilog_aux_call_outputs) == typeid(*fact) && typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		added_verilog_aux_call_outputs* ptr = dynamic_cast<added_verilog_aux_call_outputs*>(fact);
		added_verilog_aux_call_outputs* ptr2 = dynamic_cast<added_verilog_aux_call_outputs*>(Treesfact);
		if (!tcmp.empty())
		{
			if (tcmp[0])
				if (ptr->q != ptr2->q) return 0;

			if (tcmp[1])
				if (ptr->w != ptr2->w) return 0;

			if (tcmp[2])
				if (ptr->e != ptr2->e) return 0;
		}
	}
	else if (typeid(raw_dependencies) == typeid(*fact) && typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		raw_dependencies* ptr = dynamic_cast<raw_dependencies*>(fact);
		raw_dependencies* ptr2 = dynamic_cast<raw_dependencies*>(Treesfact);
		if (!tcmp.empty())
		{
			if (tcmp[0])
				if (ptr->q != ptr2->q) return 0;

			if (tcmp[1])
				if (ptr->w != ptr2->w) return 0;

			//vector
			if (tcmp[2])
			{
				if (tcmpV[0].size() > ptr->e.size())
					return 0;

				size_t	siz = tcmpV[0].size();
				for (int i = 0; i < siz; i++)
					if (tcmpV[0][i])
						if (!(ptr->e[i] == ptr2->e[i])) return 0;
			}

			//vector2
			if (tcmp[3])
			{
				if (tcmpV[1].size() > ptr->r.size())
					return 0;

				size_t	siz = tcmpV[1].size();
				for (int i = 0; i < siz; i++)
					if (tcmpV[1][i])
						if (!(ptr->r[i] == ptr2->r[i])) return 0;
			}
		}
	}
	else if (typeid(war_dependencies) == typeid(*fact) && typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		war_dependencies* ptr = dynamic_cast<war_dependencies*>(fact);
		war_dependencies* ptr2 = dynamic_cast<war_dependencies*>(Treesfact);

		if (!tcmp.empty())
		{
			if (tcmp[0])
				if (ptr->q != ptr2->q) return 0;

			if (tcmp[1])
				if (ptr->w != ptr2->w) return 0;

			//vector
			if (tcmp[2])
			{
				if (tcmpV[0].size() > ptr->e.size())
					return 0;

				size_t	siz = tcmpV[0].size();
				for (int i = 0; i < siz; i++)
					if (tcmpV[0][i])
						if (!(ptr->e[i] == ptr2->e[i])) return 0;
			}

			//vector2
			if (tcmp[3])
			{
				if (tcmpV[1].size() > ptr->r.size())
					return 0;

				size_t	siz = tcmpV[1].size();
				for (int i = 0; i < siz; i++)
					if (tcmpV[1][i])
						if (!(ptr->r[i] == ptr2->r[i])) return 0;
			}
		}
	}
	else if (typeid(waw_dependencies) == typeid(*fact) && typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		waw_dependencies* ptr = dynamic_cast<waw_dependencies*>(fact);
		waw_dependencies* ptr2 = dynamic_cast<waw_dependencies*>(Treesfact);

		if (!tcmp.empty())
		{
			if (tcmp[0])
				if (ptr->q != ptr2->q) return 0;

			if (tcmp[1])
				if (ptr->w != ptr2->w) return 0;

			//vector
			if (tcmp[2])
			{
				if (tcmpV[0].size() > ptr->e.size())
					return 0;

				size_t	siz = tcmpV[0].size();
				for (int i = 0; i < siz; i++)
					if (tcmpV[0][i])
						if (!(ptr->e[i] == ptr2->e[i])) return 0;
			}

			//vector2
			if (tcmp[3])
			{
				if (tcmpV[1].size() > ptr->r.size())
					return 0;

				size_t	siz = tcmpV[1].size();
				for (int i = 0; i < siz; i++)
					if (tcmpV[1][i])
						if (!(ptr->r[i] == ptr2->r[i])) return 0;
			}
		}
	}
	else if (typeid(schedule) == typeid(*fact) && typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		schedule* ptr = dynamic_cast<schedule*>(fact);
		schedule* ptr2 = dynamic_cast<schedule*>(Treesfact);
		if (!tcmp.empty())
		{
			if (tcmp[0])
				if (ptr->q != ptr2->q) return 0;

			if (tcmp[1])
				if (ptr->w != ptr2->w) return 0;

			if (tcmp[2])
				if (ptr->e != ptr2->e) return 0;

			if (tcmp[3])
				if (ptr->r != ptr2->r) return 0;
		}
	}
	else if (typeid(last_conditional_execution) == typeid(*fact) && typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		last_conditional_execution* ptr = dynamic_cast<last_conditional_execution*>(fact);
		last_conditional_execution* ptr2 = dynamic_cast<last_conditional_execution*>(Treesfact);
		if (!tcmp.empty())
		{
			if (tcmp[0])
				if (ptr->q != ptr2->q) return 0;

			if (tcmp[1])
				if (ptr->w != ptr2->w) return 0;
		}
	}
	else if (typeid(conditional_operations) == typeid(*fact) && typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		conditional_operations* ptr = dynamic_cast<conditional_operations*>(fact);
		conditional_operations* ptr2 = dynamic_cast<conditional_operations*>(Treesfact);

		if (!tcmp.empty())
		{
			if (tcmp[0])
				if (ptr->q != ptr2->q) return 0;

			if (tcmp[1])
				if (ptr->w != ptr2->w) return 0;

			if (tcmp[2])
				if (ptr->e != ptr2->e) return 0;

			if (tcmp[3])
				if (ptr->r != ptr2->r) return 0;

			//vector
			if (tcmp[4])
			{
				if (tcmpV[0].size() > ptr->t.size())
					return 0;

				size_t	siz = tcmpV[0].size();
				for (int i = 0; i < siz; i++)
					if (tcmpV[0][i])
						if (!(ptr->t[i] == ptr2->t[i])) return 0;
			}

			//vector2
			if (tcmp[5])
			{
				if (tcmpV[1].size() > ptr->y.size())
					return 0;

				size_t	siz = tcmpV[1].size();
				for (int i = 0; i < siz; i++)
					if (tcmpV[1][i])
						if (!(ptr->y[i] == ptr2->y[i])) return 0;
			}

			//vector3
			if (tcmp[6])
			{
				if (tcmpV[2].size() > ptr->u.size())
					return 0;

				size_t	siz = tcmpV[2].size();
				for (int i = 0; i < siz; i++)
					if (tcmpV[2][i])
						if (!(ptr->u[i] == ptr2->u[i])) return 0;
			}

			//vector4
			if (tcmp[7])
			{
				if (tcmpV[3].size() > ptr->i.size())
					return 0;

				size_t	siz = tcmpV[3].size();
				for (int i = 0; i < siz; i++)
					if (tcmpV[3][i])
						if (!(ptr->i[i] == ptr2->i[i])) return 0;
			}
		}
	}
	else if (typeid(last_conditional_transition_of_schedule) == typeid(*fact) && typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		last_conditional_transition_of_schedule* ptr = dynamic_cast<last_conditional_transition_of_schedule*>(fact);
		last_conditional_transition_of_schedule* ptr2 = dynamic_cast<last_conditional_transition_of_schedule*>(Treesfact);
		if (!tcmp.empty())
		{
			if (tcmp[0])
				if (ptr->q != ptr2->q) return 0;

			if (tcmp[1])
				if (ptr->w != ptr2->w) return 0;

			if (tcmp[2])
				if (ptr->e != ptr2->e) return 0;
		}
	}
	else if (typeid(transition_to_be_rescheduled) == typeid(*fact) && typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		transition_to_be_rescheduled* ptr = dynamic_cast<transition_to_be_rescheduled*>(fact);
		transition_to_be_rescheduled* ptr2 = dynamic_cast<transition_to_be_rescheduled*>(Treesfact);
		if (!tcmp.empty())
		{
			if (tcmp[0])
				if (ptr->q != ptr2->q) return 0;

			if (tcmp[1])
				if (ptr->w != ptr2->w) return 0;

			if (tcmp[2])
				if (ptr->e != ptr2->e) return 0;

			if (tcmp[3])
				if (ptr->r != ptr2->r) return 0;

			if (tcmp[4])
				if (ptr->t != ptr2->t) return 0;
		}
	}
	else if (typeid(last_conditional_transition) == typeid(*fact) && typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		last_conditional_transition* ptr = dynamic_cast<last_conditional_transition*>(fact);
		last_conditional_transition* ptr2 = dynamic_cast<last_conditional_transition*>(Treesfact);
		if (!tcmp.empty())
		{
			if (tcmp[0])
				if (ptr->q != ptr2->q) return 0;

			if (tcmp[1])
				if (ptr->w != ptr2->w) return 0;
		}
	}
	else if (typeid(conditional_transitions) == typeid(*fact) && typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		conditional_transitions* ptr = dynamic_cast<conditional_transitions*>(fact);
		conditional_transitions* ptr2 = dynamic_cast<conditional_transitions*>(Treesfact);
		if (!tcmp.empty())
		{
			if (tcmp[0])
				if (ptr->q != ptr2->q) return 0;

			if (tcmp[1])
				if (ptr->w != ptr2->w) return 0;

			if (tcmp[2])
				if (ptr->e != ptr2->e) return 0;

			if (tcmp[3])
				if (ptr->r != ptr2->r) return 0;

			if (tcmp[4])
				if (ptr->t != ptr2->t) return 0;

			if (tcmp[5])
				if (ptr->y != ptr2->y) return 0;

			if (tcmp[6])
				if (ptr->u != ptr2->u) return 0;

			if (tcmp[7])
				if (ptr->i != ptr2->i) return 0;
		}
	}
	else if (typeid(state) == typeid(*fact) && typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		state* ptr = dynamic_cast<state*>(fact);
		state* ptr2 = dynamic_cast<state*>(Treesfact);

		if (!tcmp.empty())
		{
			if (tcmp[0])
				if (ptr->q != ptr2->q) return 0;

			if (tcmp[1])
				if (ptr->w != ptr2->w) return 0;

			if (tcmp[2])
				if (ptr->e != ptr2->e) return 0;

			if (tcmp[3])
				if (ptr->r != ptr2->r) return 0;

			if (tcmp[4])
				if (ptr->t != ptr2->t) return 0;

			if (tcmp[5])
				if (ptr->y != ptr2->y) return 0;

			//vector
			if (tcmp[6])
			{
				if (tcmpV[0].size() > ptr->u.size())
					return 0;

				size_t	siz = tcmpV[0].size();
				for (int i = 0; i < siz; i++)
					if (tcmpV[0][i])
						if (!(ptr->u[i] == ptr2->u[i])) return 0;
			}

			//vector2
			if (tcmp[7])
			{
				if (tcmpV[1].size() > ptr->i.size())
					return 0;

				size_t	siz = tcmpV[1].size();
				for (int i = 0; i < siz; i++)
					if (tcmpV[1][i])
						if (!(ptr->i[i] == ptr2->i[i])) return 0;
			}
		}
	}
	else if (typeid(rescheduled) == typeid(*fact) && typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		rescheduled* ptr = dynamic_cast<rescheduled*>(fact);
		rescheduled* ptr2 = dynamic_cast<rescheduled*>(Treesfact);
		if (!tcmp.empty())
		{
			if (tcmp[0])
				if (ptr->q != ptr2->q) return 0;

			if (tcmp[1])
				if (ptr->w != ptr2->w) return 0;

			if (tcmp[2])
				if (ptr->e != ptr2->e) return 0;

			if (tcmp[3])
				if (ptr->r != ptr2->r) return 0;

			if (tcmp[4])
				if (ptr->t != ptr2->t) return 0;
		}
	}
	else if (typeid(last_rescheduled) == typeid(*fact) && typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		last_rescheduled* ptr = dynamic_cast<last_rescheduled*>(fact);
		last_rescheduled* ptr2 = dynamic_cast<last_rescheduled*>(Treesfact);
		if (!tcmp.empty())
		{
			if (tcmp[0])
				if (ptr->q != ptr2->q) return 0;

			if (tcmp[1])
				if (ptr->w != ptr2->w) return 0;

			if (tcmp[2])
				if (ptr->e != ptr2->e) return 0;

			if (tcmp[3])
				if (ptr->r != ptr2->r) return 0;

			if (tcmp[4])
				if (ptr->t != ptr2->t) return 0;
		}
	}
	else if (typeid(raw_cessor) == typeid(*fact) && typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		raw_cessor* ptr = dynamic_cast<raw_cessor*>(fact);
		raw_cessor* ptr2 = dynamic_cast<raw_cessor*>(Treesfact);
		if (!tcmp.empty())
		{
			if (tcmp[0])
				if (ptr->q != ptr2->q) return 0;

			if (tcmp[1])
				if (ptr->w != ptr2->w) return 0;

			if (tcmp[2])
				if (ptr->e != ptr2->e) return 0;
		}
	}
	else if (typeid(war_cessor) == typeid(*fact) && typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		war_cessor* ptr = dynamic_cast<war_cessor*>(fact);
		war_cessor* ptr2 = dynamic_cast<war_cessor*>(Treesfact);
		if (!tcmp.empty())
		{
			if (tcmp[0])
				if (ptr->q != ptr2->q) return 0;

			if (tcmp[1])
				if (ptr->w != ptr2->w) return 0;

			if (tcmp[2])
				if (ptr->e != ptr2->e) return 0;
		}
	}
	else if (typeid(waw_cessor) == typeid(*fact) && typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		waw_cessor* ptr = dynamic_cast<waw_cessor*>(fact);
		waw_cessor* ptr2 = dynamic_cast<waw_cessor*>(Treesfact);
		if (!tcmp.empty())
		{
			if (tcmp[0])
				if (ptr->q != ptr2->q) return 0;

			if (tcmp[1])
				if (ptr->w != ptr2->w) return 0;

			if (tcmp[2])
				if (ptr->e != ptr2->e) return 0;
		}
	}
	else if (typeid(op_resource) == typeid(*fact) && typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		op_resource* ptr = dynamic_cast<op_resource*>(fact);
		op_resource* ptr2 = dynamic_cast<op_resource*>(Treesfact);
		if (!tcmp.empty())
		{
			if (tcmp[0])
				if (ptr->q != ptr2->q) return 0;

			if (tcmp[1])
				if (ptr->w != ptr2->w) return 0;

			if (tcmp[2])
				if (ptr->e != ptr2->e) return 0;
		}
	}
	else if (typeid(global_resource) == typeid(*fact) && typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		global_resource* ptr = dynamic_cast<global_resource*>(fact);
		global_resource* ptr2 = dynamic_cast<global_resource*>(Treesfact);
		if (!tcmp.empty())
		{
			if (tcmp[0])
				if (ptr->q != ptr2->q) return 0;
		}
	}
	else if (typeid(module_g_resource) == typeid(*fact) && typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		module_g_resource* ptr = dynamic_cast<module_g_resource*>(fact);
		module_g_resource* ptr2 = dynamic_cast<module_g_resource*>(Treesfact);
		if (!tcmp.empty())
		{
			if (tcmp[0])
				if (ptr->q != ptr2->q) return 0;

			if (tcmp[1])
				if (ptr->w != ptr2->w) return 0;
		}
	}
	else if (typeid(cf_previous_op) == typeid(*fact) && typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		cf_previous_op* ptr = dynamic_cast<cf_previous_op*>(fact);
		cf_previous_op* ptr2 = dynamic_cast<cf_previous_op*>(Treesfact);
		if (!tcmp.empty())
		{
			if (tcmp[0])
				if (ptr->q != ptr2->q) return 0;

			if (tcmp[1])
				if (ptr->w != ptr2->w) return 0;

			if (tcmp[2])
				if (ptr->e != ptr2->e) return 0;

			if (tcmp[3])
				if (ptr->r != ptr2->r) return 0;
		}
	}
	else if (typeid(cf_previous_state) == typeid(*fact) && typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		cf_previous_state* ptr = dynamic_cast<cf_previous_state*>(fact);
		cf_previous_state* ptr2 = dynamic_cast<cf_previous_state*>(Treesfact);
		if (!tcmp.empty())
		{
			if (tcmp[0])
				if (ptr->q != ptr2->q) return 0;

			if (tcmp[1])
				if (ptr->w != ptr2->w) return 0;

			if (tcmp[2])
				if (ptr->e != ptr2->e) return 0;

			if (tcmp[3])
				if (ptr->r != ptr2->r) return 0;
		}
	}
	else if (typeid(pred_candidate_examined) == typeid(*fact) && typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		pred_candidate_examined* ptr = dynamic_cast<pred_candidate_examined*>(fact);
		pred_candidate_examined* ptr2 = dynamic_cast<pred_candidate_examined*>(Treesfact);
		if (!tcmp.empty())
		{
			if (tcmp[0])
				if (ptr->q != ptr2->q) return 0;

			if (tcmp[1])
				if (ptr->w != ptr2->w) return 0;

			if (tcmp[2])
				if (ptr->e != ptr2->e) return 0;
		}
	}
	else if (typeid(reentrant_triangle) == typeid(*fact) && typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		reentrant_triangle* ptr = dynamic_cast<reentrant_triangle*>(fact);
		reentrant_triangle* ptr2 = dynamic_cast<reentrant_triangle*>(Treesfact);

		if (!tcmp.empty())
		{
			if (tcmp[0])
				if (ptr->q != ptr2->q) return 0;

			if (tcmp[1])
				if (ptr->w != ptr2->w) return 0;

			if (tcmp[2])
				if (ptr->e != ptr2->e) return 0;

			if (tcmp[3])
				if (ptr->r != ptr2->r) return 0;

			//vector
			if (tcmp[4])
			{
				if (tcmpV[0].size() > ptr->t.size())
					return 0;

				size_t	siz = tcmpV[0].size();
				for (int i = 0; i < siz; i++)
					if (tcmpV[0][i])
						if (!(ptr->t[i] == ptr2->t[i])) return 0;
			}

			//vector2
			if (tcmp[5])
			{
				if (tcmpV[1].size() > ptr->y.size())
					return 0;

				size_t	siz = tcmpV[1].size();
				for (int i = 0; i < siz; i++)
					if (tcmpV[1][i])
						if (!(ptr->y[i] == ptr2->y[i])) return 0;
			}

			//vector3
			if (tcmp[6])
			{
				if (tcmpV[2].size() > ptr->u.size())
					return 0;

				size_t	siz = tcmpV[2].size();
				for (int i = 0; i < siz; i++)
					if (tcmpV[2][i])
						if (!(ptr->u[i] == ptr2->u[i])) return 0;
			}

			//vector4
			if (tcmp[7])
			{
				if (tcmpV[3].size() > ptr->i.size())
					return 0;

				size_t	siz = tcmpV[3].size();
				for (int i = 0; i < siz; i++)
					if (tcmpV[3][i])
						if (!(ptr->i[i] == ptr2->i[i])) return 0;
			}

			//vector5
			if (tcmp[8])
			{
				if (tcmpV[4].size() > ptr->o.size())
					return 0;

				size_t	siz = tcmpV[4].size();
				for (int i = 0; i < siz; i++)
					if (tcmpV[4][i])
						if (!(ptr->o[i] == ptr2->o[i])) return 0;
			}

			//vector6
			if (tcmp[9])
			{
				if (tcmpV[5].size() > ptr->p.size())
					return 0;

				size_t	siz = tcmpV[5].size();
				for (int i = 0; i < siz; i++)
					if (tcmpV[5][i])
						if (!(ptr->p[i] == ptr2->p[i])) return 0;
			}

			if (tcmp[10])
				if (ptr->a != ptr2->a) return 0;

			if (tcmp[11])
				if (ptr->s != ptr2->s) return 0;

			if (tcmp[12])
				if (ptr->d != ptr2->d) return 0;
		}
	}
	else if (typeid(last_reentrant_triangle) == typeid(*fact) && typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		last_reentrant_triangle* ptr = dynamic_cast<last_reentrant_triangle*>(fact);
		last_reentrant_triangle* ptr2 = dynamic_cast<last_reentrant_triangle*>(Treesfact);
		if (!tcmp.empty())
		{
			if (tcmp[0])
				if (ptr->q != ptr2->q) return 0;

			if (tcmp[1])
				if (ptr->w != ptr2->w) return 0;
		}
	}
	else if (typeid(last_schedule_state) == typeid(*fact) && typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		last_schedule_state* ptr = dynamic_cast<last_schedule_state*>(fact);
		last_schedule_state* ptr2 = dynamic_cast<last_schedule_state*>(Treesfact);
		if (!tcmp.empty())
		{
			if (tcmp[0])
				if (ptr->q != ptr2->q) return 0;

			if (tcmp[1])
				if (ptr->w != ptr2->w) return 0;

			if (tcmp[2])
				if (ptr->e != ptr2->e) return 0;
		}
	}
	else if (typeid(conditional_incomplete) == typeid(*fact) && typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		conditional_incomplete* ptr = dynamic_cast<conditional_incomplete*>(fact);
		conditional_incomplete* ptr2 = dynamic_cast<conditional_incomplete*>(Treesfact);

		if (!tcmp.empty())
		{
			if (tcmp[0])
				if (ptr->q != ptr2->q) return 0;

			if (tcmp[1])
				if (ptr->w != ptr2->w) return 0;

			if (tcmp[2])
				if (ptr->e != ptr2->e) return 0;

			if (tcmp[3])
				if (ptr->r != ptr2->r) return 0;

			//vector
			if (tcmp[4])
			{
				if (tcmpV[0].size() > ptr->t.size())
					return 0;

				size_t	siz = tcmpV[0].size();
				for (int i = 0; i < siz; i++)
					if (tcmpV[0][i])
						if (!(ptr->t[i] == ptr2->t[i])) return 0;
			}

			//vector2
			if (tcmp[5])
			{
				if (tcmpV[1].size() > ptr->y.size())
					return 0;

				size_t	siz = tcmpV[1].size();
				for (int i = 0; i < siz; i++)
					if (tcmpV[1][i])
						if (!(ptr->y[i] == ptr2->y[i])) return 0;
			}

			//vector3
			if (tcmp[6])
			{
				if (tcmpV[2].size() > ptr->u.size())
					return 0;

				size_t	siz = tcmpV[2].size();
				for (int i = 0; i < siz; i++)
					if (tcmpV[2][i])
						if (!(ptr->u[i] == ptr2->u[i])) return 0;
			}

			//vector4
			if (tcmp[7])
			{
				if (tcmpV[3].size() > ptr->i.size())
					return 0;

				size_t	siz = tcmpV[3].size();
				for (int i = 0; i < siz; i++)
					if (tcmpV[3][i])
						if (!(ptr->i[i] == ptr2->i[i])) return 0;
			}

			//vector5
			if (tcmp[8])
			{
				if (tcmpV[4].size() > ptr->o.size())
					return 0;

				size_t	siz = tcmpV[4].size();
				for (int i = 0; i < siz; i++)
					if (tcmpV[4][i])
						if (!(ptr->o[i] == ptr2->o[i])) return 0;
			}

			//vector6
			if (tcmp[9])
			{
				if (tcmpV[5].size() > ptr->p.size())
					return 0;

				size_t	siz = tcmpV[5].size();
				for (int i = 0; i < siz; i++)
					if (tcmpV[5][i])
						if (!(ptr->p[i] == ptr2->p[i])) return 0;
			}

			if (tcmp[10])
				if (ptr->a != ptr2->a) return 0;

			if (tcmp[11])
				if (ptr->s != ptr2->s) return 0;

			if (tcmp[12])
				if (ptr->d != ptr2->d) return 0;

			if (tcmp[13])
				if (ptr->f != ptr2->f) return 0;

			if (tcmp[14])
				if (ptr->g != ptr2->g) return 0;

			if (tcmp[15])
				if (ptr->h != ptr2->h) return 0;

			if (tcmp[16])
				if (ptr->j != ptr2->j) return 0;

			if (tcmp[17])
				if (ptr->k != ptr2->k) return 0;

			if (tcmp[18])
				if (ptr->l != ptr2->l) return 0;

			if (tcmp[19])
				if (ptr->z != ptr2->z) return 0;

			if (tcmp[20])
				if (ptr->x != ptr2->x) return 0;
		}
	}
	else if (typeid(mixed_incomplete_state_lists) == typeid(*fact) && typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		mixed_incomplete_state_lists* ptr = dynamic_cast<mixed_incomplete_state_lists*>(fact);
		mixed_incomplete_state_lists* ptr2 = dynamic_cast<mixed_incomplete_state_lists*>(Treesfact);

		if (!tcmp.empty())
		{
			if (tcmp[0])
				if (ptr->q != ptr2->q) return 0;

			if (tcmp[1])
				if (ptr->w != ptr2->w) return 0;

			if (tcmp[2])
				if (ptr->e != ptr2->e) return 0;

			//vector
			if (tcmp[3])
			{
				if (tcmpV[0].size() > ptr->r.size())
					return 0;

				size_t	siz = tcmpV[0].size();
				for (int i = 0; i < siz; i++)
					if (tcmpV[0][i])
						if (!(ptr->r[i] == ptr2->r[i])) return 0;
			}

			//vector2
			if (tcmp[4])
			{
				if (tcmpV[1].size() > ptr->t.size())
					return 0;

				size_t	siz = tcmpV[1].size();
				for (int i = 0; i < siz; i++)
					if (tcmpV[1][i])
						if (!(ptr->t[i] == ptr2->t[i])) return 0;
			}
		}
	}
	else if (typeid(linear_incomplete_node) == typeid(*fact) && typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		linear_incomplete_node* ptr = dynamic_cast<linear_incomplete_node*>(fact);
		linear_incomplete_node* ptr2 = dynamic_cast<linear_incomplete_node*>(Treesfact);

		if (!tcmp.empty())
		{
			if (tcmp[0])
				if (ptr->q != ptr2->q) return 0;

			if (tcmp[1])
				if (ptr->w != ptr2->w) return 0;

			if (tcmp[2])
				if (ptr->e != ptr2->e) return 0;

			//vector
			if (tcmp[3])
			{
				if (tcmpV[0].size() > ptr->r.size())
					return 0;

				size_t	siz = tcmpV[0].size();
				for (int i = 0; i < siz; i++)
					if (tcmpV[0][i])
						if (!(ptr->r[i] == ptr2->r[i])) return 0;
			}

			//vector2
			if (tcmp[4])
			{
				if (tcmpV[1].size() > ptr->t.size())
					return 0;

				size_t	siz = tcmpV[1].size();
				for (int i = 0; i < siz; i++)
					if (tcmpV[1][i])
						if (!(ptr->t[i] == ptr2->t[i])) return 0;
			}

			if (tcmp[5])
				if (ptr->y != ptr2->y) return 0;
		}
	}
	else if (typeid(incomplete_links) == typeid(*fact) && typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		incomplete_links* ptr = dynamic_cast<incomplete_links*>(fact);
		incomplete_links* ptr2 = dynamic_cast<incomplete_links*>(Treesfact);
		if (!tcmp.empty())
		{
			if (tcmp[0])
				if (ptr->q != ptr2->q) return 0;

			if (tcmp[1])
				if (ptr->w != ptr2->w) return 0;

			if (tcmp[2])
				if (ptr->e != ptr2->e) return 0;

			if (tcmp[3])
				if (ptr->r != ptr2->r) return 0;

			if (tcmp[4])
				if (ptr->t != ptr2->t) return 0;

			if (tcmp[5])
				if (ptr->y != ptr2->y) return 0;

			if (tcmp[6])
				if (ptr->u != ptr2->u) return 0;

			if (tcmp[7])
				if (ptr->i != ptr2->i) return 0;

			if (tcmp[8])
				if (ptr->o != ptr2->o) return 0;

			if (tcmp[9])
				if (ptr->p != ptr2->p) return 0;
		}
	}
	else if (typeid(last_incomplete) == typeid(*fact) && typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		last_incomplete* ptr = dynamic_cast<last_incomplete*>(fact);
		last_incomplete* ptr2 = dynamic_cast<last_incomplete*>(Treesfact);
		if (!tcmp.empty())
		{
			if (tcmp[0])
				if (ptr->q != ptr2->q) return 0;

			if (tcmp[1])
				if (ptr->w != ptr2->w) return 0;

			if (tcmp[2])
				if (ptr->e != ptr2->e) return 0;

			if (tcmp[3])
				if (ptr->r != ptr2->r) return 0;
		}
	}
	else if (typeid(global_nils) == typeid(*fact) && typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		global_nils* ptr = dynamic_cast<global_nils*>(fact);
		global_nils* ptr2 = dynamic_cast<global_nils*>(Treesfact);

		if (tcmp[0])
		{
			//vector
			if (tcmpV[0].size() > ptr->q.size())
				return 0;

			size_t	siz = tcmpV[0].size();
			for (int i = 0; i < siz; i++)
			{
				if (!tcmpV[i].empty())
				{
					if (tcmpV[i][0])
					{
						if (ptr->q[i].q != ptr2->q[i].q) return 0;
					}
					if (tcmpV[i][1])
					{
						if (ptr->q[i].w != ptr2->q[i].w) return 0;
					}
				}
			}

		}
	}
	else if (typeid(current_module) == typeid(*fact) && typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		current_module* ptr = dynamic_cast<current_module*>(fact);
		current_module* ptr2 = dynamic_cast<current_module*>(Treesfact);
		if (!tcmp.empty())
		{
			if (tcmp[0])
				if (ptr->q != ptr2->q) return 0;
		}
	}
	else if (typeid(last_linear_incomplete_node) == typeid(*fact) && typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		last_linear_incomplete_node* ptr = dynamic_cast<last_linear_incomplete_node*>(fact);
		last_linear_incomplete_node* ptr2 = dynamic_cast<last_linear_incomplete_node*>(Treesfact);
		if (!tcmp.empty())
		{
			if (tcmp[0])
				if (ptr->q != ptr2->q) return 0;
		}
	}
	else if (typeid(operator_instances) == typeid(*fact) && typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		operator_instances* ptr = dynamic_cast<operator_instances*>(fact);
		operator_instances* ptr2 = dynamic_cast<operator_instances*>(Treesfact);
		if (!tcmp.empty())
		{
			if (tcmp[0])
				if (ptr->q != ptr2->q) return 0;

			if (tcmp[1])
				if (ptr->w != ptr2->w) return 0;
		}
	}
	else if (typeid(massively_parallel_style) == typeid(*fact) && typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		massively_parallel_style* ptr = dynamic_cast<massively_parallel_style*>(fact);
		massively_parallel_style* ptr2 = dynamic_cast<massively_parallel_style*>(Treesfact);
		if (!tcmp.empty())
		{
			if (tcmp[0])
				if (ptr->q != ptr2->q) return 0;
		}
	}
	else if (typeid(hdl_style) == typeid(*fact) && typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		hdl_style* ptr = dynamic_cast<hdl_style*>(fact);
		hdl_style* ptr2 = dynamic_cast<hdl_style*>(Treesfact);
		if (!tcmp.empty())
		{
			if (tcmp[0])
				if (ptr->q != ptr2->q) return 0;
		}
	}
	else if (typeid(op_instance) == typeid(*fact) && typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		op_instance* ptr = dynamic_cast<op_instance*>(fact);
		op_instance* ptr2 = dynamic_cast<op_instance*>(Treesfact);

		if (!tcmp.empty())
		{
			if (tcmp[0])
				if (ptr->q != ptr2->q) return 0;

			if (tcmp[1])
				if (ptr->w != ptr2->w) return 0;

			if (tcmp[2])
				if (ptr->e != ptr2->e) return 0;

			if (tcmp[3])
				if (ptr->r != ptr2->r) return 0;

			if (tcmp[4])
				if (ptr->t != ptr2->t) return 0;
		}
	}
	else if (typeid(last_op_instance) == typeid(*fact) && typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		last_op_instance* ptr = dynamic_cast<last_op_instance*>(fact);
		last_op_instance* ptr2 = dynamic_cast<last_op_instance*>(Treesfact);
		if (!tcmp.empty())
		{
			if (tcmp[0])
				if (ptr->q != ptr2->q) return 0;

			if (tcmp[1])
				if (ptr->w != ptr2->w) return 0;

			if (tcmp[2])
				if (ptr->e != ptr2->e) return 0;
		}
	}
	else if (typeid(op_in_a_state) == typeid(*fact) && typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		op_in_a_state* ptr = dynamic_cast<op_in_a_state*>(fact);
		op_in_a_state* ptr2 = dynamic_cast<op_in_a_state*>(Treesfact);
		if (!tcmp.empty())
		{
			if (tcmp[0])
				if (ptr->q != ptr2->q) return 0;

			if (tcmp[1])
				if (ptr->w != ptr2->w) return 0;

			if (tcmp[2])
				if (ptr->e != ptr2->e) return 0;

			if (tcmp[3])
				if (ptr->r != ptr2->r) return 0;

			if (tcmp[4])
				if (ptr->t != ptr2->t) return 0;
		}
	}
	else if (typeid(last_op_in_a_state) == typeid(*fact) && typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		last_op_in_a_state* ptr = dynamic_cast<last_op_in_a_state*>(fact);
		last_op_in_a_state* ptr2 = dynamic_cast<last_op_in_a_state*>(Treesfact);
		if (!tcmp.empty())
		{
			if (tcmp[0])
				if (ptr->q != ptr2->q) return 0;

			if (tcmp[1])
				if (ptr->w != ptr2->w) return 0;

			if (tcmp[2])
				if (ptr->e != ptr2->e) return 0;

			if (tcmp[3])
				if (ptr->r != ptr2->r) return 0;
		}
	}
	else if (typeid(signal_instance) == typeid(*fact) && typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		signal_instance* ptr = dynamic_cast<signal_instance*>(fact);
		signal_instance* ptr2 = dynamic_cast<signal_instance*>(Treesfact);
		if (!tcmp.empty())
		{
			if (tcmp[0])
				if (ptr->q != ptr2->q) return 0;

			if (tcmp[1])
				if (ptr->w != ptr2->w) return 0;

			if (tcmp[2])
				if (ptr->e != ptr2->e) return 0;

			if (tcmp[3])
				if (ptr->r != ptr2->r) return 0;

			if (tcmp[4])
				if (ptr->t != ptr2->t) return 0;

			if (tcmp[5])
				if (ptr->y != ptr2->y) return 0;

			if (tcmp[6])
				if (ptr->u != ptr2->u) return 0;
		}
	}
	else if (typeid(last_signal_instance) == typeid(*fact) && typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		last_signal_instance* ptr = dynamic_cast<last_signal_instance*>(fact);
		last_signal_instance* ptr2 = dynamic_cast<last_signal_instance*>(Treesfact);
		if (!tcmp.empty())
		{
			if (tcmp[0])
				if (ptr->q != ptr2->q) return 0;

			if (tcmp[1])
				if (ptr->w != ptr2->w) return 0;
		}
	}
	else if (typeid(output_instance) == typeid(*fact) && typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		output_instance* ptr = dynamic_cast<output_instance*>(fact);
		output_instance* ptr2 = dynamic_cast<output_instance*>(Treesfact);
		if (!tcmp.empty())
		{
			if (tcmp[0])
				if (ptr->q != ptr2->q) return 0;

			if (tcmp[1])
				if (ptr->w != ptr2->w) return 0;

			if (tcmp[2])
				if (ptr->e != ptr2->e) return 0;

			if (tcmp[3])
				if (ptr->r != ptr2->r) return 0;

			if (tcmp[4])
				if (ptr->t != ptr2->t) return 0;

			if (tcmp[5])
				if (ptr->y != ptr2->y) return 0;
		}
	}
	else if (typeid(last_output_instance) == typeid(*fact) && typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		last_output_instance* ptr = dynamic_cast<last_output_instance*>(fact);
		last_output_instance* ptr2 = dynamic_cast<last_output_instance*>(Treesfact);
		if (!tcmp.empty())
		{
			if (tcmp[0])
				if (ptr->q != ptr2->q) return 0;

			if (tcmp[1])
				if (ptr->w != ptr2->w) return 0;
		}
	}
	else if (typeid(operator_instance_stats) == typeid(*fact) && typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		operator_instance_stats* ptr = dynamic_cast<operator_instance_stats*>(fact);
		operator_instance_stats* ptr2 = dynamic_cast<operator_instance_stats*>(Treesfact);
		if (!tcmp.empty())
		{
			if (tcmp[0])
				if (ptr->q != ptr2->q) return 0;

			if (tcmp[1])
				if (ptr->w != ptr2->w) return 0;

			if (tcmp[2])
				if (ptr->e != ptr2->e) return 0;

			if (tcmp[3])
				if (ptr->r != ptr2->r) return 0;
		}
	}
	else if (typeid(consecutive_106) == typeid(*fact) && typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		consecutive_106* ptr = dynamic_cast<consecutive_106*>(fact);
		consecutive_106* ptr2 = dynamic_cast<consecutive_106*>(Treesfact);
		if (!tcmp.empty())
		{
			if (tcmp[0])
				if (ptr->q != ptr2->q) return 0;
		}
	}
	else if (typeid(operation_order) == typeid(*fact) && typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		operation_order* ptr = dynamic_cast<operation_order*>(fact);
		operation_order* ptr2 = dynamic_cast<operation_order*>(Treesfact);
		if (!tcmp.empty())
		{
			if (tcmp[0])
				if (ptr->q != ptr2->q) return 0;

			if (tcmp[1])
				if (ptr->w != ptr2->w) return 0;

			if (tcmp[2])
				if (ptr->e != ptr2->e) return 0;

			if (tcmp[3])
				if (ptr->r != ptr2->r) return 0;

			if (tcmp[4])
				if (ptr->t != ptr2->t) return 0;

			if (tcmp[5])
				if (ptr->y != ptr2->y) return 0;

			if (tcmp[6])
				if (ptr->u != ptr2->u) return 0;

			if (tcmp[7])
				if (ptr->i != ptr2->i) return 0;

			if (tcmp[8])
				if (ptr->o != ptr2->o) return 0;

			if (tcmp[9])
				if (ptr->p != ptr2->p) return 0;
		}
	}
	else if (typeid(max_parallel_call_order) == typeid(*fact) && typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		max_parallel_call_order* ptr = dynamic_cast<max_parallel_call_order*>(fact);
		max_parallel_call_order* ptr2 = dynamic_cast<max_parallel_call_order*>(Treesfact);
		if (!tcmp.empty())
		{
			if (tcmp[0])
				if (ptr->q != ptr2->q) return 0;

			if (tcmp[1])
				if (ptr->w != ptr2->w) return 0;

			if (tcmp[2])
				if (ptr->e != ptr2->e) return 0;

			if (tcmp[3])
				if (ptr->r != ptr2->r) return 0;
		}
	}
	else if (typeid(max_op_order) == typeid(*fact) && typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		max_op_order* ptr = dynamic_cast<max_op_order*>(fact);
		max_op_order* ptr2 = dynamic_cast<max_op_order*>(Treesfact);
		if (!tcmp.empty())
		{
			if (tcmp[0])
				if (ptr->q != ptr2->q) return 0;

			if (tcmp[1])
				if (ptr->w != ptr2->w) return 0;

			if (tcmp[2])
				if (ptr->e != ptr2->e) return 0;
		}
	}
	else if (typeid(totalmax_call_order) == typeid(*fact) && typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		totalmax_call_order* ptr = dynamic_cast<totalmax_call_order*>(fact);
		totalmax_call_order* ptr2 = dynamic_cast<totalmax_call_order*>(Treesfact);
		if (!tcmp.empty())
		{
			if (tcmp[0])
				if (ptr->q != ptr2->q) return 0;

			if (tcmp[1])
				if (ptr->w != ptr2->w) return 0;

			if (tcmp[2])
				if (ptr->e != ptr2->e) return 0;
		}
	}
	else if (typeid(totalmax_gross_depth) == typeid(*fact) && typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		totalmax_gross_depth* ptr = dynamic_cast<totalmax_gross_depth*>(fact);
		totalmax_gross_depth* ptr2 = dynamic_cast<totalmax_gross_depth*>(Treesfact);
		if (!tcmp.empty())
		{
			if (tcmp[0])
				if (ptr->q != ptr2->q) return 0;

			if (tcmp[1])
				if (ptr->w != ptr2->w) return 0;

			if (tcmp[2])
				if (ptr->e != ptr2->e) return 0;
		}
	}
	else if (typeid(current_total_max_order_entry) == typeid(*fact) && typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		current_total_max_order_entry* ptr = dynamic_cast<current_total_max_order_entry*>(fact);
		current_total_max_order_entry* ptr2 = dynamic_cast<current_total_max_order_entry*>(Treesfact);
		if (!tcmp.empty())
		{
			if (tcmp[0])
				if (ptr->q != ptr2->q) return 0;
		}
	}
	else if (typeid(module_last_state) == typeid(*fact) && typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		module_last_state* ptr = dynamic_cast<module_last_state*>(fact);
		module_last_state* ptr2 = dynamic_cast<module_last_state*>(Treesfact);
		if (!tcmp.empty())
		{
			if (tcmp[0])
				if (ptr->q != ptr2->q) return 0;
		}
	}
	else if (typeid(module_local_list) == typeid(*fact) && typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		module_local_list* ptr = dynamic_cast<module_local_list*>(fact);
		module_local_list* ptr2 = dynamic_cast<module_local_list*>(Treesfact);

		if (tcmp[0])
		{
			//vector
			if (tcmpV[0].size() > ptr->q.size())
				return 0;

			size_t	siz = tcmpV[0].size();
			for (int i = 0; i < siz; i++)
			{
				if (!tcmpV[i].empty())
				{
					if (tcmpV[i][0])
					{
						if (ptr->q[i].q != ptr2->q[i].q) return 0;
					}
					if (tcmpV[i][1])
					{
						if (ptr->q[i].w != ptr2->q[i].w) return 0;
					}
					if (tcmpV[i][2])
					{
						if (ptr->q[i].e != ptr2->q[i].e) return 0;
					}
					if (tcmpV[i][3])
					{
						if (ptr->q[i].r != ptr2->q[i].r) return 0;
					}
					if (tcmpV[i][4])
					{
						if (ptr->q[i].t != ptr2->q[i].t) return 0;
					}
					if (tcmpV[i][5])
					{
						if (ptr->q[i].y != ptr2->q[i].y) return 0;
					}
					if (tcmpV[i][6])
					{
						if (ptr->q[i].u != ptr2->q[i].u) return 0;
					}
					if (tcmpV[i][7])
					{
						if (ptr->q[i].i != ptr2->q[i].i) return 0;
					}
					if (tcmpV[i][8])
					{
						if (ptr->q[i].o != ptr2->q[i].o) return 0;
					}
				}
			}
		}
	}
	if (flag)								//exeeded the limit of nested else if
	{
		if (typeid(module_local_list_parcs) == typeid(*fact) && typeid(*fact) == typeid(*Treesfact))
		{
			module_local_list_parcs* ptr = dynamic_cast<module_local_list_parcs*>(fact);
			module_local_list_parcs* ptr2 = dynamic_cast<module_local_list_parcs*>(Treesfact);

			if (tcmp[0])
			{
				//vector
				if (tcmpV[0].size() > ptr->q.size())
					return 0;

				size_t	siz = tcmpV[0].size();
				for (int i = 0; i < siz; i++)
				{
					if (!tcmpV[i].empty())
					{
						if (tcmpV[i][0])
						{
							if (ptr->q[i].q != ptr2->q[i].q) return 0;
						}
						if (tcmpV[i][1])
						{
							if (ptr->q[i].w != ptr2->q[i].w) return 0;
						}
						if (tcmpV[i][2])
						{
							if (ptr->q[i].e != ptr2->q[i].e) return 0;
						}
						if (tcmpV[i][3])
						{
							if (ptr->q[i].r != ptr2->q[i].r) return 0;
						}
						if (tcmpV[i][4])
						{
							if (ptr->q[i].t != ptr2->q[i].t) return 0;
						}
						if (tcmpV[i][5])
						{
							if (ptr->q[i].y != ptr2->q[i].y) return 0;
						}
						if (tcmpV[i][6])
						{
							if (ptr->q[i].u != ptr2->q[i].u) return 0;
						}
						if (tcmpV[i][7])
						{
							if (ptr->q[i].i != ptr2->q[i].i) return 0;
						}
						if (tcmpV[i][8])
						{
							if (ptr->q[i].o != ptr2->q[i].o) return 0;
						}
					}
				}
			}
		}
		else if (typeid(last_non_io_found) == typeid(*fact) && typeid(*fact) == typeid(*Treesfact))
		{
			last_non_io_found* ptr = dynamic_cast<last_non_io_found*>(fact);
			last_non_io_found* ptr2 = dynamic_cast<last_non_io_found*>(Treesfact);
			if (!tcmp.empty())
			{
				if (tcmp[0])
					if (ptr->q != ptr2->q) return 0;
			}
		}
		else if (typeid(last_local_number) == typeid(*fact) && typeid(*fact) == typeid(*Treesfact))
		{
			last_local_number* ptr = dynamic_cast<last_local_number*>(fact);
			last_local_number* ptr2 = dynamic_cast<last_local_number*>(Treesfact);
			if (!tcmp.empty())
			{
				if (tcmp[0])
					if (ptr->q != ptr2->q) return 0;
			}
		}
		else if (typeid(printed_formal_ios_of_called_module) == typeid(*fact) && typeid(*fact) == typeid(*Treesfact))
		{
			printed_formal_ios_of_called_module* ptr = dynamic_cast<printed_formal_ios_of_called_module*>(fact);
			printed_formal_ios_of_called_module* ptr2 = dynamic_cast<printed_formal_ios_of_called_module*>(Treesfact);
			if (!tcmp.empty())
			{
				if (tcmp[0])
					if (ptr->q != ptr2->q) return 0;

				if (tcmp[1])
					if (ptr->w != ptr2->w) return 0;

				if (tcmp[2])
					if (ptr->e != ptr2->e) return 0;

				if (tcmp[3])
					if (ptr->r != ptr2->r) return 0;
			}
		}
		else if (typeid(it_includes_ifthen) == typeid(*fact) && typeid(*fact) == typeid(*Treesfact))
		{
			it_includes_ifthen* ptr = dynamic_cast<it_includes_ifthen*>(fact);
			it_includes_ifthen* ptr2 = dynamic_cast<it_includes_ifthen*>(Treesfact);
			if (!tcmp.empty())
			{
				if (tcmp[0])
					if (ptr->q != ptr2->q) return 0;

				if (tcmp[1])
					if (ptr->w != ptr2->w) return 0;

				if (tcmp[2])
					if (ptr->e != ptr2->e) return 0;
			}
		}
		else if (typeid(it_includes_conditional_targeting) == typeid(*fact) && typeid(*fact) == typeid(*Treesfact))
		{
			it_includes_conditional_targeting* ptr = dynamic_cast<it_includes_conditional_targeting*>(fact);
			it_includes_conditional_targeting* ptr2 = dynamic_cast<it_includes_conditional_targeting*>(Treesfact);
			if (!tcmp.empty())
			{
				if (tcmp[0])
					if (ptr->q != ptr2->q) return 0;

				if (tcmp[1])
					if (ptr->w != ptr2->w) return 0;

				if (tcmp[2])
					if (ptr->e != ptr2->e) return 0;
			}
		}
		else if (typeid(targets_conditional_variable) == typeid(*fact) && typeid(*fact) == typeid(*Treesfact))
		{
			targets_conditional_variable* ptr = dynamic_cast<targets_conditional_variable*>(fact);
			targets_conditional_variable* ptr2 = dynamic_cast<targets_conditional_variable*>(Treesfact);
			if (!tcmp.empty())
			{
				if (tcmp[0])
					if (ptr->q != ptr2->q) return 0;

				if (tcmp[1])
					if (ptr->w != ptr2->w) return 0;

				if (tcmp[2])
					if (ptr->e != ptr2->e) return 0;

				if (tcmp[3])
					if (ptr->r != ptr2->r) return 0;
			}
		}
		else if (typeid(variable_has_been_listed) == typeid(*fact) && typeid(*fact) == typeid(*Treesfact))
		{
			variable_has_been_listed* ptr = dynamic_cast<variable_has_been_listed*>(fact);
			variable_has_been_listed* ptr2 = dynamic_cast<variable_has_been_listed*>(Treesfact);
			if (!tcmp.empty())
			{
				if (tcmp[0])
					if (ptr->q != ptr2->q) return 0;

				if (tcmp[1])
					if (ptr->w != ptr2->w) return 0;
			}
		}
		else if (typeid(resetstyle) == typeid(*fact) && typeid(*fact) == typeid(*Treesfact))
		{
			resetstyle* ptr = dynamic_cast<resetstyle*>(fact);
			resetstyle* ptr2 = dynamic_cast<resetstyle*>(Treesfact);
			if (!tcmp.empty())
			{
				if (tcmp[0])
					if (ptr->q != ptr2->q) return 0;
			}
		}
		else if (typeid(checkstyle) == typeid(*fact) && typeid(*fact) == typeid(*Treesfact))
		{
			checkstyle* ptr = dynamic_cast<checkstyle*>(fact);
			checkstyle* ptr2 = dynamic_cast<checkstyle*>(Treesfact);
			if (!tcmp.empty())
			{
				if (tcmp[0])
					if (ptr->q != ptr2->q) return 0;
			}
		}
		else if (typeid(total_local_entry) == typeid(*fact) && typeid(*fact) == typeid(*Treesfact))
		{
			total_local_entry* ptr = dynamic_cast<total_local_entry*>(fact);
			total_local_entry* ptr2 = dynamic_cast<total_local_entry*>(Treesfact);
			if (!tcmp.empty())
			{
				if (tcmp[0])
					if (ptr->q != ptr2->q) return 0;
			}
		}
		else if (typeid(complex_next_state_operation_depth) == typeid(*fact) && typeid(*fact) == typeid(*Treesfact))
		{
			complex_next_state_operation_depth* ptr = dynamic_cast<complex_next_state_operation_depth*>(fact);
			complex_next_state_operation_depth* ptr2 = dynamic_cast<complex_next_state_operation_depth*>(Treesfact);
			if (!tcmp.empty())
			{
				if (tcmp[0])
					if (ptr->q != ptr2->q) return 0;
			}
		}
		else if (typeid(output_filename) == typeid(*fact) && typeid(*fact) == typeid(*Treesfact))
		{
			output_filename* ptr = dynamic_cast<output_filename*>(fact);
			output_filename* ptr2 = dynamic_cast<output_filename*>(Treesfact);
			if (!tcmp.empty())
			{
				if (tcmp[0])
					if (ptr->q != ptr2->q) return 0;
			}
		}
		else if (typeid(hdl_io_pass) == typeid(*fact) && typeid(*fact) == typeid(*Treesfact))
		{
			hdl_io_pass* ptr = dynamic_cast<hdl_io_pass*>(fact);
			hdl_io_pass* ptr2 = dynamic_cast<hdl_io_pass*>(Treesfact);
			if (!tcmp.empty())
			{
				if (tcmp[0])
					if (ptr->q != ptr2->q) return 0;
			}
		}
		else if (typeid(current_hdl_style) == typeid(*fact) && typeid(*fact) == typeid(*Treesfact))
		{
			current_hdl_style* ptr = dynamic_cast<current_hdl_style*>(fact);
			current_hdl_style* ptr2 = dynamic_cast<current_hdl_style*>(Treesfact);
			if (!tcmp.empty())
			{
				if (tcmp[0])
					if (ptr->q != ptr2->q) return 0;
			}
		}
		else if (typeid(call_ios_have_been_reset) == typeid(*fact) && typeid(*fact) == typeid(*Treesfact))
		{
			call_ios_have_been_reset* ptr = dynamic_cast<call_ios_have_been_reset*>(fact);
			call_ios_have_been_reset* ptr2 = dynamic_cast<call_ios_have_been_reset*>(Treesfact);
			if (!tcmp.empty())
			{
				if (tcmp[0])
					if (ptr->q != ptr2->q) return 0;
			}
		}
		else if (typeid(debug_mode) == typeid(*fact) && typeid(*fact) == typeid(*Treesfact))
		{
			debug_mode* ptr = dynamic_cast<debug_mode*>(fact);
			debug_mode* ptr2 = dynamic_cast<debug_mode*>(Treesfact);
			if (!tcmp.empty())
			{
				if (tcmp[0])
					if (ptr->q != ptr2->q) return 0;
			}
		}
		else if (typeid(print_C_main_body) == typeid(*fact) && typeid(*fact) == typeid(*Treesfact))
		{
			print_C_main_body* ptr = dynamic_cast<print_C_main_body*>(fact);
			print_C_main_body* ptr2 = dynamic_cast<print_C_main_body*>(Treesfact);
			if (!tcmp.empty())
			{
				if (tcmp[0])
					if (ptr->q != ptr2->q) return 0;
			}
		}
		else if (typeid(cac_mode) == typeid(*fact) && typeid(*fact) == typeid(*Treesfact))
		{
			cac_mode* ptr = dynamic_cast<cac_mode*>(fact);
			cac_mode* ptr2 = dynamic_cast<cac_mode*>(Treesfact);
			if (!tcmp.empty())
			{
				if (tcmp[0])
					if (ptr->q != ptr2->q) return 0;
			}
		}
		else if (typeid(path) == typeid(*fact) && typeid(*fact) == typeid(*Treesfact))
		{
			path* ptr = dynamic_cast<path*>(fact);
			path* ptr2 = dynamic_cast<path*>(Treesfact);
			if (!tcmp.empty())
			{
				if (tcmp[0])
					if (ptr->q != ptr2->q) return 0;

				if (tcmp[1])
					if (ptr->w != ptr2->w) return 0;

				if (tcmp[2])
					if (ptr->e != ptr2->e) return 0;
			}
		}
		else if (typeid(max_path) == typeid(*fact) && typeid(*fact) == typeid(*Treesfact))
		{
			max_path* ptr = dynamic_cast<max_path*>(fact);
			max_path* ptr2 = dynamic_cast<max_path*>(Treesfact);
			if (!tcmp.empty())
			{
				if (tcmp[0])
					if (ptr->q != ptr2->q) return 0;

				if (tcmp[1])
					if (ptr->w != ptr2->w) return 0;
			}
		}
		else if (typeid(min_path) == typeid(*fact) && typeid(*fact) == typeid(*Treesfact))
		{
			min_path* ptr = dynamic_cast<min_path*>(fact);
			min_path* ptr2 = dynamic_cast<min_path*>(Treesfact);
			if (!tcmp.empty())
			{
				if (tcmp[0])
					if (ptr->q != ptr2->q) return 0;

				if (tcmp[1])
					if (ptr->w != ptr2->w) return 0;
			}
		}
		else if (typeid(op_belongs_to_state) == typeid(*fact) && typeid(*fact) == typeid(*Treesfact))
		{
			op_belongs_to_state* ptr = dynamic_cast<op_belongs_to_state*>(fact);
			op_belongs_to_state* ptr2 = dynamic_cast<op_belongs_to_state*>(Treesfact);
			if (!tcmp.empty())
			{
				if (tcmp[0])
					if (ptr->q != ptr2->q) return 0;

				if (tcmp[1])
					if (ptr->w != ptr2->w) return 0;

				if (tcmp[2])
					if (ptr->e != ptr2->e) return 0;

				if (tcmp[3])
					if (ptr->r != ptr2->r) return 0;
			}
		}
		else if (typeid(top_module) == typeid(*fact) && typeid(*fact) == typeid(*Treesfact))
		{
			top_module* ptr = dynamic_cast<top_module*>(fact);
			top_module* ptr2 = dynamic_cast<top_module*>(Treesfact);
			if (!tcmp.empty())
			{
				if (tcmp[0])
					if (ptr->q != ptr2->q) return 0;
			}
		}
		else if (typeid(package_name) == typeid(*fact) && typeid(*fact) == typeid(*Treesfact))
		{
			package_name* ptr = dynamic_cast<package_name*>(fact);
			package_name* ptr2 = dynamic_cast<package_name*>(Treesfact);
			if (!tcmp.empty())
			{
				if (tcmp[0])
					if (ptr->q != ptr2->q) return 0;
			}
		}
		else
		{
			GenfactError* ptr = new GenfactError(typeid(obj).name());
			//cout << ptr->saying << endl;
			return 0;
		}
	}	// if (flag)
	//cout << makeStringOf(Treesfact) << endl;
	return 1;
}

/// @brief compares 2 data
/// @param Treesfact <- loaded data
/// @param obj <- data to compare (/w '*')
/// @return if matched 1 else 0
size_t matchfactsstar(GeneralFact* Treesfact, factstar* obj)
{
	bool			flag = 1;
	GeneralFact*	fact = obj->fact;
	size_t			p = obj->params;

	if (typeid(type_def) == typeid(*fact) && typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		type_def* ptr = dynamic_cast<type_def*>(fact);
		type_def* ptr2 = dynamic_cast<type_def*>(Treesfact);
		if (p)
		{
			switch (p)
			{
			case 9:
				if (ptr->o != ptr2->o) return 0;
			case 8:
				if (ptr->i != ptr2->i) return 0;
			case 7:
				if (ptr->u != ptr2->u) return 0;
			case 6:
				if (ptr->y != ptr2->y) return 0;
			case 5:
				if (ptr->t != ptr2->t) return 0;
			case 4:
				if (ptr->r != ptr2->r) return 0;
			case 3:
				if (ptr->e != ptr2->e) return 0;
			case 2:
				if (ptr->w != ptr2->w) return 0;
			case 1:
				if (ptr->q != ptr2->q) return 0;
			}
		}
	}
	else if (typeid(op_def) == typeid(*fact)&& typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		op_def* ptr = dynamic_cast<op_def*>(fact);
		op_def* ptr2 = dynamic_cast<op_def*>(Treesfact);

		if (p)
		{
			switch (p)
			{
			case 7:
				if (ptr->u != ptr2->u) return 0;
			case 6:
				if (ptr->y != ptr2->y) return 0;
			case 5:
				if (ptr->t != ptr2->t) return 0;
			case 4:
				if (ptr->r != ptr2->r) return 0;
			case 3:
				if (ptr->e != ptr2->e) return 0;
			case 2:
				if (ptr->w != ptr2->w) return 0;
			case 1:
				if (ptr->q != ptr2->q) return 0;
			}

		}
	}
	else if (typeid(hierarchy_part) == typeid(*fact) && typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		hierarchy_part* ptr = dynamic_cast<hierarchy_part*>(fact);
		hierarchy_part* ptr2 = dynamic_cast<hierarchy_part*>(Treesfact);
		if (p)
		{
			switch (p)
			{
			case 7:
				if (ptr->u != ptr2->u) return 0;
			case 6:
				if (ptr->y != ptr2->y) return 0;
			case 5:
				if (ptr->t != ptr2->t) return 0;
			case 4:
				if (ptr->r != ptr2->r) return 0;
			case 3:
				if (ptr->e != ptr2->e) return 0;
			case 2:
				if (ptr->w != ptr2->w) return 0;
			case 1:
				if (ptr->q != ptr2->q) return 0;
			}

		}
	}
	else if (typeid(data_stmt) == typeid(*fact)&& typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		data_stmt* ptr = dynamic_cast<data_stmt*>(fact);
		data_stmt* ptr2 = dynamic_cast<data_stmt*>(Treesfact);
		if (p)
		{
			switch (p)
			{
			case 6:
				if (ptr->y != ptr2->y) return 0;
			case 5:
				if (ptr->t != ptr2->t) return 0;
			case 4:
				if (ptr->r != ptr2->r) return 0;
			case 3:
				if (ptr->e != ptr2->e) return 0;
			case 2:
				if (ptr->w != ptr2->w) return 0;
			case 1:
				if (ptr->q != ptr2->q) return 0;
			}
		}
	}
	else if (typeid(prog_stmt) == typeid(*fact)&& typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		prog_stmt* ptr = dynamic_cast<prog_stmt*>(fact);
		prog_stmt* ptr2 = dynamic_cast<prog_stmt*>(Treesfact);
		if (p)
		{
			switch (p)
			{
			case 8:
				if (ptr->i != ptr2->i) return 0;
			case 7:
				if (ptr->u != ptr2->u) return 0;
			case 6:
				if (ptr->y != ptr2->y) return 0;
			case 5:
				if (ptr->t != ptr2->t) return 0;
			case 4:
				if (ptr->r != ptr2->r) return 0;
			case 3:
				if (ptr->e != ptr2->e) return 0;
			case 2:
				if (ptr->w != ptr2->w) return 0;
			case 1:
				if (ptr->q != ptr2->q) return 0;
			}
		}
	}
	else if (typeid(joint_stmt) == typeid(*fact)&& typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		joint_stmt* ptr = dynamic_cast<joint_stmt*>(fact);
		joint_stmt* ptr2 = dynamic_cast<joint_stmt*>(Treesfact);
		if (p)
		{
			switch (p)
			{
			case 6:
				if (ptr->y != ptr2->y) return 0;
			case 5:
				if (ptr->t != ptr2->t) return 0;
			case 4:
				if (ptr->r != ptr2->r) return 0;
			case 3:
				if (ptr->e != ptr2->e) return 0;
			case 2:
				if (ptr->w != ptr2->w) return 0;
			case 1:
				if (ptr->q != ptr2->q) return 0;
			}
		}
	}
	else if (typeid(call_stmt) == typeid(*fact)&& typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		call_stmt* ptr = dynamic_cast<call_stmt*>(fact);
		call_stmt* ptr2 = dynamic_cast<call_stmt*>(Treesfact);
		size_t	siz = ptr2->r.size();

		if (p)
		{
			switch (p)
			{
			case 4: //vector
				if (ptr2->r.size() != ptr->r.size()) return 0;
				else if (ptr2->r.empty() != ptr->r.empty()) return 0;
				else if (!(ptr2->r.empty() && ptr->r.empty()))
					for (int i = 0; i < siz; i++)
					if (!(ptr->r[i] == ptr2->r[i])) return 0;
			case 3:
				if (ptr->e != ptr2->e) return 0;
			case 2:
				if (ptr->w != ptr2->w) return 0;
			case 1:
				if (ptr->q != ptr2->q) return 0;
			}
		}
	}
	else if (typeid(compo_stmt) == typeid(*fact)&& typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		compo_stmt* ptr = dynamic_cast<compo_stmt*>(fact);
		compo_stmt* ptr2 = dynamic_cast<compo_stmt*>(Treesfact);
		size_t	siz = ptr2->r.size();

		if (p)
		{
			switch (p)
			{
			case 3: //vector
				if (ptr2->r.size() != ptr->r.size()) return 0;
				else if (ptr2->r.empty() != ptr->r.empty()) return 0;
				else if (!(ptr2->r.empty() && ptr->r.empty()))
					for (int i = 0; i < siz; i++)
					if (!(ptr->r[i] == ptr2->r[i])) return 0;
			case 2:
				if (ptr->w != ptr2->w) return 0;
			case 1:
				if (ptr->q != ptr2->q) return 0;
			}
		}
	}
	else if (typeid(rec_stmt) == typeid(*fact)&& typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		rec_stmt* ptr = dynamic_cast<rec_stmt*>(fact);
		rec_stmt* ptr2 = dynamic_cast<rec_stmt*>(Treesfact);
		size_t	siz = ptr2->e.size();

		if (p)
		{
			switch (p)
			{
			case 3: //vector
				if (ptr2->e.size() != ptr->e.size()) return 0;
				else if (ptr2->e.empty() != ptr->e.empty()) return 0;
				else if (!(ptr2->e.empty() && ptr->e.empty()))
					for (int i = 0; i < siz; i++)
					if (!(ptr->e[i] == ptr2->e[i])) return 0;
			case 2:
				if (ptr->w != ptr2->w) return 0;
			case 1:
				if (ptr->q != ptr2->q) return 0;
			}
		}
	}
	else if (typeid(special_op) == typeid(*fact)&& typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		special_op* ptr = dynamic_cast<special_op*>(fact);
		special_op* ptr2 = dynamic_cast<special_op*>(Treesfact);
		if (p)
		{
			switch (p)
			{
			case 10:
				if (ptr->p != ptr2->p) return 0;
			case 9:
				if (ptr->o != ptr2->o) return 0;
			case 8:
				if (ptr->i != ptr2->i) return 0;
			case 7:
				if (ptr->u != ptr2->u) return 0;
			case 6:
				if (ptr->y != ptr2->y) return 0;
			case 5:
				if (ptr->t != ptr2->t) return 0;
			case 4:
				if (ptr->r != ptr2->r) return 0;
			case 3:
				if (ptr->e != ptr2->e) return 0;
			case 2:
				if (ptr->w != ptr2->w) return 0;
			case 1:
				if (ptr->q != ptr2->q) return 0;
			}
		}
	}
	else if (typeid(special_dt) == typeid(*fact)&& typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		special_dt* ptr = dynamic_cast<special_dt*>(fact);
		special_dt* ptr2 = dynamic_cast<special_dt*>(Treesfact);
		if (p)
		{
			switch (p)
			{
			case 7:
				if (ptr->u != ptr2->u) return 0;
			case 6:
				if (ptr->y != ptr2->y) return 0;
			case 5:
				if (ptr->t != ptr2->t) return 0;
			case 4:
				if (ptr->r != ptr2->r) return 0;
			case 3:
				if (ptr->e != ptr2->e) return 0;
			case 2:
				if (ptr->w != ptr2->w) return 0;
			case 1:
				if (ptr->q != ptr2->q) return 0;
			}
		}
	}
	else if (typeid(local_object) == typeid(*fact)&& typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		local_object* ptr = dynamic_cast<local_object*>(fact);
		local_object* ptr2 = dynamic_cast<local_object*>(Treesfact);
		if (p)
		{
			switch (p)
			{
			case 9:
				if (ptr->o != ptr2->o) return 0;
			case 8:
				if (ptr->i != ptr2->i) return 0;
			case 7:
				if (ptr->u != ptr2->u) return 0;
			case 6:
				if (ptr->y != ptr2->y) return 0;
			case 5:
				if (ptr->t != ptr2->t) return 0;
			case 4:
				if (ptr->r != ptr2->r) return 0;
			case 3:
				if (ptr->e != ptr2->e) return 0;
			case 2:
				if (ptr->w != ptr2->w) return 0;
			case 1:
				if (ptr->q != ptr2->q) return 0;
			}
		}
	}
	else if (typeid(subprogram_call) == typeid(*fact) && typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		subprogram_call* ptr = dynamic_cast<subprogram_call*>(fact);
		subprogram_call* ptr2 = dynamic_cast<subprogram_call*>(Treesfact);
		state_node* ptr1 = dynamic_cast<state_node*>(fact);
		state_node* ptr12 = dynamic_cast<state_node*>(Treesfact);
		size_t siz = ptr->q.size();

		if (p)
		{
			switch (p)
			{
			case 5:
				if (ptr->w != ptr2->w) return 0;
			case 4: //vector
				if (ptr2->q.size() != ptr->q.size()) return 0;
				else if (ptr2->q.empty() != ptr->q.empty()) return 0;
				else if (!(ptr2->q.empty() && ptr->q.empty()))
					for (int i = 0; i < siz; i++)
					if (!(ptr->q[i] == ptr2->q[i])) return 0;
			case 3:
			case 2:
				if (ptr1->w != ptr12->w) return 0;
			case 1:
				if (ptr1->q != ptr12->q) return 0;
			}
		}
	}
	else if (typeid(dataflow) == typeid(*fact)&& typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		dataflow* ptr = dynamic_cast<dataflow*>(fact);
		dataflow* ptr2 = dynamic_cast<dataflow*>(Treesfact);
		state_node* ptr1 = dynamic_cast<state_node*>(fact);
		state_node* ptr12 = dynamic_cast<state_node*>(Treesfact);
		size_t siz = ptr->q.size();

		if (p)
		{
			switch (p)
			{
			case 5:
				if (ptr->w != ptr2->w) return 0;
			case 4: //vector
				if (ptr2->q.size() != ptr->q.size()) return 0;
				else if (ptr2->q.empty() != ptr->q.empty()) return 0;
				else if (!(ptr2->q.empty() && ptr->q.empty()))
					for (int i = 0; i < siz; i++)
					if (!(ptr->q[i] == ptr2->q[i])) return 0;
			case 3:
			case 2:
				if (ptr1->w != ptr12->w) return 0;
			case 1:
				if (ptr1->q != ptr12->q) return 0;
			}
		}
	}
	else if (typeid(ifthen) == typeid(*fact) && typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		ifthen* ptr = dynamic_cast<ifthen*>(fact);
		ifthen* ptr2 = dynamic_cast<ifthen*>(Treesfact);
		state_node* ptr1 = dynamic_cast<state_node*>(fact);
		state_node* ptr12 = dynamic_cast<state_node*>(Treesfact);
		size_t siz = ptr->q.size();
		size_t siz2 = ptr->w.size();
		size_t siz3 = ptr->e.size();

		if (p)
		{
			switch (p)
			{
			case 8:
				if (ptr->t != ptr2->t) return 0;
			case 7:
				if (ptr->r != ptr2->r) return 0;
			case 6: //vector3
				if (ptr2->e.size() != ptr->e.size()) return 0;
				else if (ptr2->e.empty() != ptr->e.empty()) return 0;
				else if (!(ptr2->e.empty() && ptr->e.empty()))
					for (int i = 0; i < siz3; i++)
					if (!(ptr->e[i] == ptr2->e[i])) return 0;
			case 5: //vector2
				if (ptr2->w.size() != ptr->w.size()) return 0;
				else if (ptr2->w.empty() != ptr->w.empty()) return 0;
				else if (!(ptr2->w.empty() && ptr->w.empty()))
					for (int i = 0; i < siz2; i++)
					if (!(ptr->w[i] == ptr2->w[i])) return 0;
			case 4: //vector
				if (ptr2->q.size() != ptr->q.size()) return 0;
				else if (ptr2->q.empty() != ptr->q.empty()) return 0;
				else if (!(ptr2->q.empty() && ptr->q.empty()))
				for (int i = 0; i < siz; i++)
					if (!(ptr->q[i] == ptr2->q[i])) return 0;
			case 3:
			case 2:
				if (ptr1->w != ptr12->w) return 0;
			case 1:
				if (ptr1->q != ptr12->q) return 0;
			}
		}
	}
	else if (typeid(jump) == typeid(*fact)&& typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		jump* ptr = dynamic_cast<jump*>(fact);
		jump* ptr2 = dynamic_cast<jump*>(Treesfact);
		state_node* ptr1 = dynamic_cast<state_node*>(fact);
		state_node* ptr12 = dynamic_cast<state_node*>(Treesfact);
		size_t siz = ptr->q.size();

		if (p)
		{
			switch (p)
			{
			case 5:
				if (ptr->w != ptr2->w) return 0;
			case 4: //vector
				if (ptr2->q.size() != ptr->q.size()) return 0;
				else if (ptr2->q.empty() != ptr->q.empty()) return 0;
				else if (!(ptr2->q.empty() && ptr->q.empty()))
					for (int i = 0; i < siz; i++)
					if (!(ptr->q[i] == ptr2->q[i])) return 0;
			case 3:
			case 2:
				if (ptr1->w != ptr12->w) return 0;
			case 1:
				if (ptr1->q != ptr12->q) return 0;
			}
		}
	}
	else if (typeid(return_cos) == typeid(*fact)&& typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		return_cos* ptr = dynamic_cast<return_cos*>(fact);
		return_cos* ptr2 = dynamic_cast<return_cos*>(Treesfact);
		state_node* ptr1 = dynamic_cast<state_node*>(fact);
		state_node* ptr12 = dynamic_cast<state_node*>(Treesfact);

		size_t siz = ptr->q.size();

		if (p)
		{
			switch (p)
			{
			case 4: //vector
				if (ptr2->q.size() != ptr->q.size()) return 0;
				else if (ptr2->q.empty() != ptr->q.empty()) return 0;
				else if (!(ptr2->q.empty() && ptr->q.empty()))
					for (int i = 0; i < siz; i++)
					if (!(ptr->q[i] == ptr2->q[i])) return 0;
			case 3:
			case 2:
				if (ptr1->w != ptr12->w) return 0;
			case 1:
				if (ptr1->q != ptr12->q) return 0;
			}
		}
	}
	else if (typeid(state_node) == typeid(*fact))
	{
		if (typeid(subprogram_call) == typeid(*Treesfact) || typeid(dataflow) == typeid(*Treesfact) ||
			typeid(ifthen) == typeid(*Treesfact) || typeid(jump) == typeid(*Treesfact) || 
			typeid(return_cos) == typeid(*Treesfact))
		{		
			flag = 0;
			state_node* ptr = dynamic_cast<state_node*>(fact);
			state_node* ptr2 = dynamic_cast<state_node*>(Treesfact);

			if (p)
			{
				switch (p)
				{
				case 2:
					if (ptr->w != ptr2->w) return 0;
				case 1:
					if (ptr->q != ptr2->q) return 0;
				}
			}
		}
	}
	else if (typeid(change_op_number) == typeid(*fact)&& typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		change_op_number* ptr = dynamic_cast<change_op_number*>(fact);
		change_op_number* ptr2 = dynamic_cast<change_op_number*>(Treesfact);
		if (p)
		{
			switch (p)
			{
			case 3:
				if (ptr->e != ptr2->e) return 0;
			case 2:
				if (ptr->w != ptr2->w) return 0;
			case 1:
				if (ptr->q != ptr2->q) return 0;
			}
		}
	}
	else if (typeid(last_change_op_number) == typeid(*fact)&& typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		last_change_op_number* ptr = dynamic_cast<last_change_op_number*>(fact);
		last_change_op_number* ptr2 = dynamic_cast<last_change_op_number*>(Treesfact);
		if (p)
		{
			switch (p)
			{
			case 3:
				if (ptr->e != ptr2->e) return 0;
			case 2:
				if (ptr->w != ptr2->w) return 0;
			case 1:
				if (ptr->q != ptr2->q) return 0;
			}
		}
	}
	else if (typeid(op_guards) == typeid(*fact)&& typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		op_guards* ptr = dynamic_cast<op_guards*>(fact);
		op_guards* ptr2 = dynamic_cast<op_guards*>(Treesfact);
		size_t siz = ptr->e.size();
		size_t siz2 = ptr->r.size();

		if (p)
		{
			switch (p)
			{
			case 4: //vector2
				if (ptr2->r.size() != ptr->r.size()) return 0;
				else if (ptr2->r.empty() != ptr->r.empty()) return 0;
				else if (!(ptr2->r.empty() && ptr->r.empty()))
					for (int i = 0; i < siz2; i++)
					if (!(ptr->r[i] == ptr2->r[i])) return 0;
			case 3: //vector
				if (ptr2->e.size() != ptr->e.size()) return 0;
				else if (ptr2->e.empty() != ptr->e.empty()) return 0;
				else if (!(ptr2->e.empty() && ptr->e.empty()))
					for (int i = 0; i < siz; i++)
					if (!(ptr->e[i] == ptr2->e[i])) return 0;
			case 2:
				if (ptr->w != ptr2->w) return 0;
			case 1:
				if (ptr->q != ptr2->q) return 0;
			}
		}
	}
	else if (typeid(var_guards) == typeid(*fact)&& typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		var_guards* ptr = dynamic_cast<var_guards*>(fact);
		var_guards* ptr2 = dynamic_cast<var_guards*>(Treesfact);
		size_t siz = ptr->e.size();
		size_t siz2 = ptr->r.size();

		if (p)
		{
			switch (p)
			{
			case 4: //vector2
				if (ptr2->r.size() != ptr->r.size()) return 0;
				else if (ptr2->r.empty() != ptr->r.empty()) return 0;
				else if (!(ptr2->r.empty() && ptr->r.empty()))
					for (int i = 0; i < siz2; i++)
					if (!(ptr->r[i] == ptr2->r[i])) return 0;
			case 3: //vector
				if (ptr2->e.size() != ptr->e.size()) return 0;
				else if (ptr2->e.empty() != ptr->e.empty()) return 0;
				else if (!(ptr2->e.empty() && ptr->e.empty()))
					for (int i = 0; i < siz; i++)
					if (!(ptr->e[i] == ptr2->e[i])) return 0;
			case 2:
				if (ptr->w != ptr2->w) return 0;
			case 1:
				if (ptr->q != ptr2->q) return 0;
			}
		}
	}
	else if (typeid(guard_pair) == typeid(*fact)&& typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		guard_pair* ptr = dynamic_cast<guard_pair*>(fact);
		guard_pair* ptr2 = dynamic_cast<guard_pair*>(Treesfact);
		if (p)
		{
			switch (p)
			{
			case 4:
				if (ptr->r != ptr2->r) return 0;
			case 3:
				if (ptr->e != ptr2->e) return 0;
			case 2:
				if (ptr->w != ptr2->w) return 0;
			case 1:
				if (ptr->q != ptr2->q) return 0;
			}
		}
	}
	else if (typeid(guard_cond) == typeid(*fact)&& typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		guard_cond* ptr = dynamic_cast<guard_cond*>(fact);
		guard_cond* ptr2 = dynamic_cast<guard_cond*>(Treesfact);
		if (p)
		{
			switch (p)
			{
			case 4:
				if (ptr->r != ptr2->r) return 0;
			case 3:
				if (ptr->e != ptr2->e) return 0;
			case 2:
				if (ptr->w != ptr2->w) return 0;
			case 1:
				if (ptr->q != ptr2->q) return 0;
			}
		}
	}
	else if (typeid(predecessors) == typeid(*fact)&& typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		predecessors* ptr = dynamic_cast<predecessors*>(fact);
		predecessors* ptr2 = dynamic_cast<predecessors*>(Treesfact);
		size_t siz = ptr->e.size();

		if (p)
		{
			switch (p)
			{
			case 3: //vector
				if (ptr2->e.size() != ptr->e.size()) return 0;
				else if (ptr2->e.empty() != ptr->e.empty()) return 0;
				else if (!(ptr2->e.empty() && ptr->e.empty()))
					for (int i = 0; i < siz; i++)
					if (!(ptr->e[i] == ptr2->e[i])) return 0;
			case 2:
				if (ptr->w != ptr2->w) return 0;
			case 1:
				if (ptr->q != ptr2->q) return 0;
			}
		}
	}
	else if (typeid(cessor) == typeid(*fact)&& typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		cessor* ptr = dynamic_cast<cessor*>(fact);
		cessor* ptr2 = dynamic_cast<cessor*>(Treesfact);
		if (p)
		{
			switch (p)
			{
			case 3:
				if (ptr->e != ptr2->e) return 0;
			case 2:
				if (ptr->w != ptr2->w) return 0;
			case 1:
				if (ptr->q != ptr2->q) return 0;
			}
		}
	}
	else if (typeid(cessor_kind) == typeid(*fact)&& typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		cessor_kind* ptr = dynamic_cast<cessor_kind*>(fact);
		cessor_kind* ptr2 = dynamic_cast<cessor_kind*>(Treesfact);
		size_t siz = ptr->u.size();

		if (p)
		{
			switch (p)
			{
			case 7:
				if (ptr2->u.size() != ptr->u.size()) return 0;
				for (int i = 0; i < siz; i++)
					if (!(ptr->u[i] == ptr2->u[i])) return 0;
			case 6:
				if (ptr->y != ptr2->y) return 0;
			case 5:
				if (ptr->t != ptr2->t) return 0;
			case 4:
				if (ptr->r != ptr2->r) return 0;
			case 3:
				if (ptr->e != ptr2->e) return 0;
			case 2:
				if (ptr->w != ptr2->w) return 0;
			case 1:
				if (ptr->q != ptr2->q) return 0;
			}
		}
	}
	else if (typeid(old_schedule) == typeid(*fact)&& typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		old_schedule* ptr = dynamic_cast<old_schedule*>(fact);
		old_schedule* ptr2 = dynamic_cast<old_schedule*>(Treesfact);
		if (p)
		{
			if (ptr->q != ptr2->q) return 0;
		}
	}
	else if (typeid(new_schedule) == typeid(*fact)&& typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		new_schedule* ptr = dynamic_cast<new_schedule*>(fact);
		new_schedule* ptr2 = dynamic_cast<new_schedule*>(Treesfact);
		if (p)
		{
			if (ptr->q != ptr2->q) return 0;
		}
	}
	else if (typeid(local_ifthen_chain_end_operations_were_written) == typeid(*fact)&& typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		local_ifthen_chain_end_operations_were_written* ptr = dynamic_cast<local_ifthen_chain_end_operations_were_written*>(fact);
		local_ifthen_chain_end_operations_were_written* ptr2 = dynamic_cast<local_ifthen_chain_end_operations_were_written*>(Treesfact);
		if (p)
		{
			if (ptr->q != ptr2->q) return 0;
		}
	}
	else if (typeid(calls_list) == typeid(*fact)&& typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		calls_list* ptr = dynamic_cast<calls_list*>(fact);
		calls_list* ptr2 = dynamic_cast<calls_list*>(Treesfact);
		size_t siz = ptr->r.size();

		if (p)
		{
			switch (p)
			{
			case 4: //vector
				if (ptr2->r.size() != ptr->r.size()) return 0;
				else if (ptr2->r.empty() != ptr->r.empty()) return 0;
				else if (!(ptr2->r.empty() && ptr->r.empty()))
					for (int i = 0; i < siz; i++)
					if (!(ptr->r[i] == ptr2->r[i])) return 0;
			case 3:
				if (ptr->e != ptr2->e) return 0;
			case 2:
				if (ptr->w != ptr2->w) return 0;
			case 1:
				if (ptr->q != ptr2->q) return 0;
			}
		}
	}
	else if (typeid(composites_list) == typeid(*fact)&& typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		composites_list* ptr = dynamic_cast<composites_list*>(fact);
		composites_list* ptr2 = dynamic_cast<composites_list*>(Treesfact);
		size_t siz = ptr->e.size();

		if (p)
		{
			switch (p)
			{
			case 3: //vector
				if (ptr2->e.size() != ptr->e.size()) return 0;
				else if (ptr2->e.empty() != ptr->e.empty()) return 0;
				else if (!(ptr2->e.empty() && ptr->e.empty()))
					for (int i = 0; i < siz; i++)
					if (!(ptr->e[i] == ptr2->e[i])) return 0;
			case 2:
				if (ptr->w != ptr2->w) return 0;
			case 1:
				if (ptr->q != ptr2->q) return 0;
			}
		}
	}
	else if (typeid(record_aggregates_list) == typeid(*fact)&& typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		record_aggregates_list* ptr = dynamic_cast<record_aggregates_list*>(fact);
		record_aggregates_list* ptr2 = dynamic_cast<record_aggregates_list*>(Treesfact);
		size_t siz = ptr->e.size();

		if (p)
		{
			switch (p)
			{
			case 3: //vector
				if (ptr2->e.size() != ptr->e.size()) return 0;
				else if (ptr2->e.empty() != ptr->e.empty()) return 0;
				else if (!(ptr2->e.empty() && ptr->e.empty()))
					for (int i = 0; i < siz; i++)
					if (!(ptr->e[i] == ptr2->e[i])) return 0;
			case 2:
				if (ptr->w != ptr2->w) return 0;
			case 1:
				if (ptr->q != ptr2->q) return 0;
			}
		}
	}
	else if (typeid(mem_port) == typeid(*fact)&& typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		mem_port* ptr = dynamic_cast<mem_port*>(fact);
		mem_port* ptr2 = dynamic_cast<mem_port*>(Treesfact);
		if (p)
		{
			switch (p)
			{
			case 13:
				if (ptr->d != ptr2->d) return 0;
			case 12:
				if (ptr->s != ptr2->s) return 0;
			case 11:
				if (ptr->a != ptr2->a) return 0;
			case 10:
				if (ptr->p != ptr2->p) return 0;
			case 9:
				if (ptr->o != ptr2->o) return 0;
			case 8:
				if (ptr->i != ptr2->i) return 0;
			case 7:
				if (ptr->u != ptr2->u) return 0;
			case 6:
				if (ptr->y != ptr2->y) return 0;
			case 5:
				if (ptr->t != ptr2->t) return 0;
			case 4:
				if (ptr->r != ptr2->r) return 0;
			case 3:
				if (ptr->e != ptr2->e) return 0;
			case 2:
				if (ptr->w != ptr2->w) return 0;
			case 1:
				if (ptr->q != ptr2->q) return 0;
			}
		}
	}
	else if (typeid(global_declarations) == typeid(*fact)&& typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		global_declarations* ptr = dynamic_cast<global_declarations*>(fact);
		global_declarations* ptr2 = dynamic_cast<global_declarations*>(Treesfact);
		
		if (p)
		{
			if (ptr->w != NULL)
			{
				if (ptr->w != ptr2->w) return 0;
				--p;
			}
			//vector
			if (ptr2->q.size() < ptr->q.size()) return 0;
			else if (ptr2->q.empty() != ptr->q.empty()) return 0;
			else if (!(ptr2->q.empty() && ptr->q.empty()))
				for (int i = 0; i < p; i++)
			{
				if (ptr->q[i].q != ptr2->q[i].q) return 0;
				if (ptr->q[i].w != ptr2->q[i].w) return 0;
				if (ptr->q[i].e != ptr2->q[i].e) return 0;
				if (ptr->q[i].r != ptr2->q[i].r) return 0;
				if (ptr->q[i].t != ptr2->q[i].t) return 0;
				if (ptr->q[i].y != ptr2->q[i].y) return 0;
				if (ptr->q[i].u != ptr2->q[i].u) return 0;
				if (ptr->q[i].i != ptr2->q[i].i) return 0;
				if (ptr->q[i].o != ptr2->q[i].o) return 0;
			}
		}
	}
	else if (typeid(source_is_normal_dt) == typeid(*fact)&& typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		source_is_normal_dt* ptr = dynamic_cast<source_is_normal_dt*>(fact);
		source_is_normal_dt* ptr2 = dynamic_cast<source_is_normal_dt*>(Treesfact);
		
		if (p)
		{
			switch (p)
			{
			case 3:
				if (ptr->e != ptr2->e) return 0;
			case 2:
				if (ptr->w != ptr2->w) return 0;
			case 1:
				if (ptr->q != ptr2->q) return 0;
			}
		}
	}
	else if (typeid(combo) == typeid(*fact)&& typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		combo* ptr = dynamic_cast<combo*>(fact);
		combo* ptr2 = dynamic_cast<combo*>(Treesfact);
		
		if (p)
		{
			switch (p)
			{
			case 3:
				if (ptr->e != ptr2->e) return 0;
			case 2:
				if (ptr->w != ptr2->w) return 0;
			case 1:
				if (ptr->q != ptr2->q) return 0;
			}
		}
	}
	else if (typeid(sequence) == typeid(*fact)&& typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		sequence* ptr = dynamic_cast<sequence*>(fact);
		sequence* ptr2 = dynamic_cast<sequence*>(Treesfact);
		if (p)
		{
			switch (p)
			{
			case 3:
				if (ptr->e != ptr2->e) return 0;
			case 2:
				if (ptr->w != ptr2->w) return 0;
			case 1:
				if (ptr->q != ptr2->q) return 0;
			}
		}
	}
	else if (typeid(for_loop) == typeid(*fact)&& typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		for_loop* ptr = dynamic_cast<for_loop*>(fact);
		for_loop* ptr2 = dynamic_cast<for_loop*>(Treesfact);

		if (p)
		{
			switch (p)
			{
			case 13:
				if (ptr->d != ptr2->d) return 0;
			case 12:
				if (ptr->s != ptr2->s) return 0;
			case 11:
				if (ptr->a != ptr2->a) return 0;
			case 10:
				if (ptr->p != ptr2->p) return 0;
			case 9:
				if (ptr->o != ptr2->o) return 0;
			case 8:
				if (ptr->i != ptr2->i) return 0;
			case 7:
				if (ptr->u != ptr2->u) return 0;
			case 6:
				if (ptr->y != ptr2->y) return 0;
			case 5:
				if (ptr->t != ptr2->t) return 0;
			case 4:
				if (ptr->r != ptr2->r) return 0;
			case 3:
				if (ptr->e != ptr2->e) return 0;
			case 2:
				if (ptr->w != ptr2->w) return 0;
			case 1:
				if (ptr->q != ptr2->q) return 0;
			}
		}
	}
	else if (typeid(last_for_loop_entry) == typeid(*fact)&& typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		last_for_loop_entry* ptr = dynamic_cast<last_for_loop_entry*>(fact);
		last_for_loop_entry* ptr2 = dynamic_cast<last_for_loop_entry*>(Treesfact);
		if (p)
		{
			if (ptr->q != ptr2->q) return 0;
		}
	}
	else if (typeid(while_loop) == typeid(*fact)&& typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		while_loop* ptr = dynamic_cast<while_loop*>(fact);
		while_loop* ptr2 = dynamic_cast<while_loop*>(Treesfact);

		if (p)
		{
			switch (p)
			{
			case 7:
				if (ptr->u != ptr2->u) return 0;
			case 6:
				if (ptr->y != ptr2->y) return 0;
			case 5:
				if (ptr->t != ptr2->t) return 0;
			case 4:
				if (ptr->r != ptr2->r) return 0;
			case 3:
				if (ptr->e != ptr2->e) return 0;
			case 2:
				if (ptr->w != ptr2->w) return 0;
			case 1:
				if (ptr->q != ptr2->q) return 0;
			}
		}
	}
	else if (typeid(last_while_loop_entry) == typeid(*fact)&& typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		last_while_loop_entry* ptr = dynamic_cast<last_while_loop_entry*>(fact);
		last_while_loop_entry* ptr2 = dynamic_cast<last_while_loop_entry*>(Treesfact);
		if (p)
		{
			if (ptr->q != ptr2->q) return 0;
		}
	}
	else if (typeid(possible_end_if) == typeid(*fact)&& typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		possible_end_if* ptr = dynamic_cast<possible_end_if*>(fact);
		possible_end_if* ptr2 = dynamic_cast<possible_end_if*>(Treesfact);
		size_t	siz = ptr2->w.size();

		if (p)
		{
			switch (p)
			{
			case 2: //vector
				if (ptr2->w.size() != ptr->w.size()) return 0;
				else if (ptr2->w.empty() != ptr->w.empty()) return 0;
				else if (!(ptr2->w.empty() && ptr->w.empty()))
					for (int i = 0; i < siz; i++)
					if (!(ptr->w[i] == ptr2->w[i])) return 0;
			case 1:
				if (ptr->q != ptr2->q) return 0;
			}
		}
	}
	else if (typeid(end_if) == typeid(*fact)&& typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		end_if* ptr = dynamic_cast<end_if*>(fact);
		end_if* ptr2 = dynamic_cast<end_if*>(Treesfact);
		size_t	siz = ptr2->w.size();

		if (p)
		{
			switch (p)
			{
			case 2: //vector
				if (ptr2->w.size() != ptr->w.size()) return 0;
				else if (ptr2->w.empty() != ptr->w.empty()) return 0;
				else if (!(ptr2->w.empty() && ptr->w.empty()))
					for (int i = 0; i < siz; i++)
					if (!(ptr->w[i] == ptr2->w[i])) return 0;
			case 1:
				if (ptr->q != ptr2->q) return 0;
			}
		}
	}
	else if (typeid(nested_cond_fact) == typeid(*fact)&& typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		nested_cond_fact* ptr = dynamic_cast<nested_cond_fact*>(fact);
		nested_cond_fact* ptr2 = dynamic_cast<nested_cond_fact*>(Treesfact);
		size_t	siz = ptr2->w.size();

		if (p)
		{
			switch (p)
			{
			case 2: //vector
				if (ptr2->w.size() != ptr->w.size()) return 0;
				else if (ptr2->w.empty() != ptr->w.empty()) return 0;
				else if (!(ptr2->w.empty() && ptr->w.empty()))
				for (int i = 0; i < siz; i++)
					if (!(ptr->w[i] == ptr2->w[i])) return 0;
			case 1:
				if (ptr->q != ptr2->q) return 0;
			}
		}
	}
	else if (typeid(top_level_call) == typeid(*fact)&& typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		top_level_call* ptr = dynamic_cast<top_level_call*>(fact);
		top_level_call* ptr2 = dynamic_cast<top_level_call*>(Treesfact);
		if (p)
		{
			switch (p)
			{
			case 11:
				if (ptr->a != ptr2->a) return 0;
			case 10:
				if (ptr->p != ptr2->p) return 0;
			case 9:
				if (ptr->o != ptr2->o) return 0;
			case 8:
				if (ptr->i != ptr2->i) return 0;
			case 7:
				if (ptr->u != ptr2->u) return 0;
			case 6:
				if (ptr->y != ptr2->y) return 0;
			case 5:
				if (ptr->t != ptr2->t) return 0;
			case 4:
				if (ptr->r != ptr2->r) return 0;
			case 3:
				if (ptr->e != ptr2->e) return 0;
			case 2:
				if (ptr->w != ptr2->w) return 0;
			case 1:
				if (ptr->q != ptr2->q) return 0;
			}
		}
	}
	else if (typeid(top_level_call_parcs) == typeid(*fact)&& typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		top_level_call_parcs* ptr = dynamic_cast<top_level_call_parcs*>(fact);
		top_level_call_parcs* ptr2 = dynamic_cast<top_level_call_parcs*>(Treesfact);
		if (p)
		{
			switch (p)
			{
			case 11:
				if (ptr->a != ptr2->a) return 0;
			case 10:
				if (ptr->p != ptr2->p) return 0;
			case 9:
				if (ptr->o != ptr2->o) return 0;
			case 8:
				if (ptr->i != ptr2->i) return 0;
			case 7:
				if (ptr->u != ptr2->u) return 0;
			case 6:
				if (ptr->y != ptr2->y) return 0;
			case 5:
				if (ptr->t != ptr2->t) return 0;
			case 4:
				if (ptr->r != ptr2->r) return 0;
			case 3:
				if (ptr->e != ptr2->e) return 0;
			case 2:
				if (ptr->w != ptr2->w) return 0;
			case 1:
				if (ptr->q != ptr2->q) return 0;
			}
		}
	}
	else if (typeid(added_aux_call_ios) == typeid(*fact)&& typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		added_aux_call_ios* ptr = dynamic_cast<added_aux_call_ios*>(fact);
		added_aux_call_ios* ptr2 = dynamic_cast<added_aux_call_ios*>(Treesfact);
		if (p)
		{
			switch (p)
			{
			case 2:
				if (ptr->w != ptr2->w) return 0;
			case 1:
				if (ptr->q != ptr2->q) return 0;
			}
		}
	}
	else if (typeid(added_aux_call_ios1) == typeid(*fact)&& typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		added_aux_call_ios1* ptr = dynamic_cast<added_aux_call_ios1*>(fact);
		added_aux_call_ios1* ptr2 = dynamic_cast<added_aux_call_ios1*>(Treesfact);
		if (p)
		{
			switch (p)
			{
			case 3:
				if (ptr->e != ptr2->e) return 0;
			case 2:
				if (ptr->w != ptr2->w) return 0;
			case 1:
				if (ptr->q != ptr2->q) return 0;
			}
		}
	}
	else if (typeid(added_aux_call_signals) == typeid(*fact)&& typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		added_aux_call_signals* ptr = dynamic_cast<added_aux_call_signals*>(fact);
		added_aux_call_signals* ptr2 = dynamic_cast<added_aux_call_signals*>(Treesfact);
		if (p)
		{
			switch (p)
			{
			case 2:
				if (ptr->w != ptr2->w) return 0;
			case 1:
				if (ptr->q != ptr2->q) return 0;
			}
		}
	}
	else if (typeid(found_call_operator) == typeid(*fact)&& typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		found_call_operator* ptr = dynamic_cast<found_call_operator*>(fact);
		found_call_operator* ptr2 = dynamic_cast<found_call_operator*>(Treesfact);
		if (p)
		{
			switch (p)
			{
			case 2:
				if (ptr->w != ptr2->w) return 0;
			case 1:
				if (ptr->q != ptr2->q) return 0;
			}
		}
	}
	else if (typeid(added_verilog_aux_call_outputs) == typeid(*fact)&& typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		added_verilog_aux_call_outputs* ptr = dynamic_cast<added_verilog_aux_call_outputs*>(fact);
		added_verilog_aux_call_outputs* ptr2 = dynamic_cast<added_verilog_aux_call_outputs*>(Treesfact);
		if (p)
		{
			switch (p)
			{
			case 3:
				if (ptr->e != ptr2->e) return 0;
			case 2:
				if (ptr->w != ptr2->w) return 0;
			case 1:
				if (ptr->q != ptr2->q) return 0;
			}
		}
	}
	else if (typeid(raw_dependencies) == typeid(*fact)&& typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		raw_dependencies* ptr = dynamic_cast<raw_dependencies*>(fact);
		raw_dependencies* ptr2 = dynamic_cast<raw_dependencies*>(Treesfact);
		size_t siz = ptr->e.size();
		size_t siz2 = ptr->r.size();

		if (p)
		{
			switch (p)
			{
			case 4: //vector2
				if (ptr2->r.size() != ptr->r.size()) return 0;
				else if (ptr2->r.empty() != ptr->r.empty()) return 0;
				else if (!(ptr2->r.empty() && ptr->r.empty()))
					for (int i = 0; i < siz2; i++)
					if (!(ptr->r[i] == ptr2->r[i])) return 0;
			case 3: //vector
				if (ptr2->e.size() != ptr->e.size()) return 0;
				else if (ptr2->e.empty() != ptr->e.empty()) return 0;
				else if (!(ptr2->e.empty() && ptr->e.empty()))
					for (int i = 0; i < siz; i++)
					if (!(ptr->e[i] == ptr2->e[i])) return 0;
			case 2:
				if (ptr->w != ptr2->w) return 0;
			case 1:
				if (ptr->q != ptr2->q) return 0;
			}
		}
	}
	else if (typeid(war_dependencies) == typeid(*fact) && typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		war_dependencies* ptr = dynamic_cast<war_dependencies*>(fact);
		war_dependencies* ptr2 = dynamic_cast<war_dependencies*>(Treesfact);
		size_t siz = ptr->e.size();
		size_t siz2 = ptr->r.size();

		if (p)
		{
			switch (p)
			{
			case 4: //vector2
				if (ptr2->r.size() != ptr->r.size()) return 0;
				else if (ptr2->r.empty() != ptr->r.empty()) return 0;
				else if (!(ptr2->r.empty() && ptr->r.empty()))
					for (int i = 0; i < siz2; i++)
					if (!(ptr->r[i] == ptr2->r[i])) return 0;
			case 3: //vector
				if (ptr2->e.size() != ptr->e.size()) return 0;
				else if (ptr2->e.empty() != ptr->e.empty()) return 0;
				else if (!(ptr2->e.empty() && ptr->e.empty()))
					for (int i = 0; i < siz; i++)
					if (!(ptr->e[i] == ptr2->e[i])) return 0;
			case 2:
				if (ptr->w != ptr2->w) return 0;
			case 1:
				if (ptr->q != ptr2->q) return 0;
			}
		}
	}
	else if (typeid(waw_dependencies) == typeid(*fact)&& typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		waw_dependencies* ptr = dynamic_cast<waw_dependencies*>(fact);
		waw_dependencies* ptr2 = dynamic_cast<waw_dependencies*>(Treesfact);
		size_t siz = ptr->e.size();
		size_t siz2 = ptr->r.size();

		if (p)
		{
			switch (p)
			{
			case 4: //vector2
				if (ptr2->r.size() != ptr->r.size()) return 0;
				else if (ptr2->r.empty() != ptr->r.empty()) return 0;
				else if (!(ptr2->r.empty() && ptr->r.empty()))
					for (int i = 0; i < siz2; i++)
					if (!(ptr->r[i] == ptr2->r[i])) return 0;
			case 3: //vector
				if (ptr2->e.size() != ptr->e.size()) return 0;
				else if (ptr2->e.empty() != ptr->e.empty()) return 0;
				else if (!(ptr2->e.empty() && ptr->e.empty()))
					for (int i = 0; i < siz; i++)
					if (!(ptr->e[i] == ptr2->e[i])) return 0;
			case 2:
				if (ptr->w != ptr2->w) return 0;
			case 1:
				if (ptr->q != ptr2->q) return 0;
			}
		}
	}
	else if (typeid(schedule) == typeid(*fact)&& typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		schedule* ptr = dynamic_cast<schedule*>(fact);
		schedule* ptr2 = dynamic_cast<schedule*>(Treesfact);
		if (p)
		{
			switch (p)
			{
			case 4:
				if (ptr->r != ptr2->r) return 0;
			case 3:
				if (ptr->e != ptr2->e) return 0;
			case 2:
				if (ptr->w != ptr2->w) return 0;
			case 1:
				if (ptr->q != ptr2->q) return 0;
			}
		}
	}
	else if (typeid(last_conditional_execution) == typeid(*fact)&& typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		last_conditional_execution* ptr = dynamic_cast<last_conditional_execution*>(fact);
		last_conditional_execution* ptr2 = dynamic_cast<last_conditional_execution*>(Treesfact);
		if (p)
		{
			switch (p)
			{
			case 2:
				if (ptr->w != ptr2->w) return 0;
			case 1:
				if (ptr->q != ptr2->q) return 0;
			}
		}
	}
	else if (typeid(conditional_operations) == typeid(*fact)&& typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		conditional_operations* ptr = dynamic_cast<conditional_operations*>(fact);
		conditional_operations* ptr2 = dynamic_cast<conditional_operations*>(Treesfact);
		size_t siz = ptr->t.size();
		size_t siz2 = ptr->y.size();
		size_t siz3 = ptr->u.size();
		size_t siz4 = ptr->i.size();

		if (p)
		{
			switch (p)
			{
			case 8: //vector4
				if (ptr2->i.size() != ptr->i.size()) return 0;
				else if (ptr2->i.empty() != ptr->i.empty()) return 0;
				else if (!(ptr2->i.empty() && ptr->i.empty()))
					for (int i = 0; i < siz4; i++)
					if (!(ptr->i[i] == ptr2->i[i])) return 0;
			case 7: //vector3
				if (ptr2->u.size() != ptr->u.size()) return 0;
				else if (ptr2->u.empty() != ptr->u.empty()) return 0;
				else if (!(ptr2->u.empty() && ptr->u.empty()))
					for (int i = 0; i < siz3; i++)
					if (!(ptr->u[i] == ptr2->u[i])) return 0;
			case 6: //vector2
				if (ptr2->y.size() != ptr->y.size()) return 0;
				else if (ptr2->y.empty() != ptr->y.empty()) return 0;
				else if (!(ptr2->y.empty() && ptr->y.empty()))
					for (int i = 0; i < siz2; i++)
					if (!(ptr->y[i] == ptr2->y[i])) return 0;
			case 5: //vector
				if (ptr2->t.size() != ptr->t.size()) return 0;
				else if (ptr2->t.empty() != ptr->t.empty()) return 0;
				else if (!(ptr2->t.empty() && ptr->t.empty()))
					for (int i = 0; i < siz; i++)
					if (!(ptr->t[i] == ptr2->t[i])) return 0;
			case 4:
				if (ptr->r != ptr2->r) return 0;
			case 3:
				if (ptr->e != ptr2->e) return 0;
			case 2:
				if (ptr->w != ptr2->w) return 0;
			case 1:
				if (ptr->q != ptr2->q) return 0;
			}
		}
	}
	else if (typeid(last_conditional_transition_of_schedule) == typeid(*fact)&& typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		last_conditional_transition_of_schedule* ptr = dynamic_cast<last_conditional_transition_of_schedule*>(fact);
		last_conditional_transition_of_schedule* ptr2 = dynamic_cast<last_conditional_transition_of_schedule*>(Treesfact);
		if (p)
		{
			switch (p)
			{
			case 3:
				if (ptr->e != ptr2->e) return 0;
			case 2:
				if (ptr->w != ptr2->w) return 0;
			case 1:
				if (ptr->q != ptr2->q) return 0;
			}
		}
	}
	else if (typeid(transition_to_be_rescheduled) == typeid(*fact)&& typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		transition_to_be_rescheduled* ptr = dynamic_cast<transition_to_be_rescheduled*>(fact);
		transition_to_be_rescheduled* ptr2 = dynamic_cast<transition_to_be_rescheduled*>(Treesfact);
		if (p)
		{
			switch (p)
			{
			case 5:
				if (ptr->t != ptr2->t) return 0;
			case 4:
				if (ptr->r != ptr2->r) return 0;
			case 3:
				if (ptr->e != ptr2->e) return 0;
			case 2:
				if (ptr->w != ptr2->w) return 0;
			case 1:
				if (ptr->q != ptr2->q) return 0;
			}
		}
	}
	else if (typeid(last_conditional_transition) == typeid(*fact)&& typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		last_conditional_transition* ptr = dynamic_cast<last_conditional_transition*>(fact);
		last_conditional_transition* ptr2 = dynamic_cast<last_conditional_transition*>(Treesfact);
		if (p)
		{
			switch (p)
			{
			case 2:
				if (ptr->w != ptr2->w) return 0;
			case 1:
				if (ptr->q != ptr2->q) return 0;
			}
		}
	}
	else if (typeid(conditional_transitions) == typeid(*fact)&& typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		conditional_transitions* ptr = dynamic_cast<conditional_transitions*>(fact);
		conditional_transitions* ptr2 = dynamic_cast<conditional_transitions*>(Treesfact);
		if (p)
		{
			switch (p)
			{
			case 8:
				if (ptr->i != ptr2->i) return 0;
			case 7:
				if (ptr->u != ptr2->u) return 0;
			case 6:
				if (ptr->y != ptr2->y) return 0;
			case 5:
				if (ptr->t != ptr2->t) return 0;
			case 4:
				if (ptr->r != ptr2->r) return 0;
			case 3:
				if (ptr->e != ptr2->e) return 0;
			case 2:
				if (ptr->w != ptr2->w) return 0;
			case 1:
				if (ptr->q != ptr2->q) return 0;
			}
		}
	}
	else if (typeid(state) == typeid(*fact)&& typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		state* ptr = dynamic_cast<state*>(fact);
		state* ptr2 = dynamic_cast<state*>(Treesfact);
		size_t siz = ptr->u.size();
		size_t siz2 = ptr->i.size();

		if (p)
		{
			switch (p)
			{
			case 8: //vector2
				if (ptr2->i.size() != ptr->i.size()) return 0;
				else if (ptr2->i.empty() != ptr->i.empty()) return 0;
				else if (!(ptr2->i.empty() && ptr->i.empty()))
					for (int i = 0; i < siz2; i++)
					if (!(ptr->i[i] == ptr2->i[i])) return 0;
			case 7: //vector
				if (ptr2->u.size() != ptr->u.size()) return 0;
				else if (ptr2->u.empty() != ptr->u.empty()) return 0;
				else if (!(ptr2->u.empty() && ptr->u.empty()))
					for (int i = 0; i < siz; i++)
					if (!(ptr->u[i] == ptr2->u[i])) return 0;
			case 6:
				if (ptr->y != ptr2->y) return 0;
			case 5:
				if (ptr->t != ptr2->t) return 0;
			case 4:
				if (ptr->r != ptr2->r) return 0;
			case 3:
				if (ptr->e != ptr2->e) return 0;
			case 2:
				if (ptr->w != ptr2->w) return 0;
			case 1:
				if (ptr->q != ptr2->q) return 0;
			}
		}
	}
	else if (typeid(rescheduled) == typeid(*fact)&& typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		rescheduled* ptr = dynamic_cast<rescheduled*>(fact);
		rescheduled* ptr2 = dynamic_cast<rescheduled*>(Treesfact);
		if (p)
		{
			switch (p)
			{
			case 5:
				if (ptr->t != ptr2->t) return 0;
			case 4:
				if (ptr->r != ptr2->r) return 0;
			case 3:
				if (ptr->e != ptr2->e) return 0;
			case 2:
				if (ptr->w != ptr2->w) return 0;
			case 1:
				if (ptr->q != ptr2->q) return 0;
			}
		}
	}
	else if (typeid(last_rescheduled) == typeid(*fact)&& typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		last_rescheduled* ptr = dynamic_cast<last_rescheduled*>(fact);
		last_rescheduled* ptr2 = dynamic_cast<last_rescheduled*>(Treesfact);
		if (p)
		{
			switch (p)
			{
			case 5:
				if (ptr->t != ptr2->t) return 0;
			case 4:
				if (ptr->r != ptr2->r) return 0;
			case 3:
				if (ptr->e != ptr2->e) return 0;
			case 2:
				if (ptr->w != ptr2->w) return 0;
			case 1:
				if (ptr->q != ptr2->q) return 0;
			}
		}
	}
	else if (typeid(raw_cessor) == typeid(*fact)&& typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		raw_cessor* ptr = dynamic_cast<raw_cessor*>(fact);
		raw_cessor* ptr2 = dynamic_cast<raw_cessor*>(Treesfact);
		if (p)
		{
			switch (p)
			{
			case 3:
				if (ptr->e != ptr2->e) return 0;
			case 2:
				if (ptr->w != ptr2->w) return 0;
			case 1:
				if (ptr->q != ptr2->q) return 0;
			}
		}
	}
	else if (typeid(war_cessor) == typeid(*fact)&& typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		war_cessor* ptr = dynamic_cast<war_cessor*>(fact);
		war_cessor* ptr2 = dynamic_cast<war_cessor*>(Treesfact);
		if (p)
		{
			switch (p)
			{
			case 3:
				if (ptr->e != ptr2->e) return 0;
			case 2:
				if (ptr->w != ptr2->w) return 0;
			case 1:
				if (ptr->q != ptr2->q) return 0;
			}
		}
	}
	else if (typeid(waw_cessor) == typeid(*fact)&& typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		waw_cessor* ptr = dynamic_cast<waw_cessor*>(fact);
		waw_cessor* ptr2 = dynamic_cast<waw_cessor*>(Treesfact);
		if (p)
		{
			switch (p)
			{
			case 3:
				if (ptr->e != ptr2->e) return 0;
			case 2:
				if (ptr->w != ptr2->w) return 0;
			case 1:
				if (ptr->q != ptr2->q) return 0;
			}
		}
	}
	else if (typeid(op_resource) == typeid(*fact)&& typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		op_resource* ptr = dynamic_cast<op_resource*>(fact);
		op_resource* ptr2 = dynamic_cast<op_resource*>(Treesfact);
		if (p)
		{
			switch (p)
			{
			case 3:
				if (ptr->e != ptr2->e) return 0;
			case 2:
				if (ptr->w != ptr2->w) return 0;
			case 1:
				if (ptr->q != ptr2->q) return 0;
			}
		}
	}
	else if (typeid(global_resource) == typeid(*fact)&& typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		global_resource* ptr = dynamic_cast<global_resource*>(fact);
		global_resource* ptr2 = dynamic_cast<global_resource*>(Treesfact);
		if (p)
		{
			if (ptr->q != ptr2->q) return 0;
		}
	}
	else if (typeid(module_g_resource) == typeid(*fact)&& typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		module_g_resource* ptr = dynamic_cast<module_g_resource*>(fact);
		module_g_resource* ptr2 = dynamic_cast<module_g_resource*>(Treesfact);
		if (p)
		{
			switch (p)
			{
			case 2:
				if (ptr->w != ptr2->w) return 0;
			case 1:
				if (ptr->q != ptr2->q) return 0;
			}
		}
	}
	else if (typeid(cf_previous_op) == typeid(*fact)&& typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		cf_previous_op* ptr = dynamic_cast<cf_previous_op*>(fact);
		cf_previous_op* ptr2 = dynamic_cast<cf_previous_op*>(Treesfact);
		if (p)
		{
			switch (p)
			{
			case 4:
				if (ptr->r != ptr2->r) return 0;
			case 3:
				if (ptr->e != ptr2->e) return 0;
			case 2:
				if (ptr->w != ptr2->w) return 0;
			case 1:
				if (ptr->q != ptr2->q) return 0;
			}
		}
	}
	else if (typeid(cf_previous_state) == typeid(*fact)&& typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		cf_previous_state* ptr = dynamic_cast<cf_previous_state*>(fact);
		cf_previous_state* ptr2 = dynamic_cast<cf_previous_state*>(Treesfact);
		if (p)
		{
			switch (p)
			{
			case 4:
				if (ptr->r != ptr2->r) return 0;
			case 3:
				if (ptr->e != ptr2->e) return 0;
			case 2:
				if (ptr->w != ptr2->w) return 0;
			case 1:
				if (ptr->q != ptr2->q) return 0;
			}
		}
	}
	else if (typeid(pred_candidate_examined) == typeid(*fact)&& typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		pred_candidate_examined* ptr = dynamic_cast<pred_candidate_examined*>(fact);
		pred_candidate_examined* ptr2 = dynamic_cast<pred_candidate_examined*>(Treesfact);
		if (p)
		{
			switch (p)
			{
			case 3:
				if (ptr->e != ptr2->e) return 0;
			case 2:
				if (ptr->w != ptr2->w) return 0;
			case 1:
				if (ptr->q != ptr2->q) return 0;
			}
		}
	}
	else if (typeid(reentrant_triangle) == typeid(*fact)&& typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		reentrant_triangle* ptr = dynamic_cast<reentrant_triangle*>(fact);
		reentrant_triangle* ptr2 = dynamic_cast<reentrant_triangle*>(Treesfact);		
		size_t siz = ptr->t.size();
		size_t siz2 = ptr->y.size();
		size_t siz3 = ptr->u.size();
		size_t siz4 = ptr->i.size();
		size_t siz5 = ptr->o.size();
		size_t siz6 = ptr->p.size();

		if (p)
		{
			switch (p)
			{
			case 14:
				if (ptr->f != ptr2->f) return 0;
			case 13:
				if (ptr->d != ptr2->d) return 0;
			case 12:
				if (ptr->s != ptr2->s) return 0;
			case 11:
				if (ptr->a != ptr2->a) return 0;
			case 10: //vector6
				if (ptr2->p.size() != ptr->p.size()) return 0;
				else if (ptr2->p.empty() != ptr->p.empty()) return 0;
				else if (!(ptr2->p.empty() && ptr->p.empty()))
					for (int i = 0; i < siz6; i++)
					if (!(ptr->p[i] == ptr2->p[i])) return 0;
			case 9: //vector5
				if (ptr2->o.size() != ptr->o.size()) return 0;
				else if (ptr2->o.empty() != ptr->o.empty()) return 0;
				else if (!(ptr2->o.empty() && ptr->o.empty()))
					for (int i = 0; i < siz5; i++)
					if (!(ptr->o[i] == ptr2->o[i])) return 0;
			case 8: //vector4
				if (ptr2->i.size() != ptr->i.size()) return 0;
				else if (ptr2->i.empty() != ptr->i.empty()) return 0;
				else if (!(ptr2->i.empty() && ptr->i.empty()))
					for (int i = 0; i < siz4; i++)
					if (!(ptr->i[i] == ptr2->i[i])) return 0;
			case 7: //vector3
				if (ptr2->u.size() != ptr->u.size()) return 0;
				else if (ptr2->u.empty() != ptr->u.empty()) return 0;
				else if (!(ptr2->u.empty() && ptr->u.empty()))
					for (int i = 0; i < siz3; i++)
					if (!(ptr->u[i] == ptr2->u[i])) return 0;
			case 6: //vector2
				if (ptr2->y.size() != ptr->y.size()) return 0;
				else if (ptr2->y.empty() != ptr->y.empty()) return 0;
				else if (!(ptr2->y.empty() && ptr->y.empty()))
					for (int i = 0; i < siz2; i++)
					if (!(ptr->y[i] == ptr2->y[i])) return 0;
			case 5: //vector
				if (ptr2->t.size() != ptr->t.size()) return 0;
				else if (ptr2->t.empty() != ptr->t.empty()) return 0;
				else if (!(ptr2->t.empty() && ptr->t.empty()))
					for (int i = 0; i < siz; i++)
					if (!(ptr->t[i] == ptr2->t[i])) return 0;
			case 4:
				if (ptr->r != ptr2->r) return 0;
			case 3:
				if (ptr->e != ptr2->e) return 0;
			case 2:
				if (ptr->w != ptr2->w) return 0;
			case 1:
				if (ptr->q != ptr2->q) return 0;
			}
		}
	}
	else if (typeid(last_reentrant_triangle) == typeid(*fact)&& typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		last_reentrant_triangle* ptr = dynamic_cast<last_reentrant_triangle*>(fact);
		last_reentrant_triangle* ptr2 = dynamic_cast<last_reentrant_triangle*>(Treesfact);
		if (p)
		{
			switch (p)
			{
			case 2:
				if (ptr->w != ptr2->w) return 0;
			case 1:
				if (ptr->q != ptr2->q) return 0;
			}
		}
	}
	else if (typeid(last_schedule_state) == typeid(*fact)&& typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		last_schedule_state* ptr = dynamic_cast<last_schedule_state*>(fact);
		last_schedule_state* ptr2 = dynamic_cast<last_schedule_state*>(Treesfact);
		if (p)
		{
			switch (p)
			{
			case 3:
				if (ptr->e != ptr2->e) return 0;
			case 2:
				if (ptr->w != ptr2->w) return 0;
			case 1:
				if (ptr->q != ptr2->q) return 0;
			}
		}
	}
	else if (typeid(conditional_incomplete) == typeid(*fact)&& typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		conditional_incomplete* ptr = dynamic_cast<conditional_incomplete*>(fact);
		conditional_incomplete* ptr2 = dynamic_cast<conditional_incomplete*>(Treesfact);
		size_t siz = ptr->t.size();
		size_t siz2 = ptr->y.size();
		size_t siz3 = ptr->u.size();
		size_t siz4 = ptr->i.size();
		size_t siz5 = ptr->o.size();
		size_t siz6 = ptr->p.size();

		if (p)
		{
			switch (p)
			{
			case 21:
				if (ptr->x != ptr2->x) return 0;
			case 20:
				if (ptr->z != ptr2->z) return 0;
			case 19:
				if (ptr->l != ptr2->l) return 0;
			case 18:
				if (ptr->k != ptr2->k) return 0;
			case 17:
				if (ptr->j != ptr2->j) return 0;
			case 16:
				if (ptr->h != ptr2->h) return 0;
			case 15:
				if (ptr->g != ptr2->g) return 0;
			case 14:
				if (ptr->f != ptr2->f) return 0;
			case 13:
				if (ptr->d != ptr2->d) return 0;
			case 12:
				if (ptr->s != ptr2->s) return 0;
			case 11:
				if (ptr->a != ptr2->a) return 0;
			case 10: //vector6
				if (ptr2->p.size() != ptr->p.size()) return 0;
				else if (ptr2->p.empty() != ptr->p.empty()) return 0;
				else if (!(ptr2->p.empty() && ptr->p.empty()))
					for (int i = 0; i < siz6; i++)
						if (!(ptr->p[i] == ptr2->p[i])) return 0;
			case 9: //vector5
				if (ptr2->o.size() != ptr->o.size()) return 0;
				else if (ptr2->o.empty() != ptr->o.empty()) return 0;
				else if (!(ptr2->o.empty() && ptr->o.empty()))
					for (int i = 0; i < siz5; i++)
						if (!(ptr->o[i] == ptr2->o[i])) return 0;
			case 8: //vector4
				if (ptr2->i.size() != ptr->i.size()) return 0;
				else if (ptr2->i.empty() != ptr->i.empty()) return 0;
				else if (!(ptr2->i.empty() && ptr->i.empty()))
					for (int i = 0; i < siz4; i++)
						if (!(ptr->i[i] == ptr2->i[i])) return 0;
			case 7: //vector3
				if (ptr2->u.size() != ptr->u.size()) return 0;
				else if (ptr2->u.empty() != ptr->u.empty()) return 0;
				else if (!(ptr2->u.empty() && ptr->u.empty()))
					for (int i = 0; i < siz3; i++)
						if (!(ptr->u[i] == ptr2->u[i])) return 0;
			case 6: //vector2
				if (ptr2->y.size() != ptr->y.size()) return 0;
				else if (ptr2->y.empty() != ptr->y.empty()) return 0;
				else if (!(ptr2->y.empty() && ptr->y.empty()))
					for (int i = 0; i < siz2; i++)
						if (!(ptr->y[i] == ptr2->y[i])) return 0;
			case 5: //vector
				if (ptr2->t.size() != ptr->t.size()) return 0;
				else if (ptr2->t.empty() != ptr->t.empty()) return 0;
				else if (!(ptr2->t.empty() && ptr->t.empty()))
					for (int i = 0; i < siz; i++)
						if (!(ptr->t[i] == ptr2->t[i])) return 0;
			case 4:
				if (ptr->r != ptr2->r) return 0;
			case 3:
				if (ptr->e != ptr2->e) return 0;
			case 2:
				if (ptr->w != ptr2->w) return 0;
			case 1:
				if (ptr->q != ptr2->q) return 0;
			}
		}
	}
	else if (typeid(mixed_incomplete_state_lists) == typeid(*fact) && typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		mixed_incomplete_state_lists* ptr = dynamic_cast<mixed_incomplete_state_lists*>(fact);
		mixed_incomplete_state_lists* ptr2 = dynamic_cast<mixed_incomplete_state_lists*>(Treesfact);
		size_t siz = ptr->r.size();
		size_t siz2 = ptr->t.size();

		if (p)
		{
			switch (p)
			{
			case 5: //vector2
				if (ptr2->t.size() != ptr->t.size()) return 0;
				else if (ptr2->t.empty() != ptr->t.empty()) return 0;
				else if (!(ptr2->t.empty() && ptr->t.empty()))
				for (int i = 0; i < siz2; i++)
					if (!(ptr->t[i] == ptr2->t[i])) return 0;
			case 4: //vector
				if (ptr2->r.size() != ptr->r.size()) return 0;
				else if (ptr2->r.empty() != ptr->r.empty()) return 0;
				else if (!(ptr2->r.empty() && ptr->r.empty()))				
					for (int i = 0; i < siz; i++)
					if (!(ptr->r[i] == ptr2->r[i])) return 0;
			case 3:
				if (ptr->e != ptr2->e) return 0;
			case 2:
				if (ptr->w != ptr2->w) return 0;
			case 1:
				if (ptr->q != ptr2->q) return 0;
			}
		}
	}
	else if (typeid(linear_incomplete_node) == typeid(*fact)&& typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		linear_incomplete_node* ptr = dynamic_cast<linear_incomplete_node*>(fact);
		linear_incomplete_node* ptr2 = dynamic_cast<linear_incomplete_node*>(Treesfact);
		size_t siz = ptr->r.size();
		size_t siz2 = ptr->t.size();

		if (p)
		{
			switch (p)
			{
			case 6:
				if (ptr->y != ptr2->y) return 0;
			case 5: //vector2
				if (ptr2->t.size() != ptr->t.size()) return 0;
				else if (ptr2->t.empty() != ptr->t.empty()) return 0;
				else if (!(ptr2->t.empty() && ptr->t.empty()))
					for (int i = 0; i < siz2; i++)
					if (!(ptr->t[i] == ptr2->t[i])) return 0;
			case 4: //vector
				if (ptr2->r.size() != ptr->r.size()) return 0;
				else if (ptr2->r.empty() != ptr->r.empty()) return 0;
				else if (!(ptr2->r.empty() && ptr->r.empty()))
					for (int i = 0; i < siz; i++)
					if (!(ptr->r[i] == ptr2->r[i])) return 0;
			case 3:
				if (ptr->e != ptr2->e) return 0;
			case 2:
				if (ptr->w != ptr2->w) return 0;
			case 1:
				if (ptr->q != ptr2->q) return 0;
			}
		}
	}
	else if (typeid(incomplete_links) == typeid(*fact)&& typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		incomplete_links* ptr = dynamic_cast<incomplete_links*>(fact);
		incomplete_links* ptr2 = dynamic_cast<incomplete_links*>(Treesfact);
		if (p)
		{
			switch (p)
			{
			case 10:
				if (ptr->p != ptr2->p) return 0;
			case 9:
				if (ptr->o != ptr2->o) return 0;
			case 8:
				if (ptr->i != ptr2->i) return 0;
			case 7:
				if (ptr->u != ptr2->u) return 0;
			case 6:
				if (ptr->y != ptr2->y) return 0;
			case 5:
				if (ptr->t != ptr2->t) return 0;
			case 4:
				if (ptr->r != ptr2->r) return 0;
			case 3:
				if (ptr->e != ptr2->e) return 0;
			case 2:
				if (ptr->w != ptr2->w) return 0;
			case 1:
				if (ptr->q != ptr2->q) return 0;
			}
		}
	}
	else if (typeid(last_incomplete) == typeid(*fact)&& typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		last_incomplete* ptr = dynamic_cast<last_incomplete*>(fact);
		last_incomplete* ptr2 = dynamic_cast<last_incomplete*>(Treesfact);
		if (p)
		{
			switch (p)
			{
			case 4:
				if (ptr->r != ptr2->r) return 0;
			case 3:
				if (ptr->e != ptr2->e) return 0;
			case 2:
				if (ptr->w != ptr2->w) return 0;
			case 1:
				if (ptr->q != ptr2->q) return 0;
			}
		}
	}
	else if (typeid(global_nils) == typeid(*fact)&& typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		global_nils* ptr = dynamic_cast<global_nils*>(fact);
		global_nils* ptr2 = dynamic_cast<global_nils*>(Treesfact);
		// examine the case with empty vector ... like ptr->q.size() == ptr2->q.size() == 0
		if (p)
		{
			//vector
			if (ptr2->q.size() < ptr->q.size()) return 0;
			else if (ptr2->q.empty() != ptr->q.empty()) return 0;
			else if (!(ptr2->q.empty() && ptr->q.empty()))
				for (int i = 0; i < p; i++)
				{
					if (ptr->q[i].q != ptr2->q[i].q) return 0;
					if (ptr->q[i].w != ptr2->q[i].w) return 0;
				}
		}
	}
	else if (typeid(current_module) == typeid(*fact)&& typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		current_module* ptr = dynamic_cast<current_module*>(fact);
		current_module* ptr2 = dynamic_cast<current_module*>(Treesfact);
		if (p)
		{
			if (ptr->q != ptr2->q) return 0;
		}
	}
	else if (typeid(last_linear_incomplete_node) == typeid(*fact)&& typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		last_linear_incomplete_node* ptr = dynamic_cast<last_linear_incomplete_node*>(fact);
		last_linear_incomplete_node* ptr2 = dynamic_cast<last_linear_incomplete_node*>(Treesfact);
		if (p)
		{
			if (ptr->q != ptr2->q) return 0;
		}
	}
	else if (typeid(operator_instances) == typeid(*fact)&& typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		operator_instances* ptr = dynamic_cast<operator_instances*>(fact);
		operator_instances* ptr2 = dynamic_cast<operator_instances*>(Treesfact);
		if (p)
		{
			switch (p)
			{
			case 2:
				if (ptr->w != ptr2->w) return 0;
			case 1:
				if (ptr->q != ptr2->q) return 0;
			}
		}
	}
	else if (typeid(massively_parallel_style) == typeid(*fact)&& typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		massively_parallel_style* ptr = dynamic_cast<massively_parallel_style*>(fact);
		massively_parallel_style* ptr2 = dynamic_cast<massively_parallel_style*>(Treesfact);
		if (p)
		{
			if (ptr->q != ptr2->q) return 0;
		}
	}
	else if (typeid(hdl_style) == typeid(*fact)&& typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		hdl_style* ptr = dynamic_cast<hdl_style*>(fact);
		hdl_style* ptr2 = dynamic_cast<hdl_style*>(Treesfact);
		if (p)
		{
			if (ptr->q != ptr2->q) return 0;
		}
	}
	else if (typeid(op_instance) == typeid(*fact)&& typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		op_instance* ptr = dynamic_cast<op_instance*>(fact);
		op_instance* ptr2 = dynamic_cast<op_instance*>(Treesfact);

		if (p)
		{
			switch (p)
			{
			case 5:
				if (ptr->t != ptr2->t) return 0;
			case 4:
				if (ptr->r != ptr2->r) return 0;
			case 3:
				if (ptr->e != ptr2->e) return 0;
			case 2:
				if (ptr->w != ptr2->w) return 0;
			case 1:
				if (ptr->q != ptr2->q) return 0;
			}
		}
	}
	else if (typeid(last_op_instance) == typeid(*fact)&& typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		last_op_instance* ptr = dynamic_cast<last_op_instance*>(fact);
		last_op_instance* ptr2 = dynamic_cast<last_op_instance*>(Treesfact);
		if (p)
		{
			switch (p)
			{
			case 3:
				if (ptr->e != ptr2->e) return 0;
			case 2:
				if (ptr->w != ptr2->w) return 0;
			case 1:
				if (ptr->q != ptr2->q) return 0;
			}
		}
	}
	else if (typeid(op_in_a_state) == typeid(*fact)&& typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		op_in_a_state* ptr = dynamic_cast<op_in_a_state*>(fact);
		op_in_a_state* ptr2 = dynamic_cast<op_in_a_state*>(Treesfact);
		if (p)
		{
			switch (p)
			{
			case 5:
				if (ptr->t != ptr2->t) return 0;
			case 4:
				if (ptr->r != ptr2->r) return 0;
			case 3:
				if (ptr->e != ptr2->e) return 0;
			case 2:
				if (ptr->w != ptr2->w) return 0;
			case 1:
				if (ptr->q != ptr2->q) return 0;
			}
		}
	}
	else if (typeid(last_op_in_a_state) == typeid(*fact)&& typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		last_op_in_a_state* ptr = dynamic_cast<last_op_in_a_state*>(fact);
		last_op_in_a_state* ptr2 = dynamic_cast<last_op_in_a_state*>(Treesfact);
		if (p)
		{
			switch (p)
			{
			case 4:
				if (ptr->r != ptr2->r) return 0;
			case 3:
				if (ptr->e != ptr2->e) return 0;
			case 2:
				if (ptr->w != ptr2->w) return 0;
			case 1:
				if (ptr->q != ptr2->q) return 0;
			}
		}
	}
	else if (typeid(signal_instance) == typeid(*fact)&& typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		signal_instance* ptr = dynamic_cast<signal_instance*>(fact);
		signal_instance* ptr2 = dynamic_cast<signal_instance*>(Treesfact);
		if (p)
		{
			switch (p)
			{
			case 7:
				if (ptr->u != ptr2->u) return 0;
			case 6:
				if (ptr->y != ptr2->y) return 0;
			case 5:
				if (ptr->t != ptr2->t) return 0;
			case 4:
				if (ptr->r != ptr2->r) return 0;
			case 3:
				if (ptr->e != ptr2->e) return 0;
			case 2:
				if (ptr->w != ptr2->w) return 0;
			case 1:
				if (ptr->q != ptr2->q) return 0;
			}
		}
	}
	else if (typeid(last_signal_instance) == typeid(*fact)&& typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		last_signal_instance* ptr = dynamic_cast<last_signal_instance*>(fact);
		last_signal_instance* ptr2 = dynamic_cast<last_signal_instance*>(Treesfact);
		if (p)
		{
			switch (p)
			{
			case 2:
				if (ptr->w != ptr2->w) return 0;
			case 1:
				if (ptr->q != ptr2->q) return 0;
			}
		}
	}
	else if (typeid(output_instance) == typeid(*fact)&& typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		output_instance* ptr = dynamic_cast<output_instance*>(fact);
		output_instance* ptr2 = dynamic_cast<output_instance*>(Treesfact);
		if (p)
		{
			switch (p)
			{
			case 6:
				if (ptr->y != ptr2->y) return 0;
			case 5:
				if (ptr->t != ptr2->t) return 0;
			case 4:
				if (ptr->r != ptr2->r) return 0;
			case 3:
				if (ptr->e != ptr2->e) return 0;
			case 2:
				if (ptr->w != ptr2->w) return 0;
			case 1:
				if (ptr->q != ptr2->q) return 0;
			}
		}
	}
	else if (typeid(last_output_instance) == typeid(*fact)&& typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		last_output_instance* ptr = dynamic_cast<last_output_instance*>(fact);
		last_output_instance* ptr2 = dynamic_cast<last_output_instance*>(Treesfact);
		if (p)
		{
			switch (p)
			{
			case 2:
				if (ptr->w != ptr2->w) return 0;
			case 1:
				if (ptr->q != ptr2->q) return 0;
			}
		}
	}
	else if (typeid(operator_instance_stats) == typeid(*fact)&& typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		operator_instance_stats* ptr = dynamic_cast<operator_instance_stats*>(fact);
		operator_instance_stats* ptr2 = dynamic_cast<operator_instance_stats*>(Treesfact);
		if (p)
		{
			switch (p)
			{
			case 4:
				if (ptr->r != ptr2->r) return 0;
			case 3:
				if (ptr->e != ptr2->e) return 0;
			case 2:
				if (ptr->w != ptr2->w) return 0;
			case 1:
				if (ptr->q != ptr2->q) return 0;
			}
		}
	}
	else if (typeid(consecutive_106) == typeid(*fact)&& typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		consecutive_106* ptr = dynamic_cast<consecutive_106*>(fact);
		consecutive_106* ptr2 = dynamic_cast<consecutive_106*>(Treesfact);
		if (p)
		{
			if (ptr->q != ptr2->q) return 0;
		}
	}
	else if (typeid(operation_order) == typeid(*fact)&& typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		operation_order* ptr = dynamic_cast<operation_order*>(fact);
		operation_order* ptr2 = dynamic_cast<operation_order*>(Treesfact);
		if (p)
		{
			switch (p)
			{
			case 10:
				if (ptr->p != ptr2->p) return 0;
			case 9:
				if (ptr->o != ptr2->o) return 0;
			case 8:
				if (ptr->i != ptr2->i) return 0;
			case 7:
				if (ptr->u != ptr2->u) return 0;
			case 6:
				if (ptr->y != ptr2->y) return 0;
			case 5:
				if (ptr->t != ptr2->t) return 0;
			case 4:
				if (ptr->r != ptr2->r) return 0;
			case 3:
				if (ptr->e != ptr2->e) return 0;
			case 2:
				if (ptr->w != ptr2->w) return 0;
			case 1:
				if (ptr->q != ptr2->q) return 0;
			}
		}
	}
	else if (typeid(max_parallel_call_order) == typeid(*fact)&& typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		max_parallel_call_order* ptr = dynamic_cast<max_parallel_call_order*>(fact);
		max_parallel_call_order* ptr2 = dynamic_cast<max_parallel_call_order*>(Treesfact);
		if (p)
		{
			switch (p)
			{
			case 4:
				if (ptr->r != ptr2->r) return 0;
			case 3:
				if (ptr->e != ptr2->e) return 0;
			case 2:
				if (ptr->w != ptr2->w) return 0;
			case 1:
				if (ptr->q != ptr2->q) return 0;
			}
		}
	}
	else if (typeid(max_op_order) == typeid(*fact)&& typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		max_op_order* ptr = dynamic_cast<max_op_order*>(fact);
		max_op_order* ptr2 = dynamic_cast<max_op_order*>(Treesfact);
		if (p)
		{
			switch (p)
			{
			case 3:
				if (ptr->e != ptr2->e) return 0;
			case 2:
				if (ptr->w != ptr2->w) return 0;
			case 1:
				if (ptr->q != ptr2->q) return 0;
			}
		}
	}
	else if (typeid(totalmax_call_order) == typeid(*fact)&& typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		totalmax_call_order* ptr = dynamic_cast<totalmax_call_order*>(fact);
		totalmax_call_order* ptr2 = dynamic_cast<totalmax_call_order*>(Treesfact);
		if (p)
		{
			switch (p)
			{
			case 3:
				if (ptr->e != ptr2->e) return 0;
			case 2:
				if (ptr->w != ptr2->w) return 0;
			case 1:
				if (ptr->q != ptr2->q) return 0;
			}
		}
	}
	else if (typeid(totalmax_gross_depth) == typeid(*fact)&& typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		totalmax_gross_depth* ptr = dynamic_cast<totalmax_gross_depth*>(fact);
		totalmax_gross_depth* ptr2 = dynamic_cast<totalmax_gross_depth*>(Treesfact);
		if (p)
		{
			switch (p)
			{
			case 3:
				if (ptr->e != ptr2->e) return 0;
			case 2:
				if (ptr->w != ptr2->w) return 0;
			case 1:
				if (ptr->q != ptr2->q) return 0;
			}
		}
	}
	else if (typeid(current_total_max_order_entry) == typeid(*fact)&& typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		current_total_max_order_entry* ptr = dynamic_cast<current_total_max_order_entry*>(fact);
		current_total_max_order_entry* ptr2 = dynamic_cast<current_total_max_order_entry*>(Treesfact);
		if (p)
		{
			if (ptr->q != ptr2->q) return 0;
		}
	}
	else if (typeid(module_last_state) == typeid(*fact)&& typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		module_last_state* ptr = dynamic_cast<module_last_state*>(fact);
		module_last_state* ptr2 = dynamic_cast<module_last_state*>(Treesfact);
		if (p)
		{
			if (ptr->q != ptr2->q) return 0;
		}
	}
	else if (typeid(module_local_list) == typeid(*fact) && typeid(*fact) == typeid(*Treesfact))
	{
		flag = 0;
		module_local_list* ptr = dynamic_cast<module_local_list*>(fact);
		module_local_list* ptr2 = dynamic_cast<module_local_list*>(Treesfact);

		if (p)
		{
			//vector
			if (ptr2->q.size() > ptr->q.size()) return 0;
			else if (ptr2->q.empty() != ptr->q.empty()) return 0;
			else if (!(ptr2->q.empty() && ptr->q.empty()))
				for (int i = 0; i < p; i++)
			{
				if (ptr->q[i].q != ptr2->q[i].q) return 0;
				if (ptr->q[i].w != ptr2->q[i].w) return 0;
				if (ptr->q[i].e != ptr2->q[i].e) return 0;
				if (ptr->q[i].r != ptr2->q[i].r) return 0;
				if (ptr->q[i].t != ptr2->q[i].t) return 0;
				if (ptr->q[i].y != ptr2->q[i].y) return 0;
				if (ptr->q[i].u != ptr2->q[i].u) return 0;
				if (ptr->q[i].i != ptr2->q[i].i) return 0;
				if (ptr->q[i].o != ptr2->q[i].o) return 0;
			}
		}
	}
	if (flag)								//exeeded the limit of nested else if
	{
		if (typeid(module_local_list_parcs) == typeid(*fact) && typeid(*fact) == typeid(*Treesfact))
		{
			module_local_list_parcs* ptr = dynamic_cast<module_local_list_parcs*>(fact);
			module_local_list_parcs* ptr2 = dynamic_cast<module_local_list_parcs*>(Treesfact);

			if (p)
			{
				//vector
				if (ptr2->q.size() > ptr->q.size()) return 0;
				else if (ptr2->q.empty() != ptr->q.empty()) return 0;
				else if (!(ptr2->q.empty() && ptr->q.empty()))
					for (int i = 0; i < p; i++)
				{
					if (ptr->q[i].q != ptr2->q[i].q) return 0;
					if (ptr->q[i].w != ptr2->q[i].w) return 0;
					if (ptr->q[i].e != ptr2->q[i].e) return 0;
					if (ptr->q[i].r != ptr2->q[i].r) return 0;
					if (ptr->q[i].t != ptr2->q[i].t) return 0;
					if (ptr->q[i].y != ptr2->q[i].y) return 0;
					if (ptr->q[i].u != ptr2->q[i].u) return 0;
					if (ptr->q[i].i != ptr2->q[i].i) return 0;
					if (ptr->q[i].o != ptr2->q[i].o) return 0;
				}
			}
		}
		else if (typeid(last_non_io_found) == typeid(*fact)&& typeid(*fact) == typeid(*Treesfact))
		{
			last_non_io_found* ptr = dynamic_cast<last_non_io_found*>(fact);
			last_non_io_found* ptr2 = dynamic_cast<last_non_io_found*>(Treesfact);
			if (p)
			{
				if (ptr->q != ptr2->q) return 0;
			}
		}
		else if (typeid(last_local_number) == typeid(*fact)&& typeid(*fact) == typeid(*Treesfact))
		{
			last_local_number* ptr = dynamic_cast<last_local_number*>(fact);
			last_local_number* ptr2 = dynamic_cast<last_local_number*>(Treesfact);
			if (p)
			{
				if (ptr->q != ptr2->q) return 0;
			}
		}
		else if (typeid(printed_formal_ios_of_called_module) == typeid(*fact) && typeid(*fact) == typeid(*Treesfact))
		{
			printed_formal_ios_of_called_module* ptr = dynamic_cast<printed_formal_ios_of_called_module*>(fact);
			printed_formal_ios_of_called_module* ptr2 = dynamic_cast<printed_formal_ios_of_called_module*>(Treesfact);
			if (p)
			{
				switch (p)
				{
				case 4:
					if (ptr->r != ptr2->r) return 0;
				case 3:
					if (ptr->e != ptr2->e) return 0;
				case 2:
					if (ptr->w != ptr2->w) return 0;
				case 1:
					if (ptr->q != ptr2->q) return 0;
				}
			}
		}
		else if (typeid(it_includes_ifthen) == typeid(*fact)&& typeid(*fact) == typeid(*Treesfact))
		{
			it_includes_ifthen* ptr = dynamic_cast<it_includes_ifthen*>(fact);
			it_includes_ifthen* ptr2 = dynamic_cast<it_includes_ifthen*>(Treesfact);
			if (p)
			{
				switch (p)
				{
				case 3:
					if (ptr->e != ptr2->e) return 0;
				case 2:
					if (ptr->w != ptr2->w) return 0;
				case 1:
					if (ptr->q != ptr2->q) return 0;
				}
			}
		}
		else if (typeid(it_includes_conditional_targeting) == typeid(*fact)&& typeid(*fact) == typeid(*Treesfact))
		{
			it_includes_conditional_targeting* ptr = dynamic_cast<it_includes_conditional_targeting*>(fact);
			it_includes_conditional_targeting* ptr2 = dynamic_cast<it_includes_conditional_targeting*>(Treesfact);
			if (p)
			{
				switch (p)
				{
				case 3:
					if (ptr->e != ptr2->e) return 0;
				case 2:
					if (ptr->w != ptr2->w) return 0;
				case 1:
					if (ptr->q != ptr2->q) return 0;
				}
			}
		}
		else if (typeid(targets_conditional_variable) == typeid(*fact)&& typeid(*fact) == typeid(*Treesfact))
		{
			targets_conditional_variable* ptr = dynamic_cast<targets_conditional_variable*>(fact);
			targets_conditional_variable* ptr2 = dynamic_cast<targets_conditional_variable*>(Treesfact);
			if (p)
			{
				switch (p)
				{
				case 4:
					if (ptr->r != ptr2->r) return 0;
				case 3:
					if (ptr->e != ptr2->e) return 0;
				case 2:
					if (ptr->w != ptr2->w) return 0;
				case 1:
					if (ptr->q != ptr2->q) return 0;
				}
			}
		}
		else if (typeid(variable_has_been_listed) == typeid(*fact)&& typeid(*fact) == typeid(*Treesfact))
		{
			variable_has_been_listed* ptr = dynamic_cast<variable_has_been_listed*>(fact);
			variable_has_been_listed* ptr2 = dynamic_cast<variable_has_been_listed*>(Treesfact);
			if (p)
			{
				switch (p)
				{
				case 2:
					if (ptr->w != ptr2->w) return 0;
				case 1:
					if (ptr->q != ptr2->q) return 0;
				}
			}
		}
		else if (typeid(resetstyle) == typeid(*fact)&& typeid(*fact) == typeid(*Treesfact))
		{
			resetstyle* ptr = dynamic_cast<resetstyle*>(fact);
			resetstyle* ptr2 = dynamic_cast<resetstyle*>(Treesfact);
			if (p)
			{
				if (ptr->q != ptr2->q) return 0;
			}
		}
		else if (typeid(checkstyle) == typeid(*fact)&& typeid(*fact) == typeid(*Treesfact))
		{
			checkstyle* ptr = dynamic_cast<checkstyle*>(fact);
			checkstyle* ptr2 = dynamic_cast<checkstyle*>(Treesfact);
			if (p)
			{
				if (ptr->q != ptr2->q) return 0;
			}
		}
		else if (typeid(total_local_entry) == typeid(*fact)&& typeid(*fact) == typeid(*Treesfact))
		{
			total_local_entry* ptr = dynamic_cast<total_local_entry*>(fact);
			total_local_entry* ptr2 = dynamic_cast<total_local_entry*>(Treesfact);
			if (p)
			{
				if (ptr->q != ptr2->q) return 0;
			}
		}
		else if (typeid(complex_next_state_operation_depth) == typeid(*fact)&& typeid(*fact) == typeid(*Treesfact))
		{
			complex_next_state_operation_depth* ptr = dynamic_cast<complex_next_state_operation_depth*>(fact);
			complex_next_state_operation_depth* ptr2 = dynamic_cast<complex_next_state_operation_depth*>(Treesfact);
			if (p)
			{
				if (ptr->q != ptr2->q) return 0;
			}
		}
		else if (typeid(output_filename) == typeid(*fact)&& typeid(*fact) == typeid(*Treesfact))
		{
			output_filename* ptr = dynamic_cast<output_filename*>(fact);
			output_filename* ptr2 = dynamic_cast<output_filename*>(Treesfact);
			if (p)
			{
				if (ptr->q != ptr2->q) return 0;
			}
		}
		else if (typeid(hdl_io_pass) == typeid(*fact)&& typeid(*fact) == typeid(*Treesfact))
		{
			hdl_io_pass* ptr = dynamic_cast<hdl_io_pass*>(fact);
			hdl_io_pass* ptr2 = dynamic_cast<hdl_io_pass*>(Treesfact);
			if (p)
			{
				if (ptr->q != ptr2->q) return 0;
			}
		}
		else if (typeid(current_hdl_style) == typeid(*fact)&& typeid(*fact) == typeid(*Treesfact))
		{
			current_hdl_style* ptr = dynamic_cast<current_hdl_style*>(fact);
			current_hdl_style* ptr2 = dynamic_cast<current_hdl_style*>(Treesfact);
			if (p)
			{
				if (ptr->q != ptr2->q) return 0;
			}
		}
		else if (typeid(call_ios_have_been_reset) == typeid(*fact)&& typeid(*fact) == typeid(*Treesfact))
		{
			call_ios_have_been_reset* ptr = dynamic_cast<call_ios_have_been_reset*>(fact);
			call_ios_have_been_reset* ptr2 = dynamic_cast<call_ios_have_been_reset*>(Treesfact);
			if (p)
			{
				if (ptr->q != ptr2->q) return 0;
			}
		}
		else if (typeid(debug_mode) == typeid(*fact)&& typeid(*fact) == typeid(*Treesfact))
		{
			debug_mode* ptr = dynamic_cast<debug_mode*>(fact);
			debug_mode* ptr2 = dynamic_cast<debug_mode*>(Treesfact);
			if (p)
			{
				if (ptr->q != ptr2->q) return 0;
			}
		}
		else if (typeid(print_C_main_body) == typeid(*fact)&& typeid(*fact) == typeid(*Treesfact))
		{
			print_C_main_body* ptr = dynamic_cast<print_C_main_body*>(fact);
			print_C_main_body* ptr2 = dynamic_cast<print_C_main_body*>(Treesfact);
			if (p)
			{
				if (ptr->q != ptr2->q) return 0;
			}
		}
		else if (typeid(cac_mode) == typeid(*fact)&& typeid(*fact) == typeid(*Treesfact))
		{
			cac_mode* ptr = dynamic_cast<cac_mode*>(fact);
			cac_mode* ptr2 = dynamic_cast<cac_mode*>(Treesfact);
			if (p)
			{
				if (ptr->q != ptr2->q) return 0;
			}
		}
		else if (typeid(path) == typeid(*fact)&& typeid(*fact) == typeid(*Treesfact))
		{
			path* ptr = dynamic_cast<path*>(fact);
			path* ptr2 = dynamic_cast<path*>(Treesfact);
			if (p)
			{
				switch (p)
				{
				case 3:
					if (ptr->e != ptr2->e) return 0;
				case 2:
					if (ptr->w != ptr2->w) return 0;
				case 1:
					if (ptr->q != ptr2->q) return 0;
				}
			}
		}
		else if (typeid(max_path) == typeid(*fact)&& typeid(*fact) == typeid(*Treesfact))
		{
			max_path* ptr = dynamic_cast<max_path*>(fact);
			max_path* ptr2 = dynamic_cast<max_path*>(Treesfact);
			if (p)
			{
				switch (p)
				{
				case 2:
					if (ptr->w != ptr2->w) return 0;
				case 1:
					if (ptr->q != ptr2->q) return 0;
				}
			}
		}
		else if (typeid(min_path) == typeid(*fact)&& typeid(*fact) == typeid(*Treesfact))
		{
			min_path* ptr = dynamic_cast<min_path*>(fact);
			min_path* ptr2 = dynamic_cast<min_path*>(Treesfact);
			if (p)
			{
				switch (p)
				{
				case 2:
					if (ptr->w != ptr2->w) return 0;
				case 1:
					if (ptr->q != ptr2->q) return 0;
				}
			}
		}
		else if (typeid(op_belongs_to_state) == typeid(*fact)&& typeid(*fact) == typeid(*Treesfact))
		{
			op_belongs_to_state* ptr = dynamic_cast<op_belongs_to_state*>(fact);
			op_belongs_to_state* ptr2 = dynamic_cast<op_belongs_to_state*>(Treesfact);
			if (p)
			{
				switch (p)
				{
				case 4:
					if (ptr->r != ptr2->r) return 0;
				case 3:
					if (ptr->e != ptr2->e) return 0;
				case 2:
					if (ptr->w != ptr2->w) return 0;
				case 1:
					if (ptr->q != ptr2->q) return 0;
				}
			}
		}
		else if (typeid(top_module) == typeid(*fact)&& typeid(*fact) == typeid(*Treesfact))
		{
			top_module* ptr = dynamic_cast<top_module*>(fact);
			top_module* ptr2 = dynamic_cast<top_module*>(Treesfact);
			if (p)
			{
				if (ptr->q != ptr2->q) return 0;
			}
		}
		else if (typeid(package_name) == typeid(*fact)&& typeid(*fact) == typeid(*Treesfact))
		{
			package_name* ptr = dynamic_cast<package_name*>(fact);
			package_name* ptr2 = dynamic_cast<package_name*>(Treesfact);
			if (p)
			{
				if (ptr->q != ptr2->q) return 0;
			}
		}
		else
		{
			return 0;
		}
	}	// if (flag)
	return 1;
}
#pragma once
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

class GeneralFact 
{
	bool fordestr = 1;
public:
	virtual void operator=(GeneralFact& other) = 0;
	virtual ~GeneralFact() = 0;
};
GeneralFact::~GeneralFact()
{
	fordestr = 1;
}

class factUnderInspection
{

	GeneralFact* fact{};
	vector<bool>			toCompare{};
	vector<vector<bool>>	toCompareV{};
public:
	factUnderInspection()
		:fact(nullptr) {}

	factUnderInspection(GeneralFact* q, vector<bool> w, vector<vector<bool>> e)
		:fact(q)
	{
		toCompare.insert(toCompare.end(), w.begin(), w.end());
		toCompareV.insert(toCompareV.end(), e.begin(), e.end());
	}
	factUnderInspection(const factUnderInspection& other)
	{
		if (this != &other)
		{
			this->fact = other.fact;
			this->toCompare.insert(this->toCompare.end(), other.toCompare.begin(), other.toCompare.end());
			this->toCompareV.insert(this->toCompareV.end(), other.toCompareV.begin(), other.toCompareV.end());
		}
	}

	void operator=(factUnderInspection& other)
	{
		if (this != &other)
		{
			this->fact = other.fact;
			this->toCompare = other.toCompare;
			this->toCompareV = other.toCompareV;
		}
	}

	factUnderInspection(factUnderInspection&& other) noexcept
		: fact{ other.fact }, toCompare{ other.toCompare }, toCompareV{ other.toCompareV }{}

	void operator=(factUnderInspection&& other) noexcept
	{
		swap(fact, other.fact);
		swap(toCompare, other.toCompare);
		swap(toCompareV, other.toCompareV);
	}

	GeneralFact* getfact() { return fact; }
	vector<bool> getcmp() { return toCompare; }
	vector<vector<bool>> getcmpV() { return toCompareV; }

	friend factUnderInspection makeInstanceOfSpecFact(string inputline);

	friend size_t matchfactsSpec(GeneralFact* otherf, factUnderInspection* obj); // othernode, _

};

class factstar
{
	GeneralFact*	fact{};
	int				params{};
public:
	factstar() { fact = nullptr; params = NULL; }
	factstar(GeneralFact* q, int w)
		: fact(q), params(w) {}

	factstar(const factstar& other)
	{
		if (this != &other)
		{
			this->fact = other.fact;
			this->params = other.params;
		}
	}
	~factstar()
	{
		delete fact;
		params = NULL;
	}

	void operator=(factstar& other)
	{
		if (this != &other)
		{
			this->fact = other.fact;
			this->params = other.params;
		}
	}

	factstar(factstar&& other) noexcept
		: fact{ other.fact }, params{ other.params }{}

	void operator=(factstar&& other) noexcept
	{
		swap(fact, other.fact);
		swap(params, other.params);
	}
	friend size_t matchfactsstar(GeneralFact* Treesfact, factstar* obj);

};

class type_def : public GeneralFact
{
	int				q{}, e{}, t{}, u{}, i{}, o{};
	string			w{}, r{}, y{};
public:
	type_def(const int q1, const int e1, const int t1, const int u1,
		const int i1, const int o1,const string w1,const string r1, const string y1)
		:q(q1), e(e1), t(t1), u(u1), i(i1), o(o1), w(w1), r(r1), y(y1){}

	type_def(const type_def& other)
	{
		if (this != &other)
		{
			this->q = other.q;	this->r = other.r;
			this->t = other.t;	this->y = other.y;
			this->u = other.u;	this->w = other.w;
			this->e = other.e;	this->i = other.i;
			this->o = other.o;
		}
	}
	~type_def()
	{
		this->q = NULL;	this->r.clear();
		this->t = NULL;	this->y.clear();
		this->u = NULL;	this->w.clear();
		this->e = NULL;	this->i = NULL;
		this->o = NULL;

	}
	void operator=(GeneralFact& other) override
	{
		type_def* ptr = dynamic_cast<type_def*>(&other);
		this->q = ptr->q;	this->r = ptr->r;
		this->t = ptr->t;	this->y = ptr->y;
		this->u = ptr->u;	this->w = ptr->w;
		this->e = ptr->e;	this->i = ptr->i;
		this->o = ptr->o;
	}
	type_def(type_def&& other)  noexcept
		: q{ other.q }, e{ other.e }, t{ other.t }, u{ other.u }, i{ other.i }, 
		o{ other.o }, w{ other.w }, r{ other.r }, y{ other.y } {}
	void operator=(type_def&& other)  noexcept
	{
		std::swap(q, other.q); std::swap(e, other.e); std::swap(t, other.t); std::swap(u, other.u);
		std::swap(i, other.i); std::swap(o, other.o); std::swap(w, other.w); std::swap(r, other.r);
		std::swap(y, other.y);
	}

	friend string makeStringOf(GeneralFact* obj);

	friend size_t matchfactsstar(GeneralFact* Treesfact, factstar* obj); 

	friend size_t matchfactsSpec(GeneralFact* otherf, factUnderInspection* obj);

};//page 5

class op_def : public GeneralFact
{
	int				q{}, r{}, t{}, y{}, u{};
	string			w{}, e{};
public:
	op_def(const int q1, const int r1, const int t1, const int y1,
		const int u1, const string w1, const string e1)
		:q(q1), r(r1), t(t1), y(y1), u(u1), w(w1), e(e1){}
	op_def(const op_def& other)
	{
		if (this != &other)
		{
			this->q = other.q;	this->r = other.r;
			this->t = other.t;	this->y = other.y;
			this->u = other.u;	this->w = other.w;
			this->e = other.e;
		}
	}
	~op_def()
	{
		this->q = NULL;	this->r = NULL;
		this->t = NULL;	this->y = NULL;
		this->u = NULL;	this->w.clear();
		this->e.clear();

	}
	void operator=(GeneralFact& other) override
	{
		op_def* ptr = dynamic_cast<op_def*>(&other);
		this->q = ptr->q;	this->r = ptr->r;
		this->t = ptr->t;	this->y = ptr->y;
		this->u = ptr->u;	this->w = ptr->w;
		this->e = ptr->e;
	}
	op_def(op_def&& other)  noexcept
		: q{ other.q }, e{ other.e }, t{ other.t }, u{ other.u },
		w{ other.w }, r{ other.r }, y{ other.y } {}
	void operator=(op_def&& other)  noexcept
	{
		std::swap(q, other.q); std::swap(e, other.e); std::swap(t, other.t); std::swap(u, other.u);
		std::swap(w, other.w); std::swap(r, other.r); std::swap(y, other.y);
	}
	friend string makeStringOf(GeneralFact* obj);

	friend size_t matchfactsstar(GeneralFact* Treesfact, factstar* obj);

	friend size_t matchfactsSpec(GeneralFact* otherf, factUnderInspection* obj);
};//page 6

class hierarchy_part : public GeneralFact
{
	int				q{}, e{}, t{}, y{}, u{};
	string			w{}, r{};
public:
	hierarchy_part(const int q1, const int e1, const int t1, const int y1,
		const int u1, const string w1, const string r1)
		:q(q1), e(e1), t(t1), y(y1), u(u1), w(w1), r(r1){}
	hierarchy_part(const hierarchy_part& other)
	{
		if (this != &other)
		{
			this->q = other.q;	this->r = other.r;
			this->t = other.t;	this->y = other.y;
			this->u = other.u;	this->w = other.w;
			this->e = other.e;
		}
	}
	~hierarchy_part()
	{
		this->q = NULL;	this->r.clear();
		this->t = NULL;	this->y = NULL;
		this->u = NULL;	this->w.clear();
		this->e = NULL;

	}
	void operator=(GeneralFact& other) override 
	{
		hierarchy_part* ptr = dynamic_cast<hierarchy_part*>(&other);
		this->q = ptr->q;	this->r = ptr->r;
		this->t = ptr->t;	this->y = ptr->y;
		this->u = ptr->u;	this->w = ptr->w;
		this->e = ptr->e;
	}
	hierarchy_part(hierarchy_part&& other)  noexcept
		: q{ other.q }, e{ other.e }, t{ other.t }, u{ other.u },
		w{ other.w }, r{ other.r }, y{ other.y } {}
	void operator=(hierarchy_part&& other)  noexcept
	{
		std::swap(q, other.q); std::swap(e, other.e); std::swap(t, other.t); std::swap(u, other.u);
		std::swap(w, other.w); std::swap(r, other.r); std::swap(y, other.y);
	}
	friend string makeStringOf(GeneralFact* obj);

	friend size_t matchfactsstar(GeneralFact* Treesfact, factstar* obj);

	friend size_t matchfactsSpec(GeneralFact* otherf, factUnderInspection* obj);
};//page 7

class data_stmt : public GeneralFact
{
	int				e{}, r{};
	string			q{}, w{}, t{}, y{};
public:
	data_stmt(const int e1, const int r1, string q1, string w1,
		string t1, const string y1)
		:e(e1), r(r1), q(q1), w(w1), t(t1), y(y1) {}
	data_stmt(const data_stmt& other)
	{
		if (this != &other)
		{
			this->q = other.q;	this->r = other.r;
			this->t = other.t;	this->y = other.y;
			this->w = other.w;	this->e = other.e;
		}
	}
	~data_stmt()
	{
		this->q.clear();	this->r = NULL;
		this->t.clear();	this->y.clear();
		this->w.clear();	this->e = NULL;

	}
	void operator=(GeneralFact& other) override
	{
		data_stmt* ptr = dynamic_cast<data_stmt*>(&other);
		this->q = ptr->q;	this->r = ptr->r;
		this->t = ptr->t;	this->y = ptr->y;
		this->w = ptr->w;	this->e = ptr->e;
	}
	data_stmt(data_stmt&& other)  noexcept
		: q{ other.q }, e{ other.e }, t{ other.t },
		w{ other.w }, r{ other.r }, y{ other.y } {}
	void operator=(data_stmt&& other)  noexcept
	{
		std::swap(q, other.q); std::swap(e, other.e); std::swap(t, other.t); std::swap(w, other.w);
		std::swap(r, other.r); std::swap(y, other.y);
	}
	friend string makeStringOf(GeneralFact* obj);

	friend size_t matchfactsstar(GeneralFact* Treesfact, factstar* obj);

	friend size_t matchfactsSpec(GeneralFact* otherf, factUnderInspection* obj);
};//page 8

class prog_stmt : public GeneralFact
{
	int				w{}, e{}, r{}, t{}, y{}, u{}, i{};
	string			q{};
public:
	prog_stmt(const int w1, const int e1, const int r1, const int t1,
		const int y1, const int u1, const int i1, const string q1)
		:w(w1), e(e1), r(r1), t(t1), y(y1), u(u1), i(i1), q(q1){}
	prog_stmt(const prog_stmt& other)
	{
		if (this != &other)
		{
			this->q = other.q;	this->r = other.r;
			this->t = other.t;	this->y = other.y;
			this->u = other.u;	this->w = other.w;
			this->e = other.e;	this->i = other.i;
		}
	}
	~prog_stmt()
	{
		this->q.clear();this->r = NULL;
		this->t = NULL;	this->y = NULL;
		this->u = NULL;	this->w = NULL;
		this->e = NULL; this->i = NULL;

	}
	void operator=(GeneralFact& other) override
	{
		prog_stmt* ptr = dynamic_cast<prog_stmt*>(&other);
		this->q = ptr->q;	this->r = ptr->r;
		this->t = ptr->t;	this->y = ptr->y;
		this->u = ptr->u;	this->w = ptr->w;
		this->e = ptr->e;	this->i = ptr->i;
	}
	prog_stmt(prog_stmt&& other)  noexcept
		: q{ other.q }, e{ other.e }, t{ other.t }, u{ other.u }, i{ other.i },
		w{ other.w }, r{ other.r }, y{ other.y } {}
	void operator=(prog_stmt&& other)  noexcept
	{
		std::swap(q, other.q); std::swap(e, other.e); std::swap(t, other.t); std::swap(u, other.u);
		std::swap(i, other.i); std::swap(w, other.w); std::swap(r, other.r);
		std::swap(y, other.y);
	}
	friend string makeStringOf(GeneralFact* obj);

	friend size_t matchfactsstar(GeneralFact* Treesfact, factstar* obj);

	friend size_t matchfactsSpec(GeneralFact* otherf, factUnderInspection* obj);
};//page 9

class joint_stmt : public GeneralFact
{
	int				w{}, e{}, r{}, t{}, y{};
	string			q{};
public:
	joint_stmt(const int w1, const int e1, const int r1, const int t1,
		const int y1, string q1)
		:w(w1), e(e1), r(r1), t(t1), y(y1), q(q1){}
	joint_stmt(const joint_stmt& other)
	{
		if (this != &other)
		{
			this->q = other.q;	this->r = other.r;
			this->t = other.t;	this->y = other.y;
			this->w = other.w;	this->e = other.e;
		}
	}

	~joint_stmt()
	{
		this->q.clear();this->r = NULL;
		this->t = NULL;	this->y = NULL;
		this->w = NULL;	this->e = NULL;

	}
	void operator=(GeneralFact& other) override
	{
		joint_stmt* ptr = dynamic_cast<joint_stmt*>(&other);
		this->q = ptr->q;	this->r = ptr->r;
		this->t = ptr->t;	this->y = ptr->y;
		this->w = ptr->w;	this->e = ptr->e;
	}
	joint_stmt(joint_stmt&& other)  noexcept
		: q{ other.q }, e{ other.e }, t{ other.t },
		w{ other.w }, r{ other.r }, y{ other.y } {}
	void operator=(joint_stmt&& other)  noexcept
	{
		std::swap(q, other.q); std::swap(e, other.e); std::swap(t, other.t); std::swap(w, other.w);
		std::swap(r, other.r); std::swap(y, other.y);
	}
	friend string makeStringOf(GeneralFact* obj);

	friend size_t matchfactsstar(GeneralFact* Treesfact, factstar* obj);

	friend size_t matchfactsSpec(GeneralFact* otherf, factUnderInspection* obj);
};//page 12

//vector
class call_stmt : public GeneralFact
{
	int					w{}, e{};
	string				q{};
	vector<int>			r{};
public:
	call_stmt(const int w1, const int e1,const string q1, const vector<int> r1)
		:w(w1), e(e1), q(q1), r(r1) {
		r.shrink_to_fit();
	}
	call_stmt(const call_stmt& other)
	{
		if (this != &other)
		{
			this->q = other.q;	this->r = other.r;
			this->w = other.w;	this->e = other.e;
		}
	}
	~call_stmt()
	{
		this->q.clear();this->r.clear();
		this->w = NULL;	this->e = NULL;

	}
	void operator=(GeneralFact& other) override
	{
		call_stmt* ptr = dynamic_cast<call_stmt*>(&other);
		this->q = ptr->q;	this->r = ptr->r;
		this->w = ptr->w;	this->e = ptr->e;
	}
	call_stmt(call_stmt&& other)  noexcept
		: q{ other.q }, e{ other.e }, w{ other.w }, r{ other.r } {}
	void operator=(call_stmt&& other)  noexcept
	{
		std::swap(q, other.q); std::swap(e, other.e); std::swap(w, other.w); std::swap(r, other.r);
	}
	friend string makeStringOf(GeneralFact* obj);

	friend size_t matchfactsstar(GeneralFact* Treesfact, factstar* obj);

	friend size_t matchfactsSpec(GeneralFact* otherf, factUnderInspection* obj);
};//page 13

//vector
class compo_stmt : public GeneralFact
{
	int				w{};
	string			q{};
	vector<int>		r{};
public:
	compo_stmt(const int w1, string q1, const vector<int> r1)
		:w(w1), q(q1), r(r1) {
		r.shrink_to_fit();
	}
	compo_stmt(const compo_stmt& other)
	{
		if (this != &other)
		{
			this->q = other.q;	this->r = other.r;
			this->w = other.w;	
		}
	}
	~compo_stmt()
	{
		this->q.clear();this->r.clear();
		this->w = NULL;

	}
	void operator=(GeneralFact& other) override 
	{
		compo_stmt* ptr = dynamic_cast<compo_stmt*>(&other);
		this->q = ptr->q;	this->r = ptr->r;
		this->w = ptr->w;	
	}
	compo_stmt(compo_stmt&& other)  noexcept
		: q{ other.q }, w{ other.w }, r{ other.r } {}
	void operator=(compo_stmt&& other)  noexcept
	{
		std::swap(q, other.q); std::swap(w, other.w); std::swap(r, other.r);
	}
	friend string makeStringOf(GeneralFact* obj);

	friend size_t matchfactsstar(GeneralFact* Treesfact, factstar* obj);

	friend size_t matchfactsSpec(GeneralFact* otherf, factUnderInspection* obj);
};//page 14

//vector
class rec_stmt : public GeneralFact
{
	int				w{};
	string			q{};
	vector<int>		e{};
public:
	rec_stmt(const int w1,const string q1, const vector<int> e1)
		:w(w1), q(q1), e(e1) {
		e.shrink_to_fit();
	}
	rec_stmt(const rec_stmt& other)
	{
		if (this != &other)
		{
			this->q = other.q;	
			this->w = other.w;
			this->e = other.e;
		}
	}
	~rec_stmt()
	{
		this->q.clear();
		this->w = NULL;
		this->e.clear();

	}
	void operator=(GeneralFact& other) override
	{
		rec_stmt* ptr = dynamic_cast<rec_stmt*>(&other);
		this->q = ptr->q;
		this->w = ptr->w;
		this->e = ptr->e;
	}
	rec_stmt(rec_stmt&& other)  noexcept
		: q{ other.q }, e{ other.e }, w{ other.w } {}

	void operator=(rec_stmt&& other)  noexcept
	{
		std::swap(q, other.q); std::swap(e, other.e); std::swap(w, other.w); 
	}
	friend string makeStringOf(GeneralFact* obj);

	friend size_t matchfactsstar(GeneralFact* Treesfact, factstar* obj);

	friend size_t matchfactsSpec(GeneralFact* otherf, factUnderInspection* obj);
};//page 16

class special_op : public GeneralFact
{
	int				w{}, r{}, t{}, y{}, i{}, o{}, p{};
	string			q{}, e{}, u{};
public:
	special_op(const int w1, const int r1, const int t1, const int y1,
		const int i1, const int o1, const int p1,const string q1, const string e1, const string u1)
		:w(w1), r(r1), t(t1), y(y1), i(i1), o(o1), p(p1), q(q1), e(e1), u(u1){}
	special_op(const special_op& other)
	{
		if (this != &other)
		{
			this->q = other.q;	this->r = other.r;
			this->t = other.t;	this->y = other.y;
			this->u = other.u;	this->w = other.w;
			this->e = other.e;	this->i = other.i;
			this->o = other.o;	this->p = other.p;
		}
	}
	~special_op()
	{
		this->q.clear();this->r = NULL;
		this->t = NULL;	this->y = NULL;
		this->u.clear();this->w = NULL;
		this->e.clear();this->i = NULL;
		this->o = NULL;	this->p = NULL;

	}
	void operator=(GeneralFact& other) override
	{
		special_op* ptr = dynamic_cast<special_op*>(&other);
		this->q = ptr->q;	r = ptr->r;
		this->t = ptr->t;	y = ptr->y;
		this->u = ptr->u;	w = ptr->w;
		this->e = ptr->e;	i = ptr->i;
		this->o = ptr->o;	p = ptr->p;
	}
	special_op(special_op&& other)  noexcept
		: q{ other.q }, e{ other.e }, t{ other.t }, u{ other.u }, i{ other.i },
		o{ other.o }, w{ other.w }, r{ other.r }, y{ other.y } {}
	void operator=(special_op&& other)  noexcept
	{
		std::swap(q, other.q); std::swap(e, other.e); std::swap(t, other.t); std::swap(u, other.u);
		std::swap(i, other.i); std::swap(o, other.o); std::swap(w, other.w); std::swap(r, other.r);
		std::swap(y, other.y);
	}
	friend string makeStringOf(GeneralFact* obj);

	friend size_t matchfactsstar(GeneralFact* Treesfact, factstar* obj);

	friend size_t matchfactsSpec(GeneralFact* otherf, factUnderInspection* obj);
};//page 23

class special_dt : public GeneralFact
{
	int				w{}, r{};
	string			q{}, e{}, t{}, y{}, u{};
public:
	special_dt(const int w1, const int r1, const string q1, const string e1, const string t1,
		const string y1,const string u1)
		:w(w1), r(r1), q(q1), e(e1), t(t1), y(y1), u(u1){}
	special_dt(const special_dt& other)
	{
		if (this != &other)
		{
			this->q = other.q;	this->r = other.r;
			this->t = other.t;	this->y = other.y;
			this->u = other.u;	this->w = other.w;
			this->e = other.e;
		}
	}
	~special_dt()
	{
		this->q.clear();	this->r = NULL;
		this->t.clear();	this->y.clear();
		this->u.clear();	this->w = NULL;
		this->e.clear();

	}
	void operator=(GeneralFact& other) override
	{
		special_dt* ptr = dynamic_cast<special_dt*>(&other);
		this->q = ptr->q; this->r = ptr->r;
		this->t = ptr->t; this->y = ptr->y;
		this->u = ptr->u; this->w = ptr->w;
		this->e = ptr->e;
	}
	special_dt(special_dt&& other)  noexcept
		: q{ other.q }, e{ other.e }, t{ other.t }, u{ other.u },
		w{ other.w }, r{ other.r }, y{ other.y } {}
	void operator=(special_dt&& other)  noexcept
	{
		std::swap(q, other.q); std::swap(e, other.e); std::swap(t, other.t); std::swap(u, other.u);
		std::swap(w, other.w); std::swap(r, other.r); std::swap(y, other.y);
	}
	friend string makeStringOf(GeneralFact* obj);

	friend size_t matchfactsstar(GeneralFact* Treesfact, factstar* obj);

	friend size_t matchfactsSpec(GeneralFact* otherf, factUnderInspection* obj);
};//page 24

class local_object : public GeneralFact
{
	int				w{}, t{}, i{};
	string			q{}, e{}, r{}, y{}, u{}, o{};
public:
	local_object(const int t1, const int w1, const int i1, const string q1, const string e1,
		const string y1, const string u1, const string r1, const string o1)
		:t(t1), w(w1), i(i1), q(q1), e(e1), y(y1), u(u1), r(r1), o(o1){}
	local_object()
		:w(0),i(0),r(""),t(0),q(""),e(""),y(""),u(""),o(""){}
	local_object(const local_object& other)
	{
		if (this != &other)
		{
			this->q = other.q;	this->r = other.r;
			this->t = other.t;	this->y = other.y;
			this->u = other.u;	this->w = other.w;
			this->i = other.i;	this->o = other.o;
			this->e = other.e;
		}
	}
	~local_object()
	{
		this->q.clear();this->r.clear();
		this->t = NULL;	this->y.clear();
		this->u.clear();this->w = NULL;
		this->i = NULL;	this->o.clear();
		this->e.clear();

	}
	void operator=(GeneralFact& other) override
	{
		local_object* ptr = dynamic_cast<local_object*>(&other);
		this->q = ptr->q;	this->r = ptr->r;
		this->t = ptr->t;	this->y = ptr->y;
		this->u = ptr->u;	this->w = ptr->w;
		this->i = ptr->i;	this->o = ptr->o;
		this->e = ptr->e;
	}

	void operator=(local_object& other)
	{
		local_object* ptr = new local_object();
		this->q = ptr->q;	this->r = ptr->r;
		this->t = ptr->t;	this->y = ptr->y;
		this->u = ptr->u;	this->w = ptr->w;
		this->i = ptr->i;	this->o = ptr->o;
		this->e = ptr->e;
	}

	local_object(local_object&& other)  noexcept
		: q{ other.q }, e{ other.e }, t{ other.t }, u{ other.u }, i{ other.i },
		o{ other.o }, w{ other.w }, r{ other.r }, y{ other.y } {}
	void operator=(local_object&& other)  noexcept
	{
		std::swap(q, other.q); std::swap(e, other.e); std::swap(t, other.t); std::swap(u, other.u);
		std::swap(i, other.i); std::swap(o, other.o); std::swap(w, other.w); std::swap(r, other.r);
		std::swap(y, other.y);
	}
	bool operator==(local_object other)
	{
		if (this->q == other.q && this->w == other.w &&
			this->e == other.e && this->r == other.r &&
			this->t == other.t && this->y == other.y &&
			this->u == other.u && this->i == other.i &&
			this->o == other.o) return true;
		else return false;
	}
	friend string makeStringOf(GeneralFact* obj);

	friend size_t matchfactsstar(GeneralFact* Treesfact, factstar* obj);

	friend size_t matchfactsSpec(GeneralFact* otherf, factUnderInspection* obj);
};//page 25

class state_node : public GeneralFact
{
	int				w{};
	string			q{};
public:
	state_node(const int w1, const string q1)
		:w(w1), q(q1) {}
	state_node()
		:w(0),q(""){}
	~state_node()
	{
		this->q.clear();this->w = NULL; 

	}
	void operator=(GeneralFact& other) override
	{
		state_node* ptr = dynamic_cast<state_node*>(&other);
		this->q = ptr->q;	this->w = ptr->w;
	}

	state_node(state_node&& other)  noexcept
		: q{ other.q }, w{ other.w }  {}

	void operator=(state_node&& other)  noexcept
	{
		std::swap(q, other.q); std::swap(w, other.w);
	}	
	friend string makeStringOf(GeneralFact* obj);

	friend size_t matchfactsstar(GeneralFact* Treesfact, factstar* obj);

	friend size_t matchfactsSpec(GeneralFact* otherf, factUnderInspection* obj);
};//page 26

//vector
class subprogram_call : public state_node
{
	int			w{};
	vector<int>	q{};
public:
	subprogram_call(const int w1, const vector<int>q1, const int e1, const string r1)
		:state_node(e1, r1), w(w1), q(q1) {
		q.shrink_to_fit();
	}
	subprogram_call(const subprogram_call& other)
	{
		if (this != &other)
		{
			this->q = other.q; this->w = other.w;
		}
	}
	~subprogram_call()
	{
		state_node* ptr = dynamic_cast<state_node*>(this);
		this->q.clear(); this->w = NULL;
	}
	void operator=(const subprogram_call& other)
	{
		q = other.q; w = other.w;
	}
	subprogram_call(subprogram_call&& other)  noexcept
		: q{ other.q }, w{ other.w } {}
	void operator=(subprogram_call&& other)  noexcept
	{
		std::swap(q, other.q); std::swap(w, other.w);
	}
	friend string makeStringOf(GeneralFact* obj);

	friend size_t matchfactsstar(GeneralFact* Treesfact, factstar* obj);

	friend size_t matchfactsSpec(GeneralFact* otherf, factUnderInspection* obj);
};

//vector
class dataflow : public state_node
{
	int			w{};
	vector<int>	q{};
public:
	dataflow(const int w1, const vector<int> q1, const int e1, const string r1)
		:state_node(e1, r1), w(w1), q(q1) {
		q.shrink_to_fit();
	}
	dataflow(const dataflow& other)
	{
		if (this != &other)
		{
			this->q = other.q; this->w = other.w;
		}
	}
	~dataflow()
	{
		state_node* ptr = dynamic_cast<state_node*>(this);
		this->q.clear(); this->w = NULL;
	}
	void operator=(const dataflow& other)
	{
		q = other.q; w = other.w;
	}
	dataflow(dataflow&& other)  noexcept
		: q{ other.q }, w{ other.w } {}
	void operator=(dataflow&& other)  noexcept
	{
		std::swap(q, other.q); std::swap(w, other.w);
	}
	friend string makeStringOf(GeneralFact* obj);

	friend size_t matchfactsstar(GeneralFact* Treesfact, factstar* obj);

	friend size_t matchfactsSpec(GeneralFact* otherf, factUnderInspection* obj);
};

//vector
class ifthen : public state_node
{
	int			r{}, t{};
	vector<int> q{}, w{}, e{};
public:
	ifthen(const int r1, const int t1, const vector<int> q1, const vector<int> w1, 
		const vector<int> e1, const int y1, const string u1)
		:state_node(y1, u1), r(r1), t(t1), q(q1), w(w1), e(e1) {
		q.shrink_to_fit();
		w.shrink_to_fit();
		e.shrink_to_fit();
	}
	ifthen(const ifthen& other)
	{
		if (this != &other)
		{
			this->q = other.q; this->w = other.w;
			this->e = other.e; this->r = other.r;
			this->t = other.t;
		}
	}
	~ifthen()
	{
		state_node* ptr = dynamic_cast<state_node*>(this);
		this->q.clear(); this->w.clear();
		this->e.clear(); this->r = NULL;
		this->t = NULL;
	}
	void operator=(const ifthen& other)
	{
		q = other.q; w = other.w;
		e = other.e; r = other.r;
		t = other.t;
	}
	ifthen(ifthen&& other)  noexcept
		: q{ other.q }, e{ other.e }, t{ other.t }, w{ other.w }, r{ other.r } {}
	void operator=(ifthen&& other)  noexcept
	{
		std::swap(q, other.q); std::swap(e, other.e); std::swap(t, other.t); std::swap(w, other.w);
		std::swap(r, other.r);
	}
	friend string makeStringOf(GeneralFact* obj);

	friend size_t matchfactsstar(GeneralFact* Treesfact, factstar* obj);

	friend size_t matchfactsSpec(GeneralFact* otherf, factUnderInspection* obj);
};

//vector
class jump : public state_node
{
	int			w{};
	vector<int> q{};
public:
	jump(const int w1, const vector<int> q1, const int e1, const string r1)
		:state_node(e1, r1), w(w1), q(q1) {
		q.shrink_to_fit();
	}
	jump(const jump& other)
	{
		if (this != &other)
		{
			this->q = other.q; this->w = other.w;
		}
	}
	~jump()
	{
		state_node* ptr = dynamic_cast<state_node*>(this);
		this->q.clear(); this->w = NULL;
	}
	void operator=(const jump& other)
	{
		q = other.q; w = other.w;
	}
	jump(jump&& other)  noexcept
		: q{ other.q }, w{ other.w } {}
	void operator=(jump&& other)  noexcept
	{
		std::swap(q, other.q); std::swap(w, other.w);
	}
	friend string makeStringOf(GeneralFact* obj);

	friend size_t matchfactsstar(GeneralFact* Treesfact, factstar* obj);

	friend size_t matchfactsSpec(GeneralFact* otherf, factUnderInspection* obj);
};

//vector
class return_cos : public state_node
{
	vector<int>		q;
public:
	return_cos(const vector<int> q1, const int e1, const string r1)
		:state_node(e1, r1), q(q1) {
		q.shrink_to_fit();
	}
	return_cos(const return_cos& other)
	{
		if (this != &other)
		{
			this->q = other.q;
		}
	}
	~return_cos()
	{
		state_node* ptr = dynamic_cast<state_node*>(this);
		this->q.clear();
	}
	void operator=(const return_cos& other)
	{
		q = other.q;
	}
	return_cos(return_cos&& other)  noexcept
		: q{ other.q } {}
	void operator=(return_cos&& other)  noexcept
	{
		std::swap(q, other.q);
	}
	friend string makeStringOf(GeneralFact* obj);

	friend size_t matchfactsstar(GeneralFact* Treesfact, factstar* obj);

	friend size_t matchfactsSpec(GeneralFact* otherf, factUnderInspection* obj);
};

class change_op_number : public GeneralFact
{
	int				w{}, e{};
	string			q{};
public:
	change_op_number(const int e1, const int w1, const string q1)
		:e(e1), w(w1), q(q1){}
	change_op_number(const change_op_number& other)
	{
		if (this != &other)
		{
			this->q = other.q;	this->w = other.w;
			this->e = other.e;
		}
	}
	~change_op_number()
	{
		this->q.clear();this->w = NULL;
		this->e = NULL;

	}
	void operator=(GeneralFact& other) override
	{
		change_op_number* ptr = dynamic_cast<change_op_number*>(&other);
		this->q = ptr->q;	this->w = ptr->w;
		this->e = ptr->e;
	}
	change_op_number(change_op_number&& other)  noexcept
		: q{ other.q }, e{ other.e }, w{ other.w } {}
	void operator=(change_op_number&& other)  noexcept
	{
		std::swap(q, other.q); std::swap(e, other.e); std::swap(w, other.w);
	}
	friend string makeStringOf(GeneralFact* obj);

	friend size_t matchfactsstar(GeneralFact* Treesfact, factstar* obj);

	friend size_t matchfactsSpec(GeneralFact* otherf, factUnderInspection* obj);
};//page 28

class last_change_op_number : public GeneralFact
{
	int				w{}, e{};
	string			q{};
public:
	last_change_op_number(const int e1, const int w1, const string q1)
		:e(e1), w(w1), q(q1){}
	last_change_op_number(const last_change_op_number& other)
	{
		if (this != &other)
		{
			this->q = other.q;	this->w = other.w;
			this->e = other.e;
		}
	}
	~last_change_op_number()
	{
		this->q.clear(); this->w = NULL;
		this->e = NULL;

	}
	void operator=(GeneralFact& other) override
	{
		last_change_op_number* ptr = dynamic_cast<last_change_op_number*>(&other);
		this->q = ptr->q;	this->w = ptr->w;
		this->e = ptr->e;
	}
	last_change_op_number(last_change_op_number&& other)  noexcept
		: q{ other.q }, e{ other.e }, w{ other.w } {}
	void operator=(last_change_op_number&& other)  noexcept
	{
		std::swap(q, other.q); std::swap(e, other.e); std::swap(w, other.w);
	}
	friend string makeStringOf(GeneralFact* obj);

	friend size_t matchfactsstar(GeneralFact* Treesfact, factstar* obj);

	friend size_t matchfactsSpec(GeneralFact* otherf, factUnderInspection* obj);
};//page 28

//vector
class op_guards : public GeneralFact
{
	int				w{};
	string			q{};
	vector<int>		e{}, r{};
public:
	op_guards(const int w1, string q1, const vector<int>e1, const vector<int> r1)
		:w(w1), q(q1), e(e1), r(r1) {
		e.shrink_to_fit();
		r.shrink_to_fit();
	}
	op_guards(const op_guards& other)
	{
		if (this != &other)
		{
			this->q = other.q;	this->r = other.r;
			this->w = other.w;	this->e = other.e;
		}
	}
	~op_guards()
	{
		this->q.clear();this->r.clear();
		this->w = NULL;	this->e.clear();

	}
	void operator=(GeneralFact& other) override
	{
		op_guards* ptr = dynamic_cast<op_guards*>(&other);
		this->q = ptr->q;	this->r = ptr->r;
		this->w = ptr->w;	this->e = ptr->e;
	}
	op_guards(op_guards&& other)  noexcept
		: q{ other.q }, e{ other.e }, w{ other.w }, r{ other.r } {}
	void operator=(op_guards&& other)  noexcept
	{
		std::swap(q, other.q); std::swap(e, other.e); std::swap(w, other.w); std::swap(r, other.r);
	}
	friend string makeStringOf(GeneralFact* obj);

	friend size_t matchfactsstar(GeneralFact* Treesfact, factstar* obj);

	friend size_t matchfactsSpec(GeneralFact* otherf, factUnderInspection* obj);
};//page 29

//vector
class var_guards : public GeneralFact
{
	int				w{};
	string			q{};
	vector<int>		e{}, r{};
public:
	var_guards(const int w1, string q1, const vector<int> e1, const vector<int> r1)
		:w(w1), q(q1), e(e1), r(r1) {
		e.shrink_to_fit();
		r.shrink_to_fit();
	}
	var_guards(const var_guards& other)
	{
		if (this != &other)
		{
			this->q = other.q;	this->r = other.r;
			this->w = other.w;	this->e = other.e;
		}
	}
	~var_guards()
	{
		this->q.clear(); this->r.clear();
		this->w = NULL;	this->e.clear();

	}
	void operator=(GeneralFact& other) override
	{
		var_guards* ptr = dynamic_cast<var_guards*>(&other);
		this->q = ptr->q;	this->r = ptr->r;
		this->w = ptr->w;	this->e = ptr->e;
	}
	var_guards(var_guards&& other)  noexcept
		: q{ other.q }, e{ other.e }, w{ other.w }, r{ other.r } {}
	void operator=(var_guards&& other)  noexcept
	{
		std::swap(q, other.q); std::swap(e, other.e); std::swap(w, other.w); std::swap(r, other.r);
	}
	friend string makeStringOf(GeneralFact* obj);

	friend size_t matchfactsstar(GeneralFact* Treesfact, factstar* obj);

	friend size_t matchfactsSpec(GeneralFact* otherf, factUnderInspection* obj);
};//page 30
	
class guard_pair : public GeneralFact
{
	int				w{}, e{};
	string			q{}, r{};
public:
	guard_pair(const int w1, const int e1, string q1, string r1)
		:w(w1), e(e1), q(q1), r(r1){}
	guard_pair(const guard_pair& other)
	{
		if (this != &other)
		{
			this->q = other.q;	this->r = other.r;
			this->w = other.w;	this->e = other.e;
		}
	}
	~guard_pair()
	{
		this->q.clear();this->r.clear();
		this->w = NULL;	this->e = NULL;

	}
	void operator=(GeneralFact& other) override
	{
		guard_pair* ptr = dynamic_cast<guard_pair*>(&other);
		this->q = ptr->q;	this->r = ptr->r;
		this->w = ptr->w;	this->e = ptr->e;
	}
	guard_pair(guard_pair&& other)  noexcept
		: q{ other.q }, e{ other.e }, w{ other.w }, r{ other.r } {}
	void operator=(guard_pair&& other)  noexcept
	{
		std::swap(q, other.q); std::swap(e, other.e); std::swap(w, other.w); std::swap(r, other.r);
	}
	friend string makeStringOf(GeneralFact* obj);

	friend size_t matchfactsstar(GeneralFact* Treesfact, factstar* obj);

	friend size_t matchfactsSpec(GeneralFact* otherf, factUnderInspection* obj);
};//page 30

class guard_cond : public GeneralFact
{
	int				w{}, e{};
	string			q{}, r{};
public:
	guard_cond(const int w1, const int e1, const string q1, const string r1)
		:w(w1), e(e1), q(q1), r(r1){}
	guard_cond(const guard_cond& other)
	{
		if (this != &other)
		{
			this->q = other.q;	this->r = other.r;
			this->w = other.w;	this->e = other.e;
		}
	}
	~guard_cond()
	{
		this->q.clear(); this->r.clear();
		this->w = NULL;	this->e = NULL;

	}
	void operator=(GeneralFact& other) override
	{
		guard_cond* ptr = dynamic_cast<guard_cond*>(&other);
		this->q = ptr->q;	this->r = ptr->r;
		this->w = ptr->w;	this->e = ptr->e;
	}
	guard_cond(guard_cond&& other)  noexcept
		: q{ other.q }, e{ other.e }, w{ other.w }, r{ other.r } {}
	void operator=(guard_cond&& other)  noexcept
	{
		std::swap(q, other.q); std::swap(e, other.e); std::swap(w, other.w); std::swap(r, other.r);
	}
	friend string makeStringOf(GeneralFact* obj);

	friend size_t matchfactsstar(GeneralFact* Treesfact, factstar* obj);

	friend size_t matchfactsSpec(GeneralFact* otherf, factUnderInspection* obj);
};//page 31

//vector
class predecessors : public GeneralFact
{
	int				w{};
	string			q{};
	vector<int>		e{};
public:
	predecessors(const int w1, string q1, const vector<int> e1)
		:w(w1), q(q1), e(e1) {
		e.shrink_to_fit();
	}
	predecessors(const predecessors& other)
	{
		if (this != &other)
		{
			this->q = other.q;	this->w = other.w;
			this->e = other.e;
		}
	}
	~predecessors()
	{
		this->q.clear();	this->w = NULL;
		this->e.clear();

	}
	void operator=(GeneralFact& other) override
	{
		predecessors* ptr = dynamic_cast<predecessors*>(&other);
		this->q = ptr->q;	this->w = ptr->w;
		this->e = ptr->e;
	}
	predecessors(predecessors&& other)  noexcept
		: q{ other.q }, e{ other.e }, w{ other.w } {}
	void operator=(predecessors&& other)  noexcept
	{
		std::swap(q, other.q); std::swap(e, other.e); std::swap(w, other.w); 
	}
	friend string makeStringOf(GeneralFact* obj);

	friend size_t matchfactsstar(GeneralFact* Treesfact, factstar* obj);

	friend size_t matchfactsSpec(GeneralFact* otherf, factUnderInspection* obj);
};//page 32

class cessor : public GeneralFact
{
	int				w{}, e{};
	string			q{};
public:
	cessor(const int w1, const int e1, const string q1)
		:w(w1), e(e1), q(q1){}
	cessor(const cessor& other)
	{
		if (this != &other)
		{
			this->q = other.q;	this->w = other.w;
			this->e = other.e;
		}
	}
	~cessor()
	{
		this->q.clear(); this->w = NULL;
		this->e = NULL;

	}
	void operator=(GeneralFact& other) override
	{
		cessor* ptr = dynamic_cast<cessor*>(&other);
		this->q = ptr->q;	this->w = ptr->w;
		this->e = ptr->e;
	}
	cessor(cessor&& other)  noexcept
		: q{ other.q }, e{ other.e }, w{ other.w } {}
	void operator=(cessor&& other)  noexcept
	{
		std::swap(q, other.q); std::swap(e, other.e); std::swap(w, other.w);
	}
	friend string makeStringOf(GeneralFact* obj);

	friend size_t matchfactsstar(GeneralFact* Treesfact, factstar* obj);

	friend size_t matchfactsSpec(GeneralFact* otherf, factUnderInspection* obj);
};//page 33

//vector
class cessor_kind : public GeneralFact
{
	int				e{}, r{};
	string			q{}, w{}, t{}, y{};
	vector<int>		u{};
public:
	cessor_kind(const int e1, const int r1, const string q1, const string w1,
		const string t1, const string y1, const vector<int> u1)
		:e(e1), r(r1), q(q1), w(w1), t(t1), y(y1), u(u1) {
		u.shrink_to_fit();
	}
	cessor_kind(const cessor_kind& other)
	{
		if (this != &other)
		{
			this->q = other.q;	this->r = other.r;
			this->t = other.t;	this->y = other.y;
			this->u = other.u;	this->w = other.w;
			this->e = other.e;
		}
	}
	~cessor_kind()
	{
		this->q.clear();	this->r = NULL;
		this->t.clear();	this->y.clear();
		this->u.clear();	this->w.clear();
		this->e = NULL;

	}
	void operator=(GeneralFact& other) override
	{
		cessor_kind* ptr = dynamic_cast<cessor_kind*>(&other);
		this->q = ptr->q;	this->r = ptr->r;
		this->t = ptr->t;	this->y = ptr->y;
		this->u = ptr->u;	this->w = ptr->w;
		this->e = ptr->e;
	}
	cessor_kind(cessor_kind&& other)  noexcept
		: q{ other.q }, e{ other.e }, t{ other.t }, u{ other.u }, w{ other.w }, r{ other.r }, y{ other.y } {}
	void operator=(cessor_kind&& other)  noexcept
	{
		std::swap(q, other.q); std::swap(e, other.e); std::swap(t, other.t); std::swap(u, other.u);
		std::swap(w, other.w); std::swap(r, other.r);
		std::swap(y, other.y);
	}
	friend string makeStringOf(GeneralFact* obj);

	friend size_t matchfactsstar(GeneralFact* Treesfact, factstar* obj);

	friend size_t matchfactsSpec(GeneralFact* otherf, factUnderInspection* obj);
};//page 34

class old_schedule : public GeneralFact
{
	string			q{};
public:
	old_schedule(const string q1)
		: q(q1){}

	old_schedule(const old_schedule& other)
	{
		if (this != &other)
		{
			this->q = other.q;
		}
	}
	~old_schedule()
	{
		this->q.clear();
	}
	void operator=(GeneralFact& other) override
	{
		old_schedule* ptr = dynamic_cast<old_schedule*>(&other);
		this->q = ptr->q;
	}

	old_schedule(old_schedule&& other)  noexcept
		: q{ other.q } {}

	void operator=(old_schedule&& other)  noexcept
	{
		std::swap(q, other.q); 
	}
	friend string makeStringOf(GeneralFact* obj);

	friend size_t matchfactsstar(GeneralFact* Treesfact, factstar* obj);

	friend size_t matchfactsSpec(GeneralFact* otherf, factUnderInspection* obj);
};

class new_schedule : public GeneralFact
{
	string			q{};
public:
	new_schedule(const string q1)
		: q(q1) {}

	new_schedule(const new_schedule& other)
	{
		if (this != &other)
		{
			this->q = other.q;
		}
	}
	~new_schedule()
	{
		this->q.clear();
	}

	void operator=(GeneralFact& other) override
	{
		new_schedule* ptr = dynamic_cast<new_schedule*>(&other);
		this->q = ptr->q;
	}

	new_schedule(new_schedule&& other)  noexcept
		: q{ other.q } {}

	void operator=(new_schedule&& other)  noexcept
	{
		std::swap(q, other.q);
	}
	friend string makeStringOf(GeneralFact* obj);

	friend size_t matchfactsstar(GeneralFact* Treesfact, factstar* obj);

	friend size_t matchfactsSpec(GeneralFact* otherf, factUnderInspection* obj);
};

class  local_ifthen_chain_end_operations_were_written : public GeneralFact
{
	int				q{};
public:
	local_ifthen_chain_end_operations_were_written(const int q1)
		: q(q1) {}
	local_ifthen_chain_end_operations_were_written(const local_ifthen_chain_end_operations_were_written& other)
	{
		if (this != &other)
		{
			this->q = other.q;
		}
	}
	~local_ifthen_chain_end_operations_were_written()
	{
		this->q = NULL;
	}
	void operator=(GeneralFact& other) override
	{
		local_ifthen_chain_end_operations_were_written* ptr = dynamic_cast<local_ifthen_chain_end_operations_were_written*>(&other);
		this->q = ptr->q;
	}

	local_ifthen_chain_end_operations_were_written(local_ifthen_chain_end_operations_were_written&& other)  noexcept
		: q{ other.q } {}

	void operator=(local_ifthen_chain_end_operations_were_written&& other)  noexcept
	{
		std::swap(q, other.q);
	}
	friend string makeStringOf(GeneralFact* obj);

	friend size_t matchfactsstar(GeneralFact* Treesfact, factstar* obj);

	friend size_t matchfactsSpec(GeneralFact* otherf, factUnderInspection* obj);
};

//vector
class calls_list : public GeneralFact
{
	int				w{}, e{};
	string			q{};
	vector<int>		r{};
public:
	calls_list(const string q1,const int w1, const int e1, const vector<int> r1)
		: q(q1), w(w1), e(e1), r(r1) {
		r.shrink_to_fit();
	}

	calls_list(const calls_list& other)
	{
		if (this != &other)
		{
			this->q = other.q;	this->w = other.w;
			this->e = other.e;  this->r = other.r;
		}
	}
	~calls_list()
	{
		this->q .clear();this->w = NULL;
		this->e = NULL;  this->r.clear();
	}
	void operator=(GeneralFact& other) override
	{
		calls_list* ptr = dynamic_cast<calls_list*>(&other);
		this->q = ptr->q;	this->w = ptr->w;
		this->e = ptr->e;	this->r = ptr->r;
	}

	calls_list(calls_list&& other)  noexcept
		: q{ other.q }, w{ other.w }, 
		  e{ other.e }, r{ other.r } {}

	void operator=(calls_list&& other)  noexcept
	{
		std::swap(q, other.q);	std::swap(w, other.w);
		std::swap(e, other.e);	std::swap(r, other.r);
	}
	friend string makeStringOf(GeneralFact* obj);

	friend size_t matchfactsstar(GeneralFact* Treesfact, factstar* obj);

	friend size_t matchfactsSpec(GeneralFact* otherf, factUnderInspection* obj);
};

//vector
class composites_list : public GeneralFact
{
	int				w{};
	string			q{};
	vector<int>		e{};
public:
	composites_list(const string q1, const int w1, const vector<int> e1)
		: q(q1), w(w1), e(e1) {
		e.shrink_to_fit();
	}

	composites_list(const composites_list& other)
	{
		if (this != &other)
		{
			this->q = other.q;	this->w = other.w;
			this->e = other.e;  
		}
	}
	~composites_list()
	{
		this->q.clear();this->w = NULL;
		this->e.clear();
	}
	void operator=(GeneralFact& other) override
	{
		composites_list* ptr = dynamic_cast<composites_list*>(&other);
		this->q = ptr->q;	this->w = ptr->w;
		this->e = ptr->e;
	}

	composites_list(composites_list&& other)  noexcept
		: q{ other.q }, w{ other.w }, e{ other.e } {}

	void operator=(composites_list&& other)  noexcept
	{
		std::swap(q, other.q);	std::swap(w, other.w);
		std::swap(e, other.e);	
	}
	friend string makeStringOf(GeneralFact* obj);

	friend size_t matchfactsstar(GeneralFact* Treesfact, factstar* obj);

	friend size_t matchfactsSpec(GeneralFact* otherf, factUnderInspection* obj);
};

//vector
class record_aggregates_list : public GeneralFact
{
	int				w{};
	string			q{};
	vector<int>		e{};
public:
	record_aggregates_list(const string q1, const int w1, const vector<int> e1)
		: q(q1), w(w1), e(e1) {
		e.shrink_to_fit();
	}

	record_aggregates_list(const record_aggregates_list& other)
	{
		if (this != &other)
		{
			this->q = other.q;	this->w = other.w;
			this->e = other.e;
		}
	}
	~record_aggregates_list()
	{
		this->q.clear();	this->w = NULL;
		this->e.clear();
	}
	void operator=(GeneralFact& other) override
	{
		record_aggregates_list* ptr = dynamic_cast<record_aggregates_list*>(&other);
		this->q = ptr->q;	this->w = ptr->w;
		this->e = ptr->e;
	}

	record_aggregates_list(record_aggregates_list&& other)  noexcept
		: q{ other.q }, w{ other.w }, e{ other.e } {}

	void operator=(record_aggregates_list&& other)  noexcept
	{
		std::swap(q, other.q);	std::swap(w, other.w);
		std::swap(e, other.e);
	}
	friend string makeStringOf(GeneralFact* obj);

	friend size_t matchfactsstar(GeneralFact* Treesfact, factstar* obj);

	friend size_t matchfactsSpec(GeneralFact* otherf, factUnderInspection* obj);
};

class mem_port : public GeneralFact
{
	int				q{}, y{}, i{}, s{};
	string			w{}, e{}, r{}, t{}, u{}, o{}, p{}, a{}, d{};
public:
	mem_port(const int q1, const string w1, const string e1, const string r1, const string t1, const int y1,
		const string u1, const int i1, const string o1, const string p1, const string a1, const int s1, const string d1)
		: q(q1), w(w1), e(e1), r(r1), t(t1), y(y1), u(u1), i(i1), o(o1), p(p1), a(a1), s(s1), d(d1) {}

	mem_port(const mem_port& other)
	{
		if (this != &other)
		{
			this->q = other.q;	this->w = other.w;
			this->e = other.e;	this->r = other.r;	
			this->t = other.t;	this->y = other.y;	
			this->u = other.u;	this->i = other.i;	
			this->o = other.o;	this->p = other.p;
			this->a = other.a;	this->s = other.s;
			this->d = other.d;
		}
	}
	~mem_port()
	{
		this->q = NULL;	this->w.clear();
		this->e.clear();this->r.clear();
		this->t.clear();this->y = NULL;
		this->u.clear();this->i = NULL;
		this->o.clear();this->p.clear();
		this->a.clear();this->s = NULL;
		this->d.clear();

	}
	void operator=(GeneralFact& other) override
	{
		mem_port* ptr = dynamic_cast<mem_port*>(&other);
		this->q = ptr->q;	this->w = ptr->w;
		this->e = ptr->e;	this->r = ptr->r;
		this->t = ptr->t;	this->y = ptr->y;
		this->u = ptr->u;	this->i = ptr->i;
		this->o = ptr->o;	this->p = ptr->p;
		this->a = ptr->a;	this->s = ptr->s;
		this->d = ptr->d;
	}

	mem_port(mem_port&& other)  noexcept
		: q{ other.q }, w{ other.w }, e{ other.e }, r{ other.r },
		t{ other.t }, y{ other.y }, u{ other.u }, i{ other.i },
		o{ other.o }, p{ other.p }, a{ other.a }, s{ other.s },
		d{ other.d } {}

	void operator=(mem_port&& other)  noexcept
	{
		std::swap(q, other.q);	std::swap(w, other.w);
		std::swap(e, other.e);	std::swap(r, other.r);
		std::swap(t, other.t);	std::swap(y, other.y);
		std::swap(u, other.u);	std::swap(i, other.i);
		std::swap(o, other.o);	std::swap(p, other.p);
		std::swap(a, other.a);	std::swap(s, other.s);
		std::swap(d, other.d);
	}
	friend string makeStringOf(GeneralFact* obj);

	friend size_t matchfactsstar(GeneralFact* Treesfact, factstar* obj);

	friend size_t matchfactsSpec(GeneralFact* otherf, factUnderInspection* obj);
};

//vector
class global_declarations :public GeneralFact
{
	int				w{};
	vector<local_object> q{};
public:
	global_declarations(const vector<local_object> q1, const int w1)
		: q(q1), w(w1) {
		q.shrink_to_fit();
	}

	global_declarations(const global_declarations& other)
	{
		if (this != &other)
		{
			this->q = other.q;	this->w = other.w;
		}
	}
	~global_declarations()
	{
		this->q.clear();this->w = NULL;

	}
	void operator=(GeneralFact& other) override
	{
		global_declarations* ptr = dynamic_cast<global_declarations*>(&other);
		this->q = ptr->q;	this->w = ptr->w;
	}

	global_declarations(global_declarations&& other)  noexcept
		: q{ other.q }, w{ other.w } {}

	void operator=(global_declarations&& other)  noexcept
	{
		std::swap(q, other.q);	std::swap(w, other.w);
	}

	friend string makeStringOf(GeneralFact* obj);

	friend size_t matchfactsstar(GeneralFact* Treesfact, factstar* obj);

	friend size_t matchfactsSpec(GeneralFact* otherf, factUnderInspection* obj);
};

class source_is_normal_dt : public GeneralFact
{
	int				w{}, e{};
	string			q{};
public:
	source_is_normal_dt(const string q1, const int w1, const int e1)
		: q(q1), w(w1), e(e1) {}

	source_is_normal_dt(const source_is_normal_dt& other)
	{
		if (this != &other)
		{
			this->q = other.q;	this->w = other.w;
			this->e = other.e;
		}
	}
	~source_is_normal_dt()
	{
		this->q.clear();this->w = NULL;
		this->e = NULL;

	}
	void operator=(GeneralFact& other) override
	{
		source_is_normal_dt* ptr = dynamic_cast<source_is_normal_dt*>(&other);
		this->q = ptr->q;	this->w = ptr->w;
		this->e = ptr->e;
	}

	source_is_normal_dt(source_is_normal_dt&& other)  noexcept
		: q{ other.q }, w{ other.w }, e{ other.e } {}

	void operator=(source_is_normal_dt&& other)  noexcept
	{
		std::swap(q, other.q);	std::swap(w, other.w);
		std::swap(e, other.e);
	}
	friend string makeStringOf(GeneralFact* obj);

	friend size_t matchfactsstar(GeneralFact* Treesfact, factstar* obj);

	friend size_t matchfactsSpec(GeneralFact* otherf, factUnderInspection* obj);
};

class combo : public GeneralFact
{
	int				q{}, e{};
	string			w{};
public:
	combo(const int q1, const string w1, const int e1)
		: q(q1), w(w1), e(e1) {}

	combo(const combo& other)
	{
		if (this != &other)
		{
			this->q = other.q;	this->w = other.w;
			this->e = other.e;
		}
	}
	~combo()
	{
		this->q = NULL;	this->w.clear();
		this->e = NULL;
	}
	void operator=(GeneralFact& other) override
	{
		combo* ptr = dynamic_cast<combo*>(&other);
		this->q = ptr->q;	this->w = ptr->w;
		this->e = ptr->e;
	}

	combo(combo&& other)  noexcept
		: q{ other.q }, w{ other.w }, e{ other.e } {}

	void operator=(combo&& other)  noexcept
	{
		std::swap(q, other.q);	std::swap(w, other.w);
		std::swap(e, other.e);
	}
	friend string makeStringOf(GeneralFact* obj);

	friend size_t matchfactsstar(GeneralFact* Treesfact, factstar* obj);

	friend size_t matchfactsSpec(GeneralFact* otherf, factUnderInspection* obj);
};

class sequence : public GeneralFact
{
	int				q{}, e{};
	string			w{};
public:
	sequence(const int q1, const string w1, const int e1)
		: q(q1), w(w1), e(e1) {}

	sequence(const sequence& other)
	{
		if (this != &other)
		{
			this->q = other.q;	this->w = other.w;
			this->e = other.e;
		}
	}
	~sequence()
	{
		this->q = NULL;	this->w.clear();
		this->e = NULL;
	}
	void operator=(GeneralFact& other) override
	{
		sequence* ptr = dynamic_cast<sequence*>(&other);
		this->q = ptr->q;	this->w = ptr->w;
		this->e = ptr->e;
	}

	sequence(sequence&& other)  noexcept
		: q{ other.q }, w{ other.w }, e{ other.e } {}

	void operator=(sequence&& other)  noexcept
	{
		std::swap(q, other.q);	std::swap(w, other.w);
		std::swap(e, other.e);
	}
	friend string makeStringOf(GeneralFact* obj);

	friend size_t matchfactsstar(GeneralFact* Treesfact, factstar* obj);

	friend size_t matchfactsSpec(GeneralFact* otherf, factUnderInspection* obj);
};

class for_loop : public GeneralFact
{
	int				q{}, e{}, r{}, t{}, y{}, u{}, i{}, o{}, p{}, a{}, s{}, d{};
	string			w{};
public:
	for_loop(const int q1, const string w1, const int e1, const int r1, const int t1, const int y1,
		const int u1, const int i1, const int o1, const int p1, const int a1, const int s1, const int d1)
		: q(q1), w(w1), e(e1), r(r1), t(t1), y(y1), u(u1), i(i1), o(o1), p(p1), a(a1), s(s1), d(d1) {}

	for_loop(const for_loop& other)
	{
		if (this != &other)
		{
			this->q = other.q;	this->w = other.w;
			this->e = other.e;	this->r = other.r;
			this->t = other.t;	this->y = other.y;
			this->u = other.u;	this->i = other.i;
			this->o = other.o;	this->p = other.p;
			this->a = other.a;	this->s = other.s;
			this->d = other.d;
		}
	}
	~for_loop()
	{
		this->q = NULL;	this->w.clear();
		this->e = NULL;	this->r = NULL;
		this->t = NULL;	this->y = NULL;
		this->u = NULL;	this->i = NULL;
		this->o = NULL;	this->p = NULL;
		this->a = NULL;	this->s = NULL;
		this->d = NULL;

	}
	void operator=(GeneralFact& other) override
	{
		for_loop* ptr = dynamic_cast<for_loop*>(&other);
		this->q = ptr->q;	this->w = ptr->w;
		this->e = ptr->e;	this->r = ptr->r;
		this->t = ptr->t;	this->y = ptr->y;
		this->u = ptr->u;	this->i = ptr->i;
		this->o = ptr->o;	this->p = ptr->p;
		this->a = ptr->a;	this->s = ptr->s;
		this->d = ptr->d;
	}

	for_loop(for_loop&& other)  noexcept
		: q{ other.q }, w{ other.w }, e{ other.e }, r{ other.r },
		t{ other.t }, y{ other.y }, u{ other.u }, i{ other.i },
		o{ other.o }, p{ other.p }, a{ other.a }, s{ other.s },
		d{ other.d } {}

	void operator=(for_loop&& other)  noexcept
	{
		std::swap(q, other.q);	std::swap(w, other.w);
		std::swap(e, other.e);	std::swap(r, other.r);
		std::swap(t, other.t);	std::swap(y, other.y);
		std::swap(u, other.u);	std::swap(i, other.i);
		std::swap(o, other.o);	std::swap(p, other.p);
		std::swap(a, other.a);	std::swap(s, other.s);
		std::swap(d, other.d);
	}
	friend string makeStringOf(GeneralFact* obj);

	friend size_t matchfactsstar(GeneralFact* Treesfact, factstar* obj);

	friend size_t matchfactsSpec(GeneralFact* otherf, factUnderInspection* obj);
};

class last_for_loop_entry : public GeneralFact
{
	int				q{};
public:
	last_for_loop_entry(const int q1)
		: q(q1) {}

	last_for_loop_entry(const last_for_loop_entry& other)
	{
		if (this != &other)
		{
			this->q = other.q;
		}
	}
	~last_for_loop_entry()
	{
		this->q = NULL;

	}
	void operator=(GeneralFact& other) override
	{
		last_for_loop_entry* ptr = dynamic_cast<last_for_loop_entry*>(&other);
		this->q = ptr->q;
	}

	last_for_loop_entry(last_for_loop_entry&& other)  noexcept
		: q{ other.q } {}

	void operator=(last_for_loop_entry&& other)  noexcept
	{
		std::swap(q, other.q);
	}
	friend string makeStringOf(GeneralFact* obj);

	friend size_t matchfactsstar(GeneralFact* Treesfact, factstar* obj);

	friend size_t matchfactsSpec(GeneralFact* otherf, factUnderInspection* obj);
};

class while_loop : public GeneralFact
{
	int				q{}, e{}, r{}, t{}, y{}, u{};
	string			w{};
public:
	while_loop(const int q1, const string w1, const int e1, const int r1, const int t1, const int y1,
		const int u1)
		: q(q1), w(w1), e(e1), r(r1), t(t1), y(y1), u(u1) {}

	while_loop(const while_loop& other)
	{
		if (this != &other)
		{
			this->q = other.q;	this->w = other.w;
			this->e = other.e;	this->r = other.r;
			this->t = other.t;	this->y = other.y;
			this->u = other.u;	
		}
	}
	~while_loop()
	{
		this->q = NULL;	this->w.clear();
		this->e = NULL;	this->r = NULL;
		this->t = NULL;	this->y = NULL;
		this->u = NULL;
	}
	void operator=(GeneralFact& other) override
	{
		while_loop* ptr = dynamic_cast<while_loop*>(&other);
		this->q = ptr->q;	this->w = ptr->w;
		this->e = ptr->e;	this->r = ptr->r;
		this->t = ptr->t;	this->y = ptr->y;
		this->u = ptr->u;
	}

	while_loop(while_loop&& other)  noexcept
		: q{ other.q }, w{ other.w }, e{ other.e }, r{ other.r },
		t{ other.t }, y{ other.y }, u{ other.u } {}

	void operator=(while_loop&& other)  noexcept
	{
		std::swap(q, other.q);	std::swap(w, other.w);
		std::swap(e, other.e);	std::swap(r, other.r);
		std::swap(t, other.t);	std::swap(y, other.y);
		std::swap(u, other.u);	
	}
	friend string makeStringOf(GeneralFact* obj);

	friend size_t matchfactsstar(GeneralFact* Treesfact, factstar* obj);

	friend size_t matchfactsSpec(GeneralFact* otherf, factUnderInspection* obj);
};

class last_while_loop_entry : public GeneralFact
{
	int				q{};
public:
	last_while_loop_entry(const int q1)
		: q(q1) {}

	last_while_loop_entry(const last_while_loop_entry& other)
	{
		if (this != &other)
		{
			this->q = other.q;
		}
	}
	~last_while_loop_entry()
	{
		this->q = NULL;
	}
	void operator=(GeneralFact& other) override
	{
		last_while_loop_entry* ptr = dynamic_cast<last_while_loop_entry*>(&other);
		this->q = ptr->q;
	}

	last_while_loop_entry(last_while_loop_entry&& other)  noexcept
		: q{ other.q } {}

	void operator=(last_while_loop_entry&& other)  noexcept
	{
		std::swap(q, other.q);
	}
	friend string makeStringOf(GeneralFact* obj);

	friend size_t matchfactsstar(GeneralFact* Treesfact, factstar* obj);

	friend size_t matchfactsSpec(GeneralFact* otherf, factUnderInspection* obj);
};

//vector
class possible_end_if : public GeneralFact
{
	string			q{};
	vector<int>		w{};
public:
	possible_end_if(const string q1, const vector<int> w1)
		: q(q1), w(w1) {
		w.shrink_to_fit();
	}

	possible_end_if(const possible_end_if& other)
	{
		if (this != &other)
		{
			this->q = other.q;	this->w = other.w;
		}
	}
	~possible_end_if()
	{
		this->q.clear();this->w.clear();
	}
	void operator=(GeneralFact& other) override
	{
		possible_end_if* ptr = dynamic_cast<possible_end_if*>(&other);
		this->q = ptr->q;	this->w = ptr->w;
	}

	possible_end_if(possible_end_if&& other)  noexcept
		: q{ other.q }, w{ other.w } {}

	void operator=(possible_end_if&& other)  noexcept
	{
		std::swap(q, other.q);	std::swap(w, other.w);
	}
	friend string makeStringOf(GeneralFact* obj);

	friend size_t matchfactsstar(GeneralFact* Treesfact, factstar* obj);

	friend size_t matchfactsSpec(GeneralFact* otherf, factUnderInspection* obj);
};

//vector
class end_if : public GeneralFact
{
	string			q{};
	vector<int>		w{};
public:
	end_if(const string q1, const vector<int> w1)
		: q(q1), w(w1) {
		w.shrink_to_fit();
	}
	end_if(const end_if& other)
	{
		if (this != &other)
		{
			this->q = other.q;	this->w = other.w;
		}
	}
	~end_if()
	{
		this->q.clear(); this->w.clear();
	}
	void operator=(GeneralFact& other) override
	{
		end_if* ptr = dynamic_cast<end_if*>(&other);
		this->q = ptr->q;	this->w = ptr->w;

	}

	end_if(end_if&& other)  noexcept
		: q{ other.q }, w{ other.w } {}

	void operator=(end_if&& other)  noexcept
	{
		std::swap(q, other.q);	std::swap(w, other.w);
	}
	friend string makeStringOf(GeneralFact* obj);

	friend size_t matchfactsstar(GeneralFact* Treesfact, factstar* obj);

	friend size_t matchfactsSpec(GeneralFact* otherf, factUnderInspection* obj);
};

//vector
class nested_cond_fact : public GeneralFact
{
	string			q{};
	vector<int>		w{};
public:
	nested_cond_fact(const string q1, const vector<int> w1)
		: q(q1), w(w1) {
		w.shrink_to_fit();
	}
	nested_cond_fact(const nested_cond_fact& other)
	{
		if (this != &other)
		{
			this->q = other.q;	this->w = other.w;
		}
	}
	~nested_cond_fact()
	{
		this->q.clear(); this->w.clear();
	}
	void operator=(GeneralFact& other) override
	{
		nested_cond_fact* ptr = dynamic_cast<nested_cond_fact*>(&other);
		this->q = ptr->q;	this->w = ptr->w;

	}

	nested_cond_fact(nested_cond_fact&& other)  noexcept
		: q{ other.q }, w{ other.w } {}

	void operator=(nested_cond_fact&& other)  noexcept
	{
		std::swap(q, other.q);	std::swap(w, other.w);
	}
	friend string makeStringOf(GeneralFact* obj);

	friend size_t matchfactsstar(GeneralFact* Treesfact, factstar* obj);

	friend size_t matchfactsSpec(GeneralFact* otherf, factUnderInspection* obj);
};

class top_level_call : public GeneralFact
{
	int				q{}, w{}, r{}, y{}, i{}, p{};
	string			e{}, t{}, u{}, o{}, a{};
public:
	top_level_call(const int q1, const int w1, const string e1, const int r1, const string t1, const int y1,
		const string u1, const int i1, const string o1, const int p1, const string a1)
		: q(q1), w(w1), e(e1), r(r1), t(t1), y(y1), u(u1), i(i1), o(o1), p(p1), a(a1) {}

	top_level_call(const top_level_call& other)
	{
		if (this != &other)
		{
			this->q = other.q;	this->w = other.w;
			this->e = other.e;	this->r = other.r;
			this->t = other.t;	this->y = other.y;
			this->u = other.u;	this->i = other.i;
			this->o = other.o;	this->p = other.p;
			this->a = other.a;
		}
	}
	~top_level_call()
	{
		this->q = NULL;	this->w = NULL;
		this->e.clear();this->r = NULL;
		this->t.clear();this->y = NULL;
		this->u.clear();this->i = NULL;
		this->o.clear();this->p = NULL;
		this->a.clear();

	}		   
	void operator=(GeneralFact& other) override
	{
		top_level_call* ptr = dynamic_cast<top_level_call*>(&other);
		this->q = ptr->q;	this->w = ptr->w;
		this->e = ptr->e;	this->r = ptr->r;
		this->t = ptr->t;	this->y = ptr->y;
		this->u = ptr->u;	this->i = ptr->i;
		this->o = ptr->o;	this->p = ptr->p;
		this->a = ptr->a;
	}

	top_level_call(top_level_call&& other)  noexcept
		: q{ other.q }, w{ other.w }, e{ other.e }, r{ other.r },
		t{ other.t }, y{ other.y }, u{ other.u }, i{ other.i },
		o{ other.o }, p{ other.p }, a{ other.a } {}

	void operator=(top_level_call&& other)  noexcept
	{
		std::swap(q, other.q);	std::swap(w, other.w);
		std::swap(e, other.e);	std::swap(r, other.r);
		std::swap(t, other.t);	std::swap(y, other.y);
		std::swap(u, other.u);	std::swap(i, other.i);
		std::swap(o, other.o);	std::swap(p, other.p);
		std::swap(a, other.a);
	}
	friend string makeStringOf(GeneralFact* obj);

	friend size_t matchfactsstar(GeneralFact* Treesfact, factstar* obj);

	friend size_t matchfactsSpec(GeneralFact* otherf, factUnderInspection* obj);
};

class top_level_call_parcs : public GeneralFact
{
	int				q{}, w{}, r{}, y{}, i{}, p{};
	string			e{}, t{}, u{}, o{}, a{};
public:
	top_level_call_parcs(const int q1, const int w1, const string e1, const int r1, const string t1, const int y1,
		const string u1, const int i1, const string o1, const int p1 , const string a1)
		: q(q1), w(w1), e(e1), r(r1), t(t1), y(y1), u(u1), i(i1), o(o1), p(p1), a(a1) {}

	top_level_call_parcs(const top_level_call_parcs& other)
	{
		if (this != &other)
		{
			this->q = other.q;	this->w = other.w;
			this->e = other.e;	this->r = other.r;
			this->t = other.t;	this->y = other.y;
			this->u = other.u;	this->i = other.i;
			this->o = other.o;	this->p = other.p;
			this->a = other.a;
		}
	}
	~top_level_call_parcs()
	{
		this->q = NULL;	this->w = NULL;
		this->e.clear(); this->r = NULL;
		this->t.clear(); this->y = NULL;
		this->u.clear(); this->i = NULL;
		this->o.clear(); this->p = NULL;
		this->a.clear();
	}
	void operator=(GeneralFact& other) override
	{
		top_level_call_parcs* ptr = dynamic_cast<top_level_call_parcs*>(&other);
		this->q = ptr->q;	this->w = ptr->w;
		this->e = ptr->e;	this->r = ptr->r;
		this->t = ptr->t;	this->y = ptr->y;
		this->u = ptr->u;	this->i = ptr->i;
		this->o = ptr->o;	this->p = ptr->p;
	}

	top_level_call_parcs(top_level_call_parcs&& other)  noexcept
		: q{ other.q }, w{ other.w }, e{ other.e }, r{ other.r },
		t{ other.t }, y{ other.y }, u{ other.u }, i{ other.i },
		o{ other.o }, p{ other.p }, a{ other.a } {}

	void operator=(top_level_call_parcs&& other)  noexcept
	{
		std::swap(q, other.q);	std::swap(w, other.w);
		std::swap(e, other.e);	std::swap(r, other.r);
		std::swap(t, other.t);	std::swap(y, other.y);
		std::swap(u, other.u);	std::swap(i, other.i);
		std::swap(o, other.o);	std::swap(p, other.p);
		std::swap(a, other.a);
	}
	friend string makeStringOf(GeneralFact* obj);

	friend size_t matchfactsstar(GeneralFact* Treesfact, factstar* obj);

	friend size_t matchfactsSpec(GeneralFact* otherf, factUnderInspection* obj);
};

class added_aux_call_ios : public GeneralFact
{
	int				w{};
	string			q{};
public:
	added_aux_call_ios(const string q1, const int w1)
		: q(q1), w(w1) {}

	added_aux_call_ios(const added_aux_call_ios& other)
	{
		if (this != &other)
		{
			this->q = other.q;	this->w = other.w;
		}
	}
	~added_aux_call_ios()
	{
		this->q.clear();this->w = NULL;
	}
	void operator=(GeneralFact& other) override
	{
		added_aux_call_ios* ptr = dynamic_cast<added_aux_call_ios*>(&other);
		this->q = ptr->q;	this->w = ptr->w;
	}

	added_aux_call_ios(added_aux_call_ios&& other)  noexcept
		: q{ other.q }, w{ other.w } {}

	void operator=(added_aux_call_ios&& other)  noexcept
	{
		std::swap(q, other.q);	std::swap(w, other.w);
	}
	friend string makeStringOf(GeneralFact* obj);

	friend size_t matchfactsstar(GeneralFact* Treesfact, factstar* obj);

	friend size_t matchfactsSpec(GeneralFact* otherf, factUnderInspection* obj);
};

class added_aux_call_ios1 : public GeneralFact
{
	int				w{}, e{};
	string			q{};
public:
	added_aux_call_ios1(const string q1, const int w1, const int e1)
		: q(q1), w(w1), e(e1) {}
	added_aux_call_ios1(const added_aux_call_ios1& other)
	{
		if (this != &other)
		{
			this->q = other.q;	this->w = other.w;
			this->e = other.e;
		}
	}
	~added_aux_call_ios1()
	{
		this->q.clear();this->w = NULL;
		this->e = NULL;
	}
	void operator=(GeneralFact& other) override
	{
		added_aux_call_ios1* ptr = dynamic_cast<added_aux_call_ios1*>(&other);
		this->q = ptr->q;	this->w = ptr->w;
		this->e = ptr->e;

	}
	added_aux_call_ios1(added_aux_call_ios1&& other)  noexcept
		: q{ other.q }, w{ other.w }, e{ other.e } {}

	void operator=(added_aux_call_ios1&& other)  noexcept
	{
		std::swap(q, other.q);	std::swap(w, other.w);
		std::swap(e, other.e);
	}
	friend string makeStringOf(GeneralFact* obj);

	friend size_t matchfactsstar(GeneralFact* Treesfact, factstar* obj);

	friend size_t matchfactsSpec(GeneralFact* otherf, factUnderInspection* obj);
};

class added_aux_call_signals : public GeneralFact
{
	int				w{};
	string			q{};
public:
	added_aux_call_signals(const string q1, const int w1)
		: q(q1), w(w1) {}

	added_aux_call_signals(const added_aux_call_signals& other)
	{
		if (this != &other)
		{
			this->q = other.q;	this->w = other.w;
		}
	}
	~added_aux_call_signals()
	{ 
		this->q.clear();this->w = NULL;	
	}
	void operator=(GeneralFact& other) override
	{
		added_aux_call_signals* ptr = dynamic_cast<added_aux_call_signals*>(&other);
		this->q = ptr->q;	this->w = ptr->w;

	}
	added_aux_call_signals(added_aux_call_signals&& other)  noexcept
		: q{ other.q }, w{ other.w } {}

	void operator=(added_aux_call_signals&& other)  noexcept
	{
		std::swap(q, other.q);	std::swap(w, other.w);
	}
	friend string makeStringOf(GeneralFact* obj);

	friend size_t matchfactsstar(GeneralFact* Treesfact, factstar* obj);

	friend size_t matchfactsSpec(GeneralFact* otherf, factUnderInspection* obj);
};

class found_call_operator : public GeneralFact
{
	int				w{};
	string			q{};
public:
	found_call_operator(const string q1, const int w1)
		: q(q1), w(w1) {}

	found_call_operator(const found_call_operator& other)
	{
		if (this != &other)
		{
			this->q = other.q;	this->w = other.w;
		}
	}
	~found_call_operator()
	{
		this->q.clear(); this->w = NULL;
	}
	void operator=(GeneralFact& other) override
	{
		found_call_operator* ptr = dynamic_cast<found_call_operator*>(&other);
		this->q = ptr->q;	this->w = ptr->w;

	}
	found_call_operator(found_call_operator&& other)  noexcept
		: q{ other.q }, w{ other.w } {}

	void operator=(found_call_operator&& other)  noexcept
	{
		std::swap(q, other.q);	std::swap(w, other.w);
	}
	friend string makeStringOf(GeneralFact* obj);

	friend size_t matchfactsstar(GeneralFact* Treesfact, factstar* obj);

	friend size_t matchfactsSpec(GeneralFact* otherf, factUnderInspection* obj);
};

class added_verilog_aux_call_outputs : public GeneralFact
{
	int				w{};
	string			q{}, e{};
public:
	added_verilog_aux_call_outputs(const string q1, const int w1, const string e1)
		: q(q1), w(w1), e(e1) {}

	added_verilog_aux_call_outputs(const added_verilog_aux_call_outputs& other)
	{
		if (this != &other)
		{
			this->q = other.q;	this->w = other.w;
			this->e = other.e;
		}
	}
	~added_verilog_aux_call_outputs()
	{
		this->q.clear();	this->w = NULL;
		this->e.clear();
	}
	void operator=(GeneralFact& other) override
	{
		added_verilog_aux_call_outputs* ptr = dynamic_cast<added_verilog_aux_call_outputs*>(&other);
		this->q = ptr->q;	this->w = ptr->w;
		this->e = ptr->e;
	}

	added_verilog_aux_call_outputs(added_verilog_aux_call_outputs&& other)  noexcept
		: q{ other.q }, w{ other.w }, e{ other.e } {}

	void operator=(added_verilog_aux_call_outputs&& other)  noexcept
	{
		std::swap(q, other.q);	std::swap(w, other.w);
		std::swap(e, other.e);
	}
	friend string makeStringOf(GeneralFact* obj);

	friend size_t matchfactsstar(GeneralFact* Treesfact, factstar* obj);

	friend size_t matchfactsSpec(GeneralFact* otherf, factUnderInspection* obj);
};

//vector
class raw_dependencies : public GeneralFact
{
	int				w{};
	string			q{};
	vector<int>		e{}, r{};
public:
	raw_dependencies(const string q1, const int w1, const vector<int> e1, const vector<int> r1)
		: q(q1), w(w1), e(e1), r(r1) {
		e.shrink_to_fit();
		r.shrink_to_fit();
	}
	raw_dependencies(const raw_dependencies& other)
	{
		if (this != &other)
		{
			this->q = other.q;	this->w = other.w;
			this->e = other.e;  this->r = other.r;
		}
	}
	~raw_dependencies()
	{
		this->q.clear();this->w = NULL;
		this->e.clear();this->r.clear();
	}
	void operator=(GeneralFact& other) override
	{
		raw_dependencies* ptr = dynamic_cast<raw_dependencies*>(&other);
		this->q = ptr->q;	this->w = ptr->w;
		this->e = ptr->e;	this->r = ptr->r;
	}

	raw_dependencies(raw_dependencies&& other)  noexcept
		: q{ other.q }, w{ other.w },
		e{ other.e }, r{ other.r } {}

	void operator=(raw_dependencies&& other)  noexcept
	{
		std::swap(q, other.q);	std::swap(w, other.w);
		std::swap(e, other.e);	std::swap(r, other.r);
	}
	friend string makeStringOf(GeneralFact* obj);

	friend size_t matchfactsstar(GeneralFact* Treesfact, factstar* obj);

	friend size_t matchfactsSpec(GeneralFact* otherf, factUnderInspection* obj);
};

//vector
class war_dependencies : public GeneralFact
{
	int				w{};
	string			q{};
	vector<int>		e{}, r{};
public:
	war_dependencies(const string q1, const int w1, const vector<int> e1, const vector<int> r1)
		: q(q1), w(w1), e(e1), r(r1) {
		e.shrink_to_fit();
		r.shrink_to_fit();
	}
	war_dependencies(const war_dependencies& other)
	{
		if (this != &other)
		{
			this->q = other.q;	this->w = other.w;
			this->e = other.e;  this->r = other.r;
		}
	}
	~war_dependencies()
	{
		this->q.clear(); this->w = NULL;
		this->e.clear(); this->r.clear();
	}
	void operator=(GeneralFact& other) override
	{
		war_dependencies* ptr = dynamic_cast<war_dependencies*>(&other);
		this->q = ptr->q;	this->w = ptr->w;
		this->e = ptr->e;	this->r = ptr->r;
	}

	war_dependencies(war_dependencies&& other)  noexcept
		: q{ other.q }, w{ other.w },
		e{ other.e }, r{ other.r } {}

	void operator=(war_dependencies&& other)  noexcept
	{
		std::swap(q, other.q);	std::swap(w, other.w);
		std::swap(e, other.e);	std::swap(r, other.r);
	}
	friend string makeStringOf(GeneralFact* obj);

	friend size_t matchfactsstar(GeneralFact* Treesfact, factstar* obj);

	friend size_t matchfactsSpec(GeneralFact* otherf, factUnderInspection* obj);
};

//vector
class waw_dependencies : public GeneralFact
{
	int				w{};
	string			q{};
	vector<int>		e{}, r{};
public:
	waw_dependencies(const string q1, const int w1, const vector<int> e1, const vector<int> r1)
		: q(q1), w(w1), e(e1), r(r1) {
		e.shrink_to_fit();
		r.shrink_to_fit();
	}
	waw_dependencies(const waw_dependencies& other)
	{
		if (this != &other)
		{
			this->q = other.q;	this->w = other.w;
			this->e = other.e;  this->r = other.r;
		}
	}
	~waw_dependencies()
	{
		this->q.clear(); this->w = NULL;
		this->e.clear(); this->r.clear();
	}
	void operator=(GeneralFact& other) override
	{
		waw_dependencies* ptr = dynamic_cast<waw_dependencies*>(&other);
		this->q = ptr->q;	this->w = ptr->w;
		this->e = ptr->e;	this->r = ptr->r;
	}

	waw_dependencies(waw_dependencies&& other)  noexcept
		: q{ other.q }, w{ other.w },
		e{ other.e }, r{ other.r } {}

	void operator=(waw_dependencies&& other)  noexcept
	{
		std::swap(q, other.q);	std::swap(w, other.w);
		std::swap(e, other.e);	std::swap(r, other.r);
	}
	friend string makeStringOf(GeneralFact* obj);

	friend size_t matchfactsstar(GeneralFact* Treesfact, factstar* obj);

	friend size_t matchfactsSpec(GeneralFact* otherf, factUnderInspection* obj);
};

class schedule : public GeneralFact
{
	int				w{}, r{};
	string			q{}, e{};
public:
	schedule(const string q1, const int w1, const string e1, const int r1)
		: q(q1), w(w1), e(e1), r(r1) {}

	schedule(const schedule& other)
	{
		if (this != &other)
		{
			this->q = other.q;	this->w = other.w;
			this->e = other.e;  this->r = other.r;
		}
	}
	~schedule()
	{
		this->q.clear();this->w = NULL;
		this->e.clear();this->r = NULL;

	}
	void operator=(GeneralFact& other) override
	{
		schedule* ptr = dynamic_cast<schedule*>(&other);
		this->q = ptr->q;	this->w = ptr->w;
		this->e = ptr->e;  this->r = ptr->r;
	}

	schedule(schedule&& other)  noexcept
		: q{ other.q }, w{ other.w },
		e{ other.e }, r{ other.r } {}

	void operator=(schedule&& other)  noexcept
	{
		std::swap(q, other.q);	std::swap(w, other.w);
		std::swap(e, other.e);	std::swap(r, other.r);
	}
	friend string makeStringOf(GeneralFact* obj);

	friend size_t matchfactsstar(GeneralFact* Treesfact, factstar* obj);

	friend size_t matchfactsSpec(GeneralFact* otherf, factUnderInspection* obj);
};

class last_conditional_execution : public GeneralFact
{
	int				w{};
	string			q{};
public:
	last_conditional_execution(const string q1, const int w1)
		: q(q1), w(w1) {}

	last_conditional_execution(const last_conditional_execution& other)
	{
		if (this != &other)
		{
			this->q = other.q;	this->w = other.w;
		}
	}
	~last_conditional_execution()
	{
		this->q.clear();this->w = NULL;

	}
	void operator=(GeneralFact& other) override
	{
		last_conditional_execution* ptr = dynamic_cast<last_conditional_execution*>(&other);
		this->q = ptr->q;	this->w = ptr->w;

	}

	last_conditional_execution(last_conditional_execution&& other)  noexcept
		: q{ other.q }, w{ other.w } {}

	void operator=(last_conditional_execution&& other)  noexcept
	{
		std::swap(q, other.q);	std::swap(w, other.w);
	}
	friend string makeStringOf(GeneralFact* obj);

	friend size_t matchfactsstar(GeneralFact* Treesfact, factstar* obj);

	friend size_t matchfactsSpec(GeneralFact* otherf, factUnderInspection* obj);
};

//vector
class conditional_operations : public GeneralFact
{
	int				e{}, r{};
	string			q{}, w{};
	vector<int>		t{}, y{}, u{}, i{};
public:
	conditional_operations(const string q1, const string w1, const int e1, const int r1, const vector<int> t1, const vector<int> y1,
		const vector<int> u1, const vector<int> i1)
		: q(q1), w(w1), e(e1), r(r1), t(t1), y(y1), u(u1), i(i1) {
		t.shrink_to_fit();
		y.shrink_to_fit();
		u.shrink_to_fit();
		i.shrink_to_fit();
	}
	conditional_operations(const conditional_operations& other)
	{
		if (this != &other)
		{
			this->q = other.q;	this->w = other.w;
			this->e = other.e;	this->r = other.r;
			this->t = other.t;	this->y = other.y;
			this->u = other.u;	this->i = other.i;
		}
	}
	~conditional_operations()
	{
		this->q.clear();	this->w.clear();
		this->e = NULL;		this->r = NULL;
		this->t.clear();	this->y.clear();
		this->u.clear();	this->i.clear();

	}
	void operator=(GeneralFact& other) override
	{
		conditional_operations* ptr = dynamic_cast<conditional_operations*>(&other);
		this->q = ptr->q;	this->w = ptr->w;
		this->e = ptr->e;	this->r = ptr->r;
		this->t = ptr->t;	this->y = ptr->y;
		this->u = ptr->u;	this->i = ptr->i;
	}

	conditional_operations(conditional_operations&& other)  noexcept
		: q{ other.q }, w{ other.w }, e{ other.e }, r{ other.r },
		t{ other.t }, y{ other.y }, u{ other.u }, i{ other.i }{}

	void operator=(conditional_operations&& other)  noexcept
	{
		std::swap(q, other.q);	std::swap(w, other.w);
		std::swap(e, other.e);	std::swap(r, other.r);
		std::swap(t, other.t);	std::swap(y, other.y);
		std::swap(u, other.u);	std::swap(i, other.i);
	}
	friend string makeStringOf(GeneralFact* obj);

	friend size_t matchfactsstar(GeneralFact* Treesfact, factstar* obj);

	friend size_t matchfactsSpec(GeneralFact* otherf, factUnderInspection* obj);
};

class last_conditional_transition_of_schedule : public GeneralFact
{
	int				e{};
	string			q{}, w{};
public:
	last_conditional_transition_of_schedule(const string q1, const string w1, const int e1)
		: q(q1), w(w1), e(e1) {}

	last_conditional_transition_of_schedule(const last_conditional_transition_of_schedule& other)
	{
		if (this != &other)
		{
			this->q = other.q;	this->w = other.w;
			this->e = other.e;
		}
	}
	~last_conditional_transition_of_schedule()
	{
		this->q.clear();this->w.clear();
		this->e = NULL;

	}
	void operator=(GeneralFact& other) override
	{
		last_conditional_transition_of_schedule* ptr = dynamic_cast<last_conditional_transition_of_schedule*>(&other);
		this->q = ptr->q;	this->w = ptr->w;
		this->e = ptr->e;
	}

	last_conditional_transition_of_schedule(last_conditional_transition_of_schedule&& other)  noexcept
		: q{ other.q }, w{ other.w }, e{ other.e } {}

	void operator=(last_conditional_transition_of_schedule&& other)  noexcept
	{
		std::swap(q, other.q);	std::swap(w, other.w);
		std::swap(e, other.e);
	}
	friend string makeStringOf(GeneralFact* obj);

	friend size_t matchfactsstar(GeneralFact* Treesfact, factstar* obj);

	friend size_t matchfactsSpec(GeneralFact* otherf, factUnderInspection* obj);
};

class transition_to_be_rescheduled : public GeneralFact
{
	int				e{}, t{};
	string			q{}, w{}, r{};
public:
	transition_to_be_rescheduled(const string w1, const int e1, const string q1, const string r1, const int t1)
		:w(w1), e(e1), q(q1), r(r1), t(t1) {}

	transition_to_be_rescheduled(const transition_to_be_rescheduled& other)
	{
		if (this != &other)
		{
			this->q = other.q;	this->r = other.r;
			this->w = other.w;	this->e = other.e;
			this->t = other.t;
		}
	}
	~transition_to_be_rescheduled()
	{
		this->q.clear();	this->r.clear();
		this->w.clear();	this->e = NULL;
		this->t = NULL;

	}
	void operator=(GeneralFact& other) override
	{
		transition_to_be_rescheduled* ptr = dynamic_cast<transition_to_be_rescheduled*>(&other);
		this->q = ptr->q;	this->r = ptr->r;
		this->w = ptr->w;	this->e = ptr->e;
		this->t = ptr->t;
	}
	transition_to_be_rescheduled(transition_to_be_rescheduled&& other)  noexcept
		: q{ other.q }, e{ other.e }, w{ other.w }, r{ other.r }, t{other.t} {}
	void operator=(transition_to_be_rescheduled&& other)  noexcept
	{
		std::swap(q, other.q); std::swap(e, other.e); std::swap(w, other.w); std::swap(r, other.r), std::swap(t, other.t);
	}
	friend string makeStringOf(GeneralFact* obj);

	friend size_t matchfactsstar(GeneralFact* Treesfact, factstar* obj);

	friend size_t matchfactsSpec(GeneralFact* otherf, factUnderInspection* obj);
};

class last_conditional_transition : public GeneralFact
{
	int				w{};
	string			q{};
public:
	last_conditional_transition(const string q1, const int w1)
		: q(q1), w(w1) {}

	last_conditional_transition(const last_conditional_transition& other)
	{
		if (this != &other)
		{
			this->q = other.q;	this->w = other.w;
		}
	}
	~last_conditional_transition()
	{
		this->q.clear();this->w = NULL;

	}
	void operator=(GeneralFact& other) override
	{
		last_conditional_transition* ptr = dynamic_cast<last_conditional_transition*>(&other);
		this->q = ptr->q;	this->w = ptr->w;

	}

	last_conditional_transition(last_conditional_transition&& other)  noexcept
		: q{ other.q }, w{ other.w } {}

	void operator=(last_conditional_transition&& other)  noexcept
	{
		std::swap(q, other.q);	std::swap(w, other.w);
	}
	friend string makeStringOf(GeneralFact* obj);

	friend size_t matchfactsstar(GeneralFact* Treesfact, factstar* obj);

	friend size_t matchfactsSpec(GeneralFact* otherf, factUnderInspection* obj);
};

class conditional_transitions : public GeneralFact
{
	int				e{}, r{}, t{}, y{}, u{}, i{};
	string			q{}, w{};
public:
	conditional_transitions(const string q1, const string w1, const int e1, const int r1, const int t1, const int y1,
		const int u1, const int i1)
		: q(q1), w(w1), e(e1), r(r1), t(t1), y(y1), u(u1), i(i1) {}

	conditional_transitions(const conditional_transitions& other)
	{
		if (this != &other)
		{
			this->q = other.q;	this->w = other.w;
			this->e = other.e;	this->r = other.r;
			this->t = other.t;	this->y = other.y;
			this->u = other.u;	this->i = other.i;
		}
	}
	~conditional_transitions()
	{
		this->q.clear();	this->w.clear();
		this->e = NULL;	this->r = NULL;
		this->t = NULL;	this->y = NULL;
		this->u = NULL;	this->i = NULL;

	}
	void operator=(GeneralFact& other) override
	{
		conditional_transitions* ptr = dynamic_cast<conditional_transitions*>(&other);
		this->q = ptr->q;	this->w = ptr->w;
		this->e = ptr->e;	this->r = ptr->r;
		this->t = ptr->t;	this->y = ptr->y;
		this->u = ptr->u;	this->i = ptr->i;
	}

	conditional_transitions(conditional_transitions&& other)  noexcept
		: q{ other.q }, w{ other.w }, e{ other.e }, r{ other.r },
		t{ other.t }, y{ other.y }, u{ other.u }, i{ other.i } {}

	void operator=(conditional_transitions&& other)  noexcept
	{
		std::swap(q, other.q);	std::swap(w, other.w);
		std::swap(e, other.e);	std::swap(r, other.r);
		std::swap(t, other.t);	std::swap(y, other.y);
		std::swap(u, other.u);	std::swap(i, other.i);
	}
	friend string makeStringOf(GeneralFact* obj);

	friend size_t matchfactsstar(GeneralFact* Treesfact, factstar* obj);

	friend size_t matchfactsSpec(GeneralFact* otherf, factUnderInspection* obj);
};

//vector
class state : public GeneralFact
{
	int				e{}, t{}, y{};
	string			q{}, w{}, r{};
	vector<int>		u{}, i{};
public:
	state(const string q1, const string w1, const int e1, const string r1, const int t1, const int y1,
		const vector<int> u1, const vector<int> i1)
		: q(q1), w(w1), e(e1), r(r1), t(t1), y(y1), u(u1), i(i1) {
		u.shrink_to_fit();
		i.shrink_to_fit();
	}

	state(const state& other)
	{
		if (this != &other)
		{
			this->q = other.q;	this->w = other.w;
			this->e = other.e;	this->r = other.r;
			this->t = other.t;	this->y = other.y;
			this->u = other.u;	this->i = other.i;
		}
	}
	~state()
	{
		this->q.clear();	this->w.clear();
		this->e = NULL;		this->r.clear();
		this->t = NULL;		this->y = NULL;
		this->u.clear();	this->i.clear();

	}
	void operator=(GeneralFact& other) override
	{
		state* ptr = dynamic_cast<state*>(&other);
		this->q = ptr->q;	this->w = ptr->w;
		this->e = ptr->e;	this->r = ptr->r;
		this->t = ptr->t;	this->y = ptr->y;
		this->u = ptr->u;	this->i = ptr->i;
	}

	state(state&& other)  noexcept
		: q{ other.q }, w{ other.w }, e{ other.e }, r{ other.r },
		t{ other.t }, y{ other.y }, u{ other.u }, i{ other.i } {}

	void operator=(state&& other)  noexcept
	{
		std::swap(q, other.q);	std::swap(w, other.w);
		std::swap(e, other.e);	std::swap(r, other.r);
		std::swap(t, other.t);	std::swap(y, other.y);
		std::swap(u, other.u);	std::swap(i, other.i);
	}
	friend string makeStringOf(GeneralFact* obj);

	friend size_t matchfactsstar(GeneralFact* Treesfact, factstar* obj);

	friend size_t matchfactsSpec(GeneralFact* otherf, factUnderInspection* obj);
};

class rescheduled : public GeneralFact
{
	int				e{}, t{};
	string			q{}, w{}, r{};
public:
	rescheduled(const string w1, const int e1, const string q1, const string r1, const int t1)
		:w(w1), e(e1), q(q1), r(r1), t(t1) {}
	rescheduled(const rescheduled& other)
	{
		if (this != &other)
		{
			this->q = other.q;	this->r = other.r;
			this->w = other.w;	this->e = other.e;
			this->t = other.t;
		}
	}
	~rescheduled()
	{
		this->q.clear();	this->r.clear();
		this->w.clear();	this->e = NULL;
		this->t = NULL;

	}
	void operator=(GeneralFact& other) override
	{
		rescheduled* ptr = dynamic_cast<rescheduled*>(&other);
		this->q = ptr->q;	this->r = ptr->r;
		this->w = ptr->w;	this->e = ptr->e;
		this->t = ptr->t;
	}
	rescheduled(rescheduled&& other)  noexcept
		: q{ other.q }, e{ other.e }, w{ other.w }, r{ other.r }, t{ other.t } {}
	void operator=(rescheduled&& other)  noexcept
	{
		std::swap(q, other.q); std::swap(e, other.e); std::swap(w, other.w); std::swap(r, other.r), std::swap(t, other.t);
	}
	friend string makeStringOf(GeneralFact* obj);

	friend size_t matchfactsstar(GeneralFact* Treesfact, factstar* obj);

	friend size_t matchfactsSpec(GeneralFact* otherf, factUnderInspection* obj);
};

class last_rescheduled : public GeneralFact
{
	int				e{}, t{};
	string			q{}, w{}, r{};
public:
	last_rescheduled(const string w1, const int e1, const string q1, const string r1, const int t1)
		:w(w1), e(e1), q(q1), r(r1), t(t1) {}
	last_rescheduled(const last_rescheduled& other)
	{
		if (this != &other)
		{
			this->q = other.q;	this->r = other.r;
			this->w = other.w;	this->e = other.e;
			this->t = other.t;
		}
	}
	~last_rescheduled()
	{
		this->q.clear();	this->r.clear();
		this->w.clear();	this->e = NULL;
		this->t = NULL;

	}
	void operator=(GeneralFact& other) override
	{
		last_rescheduled* ptr = dynamic_cast<last_rescheduled*>(&other);
		this->q = ptr->q;	this->r = ptr->r;
		this->w = ptr->w;	this->e = ptr->e;
		this->t = ptr->t;
	}
	last_rescheduled(last_rescheduled&& other)  noexcept
		: q{ other.q }, e{ other.e }, w{ other.w }, r{ other.r }, t{ other.t } {}
	void operator=(last_rescheduled&& other)  noexcept
	{
		std::swap(q, other.q); std::swap(e, other.e); std::swap(w, other.w); std::swap(r, other.r), std::swap(t, other.t);
	}
	friend string makeStringOf(GeneralFact* obj);

	friend size_t matchfactsstar(GeneralFact* Treesfact, factstar* obj);

	friend size_t matchfactsSpec(GeneralFact* otherf, factUnderInspection* obj);
};

class raw_cessor : public GeneralFact
{
	int				w{}, e{};
	string			q{};
public:
	raw_cessor(const string q1, const int w1, const int e1)
		: q(q1), w(w1), e(e1) {}

	raw_cessor(const raw_cessor& other)
	{
		if (this != &other)
		{
			this->q = other.q;	this->w = other.w;
			this->e = other.e;
		}
	}
	~raw_cessor()
	{
		this->q.clear();	this->w = NULL;
		this->e = NULL;
	}
	void operator=(GeneralFact& other) override
	{
		raw_cessor* ptr = dynamic_cast<raw_cessor*>(&other);
		this->q = ptr->q;	this->w = ptr->w;
		this->e = ptr->e;
	}

	raw_cessor(raw_cessor&& other)  noexcept
		: q{ other.q }, w{ other.w }, e{ other.e } {}

	void operator=(raw_cessor&& other)  noexcept
	{
		std::swap(q, other.q);	std::swap(w, other.w);
		std::swap(e, other.e);
	}
	friend string makeStringOf(GeneralFact* obj);

	friend size_t matchfactsstar(GeneralFact* Treesfact, factstar* obj);

	friend size_t matchfactsSpec(GeneralFact* otherf, factUnderInspection* obj);
};

class war_cessor : public GeneralFact
{
	int				w{}, e{};
	string			q{};
public:
	war_cessor(const string q1, const int w1, const int e1)
		: q(q1), w(w1), e(e1) {}

	war_cessor(const war_cessor& other)
	{
		if (this != &other)
		{
			this->q = other.q;	this->w = other.w;
			this->e = other.e;
		}
	}
	~war_cessor()
	{
		this->q.clear();	this->w = NULL;
		this->e = NULL;
	}
	void operator=(GeneralFact& other) override
	{
		war_cessor* ptr = dynamic_cast<war_cessor*>(&other);
		this->q = ptr->q;	this->w = ptr->w;
		this->e = ptr->e;
	}

	war_cessor(war_cessor&& other)  noexcept
		: q{ other.q }, w{ other.w }, e{ other.e } {}

	void operator=(war_cessor&& other)  noexcept
	{
		std::swap(q, other.q);	std::swap(w, other.w);
		std::swap(e, other.e);
	}
	friend string makeStringOf(GeneralFact* obj);

	friend size_t matchfactsstar(GeneralFact* Treesfact, factstar* obj);

	friend size_t matchfactsSpec(GeneralFact* otherf, factUnderInspection* obj);
};

class waw_cessor : public GeneralFact
{
	int				w{}, e{};
	string			q{};
public:
	waw_cessor(const string q1, const int w1, const int e1)
		: q(q1), w(w1), e(e1) {}

	waw_cessor(const waw_cessor& other)
	{
		if (this != &other)
		{
			this->q = other.q;	this->w = other.w;
			this->e = other.e;
		}
	}
	~waw_cessor()
	{
		this->q.clear();	this->w = NULL;
		this->e = NULL;
	}
	void operator=(GeneralFact& other) override
	{
		waw_cessor* ptr = dynamic_cast<waw_cessor*>(&other);
		this->q = ptr->q;	this->w = ptr->w;
		this->e = ptr->e;
	}

	waw_cessor(waw_cessor&& other)  noexcept
		: q{ other.q }, w{ other.w }, e{ other.e } {}

	void operator=(waw_cessor&& other)  noexcept
	{
		std::swap(q, other.q);	std::swap(w, other.w);
		std::swap(e, other.e);
	}
	friend string makeStringOf(GeneralFact* obj);

	friend size_t matchfactsstar(GeneralFact* Treesfact, factstar* obj);

	friend size_t matchfactsSpec(GeneralFact* otherf, factUnderInspection* obj);
};

class op_resource : public GeneralFact
{
	int				e{};
	string			q{}, w{};
public:
	op_resource(const string q1, const string w1, const int e1)
		: q(q1), w(w1), e(e1) {}
	op_resource(const op_resource& other)
	{
		if (this != &other)
		{
			this->q = other.q;	this->w = other.w;
			this->e = other.e;
		}
	}
	~op_resource()
	{
		this->q.clear();	this->w.clear();
		this->e = NULL;
	}
	void operator=(GeneralFact& other) override
	{
		op_resource* ptr = dynamic_cast<op_resource*>(&other);
		this->q = ptr->q;	this->w = ptr->w;
		this->e = ptr->e;
	}

	op_resource(op_resource&& other)  noexcept
		: q{ other.q }, w{ other.w }, e{ other.e } {}

	void operator=(op_resource&& other)  noexcept
	{
		std::swap(q, other.q);	std::swap(w, other.w);
		std::swap(e, other.e);
	}
	friend string makeStringOf(GeneralFact* obj);

	friend size_t matchfactsstar(GeneralFact* Treesfact, factstar* obj);

	friend size_t matchfactsSpec(GeneralFact* otherf, factUnderInspection* obj);
};

class global_resource : public GeneralFact
{
	int				q{};
public:
	global_resource(const int q1)
		: q(q1) {}

	global_resource(const global_resource& other)
	{
		if (this != &other)
		{
			this->q = other.q;
		}
	}
	~global_resource()
	{
		this->q = NULL;
	}
	void operator=(GeneralFact& other) override
	{
		global_resource* ptr = dynamic_cast<global_resource*>(&other);
		this->q = ptr->q;
	}

	global_resource(global_resource&& other)  noexcept
		: q{ other.q } {}

	void operator=(global_resource&& other)  noexcept
	{
		std::swap(q, other.q);
	}
	friend string makeStringOf(GeneralFact* obj);

	friend size_t matchfactsstar(GeneralFact* Treesfact, factstar* obj);

	friend size_t matchfactsSpec(GeneralFact* otherf, factUnderInspection* obj);
};

class module_g_resource : public GeneralFact
{
	int				w{};
	string			q{};
public:
	module_g_resource(const string q1, const int w1)
		: q(q1), w(w1) {}

	module_g_resource(const module_g_resource& other)
	{
		if (this != &other)
		{
			this->q = other.q;	this->w = other.w;
		}
	}
	~module_g_resource()
	{
		this->q.clear();	this->w = NULL;
	}
	void operator=(GeneralFact& other) override
	{
		module_g_resource* ptr = dynamic_cast<module_g_resource*>(&other);
		this->q = ptr->q;	this->w = ptr->w;

	}

	module_g_resource(module_g_resource&& other)  noexcept
		: q{ other.q }, w{ other.w } {}

	void operator=(module_g_resource&& other) noexcept
	{
		std::swap(q, other.q);	std::swap(w, other.w);
	}
	friend string makeStringOf(GeneralFact* obj);

	friend size_t matchfactsstar(GeneralFact* Treesfact, factstar* obj);

	friend size_t matchfactsSpec(GeneralFact* otherf, factUnderInspection* obj);
};

class cf_previous_op : public GeneralFact
{
	int				w{}, e{}, r{};
	string			q{};	
public:
	cf_previous_op(const string q1, const int w1, const int e1, const int r1)
		: q(q1), w(w1), e(e1), r(r1) {}

	cf_previous_op(const cf_previous_op& other)
	{
		if (this != &other)
		{
			this->q = other.q;	this->w = other.w;
			this->e = other.e;  this->r = other.r;
		}
	}
	~cf_previous_op()
	{
		this->q.clear();this->w = NULL;
		this->e = NULL; this->r = NULL;

	}
	void operator=(GeneralFact& other) override
	{
		cf_previous_op* ptr = dynamic_cast<cf_previous_op*>(&other);
		this->q = ptr->q;	this->w = ptr->w;
		this->e = ptr->e;	this->r = ptr->r;
	}

	cf_previous_op(cf_previous_op&& other) noexcept
		: q{ other.q }, w{ other.w },
		e{ other.e }, r{ other.r } {}

	void operator=(cf_previous_op&& other) noexcept
	{
		std::swap(q, other.q);	std::swap(w, other.w);
		std::swap(e, other.e);	std::swap(r, other.r);
	}
	friend string makeStringOf(GeneralFact* obj);

	friend size_t matchfactsstar(GeneralFact* Treesfact, factstar* obj);

	friend size_t matchfactsSpec(GeneralFact* otherf, factUnderInspection* obj);
};

class cf_previous_state : public GeneralFact
{
	int				w{}, e{}, r{};
	string			q{};
public:
	cf_previous_state(const string q1, const int w1, const int e1, const int r1)
		: q(q1), w(w1), e(e1), r(r1) {}

	cf_previous_state(const cf_previous_state& other)
	{
		if (this != &other)
		{
			this->q = other.q;	this->w = other.w;
			this->e = other.e;  this->r = other.r;
		}
	}
	~cf_previous_state()
	{
		this->q.clear(); this->w = NULL;
		this->e = NULL; this->r = NULL;
	}
	void operator=(GeneralFact& other) override
	{
		cf_previous_state* ptr = dynamic_cast<cf_previous_state*>(&other);
		this->q = ptr->q;	this->w = ptr->w;
		this->e = ptr->e;  this->r = ptr->r;
	}

	cf_previous_state(cf_previous_state&& other) noexcept
		: q{ other.q }, w{ other.w },
		e{ other.e }, r{ other.r } {}

	void operator=(cf_previous_state&& other) noexcept
	{
		std::swap(q, other.q);	std::swap(w, other.w);
		std::swap(e, other.e);	std::swap(r, other.r);
	}
	friend string makeStringOf(GeneralFact* obj);

	friend size_t matchfactsstar(GeneralFact* Treesfact, factstar* obj);

	friend size_t matchfactsSpec(GeneralFact* otherf, factUnderInspection* obj);
};

class pred_candidate_examined : public GeneralFact
{
	int				w{}, e{};
	string			q{};
public:
	pred_candidate_examined(const string q1, const int w1, const int e1)
		: q(q1), w(w1), e(e1) {}

	pred_candidate_examined(const pred_candidate_examined& other)
	{
		if (this != &other)
		{
			this->q = other.q;	this->w = other.w;
			this->e = other.e;
		}
	}
	~pred_candidate_examined()
	{
		this->q.clear();this->w = NULL;
		this->e = NULL;
	}
	void operator=(GeneralFact& other) override
	{
		pred_candidate_examined* ptr = dynamic_cast<pred_candidate_examined*>(&other);
		this->q = ptr->q;	this->w = ptr->w;
		this->e = ptr->e;
	}

	pred_candidate_examined(pred_candidate_examined&& other) noexcept
		: q{ other.q }, w{ other.w }, e{ other.e } {}

	void operator=(pred_candidate_examined&& other) noexcept
	{
		std::swap(q, other.q);	std::swap(w, other.w);
		std::swap(e, other.e);
	}
	friend string makeStringOf(GeneralFact* obj);

	friend size_t matchfactsstar(GeneralFact* Treesfact, factstar* obj);

	friend size_t matchfactsSpec(GeneralFact* otherf, factUnderInspection* obj);
};

//vector
class reentrant_triangle : public GeneralFact
{
	int				w{}, e{}, r{}, a{}, s{};
	string			q{}, d{}, f{};
	vector<int>		t{}, y{}, u{}, i{}, o{}, p{};
public:
	reentrant_triangle(const string q1, const int w1, const int e1, const int r1, const vector<int> t1, const vector<int> y1,
		const vector<int> u1, const vector<int> i1, const vector<int> o1, const vector<int> p1, const int a1, const int s1, const string d1, const string f1)
		: q(q1), w(w1), e(e1), r(r1), t(t1), y(y1), u(u1), i(i1), o(o1), p(p1), a(a1), s(s1), d(d1), f(f1) {
		t.shrink_to_fit();
		y.shrink_to_fit();
		u.shrink_to_fit();
		i.shrink_to_fit();
		o.shrink_to_fit();
		p.shrink_to_fit();
	}

	reentrant_triangle(const reentrant_triangle& other)
	{
		if (this != &other)
		{
			this->q = other.q;	this->w = other.w;
			this->e = other.e;	this->r = other.r;
			this->t = other.t;	this->y = other.y;
			this->u = other.u;	this->i = other.i;
			this->o = other.o;	this->p = other.p;
			this->a = other.a;	this->s = other.s;
			this->d = other.d;	this->f = other.f;
		}
	}
	~reentrant_triangle()
	{
		this->q.clear();this->w = NULL;
		this->e = NULL;	this->r = NULL;
		this->t.clear();this->y.clear();
		this->u.clear();this->i.clear();
		this->o.clear();this->p.clear();
		this->a = NULL;	this->s = NULL;
		this->d.clear();this->f.clear();

	}
	void operator=(GeneralFact& other) override
	{
		reentrant_triangle* ptr = dynamic_cast<reentrant_triangle*>(&other);
		this->q = ptr->q;	this->w = ptr->w;
		this->e = ptr->e;	this->r = ptr->r;
		this->t = ptr->t;	this->y = ptr->y;
		this->u = ptr->u;	this->i = ptr->i;
		this->o = ptr->o;	this->p = ptr->p;
		this->a = ptr->a;	this->s = ptr->s;
		this->d = ptr->d;	this->f = ptr->f;
	}

	reentrant_triangle(reentrant_triangle&& other) noexcept
		: q{ other.q }, w{ other.w }, e{ other.e }, r{ other.r },
		t{ other.t }, y{ other.y }, u{ other.u }, i{ other.i },
		o{ other.o }, p{ other.p }, a{ other.a }, s{ other.s },
		d{ other.d }, f{ other.f } {}

	void operator=(reentrant_triangle&& other) noexcept
	{
		std::swap(q, other.q);	std::swap(w, other.w);
		std::swap(e, other.e);	std::swap(r, other.r);
		std::swap(t, other.t);	std::swap(y, other.y);
		std::swap(u, other.u);	std::swap(i, other.i);
		std::swap(o, other.o);	std::swap(p, other.p);
		std::swap(a, other.a);	std::swap(s, other.s);
		std::swap(d, other.d);  std::swap(f, other.f);
	}
	friend string makeStringOf(GeneralFact* obj);

	friend size_t matchfactsstar(GeneralFact* Treesfact, factstar* obj);

	friend size_t matchfactsSpec(GeneralFact* otherf, factUnderInspection* obj);
};

class last_reentrant_triangle : public GeneralFact
{
	int				w{};
	string			q{};
public:
	last_reentrant_triangle(const string q1, const int w1)
		: q(q1), w(w1) {}

	last_reentrant_triangle(const last_reentrant_triangle& other)
	{
		if (this != &other)
		{
			this->q = other.q;	this->w = other.w;
		}
	}
	~last_reentrant_triangle()
	{
		this->q.clear();this->w = NULL;

	}
	void operator=(GeneralFact& other) override
	{
		last_reentrant_triangle* ptr = dynamic_cast<last_reentrant_triangle*>(&other);
		this->q = ptr->q;	this->w = ptr->w;

	}

	last_reentrant_triangle(last_reentrant_triangle&& other) noexcept
		: q{ other.q }, w{ other.w } {}

	void operator=(last_reentrant_triangle&& other) noexcept
	{
		std::swap(q, other.q);	std::swap(w, other.w);
	}
	friend string makeStringOf(GeneralFact* obj);

	friend size_t matchfactsstar(GeneralFact* Treesfact, factstar* obj);

	friend size_t matchfactsSpec(GeneralFact* otherf, factUnderInspection* obj);
};

class last_schedule_state : public GeneralFact
{
	int				e{};
	string			q{}, w{};
public:
	last_schedule_state(const string q1, const string w1, const int e1)
		: q(q1), w(w1), e(e1) {}

	last_schedule_state(const last_schedule_state& other)
	{
		if (this != &other)
		{
			this->q = other.q;	this->w = other.w;
			this->e = other.e;
		}
	}
	~last_schedule_state()
	{
		this->q.clear();	this->w.clear();
		this->e = NULL;

	}
	void operator=(GeneralFact& other) override
	{
		last_schedule_state* ptr = dynamic_cast<last_schedule_state*>(&other);
		this->q = ptr->q;	this->w = ptr->w;
		this->e = ptr->e;
	}

	last_schedule_state(last_schedule_state&& other) noexcept
		: q{ other.q }, w{ other.w }, e{ other.e } {}

	void operator=(last_schedule_state&& other) noexcept
	{
		std::swap(q, other.q);	std::swap(w, other.w);
		std::swap(e, other.e);
	}
	friend string makeStringOf(GeneralFact* obj);

	friend size_t matchfactsstar(GeneralFact* Treesfact, factstar* obj);

	friend size_t matchfactsSpec(GeneralFact* otherf, factUnderInspection* obj);
};

//vector
class conditional_incomplete : public GeneralFact
{
	int				e{}, r{}, a{}, s{}, d{}, f{}, g{}, h{}, j{}, k{}, l{}, z{}, x{};
	string			q{}, w{};
	vector<int>		t{}, y{}, u{}, i{}, o{}, p{};
public:
	conditional_incomplete(const string q1, const string w1, const int e1, const int r1, const vector<int> t1, const vector<int> y1,
		const vector<int> u1, const vector<int> i1, const vector<int> o1, const vector<int> p1, const int a1, const int s1, const int d1,
		const int f1, const int g1, const int h1, const int j1, const int k1, const int l1, const int z1, const int x1)
		: q(q1), w(w1), e(e1), r(r1), t(t1), y(y1), u(u1), i(i1), o(o1), p(p1), a(a1), s(s1), d(d1), f(f1), g(g1), h(h1),
		j(j1), k(k1), l(l1), z(z1), x(x1) {
		t.shrink_to_fit();
		y.shrink_to_fit();
		u.shrink_to_fit();
		i.shrink_to_fit();
		o.shrink_to_fit();
		p.shrink_to_fit();
	}

	conditional_incomplete(const conditional_incomplete& other)
	{
		if (this != &other)
		{
			this->q = other.q;	this->w = other.w;
			this->e = other.e;	this->r = other.r;
			this->t = other.t;	this->y = other.y;
			this->u = other.u;	this->i = other.i;
			this->o = other.o;	this->p = other.p;
			this->a = other.a;	this->s = other.s;
			this->d = other.d;	this->f = other.f;
			this->g = other.g;	this->h = other.h;
			this->j = other.j;	this->k = other.k;
			this->l = other.l;	this->z = other.z;
			this->x = other.x;	
		}
	}
	~conditional_incomplete()
	{
		this->q.clear();this->w.clear();
		this->e = NULL;	this->r = NULL;
		this->t.clear();this->y.clear();
		this->u.clear();this->i.clear();
		this->o.clear();this->p.clear();
		this->a = NULL;	this->s = NULL;
		this->d = NULL;	this->f = NULL;
		this->g = NULL;	this->h = NULL;
		this->j = NULL;	this->k = NULL;
		this->l = NULL;	this->z = NULL;
		this->x = NULL;
	}
	void operator=(GeneralFact& other) override
	{
		conditional_incomplete* ptr = dynamic_cast<conditional_incomplete*>(&other);
		this->q = ptr->q;	this->w = ptr->w;
		this->e = ptr->e;	this->r = ptr->r;
		this->t = ptr->t;	this->y = ptr->y;
		this->u = ptr->u;	this->i = ptr->i;
		this->o = ptr->o;	this->p = ptr->p;
		this->a = ptr->a;	this->s = ptr->s;
		this->d = ptr->d;	this->f = ptr->f;
		this->g = ptr->g;	this->h = ptr->h;
		this->j = ptr->j;	this->k = ptr->k;
		this->l = ptr->l;	this->z = ptr->z;
		this->x = ptr->x;
	}

	conditional_incomplete(conditional_incomplete&& other) noexcept
		: q{ other.q }, w{ other.w }, e{ other.e }, r{ other.r },
		t{ other.t }, y{ other.y }, u{ other.u }, i{ other.i },
		o{ other.o }, p{ other.p }, a{ other.a }, s{ other.s },
		d{ other.d }, f{ other.f }, g{ other.g }, h{ other.h },
		j{ other.j }, k{ other.k }, l{ other.l }, z{ other.z },
		x{ other.x }{}

	void operator=(conditional_incomplete&& other) noexcept
	{
		std::swap(q, other.q);	std::swap(w, other.w);
		std::swap(e, other.e);	std::swap(r, other.r);
		std::swap(t, other.t);	std::swap(y, other.y);
		std::swap(u, other.u);	std::swap(i, other.i);
		std::swap(o, other.o);	std::swap(p, other.p);
		std::swap(a, other.a);	std::swap(s, other.s);
		std::swap(d, other.d);	std::swap(f, other.f);
		std::swap(g, other.g);	std::swap(h, other.h);
		std::swap(j, other.j);	std::swap(k, other.k);
		std::swap(l, other.l);	std::swap(z, other.z);
		std::swap(x, other.x);	
	}
	friend string makeStringOf(GeneralFact* obj);

	friend size_t matchfactsstar(GeneralFact* Treesfact, factstar* obj);

	friend size_t matchfactsSpec(GeneralFact* otherf, factUnderInspection* obj);
};

//vector
class mixed_incomplete_state_lists : public GeneralFact
{
	int				e{};
	string			q{}, w{};
	vector<int>		r{}, t{};
public:
	mixed_incomplete_state_lists(const string w1, const int e1, const string q1, const vector<int> r1, const vector<int> t1)
		:w(w1), e(e1), q(q1), r(r1), t(t1) {
		r.shrink_to_fit();
		t.shrink_to_fit();
	}
	mixed_incomplete_state_lists(const mixed_incomplete_state_lists& other)
	{
		if (this != &other)
		{
			this->q = other.q;	this->r = other.r;
			this->w = other.w;	this->e = other.e;
			this->t = other.t;
		}
	}
	~mixed_incomplete_state_lists()
	{
		this->q.clear();	this->r.clear();
		this->w.clear();	this->e = NULL;
		this->t.clear();
	}
	void operator=(GeneralFact& other) override
	{
		mixed_incomplete_state_lists* ptr = dynamic_cast<mixed_incomplete_state_lists*>(&other);
		this->q = ptr->q;	this->r = ptr->r;
		this->w = ptr->w;	this->e = ptr->e;
		this->t = ptr->t;
	}
	mixed_incomplete_state_lists(mixed_incomplete_state_lists&& other) noexcept
		: q{ other.q }, e{ other.e }, w{ other.w }, r{ other.r }, t{ other.t } {}
	void operator=(mixed_incomplete_state_lists&& other) noexcept
	{
		std::swap(q, other.q); std::swap(e, other.e); std::swap(w, other.w); std::swap(r, other.r), std::swap(t, other.t);
	}
	friend string makeStringOf(GeneralFact* obj);

	friend size_t matchfactsstar(GeneralFact* Treesfact, factstar* obj);

	friend size_t matchfactsSpec(GeneralFact* otherf, factUnderInspection* obj);
};

//vector
class linear_incomplete_node : public GeneralFact
{
	int			e{}, y{};
	string		q{}, w{};
	vector<int>	r{}, t{};
public:
	linear_incomplete_node(const string w1, const int e1, const string q1, const int y1, const vector<int> r1, const vector<int> t1)
		:w(w1), e(e1), q(q1), y(y1), r(r1), t(t1) {
		r.shrink_to_fit();
		t.shrink_to_fit();
	}
	linear_incomplete_node(const linear_incomplete_node& other)
	{
		if (this != &other)
		{
			this->q = other.q;	this->r = other.r;
			this->w = other.w;	this->e = other.e;
			this->t = other.t;  this->y = other.y;
		}
	}
	~linear_incomplete_node()
	{
		this->q.clear();	this->r.clear();
		this->w.clear();	this->e = NULL;
		this->t.clear();	this->y = NULL;

	}
	void operator=(GeneralFact& other) override
	{
		linear_incomplete_node* ptr = dynamic_cast<linear_incomplete_node*>(&other);
		this->q = ptr->q;	this->r = ptr->r;
		this->w = ptr->w;	this->e = ptr->e;
		this->t = ptr->t;   this->y = ptr->y;
	}
	linear_incomplete_node(linear_incomplete_node&& other) noexcept
		: q{ other.q }, e{ other.e }, w{ other.w }, r{ other.r }, t{ other.t } {}
	void operator=(linear_incomplete_node&& other) noexcept
	{
		std::swap(q, other.q); std::swap(e, other.e); std::swap(w, other.w); std::swap(r, other.r), std::swap(t, other.t);
	}
	friend string makeStringOf(GeneralFact* obj);

	friend size_t matchfactsstar(GeneralFact* Treesfact, factstar* obj);

	friend size_t matchfactsSpec(GeneralFact* otherf, factUnderInspection* obj);
};

class incomplete_links : public GeneralFact
{
	int			q{}, w{}, e{}, r{}, t{}, y{}, u{}, i{}, o{}, p{};
public:
	incomplete_links(const int q1, const int w1, const int e1, const int r1, const int t1, const int y1,
		const int u1, const int i1, const int o1, const int p1)
		: q(q1), w(w1), e(e1), r(r1), t(t1), y(y1), u(u1), i(i1), o(o1), p(p1) {}

	incomplete_links(const incomplete_links& other)
	{
		if (this != &other)
		{
			this->q = other.q;	this->w = other.w;
			this->e = other.e;	this->r = other.r;
			this->t = other.t;	this->y = other.y;
			this->u = other.u;	this->i = other.i;
			this->o = other.o;	this->p = other.p;
		}
	}
	~incomplete_links()
	{
		this->q = NULL;	this->w = NULL;
		this->e = NULL;	this->r = NULL;
		this->t = NULL;	this->y = NULL;
		this->u = NULL;	this->i = NULL;
		this->o = NULL;	this->p = NULL;

	}
	void operator=(GeneralFact& other) override
	{
		incomplete_links* ptr = dynamic_cast<incomplete_links*>(&other);
		this->q = ptr->q;	this->w = ptr->w;
		this->e = ptr->e;	this->r = ptr->r;
		this->t = ptr->t;	this->y = ptr->y;
		this->u = ptr->u;	this->i = ptr->i;
		this->o = ptr->o;	this->p = ptr->p;
	}

	incomplete_links(incomplete_links&& other) noexcept
		: q{ other.q }, w{ other.w }, e{ other.e }, r{ other.r },
		t{ other.t }, y{ other.y }, u{ other.u }, i{ other.i },
		o{ other.o }, p{ other.p } {}

	void operator=(incomplete_links&& other) noexcept
	{
		std::swap(q, other.q);	std::swap(w, other.w);
		std::swap(e, other.e);	std::swap(r, other.r);
		std::swap(t, other.t);	std::swap(y, other.y);
		std::swap(u, other.u);	std::swap(i, other.i);
		std::swap(o, other.o);	std::swap(p, other.p);
	}
	friend string makeStringOf(GeneralFact* obj);

	friend size_t matchfactsstar(GeneralFact* Treesfact, factstar* obj);

	friend size_t matchfactsSpec(GeneralFact* otherf, factUnderInspection* obj);
};

class last_incomplete : public GeneralFact
{
	int				q{}, w{}, e{};
	string			r{};
public:
	last_incomplete(const int q1, const int w1, const int e1, const string r1)
		: q(q1), w(w1), e(e1), r(r1) {}
	last_incomplete(const last_incomplete& other)
	{
		if (this != &other)
		{
			this->q = other.q;	this->w = other.w;
			this->e = other.e;  this->r = other.r;
		}
	}
	~last_incomplete()
	{
		this->q = NULL;	this->w = NULL;
		this->e = NULL;  this->r.clear();

	}
	void operator=(GeneralFact& other) override
	{
		last_incomplete* ptr = dynamic_cast<last_incomplete*>(&other);
		this->q = ptr->q;	this->w = ptr->w;
		this->e = ptr->e;  this->r = ptr->r;
	}

	last_incomplete(last_incomplete&& other) noexcept
		: q{ other.q }, w{ other.w },
		e{ other.e }, r{ other.r } {}

	void operator=(last_incomplete&& other) noexcept
	{
		std::swap(q, other.q);	std::swap(w, other.w);
		std::swap(e, other.e);	std::swap(r, other.r);
	}
	friend string makeStringOf(GeneralFact* obj);

	friend size_t matchfactsstar(GeneralFact* Treesfact, factstar* obj);

	friend size_t matchfactsSpec(GeneralFact* otherf, factUnderInspection* obj);
};

class nil_node 
{
public:
	int				q{};
	string			w{};

	nil_node(const int q1, const string w1)
		: q(q1), w(w1) {}
	nil_node(const nil_node& other)
	{
		if (this != &other)
		{
			this->q = other.q;	this->w = other.w;
		}
	}
	~nil_node()
	{
		this->q = NULL;	this->w.clear();
	}
	void operator=(nil_node& other) 
	{
		this->q = other.q;	this->w = other.w;
	}

	nil_node(nil_node&& other) noexcept
		: q{ other.q }, w{ other.w } {}

	void operator=(nil_node&& other) noexcept
	{
		std::swap(q, other.q); std::swap(w, other.w);
	}
	bool operator==(nil_node other)
	{
		if (this->q == other.q && this->w == other.w)return true;
		else return false;
	}
	friend string makeStringOf(GeneralFact* obj);

	friend size_t matchfactsstar(GeneralFact* Treesfact, factstar* obj);

	friend size_t matchfactsSpec(GeneralFact* otherf, factUnderInspection* obj);
};

//vector
class global_nils : public GeneralFact
{
	vector<nil_node>	q{};
public:
	global_nils(const vector<nil_node> q1)
		: q(q1) {
		q.shrink_to_fit();
	}

	global_nils(const global_nils& other)
	{
		if (this != &other)
		{
			this->q = other.q;
		}
	}
	~global_nils()
	{
		this->q.clear();

	}
	void operator=(GeneralFact& other) override
	{
		global_nils* ptr = dynamic_cast<global_nils*>(&other);
		this->q = ptr->q;
	}

	global_nils(global_nils&& other) noexcept
		: q{ other.q } {}

	void operator=(global_nils&& other) noexcept
	{
		std::swap(q, other.q);
	}
	friend string makeStringOf(GeneralFact* obj);

	friend size_t matchfactsstar(GeneralFact* Treesfact, factstar* obj);

	friend size_t matchfactsSpec(GeneralFact* otherf, factUnderInspection* obj);
};

class current_module : public GeneralFact
{
	string			q{};
public:
	current_module(const string q1)
		: q(q1) {}

	current_module(const current_module& other)
	{
		if (this != &other)
		{
			this->q = other.q;
		}
	}
	~current_module()
	{
		this->q.clear();

	}
	void operator=(GeneralFact& other) override
	{
		current_module* ptr = dynamic_cast<current_module*>(&other);
		this->q = ptr->q;
	}

	current_module(current_module&& other) noexcept
		: q{ other.q } {}

	void operator=(current_module&& other) noexcept
	{
		std::swap(q, other.q);
	}
	friend string makeStringOf(GeneralFact* obj);

	friend size_t matchfactsstar(GeneralFact* Treesfact, factstar* obj);

	friend size_t matchfactsSpec(GeneralFact* otherf, factUnderInspection* obj);
};

class last_linear_incomplete_node : public GeneralFact
{
	int				q{};
public:
	last_linear_incomplete_node(const int q1)
		: q(q1) {}

	last_linear_incomplete_node(const last_linear_incomplete_node& other)
	{
		if (this != &other)
		{
			this->q = other.q;
		}
	}
	~last_linear_incomplete_node()
	{
		this->q = NULL;

	}
	void operator=(GeneralFact& other) override
	{
		last_linear_incomplete_node* ptr = dynamic_cast<last_linear_incomplete_node*>(&other);
		this->q = ptr->q;
	}

	last_linear_incomplete_node(last_linear_incomplete_node&& other) noexcept
		: q{ other.q } {}

	void operator=(last_linear_incomplete_node&& other) noexcept
	{
		std::swap(q, other.q);
	}
	friend string makeStringOf(GeneralFact* obj);

	friend size_t matchfactsstar(GeneralFact* Treesfact, factstar* obj);

	friend size_t matchfactsSpec(GeneralFact* otherf, factUnderInspection* obj);
};

class operator_instances : public GeneralFact
{
	int				w{};
	string			q{};
public:
	operator_instances(const string q1, const int w1)
		: q(q1), w(w1) {}

	operator_instances(const operator_instances& other)
	{
		if (this != &other)
		{
			this->q = other.q;	this->w = other.w;
		}
	}
	~operator_instances()
	{
		this->q.clear();	this->w = NULL;

	}
	void operator=(GeneralFact& other) override
	{
		operator_instances* ptr = dynamic_cast<operator_instances*>(&other);
		this->q = ptr->q;	this->w = ptr->w;

	}

	operator_instances(operator_instances&& other) noexcept
		: q{ other.q }, w{ other.w } {}

	void operator=(operator_instances&& other) noexcept
	{
		std::swap(q, other.q);	std::swap(w, other.w);
	}
	friend string makeStringOf(GeneralFact* obj);

	friend size_t matchfactsstar(GeneralFact* Treesfact, factstar* obj);

	friend size_t matchfactsSpec(GeneralFact* otherf, factUnderInspection* obj);
};

class massively_parallel_style : public GeneralFact
{
	int				q{};
public:
	massively_parallel_style(const int q1)
		: q(q1) {}

	massively_parallel_style(const massively_parallel_style& other)
	{
		if (this != &other)
		{
			this->q = other.q;
		}
	}
	~massively_parallel_style()
	{
		this->q = NULL;
	}
	void operator=(GeneralFact& other) override
	{
		massively_parallel_style* ptr = dynamic_cast<massively_parallel_style*>(&other);
		this->q = ptr->q;
	}

	massively_parallel_style(massively_parallel_style&& other) noexcept
		: q{ other.q } {}

	void operator=(massively_parallel_style&& other) noexcept
	{
		std::swap(q, other.q);
	}
	friend string makeStringOf(GeneralFact* obj);

	friend size_t matchfactsstar(GeneralFact* Treesfact, factstar* obj);

	friend size_t matchfactsSpec(GeneralFact* otherf, factUnderInspection* obj);
};

class hdl_style : public GeneralFact
{
	string			q{};
public:
	hdl_style(const string q1)
		: q(q1) {}

	hdl_style(const hdl_style& other)
	{
		if (this != &other)
		{
			this->q = other.q;
		}
	}
	~hdl_style()
	{
		this->q.clear();
	}
	void operator=(GeneralFact& other) override
	{
		hdl_style* ptr = dynamic_cast<hdl_style*>(&other);
		this->q = ptr->q;
	}

	hdl_style(hdl_style&& other) noexcept
		: q{ other.q } {}

	void operator=(hdl_style&& other) noexcept
	{
		std::swap(q, other.q);
	}
	friend string makeStringOf(GeneralFact* obj);

	friend size_t matchfactsstar(GeneralFact* Treesfact, factstar* obj);

	friend size_t matchfactsSpec(GeneralFact* otherf, factUnderInspection* obj);
};

class op_instance : public GeneralFact
{
	int				q{}, e{}, r{};
	string			w{}, t{};
public:
	op_instance(const string w1, const int e1, const int q1, const int r1, const string t1)
		:w(w1), e(e1), q(q1), r(r1), t(t1) {}
	op_instance(const op_instance& other)
	{
		if (this != &other)
		{
			this->q = other.q;	this->r = other.r;
			this->w = other.w;	this->e = other.e;
			this->t = other.t;
		}
	}
	~op_instance()
	{
		this->q = NULL;	this->r = NULL;
		this->w.clear();this->e = NULL;
		this->t.clear();

	}
	void operator=(GeneralFact& other) override
	{
		op_instance* ptr = dynamic_cast<op_instance*>(&other);
		this->q = ptr->q;	this->r = ptr->r;
		this->w = ptr->w;	this->e = ptr->e;
		this->t = ptr->t;
	}
	op_instance(op_instance&& other) noexcept
		: q{ other.q }, e{ other.e }, w{ other.w }, r{ other.r }, t{ other.t } {}
	void operator=(op_instance&& other) noexcept
	{
		std::swap(q, other.q); std::swap(e, other.e); std::swap(w, other.w); std::swap(r, other.r), std::swap(t, other.t);
	}
	friend string makeStringOf(GeneralFact* obj);

	friend size_t matchfactsstar(GeneralFact* Treesfact, factstar* obj);

	friend size_t matchfactsSpec(GeneralFact* otherf, factUnderInspection* obj);
};

class last_op_instance : public GeneralFact
{
	int				q{}, e{};
	string			w{};
public:
	last_op_instance(const int q1, const string w1, const int e1)
		: q(q1), w(w1), e(e1) {}

	last_op_instance(const last_op_instance& other)
	{
		if (this != &other)
		{
			this->q = other.q;	this->w = other.w;
			this->e = other.e;
		}
	}
	~last_op_instance()
	{
		this->q = NULL;	this->w.clear();
		this->e = NULL;

	}
	void operator=(GeneralFact& other) override
	{
		last_op_instance* ptr = dynamic_cast<last_op_instance*>(&other);
		this->q = ptr->q;	this->w = ptr->w;
		this->e = ptr->e;
	}

	last_op_instance(last_op_instance&& other) noexcept
		: q{ other.q }, w{ other.w }, e{ other.e } {}

	void operator=(last_op_instance&& other) noexcept
	{
		std::swap(q, other.q);	std::swap(w, other.w);
		std::swap(e, other.e);
	}
	friend string makeStringOf(GeneralFact* obj);

	friend size_t matchfactsstar(GeneralFact* Treesfact, factstar* obj);

	friend size_t matchfactsSpec(GeneralFact* otherf, factUnderInspection* obj);
};

class op_in_a_state : public GeneralFact
{
	int				q{}, r{};
	string			w{}, e{}, t{};
public:
	op_in_a_state(const string w1, const string e1, const int q1, const int r1, const string t1)
		:w(w1), e(e1), q(q1), r(r1), t(t1) {}
	op_in_a_state(const op_in_a_state& other)
	{
		if (this != &other)
		{
			this->q = other.q;	this->r = other.r;
			this->w = other.w;	this->e = other.e;
			this->t = other.t;
		}
	}
	~op_in_a_state()
	{
		this->q = NULL;	this->r = NULL;
		this->w.clear();this->e.clear();
		this->t.clear();
	}
	void operator=(GeneralFact& other) override
	{
		op_in_a_state* ptr = dynamic_cast<op_in_a_state*>(&other);
		this->q = ptr->q;	this->r = ptr->r;
		this->w = ptr->w;	this->e = ptr->e;
		this->t = ptr->t;
	}
	op_in_a_state(op_in_a_state&& other) noexcept
		: q{ other.q }, e{ other.e }, w{ other.w }, r{ other.r }, t{ other.t } {}
	void operator=(op_in_a_state&& other) noexcept
	{
		std::swap(q, other.q); std::swap(e, other.e); std::swap(w, other.w); std::swap(r, other.r), std::swap(t, other.t);
	}
	friend string makeStringOf(GeneralFact* obj);

	friend size_t matchfactsstar(GeneralFact* Treesfact, factstar* obj);

	friend size_t matchfactsSpec(GeneralFact* otherf, factUnderInspection* obj);
};

class last_op_in_a_state : public GeneralFact
{
	int				q{}, r{};
	string			w{}, e{};
public:
	last_op_in_a_state(const int q1, const string w1, const string e1, const int r1)
		: q(q1), w(w1), e(e1), r(r1) {}

	last_op_in_a_state(const last_op_in_a_state& other)
	{
		if (this != &other)
		{
			this->q = other.q;	this->w = other.w;
			this->e = other.e;  this->r = other.r;
		}
	}
	~last_op_in_a_state()
	{
		this->q = NULL;	this->w.clear();
		this->e.clear();  this->r = NULL;

	}
	void operator=(GeneralFact& other) override
	{
		last_op_in_a_state* ptr = dynamic_cast<last_op_in_a_state*>(&other);
		this->q = ptr->q;	this->w = ptr->w;
		this->e = ptr->e;  this->r = ptr->r;
	}

	last_op_in_a_state(last_op_in_a_state&& other) noexcept
		: q{ other.q }, w{ other.w },
		e{ other.e }, r{ other.r } {}

	void operator=(last_op_in_a_state&& other) noexcept
	{
		std::swap(q, other.q);	std::swap(w, other.w);
		std::swap(e, other.e);	std::swap(r, other.r);
	}
	friend string makeStringOf(GeneralFact* obj);

	friend size_t matchfactsstar(GeneralFact* Treesfact, factstar* obj);

	friend size_t matchfactsSpec(GeneralFact* otherf, factUnderInspection* obj);
};

class signal_instance : public GeneralFact
{
	int				q{}, t{}, y{}, u{};
	string			w{}, e{}, r{};
public:
	signal_instance(const int q1, const string w1, const string e1, const string r1, const int t1, const int y1, const int u1)
		: q(q1), w(w1), e(e1), r(r1), t(t1), y(y1), u(u1) {}

	signal_instance(const signal_instance& other)
	{
		if (this != &other)
		{
			this->q = other.q;	this->w = other.w;
			this->e = other.e;	this->r = other.r;
			this->t = other.t;	this->y = other.y;
			this->u = other.u;	
		}
	}
	~signal_instance()
	{
		this->q = NULL;	this->w.clear();
		this->e.clear();this->r.clear();
		this->t = NULL;	this->y = NULL;
		this->u = NULL;

	}
	void operator=(GeneralFact& other) override
	{
		signal_instance* ptr = dynamic_cast<signal_instance*>(&other);
		this->q = ptr->q;	this->w = ptr->w;
		this->e = ptr->e;	this->r = ptr->r;
		this->t = ptr->t;	this->y = ptr->y;
		this->u = ptr->u;	
	}

	signal_instance(signal_instance&& other) noexcept
		: q{ other.q }, w{ other.w }, e{ other.e }, r{ other.r },
		t{ other.t }, y{ other.y }, u{ other.u } {}

	void operator=(signal_instance&& other) noexcept
	{
		std::swap(q, other.q);	std::swap(w, other.w);
		std::swap(e, other.e);	std::swap(r, other.r);
		std::swap(t, other.t);	std::swap(y, other.y);
		std::swap(u, other.u);
	}
	friend string makeStringOf(GeneralFact* obj);

	friend size_t matchfactsstar(GeneralFact* Treesfact, factstar* obj);

	friend size_t matchfactsSpec(GeneralFact* otherf, factUnderInspection* obj);
};

class last_signal_instance : public GeneralFact
{
	int				q{};
	string			w{};
public:
	last_signal_instance(const int q1, const string w1)
		: q(q1), w(w1) {}

	last_signal_instance(const last_signal_instance& other)
	{
		if (this != &other)
		{
			this->q = other.q;	this->w = other.w;
		}
	}
	~last_signal_instance()
	{
		this->q = NULL;	this->w.clear();

	}
	void operator=(GeneralFact& other) override
	{
		last_signal_instance* ptr = dynamic_cast<last_signal_instance*>(&other);
		this->q = ptr->q;	this->w = ptr->w;

	}

	last_signal_instance(last_signal_instance&& other) noexcept
		: q{ other.q }, w{ other.w } {}

	void operator=(last_signal_instance&& other) noexcept
	{
		std::swap(q, other.q);	std::swap(w, other.w);
	}
	friend string makeStringOf(GeneralFact* obj);

	friend size_t matchfactsstar(GeneralFact* Treesfact, factstar* obj);

	friend size_t matchfactsSpec(GeneralFact* otherf, factUnderInspection* obj);
};

class output_instance : public GeneralFact
{
	int				q{}, t{}, y{};
	string			w{}, e{}, r{};
public:
	output_instance(const int q1, const string w1, const string e1, const string r1, const int t1, const int y1)
		: q(q1), w(w1), e(e1), r(r1), t(t1), y(y1) {}

	output_instance(const output_instance& other)
	{
		if (this != &other)
		{
			this->q = other.q;	this->w = other.w;
			this->e = other.e;	this->r = other.r;
			this->t = other.t;	this->y = other.y;
		}
	}
	~output_instance()
	{
		this->q = NULL;	this->w.clear();
		this->e.clear();this->r.clear();
		this->t = NULL;	this->y = NULL;

	}
	void operator=(GeneralFact& other) override
	{
		output_instance* ptr = dynamic_cast<output_instance*> (&other);
		this->q = ptr->q;	this->w = ptr->w;
		this->e = ptr->e;	this->r = ptr->r;
		this->t = ptr->t;	this->y = ptr->y;
	}

	output_instance(output_instance&& other) noexcept
		: q{ other.q }, w{ other.w }, e{ other.e }, r{ other.r },
		t{ other.t }, y{ other.y } {}

	void operator=(output_instance&& other) noexcept
	{
		std::swap(q, other.q);	std::swap(w, other.w);
		std::swap(e, other.e);	std::swap(r, other.r);
		std::swap(t, other.t);	std::swap(y, other.y);
	}
	friend string makeStringOf(GeneralFact* obj);

	friend size_t matchfactsstar(GeneralFact* Treesfact, factstar* obj);

	friend size_t matchfactsSpec(GeneralFact* otherf, factUnderInspection* obj);
};

class last_output_instance : public GeneralFact
{
	int				q{};
	string			w{};
public:
	last_output_instance(const int q1, const string w1)
		: q(q1), w(w1) {}

	last_output_instance(const last_output_instance& other)
	{
		if (this != &other)
		{
			this->q = other.q;	this->w = other.w;
		}
	}
	~last_output_instance()
	{
		this->q = NULL;	this->w.clear();

	}
	void operator=(GeneralFact& other) override
	{
		last_output_instance* ptr = dynamic_cast<last_output_instance*>(&other);
		this->q = ptr->q;	this->w = ptr->w;

	}

	last_output_instance(last_output_instance&& other) noexcept
		: q{ other.q }, w{ other.w } {}

	void operator=(last_output_instance&& other) noexcept
	{
		std::swap(q, other.q);	std::swap(w, other.w);
	}
	friend string makeStringOf(GeneralFact* obj);

	friend size_t matchfactsstar(GeneralFact* Treesfact, factstar* obj);

	friend size_t matchfactsSpec(GeneralFact* otherf, factUnderInspection* obj);
};

class operator_instance_stats : public GeneralFact
{
	int				w{}, e{}, r{};
	string			q{};
public:
	operator_instance_stats(const string q1, const int w1, const int e1, const int r1)
		: q(q1), w(w1), e(e1), r(r1) {}

	operator_instance_stats(const operator_instance_stats& other)
	{
		if (this != &other)
		{
			this->q = other.q;	this->w = other.w;
			this->e = other.e;  this->r = other.r;
		}
	}
	~operator_instance_stats()
	{
		this->q.clear();this->w = NULL;
		this->e = NULL; this->r = NULL;
	}
	void operator=(GeneralFact& other) override
	{
		operator_instance_stats* ptr = dynamic_cast<operator_instance_stats*>(&other);
		this->q = ptr->q;	this->w = ptr->w;
		this->e = ptr->e;	this->r = ptr->r;
	}	

	operator_instance_stats(operator_instance_stats&& other) noexcept
		: q{ other.q }, w{ other.w },
		e{ other.e }, r{ other.r } {}

	void operator=(operator_instance_stats&& other) noexcept
	{
		std::swap(q, other.q);	std::swap(w, other.w);
		std::swap(e, other.e);	std::swap(r, other.r);
	}
	friend string makeStringOf(GeneralFact* obj);

	friend size_t matchfactsstar(GeneralFact* Treesfact, factstar* obj);

	friend size_t matchfactsSpec(GeneralFact* otherf, factUnderInspection* obj);
};

class consecutive_106 : public GeneralFact
{
	string			q{};
public:
	consecutive_106(const string q1)
		: q(q1) {}

	consecutive_106(const consecutive_106& other)
	{
		if (this != &other)
		{
			this->q = other.q;
		}
	}
	~consecutive_106()
	{
		this->q.clear();

	}
	void operator=(GeneralFact& other) override
	{
		consecutive_106* ptr = dynamic_cast<consecutive_106*>(&other);
		this->q = ptr->q;
	}

	consecutive_106(consecutive_106&& other) noexcept
		: q{ other.q } {}

	void operator=(consecutive_106&& other) noexcept
	{
		std::swap(q, other.q);
	}
	friend string makeStringOf(GeneralFact* obj);

	friend size_t matchfactsstar(GeneralFact* Treesfact, factstar* obj);

	friend size_t matchfactsSpec(GeneralFact* otherf, factUnderInspection* obj);
};

class operation_order : public GeneralFact
{
	int				e{}, r{}, t{}, y{}, u{}, i{}, o{}, p{};
	string			q{}, w{};
public:
	operation_order(const string q1, const string w1, const int e1, const int r1, const int t1, const int y1,
		const int u1, const int i1, const int o1, const int p1)
		: q(q1), w(w1), e(e1), r(r1), t(t1), y(y1), u(u1), i(i1), o(o1), p(p1) {}

	operation_order(const operation_order& other)
	{
		if (this != &other)
		{
			this->q = other.q;	this->w = other.w;
			this->e = other.e;	this->r = other.r;
			this->t = other.t;	this->y = other.y;
			this->u = other.u;	this->i = other.i;
			this->o = other.o;	this->p = other.p;
		}
	}
	~operation_order()
	{
		this->q.clear();this->w.clear();
		this->e = NULL;	this->r = NULL;
		this->t = NULL;	this->y = NULL;
		this->u = NULL;	this->i = NULL;
		this->o = NULL;	this->p = NULL;

	}
	void operator=(GeneralFact& other) override
	{
		operation_order* ptr = dynamic_cast<operation_order*>(&other);
		this->q = ptr->q;	this->w = ptr->w;
		this->e = ptr->e;	this->r = ptr->r;
		this->t = ptr->t;	this->y = ptr->y;
		this->u = ptr->u;	this->i = ptr->i;
		this->o = ptr->o;	this->p = ptr->p;
	}

	operation_order(operation_order&& other) noexcept
		: q{ other.q }, w{ other.w }, e{ other.e }, r{ other.r },
		t{ other.t }, y{ other.y }, u{ other.u }, i{ other.i },
		o{ other.o }, p{ other.p } {}

	void operator=(operation_order&& other) noexcept
	{
		std::swap(q, other.q);	std::swap(w, other.w);
		std::swap(e, other.e);	std::swap(r, other.r);
		std::swap(t, other.t);	std::swap(y, other.y);
		std::swap(u, other.u);	std::swap(i, other.i);
		std::swap(o, other.o);	std::swap(p, other.p);
	}
	friend string makeStringOf(GeneralFact* obj);

	friend size_t matchfactsstar(GeneralFact* Treesfact, factstar* obj);

	friend size_t matchfactsSpec(GeneralFact* otherf, factUnderInspection* obj);
};

class max_parallel_call_order : public GeneralFact
{
	int				e{}, r{};
	string			q{}, w{};
public:
	max_parallel_call_order(const string q1, const string w1, const int e1, const int r1)
		: q(q1), w(w1), e(e1), r(r1) {}

	max_parallel_call_order(const max_parallel_call_order& other)
	{
		if (this != &other)
		{
			this->q = other.q;	this->w = other.w;
			this->e = other.e;  this->r = other.r;
		}
	}
	~max_parallel_call_order()
	{
		this->q.clear();	this->w.clear();
		this->e = NULL;  this->r = NULL;

	}
	void operator=(GeneralFact& other) override
	{
		max_parallel_call_order* ptr = dynamic_cast<max_parallel_call_order*>(&other);
		this->q = ptr->q;	this->w = ptr->w;
		this->e = ptr->e;	this->r = ptr->r;
	}

	max_parallel_call_order(max_parallel_call_order&& other) noexcept
		: q{ other.q }, w{ other.w },
		e{ other.e }, r{ other.r } {}

	void operator=(max_parallel_call_order&& other) noexcept
	{
		std::swap(q, other.q);	std::swap(w, other.w);
		std::swap(e, other.e);	std::swap(r, other.r);
	}
	friend string makeStringOf(GeneralFact* obj);

	friend size_t matchfactsstar(GeneralFact* Treesfact, factstar* obj);

	friend size_t matchfactsSpec(GeneralFact* otherf, factUnderInspection* obj);
};

class max_op_order : public GeneralFact
{
	int				e{};
	string			q{}, w{};
public:
	max_op_order(const string q1, const string w1, const int e1)
		: q(q1), w(w1), e(e1) {}

	max_op_order(const max_op_order& other)
	{
		if (this != &other)
		{
			this->q = other.q;	this->w = other.w;
			this->e = other.e;
		}
	}
	~max_op_order()
	{
		this->q.clear();	this->w.clear();
		this->e = NULL;  

	}
	void operator=(GeneralFact& other) override
	{
		max_op_order* ptr = dynamic_cast<max_op_order*>(&other);
		this->q = ptr->q;	this->w = ptr->w;
		this->e = ptr->e;
	}

	max_op_order(max_op_order&& other) noexcept
		: q{ other.q }, w{ other.w }, e{ other.e } {}

	void operator=(max_op_order&& other) noexcept
	{
		std::swap(q, other.q);	std::swap(w, other.w);
		std::swap(e, other.e);
	}
	friend string makeStringOf(GeneralFact* obj);

	friend size_t matchfactsstar(GeneralFact* Treesfact, factstar* obj);

	friend size_t matchfactsSpec(GeneralFact* otherf, factUnderInspection* obj);
};

class totalmax_call_order : public GeneralFact
{
	int				e{};
	string			q{}, w{};
public:
	totalmax_call_order(const string q1, const string w1, const int e1)
		: q(q1), w(w1), e(e1) {}

	totalmax_call_order(const totalmax_call_order& other)
	{
		if (this != &other)
		{
			this->q = other.q;	this->w = other.w;
			this->e = other.e;
		}
	}
	~totalmax_call_order()
	{
		this->q.clear();	this->w.clear();
		this->e = NULL;

	}
	void operator=(GeneralFact& other) override
	{
		totalmax_call_order* ptr = dynamic_cast<totalmax_call_order*>(&other);
		this->q = ptr->q;	this->w = ptr->w;
		this->e = ptr->e;
	}

	totalmax_call_order(totalmax_call_order&& other) noexcept
		: q{ other.q }, w{ other.w }, e{ other.e } {}

	void operator=(totalmax_call_order&& other) noexcept
	{
		std::swap(q, other.q);	std::swap(w, other.w);
		std::swap(e, other.e);
	}
	friend string makeStringOf(GeneralFact* obj);

	friend size_t matchfactsstar(GeneralFact* Treesfact, factstar* obj);

	friend size_t matchfactsSpec(GeneralFact* otherf, factUnderInspection* obj);
};

class totalmax_gross_depth : public GeneralFact
{
	int				e{};
	string			q{}, w{};
public:
	totalmax_gross_depth(const string q1, const string w1, const int e1)
		: q(q1), w(w1), e(e1) {}

	totalmax_gross_depth(const totalmax_gross_depth& other)
	{
		if (this != &other)
		{
			this->q = other.q;	this->w = other.w;
			this->e = other.e;
		}
	}
	~totalmax_gross_depth()
	{
		this->q.clear();	this->w.clear();
		this->e = NULL;

	}
	void operator=(GeneralFact& other) override
	{
		totalmax_gross_depth* ptr = dynamic_cast<totalmax_gross_depth*>(&other);
		this->q = ptr->q;	this->w = ptr->w;
		this->e = ptr->e;
	}

	totalmax_gross_depth(totalmax_gross_depth&& other) noexcept
		: q{ other.q }, w{ other.w }, e{ other.e } {}

	void operator=(totalmax_gross_depth&& other) noexcept
	{
		std::swap(q, other.q);	std::swap(w, other.w);
		std::swap(e, other.e);
	}
	friend string makeStringOf(GeneralFact* obj);

	friend size_t matchfactsstar(GeneralFact* Treesfact, factstar* obj);

	friend size_t matchfactsSpec(GeneralFact* otherf, factUnderInspection* obj);
};

class current_total_max_order_entry : public GeneralFact
{
	int				q{};
public:
	current_total_max_order_entry(const int q1)
		: q(q1) {}

	current_total_max_order_entry(const current_total_max_order_entry& other)
	{
		if (this != &other)
		{
			this->q = other.q;
		}
	}
	~current_total_max_order_entry()
	{
		this->q = NULL;

	}
	void operator=(GeneralFact& other) override
	{
		current_total_max_order_entry* ptr = dynamic_cast<current_total_max_order_entry*>(&other);
		this->q = ptr->q;
	}

	current_total_max_order_entry(current_total_max_order_entry&& other) noexcept
		: q{ other.q } {}

	void operator=(current_total_max_order_entry&& other) noexcept
	{
		std::swap(q, other.q);
	}
	friend string makeStringOf(GeneralFact* obj);

	friend size_t matchfactsstar(GeneralFact* Treesfact, factstar* obj);

	friend size_t matchfactsSpec(GeneralFact* otherf, factUnderInspection* obj);
};

class module_last_state : public GeneralFact
{
	int				q{};
public:
	module_last_state(const int q1)
		: q(q1) {}

	module_last_state(const module_last_state& other)
	{
		if (this != &other)
		{
			this->q = other.q;
		}
	}
	~module_last_state()
	{
		this->q = NULL;

	}
	void operator=(GeneralFact& other) override
	{
		module_last_state* ptr = dynamic_cast<module_last_state*>(&other);
		this->q = ptr->q;
	}
	module_last_state(module_last_state&& other) noexcept
		: q{ other.q } {}
	void operator=(module_last_state&& other) noexcept
	{
		std::swap(q, other.q);
	}
	friend string makeStringOf(GeneralFact* obj);

	friend size_t matchfactsstar(GeneralFact* Treesfact, factstar* obj);

	friend size_t matchfactsSpec(GeneralFact* otherf, factUnderInspection* obj);
};

//vector
class module_local_list : public GeneralFact
{
	vector<local_object>	q{};
public:
	module_local_list(vector<local_object> q1)
	{
		q = q1;
		q.shrink_to_fit();
	}

	module_local_list(local_object& other)
	{
		module_local_list* ptr = dynamic_cast<module_local_list*>(&other);
		if (this != ptr)
		{
			this->q = ptr->q;
		}
	}
	~module_local_list()
	{
		this->q.clear();

	}
	void operator=(GeneralFact& other) override
	{
		module_local_list* ptr = dynamic_cast<module_local_list*>(&other);
		this->q = ptr->q;
	}

	module_local_list(module_local_list&& other) noexcept
		: q{ other.q } 	{}

	void operator=(module_local_list&& other) noexcept
	{
		std::swap(q, other.q);
	}
	friend string makeStringOf(GeneralFact* obj);

	friend size_t matchfactsstar(GeneralFact* Treesfact, factstar* obj);

	friend size_t matchfactsSpec(GeneralFact* otherf, factUnderInspection* obj);
};

//vector
class module_local_list_parcs : public GeneralFact
{
	vector<local_object>	q{};
public:
	module_local_list_parcs(const vector<local_object> q1)
		: q(q1) {
		q.shrink_to_fit();
	}

	module_local_list_parcs(const module_local_list_parcs& other)
	{
		if (this != &other)
		{
			this->q = other.q;
		}
	}
	~module_local_list_parcs()
	{
		this->q.clear();
	}
	void operator=(GeneralFact& other) override
	{
		module_local_list_parcs* ptr = dynamic_cast<module_local_list_parcs*>(&other);
		this->q = ptr->q;
	}

	module_local_list_parcs(module_local_list_parcs&& other) noexcept
		: q{ other.q } {}

	void operator=(module_local_list_parcs&& other) noexcept
	{
		std::swap(q, other.q);
	}
	friend string makeStringOf(GeneralFact* obj);

	friend size_t matchfactsstar(GeneralFact* Treesfact, factstar* obj);

	friend size_t matchfactsSpec(GeneralFact* otherf, factUnderInspection* obj);
};

class last_non_io_found : public GeneralFact
{
	int				q{};
public:
	last_non_io_found(const int q1)
		: q(q1) {}

	last_non_io_found(const last_non_io_found& other)
	{
		if (this != &other)
		{
			this->q = other.q;
		}
	}
	~last_non_io_found()
	{
		this->q = NULL;

	}
	void operator=(GeneralFact& other) override
	{
		last_non_io_found* ptr = dynamic_cast<last_non_io_found*>(&other);
		this->q = ptr->q;
	}

	last_non_io_found(last_non_io_found&& other) noexcept
		: q{ other.q } {}

	void operator=(last_non_io_found&& other) noexcept
	{
		std::swap(q, other.q);
	}
	friend string makeStringOf(GeneralFact* obj);

	friend size_t matchfactsstar(GeneralFact* Treesfact, factstar* obj);

	friend size_t matchfactsSpec(GeneralFact* otherf, factUnderInspection* obj);
};

class last_local_number : public GeneralFact
{
	int				q{};
public:
	last_local_number(const int q1)
		: q(q1) {}

	last_local_number(const last_local_number& other)
	{
		if (this != &other)
		{
			this->q = other.q;
		}
	}
	~last_local_number()
	{
		this->q = NULL;

	}
	void operator=(GeneralFact& other) override
	{
		last_local_number* ptr = dynamic_cast<last_local_number*>(&other);
		this->q = ptr->q;
	}

	last_local_number(last_local_number&& other) noexcept
		: q{ other.q } {}

	void operator=(last_local_number&& other) noexcept
	{
		std::swap(q, other.q);
	}
	friend string makeStringOf(GeneralFact* obj);

	friend size_t matchfactsstar(GeneralFact* Treesfact, factstar* obj);

	friend size_t matchfactsSpec(GeneralFact* otherf, factUnderInspection* obj);
};

class printed_formal_ios_of_called_module : public GeneralFact
{
	int				w{}, e{};
	string			q{}, r{};
public:
	printed_formal_ios_of_called_module(const string q1, const int w1, const int e1, const string r1)
		: q(q1), w(w1), e(e1), r(r1) {}

	printed_formal_ios_of_called_module(const printed_formal_ios_of_called_module& other)
	{
		if (this != &other)
		{
			this->q = other.q;	this->w = other.w;
			this->e = other.e;  this->r = other.r;
		}
	}
	~printed_formal_ios_of_called_module()
	{
		this->q.clear();this->w = NULL;
		this->e = NULL; this->r.clear();
	}
	void operator=(GeneralFact& other) override
	{
		printed_formal_ios_of_called_module* ptr = dynamic_cast<printed_formal_ios_of_called_module*>(&other);
		this->q = ptr->q;	this->w = ptr->w;
		this->e = ptr->e;  this->r = ptr->r;
	}

	printed_formal_ios_of_called_module(printed_formal_ios_of_called_module&& other) noexcept
		: q{ other.q }, w{ other.w },
		e{ other.e }, r{ other.r } {}

	void operator=(printed_formal_ios_of_called_module&& other) noexcept
	{
		std::swap(q, other.q);	std::swap(w, other.w);
		std::swap(e, other.e);	std::swap(r, other.r);
	}
	friend string makeStringOf(GeneralFact* obj);

	friend size_t matchfactsstar(GeneralFact* Treesfact, factstar* obj);

	friend size_t matchfactsSpec(GeneralFact* otherf, factUnderInspection* obj);
};

class it_includes_ifthen : public GeneralFact
{
	int				w{}, e{};
	string			q{};
public:
	it_includes_ifthen(const string q1, const int w1, const int e1)
		: q(q1), w(w1), e(e1) {}

	it_includes_ifthen(const it_includes_ifthen& other)
	{
		if (this != &other)
		{
			this->q = other.q;	this->w = other.w;
			this->e = other.e;
		}
	}
	~it_includes_ifthen()
	{
		this->q.clear(); this->w = NULL;
		this->e = NULL; 
	}
	void operator=(GeneralFact& other) override
	{
		it_includes_ifthen* ptr = dynamic_cast<it_includes_ifthen*>(&other);
		this->q = ptr->q;	this->w = ptr->w;
		this->e = ptr->e;
	}

	it_includes_ifthen(it_includes_ifthen&& other) noexcept
		: q{ other.q }, w{ other.w }, e{ other.e } {}

	void operator=(it_includes_ifthen&& other) noexcept
	{
		std::swap(q, other.q);	std::swap(w, other.w);
		std::swap(e, other.e);
	}
	friend string makeStringOf(GeneralFact* obj);

	friend size_t matchfactsstar(GeneralFact* Treesfact, factstar* obj);

	friend size_t matchfactsSpec(GeneralFact* otherf, factUnderInspection* obj);
};

class it_includes_conditional_targeting : public GeneralFact
{
	int				w{}, e{};
	string			q{};
public:
	it_includes_conditional_targeting(const string q1, const int w1, const int e1)
		: q(q1), w(w1), e(e1) {}

	it_includes_conditional_targeting(const it_includes_conditional_targeting& other)
	{
		if (this != &other)
		{
			this->q = other.q;	this->w = other.w;
			this->e = other.e;
		}
	}
	~it_includes_conditional_targeting()
	{
		this->q.clear(); this->w = NULL;
		this->e = NULL;
	}
	void operator=(GeneralFact& other) override
	{
		it_includes_conditional_targeting* ptr = dynamic_cast<it_includes_conditional_targeting*>(&other);
		this->q = ptr->q;	this->w = ptr->w;
		this->e = ptr->e;
	}

	it_includes_conditional_targeting(it_includes_conditional_targeting&& other) noexcept
		: q{ other.q }, w{ other.w }, e{ other.e } {}

	void operator=(it_includes_conditional_targeting&& other) noexcept
	{
		std::swap(q, other.q);	std::swap(w, other.w);
		std::swap(e, other.e);
	}
	friend string makeStringOf(GeneralFact* obj);

	friend size_t matchfactsstar(GeneralFact* Treesfact, factstar* obj);

	friend size_t matchfactsSpec(GeneralFact* otherf, factUnderInspection* obj);
};

class targets_conditional_variable : public GeneralFact
{
	int				w{}, e{}, r{};
	string			q{};
public:
	targets_conditional_variable(const string q1, const int w1, const int e1, const int r1)
		: q(q1), w(w1), e(e1), r(r1) {}

	targets_conditional_variable(const targets_conditional_variable& other)
	{
		if (this != &other)
		{
			this->q = other.q;	this->w = other.w;
			this->e = other.e;  this->r = other.r;
		}
	}
	~targets_conditional_variable()
	{
		this->q.clear();this->w = NULL;
		this->e = NULL; this->r = NULL;
	}
	void operator=(GeneralFact& other) override
	{
		targets_conditional_variable* ptr = dynamic_cast<targets_conditional_variable*>(&other);
		this->q = ptr->q;	this->w = ptr->w;
		this->e = ptr->e;  this->r = ptr->r;
	}

	targets_conditional_variable(targets_conditional_variable&& other) noexcept
		: q{ other.q }, w{ other.w },
		e{ other.e }, r{ other.r } {}

	void operator=(targets_conditional_variable&& other) noexcept
	{
		std::swap(q, other.q);	std::swap(w, other.w);
		std::swap(e, other.e);	std::swap(r, other.r);
	}
	friend string makeStringOf(GeneralFact* obj);

	friend size_t matchfactsstar(GeneralFact* Treesfact, factstar* obj);

	friend size_t matchfactsSpec(GeneralFact* otherf, factUnderInspection* obj);
};

class variable_has_been_listed : public GeneralFact
{
	string			q{}, w{};
public:
	variable_has_been_listed(const string q1, const string w1)
		: q(q1), w(w1) {}

	variable_has_been_listed(const variable_has_been_listed& other)
	{
		if (this != &other)
		{
			this->q = other.q;	this->w = other.w;
		}
	}
	~variable_has_been_listed()
	{
		this->q.clear();	this->w.clear();
	}
	void operator=(GeneralFact& other) override
	{
		variable_has_been_listed* ptr = dynamic_cast<variable_has_been_listed*>(&other);
		this->q = ptr->q;	this->w = ptr->w;

	}

	variable_has_been_listed(variable_has_been_listed&& other) noexcept
		: q{ other.q }, w{ other.w } {}

	void operator=(variable_has_been_listed&& other) noexcept
	{
		std::swap(q, other.q);	std::swap(w, other.w);
	}
	friend string makeStringOf(GeneralFact* obj);

	friend size_t matchfactsstar(GeneralFact* Treesfact, factstar* obj);

	friend size_t matchfactsSpec(GeneralFact* otherf, factUnderInspection* obj);
};

class resetstyle : public GeneralFact
{
	string			q{};
public:
	resetstyle(const string q1)
		: q(q1) {}

	resetstyle(const resetstyle& other)
	{
		if (this != &other)
		{
			this->q = other.q;
		}
	}
	~resetstyle()
	{
		this->q.clear();
	}
	void operator=(GeneralFact& other) override
	{
		resetstyle* ptr = dynamic_cast<resetstyle*>(&other);
		this->q = ptr->q;
	}

	resetstyle(resetstyle&& other) noexcept
		: q{ other.q } {}

	void operator=(resetstyle&& other) noexcept
	{
		std::swap(q, other.q);
	}
	friend string makeStringOf(GeneralFact* obj);

	friend size_t matchfactsstar(GeneralFact* Treesfact, factstar* obj);

	friend size_t matchfactsSpec(GeneralFact* otherf, factUnderInspection* obj);
};

class checkstyle : public GeneralFact
{
	string			q{};
public:
	checkstyle(const string q1)
		: q(q1) {}

	checkstyle(const checkstyle& other)
	{
		if (this != &other)
		{
			this->q = other.q;
		}
	}
	~checkstyle()
	{
		this->q.clear();
	}
	void operator=(GeneralFact& other) override
	{
		checkstyle* ptr = dynamic_cast<checkstyle*>(&other);
		this->q = ptr->q;
	}

	checkstyle(checkstyle&& other) noexcept
		: q{ other.q } {}

	void operator=(checkstyle&& other) noexcept
	{
		std::swap(q, other.q);
	}
	friend string makeStringOf(GeneralFact* obj);

	friend size_t matchfactsstar(GeneralFact* Treesfact, factstar* obj);

	friend size_t matchfactsSpec(GeneralFact* otherf, factUnderInspection* obj);
};

class total_local_entry : public GeneralFact
{
	int				q{};
public:
	total_local_entry(const int q1)
		: q(q1) {}

	total_local_entry(const total_local_entry& other)
	{
		if (this != &other)
		{
			this->q = other.q;
		}
	}
	~total_local_entry()
	{
		this->q = NULL;

	}
	void operator=(GeneralFact& other) override
	{
		total_local_entry* ptr = dynamic_cast<total_local_entry*>(&other);
		this->q = ptr->q;
	}

	total_local_entry(total_local_entry&& other) noexcept
		: q{ other.q } {}

	void operator=(total_local_entry&& other) noexcept
	{
		std::swap(q, other.q);
	}
	friend string makeStringOf(GeneralFact* obj);

	friend size_t matchfactsstar(GeneralFact* Treesfact, factstar* obj);

	friend size_t matchfactsSpec(GeneralFact* otherf, factUnderInspection* obj);
};

class complex_next_state_operation_depth : public GeneralFact
{
	int				q{};
public:
	complex_next_state_operation_depth(const int q1)
		: q(q1) {}

	complex_next_state_operation_depth(const complex_next_state_operation_depth& other)
	{
		if (this != &other)
		{
			this->q = other.q;
		}
	}
	~complex_next_state_operation_depth()
	{
		this->q = NULL;
	}
	void operator=(GeneralFact& other) override
	{
		complex_next_state_operation_depth* ptr = dynamic_cast<complex_next_state_operation_depth*>(&other);
		this->q = ptr->q;
	}

	complex_next_state_operation_depth(complex_next_state_operation_depth&& other) noexcept
		: q{ other.q } {}

	void operator=(complex_next_state_operation_depth&& other) noexcept
	{
		std::swap(q, other.q);
	}
	friend string makeStringOf(GeneralFact* obj);

	friend size_t matchfactsstar(GeneralFact* Treesfact, factstar* obj);

	friend size_t matchfactsSpec(GeneralFact* otherf, factUnderInspection* obj);
};

class output_filename : public GeneralFact
{
	string			q{};
public:
	output_filename(const string q1)
		: q(q1) {}

	output_filename(const output_filename& other)
	{
		if (this != &other)
		{
			this->q = other.q;
		}
	}
	~output_filename()
	{
		this->q.clear();
	}
	void operator=(GeneralFact& other) override
	{
		output_filename* ptr = dynamic_cast<output_filename*>(&other);
		this->q = ptr->q;
	}

	output_filename(output_filename&& other) noexcept
		: q{ other.q } {}

	void operator=(output_filename&& other) noexcept
	{
		std::swap(q, other.q);
	}
	friend string makeStringOf(GeneralFact* obj);

	friend size_t matchfactsstar(GeneralFact* Treesfact, factstar* obj);

	friend size_t matchfactsSpec(GeneralFact* otherf, factUnderInspection* obj);
};

class hdl_io_pass : public GeneralFact
{
	int				q{};
public:
	hdl_io_pass(const int q1)
		: q(q1) {}

	hdl_io_pass(const hdl_io_pass& other)
	{
		if (this != &other)
		{
			this->q = other.q;
		}
	}
	~hdl_io_pass()
	{
		this->q = NULL;
	}
	void operator=(GeneralFact& other) override
	{
		hdl_io_pass* ptr = dynamic_cast<hdl_io_pass*>(&other);
		this->q = ptr->q;
	}

	hdl_io_pass(hdl_io_pass&& other) noexcept
		: q{ other.q } {}

	void operator=(hdl_io_pass&& other) noexcept
	{
		std::swap(q, other.q);
	}
	friend string makeStringOf(GeneralFact* obj);

	friend size_t matchfactsstar(GeneralFact* Treesfact, factstar* obj);

	friend size_t matchfactsSpec(GeneralFact* otherf, factUnderInspection* obj);
};

class current_hdl_style : public GeneralFact
{
	string			q{};
public:
	current_hdl_style(const string q1)
		: q(q1) {}

	current_hdl_style(const current_hdl_style& other)
	{
		if (this != &other)
		{
			this->q = other.q;
		}
	}
	~current_hdl_style()
	{
		this->q.clear();
	}
	void operator=(GeneralFact& other) override
	{
		current_hdl_style* ptr = dynamic_cast<current_hdl_style*>(&other);
		this->q = ptr->q;
	}

	current_hdl_style(current_hdl_style&& other) noexcept
		: q{ other.q } {}

	void operator=(current_hdl_style&& other) noexcept
	{
		std::swap(q, other.q);
	}
	friend string makeStringOf(GeneralFact* obj);

	friend size_t matchfactsstar(GeneralFact* Treesfact, factstar* obj);

	friend size_t matchfactsSpec(GeneralFact* otherf, factUnderInspection* obj);
};

class call_ios_have_been_reset : public GeneralFact
{
	string			q{};
public:
	call_ios_have_been_reset(const string q1)
		: q(q1) {}

	call_ios_have_been_reset(const call_ios_have_been_reset& other)
	{
		if (this != &other)
		{
			this->q = other.q;
		}
	}
	~call_ios_have_been_reset()
	{
		this->q.clear();
	}
	void operator=(GeneralFact& other) override
	{
		call_ios_have_been_reset* ptr = dynamic_cast<call_ios_have_been_reset*>(&other);
		this->q = ptr->q;
	}

	call_ios_have_been_reset(call_ios_have_been_reset&& other) noexcept
		: q{ other.q } {}

	void operator=(call_ios_have_been_reset&& other) noexcept
	{
		std::swap(q, other.q);
	}
	friend string makeStringOf(GeneralFact* obj);

	friend size_t matchfactsstar(GeneralFact* Treesfact, factstar* obj);

	friend size_t matchfactsSpec(GeneralFact* otherf, factUnderInspection* obj);
};

class debug_mode : public GeneralFact
{
	int				q{};
public:
	debug_mode(const int q1)
		: q(q1) {}

	debug_mode(const debug_mode& other)
	{
		if (this != &other)
		{
			this->q = other.q;
		}
	}
	~debug_mode()
	{
		this->q = NULL;
	}
	void operator=(GeneralFact& other) override
	{
		debug_mode* ptr = dynamic_cast<debug_mode*>(&other);
		this->q = ptr->q;
	}

	debug_mode(debug_mode&& other) noexcept
		: q{ other.q } {}

	void operator=(debug_mode&& other) noexcept
	{
		std::swap(q, other.q);
	}
	friend string makeStringOf(GeneralFact* obj);

	friend size_t matchfactsstar(GeneralFact* Treesfact, factstar* obj);

	friend size_t matchfactsSpec(GeneralFact* otherf, factUnderInspection* obj);
};

class print_C_main_body : public GeneralFact
{
	int				q{};
public:
	print_C_main_body(const int q1)
		: q(q1) {}

	print_C_main_body(const print_C_main_body& other)
	{
		if (this != &other)
		{
			this->q = other.q;
		}
	}
	~print_C_main_body()
	{
		this->q = NULL;
	}
	void operator=(GeneralFact& other) override
	{
		print_C_main_body* ptr = dynamic_cast<print_C_main_body*>(&other);
		this->q = ptr->q;
	}

	print_C_main_body(print_C_main_body&& other) noexcept
		: q{ other.q } {}

	void operator=(print_C_main_body&& other) noexcept
	{
		std::swap(q, other.q);
	}
	friend string makeStringOf(GeneralFact* obj);

	friend size_t matchfactsstar(GeneralFact* Treesfact, factstar* obj);

	friend size_t matchfactsSpec(GeneralFact* otherf, factUnderInspection* obj);
};

class cac_mode : public GeneralFact
{
	int				q{};
public:
	cac_mode(const int q1)
		: q(q1) {}

	cac_mode(const cac_mode& other)
	{
		if (this != &other)
		{
			this->q = other.q;
		}
	}
	~cac_mode()
	{
		this->q = NULL;
	}
	void operator=(GeneralFact& other) override
	{
		cac_mode* ptr = dynamic_cast<cac_mode*>(&other);
		this->q = ptr->q;
	}

	cac_mode(cac_mode&& other) noexcept
		: q{ other.q } {}

	void operator=(cac_mode&& other) noexcept
	{
		std::swap(q, other.q);
	}
	friend string makeStringOf(GeneralFact* obj);

	friend size_t matchfactsstar(GeneralFact* Treesfact, factstar* obj);

	friend size_t matchfactsSpec(GeneralFact* otherf, factUnderInspection* obj);
};

class path : public GeneralFact
{
	int				w{}, e{};
	string			q{};
public:
	path(const string q1, const int w1, const int e1)
		: q(q1), w(w1), e(e1) {}

	path(const path& other)
	{
		if (this != &other)
		{
			this->q = other.q;	this->w = other.w;
			this->e = other.e;
		}
	}
	~path()
	{
		this->q.clear();this->w = NULL;
		this->e = NULL;
	}
	void operator=(GeneralFact& other) override
	{
		path* ptr = dynamic_cast<path*>(&other);
		this->q = ptr->q;	this->w = ptr->w;
		this->e = ptr->e;
	}

	path(path&& other) noexcept
		: q{ other.q }, w{ other.w }, e{ other.e } {}

	void operator=(path&& other) noexcept
	{
		std::swap(q, other.q);	std::swap(w, other.w);
		std::swap(e, other.e);
	}
	friend string makeStringOf(GeneralFact* obj);

	friend size_t matchfactsstar(GeneralFact* Treesfact, factstar* obj);

	friend size_t matchfactsSpec(GeneralFact* otherf, factUnderInspection* obj);
};

class max_path : public GeneralFact
{
	int				w{};
	string			q{};
public:
	max_path(const string q1, const int w1)
		: q(q1), w(w1) {}

	max_path(const max_path& other)
	{
		if (this != &other)
		{
			this->q = other.q;	this->w = other.w;
		}
	}
	~max_path()
	{
		this->q.clear(); this->w = NULL;
	}
	void operator=(GeneralFact& other) override
	{
		max_path* ptr = dynamic_cast<max_path*>(&other);
		this->q = ptr->q;	this->w = ptr->w;

	}

	max_path(max_path&& other) noexcept
		: q{ other.q }, w{ other.w } {}

	void operator=(max_path&& other) noexcept
	{
		std::swap(q, other.q);	std::swap(w, other.w);
	}
	friend string makeStringOf(GeneralFact* obj);

	friend size_t matchfactsstar(GeneralFact* Treesfact, factstar* obj);

	friend size_t matchfactsSpec(GeneralFact* otherf, factUnderInspection* obj);
};

class min_path : public GeneralFact
{
	int				w{};
	string			q{};
public:
	min_path(const string q1, const int w1)
		: q(q1), w(w1) {}

	min_path(const min_path& other)
	{
		if (this != &other)
		{
			this->q = other.q;	this->w = other.w;
		}
	}
	~min_path()
	{
		this->q.clear(); this->w = NULL;
	}
	void operator=(GeneralFact& other) override
	{
		min_path* ptr = dynamic_cast<min_path*>(&other);
		this->q = ptr->q;	this->w = ptr->w;

	}

	min_path(min_path&& other) noexcept
		: q{ other.q }, w{ other.w } {}

	void operator=(min_path&& other) noexcept
	{
		std::swap(q, other.q);	std::swap(w, other.w);
	}
	friend string makeStringOf(GeneralFact* obj);

	friend size_t matchfactsstar(GeneralFact* Treesfact, factstar* obj);

	friend size_t matchfactsSpec(GeneralFact* otherf, factUnderInspection* obj);
};

class op_belongs_to_state : public GeneralFact
{
	int				w{}, e{}, r{};
	string			q{};
public:
	op_belongs_to_state(const string q1, const int w1, const int e1, const int r1)
		: q(q1), w(w1), e(e1), r(r1) {}

	op_belongs_to_state(const op_belongs_to_state& other)
	{
		if (this != &other)
		{
			this->q = other.q;	this->w = other.w;
			this->e = other.e;  this->r = other.r;
		}
	}
	~op_belongs_to_state()
	{
		this->q.clear();this->w = NULL;
		this->e = NULL; this->r = NULL;

	}
	void operator=(GeneralFact& other) override
	{
		op_belongs_to_state* ptr = dynamic_cast<op_belongs_to_state*>(&other);
		this->q = ptr->q;	this->w = ptr->w;
		this->e = ptr->e;	this->r = ptr->r;
	}

	op_belongs_to_state(op_belongs_to_state&& other) noexcept
		: q{ other.q }, w{ other.w },
		e{ other.e }, r{ other.r } {}

	void operator=(op_belongs_to_state&& other) noexcept
	{
		std::swap(q, other.q);	std::swap(w, other.w);
		std::swap(e, other.e);	std::swap(r, other.r);
	}
	friend string makeStringOf(GeneralFact* obj);

	friend size_t matchfactsstar(GeneralFact* Treesfact, factstar* obj);

	friend size_t matchfactsSpec(GeneralFact* otherf, factUnderInspection* obj);
};

class top_module : public GeneralFact
{
	string			q{};
public:
	top_module(const string q1)
		: q(q1) {}

	top_module(const top_module& other)
	{
		if (this != &other)
		{
			this->q = other.q;
		}
	}
	~top_module()
	{
		this->q.clear();

	}
	void operator=(GeneralFact& other) override
	{
		top_module* ptr = dynamic_cast<top_module*>(&other);
		this->q = ptr->q;
	}

	top_module(top_module&& other) noexcept
		: q{ other.q } {}

	void operator=(top_module&& other) noexcept
	{
		std::swap(q, other.q);
	}
	friend string makeStringOf(GeneralFact* obj);

	friend size_t matchfactsstar(GeneralFact* Treesfact, factstar* obj);

	friend size_t matchfactsSpec(GeneralFact* otherf, factUnderInspection* obj);
};

class package_name : public GeneralFact
{
	string			q{};
public:
	package_name(const string q1)
		: q(q1) {}

	package_name(const package_name& other)
	{
		if (this != &other)
		{
			this->q = other.q;
		}
	}
	~package_name()
	{
		this->q.clear();
	}
	void operator=(GeneralFact& other) override
	{
		package_name* ptr = dynamic_cast<package_name*>(&other);
		this->q = ptr->q;
	}

	package_name(package_name&& other) noexcept
		: q{ other.q } {}

	void operator=(package_name&& other) noexcept
	{
		std::swap(q, other.q);
	}
	friend string makeStringOf(GeneralFact* obj);

	friend size_t matchfactsstar(GeneralFact* Treesfact, factstar* obj);

	friend size_t matchfactsSpec(GeneralFact* otherf, factUnderInspection* obj);
};

class GenfactError : public GeneralFact
{
	string saying{};
public:
	GenfactError(string pepe)
		:saying(pepe) {}
	void operator=(GeneralFact& other) override
	{
		GenfactError* ptr = dynamic_cast<GenfactError*>(&other);
		if (this != &other)
			this->saying = ptr->saying;
	}
	~GenfactError()
	{
		this->saying.clear();
	}
	friend string makeStringOf(GeneralFact* obj);
	
	friend size_t matchfactsstar(GeneralFact* Treesfact, factstar* obj);

	friend size_t matchfactsSpec(GeneralFact* otherf, factUnderInspection* obj);
};

class module_counter : public GeneralFact
{
	int				q{};
public:
	module_counter(const int q1)
		: q(q1) {}

	module_counter(const module_counter& other)
	{
		if (this != &other)
		{
			this->q = other.q;
		}
	}
	~module_counter()
	{
		this->q = NULL;

	}
	void operator=(GeneralFact& other) override
	{
		module_counter* ptr = dynamic_cast<module_counter*>(&other);
		this->q = ptr->q;
	}

	module_counter(module_counter&& other) noexcept
		: q{ other.q } {}

	void operator=(module_counter&& other) noexcept
	{
		std::swap(q, other.q);
	}
	friend string makeStringOf(GeneralFact* obj);

	friend size_t matchfactsstar(GeneralFact* Treesfact, factstar* obj);

	friend size_t matchfactsSpec(GeneralFact* otherf, factUnderInspection* obj);
};

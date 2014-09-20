#ifndef hanoi_H_
#define hanoi_H_

#include <derplanner/runtime/interface.h>

namespace plnnr
{
	namespace tuple_list
	{
		struct Handle;
	}
}

namespace plnnr
{
	struct Planner_State;
	struct Method_Instance;
}

namespace hanoi {

enum Atom_Type
{
	atom_disc,
	atom_loc,
	atom_startloc,
	atom_endloc,
	atom_clearloc,
	atom_clear,
	atom_top,
	atom_on_table,
	atom_on_other,
	atom_at,
	atom_on,
	atom_count,
};

const char* atom_name(Atom_Type type);

struct Worldstate
{
	plnnr::tuple_list::Handle* atoms[atom_count];
};

struct disc_tuple
{
	int _0;
	disc_tuple* next;
	disc_tuple* prev;
	enum { id = atom_disc };
};

struct loc_tuple
{
	int _0;
	loc_tuple* next;
	loc_tuple* prev;
	enum { id = atom_loc };
};

struct startloc_tuple
{
	int _0;
	startloc_tuple* next;
	startloc_tuple* prev;
	enum { id = atom_startloc };
};

struct endloc_tuple
{
	int _0;
	endloc_tuple* next;
	endloc_tuple* prev;
	enum { id = atom_endloc };
};

struct clearloc_tuple
{
	int _0;
	clearloc_tuple* next;
	clearloc_tuple* prev;
	enum { id = atom_clearloc };
};

struct clear_tuple
{
	int _0;
	clear_tuple* next;
	clear_tuple* prev;
	enum { id = atom_clear };
};

struct top_tuple
{
	int _0;
	top_tuple* next;
	top_tuple* prev;
	enum { id = atom_top };
};

struct on_table_tuple
{
	int _0;
	on_table_tuple* next;
	on_table_tuple* prev;
	enum { id = atom_on_table };
};

struct on_other_tuple
{
	int _0;
	on_other_tuple* next;
	on_other_tuple* prev;
	enum { id = atom_on_other };
};

struct at_tuple
{
	int _0;
	int _1;
	at_tuple* next;
	at_tuple* prev;
	enum { id = atom_at };
};

struct on_tuple
{
	int _0;
	int _1;
	on_tuple* next;
	on_tuple* prev;
	enum { id = atom_on };
};

}

namespace hanoi {

enum Task_Type
{
	task_move_top_to_clear_op,
	task_move_single_to_top_op,
	task_move_top_to_top_op,
	task_move_single_to_clear_op,
	task_root,
	task_Move_Stack,
	task_count,
};

static const int operator_count = 4;
static const int method_count = 2;

const char* task_name(Task_Type type);

struct move_top_to_clear_op_args
{
	int _0;
	int _1;
	int _2;
	int _3;
};

inline bool operator==(const move_top_to_clear_op_args& a, const move_top_to_clear_op_args& b)
{
	return \
		a._0 == b._0 &&
		a._1 == b._1 &&
		a._2 == b._2 &&
		a._3 == b._3 ;
}

struct move_single_to_top_op_args
{
	int _0;
	int _1;
	int _2;
	int _3;
};

inline bool operator==(const move_single_to_top_op_args& a, const move_single_to_top_op_args& b)
{
	return \
		a._0 == b._0 &&
		a._1 == b._1 &&
		a._2 == b._2 &&
		a._3 == b._3 ;
}

struct move_top_to_top_op_args
{
	int _0;
	int _1;
	int _2;
	int _3;
	int _4;
};

inline bool operator==(const move_top_to_top_op_args& a, const move_top_to_top_op_args& b)
{
	return \
		a._0 == b._0 &&
		a._1 == b._1 &&
		a._2 == b._2 &&
		a._3 == b._3 &&
		a._4 == b._4 ;
}

struct move_single_to_clear_op_args
{
	int _0;
	int _1;
	int _2;
};

inline bool operator==(const move_single_to_clear_op_args& a, const move_single_to_clear_op_args& b)
{
	return \
		a._0 == b._0 &&
		a._1 == b._1 &&
		a._2 == b._2 ;
}

struct Move_Stack_args
{
	int _0;
	int _1;
	int _2;
	int _3;
};

inline bool operator==(const Move_Stack_args& a, const Move_Stack_args& b)
{
	return \
		a._0 == b._0 &&
		a._1 == b._1 &&
		a._2 == b._2 &&
		a._3 == b._3 ;
}

bool root_branch_0_expand(plnnr::Method_Instance*, plnnr::Planner_State&, void*);
bool Move_Stack_branch_0_expand(plnnr::Method_Instance*, plnnr::Planner_State&, void*);
bool Move_Stack_branch_1_expand(plnnr::Method_Instance*, plnnr::Planner_State&, void*);
bool Move_Stack_branch_2_expand(plnnr::Method_Instance*, plnnr::Planner_State&, void*);
bool Move_Stack_branch_3_expand(plnnr::Method_Instance*, plnnr::Planner_State&, void*);
bool Move_Stack_branch_4_expand(plnnr::Method_Instance*, plnnr::Planner_State&, void*);

}

namespace plnnr {

template <typename V>
struct Generated_Type_Reflector<hanoi::Worldstate, V>
{
	void operator()(const hanoi::Worldstate& world, V& visitor)
	{
		PLNNR_GENCODE_VISIT_ATOM_LIST(hanoi, atom_disc, disc_tuple, visitor);
		PLNNR_GENCODE_VISIT_ATOM_LIST(hanoi, atom_loc, loc_tuple, visitor);
		PLNNR_GENCODE_VISIT_ATOM_LIST(hanoi, atom_startloc, startloc_tuple, visitor);
		PLNNR_GENCODE_VISIT_ATOM_LIST(hanoi, atom_endloc, endloc_tuple, visitor);
		PLNNR_GENCODE_VISIT_ATOM_LIST(hanoi, atom_clearloc, clearloc_tuple, visitor);
		PLNNR_GENCODE_VISIT_ATOM_LIST(hanoi, atom_clear, clear_tuple, visitor);
		PLNNR_GENCODE_VISIT_ATOM_LIST(hanoi, atom_top, top_tuple, visitor);
		PLNNR_GENCODE_VISIT_ATOM_LIST(hanoi, atom_on_table, on_table_tuple, visitor);
		PLNNR_GENCODE_VISIT_ATOM_LIST(hanoi, atom_on_other, on_other_tuple, visitor);
		PLNNR_GENCODE_VISIT_ATOM_LIST(hanoi, atom_at, at_tuple, visitor);
		PLNNR_GENCODE_VISIT_ATOM_LIST(hanoi, atom_on, on_tuple, visitor);
	}
};

template <typename V>
struct Generated_Type_Reflector<hanoi::disc_tuple, V>
{
	void operator()(const hanoi::disc_tuple& tuple, V& visitor)
	{
		PLNNR_GENCODE_VISIT_TUPLE_BEGIN(visitor, hanoi, atom_name, atom_disc, 1);
		PLNNR_GENCODE_VISIT_TUPLE_ELEMENT(visitor, tuple, 0);
		PLNNR_GENCODE_VISIT_TUPLE_END(visitor, hanoi, atom_name, atom_disc, 1);
	}
};

template <typename V>
struct Generated_Type_Reflector<hanoi::loc_tuple, V>
{
	void operator()(const hanoi::loc_tuple& tuple, V& visitor)
	{
		PLNNR_GENCODE_VISIT_TUPLE_BEGIN(visitor, hanoi, atom_name, atom_loc, 1);
		PLNNR_GENCODE_VISIT_TUPLE_ELEMENT(visitor, tuple, 0);
		PLNNR_GENCODE_VISIT_TUPLE_END(visitor, hanoi, atom_name, atom_loc, 1);
	}
};

template <typename V>
struct Generated_Type_Reflector<hanoi::startloc_tuple, V>
{
	void operator()(const hanoi::startloc_tuple& tuple, V& visitor)
	{
		PLNNR_GENCODE_VISIT_TUPLE_BEGIN(visitor, hanoi, atom_name, atom_startloc, 1);
		PLNNR_GENCODE_VISIT_TUPLE_ELEMENT(visitor, tuple, 0);
		PLNNR_GENCODE_VISIT_TUPLE_END(visitor, hanoi, atom_name, atom_startloc, 1);
	}
};

template <typename V>
struct Generated_Type_Reflector<hanoi::endloc_tuple, V>
{
	void operator()(const hanoi::endloc_tuple& tuple, V& visitor)
	{
		PLNNR_GENCODE_VISIT_TUPLE_BEGIN(visitor, hanoi, atom_name, atom_endloc, 1);
		PLNNR_GENCODE_VISIT_TUPLE_ELEMENT(visitor, tuple, 0);
		PLNNR_GENCODE_VISIT_TUPLE_END(visitor, hanoi, atom_name, atom_endloc, 1);
	}
};

template <typename V>
struct Generated_Type_Reflector<hanoi::clearloc_tuple, V>
{
	void operator()(const hanoi::clearloc_tuple& tuple, V& visitor)
	{
		PLNNR_GENCODE_VISIT_TUPLE_BEGIN(visitor, hanoi, atom_name, atom_clearloc, 1);
		PLNNR_GENCODE_VISIT_TUPLE_ELEMENT(visitor, tuple, 0);
		PLNNR_GENCODE_VISIT_TUPLE_END(visitor, hanoi, atom_name, atom_clearloc, 1);
	}
};

template <typename V>
struct Generated_Type_Reflector<hanoi::clear_tuple, V>
{
	void operator()(const hanoi::clear_tuple& tuple, V& visitor)
	{
		PLNNR_GENCODE_VISIT_TUPLE_BEGIN(visitor, hanoi, atom_name, atom_clear, 1);
		PLNNR_GENCODE_VISIT_TUPLE_ELEMENT(visitor, tuple, 0);
		PLNNR_GENCODE_VISIT_TUPLE_END(visitor, hanoi, atom_name, atom_clear, 1);
	}
};

template <typename V>
struct Generated_Type_Reflector<hanoi::top_tuple, V>
{
	void operator()(const hanoi::top_tuple& tuple, V& visitor)
	{
		PLNNR_GENCODE_VISIT_TUPLE_BEGIN(visitor, hanoi, atom_name, atom_top, 1);
		PLNNR_GENCODE_VISIT_TUPLE_ELEMENT(visitor, tuple, 0);
		PLNNR_GENCODE_VISIT_TUPLE_END(visitor, hanoi, atom_name, atom_top, 1);
	}
};

template <typename V>
struct Generated_Type_Reflector<hanoi::on_table_tuple, V>
{
	void operator()(const hanoi::on_table_tuple& tuple, V& visitor)
	{
		PLNNR_GENCODE_VISIT_TUPLE_BEGIN(visitor, hanoi, atom_name, atom_on_table, 1);
		PLNNR_GENCODE_VISIT_TUPLE_ELEMENT(visitor, tuple, 0);
		PLNNR_GENCODE_VISIT_TUPLE_END(visitor, hanoi, atom_name, atom_on_table, 1);
	}
};

template <typename V>
struct Generated_Type_Reflector<hanoi::on_other_tuple, V>
{
	void operator()(const hanoi::on_other_tuple& tuple, V& visitor)
	{
		PLNNR_GENCODE_VISIT_TUPLE_BEGIN(visitor, hanoi, atom_name, atom_on_other, 1);
		PLNNR_GENCODE_VISIT_TUPLE_ELEMENT(visitor, tuple, 0);
		PLNNR_GENCODE_VISIT_TUPLE_END(visitor, hanoi, atom_name, atom_on_other, 1);
	}
};

template <typename V>
struct Generated_Type_Reflector<hanoi::at_tuple, V>
{
	void operator()(const hanoi::at_tuple& tuple, V& visitor)
	{
		PLNNR_GENCODE_VISIT_TUPLE_BEGIN(visitor, hanoi, atom_name, atom_at, 2);
		PLNNR_GENCODE_VISIT_TUPLE_ELEMENT(visitor, tuple, 0);
		PLNNR_GENCODE_VISIT_TUPLE_ELEMENT(visitor, tuple, 1);
		PLNNR_GENCODE_VISIT_TUPLE_END(visitor, hanoi, atom_name, atom_at, 2);
	}
};

template <typename V>
struct Generated_Type_Reflector<hanoi::on_tuple, V>
{
	void operator()(const hanoi::on_tuple& tuple, V& visitor)
	{
		PLNNR_GENCODE_VISIT_TUPLE_BEGIN(visitor, hanoi, atom_name, atom_on, 2);
		PLNNR_GENCODE_VISIT_TUPLE_ELEMENT(visitor, tuple, 0);
		PLNNR_GENCODE_VISIT_TUPLE_ELEMENT(visitor, tuple, 1);
		PLNNR_GENCODE_VISIT_TUPLE_END(visitor, hanoi, atom_name, atom_on, 2);
	}
};

template <typename V>
struct Generated_Type_Reflector<hanoi::move_top_to_clear_op_args, V>
{
	void operator()(const hanoi::move_top_to_clear_op_args& tuple, V& visitor)
	{
		PLNNR_GENCODE_VISIT_TUPLE_BEGIN(visitor, hanoi, task_name, task_move_top_to_clear_op, 4);
		PLNNR_GENCODE_VISIT_TUPLE_ELEMENT(visitor, tuple, 0);
		PLNNR_GENCODE_VISIT_TUPLE_ELEMENT(visitor, tuple, 1);
		PLNNR_GENCODE_VISIT_TUPLE_ELEMENT(visitor, tuple, 2);
		PLNNR_GENCODE_VISIT_TUPLE_ELEMENT(visitor, tuple, 3);
		PLNNR_GENCODE_VISIT_TUPLE_END(visitor, hanoi, task_name, task_move_top_to_clear_op, 4);
	}
};

template <typename V>
struct Generated_Type_Reflector<hanoi::move_single_to_top_op_args, V>
{
	void operator()(const hanoi::move_single_to_top_op_args& tuple, V& visitor)
	{
		PLNNR_GENCODE_VISIT_TUPLE_BEGIN(visitor, hanoi, task_name, task_move_single_to_top_op, 4);
		PLNNR_GENCODE_VISIT_TUPLE_ELEMENT(visitor, tuple, 0);
		PLNNR_GENCODE_VISIT_TUPLE_ELEMENT(visitor, tuple, 1);
		PLNNR_GENCODE_VISIT_TUPLE_ELEMENT(visitor, tuple, 2);
		PLNNR_GENCODE_VISIT_TUPLE_ELEMENT(visitor, tuple, 3);
		PLNNR_GENCODE_VISIT_TUPLE_END(visitor, hanoi, task_name, task_move_single_to_top_op, 4);
	}
};

template <typename V>
struct Generated_Type_Reflector<hanoi::move_top_to_top_op_args, V>
{
	void operator()(const hanoi::move_top_to_top_op_args& tuple, V& visitor)
	{
		PLNNR_GENCODE_VISIT_TUPLE_BEGIN(visitor, hanoi, task_name, task_move_top_to_top_op, 5);
		PLNNR_GENCODE_VISIT_TUPLE_ELEMENT(visitor, tuple, 0);
		PLNNR_GENCODE_VISIT_TUPLE_ELEMENT(visitor, tuple, 1);
		PLNNR_GENCODE_VISIT_TUPLE_ELEMENT(visitor, tuple, 2);
		PLNNR_GENCODE_VISIT_TUPLE_ELEMENT(visitor, tuple, 3);
		PLNNR_GENCODE_VISIT_TUPLE_ELEMENT(visitor, tuple, 4);
		PLNNR_GENCODE_VISIT_TUPLE_END(visitor, hanoi, task_name, task_move_top_to_top_op, 5);
	}
};

template <typename V>
struct Generated_Type_Reflector<hanoi::move_single_to_clear_op_args, V>
{
	void operator()(const hanoi::move_single_to_clear_op_args& tuple, V& visitor)
	{
		PLNNR_GENCODE_VISIT_TUPLE_BEGIN(visitor, hanoi, task_name, task_move_single_to_clear_op, 3);
		PLNNR_GENCODE_VISIT_TUPLE_ELEMENT(visitor, tuple, 0);
		PLNNR_GENCODE_VISIT_TUPLE_ELEMENT(visitor, tuple, 1);
		PLNNR_GENCODE_VISIT_TUPLE_ELEMENT(visitor, tuple, 2);
		PLNNR_GENCODE_VISIT_TUPLE_END(visitor, hanoi, task_name, task_move_single_to_clear_op, 3);
	}
};

template <typename V>
struct Generated_Type_Reflector<hanoi::Move_Stack_args, V>
{
	void operator()(const hanoi::Move_Stack_args& tuple, V& visitor)
	{
		PLNNR_GENCODE_VISIT_TUPLE_BEGIN(visitor, hanoi, task_name, task_Move_Stack, 4);
		PLNNR_GENCODE_VISIT_TUPLE_ELEMENT(visitor, tuple, 0);
		PLNNR_GENCODE_VISIT_TUPLE_ELEMENT(visitor, tuple, 1);
		PLNNR_GENCODE_VISIT_TUPLE_ELEMENT(visitor, tuple, 2);
		PLNNR_GENCODE_VISIT_TUPLE_ELEMENT(visitor, tuple, 3);
		PLNNR_GENCODE_VISIT_TUPLE_END(visitor, hanoi, task_name, task_Move_Stack, 4);
	}
};

template <typename V>
struct Task_Type_Dispatcher<hanoi::Task_Type, V>
{
	void operator()(const hanoi::Task_Type& task_type, void* args, V& visitor)
	{
		switch (task_type)
		{
			case hanoi::task_root:
				PLNNR_GENCODE_VISIT_TASK_NO_ARGS(visitor, hanoi, task_root);
				break;
			case hanoi::task_Move_Stack:
				PLNNR_GENCODE_VISIT_TASK_WITH_ARGS(visitor, hanoi, task_Move_Stack, Move_Stack_args);
				break;
			case hanoi::task_move_top_to_clear_op:
				PLNNR_GENCODE_VISIT_TASK_WITH_ARGS(visitor, hanoi, task_move_top_to_clear_op, move_top_to_clear_op_args);
				break;
			case hanoi::task_move_single_to_top_op:
				PLNNR_GENCODE_VISIT_TASK_WITH_ARGS(visitor, hanoi, task_move_single_to_top_op, move_single_to_top_op_args);
				break;
			case hanoi::task_move_top_to_top_op:
				PLNNR_GENCODE_VISIT_TASK_WITH_ARGS(visitor, hanoi, task_move_top_to_top_op, move_top_to_top_op_args);
				break;
			case hanoi::task_move_single_to_clear_op:
				PLNNR_GENCODE_VISIT_TASK_WITH_ARGS(visitor, hanoi, task_move_single_to_clear_op, move_single_to_clear_op_args);
				break;
			default:
				plnnr_assert(false);
				break;
		}
	}
};

}

#endif

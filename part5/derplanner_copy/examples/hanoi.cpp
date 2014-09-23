#include "derplanner/runtime/runtime.h"
#include "hanoi.h"

using namespace plnnr;

#ifdef __GNUC__
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wunused-variable"
#endif

#ifdef _MSC_VER
#pragma warning(disable: 4100) // unreferenced formal parameter
#pragma warning(disable: 4189) // local variable is initialized but not referenced
#endif

#define PLNNR_COROUTINE_BEGIN(state) switch ((state).stage) { case 0:
#define PLNNR_COROUTINE_YIELD(state, label) (state).stage = label; return true; case label:;
#define PLNNR_COROUTINE_END() } return false

namespace hanoi {

static const char* atom_type_to_name[] =
{
	"disc",
	"loc",
	"startloc",
	"endloc",
	"clearloc",
	"clear",
	"top",
	"on_table",
	"on_other",
	"at",
	"on",
	"<none>",
};

const char* atom_name(Atom_Type type) { return atom_type_to_name[type]; }

}

namespace hanoi {

static const char* task_type_to_name[] =
{
	"!move_top_to_clear_op",
	"!move_single_to_top_op",
	"!move_top_to_top_op",
	"!move_single_to_clear_op",
	"root",
	"Move_Stack",
	"<none>",
};

const char* task_name(Task_Type type) { return task_type_to_name[type]; }

// method root [37:9]
struct p0_state
{
	// A [37:20]
	int _0;
	// C [37:31]
	int _1;
	// B [37:44]
	int _2;
	// bttm-disc [37:57]
	int _3;
	startloc_tuple* startloc_0;
	endloc_tuple* endloc_1;
	clearloc_tuple* clearloc_2;
	on_table_tuple* on_table_3;
	int stage;
};

bool next(p0_state& state, Worldstate& world)
{
	PLNNR_COROUTINE_BEGIN(state);

	for (state.startloc_0 = tuple_list::head<startloc_tuple>(world.atoms[atom_startloc]); state.startloc_0 != 0; state.startloc_0 = state.startloc_0->next)
	{
		state._0 = state.startloc_0->_0;

		for (state.endloc_1 = tuple_list::head<endloc_tuple>(world.atoms[atom_endloc]); state.endloc_1 != 0; state.endloc_1 = state.endloc_1->next)
		{
			state._1 = state.endloc_1->_0;

			for (state.clearloc_2 = tuple_list::head<clearloc_tuple>(world.atoms[atom_clearloc]); state.clearloc_2 != 0; state.clearloc_2 = state.clearloc_2->next)
			{
				state._2 = state.clearloc_2->_0;

				for (state.on_table_3 = tuple_list::head<on_table_tuple>(world.atoms[atom_on_table]); state.on_table_3 != 0; state.on_table_3 = state.on_table_3->next)
				{
					state._3 = state.on_table_3->_0;

					PLNNR_COROUTINE_YIELD(state, 4);
				}
			}
		}
	}

	PLNNR_COROUTINE_END();
}

// method Move_Stack [42:9]
struct p1_state
{
	// bttm-disc [42:16]
	int _0;
	// second-bttm [42:33]
	int _1;
	// xo [42:51]
	int _2;
	// xf [42:60]
	int _3;
	// xs [42:69]
	int _4;
	disc_tuple* disc_0;
	disc_tuple* disc_1;
	loc_tuple* loc_2;
	loc_tuple* loc_3;
	loc_tuple* loc_4;
	at_tuple* at_5;
	on_tuple* on_6;
	int stage;
};

bool next(p1_state& state, Worldstate& world)
{
	PLNNR_COROUTINE_BEGIN(state);

	for (state.disc_0 = tuple_list::head<disc_tuple>(world.atoms[atom_disc]); state.disc_0 != 0; state.disc_0 = state.disc_0->next)
	{
		if (state.disc_0->_0 != state._0)
		{
			continue;
		}

		for (state.disc_1 = tuple_list::head<disc_tuple>(world.atoms[atom_disc]); state.disc_1 != 0; state.disc_1 = state.disc_1->next)
		{
			state._1 = state.disc_1->_0;

			for (state.loc_2 = tuple_list::head<loc_tuple>(world.atoms[atom_loc]); state.loc_2 != 0; state.loc_2 = state.loc_2->next)
			{
				if (state.loc_2->_0 != state._2)
				{
					continue;
				}

				for (state.loc_3 = tuple_list::head<loc_tuple>(world.atoms[atom_loc]); state.loc_3 != 0; state.loc_3 = state.loc_3->next)
				{
					if (state.loc_3->_0 != state._3)
					{
						continue;
					}

					for (state.loc_4 = tuple_list::head<loc_tuple>(world.atoms[atom_loc]); state.loc_4 != 0; state.loc_4 = state.loc_4->next)
					{
						if (state.loc_4->_0 != state._4)
						{
							continue;
						}

						for (state.at_5 = tuple_list::head<at_tuple>(world.atoms[atom_at]); state.at_5 != 0; state.at_5 = state.at_5->next)
						{
							if (state.at_5->_0 != state._0)
							{
								continue;
							}

							if (state.at_5->_1 != state._2)
							{
								continue;
							}

							for (state.on_6 = tuple_list::head<on_tuple>(world.atoms[atom_on]); state.on_6 != 0; state.on_6 = state.on_6->next)
							{
								if (state.on_6->_0 != state._1)
								{
									continue;
								}

								if (state.on_6->_1 != state._0)
								{
									continue;
								}

								PLNNR_COROUTINE_YIELD(state, 7);
							}
						}
					}
				}
			}
		}
	}

	PLNNR_COROUTINE_END();
}

// method Move_Stack [45:9]
struct p2_state
{
	// bttm-disc [45:16]
	int _0;
	// xo [45:32]
	int _1;
	// xf [45:41]
	int _2;
	// xs [45:50]
	int _3;
	disc_tuple* disc_0;
	loc_tuple* loc_1;
	loc_tuple* loc_2;
	loc_tuple* loc_3;
	at_tuple* at_4;
	top_tuple* top_5;
	on_table_tuple* on_table_6;
	clear_tuple* clear_7;
	int stage;
};

bool next(p2_state& state, Worldstate& world)
{
	PLNNR_COROUTINE_BEGIN(state);

	for (state.disc_0 = tuple_list::head<disc_tuple>(world.atoms[atom_disc]); state.disc_0 != 0; state.disc_0 = state.disc_0->next)
	{
		if (state.disc_0->_0 != state._0)
		{
			continue;
		}

		for (state.loc_1 = tuple_list::head<loc_tuple>(world.atoms[atom_loc]); state.loc_1 != 0; state.loc_1 = state.loc_1->next)
		{
			if (state.loc_1->_0 != state._1)
			{
				continue;
			}

			for (state.loc_2 = tuple_list::head<loc_tuple>(world.atoms[atom_loc]); state.loc_2 != 0; state.loc_2 = state.loc_2->next)
			{
				if (state.loc_2->_0 != state._2)
				{
					continue;
				}

				for (state.loc_3 = tuple_list::head<loc_tuple>(world.atoms[atom_loc]); state.loc_3 != 0; state.loc_3 = state.loc_3->next)
				{
					if (state.loc_3->_0 != state._3)
					{
						continue;
					}

					for (state.at_4 = tuple_list::head<at_tuple>(world.atoms[atom_at]); state.at_4 != 0; state.at_4 = state.at_4->next)
					{
						if (state.at_4->_0 != state._0)
						{
							continue;
						}

						if (state.at_4->_1 != state._1)
						{
							continue;
						}

						for (state.top_5 = tuple_list::head<top_tuple>(world.atoms[atom_top]); state.top_5 != 0; state.top_5 = state.top_5->next)
						{
							if (state.top_5->_0 != state._0)
							{
								continue;
							}

							for (state.on_table_6 = tuple_list::head<on_table_tuple>(world.atoms[atom_on_table]); state.on_table_6 != 0; state.on_table_6 = state.on_table_6->next)
							{
								if (state.on_table_6->_0 != state._0)
								{
									continue;
								}

								for (state.clear_7 = tuple_list::head<clear_tuple>(world.atoms[atom_clear]); state.clear_7 != 0; state.clear_7 = state.clear_7->next)
								{
									if (state.clear_7->_0 != state._2)
									{
										continue;
									}

									PLNNR_COROUTINE_YIELD(state, 8);
								}
							}
						}
					}
				}
			}
		}
	}

	PLNNR_COROUTINE_END();
}

// method Move_Stack [48:9]
struct p3_state
{
	// bttm-disc [48:16]
	int _0;
	// xo [48:32]
	int _1;
	// xf [48:41]
	int _2;
	// xs [48:50]
	int _3;
	// below-bttm [48:102]
	int _4;
	disc_tuple* disc_0;
	loc_tuple* loc_1;
	loc_tuple* loc_2;
	loc_tuple* loc_3;
	at_tuple* at_4;
	top_tuple* top_5;
	on_tuple* on_6;
	clear_tuple* clear_7;
	int stage;
};

bool next(p3_state& state, Worldstate& world)
{
	PLNNR_COROUTINE_BEGIN(state);

	for (state.disc_0 = tuple_list::head<disc_tuple>(world.atoms[atom_disc]); state.disc_0 != 0; state.disc_0 = state.disc_0->next)
	{
		if (state.disc_0->_0 != state._0)
		{
			continue;
		}

		for (state.loc_1 = tuple_list::head<loc_tuple>(world.atoms[atom_loc]); state.loc_1 != 0; state.loc_1 = state.loc_1->next)
		{
			if (state.loc_1->_0 != state._1)
			{
				continue;
			}

			for (state.loc_2 = tuple_list::head<loc_tuple>(world.atoms[atom_loc]); state.loc_2 != 0; state.loc_2 = state.loc_2->next)
			{
				if (state.loc_2->_0 != state._2)
				{
					continue;
				}

				for (state.loc_3 = tuple_list::head<loc_tuple>(world.atoms[atom_loc]); state.loc_3 != 0; state.loc_3 = state.loc_3->next)
				{
					if (state.loc_3->_0 != state._3)
					{
						continue;
					}

					for (state.at_4 = tuple_list::head<at_tuple>(world.atoms[atom_at]); state.at_4 != 0; state.at_4 = state.at_4->next)
					{
						if (state.at_4->_0 != state._0)
						{
							continue;
						}

						if (state.at_4->_1 != state._1)
						{
							continue;
						}

						for (state.top_5 = tuple_list::head<top_tuple>(world.atoms[atom_top]); state.top_5 != 0; state.top_5 = state.top_5->next)
						{
							if (state.top_5->_0 != state._0)
							{
								continue;
							}

							for (state.on_6 = tuple_list::head<on_tuple>(world.atoms[atom_on]); state.on_6 != 0; state.on_6 = state.on_6->next)
							{
								if (state.on_6->_0 != state._0)
								{
									continue;
								}

								state._4 = state.on_6->_1;

								for (state.clear_7 = tuple_list::head<clear_tuple>(world.atoms[atom_clear]); state.clear_7 != 0; state.clear_7 = state.clear_7->next)
								{
									if (state.clear_7->_0 != state._2)
									{
										continue;
									}

									PLNNR_COROUTINE_YIELD(state, 8);
								}
							}
						}
					}
				}
			}
		}
	}

	PLNNR_COROUTINE_END();
}

// method Move_Stack [51:9]
struct p4_state
{
	// bttm-disc [51:16]
	int _0;
	// disc-other [51:33]
	int _1;
	// xo [51:50]
	int _2;
	// xf [51:59]
	int _3;
	// xs [51:68]
	int _4;
	disc_tuple* disc_0;
	disc_tuple* disc_1;
	loc_tuple* loc_2;
	loc_tuple* loc_3;
	loc_tuple* loc_4;
	at_tuple* at_5;
	at_tuple* at_6;
	top_tuple* top_7;
	top_tuple* top_8;
	on_table_tuple* on_table_9;
	int stage;
};

bool next(p4_state& state, Worldstate& world)
{
	PLNNR_COROUTINE_BEGIN(state);

	for (state.disc_0 = tuple_list::head<disc_tuple>(world.atoms[atom_disc]); state.disc_0 != 0; state.disc_0 = state.disc_0->next)
	{
		if (state.disc_0->_0 != state._0)
		{
			continue;
		}

		for (state.disc_1 = tuple_list::head<disc_tuple>(world.atoms[atom_disc]); state.disc_1 != 0; state.disc_1 = state.disc_1->next)
		{
			state._1 = state.disc_1->_0;

			for (state.loc_2 = tuple_list::head<loc_tuple>(world.atoms[atom_loc]); state.loc_2 != 0; state.loc_2 = state.loc_2->next)
			{
				if (state.loc_2->_0 != state._2)
				{
					continue;
				}

				for (state.loc_3 = tuple_list::head<loc_tuple>(world.atoms[atom_loc]); state.loc_3 != 0; state.loc_3 = state.loc_3->next)
				{
					if (state.loc_3->_0 != state._3)
					{
						continue;
					}

					for (state.loc_4 = tuple_list::head<loc_tuple>(world.atoms[atom_loc]); state.loc_4 != 0; state.loc_4 = state.loc_4->next)
					{
						if (state.loc_4->_0 != state._4)
						{
							continue;
						}

						for (state.at_5 = tuple_list::head<at_tuple>(world.atoms[atom_at]); state.at_5 != 0; state.at_5 = state.at_5->next)
						{
							if (state.at_5->_0 != state._0)
							{
								continue;
							}

							if (state.at_5->_1 != state._2)
							{
								continue;
							}

							for (state.at_6 = tuple_list::head<at_tuple>(world.atoms[atom_at]); state.at_6 != 0; state.at_6 = state.at_6->next)
							{
								if (state.at_6->_0 != state._1)
								{
									continue;
								}

								if (state.at_6->_1 != state._3)
								{
									continue;
								}

								for (state.top_7 = tuple_list::head<top_tuple>(world.atoms[atom_top]); state.top_7 != 0; state.top_7 = state.top_7->next)
								{
									if (state.top_7->_0 != state._1)
									{
										continue;
									}

									for (state.top_8 = tuple_list::head<top_tuple>(world.atoms[atom_top]); state.top_8 != 0; state.top_8 = state.top_8->next)
									{
										if (state.top_8->_0 != state._0)
										{
											continue;
										}

										for (state.on_table_9 = tuple_list::head<on_table_tuple>(world.atoms[atom_on_table]); state.on_table_9 != 0; state.on_table_9 = state.on_table_9->next)
										{
											if (state.on_table_9->_0 != state._0)
											{
												continue;
											}

											PLNNR_COROUTINE_YIELD(state, 10);
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

	PLNNR_COROUTINE_END();
}

// method Move_Stack [54:9]
struct p5_state
{
	// bttm-disc [54:16]
	int _0;
	// disc-other [54:33]
	int _1;
	// xo [54:50]
	int _2;
	// xf [54:59]
	int _3;
	// xs [54:68]
	int _4;
	// below-bttm [54:177]
	int _5;
	disc_tuple* disc_0;
	disc_tuple* disc_1;
	loc_tuple* loc_2;
	loc_tuple* loc_3;
	loc_tuple* loc_4;
	at_tuple* at_5;
	at_tuple* at_6;
	top_tuple* top_7;
	top_tuple* top_8;
	on_other_tuple* on_other_9;
	on_tuple* on_10;
	int stage;
};

bool next(p5_state& state, Worldstate& world)
{
	PLNNR_COROUTINE_BEGIN(state);

	for (state.disc_0 = tuple_list::head<disc_tuple>(world.atoms[atom_disc]); state.disc_0 != 0; state.disc_0 = state.disc_0->next)
	{
		if (state.disc_0->_0 != state._0)
		{
			continue;
		}

		for (state.disc_1 = tuple_list::head<disc_tuple>(world.atoms[atom_disc]); state.disc_1 != 0; state.disc_1 = state.disc_1->next)
		{
			state._1 = state.disc_1->_0;

			for (state.loc_2 = tuple_list::head<loc_tuple>(world.atoms[atom_loc]); state.loc_2 != 0; state.loc_2 = state.loc_2->next)
			{
				if (state.loc_2->_0 != state._2)
				{
					continue;
				}

				for (state.loc_3 = tuple_list::head<loc_tuple>(world.atoms[atom_loc]); state.loc_3 != 0; state.loc_3 = state.loc_3->next)
				{
					if (state.loc_3->_0 != state._3)
					{
						continue;
					}

					for (state.loc_4 = tuple_list::head<loc_tuple>(world.atoms[atom_loc]); state.loc_4 != 0; state.loc_4 = state.loc_4->next)
					{
						if (state.loc_4->_0 != state._4)
						{
							continue;
						}

						for (state.at_5 = tuple_list::head<at_tuple>(world.atoms[atom_at]); state.at_5 != 0; state.at_5 = state.at_5->next)
						{
							if (state.at_5->_0 != state._0)
							{
								continue;
							}

							if (state.at_5->_1 != state._2)
							{
								continue;
							}

							for (state.at_6 = tuple_list::head<at_tuple>(world.atoms[atom_at]); state.at_6 != 0; state.at_6 = state.at_6->next)
							{
								if (state.at_6->_0 != state._1)
								{
									continue;
								}

								if (state.at_6->_1 != state._3)
								{
									continue;
								}

								for (state.top_7 = tuple_list::head<top_tuple>(world.atoms[atom_top]); state.top_7 != 0; state.top_7 = state.top_7->next)
								{
									if (state.top_7->_0 != state._1)
									{
										continue;
									}

									for (state.top_8 = tuple_list::head<top_tuple>(world.atoms[atom_top]); state.top_8 != 0; state.top_8 = state.top_8->next)
									{
										if (state.top_8->_0 != state._0)
										{
											continue;
										}

										for (state.on_other_9 = tuple_list::head<on_other_tuple>(world.atoms[atom_on_other]); state.on_other_9 != 0; state.on_other_9 = state.on_other_9->next)
										{
											if (state.on_other_9->_0 != state._0)
											{
												continue;
											}

											for (state.on_10 = tuple_list::head<on_tuple>(world.atoms[atom_on]); state.on_10 != 0; state.on_10 = state.on_10->next)
											{
												if (state.on_10->_0 != state._0)
												{
													continue;
												}

												state._5 = state.on_10->_1;

												PLNNR_COROUTINE_YIELD(state, 11);
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

	PLNNR_COROUTINE_END();
}

bool root_branch_0_expand(Method_Instance* method, Planner_State& pstate, void* world)
{
	p0_state* precondition = plnnr::precondition<p0_state>(method);
	Worldstate* wstate = static_cast<Worldstate*>(world);

	PLNNR_COROUTINE_BEGIN(*method);

	precondition = push_precondition<p0_state>(pstate, method);

	while (next(*precondition, *wstate))
	{
		{
			Method_Instance* t = push_method(pstate, task_Move_Stack, Move_Stack_branch_0_expand);
			Move_Stack_args* a = push_arguments<Move_Stack_args>(pstate, t);
			a->_0 = precondition->_3;
			a->_1 = precondition->_0;
			a->_2 = precondition->_1;
			a->_3 = precondition->_2;
		}

		method->flags |= method_flags_expanded;
		PLNNR_COROUTINE_YIELD(*method, 1);
	}

	PLNNR_COROUTINE_END();
}

bool Move_Stack_branch_0_expand(Method_Instance* method, Planner_State& pstate, void* world)
{
	p1_state* precondition = plnnr::precondition<p1_state>(method);
	Move_Stack_args* method_args = plnnr::arguments<Move_Stack_args>(method);
	Worldstate* wstate = static_cast<Worldstate*>(world);

	PLNNR_COROUTINE_BEGIN(*method);

	precondition = push_precondition<p1_state>(pstate, method);
	precondition->_0 = method_args->_0;
	precondition->_2 = method_args->_1;
	precondition->_3 = method_args->_2;
	precondition->_4 = method_args->_3;

	while (next(*precondition, *wstate))
	{
		{
			Method_Instance* t = push_method(pstate, task_Move_Stack, Move_Stack_branch_0_expand);
			Move_Stack_args* a = push_arguments<Move_Stack_args>(pstate, t);
			a->_0 = precondition->_1;
			a->_1 = method_args->_1;
			a->_2 = method_args->_3;
			a->_3 = method_args->_2;
		}

		PLNNR_COROUTINE_YIELD(*method, 1);

		if (method->flags & method_flags_failed)
		{
			continue;
		}

		{
			Method_Instance* t = push_method(pstate, task_Move_Stack, Move_Stack_branch_0_expand);
			Move_Stack_args* a = push_arguments<Move_Stack_args>(pstate, t);
			a->_0 = method_args->_0;
			a->_1 = method_args->_1;
			a->_2 = method_args->_2;
			a->_3 = method_args->_3;
		}

		PLNNR_COROUTINE_YIELD(*method, 2);

		if (method->flags & method_flags_failed)
		{
			continue;
		}

		{
			Method_Instance* t = push_method(pstate, task_Move_Stack, Move_Stack_branch_0_expand);
			Move_Stack_args* a = push_arguments<Move_Stack_args>(pstate, t);
			a->_0 = precondition->_1;
			a->_1 = method_args->_3;
			a->_2 = method_args->_2;
			a->_3 = method_args->_1;
		}

		method->flags |= method_flags_expanded;
		PLNNR_COROUTINE_YIELD(*method, 3);
	}

	return expand_next_branch(pstate, Move_Stack_branch_1_expand, world);
	PLNNR_COROUTINE_END();
}

bool Move_Stack_branch_1_expand(Method_Instance* method, Planner_State& pstate, void* world)
{
	p2_state* precondition = plnnr::precondition<p2_state>(method);
	Move_Stack_args* method_args = plnnr::arguments<Move_Stack_args>(method);
	Worldstate* wstate = static_cast<Worldstate*>(world);

	PLNNR_COROUTINE_BEGIN(*method);

	precondition = push_precondition<p2_state>(pstate, method);
	precondition->_0 = method_args->_0;
	precondition->_1 = method_args->_1;
	precondition->_2 = method_args->_2;
	precondition->_3 = method_args->_3;

	while (next(*precondition, *wstate))
	{
		{
			Task_Instance* t = push_task(pstate, task_move_single_to_clear_op, 0);
			move_single_to_clear_op_args* a = push_arguments<move_single_to_clear_op_args>(pstate, t);
			a->_0 = method_args->_0;
			a->_1 = method_args->_1;
			a->_2 = method_args->_2;

			for (clear_tuple* tuple = tuple_list::head<clear_tuple>(wstate->atoms[atom_clear]); tuple != 0; tuple = tuple->next)
			{
				if (tuple->_0 != a->_2)
				{
					continue;
				}

				tuple_list::Handle* list = wstate->atoms[atom_clear];
				Operator_Effect* effect = push<Operator_Effect>(pstate.journal);
				effect->tuple = tuple;
				effect->list = list;
				tuple_list::detach(list, tuple);

				break;
			}

			for (at_tuple* tuple = tuple_list::head<at_tuple>(wstate->atoms[atom_at]); tuple != 0; tuple = tuple->next)
			{
				if (tuple->_0 != a->_0)
				{
					continue;
				}

				if (tuple->_1 != a->_1)
				{
					continue;
				}

				tuple_list::Handle* list = wstate->atoms[atom_at];
				Operator_Effect* effect = push<Operator_Effect>(pstate.journal);
				effect->tuple = tuple;
				effect->list = list;
				tuple_list::detach(list, tuple);

				break;
			}

			{
				tuple_list::Handle* list = wstate->atoms[atom_clear];
				clear_tuple* tuple = tuple_list::append<clear_tuple>(list);
				tuple->_0 = a->_1;
				Operator_Effect* effect = push<Operator_Effect>(pstate.journal);
				effect->tuple = tuple;
				effect->list = list;
			}

			{
				tuple_list::Handle* list = wstate->atoms[atom_at];
				at_tuple* tuple = tuple_list::append<at_tuple>(list);
				tuple->_0 = a->_0;
				tuple->_1 = a->_2;
				Operator_Effect* effect = push<Operator_Effect>(pstate.journal);
				effect->tuple = tuple;
				effect->list = list;
			}
		}

		method->flags |= method_flags_expanded;
		PLNNR_COROUTINE_YIELD(*method, 1);
	}

	return expand_next_branch(pstate, Move_Stack_branch_2_expand, world);
	PLNNR_COROUTINE_END();
}

bool Move_Stack_branch_2_expand(Method_Instance* method, Planner_State& pstate, void* world)
{
	p3_state* precondition = plnnr::precondition<p3_state>(method);
	Move_Stack_args* method_args = plnnr::arguments<Move_Stack_args>(method);
	Worldstate* wstate = static_cast<Worldstate*>(world);

	PLNNR_COROUTINE_BEGIN(*method);

	precondition = push_precondition<p3_state>(pstate, method);
	precondition->_0 = method_args->_0;
	precondition->_1 = method_args->_1;
	precondition->_2 = method_args->_2;
	precondition->_3 = method_args->_3;

	while (next(*precondition, *wstate))
	{
		{
			Task_Instance* t = push_task(pstate, task_move_top_to_clear_op, 0);
			move_top_to_clear_op_args* a = push_arguments<move_top_to_clear_op_args>(pstate, t);
			a->_0 = method_args->_0;
			a->_1 = precondition->_4;
			a->_2 = method_args->_1;
			a->_3 = method_args->_2;

			for (clear_tuple* tuple = tuple_list::head<clear_tuple>(wstate->atoms[atom_clear]); tuple != 0; tuple = tuple->next)
			{
				if (tuple->_0 != a->_3)
				{
					continue;
				}

				tuple_list::Handle* list = wstate->atoms[atom_clear];
				Operator_Effect* effect = push<Operator_Effect>(pstate.journal);
				effect->tuple = tuple;
				effect->list = list;
				tuple_list::detach(list, tuple);

				break;
			}

			for (at_tuple* tuple = tuple_list::head<at_tuple>(wstate->atoms[atom_at]); tuple != 0; tuple = tuple->next)
			{
				if (tuple->_0 != a->_0)
				{
					continue;
				}

				if (tuple->_1 != a->_2)
				{
					continue;
				}

				tuple_list::Handle* list = wstate->atoms[atom_at];
				Operator_Effect* effect = push<Operator_Effect>(pstate.journal);
				effect->tuple = tuple;
				effect->list = list;
				tuple_list::detach(list, tuple);

				break;
			}

			for (on_other_tuple* tuple = tuple_list::head<on_other_tuple>(wstate->atoms[atom_on_other]); tuple != 0; tuple = tuple->next)
			{
				if (tuple->_0 != a->_0)
				{
					continue;
				}

				tuple_list::Handle* list = wstate->atoms[atom_on_other];
				Operator_Effect* effect = push<Operator_Effect>(pstate.journal);
				effect->tuple = tuple;
				effect->list = list;
				tuple_list::detach(list, tuple);

				break;
			}

			for (on_tuple* tuple = tuple_list::head<on_tuple>(wstate->atoms[atom_on]); tuple != 0; tuple = tuple->next)
			{
				if (tuple->_0 != a->_0)
				{
					continue;
				}

				if (tuple->_1 != a->_1)
				{
					continue;
				}

				tuple_list::Handle* list = wstate->atoms[atom_on];
				Operator_Effect* effect = push<Operator_Effect>(pstate.journal);
				effect->tuple = tuple;
				effect->list = list;
				tuple_list::detach(list, tuple);

				break;
			}

			{
				tuple_list::Handle* list = wstate->atoms[atom_top];
				top_tuple* tuple = tuple_list::append<top_tuple>(list);
				tuple->_0 = a->_1;
				Operator_Effect* effect = push<Operator_Effect>(pstate.journal);
				effect->tuple = tuple;
				effect->list = list;
			}

			{
				tuple_list::Handle* list = wstate->atoms[atom_at];
				at_tuple* tuple = tuple_list::append<at_tuple>(list);
				tuple->_0 = a->_0;
				tuple->_1 = a->_3;
				Operator_Effect* effect = push<Operator_Effect>(pstate.journal);
				effect->tuple = tuple;
				effect->list = list;
			}

			{
				tuple_list::Handle* list = wstate->atoms[atom_on_table];
				on_table_tuple* tuple = tuple_list::append<on_table_tuple>(list);
				tuple->_0 = a->_0;
				Operator_Effect* effect = push<Operator_Effect>(pstate.journal);
				effect->tuple = tuple;
				effect->list = list;
			}
		}

		method->flags |= method_flags_expanded;
		PLNNR_COROUTINE_YIELD(*method, 1);
	}

	return expand_next_branch(pstate, Move_Stack_branch_3_expand, world);
	PLNNR_COROUTINE_END();
}

bool Move_Stack_branch_3_expand(Method_Instance* method, Planner_State& pstate, void* world)
{
	p4_state* precondition = plnnr::precondition<p4_state>(method);
	Move_Stack_args* method_args = plnnr::arguments<Move_Stack_args>(method);
	Worldstate* wstate = static_cast<Worldstate*>(world);

	PLNNR_COROUTINE_BEGIN(*method);

	precondition = push_precondition<p4_state>(pstate, method);
	precondition->_0 = method_args->_0;
	precondition->_2 = method_args->_1;
	precondition->_3 = method_args->_2;
	precondition->_4 = method_args->_3;

	while (next(*precondition, *wstate))
	{
		{
			Task_Instance* t = push_task(pstate, task_move_single_to_top_op, 0);
			move_single_to_top_op_args* a = push_arguments<move_single_to_top_op_args>(pstate, t);
			a->_0 = method_args->_0;
			a->_1 = precondition->_1;
			a->_2 = method_args->_1;
			a->_3 = method_args->_2;

			for (top_tuple* tuple = tuple_list::head<top_tuple>(wstate->atoms[atom_top]); tuple != 0; tuple = tuple->next)
			{
				if (tuple->_0 != a->_1)
				{
					continue;
				}

				tuple_list::Handle* list = wstate->atoms[atom_top];
				Operator_Effect* effect = push<Operator_Effect>(pstate.journal);
				effect->tuple = tuple;
				effect->list = list;
				tuple_list::detach(list, tuple);

				break;
			}

			for (at_tuple* tuple = tuple_list::head<at_tuple>(wstate->atoms[atom_at]); tuple != 0; tuple = tuple->next)
			{
				if (tuple->_0 != a->_0)
				{
					continue;
				}

				if (tuple->_1 != a->_2)
				{
					continue;
				}

				tuple_list::Handle* list = wstate->atoms[atom_at];
				Operator_Effect* effect = push<Operator_Effect>(pstate.journal);
				effect->tuple = tuple;
				effect->list = list;
				tuple_list::detach(list, tuple);

				break;
			}

			for (on_table_tuple* tuple = tuple_list::head<on_table_tuple>(wstate->atoms[atom_on_table]); tuple != 0; tuple = tuple->next)
			{
				if (tuple->_0 != a->_0)
				{
					continue;
				}

				tuple_list::Handle* list = wstate->atoms[atom_on_table];
				Operator_Effect* effect = push<Operator_Effect>(pstate.journal);
				effect->tuple = tuple;
				effect->list = list;
				tuple_list::detach(list, tuple);

				break;
			}

			{
				tuple_list::Handle* list = wstate->atoms[atom_clear];
				clear_tuple* tuple = tuple_list::append<clear_tuple>(list);
				tuple->_0 = a->_2;
				Operator_Effect* effect = push<Operator_Effect>(pstate.journal);
				effect->tuple = tuple;
				effect->list = list;
			}

			{
				tuple_list::Handle* list = wstate->atoms[atom_at];
				at_tuple* tuple = tuple_list::append<at_tuple>(list);
				tuple->_0 = a->_0;
				tuple->_1 = a->_3;
				Operator_Effect* effect = push<Operator_Effect>(pstate.journal);
				effect->tuple = tuple;
				effect->list = list;
			}

			{
				tuple_list::Handle* list = wstate->atoms[atom_on_other];
				on_other_tuple* tuple = tuple_list::append<on_other_tuple>(list);
				tuple->_0 = a->_0;
				Operator_Effect* effect = push<Operator_Effect>(pstate.journal);
				effect->tuple = tuple;
				effect->list = list;
			}

			{
				tuple_list::Handle* list = wstate->atoms[atom_on];
				on_tuple* tuple = tuple_list::append<on_tuple>(list);
				tuple->_0 = a->_0;
				tuple->_1 = a->_1;
				Operator_Effect* effect = push<Operator_Effect>(pstate.journal);
				effect->tuple = tuple;
				effect->list = list;
			}
		}

		method->flags |= method_flags_expanded;
		PLNNR_COROUTINE_YIELD(*method, 1);
	}

	return expand_next_branch(pstate, Move_Stack_branch_4_expand, world);
	PLNNR_COROUTINE_END();
}

bool Move_Stack_branch_4_expand(Method_Instance* method, Planner_State& pstate, void* world)
{
	p5_state* precondition = plnnr::precondition<p5_state>(method);
	Move_Stack_args* method_args = plnnr::arguments<Move_Stack_args>(method);
	Worldstate* wstate = static_cast<Worldstate*>(world);

	PLNNR_COROUTINE_BEGIN(*method);

	precondition = push_precondition<p5_state>(pstate, method);
	precondition->_0 = method_args->_0;
	precondition->_2 = method_args->_1;
	precondition->_3 = method_args->_2;
	precondition->_4 = method_args->_3;

	while (next(*precondition, *wstate))
	{
		{
			Task_Instance* t = push_task(pstate, task_move_top_to_top_op, 0);
			move_top_to_top_op_args* a = push_arguments<move_top_to_top_op_args>(pstate, t);
			a->_0 = method_args->_0;
			a->_1 = precondition->_5;
			a->_2 = precondition->_1;
			a->_3 = method_args->_1;
			a->_4 = method_args->_2;

			for (top_tuple* tuple = tuple_list::head<top_tuple>(wstate->atoms[atom_top]); tuple != 0; tuple = tuple->next)
			{
				if (tuple->_0 != a->_2)
				{
					continue;
				}

				tuple_list::Handle* list = wstate->atoms[atom_top];
				Operator_Effect* effect = push<Operator_Effect>(pstate.journal);
				effect->tuple = tuple;
				effect->list = list;
				tuple_list::detach(list, tuple);

				break;
			}

			for (at_tuple* tuple = tuple_list::head<at_tuple>(wstate->atoms[atom_at]); tuple != 0; tuple = tuple->next)
			{
				if (tuple->_0 != a->_0)
				{
					continue;
				}

				if (tuple->_1 != a->_3)
				{
					continue;
				}

				tuple_list::Handle* list = wstate->atoms[atom_at];
				Operator_Effect* effect = push<Operator_Effect>(pstate.journal);
				effect->tuple = tuple;
				effect->list = list;
				tuple_list::detach(list, tuple);

				break;
			}

			for (on_tuple* tuple = tuple_list::head<on_tuple>(wstate->atoms[atom_on]); tuple != 0; tuple = tuple->next)
			{
				if (tuple->_0 != a->_0)
				{
					continue;
				}

				if (tuple->_1 != a->_1)
				{
					continue;
				}

				tuple_list::Handle* list = wstate->atoms[atom_on];
				Operator_Effect* effect = push<Operator_Effect>(pstate.journal);
				effect->tuple = tuple;
				effect->list = list;
				tuple_list::detach(list, tuple);

				break;
			}

			{
				tuple_list::Handle* list = wstate->atoms[atom_top];
				top_tuple* tuple = tuple_list::append<top_tuple>(list);
				tuple->_0 = a->_1;
				Operator_Effect* effect = push<Operator_Effect>(pstate.journal);
				effect->tuple = tuple;
				effect->list = list;
			}

			{
				tuple_list::Handle* list = wstate->atoms[atom_at];
				at_tuple* tuple = tuple_list::append<at_tuple>(list);
				tuple->_0 = a->_0;
				tuple->_1 = a->_4;
				Operator_Effect* effect = push<Operator_Effect>(pstate.journal);
				effect->tuple = tuple;
				effect->list = list;
			}

			{
				tuple_list::Handle* list = wstate->atoms[atom_on];
				on_tuple* tuple = tuple_list::append<on_tuple>(list);
				tuple->_0 = a->_0;
				tuple->_1 = a->_2;
				Operator_Effect* effect = push<Operator_Effect>(pstate.journal);
				effect->tuple = tuple;
				effect->list = list;
			}
		}

		method->flags |= method_flags_expanded;
		PLNNR_COROUTINE_YIELD(*method, 1);
	}

	PLNNR_COROUTINE_END();
}

}

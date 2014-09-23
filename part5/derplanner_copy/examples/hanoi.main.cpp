#include <stdio.h>
#include <string.h>
#include <vector>
#include <iostream>
#include <derplanner/runtime/runtime.h>
#include <derplanner/runtime/interface.h>
#include <derplanner/runtime/world_printf.h>
#include "hanoi.h"
#include <stdlib.h>
#include <time.h>

using namespace plnnr;
using namespace hanoi;
using namespace std;

int main()
{
    const size_t tuple_list_page = 1024;
    const int num_discs = 12;
    const int A = 0;
    const int B = 1;
    const int C = 2;

    hanoi::Worldstate world_struct;
    memset(&world_struct, 0, sizeof(world_struct));

    world_struct.atoms[atom_disc] = tuple_list::create<disc_tuple>(num_discs);
    world_struct.atoms[atom_loc] = tuple_list::create<loc_tuple>(3);
    world_struct.atoms[atom_startloc] = tuple_list::create<startloc_tuple>(1);
    world_struct.atoms[atom_endloc] = tuple_list::create<endloc_tuple>(1);
    world_struct.atoms[atom_clearloc] = tuple_list::create<clearloc_tuple>(1);
    world_struct.atoms[atom_clear] = tuple_list::create<clear_tuple>(tuple_list_page);
    world_struct.atoms[atom_top] = tuple_list::create<top_tuple>(tuple_list_page);
    world_struct.atoms[atom_on_table] = tuple_list::create<on_table_tuple>(tuple_list_page);
    world_struct.atoms[atom_on_other] = tuple_list::create<on_other_tuple>(tuple_list_page);
    world_struct.atoms[atom_at] = tuple_list::create<at_tuple>(tuple_list_page);
    world_struct.atoms[atom_on] = tuple_list::create<on_tuple>(tuple_list_page);

    plnnr::Worldstate world(&world_struct);

    // Set world state for each disc
    for (int i = 0; i < num_discs; i++)
    {
        world.append(atom<disc_tuple>(i));
        if (i == 0)
        {
            world.append(atom<on_table_tuple>(i));
        }
        else
        {
            world.append(atom<on_other_tuple>(i));
            world.append(atom<on_tuple>(i, i-1));
        }
        world.append(atom<at_tuple>(i, A));
    }
    world.append(atom<top_tuple>(num_discs-1)); // Top disc is "top"

    // Set up 3 locations, with B & C clear
    world.append(atom<loc_tuple>(A));
    world.append(atom<loc_tuple>(B));
    world.append(atom<loc_tuple>(C));
    world.append(atom<clear_tuple>(B));
    world.append(atom<clear_tuple>(C));
    world.append(atom<startloc_tuple>(A));
    world.append(atom<endloc_tuple>(C));
    world.append(atom<clearloc_tuple>(B));

    World_Printf printer;
    plnnr::reflect(world_struct, printer);

    plnnr::Stack methods(3276820);
    plnnr::Stack tasks(3276820);
    plnnr::Stack jstack(3276820);
    plnnr::Stack trace(3276820);

    Planner_State pstate;
    pstate.top_method = 0;
    pstate.top_task = 0;
    pstate.methods = &methods;
    pstate.tasks = &tasks;
    pstate.journal = &jstack;
    pstate.trace = &trace;


    clock_t start = clock();
    find_plan_init(pstate, hanoi::task_root, hanoi::root_branch_0_expand);

    Find_Plan_Status status = plan_in_progress;
    while (status == plan_in_progress)
    {
        //cout << "-----------------------" << endl << endl;
        status = find_plan_step(pstate, world.data());
        //plnnr::reflect(world_struct, printer);
    }

    if (status == plan_found)
    {
        printf("\nplan found:\n\n");
        Task_Instance* task = bottom<Task_Instance>(pstate.tasks);
        task_printf task_printer;
        plnnr::walk_stack_up<hanoi::Task_Type>(task, task_printer);
    }
    else
    {
        printf("plan not found.\n");
    }
    clock_t end = clock();

    unsigned long micros = end - start;
    double millis = micros / 1000;

    cout << "Elapsed Time: " << millis << " ms" << endl;

    return 0;
}

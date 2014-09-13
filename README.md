RIPFall2014P1
=============

Repository for Homework 1 for CS 4649/7649

Blackbox and ff planners are stored in the planners directory. They are 32-bit linux executables, do not work on 64 bit machines.

The usage is something like this
./planner -o domain.pddl -f problem.pddl

For example, to run blackbox on the hanoi problem, in the part1 directory, 
$ ../planners/blackbox -o hanoi-domain.pddl -f hanoi2.pddl

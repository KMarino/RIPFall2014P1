How to Run Sokoban Planner
-------------------------------------------------------------------------------

System Requirements:
-These planners are platform dependent, you will need 32-bit Linux to run them.

-------------------------------------------------------------------------------
How to Run:

Step 1: Open Terminal

Step 2: Go to the directory where the PDDL files with the domain and problems are located.

Step 3: From the terminal run the following line to run with ff planner:
../planners/ff -o sokoban-domain.pddl -f sokobanP2-1.pddl

(In the above line substitute "sokobanP2-1.pddl" with the name of the problem you wish to run. Change "ff" to blackbox in the above line to run with black box planner)

Note: In the above line it is assumed that your planners are under a folder called "planners". Make sure to change the line accordingly depending of your directory names and locations.

-------------------------------------------------------------------------------




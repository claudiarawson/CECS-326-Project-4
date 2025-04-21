# CECS-326-Project-4
Group: Reichen Brown (ID: 029657509) & Claudia Rawson (ID: 030782685)


## GOAL
An implementation of the following scheduling algorithms:
    - FCFS
    - Priority
    - Round Robin


## SUMMARY
The project files contain a Makefile that will compile the code and provide a run function.

To begin, the directory should contain the following files:

    1. book.txt
    2. CPU.c
    3. cpu.h
    4. driver.c
    5. list.c
    6. list.h
    7. Makefile
    8. pri-schedule.txt
    9. README.md
    10. rr-schedule.txt
    11. schedule_fcfs.c
    12. schedule_priority.c 
    13. schedule_rr.c
    14. schedule.txt
    15. schedulers.h
    16. task.h

Commands provided by the Makefile:

    1. make rr
    2. make fcfs
    3. make priority
    4. make clean

## HOW TO RUN
**Command: make rr**

    To compile the code, use the "make" command in the terminal by typing: make rr
        (RR) scheduling, where each task is run for a time quantum (or for the
        remainder of its CPU burst).
    
**Command: make fcfs**

    Use the "fcfs" command in the terminal by typing: make fcfs
        (FCFS), which schedules tasks in the order in which they request
        the CPU.

**Command: make priority**
    Use the "priority" command in the terminal by typing: make priority
        (Priority Scheduling), which schedules tasks based on priority

**Command: make clean**

    For more tests, you can remove the output files using "make clean"
        This should clean up your directory from previous test outputs.
/*
 * Priority scheduling
 */
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

#include "task.h"
#include "list.h"
#include "cpu.h"

struct node *head = NULL;

void add(char *name, int priority, int burst) {
    static int tid = 1;  // Unique task ID

    Task *newTask = malloc(sizeof(Task));
    newTask->name = name;
    newTask->priority = priority;
    newTask->burst = burst;
    newTask->tid = tid++;

    insert(&head, newTask);
}

void schedule() {
    while (head != NULL) {
        struct node *highest = head;
        struct node *current = head;

        while (current != NULL) {
            if (current->task->priority < highest->task->priority) {
                highest = current;
            }
            current = current->next;
        }

        Task *selected = highest->task;
        run(selected, selected->burst);
        delete(&head, selected);
    }
}

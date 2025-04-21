/**
 * Round-robin scheduling
 */

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

#include "task.h"
#include "list.h"
#include "cpu.h"


/*
 * Your code and design here:
 */

 // Global head of the list
struct node *head = NULL;

 // Function to add task (called by driver.c)
void add(char *name, int priority, int burst) {
    static int tid = 1;  // Unique task ID

    Task *newTask = malloc(sizeof(Task));
    newTask->name = name;
    newTask->priority = priority;
    newTask->burst = burst;
    newTask->tid = tid++;

    insert(&head, newTask);
}

// Reverse the linked list (due to list.c implementation)
struct node* reverseList(struct node* head) {
    struct node* prev = NULL;
    struct node* curr = head;
    struct node* next = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

// Round-robin schedule
void schedule() {
    head = reverseList(head);

    struct node *temp;

    while (head != NULL) {
        temp = head;
        struct node *prev = NULL;

        while (temp != NULL) {
            Task *t = temp->task;
            int run_time = (t->burst > QUANTUM) ? QUANTUM : t->burst;

            run(t, run_time);
            t->burst -= run_time;

            // If task is done, remove it
            if (t->burst <= 0) {
                struct node *to_delete = temp;
                temp = temp->next;

                if (prev == NULL) {
                    head = temp;
                } else {
                    prev->next = temp;
                }

                free(to_delete->task);
                free(to_delete);
            } else {
                // Move to next task
                prev = temp;
                temp = temp->next;
            }
        }
    }
}
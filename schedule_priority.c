/*
 * Priority scheduling
 */
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

#include "task.h"
#include "list.h"
#include "cpu.h"

struct node *head = NULL; // Linked List Head Pointer

// Function to add task (called by driver.c)
void add(char *name, int priority, int burst) {
    // Initialize Task 
    Task *newTask = malloc(sizeof(Task));
    newTask->name = name;
    newTask->priority = priority;
    newTask->burst = burst;

    // list.c insert
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

// Priority scheduling
void schedule() {
    head = reverseList(head); // reverse the list to work with list.c implementation (FIFO)

    while (head != NULL) {
        // nodes for priority
        struct node *highest = head;
        struct node *current = head;

        while (current != NULL) {
            if (current->task->priority > highest->task->priority) { // Decide priority task order
                highest = current;
            }
            // current list (ordered by priority)
            current = current->next;
        }

        // run
        Task *selected = highest->task;
        run(selected, selected->burst);
        delete(&head, selected);
    }
}

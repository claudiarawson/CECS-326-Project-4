/**
 * FCFS scheduling
 */
 
#include <stdlib.h>
#include <stdio.h>

#include "task.h"
#include "list.h"
#include "cpu.h"

//Your code and design here

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

// FCFS Scheduling
void schedule() {
    head = reverseList(head); // reverse the list to work with list.c implementation (FIFO)

    struct node *temp = head; // start at head of list and run one-by-one
    while (temp != NULL) {
        run(temp->task, temp->task->burst);
        temp = temp->next;
    }
}
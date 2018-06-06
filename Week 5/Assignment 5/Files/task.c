/*
 * CS 261 Assignment 5
 * Name: Eddie C. Fox
 * Date: July 31, 2016
 */

#include "task.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>

/**
 * Creates a new task with the given priority and name.
 * @param priority
 * @param name
 * @return  The new task.
 */
Task* taskNew(int priority, char* name)
{
    // FIXME: implement
	Task* newTask = malloc(sizeof(Task));
	newTask->priority = priority; 
	strcpy(newTask->name, name);

	return newTask;
}

/**
 * Frees a dynamically allocated task.
 * @param task
 */
void taskDelete(Task* task)
{
    free(task);
}

/**
 * Casts left and right to Task pointers and returns
 * -1 if left's priority < right's priority,
 *  1 if left's priority > right's priority,
 *  0 if left's priority == right's priority.
 * @param left  Task pointer.
 * @param right  Task pointer.
 * @return 
 */
int taskCompare(void* left, void* right)
{
    // FIXME: implement
	
	Task* task1 = (Task*)left;
	Task* task2 = (Task*)right;

	if (task1->priority < task2->priority)
	{
		return -1;
	}

	else if (task1->priority > task2->priority)
	{
		return 1;
	}

	else
	{
		if (task1->name < task2->name)
		{
			return -1;
		}

		else if (task1->name > task2->name)
		{
			return 1;
		}

		else (task1->name == task2->name)
		{
			return 0;
		}
	}
}

/**
 * Prints a task as a (priority, name) pair.
 * @param value  Task pointer.
 */
void taskPrint(void* value)
{
    Task* task = (Task*)value;
    printf("%s", task->name);
}

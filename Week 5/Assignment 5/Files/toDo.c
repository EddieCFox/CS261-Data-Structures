/*
 * CS 261 Assignment 5
 * Name: Eddie C. Fox
 * Date: July 31, 2016
 */

#include "dynamicArray.h"
#include "task.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>



/**
*Compares a task with each task already in the heap.   
*@param heap
*@param the new task to compare to the heap 
*@Returns: 0 if not present, 1 if present  
*/

int duplicateCheck(DynamicArray *heap, struct Task *task)
{
 // FIXME: Implement
	
	int size = dySize(heap);

	for (int i = 0; i < size; i++) 
		/* Iterate through the array of Task pointer.*/
	{
		if (taskCompare(task, dyGet(heap, i)) == 0)
		{
			return 1;
		}
	}

	return 0;
}

/**
 * Loads into heap a list from a file with lines formatted like
 * "priority, name".
 * @param heap
 * @param file
 */

void listLoad(DynamicArray* heap, FILE* file)
{
	const int FORMAT_LENGTH = 256;
	char format[FORMAT_LENGTH];
	snprintf(format, FORMAT_LENGTH, "%%d, %%%d[^\n]", TASK_NAME_SIZE);

	Task temp;
	while (fscanf(file, format, &temp.priority, &temp.name) == 2)
	{
		struct Task *newTask = taskNew(temp.priority, temp.name);
			if (duplicateCheck(heap, newTask) == 0) {
				dyHeapAdd(heap, newTask, taskCompare);
			}
	}
}

/**
 * Writes to a file all tasks in heap with lines formatted like
 * "priority, name".
 * @param heap
 * @param file
 */
void listSave(DynamicArray* heap, FILE* file)
{
	for (int i = 0; i < dySize(heap); i++)
	{
		Task* task = dyGet(heap, i);
		fprintf(file, "%d, %s\n", task->priority, task->name);
	}
}

/**
 * Prints every task in heap.
 * @param heap
 */
void listPrint(DynamicArray* heap)
{
    DynamicArray* temp = dyNew(1);
    dyCopy(heap, temp);
    while (dySize(temp) > 0) /* Changed dySize(heap) to dySize(temp) to prevent infinite loop until crash.*/
    {
        Task* task = dyHeapGetMin(temp);
        printf("\n");
        taskPrint(task);
        printf("\n");
        dyHeapRemoveMin(temp, taskCompare);
    }
    dyDelete(temp);
}

/**
 * Handles the given command.
 * @param list
 * @param command
 */
void handleCommand(DynamicArray* list, char command)
{
    // FIXME: Implement

	char *newlinePointer; /* Pointer to newline character in filename string*/
	FILE *filePointer; /* Pointer to file that is to be opened.*/
	char filename[100]; // C-string to hold read filename from user.
	char taskName[100]; // C-string to hold task name from user.
	int priority; // Holds entered priority.
	Task *newTask;
	Task *firstTask;

	switch (command)
	{

	case 'l': /* "Load to-do list from a file.*/
		{
			printf("Please enter a filename to load from:\n");
			if (fgets(filename, sizeof(filename), stdin) != NULL) /* If file name isn't empty*/
			{
				newlinePointer = strchr(filename, '\n'); /* Sets newlinePointer to the newline within the filename string.
														 There will inevitably be one because the user must press enter 
														 after the filename, and that enter is read as a newline.*/
				if (newlinePointer) /* If newline pointer is detected at the end of the name string*/
				{
					*newlinePointer = '\0'; /* Modify newline pointer to equal null terminator, so nothing else is read.*/
				}
			}

			filePointer = fopen(filename, "r"); /* Open file in read mode.*/
			if (filePointer == NULL) /* If the file failed to open*/
			{
				printf("Failed to open file: %s\n", filename);
				break;
			}

			else
			{
				listLoad(list, filePointer); /* Load file*/
				fclose(filePointer); /* Close file*/
				printf("The list has been loaded from file successfully.\n\n");
				break;
			}
		}

	case 's': /* Save to-do list to a file */
		{
			if (dySize(list) <= 0) /* If array is empty, print that it is emptyu and break execution*/
			{
				printf("This to-do list is empty.\n\n");
				break;
			}

			else
			{
				printf("Please enter a filename to save to:\n");
				if (fgets(filename, sizeof(filename), stdin) != NULL) /* If file name isn't empty*/
				{
					newlinePointer = strchr(filename, '\n'); /* Sets newlinePointer to the newline within the filename string.
															 There will inevitably be one because the user must press enter
															 after the filename, and that enter is read as a newline.*/
					if (newlinePointer) /* If newline pointer is detected at the end of the name string*/
					{
						*newlinePointer = '\0'; /* Modify newline pointer to equal null terminator, so nothing else is read.*/
					}
				}

				filePointer = fopen(filename, "w"); /* Open file in write mode.*/
				
				if (filePointer == NULL)
				{
					printf("Could not open file.\n\n");
					break;
				}

				else
				{
					listSave(list, filePointer);
					fclose(filePointer);
					printf("List saved.\n\n");
					break;
				}
			}
		}

	case 'a': /* Add task to node.*/
		{
			printf("Please enter task name: ");
			if (fgets(taskName, sizeof(taskName), stdin) != NULL)
			{
				newlinePointer = strchr(filename, '\n'); /* Sets newlinePointer to the newline within the filename string.
														 There will inevitably be one because the user must press enter
														 after the filename, and that enter is read as a newline.*/
				if (newlinePointer) /* If newline pointer is detected at the end of the name string*/
				{
					*newlinePointer = '\0'; /* Modify newline pointer to equal null terminator, so nothing else is read.*/
				}
			}

			do
			{
				printf("Please enter a priority for the task. (0-999). 0 is highest.");
				scanf("%d", &priority);
				
			} while (!(priority >= 0 && priority <= 999));

			while (getchar() != '\n');

			newTask = taskNew(priority, taskName);
			dyHeapAdd(list, newTask, taskCompare);
			printf("The task %s has been added to your to-do list.\n\n", taskName);
			break;
		}

	case 'g': /* Get the first task*/
		{
			if (dySize(list) <= 0) /* If array is empty, print that it is emptyu and break execution*/
			{
				printf("This to-do list is empty.\n\n");
				break;
			}

			else
			{
				firstTask = (Task*)dyHeapGetMin(list);
				printf("Your first task is %s\n\n", firstTask->name);
				break;
			}

			break;
		}

	case 'r': /* Remove the first task*/
		{
			if (dySize(list) <= 0) /* If array is empty, print that it is emptyu and break execution*/
			{
				printf("This to-do list is empty.\n\n");
				break;
			}

			else
			{
				firstTask = (Task*)dyHeapGetMin(list); /* We need to assign firstTask to it before deleting so we can free it.*/
				dyHeapRemoveMin(list, taskCompare);
				printf("The first task, '%s' , has been removed.\n\n", firstTask->name);
				free(firstTask);
				break;
			}

			break;
		}

	case 'p':
		{
			if (dySize(list) <= 0) /* If array is empty, print that it is emptyu and break execution*/
			{
				printf("This to-do list is empty.\n\n");
				break;
			}

			else
			{
				listPrint(list);
				break;
			}
		}

	case 'e':
		{
			printf("\nBye!");
			break;
		}

	default:
		{
		printf("Invalid command. Try again.\n\n");
		break;
		}
	}
}

int main()
{
    // Implement
    printf("\n\n** TO-DO LIST APPLICATION **\n\n");
    DynamicArray* list = dyNew(8);
    char command = ' ';

    do
    {
        printf("Press:\n"
               "'l' to load to-do list from a file\n"
               "'s' to save to-do list to a file\n"
               "'a' to add a new task\n"
               "'g' to get the first task\n"
               "'r' to remove the first task\n"
               "'p' to print the list\n"
               "'e' to exit the program\n"
        );
        command = getchar();
        // Eat newlines
        while (getchar() != '\n');
        handleCommand(list, command);
    }
    while (command != 'e');
    dyDelete(list);
    return 0;
}
#include "hashMap.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <assert.h>

/**
 * Allocates a string for the next word in the file and returns it. This string
 * is null terminated. Returns NULL after reaching the end of the file.
 * @param file
 * @return Allocated string or NULL.
 */
char* nextWord(FILE* file)
{
    int maxLength = 16;
    int length = 0;
    char* word = malloc(sizeof(char) * maxLength);
    while (1)
    {
        char c = fgetc(file);
        if ((c >= '0' && c <= '9') ||
            (c >= 'A' && c <= 'Z') ||
            (c >= 'a' && c <= 'z') ||
            c == '\'')
        {
            if (length + 1 >= maxLength)
            {
                maxLength *= 2;
                word = realloc(word, maxLength);
            }
            word[length] = c;
            length++;
        }
        else if (length > 0 || c == EOF)
        {
            break;
        }
    }
    if (length == 0)
    {
        free(word);
        return NULL;
    }
    word[length] = '\0';
    return word;
}

/**
 * Prints the concordance of the given file and performance information. Uses
 * the file input1.txt by default or a file name specified as a command line
 * argument.
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, const char** argv)
{
    // FIXME: implement
    const char* fileName = "input1.txt";
    if (argc > 1)
    {
        fileName = argv[1];
    }
    printf("Opening file: %s\n", fileName);
    
    clock_t timer = clock();
    
    HashMap* map = hashMapNew(10);
    
    // --- Concordance code begins here ---
    // Be sure to free the word after you are done with it here.

	FILE* filePointer;

	filePointer = fopen(fileName, "r"); /* Open file in read mode. Need to read the words in.*/
	char *word; /* Character pointer to hold the word. This will be used as a key in the hash map.*/

	if (!filePointer)
	{
		printf("Could not open specified input file.\n");
	}

	word = nextWord(filePointer);

	while (word) /* Get words until the end of the file is reached.*/
	{
		if (hashMapContainsKey(map, word)) /* If the concordance already includes the word, increment the count by 1.*/
		{
			(*hashMapGet(map, word)) += 1;
		}

		else
		{
			hashMapPut(map, word, 1); /* Insert word as a new key into the hash map with a count of 1 usage.*/
		}

		word = nextWord(filePointer);
	}

	/* At this point, all words have been added with their proper count to the concordance. Now we need to close
	the file and print the concordance.*/

	fclose(filePointer);
	filePointer = NULL;
	
	printf("\n"); /* Create some space before the concordance table.*/
	printf("Word Count:\n\n");

	for (int i = 0; i < hashMapCapacity(map); i++)
	{
		HashLink* current;

		current = map->table[i]; /* Set current equal to the start of each bucket.*/

		while (current != NULL) /* Iterate through the bucket and print out all the hash links.*/
		{
			printf("%s: %d\n", current->key, current->value);
			current = current->next;
		}
	}

    // --- Concordance code ends here ---
    
    hashMapPrint(map);
    
    timer = clock() - timer;
    printf("\nRan in %f seconds\n", (float)timer / (float)CLOCKS_PER_SEC);
    printf("Empty buckets: %d\n", hashMapEmptyBuckets(map));
    printf("Number of links: %d\n", hashMapSize(map));
    printf("Number of buckets: %d\n", hashMapCapacity(map));
    printf("Table load: %f\n", hashMapTableLoad(map));
    
    hashMapDelete(map);
    return 0;
}
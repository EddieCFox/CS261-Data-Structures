/*
 * CS 261 Data Structures
 * Assignment 6
 * Name: Eddie C. Fox
 * Date:  8/9/2016
 */

#include "hashMap.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

int hashFunction1(const char* key)
{
    int r = 0;
    for (int i = 0; key[i] != '\0'; i++)
    {
        r += key[i];
    }
    return r;
}

int hashFunction2(const char* key)
{
    int r = 0;
    for (int i = 0; key[i] != '\0'; i++)
    {
        r += (i + 1) * key[i];
    }
    return r;
}

/**
 * Creates a new hash table link with a copy of the key string.
 * @param key Key string to copy in the link.
 * @param value Value to set in the link.
 * @param next Pointer to set as the link's next.
 * @return Hash table link allocated on the heap.
 */
HashLink* hashLinkNew(const char* key, int value, HashLink* next)
{
    HashLink* link = malloc(sizeof(HashLink));
    link->key = malloc(sizeof(char) * (strlen(key) + 1));
    strcpy(link->key, key);
    link->value = value;
    link->next = next;
    return link;
}

/**
 * Free the allocated memory for a hash table link created with hashLinkNew.
 * @param link
 */
static void hashLinkDelete(HashLink* link)
{
    free(link->key);
    free(link);
}

/**
 * Initializes a hash table map, allocating memory for a link pointer table with
 * the given number of buckets.
 * @param map
 * @param capacity The number of table buckets.
 */
void hashMapInit(HashMap* map, int capacity)
{
    map->capacity = capacity;
    map->size = 0;
    map->table = malloc(sizeof(HashLink*) * capacity);
    for (int i = 0; i < capacity; i++)
    {
        map->table[i] = NULL;
    }
}

/**
 * Removes all links in the map and frees all allocated memory. You can use
 * hashLinkDelete to free the links.
 * @param map
 */
void hashMapCleanUp(HashMap* map)
{
    // FIXME: implement
	assert(map != NULL);

	struct HashLink* current;
	struct HashLink* next;
	
	for (int i = 0; i < map->capacity; i++)
	{
		current = map->table[i];

		if (map->table[i] == NULL) /* If the bucket is empty, go to the next bucket.*/
		{
			continue;
		}

		current = map->table[i];

		/* If execution has reached this do-while loop, there is at least one hash link inside the bucket, 
		otherwise, the continue statement would have been triggered. next is set to current->next. If there is
		only 1 item in the bucket, it will stop after the first loop, because the next will be NULL. That is why
		it is necessary to make it a do-while loop, to delete the first and only item.*/

		do 
		{
			next = current->next;
			hashLinkDelete(current);
			current = next;

		} while (next != NULL);	
	}

	free(map->table);
	map->table = NULL;
}

/**
 * Creates a hash table map, allocating memory for a link pointer table with
 * the given number of buckets.
 * @param capacity The number of buckets.
 * @return The allocated map.
 */
HashMap* hashMapNew(int capacity)
{
    HashMap* map = malloc(sizeof(HashMap));
    hashMapInit(map, capacity);
    return map;
}

/**
 * Removes all links in the map and frees all allocated memory, including the
 * map itself.
 * @param map
 */
void hashMapDelete(HashMap* map)
{
	hashMapCleanUp(map);
    free(map);
}

/**
 * Returns a pointer to the value of the link with the given key. Returns NULL
 * if no link with that key is in the table.
 * 
 * Use HASH_FUNCTION(key) and the map's capacity to find the index of the
 * correct linked list bucket. Also make sure to search the entire list.
 * 
 * @param map
 * @param key
 * @return Link value or NULL if no matching link.
 */
int* hashMapGet(HashMap* map, const char* key)
{
    // FIXME: implement

	int hashIndex;
	struct HashLink* current;

	assert(map != NULL);

	hashIndex = HASH_FUNCTION(key) % map->capacity;

	if (hashIndex < 0)
	{
		hashIndex += map->capacity;
	}

	current = map->table[hashIndex];

	while (current != NULL)
	{
		if (strcmp(current->key, key) == 0)
		{
			return &(current->value); /* Return a pointer to the current link value, so it can be dereferenced later.*/
		}

		current = current->next;
	}

	return NULL;
}

/**
 * Resizes the hash table to have a number of buckets equal to the given
 * capacity. After allocating the new table, all of the links need to be
 * rehashed into it because the capacity has changed.
 * 
 * Remember to free the old table and any old links if you use hashMapPut to
 * rehash them.
 * 
 * @param map
 * @param capacity The new number of buckets.
 */
void resizeTable(HashMap* map, int capacity)
{
    // FIXME: implement
	
	assert(map != NULL);
	assert(capacity > map->capacity);

	HashMap* temp = hashMapNew(capacity);
	HashLink* current;
	
	assert(temp != NULL);

	for (int i = 0; i < map->capacity; i++)
	{
		
		if (map->table[i] == NULL)
		{
			continue;
		}

		current = map->table[i];

		do
		{
			hashMapPut(temp, current->key, current->value);
			current = current->next;
		} while (current != NULL);
	}

	
	hashMapCleanUp(map);

	map->capacity = temp->capacity;
	map->size = temp->size;
	map->table = temp->table;

	temp->table = NULL;
	free(temp);

}

/**
 * Updates the given key-value pair in the hash table. If a link with the given
 * key already exists, this will just update the value. Otherwise, it will
 * create a new link with the given key and value and add it to the table
 * bucket's linked list. You can use hashLinkNew to create the link.
 * 
 * Use HASH_FUNCTION(key) and the map's capacity to find the index of the
 * correct linked list bucket. Also make sure to search the entire list.
 * 
 * @param map
 * @param key
 * @param value
 */
void hashMapPut(HashMap* map, const char* key, int value)
{
    // FIXME: implement
	
	assert(map != NULL);
	
	if (hashMapContainsKey(map, key)) /* If the map contains the key, update the value with the parameters one.*/
	{
		*hashMapGet(map, key) = value;
	}

	else
	{
		int hashIndex;
		hashIndex = HASH_FUNCTION(key) % map->capacity;

		if (hashIndex < 0)
		{
			hashIndex += map->capacity;
		}
		
		HashLink* newLink = hashLinkNew(key, value, map->table[hashIndex]); /* Create new link with value and map, and point to bucket.*/
		map->table[hashIndex] = newLink;  /* Point bucket to newlink, adding the newLink to the bucket.*/
		map->size++; /* Increase size.*/

		if (hashMapTableLoad(map) > MAX_TABLE_LOAD)
		{
			resizeTable(map, (map->capacity * 2));
		}
	}
}

/**
 * Removes and frees the link with the given key from the table. If no such link
 * exists, this does nothing. Remember to search the entire linked list at the
 * bucket. You can use hashLinkDelete to free the link.
 * @param map
 * @param key
 */
void hashMapRemove(HashMap* map, const char* key)
{
    // FIXME: implement

	assert(map != NULL);

	int hashIndex;

	hashIndex = HASH_FUNCTION(key) % map->capacity;

	if (hashIndex < 0)
	{
		hashIndex += map->capacity;
	}

	HashLink* current;
	HashLink* next;

	current = map->table[hashIndex];

	if (current != NULL)
	{
		next = current->next;
		if (strcmp(current->key, key) == 0)
		{
			map->table[hashIndex] = next;
			hashLinkDelete(current);
			map->size--;
			current = next;
		}
	}

	while (current != NULL) /* Iterates through the map and deletes a link if the key is found. If the end is reached, simply returns.*/
	{
		if (strcmp(next->key, key) == 0) /* If the link is the one containing the key in the parameter, we need to remove it.*/
		{
			current->next = next->next;
			hashLinkDelete(next); /* Delete the link.*/
			map->size--;
		}

		current = current->next;
		next = next->next;
	}

	if (current == NULL) /* This is only the case if there is no links in the bucket, so the while loop never fires off. Simply returns without doing anything.
						 Arguably unnecessary, but good for documenting the logic of the function.*/
	{
		return;
	}

}

/**
 * Returns 1 if a link with the given key is in the table and 0 otherwise.
 * 
 * Use HASH_FUNCTION(key) and the map's capacity to find the index of the
 * correct linked list bucket. Also make sure to search the entire list.
 * 
 * @param map
 * @param key
 * @return 1 if the key is found, 0 otherwise.
 */
int hashMapContainsKey(HashMap* map, const char* key)
{
    // FIXME: implement

	assert(map != NULL);

	if (hashMapGet(map, key) != NULL)
	{
		return 1;
	}

	else
	{
		return 0;
	}
}

/**
 * Returns the number of links in the table.
 * @param map
 * @return Number of links in the table.
 */
int hashMapSize(HashMap* map)
{
    // FIXME: implement

	return map->size;
}

/**
 * Returns the number of buckets in the table.
 * @param map
 * @return Number of buckets in the table.
 */
int hashMapCapacity(HashMap* map)
{
    // FIXME: implement
	return map->capacity;
}

/**
 * Returns the number of table buckets without any links.
 * @param map
 * @return Number of empty buckets.
 */
int hashMapEmptyBuckets(HashMap* map)
{
    // FIXME: implement
    
	int emptyCount = 0;

	for (int i = 0; i < map->capacity; i++)
	{
		if (map->table[i] == NULL)
		{
			emptyCount++;
		}
	}

	return emptyCount;
}

/**
 * Returns the ratio of (number of links) / (number of buckets) in the table.
 * Remember that the buckets are linked lists, so this ratio tells you nothing
 * about the number of empty buckets. Remember also that the load is a floating
 * point number, so don't do integer division.
 * @param map
 * @return Table load.
 */
float hashMapTableLoad(HashMap* map)
{
    // FIXME: implement

	return (((float)(map->size)) / ((float)(map->capacity)));
}

/**
 * Prints all the links in each of the buckets in the table.
 * @param map
 */
void hashMapPrint(HashMap* map)
{
    for (int i = 0; i < map->capacity; i++)
    {
        HashLink* link = map->table[i];
        if (link != NULL)
        {
            printf("\nBucket %i ->", i);
            while (link != NULL)
            {
                printf(" (%s, %d) ->", link->key, link->value);
                link = link->next;
            }
        }
    }
    printf("\n");
}
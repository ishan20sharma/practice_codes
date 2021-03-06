#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAP_SIZE 100
#define LOAD_FACTOR 20

/* Linked list nodes represent each element and its key */
typedef struct listNode {
	int key;
	int data;
	struct listNode *next;
}listNode;

/* Represent a bucket of hashmap */
typedef struct hashMapNode {
	int bCount; /* Number of elements in the bucket */
	listNode *head;
}hashMapNode;

/* Represents the hashtable */
typedef struct hashMap {
	int tSize; /* Number of buckets in the table */
	int eCount; /* Number of elements in the table */
	hashMapNode *table;
}hashMap;


/* Hash Function */
int hash(int key, int tSize) {
	return key % tSize;
}

/* Creates a hash table */
hashMap *createHashMap(int size) {
	int i;
	hashMap *h;
	
	h = (hashMap *)malloc(sizeof(hashMap));

	/* Check if the memory is allocated for the hashMap head or not */
	if(!h) {
		printf("Could not allocate memory for the hashmap\n");
		return NULL;
	}
	
	h->tSize = size/LOAD_FACTOR;
	h->eCount = 0;
	
	h->table = (hashMapNode *)malloc(sizeof(hashMapNode) * (h->tSize));

	/* Check if memory is allocated for the record or not */
	if(!(h->table)) {
		return NULL;
	}
	
	for(i=0; i<h->tSize; i++) {
		(h->table[i]).bCount = 0;
		(h->table[i]).head = NULL;	
	}

	return h;
}

/* Check if a key exists in the hashmap or not */
int hashSearch(hashMap *hMap, int key) {
	listNode *current = (hMap->table[hash(key, hMap->tSize)]).head;

	for(current; current; current = current->next) {
		if(current->key == key)
			return 1;
	}

	printf("Key does not exist\n");
	return 0;
}

/* Insert a key and data in the hashmap */
int hashInsert(hashMap *hMap, int key, int data) {
	listNode *temp;
	int index;
	/* Get the index of the bucket */
	index = hash(key, hMap->tSize);

	/* Create the list node to be inserted */
	listNode *newNode = (listNode *)malloc(sizeof(listNode));
	if(!newNode) {
		printf("Could not create memory for new node\n");
		return 0;
	}
	newNode->key = key;
	newNode->data = data;

	/* Add the newNode as the first element of the bucket */
	newNode->next = (hMap->table[index]).head;
	(hMap->table[index]).head = newNode;

	/* Increase the count of the number of elements in the bucket */
	(hMap->table[index]).bCount++;

	/* Increase the count of the number of the elements in the hashmap */
	hMap->eCount++;

	if(hMap->eCount/hMap->tSize > LOAD_FACTOR) {
		if(rehash(hMap) == 0) {
			printf("Could not rehash the hashmap\n");
			return 0;
		}
	}
	return 1;
}

/* Create a new hash table from the previous table */
int rehash(hashMap *hMap){
	int oldSize, i, index;
	listNode *temp = NULL, *temp2 = NULL;
	hashMapNode *oldTable = NULL;

	/* Save the old size and table */
	oldSize = hMap->tSize;
	oldTable = hMap->table;

	/* Increase the size and create the new table */
	hMap->tSize = oldSize * 2;
	hMap->table = (hashMapNode *)malloc(sizeof(hashMapNode) * (hMap->tSize));

	if(!hMap->table) {
		printf("Could not create new table\n");
		return 0;
	}
	
	/* Move the elements from the old hash table to the new hash table */
	for(i=0; i<oldSize; i++) {
		temp = oldTable[i].head;
		while(temp) {
			index = hash(temp->key, hMap->tSize);
			temp2 = temp;
	
			temp = temp->next;

			temp2->next = (hMap->table[index]).head;
			(hMap->table[index]).head = temp2;
			
		}
	}	
	return 1;
}

/* Deletes a key from the hashMap */
int deleteHashMap(hashMap *hMap, int key) {
	int index = hash(key, hMap->tSize);
	listNode *prev = NULL;
	listNode *current = NULL;
	printf("deleting the key from bucket %d\n", index);
	for(current = (hMap->table[index]).head; current; prev = current,current=current->next) {
		printf("locating the key\n");
		if(current->key == key) {
			printf("key located\n");
			if(prev){	
				prev->next = current->next;
				printf("changed the prev node\n");
			}
			free(current);
			((hMap->table[index]).bCount)--;
			hMap->eCount--;
			return 1;
		}
	}
	printf("Could not delete the element\n");
	return 0;
}

/* Returns the value associated with the key */
int getValue(hashMap *hMap, int key) {
	listNode *current = NULL;
	int index = hash(key, hMap->tSize);

	for(current = (hMap->table[index]).head; current; current = current->next) {	
		if(current->key == key) 
			return current->data; /* It could return 0 also */
	}
	return -1;
}

/* Returns the list node associated with the key */
listNode *getNode(hashMap *hMap, int key) {
	int index = hash(key, hMap->tSize);
	listNode *current = (hMap->table[index]).head;

	for(current; current; current = current->next) {
		if(current->key == key)
			return current;
	}
	
	return NULL;
}

/* Modifies rhe value associated with a key */
int modifyValue(hashMap *hMap,int key, int data) {
	listNode *current = NULL;
	int index = hash(key, hMap->tSize);
	for(current = (hMap->table[index]).head; current; current = current->next) {
		if(current->key == key) {
			current->data = data;
			return 1;
		}
	}
	return 0;
}

/* Prints the Hash Map */
int printHashMap(hashMap *hMap){
	listNode *current;
	int i = 0;
	
	printf("** HashMap Table **\n");
	for(i; i < hMap->tSize; i++) {
		printf("Bucket %d: ",i);
		for(current = (hMap->table[i]).head; current; current = current->next) {
				printf("%d  ", current->key);
		}
		printf("\n");
	}	
	printf("eCount is %d\ntSize is %d\nValue of eCount/tSize is %d\n", hMap->eCount, hMap->tSize,hMap->eCount/hMap->tSize);
}

int main() {
	hashMap *hMap = createHashMap(MAP_SIZE);
	if(!hMap) {
		printf("Hash table not created\n");
		return -1;
	}

	listNode *increment = NULL;
	printf("hash table successfully created\n");

	int i = 0;
	for(i; i< 1000; i++)
		hashInsert(hMap,i,i);
	printf("Completed hashMap is\n");
	printHashMap(hMap);

/*	printf("Value associated with key 840 is %d\n",getValue(hMap,840));

	increment = getNode(hMap,840);
	modifyValue(hMap, 840, 16);
	//increment->data = increment->data+1;
	printf("Value associated with key 840 is %d\n",getValue(hMap,840));
	
*/	
	/* Check deleteHashMap 
	if(deleteHashMap(hMap,1006))
		printHashMap(hMap);
	else
		printf("No key available to be deleted\n"); */
	
	/*if(hashInsert(hMap, 15, 53)) {
		printf("Key inserted\n");
		printHashMap(hMap);
	} */

	if(hashSearch(hMap, 5))
		printf("Key Present\n");

	return 0;
}

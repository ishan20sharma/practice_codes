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
	int bCount; /* Number of element in the bucket */
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
	listNode *temp = (hMap->table[hash(key, hMap->tSize)]).head;

	while(temp) {
		if(temp->key == key)
			return 1;
		temp = temp->next;
	}
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
	newNode->key = key;
	newNode->data = data;

	/* Add the newNode as the first element of the bucket */
	newNode->next = (hMap->table[index]).head;
	(hMap->table[index]).head = newNode;

	/* Increase the count of the number of elements in the bucket */
	(hMap->table[index]).bCount++;

	/* Increase the count of the number of the elements in the hashmap */
	(hMap->eCount)++;

	if(hMap->eCount/hMap->tSize > LOAD_FACTOR)
		rehash(hMap);
	
	return 1;
}

/* Create a new hash table from the previous table */
int rehash(hashMap *hMap){
	int oldSize, i, index;
	listNode *p, *temp, *temp2;
	hashMapNode *oldTable;

	/* Save the old size and table */
	oldSize = hMap->tSize;
	oldTable = hMap->table;

	/* Increase the size and create the new table */
	hMap->tSize = oldSize * 2;
	hMap->table = (hashMapNode *)malloc(sizeof(hashMapNode) * (hMap->tSize));

	if(!hMap->table) {
		printf("Could not create new table\n");
		return -1;
	}
	
	/* Move the elements from the old hash table to the new hash table */
	for(i=0; i<oldSize; i++) {
		for(temp = oldTable[i].head; temp; temp = temp->next) {
			/* Find an index in the new table */		
			index = hash(temp->key, hMap->tSize);

			/* Move the listNode from the old table to the new table */
			temp2 = temp;
			temp2->next = (hMap->table[i]).head;
			(hMap->table[i]).head = temp2;
		}
	}	

	return 1;
}

/* Deletes a key from the hashMap */
int deleteHashMap(hashMap *hMap, int key) {
	int i = 0;
	int index = hash(key, hMap->tSize);
	listNode *prev = NULL;
	listNode *current = NULL;
	printf("deleting the key\n");
	for(current = (hMap->table[i]).head;current; prev = current,current=current->next) {
		printf("counting the linkedlist\n");
		if(current->key == key) {
			printf("deleting the key\n");
			if(prev)	
				prev->next = current->next;
			printf("changed the prev node\n");
			free(current);
			return 1;
		}
	}
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

	printHashMap(hMap);

	printf("Value associated with key 840 is %d\n",getValue(hMap,840));

	increment = getNode(hMap,840);
	increment->data = increment->data+1;
	printf("Value associated with key 840 is %d\n",getValue(hMap,840));
	
	
	deleteHashMap(hMap,841);
	printHashMap(hMap);
	
	/*if(hashInsert(hMap, 15, 53))
		printf("Key inserted\n");

	if(hashSearch(hMap, 15))
		printf("Key Present\n");*/

	return 0;
}

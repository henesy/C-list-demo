// Need stdlib.h for free() and malloc()
#include <stdlib.h>

// Nil is basically NULL
#define nil	((void*)0)

/* A singly-linked list implementation */
typedef struct Node Node;
typedef struct List List;

// A node within the list
struct Node {
	Node*	next;
	void*	dat;
};

// A list
struct List {
	Node*	root;
	int		size;
};

// Create a new list
List mklist(void);

// Append to a list
void ladd(List*, void*);

// Search → delete from a list
void* ldel(List*, void*, int(*comp)(void *, void *));

// Access elements of a list by 'index'
void* lget(List*, int);

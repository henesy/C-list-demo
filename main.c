#include <stdio.h>
#include <string.h>
#include "list.h"

// Booleans ☺
#define true	1
#define false	0

// Tells printing what type to print
typedef int Type;
enum Type {
	integer,	// Represents an `int`
	floating,	// Represents a `double`
	string,		// Represents a `char*` 
};

// Print a list out
void
printl(List l, Type t)
{
	Node *n;
	
	printf("{\n");

	for(n = l.root ; n != nil; n = n->next){
		putchar('\t');
		
		switch(t){
		case integer:
			// This looks ugly because `n` is being cast to an `int*` and then dereferenced
			// Dereferencing yields the integer value stored in the memory pointed to
			printf("%d", *((int*)n->dat));
			break;
		case floating:
			printf("%f", *((double*)n->dat));
			break;
		case string:
			printf("%s", (char*)n->dat);
			break;
		}
		
		putchar('\n');
	}
	
	printf("}\n");
}

// Compare two integer elements in the list
int
intcomp(void *a, void *b)
{
	int *A = (int*)a, *B = (int*)b;

	if(*A == *B)
		return true;

	return false;
}

// Compare two double elements in the list
int
doublecomp(void *a, void *b)
{
	double *A = (double*)a, *B = (double*)b;

	if(*A == *B)
		return true;

	return false;
}

// Compare two string elements in the list
int
stringcomp(void *a, void *b)
{
	char *A = (char*)a, *B = (char*)b;
	
	if(strcmp(A, B) == 0)
		return true;
	
	return false;
}


// Demonstrate using a singly-linked list in C
void
main()
{
	int i;
	List integers, doubles, strings;
	
	/* Integers */

	integers = mklist();
	
	int one = 1, two = 2, three = 3;

	// Put the elements in the list, in order
	ladd(&integers, &one);
	ladd(&integers, &two);
	ladd(&integers, &three);
	
	printf("Integers (full) ");
	printl(integers, integer);
	
	// Delete `2` from the list
	int othertwo = 2;
	ldel(&integers, &othertwo, intcomp);

	printf("Integers (deleted) ");
	printl(integers, integer);
	
	/* Doubles */
	
	doubles = mklist();
	
	double pi = 3.14, e = 2.72;	/* sorry */
	
	ladd(&doubles, &pi);
	ladd(&doubles, &e);
	
	printf("Doubles (full) ");
	printl(doubles, floating);
	
	double otherpi = 3.14;
	ldel(&doubles, &otherpi, doublecomp);
	
	printf("Doubles (deleted) ");
	printl(doubles, floating);
	
	/* Strings */
	
	strings = mklist();
	
	char *bob = "Bob", *ana = "Ana", *jane = "Jane";
	
	ladd(&strings, bob);
	ladd(&strings, ana);
	ladd(&strings, jane);
	
	printf("Strings (full) ");
	printl(strings, string);
	
	// This works because a `const char* "Jane"` will be put on the stack
	// The stack value will be passed in as the argument
	ldel(&strings, "Jane", stringcomp);
	
	char *diane = calloc(6, sizeof (char));
	
	/* 
	You don't want to do
	
		diane = "Diane";
		
	as `diane` is allocated and is a pointer. The string constant will be on
		the stack and cease to be usable once the owner function returns.  
	
	We want to 'copy' values from the constant "Diane" to be stored
		in the allocated memory inside `diane`. 
	
	There is a size of 6 as a '\0' character terminates strings.
	
	Note that `'\0' == 0`. 
	*/
	
	// Str _n_ cpy() is used for memory safety reasons
	strncpy(diane, "Diane", sizeof "Diane");

	ladd(&strings, diane);
	
	printf("Strings (modified) ");
	printl(strings, string);
	
	/* Free allocated memory */
	
	// Nodes are allocated memory, so we need to free all remaining nodes
	// Strategy: delete the head until the list is empty
	while(integers.size > 0)
		ldel(&integers, integers.root->dat, intcomp);
	
	while(doubles.size > 0)
		ldel(&doubles, doubles.root->dat, doublecomp);
	
	while(strings.size > 0)
		ldel(&strings, strings.root->dat, stringcomp);
	
	// Free diane as well, as we allocated the name
	free(diane);

	printf("Integers (freed) ");
	printl(integers, integer);
	
	printf("Doubles (freed) ");
	printl(doubles, floating);
	
	printf("Strings (freed) ");
	printl(strings, string);
}

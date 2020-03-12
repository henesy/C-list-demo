# C list demo

Written for a friend, demonstrates pointers/list usage in C ☺.

This list implementation isn't the cleanest, but should show most relevant usage off. 

The list implementation is a singly-linked list. 

## Notes on pointers

- A pointer 'points' to a location in memory typically expressed as an address in a form such as `0xFA12F`

- The 'value' of a pointer is the address in memory being pointed to and stored a type associated with the allocation 

- A pointer can point to an arbitrary depth of other pointers, as per `int**` being a pointer to a pointer to a location in memory known to be of type `int` (integer)

- The `*` operator shifts in towards the value stored in memory, as per `*n` yielding the value stored in the memory pointed to by `n`

- The `&` operator shifts out towards pointing to whatever the value is, as per `&n` yielding a pointer to the pointer `n`

- The `->` operator is shorthand for 'dereference and element of' for pointers to `struct` types, as per `bob->name` where `Person* bob` is a pointer to a `struct` type named `Person` with an element of `name` ;; this is equivalent to `(*bob).name`

## Dependencies

- A C compiler such as `gcc`
- `make`

On Ubuntu:

	$ sudo apt install build-essential gcc

## Build

	$ make
	
## Run

	$ ./a.out

## Relevant manuals

For outside functions used. 

- https://linux.die.net/man/3/putchar
- https://linux.die.net/man/3/printf
- https://linux.die.net/man/3/strcmp
- https://linux.die.net/man/3/strcpy (covers strncpy)
- https://linux.die.net/man/3/free	(also covers malloc/calloc)


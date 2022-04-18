
# Simple Shell

## Descripcion 

C shell is the UNIX shell (command execution program, often called a command interpreter ) created by Bill
Joy at the University of California at Berkeley as an alternative to UNIX's original shell, the Bourne shell.
These two UNIX shells, along with the Korn shell , are the three most commonly used shells. The C shell program
name is csh , and the shell prompt (the character displayed to indicate readiness for user input) is the % symbol.
The C shell was invented for programmers who prefer a syntax similar to that of the C programming language.

## Prototype

```c
int _printf(const char *format, ...);
```

## Usage

_printf \- Belongs to the library stdio.h.
Allows to display (data), The function is created
printf();
Parameters are placed inside the parantheses.
The function returns a value that represents the character number

-syntax
printf("chain", value_1, value_2,...)

```c
#include "main.h"

int main(void)
{
	_printf("Hello World.\n");
	return (0);
}
```

## RETURN VALUE

If successful, the total number of characters written is returned. On failure,
a negative number is returned.

## Example

```c
#include "main.h"

int main(void)
{
	_printf("Let\'s try to printf a simple sentence.\n");
	return (0);
}
```
## Authors - Cohort 17

- Laura Socarras 
- Maria Paz Quirola

## Flowchart

<p align="center">
	<img src="./assets/flowchar-printf-project.jpg"/>
</p>
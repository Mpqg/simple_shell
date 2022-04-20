#!bin/bash

GCC := gcc -Wall -Werror -Wextra -pedantic -std=gnu89
BETTY := betty

#
# betty
#

linter:
	@$(BETTY) *.c
	@$(BETTY) *.h

tests:
	$(info Running the tests)

build:
	$(info Building the project...)
	$(GCC) *.c -o hsh
	$(info Build proccess terminated!)

clean:
	$(info Cleaning residuals files...)
	@rm *.o
	@rm hsh
	$(info Cleaning proccess terminated!)

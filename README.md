# push_swap
Sorting with 2 stacks

### About this project
* This is an individual project at [École 42](https://42.fr)
* This project objective is to sort numbers using 2 stacks and specfic operations.
* The operations:
	* sa: swap the first and the second number on stack a
	* sb: swap the first and the second number on stack b
	* ss: do sa and sb
	* pa: move the first number from stack b to stack a
	* pb: move the first number from stack a to stack b
	* ra: move the first number in stack a to the bottom of the stack a
	* rb: move the first number in stack b to the bottom of the stack b
	* rr: do ra and rb
	* rra: move the last number in stack a to the top of the stack a
	* rrb: move the last number in stack b to the top of the stack b
	* rrr: do rra and rrb
* There are 2 programs in this project:
	* push_swap: this program will take the numbers, sort them and output the used operations.
	* checker: this program will take the numbers, read the operations and check if the numbers are sorted or not.

### How to run the program
Run make command.
```
make
```
You will get push_swap and checker file.

To run the push_swap,
```
./push_swap [numbers]
```
The program will output the operations using to sort the numbers, for example:
```
$> ./push_swap 3 2 1 | cat -e
sa$
ra$
```

To run the checker,
```
./checker [numbers]
```
Then, you have to input operations. One operation each time then press Enter. After finished, press command + D or CTRL + D. For example:
```
$>./checker 3 2 1
sa
ra
OK
$> ./checker 3 2 1
ra
sa
KO
```

You can run push_swap and then send the result to the checker to check it.
```
ARG="3 2 1"; ./push_swap $ARG | ./checker $ARG
```

I also have 2 debug mode:
* -v show stack a and stack b in each operation
```
./push_swap -v [numbers]
```

* -c change the color of the operations
```
./push_swap -c [numbers]
```

* -vc you can combine this two together
```
./push_swap -vc [numbers]
./push_swap -cv [numbers]
```

### The algorithms I used
First of all, the way to do classic algorithms isn't worked in this project becuase you have to use 2 stacks and the specific opreations. It will take a lot of operations to exchange the place of the number comparing to just 1 operations if you use array or linked list. However, the idea of each sorting is still applicable.

Another note is that all of my algorithms using in this project will take O(N^2) for the calculation but only O(Nlog(N)) for the operations.

To optimize my push_swap, I used many sorting algorithms based on the number of the inputs.

If the input is 2 numbers, I just check the order and swap it so it's just one operation.

The same goes for 3 numbers, I just have a manual operations in each cases which will result in 0-3 operations.

For 4 numbers to 45 numbers, I applied selection sort. The process is
* Finding the lowest number in stack a
* Rotate or reverse rotate until that number is at the top
* Push the number into stack b
* When stack a is sorted, push all the numbers from stack b back to stack a

For more than 45 numbers, I created an algorithms myself. This algorithms uses cost calculation method so it will choose the lowest cost to move.
* Stack b always sorted (for example 5 4 3 2 1) or sorted but reversed (for example 3 2 1 5 4)
* Cost = [move stack a to top] + [move stack b to its proper place] + [push]
* Then I move the lowest cost number.
* For optimization, I combine the move ra and rb to rr (or rra and rrb to rrr) to reduce the operations.
* More of that, when stack a is low in numbers, I used selection sort for the rest of the stack because the cost to move stack b is very high.
* After everything is sorted in stack b, I push them back to stack a

### The evaluation and my result
The evaluation criteria are
* 3 numbers: <= 3 operations to pass the project
* 5 numbers: <= 12 operations to pass the project
* 100 numbers: <= 700 operations to get the full bonus
* 500 numbers: <= 5500 operations to get the full bonus

My result
* 3 numbers: 0-2 operations (avg 1 operation)
* 5 numbers: 0-12 operations (avg 7 operations)
* 100 numbers: 504-608 operations (avg 546 operations)
* 500 numbers: 4596-5459 operations (avg 4931 operations)

Note that the result generate from 100 random trials so it may be different each times.

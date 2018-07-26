# 2303HW1
HW 1 for  CS2303 Systems Programming

Matt Freed
Assignment 1
1/21/2018

Program Summary:

	this program requires the user to input a year and outputs a formatted calendar for the given year. The calendar takes into account leap years and will work with any year above 0 (the input must also be an integer, otherwise the program will return an error).

For this program, Sunday = 0, Saturday = 6

To run: gcc -Wall -o PA1 PA1.c
	./PA1.out

Running program:

	in the terminal, compile the program using gcc -Wall PA1.c -lm
	use the command ./a.out to run the program
	input the year that the user wants then press enter to receive the calendar

Algorithm:

	Starting day of the year algorithm borrowed from mathforum.org
	link: http://mathforum.org/library/drmath/view/55837.html
	
	equation:  n = (d + 2m + [3(m+1)/5] + y + [y/4] - [y/100] + [y/400] + 2)%7
	d = number of days in the month
	m = month number (January and February have to be 13 and 14 respectively of the previous year for this equation to work.
	y = year 
	n = starting day (Sunday-Saturday)


	-When using this equation we are always searching for the first day of the month, therefore d = 1.
	-m will be equal to January (13) since we will be printing the entire year. 
	-Because January must used with the previous year (as describe above), the algorithm was adjusted to be: n = (1 + 2(13) + [3(13+1)/5] + (y-1) + [(y-1)/4] - [(y-1)/100] + [(y-1)/400] + 2)%7

	-The final output will be equal to the number day of the week that january 1st will be on. 
	-This equation makes Saturday = 0 instead of Sunday, therefore a switch statement is used afterwards to convert the days to the correct numbers.
	
Loop Invariants:

	-printMonth for loop:
		loop 1: loops through entire month, counting the amount of days and sets nextStartDay as the starting day of the next month
		invariants: i<31 && i>=0, nextStartDay>=0 && nextStartDay<=6
	
		loop 2: outputs the correct spacing format for the calendar.
		invariants: i>=0 && i<=6
	
		loop 3:  loops through entire month and prints the correct day formatting to the console
		invariants: dayIncrement <7 && >=0

	-printCalendar for loop:
		loops through months Feb-Dec and outputs the months in the correct calendar format
		invariants: i>1 && i<13

	
		

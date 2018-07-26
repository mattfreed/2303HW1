//Matt Freed
//Assignment 1
//Cs2303

#include <stdio.h>
#include <stdlib.h>


/**
*Determine if year is leap year
*@param year Year that the calendar is looking for
*@return 1 if leap year, 0 if not
*/
int isLeapYear (int year){
	if ((year<100) && (year%4==0)){// checking if the given year is <100 and divisible by 4. if yes, returns true
		return 1;
	}
	else if ((year>=100) && (year%4==0)){ // checking if the year is >100 and divisible by 4
		if ((year<400)&&(year%100 != 0)){// check if year is <400 and not 100, if yes return true
			return 1;
		}
		if ((year >=400)&&(year%400 == 0)){// check if year is >= 400 and is divisble by 400. If yes return true
			return 1;
		}
		if ((year >=400)&&(year%100 != 0)&&(year%400 != 0)){ // check if the year is >400 and not divisible by 100 or 400, if yes return true
			return 1;
		}
	}
	else {
		return 0; // return not a leap year if all above is false
	}
	return 0;
}


/**
*Prints the month name
*@param year Year that the calendar is looking for
*@param month Current month that the calendar is looking to output
*@return Amount of days in given month
*/
int printMonthName(int year, int month){
	switch(month){ //goes to the month number that is input
		case 1://Jan
			printf("JANUARY %d\n", year);
			printf("\n");
			return 31;

		case 2://Feb
			printf("FEBRUARY %d\n", year);
			printf("\n");
			if (isLeapYear(year) == 1){// check if the year is a leap year. output 29 if true, otherwise output 28
				return 29;}
			else {
				return 28;
			}
		case 3://March
			printf("MARCH %d\n", year);
			printf("\n");
			return 31;
		case 4://April
			printf("APRIL %d\n", year);
			printf("\n");
			return 30;
		case 5://May
			printf("MAY %d\n", year);
			printf("\n");
			return 31;
		case 6://June
			printf("JUNE %d\n", year);
			printf("\n");
			return 30;
		case 7://July
			printf("JULY %d\n", year);
			printf("\n");
			return 31;
		case 8://Aug
			printf("AUGUST %d\n", year);
			printf("\n");
			return 31;
		case 9://Sep
			printf("SEPTEMBER %d\n", year);
			printf("\n");
			return 30;
		case 10://Oct
			printf("OCTOBER %d\n", year);
			printf("\n");
			return 31;
		case 11://Nov
			printf("NOVEMBER %d\n", year);
			printf("\n");
			return 30;
		case 12://Dec
			printf("DECEMBER %d\n", year);
			printf("\n");
			return 31;
	}
	return 0;
}



/**
*Calls printMonthName() and prints out days of the month in calendar format
*@param year Year that the calendar is looking for
*@param month Current month that the calendar is looking to output
*@param startDay The start day for the month
*@return the start day for the next month 
*/
int printMonth(int year, int month, int startDay){
	int days = printMonthName(year,month); // amount of days in the month
	int nextStartDay = startDay;// The initial start day of the month, Sunday ==0
	int dayIncrement = startDay;// The day of the week to print
	
	//loops through entire month counting the days and sets nextStartDay as the next starting day for the following month
	//pre condition: nextStartDay = startDay, i = 0
	for(int i = 0; i<days; i++){
		if (nextStartDay == 6){ // if nextStartDay is saturday, increase the day to sunday
			nextStartDay = 0;
		}
		else{
		nextStartDay++; // otherwise, increase the day by 1
		}
	}
	//loop invariant:
	//nextStartDay>=0 && nextStartDay<=6
	//i<31 && i>=0

	printf("Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");
	if (startDay != 0){//check if the start day is not a sunday
		//loop outputs the correct spacing format for the calendar 
		for(int i = 0; i<startDay; i++){
			printf("     ");// print spaces until the first day of the month is found
		}
		//loop invariants:
		//i>=0 && i<= 6
	}
	//loops through entire month's days and prints the day formatting
	for (int i = 1; i<=days; i++){
		switch(dayIncrement){//prints the correct formatting for day and day number
			case 0://Sunday case
				if(i<9){ // if the sunday is less than  day 9, output this formatting
					printf("  %d    ",i);
				}
				else if (i ==9){ // if the sundday is day 9, output this formatting
					printf("  %d   ",i);
				} 
				else{		//otherwise output this format
					printf(" %d   ",i);
				}
				break;			
			case 6://Saturday case
				if( i == 1){ // if saturday is first day of month output this   formatting
					printf("  %d\n",i);
				}
				else{ // otherwise output this formatting
					printf("%d\n",i);
				}
				break;
			default://default case
				if( i == 1){ //output this formatting for first day of month
					printf("  %d    ",i);
				}
				else if((i<9)&&(i>1)){ //output this formatting if the day is between days 1 and 9
					printf("%d    ",i);
				}
				else{ //otherwise output this formatting
					printf("%d   ",i);
				}
		}

		if(dayIncrement == 6){//if the day was saturday, change the day to saturday
			dayIncrement = 0;
		}
		else {			// otherwise increase the day by 1
			dayIncrement++;
		}
		
	}
	//loop invariants:
		//day increment <7 && >=0
		// i < 32 && >=1
	if (dayIncrement != 0){// if the last day is not a sunday, start a new line for formating 
		printf("\n");
	}

	return nextStartDay; // return the starting day of the next month
}

/**
*Loops through year and calls the function printMonth() 12 times, once for each month
*@param year Year that the calendar is looking for
*@param startDay The start day for the month
*@return 0
*/
int printCalendar(int year, int startDay){
	printf("\n");
	printf("\n");
	printf("  ***    CALENDAR for %d   ***\n",year);
	printf("\n");
	
	
	int next =printMonth(year,1, startDay); //prints the january schedule for given year. returns the start date for the following month
	//loops through months Feb-Dec and outputs the month's calendar format
	// pre condition next = january 1st on start day
	// post condition next = december 1st
	for (int i = 2; i <=12; i++){
		printf("\n");
		next = printMonth(year, i, next); //prints the month and sets next == to next month start date
	}
	//loop invariants:
	// i>1 && i<13

	return 0;

}
/**
*Calculates the starting day of the given year
*@param year Year that the calendar is looking for
*@return the starting day of the year
*/
int startingDayCalc(int year){
	//mathforum.org
	//N = 1 + 2(13) + [3(13+1)/5]+(y-1)+[(y-1)/4]-[(y-1)/100]+[(y-1)/400]+2
	int startingDay = (1+(2*13)+(3*(13+1)/5)+(year-1)+((year-1)/4)-((year-1)/100)+((year-1)/400)+2)%7; //which day of the week to print
	switch(startingDay){//equation sets saturday as 0, switch statement changes days to the correct output
		case 0:
			startingDay = 6;
			break;
		case 1:
			startingDay = 0;
			break;
		case 2:
			startingDay = 1;
			break;
		case 3:
			startingDay = 2;
			break;
		case 4:
			startingDay = 3;
			break;
		case 5:
			startingDay = 4;
			break;
		case 6:
			startingDay = 5;
			break;
	}
	return startingDay;
}


/**
*Outputs entire calendar for given year
*/
int main (void){
	printf("\n");
	printf("                          MONTHLY CALENDAR\n");
	printf("\n");

	int year = 0;//defaults year to 0 incase anything other than an integer is an input

	printf("please enter a year for this calendar:- ");
	scanf("%d", &year);


	printf("\n");
	if (year <= 0){// checks to see if year is <=0, if yes returns an error statement
		printf("Year is invalid\n");
		exit(0);
	}
	
	printCalendar(year, startingDayCalc(year));// prints the entire calendar year that has been requested

	
	
	return 0;

}

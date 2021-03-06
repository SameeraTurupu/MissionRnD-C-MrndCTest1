/*
Q4: Two dates are given in a 8 node single linked list form,where each node
has one digit only, dates 01-31, months 01-12, year 0000-9999.

Find the number of days in between those two dates .[Exclusive]

Ex : Date1:  0->1->0->1->2->0->0->4 .
     Date2 : 0->5->0->1->2->0->0->4 should return 3 .
As there are 3 days between Jan1st 2004 and Jan 5th 2004.

Ex 2 : Date1 : 3->1->1->2->2->0->1->2.
       Date2 : 0->2->0->1->2->0->1->3 should return 1 .
(There is only one day between 31st Dec 2012 and 2nd  Jan 2013 .)

Note : Consecutive Days and Same Days should return 0;
->Return -1 for NULL Inputs .
->Between Days have to be calculated by not including start and end date .
->The SLL will have 8 Nodes in all cases . Month 9 will be represented as 09.

Difficulty : Hard 
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct node{
	int data;
	struct node *next;
};

int LeapYearsCount(int days, int months, int years)
{
	if (months <= 2)
		years--;
	return years / 4 - years / 100 + years / 400;
}
int between_days(struct node *date1head, struct node *date2head){
	if (!date1head || !date2head)
		return -1;
	struct node *temp1 = date1head;
	struct node *temp2 = date2head;
	int count = 1;
	int d1 = temp1->data * 10;
	temp1 = temp1->next;
	d1 += temp1->data;
	int d2 = temp2->data * 10;
	temp2 = temp2->next;
	d1 += temp2->data;
	temp1 = temp1->next;
	int m1 = temp1->data * 10;
	temp1 = temp1->next;
	m1 += temp2->data;
	temp1 = temp1->next;
	int m2 = temp2->data * 10;
	temp2 = temp2->next;
	m2 += temp2->data;
	temp2 = temp2->next;
	int y1 = 0;
	y1= y1 *10 + temp1->data;
	temp1 = temp1->next;
	y1 = y1 * 10 + temp1->data;
	temp1 = temp1->next;
	y1 = y1 * 10 + temp1->data;
	temp1 = temp1->next;
	y1 += temp1->data;
	int y2 = 0;
	y2 = y2 * 10 + temp2->data;
	temp2 = temp2->next;
	y2 = y2 * 10 + temp2->data;
	temp2 = temp2->next;
	y2 = y2 * 10 + temp2->data;
	temp2 = temp2->next;
	y2 += temp2->data;
	printf("%d", d1);
	int monthDays[12] = { 31, 28, 31, 30, 31, 30,31, 31, 30, 31, 30, 31 };
	int n1 = y1 * 365 + d1;
	for (int i = 0; i< m1 - 1; i++)
		n1 += monthDays[i];
	n1 += LeapYearsCount(d1, m1, y1);
	int n2 = y2 * 365 + d2;
	for (int i = 0; i< m2 - 1; i++)
		n2 += monthDays[i];
	n2 += LeapYearsCount(d2, m2, y2);
	return n2 - n1;
}
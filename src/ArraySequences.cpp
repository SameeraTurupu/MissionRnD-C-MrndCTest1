/*
Given an array which has two arithmetic sequences and 
one geometric sequence (in any order).
Copy indexes where each sequence starts and ends into an Array and return it.

Note : Each sequence will be of atleast LENGTH 3,and The sequences can be overlapping

Ex : 1, 3, 5, 7, 2, 4, 8, 16 18 20, output is [0, 3, 7, 9, 4, 7]
Ex : 1 ,2, 4, 8, 12, 16, 21, 26     output is [2, 5, 5, 7, 0, 3]
Ex : 10 15 20 30 50 70 100 200 400 800  output is [0, 2, 3, 5, 6, 9]

The final_arr[0], final_arr[1] values in final array  
will be start and end indexes of First A.P in the Original Array

The final_arr[2], final_arr[3] values in final array  
will be start and end indexes of Second A.P 

The final_arr[4], final_arr[5] values in final array  
will be start and end indexes of First  G.P (Only)

Input: Array and Length of Array
Output : New Array which has 6 integers , which denote the (start,end) indexes .

Note : All elements in the array will be part of atleast 1 sequence .
Two A.P cannot start at same index . 

Difficulty : Medium
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int * find_sequences(int *arr, int len){
	//Return final array which has 6indexes [AP1_S,AP1_E,AP2_S,AP2_E,GP1_S,GP2_E]
	if (!arr || len <= 0)
		return NULL;
	int *res = (int *)malloc(sizeof(int) * 6);
	int index, common_difference = arr[1] - arr[0];
	for (index = 1; index < len; index++) {
		if (arr[index] == arr[index - 1] + common_difference)
			continue;
		break;
		
	}
	res[0] = 0; 
	res[1] = index - 1;
	res[2] = index;
	common_difference = arr[index + 1] - arr[index];
	for (index + 1; index < len; index++) {
		printf("in se %d  %d %d", index, arr[index], arr[index - 1]);
		if (arr[index] == (arr[index - 1] + common_difference))
			continue;
		break;
	}
	res[3] = index - 1;
	int r = arr[index + 1] / arr[index];
	if (r == arr[index] / arr[index - 1])
		res[4] = index - 1;
	else
		res[4] = index;
	for (index + 1; index < len; index++) {
		//printf("--%d---\n", index);
		if (arr[index] == (arr[index - 1] * r))
			continue;
		break;
	}
	res[5] = index;
	return res;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int number_test_case = 0;
int numbers = 0;
char num[256];
void enter_case(int* count);
void enter_element(int*);
int main (int argc, char* argv[]){

	int opt = 0;
ENTER_NUMBER_OF_TEST_CASE:
	memset(num, 0, 256);
	printf("please enter number: ");
	fgets(num, 256, stdin);
	sscanf (num,"%d", &number_test_case);
	if(number_test_case < 1 || number_test_case > 100){
		system("clear");
		goto ENTER_NUMBER_OF_TEST_CASE;
	}

ENTER_NUMBER_OF_TEST_CASE_OPT:
//	printf("please enter case: %d", (opt + 1));
//	memset(num, 0, 256);
//	fgets(num, 256, stdin);
//	sscanf (num,"%d", &numbers);
//	if(numbers < 1 || numbers > 100){
//		goto ENTER_NUMBER_OF_TEST_CASE_OPT;
//	}
	enter_case(&opt);
	if(opt < number_test_case){
		goto ENTER_NUMBER_OF_TEST_CASE_OPT;
	}
	return EXIT_SUCCESS;
}
void enter_case(int* opt){
	int element = 0;
ENTER_NUMBER_ELEMENT:
	memset(num, 0, 256);
	printf("please enter number: ");
	fgets(num, 256, stdin);
	sscanf (num,"%d", &element);
	if(element < 1 || element > 100){
		goto ENTER_NUMBER_ELEMENT;
	}
	enter_element(&element);
	(*opt)++;
}
void enter_element(int* element){
int count = 0;

}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_BUFFER 1024
typedef struct {
	unsigned long long square;
	void * next;
} LINK_LIST_RESTULT;

LINK_LIST_RESTULT * result = 0;
LINK_LIST_RESTULT * last_node = 0;
#define MIN_TEST_CASE 1
#define MAX_TEST_CASE 100
#define MIN_TEST_ELEM 1
#define MAX_TEST_ELEM 100
int number_test_case = 0;
int numbers = 0;
int  enter_number(int, int, char*);
void enter_test_cases(int);
void enter_elements(int, LINK_LIST_RESTULT **);
unsigned long long get_square (char*, int);
void hdeeva_out_put();
char buffer[MAX_BUFFER];

int main (int argc, char* argv[]){
	fprintf(stdout, "Please read readme.text.\nSample Input:\n");
	number_test_case = enter_number(MIN_TEST_CASE, MAX_TEST_CASE, "Please enter number of test case: ");
	enter_test_cases(number_test_case);
	hdeeva_out_put();
	return EXIT_SUCCESS;
}
int enter_number(int min, int max, char* message){
	int num = 0;
ENTER_NUMBER:
	memset(buffer, 0, MAX_BUFFER);
	fgets(buffer, MAX_BUFFER, stdin);
	sscanf (buffer,"%d", &num);
	if(num < min || num > max){
		fprintf(stdout, "Wrong entering. Please retry.\n");
		goto ENTER_NUMBER;
	}
	return num;
}
void enter_test_cases(int _case){
	int cur_case = 0;
	int elements = 0;
	char message[128];
ENTER_TEST_CASE:
	memset(message, 0, 128);
//	sprintf(message, "Please enter number of elements for %ith case:", cur_case + 1);
	elements = enter_number(MIN_TEST_ELEM, MAX_TEST_ELEM, message);

	enter_elements(elements, &last_node);
	cur_case++;
	if(cur_case < _case){
		goto ENTER_TEST_CASE;
	}
}
void enter_elements(int element, LINK_LIST_RESTULT ** rs){
	unsigned long long square = 0;
	char message[128];
ENTER_ELEMENTS:
	memset(message, 0, 128);
	memset(buffer, 0, MAX_BUFFER);
	sprintf(message, "Please enter %i element(s): ", element );
//	fprintf(stdout, "%s", message);
	fgets(buffer, MAX_BUFFER, stdin);
	square = get_square(buffer, element);
	if(square < 1){
		fprintf(stdout, "Wrong entering. Please retry.\n");
		goto ENTER_ELEMENTS;
	}
	if((*rs) == 0){
		(*rs) = (LINK_LIST_RESTULT *) malloc(sizeof(LINK_LIST_RESTULT));
		(*rs)->next = 0;
		(*rs)->square = square;
		result = (*rs);
	}
	else{
		LINK_LIST_RESTULT * t = (LINK_LIST_RESTULT *) malloc(sizeof(LINK_LIST_RESTULT));
		t->next = 0;
		t->square = square;
		(* rs)->next = t;
		(* rs) = t;
	}
}
unsigned long long get_square (char* data, int element){
	unsigned long long rs = 0;
	char * pch;
	int temp = 0;
	int status = 0;
	int i = 0;
	pch = strtok (data," ");
GET_SQUARE:
	if(pch != 0){
		status = sscanf (pch,"%i", &temp);
		if(status < 1){
			return 0;
		}
		if(temp > 0){
			rs += (unsigned long long)((unsigned long long)temp * (unsigned long long)temp);
		}
		pch = strtok (0," ");
		++i;
		goto GET_SQUARE;
	}
	if(i != element){
		fprintf(stdout, "Wrong entering. Please retry.\n");
		return 0;
	}
	return rs;
}
void hdeeva_out_put(){
	fprintf(stdout, "Sample Output:\n");
	LINK_LIST_RESTULT * t;
HDEEVA_OUT_PUT:
	t = result;
	if(t != 0){
		fprintf(stdout, "%lld\n", t->square);
		result = (LINK_LIST_RESTULT * )result->next;
		free(t);
		goto HDEEVA_OUT_PUT;
	}
	result = 0;
}

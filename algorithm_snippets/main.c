#include <stdio.h>
#include <time.h>
#include "multiply.h"
#include "euclid.h"
#define LOOP 1000000
void test_multiply_funcs(void);
void test_euclid_funcs(void);
void print_time(int (*func)(int, int), int, int, char*);

int main(void) {
	
	test_multiply_funcs();
	test_euclid_funcs();

	return 0;
}

void test_multiply_funcs(void) {
	print_time(multiply_decimal_decomposition, 10, 20, "multiply_decimal_decomposition");
	print_time(a_la_russe, 10, 20, "a_la_russe");
}

void test_euclid_funcs(void) {
	print_time(get_gcd, 280, 30, "get_gcd");
	print_time(get_gcd_recursion, 280, 30, "get_gcd_recursion");
	print_time(get_gcd_fast, 332, 10, "get_gcd_fast");
	print_time(get_gcd_fast_recursion, 16, 332, "get_gcd_fast_recursion");
}

void print_time(int (*func)(int, int), int a, int b, char* func_name) {
	clock_t start, end;
	double duration;
	start = clock();
	for(int i=0; i< LOOP; i++) func(a, b);
	end = clock();
	duration = (double)(end - start) / CLOCKS_PER_SEC;
	printf("%30s \tduration : %fs, \tstart : %ld,\t end : %ld\n", func_name, duration, start, end);
}
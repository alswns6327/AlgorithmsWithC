#include <stdio.h>
#include <time.h>
#include "multiply.h"
#include "euclid.h"
#include "prime_number.h"

#define LOOP 1000000

void test_multiply_funcs(void);
void test_euclid_funcs(void);
void print_time(int (*func)(int), int, char*);
void print_time2(int (*func)(int, int), int, int, char*);
void test_prime_number_funcs(void);

static clock_t start, end;
static double duration;

int main(void) {
	
	/*test_multiply_funcs();
	test_euclid_funcs();
	test_prime_number_funcs();*/
	sieve_of_eratosthenes(30);

	return 0;
}

void test_multiply_funcs(void) {
	print_time2(multiply_decimal_decomposition, 10, 20, "multiply_decimal_decomposition");
	print_time2(a_la_russe, 10, 20, "a_la_russe");
}

void test_euclid_funcs(void) {
	print_time2(get_gcd, 280, 30, "get_gcd");
	print_time2(get_gcd_recursion, 280, 30, "get_gcd_recursion");
	print_time2(get_gcd_fast, 332, 10, "get_gcd_fast");
	print_time2(get_gcd_fast_recursion, 16, 332, "get_gcd_fast_recursion");
}

void test_prime_number_funcs(void) {
	print_time(is_prime, 103, "is_prime");
	print_time(is_prime2, 3000, "is_prime2");
}

void print_time(int (*func)(int), int n, char* func_name) {
	start = clock();
	for (int i = 0; i < LOOP; i++) func(n);
	int res = func(n);
	end = clock();
	duration = (double)(end - start) / CLOCKS_PER_SEC;
	printf("%30s \tduration : %fs, \tstart : %ld,\tend : %ld\tresult : %s\n", func_name, duration, start, end, res ? "is prime" : "is not prime");
}

void print_time2(int (*func)(int, int), int a, int b, char* func_name) {
	start = clock();
	for(int i=0; i< LOOP; i++) func(a, b);
	int res = func(a, b);
	end = clock();
	duration = (double)(end - start) / CLOCKS_PER_SEC;
	printf("%30s \tduration : %fs, \tstart : %ld,\tend : %ld\tresult : %d\n", func_name, duration, start, end, res);
}


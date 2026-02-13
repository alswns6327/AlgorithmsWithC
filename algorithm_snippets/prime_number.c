#include "common.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

int is_prime(int num) {
	if (num < 2) return FALSE;
	for (int i = 2; i < num; i++) 
		if (num % i == 0) return FALSE;
	
	return TRUE;
}

int is_prime2(int num) {
	if (num < 2) return FALSE;

	int sqrn = (int) sqrt(num);
	for (int i = 2; i <= sqrn; i++)
		if (num % i == 0) return FALSE;
	
	return TRUE;
}

void sieve_of_eratosthenes(int num) {
	int* ary = (int*)calloc(++num, sizeof(int));
	if (ary == NULL) {
		printf("\n 오류 발생");
		exit(1);
	}
	for (int i = 2; i*i <= num; i++) {
		if (ary[i]) continue;
		for (int j = i + i; j <= num; j += i) {
			ary[j] = 1;
		}
	}
	for (int i = 2; i < num; i++) {
		if(!ary[i]) printf("%3d", i);
	}
	free(ary);
}
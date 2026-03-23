#include "ary_stack.h"
#include "linked_stack.h"
#include "calcutil.h"
#include <stdio.h>
#include <string.h>
int main(void) {
	char a[50] = "(((2*3)+(6/2))-4)", b[50];

	postfix1(b, a);
	printf("\n%s = %s, %s\n%d\n\n",a, b, is_legal(b) ? "good" : "bad", calc(b));

	char c[20] = "2*3+6/2-4";
	postfix2(b, c);
	printf("\n%s = %s, %s\n%d\n\n", c, b, is_legal(b) ? "good" : "bad", calc(b));

	return 0;
}
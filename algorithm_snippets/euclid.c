/*
*	A와 B의 최대 공약수가 G라 가정
*	A = a * G, B = b * G 일때 
*	A-B = (a - b) * G 이므로 A-B와 B의 최대공약수 역시 G임을 알 수 있다.
*	고로 큰 수에서 작은 수를 빼나가다 한 쪽이 0이 되는 시점에서 두 수를 더하면 최대 공약수만이 남게 된다.
*	(0의 최대공약수는 모든 수)
*/
int get_gcd(int u, int v) {
	while (u * v) {
		if (u > v) u -= v;
		else v -= u;
	}
	
	return u + v;
}
/*
*	get_gcd의 재귀버전
*/
int get_gcd_recursion(int u, int v) {
	if (u * v) {
		return u > v ? get_gcd_recursion(u - v, v) : get_gcd_recursion(u, v - u);
	}
	return u + v;	
}

/*
*	GCD(A, B) = GCD(A-B, B)에서 A와 B의 차이가 크다면 A와 B의 값이 역전될 때 까지 A에는 B의 값을 상당히 여러번 빼게 된다.
*	그런 경우 나머지 연산을 통하여 한 번으로 줄일 수 있다.
*	ex) A = 332 B = 10를 A-B로 한다면 2에 도달하기 까지 33번의 뺄셈이 필요하나 A % B의 경우 한 번으로 족하다.
*/
int get_gcd_fast(int u, int v) {
	int t;
	while (u * v) {
		t = u %= v;
		u = v;
		v = t;
	}

	return u + v;
}
/*
*	get_gcd_fast의 재귀버전
*/
int get_gcd_fast_recursion(int u, int v) {
	if (u * v) {
		return get_gcd_fast_recursion(v, u % v);
	}
	return u + v;
}
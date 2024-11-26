/* Opis:
* miller_rabin(n) zwraca 1 jeśli n jest piewsze, lub w przeciwnym razie 0;
*/
long long mul(long long a, long long b, long long m) {
	return (long long)(__int128(a) * b % m);
}
long long pow(long long base, long long exp, long long mod) {
	for (long long res = 1;; exp /= 2) {
		if (exp == 0)
			return res;
		if (exp & 1)
			res = mul(res, base, mod);
		base = mul(base, base, mod);
	}
}
bool miller_rabin(long long n) {
	if (n == 2 || n == 3)
		return true;
	if (n < 2 || n % 2 == 0 || n % 3 == 0)
		return false;
	long long d = n - 1;
	int r = 0;
	while (d % 2 == 0)
		d /= 2, r++;
	for (long long base : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31}) {
		if (base % n == 0) continue;
		long long x = pow(base, d, n);
		if (x == 1)
			continue;
		bool found = false;
		for (int i = 0; i < r; i++) {
			if (x == n - 1) {
				found = true;
				break;
			}
			x = mul(x, x, n);
		}
		if (!found)
			return false;
	}
	return true;
}

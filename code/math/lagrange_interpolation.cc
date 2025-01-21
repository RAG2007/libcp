/*
* As values pass values of the polynomial at points {0, 1, ..., n}, where n is the degree of the polynomial.
* Returns the value of the polynomial with argument x.
*/

const int mod = 1e9+7;
int mul(long long a, long long b) {
	return a * b % mod;
}
int add(long long a, long long b) {
	return (a + b) % mod;
}
int normalize(long long a) {
	return (a + mod) % mod;
}
int fexp(int base, int exp) {
	for (int res = 1;; exp >>= 1) {
		if (exp == 0)
			return res;
		if (1 & exp)
			res = mul(res, base);
		base = mul(base, base);
	}
}
int pol_at_x(int x, vector<int> values /*values in points {0, 1, ..., n}*/) {
	int n = values.size()-1;
	vector<int> pref(n+1);
	vector<int> suf(n+1);
	vector<int> facinv(n+1);
	pref[0] = x;
	suf[n] = x - n;
	facinv[0] = 1;
	for (int i = 1; i <= n; i++)
		pref[i] = mul(pref[i-1], x - i);
	for (int i = n-1; i >= 0; i--)
		suf[i] = mul(suf[i+1], x - i);
	for (int i = 1; i <= n; i++)
		facinv[i] = mul(facinv[i-1], fexp(i, mod - 2));
	int res = 0;
	for (int i = 0; i <= n; i++) {
		int numerator = 1;
		if (i > 0)
			numerator = mul(numerator, pref[i-1]);
		if (i < n)
			numerator = mul(numerator, suf[i+1]);
		int denominator = 1;
		if (i > 0)
			denominator = mul(denominator, facinv[i]);
		if (i < n)
			denominator = mul(denominator, facinv[n-i]);
		int minus = 1;
		if ((n - i) & 1) minus = -1;
		
		res = add(res, minus * mul(values[i], mul(numerator, denominator)));
		res = normalize(res);
	}
	return res;
}

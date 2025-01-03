/* Opis:
	structura do hashowania stringa i otrzymywania hashu arbitrary elementu w czasie stałym
	get_hash(l, r) zwraca hash podzłowa [l, r]
*/

class hash {
	const int prime = 37;
	const long long mod = 333333333333333331;
	vector<long long> hashes;
	vector<long long> inv;

	long long mul(long long a, long long b, long long m) {
		return (long long)((__int128)a * b % m);
	}

	long long add(long long a, long long b, long long m) {
		return (long long)((__int128)((__int128)a + b) % m);
	}

	long long sub(long long a, long long b, long long m) {
		return (long long)(((__int128)(a - b) + m) % m);
	}
	public:
	hs(string &a) {
		auto exp = [&](long long base, long long exp, long long m) ->long long {
			for (long long res = 1;; exp >>= 1) {
				if (exp == 0)
					return res;
				if (1 & exp)
					res = mul(res, base, m);
				base = mul(base, base, m);
			}
		};
		hashes.resize(a.size());
		inv.resize(a.size());
		inv[0] = 1;
		inv[1] = exp(prime, mod - 2, mod);
		long long p = prime;
		hashes[0] = a[0] - 'a' + 1;
		for (int i = 1; i < (int)a.size(); i++) {
			hashes[i] = add(hashes[i-1], mul(p, a[i] - 'a' + 1, mod), mod);
			inv[i] = mul(inv[i-1], inv[1], mod);
			p = mul(p, prime, mod);
		}
	}
	long long get_hash(int l, int r) {
		long long val = hashes[r];
		if (l > 0)
			val = sub(val, hashes[l-1], mod);
		return mul(val, inv[l], mod);
	}
};

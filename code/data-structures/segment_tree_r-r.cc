/* Opis:
* update(l, r, v) dodaje do wartości na przedziale [l, r] wartość v
* query(l, r) zwraca sumę na przedziale [l, r]
*/
class seg {
	vector<long long> values;
	vector<long long> lazy;
	int size;
	void pro(int node) {
		if (node >= size)
			return;
		long long val = lazy[node] / 2;
		lazy[node] = 0;
		lazy[node * 2] += val;
		lazy[node * 2 + 1] += val;
		values[node * 2] += val;
		values[node * 2 + 1] += val;
	}
	void update(int node, int lr, int rr, int lq, int rq, int value) {
		pro(node);
		if (lq <= lr && rr <= rq) {
			values[node] += (long long)(rr - lr + 1) * value;
			lazy[node] += (long long)(rr - lr + 1) * value;
			return;
		}
		int middle = (lr + rr) / 2;
		if (lq <= middle)
			update(node * 2, lr, middle, lq, rq, value);
		if (middle < rq)
			update(node * 2 + 1, middle + 1, rr, lq, rq, value);
		values[node] = values[node * 2] + values[node * 2 + 1];
	}
	long long query(int node, int lr, int rr, int lq, int rq) {
		pro(node);
		if (lq <= lr && rr <= rq)
			return values[node];
		int middle = (lr + rr) / 2;
		long long m = 0;
		if (lq <= middle)
			m += query(node * 2, lr, middle, lq, rq);
		if (middle < rq)
			m += query(node * 2 + 1, middle + 1, rr, lq, rq);
		return m;
	}
	public:
	seg(int s) {
		size = 1 << (int)ceil(log2(s));
		values.resize(size * 2);
		lazy.resize(size * 2);
	}
	void update(int lq, int rq, int value) {
		update(1, 0, size - 1, lq, rq, value);
	}
	long long query(int lq, int rq) {
		return query(1, 0, size - 1, lq, rq);
	}
};

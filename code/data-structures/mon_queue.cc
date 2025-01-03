/*
* Opis:
* insert(x, y) dodaje element o wartości x na indeksie y,
* query() zwraca największą wartość na przedziale [mi, k], gdzie k to ostatnia dodana wartość,
* inc(v) zwiększa mi o v.
*/
class mon_queue {
	deque<pair<int, int>> q;
	int mi = 0; //max index that is valid
	public:
	void insert(int value, int index) {
		while (!q.empty() && q.back().first < value)
			q.pop_back();
		q.push_back({value, index});
	}
	int query() {
		while (!q.empty() && q.front().second < mi)
			q.pop_front();
		return q.front().first;
	}
	void inc(int value) {
		mi += value;
	}
};

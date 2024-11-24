struct mon_queue {
	deque<pair<int, int>> q;
	int mi = 0; //max index that is valid

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

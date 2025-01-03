/*
* Opis:
* update(x, v) zmienia wartość na indeksie x na v,
* query(l, r) zwraca minimalną wartość na przedziale [l, r].
*/

class segment {
        int size;
        vector<int>values;
		public:
        segment(int s) {
                size = (1 << (int)ceil(log2(s)));
                values.resize(size * 2);
        }
        void update(int index, int value) {
                index += size;
                values[index] = value;
                for (index /= 2; index > 0; index /= 2)
                        values[index] = min(values[index * 2], values[index * 2 + 1]);
        }
        int query(int l, int r) {
                int mn = INT_MAX;
                for (l += size, r += size; l <= r; l /= 2, r /= 2) {
                        if (l&1) mn = min(mn, values[l++]);
                        if (~r&1) mn = min(mn, values[r--]);
                }
                return mn;
        }
};

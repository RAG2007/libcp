/*
* Opis:
* update(x, y) zmienia wartość na indeksie x o y,
* query(l, r) zwraca sumę na przedziale [l, r].
*/

class fenwick {
        vector<long long> values;
        long long query(int index) {
                long long sum = 0;
                for (index++; index > 0; index &= (index - 1))
                        sum += values[index - 1];
                return sum;
        }
		public:
        fenwick(int size) {
                values.resize(size);
        }
        void update(int index, long long delta) {
                for (; index < (int)values.size(); index |= (index + 1))
                        values[index] += delta;
        }
        long long query(int l, int r){
                return query(r) - query(l - 1);
        }
};

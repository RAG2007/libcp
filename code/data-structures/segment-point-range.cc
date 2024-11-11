struct segment {
        int size;
        vector<long long>values;
        segment(int s) {
                size = (1 << (int)ceil(log2(s)));
                values.resize(size * 2);
        }
        void update(int index, int value) {
                index += size;
                values[index] = value;
                for (index /= 2; index > 0; index /= 2)
                        values[index] = values[index * 2] + values[index * 2 + 1];
        }
        long long query(int l, int r) {
                long long sum = 0;
                for (l += size, r += size; l <= r; l /= 2, r /= 2) {
                        if (1&l) sum += values[l++];
                        if (!(1&r)) sum += values[r--];
                }
                return sum;
        }
};

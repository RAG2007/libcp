#include <bits/stdc++.h>

using namespace std;

struct fenwick {
        vector<long long> values;
        fenwick(int size) {
                values.resize(size);
        }
        void update(int index, long long delta) {
                for (;index < (int)values.size(); index |= (index + 1))
                        values[index] += delta;
        }
        long long query(int index) {
                long long sum = 0;
                for (;index >= 0; index &= index + 1)
                        sum += values[index--];
                return sum;
        }
        long long query(int l, int r){
                return query(r) - query(l - 1);
        }
};

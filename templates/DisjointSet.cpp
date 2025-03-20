    #include <bits/stdc++.h>
    using namespace std;

    class DisjointSet {
        private:
            vector<int> parent;
            vector<int> setSize;

        public:
            DisjointSet(int N) : parent(N), setSize(N) {
                for (int i = 0; i < N; ++i) {
                    parent[i] = i;
                    setSize[i] = 1;
                }
            }

            int find(int i) {
                if (parent[i] == i)
                    return i;
                return parent[i] = find(parent[i]);
            }

            void merge(int a, int b) {
                a = find(a);
                b = find(b);

                if (a != b) {
                    parent[b] = a;
                    setSize[a] += setSize[b];
                }
            }

            int getSetSize(int a) {
                return setSize[find(a)];
            }
    };

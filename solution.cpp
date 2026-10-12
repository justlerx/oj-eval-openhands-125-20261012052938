#include <cstdio>
#include <vector>
#include <unordered_map>
using namespace std;

struct CustomHash {
    size_t operator()(const long long& key) const {
        return key ^ (key >> 32);
    }
};

class UnionFind {
private:
    vector<int> parent;
    vector<int> size;
    
public:
    UnionFind(int n) : parent(n), size(n, 1) {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    
    inline int find(int x) {
        while (parent[x] != x) {
            parent[x] = parent[parent[x]]; // Path compression
            x = parent[x];
        }
        return x;
    }
    
    inline void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        
        if (rootX == rootY) return;
        
        // Union by size
        if (size[rootX] < size[rootY]) {
            parent[rootX] = rootY;
            size[rootY] += size[rootX];
        } else {
            parent[rootY] = rootX;
            size[rootX] += size[rootY];
        }
    }
    
    inline bool connected(int x, int y) {
        return find(x) == find(y);
    }
};

struct Constraint {
    int i, j, e;
};

int main() {
    int t;
    scanf("%d", &t);
    
    while (t--) {
        int n;
        scanf("%d", &n);
        
        vector<Constraint> constraints;
        constraints.reserve(n);
        
        unordered_map<long long, int, CustomHash> id_map;
        id_map.reserve(n * 2);
        int next_id = 0;
        
        // Read all constraints and collect unique variables
        for (int k = 0; k < n; k++) {
            long long i, j;
            int e;
            scanf("%lld %lld %d", &i, &j, &e);
            
            int id_i, id_j;
            auto it_i = id_map.find(i);
            if (it_i == id_map.end()) {
                id_i = next_id++;
                id_map[i] = id_i;
            } else {
                id_i = it_i->second;
            }
            
            auto it_j = id_map.find(j);
            if (it_j == id_map.end()) {
                id_j = next_id++;
                id_map[j] = id_j;
            } else {
                id_j = it_j->second;
            }
            
            constraints.push_back({id_i, id_j, e});
        }
        
        UnionFind uf(next_id);
        
        // Process equality constraints first
        for (const auto& constraint : constraints) {
            if (constraint.e == 1) {
                uf.unite(constraint.i, constraint.j);
            }
        }
        
        // Check inequality constraints
        bool possible = true;
        for (const auto& constraint : constraints) {
            if (constraint.e == 0) {
                if (uf.connected(constraint.i, constraint.j)) {
                    possible = false;
                    break;
                }
            }
        }
        
        printf("%s\n", possible ? "YES" : "NO");
    }
    
    return 0;
}
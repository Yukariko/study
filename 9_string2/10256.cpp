#include <bits/stdc++.h>

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif
using ll = long long;
using ld = long double;

using namespace std;

int toNum(char c)
{
    switch (c) {
    case 'A': return 0;
    case 'C': return 1;
    case 'G': return 2;
    case 'T': return 3;
    }
    return -1;
}

struct Trie {
    array<Trie *, 4> nodes = {};
    Trie *fail_node = nullptr;
    int end = 0;

    ~Trie()
    {
        for (int i=0; i < 4; i++)
            if (nodes[i] != nullptr)
                delete nodes[i];
    }

    void insert(const char *s)
    {
        if (*s == '\0') { end = 1; return; }
        Trie * &next = nodes[toNum(*s)];
        if (next == nullptr) next = new Trie;
        next->insert(s + 1);
    }

    int find(const char *s)
    {
        if (*s == '\0') return end;
        int idx = toNum(*s);
        Trie * &next = nodes[idx];
        if (next == nullptr) return end + find_fail_node(this, idx)->find(s + 1);
        return end + next->find(s + 1);
    }

    static Trie * find_fail_node(Trie *node, int idx)
    {
        Trie *tmp = node->fail_node;
        while (tmp->fail_node != tmp && tmp->nodes[idx] == nullptr)
            tmp = tmp->fail_node;
        if (tmp->nodes[idx] != nullptr)
            tmp = tmp->nodes[idx];
        return tmp;
    }

    static void build_failure_func(Trie * root)
    {
        queue<Trie *> q;
        root->fail_node = root;
        for (int i=0; i < 4; i++) {
            if (root->nodes[i] == nullptr) continue;
            root->nodes[i]->fail_node = root;
            q.push(root->nodes[i]);
        }

        while (!q.empty()) {
            Trie *node = q.front();
            q.pop();

            for (int i=0; i < 4; i++) {
                Trie *child = node->nodes[i];
                if (child == nullptr) continue;
                child->fail_node = find_fail_node(node, i);
                child->end += child->fail_node->end;
                q.push(child);
            }
        }
    }
};

Trie *root;
int N, M;
char dna[1000001];
char marker[101];
bool visited[101][101];

void build_mutation()
{
    for (int i=0; i < M; i++) {
        for (int j=i+1; j <= M; j++) {
            reverse(marker + i, marker + j);
            root->insert(marker);
            reverse(marker + i, marker + j);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        Trie trie;
        root = &trie;
        cin >> N >> M;
        cin >> dna >> marker;

        memset(visited, 0, sizeof(visited));
        build_mutation();
        Trie::build_failure_func(root);
        cout << root->find(dna) << endl;
    }

    return 0;
}

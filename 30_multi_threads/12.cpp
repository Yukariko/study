#include <bits/stdc++.h>

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif
using ll = long long;
using ld = long double;

using namespace std;

template <typename T>
struct SafeQueue
{
	struct Node {
		T elem;
		Node *next = nullptr;
		Node(const T& elem) : elem(elem) {}
	};

	Node *head = nullptr, *tail = nullptr;

	SafeQueue()
	{
	}

	~SafeQueue()
	{
		while (pop()) {
		}
	}

	void push(T elem)
	{
		Node *node = new Node(elem);
		while (head == nullptr) {
			if (__sync_bool_compare_and_swap(&head, nullptr, node)) {
				__sync_bool_compare_and_swap(&tail, nullptr, node);
				return;
			}
		}
		while (true) {
			Node *last = tail;
			if (last == nullptr) continue;
			if (last->next == nullptr) {
				if (__sync_bool_compare_and_swap(&last->next, nullptr, node)) {
					__sync_bool_compare_and_swap(&tail, last, node);
					return;
				}
			} else {
				__sync_bool_compare_and_swap(&tail, last, last->next);
			}
		}
	}

	bool empty()
	{
		return head == nullptr;
	}

	bool pop()
	{
		Node *first, *last;
		while (true) {
			first = head;
			last = tail;
			if (first == nullptr) {
				return false;
			}
			if (first == last) {
				__sync_bool_compare_and_swap(&tail, last, nullptr);
				continue;
			}
			if (__sync_bool_compare_and_swap(&head, first, first->next)) {
				break;
			}
		}

		free(first);
		return true;
	}
};

struct ItemList
{
	SafeQueue<string> items;
	ItemList()
	{
	}

	~ItemList()
	{
	}

	bool buy()
	{
		return items.pop();
	}

	void sell(string name)
	{
		items.push(name);
	}
};

struct Auction {
	map<string, ItemList> items;
	pthread_rwlock_t rwlock;

	Auction() {
		pthread_rwlock_init(&rwlock, NULL);
	}

	~Auction() {
		pthread_rwlock_destroy(&rwlock);
	}

	bool buy(string name)
	{
		bool ret = false;
		pthread_rwlock_rdlock(&rwlock);
		if (items.find(name) != items.end()) {
			ret = items[name].buy();
		}
		pthread_rwlock_unlock(&rwlock);
		return ret;
	}

	void sell(string name, string user)
	{
		pthread_rwlock_rdlock(&rwlock);
		if (items.find(name) != items.end()) {
			items[name].sell(user);
			pthread_rwlock_unlock(&rwlock);
			return;
		}
		pthread_rwlock_unlock(&rwlock);
		pthread_rwlock_wrlock(&rwlock);
		items[name].sell(user);
		pthread_rwlock_unlock(&rwlock);
	}
};

Auction auc;

string generate_item_name()
{
	string name = "";
	name += rand() % 26 + 'A';
	name += rand() % 26 + 'A';
	return name;
}

void *run(void* arg)
{
	string myname = *(string *)arg;
	for (int i=0; i < 100000; i++) {
		string name = generate_item_name();

		if (rand() % 2 == 1) {
			auc.buy(name);
		} else {
			auc.sell(name, myname);
		}
	}
	return NULL;
}


const int max_threads = 2;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	pthread_t threads[max_threads];
	string names[4] = { "kangmin", "chayoung", "seungmin", "ikhee" };

	for (int i=0; i < max_threads; i++) {
		pthread_create(&threads[i], NULL, run, &names[i]);
	}
	for (int i=0; i < max_threads; i++) {
		pthread_join(threads[i], NULL);
	}

	return 0;
}

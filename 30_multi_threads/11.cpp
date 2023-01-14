#include <bits/stdc++.h>

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif
using ll = long long;
using ld = long double;

using namespace std;

struct ItemList
{
	queue<pair<string, int>> items;
	pthread_mutex_t _lock;
	ItemList()
	{
		pthread_mutex_init(&_lock, NULL);
	}

	~ItemList()
	{
		pthread_mutex_destroy(&_lock);
	}

	bool buy(int cnt)
	{
		pthread_mutex_lock(&_lock);
		while (cnt > 0 && !items.empty()) {
			auto item = items.front();
			int num = min(cnt, item.second);
			cnt -= num;
			item.second -= num;
			if (item.second == 0) {
				items.pop();
			}
		}
		pthread_mutex_unlock(&_lock);
		if (cnt == 0) {
			return true;
		}
		return false;
	}

	void sell(string name, int cnt)
	{
		pthread_mutex_lock(&_lock);
		items.emplace(name, cnt);
		pthread_mutex_unlock(&_lock);
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

	bool buy(string name, int cnt)
	{
		bool ret = false;
		pthread_rwlock_rdlock(&rwlock);
		if (items.find(name) != items.end()) {
			ret = items[name].buy(cnt);
		}
		pthread_rwlock_unlock(&rwlock);
		return ret;
	}

	void sell(string name, string user, int cnt)
	{
		pthread_rwlock_rdlock(&rwlock);
		if (items.find(name) != items.end()) {
			items[name].sell(user, cnt);
			pthread_rwlock_unlock(&rwlock);
			return;
		}
		pthread_rwlock_unlock(&rwlock);
		pthread_rwlock_wrlock(&rwlock);
		items[name].sell(user, cnt);
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
		int cnt = rand() % 100 + 1;

		if (rand() % 2 == 1) {
			auc.buy(name, cnt);
		} else {
			auc.sell(name, myname, cnt);
		}
	}
	return NULL;
}


const int max_threads = 4;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	pthread_t threads[max_threads];
	string names[max_threads] = { "kangmin", "chayoung", "seungmin", "ikhee" };

	for (int i=0; i < max_threads; i++) {
		pthread_create(&threads[i], NULL, run, &names[i]);
	}
	for (int i=0; i < max_threads; i++) {
		pthread_join(threads[i], NULL);
	}

	return 0;
}

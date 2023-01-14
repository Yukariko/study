#include <bits/stdc++.h>

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif
using ll = long long;
using ld = long double;

using namespace std;


struct SafeInt
{
	pthread_mutex_t _lock;
	int num;

	SafeInt(int n = 0) : num(n)
	{
		pthread_mutex_init(&_lock, NULL);
	}

	~SafeInt()
	{
		pthread_mutex_destroy(&_lock);
	}

	bool sub_if_ge(int n)
	{
		pthread_mutex_lock(&_lock);
		if (num >= n) {
			num -= n;
			pthread_mutex_unlock(&_lock);
			return true;
		}
		pthread_mutex_unlock(&_lock);
		return false;
	}

	void operator+=(int n)
	{
		pthread_mutex_lock(&_lock);
		num += n;
		pthread_mutex_unlock(&_lock);
	}

	void operator-=(int n)
	{
		pthread_mutex_lock(&_lock);
		num -= n;
		pthread_mutex_unlock(&_lock);
	}

};

struct Auction {
	map<string, SafeInt> items;
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
			ret = items[name].sub_if_ge(cnt);
		}
		pthread_rwlock_unlock(&rwlock);
		return ret;
	}

	void sell(string name, int cnt)
	{
		pthread_rwlock_rdlock(&rwlock);
		if (items.find(name) != items.end()) {
			items[name] += cnt;
			pthread_rwlock_unlock(&rwlock);
			return;
		}
		pthread_rwlock_unlock(&rwlock);
		pthread_rwlock_wrlock(&rwlock);
		items[name] += cnt;
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
	for (int i=0; i < 1000; i++) {
		string name = generate_item_name();
		int cnt = rand() % 100 + 1;

		if (rand() % 2 == 1) {
			auc.buy(name, cnt);
		} else {
			auc.sell(name, cnt);
		}
	}
	return NULL;
}


const int max_threads = 4;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	pthread_t threads[max_threads];
	//string names[max_threads] = { "kangmin", "chayoung", "seungmin", "ikhee" };

	for (int i=0; i < max_threads; i++) {
		pthread_create(&threads[i], NULL, run, nullptr);
	}
	for (int i=0; i < max_threads; i++) {
		pthread_join(threads[i], NULL);
	}

	return 0;
}

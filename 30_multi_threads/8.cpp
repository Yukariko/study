#include <bits/stdc++.h>

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif
using ll = long long;
using ld = long double;

using namespace std;


struct Auction {
	map<string, int> items;
	pthread_mutex_t plock;

	Auction() {
		for (int i=0; i < 26; i++) {
			for (int j=0; j < 26; j++) {
				string name = "";
				name += 'A' + i;
				name += 'A' + j;
				items[name] = 0;
			}
		}
		pthread_mutex_init(&plock, NULL);
	}

	bool buy(string name, int cnt)
	{
		pthread_mutex_lock(&plock);
		if (items[name] >= cnt) {
			items[name] -= cnt;
			pthread_mutex_unlock(&plock);
			return true;
		}
		pthread_mutex_unlock(&plock);
		return false;
	}

	void sell(string name, int cnt)
	{
		pthread_mutex_lock(&plock);
		items[name] += cnt;
		pthread_mutex_unlock(&plock);
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


const int max_threads = 2;

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

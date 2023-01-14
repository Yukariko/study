#include <bits/stdc++.h>

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif
using ll = long long;
using ld = long double;

using namespace std;

volatile bool turn;
volatile int counter;
pthread_mutex_t plock;

void *run(void* arg)
{
	for (int i=0; i < 1000000; i++) {
		while (!__sync_bool_compare_and_swap(&turn, false, true));
		counter++;
		turn = false;
	}
	return NULL;
}


const int max_threads = 5;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	pthread_t threads[max_threads];

	pthread_mutex_init(&plock, NULL);
	for (int i=0; i < max_threads; i++) {
		pthread_create(&threads[i], NULL, run, nullptr);
	}
	for (int i=0; i < max_threads; i++) {
		pthread_join(threads[i], NULL);
	}

	cout << counter << endl;

	return 0;
}

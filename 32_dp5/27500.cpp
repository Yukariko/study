#include <bits/stdc++.h>

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif
using ll = long long;
using ld = long double;

using namespace std;

int hp1, hp2;
int d1, d2, d3, d4;
int M;
int fr[316];
pair<int, int> cache[302][302][302];
tuple<int, int, int> sel[302][302][302];

pair<int, int> solve(int frame, int jax, int fiora)
{
	if (frame >= 302 || jax <= 0) {
		return {302, 0};
	}

	if (fiora <= 0) {
		return {frame, -jax};
	}

	auto& ret = cache[frame][jax][fiora];
	if (ret.first != 0) {
		return ret;
	}
	auto& s = sel[frame][jax][fiora];
	int dmg = fr[frame] == 1? d3: fr[frame] == 3? d4: 0;
	ret = solve(frame + 1, jax - dmg, fiora);
	s = {0, jax - dmg, fiora};

	for (int i = 1; i <= 4; i++) {
		dmg += fr[frame + i] == 1? d3: fr[frame + i] == 3? d4: 0;
	}
	int fdmg = fr[frame + 4] == 2? 0: d1;
	auto nret = solve(frame + 5, jax - dmg, fiora - fdmg);
	if (ret > nret) {
		ret = nret;
		s = {1, jax - dmg, fiora - fdmg};
	}
	dmg = fr[frame + 14] == 1? d3: fr[frame + 14] == 3? d4: 0;
	fdmg = fr[frame + 14] == 2? 0: d2;
	nret = solve(frame + 15, jax - dmg, fiora - fdmg);
	if (ret > nret) {
		ret = nret;
		s = {2, jax - dmg, fiora - fdmg};
	}
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> hp1 >> hp2;
	cin >> d1 >> d2 >> d3 >> d4;
	cin >> M;
	for (int i = 0; i < M; i++) {
		int frame;
		string skill;
		cin >> frame >> skill;

		if (skill == "attack") {
			fr[frame + 4] = 1;
		} else {
			for (int j = 0; j < 9; j++) {
				fr[frame + j] = 2;
			}
			fr[frame + 9] = 3;
		}
	}

	auto ans = solve(0, hp1, hp2);
	if (ans.first == 302) {
		cout << "NO" << endl;
		return 0;
	}

	cout << "YES" << endl;
	int frame = 0;
	int jax = hp1;
	int fiora = hp2;
	while (frame <= 302 || fiora > 0) {
		auto& [action, njax, nfiora] = sel[frame][jax][fiora];
		if (action == 0) {
			frame += 1;
		} else if (action == 1) {
			cout << frame << " " << "attack" << endl;
			frame += 5;
		} else {
			cout << frame << " " << "counter strike" << endl;
			frame += 15;

		}
		jax = njax;
		fiora = nfiora;
	}

	return 0;
}


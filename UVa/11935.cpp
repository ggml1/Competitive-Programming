#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const double eps = 1e-6;

bool can(vector<pair<double, pair<string, double>>> events, double gas, double cons) {
	double orig = gas;

	double leak = 0;

	double last = 0;

	for (auto x : events) {
		double need = cons * (x.first - last) / 100.00;

		need += (x.first - last) * leak;

		last = x.first;

		if (need - gas > eps) {
			return 0;
		}

		if (x.second.first == "Gas") {
			gas = orig;
			continue;
		} else if (x.second.first == "Leak") {
			leak += 1.0;
		} else if (x.second.first == "Mechanic") {
			leak = 0.0;
		} else if (x.second.first == "Fuel") {
			cons = x.second.second;
		}

		gas -= need;
	}

	return 1;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(nullptr);

	string s;

	string a1, a2, a3, a4;

	string endd = "0 Fuel consumption 0";

	while (getline(cin, s) && s.compare(endd)) {
		stringstream a(s);

		a >> a1 >> a2 >> a3 >> a4;

		int consumption = stoi(a4);

		vector<pair<double, pair<string, double>>> all;

		while (getline(cin, s) && s.find("Goal") == string::npos) {
			string d, e, f; double change;

			stringstream b(s);

			if (s.find("Fuel consumption") != string::npos) {
				b >> d >> e >> f >> change;
				all.push_back({(double) stoi(d), {e, change}});
			} else {
				b >> d >> e;

				int dist = stoi(d);

				all.push_back({(double) dist, {e, 0}});
			}
		}

		string event, d; stringstream b(s); b >> d >> event;

		all.push_back({(double) stoi(d), {event, 0.0}});
		////////
		double lo = 0, hi = 1e5 + 1;

		for (int i = 0; i < 100; ++i) {
			if (hi - lo < eps) break;

			double mid = (lo + hi) / 2.0;

			if (can(all, mid, consumption)) hi = mid;
			else {
				lo = mid;
			}
		}

		cout << fixed << setprecision(3) << hi << endl;
	}

    return 0;
}

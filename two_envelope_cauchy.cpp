#include <bits/stdc++.h>
using namespace std;


#define M_PIl 3.141592653589793238462643383279502884L // i don't have this for some reason

// nevermind, unused for optimization
long double positiveCauchy(mt19937 &rng, uniform_real_distribution<long double> &dist){
	long double u = dist(rng);
	return tanl(M_PIl*u);
}

int main() {
	mt19937 rng(random_device{}());
	uniform_real_distribution<long double> dist(0.0L, 0.5L*M_PIl);
	uniform_int_distribution<int> coin(0, 1);
	long double totalSwitch = 0.0L, totalStay = 0.0L;
	cout.precision(12);

	long double heads = 0.0L;
	for (int chunks = 0; true; chunks++){ // two loops so it doesn't print too much
		int chunkSize = 10000000;
		for (int i = 0; i < chunkSize; i++){
			long double smaller = tanl(dist(rng)); // tan of uniform [0,pi/2]
			if(coin(rng)){ // 50% chance first choice is bigger
				heads += 1.0L;
				totalSwitch += smaller;
				totalStay += 2.0L*smaller;
			}
			else{
				totalSwitch += 2.0L*smaller;
				totalStay += smaller;
			}
		}
		long double n = ((long double)(chunks+1)*chunkSize); // trials so far
		cout << "n = " << n << "\n";
		// cout << "heads/n = " << heads/n <<"\n";
		cout << "switch/stay = " << totalSwitch/n << " / " << totalStay/n << "\n";
		cout << "            = " << totalSwitch/totalStay << "\n";
		cout << "switch-stay = " << (totalSwitch-totalStay) / n << "\n";
		// cout << "switch, stay = " << totalSwitch << ", " << totalStay << "\n";
	}

	return 0;
}

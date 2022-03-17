//TASK: https://cses.fi/dt/task/346
//Solution below.

#include <vector>
#include <iostream>
#include <algorithm>
 
using namespace std;
 
int sumUpTo(int num) {
	return (num*num + num) / 2;
}
 
int main()
{
	int luku;
	vector<int> lukulista;
	cin >> luku;
	for (int i = 0; i <= luku; i++) {
		lukulista.push_back(i);
	}
	int tavoite = ((luku*luku+luku) / 2) / 2;
 
	vector<vector<long long>> taulukko = { {} }; //1 true, 0 false
	for (int sarake = 0; sarake <= luku; sarake++) {
		taulukko[0].push_back(1);
	}
	for (int rivi = 1; rivi <= tavoite; rivi++) {
		taulukko.push_back({0});
	}
 
 
	for (int rivi = 1; rivi < taulukko.size(); rivi++) {
		for (int sarake = 1; sarake <= luku; sarake++) {
 
			if (rivi - lukulista[sarake] >= 0) {
				taulukko[rivi].push_back(taulukko[rivi][sarake - 1]+taulukko[rivi - lukulista[sarake]][sarake-1]);
			} else {
				taulukko[rivi].push_back(taulukko[rivi][sarake-1]);
			}
 
		}
	}
 
 
	if (((luku*luku + luku) / 2) % 2 == 0) {
		cout << taulukko.back().back() / 2;
	} else {
		cout << "0" << endl;
	}
 
	int a;
	cin >> a;
	//LOPPUHOMMAT OK
  return 0;
}

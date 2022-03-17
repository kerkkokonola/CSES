//TASK: https://cses.fi/dt/task/722/

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
 
using namespace std;
 
int kuutiolkm;
int suurin;
vector<int> kuutiot;
multiset<int> tornit;
 
int main()
{
	cin >> kuutiolkm;
 
	for (int i = 0; i < kuutiolkm; i++) {
		int UI;
		cin >> UI;
		kuutiot.push_back(UI);
		suurin = max(suurin, UI);
	}
 
	tornit = { kuutiot[0] };
 
 
	for (int i = 1; i < (int)kuutiot.size(); i++) {
		bool done = false;
		auto it = tornit.upper_bound(kuutiot[i]);
		if (it != tornit.end()) {
			tornit.erase(it);
			tornit.insert(kuutiot[i]);
		} else {
			tornit.insert(kuutiot[i]);
		}
	}
 
	cout << tornit.size() << endl;
 
  return 0;
}
 

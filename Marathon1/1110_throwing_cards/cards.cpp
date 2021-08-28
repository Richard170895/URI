#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

int main() {
	//clock_t start, end;
	//start = clock();
	vector<int> cards;
	vector<int> discarded;
	int i, j;
	int n;
	while(1) {
		cards.clear();
		discarded.clear();
		cin >> n;
		if(n == 0) {
			//end = clock();
			//double total_time = (double)(end-start)/(double)(CLOCKS_PER_SEC);
			//cout << '\n' << total_time << '\n';
			return 0;
		}
		for(i = 0; i < n; i++) {
			cards.push_back(i+1);
		}
		
		while(cards.size() > 1) {
			discarded.push_back(cards[0]);
			cards.erase(cards.begin());
			cards.push_back(cards[0]);
			cards.erase(cards.begin());
		}
		cout << "Discarded cards:";
		j = discarded.size();
		if(j > 0) cout << ' ';
		for(i = 0; i < j; i++) {
			if(i < j-1) cout << discarded[i] << ", ";
			else cout << discarded[i];
		}
		cout << '\n';
		cout << "Remaining card: " << cards[0] << '\n';
	}
	
}

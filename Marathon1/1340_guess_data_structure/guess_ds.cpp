#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>
#include <ctime>
using namespace std;
 
int main() {
	//clock_t start, end;
	//start = clock();
 	int n;
 	int op, value;
 	int q, s, p;
 	int i, j;
 	queue<int> returned;
 	stack<int> returned_back;
 	priority_queue<int> prior;
 	while(1) {
	 	if(!(cin >> n)){
	 		//end = clock();
	 		//double time_elapsed = (double)(end-start)/(double)(CLOCKS_PER_SEC);
	 		//cout << time_elapsed << '\n';
	 		return 0;
	 	} 
 		returned = queue<int> ();
 		returned_back = stack<int> ();
 	 	prior = priority_queue<int> ();
		q = 1;
		s = 1;
		p = 1;
	 	for(;n > 0; n--) {
	 		cin >> op >> value;
	 		if(op == 1) {
	 			returned.push(value);
	 			returned_back.push(value);
	 			prior.push(value);
	 		}
	 		else {
	 			if(value != returned.front()) {
	 				q = 0;
		 		}
		 		if(value != returned_back.top()) {
		 			s = 0;
		 		}
		 		if(value != prior.top()) {
		 			p = 0;
		 		}
		 		returned.pop();
		 		returned_back.pop();
		 		prior.pop();
	 		}
	 	}
	 	if(q + s + p == 0) {
			cout << "impossible\n";
		}
		else {
			if(q + s + p > 1) {
				cout << "not sure\n";
			}
			else {
				if(q == 1) {
					cout << "queue\n";
				}
				else {
					if(s == 1) {
						cout << "stack\n";
					}
					else {
						if(p == 1) {
							cout << "priority queue\n";
						}
					}
				}
			}
		}
 	}
    
    return 0;
}

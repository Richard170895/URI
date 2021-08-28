#include <iostream>
#include <map>
#include <string>
#include <ctime>
using namespace std;
 
int main() {
	map<string, string> dict;
	map<string, string>::iterator d;
	string words;
	string lines;
	string line;
	int m, n, instances;
	cin >> instances;
 	for(;instances > 0; instances--) {
 		cin >> m >> n;
 		getline(cin, words);
 		dict.clear();
	 	for(;m > 0; m--) {
	 		getline(cin, words);
	 		getline(cin, lines);
	 		dict.insert(dict.end(), pair<string, string>(words, lines));

	 	}
	 	for(;n > 0; n--) {
	 		getline(cin, lines, cin.widen('\n'));
	 		lines = lines+'\0';
	 		words = "";
	 		for(char x : lines) {
	 			if(x == ' ' or x == '\n' or x == '\0') {
	 				d = dict.find(words);
	 				if(d != dict.end()) {
	 					cout << d->second;
	 				}
	 				else {
	 					cout << words;
	 				}
	 				if(x != '\0') {
	 					cout << ' ';
	 				}
	 				words = "";
	 			}
	 			else {
	 				words = words + x;
	 			}
	 		}
	 		cout << '\n';
	 	}
	 	cout << '\n';
 	}
    
    return 0;
}

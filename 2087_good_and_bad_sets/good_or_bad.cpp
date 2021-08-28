#include <iostream>
#include <string>
#include <ctime>

using namespace std;	

struct Trie {
	Trie* children[26];
	bool end;
};

bool insert(Trie* t, string w) {
	Trie* it = t;
	int s = w.size();
	int i = 0;
	int j = 0;
	while(!it->end && i < s) {
		if(it->children[(int)w[i]-97]) {
			it = it->children[(int)w[i]-97];
		}
		else {
			it->children[(int)w[i]-97] = (Trie *) malloc(sizeof(Trie));
			it = it->children[(int)w[i]-97];
			it->end = false;
		}
		i++;
	}
	
	if(it->end) return true;
	if(i == s) {
		for(j = 0; j < 26; j++) {
			if(it->children[j]) return true;
		}
	}
	it->end = true;
	return false;
}

int main() {
	//clock_t start, end;
	//start = clock();
	int n;
	bool bad;
	string word;
	Trie* t;
	while(1) {
		t = (Trie *) malloc(sizeof(Trie));
		t->end = false;
		cin >> n;
		if(n == 0) {
			//end = clock();
			//double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    		//cout << "Time taken by program is : " << fixed 
         	//	<< time_taken;
    		//cout << " sec " << endl;
			return 0;
		}
		bad = false;
		for(;n > 0; n--) {
			cin >> word;
			if(!bad)
				bad = insert(t, word);
		}
		if(bad){
			cout << "Conjunto Ruim\n";
		}
		else {
			cout << "Conjunto Bom\n";
		}
			
	}
	
	return 0;
}

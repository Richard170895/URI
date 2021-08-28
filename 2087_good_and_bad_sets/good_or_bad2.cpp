#include <iostream>
#include <string>
#include <vector>

using namespace std;	

struct trie {
	int children[27];
	bool end = false;
	
	trie() {
		for(int i = 0; i < 27; i++) children[i] = -1;
	}
};

bool insert(vector<trie> t, string w) {
	int i = 0;
	int s = w.size();
	int n;
	int v = 0;
	char c;
	for(i = 0; i < s; i++) {
		cout << t.size() << '\n';
		if(t[v].end) {
			cout << "Entrou aqui\n";
			return true;
		}
		c = w[i];
		if(t[v].children[(int)c-97] == -1) {
			t[v].children[(int)c-97] = t.size();
			trie tr;
			t.insert(t.end, tr, 27);
		}
		v = t[v].children[(int)c-97];
	}
	t[v].end = true;
	return false;
}

vector<trie> t(1);

int main() {	
	int n;
	bool bad;
	string word;
	

	while(1) {
		cin >> n;
		if(n == 0) {
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

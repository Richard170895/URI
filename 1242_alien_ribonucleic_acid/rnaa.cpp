#include <iostream>
 
using namespace std;

int main() {
 	string received;
 	int go = 0;
 	int count;
 	bool foldable = true;
 	int i;
 	 while(cin >> received) {
 	 	count = 0;
 	 	go = 0;
 	 	foldable = true;
 		if(received.length() > 300 || received.length() < 1)
 			return 0;
 		else {
 			while(foldable) {
 				if(go == received.length()-1) {
 					foldable = false;
 				}
 				if(go+1 < received.length()) {
 					if(received[go] == 'S' && received[go+1] == 'B' || received[go] == 'B' && received[go+1] == 'S' || 
 						received[go] == 'C' && received[go+1] == 'F' || received[go] == 'F' && received[go+1] == 'C') {
 						foldable = true;
 						count++;
 						for(i = go; i < received.length(); i++) {
 							received[i] = received[i+2];
 						}
 						received[i] = '\0';
 						go = 0;
 					
 					}
 					else {
 						go++;
 					}
 				}
 			}
 			cout << count << '\n';
 		}
 	}
    return 0;
}

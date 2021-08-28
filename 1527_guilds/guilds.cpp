#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <cstdio>
//#include <ctime>

using namespace std;

int main() {
	//time_t start, end;
	//start = clock();
	int n, m, i, j, last;
	int action, player1, player2; //input... what to do and players' ids
	int gp1, gp2; //guilds of players to compare
	int p1, p2, r; //first guild's points, second guild's points, Rafael's guild
	int wins = 0; //how many victorious battles Rafael was in
	int player[100001][2];
	int guild[100001][3];
	//start
	n = 1;
	while(1) {
		cin >> n >> m;
		if(n != 0) {
			wins = 0;
			//scanf("%c");
			for(i = 0; i < n; i++) {
				if(scanf("%d", &j) == true) {
					player[i][0] = i;
					player[i][1] = -1;
					guild[i][0] = i;
					guild[i][1] = i;
					guild[i][2] = j;
				}
				else {
					i--;
				}
			}
			
			for(;m > 0; m--) { //iterates while actions still exist
				cin >> action >> player1 >> player2;
				gp1 = player[player1-1][0];
				gp2 = player[player2-1][0];
				if(action == 1) { //joins the player1's guild with player2's guild
					if(gp1 != gp2) {
						
						guild[gp1][2] = guild[gp1][2] + 
										guild[gp2][2];
						last = guild[gp1][1];
						player[last][1] = guild[gp2][0];
						guild[gp1][1] = guild[gp2][1];
						i = guild[gp2][0];
						while(i != -1) {
							player[i][0] = gp1;
							i = player[i][1];
						}
					}
				}
				else {
					if(action == 2) { //battles player1's guild vs player2's guild
						p1 = guild[gp1][2];
						p2 = guild[gp2][2];
						r = player[0][0];
						if(p1 != p2 && (r == gp1 || r == gp2)) {
							if(r == gp1 && p1 > p2) {
								wins++;
							}
							if(r == gp2 && p1 < p2) {
								wins++;
							}
						}
					}
				}
			}
			cout << wins << '\n';
		}
    	else {
			//end = clock();
			//double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    		//cout << "Time taken by program is : " << fixed 
<<<<<<< HEAD
         	//	<< time_taken;
=======
         		//<< time_taken;
>>>>>>> e19ce9cf4ff4dead15c6a7e8db071902dac85b28
    		//cout << " sec " << endl;
    		return 0; 
		}	
	}
	
}

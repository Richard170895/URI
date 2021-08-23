/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

int main()
{
    int bn = 48;
    int bc = 96;
    
    int current_knight[2];
    int current_pews[8][2];
    char knight[3];
    char pew[3];
    int j;
    int i;
    int naopode = 0;
    int go = 1;
    int count;
    int test = 0;
    int future[2][8] = {{1, 1, -1, -1, 2, 2, -2, -2}, 
    					{2, -2, 2, -2, 1, -1, 1, -1}};;
    while(1) {
        test++;
        count = 0;
        scanf("%s", knight);
        if((int)knight[0]-bn == 0) {
            return 0;
        }
        else {
            current_knight[0] = (int)knight[0]-bn;
            current_knight[1] = (int)knight[1]-bc;
            for(i = 0; i < 8; i++) {
                scanf("%s", pew);
                current_pews[i][0] = (int)pew[0]-bn;
                current_pews[i][1] = (int)pew[1]-bc;
            }
            
            for(i = 0; i < 8; i++) {
                for(j = 0; j < 8 && naopode==0; j++) {
                    if(current_knight[0] + future[0][i] > 0 && current_knight[0] + future[0][i] < 9 && current_knight[1] + future[1][i] > 0 && current_knight[1] + future[1][i] < 9) {
                        if((current_knight[0] + future[0][i] == current_pews[j][0] - 1 && current_knight[1] + future[1][i] == current_pews[j][1] + 1) ||
                           (current_knight[0] + future[0][i] == current_pews[j][0] - 1 && current_knight[1] + future[1][i] == current_pews[j][1] - 1)) {
                            naopode = 1;
                        }             
                    }
                    else {
                        naopode = 1;
                    }
                    
                }
                if(naopode == 0) {
                    count++;
                    //printf("Pode: %d%d\n", current_knight[0] + future[0][i],  current_knight[1] + future[1][i]);
                }
                else {
                	//printf("Nao pode: %d%d\n", current_knight[0] + future[0][i],  current_knight[1] + future[1][i]);
                }
                naopode = 0;
            }
            printf("Caso de Teste #%d: %d movimento(s).\n", test, count);
        }
        
    }
    return 0;
}


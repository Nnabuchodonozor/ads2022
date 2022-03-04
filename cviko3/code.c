#import <stdio.h>
#import <stdint.h>
#import <stdlib.h>


int main(int argc, const char * argv[]){
    FILE *fP;
    int a[1000][50]; 
    
    int i,j;
    for (i = 0; i < 1000; ++i) {
        for (j = 0; j < 50; ++j) {
        fscanf(fP, "%d ", &a[i][j]);
        }
    }

    



return 0;
}
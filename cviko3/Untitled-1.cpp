#include <iostream>
#include <fstream>
using namespace std;


const int ROW = 1000;
const int COL = 50;
int image[ROW][COL];
int paths[ROW][COL][3];
int main() {


ifstream fp("ADS2021_cvicenie3data.txt");
if (! fp) {
    cout << "Error, file couldn't be opened" << endl; 
    return 1; 
}    
for(int row = 0; row < ROW; row++) {  // stop loops if nothing to read
   for(int column = 0; column < COL; column++){
        fp >> image[row][column];
        if ( ! fp ) {
           cout << "Error reading file for element " << row << "," << column << endl; 
           return 1; 
        }
    }
}

for(int i = 0; i< ROW-1; i++){
    for(int j=0;j<COL;j++){
        if(i==0){    
            if(j==0){
                paths[i][j][0]=0;
                continue;
            }
            else if(j==(COL-1)){
                paths[i][j][2]=0;
                continue;
            }
            else
            {
                paths[i][j][0]=image[i+1][j-1];
                paths[i][j][1]=image[i+1][j];
                paths[i][j][2]=image[i+1][j+1];
            }
        }else{
            if(j==0){
                paths[i][j][0]=0;
                continue;
            }
            else if(j==(COL-1)){
                paths[i][j][2]=0;
                continue;
            }
            else
            {
                paths[i][j][0]=paths[i-1][j][0]+image[i+1][j-1];
                paths[i][j][1]=paths[i-1][j][1]+image[i+1][j];
                paths[i][j][2]=paths[i-1][j][2]+image[i+1][j+1];
            }
        }    
    }
}

for(int i = 0; i< ROW-1; i++){
    for(int j=0;j<COL;j++){
        cout << "[ " << paths[i][j][0] << ", " << paths[i][j][1] << ", " << paths[i][j][2] << " ] ; "; 
    }
    cout << endl;
}



 return 0;
}
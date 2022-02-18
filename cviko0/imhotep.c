#import <stdio.h>
#import <stdint.h>
#import <stdlib.h>

int combinations[176851][100];
int path[100][100];
long B = 0;

int findMinimalPath(long maxCombinations, int rows, int cols, int arr[rows][cols]){
    int j,k;
    long i;
    int poleSuctov[maxCombinations][1];
    for(i = 0; i < maxCombinations; i++){
        long sucet=0;  
        for(j = 0; j < rows; j++){            
            sucet = sucet + arr[j][combinations[i][j]];
        }
        poleSuctov[i][0]=sucet;
    }
    // for(i = 0; i < maxCombinations; i++){
    //     printf("%d \n",poleSuctov[i][0]);
    // }
    int min = 0;
    for(i = 0; i < maxCombinations; i++){
        if(abs(poleSuctov[i][0])<abs(poleSuctov[min][0])){
            min = i;
        }
    }
    printf("minimum je %d na indexe %d \n",poleSuctov[min][0],min);

    for(i = 0; i < rows; i++){
        for(j=0;j<cols;j++){
            if(j==combinations[min][i]){
                printf("\033[1;31m");
                printf("%d ",arr[i][j]);
                printf("\033[0m");
            }   
            else{
                printf("%d ",arr[i][j]);
            }     
            
        }
        printf("\n");
    }

    return 0;
}


unsigned long factorial(unsigned long f)
{
    if ( f == 0 ) 
        return 1;
    return(f * factorial(f - 1));
}

void combUtil(int chosen[], int arr[], int index, int r, int start, int end){
    if(index == r)
    {
        for(int i = 0; i < r; i++){
            combinations[B][i]=arr[chosen[i]];
            // printf(" %d",combinations[B][r]);
            }
        // printf("\n");
        B++;
        return;
    }
    for(int i = start; i <= end; i++){
        chosen[index]=i;
        combUtil(chosen,arr, index + 1,r,i,end);
    }
    return;
}

void comb(int arr[], int n, int r){
    int chosen[r+1];
    combUtil(chosen,arr,0,r,0,n-1);
}

int greedy(int rows, int cols,int arr[rows][cols]){
    int i,j;
    int sucet =0;
    int min, minj;
    
    for(i = 0; i< rows; i++){
        min =999999999;
        for(j = 0; j<cols; j++){
            if(abs(sucet+arr[i][j])<abs(sucet + min)){
                min = arr[i][j];
                minj=j;
            }                
        }
        path[i][0]=minj;
        path[i][1]=sucet;
        sucet = sucet + min;
    }

    for(i = 0; i < rows; i++){
        for(j=0;j<cols;j++){
            if(j==path[i][0]){    
                printf("\033[1;31m");
                printf("%d ",arr[i][j]);
                printf("\033[0m");
            }
            else{
                printf("%d ",arr[i][j]);

            }   
        }
        printf("  sucet   %d ",path[i][1]);

        printf("\n");
    }
    
    return sucet;
}


int main(int argc, const char * argv[]){
    FILE *fP;
    int rows, cols;
    
    if ((fP = fopen("cvicenie1data.txt","r")) == NULL){
        exit(1);
    }
    fscanf(fP,"%d",&rows);
    fscanf(fP,"%d",&cols);
    int a[rows][cols]; 
    
    int i,j;
    for (i = 0; i < rows; ++i) {
        for (j = 0; j < cols; ++j) {
        fscanf(fP, "%d, ", &a[i][j]);
        }
    }
    int sucet =0;
   
    fclose(fP);
    
    int c = greedy(rows,cols,a);
    printf("minimum je %d \n",c);
    // int arr[] = {0,1,2,3};
    // int n = 4;
    // int r = 100;
    // comb(arr,n,r);
    
    // int x = findMinimalPath(B,rows,cols,a);
    
    return 0;
}
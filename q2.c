#include<stdio.h>

int main(){
    int n;
    scanf("%d",&n);
    int nos = (n+1) * (n+1);//number of states
    int arr[2*nos + 1][nos];
    for(int i = 0; i < (2*nos + 1); i++){
        for(int j = 0; j < nos; j++){
            arr[i][j] = 0;
        }
        //printf("\n");
    }
    arr[0][nos-1] = 1;
    for(int i = 1; i <= nos; i++){
        if(i%(n+1) != 0){
            arr[i][i] = 1;
        } 
        else{
            arr[i][i-2] = 1;
        }
    }
    for(int i = nos + 1; i <= 2 * nos; i++){
        if(i+n-nos < nos){
            arr[i][i-nos+n] = 1;
        }
        else{
            arr[i][i-nos-n-2] = 1;
        }
    }
    for(int i = 0; i < (2*nos + 1); i++){
        for(int j = 0; j < nos; j++){
            printf("%d ", arr[i][j]); 
        }
        printf("\n");
    }
}
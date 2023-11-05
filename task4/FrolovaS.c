#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int ppp(int n, int m, int **a){
    if (n<0 || m<0||n>=15 || m>=15){
        return 0;
    }
    if (a[n][m]==2){
        return 0;
    }
    if (a[n][m]==0){
        return 0;
    }
    if (n==14 && m==14){
        return 1;
    }
    if (a[n][m]==1){
        a[n][m]=2;
        return ppp(n+1, m, a) || ppp(n, m+1, a) || ppp(n-1, m, a) || ppp(n, m-1, a);
    }

}

 int main (){
    srand(time(NULL));
    int n=15, m=15,i,j,res;
    scanf ("%d %d", &n, &m);
    int **a = malloc(n*sizeof(int*));
    for (i=0; i<n; i++){
        a[i]=malloc(m*sizeof(int));}
    for (i=0; i<n; i++){
        for (j=0; j<m; j++){
            int x;
            x= 1+rand()%10;
            if (x<2){
                a[i][j]=0;
            }
            else {
                a[i][j]=1;
            }
        }
        }
    a[0][0]=1;
    a[14][14]=1;
    res=ppp(0,0,a);
    for (i=0; i<n; i++){
        for (j=0; j<m; j++){
            printf("%d ", a[i][j]);
        }
        printf("\n");
        
    }
    if (res==0) {
        printf ("no ways");
    }
    else {
        printf ("there is a way");
    }
    return 0;
 }

 
 

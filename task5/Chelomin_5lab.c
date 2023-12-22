#include <stdio.h>
#include <conio.h>

int a[3][3];
void nul(){ 
    int i,j;
    for(i=1; i<=3; i++){
        for (j=1;j<=3;j++){
      a[i][j]=0;}  
 }
}

void visual(){
    int i,j;
    printf ("  1 2 3\n");
    for(i=1; i<=3; i++){
        printf ("%d", i);  
        for (j=1;j<=3;j++){   
            if (a[i][j]==0){printf("| ");};
            if (a[i][j]==1){printf("|O");};
            if (a[i][j]==2){printf("|X");};}
        printf ("|\n");   
        printf ("________\n");
 }        
}

void hod (int n){
    int hi;
    int sto; 
    int str; 
    int ver = 0;

    while (ver==0){
        printf ("Your move. Enter the row and column number. \n");  
        scanf("%d", &hi);
        sto = hi % 10;
        str = (hi - sto) / 10;
        if (a[str][sto]==0 && (hi==11 || hi==12 || hi==13 || hi==21 || hi==22 || hi==23 || hi==31 || hi==32 || hi==33 )) (ver=1);}

    if (n==1) {a[str][sto]=1;}
    if (n==2) {a[str][sto]=2;} 
}

int proverka(){   
    int i;
    int res; 
    res = 0;
 
    for (i=1; i<=3; i++){
        if (a[i][1]==1 && a[i][2]==1 && a[i][3]==1 ) {res=1;}
}
    for (i=1; i<=3; i++){
        if (a[1][i]==1 && a[2][i]==1 && a[3][i]==1 ) {res=1;}
}

    if (a[1][1]==1 && a[2][2]==1 && a[3][3]==1 )  {res=1;}
    if (a[1][3]==1 && a[2][2]==1 && a[3][1]==1 )  {res=1;}
    
    for (i=1; i<=3; i++){
        if (a[i][1]==2 && a[i][2]==2 && a[i][3]==2 ) {res=2;}
}
    for (i=1; i<=3; i++){
        if (a[1][i]==2 && a[2][i]==2 && a[3][i]==2 ) {res=2;}
}
    if (a[1][1]==2 && a[2][2]==2 && a[3][3]==2 )  {res=2;}
    if (a[1][3]==2 && a[2][2]==2 && a[3][1]==2 )  {res=2;}   
    return res;
}

void main(){
int igra = 0;

nul();

visual();

while (igra==0){
    hod(1);
    visual();
    igra = proverka();
    if (igra==0){
        hod(2);
        visual();
        igra=proverka();}
}

if (igra==1){printf ("The noughts won\n");};
if (igra==2){printf ("The crosses won\n");};
getch();
}
#include <stdio.h>
#include <stdlib.h>
void main(){
printf("input your coordinates:");
int x1,y1,x2,y2;
scanf ("%d %d %d %d",&x1, &y1, &x2, &y2);
if (abs(y1-y2)<=1 && abs(x1-x2)<=1){
    printf("King +");
}
else{printf("King -");
}
if (x1==x2 || y1==y2){
    printf("Ladya +");

}
else{
    printf("Ladya -");
}
if ((abs(x1-x2))<=7 && (abs(y1-y2))<=7){
    printf("Ferz +");
}
else{
    printf("Ferz -");
}
for(int i=1;i<=8;i++){
    if(abs(x1-x2)==i && abs(y1-y2)==i){
        printf("Slon +");
    }
    else{
        printf("Slon -");
    }
}
if((x1+1==x2&&y1+2==y2)||(x1+2==x2&&y1+1==y2)||(x1-1==x2&&y1+2==y2)||(x1-1==x2&&y1-2==y2)||(x1+1==x2&&y1-2==y2)||(x1-2==x2&&y1+1==y2||(x1-2==x2&&y1-1==y2)||(x1+2==x2&&y1-1==y2))){
    printf("Kon +");
}
else{
    printf("Kon -");
}
}


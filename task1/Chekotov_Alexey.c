#include <stdio.h>
#include <math.h>

int main()
{
    int a,b,x,y;
    scanf("%d %d %d %d",&a, &b, &x, &y);
    if (a==x || b==y){
        printf("lad\n");
    }
    if ((abs(a-x)==1 && abs(b-y)==1) || (abs(a-x)==1 && b==y) || (abs(b-y)==1 && a==x)){
        printf("kor\n");
    }
    if (abs(a-x)==abs(b-y)){
        printf("slon\n");
    }
    if ((abs(a-x)==abs(b-y)) || (a==x || b==y)){
        printf("ferz\n");
    }
    if ((abs(a-x)==1 && abs(b-y)==2) || (abs(a-x)==2 && abs(b-y)==1)){
        printf("kon");
    }
}

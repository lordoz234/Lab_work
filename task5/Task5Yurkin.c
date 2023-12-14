#include <stdio.h>
#define N 10
#include <string.h>
#define N_SYMBOLS 4


char* product[N]={"Jacket","Shirt","Shorts","Jeans","Cap","Sneakers","Bag","Backpack","Socks","T-shirt"};
int price[N]={5000,2500,2000,3000,1500,6000,1000,1300,300,500};
char* bar_code[N]={"1001","1002","1003","1004","1005","1006","1007","1008","1009","1010"};
int discount[N]={10,15,20,30,25,5,12,45,5,7};
int cnt[N]={0,0,0,0,0,0,0,0,0,0};

int scan_bar_code();
int project();
float output(int number, int i);
void add_sum(int i);
void final_sum();

int main(){
    int number,i;
    number=project();
    while(1){
        if (number==1){
            i=scan_bar_code();
            number=project();
        }
        else if(number==2){
            output(i,number);
            number=project();
        }
        else if(number==3){
            add_sum(i);
            number=project(i);
        }
        else if(number==4){
            final_sum();
            return 0;
        }

    }



}

int scan_bar_code(){
    char* code[N_SYMBOLS];
    int  i = 0;
    printf("Enter barcode:");
    scanf("%s",&code);
    for(i=0;i<N;i++){
        if(strcmp(code,bar_code[i])==0){
            printf("Item scanned!\n");
            return i;
        }

    }
    printf("This product doesn't exist!\n");



}

int project(){
    int number;
    printf("1.Scan barcode:\n 2.Desripction of the scanned product: \n 3.Add to check:\n 4.Final check:\n");
    scanf("%d",&number);
    return number;

    }

float output(int number, int i){
    int number1=i;
    int mode=number;
    float end_price;
    end_price = price[number1] - (price[number1] * discount[number1] * 0.01);
    if(mode==2){
        printf("Item: %s\nPrice: %d p.\n Count:%d\n Discount:%d % \n Price_with_dicsount:%d\n ",product[number1],price[number1],cnt[number1],discount[number1],end_price);

    }
    else{
        end_price = price[number1] * cnt[number1] - (price[number1] * cnt[number1] * discount[number1] * 0.01);
        printf("Item: %s\nPrice: %d p.\n Count:%d\n Discount:%d % \n Price_with_dicsount:%d\n ",product[number1],price[number1],cnt[number1],discount[number1],end_price);
    }
    return end_price;
    return 0;
}

void add_sum(int i){
    if(i>0 && i<11){
        int number=0;
        cnt[i]++;
        printf("Product added!\n");
    }
    else{
        printf("Please,scan barcode\n");
    }
}

void final_sum(){
int i=0, number=4;
float end_price = 0;
printf("_________CLOTHE_SHOP_________\n _________CHECK_________\n");
for (i=0;i<N;i++){
    if(cnt[i]>0){
        end_price+=output(number,i);
    }
}
printf("Total purchase amount:%f RUbles",end_price);
}

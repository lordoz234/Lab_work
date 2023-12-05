#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Prod{
    char name[50];
    int pric; // цена за единицу товара
    int kod[4];// штрихкод
    int kol;// количество определенного товара 
    int sal;// скидка в процентах
    float sum;// общая сумма за товар с учетом скидки
    float salr;// скидка в рублях 
};

int main(){
    srand (time(NULL));
    float SUM = 0;
    float SC = 0;
    int flag = 1;
    int a, b, c, d;
    int k1=0, k2=0, k3=0, k4=0, k5=0, k6=0;

    struct Prod milk;
    milk.pric = 78;
    strcpy (milk.name, "Молоко Коровье счастье");
    milk.kod[0] = 4;
    milk.kod[1] = 5;
    milk.kod[2] = 6;
    milk.kod[3] = 0;
    milk.sal = (rand()%10 + 1)*5;
    milk.sum = 0;
    milk.salr = 0;

    struct Prod cookie;
    cookie.pric = 56;
    strcpy (cookie.name, "Печенье Любятово");
    cookie.kod[0] = 5;
    cookie.kod[1] = 3;
    cookie.kod[2] = 8;
    cookie.kod[3] = 1;
    cookie.sal = (rand()%10 + 1)*5;
    cookie.sum = 0;
    cookie.salr = 0;

    struct Prod bread;
    bread.pric = 45;
    strcpy (bread.name,"Хлеб Бородинский" );
    bread.kod[0] = 9;
    bread.kod[1] = 8;
    bread.kod[2] = 9;
    bread.kod[3] = 7;
    bread.sal = (rand()%10 + 1)*5;
    bread.sum = 0;
    bread.salr = 0;

    struct Prod eggs;
    eggs.pric = 67;
    strcpy (eggs.name, "Яйца куриные");
    eggs.kod[0] = 3;
    eggs.kod[1] = 4;
    eggs.kod[2] = 8;
    eggs.kod[3] = 6;
    eggs.sal = (rand()%10 + 1)*5;
    eggs.sum = 0;
    eggs.salr = 0;

    struct Prod sweets;
    sweets.pric = 119;
    strcpy (sweets.name, "Шоколадные конфеты");
    sweets.kod[0] = 7;
    sweets.kod[1] = 1;
    sweets.kod[2] = 2;
    sweets.kod[3] = 6;
    sweets.sal = (rand()%10 + 1)*5;
    sweets.sum = 0;
    sweets.salr = 0;

    struct Prod wat;
    wat.pric = 29;
    strcpy (wat.name, "Вода негазированная");
    wat.kod[0] = 7;
    wat.kod[1] = 5;
    wat.kod[2] = 9;
    wat.kod[3] = 1;
    wat.sal = (rand()%10 + 1)*5;
    wat.sum = 0;
    wat.salr = 0;

    int *arr = (int *)malloc(4 * sizeof(int));
    while (flag==1){
        printf ("Отскранируйте товар: ");
        scanf("%d %d %d %d", &a, &b, &c, &d);
        if ((a==0)&& (b==0) && (c==0)&& (d==0)){
            flag = 0;
        }
        arr[0] = a;
        arr[1] = b;
        arr[2] = c;
        arr[3] = d;
        for (int i1=0; i1<4; i1++){
            if (arr[i1]== milk.kod[i1]){
                ++k1;
            }
            if (k1==4){
                milk.kol = k1/4;
                milk.salr = (milk.pric*(k1/4)*milk.sal)/100;
                milk.sum = milk.pric*(k1/4) - milk.salr;

            }
            if ((k1>4) && k1%4==0){
                milk.kol = k1/4;
                milk.salr = (milk.pric*(k1/4)*milk.sal)/100;
                milk.sum = milk.pric*(k1/4) - milk.salr;
                
            }
        }
        for (int i2=0; i2<4; i2++){
            if (arr[i2]== cookie.kod[i2]){
                ++k2;
            }
            if (k2==4){
                cookie.kol = k2/4;
                cookie.salr = (cookie.pric*(k2/4)*cookie.sal)/100;
                cookie.sum = cookie.pric*(k2/4) - cookie.salr;

            }
            if ((k2>4) && k2%4==0){
                cookie.kol = k2/4;
                cookie.salr = (cookie.pric*(k2/4)*cookie.sal)/100;
                cookie.sum = cookie.pric*(k2/4) - cookie.salr;
                
            }
        }
        for (int i3=0; i3<4; i3++) {
            if (arr[i3]== bread.kod[i3]){
                ++k3;
            }
            if (k3==4){
                bread.kol = k3/4;
                bread.salr = (bread.pric*(k3/4)*bread.sal)/100;
                bread.sum = bread.pric*(k3/4) - bread.salr;
            }
            }
            if ((k3>4) && k3%4==0){
                bread.kol = k3/4;
                bread.salr = (bread.pric*(k3/4)*bread.sal)/100;
                bread.sum = bread.pric*(k3/4) - bread.salr;
            }
    
        for (int i4=0; i4<4; i4++){
            if (arr[i4]== eggs.kod[i4]){
                ++k4;
            }
            if (k4==4){
                eggs.kol = k4/4;
                eggs.salr = (eggs.pric*(k4/4)*eggs.sal)/100;
                eggs.sum = eggs.pric*(k4/4) - eggs.salr;
            }
            if ((k4>4) && k4%4==0){
                eggs.kol = k4/4;
                eggs.salr = (eggs.pric*(k4/4)*eggs.sal)/100;
                eggs.sum = eggs.pric*(k4/4) - eggs.salr;
            }
        }
        for (int i5=0; i5<4; i5++){
            if (arr[i5]== sweets.kod[i5]){
                ++k5;
            }
            if (k5==4){
                sweets.kol = k5/4;
                sweets.salr = (sweets.pric*(k5/4)*sweets.sal)/100;
                sweets.sum = sweets.pric*(k5/4) - sweets.salr;
            }
            if ((k5>4) && k5%4==0){
                sweets.kol = k5/4;
                sweets.salr = (sweets.pric*(k5/4)*sweets.sal)/100;
                sweets.sum = sweets.pric*(k5/4) - sweets.salr;
            }
        }
        for (int i6=0; i6<4; i6++){
            if (arr[i6]== wat.kod[i6]){
                ++k6;
            }
            if (k6==4){
                wat.kol = k6/4;
                wat.salr = (wat.pric*(k6/4)*wat.sal)/100;
                wat.sum = wat.pric*(k6/4) - wat.salr;

            }
            if ((k6>4) && k6%4==0){
                wat.kol = k6/4;
                wat.salr = (wat.pric*(k6/4)*wat.sal)/100;
                wat.sum = wat.pric*(k6/4) - wat.salr;
                
            }
        }
    }
    printf ("Чек\n");
    if (k1>=4){
        printf ("Молоко Коровье счастье - ");
        printf ("цена за единицу товара = %d руб. - ", milk.pric);
        printf ("количество товара = %d - ", milk.kol);
        printf ("сумма = %2.f руб.\n", milk.sum);
        
    }
    if (k2>=4){
        printf ("Печенье Любятово - ");
        printf ("цена за единицу товара = %d руб. - ", cookie.pric);
        printf ("количество товара = %d - ", cookie.kol);
        printf ("Сумма = %2.f руб.\n", cookie.sum);
        
    }
    if (k3>=4){
        printf ("Хлеб Бородинский - ");
        printf ("цена за единицу товара = %d руб. - ", bread.pric);
        printf ("количество товара = %d- ", bread.kol);
        printf ("сумма = %2.f руб.\n", bread.sum);
        
    }
    if (k4>=4){
        printf ("Яйца куриные - ");
        printf ("цена за единицу товара = %d руб. - ", eggs.pric);
        printf ("количество товара = %d - ", eggs.kol);
        printf ("сумма = %2.f руб.\n", eggs.sum);
        
    }
    if (k5>=4){
        printf ("Шоколадные конфеты - ");
        printf ("цена за единицу товара = %d руб. - ", sweets.pric);
        printf ("количество товара = %d - ", sweets.kol);
        printf ("сумма = %2.f руб.\n", sweets.sum);
        
    }
    if (k6>=4){
        printf ("Вода негазированная - ");
        printf ("цена за единицу товара = %d руб. - ", wat.pric);
        printf ("количество товара = %d - ", wat.kol);
        printf ("сумма = %2.f руб.\n", wat.sum);
        
    }
    SC = milk.salr + cookie.salr + bread.salr + eggs.salr + sweets.salr + wat.salr;
    SUM = milk.sum + cookie.sum + bread.sum + eggs.sum + sweets.sum + wat.sum;
    printf ("Cуммарная скидка = %2.f руб.\n", SC);
    printf ("Общая сумма = %2.f руб.\n", SUM);
    return 0;
}

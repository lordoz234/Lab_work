#include <stdio.h>

int main()
{
    int x_1, y_1, x_2, y_2;
    printf("first position:\n");
    do
    {
        scanf_s("%d %d", &x_1, &y_1);
    } while (x_1 > 8 || y_1 > 8 || x_1 < 0 || y_1 < 0);

        printf("second position:\n");
        do
        {
            scanf_s("%d %d", &x_2, &y_2);
        } while (x_2 > 8 || y_2 > 8 || x_2 < 0 || y_2 < 0);

            if (x_1 == x_2 && y_1 == y_2) //����������� ����������
            {
                printf("Coordinates match !\n");
                return 1;
            };

            if ((x_1 - 1 == x_2 || x_1 + 1 == x_2 || x_1 == x_2) && (y_1 - 1 == y_2 || y_1 + 1 == y_2 || y_1 == y_2)) //������
                printf("The king can refuse at this point\n");
            else
                printf("The king cant refuse at this point\n");


            if ((x_1 == x_2 && y_1 != y_2) || (x_1 != x_2 && y_1 == y_2)) //�����
                printf("The rook can refuse at this point\n");
            else
                printf("The rook cant refuse at this point\n");


            if (abs(x_2 - x_1) == abs(y_2 - y_1)) //����
                printf("The elephant can refuse at this point\n");
            else
                printf("The elephant cant refuse at this point\n");


            if ((abs(x_2 - x_1) == abs(y_2 - y_1)) || (x_1 == x_2 && y_1 != y_2) || (x_1 != x_2 && y_1 == y_2)) //�����
                printf("The queen can refuse at this point\n");
            else
                printf("The queen cant refuse at this point\n");


            if ((abs(x_2 - x_1) == 1 && abs(y_2 - y_1) == 2) || (abs(y_2 - y_1) == 1 && abs(x_2 - x_1) == 2)) //����
                printf("The horse can refuse at this point\n");
            else
                printf("The horse cant refuse at this point\n");
            system("pause");
            return 0;
}
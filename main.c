#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <conio.h>
#include <string.h>


void bubble(int* array_sort, int size);
void qs(int* array_sort, int first, int last);

int main()
{
    int n, array_main[100],  i, j, k, choise, temp, maxN, minM;
    char c, str[20];
    setlocale(LC_ALL, "Rus");
    printf("Введите количество элементов массива (не более 100): ");
    do{  //Проверка ввода
        scanf("%s", &str);
        n = atof(str);
        if(n<2 || n>100) printf("Массив должен содержать от 2 до 100 элементов, попробуйте снова: ");
    }while(n<2 || n>100);

    printf("\n1. Заполнить массив вручную \n2. Заполнить массив случайными числами\n");
    do{  //Проверка ввода
        scanf("%s", &str);
        choise = atof(str);
        if(choise<1 || choise>2) printf("Некорректный выбор, попробуйте снова: ");
    }while(choise<1 || choise>2);

    printf("\n");
    switch(choise){
        case 1: //Ввод элементов пользователем
            for(i = 0; i<n; i++){
                printf("%d элемент массива: ", i+1);
                do{  //Проверка ввода
                    scanf("%s", &str);
                    array_main[i] = atof(str);
                    if(array_main[i]==0) printf("Неккоректное значение, попробуйте снова: ");
                }while(array_main[i]==0);
            }
            break;
        case 2: //Ввод случайных элементов
            srand(time(NULL));
            for(i = 0; i<n; i++){
                array_main[i] = -1000 + rand() % ((1000 + 1) + 1000);;
            }
            break;
    }


    printf("Ваш массив:\n");

    for(i = 0; i<n; i++){
        printf("%d ", array_main[i]);
    }

    choise = 0;

    printf("\n\n1. Сортировка методом пузырька \n2. Сортировка методом Хоара\n");
    do{  //Проверка ввода
        scanf("%s", &str);
        choise = atof(str);
        if(choise<1 || choise>2) printf("Некорректный выбор, попробуйте снова: ");
    }while(choise<1 || choise>2);
    switch(choise){
        case 1: //Сортировка методом пузырька
            bubble(array_main, n);
            break;
        case 2: //Сортировки методом Хоара
            qs(array_main, 0, n-1);
            break;
    }

    for (i = 0; i < n; i++) { //Удаление повторяющихся элементов массива
        for (j = i + 1; j < n;) {
            if (array_main[j] == array_main[i]){
                for (k = j; k < n; k++){
                    array_main[k] = array_main[k + 1];
                }
                n--;
            } else j++;
        }
    }

    printf("\nОтсортированный массив:\n");

    for(i = 0; i<n; i++){
        printf("%d ", array_main[i]);
    }

    printf("\n\nЗадайте N-ый максимум и M-ый минимум\n");
    do{
        printf("N: ");
        scanf("%s", &str);
        maxN = atof(str);
        if(maxN>n || maxN<1) printf("Заданный максимум невозможен, попробуйте снова\n");
    }while(maxN>n || maxN<1);
    do{
        printf("M: ");
        scanf("%s", &str);
        minM = atof(str);
        if(minM>n || minM<1) printf("Заданный минимум невозможен, попробуйте снова\n");
        }while(minM>n || minM<1);
    printf("\nВаш %d максимум: %d", maxN, array_main[n-maxN]);
    printf("\nВаш %d минимум: %d", minM, array_main[minM-1]);
    getch();

    return 0;
}

void bubble(int* array_sort, int size){ //Реализация сортировки методом пузырька
    int n = size, i, j, temp;

    for(i=n-1; i>=0; i--){
        for(j=0; j<i; j++){
            if(array_sort[j]>array_sort[j+1]){
                temp = array_sort[j];
                array_sort[j] =  array_sort[j+1];
                array_sort[j+1] = temp;
            }
        }
    }
}


void qs(int* array_sort, int first, int last){ //Реализация сортировки методом Хоара
   int i, j, x, temp;

   if(first<last){
      x=first;
      i=first;
      j=last;

      while(i<j){
         while(array_sort[i]<=array_sort[x]&&i<last)
            i++;
         while(array_sort[j]>array_sort[x])
            j--;
         if(i<j){
            temp=array_sort[i];
            array_sort[i]=array_sort[j];
            array_sort[j]=temp;
         }
      }

      temp=array_sort[x];
      array_sort[x]=array_sort[j];
      array_sort[j]=temp;
      qs(array_sort,first,j-1);
      qs(array_sort,j+1,last);
   }
}



#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX_ELEMENTS 8

int cmp(const void *a, const void *b) {
     return *(int*)a - *(int*)b;
 }

int main(int argc, char* argv[])
{
int n, i,j;
float m[MAX_ELEMENTS], result = 1; int iMax, iMin, MaxMod;

for (int i = 0; i < MAX_ELEMENTS; i++) // Заполнение массива
{ printf("m[%d] = ", i); scanf("%f", &m[i]);}

int score = 0, Cc=0, p=1; // p - произведение 

printf("Enter a value:");
scanf("%d", &Cc);

iMax=0;
iMin=0;

for (i = 0; i < MAX_ELEMENTS; i++)
{
if (m[i] > Cc) {score++;} 
}
printf("The number of digits that are greater than %d: %d\n", Cc, score);

for (i = 0; i < MAX_ELEMENTS; i++)
{
if (m[i] > m[iMax]) {iMax = i; iMin=0;} else //если нашли новый максимум, обнуляем минимум
if (m[i] < m[iMin]) {iMin = i; iMax=0;} //в другом случае наоборот
}


if (iMax == MAX_ELEMENTS-1) printf("Product = 0"); //если максимальное по модулю число - последнее в массиве, очевидно, после него ничего нет и произведение будет = 0
else
{
if (iMin==0)
{
p=1;
for (i=iMax;i<MAX_ELEMENTS;i++) //например максимальный под номером 6, всего элементов 8. для i=6; i<8;i++ цикл выполнится 2 раза, т. е. умножатся 7 и 8 элементы (не забываем, что заполняли мы массив с 0 до 7, т. е. m[6] это седьмой элемент)
p=p*m[i];
}
else for (i=iMin;i<MAX_ELEMENTS;i++)
p=p*m[i];
printf("Product of array elements = %d\n", p);
}
printf("Sort in ascending order:");
qsort(m, n, sizeof(int), cmp ); // СОРТИРУЕМ
    for(i = 0 ; i < n; i++) { // ВЫВОДИМ РЕЗУЛЬТАТ
        printf("%f ", m[i]);

  }
    return 0;
 }
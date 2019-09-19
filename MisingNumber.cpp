/* C++ implementation of QuickSort */
#include <bits/stdc++.h>
using namespace std;
// Una funci�n para cambiar dos elementos
void swap(int* a, int* b)
{
int t = *a;
*a = *b;
*b = t;
}
/* Esta funci�n toma el �ltimo elemento como pivote, lo coloca en su posici�n
correcta en el arreglo y posiciona todos los elementos menores a la izquierda y los
mayores a la derecha de el mismo*/
int partition (int arr[], int low, int high)
{
int pivot = arr[high]; // pivote
int i = (low - 1); // posici�n del primer elemento
for (int j = low; j <= high - 1; j++)
{
// Si el el elemento actual es menor que el pivote
if (arr[j] < pivot)
{
i++; // incrementar el index del menor elemento
swap(&arr[i], &arr[j]);
}
}
swap(&arr[i + 1], &arr[high]);
return (i + 1);
}
/* La funci�n principal que corre QuickSort
arr[] --> arreglo a ordenar,
low --> l�mite inicial,
high --> l�mite final */
void quickSort(int arr[], int low, int high)
{
if (low < high)
{
/*pi es la partici�n del �ndice, arr[p] est� en el lugar correcto */
int pi = partition(arr, low, high);
// Ordenando separadamente los elementos antes y despu�s de la
// partici�n
quickSort(arr, low, pi - 1);
quickSort(arr, pi + 1, high);
}
}
/* Funci�n para imprimir arreglo */
void printArray(int arr[], int size)
{
int i;
for (i = 0; i < size; i++)
cout << arr[i] << " ";
cout << endl;
}
// C�digo principal para utilizarlo
int main()
{
int arr[] = {10, 7, 8, 9, 1, 5};
int n = sizeof(arr) / sizeof(arr[0]);
quickSort(arr, 0, n - 1);
cout << "Sorted array: \n";
printArray(arr, n);
return 0;
}

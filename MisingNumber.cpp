#include <bits/stdc++.h>
using namespace std;
// Una función para cambiar dos elementos
void swap(int* a, int* b){
    int t = *a;
    *a = *b;
    *b = t;
}
/* Esta función toma el último elemento como pivote, lo coloca en su posición
correcta en el arreglo y posiciona todos los elementos menores a la izquierda y los
mayores a la derecha de el mismo*/
int partition (int arr[], int low, int high){
    int pivot = arr[high]; // pivote
    int i = (low - 1); // posición del primer elemento
    for (int j = low; j <= high - 1; j++){
    // Si el el elemento actual es menor que el pivote
        if (arr[j] < pivot){
            i++; // incrementar el index del menor elemento
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
/* La función principal que corre QuickSort
arr[] --> arreglo a ordenar,
low --> límite inicial,
high --> límite final */
void quickSort(int arr[], int low, int high){
    if (low < high){
        /*pi es la partición del índice, arr[p] está en el lugar correcto */
        int pi = partition(arr, low, high);
        // Ordenando separadamente los elementos antes y después de la
        // partición
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
/* Función para imprimir arreglo */
void printArray(int arr[], int size){
    int i;
    for (i = 0; i < size; i++)
    cout << arr[i] << " ";
    cout << endl;
}
/*Funcion para el mising number*/
void misingNumber(int a[], int n){
    int aux = a[n];
    //cout << aux;
    if(aux%2 == 0){
        aux = aux +2;
    }else {
        aux = aux +1;
    }
    cout << "mising number: "<< aux << endl;
}
int pedirArray(){
    int n;
    cout << "Ingrese la cantidad de datos ";
    cin >> n;
    int a[n];
    cout << "Ingrese los datos ";
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    //printArray(a,n);
    //int n = sizeof(arr) / sizeof(arr[0]);
    quickSort(a, 0, n - 1);
    cout << "Sorted array: \n";
    printArray(a, n);
    misingNumber(a,n-1);
    //return a;
}

// Código principal para utilizarlo
int main(){
    int cant, i=0;
    cout << "Ingrese la cantidad de arreglos ";
    cin >> cant;
    while(i<cant){
        pedirArray();
        i++;
        //cout << "----";
    }
    return 0;
}

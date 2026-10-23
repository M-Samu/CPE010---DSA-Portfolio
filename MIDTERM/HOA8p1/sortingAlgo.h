#ifndef SORTINGALGO_H
#define SORTINGALGO_H

template <typename T>
void displayAll(T arr[], int size){
    for (int i=0; i<size; i++){
        std::cout << arr[i] << " ";
    }
}

template <typename T>
void shellSort(T arr[], int size){
    for (int gap = size/2; gap>0; gap/=2){
        for (int i = gap; i<size; i++){
            T temp = arr[i];
            int j = i;
            while (j>=gap && arr[j-gap]>temp){
                arr[j] = arr[j-gap];
                j -= gap;
            }
            arr[j] = temp;
        }
    }
}

template <typename T>
void merge(T arr[], int left, int mid, int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;

    T* leftArr = new T[n1];
    T* rightArr = new T[n2];

    for (int i=0; i<n1; i++){
        leftArr[i] = arr[left + i];
    }
    for (int i=0; i<n2; i++){
        rightArr[i] = arr[mid + 1 + i];
    }

    int i=0, j=0, k=left;   

    while (i<n1 && j<n2){
        if (leftArr[i] <= rightArr[j]){
            arr[k] = leftArr[i];
            i++;
        }
        else{
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while (i<n1){
        arr[k] = leftArr[i];
        k++;
        i++;
    }

    while (j<n2){
        arr[k] = rightArr[j];
        k++;
        j++;
    }

    delete [] leftArr;
    delete [] rightArr;

}

template <typename T>
void mergeSort(T arr[], int left, int right){
    if (left<right){
        int mid = left + (right-left)/2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid+1, right);
        merge(arr, left, mid, right);
    }
}

template <typename T>
int partition(T arr[], int low, int high){
    T pivot = arr[high];
    int i = low - 1;

    for (int j=low; j<high; j++){
        if (arr[j] <= pivot){
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);   
    return i+1;
}

template <typename T>
void quickSort(T arr[], int low, int high){
    if (low<high){
        int pivotIndex = partition(arr, low, high);

        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

template <typename T>
void insertionSort(T arr[], int low, int high, int arrSize){
    int k = 1, j;
    T temp;

    while (k < arrSize){
        temp = arr[k];
        j = k - 1;
        while (j >= 0 && temp <= arr[j]){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
        k++;
    }
}

template <typename T>
void hybridQuickSort(T arr[], int low, int high, int arrSize){
    const int THRESHOLD = 10;

    if (low < high){
        if (high - low + 1 <= THRESHOLD){
            insertionSort(arr, low, high, arrSize);
        }
        else{
            int pivotIndex = partition(arr, low, high);

            hybridQuickSort(arr, low, pivotIndex - 1, arrSize);
            hybridQuickSort(arr, pivotIndex + 1, high, arrSize);    
        }
        }
    }

#endif 
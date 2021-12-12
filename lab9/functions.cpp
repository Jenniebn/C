// Define your FOUR functions here (no more, no less):
// First, the 3 functions for the selectionSort:
// swap_values, find_index_of_swap, sort
void sort(bool direction, int arr[], int size, int startIndex){
    if (startIndex == size){}
    else if (direction == true){
        // Descending Sort
        int biggest = find_index_of_swap(true, arr, size, startIndex);
        swap_values(arr[startIndex], arr[biggest]);
        sort(true, arr, size, startIndex + 1);
    }
    else if (direction == false){
        // Ascending Sort
        int smallest = find_index_of_swap(false, arr, size, startIndex);
        swap_values(arr[startIndex], arr[smallest]);
        sort(false, arr, size, startIndex + 1);
    }
}

void swap_values(int& v1, int& v2){
    int temp;
    temp = v1;
    v1 = v2;
    v2 = temp;
}

int find_index_of_swap(bool direction, int arr[], int size, int startIndex){
    if (direction == true){
        // Descending Sort
        int max = arr[startIndex];
        int indexOfMax = startIndex;
        for (int index = startIndex + 1; index < size; index ++){
            if (arr[index] > max){
                max = arr[index];
                indexOfMax = index;
            }
        }
        return indexOfMax;
    }
    else {
        // Ascending Sort
        int min = arr[startIndex];
        int indexOfMin = startIndex;
        for (int index = startIndex + 1; index < size; index ++){
            if (arr[index] < min){
                min = arr[index];
                indexOfMin = index;
            }
        }
        return indexOfMin;
    }
}
// Next, define the function getArray here. 
// This is the same one we used in Lab 4, so you can copy it over as is.
void getArray(ifstream& in, string fname, int arr[], int size){
    in.open(fname);
    if ( in.fail() ) 
    { 
        cerr << "Input file opening failed.\n"; 
        exit(1); 
    }
    for (int i = 0; i < size; i++)
    {
        in >> arr[i];
    }
}
#include <iostream>

using namespace std;

int findMissingInt(int array[], int size){
    int x = 0;
    for (int i = 0; i != size; ++i){
        x ^= array[i];
    }
    for (int i = 1; i != size + 2; ++i){
        x ^= i;
    }
    return x;
}

int main(){
    int array[8] = {1, 2, 4, 5, 6, 7, 8, 9};
    cout << findMissingInt(array, 8) << endl;
    return 0;
}
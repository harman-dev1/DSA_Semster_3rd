#include <iostream>
using namespace std;
#define SIZE 20

int hash_fn(int key) {
    return key % SIZE;
}

int probing(int A[], int key) {
    int i = 0;
    int index = hash_fn(key);
    while (A[(index + i) % SIZE] != 0) {
        i += 1;
    }
    return ((index + i) % SIZE);
}

void insert(int A[], int key) {
    int index = hash_fn(key);
    if (A[index] != 0) {
        index = probing(A, key);
    }
    A[index] = key;
}

int search(int A[], int key) {
    int index = hash_fn(key);
    int i = 0;
    while(A[(index+i) % SIZE] != key && A[(index+i) % SIZE] != 0) {
        i += 1;
    }
    if(A[(index+i) % SIZE] == 0) {
        return -1;
    }
    return (index+i) % SIZE;    
}

void print(int A[]) {
    for(int i = 0;i <20; i++) {
        //if(A[i] != 0) {
            cout << "index :" << i << ", " << A[i] << " ";
        //}
    }
    cout << endl;
}

main() {
    int A[20];
    for (int i = 0; i < 20; i++) {
        A[i] = 0;
    }
    insert(A, 29);
    insert(A, 19);
    insert(A, 29);
    insert(A, 39);
    insert(A, 119);
    insert(A, 129);
    insert(A, 49);

    cout << "Successfull Search" << endl;
    int key = 29;
    int value = search(A,key);
    cout << "key :" << key << ", Value :" << value << endl;

    cout << "UNsuccessfull Search" << endl;
    key = 3;
    value = search(A,key);
    cout << "key :" << key << ", Value :" << value << endl;

    print(A);
}
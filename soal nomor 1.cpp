#include <iostream>
#include <string>

using namespace std;

// Definisi struct untuk data Nama Alamat
struct Person {
    string nama;
    string alamat;
};

// Bubble Sort
void bubbleSort(Person arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].nama > arr[j + 1].nama) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        if (!swapped)
            break;
    }
}

// Selection Sort
void selectionSort(Person arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j].nama < arr[min_index].nama)
                min_index = j;
        }

        swap(arr[i], arr[min_index]);
    }
}

int main() {
    Person data[] = {
        {"Fahmi", "Jakarta"},
        {"Romi", "Solo"},
        {"Andri", "Jakarta"},
        {"Fadillah", "Banyuwangi"},
        {"Ruli", "Bandung"},
        {"Rudi", "Bali"},
        {"Dendi", "Purwokerto"},
        {"Zaki", "Madiun"}
    };

    int n = sizeof(data) / sizeof(data[0]);

    // Urutkan menggunakan Bubble Sort
    bubbleSort(data, n);

    cout << "Hasil Bubble Sort:" << endl;
    cout << "Nama\tAlamat" << endl;
    for (int i = 0; i < n; i++) {
        cout << data[i].nama << "\t" << data[i].alamat << endl;
    }

    cout << endl;

    // Kembalikan data awal
    data[0] = {"Fahmi", "Jakarta"};
    data[1] = {"Romi", "Solo"};
    data[2] = {"Andri", "Jakarta"};
    data[3] = {"Fadillah", "Banyuwangi"};
    data[4] = {"Ruli", "Bandung"};
    data[5] = {"Rudi", "Bali"};
    data[6] = {"Dendi", "Purwokerto"};
    data[7] = {"Zaki", "Madiun"};

    // Urutkan menggunakan Selection Sort
    selectionSort(data, n);

    cout << "Hasil Selection Sort:" << endl;
    cout << "Nama\tAlamat" << endl;
    for (int i = 0; i < n; i++) {
        cout << data[i].nama << "\t" << data[i].alamat << endl;
    }

    return 0;
}


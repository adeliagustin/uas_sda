#include <iostream>
#include <vector>

using namespace std;

// Fungsi untuk melakukan binary search pada array
vector<int> binarySearch(const vector<int>& arr, int target) {
    vector<int> indices;

    int low = 0;
    int high = arr.size() - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == target) {
            indices.push_back(mid);
            // Cari indeks lain dengan nilai yang sama di sebelah kiri
            int left = mid - 1;
            while (left >= 0 && arr[left] == target) {
                indices.push_back(left);
                left--;
            }
            // Cari indeks lain dengan nilai yang sama di sebelah kanan
            int right = mid + 1;
            while (right < arr.size() && arr[right] == target) {
                indices.push_back(right);
                right++;
            }
            return indices;
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return indices; // Jika tidak ditemukan, kembalikan vector kosong
}

int main() {
    vector<int> arr = {19, 40, 10, 90, 2, 50, 60, 50, 1};

    // Test case
    vector<int> test_cases = {1, 50, 100};

    for (int target : test_cases) {
        vector<int> indices = binarySearch(arr, target);
        if (!indices.empty()) {
            cout << "Angka " << target << " ada di indeks ke ";
            for (int i = 0; i < indices.size(); i++) {
                cout << indices[i];
                if (i < indices.size() - 1) {
                    cout << " dan ";
                }
            }
            cout << endl;
        } else {
            cout << "Angka " << target << " tidak ada dalam array." << endl;
        }
    }

    return 0;
}


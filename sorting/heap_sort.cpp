#include <iostream>
#include <vector>

using namespace std;

class HeapSort {
   public:
    void sort(vector<int>& arr) {
        for (int i = arr.size() / 2 - 1; i >= 0; i--) {
            heapify_(arr, i, arr.size());
        }
        for (int i = arr.size() - 1; i >= 0; i--) {
            int temp = arr[0];
            arr[0] = arr[i];
            arr[i] = temp;
            heapify_(arr, 0, i);
        }
    }

   private:
    void heapify_(vector<int>& arr, int index, int size) {
        int max = index;
        for (int i = 1; i <= 2; i++) {
            int child = index * 2 + i;
            if (child < size) {
                if (arr[max] < arr[child]) {
                    max = child;
                }
            }
        }
        if (max != index) {
            int temp = arr[max];
            arr[max] = arr[index];
            arr[index] = temp;
            heapify_(arr, max, size);
        }
    }
};

int main() {
    vector<int> input = {5, 3, 10, 7, 1, 6, 9, 4, 8, 2};

    cout << "Input array: " << endl;
    for (auto i : input) cout << i << ' ';
    cout << endl;

    HeapSort s;
    s.sort(input);
    cout << "Sorted array: " << endl;
    for (auto i : input) cout << i << ' ';
    cout << endl;

    return 0;
}
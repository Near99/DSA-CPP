#include <iostream>
#include <vector>

using namespace std;

class InsertionSort {
   public:
    void sort(vector<int>& arr) {
        for (int i = 1; i < arr.size(); i++) {
            int j = i;
            while (j > 0 && arr[j] < arr[j - 1]) {
                auto temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
                j--;
            }
        }
    }
};

int main() {
    vector<int> input = {5, 3, 10, 7, 1, 6, 9, 4, 8, 2};

    cout << "Input array: " << endl;
    for (auto i : input) cout << i << ' ';
    cout << endl;

    InsertionSort s;
    s.sort(input);
    cout << "Sorted array: " << endl;
    for (auto i : input) cout << i << ' ';
    cout << endl;

    return 0;
}
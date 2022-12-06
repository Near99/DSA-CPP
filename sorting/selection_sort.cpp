#include <iostream>
#include <vector>

using namespace std;

class SelectionSort {
   public:
    void sort(vector<int>& arr) {
        for (int i = 0; i < arr.size() - 1; i++) {
            int k = i;
            for (int j = k + 1; j < arr.size(); j++) {
                if (arr[j] < arr[k]) k = j;
            }
            int temp = arr[i];
            arr[i] = arr[k];
            arr[k] = temp;
        }
    }
};

int main() {
    vector<int> input = {5, 3, 10, 7, 1, 6, 9, 4, 8, 2};

    cout << "Input array: " << endl;
    for (auto i : input) cout << i << ' ';
    cout << endl;

    SelectionSort s;
    s.sort(input);
    cout << "Sorted array: " << endl;
    for (auto i : input) cout << i << ' ';
    cout << endl;

    return 0;
}

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class QuickSort {
   public:
    void sort(vector<int>& arr) { quick_sort_(arr, 0, arr.size() - 1); }

   private:
    void quick_sort_(vector<int>& arr, int low, int high) {
        if ((high - low) > 0) {
            int p = partition_(arr, low, high);
            quick_sort_(arr, low, p - 1);
            quick_sort_(arr, p + 1, high);
        }
    }

    int partition_(vector<int>& arr, int low, int high) {
        int p = high;
        int firsthigh = low;
        for (int i = low; i < high; i++) {
            if (arr[i] < arr[p]) {
                int temp = arr[i];
                arr[i] = arr[firsthigh];
                arr[firsthigh] = temp;
                firsthigh++;
            }
        }
        int temp = arr[p];
        arr[p] = arr[firsthigh];
        arr[firsthigh] = temp;
        return firsthigh;
    }
};

int main() {
    vector<int> input = {5, 3, 10, 7, 1, 6, 9, 4, 8, 2};

    cout << "Input array: " << endl;
    for (auto i : input) cout << i << ' ';
    cout << endl;

    QuickSort s;
    s.sort(input);
    cout << "Sorted array: " << endl;
    for (auto i : input) cout << i << ' ';
    cout << endl;

    return 0;
}
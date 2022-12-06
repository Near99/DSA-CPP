#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class MergeSort {
   public:
    void sort(vector<int>& arr) { merge_sort_(arr, 0, arr.size() - 1); }

   private:
    void merge_sort_(vector<int>& arr, int low, int high) {
        auto middle = (low + high) / 2;
        if (low >= high) return;
        merge_sort_(arr, low, middle);
        merge_sort_(arr, middle + 1, high);
        merge_(arr, low, middle, high);
    }
    void merge_(vector<int>& arr, int low, int middle, int high) {
        queue<int> buffer_one, buffer_two;
        for (int i = low; i <= middle; i++) buffer_one.push(arr[i]);
        for (int i = middle + 1; i <= high; i++) buffer_two.push(arr[i]);
        int i = low;
        while (!buffer_one.empty() && !buffer_two.empty()) {
            if (buffer_one.front() > buffer_two.front()) {
                arr[i++] = buffer_two.front();
                buffer_two.pop();
            } else {
                arr[i++] = buffer_one.front();
                buffer_one.pop();
            }
        }
        while (!buffer_one.empty()) {
            arr[i++] = buffer_one.front();
            buffer_one.pop();
        }
        while (!buffer_two.empty()) {
            arr[i++] = buffer_two.front();
            buffer_two.pop();
        }
    };
};

int main() {
    vector<int> input = {5, 3, 10, 7, 1, 6, 9, 4, 8, 2};

    cout << "Input array: " << endl;
    for (auto i : input) cout << i << ' ';
    cout << endl;

    MergeSort s;
    s.sort(input);
    cout << "Sorted array: " << endl;
    for (auto i : input) cout << i << ' ';
    cout << endl;

    return 0;
}
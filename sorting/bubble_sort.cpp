#include <iostream>
#include <vector>

using namespace std;

class BubbleSort {
   public:
    void sort(vector<int>& arr) {
        bool flag = false;
        int i = 0;
        while (!flag) {
            flag = true;
            for (int j = 0; j < arr.size() - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    flag = false;
                    auto temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
            i++;
        }
    }
};

int main() {
    vector<int> input = {5, 3, 10, 7, 1, 6, 9, 4, 8, 2};

    cout << "Input array: " << endl;
    for (auto i : input) cout << i << ' ';
    cout << endl;

    BubbleSort s;
    s.sort(input);
    cout << "Sorted array: " << endl;
    for (auto i : input) cout << i << ' ';
    cout << endl;

    return 0;
}
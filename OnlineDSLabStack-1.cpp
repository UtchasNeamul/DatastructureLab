#include <iostream>

using namespace std;

int main() {
    int arr[10];

    cout << "Enter 10 elements: ";
    for (int i = 0; i < 10; i++) {
        cin >> arr[i];
    }

    int minSum = abs(arr[0] + arr[1]); // Initialize with the absolute sum of the first two elements
    int num1 = arr[0];
    int num2 = arr[1];

    for (int i = 0; i < 9; i++) {
        for (int j = i + 1; j < 10; j++) {
            int sum = abs(arr[i] + arr[j]);
            if (sum < minSum) {
                minSum = sum;
                num1 = arr[i];
                num2 = arr[j];
            }
        }
    }

    cout << "The two elements that give the sum nearest to zero are: " << num1 << " and " << num2 << endl;

    return 0;
}

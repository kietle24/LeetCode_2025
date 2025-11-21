#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
using namespace std;
using namespace std::chrono;

// Recursive implementation of linear search
int recursiveLinearSearch(const vector<int>& arr, int target, int index = 0) {
    if (index >= arr.size()) {
        return -1;
    }
    if (arr[index] == target) {
        return index;
    }
    return recursiveLinearSearch(arr, target, index + 1);
}

// Recursive implementation of binary search
int recursiveBinarySearch(const vector<int>& arr, int target, int low, int high) {
    if (low > high) {
        return -1;
    }
    
    int mid = low + (high - low) / 2;
    
    if (arr[mid] == target) {
        return mid;
    } else if (arr[mid] > target) {
        return recursiveBinarySearch(arr, target, low, mid - 1);
    } else {
        return recursiveBinarySearch(arr, target, mid + 1, high);
    }
}

// Main function to compare linear and binary search
void CompareLinearBinarySearch(vector<int> arr, int n, int k) {
    // Create a sorted copy for binary search
    vector<int> sortedArr = arr;
    sort(sortedArr.begin(), sortedArr.end());
    
    // Measure linear search time
    auto start = high_resolution_clock::now();
    int linearResult = recursiveLinearSearch(arr, k);
    auto end = high_resolution_clock::now();
    auto linearTime = duration_cast<nanoseconds>(end - start);
    
    // Measure binary search time
    start = high_resolution_clock::now();
    int binaryResult = recursiveBinarySearch(sortedArr, k, 0, n - 1);
    end = high_resolution_clock::now();
    auto binaryTime = duration_cast<nanoseconds>(end - start);
    
    // Output results
    cout << linearResult << endl;
    cout << binaryResult << endl;
    
    // Compare times and output which is faster
    if (linearTime < binaryTime) {
        cout << "Linear faster than Binary" << endl;
    } else if (binaryTime < linearTime) {
        cout << "Binary faster than Linear" << endl;
    } else {
        cout << "Linear equal to Binary" << endl;
    }
}

// Test function for the provided example
void testExample() {
    cout << "Testing with provided example:" << endl;
    int n = 5;
    vector<int> A = {1, 3, 4, 6, 5};
    int k = 12;
    
    cout << "Array: ";
    for (int x : A) cout << x << " ";
    cout << endl;
    cout << "Searching for: " << k << endl;
    cout << "Number of elements: " << n << endl << endl;
    
    CompareLinearBinarySearch(A, n, k);
    cout << endl;
}

// Test function for the table example
void testTableExample() {
    cout << "Testing with table example:" << endl;
    int n = 10;
    vector<int> A = {1, 2, 4, 5, 8, 10, 12, 12, 13, 13};
    int k = 23;
    
    cout << "Array: ";
    for (int x : A) cout << x << " ";
    cout << endl;
    cout << "Searching for: " << k << endl;
    cout << "Number of elements: " << n << endl << endl;
    
    CompareLinearBinarySearch(A, n, k);
    cout << endl;
}

// Additional test cases
void additionalTests() {
    cout << "Additional test cases:" << endl;
    
    // Test case 1: Element found
    cout << "Test 1 - Element found:" << endl;
    vector<int> A1 = {1, 3, 5, 7, 9, 11, 13, 15};
    cout << "Array: ";
    for (int x : A1) cout << x << " ";
    cout << endl;
    cout << "Searching for: 7" << endl;
    CompareLinearBinarySearch(A1, A1.size(), 7);
    cout << endl;
    
    // Test case 2: Small array
    cout << "Test 2 - Small array:" << endl;
    vector<int> A2 = {1, 2, 3};
    cout << "Array: ";
    for (int x : A2) cout << x << " ";
    cout << endl;
    cout << "Searching for: 2" << endl;
    CompareLinearBinarySearch(A2, A2.size(), 2);
    cout << endl;
    
    // Test case 3: Large array to see performance difference
    cout << "Test 3 - Large array (performance test):" << endl;
    vector<int> A3;
    for (int i = 1; i <= 1000; i++) {
        A3.push_back(i);
    }
    cout << "Array: 1 to 1000 (1000 elements)" << endl;
    cout << "Searching for: 999" << endl;
    CompareLinearBinarySearch(A3, A3.size(), 999);
    cout << endl;
}

int main() {
    testExample();
    testTableExample();
    additionalTests();
    
    return 0;
}
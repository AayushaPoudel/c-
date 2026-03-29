#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k;
    
    cout << "Enter number of observations: ";
    cin >> n;

    vector<float> x(n);

    cout << "Enter the sequence:\n";
    for(int i = 0; i < n; i++) {
        cin >> x[i];
    }

    cout << "Enter lag (k): ";
    cin >> k;

    float numerator = 0, denominator = 0, mean = 0;

    // Calculate mean
    for(int i = 0; i < n; i++) {
        mean += x[i];
    }
    mean /= n;

    // Calculate numerator
    for(int i = 0; i < n - k; i++) {
        numerator += (x[i] - mean) * (x[i + k] - mean);
    }

    // Calculate denominator
    for(int i = 0; i < n; i++) {
        denominator += (x[i] - mean) * (x[i] - mean);
    }

    float r_k = numerator / denominator;

    cout << "Autocorrelation coefficient (r_" << k << ") = " << r_k << endl;

    return 0;
}
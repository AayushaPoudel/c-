#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    int n;
    cout << "Enter number of data points: ";
    cin >> n;

    vector<float> data(n);

    cout << "Enter data values (between 0 and 1):\n";
    for(int i = 0; i < n; i++) {
        cin >> data[i];
    }

    // Sort data
    sort(data.begin(), data.end());

    float D_plus = 0, D_minus = 0;

    for(int i = 0; i < n; i++) {
        float empirical = (i + 1) / (float)n;
        float theoretical = data[i];  // Uniform CDF = x

        D_plus = max(D_plus, empirical - theoretical);
        D_minus = max(D_minus, theoretical - (i / (float)n));
    }

    float D = max(D_plus, D_minus);

    cout << "D+ = " << D_plus << endl;
    cout << "D- = " << D_minus << endl;
    cout << "Kolmogorov-Smirnov Statistic D = " << D << endl;

    return 0;
}
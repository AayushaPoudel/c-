#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int n;
    cout << "Enter number of categories: ";
    cin >> n;

    vector<float> observed(n), expected(n);

    cout << "Enter observed frequencies:\n";
    for(int i = 0; i < n; i++) {
        cin >> observed[i];
    }

    cout << "Enter expected frequencies:\n";
    for(int i = 0; i < n; i++) {
        cin >> expected[i];
    }

    float chi_square = 0;

    for(int i = 0; i < n; i++) {
        if(expected[i] != 0) {
            chi_square += pow(observed[i] - expected[i], 2) / expected[i];
        }
    }

    cout << "Chi-Square value = " << chi_square << endl;

    return 0;
}
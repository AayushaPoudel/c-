#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int n;
    cout << "Enter number of random numbers: ";
    cin >> n;

    vector<float> r(n);

    cout << "Enter random numbers (0 to 1):\n";
    for(int i = 0; i < n; i++) {
        cin >> r[i];
    }

    int three_same = 0, one_pair = 0, all_diff = 0;

    for(int i = 0; i < n; i++) {
        int num = (int)(r[i] * 1000); // convert to 3-digit integer

        int d1 = num / 100;
        int d2 = (num / 10) % 10;
        int d3 = num % 10;

        if(d1 == d2 && d2 == d3)
            three_same++;
        else if(d1 == d2 || d2 == d3 || d1 == d3)
            one_pair++;
        else
            all_diff++;
    }

    // Expected probabilities for 3-digit groups
    float p_three = 0.01;   // 10/1000
    float p_pair  = 0.27;   // 270/1000
    float p_diff  = 0.72;   // 720/1000

    float E_three = n * p_three;
    float E_pair  = n * p_pair;
    float E_diff  = n * p_diff;

    // Chi-square calculation
    float chi_square = 0;
    chi_square += pow(three_same - E_three, 2) / E_three;
    chi_square += pow(one_pair - E_pair, 2) / E_pair;
    chi_square += pow(all_diff - E_diff, 2) / E_diff;

    cout << "\nObserved Frequencies:\n";
    cout << "Three same: " << three_same << endl;
    cout << "One pair: " << one_pair << endl;
    cout << "All different: " << all_diff << endl;

    cout << "\nExpected Frequencies:\n";
    cout << "Three same: " << E_three << endl;
    cout << "One pair: " << E_pair << endl;
    cout << "All different: " << E_diff << endl;

    cout << "\nChi-square value = " << chi_square << endl;

    return 0;
}
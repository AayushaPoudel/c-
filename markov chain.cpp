#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;

    cout << "Enter number of states: ";
    cin >> n;

    vector<vector<float>> transition(n, vector<float>(n));
    vector<float> state(n), nextState(n, 0);

    // Input transition matrix
    cout << "Enter transition probability matrix:\n";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> transition[i][j];
        }
    }

    // Input initial state
    cout << "Enter initial state probabilities:\n";
    for(int i = 0; i < n; i++) {
        cin >> state[i];
    }

    // Compute next state
    for(int j = 0; j < n; j++) {
        for(int i = 0; i < n; i++) {
            nextState[j] += state[i] * transition[i][j];
        }
    }

    // Output result
    cout << "Next state probabilities:\n";
    for(int i = 0; i < n; i++) {
        cout << nextState[i] << " ";
    }

    return 0;
}
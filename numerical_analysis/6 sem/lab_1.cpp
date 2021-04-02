#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

void print(vector< vector<double> > A) {
    int n = A.size();
    for (int i=0; i<n; i++) {
        for (int j=0; j<n+1; j++) {
            cout << A[i][j] << "\t";
            if (j == n-1) {
                cout << "| ";
            }
        }
        cout << "\n";
    }
    cout << endl;
}


void print_vector(vector<double> v) {
    for(auto it : v){
        cout << it << " ";
    }
    cout << endl;
}

void test(vector< vector<double> > A, vector<double> x){
    int n = A.size();
    vector<double> x_test(n);
    for(int i = 0; i < n; ++i){ 
        double sum = 0;
        for(int j = 0; j < n; ++j){
            sum += A[i][j]*x[j];
        }
        x_test[i] = sum;
    }
    print_vector(x_test);
}

vector<double> gauss(vector< vector<double> > A) {
    int n = A.size();
    // forward
    for (int i=0; i<n-1; i++) {
        // Search for maximum in this column
        double maxEl = abs(A[i][i]);
        int maxRow = i;
        for (int k=i+1; k<n; k++) {
            if (abs(A[k][i]) > maxEl) {
                maxEl = abs(A[k][i]);
                maxRow = k;
            }
        }
        cout << "Pivot index " << maxRow << endl;
        // Swap maximum row with current row (column by column)
        for (int k=i; k<n+1;k++) {
            double tmp = A[maxRow][k];
            A[maxRow][k] = A[i][k];
            A[i][k] = tmp;
        }

        // Make all rows below this one 0 in current column
        for (int k=i+1; k<n; k++) {
            double c = -A[k][i]/A[i][i];
            for (int j=i; j<n+1; j++) {
                if (i==j) {
                    A[k][j] = 0;
                } else {
                    A[k][j] += c * A[i][j];
                }
            }
        }
        print(A);
    }
    
    // backward
    vector<double> x(n);
    for (int i=n-1; i>=0; i--) {
        x[i] = A[i][n]/A[i][i];
        for (int k=i-1;k>=0; k--) {
            A[k][n] -= A[k][i] * x[i];            
        }
    }
    return x;
}

int main() {
    int n = 4;
    vector< vector<double> > A = {{-5, -6, 4, -2, 64}, 
                                {0, 3, -4, -6, -55}, 
                                {2, 4, -4, 2, -48}, 
                                {1, -8, 2, 8, 68}};


    print(A);
    // Calculate solution
    vector<double> x(n);
    x = gauss(A);

    // Print result
    cout << "Result:\n";
    print_vector(x);

    cout << "Test:\n";
    test(A, x);
    cout << endl;
}
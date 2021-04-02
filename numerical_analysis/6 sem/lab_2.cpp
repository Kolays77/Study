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

vector<double> solve(vector< vector<double> > A) { 
    int n = A.size();
    vector<double> xs(n, 0);
    vector<double> ps(n, 0);
    vector<double> qs(n, 0);
    ps[0] = -A[0][1] / A[0][0];
    qs[0] = A[0][n] / A[0][0];
    
    cout << "0s ps::" << ps[0] << "  qs " << qs[0] << endl;
    for(int i = 1; i < n - 1; ++i) {
        ps[i] = -A[i][i+1] / (A[i][i] + A[i][i-1]* ps[i-1]);
        qs[i] = (A[i][n] - A[i][i-1]*qs[i-1]) / (A[i][i] + A[i][i-1]*ps[i-1]);
        cout << i << "s ps::" << ps[i] << "  qs " << qs[i] << endl;
    }
    ps[n-1] = 0;
    qs[n-1] = (A[n-1][n] - A[n-1][n-2]*qs[n-2]) / (A[n-1][n-1] +  A[n-1][n-2]*ps[n-2] );
    cout << "4s ps::" << ps[n-1] << "  qs " << qs[n-1] << endl;

    xs[n-1] = qs[n-1];
    for(int i = n-2; i >= 0; i--) {
        xs[i] = ps[i]*xs[i+1] + qs[i];
    }
    cout << "Вектор решения x" << endl;
    
    print_vector(xs);
    cout << "Проверка решения. Умножим A*x" << endl;
    test(A, xs);

   
    return {};
}


int main() {
    vector< vector<double> > A = {{8, -2, 0, 0, 6}, 
                                {-1,6, -2, 0, 3}, 
                                {0, 2, -10, -4, 8},
                                {0, 0, -1, 6,  5}};
    vector<double> x = solve(A); 
}



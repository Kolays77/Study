#include <vector>
#include "headers/print_collections.h"
#include "/mnt/c/Users/nimak/Git/matplotlib-cpp/matplotlibcpp.h"
#include "headers/poly.h"

const double pi = 3.14159265359;
namespace plt = matplotlibcpp;

template <typename T>
Poly<T> CreateLagrangePoly(const std::vector<T>& xs, const std::vector<T>& ys) {
    const size_t deg = xs.size() - 1;
    Poly<T> poly, temp;
    T derivative = 1;
    for (size_t i = 0; i <= deg; ++i) {
        temp.Clear();
        temp[0] = ys[i];
        for (size_t j = 0; j <= deg; ++j) {
            if (i != j)
                temp *=  Poly<T>(std::vector<T>({-xs[j]/(xs[i] - xs[j]), 1.0/(xs[i] - xs[j])}));
        }
        poly += temp;
    }

    return poly;
}


double  lagrange(std::vector<double> fy, std::vector<double>  fx, double  x) {
    int dim = fx.size();
    double ch = 1, zn = 1,res1 = 0;
    int i = 0, j = 0;
    for (j = 0; j < dim; j++) {
        ch = 1, zn = 1;
        for (i = 0; i < dim; i++) {
            if (i != j) {
                ch *= (x - fx.at(i));
                zn *= (fx.at(j) - fx.at(i));
            }
        }
        ch = ch * fy.at(j);

        res1+=ch/zn;
    }

    return res1;
}


double LP(double x, std::vector<double> xv, std::vector<double> yv) { //Lagrange polynomial
	int size = xv.size(); //Количество точек (для удобства)
	double sum = 0; //Значение функции
	for(int i = 0; i < size; i++){
		double mul = 1; //Произведение
		for(int j = 0; j < size; j++){
			if(i!=j) mul *= (x - xv[j])/(xv[i]-xv[j]);
		}
		sum += yv[i]*mul;
	}
	return sum;
}




double newtone(double x, std::vector<double> arrX, std::vector<double> arrY){
    int dim = arrX.size();
    double res = arrY.at(0);
    double current = 1;
    std::vector<double> arrY0;

    for(int j=0;j<dim;j++){
        for(int i=0;i<dim-j-1;i++){
            arrY.at(i) = (arrY.at(i+1)-arrY.at(i))/(arrX.at(i+j+1)-arrX.at(i));
            if(i==0)
                arrY0.push_back(arrY.at(i));
        }
    }
    for (int i=0;i<dim-1;i++){
        current = current*(x-arrX.at(i));
        res+=arrY0.at(i)*current;
    }
    return res;
}
 
double func(double x) {
    return x * std::sin(x);
}


int Test_4() {
    std::cout << " X * X sin(X) " << std::endl;
    
    const double from = -5; 
    const double to = 5;
    const double dx = 0.1; 
    const size_t N = (to - from) / dx + 1;
    
    std::vector<double> points(N);
    points[0] = from;
    for (size_t i = 1; i < N; ++i) {   
        points[i] = points[i - 1] + dx;
    } 
    int n = 4;
    
    std::vector<double> approx_n_points = {0, pi/6, 2*pi/6, 3*pi/6};
    
   
    std::cout << "points " << approx_n_points << std::endl;
    std::vector<double> std_func_n_points(n); 
    for (size_t i = 0; i < n; ++i) {
        std_func_n_points[i] = func(approx_n_points[i]);
    }
    /*
    Poly<double> approx_poly = CreateLagrangePoly(approx_n_points, std_func_n_points);
    std::cout << " Approx poly : " << approx_poly << std::endl;
    std::cout << approx_poly.At(pi/4);
    */
    std::vector<double> my_func_y(N); 
    std::vector<double> std_func_y(N);
    
    for (size_t i = 0; i < N; ++i) {
        my_func_y[i] =  LP(points[i], approx_n_points, std_func_n_points);
        std_func_y[i] = func(points[i]);
    }
    //
    double point = pi/4;
    double res_newtone = newtone(point, approx_n_points,  std_func_n_points);
    double res_lag =  LP(point, approx_n_points, std_func_n_points);
    double res =  func(point);
    


    std::cout << " res_newtone "  << res_newtone << std::endl;
    std::cout << " res_lag " << res_lag << std::endl;
    std::cout << " res " << res << std::endl;
    
    plt::named_plot("my func", points, my_func_y);
    plt::named_plot("std::func ", points, std_func_y);
    plt::xlim(from, to); // Set x-axis to interval [0,1000000]
    plt::ylim(from, to); // Set x-axis to interval [0,1000000]
    plt::title("Test");
    plt::legend();
    plt::show();
    return 0;
}




int main() {
    Test_4();
    return 0;
}
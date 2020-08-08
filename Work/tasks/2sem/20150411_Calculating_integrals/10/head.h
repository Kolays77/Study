double function(double x);
double calculate_current_integral(double (*f)(double),
								  double a,
								  double b,
								  double eps);
double calculate_integral(double (*f)(double),
						double a,
						double *result,
						double eps);

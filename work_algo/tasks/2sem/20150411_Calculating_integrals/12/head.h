double coord1(double t);
double coord2(double t);
int calculate_length(double (*x)(double),
                        double (*y)(double),
						double a,
						double b,
						double eps,
						double *result);

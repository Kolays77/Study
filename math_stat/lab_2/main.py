import numpy as np
import params as prm
import cont_distributions as dstrb
import matplotlib.pyplot as plt

if __name__ == "__main__":
    uniform = dstrb.Uniform(prm.segment[0], prm.segment[1])
    normal = dstrb.Normal(prm.a, prm.sigma)
    exp = dstrb.Exponential(prm.lamb)

    xs_uniform = np.loadtxt("uniform_distribution.txt", dtype=float)
    xs_normal = np.loadtxt("normal_distribution.txt", dtype=float)
    xs_exp = np.loadtxt("exponential_distribution.txt", dtype=float)

    emp_1 = dstrb.Empirical(xs_uniform, "Uniform")
    emp_2 = dstrb.Empirical(xs_normal, "Normal")
    emp_3 = dstrb.Empirical(xs_exp, "Exponential")

    for emp in [(emp_1, uniform), (emp_2, normal), (emp_3, exp)]:
        print("type = ", emp[1].type, end='\n')
        emp[0].show()
        emp[0].plot_hist()
        emp[0].plot_edf()
        emp[0].print_interval_table()
        prop_error_table = dstrb.create_prop_error_table(emp[0], emp[1])
        print(prop_error_table, end='\n')
        emp[0].plot_hist()
        emp[0].plot_edf()
        interval_error_table = dstrb.create_interval_error_table(emp[0], emp[1])
        print(interval_error_table)
        print("---------------------")


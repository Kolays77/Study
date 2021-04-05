import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from matplotlib import collections as mc
import math


class Base:
    def __init__(self):
        self.type = 0
        self.mean = 0
        self.dispersion = 0
        self.std = 0
        self.mode = 0
        self.median = 0
        self.skewness = 0  # коэф асиметрии
        self.kurtosis = 0  # коэф эксцесса

    def __repr__(self):
        return self.type


    def show(self):
        print("Properties of ", self.type, end='\n')
        print("Выборочное среднее: ", round(self.mean, 5), end='\n')
        print("Выборочная дисперсия с поправкой Шепарда: ", round(self.dispersion, 5), end='\n')
        print("Выборочное среднее квадратичное отклонение: ", round(self.std, 5), end='\n')
        print("Выборочная мода: ", round(self.mode, 5), end='\n')
        print("Выборочная медиана: ", round(self.median, 5), end='\n')
        print("Выборочный коэффициент ассиметрии:", round(self.skewness, 5), end='\n')
        print("Выборочный коэффициент эксцесса: ", round(self.kurtosis, 5), end='\n\n')

    def get_list_props(self):
        return [round(self.mean,5),
                round(self.dispersion,5),
                round(self.std,5),
                round(self.mode,5),
                round(self.median,5),
                round(self.skewness,5),
                round(self.kurtosis,5)]

    def CDF(self, x):  # Cumulative distribution function
        return 0

    def count_prob_interval(self, interval: pd.Interval):
        return self.CDF(interval.right) - self.CDF(interval.left)


class Uniform(Base):
    def __init__(self, a, b):
        super().__init__()
        self.a = a
        self.b = b
        self.type = "Uniform"
        self.mean = (a + b) / 2
        self.dispersion = (b - a) ** 2 / 12
        self.std = (b - a) / 2 / np.sqrt(3)
        self.mode = self.mean
        self.median = self.mean
        self.skewness = 0
        self.kurtosis = -6 / 5

    def CDF(self, x):
        if x < self.a:
            return 0
        if x >= self.b:
            return 1
        return (x - self.a) / (self.b - self.a)


class Normal(Base):
    def __init__(self, a, sigma):
        super().__init__()
        self.type = "Normal"
        self.mean = a
        self.dispersion = sigma ** 2
        self.std = sigma
        self.mode = a
        self.median = a
        self.skewness = 0
        self.kurtosis = 0
        self.a = a
        self.sigma = sigma

    def CDF(self, x):
        return 0.5 * (1 + math.erf((x - self.a) / math.sqrt(2) / self.sigma))


class Exponential(Base):
    def __init__(self, lamb):
        super().__init__()
        self.type = "Exponential"
        self.mean = 1 / lamb
        self.dispersion = 1 / lamb / lamb
        self.std = self.mean
        self.mode = 0
        self.median = np.log(2) / lamb
        self.skewness = 2
        self.kurtosis = 6
        self.lamb = lamb

    def CDF(self, x):
        if x < 0:
            return 0
        else:
            return 1 - np.exp(-self.lamb * x)


def create_prop_error_table(empiric, theoretical):
    struct = {"Empirical": empiric.get_list_props(),
              "Theoretical": theoretical.get_list_props()}
    prop_error_table = pd.DataFrame(struct)
    prop_error_table.index = ["mean",
                              "dispersion",
                              "std",
                              "mode",
                              "median",
                              "skewness",
                              "kurtosis"]
    prop_error_table["Absolute_error"] = round(np.abs(prop_error_table["Empirical"] -
                                                prop_error_table["Theoretical"]), 5)
    prop_error_table["Relative_error"] = round(np.abs(prop_error_table["Absolute_error"] \
                                                / prop_error_table["Theoretical"]), 5)
    return prop_error_table


def create_interval_error_table(emp, theory):
    struct = {"Intervals":emp.__df["Intervals"], "Frequency":emp.__df["Frequency"]}
    table = pd.DataFrame(struct)
    probes = [round(theory.count_prob_interval(seg), 5) for seg in table["Intervals"]]
    table["theory_prob"] = probes
    table["error"] = np.abs(table["Frequency"] - table["theory_prob"])
    return table


class Empirical(Base):
    def __init__(self,
                 data,
                 type_="Unknown", *args):
        super().__init__()
        self.params = list(args)
        self.type = type_
        self.__size = len(data)
        self.count_intervals = int(1 + np.log2(self.__size))
        self.__count_intervals = count_intervals = int(1 + np.log2(self.__size))
        self.__data = np.sort(data)
        self.__create_bins()
        self.__df = self.__create_interval_df()  # main interval dataframe
        self.__add_midpoint()
        # counting:
        self.__count_mean()
        self.__count_dispersion()  # with Sheppard's correction
        self.__count_std()
        self.__count_mode()
        self.__count_median()
        self.__count_skewness()
        self.__count_kurtosis()
        # self.test()

    def get_df(self):
        return self.__df


    def plot_hist(self):
        fig, ax = plt.subplots()
        plt.hist(self.__data, self.__bins, density=True)
        ax.set_xticks(self.__bins)
        ax.autoscale()
        fig.savefig("hist_" + self.type + '.png')

    def plot_edf(self):
        fig, ax = plt.subplots(figsize=(10, 8))
        n = self.__size
        lines = [[(self.__data[i], (i + 1) / n), (self.__data[i + 1], (i + 1) / n)] for i in range(n - 1)]
        lc = mc.LineCollection(lines)
        ax.add_collection(lc)
        ax.autoscale()
        ax.set_yticks(np.arange(0, 1.1, 0.1))
        ax.set_xticks(np.arange(round(self.__data[0], 1), round(self.__data[-1], 1) + 0.2, 0.4))
        ax.tick_params(labelsize=8)
        # ax.margins(0.1)
        fig.savefig("edf_" + self.type + '.png')

    def __create_bins(self):
        lower = self.__data[0]
        upper = self.__data[-1]
        if self.type == "Exponential":
            lower = 0
        if self.type == "Uniform":
            lower = self.params[0]
            upper = self.params[1]

        d = upper - lower
        m = self.count_intervals
        h = d / m
        self.__bins = np.zeros(m + 1)
        self.__bins[0] = lower
        self.__bins[-1] = upper
        for i in range(1, len(self.__bins) - 1):
            self.__bins[i] = self.__bins[i - 1] + h

    def __add_midpoint(self):
        xs = [round((self.__bins[i] + self.__bins[i - 1]) / 2, 5)
              for i in range(1, len(self.__bins))]  # Midpoint of the segment
        self.__df["Midpoint"] = xs

    def __create_interval_df(self):
        s = pd.Series(self.__data)
        cut = pd.cut(s, bins=self.__bins, right=True, include_lowest=True, precision=5)
        res = s.groupby(cut).size()
        intervals = res.index.tolist()
        intervals[0] = pd.Interval(self.__bins[0], intervals[0].right, closed='both')
        df = pd.DataFrame({"Intervals": intervals, "Count": res.tolist()})
        df["Frequency"] = df["Count"] / self.__size
        return df

    def __count_centre_k_moment(self, k):
        return sum((self.__df.Midpoint - self.mean) ** k * self.__df.Frequency)

    def __count_k_moment(self, k):
        return sum((self.__df.Midpoint ** k) * self.__df.Frequency)

    def __count_mean(self):
        self.mean = self.__count_k_moment(1)

    def __count_dispersion(self, corr=True):
        self.dispersion = self.__count_centre_k_moment(2)
        if corr:
            self.dispersion -= 1 /12*(self.__data[-1] - self.__data[0]) / self.count_intervals

    def __count_std(self):
        self.std = np.sqrt(self.dispersion)

    def __count_median(self):
        h = (self.__bins[-1] - self.__bins[0]) / self.count_intervals
        s = self.__df["Frequency"][0]
        k = 0
        while s <= 1 / 2:
            k += 1
            s += self.__df["Frequency"][k]
        w_k = self.__df["Frequency"][k]
        left = self.__df["Intervals"][k].left
        right = self.__df["Intervals"][k].right
        if s == 1 / 2:
            self.median = right
        else:
            self.median = left + (h / w_k) * (0.5 - (s - w_k))

    def __count_mode(self):
        idx_max = self.__df["Count"].idxmax()
        max_freq = self.__df["Frequency"][idx_max]
        right_freq, left_freq = 0, 0
        if idx_max > 0:
            left_freq = self.__df["Frequency"][idx_max - 1]
        if idx_max + 1 < self.count_intervals:
            right_freq = self.__df["Frequency"][idx_max + 1]
        h = (self.__bins[-1] - self.__bins[0]) / self.count_intervals
        left_mode = self.__df["Intervals"][idx_max].left
        self.mode = left_mode + h * ((max_freq - left_freq) / (2 * max_freq - left_freq - right_freq))

    def __count_skewness(self):
        self.skewness = self.__count_centre_k_moment(3) / (self.std ** 3)

    def __count_kurtosis(self):
        self.kurtosis = self.__count_centre_k_moment(4) / (self.std ** 4) - 3

    def print_interval_table(self):
        print(self.__df, end='\n\n')

from scipy import stats

if __name__ == "__main__":

    alpha = float(input("Enter p (or alpha): "))
    n = int(input("Sample size: "))

    t_lower = stats.t.ppf(alpha/2, n - 1)
    t_upper = abs(t_lower)

    print("t_lower: ", t_lower)
    print("t_upper: ", t_upper)

    t_lower_onetail = stats.t.ppf(alpha, n - 1)
    t_upper_onetail = abs(t_lower_onetail)

    print(t_lower_onetail)
    print(t_upper_onetail)
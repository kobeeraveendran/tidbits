import math
from scipy import stats

if __name__ == "__main__":

    n1 = int(input("n1: "))
    x_1 = float(input("x_bar_1: "))
    std1 = float(input("Std dev 1: "))

    n2 = int(input("n2: "))
    x_2 = float(input("x_bar_2: "))
    std2 = float(input("Std dev 2: "))

    mu_diff = x_1 - x_2
    

    # rejection region
    alpha = float(input("alpha: "))

    if n1 >= 30 and n2 >= 30:

        std_err = math.sqrt((std1 ** 2 / n1) + (std2 ** 2 / n2))

        z = mu_diff / std_err

        print("z: ", z)

        # use z distribution
        p_val_onetail = abs(stats.norm.ppf(alpha))
        p_val_twotail = abs(stats.norm.ppf(alpha / 2))

        print("p one-tailed: ", p_val_onetail)
        print("p two-tailed: ", p_val_twotail)

    else:

        s_p2 = ((n1 - 1) * std1 ** 2 + (n2 - 1) * std2 ** 2) / (n1 + n2 - 2)

        std_err = math.sqrt(s_p2 * (1 / n1 + 1 / n2))
        
        # use t distribution
        p_val_onetail = abs(stats.t.ppf(alpha, n1 + n2 - 2))
        p_val_twotail = abs(stats.t.ppf(alpha / 2, n1 + n2 - 2))


    # confidence intervals
    print("{} +/- {} * {}".format(mu_diff, p_val_twotail, std_err))

    bounds = (mu_diff - p_val_twotail * std_err, mu_diff + p_val_twotail * std_err)

    print("Bounds: ", bounds)
import math
from scipy import stats
import numpy as np
import argparse


if __name__ == "__main__":

    parser = argparse.ArgumentParser()

    parser.add_argument("--prop", dest = "prop", action = "store_true")
    parser.set_defaults(prop = False)

    args = parser.parse_args()

    if not args.prop:

        x_bar = float(input("Sample mean (x bar): "))
        mu = float(input("Population mean (mu): "))
        std = float(input("Std dev: "))
        n = float(input("Sample size: "))

        z = (x_bar - mu) / (std / math.sqrt(n))

        print("z/t: ", z)

        print("p value (z): ", stats.norm.cdf(z))

        print("p value (t): ", stats.t.sf(np.abs(z), n - 1))

    else:
        p_hat = float(input("Sample proportion (p_hat): "))
        p = float(input("True/original proportion (p): "))
        q = 1 - p
        n = int(input("Sample size: "))

        z = (p_hat - p) / math.sqrt((p * q) / n)

        print("z: ", z)

        print("p value (z): ", stats.norm.cdf(z))
        print("p value (t): ", stats.t.sf(abs(z), n - 1))
from var_stddev import std_dev
import argparse
from scipy import stats

def inverse_zscore(z_score, mean, stddev):
    x = z_score * stddev + mean
    return x

parser = argparse.ArgumentParser()

parser.add_argument('--no_params', type = bool, default = False)
parser.add_argument('--inverse', dest = 'inverse', action = 'store_true')
parser.add_argument('--p_to_z', dest = 'p', action = "store_true")
parser.add_argument('--z_to_p', dest = 'z', action = "store_true")

parser.set_defaults(inverse = False, p = False, z = False)
args = parser.parse_args()



if args.inverse:
    mean = float(input('Enter mean: '))
    stddev = float(input('Enter standard deviation: '))
    z = float(input('Enter z-score value: '))
    print('X value for corresponding z score, mean, stddev: ', inverse_zscore(z, mean, stddev))

elif args.p:
    p = float(input("Enter p value: "))

    print("Corresponding z-score: ", stats.norm.ppf(p))

elif args.z:
    z = float(input("Enter z-score: "))

    print("Corresponding probability (p) value: ", stats.norm.cdf(z))

else:
    mean = float(input('Enter mean: '))
    stddev = float(input('Enter standard deviation: '))
    x = float(input('Enter value of x: '))

    z_score = (x - mean) / stddev
    print('Z score: {} standard deviations'.format(z_score))
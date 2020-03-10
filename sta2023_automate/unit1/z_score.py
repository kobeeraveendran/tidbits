from var_stddev import std_dev
import argparse

def inverse_zscore(z_score, mean, stddev):
    x = z_score * stddev + mean
    return x

parser = argparse.ArgumentParser()

parser.add_argument('--no_params', type = bool, default = False)
parser.add_argument('--inverse', dest = 'inverse', action = 'store_true')

parser.set_defaults(inverse = False)
args = parser.parse_args()

mean = float(input('Enter mean: '))
stddev = float(input('Enter standard deviation: '))

if not args.inverse:
    if not args.no_params:
        x = float(input('Enter value of x: '))

        z_score = (x - mean) / stddev
        print('Z score: {} standard deviations'.format(z_score))

else:
    z = float(input('Enter z-score value: '))
    print('X value for corresponding z score, mean, stddev: ', inverse_zscore(z, mean, stddev))

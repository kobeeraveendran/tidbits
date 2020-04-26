from math import sqrt

if __name__ == '__main__':
    n = int(input('Enter sample size (n): '))
    mu = float(input('Enter mean (mu): '))
    std = float(input('Enter standard deviation (sigma): '))

    print('Sample distribution:')
    print('Sample mean: ', mu)
    print('Standard error: ', std / sqrt(n))
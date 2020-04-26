import numpy as np

def ev(x, p_x):
    return sum([i * j for i, j in zip(x, p_x)])

def var(x, p_x, mu):
    return sum([(x_i - mu) ** 2 * p_x_i for x_i, p_x_i in zip(x, p_x)])

if __name__ == '__main__':
    x = input('Enter x values separated by spaces: ').split()
    x = [int(i) for i in x]

    p_x = input('Enter P(x) values separated by spaces: ').split()
    p_x = [float(i) for i in p_x]

    

    expected_value = ev(x, p_x)
    variance = var(x, p_x, expected_value)
    std_dev = np.sqrt(variance)

    print('Expected value (mu): ', expected_value)
    print('Variance (sigma): ', variance)
    print('Standard deviation: ', std_dev)
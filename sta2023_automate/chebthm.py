import argparse

def chebthm(k):
    

if __name__ == '__main__':
    parser = argparse.ArgumentParser()

    parser.add_argument('--k', type = int)

    args = parser.parse_args()

    print('Observations falling within {0} standard deviations of mean: {1}%\n'.format(args.k, ((1 - 1/(args.k ** 2)) * 100)))
# given a list of names and a number of bins (teams in this case), this will
# equally (or nearly equally) distribute them across the bins
import random
import argparse

if __name__ == '__main__':

    parser = argparse.ArgumentParser(description = 'Bucket Team Randomizer')
    parser.add_argument('--num_buckets', default = 2, type = int, 
                        help = 'The number of groups you want to sort the players into')
    
    args = parser.parse_args()

    # gather list of players
    player_list = 'Dreamtime, Phoenix, Saood, REY305, Reece, Radiador, meh???'.split(',')
    #player_list = input("Enter list of players separated by a comma (,): ").split(',')
    player_list = [x.strip() for x in player_list]
    
    # sanity check
    print(player_list)

    random.shuffle(player_list)

    print('Shuffled list: \n', player_list)

    # sort players into n bins
    n = args.num_buckets

    groups = {x: [] for x in range(n)}

    for i, player in enumerate(player_list):
        groups[i % n].append(player)

    # final teams
    for key, val in groups.items():
        print('\nTeam {}:\n'.format(key + 1))

        for player in groups[key]:
            print('   ', player)

        print('\n')
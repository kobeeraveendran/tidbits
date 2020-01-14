# given a list of names and a number of bins (teams in this case), this will
# equally (or nearly equally) distribute them across the bins
import random
import argparse

if __name__ == '__main__':

    parser = argparse.ArgumentParser(description = 'Bucket Team Randomizer')
    parser.add_argument('--num_buckets', default = 2, type = int, 
                        help = 'The number of groups you want to sort the players into')
    parser.add_argument('--delimiter', default = ',', type = str, 
                        help = "The character you'd like to use to separate player names, default is ,")
    
    
    args = parser.parse_args()

    # gather list of players
    #player_list = 'Dreamtime, Phoenix, Saood, REY305, Reece, Radiador, meh???'.split(',')
    #player_list = input("Enter list of players separated by a comma (,): ").split(',')
    #player_list = [x.strip() for x in player_list]

    # or, if list isn't available, enter line by line
    print('Enter players (one per line):')
    print('(press Enter again when done entering names)\n')

    curr_player = input()
    player_list = [curr_player]

    while True:
        curr_player = input()

        if curr_player == '':
            break

        player_list.append(curr_player)

    
    # sanity check
    #print(player_list)

    random.shuffle(player_list)

    #print('Shuffled list: \n', player_list)

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
# import the required libraries....
# for this project we need only "random" library only
import random

# create the set of cards...
# here, if you want to make a single list, it will also work fine(but you might need to change some funtions) 
# no. of element in suits = 4
# no. of element in ranks = 13
# total cards are 4*13 = 52
suits = ('Hearts','Diamond','spades','Clubs')
ranks = ('Two','Three','Four','Five','Six','Seven','Eight','Nine','Ten','Jack','Queen','King','Ace')
values = {'Two':2,'Three':3,'Four':4,'Five':5,'Six':6,'Seven':7,'Eight':8,'Nine':9,'Ten':10,'Jack':11,'Queen':12,'King':13,'Ace':14}

# now generate the cards
# you can view the card by printing them
class Card:

    def __init__(self,suit,rank):

        self.suit = suit
        self.rank = rank
        self.value = values[rank]

    def __str__(self):
        return self.rank + 'of' + self.suit

# now this class make decks for the players and it has member functions like shuffle and deal_one
# to increase its functionality
class Deck:
    
    def __init__(self):
        self.all_cards = []
        for suit in suits:
            for rank in ranks:
                self.all_cards.append(Card(suit,rank))

    def shuffle(self):

        random.shuffle(self.all_cards)

    def deal_one(self):
        
        return self.all_cards.pop()

# this class makes the players and assign them functions that they can perform
class Player:

    def __init__(self,name):
        self.name = name
        self.all_cards = []

    def remove_one(self):
        return self.all_cards.pop(0)

    def add_cards(self,new_cards):
        if type(new_cards)==type([]):
            self.all_cards.extend(new_cards)
        else:
            self.all_cards.append(new_cards)

    def __str__(self):
        return f'Player {self.name} has {[len(self.all_cards)]} cards.'

# making two players 
player_one = Player('One')
player_two = Player('Two')

# genterating decks and suffling the cards in it
new_deck = Deck()
new_deck.shuffle()

# assigning the cards to the players
for i in range(26):
    player_one.add_cards(new_deck.deal_one())
    player_two.add_cards(new_deck.deal_one())

# this acts as the switch for the game to tune on and off
game_on = True

# main logic of the game
round_num = 0
while game_on:

    round_num +=1
    print(f'Round {round_num}')

    if len(player_one.all_cards) == 0:
        print('Player One out of cards! Game over')
        print('Player Two Wins!')
        game_on = False
        break

    if len(player_two.all_cards) == 0:
        print('Player Two out of cards! Game Over')
        print('Player One Wins!')
        game_on = False
        break


    player_one_cards = []
    player_one_cards.append(player_one.remove_one())

    player_two_cards = []
    player_two_cards.append(player_two.remove_one())

    at_war = True

    while at_war:

        if player_one_cards[-1].value > player_two_cards[-1].value:

            player_one.add_cards(player_one_cards)
            player_one.add_cards(player_two_cards)

            at_war = False

        elif player_one_cards[-1].value < player_two_cards[-1].value:

            player_two.add_cards(player_two_cards)
            player_two.add_cards(player_one_cards)

            at_war = False

        else:
            
            print('WAR!')

            if len(player_one.all_cards)<5:
                
                print('Player One unable to play war! Game Over at War')
                print('PLayer Two Wins! Player One Loses!')
                game_on = False

            elif len(player_two.all_cards)<5:
                
                print('Player Two unable to play war! Over at War')
                print('Player One Wins! Player Two Loses')
                game_on = False
                break

            else:
                for num in range(5):
                    player_one_cards.append(player_one.remove_one())
                    player_two_cards.append(player_two.remove_one())


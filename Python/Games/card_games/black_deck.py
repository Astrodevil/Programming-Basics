# to stimulate this game you just have to download or paste the code in any your IDE or editor
# which is compatible with running python codes.


import random

suits = ('Hearts', 'Diamonds', 'Spades', 'Clubs')
ranks = ('Two', 'Three', 'Four', 'Five', 'Six', 'Seven', 'Eight', 'Nine', 'Ten', 'Jack', 'Queen', 'King', 'Ace')
values = {'Two':2, 'Three':3, 'Four':4, 'Five':5, 'Six':6, 'Seven':7, 'Eight':8, 'Nine':9, 'Ten':10, 'Jack':10, 'Queen':10, 'King':10, 'Ace':11}

playing = True

class Card:
    
    def __init__(self,suit,rank):
        self.suit = suit
        self.rank = rank
        self.value = values[rank]
    
    def __str__(self):
        return self.rank+' of '+self.suit

# two_hearts = Card('Hearts','Two')
# print(two_hearts)

class Deck:
    
    def __init__(self):
        self.deck = []  # start with an empty list
        for suit in suits:
            for rank in ranks:
                self.deck.append(Card(suit,rank))
    
    def __str__(self):
        return f'{self.deck[7]}'

    def shuffle(self):
        random.shuffle(self.deck)
        
    def deal(self):
        return self.deck.pop(0)
        
class Hand:
    def __init__(self):
        self.cards = []  # start with an empty list as we did in the Deck class
        self.value = 0   # start with zero value
        self.aces = 0    # add an attribute to keep track of aces
    
    def add_card(self,card):
        self.cards.append(card)
        self.value += values[card.rank]
        if 'Ace' in card.rank:
            self.aces +=1

    def adjust_for_ace(self):
        if self.aces > 0:
            while True:
                if self.value > 21:
                    self.value -= 10
                    self.aces -=1
                    continue
                else:
                    break
                
class Chips:
    
    def __init__(self):
        self.total = 100  # This can be set to a default value or supplied by a user input
        self.bet = 0
        
    def win_bet(self):
        self.total += self.bet
    
    def lose_bet(self):
        self.total -= self.bet

def take_bet(chips):
    while True:
        try:
            chips.bet = int(input('enter the amount to bet :'))
        except ValueError:
            print('oops ! enter a integer !')
        else:
            if chips.bet>chips.total:
                print("bent can't be placed")
                continue
            else:
                break

def hit(deck,hand):
    
    hand.add_card(deck.deal())
    hand.adjust_for_ace()

def hit_or_stand(deck,hand):
    global playing  # to control an upcoming while loop
    
    while True:
        Hit = input('do you want to hit or stand : "h" or "s" : ')
        if Hit[0].lower() == 'h':
            hit(deck,hand)
        elif Hit[0].lower() == 's':
            print('player is standing! dealer is playing.')
        else:
            print('Sorry ! please try again . ')
            continue
        break

def show_some(player,dealer):
    
    print('dealer"s hand :')
    print('< card hidden >')
    print('',dealer.cards[1])
    print('\nplayer"s hand :',*player.cards,sep = '\n')
    
def show_all(player,dealer):
    
    print('dealer"s hand  :',*dealer.cards,sep = '\n')
    print('dealer"s value :',*dealer.value)
    print('player"s hand  :',*player.cards,sep = '\n')
    print('player"s value :',*player.value)

def player_busts(player,dealer,chips):
    print('player busted! dealer wins ')
    chips.lose_bet()

def player_wins(player,dealer,chips):
    print('player wins !')
    chips.win_bet()
   
def dealer_busts(player,dealer,chips):
    print('dealer busted ! palyer wins')
    chips.win_bet()
    
def dealer_wins(player,dealer,chips):
    print('dealer wins !')
    chips.lose_bet()
    
def push():
    print('dealer and player ties up! it"s a push')

while True:
    # Print an opening statement
    print('this a black jet stimulation ! \n reach as close as you can to 21 without going over !')
    print(' ace can have value 1 or 11 ! \ndealer will stop at 17 !')
    # Create & shuffle the deck, deal two cards to each player
    deck = Deck()
    deck.shuffle()
    
    player_hand = Hand()
    player_hand.add_card(deck.deal())
    player_hand.adjust_for_ace()
    player_hand.add_card(deck.deal())
    player_hand.adjust_for_ace()
    
    dealer_hand = Hand()
    dealer_hand.add_card(deck.deal())
    dealer_hand.adjust_for_ace()
    dealer_hand.add_card(deck.deal())
    dealer_hand.adjust_for_ace()
        
    # Set up the Player's chips
    player_chips = Chips()
    
    # Prompt the Player for their bet
    take_bet(player_chips)
    
    # Show cards (but keep one dealer card hidden)
    show_some(player_hand,dealer_hand)
    
    while playing:  # recall this variable from our hit_or_stand function
        
        # Prompt for Player to Hit or Stand
        hit_or_stand(deck,player_hand)
        
        # Show cards (but keep one dealer card hidden)
        show_some(player_hand,dealer_hand)
        
        # If player's hand exceeds 21, run player_busts() and break out of loop
        if player_hand.value > 21 :
            player_busts(player_hand,dealer_hand,player_chips)
            
            break

    # If Player hasn't busted, play Dealer's hand until Dealer reaches 17
    if player_hand.value <= 21 :
        if dealer_hand.value < 17 :
            hit_or_stand(deck,dealer_hand)
        
        # Show all cards
        show_all(player_hand,dealer_hand)
        # Run different winning scenarios
        if dealer_hand.value > 21 :
            dealer_busts(player_hand,dealer_hand,player_chips)
        
        elif player_hand.value < dealer_hand : 
            dealer_wins(player_hand,dealer_hand,player_chips)
        
        elif player_hand.value > dealer_hand :
            player_wins(player_hand,dealer_hand,player_chips)
            
        else :
            push()
            
    # Inform Player of their chips total 
    print('the total chips that player have : ',player_chips.total)
    # Ask to play again
    choice = input('would you like to play again : "y" for yes or "n" for no')
    if choice == 'y' :
        continue
    else :
        break
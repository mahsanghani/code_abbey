from enum import Enum
from random import randint


class Suit(Enum):
    Hearts = "Hearts"
    Spades = "Spades"
    Clubs = "Clubs"
    Diamonds = "Diamonds"


class Card():
    def __init__(self, suit, value):
        self.suit = suit
        self.value = value

    def __str__(self):
        num_val = self.value
        if num_val == 11:
            num_val = "Jack"
        if num_val == 12:
            num_val = "Queen"
        if num_val == 13:
            num_val = "King"
        return str(num_val) + " of " + str(self.suit).split('.')[1]


class Deck():
    cards = None

    def __init__(self):
        self.cards = []
        for i in range(0, 13):
            self.cards.append(Card(Suit.Hearts, i + 1))
            self.cards.append(Card(Suit.Spades, i + 1))
            self.cards.append(Card(Suit.Diamonds, i + 1))
            self.cards.append(Card(Suit.Clubs, i + 1))

    def __str__(self):
        ret_val = ""
        for card in self.cards:
            ret_val += str(card) + "\n"
        return ret_val

    # back of array is treated as top
    def draw(self):
        return self.cards.pop()

    def draw_random(self):
        rand_draw = randint(0, len(self.cards) - 1)
        card = self.cards[rand_draw]
        del self.cards[rand_draw]
        return card

    # back of array is treated as top
    def add_to_top(self, card):
        self.cards.append()

    # bottom of deck is start of array
    def add_to_bottom(self, card):
        self.cards.insert(0, card)

    def shuffle(self):
        new_indices = []
        ceil = len(self.cards) - 1
        for i in range(0, len(self.cards)):
            swap_index = randint(0, randint(0, ceil))
            swap_card = self.cards[swap_index]
            self.cards[swap_index] = self.cards[i]
            self.cards[i] = swap_card


class Hand():
    cards = None

    def __init__(self):
        self.cards = []

    def __str__(self):
        ret_val = ""
        for card in self.cards:
            ret_val += str(card) + "\n"
        return ret_val

    def add_to_hand(self, card):
        self.cards.append(card)

    def remove_from_hand(self, index):
        card = self.cards[index]
        del self.cards[index]
        return card


deck = Deck()

print
deck
deck.shuffle()
print
deck

hand = Hand()
hand.add_to_hand(deck.draw())

print
hand

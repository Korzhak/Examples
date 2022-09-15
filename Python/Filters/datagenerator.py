import random


def float_generator(low, high):
    return random.randint(int((low + 2) * 100), int((high - 2) * 100)) / 100


def int_generator(low, high):
    return random.randint(low, high)

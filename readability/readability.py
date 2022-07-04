from cs50 import get_string
import math


def main():
    text = get_string("Text: ")
    L = letters(text) / words(text) * 100
    S = sentences(text) / words(text) * 100
    grade(L, S)


def letters(txt):
    letter_count = 0
    for char in txt:
        if (ord(char.lower()) >= 97 and ord(char.lower()) <= 122):
            letter_count += 1
    return letter_count


def words(txt):
    word_list = txt.split()
    return len(word_list)


def sentences(txt):
    sentence_count = 0
    sentence_end = {'.', '?', '!'}
    for char in txt:
        if char in sentence_end:
            sentence_count += 1
    return sentence_count


def grade(L, S):
    index = round((0.0588 * L) - (0.296 * S) - 15.8)
    if index < 1:
        print("Before Grade 1")
    elif index >= 16:
        print("Grade 16+")
    else:
        final = math.trunc(index)
        print(f"Grade {final}")


main()
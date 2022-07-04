from cs50 import get_string


def main():
    while True:
        card_num = get_string("Number: ")
        if card_num.isnumeric():
            check_card(card_num)
            break

def LuhnAlg(num):
    every_two = num[len(num)-2:None:-2]
    to_add = num[len(num)-1:None:-2]
    total=0
    sum_to_add=0
    final=0
    for x in str(every_two):
         x = int(x)*2
         if x > 9:
            sum = 0
            for i in str(x):
                sum  += int(i)
            total+=sum
         else:
            total+=x
   ## print(total)
    for x in to_add:
        x = int(x)
        sum_to_add+=x
    final = total + sum_to_add
    return final

def check_card(card_num):
    num = str(LuhnAlg(card_num))
    num = str(num)
    if (len(card_num)!=13 and len(card_num)!=15 and len(card_num)!=16) or num[-1] != '0':
        print("INVALID")
    else:
        if (len(card_num) == 13 or len(card_num) == 16) and card_num[0] == '4':
            print("VISA")
        elif (len(card_num) == 16 and (card_num[:2] == '51' or card_num[:2] == '52' or card_num[:2] == '53' or card_num[:2] == '54' or card_num[:2] == '55')):
            print("MASTERCARD")
        elif (len(card_num) == 15 and (card_num[:2] == '34' or card_num[:2] == '37')):
            print("AMEX")



main()

import random
answer = random.randint(1,100)
count = 0
guess = 0
while guess != answer :
    guess = input("PLease enter a number between 1 and 100: ")

    count = count + 1
    guess = int(guess)
    if guess > answer :
        print("Too high.")
    elif guess < answer :
        print("Too low.")
    elif guess < 1 or guess > 100:
        print("Wrong range.")





print("You got it! My number is " + str(answer) + ".")
print("It took you", count, "guesses to get the number!")

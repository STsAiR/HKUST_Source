import random
import turtle





answer = random.randint(1,100)
count = 0
guess = 0
xposition = -300
yposition = 110
turtle.up()
turtle.goto(xposition , yposition)

while guess != answer :

    turtle.up()
    turtle.goto(xposition , yposition)
    turtle.down()
    guess = turtle.textinput("Guessing Game", "PLease enter a number between 1 and 100: ")
    count = count + 1
    guess = int(guess)
    if guess > answer and guess <= 100:
        turtle.write("Too high.",font=("Arial", 40, "bold"))
    elif guess < answer and guess > 0 :
        turtle.write("Too low.",font=("Arial", 40, "bold"))
    elif answer == guess:
        break
    else:
        turtle.write("Wrong range.",font=("Arial", 40, "bold"))
    
    yposition = yposition - 40



turtle.write("You got it! My number is " + str(answer) + ".",font=("Arial", 20, "bold"))
yposition = yposition - 20
turtle.up()
turtle.goto(xposition , yposition)
turtle.down()
turtle.write("It took you " + str(count) + " guesses to get the number!",font=("Arial", 20, "bold"))


turtle.done()

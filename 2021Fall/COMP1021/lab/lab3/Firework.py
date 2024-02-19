import turtle
import random
firework_colours = ["red", "orange", "yellow", "green", "cyan", "blue", "violet"]
turtle.speed(0)
colour = firework_colours[random.randint(0,len(firework_colours)-1)]
turtle.up()
turtle.color(colour)
turtle.forward(10)
turtle.left(90)
turtle.hideturtle()
for j in range(7):
    turtle.forward(10)
    turtle.left(90)
    for i in range(12):
        turtle.circle(10*(j+1), 360/12)
        turtle.dot(3)
    turtle.right(90)
    

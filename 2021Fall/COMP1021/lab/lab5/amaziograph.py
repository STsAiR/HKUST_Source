# COMP1021 Lab 5 Amaziograph
# Name: Koo Kin Nam
# Student ID: 20849751
# Email: knkoo@connect.ust.hk
import turtle

turtle.setup(800,600)    # Set the width and height be 800 x 600

number_of_divisions = 8  # The number of subdivisions around the centre
turtle_width = 3         # The width of the turtles

# Don't show the animation
turtle.tracer(False)

# Draw the background lines

backgroundLineTurtle = turtle.Turtle()

backgroundLineTurtle.width(1)

backgroundLineTurtle.down()
backgroundLineTurtle.color("gray84") # Draw the centered line
for i in range(number_of_divisions):
    backgroundLineTurtle.forward(500)
    backgroundLineTurtle.backward(500)
    backgroundLineTurtle.left(360 / number_of_divisions)

backgroundLineTurtle.up()

# Show the instructions
backgroundLineTurtle.color("purple")
backgroundLineTurtle.goto(-turtle.window_width()/2+50, 100)
backgroundLineTurtle.write("""s - change a colour for one of the colour buttons
m - all 8 drawing turtles go to middle
c - clear all drawings made by the 8 drawing turtles
""", font=("Arial", 14, "normal"))

backgroundLineTurtle.hideturtle()

# Set up a turtle for handling message on the turtle screen
textTurtle = turtle.Turtle()
# This sets the colour of the text to red
textTurtle.color("red")
# We do not want it to show/draw anything, except the message text
textTurtle.up() 
# Set it the be at center, near the colour selections
textTurtle.goto(0, -200)
# We do not want to show it on the screen
textTurtle.hideturtle()

# Part 2 Preparing the drawing turtles

# The drawing turtles are put in a list
allDrawingTurtles = [] 

# Part 2.1 Add the 8 turtles in the list
# Please finish this part
for _ in range(number_of_divisions):
    drawingturtle = turtle.Turtle()
    drawingturtle.width(turtle_width)
    drawingturtle.speed(0)
    drawingturtle.hideturtle()
    allDrawingTurtles.append(drawingturtle)
    
# Part 2.2 Set up the first turtle for drawing
# Please finish this part
dragTurtle = allDrawingTurtles[0]
dragTurtle.shape("circle")
dragTurtle.shapesize(2,2)
dragTurtle.showturtle()

# Part 3 Preparing the basic drawing system
# Set up the ondrag event
# Please finish this part
def draw(x,y):
    dragTurtle.ondrag(None)
    turtle.tracer(False)
    textTurtle.clear()
    dragTurtle.goto(x,y)
    x_transform = [1, 1, -1, -1, 1, 1, -1, -1] # This represents + + - - + + - -
    y_transform = [1, -1, 1, -1, 1, -1, 1, -1] # This represents + - + - + - + -
    for i in range(1, number_of_divisions):
        if i < 4:
            new_x = x * x_transform[i] # x with sign change
            new_y = y * y_transform[i] # y with sign change
                
        else:
            new_x = y * y_transform[i] # Note that we assign y as new x
            new_y = x * x_transform[i] # Note that we assign x as new y
        allDrawingTurtles[i].goto(new_x, new_y)
    turtle.tracer(True)
    dragTurtle.ondrag(draw)
dragTurtle.ondrag(draw)

# Part 5.2 clear all drawings made by the 8 drawing turtles
def clearDrawing():
    # Please finish this part
    turtle.tracer(False)
    textTurtle.clear() # clear the previous message
    for i in range(len(allDrawingTurtles)):
        allDrawingTurtles[i].clear()
    textTurtle.write("The screen is cleared", \
                       align="center", font=("Arial",14))
    turtle.tracer(True)
        
turtle.onkeypress(clearDrawing,"c")


# Part 5.3 all 8 drawing turtles go to middle
def goToMiddle():
    # Please finish this part
    turtle.tracer(False)
    textTurtle.clear() # clear the previous message
    for i in range(len(allDrawingTurtles)):
        allDrawingTurtles[i].up()
        allDrawingTurtles[i].goto(0,0)
        allDrawingTurtles[i].down()
    textTurtle.write("All 8 turtles returned to middle", \
                       align="center", font=("Arial",14))
    turtle.tracer(True)

turtle.onkeypress(goToMiddle,"m")


# Part 4 handling the colour selection
# Make the colour selection turtles
# Here is the list of colours
colours = ["black", "orange red", "lawn green", "medium purple", "light sky blue", "orchid", "gold"]

# Part 4.2 Set up the onclick event
# Please finish this part
def handleColourChange(x, y):
    for i in range(len(colours)):
        if x <= (-130 + 50 * i):
            for j in range(len(allDrawingTurtles)):
                allDrawingTurtles[j].color(colours[i])
            break


# Part 5.4 change a colour in the colour selection
def changeColour():
    # Please finish this part
    textTurtle.clear() # clear the previous message
    index = turtle.textinput("Change color", \
                             "Please type the index number for the turtle: (0-6)")
    if index:
        index = int(index)
        while index <0 or index > len(colours)-1:
            index = turtle.textinput("Change color", \
                             "Please type the index number for the turtle: (0-6)")
            index = int(index)
        new_color = turtle.textinput("Change color", \
                                     "Please type the color you want to use e.g. LittleBlue2:")
        if new_color:
            turtle.tracer(False)
            colours[index] = new_color
            colourSelectionTurtles[index].color(colours[index])
            textTurtle.write("The colour for that button has been changed, click on the button to use it", \
                               align="center", font=("Arial",14))
    turtle.tracer(True)
    turtle.listen()
turtle.onkeypress(changeColour,"s")


# Part 4.1 Make the colour selection turtles
colourSelectionTurtles = []
# Please finish this part
for i in range(len(colours)):
    t = turtle.Turtle()
    t.shape("square")
    t.shapesize(2,2)
    t.color(colours[i])
    t.up()
    t.goto(-150+50*i,-250)
    t.color(colours[i])
    t.onclick(handleColourChange)
    colourSelectionTurtles.append(t)

turtle.tracer(True)
turtle.listen()

turtle.done()


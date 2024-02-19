# fireworks
import playsound
import random   # module providing the randint function
import time     # time module to delay after drawing five fireworks
import turtle   # turtle module for drawing fireworks

#### Initialize variables used in the program

# The following width and height match the GIF used by the program
screen_width, screen_height = 900, 564

firework_radius = 100   # The maximum radius a firework can have
firework_count = 30     # The number of fireworks to shoot

# A list of colours to choose from for a firework
firework_colours = ["red", "orange", "yellow", "green", "cyan", "blue", "violet"]


#### Initialize the turtle module

turtle.setup(screen_width, screen_height)   # Set the size of the screen
turtle.bgpic("hong_kong.gif")               # Put the background image on the
                                            # screen
turtle.width(3)                             # Draw lines with a width of three
turtle.shape("circle")                      # Set the turtle to be bomb shape
turtle.color("red")                         # Set the turtle color to red


#### For loop to shoot individual firework

for i in range(firework_count):
    turtle.speed(6)
    # Clear the sky (screen) for every five fireworks
    if i > 0 and i % 5 == 0:
        time.sleep(1)
        turtle.clear()

    
    #### Add your code here
    # Initialize a starting position
    start_x = random.randint(int(-screen_width/2) , int(screen_width /2))
    start_y = random.randint(int(-screen_height),0)
    turtle.up()
    turtle.goto(start_x, start_y)
    turtle.showturtle()
    
    # Initialize a destination
    dest_x = random.randint(int(-screen_width/2)+30 , int(screen_width /2)-30)
    dest_y = random.randint(0,int(screen_height/2 - 30))

    # Shoot a firework from the start to the destination
    turtle.color("red")
    turtle.goto(dest_x,dest_y)

    #### The turtle is in the sky, explode the firework

    #### Add your code here
    # Pick a firework color from the firework colour list
    colour = firework_colours[random.randint(0,len(firework_colours)-1)]
    turtle.color(colour)
    
    # Pick a size for the firework
    radius = random.randint(int(firework_radius/2),int(firework_radius))
    
    # Pick the number of explosion directions
    explosion_direction = random.randint(10,20)


    #### For loop to draw each ring of explosion
    turtle.tracer(False)
    for this_radius in range(10, radius, 10):
            turtle.hideturtle()
            turtle.speed(0)
            turtle.setheading(0)
            turtle.forward(this_radius)
            turtle.setheading(90)
            for _ in range(explosion_direction):
                turtle.dot(this_radius/10)
                turtle.circle(this_radius, 360/explosion_direction)
            turtle.goto(dest_x,dest_y-this_radius/2.5)
    
    turtle.tracer(True)
    
    playsound.play("explosion.wav")
    #### Add your code here






turtle.done() # Need to keep the window display up

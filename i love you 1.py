import turtle
import time

# Setup layar
screen = turtle.Screen()
screen.bgcolor("white")
screen.setup(width=800, height=600)

# Setup turtle
pen = turtle.Turtle()
pen.speed(6)
pen.color("red")
pen.pensize(5)
pen.hideturtle()

# Posisi awal
pen.penup()
pen.goto(-300, 0)
pen.pendown()

# Fungsi untuk menggambar hati
def draw_heart():
    pen.color("red")
    pen.begin_fill()
    pen.left(140)
    pen.forward(113)
    for i in range(200):
        pen.right(1)
        pen.forward(1)
    pen.left(120)
    for i in range(200):
        pen.right(1)
        pen.forward(1)
    pen.forward(112)
    pen.end_fill()

# Menulis "I"
pen.penup()
pen.goto(-200, 0)
pen.pendown()
pen.left(90)
pen.forward(50)
pen.penup()
pen.goto(-200, -25)
pen.pendown()
pen.forward(50)

# Pindah ke posisi Love
pen.penup()
pen.goto(-150, 0)
pen.pendown()

# Menggambar hati kecil sebagai pengganti "Love"
draw_heart()

# Menulis "You"
pen.penup()
pen.goto(0, 0)
pen.pendown()
pen.color("black")
pen.write("You", font=("Arial", 24, "bold"))

# Tunggu sebelum menutup
time.sleep(3)
turtle.bye()
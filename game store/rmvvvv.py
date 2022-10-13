#________________________________________________________________________________________________________________________

from tkinter import*
from PIL import ImageTk, Image
ris=Tk()
ris.title("CRAZY GAMES")
ris.geometry("1350x1000")
ris.configure(background="black")


cl=Canvas(ris,width="1350",height="1000")
cl.pack()
Photo=ImageTk.PhotoImage(Image.open("image.jpeg"))
cl.create_image(-20,-180,anchor=NW,image=Photo)

#________________________________________________________________________________________________________________________

def thx():
    thx=Tk()
    thx.title("THANK YOU")
    thx.geometry("1350x1000")
    thx.configure(background="pink")


    tthx=Button( text="THANK YOU, YOUR PURCHASE IS SUCCESSFULL", font="consolas 35 bold", bg="lawn green", fg="blue2", relief=SOLID, borderwidth=15)
    tthx.place(x=550, y=300)

#________________________________________________________________________________________________________________________





def billing():
  rut=Tk()
  rut.title("enter card details")
  rut.geometry("400x600")
  rut.resizable('false','false')
  rut.configure(background="black")

  rit1=Label(rut, text="CC DETAILS", font="consolas 30 bold", fg="lawn green", bg="black")
  rit1.place(x=140, y=10)

  rit1=Label(rut, text="CC NUM ==>", font="consolas 16", fg="lawn green", bg="black")
  rit1.place(x=10, y=70)

  rit1=Label(rut, text="_______________________________", font="consolas 16", fg="red", bg="black")
  rit1.place(x=10, y=100)

  rit1=Label(rut, text="CC EXPIRY  ==>", font="consolas 16", fg="lawn green", bg="black")
  rit1.place(x=10, y=170)

  rit1=Label(rut, text="_______________________________", font="consolas 16", fg="red", bg="black")
  rit1.place(x=10, y=200)

  rit1=Label(rut, text="CVV^     ==>", font="consolas 16", fg="lawn green", bg="black")
  rit1.place(x=10, y=270)

  rit1=Label(rut, text="_______________________________", font="consolas 16", fg="red", bg="black")
  rit1.place(x=10, y=300)

  rit1=Label(rut, text="VOUCHER   ==>", font="consolas 16", fg="lawn green", bg="black")
  rit1.place(x=10, y=370)

  rit1=Label(rut, text="_______________________________", font="consolas 16", fg="red", bg="black")
  rit1.place(x=10, y=400)

  ent1=Entry(rut, borderwidth=4)
  ent1.place(x=200, y=70)

  ent1=Entry(rut, borderwidth=4)
  ent1.place(x=200, y=170)

  ent1=Entry(rut, borderwidth=4)
  ent1.place(x=200, y=270)

  ent1=Entry(rut, borderwidth=4)
  ent1.place(x=200, y=370)




  net=Button(rut, text="PAY", font="consolas 18 bold", bg="grey", fg="lawn green", relief=SOLID, borderwidth=5, command=thx)
  net.place(x=80, y=430)


#________________________________________________________________________________________________________________________


def win1():
    import turtle
    import time
    import random

    delay = 0.1

    score = 0
    high_score = 0
    wn = turtle.Screen()
    wn.title("Snake Game by @RMV")
    wn.bgcolor("green")
    wn.setup(width=600, height=600)
    wn.tracer(0) # Turns off the screen updates
    head = turtle.Turtle()
    head.speed(0)
    head.shape("square")
    head.color("black")
    head.penup()
    head.goto(0,0)
    head.direction = "stop"


    food = turtle.Turtle()
    food.speed(0)
    food.shape("circle")
    food.color("red")
    food.penup()
    food.goto(0,100)


    segments = []
    pen = turtle.Turtle()
    pen.speed(0)
    pen.shape("square")
    pen.color("white")
    pen.penup()
    pen.hideturtle()
    pen.goto(0, 260)
    pen.write("Score: 0  High Score: 0", align="center", font=("Courier", 24, "normal"))


    def go_up():
        if head.direction != "down":
            head.direction = "up"
    def go_down():
        if head.direction != "up":
            head.direction = "down"
    def go_left():
        if head.direction != "right":
            head.direction = "left"
    def go_right():
        if head.direction != "left":
            head.direction = "right"

    def move():
        if head.direction == "up":
            y = head.ycor()
            head.sety(y + 20)

        if head.direction == "down":
            y = head.ycor()
            head.sety(y - 20)

        if head.direction == "left":
            x = head.xcor()
            head.setx(x - 20)

        if head.direction == "right":
            x = head.xcor()
            head.setx(x + 20)

# Keyboard bindings
    wn.listen()
    wn.onkeypress(go_up, "w")
    wn.onkeypress(go_down, "s")
    wn.onkeypress(go_left, "a")
    wn.onkeypress(go_right, "d")

# Main game loop
    while True:
        wn.update()

        if head.xcor()>290 or head.xcor()<-290 or head.ycor()>290 or head.ycor()<-290:
            time.sleep(1)
            head.goto(0,0)
            head.direction = "stop"

            for segment in segments:
                segment.goto(1000, 1000)
        
        # Clear the segments list
            segments.clear()

        # Reset the score
            score = 0

        # Reset the delay
            delay = 0.1

            pen.clear()
            pen.write("Score: {}  High Score: {}".format(score, high_score), align="center", font=("Courier", 24, "normal")) 


    # Check for a collision with the food
        if head.distance(food) < 20:
            x = random.randint(-290, 290)
            y = random.randint(-290, 290)
            food.goto(x,y)

        # Add a segment
            new_segment = turtle.Turtle()
            new_segment.speed(0)
            new_segment.shape("square")
            new_segment.color("grey")
            new_segment.penup()
            segments.append(new_segment)

        # Shorten the delay
            delay -= 0.001

            score += 10

            if score > high_score:
                high_score = score
        
            pen.clear()
            pen.write("Score: {}  High Score: {}".format(score, high_score), align="center", font=("Courier", 24, "normal"))

        for index in range(len(segments)-1, 0, -1):
            x = segments[index-1].xcor()
            y = segments[index-1].ycor()
            segments[index].goto(x, y)

        if len(segments) > 0:
            x = head.xcor()
            y = head.ycor()
            segments[0].goto(x,y)

        move()    

    # Check for head collision with the body segments
        for segment in segments:
            if segment.distance(head) < 20:
                time.sleep(1)
                head.goto(0,0)
                head.direction = "stop"
        
            # Hide the segments
                for segment in segments:
                    segment.goto(1000, 1000)
        
            # Clear the segments list
                segments.clear()

            # Reset the score
                score = 0

            # Reset the delay
                delay = 0.1
        
            # Update the score display
                pen.clear()
                pen.write("Score: {}  High Score: {}".format(score, high_score), align="center", font=("Courier", 24, "normal"))

        time.sleep(delay)

    wn.mainloop()


#__________________________________________________________________________________________________________________________________



def win2():
    root = Tk()
    root.geometry("300x500")
    root.title("TIC TAC TOE")

    head = Label(root,text="TIC\TAC\TOE---RMV---",fg="forestgreen",bg="light cyan",font=("Arial",20,"italic"))
    head.pack()

    p1_name = ""
    p2_name = ""
    START = False
    def Start():
        global p1_name,p2_name,START
        P1 = p1.get()
        P2 = p2.get()

        if P1.split() == []:
            text = "Enter Player 1 Name"
            turn.place(x=50,y=455)
            turn['fg'] = "red"
            turn['text'] = text
        elif P2.split() == []:
            text = "Enter Player 2 Name"
            turn.place(x=50,y=455)
            turn['fg'] = "red"
            turn['text'] = text
        elif P1.split() == P2.split():
            text = "Enter Different Player Names"
            turn.place(x=25,y=455)
            turn['fg'] = "red"
            turn['text'] = text
        else:
            p1_name = P1
            p2_name = P2
            p1['font'] = ("Arial",8,"bold")
            p2['font'] = ("Arial",8,"bold")
            p1['state']=DISABLED
            p2['state']=DISABLED

            start.place(x=1000,y=1000)
            turn['text'] = "{}{} Turn".format(p1_name,"'s")
            turn['fg'] = "blue"
            turn['font'] = ("Ubuntu",20,"bold")
            turn.place(x=50,y=425)
            START = True
        
    def WinCheck():
        if b1['text'] == "O" and b2['text'] == "O" and b3['text'] == "O":
            b1['bg']="light green";b2['bg']="light green";b3['bg']="light green"
            return "p1"
        elif b4['text'] == "O" and b5['text'] == "O" and b6['text'] == "O":
            b4['bg']="light green";b5['bg']="light green";b6['bg']="light green"
            return "p1"
        elif b7['text'] == "O" and b8['text'] == "O" and b9['text'] == "O":
            b7['bg']="light green";b8['bg']="light green";b9['bg']="light green"
            return "p1"
        elif b1['text'] == "O" and b4['text'] == "O" and b7['text'] == "O":
            b1['bg']="light green";b4['bg']="light green";b7['bg']="light green"
            return "p1"
        elif b2['text'] == "O" and b5['text'] == "O" and b8['text'] == "O":
            b2['bg']="light green";b5['bg']="light green";b8['bg']="light green"
            return "p1"
        elif b3['text'] == "O" and b6['text'] == "O" and b9['text'] == "O":
            b3['bg']="light green";b6['bg']="light green";b9['bg']="light green"
            return "p1"
        elif b1['text'] == "O" and b5['text'] == "O" and b9['text'] == "O":
            b1['bg']="light green";b5['bg']="light green";b9['bg']="light green"
            return "p1"
        elif b3['text'] == "O" and b5['text'] == "O" and b7['text'] == "O":
            b3['bg']="light green";b5['bg']="light green";b7['bg']="light green"
            return "p1"
    
        if b1['text'] == "X" and b2['text'] == "X" and b3['text'] == "X":
            b1['bg']="light blue";b2['bg']="light blue";b3['bg']="light blue"
            return "p2"
        elif b4['text'] == "X" and b5['text'] == "X" and b6['text'] == "X":
            b4['bg']="light blue";b5['bg']="light blue";b6['bg']="light blue"
            return "p2"
        elif b7['text'] == "X" and b8['text'] == "X" and b9['text'] == "X":
            b7['bg']="light blue";b8['bg']="light blue";b9['bg']="light blue"
            return "p2"
        elif b1['text'] == "X" and b4['text'] == "X" and b7['text'] == "X":
            b1['bg']="light blue";b4['bg']="light blue";b7['bg']="light blue"
            return "p2"
        elif b2['text'] == "X" and b5['text'] == "X" and b8['text'] == "X":
            b2['bg']="light blue";b5['bg']="light blue";b8['bg']="light blue"
            return "p2"
        elif b3['text'] == "X" and b6['text'] == "X" and b9['text'] == "X":
            b3['bg']="light blue";b6['bg']="light blue";b9['bg']="light blue"
            return "p2"
        elif b1['text'] == "X" and b5['text'] == "X" and b9['text'] == "X":
            b1['bg']="light blue";b5['bg']="light blue";b9['bg']="light blue"
            return "p2"
        elif b3['text'] == "X" and b5['text'] == "X" and b7['text'] == "X":
            b3['bg']="light blue";b5['bg']="light blue";b7['bg']="light blue"
            return "p2"
    
        elif (b1['text'] != "" and b2['text'] != "" and b3['text'] != "" and
            b4['text'] != "" and b5['text'] != "" and b6['text'] != "" and
            b7['text'] != "" and b8['text'] != "" and b9['text'] != ""):
            return "tie"
        
        else:
            return False
    def DisableButtons(ButtonList):
        for a in range(len(ButtonList)):
            ButtonList[a]['state'] = DISABLED
    def EnableButtons(ButtonList):
        for a in range(len(ButtonList)):
            ButtonList[a]['state'] = NORMAL
    def BtnClick(button):
        global START,p1_name,p2_name
        if START == True:
            if button['text'] == "":
                if turn['text'] == "{}{} Turn".format(p1_name,"'s"):
                    button['text'] = "O"
                    turn['text'] = "{}{} Turn".format(p2_name,"'s")
                else:
                    button['text'] = "X"
                    turn['text'] = "{}{} Turn".format(p1_name,"'s")

            check = WinCheck()
            if check != False:
                restart.place(x=105,y=470)
                START = False
                if check=="p1":
                    text = "{} Wins".format(p1_name)
                    buttons = [b1,b2,b3,b4,b5,b6,b7,b8,b9]
                    Remove = []
                    for i in range(9):
                        if buttons[i]['bg'] == "light green":
                            Remove.append(buttons[i])
                elif check=="p2":
                    text = "{} Wins".format(p2_name)
                    buttons = [b1,b2,b3,b4,b5,b6,b7,b8,b9]
                    Remove = []
                    for i in range(9):
                        if buttons[i]['bg'] == "light blue":
                            Remove.append(buttons[i])
                else:
                    text = "It is a tie !"
                turn['fg'] = "forestgreen"
                turn['text'] = text

                if check == "p1" or check == "p2":
                    for i in range(len(Remove)):
                        buttons.remove(Remove[i])
                    DisableButtons(buttons)

    def Restart():
        Buttons = [b1,b2,b3,b4,b5,b6,b7,b8,b9]
        EnableButtons([p1,p2])
        EnableButtons(Buttons)
        restart.place(x=1000,y=1000)
        for a in range(len(Buttons)):
            Buttons[a]['text'] = ""
            Buttons[a]['bg'] = "SystemButtonFace"
        turn['text'] = ""
        start.place(x=107,y=410)
        p1['font'] = "TkTextFont"
        p2['font'] = "TkTextFont"
####################################################################################

    Label(root,text="Player 1 :",fg="brown",font=("Courier",10,"bold")).place(x=0,y=50)
    p1 = Entry(root)
    p1.place(x=90,y=52)

    Label(root,text="Player 2 :",fg="brown",font=("Courier",10,"bold")).place(x=0,y=75)
    p2 = Entry(root)
    p2.place(x=90,y=77)

    start = Button(root,text="START",bg="gray90",fg="green",font=("Ubuntu",15,"bold"),command=Start)
    start.place(x=107,y=410)

    turn = Label(root,text="",font=("Ubuntu",15,"normal"))
    turn.place(x=50,y=455)

###################################

    b1 = Button(root,width=13,height=6,command = lambda:BtnClick(b1))
    b1.place(x=0,y=100)

    b2 = Button(root,width=13,height=6,command = lambda:BtnClick(b2))
    b2.place(x=100,y=100)

    b3 = Button(root,width=13,height=6,command = lambda:BtnClick(b3))
    b3.place(x=200,y=100)

    b4 = Button(root,width=13,height=6,command = lambda:BtnClick(b4))
    b4.place(x=0,y=200)

    b5 = Button(root,width=13,height=6,command = lambda:BtnClick(b5))
    b5.place(x=100,y=200)

    b6 = Button(root,width=13,height=6,command = lambda:BtnClick(b6))
    b6.place(x=200,y=200)

    b7 = Button(root,width=13,height=6,command = lambda:BtnClick(b7))
    b7.place(x=0,y=300)

    b8 = Button(root,width=13,height=6,command = lambda:BtnClick(b8))
    b8.place(x=100,y=300)

    b9 = Button(root,width=13,height=6,command = lambda:BtnClick(b9))
    b9.place(x=200,y=300)

###################################

    restart = Button(root,text="Restart",fg="blue",bg="aquamarine",width = 10,height=1,font=("Courier",10,"bold"),command = Restart)
##restart.place(x=105,y=470)
    restart.place(x=1000,y=1000)

    root.mainloop()


#________________________________________________________________________________________________________________________________________



def win3():
    
    from math import sqrt
    from random import shuffle
    HEIGHT = 768
    WIDTH = 1366
    window = Tk()
    colors = ["darkred", "green", "blue", "purple", "pink", "lime"]
    health = {
        "ammount" : 3,
        "color": "green"
    }
    window.title("Bubble Blaster")
    c = Canvas(window, width=WIDTH, height=HEIGHT, bg="darkblue")
    c.pack()
    ship_id = c.create_polygon(5, 5, 5, 25, 30, 15, fill="green")
    ship_id2 = c.create_oval(0, 0, 30, 30, outline="red")
    SHIP_R = 15
    MID_X = WIDTH / 2
    MID_Y = HEIGHT / 2
    c.move(ship_id, MID_X, MID_Y)
    c.move(ship_id2, MID_X, MID_Y)
    ship_spd = 10
    score = 0
    def move_ship(event):
        if event.keysym == "Up":
            c.move(ship_id, 0, -ship_spd)
            c.move(ship_id2, 0, -ship_spd)
        elif event.keysym == "Down":
            c.move(ship_id, 0, ship_spd)
            c.move(ship_id2, 0, ship_spd)
        elif event.keysym == "Left":
            c.move(ship_id, -ship_spd, 0)
            c.move(ship_id2,  -ship_spd, 0)
        elif event.keysym == "Right":
            c.move(ship_id, ship_spd, 0)
            c.move(ship_id2,  ship_spd, 0)
        elif event.keysym == "P":
            score += 10000
    c.bind_all('<Key>', move_ship)
    from random import randint
    bub_id = list()
    bub_r = list()
    bub_speed = list()
    bub_id_e = list()
    bub_r_e = list()
    bub_speed_e = list()
    min_bub_r = 10
    max_bub_r = 30
    max_bub_spd = 10
    gap = 100
    def create_bubble():
        x = WIDTH + gap
        y = randint(0, HEIGHT)
        r = randint(min_bub_r, max_bub_r)
        id1 = c.create_oval(x - r, y - r, x + r, y + r, outline="white", fill="lightblue")
        bub_id.append(id1)
        bub_r.append(r)
        bub_speed.append(randint(5, max_bub_spd))
    def create_bubble_e():
        x = WIDTH + gap
        y = randint(0, HEIGHT)
        r = randint(min_bub_r, max_bub_r)
        id1 = c.create_oval(x - r, y - r, x + r, y + r, outline="black", fill="red")
        bub_id_e.append(id1)
        bub_r_e.append(r)
        bub_speed_e.append(randint(6, max_bub_spd))
    def create_bubble_r():
        x = WIDTH + gap
        y = randint(0, HEIGHT)
        r = randint(min_bub_r, max_bub_r)
        id1 = c.create_oval(x - r, y - r, x + r, y + r, outline="white", fill=colors[0])
        bub_id.append(id1)
        bub_r.append(r)
        bub_speed.append(randint(6, max_bub_spd))
    def move_bubbles():
        for i in range(len(bub_id)):
            c.move(bub_id[i], -bub_speed[i], 0)
        for i in range(len(bub_id_e)):
            c.move(bub_id_e[i], -bub_speed_e[i], 0)
    from time import sleep, time
    bub_chance = 30
    def get_coords(id_num):
        pos = c.coords(id_num)
        x = (pos[0] + pos[2]) / 2
        y = (pos[1] + pos[3]) / 2
        return x, y
    def del_bubble(i):
        del bub_r[i]
        del bub_speed[i]
        c.delete(bub_id[i])
        del bub_id[i]
    def clean():
        for i in range(len(bub_id) -1, -1, -1):
            x, y = get_coords(bub_id[i])
            if x < -gap:
                del_bubble(i)
    def distance(id1, id2):
        x1, y1 = get_coords(id1)
        x2, y2 = get_coords(id2)
        return sqrt((x2 - x1) ** 2 + (y2 - y1) ** 2)
    def  collision():
        points = 0
        for bub in range(len(bub_id) -1, -1, -1):
            if distance(ship_id2, bub_id[bub]) < (SHIP_R + bub_r[bub]):
                points += (bub_r[bub] + bub_speed[bub])
                del_bubble(bub)
        return points
    def cleanAll():
        for i in range(len(bub_id) -1, -1, -1):
            x, y = get_coords(bub_id[i])
            del_bubble(i)
    def  collision_e():
        for bub in range(len(bub_id_e) -1, -1, -1):
            if distance(ship_id2, bub_id_e[bub]) < (SHIP_R + bub_r_e[bub]):
                window.destroy()
                print("You were killed by a red bubble...")
                print("You got ", score, " score!")
                sleep(100)            
    c.create_text(50, 30, text="SCORE", fill="white")
    st = c.create_text(50, 50, fill="white")
    c.create_text(100, 30, text="TIME", fill="white")
    tt = c.create_text(100, 50, fill="white")
    def show(score):
        c.itemconfig(st, text=str(score))
    evil_bub = 50
    #MAIN GAME LOOP
    while True:
        if randint(1, bub_chance) == 1:
            create_bubble()
        if randint(1, evil_bub) == 1:
            create_bubble_e()
        if randint(1, 100) == 1:
            create_bubble_r()
        move_bubbles()
        collision_e()
        clean()
        score += collision()
        if score >= 400:
           evil_bub = 40
           bub_chance = 25
           if score >= 1000:
               evil_bub = 30
               bub_chance = 20
        show(score)
        window.update()
        shuffle(colors)
        sleep(0.01)






#---------------------------------------------------------------------------------------------------------------------------------

def snakeo():
  play=Tk()
  play.title("snake")
  play.geometry("1350x1000")
  play.resizable('false','false')
  play.configure(background="yellow")

  put1=Label(play, text="SNAKE,.....YOU HAVE CHOSEN A GOOD GAME", font="consolas 30 bold", fg="red", bg="white")
  put1.place(x=250, y=20)
  
  put1=Button(play, text="WANT A TRIAL???", font="elephant 20 bold", fg="skyblue", bg="grey", relief=RAISED, borderwidth=6, command=win1)
  put1.place(x=200, y=600)

  put1=Button(play, text="BUY", font="elephant 20 bold", fg="skyblue", bg="grey", relief=RAISED, borderwidth=6, command=billing)
  put1.place(x=800, y=600)



#--------------------------------------------------------------------------------------------------------------------------------

def ttto():
  play=Tk()
  play.title("snake")
  play.geometry("1350x1000")
  play.resizable('false','false')
  play.configure(background="yellow")

  put1=Label(play, text="TIC TAC TOE,.....YOU HAVE CHOSEN A GOOD GAME", font="consolas 30 bold", fg="red", bg="white")
  put1.place(x=250, y=20)
  
  put1=Button(play, text="WANT A TRIAL???", font="elephant 20 bold", fg="skyblue", bg="grey", relief=RAISED, borderwidth=6, command=win2)
  put1.place(x=200, y=600)

  put1=Button(play, text="BUY", font="elephant 20 bold", fg="skyblue", bg="grey", relief=RAISED, borderwidth=6, command=billing)
  put1.place(x=800, y=600)


#------------------------------------------------------------------------------------------------------------------------------

def bubblo():
  play=Tk()
  play.title("snake")
  play.geometry("1350x1000")
  play.resizable('false','false')
  play.configure(background="yellow")

  put1=Label(play, text="BUBBLE,.....YOU HAVE CHOSEN A GOOD GAME", font="consolas 30 bold", fg="red", bg="white")
  put1.place(x=250, y=20)
  
  put1=Button(play, text="WANT A TRIAL???", font="elephant 20 bold", fg="skyblue", bg="grey", relief=RAISED, borderwidth=6, command=win3)
  put1.place(x=200, y=600)

  put1=Button(play, text="BUY", font="elephant 20 bold", fg="skyblue", bg="grey", relief=RAISED, borderwidth=6, command=billing)
  put1.place(x=800, y=600)

  
#________________________________________________________________________________________________________________________


def gms():
  play=Tk()
  play.title("games")
  play.geometry("1350x1000")
  play.resizable('false','false')
  play.configure(background="blue")



  put1=Label(play, text="Select the game you want to play!!", font="consolas 30 bold", fg="red", bg="white")
  put1.place(x=250, y=20)

  put1=Button(play, text="SNAKE", font="elephant 20 bold", fg="skyblue", bg="grey", relief=RAISED, borderwidth=6, command=snakeo)
  put1.place(x=200, y=600)

  put1=Button(play, text="TIC~TAC~TOE", font="elephant 20 bold", fg="skyblue", bg="grey", relief=RAISED, borderwidth=6, command=ttto)
  put1.place(x=550, y=600)

  put1=Button(play, text="BUBBLE GAME", font="elephant 20 bold", fg="skyblue", bg="grey", relief=RAISED, borderwidth=6, command=bubblo)
  put1.place(x=1000, y=600)







#------------------------------------------------------------------------------------------------------------------------



#________________________________________________________________________________________________________________________

def oops():
  rut=Tk()
  rut.title("Start")
  rut.geometry("400x600")
  rut.resizable('false','false')
  rut.configure(background="black")

  rit1=Label(rut, text="LOGIN", font="consolas 30 bold", fg="lawn green", bg="black")
  rit1.place(x=140, y=10)

  rit1=Label(rut, text="First name ==>", font="consolas 16", fg="lawn green", bg="black")
  rit1.place(x=10, y=70)

  rit1=Label(rut, text="_______________________________", font="consolas 16", fg="red", bg="black")
  rit1.place(x=10, y=100)

  rit1=Label(rut, text="Last name  ==>", font="consolas 16", fg="lawn green", bg="black")
  rit1.place(x=10, y=170)

  rit1=Label(rut, text="_______________________________", font="consolas 16", fg="red", bg="black")
  rit1.place(x=10, y=200)

  rit1=Label(rut, text="Email      ==>", font="consolas 16", fg="lawn green", bg="black")
  rit1.place(x=10, y=270)

  rit1=Label(rut, text="_______________________________", font="consolas 16", fg="red", bg="black")
  rit1.place(x=10, y=300)

  rit1=Label(rut, text="Password   ==>", font="consolas 16", fg="lawn green", bg="black")
  rit1.place(x=10, y=370)

  rit1=Label(rut, text="_______________________________", font="consolas 16", fg="red", bg="black")
  rit1.place(x=10, y=400)

  ent1=Entry(rut, borderwidth=4)
  ent1.place(x=200, y=70)

  ent1=Entry(rut, borderwidth=4)
  ent1.place(x=200, y=170)

  ent1=Entry(rut, borderwidth=4)
  ent1.place(x=200, y=270)

  ent1=Entry(rut, borderwidth=4)
  ent1.place(x=200, y=370)




  net=Button(rut, text="Login", font="consolas 18 bold", bg="grey", fg="lawn green", relief=SOLID, borderwidth=5, command=gms)
  net.place(x=80, y=430)

  net1=Button(rut, text="Register", font="consolas 18 bold", bg="grey", fg="lawn green", relief=SOLID, borderwidth=5, command=oops1)
  net1.place(x=200, y=430)

def oops1():
  rut=Tk()
  rut.title("Register window")
  rut.geometry("400x600")
  rut.resizable('false','false')
  rut.configure(background="black")

  rit1=Label(rut, text="REGISTER", font="consolas 30 bold", fg="lawn green", bg="black")
  rit1.place(x=100, y=10)

  rit1=Label(rut, text="First name:", font="consolas 16", fg="lawn green", bg="black")
  rit1.place(x=10, y=70)

  rit1=Label(rut, text="_______________________________", font="consolas 16", fg="red", bg="black")
  rit1.place(x=10, y=100)

  rit1=Label(rut, text="Last name:", font="consolas 16", fg="lawn green", bg="black")
  rit1.place(x=10, y=170)

  rit1=Label(rut, text="_______________________________", font="consolas 16", fg="red", bg="black")
  rit1.place(x=10, y=200)

  rit1=Label(rut, text="Email:", font="consolas 16", fg="lawn green", bg="black")
  rit1.place(x=10, y=270)

  rit1=Label(rut, text="_______________________________", font="consolas 16", fg="red", bg="black")
  rit1.place(x=10, y=300)

  rit1=Label(rut, text="Password:", font="consolas 16", fg="lawn green", bg="black")
  rit1.place(x=10, y=370)

  rit2=Label(rut, text="Confirm password:", font="consolas 16", fg="lawn green", bg="black")
  rit2.place(x=10, y=470)


  rit1=Label(rut, text="_______________________________", font="consolas 16", fg="red", bg="black")
  rit1.place(x=10, y=400)

  rit1=Label(rut, text="_______________________________", font="consolas 16", fg="red", bg="black")
  rit1.place(x=10, y=500)

  ent1=Entry(rut, borderwidth=4)
  ent1.place(x=240, y=70)

  ent1=Entry(rut, borderwidth=4)
  ent1.place(x=240, y=170)

  ent1=Entry(rut, borderwidth=4)
  ent1.place(x=240, y=270)

  ent1=Entry(rut, borderwidth=4)
  ent1.place(x=240, y=370)

  ent1=Entry(rut, borderwidth=4)
  ent1.place(x=240, y=470)

  net1=Button(rut, text="Register", font="consolas 18 bold", bg="grey", fg="lawn green", relief=SOLID, borderwidth=5, command=gms)
  net1.place(x=130, y=530)

  
#________________________________________________________________________________________________________________________

myk1=Button( text="Start", font="consolas 35 bold", bg="lawn green", fg="blue2", relief=SOLID, borderwidth=15,
            command=oops)
myk1.place(x=550, y=300)

ris.mainloop()
#________________________________________________________________________________________________________________________

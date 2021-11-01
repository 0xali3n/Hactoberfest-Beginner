from tkinter import *
import time
from tkinter import messagebox

root = Tk()   # creating Tk window
root.geometry("300x300")   # setting geometry of tk window
root.config(bg ='blanched almond')   # setting background colour of tk window
root.title("Time Counter")   # title() is used to display a message in the title bar.

# Declaration of variables
hr=StringVar()
min=StringVar()
sec=StringVar()

# setting the default value as 0
hr.set("0")
min.set("0")
sec.set("0")

# Use of Entry class to take input from the user
hourEntry= Entry(root, width=3, font=("Arial",18,"bold"), textvariable=hr)
hourEntry.place(x=80,y=20)
minuteEntry= Entry(root, width=3, font=("Arial",18,"bold"), textvariable=min)
minuteEntry.place(x=130,y=20)
secondEntry= Entry(root, width=3, font=("Arial",18,"bold"), textvariable=sec)
secondEntry.place(x=180,y=20)

def submit():
    try:
        # the input provided by the user is stored in here :temp
        temp = int(hr.get())*3600 + int(min.get())*60 + int(sec.get())
    except:
        print("Please input the right value")
    while temp >-1:
        mins,secs = divmod(temp,60)   # divmod(firstvalue = temp//60, secondvalue = temp%60)
        # Converting the input entered in mins or secs to hours, mins ,secs
        # (input = 110 min --> 120*60 = 6600 => 1hr : 50min: 0sec)
        hours=0
        if mins >60:
            hours, mins = divmod(mins, 60)   # divmod(firstvalue = temp//60, secondvalue = temp%60)

        # format () method is used to store the value up to two decimal places
        hr.set("{0:2d}".format(hours))
        min.set("{0:2d}".format(mins))
        sec.set("{0:2d}".format(secs))

        root.update()    # updating the GUI window after decrementing the temp value every time
        time.sleep(1)

        # when temp value = 0; then a messagebox pop's up with a message:"Time's up"
        if (temp == 0):
            messagebox.showinfo("Time Countdown", "Time's up ")
        # after every one sec the value of temp will be decremented by one
        temp -= 1

btn = Button(root, text='Set Countdown Time', bg='peach puff', bd='5', command= submit)   # button widget
btn.place(x = 80,y = 120)

# infinite loop which is required to run tkinter program infinitely until an interrupt occurs
root.mainloop()
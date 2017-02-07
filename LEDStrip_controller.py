from Tkinter import *
import serial

master = Tk()

ser = serial.Serial('COM8',baudrate=9600)

v = StringVar()
w = Label(master,textvariable=v).grid(row=0,column=2)
v.set("Initialized")

#Start defining!

def sendRed():
    ser.write("114")
    v.set("Red")
    
def sendGreen():
    ser.write("103")
    v.set("Green")
    
def sendBlue():
    ser.write("98")
    v.set("Blue")
    
def sendRainbow():
    ser.write("117")
    v.set("Rainbow")
    
def sendCycle():
    ser.write("99")
    v.set("Rainbow Cycle")
    
def sendCheckerboard():
    ser.write("116")
    v.set("Checkerboard")
    
def sendChase():
    ser.write("104")
    v.set("Chase")
    
def sendBreathe():
    ser.write("112")
    v.set("Breathe")
    
def sendOff():
    ser.write("111")
    v.set("Off")
    
red = Button(master,text="Red",command=sendRed,fg="red")
red.grid(row=1,column=1)
green = Button(master,text="Green",command=sendGreen,fg="green")
green.grid(row=1,column=2)
blue = Button(master,text="Blue",command=sendBlue,fg="blue")
blue.grid(row=1,column=3)
rainbow = Button(master,text="Rainbow",command=sendRainbow)
rainbow.grid(row=2,column=1)
cycle = Button(master,text="Cycle",command=sendCycle)
cycle.grid(row=2,column=2)
checkerboard = Button(master,text="Checkerboard",command=sendCheckerboard)
checkerboard.grid(row=2,column=3)
chase = Button(master,text="Chase",command=sendChase)
chase.grid(row=3,column=1)
breathe = Button(master,text="Breathe",command=sendBreathe)
breathe.grid(row=3,column=3)
off = Button(master,text="Off",command=sendOff)
off.grid(row=3,column=2)

mainloop()
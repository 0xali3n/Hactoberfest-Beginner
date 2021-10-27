from time import sleep
from random import randrange
from os import name, system
from sys import exit

#To play the game again or exit from game
def playAgain():
    print("\nPress 1 to play again..\nPress 2 to exit..")
    command = input("Enter your command : ")
    if(command == '1'):
        clearScreen()
        startGame()
    else:
        exit()

#To check whether user is done with the calculations or program wait for 3 seconds
def checkAnswer():
    answer = input("Done(Y/N) : ")
    if(answer.lower() == 'y'):
        return True
    elif(answer.lower() == 'n'):
        print("oh, no worries, take your time")
        sleep(3)
        flag = checkAnswer()
    else:
        print('Invalid command..')
        return False
    return flag

#To print questions(instructions) for user
def printQuestion(question, number=0):
    if(number):
        print(question.format(number))
    else:
        print(question)
    if(checkAnswer() == True):
        return
    else:
        exit()

#To start game 
def startGame():
    printQuestion("\nGuess any number in your mind")
    printQuestion("\nNow add same number to it(or double it)")
    numberToAdd = randrange(0, 100, 2)
    printQuestion("\nNow add {}", numberToAdd)
    printQuestion("\nNow make it half(half your result)")
    printQuestion("\nNow minus the number you chose first from the result")
    print("\nResult is {}".format(numberToAdd//2))
    print("Over".center(20, '*'))
    playAgain()

#To clear screen(terminal)
def clearScreen():
    if name == 'posix':
        _ = system('clear')
    else:
        _ = system('cls')

print("This is fun calculation game".center(60, '-'))
print()
print("Just follow the instructions".center(60,'*'))
print("This program will give final result".center(60, '*'))
startGame()
playAgain()
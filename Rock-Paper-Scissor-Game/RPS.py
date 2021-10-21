import random
print("*****Rock Paper Scissor*****\nInitial score given is 5 to both player and computer\nEnter 'Q' anytime to exit\n")

# print(comp)
def geam():
    player_score = 5
    computer_scoer = 5
    draw = 0
    i = 0
    while i <= 10:
        i += 1
        r = "Rock"
        p = "Paper"
        s = "Scissor"
        car = ["r", "p", "s"]

        comp = random.choice(car)
        # print(comp)


        person = input(f"R :: {r}\nP :: {p}\ns :: {s}\n").lower()
        if person == "q":
            print("\nThanks for playing")
            exit()
        if (person == "r" and comp =="s"):
            print(f"Computer had {s}\nYou Won the round\n")
            player_score += 1
            computer_scoer -= 1
        elif (person == "r" and comp == "p"):
            print(f"Computer had {p}\nYou Lost the round\n")
            player_score -= 1
            computer_scoer += 1
        elif (person == "p" and comp == "r"):
            print(f"Computer had {r}\nYou Won the round\n")
            player_score += 1
            computer_scoer -= 1
        elif (person == "p" and comp == "s"):
            print(f"Computer had {s}\nYou Lost the round\n")
            player_score -= 1
            computer_scoer += 1
        elif (person == "s" and comp == "p"):
            print(f"Computer had {p}\nYou Won the round\n")
            player_score += 1
            computer_scoer -= 1
        elif (person == "s" and comp == "r"):
            print(f"Computer had {s}\nYou Lost the round\n")
            player_score -= 1
            computer_scoer += 1
        elif ((person == "r" and comp == "r") or (person == "p" and comp == "p") or (person == "s" and comp == "s")):
            print("Its a Tie\n")
            draw += 1
            i -= 1
        else:
            print("Invalid input!!!\n")
        # if (player_score == 10) or (computer_scoer == 10) or (player_score == computer_scoer == 0):
        #     print(f"*****The End*****\nYour score :: {player_score}\nComputer score :: {computer_scoer}\n"
        #           f"Number of Draws :: {draw}")
    if player_score <= computer_scoer:
        print(f"You lost the game!!\nYour score :: {player_score}\nComputer score :: {computer_scoer}\n"
              f"Number of Draws :: {draw}\nYou can still beat the computer")

    elif computer_scoer <= player_score:
        print(f"You Won the game!!\nYour score :: {player_score}\nComputer score :: {computer_scoer}\n"
              f"Number of Draws :: {draw}\n")
    elif computer_scoer == player_score:
        print(f"Game is draw!!\nYour score :: {player_score}\nComputer score :: {computer_scoer}\n"
              f"Number of Draws :: {draw}\n")
    again = input("Do you want to play again?\nY :: Yes\nN :: No\n").lower()
    if (again == "y"):
        geam()
    else:
        print("\nThanks For playing")
        exit()

geam()









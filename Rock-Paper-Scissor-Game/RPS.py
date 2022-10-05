import random

print("*****Rock Paper Scissor*****\nInitial score given is 5 to both player and computer\nEnter 'Q' anytime to exit\n")


def game():
    player_score = 5
    computer_score = 5
    draw = 0
    i = 0
    while i <= 10:
        i += 1

        rock = '''
            _______
        ---'   ____)
              (_____)
              (_____)
              (____)
        ---.__(___)
        '''

        paper = '''
            _______
        ---'   ____)____
                  ______)
                  _______)
                 _______)
        ---.__________)
        '''

        scissor = '''
            _______
        ---'   ____)____
                  ______)
               __________)
              (____)
        ---.__(___)
        '''

        rps = [rock, paper, scissor]
        r = "Rock"
        p = "Paper"
        s = "Scissor"
        char = ["r", "p", "s"]

        comp = random.choice(char)
        person = input(f"R :: {r}\nP :: {p}\nS :: {s}\n").lower()
        if person == "q":
            print("\nThanks for playing")
            exit()
        if person == "r" and comp == "s":
            print(f"{rock}\nComputer chose: {scissor}\nYou Won the round\n")
            player_score += 1
            computer_score -= 1
        elif person == "r" and comp == "p":
            print(f"{rock}\nComputer chose: {paper}\nYou Lost the round\n")
            player_score -= 1
            computer_score += 1
        elif person == "p" and comp == "r":
            print(f"{paper}\nComputer chose: {rock}\nYou Won the round\n")
            player_score += 1
            computer_score -= 1
        elif person == "p" and comp == "s":
            print(f"{paper}\nComputer chose: {scissor}\nYou Lost the round\n")
            player_score -= 1
            computer_score += 1
        elif person == "s" and comp == "p":
            print(f"{scissor}\nComputer chose: {paper}\nYou Won the round\n")
            player_score += 1
            computer_score -= 1
        elif person == "s" and comp == "r":
            print(f"{scissor}\nComputer chose: {scissor}\nYou Lost the round\n")
            player_score -= 1
            computer_score += 1
        # elif (person == "r" and comp == "r") or (person == "p" and comp == "p") or (person == "s" and comp == "s"):
        #     print("Its a Tie\n")
        #     draw += 1
        #     i -= 1
        elif person == "r" and comp == "r":
            print(f"{rock}\nComputer chose: {rock}\nYou Lost the round\n")
            print("Its a Tie\n")
            draw += 1
            i -= 1
        elif person == "p" and comp == "p":
            print(f"{paper}\nComputer chose: {paper}\nYou Lost the round\n")
            print("Its a Tie\n")
            draw += 1
            i -= 1
        elif person == "s" and comp == "s":
            print(f"{scissor}\nComputer chose: {scissor}\nYou Lost the round\n")
            print("Its a Tie\n")
            draw += 1
            i -= 1
        else:
            print("Invalid input!!!\n")
        # if (player_score == 10) or (computer_score == 10) or (player_score == computer_score == 0):
        #     print(f"*****The End*****\nYour score :: {player_score}\nComputer score :: {computer_score}\n"
        #           f"Number of Draws :: {draw}")
    if player_score <= computer_score:
        print(f"You lost the game!!\nYour score :: {player_score}\nComputer score :: {computer_score}\n"
              f"Number of Draws :: {draw}\nYou can still beat the computer")

    elif computer_score <= player_score:
        print(f"You Won the game!!\nYour score :: {player_score}\nComputer score :: {computer_score}\n"
              f"Number of Draws :: {draw}\n")
    elif computer_score == player_score:
        print(f"Game is draw!!\nYour score :: {player_score}\nComputer score :: {computer_score}\n"
              f"Number of Draws :: {draw}\n")
    again = input("Do you want to play again?\nY :: Yes\nN :: No\n").lower()
    if again == "y":
        game()
    else:
        print("\nThanks For playing")
        exit()


game()



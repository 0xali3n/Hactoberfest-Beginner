#Chopsticks Game


class Chop:
    def __init__(self):
        '''we have two players p1 and p2. Initially both have one finger alive in both hands.
        p1[1] indicates left hand and p1[2] indicates right hand and same for p2.'''

        self.p1=[1,1,1]                     #player one specifications
        self.p2=[1,1,1]                     #player one specifications
        self.x=0
        self.winCon=0

    def combatA(self):
        if self.handInput==1:               #attack
            if self.handAffector==1:
                self.p2[1]=self.p1[1]+self.p2[1]
            if self.handAffector==2:
                self.p2[2]=self.p1[1]+self.p2[2]
        if self.handInput==2:               #attack
            if self.handAffector==1:
                self.p2[1]=self.p1[2]+self.p2[1]
            if self.handAffector==2:
                self.p2[2]=self.p1[2]+self.p2[2]
        if self.handInput==3:               #split
            if self.handAffector==1:
                self.d=self.p1[1]
                self.p1[2]+=self.p1[1]//2
                self.p1[1]=self.d-self.p1[1]//2
            if self.p1[1]%2==1:
                self.p1[1]=self.p1[1]+1
            if self.handAffector==2:
                self.d=self.p1[1]
                self.p1[2]+=self.p1[1]//2
                self.p1[1]=self.d-self.p1[1]//2
                if self.p1[2]%2==1:
                    self.p1[2]=self.p1[2]+1

    def combatB(self):
        if self.handInput==1:               #attack
            if self.handAffector==1:
                self.p1[1]=self.p2[1]+self.p1[1]
            if self.handAffector==2:
                self.p1[2]=self.p2[1]+self.p1[2]
        if self.handInput==2:               #attack
            if self.handAffector==1:
                self.p1[1]=self.p2[2]+self.p2[1]
            if self.handAffector==2:
                self.p1[2]=self.p2[2]+self.p1[2]
        if self.handInput==3:               #split
            if self.handAffector==1:
                self.d1=self.p2[1]
                self.p2[2]+=self.p2[1]//2
                self.p2[1]=self.d1-self.p2[1]//2
                if self.p2[1]%2==1:
                    self.p2[1]=self.p2[1]+1
            if self.handAffector==2:
                self.d1=self.p2[1]
                self.p2[2]+=self.p2[1]//2
                self.p2[1]=self.d1-self.p2[1]//2
                if self.p2[2]%2==1:
                    self.p2[2]=self.p2[2]+1

    def handChoice(self):
        print("Which hand will you use this turn?\n")
        print("1. Left Hand\n2. Right Hand\n3. Split\n")
        self.handInput=int(input())

    def attackChoice(self):
        print("Which hand will you attack this turn?\n")
        print("1. Left Hand\n2. Right Hand\n")
        self.handAffector=int(input())

    def handRolloverLogic(self):
        if self.p1[1]>=5:self.p1[1]=0
        if self.p1[2]>=5:self.p1[2]=0
        if self.p2[1]>=5:self.p2[1]=0
        if self.p2[2]>=5:self.p2[2]=0

    def playerOne(self):            #player One's turn
        self.handChoice()           #which hand will i use this turn
        self.attackChoice()         #on which hand will i use against this turn
        self.combatA()
        self.handRolloverLogic()

    def playerTwo(self):
        self.handChoice()
        self.attackChoice()
        self.combatB()
        self.handRolloverLogic()

    def winCheck(self):             #check to see if wither both of player one's hands have reached 0
        if self.p1[1]==0 and self.p1[2]==0:
            self.winCon=1
            self.x=1
    #check if both of player One's hands equal zero to see if player Two won
        if self.p2[1]==0 and self.p2[2]==0:
            self.winCon=2
            self.x=1

obj=Chop()
while obj.x==0:
    obj.winCheck()                  #does a check to see if either both of player one's hands have reached 0
    print("Player One\'s Turn\n")
    print("   H1  H2\n")
    print("P1: {}  {}\n".format(obj.p1[1],obj.p1[2]))
    print("P2: {}  {}\n".format(obj.p2[1],obj.p2[2]))
    obj.playerOne()                 #Player one's turn
    obj.winCheck()                  #does a check to see if either both of player one's hands have reached 0

    print("Player Two\'s Turn\n")
    print(" H1  H2\n")
    print("P1: {}  {}\n".format(obj.p1[1],obj.p1[2]))
    print("P2: {}  {}\n".format(obj.p2[1],obj.p2[2]))
    obj.playerTwo()  #player two's turn

if obj.winCon==1:
    print("***********  Player Two Wins  ***********\n")
if obj.winCon==2:
    print("***********  Player One Wins  ***********\n")

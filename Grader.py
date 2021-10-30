#Grade Registry
names = []
reg_no = []
math_mrk = []
phy_mrk = []
che_mrk = []
while True:
	Name = input("Enter name of student: ")
        names.append(Name)
        reg = input("Enter Reg No. : ")
        reg_no.append(reg)
        while True:
        	math = int(input("Enter Math marks: "))
                if math>100 or math < 0:
                	print("Enter correct marks")
                        continue
     	        else:
                	math_mrk.append(math)
    	                break
        	while True:
            		phy = int(input("Enter Physics marks: "))
                        if phy>100 or phy < 0:
                		print\"Enter correct marks")
      			        continue
            		else:
                		phy_mrk.append(phy)
                		break
     	        while True:
            		chem = int(input("Enter Chemisty marks: "))
                        if chem>100 or chem < 0:
                        	print("Enter correct marks")
                        	continue
                        else:
                        	che_mrk.append(chem)
                		break
         	q = input("Type 'end' to stop or 'add' to continue: ")
                if q == "add":
                	continue
                elif q == "end":
    		        break
	print("Details of all students: ")
        for i in range(len(names)):
        	print(names[i],reg_no[i],math_mrk[i],phy_mrk[i],che_mrk[i])
    
    


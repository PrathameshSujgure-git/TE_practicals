bot_name = "Pybot"
print("Myself",bot_name, "I was born on 21st April 2022")
 
user_name = input("Enter your name: ")
 
def greet():
    print("Hello" ,user_name, "Hope you are having good time, lets test your python knowledge")
 
greet()
 
user_answer1 = ""
 
def ques1_guess():
        print("Question No. 1: In which year python was invented?")
        print("Option A: 1991")
        print("Option B: 1995")
        print("Option C: 1997")
        print("Option D: 1989")
        user_answer1 = input("Enter your answer option: ")
        if user_answer1 == "A" :
            print("Correct Answer!")
            points = 1
            print("Your score is: ",points)
        else:
            print("Wrong Answer!")
 
ques1_guess()
 
def ques2_guess():
        print("Question No. 2: Who invented python?")
        print("Option A: Guido van Rossum")
        print("Option B: Henrick Eich")
        print("Option C: Mark Russou")
        print("Option D: Bjarne Stroustrup")
        user_answer2 = input("Enter your answer: ")
        if user_answer2 == "Guido van Rossum":
            print("Correct Answer!")
            points = 2
            print("Your score is: ",points)
        else:
            print("Wrong Answer!")
 
ques2_guess()
 
def exit():
    playAgain =  input("Would you like to play again?Y/N")
    if(playAgain == "Y"):
        ques1_guess()
        ques2_guess()
    else:
        print("You have reached to the end of the game")
 
exit()
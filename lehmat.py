//TASK: https://cses.fi/dt/task/329/

lehmaLkm = input().split()[0]
secondInput = input().split()
currNum = 1
tulleet = {}
 
for x in range(0, len(secondInput)):
  
    if int(secondInput[x]) == currNum:
        tulleet[int(secondInput[x])]  = True
        while True:
            if currNum not in tulleet:
                break
            currNum += 1
            
    elif int(secondInput[x]) > currNum:
        tulleet[int(secondInput[x])] = True
        
    print(currNum) 

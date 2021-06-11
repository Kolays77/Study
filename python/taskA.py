troom = int(input())
tcond = int(input())

command = input()

if command == "auto":
	print(tcond)
elif command == "freeze":
	if troom < tcond:
		print(troom)
	else:
		print(tcond)
elif command == "heat":
    if troom > tcond:
        print(troom)
    else:
        print(tcond)
else:
    print(troom)
    

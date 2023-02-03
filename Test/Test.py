def gom(x):

    if x < 0:
        raise Exception("Error: Please Enter positive Numbers Only");
        
    print("You have Entered: ",x);
    
while 1 == 1:

    try:    
        num = int( input("Enter a Number: "));
        gom(num);
    except Exception as msg:
        print(msg);
       
#



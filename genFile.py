import random



i = 0
with open("test.txt","w") as f:
    while i<=10000000:
        temp = random.randint(0,127)
        f.write(chr(temp))
        
        i+=1
        if i%100==0:
            f.flush()


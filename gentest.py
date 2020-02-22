from random import randint

queueLen = 20
steps = 3

with open("test.txt", "w") as file:
    file.write("{} {}\n".format(queueLen, steps))
    for i in range(2):
        for j in range(queueLen):
            file.write('.' if randint(0, 10) > 2 else ('x' if i != 0 or j != 0 else '.'))
        file.write('\n')

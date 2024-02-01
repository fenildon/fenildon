x=int(input("enter num1: "))
y=int(input("enter num2: "))
print("before swap x={} y={} ".format(x,y),end='END')
x,y=y,x
print(" after swap x={} y={} ".format(x,y))
# end is use full in print function modify def value of '\n' at end
# sep is use full for avoid default nature of seprator','(oprator) (space)

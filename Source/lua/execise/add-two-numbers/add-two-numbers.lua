list1={2,4,3}
list2={5,6,4}


function pow(x,y)
    if y==0 then
        return 1
    end
    y=y-1
    result = x
    for i = y, 1,-1 do
        result = result*x
    end
    return result
end


number1=0
for count=#list1,1,-1 do
    number1= number1+ pow(10,count-1)*list1[count]
end

number2=0
for count = #list2, 1,-1 do
    number2 = number2+pow(10,count-1)*list2[count]
end

number = number1+number2

print(number)

numStr= tostring(number)

print(string.reverse(numStr))
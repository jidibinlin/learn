s = io.read("*l")

set={}

left = 0
result = 0

for i = 1, #s do
    if i~=1 then
        set[string.sub(s,i-1,i-1)]=nil
    end

    while (left+1<= #s) and set[string.sub(s,left+1,left+1)]==nil do
        set[string.sub(s,left+1,left+1)]=string.sub(s,left+1,left+1)
        left=left+1
    end
    result = math.max(result,left-i+1)
end
print(result)

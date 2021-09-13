
tab = {
   [1]=1,
   [2]=2,
   [3]=3
}


for key,value in pairs(tab) do
   value = 2
end

for key,value in pairs(tab) do
   print("%d",value)
end

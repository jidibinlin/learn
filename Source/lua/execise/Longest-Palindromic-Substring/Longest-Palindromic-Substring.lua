-- 处理输入
input = io.read()

--动态规划
--[[

1. 寻找最优子结构
	p(i,j)=true : 从下标i到j是回文字串
2. 递归定义最优解的值
	p(i-1,j+1): 为回文字串的条件是p(i,j)=true 且s[i-1]==s[j+1]
3. 边界条件
	1. 当字串长度为1时，显然就是回文字串
	2. 当字串长度为2时, 必须s[i]==s[i+1]
4. 计算最优解的值

--]]
dp = {}

for i = 1, #input do
	dp[i]={}
	for j = 1, #input do
		if i == j then
			dp[i][j]=true
		else
			dp[i][j]=false
		end	
	end
end
function printTable(dp)
	for i = 1, #dp do
		local string=""
		for j = 1, #dp[i] do
			if dp[i][j] then
				string = string.."true "
			else
				string = string.."false "
			end
		end
	end
end

max = 1
result={}
result[1]=1
result[2]=1

for i = 2, #input do
	for j = 1,#input-i+1,1 do
		if i == 2 then
			dp[j][j+1]= string.sub(input,j,j) == string.sub(input,j+1,j+1) and true or false
			if string.sub(input,j,j) == string.sub(input,j+1,j+1) then
				max = i
				result[1]=j
				result[2]=j+1
			end
		else
			if dp[j+1][j+i-2] == true and string.sub(input,j,j) == string.sub(input,j+i-1,j+i-1) then
				dp[j][j+i-1]=true
				if i>= max then
					max = i
					result[1]=j
					result[2]=j+i-1
				end
			else
				dp[j][j+i-1]=false
			end
		end
	end
end
print(string.sub(result[1],result[2]))


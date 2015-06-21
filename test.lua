lwiringpi = require "lwiringpi"


print("Macros:")

local array = {}
for k, v in pairs(lwiringpi) do
	table.insert(array, {key = k, value = v})
end

table.sort(array, function(a, b)
	return a.key < b.key
end)

for _, data in pairs(array) do
	local k = data.key
	local v = data.value
	if type(v) ~= "function" then
		print(string.format("lwiringpi.%s", k))
	else
		print(string.format("lwiringpi.%s()", k))
	end
end






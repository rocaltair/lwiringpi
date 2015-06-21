gpio = require "lwiringpi"

for k, v in pairs(gpio) do
	print(k, v)
end
gpio.delay(5000)



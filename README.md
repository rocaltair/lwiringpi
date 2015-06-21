# lwiringpi
wiringPi(https://github.com/WiringPi/WiringPi) wraped  for lua

tested on rasbian

# Functions

lwiringpi.wiringPiSetup()

lwiringpi.wiringPiSetupSys()

lwiringpi.wiringPiSetupGpio()

lwiringpi.wiringPiSetupPiFace()

lwiringpi.piBoardRev()

lwiringpi.wpiPinToGpio(wpiPin)

lwiringpi.wiringPiSetupPiFaceForGpioProg()

lwiringpi.pinMode(pin, mode)

lwiringpi.getAlt(pin)

lwiringpi.pullUpDnControl(pin, pud)

lwiringpi.digitalWrite(pin, value)

lwiringpi.digitalWriteByte(value)

lwiringpi.gpioClockSet(pin, freq)

lwiringpi.pwmWrite(pin, value)

lwiringpi.setPadDrive(group, value)

lwiringpi.digitalRead(pin)

lwiringpi.pwmSetMode(mode)

lwiringpi.pwmSetRange(range)

lwiringpi.pwmSetClock(divisor)

lwiringpi.waitForInterrupt(pin, mS)

lwiringpi.piLock(key)

lwiringpi.piUnlock(key)

lwiringpi.piHiPri(pri)

lwiringpi.delay(howLong)

lwiringpi.delayMicroseconds(howLong)

lwiringpi.millis()

lwiringpi.micros()

# Macros

lwiringpi.GPIO_CLOCK

lwiringpi.HIGH

lwiringpi.LOW


lwiringpi.INT_EDGE_BOTH

lwiringpi.INT_EDGE_FALLING

lwiringpi.INT_EDGE_RISING

lwiringpi.INT_EDGE_SETUP


lwiringpi.NUM_PINS


lwiringpi.INPUT

lwiringpi.OUTPUT


lwiringpi.PUD_DOWN

lwiringpi.PUD_UP

lwiringpi.PUD_OFF


lwiringpi.PWM_MODE_BAL

lwiringpi.PWM_MODE_MS

lwiringpi.PWM_OUTPUT


lwiringpi.WPI_MODE_GPIO

lwiringpi.WPI_MODE_GPIO_SYS


lwiringpi.WPI_MODE_PIFACE

lwiringpi.WPI_MODE_PINS

lwiringpi.WPI_MODE_UNINITIALISED


# How to install

clone this repo to your dir

make && sudo make install





#include <wiringPi.h>
#include <lua.h>
#include <lauxlib.h>

#define LIBNAME "lwiringpi"

#define ARRAY_LINE(KEY)	\
	{ #KEY , KEY }

struct lwiringpi_macro_t{
	const char *name;
	int value;
};

static const struct lwiringpi_macro_t macros[] = {
	// Deprecated
	ARRAY_LINE(NUM_PINS),
	ARRAY_LINE(WPI_MODE_PINS),
	ARRAY_LINE(WPI_MODE_GPIO),
	ARRAY_LINE(WPI_MODE_GPIO_SYS),
	ARRAY_LINE(WPI_MODE_PIFACE),
	ARRAY_LINE(WPI_MODE_UNINITIALISED),
	// Pin modes
	ARRAY_LINE(INPUT),
	ARRAY_LINE(OUTPUT),
	ARRAY_LINE(PWM_OUTPUT),
	ARRAY_LINE(GPIO_CLOCK),
	ARRAY_LINE(LOW),
	ARRAY_LINE(HIGH),
	// Pull up/down/none
	ARRAY_LINE(PUD_OFF),
	ARRAY_LINE(PUD_DOWN),
	ARRAY_LINE(PUD_UP),
	// PWM
	ARRAY_LINE(PWM_MODE_MS),
	ARRAY_LINE(PWM_MODE_BAL),
	// Interrupt levels
	ARRAY_LINE(INT_EDGE_SETUP),
	ARRAY_LINE(INT_EDGE_FALLING),
	ARRAY_LINE(INT_EDGE_RISING),
	ARRAY_LINE(INT_EDGE_BOTH),
	{NULL, 0},
};

LUA_API int lua_wiringPiSetup(lua_State *L) {
	int ret = wiringPiSetup();
	lua_pushinteger(L, ret);
	return 1;
}

LUA_API int lua_wiringPiSetupSys(lua_State *L) {
	int ret = wiringPiSetupSys();
	lua_pushinteger(L, ret);
	return 1;
}

LUA_API int lua_wiringPiSetupGpio(lua_State *L) {
	int ret = wiringPiSetupGpio();
	lua_pushinteger(L, ret);
	return 1;
}

LUA_API int lua_wiringPiSetupPiFace(lua_State *L) {
	int ret = wiringPiSetupPiFace();
	lua_pushinteger(L, ret);
	return 1;
}

LUA_API int lua_piBoardRev(lua_State *L) {
	int ret = piBoardRev();
	lua_pushinteger(L, ret);
	return 1;
}

LUA_API int lua_wpiPinToGpio(lua_State *L) {
	int wpiPin = luaL_checkinteger(L, 1);
	int ret = wpiPinToGpio(wpiPin);
	lua_pushinteger(L, ret);
	return 1;
}

LUA_API int lua_wiringPiSetupPiFaceForGpioProg(lua_State *L) {
	int ret = wiringPiSetupPiFaceForGpioProg();	
	lua_pushinteger(L, ret);
	return 1;
}

LUA_API int lua_pinMode(lua_State *L) {
	int pin = luaL_checkinteger(L, 1);
	int mode = luaL_checkinteger(L, 2);
	pinMode(pin, mode);
	return 0;
}

LUA_API int lua_getAlt(lua_State *L) {
	int pin = luaL_checkinteger(L, 1);
	int ret = getAlt(pin);
	lua_pushinteger(L, ret);
	return 1;
}

LUA_API int lua_pullUpDnControl(lua_State *L) {
	int pin = luaL_checkinteger(L, 1);
	int pud = luaL_checkinteger(L, 2);
	pullUpDnControl(pin, pud);
	return 0;
}

LUA_API int lua_digitalWrite(lua_State *L) {
	int pin = luaL_checkinteger(L, 1);
	int value = luaL_checkinteger(L, 2);
	digitalWrite(pin, value);
	return 0;
}

LUA_API int lua_digitalWriteByte(lua_State *L) {
	int value = luaL_checkinteger(L, 1);
	digitalWriteByte(value);
	return 0;
}

LUA_API int lua_gpioClockSet(lua_State *L) {
	int pin = luaL_checkinteger(L, 1);
	int freq = luaL_checkinteger(L, 2);
	gpioClockSet(pin, freq);
	return 0;
}

LUA_API int lua_pwmWrite(lua_State *L) {
	int pin = luaL_checkinteger(L, 1);
	int value = luaL_checkinteger(L, 2);
	pwmWrite(pin, value);
	return 0;
}

LUA_API int lua_setPadDrive(lua_State *L) {
	int group = luaL_checkinteger(L, 1);
	int value = luaL_checkinteger(L, 2);
	setPadDrive(group, value);
	return 0;
}

LUA_API int lua_digitalRead(lua_State *L) {
	int pin = luaL_checkinteger(L, 1);
	int ret = digitalRead(pin);
	lua_pushinteger(L, ret);
	return 1;
}

LUA_API int lua_pwmSetMode(lua_State *L) {
	int mode = luaL_checkinteger(L, 1);
	pwmSetMode(mode);
	return 0;
}

LUA_API int lua_pwmSetRange(lua_State *L) {
	unsigned int range = (unsigned int) luaL_checkinteger(L, 1);
	pwmSetRange(range);
	return 0;
}

LUA_API int lua_pwmSetClock(lua_State *L) {
	int divisor = luaL_checkinteger(L, 1);
	pwmSetClock(divisor);
	return 0;
}

LUA_API int lua_waitForInterrupt(lua_State *L) {
	int pin = luaL_checkinteger(L, 1);
	int mS = luaL_checkinteger(L, 2);
	int ret = waitForInterrupt(pin, mS);
	lua_pushinteger(L, ret);
	return 1;
}

/*
LUA_API int lua_wiringPiISR(lua_State *L) {
	int pin = luaL_checkinteger(L, 1);
	int mode = luaL_checkinteger(L, 2);
	if (!lua_isfunction(L, 3)) {
			luaL_error(L, "a function required for arg #3 of wiringPiISR");
			return 0;
	}
	int ret = wiringPiISR(pin, mode, void (*function)(void));
	lua_pushinteger(L, ret);
	return 1;
}
*/

/*
LUA_API int lua_piThreadCreate(lua_State *L) {
	int ret = 0;
	extern int piThreadCreate(void *(*fn)(void *));
	lua_pushinteger(L, ret);
	return 1;
}
*/

LUA_API int lua_piLock(lua_State *L) {
	int key = luaL_checkinteger(L, 1);
	piLock(key);
	return 0;
}

LUA_API int lua_piUnlock(lua_State *L) {
	int key = luaL_checkinteger(L, 1);
	piUnlock(key);
	return 0;
}

LUA_API int lua_piHiPri(lua_State *L) {
	int pri = luaL_checkinteger(L, 1);
	int ret = piHiPri(pri);
	lua_pushinteger(L, ret);
	return 1;
}

LUA_API int lua_delay(lua_State *L) {
	unsigned int howLong = (unsigned int)luaL_checkinteger(L, 1);
	delay(howLong);
	return 0;
}

LUA_API int lua_delayMicroseconds(lua_State *L) {
	unsigned int howLong = (unsigned int)luaL_checkinteger(L, 1);
	delayMicroseconds(howLong);
	return 0;
}

LUA_API int lua_millis(lua_State *L) {
	lua_Number ret = (lua_Number)millis();
	lua_pushnumber(L, ret);
	return 1;
}

LUA_API int lua_micros(lua_State *L) {
	lua_Number ret = (lua_Number)micros();
	lua_pushnumber(L, ret);
	return 1;
}

static const struct luaL_Reg funcs[] = {
	{"wiringPiSetup", lua_wiringPiSetup},
	{"wiringPiSetupSys", lua_wiringPiSetupSys},
	{"wiringPiSetupGpio", lua_wiringPiSetupGpio},
	{"wiringPiSetupPiFace", lua_wiringPiSetupPiFace},
	{"piBoardRev", lua_piBoardRev},
	{"wpiPinToGpio", lua_wpiPinToGpio},
	{"wiringPiSetupPiFaceForGpioProg", lua_wiringPiSetupPiFaceForGpioProg},
	{"pinMode", lua_pinMode},
	{"getAlt", lua_getAlt},
	{"pullUpDnControl", lua_pullUpDnControl},
	{"digitalWrite", lua_digitalWrite},
	{"digitalWriteByte", lua_digitalWriteByte},
	{"gpioClockSet", lua_gpioClockSet},
	{"pwmWrite", lua_pwmWrite},
	{"setPadDrive", lua_setPadDrive},
	{"digitalRead", lua_digitalRead},
	{"pwmSetMode", lua_pwmSetMode},
	{"pwmSetRange", lua_pwmSetRange},
	{"pwmSetClock", lua_pwmSetClock},
	{"waitForInterrupt", lua_waitForInterrupt},
	// {"wiringPiISR", lua_wiringPiISR},
	// {"piThreadCreate", lua_piThreadCreate},
	{"piLock", lua_piLock},
	{"piUnlock", lua_piUnlock},
	{"piHiPri", lua_piHiPri},
	{"delay", lua_delay},
	{"delayMicroseconds", lua_delayMicroseconds},
	{"millis", lua_millis},
	{"micros", lua_micros},
	{NULL, NULL},
};

int luaopen_lwiringpi(lua_State *L) {
	const char *name;
	int value;
	int i = 0;
	luaL_register(L, LIBNAME, funcs);
	for (;;) {
		name = macros[i].name;
		value = macros[i].value;
		i++;
		if (name == NULL) {
			break;
		}
		lua_pushstring(L, name);
		lua_pushinteger(L, value);
		lua_settable(L, -3);
	}
	return 1;
}


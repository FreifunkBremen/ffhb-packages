all: respondd.so

CFLAGS += -Wall

respondd.so: respondd.c
	$(CC) $(CPPFLAGS) $(CFLAGS) $(LDFLAGS) -std=c11 -shared -fPIC -D_GNU_SOURCE -lnl-tiny -o $@ $^ $(LDLIBS)

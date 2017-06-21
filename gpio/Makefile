#
# Makefile:
#	The gpio command:
#	  A swiss-army knige of GPIO shenanigans.
#	https://projects.drogon.net/wiring-pi
#
#	Copyright (c) 2012-2013 Gordon Henderson
#################################################################################
# This file is part of wiringPi:
#	Wiring Compatable library for the Raspberry Pi
#
#    wiringPi is free software: you can redistribute it and/or modify
#    it under the terms of the GNU Lesser General Public License as published by
#    the Free Software Foundation, either version 3 of the License, or
#    (at your option) any later version.
#
#    wiringPi is distributed in the hope that it will be useful,
#    but WITHOUT ANY WARRANTY; without even the implied warranty of
#    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#    GNU Lesser General Public License for more details.
#
#    You should have received a copy of the GNU Lesser General Public License
#    along with wiringPi.  If not, see <http://www.gnu.org/licenses/>.
#################################################################################

DESTDIR=/usr
PREFIX?=/local

#DEBUG	= -g -O0
DEBUG	= -O2
CC	?= gcc
INCLUDE	= -I$(DESTDIR)$(PREFIX)/include
CFLAGS	+= $(DEBUG) -Wall $(INCLUDE) -Winline -pipe

LDFLAGS	= -L$(DESTDIR)$(PREFIX)/lib
LIBS    = -lwiringPi -lwiringPiDev -lpthread -lm

ifeq ($(PLATFORM),)
  PLATFORM = OrangePi_2G-IOT
  #PLATFORM = OrangePi_PC2
  #PLATFORM = OrangePi_A64
  #PLATFORM = OrangePi_H5
  #PLATFORM = OrangePi_ZERO
endif

ifeq ($(PLATFORM), OrangePi_2G-IOT)
EXTRA_CFLAGS = -DCONFIG_ORANGEPI_2G_IOT
EXTRA_CFLAGS += -DCONFIG_ORANGEPI
endif

ifeq ($(PLATFORM), OrangePi_PC2)
EXTRA_CFLAGS = -DCONFIG_ORANGEPI_PC2
EXTRA_CFLAGS += -DCONFIG_ORANGEPI
endif

ifeq ($(PLATFORM), OrangePi_A64)
EXTRA_CFLAGS = -DCONFIG_ORANGEPI_A64
EXTRA_CFLAGS += -DCONFIG_ORANGEPI
endif

ifeq ($(PLATFORM), OrangePi_H3)
EXTRA_CFLAGS = -DCONFIG_ORANGEPI_H3
EXTRA_CFLAGS += -DCONFIG_ORANGEPI
endif

ifeq ($(PLATFORM), OrangePi_ZERO)
EXTRA_CFLAGS = -DCONFIG_ORANGEPI_ZERO
EXTRA_CFLAGS += -DCONFIG_ORANGEPI
endif

# May not need to  alter anything below this line
###############################################################################

SRC	=	gpio.c extensions.c readall.c pins.c

ifeq ($(PLATFORM), OrangePi_2G-IOT)
  SRC += OrangePi.c
endif

ifeq ($(PLATFORM), OrangePi_PC2)
  SRC += OrangePi.c
endif

ifeq ($(PLATFORM), OrangePi_A64)
  SRC += OrangePi.c
endif

ifeq ($(PLATFORM), OrangePi_H3)
  SRC += OrangePi.c
endif

ifeq ($(PLATFORM), OrangePi_ZERO)
  SRC += OrangePi.c
endif

OBJ	=	$(SRC:.c=.o)

all:		gpio

gpio:	$(OBJ)
	@echo [Link]
	@$(CC) -o $@ $(OBJ) $(LDFLAGS) $(LIBS)
	
.c.o:
	@echo [Compile] $<
	@$(CC) -c $(CFLAGS) $(EXTRA_CFLAGS) $< -o $@

.PHONY:	clean
clean:
	@echo "[Clean]"
	@rm -f $(OBJ) gpio *~ core tags *.bak

.PHONY:	tags
tags:	$(SRC)
	@echo [ctags]
	@ctags $(SRC)

.PHONY:	install
install:
	@echo "[Install]"
	@install -m 0755 -d	$(DESTDIR)$(PREFIX)/bin $(DESTDIR)$(PREFIX)/man/man1
	@install -m 4755 -o root -g root gpio	$(DESTDIR)$(PREFIX)/bin
	@install -m 0644 gpio.1		$(DESTDIR)$(PREFIX)/man/man1

.PHONY:	uninstall
uninstall:
	@echo "[UnInstall]"
	@rm -f $(DESTDIR)$(PREFIX)/bin/gpio
	@rm -f $(DESTDIR)$(PREFIX)/man/man1/gpio.1

.PHONY:	depend
depend:
	makedepend -Y $(SRC)

# DO NOT DELETE

gpio.o: extensions.h
extensions.o: extensions.h

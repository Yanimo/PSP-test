TARGET = Test3
OBJS = main.o common/callback.o

INCDIR =
#gcc compilers
CFLAGS = #C compiler
CXXFLAGS = $(CFLAGS) -std=c++14 -fno-rtti #C++ compiler
ASFLAGS = $(CFLAGS) #for .s files

#link cpp
LIBS += -lstdc++

#PSP codes
BUILD_PRX = 1
PSP_FW_VERSION = 500
PSP_LARGE_MEMORY = 1 #turn on 64MB 

EXTRA_TARGETS = EBOOT.PBP
PSP_EBOOT_TITLE = PSP Button Test
#PSP_EBOOT_ICON = ICON0.PNG #Icon for psp title
#PSP_EBOOT_PIC1= PIC1.png #Background Picture for psp title
#PSP_EBOOT_SND0= SND0.at3 #Sound for psp title

PSPSDK = $(shell psp-config --pspsdk-path)
include $(PSPSDK)/lib/build.mak
#############################################################################
# Makefile for building: irm
# Generated by qmake (2.01a) (Qt 4.8.5) on: Sat Jan 10 17:11:16 2015
# Project:  irm.pro
# Template: app
# Command: /usr/bin/qmake -o Makefile irm.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_WEBKIT -DQT_NO_DEBUG -DQT_SQL_LIB -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I/usr/share/qt4/mkspecs/default -I. -I/usr/include/QtCore -I/usr/include/QtGui -I/usr/include/QtSql -I/usr/include -I. -Iheaders -I.
LINK          = g++
LFLAGS        = -Wl,-O1
LIBS          = $(SUBLIBS)  -L/usr/lib64 -lQtSql -L/usr/lib64 -lQtGui -L/usr/X11R6/lib -lQtCore -lpthread 
AR            = ar cqs
RANLIB        = 
QMAKE         = /usr/bin/qmake
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
STRIP         = strip
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = sources/main.cpp \
		sources/Window.cpp \
		sources/pages.cpp \
		sources/DBFactory.cpp \
		sources/ResidentDialog.cpp \
		sources/photopreview.cpp \
		sources/typeresidentdialog.cpp moc_Window.cpp \
		moc_pages.cpp \
		moc_ResidentDialog.cpp \
		moc_typeresidentdialog.cpp
OBJECTS       = main.o \
		Window.o \
		pages.o \
		DBFactory.o \
		ResidentDialog.o \
		photopreview.o \
		typeresidentdialog.o \
		moc_Window.o \
		moc_pages.o \
		moc_ResidentDialog.o \
		moc_typeresidentdialog.o
DIST          = /usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/common/gcc-base.conf \
		/usr/share/qt4/mkspecs/common/gcc-base-unix.conf \
		/usr/share/qt4/mkspecs/common/g++-base.conf \
		/usr/share/qt4/mkspecs/common/g++-unix.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/modules/qt_webkit.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/release.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/shared.prf \
		/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		irm.pro
QMAKE_TARGET  = irm
DESTDIR       = 
TARGET        = irm

first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile $(TARGET)

$(TARGET):  $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: irm.pro  /usr/share/qt4/mkspecs/default/qmake.conf /usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/common/gcc-base.conf \
		/usr/share/qt4/mkspecs/common/gcc-base-unix.conf \
		/usr/share/qt4/mkspecs/common/g++-base.conf \
		/usr/share/qt4/mkspecs/common/g++-unix.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/modules/qt_webkit.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/release.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/shared.prf \
		/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		/usr/lib64/libQtSql.prl \
		/usr/lib64/libQtCore.prl \
		/usr/lib64/libQtGui.prl
	$(QMAKE) -o Makefile irm.pro
/usr/share/qt4/mkspecs/common/unix.conf:
/usr/share/qt4/mkspecs/common/linux.conf:
/usr/share/qt4/mkspecs/common/gcc-base.conf:
/usr/share/qt4/mkspecs/common/gcc-base-unix.conf:
/usr/share/qt4/mkspecs/common/g++-base.conf:
/usr/share/qt4/mkspecs/common/g++-unix.conf:
/usr/share/qt4/mkspecs/qconfig.pri:
/usr/share/qt4/mkspecs/modules/qt_webkit.pri:
/usr/share/qt4/mkspecs/features/qt_functions.prf:
/usr/share/qt4/mkspecs/features/qt_config.prf:
/usr/share/qt4/mkspecs/features/exclusive_builds.prf:
/usr/share/qt4/mkspecs/features/default_pre.prf:
/usr/share/qt4/mkspecs/features/release.prf:
/usr/share/qt4/mkspecs/features/default_post.prf:
/usr/share/qt4/mkspecs/features/shared.prf:
/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf:
/usr/share/qt4/mkspecs/features/warn_on.prf:
/usr/share/qt4/mkspecs/features/qt.prf:
/usr/share/qt4/mkspecs/features/unix/thread.prf:
/usr/share/qt4/mkspecs/features/moc.prf:
/usr/share/qt4/mkspecs/features/resources.prf:
/usr/share/qt4/mkspecs/features/uic.prf:
/usr/share/qt4/mkspecs/features/yacc.prf:
/usr/share/qt4/mkspecs/features/lex.prf:
/usr/share/qt4/mkspecs/features/include_source_dir.prf:
/usr/lib64/libQtSql.prl:
/usr/lib64/libQtCore.prl:
/usr/lib64/libQtGui.prl:
qmake:  FORCE
	@$(QMAKE) -o Makefile irm.pro

dist: 
	@$(CHK_DIR_EXISTS) .tmp/irm0.1.0 || $(MKDIR) .tmp/irm0.1.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/irm0.1.0/ && $(COPY_FILE) --parents headers/Window.h headers/pages.h headers/DBFactory.h headers/ResidentDialog.h headers/common.h headers/photopreview.h headers/typeresidentdialog.h .tmp/irm0.1.0/ && $(COPY_FILE) --parents sources/main.cpp sources/Window.cpp sources/pages.cpp sources/DBFactory.cpp sources/ResidentDialog.cpp sources/photopreview.cpp sources/typeresidentdialog.cpp .tmp/irm0.1.0/ && (cd `dirname .tmp/irm0.1.0` && $(TAR) irm0.1.0.tar irm0.1.0 && $(COMPRESS) irm0.1.0.tar) && $(MOVE) `dirname .tmp/irm0.1.0`/irm0.1.0.tar.gz . && $(DEL_FILE) -r .tmp/irm0.1.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


check: first

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: moc_Window.cpp moc_pages.cpp moc_ResidentDialog.cpp moc_typeresidentdialog.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_Window.cpp moc_pages.cpp moc_ResidentDialog.cpp moc_typeresidentdialog.cpp
moc_Window.cpp: headers/Window.h
	/usr/bin/moc $(DEFINES) $(INCPATH) headers/Window.h -o moc_Window.cpp

moc_pages.cpp: headers/pages.h
	/usr/bin/moc $(DEFINES) $(INCPATH) headers/pages.h -o moc_pages.cpp

moc_ResidentDialog.cpp: headers/ResidentDialog.h
	/usr/bin/moc $(DEFINES) $(INCPATH) headers/ResidentDialog.h -o moc_ResidentDialog.cpp

moc_typeresidentdialog.cpp: headers/typeresidentdialog.h
	/usr/bin/moc $(DEFINES) $(INCPATH) headers/typeresidentdialog.h -o moc_typeresidentdialog.cpp

compiler_rcc_make_all:
compiler_rcc_clean:
compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all:
compiler_uic_clean:
compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean 

####### Compile

main.o: sources/main.cpp headers/Window.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o sources/main.cpp

Window.o: sources/Window.cpp headers/Window.h \
		headers/DBFactory.h \
		headers/pages.h \
		headers/ResidentDialog.h \
		headers/typeresidentdialog.h \
		headers/common.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Window.o sources/Window.cpp

pages.o: sources/pages.cpp headers/pages.h \
		headers/Window.h \
		headers/ResidentDialog.h \
		headers/common.h \
		headers/DBFactory.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o pages.o sources/pages.cpp

DBFactory.o: sources/DBFactory.cpp headers/DBFactory.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o DBFactory.o sources/DBFactory.cpp

ResidentDialog.o: sources/ResidentDialog.cpp headers/ResidentDialog.h \
		headers/pages.h \
		headers/common.h \
		headers/photopreview.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ResidentDialog.o sources/ResidentDialog.cpp

photopreview.o: sources/photopreview.cpp headers/photopreview.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o photopreview.o sources/photopreview.cpp

typeresidentdialog.o: sources/typeresidentdialog.cpp headers/typeresidentdialog.h \
		headers/pages.h \
		headers/common.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o typeresidentdialog.o sources/typeresidentdialog.cpp

moc_Window.o: moc_Window.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_Window.o moc_Window.cpp

moc_pages.o: moc_pages.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_pages.o moc_pages.cpp

moc_ResidentDialog.o: moc_ResidentDialog.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_ResidentDialog.o moc_ResidentDialog.cpp

moc_typeresidentdialog.o: moc_typeresidentdialog.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_typeresidentdialog.o moc_typeresidentdialog.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:


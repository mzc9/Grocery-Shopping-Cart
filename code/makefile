# ==========================================================
# File:makefile
# Author: mzc
# Descriptions: make file builds for Assignment 2 - CS 162
# code referenced and modified from lecture posted in class
# ==========================================================

# ===========================
#    Needed for all builds
# ===========================

CXX = g++  			# standard variable name for compiler
CXXFLAGS = -std=c++0x		# compile flags for language version for C++
CXXFLAGS += -Wall		# turn on all warnings
CXXFLAGS += -pedantic-errors	# enforce the standard
CXXFLAGS += -g			# ensure debug is "on"


# =============================
#    Assignment specific files
# =============================


# SRC are source files
SRC1 = item.cpp
SRC2 = list.cpp
SRC3 = utils.cpp
SRC4 = shoppingCart.cpp
SRC5 = mainAssign2.cpp
SRCS = ${SRC1} ${SRC2} ${SRC3} ${SRC4} ${SRC5}

# HEADER for header files
HEADER1 = item.hpp
HEADER2 = list.hpp
HEADER3 = utils.hpp
HEADER4 = shoppingCart.hpp
HEADERS = ${HEADER1} ${HEADER2} ${HEADER3} ${HEADER4}

# executable files
PROG1 = main
PROGS = ${PROG1}

# This is the name of your document(s). 
# Edit as needed.
DOC = Reflections.pdf


# This is the name of your compressed file. 
# Edit name as needed. Keep the format.



# ==================
#      Builds 
# ==================

# make all will call this build

all:
	${CXX} ${CXXFLAGS} ${SRCS} -o ${PROG1}

# Typing 'make zip' creates the zip file for submission

zip:
	zip ${ZIP} ${SRCS} ${HEADERS} ${DOC} makefile

# make clean calls this build and will remove the executable file
clean: 
	rm -f ${PROGS} *.o main


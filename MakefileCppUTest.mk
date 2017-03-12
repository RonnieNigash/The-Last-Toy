#Set this to @ to keep the makefile quiet
SILENCE = @

#---- Outputs ----#
COMPONENT_NAME = The-Last-Toy_CppUTest
TARGET_LIB = \
	lib/lib$(COMPONENT_NAME).a
	
TEST_TARGET = \
	$(COMPONENT_NAME)_tests

#--- Inputs ----#
PROJECT_HOME_DIR = .
CPP_PLATFORM = g++

SRC_DIRS = \
	$(PROJECT_HOME_DIR)/src/\

TEST_SRC_DIRS = \
	tests\
	tests/*\

INCLUDE_DIRS =\
  .\
  $(CPPUTEST_HOME)/include\
  $(PROJECT_HOME_DIR)/include/\
  
CPPUTEST_WARNINGFLAGS += -Wall 

CPPFLAGS = -I$(CPPUTEST_HOME)/include
CXXFLAGS = -include $(CPPUTEST_HOME)/include/CppUTest/MemoryLeakDetectorNewMacros.h
CFLAGS = -include $(CPPUTEST_HOME)/include/CppUTest/MemoryLeakDetectorMallocMacros.h
LD_LIBRARIES = -L$(CPPUTEST_HOME)/cpputest_build/lib -lCppUTest -lCppUTestExt

include $(CPPUTEST_HOME)/build/MakefileWorker.mk

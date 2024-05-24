# Makefile

CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Werror -O2

# List all source files here
SRCS = main.cpp \
       IFsm.cpp \
       IState.cpp \
       IEvent.cpp \
       IEventProcessor.cpp \
       ISendEvent.cpp \
       IThread.cpp \
       ITimedEventState.cpp \
       ITimedSendEventState.cpp \
       ITimerState.cpp \
       ObjectDictionary.cpp \
       MyTimer.cpp \
       LogicalStateTranslator.cpp 

#       EventHandler.cpp

OBJS = $(SRCS:.cpp=.o)
DEPS = $(SRCS:.cpp=.d)
TARGET = program

all: $(TARGET)

-include $(DEPS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -MMD -MP -c $< -o $@

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

.PHONY: clean
clean:
	rm -f $(OBJS) $(DEPS) $(TARGET)

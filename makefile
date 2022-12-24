
CC=g++
OBJS=Animal.o Chicken.o ChickenFarm.o Cow.o CowsFarm.o Farm.o farmMarket.o Market.o Sheep.o SheepFarm.o
EXEC=CPP_FARM
DEBUG_FLAG=-g 
COMP_FLAG=-c
CLEAN=clean
$(EXEC) : $(OBJS)
	$(CC) $(DEBUG_FLAG) $(OBJS) -o $@
Animal.o: Animal.cpp Animal.h
	$(CC) $(DEBUG_FLAG) $(COMP_FLAG) $*.cpp
Chicken.o: Chicken.cpp Chicken.h Animal.h
	$(CC) $(DEBUG_FLAG) $(COMP_FLAG) $*.cpp
ChickenFarm.o: ChickenFarm.cpp ChickenFarm.h Farm.h Animal.h Chicken.h
	$(CC) $(DEBUG_FLAG) $(COMP_FLAG) $*.cpp
	
Cow.o: Cow.cpp Cow.h Animal.h
	$(CC) $(DEBUG_FLAG) $(COMP_FLAG) $*.cpp
	
CowsFarm.o: CowsFarm.cpp CowsFarm.h Farm.h Animal.h Cow.h
	$(CC) $(DEBUG_FLAG) $(COMP_FLAG) $*.cpp
	
Farm.o: Farm.cpp Farm.h Animal.h
	$(CC) $(DEBUG_FLAG) $(COMP_FLAG) $*.cpp
	
farmMarket.o: farmMarket.cpp Market.h Farm.h Animal.h CowsFarm.h Cow.h  ChickenFarm.h SheepFarm.h
	$(CC) $(DEBUG_FLAG) $(COMP_FLAG) $*.cpp
	
Market.o: Market.cpp Market.h Farm.h Animal.h CowsFarm.h Cow.h \
 ChickenFarm.h SheepFarm.h FarmExp.h
	$(CC) $(DEBUG_FLAG) $(COMP_FLAG) $*.cpp
	
Sheep.o: Sheep.cpp Sheep.h Animal.h
	$(CC) $(DEBUG_FLAG) $(COMP_FLAG) $*.cpp
	
SheepFarm.o: SheepFarm.cpp SheepFarm.h Farm.h Animal.h Sheep.h
	$(CC) $(DEBUG_FLAG) $(COMP_FLAG) $*.cpp
	
clean:
	rm -f $(OBJS) $(EXEC)

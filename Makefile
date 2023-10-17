PLAYER.HPP = Player/Player.hpp
PLAYER.CPP = Player/Player.cpp
CONTROLLER.HPP = Controller/Controller.hpp
CONTROLLER.CPP = Controller/Controller.cpp
FIELD.HPP = Field/Field.hpp
FIELD.CPP = Field/Field.cpp
CELL.HPP = Field/Cell.hpp
CELL.CPP = Field/Cell.cpp
IEVENT.HPP = Event/IEvent.hpp
IEVENT.CPP = Event/IEvent.cpp
HEALTH_EVENT.HPP = Event/HealthEvent.hpp
HEALTH_EVENT.CPP = Event/HealthEvent.cpp

game: main.o Player.o Controller.o Field.o Cell.o IEvent.o HealthEvent.o
	g++ main.o Player.o Controller.o Field.o Cell.o HealthEvent.o IEvent.o -o game

main.o: main.cpp $(PLAYER.HPP) $(CONTROLLER.CPP) $(FIELD.HPP) $(CELL.HPP) $(IEVENT.HPP) $(HEALTH_EVENT.HPP)
	g++ -c main.cpp

Player.o: $(PLAYER.CPP) $(PLAYER.HPP)
	g++ -c $(PLAYER.CPP)

Controller.o: $(CONTROLLER.CPP) $(CONTROLLER.HPP) $(PLAYER.HPP) $(FIELD.HPP) $(CELL.HPP)
	g++ -c $(CONTROLLER.CPP)

Field.o: $(FIELD.CPP) $(FIELD.HPP) $(CELL.HPP)
	g++ -c $(FIELD.CPP)

Cell.o: $(CELL.CPP) $(CELL.HPP) $(IEVENT.HPP)
	g++ -c $(CELL.CPP)

HealthEvent.o: $(IEVENT.HPP) $(HEALTH_EVENT.HPP) $(HEALTH_EVENT.CPP)
	g++ -c $(HEALTH_EVENT.CPP)

IEvent.o: $(IEVENT.HPP) $(IEVENT.CPP)
	g++ -c $(IEVENT.CPP)

clean:
	rm *.o

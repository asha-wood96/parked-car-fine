main: ParkedCar.o ParkingMeter.o PoliceOfficer.o ParkingTicket.o
    gcc -o main ParkedCar.o ParkingMeter.o PoliceOfficer.o ParkingTicket.o

ParkedCar.o:

ParkingMeter.o:

PoliceOfficer.o:

ParkingTicket.o: 

clean:
Rm main ParkedCar.o ParkingMeter.o PoliceOfficer.o ParkingTicket.o *.o

(no .h files all in main.cpp)
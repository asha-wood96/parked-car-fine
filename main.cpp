
//Final Project
//Parking Ticket Generator for Violating Cars
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;


class ParkedCar
{
private:
    string make; // data and functions for the car
    string model; 
    string color; 
    string licenseNumber; 
    int minutesParked;
    
    
public:
    ParkedCar(string mk, string md, string col, string ln, double minp) //Constructor
    {
        this -> make = mk;
        this  -> model = md;
        this  -> color = col;
        this  -> licenseNumber = ln;
        this  -> minutesParked = minp;
    }
    
    ParkedCar(ParkedCar &car)
    {
        this -> make = car.make;
        this -> model = car.model;
        this -> color = car.color;
        this -> licenseNumber = car.licenseNumber;
        this -> minutesParked = car.minutesParked;
    }
    
    ParkedCar()
    {
        make = " ";
        model = " ";
        color = " ";
        licenseNumber = " ";
        minutesParked = 0;
    }
    
    void set(string mak, string mod, string colo, string linu, double mipa)
    {
        
        this -> make = mak;
        this ->model = mod;
        this -> color = colo;
        this -> licenseNumber = linu;
        this -> minutesParked = mipa;
        
    }
    
    string getMake() const
    {
        return make;
    }
    string getModel() const
    {
        return model;
    }
    string getColor() const
    {
        return color;
    }
    string getLicenseNumber() const
    {
        return licenseNumber;
    }
    double getMinutesParked() const
    {
        return minutesParked;
    }
    
    string someString()
    {
        string newString = "Parking Violator \n\n" "Car Make: " + make + "\nCar Model: " + model
        + "\nCar Color: " + color + "\nCar License Number: " + licenseNumber
        + "\n\nAllowed Parking Time Exceeded\n\n" "Minutes Parked: " + to_string(minutesParked);
        cout << newString << endl;
        return newString;
    }
};


double baseFine = 25;
double hourlyFine;



class ParkingMeter
{
    
private:
    int  minsOfParkTime; //number of minutes of parking time purchased
    double  timeOfPurchase; //when were minutes bought
    double  expirationTime;//when does the payment expire
public:
    
    ParkingMeter(){
        this -> minsOfParkTime = 0;
    }
    ParkingMeter(double minsOfParkTime)
    {
        this -> minsOfParkTime = minsOfParkTime;
    }
    
    void setMinutesOfParkTime(double minsOfParkTime) //setter
    {
        minsOfParkTime = minsOfParkTime;
    }
    
    ParkingMeter(ParkingMeter &PM)
    {
        minsOfParkTime = PM.minsOfParkTime;
    }
    
    double getMinsOfParkTime() //getter
    {
        return minsOfParkTime;
    }
    
    string someString()
    {
        string newString = "Minutes of parking on Meter: " + to_string(minsOfParkTime) ;
        return newString;
    }
    
    bool expired()
    {
        if ( 66 - 60 < 0) //expirationParkTime - nowTime ( rand() - rand() < 0 )
            return true;
        
        else
            return false;
    }
    
    
};




class PoliceOfficer
{
private:
    string name;
    string badgeNumber;
    
    
public:
    PoliceOfficer()
    {
        name = " ";
        badgeNumber = " ";
        
    }
    PoliceOfficer(string PN, string BN)
    {
        name = PN;
        badgeNumber = BN;
    }
    
    void set(string PN, string BN)
    {
        name = PN;
        badgeNumber = BN;
    }
    
    
    string getName() const
    {
        return name;
    }
    string getBadgeNumber() const
    {
        return badgeNumber;
    }
    
    
  
};




class ParkingTicket
{
private:
    const double BASE_FINE = 25;
    const double HOURLY_FINE = 10;
    double fine;
    double hourlyFine;
    int illegalParkedHour;
    ParkedCar violater;
    ParkingMeter teller;
    PoliceOfficer issuer;
    
    
    
public:
   
    void setFine(double fine)
    {
        this -> fine = fine;
    }
    double getFine() const
    {
        return fine;
    }
    void setHourlyFine(double hourlyFine)
    {
        this -> hourlyFine = hourlyFine;
    }
    double getHourlyFine() const
    {
        return hourlyFine;
    }
    
    ParkingTicket(){
        fine = 0.0;
        
       
        
        
       }
    ParkingTicket(ParkedCar pc, ParkingMeter pm, PoliceOfficer po)
    {
        double hours =   (pc.getMinutesParked() - pm.getMinsOfParkTime() )  / 60.0;  //converts minutes to hours 
        illegalParkedHour = hours;
        
        double hourly_fine = 25.0;
        
        while (hours > 0)          //calculates parking fine 
        {
            fine += hourly_fine;
            hourly_fine = 10;
            hours--;
            
        }
       
    
        hourlyFine = fine - baseFine;
       
       // if(fine == baseFine)      //this is extraneous calculation to show the whether to print out just base fine or both base and hourly
       //{
       //cout << baseFine;
       //}
       //else
       //{
       //cout << baseFine << endl;
       //cout << hourlyFine << endl;
       //}
        
        
        
        
      
        violater = pc;
        teller = pm;
        issuer = po;
        cout << "\nReporting Patrol Officer\n\n";
        cout << "Police officer: " << po.getName() << endl << endl;
        cout << "Badge Number: " << po.getBadgeNumber() << endl << endl;
        pc.someString();
        cout << "Minutes purchased at the parking meter: " << pm.getMinsOfParkTime() << endl << endl;
    }
 
    
    void illegalParkedCar(ParkedCar PC, ParkingMeter PM, PoliceOfficer PO)
     {
     cout << "Illegal Parked Car: ";
     cout << "Car Make " << PC.getMake();
     cout << "Car Model " << PC.getModel();
     cout << "Car Color " << PC.getColor();
     cout << "Car License Number " << PC.getLicenseNumber();
     
     
    
     
     cout << "Fine Amount: $" << getFine() << endl;
     cout << "Hourly amount $" << getHourlyFine() << endl;
     cout << "Name of Police Officer: ";
     cout << PO.getName() << endl;
     cout << "Badge Number: " <<  PO.getBadgeNumber() << endl;
     
     }
    
};



ParkingTicket *createParkingTicket(ParkingMeter pm, ParkedCar pc, PoliceOfficer po)
{
   
    if (pc.getMinutesParked() - pm.getMinsOfParkTime() > 0)
    {
        return new ParkingTicket(pc,pm,po);}
    
    else {
        return NULL;
    }
}



int main()
{
    //current time
    ParkingTicket *tickets[100];
    //bool state;
    string name;
    string badge;
    PoliceOfficer PO1("Owen Card", "F783D");
    PoliceOfficer PO2("Jack Hart", "4R378");
    PoliceOfficer PO3("Max Diamond", "43U89");
  
    
    //The random number passed to parkedcar shows the minutes of parking
    ParkedCar PC1("Lamborghini", "Aventador LP 740-4 S", "black", "875I653", 61); //rand()
    ParkedCar PC2("Audi", "E-Tron GT", "gray", "45A65E3", rand());
    ParkedCar PC3("Nissan", "Skyline GTR R34", "blue", "345D343", rand());
    
    //The random number passed to parking meter shows the minutes of paid parking
    ParkingMeter PM1(60); //rand()
    ParkingMeter PM2(rand());
    ParkingMeter PM3(rand());
    
    int index = 0;
    
    ParkingTicket *pt1 = createParkingTicket(PM1, PC1, PO1);
    if (pt1 != NULL) {
        tickets[index] = pt1;
        index++;
    
        for (int i = 0; i<index; i++)
        {
        
        cout << "Base Fine: $" << baseFine << endl;
        cout << "Your hourly Fine $" << tickets[i] -> getHourlyFine() << endl;
        cout << "Your total fine is: $" << tickets[i]->getFine() << endl << endl;
        }
    }
   
    else
    {
        cout << "\nNo parking violation for " << PC1.getMake() << " " << PC1.getModel() << endl <<
        endl;
        
    }
    
 
    
    pt1 = createParkingTicket(PM2, PC2, PO2);
    if (pt1 != NULL) {
        tickets[index] = pt1;
        index++;
        
        for (int i = 0; i<index; i++)
        {
            
            cout << "Base Fine: $" << baseFine << endl;
            cout << "Your total fine is: $" << tickets[i]->getFine() << endl << endl;
            
           
        }
        
    }

    else
    {
cout << "No parking violation for " << PC2.getMake() << " " << PC2.getModel() << endl << endl;
    }
    
  
pt1 = createParkingTicket(PM3, PC3, PO3);
    if (pt1 != NULL) {
        tickets[index] = pt1;
        index++;
        
        for (int i = 0; i<index; i++){
            
            cout << "Base Fine: $" << baseFine << endl;
            //cout << "Hourly Fine $" <<
            cout << "Your total fine is: $" << tickets[i]->getFine() << endl << endl;
        

    }
    }
    else
    {
        cout << "No parking violation for " << PC3.getMake() << " " << PC3.getModel() << endl << endl;
        
    }

 

    return 0;
}


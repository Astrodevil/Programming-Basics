#pragma once
#include <fstream>
#include <string>
using namespace std;

class Name {

	string fName;
	string lName;
public:
	Name();
	Name(string fN, string lN);
	Name(const Name&);
	~Name();

	void setFName(string);
	void setLName(string);
	string getFName();
	string getLName();
	
	friend ostream& operator<<(ostream&, const Name&);
	friend ifstream& operator>>(ifstream&, Name&);
	friend ofstream& operator<<(ofstream&, Name&);
	friend istream& operator>>(istream&, Name&);
};

class Date {
	int day;
	int month;
	int year;

public:
	Date();
	Date(int, int, int);
	Date(const Date&);
	~Date() {};
	
	void setDay(int);
	void setMonth(int);
	void setYear(int);
	int getDay();
	int getMonth();
	int getYear();

	friend ostream& operator<<(ostream&, const Date&);
	friend ifstream& operator>>(ifstream&, Date&);
	friend ofstream& operator<<(ofstream&, const Date&);
	friend istream& operator>>(istream&, Date&);
};

class mTime {
	int hour;
	int min;
	int sec;

public:
	mTime();
	mTime(int, int, int);
	mTime(const mTime&);
	~mTime() {};

	void setHour(int);
	void setMin(int);
	void setSec(int);
	int getHour();
	int getMin();
	int getSec();

	friend ostream& operator<<(ostream&, const mTime&);
	friend ifstream& operator>>(ifstream&, mTime&);
	friend ofstream& operator<<(ofstream&, const mTime&);
	friend istream& operator>>(istream&, mTime&);
};

class Service {
	string source;
	string destination;
	float distance; //in km
	Date bookingDate;
	mTime bookingTime;
	int status; // 0 for pending, 1 if complete, 3 if cancelled
	float fuelrate;
	int cId; // Customer Id who booked the ride
	int dId; // Driver Id
	int vId; // vehicle Id
	int sId;  //service id
	float fare;  //fare

public:
	Service();
	Service(string, string, float, Date, mTime, int, float, int, int, int, int, float);
	~Service();

	void setSource(string);
	void setDestination(string);
	void setDistance(float);
	void setBookingDate(Date);
	void setBookingTime(mTime);
	void setStatus(int);
	void setFuelRate(float);
	void setCId(int);
	void setDId(int);
	void setVId(int);
	void setSId(int);
	void setFare(float);

	string getSource();
	string getDestination();
	float getDistance();
	Date getBookingDate();
	mTime getBookingTime();
	int getStatus();
	float getFuelRate();
	int getCId();
	int getDId();
	int getVId();
	int getSId();
	float getFare();

	friend ostream& operator<<(ostream&, Service&);
	friend ifstream& operator>>(ifstream&, Service&);
	friend ofstream& operator<<(ofstream&, const Service&);
	friend istream& operator>>(istream&, Service&);
};
class Ride : public Service {
	int noofPassengers; // false for pending, true if complete
	string rideType; // intercity, intracity
	float DriverRanking; // 0 to 5 scale (worst to best)
	float VehicleRanking; // 0 to 5 scale (worst to best)

public:
	Ride(string, string, float, Date, mTime, int, float, int, int, int, int,float, int, string, float, float);
	
	void setNoofPassengers(int);
	void setRideType(string);
	void setDRank(float);
	void setVRank(float);

	int getNoofPassengers();
	string getRideType();
	float getDRank();
	float getVRank();

	~Ride();

	friend ostream& operator<<(ostream&, Ride&);
	friend ifstream& operator>>(ifstream&, Ride&);
	friend ofstream& operator<<(ofstream&, const Ride&);
	friend istream& operator>>(istream&, Ride&);

};
class Delivery : public Service {
	float goodsWeight; // Weight of goods in Kg
	string goodsType; //type of goods food, furniture, petroleum, chemicals, etc.

public:
	Delivery(string, string, float, Date, mTime, int, float, int, int, int, int, float, float, string);
	~Delivery();

	void setGoodsWeight(float);
	void setGoodsType(string);

	float getGoodsWeight();
	string getGoodsType();

	friend ostream& operator<<(ostream&, Delivery&);
	friend ifstream& operator>>(ifstream&, Delivery&);
	friend ofstream& operator<<(ofstream&, const Delivery&);
	friend istream& operator>>(istream&, Delivery&);
};

class Person {
private:
	Name pName;
	Date DOB;
	int Age;
	int Nid;
public:
	Person();
	Person(Name, Date, int, int);
	Person(const Person&);
	~Person() {};

	void setName(Name);
	void setDOB(Date);
	void setAge(int);
	void setID(int);

	Name getName();
	Date getDOB();
	int getAge();
	int getID();

	friend ostream& operator<<(ostream&, const Person&);
	friend istream& operator>>(istream&, Person&);
	friend ofstream& operator<<(ofstream&, Person&);
	friend ifstream& operator>>(ifstream&, Person&);
};
class Customer : public Person {
private:
	int cId;
	int noofBookings;
	Service** bookingHistory;
public:
	Customer();
	Customer(Name, Date, int, int, int, Service**,int);
	Customer(const Customer&);
	~Customer();

	void setCId(int);
	void setHistorry(Service**,int);

	int findHistory(int, int&);
	void loadHistory(int);

	int getCId();
	int getNoofServices();
	Service** getHistory();

	friend ostream& operator<<(ostream&, Customer&);
	friend istream& operator>>(istream&, Customer&);
	friend ifstream& operator>>(ifstream&, Customer&);
	friend ofstream& operator<<(ofstream&, Customer&);

};
class Driver : public Person {
private:
	int dId;
	char** LicencesList;
	int noofLicences;
	float overallRanking;
	float salary;
	int experience;
	int status; // 1 for free, 2 if booked and 3 if cancelled
	Service** serviceHistory;
	int noofServices;

public:
	Driver();
	Driver(Name, Date, int, int, int, char**, int, float, float, int, int, Service**,int);
	Driver(const Driver&);
	~Driver();

	void setDId(int);
	void setLicenceList(char**,int);
	void setNoofLicences(int);
	void setRanking(float);
	void setSalary(float);
	void setExperience(int);
	void setStatus(int);
	void setHistory(Service**,int);

	int getDId();
	char** getLicenceList();
	int getNoofLicences();
	float getRanking();
	float getSalary();
	int getExperience();
	int getStatus();
	Service** getHistory();
	int getNoofServices();

	int findHistory(int, int&);
	void loadHistory(int);

	friend ostream& operator<<(ostream&, Driver&);
	friend istream& operator>>(istream&, Driver&);
	friend ofstream& operator<<(ofstream&, Driver&);
	friend ifstream& operator>>(ifstream&, Driver&);
};
class Feature {
	int fId;
	string description;
	float cost;
public:
	Feature(int, string, float);
	~Feature();

	void setFId(int);
	void setDescription(string);
	void setCost(float);

	int getFId();
	string getDescription();
	float getCost();

	friend ostream& operator<<(ostream&, const Feature&);
	friend istream& operator>>(istream&, Feature&);
	friend ofstream& operator<<(ofstream&, Feature&);
	friend ifstream& operator>>(ifstream&, Feature&);
};

class Vehicle {
	int vId;
	int registrationNo;
	float avgMileage;
	string LicenceType; // License required for driving the vehicle
	bool status; // false for free, true if booked in a service already
	string fueltype;
	float overallRanking;
	Date manufacturingDate;
	Feature* list;
	Service** serviceHistory;
	int noofServices;
	int noofFeatures;

public:
	Vehicle(int, int, float, string, bool, string, float, Date, Feature*, Service**, int, int);
	
	int getVId();
	int getRegNo();
	int getAvgMil();
	string getLicenceType();
	bool getStatus();
	string getFuelType();
	int getOverallRanking();
	Date getManuDate();
	Feature* getFeatList();
	int getNoofFeatures();
	Service** getServiceHistory();
	int getNoofServices();
	
	void setVId(int);
	void setRegNo(int);
	void setAvgMil(int);
	void setLicenceType(string);
	void setStatus(bool);
	void setFuelType(string);
	void setOverallRanking(int);
	void setManuDate(Date);
	void setFeatList(Feature*, int);
	void setNoofFeatures(int);
	void setServiceHistory(Service**, int);

	int findHistory(int, int&);
	void loadHistory(int);

	~Vehicle();


	friend ostream& operator<<(ostream&, Vehicle&);
	friend istream& operator>>(istream&, Vehicle&);
	friend ofstream& operator<<(ofstream&, Vehicle&);
	friend ifstream& operator>>(ifstream&, Vehicle&);
};
//add Complete Hierarchy of vehicles based on their types and functions

//Ride Vehicle
class RideVehicle : public Vehicle {
public:
	RideVehicle(int, int, float, string, bool, string, float, Date, Feature*, Service**, int, int);
};

//Transport Vehicle
class TransportVehicle : public Vehicle {
public:
	TransportVehicle(int, int, float, string, bool, string, float, Date, Feature*, Service**, int, int);
};

//RideTrans Vehicle
class RideTransVehicle : public Vehicle {
public:
	RideTransVehicle(int, int, float, string, bool, string, float, Date, Feature*, Service**, int, int);
};

//SmallRide Vehicle
class SmallRideVehicle : public RideVehicle
{
public:
	SmallRideVehicle(int, int, float, string, bool, string, float, Date, Feature*, Service**, int, int);
};

//LargeRide Vehicle
class LargeRideVehicle : public RideVehicle
{
public:
	LargeRideVehicle(int, int, float, string, bool, string, float, Date, Feature*, Service**, int, int);
};

//LightTrans Vehicle
class LightTransVehicle : public TransportVehicle
{
public:
	LightTransVehicle(int, int, float, string, bool, string, float, Date, Feature*, Service**, int, int);
};

//HeavyTrans Vehicle
class HeavyTransVehicle : public TransportVehicle
{
public:
	HeavyTransVehicle(int, int, float, string, bool, string, float, Date, Feature*, Service**, int, int);
};

class TMS
{
	int totalCustomers;
	int totaldDrivers;
	int totalVehicles;
	int totalRides;
	int totalDeliveries;
	
	int availableCustomers;
	int availableDrivers;
	int availableVehicles;
	int availableRides;
	int availableDeliveries;

	Customer** Customers;
	Driver** Drivers;
	Vehicle** Vehicles;
	Ride** Rides;
	Delivery** Deliveries;

public:
	TMS(int, int, int);
	~TMS();

	void addCustomer();
	void loadCustomers();
	void displayAllCustomers();
	void displayCustomerWithID();
	void displayCustomerWithSameVehicle();
	void displayAllCancelledServicesByCustomer();

	void loadDrivers();
	void addDriver();
	bool isDriverFound(int);
	void removeDriver();
	void displayAllDrivers();
	void displayDriversWithRank4_5();
	void displayDriversWithRank();
	void displayDriverWithID();
	void displayDriverWithMultipleLicence();
	void displayDriverWhoDeliveredOnSameDate();
	void writeDrivers();

	void loadVehicles();
	void addVehicle();
	bool isVehicleFound(int);
	void removeVehicle();
	void displayVehicleWithID();
	void displayAllVehicles();
	void writeVehicle();

	void loadRides();
	void addRide();
	void displayAllRides();
	void displayRideOfUser(int);
	void displayRideOfDriver(int);
	void displayRideOfVehicle(int);
	void completeRide();
	void cancelRide();
	void writeRides();
	void displayRideWithID();

	void loadDeliveries();
	void addDelivery();
	void displayAllDeliveries();
	void displayDeliveryOfUser(int);
	void displayDeliveryOfDriver(int);
	void displayDeliveryOfVehicle(int);
	void completeDelivery();
	void cancelDelivery();
	void writeDelivery();
	void displayDeliveryWithID();

	void displayAllPendingServicesOnDate();
	void displayAllPendingServicesbyDriver();
};

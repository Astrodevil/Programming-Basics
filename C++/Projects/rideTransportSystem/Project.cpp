#include "Project.h"
#include <cstring>
#include <string>
#include <iostream>
using namespace std;

//Name
Name::Name() {
	fName = " ";
	lName = " ";
}

Name::Name(string fN, string lN) {
	fName = fN;
	lName = lN;

}

Name::Name(const Name& copy) {
	fName = copy.fName;
	lName = copy.lName;
}

string Name::getFName() {
	return fName;
}

string Name::getLName() {
	return lName;
}

void Name::setFName(string fN) {
	fName = fN;
}

void Name::setLName(string lN) {
	lName = lN;
}

ostream& operator<<(ostream& out, const Name& n) {
	out << n.fName << " " << n.lName << endl;
	return out;
}

ifstream& operator>>(ifstream& fin, Name& n)
{
	string fN;
	string lN;

	fin >> fN;
	fin >> lN;

	n.setFName(fN);
	n.setLName(lN);

	return fin;
}


ofstream& operator<<(ofstream& fout, Name& n) {
	fout << n.fName << " " << n.lName << endl;
	return fout;
}


istream& operator>>(istream& in, Name& n)
{
	string fN;
	string lN;

	cout << "Enter First Name: ";
	in >> fN;
	cin.ignore();


	cout << "Enter Last Name: ";
	in >> lN;
	cin.ignore();

	n.setFName(fN);
	n.setLName(lN);


	return in;
}



Name::~Name(){
	//
}


//Date
Date::Date() {
	day = 0;
	month = 0;
	year = 0;
}

Date::Date(int d, int m, int y) {
	day = d;
	month = m;
	year = y;
}

Date::Date(const Date& date) {
	day = date.day;
	month = date.month;
	year = date.year;
}

void Date::setDay(int d) {
	day = d;
}
void Date::setMonth(int m) {
	month = m;
}
void Date::setYear(int y) {
	year = y;
}

int Date::getDay() {
	return day;
}
int Date::getMonth() {
	return month;
}
int Date::getYear() {
	return year;
}
ostream& operator<<(ostream& out, const Date& date) {
	out << date.day << " / " << date.month << " / " << date.year << endl;
	return out;
}

ifstream& operator>>(ifstream& fin, Date& d)
{
	int day, month, year;

	fin >> day;
	fin >> month;
	fin >> year;

	d.setDay(day);
	d.setMonth(month);
	d.setYear(year);

	return fin;
}

ofstream& operator<<(ofstream& fout, const Date& date) {
	fout << date.day << " " << date.month << " " << date.year << endl;
	return fout;
}


istream& operator>>(istream& in, Date& d)
{
	int day, month, year;

	cout << "Enter day: ";
	in >> day;

	cout << "Enter month: ";
	in >> month;

	cout << "Enter year: ";
	in >> year;

	d.setDay(day);
	d.setMonth(month);
	d.setYear(year);

	return in;
}



//mTime
mTime::mTime() {
	hour = 0;
	min = 0;
	sec = 0;
}

mTime::mTime(int h, int m, int s) {
	hour = h;
	min = m;
	sec = s;
}

mTime::mTime(const mTime& time) {
	hour = time.hour;
	min = time.min;
	sec = time.sec;
}

void mTime::setHour(int h) {
	hour = h;
}
void mTime::setMin(int m) {
	min = m;
}
void mTime::setSec(int s) {
	sec = s;
}

int mTime::getHour() {
	return hour;
}
int mTime::getMin() {
	return min;
}
int mTime::getSec() {
	return sec;
}

ostream& operator<<(ostream& out, const mTime& Time) {
	out << Time.hour << " : " << Time.min << " : " << Time.sec << endl;
	return out;
}

istream& operator>>(istream& in, mTime& Time) {
	int h, m, s;

	cout << "Enter hour: ";
	in >> h;

	cout << "Enter minute: ";
	in >> m;

	cout << "Enter second: ";
	in >> s;

	Time.setSec(s);
	Time.setMin(m);
	Time.setHour(h);


	return in;
}


ofstream& operator<<(ofstream& fout, const mTime& Time) {
	fout << Time.hour << " " << Time.min << " " << Time.sec << endl;
	return fout;
}

ifstream& operator>>(ifstream& in, mTime& Time) {
	int h, m, s;

	in >> h;
	in >> m;
	in >> s;

	Time.setSec(s);
	Time.setMin(m);
	Time.setHour(h);


	return in;
}

//Service

Service::Service() {
	source = " ";
	destination = " ";
	distance = 0;
	bookingDate = Date();
	bookingTime = mTime();
	status = 0;
	fuelrate = 0;
	cId = 0;
	dId = 0;
	vId = 0;
	sId = 0;
}

Service::Service(string s, string d, float dis, Date bDate, mTime bTime, int st, float fRate, int cID, int dID, int vID , int sID, float fare) {
	source = s;
	destination = d;
	distance = dis;
	bookingDate = bDate;
	bookingTime = bTime;
	status = st;
	fuelrate = fRate;
	cId = cID;
	dId = dID;
	vId = vID;
	sId = sID;
	this->fare = fare;
}

Service::~Service() {

	//
}


void Service::setSource(string source) {
	this->source = source;
}							

void Service::setDestination(string destination) {
	this->destination = destination;
}

void Service::setDistance(float distance) {
	this->distance = distance;
}

void Service::setBookingDate(Date date) {
	bookingDate = date;
}

void Service::setBookingTime(mTime time) {
	bookingTime = time;
}

void Service::setStatus(int status) {
	this->status = status;
}

void Service::setFuelRate(float rate) {
	this->fuelrate = rate;
}

void Service::setCId(int cid) {
	this->cId = cid;
}

void Service::setVId(int vid) {
	this->vId = vid;
}

void Service::setDId(int did) {
	this->dId = did;
}

void Service::setSId(int id) {
	this->sId = id;
}

void Service::setFare(float fare) {
	this->fare = fare;
}



string Service::getSource() {
	return source;
}

string Service::getDestination() {
	return destination;
}

float Service::getDistance() {
	return distance;
}

Date Service::getBookingDate() {
	return bookingDate;
}

mTime Service::getBookingTime() {
	return bookingTime;
}

int Service::getStatus() {
	return status;
}

float Service::getFuelRate() {
	return fuelrate;
}

int Service::getCId() {
	return cId;
}

int Service::getVId() {
	return vId;
}

int Service::getDId() {
	return dId;
}

int Service::getSId() {
	return sId;
}

float Service::getFare() {
	return fare;
}

ostream& operator<<(ostream& out, Service& service) {
	out << "------------------Ride Information------------------\n";
	out << "Source: " << service.getSource() << endl;
	out << "Destination: "<< service.getDestination() << endl;
	out << "Distance: " << service.getDistance() << endl;
	out << "Booking Date: " << service.getBookingDate() << endl;
	out << "Booking Time: " << service.getBookingTime() << endl;
	out << "Status (0: pending, 1: completed ): " << service.getStatus() << endl;
	out << "Customer ID: " << service.getCId() << endl;
	out << "Driver ID: " << service.getDId() << endl;
	out << "Vehicle ID: " << service.getVId() << endl;
	out << "Fare: " << service.getFare() << endl;

	out << "----------------------------------------------------\n";
	return out;
}

istream& operator>>(istream& in, Service& service) {

	string source, destination;
	float distance;
	Date date;
	mTime mtime;
	int status;
	int cid, did, vid;

	cout << "Enter Source: ";
	in >> source;
	in.ignore();

	cout << "Enter Destiantion: ";
	in >> destination;
	in.ignore();

	cout << "Enter distance (in KMs): ";
	in >> distance;

	cout << "Enter Booking Date: \n";
	in >> date;

	cout << "Enter Booking Time: \n";
	in >> mtime;

	cout << "Enter Status (0 for pending, 1 if complete): ";
	in >> status;

	cout << "Enter Customer ID: ";
	in >> cid;

	cout << "Enter Driver ID: ";
	in >> did;

	cout << "Enter Vehicle ID: ";
	in >> vid;

	srand(time(0));
	int sid = rand();

	service.setSource(source);
	service.setDestination(destination);
	service.setDistance(distance);
	service.setBookingDate(date);
	service.setBookingTime(mtime);
	service.setStatus(status);
	service.setCId(cid);
	service.setDId(did);
	service.setVId(vid);
	service.setSId(sid);
	service.setFare(distance * 21);

	return in;
}


ofstream& operator<<(ofstream& fout, Service& service) {

	fout << service.getSource() << endl;
	fout << service.getDestination() << endl;
	fout << service.getDistance() << endl;
	fout << service.getBookingDate();
	fout << service.getBookingTime();
	fout << service.getStatus() << endl;
	fout << service.getCId() << endl;
	fout << service.getDId() << endl;
	fout << service.getVId() << endl;
	fout << service.getSId() << endl;
	fout << service.getFare() << endl;

	return fout;
}

ifstream& operator>>(ifstream& fin, Service& service) {

	string source, destination;
	float distance, fare;
	Date date;
	mTime time;
	int status;
	int cid, did, vid, sid;

	fin >> source;

	fin >> destination;

	fin >> distance;

	fin >> date;

	fin >> time;

	fin >> status;

	fin >> cid;

	fin >> did;

	fin >> vid;

	fin >> sid;

	fin >> fare;

	service.setSource(source);
	service.setDestination(destination);
	service.setDistance(distance);
	service.setBookingDate(date);
	service.setBookingTime(time);
	service.setStatus(status);
	service.setCId(cid);
	service.setDId(did);
	service.setVId(vid);
	service.setSId(sid);
	service.setFare(fare);

	return fin;
}


//Ride

Ride::Ride(string s = " ", string d = " ", float dis = 0, Date bDate = Date(), mTime bTime = mTime(), int st = 0, float fRate = 0, int cID = 0, int dID = 0, int vID = 0, int sID = 0, float fare = 0, int noP = 0, string type = " ", float dRanking = 0, float vRanking = 0) :Service(s, d, dis, bDate, bTime, st, fRate, cID, dID, vID, sID, fare) {
	noofPassengers = noP;
	rideType = type;
	DriverRanking = dRanking;
	VehicleRanking = vRanking;
}

void Ride::setNoofPassengers(int no) {
	noofPassengers = no;
}


void Ride::setRideType(string type) {
	rideType = type;
}

void Ride::setDRank(float rank) {
	DriverRanking = rank;
}

void Ride::setVRank(float rank) {
	VehicleRanking = rank;
}

int Ride::getNoofPassengers() {
	return noofPassengers;
}


string Ride::getRideType() {
	return rideType;
}

float Ride::getDRank() {
	return DriverRanking;
}

float Ride::getVRank() {
	return VehicleRanking;
}


Ride::~Ride() {
	//
}



ostream& operator<<(ostream& out, Ride& ride) {
	out << "------------------Ride Information------------------\n";
	out << "Source: " << ride.getSource() << endl;
	out << "Destination: " << ride.getDestination() << endl;
	out << "Distance: " << ride.getDistance() << endl;
	out << "Booking Date: " << ride.getBookingDate();
	out << "Booking Time: " << ride.getBookingTime();
	out << "Status: " << ride.getStatus() << endl;
	out << "Customer ID: " << ride.getCId() << endl;
	out << "Driver ID: " << ride.getDId() << endl;
	out << "Vehicle ID: " << ride.getVId() << endl;
	out << "No. of Passengers: " << ride.noofPassengers << endl;
	out << "Ride type: " << ride.rideType << endl;
	out << "Driver Ranking: " << ride.DriverRanking << endl;
	out << "Vehicle Ranking: " << ride.VehicleRanking << endl;
	out << "Fare: " << ride.getFare() << endl;
	out << "Service ID: " << ride.getSId() << endl;

	out << "----------------------------------------------------\n";
	return out;
}

istream& operator>>(istream& in, Ride& ride) {

	string source, destination, type;
	
	float distance, fare;
	Date date;
	mTime mtime;
	int status;
	int cid, did, vid, sid;

	cout << "Enter Source: ";
	in >> source;
	in.ignore();

	cout << "Enter Destiantion: ";
	in >> destination;
	in.ignore();

	cout << "Enter distance (in KMs): ";
	in >> distance;

	cout << "Enter Booking Date: \n";
	in >> date;

	cout << "Enter Booking Time: \n";
	in >> mtime;

	//cout << "Enter Status (0 for pending, 1 if complete): ";
	//in >> status;

	cout << "Enter Customer ID: ";
	in >> cid;

	cout << "Enter Driver ID: ";
	in >> did;

	cout << "Enter Vehicle ID: ";
	in >> vid;

	cout << "Enter No of Passengers: ";
	in >> ride.noofPassengers;

	cout << "Enter ride type (intercity, intracity): ";
	in >> type;

	/*cout << "Enter Driver ranking (0 to 5 scale (worst to best)): ";
	in >> ride.DriverRanking;

	cout << "Enter Vehiclle ranking (0 to 5 scale (worst to best)): ";
	in >> ride.VehicleRanking;*/

	srand(time(0));
	sid = rand();

	ride.setSource(source);
	ride.setDestination(destination);
	ride.setDistance(distance);
	ride.setBookingDate(date);
	ride.setBookingTime(mtime);
	ride.setStatus(0);
	ride.setCId(cid);
	ride.setDId(did);
	ride.setVId(vid);
	ride.setRideType(type);
	ride.setSId(sid);
	ride.setDRank(0);
	ride.setVRank(0);
	ride.setFare(distance * 21);

	return in;
}


ofstream& operator<<(ofstream& fout, Ride& ride) {

	fout << ride.getSource() << endl;
	fout << ride.getDestination() << endl;
	fout << ride.getDistance() << endl;
	fout << ride.getBookingDate();
	fout << ride.getBookingTime();
	fout << ride.getStatus() << endl;
	fout << ride.getCId() << endl;
	fout << ride.getDId() << endl;
	fout << ride.getVId() << endl;
	fout << ride.getNoofPassengers() << endl;
	fout << ride.getRideType() << endl;
	fout << ride.getDRank() << endl;
	fout << ride.getVRank() << endl;
	fout << ride.getFare() << endl;
	fout << ride.getSId() << endl << endl;

	return fout;
}

ifstream& operator>>(ifstream& fin, Ride& ride) {

	string source, destination, type;
	float distance, fare;
	Date date;
	mTime time;
	int status;
	int cid, did, vid, sid;

	fin >> source;

	fin >> destination;

	fin >> distance;

	fin >> date;

	fin >> time;

	fin >> status;

	fin >> cid;

	fin >> did;

	fin >> vid;

	fin >> ride.noofPassengers;

	fin >> type;

	fin >> ride.DriverRanking;

	fin >> ride.VehicleRanking;

	fin >> fare;

	fin >> sid;

	ride.setSource(source);
	ride.setDestination(destination);
	ride.setDistance(distance);
	ride.setBookingDate(date);
	ride.setBookingTime(time);
	ride.setStatus(status);
	ride.setCId(cid);
	ride.setDId(did);
	ride.setVId(vid);
	ride.setFare(fare);
	ride.setSId(sid);

	ride.setRideType(type);

	return fin;
}


Delivery::Delivery(string s = " ", string d = " ", float dis = 0, Date bDate = Date(), mTime bTime = mTime(), int st = 0, float fRate = 0, int cID = 0, int dID = 0, int vID = 0, int sID = 0, float fare = 0, float weight = 0, string type = " ") :Service(s, d, dis, bDate, bTime, st, fRate, cID, dID, vID, sID, fare) {

	goodsWeight = weight;
	goodsType = type;

}

void Delivery::setGoodsWeight(float weight) {
	goodsWeight = weight;
}

void Delivery::setGoodsType(string type = " ") {
	goodsType = type;
}

float Delivery::getGoodsWeight() {
	return goodsWeight;
}

string Delivery::getGoodsType() {
	return goodsType;
}

Delivery::~Delivery() {
	//
}



ostream& operator<<(ostream& out, Delivery& delivery) {
	out << "------------------Delivery Information------------------\n";
	out << "Source: " << delivery.getSource() << endl;
	out << "Destination: " << delivery.getDestination() << endl;
	out << "Distance: " << delivery.getDistance() << endl;
	out << "Booking Date: " << delivery.getBookingDate();
	out << "Booking Time: " << delivery.getBookingTime();
	out << "Status: " << delivery.getStatus() << endl;
	out << "Customer ID: " << delivery.getCId() << endl;
	out << "Driver ID: " << delivery.getDId() << endl;
	out << "Vehicle ID: " << delivery.getVId() << endl;
	out << "Goods Weight: " << delivery.getGoodsWeight() << endl;
	out << "Goods Type: " << delivery.getGoodsType() << endl;
	out << "Fare: " << delivery.getFare() << endl;
	out << "Service ID: " << delivery.getSId() << endl;

	out << "--------------------------------------------------------\n";
	return out;
}

istream& operator>>(istream& in, Delivery& delivery) {

	string source, destination, goodsType;
	float distance, weight;
	Date date;
	mTime mtime;
	int status;
	int cid, did, vid, sid;

	cout << "Enter Source: ";
	in >> source;
	in.ignore();

	cout << "Enter Destiantion: ";
	in >> destination;
	in.ignore();

	cout << "Enter distance (in KMs): ";
	in >> distance;

	cout << "Enter Booking Date: \n";
	in >> date;

	cout << "Enter Booking Time: \n";
	in >> mtime;

	/*cout << "Enter Status (0 for pending, 1 if complete): ";
	in >> status;*/

	cout << "Enter Customer ID: ";
	in >> cid;

	cout << "Enter Driver ID: ";
	in >> did;

	cout << "Enter Vehicle ID: ";
	in >> vid;

	cout << "Enter Goods Weight: ";
	in >> weight;
	in.ignore();

	cout << "Enter Goods Type: ";
	in >> goodsType;

	srand(time(0));
	sid = rand();

	delivery.setSource(source);
	delivery.setDestination(destination);
	delivery.setDistance(distance);
	delivery.setBookingDate(date);
	delivery.setBookingTime(mtime);
	delivery.setStatus(0);
	delivery.setCId(cid);
	delivery.setDId(did);
	delivery.setVId(vid);
	delivery.setSId(sid);
	delivery.setFare(distance * 11);

	delivery.setGoodsWeight(weight);
	delivery.setGoodsType(goodsType);
	
	return in;
}


ofstream& operator<<(ofstream& fout, Delivery& delivery) {

	fout << delivery.getSource() << endl;
	fout << delivery.getDestination() << endl;
	fout << delivery.getDistance() << endl;
	fout << delivery.getBookingDate();
	fout << delivery.getBookingTime();
	fout << delivery.getStatus() << endl;
	fout << delivery.getCId() << endl;
	fout << delivery.getDId() << endl;
	fout << delivery.getVId() << endl;
	fout << delivery.getGoodsWeight() << endl;
	fout << delivery.getGoodsType() << endl;
	fout << delivery.getFare() << endl << endl;
	fout << delivery.getSId() << endl << endl;

	return fout;
}

ifstream& operator>>(ifstream& fin, Delivery& delivery) {

	string source, destination, goodsType;
	float distance, weight, fare;
	Date date;
	mTime time;
	int status;
	int cid, did, vid, sid;

	fin >> source;

	fin >> destination;

	fin >> distance;

	fin >> date;

	fin >> time;

	fin >> status;

	fin >> cid;

	fin >> did;

	fin >> vid;

	fin >> weight;

	fin >> goodsType;

	fin >> fare;

	fin >> sid;

	delivery.setSource(source);
	delivery.setDestination(destination);
	delivery.setDistance(distance);
	delivery.setBookingDate(date);
	delivery.setBookingTime(time);
	delivery.setStatus(status);
	delivery.setCId(cid);
	delivery.setDId(did);
	delivery.setVId(vid);
	delivery.setSId(sid);
	delivery.setFare(fare);
	delivery.setGoodsWeight(weight);
	delivery.setGoodsType(goodsType);

	return fin;
}


//Person

Person::Person() {
	pName = Name();
	DOB = Date();
	Age = 0;
	Nid = 0;
}

Person::Person(Name name, Date dob, int age, int id) {
	pName = name;
	DOB = dob;
	Age = age;
	Nid = id;
}

Person::Person(const Person& person) {
	pName = person.pName;
	DOB = person.DOB;
	Age = person.Age;
	Nid = person.Nid;
}

void Person::setName(Name name) {
	pName = name;
}
void Person::setDOB(Date dob) {
	DOB = dob;
}
void Person::setAge(int age) {
	Age = age;
}
void Person::setID(int id) {
	Nid = id;
}

Name Person::getName() {
	return pName;
}

Date Person::getDOB() {
	return DOB;
}
int Person::getAge() {
	return Age;
}
int Person::getID() {
	return Nid;
}

ostream& operator<<(ostream& out, const Person& person) {
	out << "-------- Person Information --------" << endl;
	out << "Person ID: " << person.Nid << endl;
	out << "Name: " << person.pName << endl;
	out << "DOB: " << person.DOB << endl;
	out << "Age: " << person.Age << endl;
	out << "------------------------------------" << endl;
	return out;
}

istream& operator>>(istream& in, Person& person) {
	int id, age;
	Name name;
	
	Date dob;
	srand(time(0));
	id = rand();
	
	in>>name;


	cout << "Enter Date of Birth: \n";
	in >> dob;
	cout << "Enter age: ";
	in >> age;
	
	person.setID(id);
	person.setName(name);
	person.setDOB(dob);
	person.setAge(age);

	return in;
}

ofstream& operator<<(ofstream& fout, Person& person) {
	fout << "-------- Person Information --------" << endl;
	fout << "Person ID: " << person.Nid << endl;
	fout << "Name: " << person.pName << endl;
	fout << "DOB: " << person.DOB << endl;
	fout << "Age: " << person.Age << endl;
	fout << "------------------------------------" << endl;
	return fout;
}

ifstream& operator>>(ifstream& fin, Person& person) {
	int id, age;
	Name name;
	Date dob;

	fin >> id;

	fin >> name;


	fin >> dob;
	fin >> age;

	person.setID(id);
	person.setName(name);
	person.setDOB(dob);
	person.setAge(age);

	return fin;
}


//Customer

Customer::Customer() {
	cId = 0;
	noofBookings = 0;
	bookingHistory = nullptr;
	bookingHistory = new Service * [1];
}

Customer::Customer(Name name, Date dob, int age, int id, int cID, Service** history,int noofbookings) :Person(name, dob, age, id) {
	cId = cID;
	bookingHistory = nullptr;
	bookingHistory = new Service * [1];
	noofBookings = noofbookings;

	if (history != nullptr || noofbookings > 0) {
		bookingHistory[0] = new Service[noofbookings];
		for (int i = 0; i < noofbookings; i++)
		{
			bookingHistory[0][i] = history[0][i];
		}
	}
}

Customer::Customer(const Customer& customer) {
	cId = customer.cId;
	bookingHistory = nullptr;
	noofBookings = customer.noofBookings;
	bookingHistory = new Service * [1];

	if (customer.bookingHistory != nullptr || customer.noofBookings > 0) {
		bookingHistory[0] = new Service[customer.noofBookings];
		for (int i = 0; i < customer.noofBookings; i++)
		{
			bookingHistory[0][i] = customer.bookingHistory[0][i];
		}
	}
}

void Customer::setCId(int id) {
	cId = id;
}
void Customer::setHistorry(Service** history,int size) {
	noofBookings = size;
	if (history != nullptr || size > 0) {
		bookingHistory[0] = new Service[size];
		for (int i = 0; i < size; i++)
		{
			bookingHistory[0][i] = history[0][i];
		}
	}
}

int Customer::getCId() {
	return cId;
}

int Customer::getNoofServices() {
	return noofBookings;
}

Service** Customer::getHistory() {
	return bookingHistory;
}

Customer::~Customer() {
	if (bookingHistory != nullptr) {

		for (int i = 0; i < noofBookings; i++)
		{
			delete[] bookingHistory[i];
		}
		delete[] bookingHistory;
	}
}

int Customer::findHistory(int id,int &noofrides) {
	int total = 0;
	int found = 0;
	int found1 = 0;
	Delivery* deliveries = nullptr;
	Ride* rides = nullptr;
	ifstream dFile("deliveries.txt");
	if (dFile.is_open()) {
		dFile >> total;
		if (total > 0) {
			deliveries = new Delivery[total];
			for (int i = 0; i < total; i++)
			{
				dFile >> deliveries[i];
			}
		}
	}
	dFile.close();
	for (int i = 0; i < total; i++)
	{
		if (deliveries[i].getCId() == id) {
			found++;
		}
	}


	ifstream rFile("rides.txt");
	if (rFile.is_open()) {
		rFile >> total;
		if (total > 0) {
			rides = new Ride[total];
			for (int i = 0; i < total; i++)
			{
				rFile >> rides[i];
			}
		}
	}
	rFile.close();

	for (int i = 0; i < total; i++)
	{
		if (rides[i].getCId() == id) {
			found1++;
		}
	}
	noofrides = found1;

	delete[] deliveries;
	delete[] rides;
	deliveries = nullptr;
	rides = nullptr;

	return found;
}
void Customer::loadHistory(int id) {
	int noofRides = 0;
	int noofDeliveries = findHistory(id, noofRides);
	int total = noofDeliveries + noofRides;
	int noofentries = 0;

	noofBookings = total;

	bookingHistory = new Service*[1];
	bookingHistory[0] = new Service[total];

	Ride* temp1 = nullptr;
	Delivery* temp2 = nullptr;

	ifstream rFile("rides.txt");
	if (rFile.is_open()) {
		rFile >> noofentries;
		temp1 = new Ride[noofentries];
		for (int i = 0; i < noofentries; i++)
		{
			rFile >> temp1[i];
		}
	}
	rFile.close();
	int j = 0;
	for (int i = 0; i < noofentries; i++)
	{
		if (temp1[i].getCId() == id) {
			bookingHistory[0][j++] = temp1[i];
		}
	}



	ifstream dFile("deliveries.txt");
	if (dFile.is_open()) {
		dFile >> noofentries;
		temp2 = new Delivery[noofentries];
		for (int i = 0; i < noofentries; i++)
		{
			dFile >> temp2[i];
		}
	}
	dFile.close();
	for (int i = 0; i < noofentries; i++)
	{
		if (temp2[i].getCId() == id) {
			bookingHistory[0][j++] = temp2[i];
		}
	}
	delete[] temp1;
	delete[] temp2;
	temp1 = nullptr;
	temp2 = nullptr;
}

ostream& operator<<(ostream& out, Customer& customer) {
	out << "------------- Customer Information -------------------" << endl;
	out << "Name: " << customer.getName();
	out << "Customer ID: "<<customer.getCId() << endl;
	out << "Person ID: "<<customer.getID() << endl;
	out << "DOB: " << customer.getDOB();
	out << "Age: " << customer.getAge() << endl;
	customer.loadHistory(customer.cId);
	out << "Total Services: " << customer.noofBookings << endl;
	out << "------------------------------------------------------" << endl;
	return out;

}

istream& operator>>(istream& in, Customer& customer) {

	int age, pid, cid;
	string fN, lN;
	Date dob;
	Name name;

	in >> name;

	cout << "Enter Date of Birth: \n";
	in >> dob;

	cout << "Enter age: ";
	in >> age;

	srand(time(0));

	pid = rand();
	cid = rand();

	customer.setName(name);
	customer.setDOB(dob);
	customer.setAge(age);
	customer.setID(pid);
	customer.setCId(cid);
	customer.setHistorry(nullptr,0);

	return in;
}


ifstream& operator>>(ifstream& fin, Customer& cust)
{

	int cid, pid;
	string fN, lN;
	Name name;
	Date dob;


	fin >> cid;
	fin >> pid;
	fin >> name;

	fin >> dob;

	cust.setCId(cid);
	cust.setID(pid);
	cust.setName(name);
	cust.setDOB(dob);

	return fin;
}

ofstream& operator<<(ofstream& fout, Customer& cust)
{
	fout << cust.getCId() << endl;
	fout << cust.getID() << endl;
	fout << cust.getName();
	fout << cust.getDOB();
	fout << cust.getAge() << endl << endl;

	return fout;
}



//Driver

Driver::Driver() {
	dId = 0;
	LicencesList = nullptr;
	noofLicences = 0;
	overallRanking = 0;
	salary = 0;
	experience = 0;
	status = 1;
	noofServices = 0;
	serviceHistory = nullptr;
	serviceHistory = new Service * [1];
	LicencesList = new char* [1];
}

Driver::Driver(Name name, Date dob, int age, int id, int dID, char** list, int totalLicence, float rank, float salary, int experience, int status, Service** history,int noofservices = 0) :Person(name, dob, age, id) {
	dId = dID;
	LicencesList = nullptr;
	if (list != nullptr) {

		LicencesList = new char* [totalLicence];
		for (int i = 0; i < totalLicence; i++)
		{
			LicencesList[i] = new char[strlen(list[i]) + 1];
			strcpy(LicencesList[i], list[i]);
		}

	}
	noofLicences = totalLicence;
	overallRanking = rank;
	this->salary = salary;
	this->experience = experience;
	this->status = status;
	this->noofServices = noofservices;
	serviceHistory = new Service * [1];

	if (history!=nullptr||noofservices > 0) {
		serviceHistory[0] = new Service[noofservices];
		for (int i = 0; i < noofservices; i++)
		{
			serviceHistory[0][i] = history[0][i];
		}
	}
	LicencesList = new char* [1];
	//LicencesList[0] = new char [20];
}

Driver::Driver(const Driver& driver) {
	dId = driver.dId;

	LicencesList = nullptr;
	if (driver.LicencesList != nullptr) {

		LicencesList = new char* [driver.noofLicences];
		for (int i = 0; i < driver.noofLicences; i++)
		{
			LicencesList[i] = new char[strlen(driver.LicencesList[i]) + 1];
			strcpy(LicencesList[i], driver.LicencesList[i]);
		}

	}
	noofLicences = driver.noofLicences;
	overallRanking = driver.overallRanking;
	this->salary = driver.salary;
	this->experience = driver.experience;
	this->status = driver.status;
	this->noofServices = driver.noofServices;
	serviceHistory = new Service * [1];

	if (driver.noofServices> 0 || driver.serviceHistory!=nullptr) {
		serviceHistory[0] = new Service[driver.noofServices];
		for (int i = 0; i < driver.noofServices; i++)
		{
			serviceHistory[0][i] = driver.serviceHistory[0][i];
		}
	}
	if (noofLicences > 0) {
		LicencesList = new char* [noofLicences];
		for (int i = 0; i < noofLicences; i++)
		{
			LicencesList[i] = new char[20];
		}
	}
}

Driver::~Driver() {
	if (LicencesList != nullptr) {

		for (int i = 0; i < noofLicences; i++)
		{
			delete[] LicencesList[i];
		}
		delete[] LicencesList;
		LicencesList = nullptr;
	}

	if (serviceHistory != nullptr) {

		for (int i = 0; i < noofServices; i++)
		{
			delete[] serviceHistory[i];
		}
		delete[] serviceHistory;
	}
	if (LicencesList != nullptr) {
		for (int i = 0; i < noofLicences; i++)
		{
			delete[] LicencesList[i];
		}
		delete[] LicencesList;
	}
}

void Driver::setDId(int id) {
	dId = id;
}
void Driver::setLicenceList(char** list,int size) {
	noofLicences = size;
	if (list != nullptr) {

		LicencesList = new char* [size];
		for (int i = 0; i < size; i++)
		{
			LicencesList[i] = new char[strlen(list[i]) + 1];
			strcpy(LicencesList[i], list[i]);
		}

	}
}
void Driver::setNoofLicences(int no) {
	noofLicences = no;
}
void Driver::setRanking(float rank) {
	overallRanking = rank;
}
void Driver::setSalary(float salary) {
	this->salary = salary;
}
void Driver::setExperience(int exp) {
	experience = exp;
}
void Driver::setStatus(int sts) {
	status = sts;
}

void Driver::setHistory(Service** history,int size) {
	noofServices = size;
	if (history !=nullptr||size > 0) {
		serviceHistory[0] = new Service[size];
		for (int i = 0; i < size; i++)
		{
			serviceHistory[0][i] = history[0][i];
		}
	}
}

int Driver::getDId() {
	return	dId;
}
char** Driver::getLicenceList() {
	return LicencesList;
}
int Driver::getNoofLicences() {
	return noofLicences;
}
float Driver::getRanking() {
	return overallRanking;
}
float Driver::getSalary() {
	return salary;
}
int Driver::getExperience() {
	return experience;
}
int Driver::getStatus() {
	return status;
}

Service** Driver::getHistory() {
	return serviceHistory;
}

int Driver::getNoofServices() {
	return noofServices;
}

int Driver::findHistory(int id, int& noofrides) {
	int total = 0;
	int found = 0;
	int found1 = 0;
	Delivery* deliveries = nullptr;
	Ride* rides = nullptr;

	ifstream dFile("deliveries.txt");
	if (dFile.is_open()) {
		dFile >> total;
		if (total > 0) {
			deliveries = new Delivery[total];
			for (int i = 0; i < total; i++)
			{
				dFile >> deliveries[i];
			}
		}
	}
	dFile.close();
	for (int i = 0; i < total; i++)
	{
		if (deliveries[i].getDId() == id) {
			found++;
		}
	}


	ifstream rFile("rides.txt");
	if (rFile.is_open()) {
		rFile >> total;
		if (total > 0) {
			rides = new Ride[total];
			for (int i = 0; i < total; i++)
			{
				rFile >> rides[i];
			}
		}
	}
	rFile.close();

	for (int i = 0; i < total; i++)
	{
		if (rides[i].getDId() == id) {
			found1++;
		}
	}
	noofrides = found1;

	delete[] deliveries;
	delete[] rides;
	deliveries = nullptr;
	rides = nullptr;

	return found;
}
void Driver::loadHistory(int id) {
	int noofRides = 0;
	int noofDeliveries = findHistory(id, noofRides);
	int total = noofDeliveries + noofRides;
	int noofentries = 0;

	noofServices = total;

	serviceHistory = new Service * [1];
	serviceHistory[0] = new Service[total];

	Ride* temp1 = nullptr;
	Delivery* temp2 = nullptr;

	ifstream rFile("rides.txt");
	if (rFile.is_open()) {
		rFile >> noofentries;
		temp1 = new Ride[noofentries];
		for (int i = 0; i < noofentries; i++)
		{
			rFile >> temp1[i];
		}
	}
	rFile.close();
	int j = 0;
	for (int i = 0; i < noofentries; i++)
	{
		if (temp1[i].getDId() == id) {
			serviceHistory[0][j++] = temp1[i];
		}
	}



	ifstream dFile("deliveries.txt");
	if (dFile.is_open()) {
		dFile >> noofentries;
		temp2 = new Delivery[noofentries];
		for (int i = 0; i < noofentries; i++)
		{
			dFile >> temp2[i];
		}
	}
	dFile.close();
	for (int i = 0; i < noofentries; i++)
	{
		if (temp2[i].getDId() == id) {
			serviceHistory[0][j++] = temp2[i];
		}
	}
	delete[] temp1;
	delete[] temp2;
	temp1 = nullptr;
	temp2 = nullptr;
}


ostream& operator<<(ostream& out, Driver& driver) {
	out << "------------- Driver Information -------------------" << endl;
	out << "Name: " << driver.getName();
	out << "Driver ID: " << driver.getDId() << endl;
	out << "Person ID: " << driver.getID() << endl;
	out << "DOB: " << driver.getDOB();
	out << "Age: " << driver.getAge() << endl;
	out << "No of Licences: " << driver.getNoofLicences() << endl;
	out << "Licence List: ";
	for (int i = 0; i < driver.getNoofLicences(); i++)
	{
		out << driver.getLicenceList()[i] << ", ";
	}
	out << endl;
	out << "Ranking: " << driver.getRanking() << endl;
	out << "Salary: " << driver.getSalary() << endl;
	out << "Status (1:free, 2: booked, 3: cancelled): " << driver.getStatus() << endl;
	 
	driver.loadHistory(driver.dId);
	out << "Total Services: " << driver.noofServices << endl;

	out << "----------------------------------------------------" << endl;

	return out;

}

istream& operator>>(istream& in, Driver& driver) {

	Name name;
	Date dob;
	int pid, did, age, noofLicences, status, experience;

	float ranking, salary;

	in >> name;

	cout << "Enter Date of Birth: \n";
	in >> dob;

	cout << "Enter age: ";
	in >> age;

	cout << "No. of Licences: ";
	in >> noofLicences;

	char** Licences = new char* [noofLicences];

	for (int i = 0; i < noofLicences; i++)
	{
		Licences[i] = new char[20];
	}

	for (int i = 0; i < noofLicences; i++)
	{
		cout << "Enter Licence " << i + 1 << ": ";
		in >> Licences[i];
		in.ignore();
	}

	cout << "Enter ranking: ";
	in >> ranking;

	cout << "Enter salary: ";
	in >> salary;

	cout << "Enter experience: ";
	in >> experience;

	cout << "Enter status (1 for free, 2 if booked and 3 if canceled): ";
	in >> status;

	srand(time(0));

	pid = rand();
	did = rand();

	driver.setName(name);
	driver.setDOB(dob);
	driver.setAge(age);
	driver.setID(pid);
	driver.setDId(did);
	driver.setHistory(nullptr, 0);
	driver.setNoofLicences(noofLicences);
	driver.setLicenceList(Licences, noofLicences);
	driver.setRanking(ranking);
	driver.setSalary(salary);
	driver.setStatus(status);
	driver.setExperience(experience);

	for (int i = 0; i < noofLicences; i++)
	{
		delete[] Licences[i];
	}
	delete[] Licences;

	return in;
}


ofstream& operator<<(ofstream& fout, Driver& driver) {

	fout << driver.getDId() << endl;
	fout << driver.getID() << endl;
	fout << driver.getName();
	fout << driver.getDOB();
	fout << driver.getAge() << endl;
	fout << driver.getNoofLicences() << endl;
	for (int i = 0; i < driver.getNoofLicences(); i++)
	{
		fout << driver.getLicenceList()[i] <<" ";
	}
	fout << endl;
	fout << driver.getRanking() << endl;
	fout << driver.getSalary() << endl;
	fout << driver.getExperience() << endl;
	fout << driver.getStatus() << endl << endl;

	//licences, history

	return fout;
}


ifstream& operator>>(ifstream& fin, Driver& driver) {

	Name name;
	Date dob;
	int pid, did, age, noofLicences, status, experience;

	float ranking, salary;

	fin >> did;

	fin >> pid;

	fin >> name;

	fin >> dob;

	fin >> age;

	fin >> noofLicences;

	char** Licences = new char* [noofLicences];

	for (int i = 0; i < noofLicences; i++)
	{
		Licences[i] = new char[20];
	}

	for (int i = 0; i < noofLicences; i++)
	{
		fin >> Licences[i];
	}

	fin >> ranking;

	fin >> salary;

	fin >> experience;

	fin >> status;

	driver.setName(name);
	driver.setDOB(dob);
	driver.setAge(age);
	driver.setID(pid);
	driver.setDId(did);
	driver.setHistory(nullptr, 0);
	driver.setNoofLicences(noofLicences);
	driver.setLicenceList(Licences, noofLicences);
	driver.setRanking(ranking);
	driver.setSalary(salary);
	driver.setStatus(status);
	driver.setExperience(experience);

	for (int i = 0; i < noofLicences; i++)
	{
		delete[] Licences[i];
	}
	delete[] Licences;

	//licences & history
	return fin;
}


//Feature 

Feature::Feature(int fid = 0, string desc = " ", float cost = 0) {
	this->fId = fid;
	description = desc;
	this->cost = cost;
}

void Feature::setFId(int id) {
	fId = id;
}

void Feature::setDescription(string desc) {
	description = desc;
}
void Feature::setCost(float cost) {
	this->cost = cost;
}

int Feature::getFId() {
	return fId;
}

string Feature::getDescription() {
	return description;
}

float Feature::getCost() {
	return cost;
}


Feature::~Feature() {
	//
}

ostream& operator<<(ostream& out, const Feature&feat)
{
	cout << "Feature ID: " << feat.fId << endl;
	cout << "Description: " << feat.description << endl;
	cout << "Cost: " << feat.cost << endl;

	return out;
}

istream& operator>>(istream& in, Feature& feat)
{
	cout << "Enter Feature ID: ";
	in >> feat.fId;

	cout << "Enter Feature Description (MAX 50 characters): ";
	in >> feat.description;
	in.ignore();

	cout << "Enter Feature Cost: ";
	in >> feat.cost;

	return in;
}


ofstream& operator<<(ofstream& fout, Feature& feat)
{
	fout << feat.fId << endl;
	fout << feat.description << endl;
	fout << feat.cost << endl;

	return fout;
}

ifstream& operator>>(ifstream& fin, Feature& feat)
{
	fin >> feat.fId;

	fin >> feat.description;

	fin >> feat.cost;

	return fin;
}


//Vehicle

Vehicle::Vehicle(int vId = 0, int regNo = 0, float avgMil = 0, string licenceType = " ", bool sts = false, string fuel = " ", float ranking = 0, Date manuDate = Date(), Feature* list = nullptr, Service** history = nullptr,int noofservices = 0, int nooffeat = 0) {
	this->vId = vId;
	registrationNo = regNo;
	avgMileage = avgMil;

	LicenceType = licenceType;
	status = sts;

	fueltype = fuel;
	overallRanking = ranking;
	manufacturingDate = manuDate;

	noofFeatures = nooffeat;

	this->list = nullptr;
	if (list != nullptr) {
		
		this->list = new Feature[nooffeat];
		for (int i = 0; i < nooffeat; i++)
		{
			this->list[i] = list[i];
		}
	}
	noofServices = noofservices;
	serviceHistory = new Service * [1];
	if (history != nullptr||noofservices>0) {

		serviceHistory[0] = new Service[noofservices];

		for (int i = 0; i < noofservices; i++)
		{
			serviceHistory[0][i] = history[0][i];
		}

	}
}

Vehicle::~Vehicle() {
	delete[] list;
	list = nullptr;

	if (serviceHistory != nullptr) {

		for (int i = 0; i < noofServices; i++)
		{
			delete[] serviceHistory[i];
		}
		delete[] serviceHistory;
	}
}

int Vehicle::getVId() {
	return vId;
}

int Vehicle::getRegNo() {
	return registrationNo;
}

int Vehicle::getAvgMil() {
	return avgMileage;
}

string Vehicle::getLicenceType() {
	return LicenceType;
}

bool Vehicle::getStatus() {
	return status;
}

string Vehicle::getFuelType() {
	return fueltype;
}

int Vehicle::getOverallRanking() {
	return overallRanking;
}

Date Vehicle::getManuDate() {
	return manufacturingDate;
}

Feature* Vehicle::getFeatList() {
	return list;
}

int Vehicle::getNoofFeatures() {
	return noofFeatures;
}

Service** Vehicle::getServiceHistory() {
	return serviceHistory;
}

int Vehicle::getNoofServices() {
	return noofServices;
}

void Vehicle::setVId(int id) {
	vId = id;
}

void Vehicle::setRegNo(int no) {
	registrationNo = no;
}

void Vehicle::setAvgMil(int mil) {
	avgMileage = mil;
}


void Vehicle::setFuelType(string type) {
	fueltype = type;
}

void Vehicle::setLicenceType(string type) {
	LicenceType = type;
}

void Vehicle::setStatus(bool sts) {
	status = sts;
}

void Vehicle::setOverallRanking(int ranking) {
	overallRanking = ranking;
}

void Vehicle::setManuDate(Date date) {
	manufacturingDate = date;
}

void Vehicle::setNoofFeatures(int no) {
	noofFeatures = no;
}

void Vehicle::setFeatList(Feature*fList,int no) {
	noofFeatures = no;

	this->list = nullptr;
	if (fList != nullptr) {

		this->list = new Feature[no];
		for (int i = 0; i < no; i++)
		{
			this->list[i] = fList[i];
		}
	}
}

void Vehicle::setServiceHistory(Service**services,int no) {
	noofServices = no;
	serviceHistory = new Service * [1];
	if (services != nullptr || no > 0) {

		serviceHistory[0] = new Service[no];

		for (int i = 0; i < no; i++)
		{
			serviceHistory[0][i] = services[0][i];
		}

	}
}


int Vehicle::findHistory(int id, int& noofrides) {
	int total = 0;
	int found = 0;
	int found1 = 0;
	Delivery* deliveries = nullptr;
	Ride* rides = nullptr;

	ifstream dFile("deliveries.txt");
	if (dFile.is_open()) {
		dFile >> total;
		if (total > 0) {
			deliveries = new Delivery[total];
			for (int i = 0; i < total; i++)
			{
				dFile >> deliveries[i];
			}
		}
	}
	dFile.close();
	for (int i = 0; i < total; i++)
	{
		if (deliveries[i].getVId() == id) {
			found++;
		}
	}


	ifstream rFile("rides.txt");
	if (rFile.is_open()) {
		rFile >> total;
		if (total > 0) {
			rides = new Ride[total];
			for (int i = 0; i < total; i++)
			{
				rFile >> rides[i];
			}
		}
	}
	rFile.close();

	for (int i = 0; i < total; i++)
	{
		if (rides[i].getVId() == id) {
			found1++;
		}
	}
	noofrides = found1;

	delete[] deliveries;
	delete[] rides;
	deliveries = nullptr;
	rides = nullptr;

	return found;
}
void Vehicle::loadHistory(int id) {
	int noofRides = 0;
	int noofDeliveries = findHistory(id, noofRides);
	int total = noofDeliveries + noofRides;
	int noofentries = 0;

	noofServices = total;

	serviceHistory = new Service * [1];
	serviceHistory[0] = new Service[total];

	Ride* temp1 = nullptr;
	Delivery* temp2 = nullptr;

	ifstream rFile("rides.txt");
	if (rFile.is_open()) {
		rFile >> noofentries;
		temp1 = new Ride[noofentries];
		for (int i = 0; i < noofentries; i++)
		{
			rFile >> temp1[i];
		}
	}
	rFile.close();
	int j = 0;
	for (int i = 0; i < noofentries; i++)
	{
		if (temp1[i].getVId() == id) {
			serviceHistory[0][j++] = temp1[i];
		}
	}



	ifstream dFile("deliveries.txt");
	if (dFile.is_open()) {
		dFile >> noofentries;
		temp2 = new Delivery[noofentries];
		for (int i = 0; i < noofentries; i++)
		{
			dFile >> temp2[i];
		}
	}
	dFile.close();
	for (int i = 0; i < noofentries; i++)
	{
		if (temp2[i].getVId() == id) {
			serviceHistory[0][j++] = temp2[i];
		}
	}
	delete[] temp1;
	delete[] temp2;
	temp1 = nullptr;
	temp2 = nullptr;
}


ostream& operator<<(ostream& out, Vehicle& vehicle)
{
	out << "---------------Vehicle Information---------------\n";
	out << "Vehicle ID: " << vehicle.vId << endl;
	out << "Registration No.: " << vehicle.registrationNo << endl;
	out << "Average Mileage: " << vehicle.avgMileage << endl;
	out << "Licence Type: " << vehicle.LicenceType << endl;
	out << "Status (false for free, true if booked): " << vehicle.status << endl;
	out << "Fuel Type: " << vehicle.fueltype << endl;
	out << "Overall Ranking: " << vehicle.overallRanking << endl;
	out << "Manufactured Date: "<< vehicle.manufacturingDate;
	out << "No of Features: " << vehicle.noofFeatures << endl;
	for (int i = 0; i < vehicle.noofFeatures; i++)
	{
		out << "Feature " << i + 1 << ": \n";
		out << "Feature ID: " << vehicle.list[i].getFId() << endl;
		out << "Feature Description: " << vehicle.list[i].getDescription() << endl;
		out << "Feature Cost: " << vehicle.list[i].getCost() << endl;
	}

	vehicle.loadHistory(vehicle.vId);
	out << "Total Services: " << vehicle.noofServices << endl;

	cout << "-------------------------------------------------\n";
	return out;
}


istream& operator>>(istream& in, Vehicle& vehicle)
{
	string fType, lType, Description;
	int vid, regNo, avgMil, rank, noofFeatures;
	bool status;
	Date date;
	int fId;
	float cost;

	cout << "Enter vehicle ID: ";
	in >> vid;

	cout << "Enter Registration No.: ";
	in >> regNo;

	cout << "Enter Average Mileage: ";
	in >> avgMil;

	cout << "Enter Licence Type: ";
	in >> lType;
	in.ignore();

	cout << "Enter Status (0 for free, 1 if booked): ";
	in >> status;

	cout << "Enter Fuel Type: ";
	in >> fType;
	in.ignore();

	cout << "Enter Overall Ranking: ";
	in >> rank;

	cout << "Enter Manufactured Date: \n";
	in >> date;

	cout << "Enter No of Features: ";
	in >> noofFeatures;

	Feature* list = new Feature[noofFeatures];

	for (int i = 0; i < noofFeatures; i++)
	{
		cout << "Enter Feature " << i + 1 << ": \n";
		cout << "Enter feature ID: ";
		in >> fId;
		in.ignore();
		cout << "Enter feature Description: ";
		in >> Description;
		in.ignore();

		cout << "Enter feature cost: ";
		in >> cost;
		list[i].setFId(fId);
		list[i].setDescription(Description);
		list[i].setCost(cost);
	}

	vehicle.setVId(vid);
	vehicle.setRegNo(regNo);
	vehicle.setAvgMil(avgMil);
	vehicle.setLicenceType(lType);
	vehicle.setFuelType(fType);
	vehicle.setStatus(status);
	vehicle.setOverallRanking(rank);
	vehicle.setManuDate(date);

	vehicle.setFeatList(list,noofFeatures);
	vehicle.setServiceHistory(nullptr, 0);

	return in;
}


ofstream& operator<<(ofstream& fout, Vehicle& vehicle)
{
	fout << vehicle.vId << endl;
	fout << vehicle.registrationNo << endl;
	fout << vehicle.avgMileage << endl;
	fout << vehicle.LicenceType << endl;
	fout << vehicle.status << endl;
	fout << vehicle.fueltype << endl;
	fout << vehicle.overallRanking << endl;
	fout << vehicle.manufacturingDate;
	fout << vehicle.noofFeatures << endl;
	for (int i = 0; i < vehicle.noofFeatures; i++)
	{
		fout << vehicle.list[i].getFId() << " " << vehicle.list[i].getCost() << " " << vehicle.list[i].getDescription() << endl;
		fout << endl;
	}

	return fout;
}

ifstream& operator>>(ifstream& fin, Vehicle& vehicle)
{
	int noofFeat;
	string fType, lType, desc;
	int fid;
	float cost;

	fin >> vehicle.vId;

	fin >> vehicle.registrationNo;

	fin >> vehicle.avgMileage;

	fin >> lType;

	fin >> vehicle.status;

	fin >> fType;

	fin >> vehicle.overallRanking;

	fin >> vehicle.manufacturingDate;

	fin >> vehicle.noofFeatures;
	Feature* list = new Feature[vehicle.noofFeatures];

	for (int i = 0; i < vehicle.noofFeatures; i++)
	{
		fin >> fid;
		fin >> cost;
		fin >> desc;
		list[i].setFId(fid);
		list[i].setCost(cost);
		list[i].setDescription(desc);
	}

	vehicle.setLicenceType(lType);
	vehicle.setFuelType(fType);
	vehicle.setNoofFeatures(vehicle.noofFeatures);
	vehicle.setFeatList(list, vehicle.noofFeatures);
	delete[] list;
	list = nullptr;

	return fin;
}

//Ride Vehicle
RideVehicle::RideVehicle(int vId = 0, int regNo = 0, float avgMil = 0, string licenceType = " ", bool sts = false, string fuel = " ", float ranking = 0, Date manuDate = Date(), Feature* list = nullptr, Service** history = nullptr, int noofservices = 0, int nooffeat = 0) :Vehicle(vId, regNo, avgMil, licenceType, sts, fuel, ranking, manuDate, list, history, noofservices, nooffeat) {

}

//Transport Vehicle
TransportVehicle::TransportVehicle(int vId = 0, int regNo = 0, float avgMil = 0, string licenceType = " ", bool sts = false, string fuel = " ", float ranking = 0, Date manuDate = Date(), Feature* list = nullptr, Service** history = nullptr, int noofservices = 0, int nooffeat = 0) : Vehicle(vId, regNo, avgMil, licenceType, sts, fuel, ranking, manuDate, list, history, noofservices, nooffeat) {

}

//RideTrans Vehicle
RideTransVehicle::RideTransVehicle(int vId = 0, int regNo = 0, float avgMil = 0, string licenceType = " ", bool sts = false, string fuel = " ", float ranking = 0, Date manuDate = Date(), Feature* list = nullptr, Service** history = nullptr, int noofservices = 0, int nooffeat = 0) : Vehicle(vId, regNo, avgMil, licenceType, sts, fuel, ranking, manuDate, list, history, noofservices, nooffeat) {

}

//SmallRide Vehicle
SmallRideVehicle::SmallRideVehicle(int vId = 0, int regNo = 0, float avgMil = 0, string licenceType = " ", bool sts = false, string fuel = " ", float ranking = 0, Date manuDate = Date(), Feature* list = nullptr, Service** history = nullptr, int noofservices = 0, int nooffeat = 0) : RideVehicle(vId, regNo, avgMil, licenceType, sts, fuel, ranking, manuDate, list, history, noofservices, nooffeat) {

}

//LargeRide Vehicle
LargeRideVehicle::LargeRideVehicle(int vId = 0, int regNo = 0, float avgMil = 0, string licenceType = " ", bool sts = false, string fuel = " ", float ranking = 0, Date manuDate = Date(), Feature* list = nullptr, Service** history = nullptr, int noofservices = 0, int nooffeat = 0) : RideVehicle(vId, regNo, avgMil, licenceType, sts, fuel, ranking, manuDate, list, history, noofservices, nooffeat) {

}


//LightTrans Vehicle
LightTransVehicle::LightTransVehicle(int vId = 0, int regNo = 0, float avgMil = 0, string licenceType = " ", bool sts = false, string fuel = " ", float ranking = 0, Date manuDate = Date(), Feature* list = nullptr, Service** history = nullptr, int noofservices = 0, int nooffeat = 0) : TransportVehicle(vId, regNo, avgMil, licenceType, sts, fuel, ranking, manuDate, list, history, noofservices, nooffeat) {

}

//HeavyTrans Vehicle
HeavyTransVehicle::HeavyTransVehicle(int vId = 0, int regNo = 0, float avgMil = 0, string licenceType = " ", bool sts = false, string fuel = " ", float ranking = 0, Date manuDate = Date(), Feature* list = nullptr, Service** history = nullptr, int noofservices = 0, int nooffeat = 0) : TransportVehicle(vId, regNo, avgMil, licenceType, sts, fuel, ranking, manuDate, list, history, noofservices, nooffeat) {

}

//TMS

TMS::TMS(int customers = 15, int drivers = 10, int vehicles = 20) {

	this->totalCustomers = customers;
	this->totaldDrivers = drivers;
	this->totalVehicles = vehicles;
	totalRides = 1000;
	totalDeliveries = 1000;

	availableCustomers = 0;
	availableDrivers = 0;
	availableVehicles = 0;
	availableRides = 0;
	availableDeliveries = 0;

	Customers = new Customer * [1];
	Customers[0] = new Customer[customers];

	Drivers = new Driver * [1];
	Drivers[0] = new Driver[drivers];

	Vehicles = new Vehicle * [1];
	Vehicles[0] = new Vehicle[vehicles];

	Rides = new Ride * [1];
	Rides[0] = new Ride[totalRides];

	Deliveries = new Delivery * [1];
	Deliveries[0] = new Delivery[totalDeliveries];

	loadCustomers();
	loadDrivers();
	loadVehicles();
	loadRides();
	loadDeliveries();
}

TMS::~TMS() {
	//for (int i = 0; i < totalCustomers; i++)
	//{
	//	delete[] Customers[i];
	//}
	//delete[] Customers;
	//Customers = nullptr;

	//for (int i = 0; i < totaldDrivers; i++)
	//{
	//	delete[] Drivers[i];
	//}
	//delete[] Drivers;
	//Drivers = nullptr;

	//for (int i = 0; i < totalVehicles; i++)
	//{
	//	delete[] Vehicles[i];
	//}
	//delete[] Vehicles;
	//Vehicles = nullptr;

}



void TMS::loadCustomers() {
	ifstream file("customers.txt");
	if (file.is_open()) {
		if (file) {
			file >> availableCustomers;

			for (int i = 0; i < availableCustomers; i++)
			{
				file >> Customers[0][i];
			}

		}
	}
	file.close();

}

void TMS::displayRideOfUser(int id) {
	for (int i = 0; i < availableRides; i++)
	{
		if (Rides[0][i].getCId() == id) {
			cout << Rides[0][i];
		}
	}
}

void TMS::displayRideOfDriver(int id) {
	for (int i = 0; i < availableRides; i++)
	{
		if (Rides[0][i].getDId() == id) {
			cout << Rides[0][i];
		}
	}
}


void TMS::displayDeliveryOfUser(int id) {
	for (int i = 0; i < availableDeliveries; i++)
	{
		if (Deliveries[0][i].getCId() == id) {
			cout << Deliveries[0][i];
		}
	}
}

void TMS::displayDeliveryOfDriver(int id) {
	for (int i = 0; i < availableDeliveries; i++)
	{
		if (Deliveries[0][i].getDId() == id) {
			cout << Deliveries[0][i];
		}
	}
}

void TMS::displayAllCustomers() {
	cout << "Total Customers: " << availableCustomers << endl;
	for (int i = 0; i < availableCustomers; i++)
	{
		int id = Customers[0][i].getCId();
		cout << Customers[0][i];
		if (Customers[0][i].getNoofServices() > 0) {

			displayRideOfUser(id);
			displayDeliveryOfUser(id);
		}
		cout << "\n";
	}
}


void TMS::displayCustomerWithID() {
	int id;
	cout << "Enter Customer ID: ";
	cin >> id;
	for (int i = 0; i < availableCustomers; i++)
	{
		int custId = Customers[0][i].getCId();
		if (id == custId) {
			cout << Customers[0][i];
			displayRideOfUser(custId);
			displayDeliveryOfUser(custId);
			cout << "\n";
		}
	}

}


void TMS::displayCustomerWithSameVehicle() {
	int id;
	cout << "Enter vehicle ID: ";
	cin >> id;

	for (int i = 0; i < availableCustomers; i++)
	{
		for (int j = 0; j < availableRides; j++)
		{
			int cid = Rides[0][j].getCId();
			int id = Customers[0][i].getCId();
			if (cid==id) 
			{
				cout << Customers[0][i];
				//displayRideOfUser(custId);
				//displayDeliveryOfUser(custId);
				cout << "\n";
			}
		}
	}

}


void TMS::displayAllCancelledServicesByCustomer() {
	int id;
	cout << "Enter customer ID: ";
	cin >> id;
	for (int i = 0; i <availableRides; i++)
	{
		if (Rides[0][i].getCId() == id) {
			cout << Rides[0][i];
		}
	}
	for (int i = 0; i < availableDeliveries; i++)
	{
		if (Deliveries[0][i].getCId() == id) {
			cout << Deliveries[0][i];
		}
	}
}


void TMS::addCustomer()
{

	Customer newCustomer;
	cin >> newCustomer;

	loadCustomers();
	Customers[0][availableCustomers++] = newCustomer;

	ofstream cFile("customers.txt");
	if (cFile.is_open()) {
		cFile << availableCustomers << endl;

		for (int i = 0; i < availableCustomers; i++)
		{
			cFile << Customers[0][i];
		}
		cout << "\nPerson ID: " << newCustomer.getID() << endl;
		cout << "Customer ID: " << newCustomer.getCId() << endl;
		cout << "\nSuccess 200. Customer Added Successfully!\n";
	}
	else {
		cout << "Error opening file customers.txt!\n";
	}
	cFile.close();
}



void TMS::loadDrivers() {
	ifstream file("drivers.txt");
	if (file.is_open()) {
		if (file) {
			file >> availableDrivers;

			for (int i = 0; i < availableDrivers; i++)
			{
				file >> Drivers[0][i];
			}

		}
	}
	file.close();

}

void TMS::writeDrivers() {
	ofstream dFile("drivers.txt");
	if (dFile.is_open()) {
		dFile << availableDrivers << endl;

		for (int i = 0; i < availableDrivers; i++)
		{
			dFile << Drivers[0][i];
		}
	}
	else {
		cout << "Error opening file drivers.txt!\n";
	}
	dFile.close();
}

void TMS::addDriver()
{

	Driver newDriver;
	cin >> newDriver;

	loadDrivers();
	Drivers[0][availableDrivers++] = newDriver;
	writeDrivers();
	cout << "\nPerson ID: " << newDriver.getID() << endl;
	cout << "Customer ID: " << newDriver.getDId() << endl;
	cout << "\nSuccess 200. Driver Added Successfully!\n";
}


void TMS::displayAllDrivers() {
	cout << "Total Drivers: " << availableDrivers << endl;
	for (int i = 0; i < availableDrivers; i++)
	{
		int id = Drivers[0][i].getDId();
		cout << Drivers[0][i];
		if (Drivers[0][i].getNoofServices() > 0) {
			displayRideOfDriver(id);
			displayDeliveryOfDriver(id);
		}
		cout << endl;
	}

}


void TMS::displayDriversWithRank4_5() {
	int count = 0;
	for (int i = 0; i < availableDrivers; i++)
	{
		if (Drivers[0][i].getRanking() >= 4.5) {

			cout << Drivers[0][i];
			count++;
		}
	}
	cout << "Total Drivers Found: " << count << endl;
}


void TMS::displayDriversWithRank() {
	int count = 0;
	int rank;
	cout << "Enter rank: ";
	cin >> rank;
	for (int i = 0; i < availableDrivers; i++)
	{
		if (Drivers[0][i].getRanking() >= rank) {

			cout << Drivers[0][i];
			count++;
		}
	}
	cout << "Total Drivers Found: " << count << endl;
}


void TMS::displayDriverWithID() {
	int id;
	cout << "Enter Driver ID: ";
	cin >> id;
	for (int i = 0; i < availableDrivers; i++)
	{
		int did = Drivers[0][i].getDId();
		if (id == did) {
			cout << Drivers[0][i];
			displayRideOfDriver(did);
			displayDeliveryOfDriver(did);
			cout << "\n";
		}
	}

}
void TMS::displayDriverWithMultipleLicence() {
	for (int i = 0; i < availableDrivers; i++)
	{
		if (Drivers[0][i].getNoofLicences() > 1) {
			cout << Drivers[0][i];
			cout << "\n";
		}
	}
}

void TMS::displayDriverWhoDeliveredOnSameDate() {
	int id;
	Date date;
	cin >> date;
	cout << "Enter Driver ID: ";
	cin >> id;
	for (int i = 0; i < availableDeliveries; i++)
	{
		if (Deliveries[0][i].getBookingDate().getDay() == date.getDay() && Deliveries[0][i].getBookingDate().getMonth() == date.getMonth() && Deliveries[0][i].getBookingDate().getYear() == date.getYear() && Deliveries[0][i].getDId() == id) {
			for (int i = 0; i < availableDrivers; i++)
			{
				if (Drivers[0][i].getDId() == id) {
					cout << Drivers[0][i] << endl;
				}
			}
		}
	}

}


bool TMS::isDriverFound(int id) {
	loadDrivers();
	for (int i = 0; i < availableDrivers; i++)
	{
		if (id == Drivers[0][i].getDId()) {
			return true;
		}
	}
	return false;
}
 

void TMS::removeDriver()
{
	int id;
	cout << "Enter driver ID: ";
	cin >> id;

	if (isDriverFound(id)) {
		ofstream dFile("drivers.txt");
		if (dFile.is_open()) {
			dFile << availableDrivers-1 << endl;

			for (int i = 0; i < availableDrivers; i++)
			{
				if (id != Drivers[0][i].getDId()) {

					dFile << Drivers[0][i];
				}
			}
			cout << "\nSuccess 200. Driver Removed Successfully!\n";
		}
		else {
			cout << "Error opening file drivers.txt!\n";
		}
	}
	else {
		cout << "Error 404. Driver with ID: " << id << " not Found!\n";
	}
	loadDrivers();

}

void TMS::loadVehicles() {
	ifstream file("vehicles.txt");
	if (file.is_open()) {
		if (file) {
			file >> availableVehicles;

			for (int i = 0; i < availableVehicles; i++)
			{
				file >> Vehicles[0][i];
			}

		}
	}
	file.close();
}

void TMS::writeVehicle() {

	ofstream vFile("vehicles.txt");
	if (vFile.is_open()) {
		vFile << availableVehicles << endl;

		for (int i = 0; i < availableVehicles; i++)
		{
			vFile << Vehicles[0][i];
		}
	}
	else {
		cout << "Error opening file vehicles.txt!\n";
	}
	vFile.close();

}

void TMS::addVehicle() {

	bool isFound = true;
	Vehicle newVehicle;
	cin >> newVehicle;

	for (int i = 0; i < availableVehicles; i++)
	{
		if (Vehicles[0][i].getRegNo() == newVehicle.getRegNo()) {
			isFound = false;
			cout << "Vehicle with Reg no already found\n";
		}
	}
	if (isFound) {

		loadVehicles();
		Vehicles[0][availableVehicles++] = newVehicle;

		cout << "\nSuccess 200. Vehicle Added Successfully!\n";
		cout << "\n Vehicle ID: " << newVehicle.getVId() << endl;

		writeVehicle();
	}


}

bool TMS::isVehicleFound(int id) {
	loadVehicles();
	for (int i = 0; i < availableVehicles; i++)
	{
		if (id == Vehicles[0][i].getVId()) {
			return true;
		}
	}
	return false;
}

void TMS::removeVehicle()
{
	int id;
	cout << "Enter vehicle ID: ";
	cin >> id;

	if (isVehicleFound(id)) {
		ofstream vFile("vehicles.txt");
		if (vFile.is_open()) {
			vFile << availableVehicles - 1 << endl;

			for (int i = 0; i < availableVehicles; i++)
			{
				if (id != Vehicles[0][i].getVId()) {

					vFile << Vehicles[0][i];
				}
			}
			cout << "\nSuccess 200. Vehicle Removed Successfully!\n";
		}
		else {
			cout << "Error opening file vehicles.txt!\n";
		}
	}
	else {
		cout << "Error 404. Vehicle with ID: " << id << " not Found!\n";
	}
	loadVehicles();

}


void TMS::displayVehicleWithID() {
	int id;
	cout << "Enter ID: ";
	cin >> id;

	for (int i = 0; i < availableVehicles; i++)
	{
		if (Vehicles[0][i].getVId() == id) {
			cout << Vehicles[0][i];
		}
	}
}


void TMS::displayRideWithID() {

	int id;
	cout << "Enter service ID: ";
	cin >> id;

	for (int i = 0; i < availableRides; i++)
	{
		if (Rides[0][i].getSId() == id) {
			cout << Rides[0][i];
		}
	}

}

void TMS::displayDeliveryWithID() {

	int id;
	cout << "Enter service ID: ";
	cin >> id;

	for (int i = 0; i < availableDeliveries; i++)
	{
		if (Deliveries[0][i].getSId() == id) {
			cout << Deliveries[0][i];
		}
	}

}



void TMS::displayRideOfVehicle(int id) {
	for (int i = 0; i < availableRides; i++)
	{
		if (Rides[0][i].getVId() == id) {
			cout << Rides[0][i];
		}
	}
}

void TMS::displayDeliveryOfVehicle(int id) {
	for (int i = 0; i < availableDeliveries; i++)
	{
		if (Deliveries[0][i].getVId() == id) {
			cout << Deliveries[0][i];
		}
	}
}


void TMS::completeDelivery() {
	int id;
	cout << "Enter service ID: ";
	cin >> id;
	Delivery deliv;

	for (int i = 0; i < availableDeliveries; i++)
	{
		if (Deliveries[0][i].getSId() == id) {
			if (Deliveries[0][i].getStatus() == 0) {
				deliv = Deliveries[0][i];
				Deliveries[0][i].setStatus(1);

				cout << "Fare: " << Deliveries[0][i].getFare() << endl;
				cout << "\nSuccess 200. Delivery Status Changed Successfully!\n";
				writeDelivery();
			}
			else
			{
				cout << "Delivery is already completed!\n";
			}
		}
	}
	//update driver status
	for (int j = 0; j < availableDrivers; j++)
	{
		if (Drivers[0][j].getDId() == deliv.getDId()) {
			Drivers[0][j].setStatus(1);
			writeDrivers();
		}
	}
	//update vehicle status
	for (int i = 0; i < availableVehicles; i++)
	{
		if (Vehicles[0][i].getVId() == deliv.getVId()) {
			Vehicles[0][i].setStatus(0);
			writeVehicle();
		}
	}

}


void TMS::cancelDelivery() {
	int id;
	cout << "Enter service ID: ";
	cin >> id;
	Delivery deliv;
	ofstream dFile("deliveries.txt");

	for (int i = 0; i < availableDeliveries; i++)
	{
		if (dFile.is_open()) {
			if (Deliveries[0][i].getSId() == id) {
				deliv = Deliveries[0][i];
			}
			if (Deliveries[0][i].getSId() != id) {
				dFile << availableDeliveries << endl;
				for (int i = 0; i < availableDeliveries; i++)
				{
					dFile << Deliveries[0][i];
				}
				cout << "\nSuccess 200. Delivery Cancelled Successfully!\n";
			}
		}
		else {
			cout << "Error opening file rides.txt!\n";
		}
		dFile.close();
	}

	//update driver status
	for (int j = 0; j < availableDrivers; j++)
	{
		if (Drivers[0][j].getDId() == deliv.getDId()) {
			Drivers[0][j].setStatus(3);
			writeDrivers();
		}
	}
	//update vehicle status
	for (int i = 0; i < availableVehicles; i++)
	{
		if (Vehicles[0][i].getVId() == deliv.getVId()) {
			Vehicles[0][i].setStatus(0);
			writeVehicle();
		}
	}

}



void TMS::cancelRide() {
	int id;
	cout << "Enter service ID: ";
	cin >> id;
	Ride ride;

	for (int i = 0; i < availableRides; i++)
	{
		if (Rides[0][i].getSId() == id) {
			ride = Rides[0][i];
			Rides[0][i].setStatus(3);
			writeRides();
		}
		cout << "\nSuccess 200. Ride Cancelled Successfully!\n";
	}

	//update driver status
	for (int j = 0; j < availableDrivers; j++)
	{
		if (Drivers[0][j].getDId() == ride.getDId()) {
			Drivers[0][j].setStatus(3);
			writeDrivers();
		}
	}
	//update vehicle status
	for (int i = 0; i < availableVehicles; i++)
	{
		if (Vehicles[0][i].getVId() == ride.getVId()) {
			Vehicles[0][i].setStatus(0);
			writeVehicle();
		}
	}
}



void TMS::completeRide() {
	int id,drank,vrank;
	cout << "Enter service ID: ";
	cin >> id;
	Ride ride;

	for (int i = 0; i < availableRides; i++)
	{
		if (Rides[0][i].getSId() == id) {
			if (Rides[0][i].getStatus() == 0) {
				ride = Rides[0][i];
				cout << "Enter Driver ranking (0 to 5):  ";
				cin >> drank;
				cout << "Enter Vehicle ranking (0 to 5): ";
				cin >> vrank;
				Rides[0][i].setStatus(1);
				Rides[0][i].setDRank(drank);
				Rides[0][i].setVRank(vrank);
				writeRides();
				cout << "Fare: " << Rides[0][i].getFare() << endl;
				cout << "\nSuccess 200. Ride Status Changed Successfully!\n";
			}
			else
			{
				cout << "Ride is already completed!\n";
			}
		}
	}
	//update driver status
	for (int j = 0; j < availableDrivers; j++)
	{
		if (Drivers[0][j].getDId() == ride.getDId()) {
			Drivers[0][j].setStatus(1);
			int salary = Drivers[0][j].getSalary();
			if (ride.getDRank() >= 4.5) {
				Drivers[0][j].setSalary(salary + (salary * 15 / 100));
			}
			
			writeDrivers();
		}
	}
	//update vehicle status
	for (int i = 0; i < availableVehicles; i++)
	{
		if (Vehicles[0][i].getVId() == ride.getVId()) {
			Vehicles[0][i].setStatus(0);
			writeVehicle();
		}
	}
}


void TMS::displayAllVehicles() {
	cout << "Total Vehicles: " << availableVehicles << endl;
	for (int i = 0; i < availableVehicles; i++)
	{
		int id = Vehicles[0][i].getVId();
		cout << Vehicles[0][i];
		if (Vehicles[0][i].getNoofServices() > 0) {
			displayRideOfVehicle(id);
			displayDeliveryOfVehicle(id);
		}
	}
}


void TMS::loadRides() {
	ifstream file("rides.txt");
	if (file.is_open()) {
		if (file) {
			file >> availableRides;

			for (int i = 0; i < availableRides; i++)
			{
				file >> Rides[0][i];
			}

		}
	}
	file.close();
}


void TMS::writeRides() {

	ofstream rFile("rides.txt");
	if (rFile.is_open()) {
		rFile << availableRides << endl;

		for (int i = 0; i < availableRides; i++)
		{
			rFile << Rides[0][i];
		}
	}
	else {
		cout << "Error opening file rides.txt!\n";
	}
	rFile.close();

}


void TMS::addRide() {

	Ride newRide;
	cin >> newRide;
	bool isOkay = true;
	
	for (int i = 0; i < availableDrivers; i++)
	{
		if (Drivers[0][i].getDId() == newRide.getDId() && Drivers[0][i].getStatus() == 2) {
			cout << "Driver is already booked!\n";
			isOkay = false;
		}
		else if (Vehicles[0][i].getVId() == newRide.getVId() && Vehicles[0][i].getStatus() == 1) {
			cout << "Vehicle is already booked!\n";
			isOkay = false;
		}
	}

	if (isOkay) {

		loadRides();
		Rides[0][availableRides++] = newRide;

		writeRides();
		cout << "Service ID: " << newRide.getSId() << endl;
		cout << "\nSuccess 200. Ride Added Successfully!\n";

		//update vehicle status
		for (int i = 0; i < availableVehicles; i++)
		{
			if (Vehicles[0][i].getVId() == newRide.getVId()) {
				Vehicles[0][i].setStatus(1);
			}
		}
		//update in file
		writeVehicle();

		//update driver status

		for (int i = 0; i < availableDrivers; i++)
		{
			if (Drivers[0][i].getDId() == newRide.getDId()) {
				Drivers[0][i].setStatus(2);
			}
		}
		writeDrivers();

	}
	
}

void TMS::displayAllRides() {
	cout << "Total Rides: " << availableRides << endl;
	for (int i = 0; i < availableRides; i++)
	{
		cout << Rides[0][i];
	}
}


void TMS::loadDeliveries() {
	ifstream file("deliveries.txt");
	if (file.is_open()) {
		if (file) {
			file >> availableDeliveries;

			for (int i = 0; i < availableDeliveries; i++)
			{
				file >> Deliveries[0][i];
			}

		}
	}
	file.close();

}

void TMS::displayAllDeliveries() {
	cout << "Total Deliveries: " << availableDeliveries << endl;
	for (int i = 0; i < availableDeliveries; i++)
	{
		cout << Deliveries[0][i];
	}
}


void TMS::writeDelivery() {

	ofstream dFile("deliveries.txt");
	if (dFile.is_open()) {
		dFile << availableDeliveries << endl;

		for (int i = 0; i < availableDeliveries; i++)
		{
			dFile << Deliveries[0][i];
		}
	}
	else {
		cout << "Error opening file deliveries.txt!\n";
	}
	dFile.close();

}


void TMS::addDelivery()
{
	bool isOkay = true;
	Delivery newDelivery;
	cin >> newDelivery;

	for (int i = 0; i < availableDrivers; i++)
	{
		if (Drivers[0][i].getDId() == newDelivery.getDId() && Drivers[0][i].getStatus() == 2) {
			cout << "Driver is already booked!\n";
			isOkay = false;
		}
		else if (Vehicles[0][i].getVId() == newDelivery.getVId() && Vehicles[0][i].getStatus() == 1) {
			cout << "Vehicle is already booked!\n";
			isOkay = false;
		}
	}

	if (isOkay) {

		loadDeliveries();
		Deliveries[0][availableDeliveries++] = newDelivery;
		
		writeDelivery();
		cout << "Service ID: " << newDelivery.getSId() << endl;
		cout << "\nSuccess 200. Delivery Added Successfully!\n";

	}


}

void TMS::displayAllPendingServicesOnDate() {
	Date date;
	cout << "Enter date: \n";
	cin >> date;

	for (int i = 0; i < availableRides; i++)
	{
		if (Rides[0][i].getBookingDate().getDay() == date.getDay() && Rides[0][i].getBookingDate().getMonth() == date.getMonth() && Rides[0][i].getBookingDate().getYear() == date.getYear() && Rides[0][i].getStatus() == 0) {
			cout << Rides[0][i];
		}
	}

	for (int i = 0; i < availableDeliveries; i++)
	{
		if (Deliveries[0][i].getBookingDate().getDay() == date.getDay() && Deliveries[0][i].getBookingDate().getMonth() == date.getMonth() && Deliveries[0][i].getBookingDate().getYear() == date.getYear() && Deliveries[0][i].getStatus() == 0) {
			cout << Deliveries[0][i];
		}
	}
}

void TMS::displayAllPendingServicesbyDriver() {
	int id;
	cout << "Enter Driver ID: ";
	cin >> id;

	for (int i = 0; i < availableRides; i++)
	{
		if (Rides[0][i].getDId()==id && Rides[0][i].getStatus() == 0) {
			cout << Rides[0][i];
		}
	}

	for (int i = 0; i < availableDeliveries; i++)
	{
		if (Deliveries[0][i].getDId() == id && Deliveries[0][i].getStatus() == 0) {
			cout << Deliveries[0][i];
		}
	}
}
#include "Project.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <windows.h>


//for reference only
void Menu() {
	cout << "1. Add a new Customer" << endl;
	cout << "2. Add or remove a Driver" << endl;
	cout << "3. Add or remove a Vehicle" << endl;
	cout << "4. Print List of All Customers" << endl;
	cout << "5. Print List of All drivers" << endl;
	cout << "6. Print complete list of vehicles with details by their category" << endl;
	cout << "7. Print complete details and service history of a particular vehicle, (Provide vehicle ID)" << endl;
	cout << "8. Print complete history of a particular customer, (Provide customer ID)" << endl;
	cout << "9. Print complete history of a driver including services. (Provide driver ID)" << endl;
	cout << "10. Print list of all drivers who have ranking above 4.5." << endl;
	cout << "11. Print list of all drivers who have multiple licenses and their license information too" << endl;
	cout << "13. Add a Service request (ride or delivery)" << endl;
	cout << "14. Cancel a booking" << endl;
	cout << "15. Complete a Service (Provide Service ID)" << endl;
	cout << "16. Print details of all Customers, who used the same vehivle in a ride service on a different date" << endl;
	cout << "17. Print List of all drivers who completed delvery services on same day" << endl;
	cout << "18. Print details of all pending services on a particular date" << endl;
	cout << "19. Print details of all pending services of a particular driver" << endl;
	cout << "20. Print details of all cancelled services by a customer" << endl;
}


void showMenu(TMS &T) {
	int choice;
a:
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
	cout << setw(100) << "------------------ Welcome To Travel Management System ------------------\n\n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	cout << "1. Customers\n";
	cout << "2. Drivers\n";
	cout << "3. Vehicles\n";
	cout << "4. Rides\n";
	cout << "5. Deliveries\n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
	cout << "0. Exit!\n\n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	cout << "Enter choice: ";
	cin >> choice;
	
	switch (choice)
	{
	case 0:
		break;
	case 1:
		b:
		cout << "1. Add a Cusotmer\n";
		cout << "2. Details of Specific Customer\n";
		cout << "3. Details All Customers\n";
		cout << "4. Details Customer who used same vehicle for a trip\n";
		cout << "5. Pending Services on a Particular Date\n";
		cout << "6. Cancelled Services By Customer\n";
		cout << "0. Main Menu\n\n";
		cout << "Enter choice: ";
		cin >> choice;
		switch (choice)
		{
		case 0:
			goto a;
		case 1:
			T.addCustomer();
			goto b;
			break;
		case 2:
			T.displayCustomerWithID();
			goto b;
			break;
		case 3:
			T.displayAllCustomers();
			goto b;
			break;
		case 4:
			T.displayCustomerWithSameVehicle();
			goto b;
			break;
		case 5:
			T.displayAllPendingServicesOnDate();
			goto b;
			break;
		case 6:
			T.displayAllCancelledServicesByCustomer();
			goto b;
			break;
		default:
			cout << "Invalid Choice!\n\n";
			goto b;
			break;
		}
		break;
	case 2:
		c:
		cout << "1. Add a Driver\n";
		cout << "2. Remove a Driver\n";
		cout << "3. Details of Specific Driver\n";
		cout << "4. Details of Driver with Ranking > 4.5 \n";
		cout << "5. Details of Driver with Multiple Licences \n";
		cout << "6. Details of Driver with who Delivered on same Date \n";
		cout << "7. Details of Pending Services by Particular Driver \n";
		cout << "0. Main Menu!\n\n";
		cout << "Enter choice: ";
		cin >> choice;
		switch (choice)
		{
		case 0:
			goto a;
		case 1: 
			T.addDriver();
			goto c;
			break;
		case 2:
			T.removeDriver();
			goto c;
			break;
		case 3:
			T.displayDriverWithID();
			goto c;
			break;
		case 4:
			T.displayDriversWithRank4_5();
			goto c;
			break;
		case 5:
			T.displayDriverWithMultipleLicence();
			goto c;
			break;
		case 6:
			T.displayDriverWhoDeliveredOnSameDate();
			goto c;
			break;
		case 7:
			T.displayAllPendingServicesbyDriver();
			goto c;
			break;
		default:
			cout << "Invalid Choice!\n\n";
			goto c;
			break;
		}
		break;
	case 3:
		d:
		cout << "1. Add a Vehicle\n";
		cout << "2. Remove a Vehicle\n";
		cout << "3. Display All Vehicles\n";
		cout << "4. Display Specfic Vehicle\n";
		cout << "0. Main Menu!\n\n";
		cout << "Enter choice: ";
		cin >> choice;
		switch (choice)
		{
		case 0:
			goto a;
			break;
		case 1:
			T.addVehicle();
			goto d;
			break;
		case 2:
			T.removeVehicle();
			goto d;
			break;
		case 3:
			T.displayAllVehicles();
			goto d;
			break;
		case 4:
			T.displayVehicleWithID();
			goto d;
			break;
		default:
			cout << "Invalid Choice!\n\n";
			goto d;
			break;
		}
		break;
	case 4:
		e:
		cout << "1. Add a Ride\n";
		cout << "2. Cancel a Ride\n";
		cout << "3. Complete a Ride\n";
		cout << "4. Display All Rides\n";
		cout << "5. Display a Specific Ride\n";
		cout << "0. Main Menu!\n\n";
		cout << "Enter choice: ";
		cin >> choice;
		cin.ignore();
		switch (choice)
		{
		case 0:
			goto a;
			break;
		case 1:
			T.addRide();
			goto e;
			break;
		case 2:
			T.cancelRide();
			goto e;
			break;
		case 3:
			T.completeRide();
			goto e;
			break;
		case 4:
			T.displayAllRides();
			goto e;
			break;
		case 5:
			T.displayRideWithID();
			goto e;
			break;
		default:
			cout << "Invalid Choice!\n\n";
			goto e;
			break;
		}
		break;
	case 5:
		f:
		cout << "1. Add a Delivery\n";
		cout << "2. Cancel a Delivery\n";
		cout << "3. Complete a Delivery\n";
		cout << "4. Display All Deliveries\n";
		cout << "5. Display a Specific Delivery \n";
		cout << "0. Main Menu!\n\n";
		cout << "Enter choice: ";
		cin >> choice;
		cin.ignore();
		switch (choice)
		{
		case 0:
			goto a;
			break;
		case 1:
			T.addDelivery();
			goto f;
			break;
		case 2:
			T.cancelDelivery();
			goto f;
			break;
		case 3:
			T.completeDelivery();
			goto f;
			break;
		case 4:
			T.displayAllDeliveries();
			goto f;
			break;
		case 5:
			T.displayDeliveryWithID();
			goto f;
			break;
		default:
			cout << "Invalid Choice!\n\n";
			goto f;
			break;
		}
		break;

	default:
		cout << "Invalid Choice!\n";
		goto a;
		break;
	}
}

int main() {

	TMS T(15,10,20);
	showMenu(T);

	return 0;
}
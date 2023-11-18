#include <stdlib.h>
#include <iostream>
//#include "stdafx.h"

#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/prepared_statement.h>
using namespace std;



int main()
{
	/*
		Initialisierungen
	*/
	const string server = "tcp://127.0.0.6:6666";
	string username = "";
	string password = "";
	sql::Driver* driver;
	sql::Connection* con;
	sql::PreparedStatement* pstmt;
	sql::ResultSet* result;
	
	
	cout << "Benutzernamen eingeben: ";
	cin >> username;
	cout << "Passwort eingeben: ";
	cin >> password;

	try
	{
		driver = get_driver_instance();
		con = driver->connect(server, username, password);
	}
	catch (sql::SQLException e)
	{
		cout << "Could not connect to server. Error message: " << e.what() << endl;
		system("pause");
		exit(1);
	}

	con->setSchema("changerepo");

	/*
		Insert Query

		Beim Schreiben in die Tabelle Changes ist zu beachten, das die Row "ChanageID" Unique 
		ist. Außerdem darf die Row "ID" nicht über die Query gefüllt werden, da diese die 
		Auto_Increment eigenschaft besitzt. 
	*/
	pstmt = con->prepareStatement("INSERT INTO Changes(ChangeID, Kundenname, Beschreibung) VALUES(?, ?, ?);");
	pstmt->setBigInt(1, "1006");
	pstmt->setString(2, "Test");
	pstmt->setString(3, "Testbeschreibung");
	pstmt->execute();
	delete pstmt;

	/*
		Select Query
	*/
	pstmt = con->prepareStatement("SELECT * FROM Changes;");
    result = pstmt->executeQuery();

	while (result->next()) {


		printf("Reading from table=(%d, %d, %s, %s)\n", result->getInt(1), result->getInt(2), result->getString(3).c_str(), 
			result->getString(4).c_str());

	}
		

	delete result;
	delete pstmt;
	delete con;
	system("pause");
	return 0;
}
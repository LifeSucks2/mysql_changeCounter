#include <stdlib.h>
#include <iostream>
//#include "stdafx.h"
#include <vector>
#include "sorting.h"

#include "mysql_fkt.h"
#include "checkChangeID.h"
using namespace std;



int main()
{
	/*
	* Ausgabe der Inhalte des Select querys
	 
		while (result->next()) {
			printf("Reading from table=(%d, %d, %s, %s)\n", result->getInt(1), result->getInt(2), result->getString(3).c_str(), 
				result->getString(4).c_str());
		}
	*/
	
	
	
	sql::Connection* con;
	sql::ResultSet* result;

	//Verbindung zur DB aufbauen und select befehl ausführen
	con = mysqlfkt::mysqlTryToConnectDB("127.0.0.1:6666", "changerepo");
	result = mysqlfkt::mysqlSelectQueryExecute("SELECT * FROM Changes;", con);
	
	// Vektor füllen
	vector<int> changeIDs = {};
	while (result->next())
		changeIDs.push_back(result->getInt(2));

	//Vektor sortieren
	sorting::QuickSort(changeIDs, 0, changeIDs.size() - 1);

	//ChangeID finden und auswählen
	checkChangeID::checkSetID(changeIDs, con);

	mysqlfkt::deleteConnection(result, con);
	system("pause");
	return 0;
}
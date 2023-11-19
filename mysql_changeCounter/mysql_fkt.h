#ifndef _MYSQL_FKT_H_
#define _MYSQL_FKT_H_
#include <stdlib.h>
#include <iostream>
#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/prepared_statement.h>




namespace mysqlfkt {
	sql::Connection* mysqlTryToConnectDB(std::string serveradress, std::string DatabaseSchema);
	sql::ResultSet* mysqlSelectQueryExecute(std::string mysqlSelectQuery, sql::Connection* connection);
	void mysqlInsertQueryExec(std::string mysqlInsertQuery, sql::Connection* connection, int id, std::string kundenname, std::string ticketbeschreibung);
	void deleteConnection(sql::ResultSet* res, sql::Connection* con);
}



#endif // !_MYSQL_FKT_H_


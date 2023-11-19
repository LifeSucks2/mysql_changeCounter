#include "mysql_fkt.h"

namespace mysqlfkt {
	sql::Connection* mysqlTryToConnectDB(std::string serveradress, std::string DatabaseSchema) {
		std::string username, password, chIDAntwort;
		sql::Driver* driver;
		sql::Connection* con;

		std::cout << "Benutzernamen eingeben: ";
		std::cin >> username;
		std::cout << "Passwort eingeben: ";
		std::cin >> password;

		try
		{
			driver = get_driver_instance();
			con = driver->connect(serveradress, username, password);
		}
		catch (sql::SQLException e)
		{
			std::cout << "Could not connect to server. Error message: " << e.what() << std::endl;
			system("pause");
			exit(1);
		}
		con->setSchema(DatabaseSchema);
		return con;
	}
	sql::ResultSet* mysqlSelectQueryExecute(std::string mysqlSelectQuery, sql::Connection* connection) {
		sql::PreparedStatement* pstmt;
		pstmt = connection->prepareStatement("SELECT * FROM Changes;");
		return pstmt->executeQuery();
	}
	void mysqlInsertQueryExec(std::string mysqlInsertQuery, sql::Connection* connection, int id, std::string kundenname, std::string ticketbeschreibung) {
		sql::PreparedStatement* pstmt;
		pstmt = connection->prepareStatement(mysqlInsertQuery);
		pstmt->setBigInt(1, std::to_string(id));
		pstmt->setString(2, kundenname);
		pstmt->setString(3, ticketbeschreibung);
		pstmt->execute();
		//delete pstmt;
	}
	void deleteConnection(sql::ResultSet* res, sql::Connection* con) {
		delete res;
		delete con;
	}

}
#include "checkChangeID.h"
#include "mysql_fkt.h"


namespace checkChangeID {
	void checkSetID(std::vector<int>& changeIDs, sql::Connection* connect) {
		int id = 0;
		std::string chIDAntwort, Kundenname, Ticketbeschreibung;
		std::string query = "INSERT INTO Changes(ChangeID, Kundenname, Beschreibung) VALUES(?, ?, ?);";

		for (int i = 0; i < changeIDs.size(); i++) {
			if (i < changeIDs.size()) {
				if (changeIDs[i + 1] - changeIDs[i] > 1) {
					id = changeIDs[i] + 1;
					std::cout << "Freie ChangeID lautet: " << id << std::endl;
					std::cout << "ChangeID auswählen? Bitte mit Ja oder Nein antworten. ";
					std::cin >> chIDAntwort;

					if (chIDAntwort == "ja" || chIDAntwort == "Ja" || chIDAntwort == "JA") {
						std::cout << "Geben Sie den Kundennamen ein ";
						std::cin >> Kundenname;
						std::cout << "Geben Sie die Ticketbeschreibung ein ";
						std::cin >> Ticketbeschreibung;

						//Insert Query

						//Beim Schreiben in die Tabelle Changes ist zu beachten, das die Row "ChanageID" Unique
						//ist. Außerdem darf die Row "ID" nicht über die Query gefüllt werden, da diese die
						//Auto_Increment eigenschaft besitzt.

						mysqlfkt::mysqlInsertQueryExec(query, connect, id, Kundenname, Ticketbeschreibung);
						break;
					}
					if (chIDAntwort == "nein" || chIDAntwort == "Nein" || chIDAntwort == "NEIN") {
						std::cout << "Programm wird geschlossen";
						break;
					}
					else {
						i--;
						continue;
					}
				}
			}
		}
	}
}
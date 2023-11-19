#ifndef _CHECKCHANGEID_H_
#define _CHECKCHANGEID_H_

#include <vector>
#include <iostream>
#include "mysql_connection.h"

namespace checkChangeID {
	/*
		ID Check logik soll die ChangeIDs aus der Datenbank in einem Vektor abspreichern und die
		n‰chste freie ID dem User vorschlagen. Auﬂerdem wird die ChangeID in der DB abgespeichert. 
	*/
	void checkSetID(std::vector<int>& changeIDs, sql::Connection* connect);
}

#endif // 


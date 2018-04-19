#include "HeartbeatPing.h"
#include "SCon.h"
#include <list>

#define HPORT 	"778"
#define BACKLOG	"12"

class HeartbeatPing {
	public:
		HeartbeatPing(std::list<SCon> ipList);
		void runClass();
		void stopClass();
		bool isClassTerminal();

	private:
		std::list<SCon> pairedList;
		bool classActive;
		bool classTerminal;	
};
		


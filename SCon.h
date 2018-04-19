#ifndef SCON_H
#define SCON_H

#include <list>
#include <string>

class SCon {
	public:
		SCon(std::list<std::string>, std::list<bool>);
		std::string ipGet(int);
		void ipAdd(std::string);
		bool activeGet(bool);
		bool activeSet(bool);
	private:
		std::list<std::string> ipList;
		std::list<bool> activeList;
}

#endif


/*
 *   Copyright (C) 2009-2014,2016 by Jonathan Naylor G4KLX
 *
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation; either version 2 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program; if not, write to the Free Software
 *   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#ifndef	Network_H
#define	Network_H

#include "UDPSocket.h"

#include <cstdint>
#include <string>

class CNetwork {
public:
	CNetwork(unsigned int port, const std::string& callsign, bool debug);
	~CNetwork();

	bool open();

	bool writeData(const unsigned char* data, unsigned int length, const in_addr& address, unsigned int port);

	unsigned int readData(unsigned char* data, unsigned int length, in_addr& address, unsigned int& port);

	bool writePoll(const in_addr& address, unsigned int port);

	bool writeUnlink(const in_addr& address, unsigned int port);

	void close();

private:
	std::string  m_callsign;
	CUDPSocket   m_socket;
	bool         m_debug;
};

#endif

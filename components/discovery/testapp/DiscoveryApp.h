/* Copyright (C) 2016 Alexander Shishenko <alex@shishenko.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * In addition, as a special exception, the copyright holders give
 * permission to link the code of portions of this program with the
 * OpenSSL library under certain conditions as described in each
 * individual source file, and distribute linked combinations
 * including the two.
 * You must obey the GNU General Public License in all respects
 * for all of the code used other than OpenSSL.  If you modify
 * file(s) with this exception, you may extend this exception to your
 * version of the file(s), but you are not obligated to do so.  If you
 * do not wish to do so, delete this exception statement from your
 * version.  If you delete this exception statement from all source
 * files in the program, then also delete it here.
 */
#pragma once
#include <QCoreApplication>
#include <QHostAddress>
#include <QUrl>
#include "discovery/multicast/MulticastGroup.h"
#include "discovery/multicast/MulticastProvider.h"
#include "discovery/bt/BTProvider.h"
#include "discovery/bt/BTGroup.h"
#include "discovery/dht/DHTProvider.h"
#include "discovery/dht/DHTGroup.h"

namespace librevault {

class DiscoveryApp : public QCoreApplication {
  Q_OBJECT
public:
	DiscoveryApp(int argc, char** argv, const char* USAGE);
private:
	MulticastProvider* mcast_p;
	DHTProvider* dht_p;
  BTProvider* bt_p;

  MulticastGroup* mcast_g;
  DHTGroup* dht_g;
  BTGroup* bt_g;

private slots:
	void handleDiscoveredMulticast(QPair<QHostAddress, quint16> endpoint);
	void handleDiscoveredDht(QPair<QHostAddress, quint16> endpoint);
	void handleDiscoveredTorrent(QPair<QHostAddress, quint16> endpoint);
};

} /* namespace librevault */

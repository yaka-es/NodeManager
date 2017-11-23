/* JSONDB/JSONDB.h */
/*-
 * Copyright 2013, 2014 Range Networks, Inc.
 *
 * This software is distributed under the terms of the GNU Affero Public License.
 * See the COPYING file in the main directory for details.
 *
 * This use of this software may be subject to additional restrictions.
 * See the LEGAL file in the main directory for details.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _NODEMANAGER_JSONDB_H
#define _NODEMANAGER_JSONDB_H

#include <string>
#include <vector>

#include <CommonLibs/sqlite3util.h>

#include <JsonBox.h>

class JSONDB {
private:
	sqlite3 *mDB;
	std::string generateWhereClause(JsonBox::Object request);
	std::string implode(std::string delimiter, std::vector<std::string> pieces);
	JsonBox::Object read(std::string query, unsigned retries = 5);
	JsonBox::Object execOnly(std::string query, unsigned retries = 5);

public:
	bool connect(std::string);
	bool disconnect();
	JsonBox::Object query(JsonBox::Object, unsigned retries = 5);
};

#endif /* _NODEMANAGER_JSONDB_H */

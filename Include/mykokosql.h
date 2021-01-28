#pragma once

// Usually located in "C:\Program Files\MySQL\MySQL Server 8.0\include"
#include "mysql.h"

// Usually located in "C:\Program Files\MySQL\MySQL Server 8.0\lib"
#pragma comment(lib, "libmysql.lib")

// Class used to represent a connection to a MySQL database
class MykokoSQL final{
public:
	MykokoSQL() noexcept;
};
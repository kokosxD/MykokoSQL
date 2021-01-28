#pragma once

// Usually located in "C:\Program Files\MySQL\MySQL Server 8.0\include"
#include "mysql.h"

// Usually located in "C:\Program Files\MySQL\MySQL Server 8.0\lib"
#pragma comment(lib, "libmysql.lib")

// Class used to represent a connection to a MySQL database
class MykokoSQL final{
private:
	MYSQL* m_db = nullptr;
public:
	MykokoSQL() noexcept;

	~MykokoSQL() noexcept;

	/**
	* // Initializes MySQL
	* @return True if MySQL is initialized
	*/
	const bool Init() noexcept;

	/**
	* // Closes the current connection
	* @return None
	*/
	void Close() noexcept;

	/**
	* // Connects with the requested MySQL server
	* @param _host Host name or IP address to connect with
	* @param _user User name
	* @param _password User password
	* @param _db Database name
	* @param _port Port to use for the connection (default is 0)
	* @return True if the connection to the requested MySQL server is established
	*/
	const bool Connect(
		const char* const _host,
		const char* const _user,
		const char* const _password,
		const char* const _db = nullptr,
		const unsigned int& _port = 0
	) noexcept;
};
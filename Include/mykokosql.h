#pragma once

// Usually located in "C:\Program Files\MySQL\MySQL Server 8.0\include"
#include "mysql.h"

// Usually located in "C:\Program Files\MySQL\MySQL Server 8.0\lib"
#pragma comment(lib, "libmysql.lib")

// Class used to represent a connection to a MySQL database
class MykokoSQL final{
private:

	/**
	* // Performs case-insensitive comparison on the given characters
	* @param _ch1 The first character to compare
	* @param _ch2 The second character to compare
	* @return True if the 2 characters are same
	*/
	static const bool __CaseInsensitiveComparison(const char& _ch1, const char& _ch2) noexcept;
public:

	// Class used to represent a MySQL column
	class Row;
	class Column final{
	private:
		friend class Row;

		// Accessible from MykokoSQL::Row
		Column(const Row* const _row, const unsigned int& _col_indx) noexcept;

		// Accessible from MykokoSQL::Row
		Column() noexcept;

		const Row* const m_row = nullptr;
		const unsigned int m_indx = 0;
		const char* m_bytes = nullptr;
		unsigned int m_len = 0;
	public:

		/**
		* @return The index of the current column
		*/
		const unsigned int GetIndex() const noexcept;

		/**
		* @return The column
		*/
		const char* const Get() const noexcept;

		/**
		* @return The length of the current column in bytes
		*/
		const unsigned int Length() const noexcept;

		/**
		* @return True if the current column is NULL
		*/
		const bool IsNull() const noexcept;

		/**
		* @param _col_indx The index of the byte to return
		* @return A byte from the current column
		*/
		const char operator[](const unsigned int& _byte_indx) const noexcept;

		/**
		* @return The column
		*/
		operator const char* const() const noexcept;

		/**
		* @return True if the current column is valid
		*/
		operator const bool() const noexcept;
	};

	// Class used to represent a MySQL row
	class Result;
	class Row final{
	private:
		friend class Column;
		friend class Result;

		// Accessible from MykokoSQL::Result
		Row(const Result* const _res, const unsigned int& _row_indx) noexcept;

		// Accessible from MykokoSQL::Result
		Row() noexcept;

		const Result* m_res = nullptr;
		const unsigned long int m_indx = 0;
	public:

		/**
		* @return The index of the current row
		*/
		const unsigned int GetIndex() const noexcept;

		/**
		* @return The number of columns in the current row
		*/
		const unsigned int GetColumnCount() const noexcept;

		/**
		* // Returns a fetched column
		* @param _col_indx The index of the column to return
		* @return The column with the given index
		*/
		const Column operator[](const unsigned int& _col_indx) const noexcept;

		/**
		* // Returns a fetched column
		* @param _col_name The name of the column to return
		* @return The column with the given name
		*/
		const Column operator[](const char* const _col_name) const noexcept;

		/**
		* @return True if the current row is valid
		*/
		operator const bool() const noexcept;
	};

	// Class used to represent the result of a MySQL operation
	class Result final{
	private:
		friend class Column;
		friend class Row;
		friend class MykokoSQL;

		// Accessible from MykokoSQL
		Result(MYSQL_RES* const _res) noexcept;

		// Accessible from MykokoSQL
		Result() noexcept;

		MYSQL_RES* m_mysql_res = nullptr;
	public:
		~Result() noexcept;

		/**
		* @return The number of rows in the current result
		*/
		const unsigned long long int GetRowCount() const noexcept;

		/**
		* // Returns a fetched row
		* @param _row_indx The index of the row to return
		* @return The row with the given index
		*/
		const Row operator[](const unsigned int& _row_indx) const noexcept;

		/**
		* @return True if the current result is valid
		*/
		operator const bool() const noexcept;
	};
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

	/**
	* // Executes the given query
	* @param _query Query to execute
	* @return True if the given query was executed successfully
	*/
	const Result Execute(const char* const _query) noexcept;

	/**
	* // Executes the given query
	* @param _query Query to execute
	* @param _len Length of query
	* @return True if the given query was successfully executed
	*/
	const Result Execute(const char* const _query, const unsigned int& _len) noexcept;

	/**
	* @return The last MySQL error code
	*/
	const unsigned int GetLastErrorCode() const noexcept;

	/**
	* @return The last MySQL error message
	*/
	const char* const GetLastErrorMessage() const noexcept;

	/**
	* @return True if the current MySQL object is valid
	*/
	operator const bool() const noexcept;
};
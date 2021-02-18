#pragma once

// Usually located in "C:\Program Files\MySQL\MySQL Server 8.0\include"
#include "mysql.h"

// Usually located in "C:\Program Files\MySQL\MySQL Server 8.0\lib"
#pragma comment(lib, "libmysql.lib")

// Class used to represent a MySQL connection
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

	// Classes forward declarations
	class Field;
	class Column;
	class Row;
	class Result;

	// Class used to represent a MySQL field
	class Field final{
	public:

		// Enumerator used to represent a MySQL field type
		enum class Type : unsigned short{

			// Invalid MySQL field type
			Invalid = 0x0000,

			// TINYINT
			TinyInt = 0x0001,

			// SMALLINT
			SmallInt = 0x0002,

			// LONG
			Long = 0x0003,

			// FLOAT
			Float = 0x0004,

			// DOUBLE
			Double = 0x0005,

			// NULL
			Null = 0x0006,

			// TIMESTAMP
			TimeStamp = 0x0007,

			// BIGINT
			BigInt = 0x0008,

			// MEDIUMINT
			MediumInt = 0x0009,

			// DATE
			Date = 0x000A,

			// TIME
			Time = 0x000B,

			// DATETIME
			DateTime = 0x000C,

			// YEAR
			Year = 0x000D,

			// VARCHAR
			VarChar = 0x000F,

			// BIT
			Bit = 0x0010,

			// JSON
			JSON = 0x00F5,

			// DECIMAL
			Decimal = 0x00F6,

			// ENUM
			Enum = 0x00F7,

			// SET
			Set = 0x00F8,

			// TINYBLOB
			TinyBlob = 0x00F9,

			// MEDIUMBLOB
			MediumBlob = 0x00FA,

			// LONGBLOB
			LongBlob = 0x00FB,
			
			// BLOB
			Blob = 0x00FC,

			// VARCHAR
			VarString = 0x00FD,

			// STRING
			String = 0x00FE,

			// GEOMETRY
			Geometry = 0x00FF
		};

		// Enumerator used to represent a MySQL character set
		enum class CharacterSet : unsigned short{

			// Invalid MySQL character set
			Invalid = 0x0000,

			// Big5 Traditional Chinese
			Big5 = 0x0001,

			// DEC West European
			DEC8 = 0x0003,

			// DOS West European
			CP850 = 0x0004,

			// HP West European
			HP8 = 0x0006,

			// KOI8-R Relcom Russian
			KOI8R = 0x0007,

			// CP1252 West European
			Latin1 = 0x0008,

			// ISO 8859-2 Central European
			Latin2 = 0x0009,

			// 7bit Swedish
			Swe7 = 0x000A,

			// US ASCII
			ASCII = 0x000B,

			// EUC-JP Japanese
			UJIS = 0x000C,

			// Shift-JIS Japanese
			SJIS = 0x000D,

			// ISO 8859-8 Hebrew
			Hebrew = 0x0010,

			// TIS620 Thai
			TIS620 = 0x0012,

			// EUC-KR Korean
			EUCKR = 0x0013,

			// KOI8-U Ukrainian
			KOI8U = 0x0016,

			// GB2312 Simplified Chinese
			GB2312 = 0x0018,

			// ISO 8859-7 Greek
			Greek = 0x0019,

			// Windows Central European
			CP1250 = 0x001A,

			// GBK Simplified Chinese
			GBK = 0x001C,

			// ISO 8859-9 Turkish
			Latin5 = 0x001E,

			// ARMSCII-8 Armenian
			ArmSCII8 = 0x0020,

			// UTF-8 Unicode
			UTF8 = 0x0021,

			// UCS-2 Unicode
			UCS2 = 0x0023,

			// DOS Russian
			CP866 = 0x0024,

			// DOS Kamenicky Czech-Slovak
			KEYBCS2 = 0x0025,

			// Mac Central European
			MacCE = 0x0026,

			// Mac West European
			Macroman = 0x0027,

			// DOS Central European
			CP852 = 0x0028,

			// ISO 8859-13 Baltic
			Latin7 = 0x0029,

			// Windows Cyrillic
			CP1251 = 0x0033,

			// UTF-16 Unicode
			UTF16 = 0x0036,

			// UTF-16LE Unicode
			UTF16LE = 0x0038,

			// Windows Arabic
			CP1256 = 0x0039,

			// Windows Baltic
			CP1257 = 0x003B,

			// UTF-32 Unicode
			UTF32 = 0x003C,

			// Binary pseudo charset
			Binary = 0x003F,

			// GEOSTD8 Georgian
			GEOSTD8 = 0x005C,

			// SJIS for Windows Japanese
			CP932 = 0x005F,

			// UJIS for Windows Japanese
			EUCJPMS = 0x0061,

			// China National Standard GB18030
			GB18030 = 0x00F8,

			// UTF-8 Unicode
			UTF8MB4 = 0x00FF
		};
	private:
		friend class Column;
		friend class Result;

		// Accessible from MykokoSQL::Column and MykokoSQL
		Field(const Result* const _res, const unsigned short& _field_indx) noexcept;

		// Accessible from MykokoSQL::Column and MykokoSQL
		Field() noexcept;

		const Result* m_res = nullptr;
		unsigned short m_indx = 0;
		Type m_type = Type::Invalid;
		const char* m_name = nullptr;
		unsigned short m_len = 0;
		const char* m_table_name = nullptr;
		unsigned short m_table_name_len = 0;
		const char* m_db_name = nullptr;
		unsigned short m_db_name_len = 0;
		CharacterSet m_char_set = CharacterSet::Invalid;
	public:

		/**
		* @param _type The field type of which to return its string representation
		* @return The string representation of the given field type
		*/
		static const char* const TypeToString(const Type& _type) noexcept;

		/**
		* @param _char_set The character set of which to return its collation
		* @return The collation of the given character set
		*/
		static const char* const GetCharacterSetCollation(const CharacterSet& _char_set) noexcept;

		/**
		* @return The index of the current field
		*/
		const unsigned short GetIndex() const noexcept;

		/**
		* @return The type of the current field
		*/
		const Type GetType() const noexcept;

		/**
		* @return The field
		*/
		const char* const Get() const noexcept;

		/**
		* @return The length of the current field
		*/
		const unsigned short Length() const noexcept;

		/**
		* @return The table name on which the current field belongs to
		*/
		const char* const GetTableName() const noexcept;

		/**
		* @return The length of the table name on which the current field belongs to
		*/
		const unsigned short GetTableNameLength() const noexcept;

		/**
		* @return The database name on which the current field belongs to
		*/
		const char* const GetDatabaseName() const noexcept;

		/**
		* @return The length of the database name on which the current field belongs to
		*/
		const unsigned short GetDatabaseNameLength() const noexcept;

		/**
		* @return Character set the current field uses
		*/
		const CharacterSet GetCharacterSet() const noexcept;

		/**
		* @return True if the current field is valid
		*/
		operator const bool() const noexcept;
	};

	// Class used to represent a MySQL column
	class Column final{
	private:
		friend class Row;

		// Accessible from MykokoSQL::Row
		Column(const Row* const _row, const unsigned short& _col_indx) noexcept;

		// Accessible from MykokoSQL::Row
		Column() noexcept;

		const Row* m_row = nullptr;
		unsigned short m_indx = 0;
		const char* m_bytes = nullptr;
		unsigned short m_len = 0;
	public:

		/**
		* @return The index of the current column
		*/
		const unsigned short GetIndex() const noexcept;

		/**
		* @return The column
		*/
		const char* const Get() const noexcept;

		/**
		* @return The length of the current column in bytes
		*/
		const unsigned short Length() const noexcept;

		/**
		* @return The field of the current column
		*/
		const Field GetField() const noexcept;

		/**
		* @return True if the current column is NULL
		*/
		const bool IsNull() const noexcept;

		/**
		* @param _col_indx The index of the byte to return
		* @return A byte from the current column
		*/
		const unsigned char operator[](const unsigned short& _byte_indx) const noexcept;

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
	class Row final{
	private:
		friend class Column;
		friend class Result;

		// Accessible from MykokoSQL::Result
		Row(const Result* const _res, const unsigned long long int& _row_indx) noexcept;

		// Accessible from MykokoSQL::Result
		Row() noexcept;

		const Result* m_res = nullptr;
		unsigned long long int m_indx = 0;
	public:

		/**
		* @return The index of the current row
		*/
		const unsigned long long int GetIndex() const noexcept;

		/**
		* @return The number of columns in the current row
		*/
		const unsigned short GetColumnCount() const noexcept;

		/**
		* // Returns a fetched column
		* @param _col_indx The index of the column to return
		* @return The column with the given index
		*/
		const Column operator[](const unsigned short& _col_indx) const noexcept;

		/**
		* // Returns a fetched column
		* @param _col_name The name of the column to return
		* @return The column with the given name
		*/
		const Column operator[](const char* const _col_name) const noexcept;

		/**
		* @return True if the current row is not valid
		*/
		const bool operator!() const noexcept;

		/**
		* @remarks Returns false if the current row belongs to a different result than the given one
		* @param _other Row to compare it with the current one
		* @return True if the current row is equal to the given one
		*/
		const bool operator==(const Row& _other) const noexcept;

		/**
		* @note Used in range-based for loops
		* @remarks Returns false if the current row belongs to a different result than the given one
		* @param _other Row to compare it with the current one
		* @return True if the current row is not equal to the given one
		*/
		const bool operator!=(const Row& _other) const noexcept;

		/**
		* @remarks Returns false if the current row belongs to a different result than the given one
		* @param _other Row to compare it with the current one
		* @return True if the current row is before the given one
		*/
		const bool operator<(const Row& _other) const noexcept;

		/**
		* @remarks Returns false if the current row belongs to a different result than the given one
		* @param _other Row to compare it with the current one
		* @return True if the current row is before or equal to the given one
		*/
		const bool operator<=(const Row& _other) const noexcept;

		/**
		* @remarks Returns false if the current row belongs to a different result than the given one
		* @param _other Row to compare it with the current one
		* @return True if the current row is after the given one
		*/
		const bool operator>(const Row& _other) const noexcept;

		/**
		* @remarks Returns false if the current row belongs to a different result than the given one
		* @param _other Row to compare it with the current one
		* @return True if the current row is after or equal to the given one
		*/
		const bool operator>=(const Row& _other) const noexcept;

		/**
		* @note Used in range-based for loops
		* @return The current row
		*/
		const Row& operator*() const noexcept;

		/**
		* // Returns a row that is as many rows provided, rows after the current one
		* @remarks Returns an invalid row if there are less than as many rows provided, rows after the current one
		* @param _row_indx The number of rows after the current one
		* @return The row that is as many rows provided, rows after the current one
		*/
		const Row operator+(const unsigned long long int& _row_indx) const noexcept;
		
		/**
		* // Sets the current row to the next one
		* @remarks Returns an invalid row if the current row in the last one
		* @note Used in range-based for loops
		* @return The current row
		*/
		const Row& operator++() noexcept;

		/**
		* // Sets the current row to the next one
		* @remarks Returns an invalid row if the current row in the last one
		* @return The current row
		*/
		const Row& operator++(int) noexcept;

		/**
		* // Sets the current row to the row that is as many rows provided, rows after the current one
		* @remarks Returns an invalid row if there are less than as many rows provided, rows after the current one
		* @param _row_indx The number of rows after the current one
		* @return The current row
		*/
		const MykokoSQL::Row& operator+=(const unsigned long long int& _row_indx) noexcept;

		/**
		* // Returns a row that is as many rows provided, rows before the current one
		* @remarks Returns an invalid row if there are less than as many rows provided, rows before the current one
		* @param _row_indx The number of rows before the current one
		* @return The row that is as many rows provided, rows before the current one
		*/
		const Row operator-(const unsigned long long int& _row_indx) const noexcept;

		/**
		* // Sets the current row to the previous one
		* @remarks Returns an invalid row if the current row in the first one
		* @return The current row
		*/
		const Row& operator--() noexcept;

		/**
		* // Sets the current row to the previous one
		* @remarks Returns an invalid row if the current row in the first one
		* @return The current row
		*/
		const Row& operator--(int) noexcept;

		/**
		* // Sets the current row to the row that is as many rows provided, rows before the current one
		* @remarks Returns an invalid row if there are less than as many rows provided, rows before the current one
		* @param _row_indx The number of rows before the current one
		* @return The current row
		*/
		const MykokoSQL::Row& operator-=(const unsigned long long int& _row_indx) noexcept;

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
		* @note Used in range-based for loops
		* @return The first row in the current result
		*/
		const Row begin() const noexcept;

		/**
		* @note Used in range-based for loops
		* @return An invalid row
		*/
		const Row end() const noexcept;

		/**
		* @return The number of rows in the current result
		*/
		const unsigned long long int GetRowCount() const noexcept;

		/**
		* // Returns a fetched row
		* @param _row_indx The index of the row to return
		* @return The row with the given index
		*/
		const Row operator[](const unsigned long long int& _row_indx) const noexcept;

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
		const unsigned short& _port = 0
	) const noexcept;

	/**
	* // Executes the given query
	* @param _query Query to execute
	* @return True if the given query was executed successfully
	*/
	const Result Execute(const char* const _query) const noexcept;

	/**
	* // Executes the given query
	* @param _query Query to execute
	* @param _len Length of query
	* @return True if the given query was successfully executed
	*/
	const Result Execute(const char* const _query, const unsigned long int& _len) const noexcept;

	/**
	* @return The last MySQL error code
	*/
	const unsigned short GetLastErrorCode() const noexcept;

	/**
	* @return The last MySQL error message
	*/
	const char* const GetLastErrorMessage() const noexcept;

	/**
	* @return True if the current MySQL object is valid
	*/
	operator const bool() const noexcept;
};
#include "mykokosql.h"

MykokoSQL::MykokoSQL() noexcept{
	Init();
}

MykokoSQL::~MykokoSQL() noexcept{
	Close();
}

const bool MykokoSQL::__CaseInsensitiveComparison(const char& _ch1, const char& _ch2) noexcept{
	if(_ch1 == _ch2){
		return true;
	}
	else if(isalpha(_ch1) && isalpha(_ch2)){
		return abs(_ch1 - _ch2) == 0 || abs(_ch1 - _ch2) == 32;
	}

	return false;
}

const bool MykokoSQL::Init() noexcept{
	if(! m_db){
		m_db = mysql_init(nullptr);
	}

	return m_db;
}

void MykokoSQL::Close() noexcept{
	if(m_db){
		mysql_close(m_db);
		m_db = nullptr;
	}
}

const bool MykokoSQL::Connect(
	const char* const _host,
	const char* const _user,
	const char* const _password,
	const char* const _db,
	const unsigned short& _port
) const noexcept{
	if(m_db){
		return mysql_real_connect(m_db, _host, _user, _password, _db, _port, nullptr, 0);
	}

	return false;
}

const MykokoSQL::Result MykokoSQL::Execute(const char* const _query) const noexcept{
	if(_query){
		return Execute(_query, static_cast<unsigned int>(strlen(_query)));
	}

	return Result();
}

const MykokoSQL::Result MykokoSQL::Execute(const char* const _query, const unsigned long int& _len) const noexcept{
	if(m_db){
		if(_query){
			if(! mysql_real_query(m_db, _query, _len)){
				return Result(mysql_store_result(m_db));
			}
		}
	}

	return Result();
}

const MykokoSQL::Result MykokoSQL::GetFields(const char* const _table) const noexcept{
	const unsigned int table_len = static_cast<unsigned int>(strnlen_s(_table, 256));
	if(table_len != 256){
		char GET_FIELDS_QUERY[18 + 256 + 1] = {
			0x53, 0x48, 0x4f, 0x57, 0x20,
			0x43, 0x4f, 0x4c, 0x55, 0x4d, 0x4e, 0x53, 0x20,
			0x46, 0x52, 0x4f, 0x4d, 0x20
		};
		strncpy_s(&GET_FIELDS_QUERY[18], 256 + 1, _table, table_len);
		strncpy_s(&GET_FIELDS_QUERY[18 + table_len], 256ull - table_len + 1, &static_cast<const char&>(0x3b), 1);

		return Execute(GET_FIELDS_QUERY, 18 + table_len + 1);
	}

	return Result();
}

const unsigned short MykokoSQL::GetLastErrorCode() const noexcept{
	if(m_db){
		return mysql_errno(m_db);
	}

	return 0;
}

const char* const MykokoSQL::GetLastErrorMessage() const noexcept{
	if(m_db){
		return mysql_error(m_db);
	}

	return "";
}

MykokoSQL::operator const bool() const noexcept{
	return m_db;
}
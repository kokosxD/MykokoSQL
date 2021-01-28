#include "mykokosql.h"

MykokoSQL::MykokoSQL() noexcept{
	Init();
}

MykokoSQL::~MykokoSQL() noexcept{
	Close();
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
	const unsigned int& _port
) noexcept{
	return mysql_real_connect(m_db, _host, _user, _password, _db, _port, nullptr, 0);
}
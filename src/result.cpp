#include "mykokosql.h"

MykokoSQL::Result::Result(MYSQL_RES* const _res) noexcept : m_mysql_res(_res), m_is_valid(true){}

MykokoSQL::Result::Result() noexcept{}

MykokoSQL::Result::~Result() noexcept{
	if(m_mysql_res){
		mysql_free_result(m_mysql_res);
	}
}

const MykokoSQL::Row MykokoSQL::Result::begin() const noexcept{
	return Row(this, 0);
}

const MykokoSQL::Row MykokoSQL::Result::end() const noexcept{
	return Row();
}

const unsigned long long int MykokoSQL::Result::GetRowCount() const noexcept{
	if(m_mysql_res){
		return m_mysql_res->row_count;
	}

	return 0;
}

const MykokoSQL::Field MykokoSQL::Result::GetFields() const noexcept{
	if(m_mysql_res){
		return Field(this, 0);
	}

	return Field();
}

const bool MykokoSQL::Result::HasData() const noexcept{
	return m_mysql_res;
}

const MykokoSQL::Row MykokoSQL::Result::operator[](const unsigned long long int& _row_indx) const noexcept{
	if(m_mysql_res){
		if(_row_indx < m_mysql_res->row_count){
			return Row(this, _row_indx);
		}
	}

	return Row();
}

MykokoSQL::Result::operator const bool() const noexcept{
	return m_is_valid;
}
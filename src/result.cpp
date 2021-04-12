#include "mykokosql.h"

kokos::MykokoSQL::Result::Result(MYSQL_RES* const _res) noexcept : m_mysql_res(_res), m_is_valid(true){}

kokos::MykokoSQL::Result::Result() noexcept{}

kokos::MykokoSQL::Result::~Result() noexcept{
	if(m_mysql_res){
		mysql_free_result(m_mysql_res);
	}
}

const kokos::MykokoSQL::Row kokos::MykokoSQL::Result::begin() const noexcept{
	return Row(this, 0);
}

const kokos::MykokoSQL::Row kokos::MykokoSQL::Result::end() const noexcept{
	return Row();
}

const unsigned long long int kokos::MykokoSQL::Result::GetRowCount() const noexcept{
	if(m_mysql_res){
		return m_mysql_res->row_count;
	}

	return 0;
}

const kokos::MykokoSQL::Field kokos::MykokoSQL::Result::GetFields() const noexcept{
	if(m_mysql_res){
		return Field(this, 0);
	}

	return Field();
}

const bool kokos::MykokoSQL::Result::HasData() const noexcept{
	return m_mysql_res;
}

const kokos::MykokoSQL::Row kokos::MykokoSQL::Result::operator[](const unsigned long long int& _row_indx) const noexcept{
	if(m_mysql_res){
		if(_row_indx < m_mysql_res->row_count){
			return Row(this, _row_indx);
		}
	}

	return Row();
}

const bool kokos::MykokoSQL::Result::operator!() const noexcept{
	return ! operator const bool();
}

const bool kokos::MykokoSQL::Result::operator==(const Result& _other) const noexcept{
	return m_mysql_res == _other.m_mysql_res;
}

const bool kokos::MykokoSQL::Result::operator!=(const Result& _other) const noexcept{
	return ! operator==(_other);
}

kokos::MykokoSQL::Result::operator const bool() const noexcept{
	return m_is_valid;
}
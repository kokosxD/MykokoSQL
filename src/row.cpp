#include "mykokosql.h"

MykokoSQL::Row::Row(const Result* const _res, const unsigned long long int& _row_indx) noexcept : m_res(_res), m_indx(_row_indx){}

MykokoSQL::Row::Row() noexcept{}

const unsigned long long int MykokoSQL::Row::GetIndex() const noexcept{
	return m_indx;
}

const unsigned int MykokoSQL::Row::GetColumnCount() const noexcept{
	if(m_res){
		if(m_res->m_mysql_res){
			return m_res->m_mysql_res->field_count;
		}
	}

	return 0;
}

const MykokoSQL::Column MykokoSQL::Row::operator[](const unsigned int& _col_indx) const noexcept{
	if(m_res){
		if(m_res->m_mysql_res){
			if(_col_indx < m_res->m_mysql_res->field_count){
				return Column(this, _col_indx);
			}
		}
	}

	return Column();
}

const MykokoSQL::Column MykokoSQL::Row::operator[](const char* const _col_name) const noexcept{
	if(m_res){
		if(m_res->m_mysql_res){
			if(m_res->m_mysql_res->fields){
				const unsigned int col_name_len = static_cast<unsigned int>(strlen(_col_name));
				for(unsigned int col_indx = 0; col_indx < m_res->m_mysql_res->field_count; col_indx++){
					if(m_res->m_mysql_res->fields[col_indx].name_length == col_name_len){
						for(unsigned int character = 0; character < col_name_len; character++){
							if(! __CaseInsensitiveComparison(m_res->m_mysql_res->fields[col_indx].name[character], _col_name[character])){
								goto next_column;
							}
						}

						return Column(this, col_indx);
					}

				next_column:;
				}
			}
		}
	}

	return Column();
}

const bool MykokoSQL::Row::operator!() const noexcept{
	return ! m_res;
}

const bool MykokoSQL::Row::operator==(const Row& _other) const noexcept{
	return m_res == _other.m_res && m_indx == _other.m_indx;
}

const bool MykokoSQL::Row::operator!=(const Row& _other) const noexcept{
	return ! operator==(_other);
}

const bool MykokoSQL::Row::operator<(const Row& _other) const noexcept{
	if(m_res == _other.m_res){
		return m_indx < _other.m_indx;
	}

	return false;
}

const bool MykokoSQL::Row::operator<=(const Row& _other) const noexcept{
	return operator<(_other) || operator==(_other);
}

const bool MykokoSQL::Row::operator>(const Row& _other) const noexcept{
	if(m_res == _other.m_res){
		return m_indx > _other.m_indx;
	}

	return false;
}

const bool MykokoSQL::Row::operator>=(const Row& _other) const noexcept{
	return operator>(_other) || operator==(_other);
}

const MykokoSQL::Row& MykokoSQL::Row::operator*() const noexcept{
	return *this;
}

const MykokoSQL::Row MykokoSQL::Row::operator+(const unsigned long long int& _row_indx) const noexcept{
	Row next_row = *this;
	next_row += _row_indx;
	return next_row;
}

const MykokoSQL::Row& MykokoSQL::Row::operator++() noexcept{
	return operator+=(1);
}

const MykokoSQL::Row& MykokoSQL::Row::operator++(int) noexcept{
	return operator++();
}

const MykokoSQL::Row& MykokoSQL::Row::operator+=(const unsigned long long int& _row_indx) noexcept{
	if(m_res){
		if(m_res->m_mysql_res){
			if(m_indx + _row_indx < m_res->m_mysql_res->row_count){
				return *this = Row(m_res, m_indx + _row_indx);
			}
			
			return *this = Row();
		}
	}

	return *this;
}

const MykokoSQL::Row MykokoSQL::Row::operator-(const unsigned long long int& _row_indx) const noexcept{
	Row prev_row = *this;
	prev_row -= _row_indx;
	return prev_row;
}

const MykokoSQL::Row& MykokoSQL::Row::operator--() noexcept{
	return operator-=(1);
}

const MykokoSQL::Row& MykokoSQL::Row::operator--(int) noexcept{
	return operator--();
}

const MykokoSQL::Row& MykokoSQL::Row::operator-=(const unsigned long long int& _row_indx) noexcept{
	if(m_res){
		if(m_res->m_mysql_res){
			if(m_indx >= _row_indx){
				return *this = Row(m_res, m_indx - _row_indx);
			}

			return *this = Row();
		}
	}

	return *this;
}

MykokoSQL::Row::operator const bool() const noexcept{
	return m_res;
}
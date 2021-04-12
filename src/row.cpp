#include "mykokosql.h"

kokos::MykokoSQL::Row::Row(const Result* const _res, const unsigned long long int& _row_indx) noexcept{
	if(_res){
		if(_res->m_mysql_res){
			if(_row_indx < _res->m_mysql_res->row_count){
				m_res = _res;
				m_indx = _row_indx;
			}
		}
	}
}

kokos::MykokoSQL::Row::Row() noexcept{}

const unsigned long long int kokos::MykokoSQL::Row::GetIndex() const noexcept{
	return m_indx;
}

const unsigned short kokos::MykokoSQL::Row::GetColumnCount() const noexcept{
	if(m_res){
		if(m_res->m_mysql_res){
			return m_res->m_mysql_res->field_count;
		}
	}

	return 0;
}

const kokos::MykokoSQL::Column kokos::MykokoSQL::Row::operator[](const unsigned short& _col_indx) const noexcept{
	if(m_res){
		if(m_res->m_mysql_res){
			if(_col_indx < m_res->m_mysql_res->field_count){
				return Column(this, _col_indx);
			}
		}
	}

	return Column();
}

const kokos::MykokoSQL::Column kokos::MykokoSQL::Row::operator[](const char* const _col_name) const noexcept{
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

const bool kokos::MykokoSQL::Row::operator!() const noexcept{
	return ! operator const bool();
}

const bool kokos::MykokoSQL::Row::operator==(const Row& _other) const noexcept{
	return m_res == _other.m_res && m_indx == _other.m_indx;
}

const bool kokos::MykokoSQL::Row::operator!=(const Row& _other) const noexcept{
	return ! operator==(_other);
}

const bool kokos::MykokoSQL::Row::operator<(const Row& _other) const noexcept{
	if(m_res == _other.m_res){
		return m_indx < _other.m_indx;
	}

	return false;
}

const bool kokos::MykokoSQL::Row::operator<=(const Row& _other) const noexcept{
	return operator<(_other) || operator==(_other);
}

const bool kokos::MykokoSQL::Row::operator>(const Row& _other) const noexcept{
	if(m_res == _other.m_res){
		return m_indx > _other.m_indx;
	}

	return false;
}

const bool kokos::MykokoSQL::Row::operator>=(const Row& _other) const noexcept{
	return operator>(_other) || operator==(_other);
}

const kokos::MykokoSQL::Row& kokos::MykokoSQL::Row::operator*() const noexcept{
	return *this;
}

const kokos::MykokoSQL::Row kokos::MykokoSQL::Row::operator+(const unsigned long long int& _row_indx) const noexcept{
	Row next_row = *this;
	return next_row += _row_indx;
}

const kokos::MykokoSQL::Row& kokos::MykokoSQL::Row::operator++() noexcept{
	return operator+=(1);
}

const kokos::MykokoSQL::Row& kokos::MykokoSQL::Row::operator++(int) noexcept{
	return operator++();
}

const kokos::MykokoSQL::Row& kokos::MykokoSQL::Row::operator+=(const unsigned long long int& _row_indx) noexcept{
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

const kokos::MykokoSQL::Row kokos::MykokoSQL::Row::operator-(const unsigned long long int& _row_indx) const noexcept{
	Row prev_row = *this;
	return prev_row -= _row_indx;
}

const kokos::MykokoSQL::Row& kokos::MykokoSQL::Row::operator--() noexcept{
	return operator-=(1);
}

const kokos::MykokoSQL::Row& kokos::MykokoSQL::Row::operator--(int) noexcept{
	return operator--();
}

const kokos::MykokoSQL::Row& kokos::MykokoSQL::Row::operator-=(const unsigned long long int& _row_indx) noexcept{
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

kokos::MykokoSQL::Row::operator const bool() const noexcept{
	return m_res;
}
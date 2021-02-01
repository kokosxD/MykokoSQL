#include "mykokosql.h"

MykokoSQL::Row::Row(const Result* const _res, const unsigned int& _row_indx) noexcept : m_res(_res), m_indx(_row_indx){}

MykokoSQL::Row::Row() noexcept{}

const unsigned int MykokoSQL::Row::GetIndex() const noexcept{
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
					if(m_res->m_mysql_res->fields[col_indx].length == col_name_len){
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

MykokoSQL::Row::operator const bool() const noexcept{
	return m_res;
}
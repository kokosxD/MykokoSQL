#include "mykokosql.h"

kokos::MykokoSQL::Column::Column(const Row* const _row, const unsigned short& _col_indx) noexcept{
	if(_row){
		if(_row->m_res){
			if(_row->m_res->m_mysql_res){
				if(_row->m_res->m_mysql_res->data){
					if(_row->m_res->m_mysql_res->data->data){

						// Get column row
						MYSQL_ROWS* last_row = _row->m_res->m_mysql_res->data->data;
						for(unsigned int row_indx = 0; row_indx < _row->m_indx; row_indx++){

							// Expected row but no more rows are available
							if(! last_row->next){
								return;
							}

							last_row = last_row->next;
						}
						m_row = _row;
						m_indx = _col_indx;

						// Column is not NULL
						if(m_bytes = last_row->data[m_indx]){

							// Skip any NULL columns
							unsigned int next_non_null_col = m_indx + 1;
							while(! last_row->data[next_non_null_col]){
								next_non_null_col++;
							}
							m_len = static_cast<unsigned short>(last_row->data[next_non_null_col] - last_row->data[m_indx] - 1);
						}

						// NULL column
						else{
							m_bytes = "";
						}

						return;
					}
				}
			}
		}
	}

	m_bytes = "";
}

kokos::MykokoSQL::Column::Column() noexcept : m_bytes(""){}

const unsigned short kokos::MykokoSQL::Column::GetIndex() const noexcept{
	return m_indx;
}

const char* const kokos::MykokoSQL::Column::Get() const noexcept{
	return m_bytes;
}

const unsigned short kokos::MykokoSQL::Column::Length() const noexcept{
	return m_len;
}

const kokos::MykokoSQL::Field kokos::MykokoSQL::Column::GetField() const noexcept{
	if(m_row){
		if(m_row->m_res){
			if(m_row->m_res->m_mysql_res){
				return Field(m_row->m_res, m_indx);
			}
		}
	}

	return Field();
}

const bool kokos::MykokoSQL::Column::IsNull() const noexcept{
	return m_bytes == "" && ! m_len;
}

const unsigned char kokos::MykokoSQL::Column::operator[](const unsigned short& _byte_indx) const noexcept{
	if(m_bytes){
		if(_byte_indx <= m_len){
			return m_bytes[_byte_indx];
		}
	}

	return static_cast<char>(0x00);
}

kokos::MykokoSQL::Column::operator const char* const() const noexcept{
	return m_bytes;
}

kokos::MykokoSQL::Column::operator const bool() const noexcept{
	return m_row && m_bytes;
}
#include "mykokosql.h"

MykokoSQL::Field::Field(const Result* const _res, const unsigned short& _field_indx) noexcept{
	if(_res){
		if(_res->m_mysql_res){
			if(_res->m_mysql_res->fields){
				if(_field_indx < _res->m_mysql_res->field_count){
					m_res = _res;
					m_indx = _field_indx;
					m_type = static_cast<Type>(_res->m_mysql_res->fields[_field_indx].type);
					m_name = _res->m_mysql_res->fields[_field_indx].name;
					m_len = static_cast<unsigned short>(_res->m_mysql_res->fields[_field_indx].name_length);
					m_table_name = _res->m_mysql_res->fields[_field_indx].table;
					m_table_name_len = static_cast<unsigned short>(_res->m_mysql_res->fields[_field_indx].table_length);
					m_db_name = _res->m_mysql_res->fields[_field_indx].db;
					m_db_name_len = static_cast<unsigned short>(_res->m_mysql_res->fields[_field_indx].db_length);
					m_char_set = static_cast<CharacterSet>(_res->m_mysql_res->fields[_field_indx].charsetnr);
					return;
				}
			}
		}
	}

	m_name = "";
	m_table_name = "";
	m_db_name = "";
}

MykokoSQL::Field::Field() noexcept : m_name(""), m_table_name(""), m_db_name(""){}

const char* const MykokoSQL::Field::TypeToString(const Type& _type) noexcept{
	switch(_type){
		case MykokoSQL::Field::Type::Invalid:
		{
			return "";
		}
		case MykokoSQL::Field::Type::TinyInt:
		{
			return "TINYINT";
		}
		case MykokoSQL::Field::Type::SmallInt:
		{
			return "SMALLINT";
		}
		case MykokoSQL::Field::Type::Long:
		{
			return "LONG";
		}
		case MykokoSQL::Field::Type::Float:
		{
			return "FLOAT";
		}
		case MykokoSQL::Field::Type::Double:
		{
			return "DOUBLE";
		}
		case MykokoSQL::Field::Type::Null:
		{
			return "NULL";
		}
		case MykokoSQL::Field::Type::TimeStamp:
		{
			return "TIMESTAMP";
		}
		case MykokoSQL::Field::Type::BigInt:
		{
			return "BIGINT";
		}
		case MykokoSQL::Field::Type::MediumInt:
		{
			return "MEDIUMINT";
		}
		case MykokoSQL::Field::Type::Date:
		{
			return "DATE";
		}
		case MykokoSQL::Field::Type::Time:
		{
			return "TIME";
		}
		case MykokoSQL::Field::Type::DateTime:
		{
			return "DATETIME";
		}
		case MykokoSQL::Field::Type::Year:
		{
			return "YEAR";
		}
		case MykokoSQL::Field::Type::VarChar:
		{
			return "VARCHAR";
		}
		case MykokoSQL::Field::Type::Bit:
		{
			return "BIT";
		}
		case MykokoSQL::Field::Type::JSON:
		{
			return "JSON";
		}
		case MykokoSQL::Field::Type::Decimal:
		{
			return "DECIMAL";
		}
		case MykokoSQL::Field::Type::Enum:
		{
			return "ENUM";
		}
		case MykokoSQL::Field::Type::Set:
		{
			return "SET";
		}
		case MykokoSQL::Field::Type::TinyBlob:
		{
			return "TINYBLOB";
		}
		case MykokoSQL::Field::Type::MediumBlob:
		{
			return "MEDIUMBLOB";
		}
		case MykokoSQL::Field::Type::LongBlob:
		{
			return "LONGBLOB";
		}
		case MykokoSQL::Field::Type::Blob:
		{
			return "BLOB";
		}
		case MykokoSQL::Field::Type::VarString:
		{
			return "VARSTRING";
		}
		case MykokoSQL::Field::Type::String:
		{
			return "STRING";
		}
		case MykokoSQL::Field::Type::Geometry:
		{
			return "GEOMETRY";
		}
		default:
		{
			return "";
		}
	}
}

const char* const MykokoSQL::Field::GetCharacterSetCollation(const CharacterSet& _char_set) noexcept{
	switch(_char_set){
		case MykokoSQL::Field::CharacterSet::Invalid:
		{
			return "";
		}
		case MykokoSQL::Field::CharacterSet::Big5:
		{
			return "big5_chinese_ci";
		}
		case MykokoSQL::Field::CharacterSet::DEC8:
		{
			return "dec8_swedish_ci";
		}
		case MykokoSQL::Field::CharacterSet::CP850:
		{
			return "cp850_general_ci";
		}
		case MykokoSQL::Field::CharacterSet::HP8:
		{
			return "hp8_english_ci";
		}
		case MykokoSQL::Field::CharacterSet::KOI8R:
		{
			return "koi8r_general_ci";
		}
		case MykokoSQL::Field::CharacterSet::Latin1:
		{
			return "latin1_swedish_ci";
		}
		case MykokoSQL::Field::CharacterSet::Latin2:
		{
			return "latin2_general_ci";
		}
		case MykokoSQL::Field::CharacterSet::Swe7:
		{
			return "swe7_swedish_ci";
		}
		case MykokoSQL::Field::CharacterSet::ASCII:
		{
			return "ascii_general_ci";
		}
		case MykokoSQL::Field::CharacterSet::UJIS:
		{
			return "ujis_japanese_ci";
		}
		case MykokoSQL::Field::CharacterSet::SJIS:
		{
			return "sjis_japanese_ci";
		}
		case MykokoSQL::Field::CharacterSet::Hebrew:
		{
			return "hebrew_general_ci";
		}
		case MykokoSQL::Field::CharacterSet::TIS620:
		{
			return "tis620_thai_ci";
		}
		case MykokoSQL::Field::CharacterSet::EUCKR:
		{
			return "euckr_korean_ci";
		}
		case MykokoSQL::Field::CharacterSet::KOI8U:
		{
			return "koi8u_general_ci";
		}
		case MykokoSQL::Field::CharacterSet::GB2312:
		{
			return "gb2312_chinese_ci";
		}
		case MykokoSQL::Field::CharacterSet::Greek:
		{
			return "greek_general_ci";
		}
		case MykokoSQL::Field::CharacterSet::CP1250:
		{
			return "cp1250_general_ci";
		}
		case MykokoSQL::Field::CharacterSet::GBK:
		{
			return "gbk_chinese_ci";
		}
		case MykokoSQL::Field::CharacterSet::Latin5:
		{
			return "latin5_turkish_ci";
		}
		case MykokoSQL::Field::CharacterSet::ArmSCII8:
		{
			return "armscii8_general_ci";
		}
		case MykokoSQL::Field::CharacterSet::UTF8:
		{
			return "utf8_general_ci";
		}
		case MykokoSQL::Field::CharacterSet::UCS2:
		{
			return "ucs2_general_ci";
		}
		case MykokoSQL::Field::CharacterSet::CP866:
		{
			return "cp866_general_ci";
		}
		case MykokoSQL::Field::CharacterSet::KEYBCS2:
		{
			return "keybcs2_general_ci";
		}
		case MykokoSQL::Field::CharacterSet::MacCE:
		{
			return "macce_general_ci";
		}
		case MykokoSQL::Field::CharacterSet::Macroman:
		{
			return "macroman_general_ci";
		}
		case MykokoSQL::Field::CharacterSet::CP852:
		{
			return "cp852_general_ci";
		}
		case MykokoSQL::Field::CharacterSet::Latin7:
		{
			return "latin7_general_ci";
		}
		case MykokoSQL::Field::CharacterSet::CP1251:
		{
			return "cp1251_general_ci";
		}
		case MykokoSQL::Field::CharacterSet::UTF16:
		{
			return "utf16_general_ci";
		}
		case MykokoSQL::Field::CharacterSet::UTF16LE:
		{
			return "utf16le_general_ci";
		}
		case MykokoSQL::Field::CharacterSet::CP1256:
		{
			return "cp1256_general_ci";
		}
		case MykokoSQL::Field::CharacterSet::CP1257:
		{
			return "cp1257_general_ci";
		}
		case MykokoSQL::Field::CharacterSet::UTF32:
		{
			return "utf32_general_ci";
		}
		case MykokoSQL::Field::CharacterSet::Binary:
		{
			return "binary";
		}
		case MykokoSQL::Field::CharacterSet::GEOSTD8:
		{
			return "geostd8_general_ci";
		}
		case MykokoSQL::Field::CharacterSet::CP932:
		{
			return "cp932_japanese_ci";
		}
		case MykokoSQL::Field::CharacterSet::EUCJPMS:
		{
			return "eucjpms_japanese_ci";
		}
		case MykokoSQL::Field::CharacterSet::GB18030:
		{
			return "gb18030_chinese_ci";
		}
		case MykokoSQL::Field::CharacterSet::UTF8MB4:
		{
			return "utf8mb4_0900_ai_ci";
		}
		default:
		{
			return "";
		}
	}
}

const MykokoSQL::Field MykokoSQL::Field::begin() const noexcept{
	return Field(m_res, 0);
}

const MykokoSQL::Field MykokoSQL::Field::end() const noexcept{
	return Field();
}

const unsigned short MykokoSQL::Field::GetIndex() const noexcept{
	return m_indx;
}

const MykokoSQL::Field::Type MykokoSQL::Field::GetType() const noexcept{
	return m_type;
}

const char* const MykokoSQL::Field::Get() const noexcept{
	return m_name;
}

const unsigned short MykokoSQL::Field::Length() const noexcept{
	return m_len;
}

const char* const MykokoSQL::Field::GetTableName() const noexcept{
	return m_table_name;
}

const unsigned short MykokoSQL::Field::GetTableNameLength() const noexcept{
	return m_table_name_len;
}

const char* const MykokoSQL::Field::GetDatabaseName() const noexcept{
	return m_db_name;
}

const unsigned short MykokoSQL::Field::GetDatabaseNameLength() const noexcept{
	return m_db_name_len;
}

const MykokoSQL::Field::CharacterSet MykokoSQL::Field::GetCharacterSet() const noexcept{
	return m_char_set;
}

const bool MykokoSQL::Field::operator!() const noexcept{
	return ! operator const bool();
}

const bool MykokoSQL::Field::operator==(const Field& _other) const noexcept{
	return
		m_res == _other.m_res &&
		m_indx == _other.m_indx &&
		m_type == _other.m_type &&
		m_name == _other.m_name &&
		m_table_name == _other.m_table_name &&
		m_db_name == _other.m_db_name &&
		m_char_set == _other.m_char_set
	;
}

const bool MykokoSQL::Field::operator!=(const Field& _other) const noexcept{
	return ! operator==(_other);
}

const bool MykokoSQL::Field::operator<(const Field& _other) const noexcept{
	if(
		m_res == _other.m_res &&
		m_table_name == _other.m_table_name &&
		m_db_name == _other.m_db_name &&
		m_char_set == _other.m_char_set
	){
		return m_indx < _other.m_indx;
	}

	return false;
}

const bool MykokoSQL::Field::operator<=(const Field& _other) const noexcept{
	return operator<(_other) || operator==(_other);
}

const bool MykokoSQL::Field::operator>(const Field& _other) const noexcept{
	if(
		m_res == _other.m_res &&
		m_table_name == _other.m_table_name &&
		m_db_name == _other.m_db_name &&
		m_char_set == _other.m_char_set
	){
		return m_indx > _other.m_indx;
	}

	return false;
}

const bool MykokoSQL::Field::operator>=(const Field& _other) const noexcept{
	return operator>(_other) || operator==(_other);
}

const MykokoSQL::Field& MykokoSQL::Field::operator*() const noexcept{
	return *this;
}

const MykokoSQL::Field MykokoSQL::Field::operator+(const unsigned int& _field_indx) const noexcept{
	Field next_field = *this;
	return next_field += _field_indx;
}

const MykokoSQL::Field& MykokoSQL::Field::operator++() noexcept{
	return operator+=(1);
}

const MykokoSQL::Field& MykokoSQL::Field::operator++(int) noexcept{
	return operator++();
}

const MykokoSQL::Field& MykokoSQL::Field::operator+=(const unsigned int& _field_indx) noexcept{
	if(m_res){
		if(m_res->m_mysql_res){
			if(m_indx + _field_indx < m_res->m_mysql_res->field_count){
				return *this = Field(m_res, m_indx + _field_indx);
			}
		}

		return *this = Field();
	}

	return *this;
}

const MykokoSQL::Field MykokoSQL::Field::operator-(const unsigned int& _field_indx) const noexcept{
	Field prev_field = *this;
	return prev_field -= _field_indx;
}

const MykokoSQL::Field& MykokoSQL::Field::operator--() noexcept{
	return operator-=(1);
}

const MykokoSQL::Field& MykokoSQL::Field::operator--(int) noexcept{
	return operator--();
}

const MykokoSQL::Field& MykokoSQL::Field::operator-=(const unsigned int& _field_indx) noexcept{
	if(m_res){
		if(m_indx >= _field_indx){
			return *this = Field(m_res, m_indx - _field_indx);
		}

		return *this = Field();
	}

	return *this;
}

MykokoSQL::Field::operator const bool() const noexcept{
	return m_type != Type::Invalid && m_name && m_len && m_table_name && m_table_name_len && m_db_name && m_db_name_len && m_char_set != CharacterSet::Invalid;
}
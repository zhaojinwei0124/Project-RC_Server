////////////////////////////////////////////////////////////////////////////////////////
//
//             时间：11:08 2013-11-15 
//			   说明：玩家数据存储
//
//
/////////////////////////////////////////////////////////////////////////////////////////
#ifndef _ODBC_CITYDATA_H_
#define _ODBC_CITYDATA_H_

#include "Base.h"
#include "DataBase/ODBCBase.h"
#include "DBStruct/DBStruct_City.h"

class ODBCCityData:public ODBCBase
{
private: 
	int64   m_UserId;
public:
	ODBCCityData(ODBCInterface* pInterface);

	virtual bool	Load();
	virtual bool	Save(DBCity* pSource);
	virtual bool	ParseResult(DBCity* pResult);

public:
	void            SetUserId(int64 UserId);
	int64           GetUserId();
};

#endif
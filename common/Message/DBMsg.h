/*
	功能说明：数据存储相关所有消息
*/
#ifndef _DBMSG_H_
#define _DBMSG_H_

#include "service/Message.h"
#include "service/BaseService.h"
#include "../DBManage/DBTask/DBBaseTask.h"
#include "DBStruct/DBStruct_User.h"
#include "DBStruct/DBStruct_WordMap.h"

//////////////////////////////////////////////////////////////
// 分配存储任务消息
/////////////////////////////////////////////////////////////
MESSAGE_DEF_BEGIN(DBAssignTaskMsg)
	DBBaseTaskPtr m_DBBaseTaskPtr;
MESSAGE_DEF_END(DBAssignTaskMsg)

//////////////////////////////////////////////////////////////
// 检测数据库是否连接消息
/////////////////////////////////////////////////////////////
MESSAGE_DEF_BEGIN(DBCheckConnectMsg)
MESSAGE_DEF_END(DBCheckConnectMsg)

//////////////////////////////////////////////////////////////
// 加载玩家数据消息
/////////////////////////////////////////////////////////////
MESSAGE_DEF_BEGIN(DBLoadUserMsg)
	int64          m_UserGuid;        //玩家的uid
	string    m_UserName;       // 玩家名称 
	DBFullUserData m_UserData;      // 玩家的数据
MESSAGE_DEF_END(DBLoadUserMsg);

//////////////////////////////////////////////////////////////
// 返回玩家数据消息
/////////////////////////////////////////////////////////////
MESSAGE_DEF_BEGIN(DBRetLoadUserMsg)
	int64          m_UserGuid;        //玩家的uid
	string         m_UserName;       // 玩家名称 
	DBFullUserData m_UserData;      // 玩家的数据
	int            m_nResult;       // 返回结果
MESSAGE_DEF_END(DBRetLoadUserMsg);

//////////////////////////////////////////////////////////////
// 保存玩家数据消息
/////////////////////////////////////////////////////////////
MESSAGE_DEF_BEGIN(DBSaveUserMsg)
	int64          m_UserGuid;        //玩家的uid
	DBFullUserData m_UserData;      // 玩家的数据
	int            m_nResult;       // 返回结果
	bool           m_bImmediateSave;
	bool           m_bFinalSave;
MESSAGE_DEF_END(DBSaveUserMsg);

//////////////////////////////////////////////////////////////
// 返回保存玩家数据消息
/////////////////////////////////////////////////////////////
MESSAGE_DEF_BEGIN(DBRetSaveUserMsg)
	int64          m_UserGuid;        //玩家的uid
	int            m_nResult;       // 返回结果
	bool           m_bImmediateSave;
	bool           m_bFinalSave;
MESSAGE_DEF_END(DBRetSaveUserMsg);

//////////////////////////////////////////////////////////////
// 创建角色消息
/////////////////////////////////////////////////////////////
MESSAGE_DEF_BEGIN(DBCreateCharMsg)
	int64          m_UserGuid;        //玩家的uid
	string         m_UserName;       // 玩家名称 
	DBFullUserData m_UserData;      // 玩家的数据
MESSAGE_DEF_END(DBCreateCharMsg);

//////////////////////////////////////////////////////////////
// 返回创建角色消息
/////////////////////////////////////////////////////////////
MESSAGE_DEF_BEGIN(DBRetCreateCharMsg)
	int64          m_UserGuid;        //玩家的uid
	string         m_UserName;       // 玩家名称 
	DBFullUserData m_UserData;      // 玩家的数据
	int            m_nResult;       // 返回结果
MESSAGE_DEF_END(DBRetCreateCharMsg);

//////////////////////////////////////////////////////////////
// 数据操作结果返回消息
/////////////////////////////////////////////////////////////
MESSAGE_DEF_BEGIN(DBOpRetMsg)
	int          m_OpRet;;        
	int          m_OpType;       
	int64        m_Key;     
	int          m_TaskType;   
	int          m_ReqOpTime;
MESSAGE_DEF_END(DBOpRetMsg);

//////////////////////////////////////////////////////////////
// 请求地块信息
/////////////////////////////////////////////////////////////
MESSAGE_DEF_BEGIN(DBReqLoadTileDataMsg)
	
MESSAGE_DEF_END(DBReqLoadTileDataMsg)

//////////////////////////////////////////////////////////////
// 请求地块返回消息
/////////////////////////////////////////////////////////////
MESSAGE_DEF_BEGIN(DBRetLoadTileDataMsg)
	DBTileDataPtr m_DataPtr;
	int m_nResult;
MESSAGE_DEF_END(DBRetLoadTileDataMsg)

//////////////////////////////////////////////////////////////
// 请求保存地块信息
/////////////////////////////////////////////////////////////
MESSAGE_DEF_BEGIN(DBReqSaveTileDataMsg)
	DBTileDataPtr m_DataPtr;
MESSAGE_DEF_END(DBReqSaveTileDataMsg)

//////////////////////////////////////////////////////////////
// 保存地块操作返回消息
/////////////////////////////////////////////////////////////
MESSAGE_DEF_BEGIN(DBRetSaveTileDataMsg)
	int m_nResult;
MESSAGE_DEF_END(DBRetSaveTileDataMsg)

//////////////////////////////////////////////////////////////
// 请求保存地块信息
/////////////////////////////////////////////////////////////
MESSAGE_DEF_BEGIN(DBReqSaveCityDataMsg)
	DBTileDataPtr m_DataPtr;
MESSAGE_DEF_END(DBReqSaveTileDataMsg)



#endif
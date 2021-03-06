#include "DBStruct_March.h"
#include "march/GameDefine_March.h"
#include "GuidDefine.h"
void DBMarch::CleanUp( )
{
	__ENTER_FUNCTION
		m_Hero.CleanUp();
		for (int i=0;i<TROOP_QUEUE_MAX_COUNT;i++)
		{
			m_TroopList[i].CleanUp();
		}
		m_pos.CleanUp();
		m_nBeginTime = 0; // 出发时间
		m_nEndTime = 0;   // 返回时间
		m_nMarchId = 0;   // 唯一标示
		m_nPlayerId = 0;;  // 玩家ID
		m_nCityId = 0;    // 城市ID
		m_nStatus = MARCHSTATUS_INVALID;    // 状态
		m_nBuildId = invalid_guid64;
		m_nInstSceneId = invalid_id;
		m_nClassSceneId = invalid_id;
	__LEAVE_FUNCTION
}
void DBMarch::CopyFrom(const DBMarch& rSource)
{
	__ENTER_FUNCTION
		CleanUp();
		m_Hero.CopyFrom(rSource.m_Hero);

		for (int i=0;i<TROOP_QUEUE_MAX_COUNT;i++)
		{
			m_TroopList[i].CopyFrom(rSource.m_TroopList[i]);
		}

		m_pos        = rSource.m_pos;
		m_nBeginTime = rSource.m_nBeginTime;
		m_nEndTime   = rSource.m_nEndTime;
		m_nMarchId   = rSource.m_nMarchId;
		m_nPlayerId  = rSource.m_nPlayerId;
		m_nCityId    = rSource.m_nCityId;
		m_nStatus    = rSource.m_nStatus;
		m_nBuildId   = rSource.m_nBuildId;
		m_nInstSceneId = rSource.m_nInstSceneId;
		m_nClassSceneId= rSource.m_nClassSceneId;
	__LEAVE_FUNCTION
}

void DBMarch::InitMarch(int64 userId,int64 cityId,int64 buildId)
{
	CleanUp();
	m_nMarchId = GUIDDEF_GEN(March);


	for (int i=0;i<TROOP_QUEUE_MAX_COUNT;i++)
	{
		m_TroopList[i].InitTroop(i,i,m_nMarchId);
	}

	m_nPlayerId = userId;
	m_nCityId   = cityId;
	m_nStatus   = MARCHSTATUS_IDLE;
	m_nBuildId  = buildId;

}

void DBMapMarch::CleanUp()
{
	m_MarchList.clear();
}
void DBMapMarch::CopyFrom(const DBMapMarch& rSource)
{
	int iSize = (int)rSource.m_MarchList.size();
	m_MarchList.reserve(iSize);
	for (int i=0;i<iSize;i++)
	{
		m_MarchList[i].CopyFrom(rSource.m_MarchList[i]);
	}
}


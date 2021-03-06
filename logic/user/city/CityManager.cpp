
#include "../User.h"
#include "CityManager.h"
#include "Message/DBMsg.h"
#include "service/MessageOp.h"
#include "packet/Packet/GC_BUILDING_LEVELUP_PAK.h"


/////////arrange function///////////////
CityManager::CityManager(User &rUser)
	: BaseManager(rUser)
{
	m_CityPtr = CityPtr(new City());
	
}
CityManager::~CityManager(void)
{

}

void CityManager::Init()
{
	__ENTER_FUNCTION
		

	__LEAVE_FUNCTION
}

void CityManager::OnLogin()
{
	__ENTER_FUNCTION
		AssertEx(m_CityPtr,"");
	m_CityPtr->OnLogin();
	__LEAVE_FUNCTION
}

ScenePos CityManager::GetPos()
{
	ScenePos rPos;
	rPos.m_fX = m_CityPtr->GetPosX();
	rPos.m_fZ = m_CityPtr->GetPosZ();
	return rPos;
}

void  CityManager::Tick(const TimeInfo& rTimeInfo)
{
	__ENTER_FUNCTION
		AssertEx(m_CityPtr,"");
	m_CityPtr->Tick(rTimeInfo);
	__LEAVE_FUNCTION
}

void CityManager::SerializeFromDB(const DBFullUserData& rSource)
{
	__ENTER_FUNCTION
		AssertEx(m_CityPtr,"");
		m_CityPtr->SerializeFromDB(rSource.m_City);
	__LEAVE_FUNCTION
}
void CityManager::SerializeToDB(DBFullUserData& rDesc)
{
	__ENTER_FUNCTION
		AssertEx(m_CityPtr,"");
		m_CityPtr->SerializeToDB(rDesc.m_City);
	__LEAVE_FUNCTION
}


bool  CityManager::CheckSendMarchIntoMap(int64 nBuildId)
{
	__ENTER_FUNCTION
		AssertEx(m_CityPtr,"");
	return m_CityPtr->CheckSendMarchIntoMap(nBuildId);
	__LEAVE_FUNCTION
		return false;
}

bool  CityManager::BeginTrainTroop(int64 nBuildId,int nQueueIndex,int nType,int Count,GC_Troop_Train* pMessage)
{
	__ENTER_FUNCTION
		AssertEx(m_CityPtr,"");
	bool ret = m_CityPtr->BeginTrainTroop(nBuildId,nQueueIndex,nType,Count,pMessage->mutable_data());
		if (ret)
		{
			
			pMessage->set_ret(0);
		}
		else
		{
			pMessage->set_ret(1);
		}
		return ret;

	__LEAVE_FUNCTION
		return false;
}

bool CityManager::BuildLevelUp(int64 nBuildId,GC_Building_LevelUp* pMessage)
{
	__ENTER_FUNCTION
		AssertEx(m_CityPtr,"");
		
	bool bRet = m_CityPtr->BuildingLevelUp(nBuildId);
	pMessage->set_buildingid(nBuildId);
	if (bRet)
	{
		
		pMessage->set_ret(0);
	}
	else
	{
		pMessage->set_ret(1);
	}
	BuildingPtr Ptr = m_CityPtr->GetBuilding(nBuildId);
	AssertEx(Ptr,"");
	pMessage->set_level(Ptr->GetLevel());
	__LEAVE_FUNCTION
		return false;
}

// 获得某个建筑物的驻守英雄
/*int64  CityManager::GetMarchId(int64 nBuildId)
{
	return m_CityPtr->GetHeroId(nBuildId);
}

// 获得整个队伍信息
TroopList_T CityManager::GetTroopList(int64 nBuildId)
{
	return m_CityPtr->GetTroopList(nBuildId);
}

void  CityManager::AssignHeroToBuild(int64 nBuildId,int64 nHeroId)
{
	__ENTER_FUNCTION
		AssertEx(m_CityPtr,"");
	 m_CityPtr->AssignHeroToBuild(nBuildId,nHeroId);
	__LEAVE_FUNCTION
}

bool  CityManager::CheckAssignHero(int64 nBuildId)
{
	__ENTER_FUNCTION
		AssertEx(m_CityPtr,"");
	return m_CityPtr->CheckAssignHero(nBuildId);
	__LEAVE_FUNCTION
		return false;
}*/

void  CityManager::FileData(GC_CityData* pCityData)
{
	__ENTER_FUNCTION
		AssertEx(m_CityPtr,"");
		m_CityPtr->FileData(pCityData);
	__LEAVE_FUNCTION
}
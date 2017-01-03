
#include "../User.h"
#include "MarchManager.h"
#include "Table/Table_RoleBaseAttr.h"
#include "packet/Packet/PBMessage.pb.h"
#include "Message/DBMsg.h"
#include "service/MessageOp.h"

/////////arrange function///////////////
MarchManager::MarchManager(User &rUser)
	: BaseManager(rUser)
{
	m_mapMarch.clear();
}
MarchManager::~MarchManager(void)
{
	m_mapMarch.clear();
}

void MarchManager::Init()
{

}

void MarchManager::OnLogin()
{
	__ENTER_FUNCTION
	for (MarchPtrMap::iterator it = m_mapMarch.begin();it != m_mapMarch.end();it++)
	{
		MarchPtr Ptr = it->second;
		AssertEx(Ptr,"");
		Ptr->OnLogin();
	}
	__LEAVE_FUNCTION
}

void  MarchManager::Tick(const TimeInfo& rTimeInfo)
{
	__ENTER_FUNCTION
		for (MarchPtrMap::const_iterator it = m_mapMarch.begin();it != m_mapMarch.end(); it++)
		{
			MarchPtr Ptr = it->second;
			Ptr->Tick(rTimeInfo);
		}
	__LEAVE_FUNCTION
}


bool   MarchManager::AddTroop(int64 nMarchId,int nType,int nHp)
{
	__ENTER_FUNCTION
		MarchPtrMap::iterator it = m_mapMarch.find(nMarchId);
		if (it == m_mapMarch.end())
		{
			return false;
		}

		MarchPtr Ptr= it->second;
		Ptr->AddTroop(nMarchId,nType,nHp);
	__LEAVE_FUNCTION
		return false;
}

void   MarchManager::FileData(GC_MarchList* pMarchList)
{
	__ENTER_FUNCTION
		for (MarchPtrMap::const_iterator it = m_mapMarch.begin();it != m_mapMarch.end(); it++)
		{
			MarchPtr Ptr = it->second;
			GC_MarchData* pMarchData = pMarchList->add_marchlist();
			AssertEx(pMarchData,"");
			pMarchData->set_marchid(Ptr->GetMarchId());
			pMarchData->set_begintime(Ptr->GetBeginTime());
			pMarchData->set_buildid(Ptr->GetBuildId());
			pMarchData->set_cityid(Ptr->GetCityId());
			pMarchData->set_fightid(Ptr->GetFightId());
			Hero rHero = Ptr->GetHero();
			GC_HeroData* pGCHeroData = pMarchData->mutable_hero();
			pGCHeroData->set_type(rHero.GetType());
			pGCHeroData->set_level(rHero.GetLevel());
			pGCHeroData->set_hp(rHero.GetHp());
			pGCHeroData->set_mp(0);
			pGCHeroData->set_arrangeindex(rHero.GetArrangeIndex());
			pGCHeroData->set_marchid(Ptr->GetMarchId());

			CooldownList_T CoolDownT = rHero.GetCooldownList();
			for (int j=0;j<CoolDownT.GetListSize();j++)
			{
				CoolDown_Info rCoolDown = CoolDownT.GetCooldownByIndex(j);
				GC_CoolDownInfo* pCoolDown = pGCHeroData->add_cooldown();
				pCoolDown->set_cdtime(rCoolDown.m_nCDTime);
				pCoolDown->set_elapsed(rCoolDown.m_nCDTimeElapsed);
				pCoolDown->set_id(rCoolDown.m_nID);
			}

			TroopList_T TroopListT = Ptr->GetTroopList();
			for (int i=0;i< TroopListT.GetListSize();i++)
			{
				Troop rTroop = TroopListT.GetTroopByIndex(i);
				if (rTroop.GetType()>0)
				{
					GC_TroopData* pTroopData =	pMarchData->add_troop();
					pTroopData->set_type(rTroop.GetType());
					pTroopData->set_level(rTroop.GetLevel());
					pTroopData->set_hp(rTroop.GetHp());
					pTroopData->set_mp(0);
					pTroopData->set_arrangeindex(rTroop.GetArrangeIndex());
					pTroopData->set_marchid(rTroop.GetMarchId());

					CooldownList_T CoolDownT = rTroop.GetCooldownList();
					for (int j=0;j<CoolDownT.GetListSize();j++)
					{
						CoolDown_Info rCoolDown = CoolDownT.GetCooldownByIndex(j);
						GC_CoolDownInfo* pCoolDown = pTroopData->add_cooldown();
						pCoolDown->set_cdtime(rCoolDown.m_nCDTime);
						pCoolDown->set_elapsed(rCoolDown.m_nCDTimeElapsed);
						pCoolDown->set_id(rCoolDown.m_nID);
					}
				}
			}
			
		}
	__LEAVE_FUNCTION
}

void MarchManager::SerializeFromDB(const DBFullUserData& rSource)
{
	__ENTER_FUNCTION
		for (int i=0;i<MARCH_MAX_COUNT;i++)
		{
			if (rSource.m_MarchList[i].m_nMarchId <= 0)
			{
				continue;
			}
			
			MarchPtr Ptr = MarchPtr(new March());
			AssertEx(Ptr,"");
			Ptr->SerializeFromDB(rSource.m_MarchList[i]);
			m_mapMarch.insert(std::make_pair(Ptr->GetMarchId(),Ptr));
			m_mapBuildMarch.insert(std::make_pair(Ptr->GetBuildId(),Ptr->GetMarchId()));
		}
		
	__LEAVE_FUNCTION
}
void MarchManager::SerializeToDB(DBFullUserData& rDesc)
{
	__ENTER_FUNCTION
	int nMarchIndex = 0;
	for (MarchPtrMap::const_iterator it = m_mapMarch.begin();it != m_mapMarch.end(); it++)
	{
		AssertEx(nMarchIndex>=0 && nMarchIndex<MARCH_MAX_COUNT,"");
		it->second->SerializeToDB(rDesc.m_MarchList[nMarchIndex]);
		nMarchIndex++;
	}
	__LEAVE_FUNCTION
}

bool  MarchManager::InitMarchInfo(int64 nBuildId,const TroopList_T& rTroopList,const Hero& rHero,March& rMarch)
{
	__ENTER_FUNCTION

		AssertEx(nBuildId>0,"");
		BuildMarchMap::iterator itBuild = m_mapBuildMarch.find(nBuildId);
		if (itBuild == m_mapBuildMarch.end())
		{
			return false;
		}

		int64 nMarchId = itBuild->second;
		MarchPtrMap::iterator it = m_mapMarch.find(nMarchId);
		if (it == m_mapMarch.end())
		{
			return false;
		}

		MarchPtr Ptr= it->second;

		Ptr->SetTroopList(rTroopList);
		Ptr->SetHero(rHero);
		Ptr->SetBeginTime(static_cast<int>(gTimeManager.GetANSITime()));
		Ptr->SetStatus(MARCHSTATUS_READY);
		rMarch = *Ptr;
		return true;
	__LEAVE_FUNCTION
		return false;
}

bool MarchManager::UpdateMarchState(int64 nMarchId,int nState)
{
	__ENTER_FUNCTION
		AssertEx(nMarchId>0,"");
		AssertEx(nState>=MARCHSTATUS_INVALID && nState<MARCHSTATUS_MAX,"");
		MarchPtrMap::iterator it = m_mapMarch.find(nMarchId);
		if (it == m_mapMarch.end())
		{
			return false;
		}

		MarchPtr Ptr= it->second;
		AssertEx(Ptr,"");
		Ptr->SetStatus(nState);
		DBReqSaveMarchDataMsgPtr MsgPtr = POOLDEF_NEW(DBReqSaveMarchDataMsg);
		Ptr->SerializeToDB(MsgPtr->m_March);
		SendMessage2Srv(ServiceID::DBAGENT,MsgPtr);
		return true;
	__LEAVE_FUNCTION
		return false;
}


MarchPtr  MarchManager::GetMarchInfo(int64 nMarchId)
{
	__ENTER_FUNCTION

		MarchPtrMap::iterator it = m_mapMarch.find(nMarchId);
	if (it == m_mapMarch.end())
	{
		return null_ptr;
	}

	return it->second;
	__LEAVE_FUNCTION
		return null_ptr;
}

bool  MarchManager::CheckSendMarchIntoMap(int64 nMarchId)
{
	__ENTER_FUNCTION
		
	MarchPtrMap::iterator it = m_mapMarch.find(nMarchId);
	if (it == m_mapMarch.end())
	{
		return false;
	}

	MarchPtr Ptr= it->second;
	if (Ptr->GetStatus() != MARCHSTATUS_IDLE)
	{
		return false;
	}
	int64 nHeroId = Ptr->GetHeroId();
	//if (nHeroId<=0)
	//{
		//return false;
	//}
	return true;
	__LEAVE_FUNCTION
		return false;
}


void  MarchManager::AssignHeroToMarch(int64 nMarchId,const Hero& rHero)
{
	__ENTER_FUNCTION
		MarchPtrMap::iterator it = m_mapMarch.find(nMarchId);
		if (it == m_mapMarch.end())
		{
			return ;
		}

		MarchPtr  ptr = it->second;
		ptr->SetHero(rHero);

	__LEAVE_FUNCTION
}

bool  MarchManager::CheckAssignHero(int64 nMarchId)
{
	__ENTER_FUNCTION
		MarchPtrMap::iterator it = m_mapMarch.find(nMarchId);
		if (it == m_mapMarch.end())
		{
			return false;
		}

		MarchPtr  ptr = it->second;
		if (ptr->GetHeroId()>0)
			return false;
		return true;
	__LEAVE_FUNCTION
		return false;
}

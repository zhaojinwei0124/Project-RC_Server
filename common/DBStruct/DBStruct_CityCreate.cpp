#include "DBStruct_CityCreate.h"

void DBCityCreate::CleanUp( )
{
	__ENTER_FUNCTION
		m_tileID    = 0; //�ؿ�ID
		m_nCityID   = 0;
		m_UserId = 0;
		m_nLevel    = 0;
		m_fPosX     = 0;
		m_fPosZ     = 0;
		m_lstMarch.clear();
		m_lstBuilding.clear();
		m_Hero.CleanUp();
		m_lstTrain.clear();
	
		
	__LEAVE_FUNCTION
}
void DBCityCreate::CopyFrom(const DBCityCreate& rSource)
{
	__ENTER_FUNCTION
		CleanUp();
		m_tileID    = rSource.m_tileID; //�ؿ�ID
		m_nCityID   = rSource.m_nCityID;
		m_UserId    = rSource.m_UserId;
		m_nLevel    = rSource.m_nLevel;
		m_fPosX     = rSource.m_fPosX;
		m_fPosZ     = rSource.m_fPosZ;
		m_nFood     = rSource.m_nFood;
		m_nStone    = rSource.m_nStone;
		m_nIron     = rSource.m_nIron;
		m_nGold     = rSource.m_nGold;

		
	
		int nBuildSize = (int)rSource.m_lstBuilding.size();
		m_lstBuilding.resize(nBuildSize);
		for (int i=0;i<nBuildSize;i++)
		{
			m_lstBuilding[i].CopyFrom(rSource.m_lstBuilding[i]);
		}
		
		int nMarchSize = (int)rSource.m_lstMarch.size();
		m_lstMarch.resize(nMarchSize);
		for (int i=0;i<nMarchSize;i++)
		{
			m_lstMarch[i].CopyFrom(rSource.m_lstMarch[i]);
		}

		m_Hero.CopyFrom(rSource.m_Hero);

		int nTrainSize = (int)rSource.m_lstTrain.size();
		m_lstTrain.resize(nTrainSize);
		for (int i=0;i<nTrainSize;i++)
		{
			m_lstTrain[i].CopyFrom(rSource.m_lstTrain[i]);
		}

	__LEAVE_FUNCTION
}

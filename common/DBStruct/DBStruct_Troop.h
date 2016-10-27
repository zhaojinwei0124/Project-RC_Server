
#ifndef __DBSTRUCT_TROOP_H__
#define __DBSTRUCT_TROOP_H__

#include "DBStruct.h"
#include "troop/GameDefine_Troop.h"



// ��ҳ�����Ϣ
struct DBTroop
{
public:
	DBTroop(){CleanUp();};
	~DBTroop(){};

	void CleanUp( );
	void CopyFrom(const DBTroop& rSource);

public:
	int     m_nType; //������
	int     m_nLevel;//�ȼ�
	int     m_nCount; // ����
	int64   m_nBuildId; // ������ӪID
	int     m_nHp;       // ��ǰ��Ѫ��
	int     m_nArrangeIndex; // ���ε�λ��
	int     m_nQueueIndex;   // ���е�λ��
	
};

typedef DBCommonData<DBTroop> DBTroopData;
typedef boost::shared_ptr<DBTroopData> DBTroopDataPtr;


#endif
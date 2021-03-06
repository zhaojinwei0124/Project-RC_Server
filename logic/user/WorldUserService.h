
#ifndef _WORLDUSERSERVICE_H_
#define _WORLDUSERSERVICE_H_

#include "Base.h"
#include "service/Invoker.h"
#include "service/Service.h"
#include "User.h"
#include "user/GameDefine_User.h"
#include "player/GamePlayerManager.h"


class WorldUserService :public Service
{
public:
	explicit WorldUserService();
	virtual ~WorldUserService(void);

public:
	friend class GamePlayerManager;

public:
	virtual int GetServiceID(void){return ServiceID::WORLDUSER;}

public:
	virtual void Init(void);
	virtual void Tick(const TimeInfo &rTimeInfo);

protected:
	virtual void Shutdown(void);

	//////////////////////////////////////////////////////////////////////////
	//场景玩家数量
public:
	void SetCurPlayerCount(tint32 nCurPlayerCount);
	tint32 GetCurPlayerCount(void) const {return m_nCurPlayerCount;}
protected:
	tint32 m_nCurPlayerCount;
public:
	void SetEnteringPlayerCount(tint32 nEnteringPlayerCount) {m_nEnteringPlayerCount = nEnteringPlayerCount;}
	tint32 GetEnteringPlayerCount(void) const {return m_nEnteringPlayerCount;}
	void IncEnteringPlayerCount(void) {m_nEnteringPlayerCount++;}
	void DecEnteringPlayerCount(void) {m_nEnteringPlayerCount--;}
protected:
	tint32 m_nEnteringPlayerCount;

public:	
	virtual void HandleMessage(const RetMarchStartMsg &rMsg);
	//MESSAGE_TRANSPORTTOUSER_DECL(RetMarchStartMsg);
	//MESSAGE_TRANSPORTTOUSER_DECL(MarchRetNearListMsg);
	MESSAGE_TRANSPORTTOUSER_DECL(RetMarchMoveMsg);
	MESSAGE_TRANSPORTTOUSER_DECL(KickPlayerByGuidMsg); 
	virtual void HandleMessage(const PlayerLeaveWorldMsg &rMsg);

	virtual void HandleMessage(const PlayerEnterWorldMsg &rMsg);
	virtual void HandleMessage(const MarchRetFightMsg &rMsg);
	virtual void HandleMessage(const RetBattleInfoMsg &rMsg);
	virtual void HandleMessage(const RetObjListMsg &rMsg);
	virtual void HandleMessage(const UpdateMarchMsg &rMsg);
	virtual void HandleMessage(const ObjAttackTargetMsg &rMsg);
	virtual void HandleMessage(const ObjHurtMsg &rMsg);
	virtual void HandleMessage(const ObjTrackTargetMsg &rMsg);
	virtual void HandleMessage(const RetBattleStartMsg &rMsg);
	virtual void HandleMessage(const RetBattleEndMsg &rMsg);
	virtual void HandleMessage(const TrainTroopOverMsg &rMsg);
	virtual void HandleMessage(const RetUserSkillMsg &rMsg);
	virtual void HandleMessage(const RetArrangChangeMsg &rMsg);
	virtual void HandleMessage(const MarchRetNearListMsg &rMsg);
private:
	User*			GetUserByGuid(int64 guid);


public:

	// 保存玩家信息
	void Tick_User(const TimeInfo &rTimeInfo);

private:

	UserMap m_mapUser;

	GamePlayerManager m_PlayerManager;
};


typedef GeneralInvoker<WorldUserService,200,200> WorldUserInvoker;


#endif
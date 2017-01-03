
#ifndef _GAMEDEFINE_BUILDING_H_
#define _GAMEDEFINE_BUILDING_H_

#include "Base.h"

#define BUILDING_BARRACK_MAX 4
#define BUILDING_WALL_MAX    1

enum BUILDINGTYPE
{
	BUILDINGTYPE_MIN=1,
	BUIDINGTYPE_CASTLE = BUILDINGTYPE_MIN,    // 城堡
	BUIDINGTYPE_WALL=2,          // 城墙
	BUIDINGTYPE_QYARRT=3,        // 采石场
	BUIDINGTYPE_FARM,          // 农田
	BUIDINGTYPE_IRONMINE,      // 铁矿
	BUIDINGTYPE_BARRACKS,      // 兵营
	BUIDINGTYPE_CHURCH,        // 教堂
	BUIDINGTYPE_PROVIDEGROUND, // 试炼场
	BUIDINGTYPE_TRADECENTER,   // 贸易中心
	BUIDINGTYPE_WAREHOUSE,     // 仓库
	BUIDINGTYPE_COLLEGE,       // 学院
	BUIDINGTYPE_EMBASSY,       // 使馆
	BUIDINGTYPE_PUB,           // 酒馆
	BUIDINGTYPE_BLACKSMITH,    // 铁匠铺
	BUIDINGTYPE_RESDIENCE,     // 民居
	BUIDINGTYPE_LOOTWAREHOUSE, // 战利品仓库

	BUIDINGTYPE_MAX,
};

enum 
{

};

#endif
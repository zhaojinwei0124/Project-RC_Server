//This code create by CodeEngine,don't modify
#include "Table_CopyScene.h"







bool Table_CopyScene::__Load(DBC_Loader & loader)
 {
 __ENTER_FUNCTION
 
 AssertEx(ID_TAB_CURCOL_COUNT==loader.GetFieldsNum(), "CopyScene Columns Differ"); 
 loader.ReadDirect(m_DescInfo,(tint32)ID_DESCINFO);
loader.ReadDirect(m_HeartbeatTime,(tint32)ID_HEARTBEATTIME);
loader.ReadDirect(m_Id,(tint32)ID_ID);
loader.ReadDirect(m_Name,(tint32)ID_NAME);
loader.ReadDirect(m_Rule[0],(tint32)ID_RULE1);
loader.ReadDirect(m_Rule[1],(tint32)ID_RULE2);
loader.ReadDirect(m_Rule[2],(tint32)ID_RULE3);
loader.ReadDirect(m_Rule[3],(tint32)ID_RULE4);
loader.ReadDirect(m_WaitTime,(tint32)ID_WAITTIME);

 return true;
 __LEAVE_FUNCTION
 return false;
 }


 DEFINE_SEQUENCE_TABLE_FUNCTIONS(Table_CopyScene);




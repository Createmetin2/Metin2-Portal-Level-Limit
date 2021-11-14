//Find
	if (m_dwLevel)
	{
		UpdateTextTailLevel(m_dwLevel);
	}

///Add
#if defined(__BL_PORTAL_UPDATE__)
	else if (IsWarp())
		UpdatePortalTextTailLevelLimit();
#endif

///Add Func
#if defined(__BL_PORTAL_UPDATE__)
#include "PythonNonPlayer.h"

void CInstanceBase::UpdatePortalTextTailLevelLimit()
{
	const std::pair<int, int>* pPortalLevelLimit = CPythonNonPlayer::Instance().GetPortalLevelLimit(GetRace());
	if (pPortalLevelLimit == nullptr)
		return;
	
	static const D3DXCOLOR s_kPortalLevelLimitColor = D3DXCOLOR(0.0f, 1.0f, 1.0f, 1.0f);
	const int iMinLevel = pPortalLevelLimit->first;
	const int iMaxLevel = pPortalLevelLimit->second;

	char szText[32];
	snprintf(szText, sizeof(szText), "Lv Limit: [%d-%d]", iMinLevel, iMaxLevel);
	CPythonTextTail::Instance().AttachLevel(GetVirtualID(), szText, s_kPortalLevelLimitColor);
}
#endif
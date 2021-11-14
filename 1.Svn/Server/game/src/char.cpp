//Find in void CHARACTER::EncodeInsertPacket(LPENTITY entity)
	pack.wRaceNum	= GetRaceNum();

///Add
#if defined(__BL_PORTAL_UPDATE__)
	pack.iPortalMinLevelLimit = 0;
	pack.iPortalMaxLevelLimit = 0;

	if (IsWarp())
	{
		const std::pair<int, int>* pPortalLevelLimit = CHARACTER_MANAGER::Instance().GetPortalLevelLimit(GetRaceNum());
		if (pPortalLevelLimit != nullptr)
		{
			pack.iPortalMinLevelLimit = pPortalLevelLimit->first;
			pack.iPortalMaxLevelLimit = pPortalLevelLimit->second;
		}
	}
#endif

//Find in class FuncCheckWarp
				m_lTargetY *= 100;

///Add
#if defined(__BL_PORTAL_UPDATE__)
				const std::pair<int, int>* pPortalLevelLimit = CHARACTER_MANAGER::Instance().GetPortalLevelLimit(pkWarp->GetRaceNum());
				m_iMinLevelLimit = pPortalLevelLimit ? pPortalLevelLimit->first : 1;
				m_iMaxLevelLimit = pPortalLevelLimit ? pPortalLevelLimit->second : gPlayerMaxLevel;
#endif

//Find
				if (m_bUseWarp)
					pkChr->WarpSet(m_lTargetX, m_lTargetY);
				else
				{
					pkChr->Show(pkChr->GetMapIndex(), m_lTargetX, m_lTargetY);
					pkChr->Stop();
				}

///Change
#if defined(__BL_PORTAL_UPDATE__)
				const int iPlayerLevel = pkChr->GetLevel();
				if (iPlayerLevel >= m_iMinLevelLimit && iPlayerLevel <= m_iMaxLevelLimit)
				{
#endif
					if (m_bUseWarp)
						pkChr->WarpSet(m_lTargetX, m_lTargetY);
					else
					{
						pkChr->Show(pkChr->GetMapIndex(), m_lTargetX, m_lTargetY);
						pkChr->Stop();
					}
#if defined(__BL_PORTAL_UPDATE__)
				}
				/*else if (number(1, 100) < 10)
					pkChr->ChatPacket(CHAT_TYPE_INFO, "Your level is not enough for this portal.");*/
#endif

//Find in class FuncCheckWarp
			long m_lTargetY;

///Add
#if defined(__BL_PORTAL_UPDATE__)
			int m_iMinLevelLimit;
			int m_iMaxLevelLimit;
#endif
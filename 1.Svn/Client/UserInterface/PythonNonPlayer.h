//Find
		void				GetMatchableMobList(int iLevel, int iInterval, TMobTableList * pMobTableList);

///Add
#if defined(__BL_PORTAL_UPDATE__)
		void							AddPortalLevelLimit(DWORD dwRace, int iMinLevel, int iMaxLevel);
		const std::pair<int, int>*		GetPortalLevelLimit(DWORD dwRace) const;
#endif

//Find
		TNonPlayerDataMap	m_NonPlayerDataMap;

///Add
#if defined(__BL_PORTAL_UPDATE__)
		std::unordered_map<DWORD, std::pair<int, int>> m_NonPlayerPortalLevelLimit;
#endif
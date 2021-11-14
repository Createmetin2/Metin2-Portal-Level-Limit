//Find
		void			FlushPendingDestroy();

///Add
#if defined(__BL_PORTAL_UPDATE__)
		void							InitPortalLevelLimit(const char* FileName);
		void							AddPortalLevelLimit(DWORD dwRace, int iMinLevel, int iMaxLevel);
		const std::pair<int, int>*		GetPortalLevelLimit(DWORD dwRace) const;
#endif

//Find
		CHARACTER_SET		m_set_pkChrPendingDestroy;

///Add
#if defined(__BL_PORTAL_UPDATE__)
		std::unordered_map<DWORD, std::pair<int, int>> m_mapPlayerPortalLevelLimit;
#endif
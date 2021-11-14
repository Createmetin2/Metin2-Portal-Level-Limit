//Find
	PanamaLoad();

///Add
#if defined(__BL_PORTAL_UPDATE__)
	char szPortalLevelLimitFileName[256];
	snprintf(szPortalLevelLimitFileName, sizeof(szPortalLevelLimitFileName),
		"%s/portal.txt", LocaleService_GetBasePath().c_str());

	char_manager.InitPortalLevelLimit(szPortalLevelLimitFileName);
#endif
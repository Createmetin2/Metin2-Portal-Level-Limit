//Find in bool CPythonNetworkStream::RecvCharacterAppendPacket()
	kNetActorData.m_dwLevel = 0;

///Add
#if defined(__BL_PORTAL_UPDATE__)
	if (kNetActorData.m_bType == CActorInstance::TYPE_WARP)
		CPythonNonPlayer::Instance().AddPortalLevelLimit(kNetActorData.m_dwRace, chrAddPacket.iPortalMinLevelLimit, chrAddPacket.iPortalMaxLevelLimit);
#endif
///Add to end
#if defined(__BL_PORTAL_UPDATE__)
void CPythonNonPlayer::AddPortalLevelLimit(DWORD dwRace, int iMinLevel, int iMaxLevel)
{
	if (iMinLevel > 0 && iMaxLevel > 0)
		m_NonPlayerPortalLevelLimit[dwRace] = std::make_pair(iMinLevel, iMaxLevel);
}

const std::pair<int, int>* CPythonNonPlayer::GetPortalLevelLimit(DWORD dwRace) const
{
	auto it = m_NonPlayerPortalLevelLimit.find(dwRace);
	if (it != m_NonPlayerPortalLevelLimit.end())
		return &it->second;

	return nullptr;
}
#endif
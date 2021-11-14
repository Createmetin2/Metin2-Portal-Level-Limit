///Add to end
#if defined(__BL_PORTAL_UPDATE__)
#include <sstream>
#include <fstream>

void CHARACTER_MANAGER::InitPortalLevelLimit(const char* FileName)
{
	std::ifstream file(FileName);
	if (file.is_open() == false)
	{
		sys_err("Cannot open %s file.", FileName);
		return;
	}

	std::string   line;

	while (std::getline(file, line))
	{
		std::stringstream			linestream(line);
		std::string					dwRaceNum;
		int							iMinLevel;
		int							iMaxLevel;

		std::getline(linestream, dwRaceNum, '\t');

		if (dwRaceNum.empty() || dwRaceNum.at(0) == '#')
			continue;

		linestream >> iMinLevel >> iMaxLevel;
		AddPortalLevelLimit(std::stoul(dwRaceNum), iMinLevel, iMaxLevel);
	}
}

void CHARACTER_MANAGER::AddPortalLevelLimit(DWORD dwRace, int iMinLevel, int iMaxLevel)
{
	iMinLevel = MINMAX(1, iMinLevel, gPlayerMaxLevel);
	iMaxLevel = MINMAX(1, iMaxLevel, gPlayerMaxLevel);

	m_mapPlayerPortalLevelLimit[dwRace] = std::make_pair(iMinLevel, iMaxLevel);
}

const std::pair<int, int>* CHARACTER_MANAGER::GetPortalLevelLimit(DWORD dwRace) const
{
	auto it = m_mapPlayerPortalLevelLimit.find(dwRace);
	if (it != m_mapPlayerPortalLevelLimit.end())
		return &it->second;

	return nullptr;
}
#endif
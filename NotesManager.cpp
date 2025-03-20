#include "NotesManager.h"

void NotesManager::AddNotes(std::string key, std::filesystem::path path)
{
	if (!std::filesystem::exists(path))
	{
		std::cout << "•ˆ–ÊƒpƒX‚ª•s³‚Å‚·:" << std::endl;
		std::cout << path << std::endl;
	}

	Translate(key, path);
}

void NotesManager::Translate(std::string key, std::filesystem::path path)
{
	std::ifstream file(path);
	std::string line;

	std::getline(file, line);
	float bpm = std::stof(line);
	std::getline(file, line);
	float offset = std::stof(line) / 1000.0f;

	std::vector<Note> toadd;

	while (true)
	{
		std::getline(file, line);
		if (line == "END") break;
		line.erase(std::remove_if(line.begin(), line.end(), ::isspace), line.end());

		int m = (int)line.size();
		float spreadTime = 240.0f / ((float)m * bpm);
		for (int i = 0; i < m; i++)
		{
			Action action = Action::Non;

			if (line[i] == '0') action = Action::Non;
			else if (line[i] == '1') action = Action::Punch;
			else if (line[i] == '2') action = Action::Jump;

			Note note{ .judgeTime = nowTime + spreadTime * i + offset, .action = action };
			if (action != Action::Non)
			{
				toadd.push_back(note);
			}
		}
		nowTime += spreadTime * m;
	}

	notes[key] = toadd;
	file.close();

	Reset();
}

void NotesManager::Reset()
{
	nowTime = 0.0f;
}

void NotesManager::RemoveNotes(std::string key)
{
	auto itr = notes.find(key);
	if (itr == notes.end()) return;

	notes.erase(itr);
}

std::vector<Note> NotesManager::GetNotes(std::string key)
{
	auto itr = notes.find(key);
	if (itr == notes.end()) return std::vector<Note>();

	return notes[key];
}
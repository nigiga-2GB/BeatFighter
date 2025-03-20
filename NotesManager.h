#pragma once

#include<filesystem>
#include<fstream>
#include<iostream>
#include<unordered_map>
#include<vector>
#include<cstdlib>
#include<memory>

enum class Action
{
	Non,
	Punch,
	Jump,
};

struct Note
{
	bool isActive = false;
	float judgeTime = 0.0f;
	Action action;
};

class NotesManager
{
private:
	std::unordered_map<std::string, std::vector<Note>> notes;
	float nowTime = 0.0f;

	void Translate(std::string key, std::filesystem::path path);
	void Reset();

public:
	void AddNotes(std::string key, std::filesystem::path path);
	void RemoveNotes(std::string key);

	std::vector<Note> GetNotes(std::string key);
};
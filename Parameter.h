#pragma once

#include<map>
#include<string>

class Parameter
{
private:
	std::map<std::string, int> _param;

public:
	const static int Error = -1;

	Parameter() = default;
	virtual ~Parameter() = default;

	void Set(std::string key, int val)
	{
		_param[key] = val;
	}

	int Get(std::string key) const
	{
		auto itr = _param.find(key);
		if (itr == _param.end())
		{
			return Error;
		}
		
		return itr->second;
	}
};


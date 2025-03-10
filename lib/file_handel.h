#pragma once
#include <fstream>
#include <string>
#include <vector>

struct FileHandel
{
	std::string filename;
	std::fstream file;
	std::vector<std::string> data;

	FileHandel(std::string filename) : filename(filename) {}

	void loadDataFromFileToVector(std::vector<std::string>& data)
	{
		this->file.open(this->filename, std::ios::in);
		if (this->file.fail())
			return;

		if (this->file.is_open())
		{
			std::string line;
			while (std::getline(this->file, line))
			{
				data.push_back(line);
			}
			this->file.close();
		}
	}

	void saveVectorToFile(std::vector<std::string> data)
	{
		this->file.open(this->filename, std::ios::out);
		if (this->file.fail())
			return;

		if (this->file.is_open())
		{
			for (std::string line : data)
			{
				this->file << line << std::endl;
			}
			this->file.close();
		}
	}

	void updateRecordFromFile(std::string record, std::string newRecord)
	{
		this->loadDataFromFileToVector(data);

		for (std::string& line : data)
		{
			if (line == record)
			{
				line = newRecord;
				break;
			}
		}

		this->saveVectorToFile(data);
	}

	void deleteRecordFromFile(std::string record)
	{
		this->loadDataFromFileToVector(data);

		for (std::string& line : data)
		{
			if (line == record)
			{
				line = "";
				break;
			}
		}

		this->saveVectorToFile(data);
	}
};
#include <algorithm>
#include <cassert>
#include <iomanip>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <sstream>
#include <limits>

class HRMLDocument;

class HRMLTag
{
private:
	friend HRMLDocument;

	HRMLTag(const std::string & name, HRMLTag * parent)
		: name{ name }
		, attributes{}
		, children{}
		, parent{ parent }
	{}

public:
	HRMLTag & addChild(const std::string & name)
	{
		auto result = children.emplace(std::piecewise_construct,
			std::forward_as_tuple(name),
			std::forward_as_tuple(new HRMLTag{ name, this }));
		assert(result.second);
		return *result.first->second;
	}

	HRMLTag & addAttribute(const std::string & name, const std::string & value)
	{
		assert(attributes.count(name) == 0);
		attributes[name] = value;
		return *this;
	}

	std::string & operator[](const std::string & attributeName)
	{
		return attributes[attributeName]; // Tag names are unique anyway so .at isn't necessary
	}

	std::pair<std::string, bool> query(const std::string & query)
	{
		if (query.size() == 0)
		{
			return { "", false };
		}

		size_t separatorIndex = query.find_first_of(".~");
		if (separatorIndex == std::string::npos)
		{
			std::string attributeName = query.substr(separatorIndex + 1);
			if (attributes.count(attributeName) == 1)
			{
				return { attributes[attributeName], true };
			}
			else
			{
				return { "", false };
			}
		}
		else
		{
			std::string tagName = query.substr(0, separatorIndex);
			if (children.count(tagName) == 1)
			{
				return children[tagName]->query(query.substr(separatorIndex + 1));
			}
			else
			{
				return { "", false };
			}
		}
	}

	// Data accessors
	const std::string & getName() const
	{
		return name;
	}

	HRMLTag & getParent() const
	{
		return *parent;
	}

private:
	std::string name;
	std::unordered_map<std::string, std::string> attributes;
	std::unordered_map<std::string, HRMLTag*> children;
	HRMLTag* parent;
};

class HRMLDocument
{
public:
	HRMLDocument() = default;

	HRMLTag & addChild(const std::string & name)
	{
		auto result = children.emplace(std::piecewise_construct,
			std::forward_as_tuple(name),
			std::forward_as_tuple(new HRMLTag{ name, nullptr }));
		return *result.first->second;
	}

	std::pair<std::string, bool> query(const std::string & query)
	{
		if (query.size() == 0)
		{
			return { "", false };
		}

		size_t separatorIndex = query.find_first_of(".~");
		if (separatorIndex == std::string::npos)
		{
			return { "", false };
		}
		else
		{
			std::string tagName = query.substr(0, separatorIndex);
			if (children.count(tagName) == 1)
			{
				return children[tagName]->query(query.substr(separatorIndex + 1));
			}
			else
			{
				return { "", false };
			}
		}
	}

private:
	std::unordered_map<std::string, HRMLTag*> children;
};

HRMLDocument generateHRMLDocument(const std::vector<std::string> & programLines)
{
	HRMLDocument document;
	HRMLTag * currentParentTag = nullptr;
	for (const std::string & line : programLines)
	{
		if (line[0] == '/')
		{
			assert(currentParentTag != nullptr);
			currentParentTag = &currentParentTag->getParent();
		}
		else
		{
			std::stringstream lineStream{ line };
			std::string tagName;
			lineStream >> tagName;
			if (currentParentTag == nullptr)
			{
				currentParentTag = &document.addChild(tagName);
			}
			else
			{
				currentParentTag = &currentParentTag->addChild(tagName);
			}

			std::string attributeName;
			while (lineStream >> attributeName)
			{
				lineStream.ignore(std::numeric_limits<std::streamsize>::max(), '\"');
				std::string attributeValue;
				std::getline(lineStream, attributeValue, '\"');
				(*currentParentTag)[attributeName] = attributeValue;
			}
		}
	}
	return document;
}

int main()
{
	int programLineCount = 0;
	int queryCount = 0;
	std::cin >> programLineCount >> queryCount;
	std::cin.ignore(1); // Ignore newline

	std::vector<std::string> programLines{ static_cast<size_t>(programLineCount) };
	for (int i = 0; i < programLineCount; ++i)
	{
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '<');
		std::getline(std::cin, programLines[i], '>');
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	std::vector<std::string> queryStrings{ static_cast<size_t>(queryCount) };
	for (int i = 0; i < queryCount; ++i)
	{
		std::getline(std::cin, queryStrings[i]);
	}

	HRMLDocument document = generateHRMLDocument(programLines);

	for (const std::string & query : queryStrings)
	{
		auto[attribute, success] = document.query(query);
		if (success)
		{
			std::cout << attribute;
		}
		else
		{
			std::cout << "Not Found!";
		}
		std::cout << std::endl;
	}

	return 0;
}
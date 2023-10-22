#include <cstdint>
#include <cstring>
#include <iostream>

class ToyStringView;

class ToyString {
private:
	size_t size, reserved;
	char* data;

public:
	explicit ToyString(const char*);
	explicit ToyString(char*);
	ToyString(const ToyString&);
	ToyString(const ToyStringView&);
	~ToyString();

	char* GetCString() { return data; }
	const char* GetCString() const { return data; }

	size_t Length() const;
	
	char& operator[] (size_t index);
	char operator[] (size_t index) const;

	ToyString& operator=(const ToyString&);
	ToyString& operator=(const char*);
	ToyString& operator=(char*);
	ToyString& operator=(const ToyStringView&);

	ToyString& operator+=(const ToyString&);
	ToyString& operator+=(const char*);
	ToyString& operator+=(char*);
	ToyString& operator+=(const ToyStringView&);

	ToyString operator+(const ToyString&) const;
	ToyString operator+(const char*) const;
	ToyString operator+(char*) const;
	ToyString operator+(const ToyStringView&) const;

	ToyStringView SubString(size_t from, size_t len);
};

class ToyStringView {
private:
	char* data;
	size_t size;
public:
	ToyStringView(char* start, size_t size_);

	char operator[] (size_t index);
	char operator[] (size_t index) const;
	size_t Length() const;
};

std::ostream& operator<<(std::ostream& os, ToyStringView view);
std::ostream& operator<<(std::ostream& os, const ToyString& ts);

ToyString operator+(const char*, const ToyString&);
ToyString operator+(const char*, const ToyStringView&);
ToyString operator+(char*, const ToyString&);
ToyString operator+(char*, const ToyStringView&);
ToyString operator+(const ToyStringView&, const char*);
ToyString operator+(const ToyStringView&, char*);
ToyString operator+(const ToyStringView&, const ToyString&);
ToyString operator+(const ToyStringView&, const ToyStringView&);


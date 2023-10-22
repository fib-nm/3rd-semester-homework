#include "Toy_string.hpp"
// constructor, .Substring, destructor, .Length, [i], =, +=, +, <<


// ToyString(const char*) constructor
ToyString::ToyString(const char* c_str) {
    size = std::strlen(c_str);
    reserved = size + 1;
    data = new char[reserved];

    for (size_t i = 0; i < size; ++i) {
        data[i] = c_str[i];
    }
    data[size] = 0;
}

// ToyString(char*) constructor
ToyString::ToyString(char* c_str) {
    size = std::strlen(c_str);
    reserved = size + 1;
    data = new char[reserved];

    for (size_t i = 0; i < size; ++i) {
        data[i] = c_str[i];
    }
    data[size] = 0;
}

// ToyString(const ToyString&) constructor
ToyString::ToyString(const ToyString& rhs) {
    size = rhs.size;
    reserved = size + 1;
    data = new char[reserved];

    for (size_t i = 0; i < size; ++i) {
        data[i] = rhs.data[i];
    }
    data[size] = 0;
}

// ToyString(const ToyString&) constructor
ToyString::ToyString(const ToyStringView& rhs) {
    size = rhs.Length();
    reserved = size + 1;
    data = new char[reserved];

    for (size_t i = 0; i < size; ++i) {
        data[i] = rhs[i];
    }
    data[size] = 0;
}

// ToyString destructor
ToyString::~ToyString() {
    delete[] data;
}

// ToyString.Length
size_t ToyString::Length() const {
    return size;
}

// char& ToyString[i]
char& ToyString::operator[] (size_t index) {
    return data[index];
}

// char ToyString[i]
char ToyString::operator[] (size_t index) const {
    return data[index];
}

// ToyString = const ToyString&
ToyString& ToyString::operator=(const ToyString& rhs) {
    if (this == &rhs) return *this;

    ToyString tmp{ rhs };
    std::swap(size, tmp.size);
    std::swap(reserved, tmp.reserved);
    std::swap(data, tmp.data);
    return *this;
}

// ToyString = const char*
ToyString& ToyString::operator=(const char* rhs) {    
    ToyString x{ rhs };
    (*this) = x;
    return *this;
    
}

// ToyString = char*
ToyString& ToyString::operator=(char* rhs) {
    ToyString x{ rhs };
    (*this) = x;
    return *this;

}

// ToyString = ToyStringView
ToyString& ToyString::operator=(const ToyStringView& rhs) {
    ToyString x{ rhs };
    (*this) = x;
    return *this;
}

// ToyString += const ToyString&
ToyString& ToyString::operator+= (const ToyString& rhs) {
    size_t new_size = size + rhs.size;

    if (reserved < new_size + 1) {
        char* new_data = new char[new_size + 1];
        for (size_t i = 0; i < size; ++i) {
            new_data[i] = data[i];
        }
        reserved = new_size + 1;
        delete[] data;
        data = new_data;
    }

    for (size_t i = size; i < new_size; ++i) {
        data[i] = rhs.data[i - size];
    }
    size = new_size;
    data[size] = 0;
    return *this;
}

// ToyString += const char*
ToyString& ToyString::operator+= (const char* rhs) {
    ToyString new_string{ rhs };
    (*this) += new_string;
    return *this;
}

// ToyString += char*
ToyString& ToyString::operator+= (char* rhs) {
    ToyString new_string{ rhs };
    (*this) += new_string;
    return *this;
}

// ToyString += ToyStringView
ToyString& ToyString::operator+= (const ToyStringView& rhs) {
    ToyString new_string{ rhs };
    (*this) += new_string;
    return *this;
}

// ToyString + const ToyString&
ToyString ToyString::operator+(const ToyString& rhs) const {
    ToyString copy(*this);
    copy += rhs;
    return copy;
}

// ToyString + const char*
ToyString ToyString::operator+(const char* rhs) const {
    ToyString x{ rhs };
    return (*this) + x;
}

// ToyString + char*
ToyString ToyString::operator+(char* rhs) const {
    ToyString x{ rhs };
    return (*this) + x;
}

//ToyString + ToyStringView
ToyString ToyString::operator+(const ToyStringView& rhs) const {
    ToyString x{ rhs };
    return (*this) + x;
}

// const char* + ToyString&
ToyString operator+(const char* lhs, const ToyString& rhs) {
    ToyString x{ lhs };
    return x + rhs;
}

// const char* + ToyStringView
ToyString operator+(const char* lhs, const ToyStringView& rhs) {
    ToyString x{ lhs }, y{ rhs };
    return x + y;
}

// char* + ToyString&
ToyString operator+(char* lhs, const ToyString& rhs) {
    ToyString x{ lhs };
    return x + rhs;
}

// char* + ToyStringView
ToyString operator+(char* lhs, const ToyStringView& rhs) {
    ToyString x{ lhs }, y{ rhs };
    return x + y;
}

//ToyStringView + char*
ToyString operator+(const ToyStringView& lhs, char* rhs) {
    ToyString x{ lhs }, y{ rhs };
    return x + y;
}

//ToyStringView + const char*
ToyString operator+(const ToyStringView& lhs, const char* rhs) {
    ToyString x{ lhs }, y{ rhs };
    return x + y;
}

//ToyStringView + ToyString&
ToyString operator+(const ToyStringView& lhs, const ToyString& rhs) {
    ToyString x{ lhs };
    return x + rhs;
}

//ToyStringView + ToyStringView
ToyString operator+(const ToyStringView& lhs, const ToyStringView& rhs) {
    ToyString x{ lhs }, y{ rhs };
    return x + y;
}

// ostream << ToyString
std::ostream& operator<<(std::ostream& os, const ToyString& ts) {
    os << ts.GetCString();
    return os;
}





// ToyStringView(char* start, size_t size_) constructor
ToyStringView::ToyStringView(char* start, size_t size_)
    : data(start), size(size_) {}

// ToyString.SubString
ToyStringView ToyString::SubString(size_t from, size_t len) {
    return ToyStringView{ data + from, len };
}

// ToyStringView.Length
size_t ToyStringView::Length() const { return size; }

// ToyStringView[] const
char ToyStringView::operator[] (size_t index) const {
    if (index >= size) return 0;
    return data[index];
}

// ToyStringView[]
char ToyStringView::operator[] (size_t index) {
    if (index >= size) return 0;
    return data[index];
}

// ostream << ToyStringView
std::ostream& operator<<(std::ostream& os, ToyStringView view) {
    for (size_t i = 0; i < view.Length(); ++i) {
        os << view[i];
    }
    return os;
}

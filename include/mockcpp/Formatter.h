
#ifndef __MOCKCPP_FORMATTER_H
#define __MOCKCPP_FORMATTER_H

#include <mockcpp/mockcpp.h>

#include <string>

#include <mockcpp/OutputStringStream.h>
#include <mockcpp/TypeString.h>

MOCKCPP_NS_START

///////////////////////////////////////////////////////
std::string toBufferString(void* buf, size_t size);

///////////////////////////////////////////////////////
template <typename T>
std::string toString(const T& val)
{
   return MOCKCPP_NS::toBufferString((void*)&val, sizeof(val));
}

///////////////////////////////////////////////////////
std::string toPointerString(void*);

///////////////////////////////////////////////////////
template <typename T>
std::string toString(T* p)
{
   return MOCKCPP_NS::toPointerString((void*)p);
}

///////////////////////////////////////////////////////
template <typename T>
std::string toString(const T* s)
{
	return MOCKCPP_NS::toPointerString((void*)s);
}

///////////////////////////////////////////////////////
std::string toString(std::string s);
std::string toString(char* s);
std::string toString(const char* s);
std::string toString(float f);
std::string toString(double d);
std::string toString(bool b);
std::string toString(char c);
std::string toString(unsigned char c);
std::string toString(short s);
std::string toString(unsigned short s);
std::string toString(int i);
std::string toString(unsigned int i);
std::string toString(long l);
std::string toString(unsigned long l);

#if (MOCKCPP_SUPPORT_LONG_LONG == 1)
std::string toString(long long ll);
std::string toString(unsigned long long ll);
#endif

/////////////////////////////////////////////////////////////////
template <typename T>
std::string toTypeAndValueString(const T& val)
{
	oss_t oss;
	oss << "(" << MOCKCPP_NS::TypeString<T>::value() << ")" 
       << MOCKCPP_NS::toString(val);
	return oss.str();
}

MOCKCPP_NS_END

#endif


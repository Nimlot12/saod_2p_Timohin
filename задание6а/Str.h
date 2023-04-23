#pragma once
#include <iostream>
#include "_str.h"
using namespace std;

class Str
{
	_str* m_pStr;

public:
	Str() {
		m_pStr = new _str;
	}

	Str(const char* p) {
		m_pStr = new _str(p);
	}

	Str(const Str& s) {
		m_pStr = s.m_pStr;
		m_pStr->AddRef();
	}

	~Str() {
		m_pStr->Release();
	}

	int len() const {
		return strlen(m_pStr->m_pszData);
	}

	Str& operator = (const Str &s) {
		if (this != &s) {
			s.m_pStr->AddRef();
			m_pStr->Release();
			m_pStr = s.m_pStr;
		}
		return *this;
	}

	Str& operator += (const Str& s) {
		int length = len() + s.len();
		if (s.len() != 0) {
			_str* pstrTmp = new _str;
			delete[] pstrTmp->m_pszData;

			pstrTmp->m_pszData = new char[length + 1];
			strcpy_s(pstrTmp->m_pszData, length + 1, m_pStr->m_pszData);
			strcat_s(pstrTmp->m_pszData, length + 1, s.m_pStr->m_pszData);

			m_pStr->Release();
			m_pStr = pstrTmp;
		}
		return *this;
	}

	inline operator char* () const {
		return  m_pStr->m_pszData;
	}

	int find(const char* t, int off) const {
		int lenStr = strlen(m_pStr->m_pszData);
		int lenSubStr = strlen(t);

		if (*m_pStr->m_pszData == '\0') {
			return -1;
		}

		else if (*t == '\0') {
			return -1;
		}

		else if (lenSubStr > lenStr) {
			return -1;
		}

		else if (off < 0 || off >= lenStr) {
			return -1;
		}

		for (char *i = m_pStr->m_pszData + off, *end = m_pStr->m_pszData + lenStr - lenSubStr + 1; i != end; ++i) {
			int checker = 0;
			for (const char* j = t, *k = i; j < t + lenSubStr; j++, k++) {
				if (*k != *j) break;
				checker++;
			}
			if (checker == lenSubStr) return i - m_pStr->m_pszData;
		}
		return -1;
	}
};


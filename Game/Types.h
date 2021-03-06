//////////////////////////////////////////////////////////////////////

#pragma once

//////////////////////////////////////////////////////////////////////

typedef __int8				int8;
typedef __int16				int16;
typedef __int32				int32;
typedef __int64				int64;
typedef unsigned int		uint;
typedef unsigned __int8		uint8;
typedef unsigned __int16	uint16;
typedef unsigned __int32	uint32;
typedef unsigned __int64	uint64;
typedef wchar_t				wchar;
typedef uint8				byte;

//////////////////////////////////////////////////////////////////////`

using std::wstring;
using std::string;
using std::vector;
using std::function;
using std::unique_ptr;

typedef std::basic_string<TCHAR> tstring;

//////////////////////////////////////////////////////////////////////

const nullptr_t null = nullptr;

//////////////////////////////////////////////////////////////////////

typedef rapidxml::xml_document<char>	XmlDocument;
typedef rapidxml::xml_node<char>		XmlNode;
typedef rapidxml::xml_attribute<char>	XmlAttribute;


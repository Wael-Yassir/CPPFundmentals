#pragma once

// Old style enum
enum Status
{
	OK,
	NOT_FOUND
};

enum class FileError
{
	NOT_FOUND,
	OK
};

enum class NetworkError
{
	DISCONNECTED,
	OK
};
#pragma once
#include "stdafx.h"
class DriverInstall {
public:

	BOOL InstallDriver(const CHAR * lpszDriverName, const CHAR * lpszDriverPath, const CHAR * lpszAltitude);

	BOOL StartDriver(const CHAR * lpszDriverName);

	BOOL StopDriver(const CHAR * lpszDriverName);

	BOOL DeleteDriver(const CHAR * lpszDriverName);

};